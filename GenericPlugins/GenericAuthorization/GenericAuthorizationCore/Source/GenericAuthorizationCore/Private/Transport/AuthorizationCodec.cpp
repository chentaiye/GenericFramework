// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Transport/AuthorizationCodec.h"

#include "Dom/JsonObject.h"
#include "JsonObjectConverter.h"
#include "GenericPlatform/GenericPlatformMisc.h"
#include "Misc/AES.h"
#include "Misc/Base64.h"
#include "Misc/EngineVersionComparison.h"
#include "Policies/CondensedJsonPrintPolicy.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "Containers/StringConv.h"
#include "Verify/AuthorizationVerifier.h"
#include "Misc/SecureHash.h"

namespace AuthorizationCodecPrivate
{
	constexpr TCHAR RequestCodePrefix[] = TEXT("GARQ1-");
	constexpr TCHAR LicenseCodePrefix[] = TEXT("GAL1-");
	constexpr TCHAR TransportNamespace[] = TEXT("GenericAuthorizationTransport");
	constexpr int32 AesBlockSize = static_cast<int32>(FAES::AESBlockSize);

	bool SerializeRequestPayloadToJson(const FAuthorizationRequestCodePayload& InPayload, FString& OutJsonText, FString& OutError)
	{
		const TSharedRef<FJsonObject> JsonObject = MakeShared<FJsonObject>();
		JsonObject->SetStringField(TEXT("SchemaVersion"), InPayload.SchemaVersion);
		JsonObject->SetStringField(TEXT("ProductId"), InPayload.ProductId);
		JsonObject->SetStringField(TEXT("DeviceId"), InPayload.DeviceId);
		JsonObject->SetStringField(TEXT("PackageFingerprint"), InPayload.PackageFingerprint);
		JsonObject->SetNumberField(TEXT("IssuedAtUnixSeconds"), static_cast<double>(InPayload.IssuedAtUnixSeconds));

		const TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter =
			TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&OutJsonText);
		if (!FJsonSerializer::Serialize(JsonObject, JsonWriter))
		{
			OutError = TEXT("Failed to serialize authorization request payload.");
			return false;
		}

		return true;
	}

	template <typename StructType>
	bool DeserializeJsonToStruct(const FString& InJsonText, StructType& OutStructData, FString& OutError)
	{
		if (InJsonText.IsEmpty())
		{
			OutError = TEXT("Authorization transport payload is empty.");
			return false;
		}

		if (!FJsonObjectConverter::JsonObjectStringToUStruct(InJsonText, &OutStructData, 0, 0))
		{
			OutError = TEXT("Failed to parse authorization transport payload.");
			return false;
		}

		return true;
	}

	bool StartsWithPrefix(const FString& InText, const TCHAR* Prefix)
	{
		return InText.TrimStartAndEnd().StartsWith(Prefix, ESearchCase::CaseSensitive);
	}

	FString BuildBase64Url(const TArray<uint8>& InBytes)
	{
		FString EncodedText = FBase64::Encode(InBytes);
		EncodedText.ReplaceInline(TEXT("+"), TEXT("-"));
		EncodedText.ReplaceInline(TEXT("/"), TEXT("_"));

		while (EncodedText.EndsWith(TEXT("=")))
		{
#if UE_VERSION_OLDER_THAN(5, 5, 0)
			EncodedText.LeftChopInline(1, false);
#else
			EncodedText.LeftChopInline(1, EAllowShrinking::No);
#endif
		}

		return EncodedText;
	}

	bool DecodeBase64Url(const FString& InBase64Url, TArray<uint8>& OutBytes, FString& OutError)
	{
		FString PaddedText = InBase64Url;
		PaddedText.ReplaceInline(TEXT("-"), TEXT("+"));
		PaddedText.ReplaceInline(TEXT("_"), TEXT("/"));

		while ((PaddedText.Len() % 4) != 0)
		{
			PaddedText.AppendChar(TEXT('='));
		}

		if (!FBase64::Decode(PaddedText, OutBytes))
		{
			OutError = TEXT("Failed to decode authorization transport text.");
			return false;
		}

		return true;
	}

	FAES::FAESKey BuildTransportKey(const FString& VerificationKey, const FString& Purpose)
	{
		FAES::FAESKey AesKey;
		const FString KeySeed = FString::Printf(TEXT("%s|%s|%s"), TransportNamespace, *Purpose, *VerificationKey);

		const auto BuildDigest = [](const FString& InSeed, uint8 OutDigest[16])
		{
			const FTCHARToUTF8 Utf8Seed(*InSeed);
			FMD5 Md5Generator;
			Md5Generator.Update(reinterpret_cast<const uint8*>(Utf8Seed.Get()), Utf8Seed.Length());
			Md5Generator.Final(OutDigest);
		};

		uint8 FirstDigest[16];
		uint8 SecondDigest[16];
		BuildDigest(KeySeed + TEXT("|0"), FirstDigest);
		BuildDigest(KeySeed + TEXT("|1"), SecondDigest);

		FMemory::Memcpy(AesKey.Key, FirstDigest, 16);
		FMemory::Memcpy(AesKey.Key + 16, SecondDigest, 16);
		return AesKey;
	}

	void AddPkcs7Padding(TArray<uint8>& InOutBytes)
	{
		const uint8 PaddingSize = static_cast<uint8>(AesBlockSize - (InOutBytes.Num() % AesBlockSize == 0 ? AesBlockSize : InOutBytes.Num() % AesBlockSize));
		const uint8 EffectivePaddingSize = PaddingSize == 0 ? static_cast<uint8>(AesBlockSize) : PaddingSize;

		for (uint8 PaddingIndex = 0; PaddingIndex < EffectivePaddingSize; ++PaddingIndex)
		{
			InOutBytes.Add(EffectivePaddingSize);
		}
	}

	bool RemovePkcs7Padding(TArray<uint8>& InOutBytes, FString& OutError)
	{
		if (InOutBytes.IsEmpty())
		{
			OutError = TEXT("Authorization transport payload is empty after decrypt.");
			return false;
		}

		const uint8 PaddingSize = InOutBytes.Last();
		if (PaddingSize == 0 || PaddingSize > AesBlockSize || PaddingSize > InOutBytes.Num())
		{
			OutError = TEXT("Authorization transport padding is invalid.");
			return false;
		}

		for (int32 PaddingIndex = 0; PaddingIndex < PaddingSize; ++PaddingIndex)
		{
			if (InOutBytes[InOutBytes.Num() - 1 - PaddingIndex] != PaddingSize)
			{
				OutError = TEXT("Authorization transport padding is corrupted.");
				return false;
			}
		}

#if UE_VERSION_OLDER_THAN(5, 5, 0)
		InOutBytes.RemoveAt(InOutBytes.Num() - PaddingSize, PaddingSize, false);
#else
		InOutBytes.RemoveAt(InOutBytes.Num() - PaddingSize, PaddingSize, EAllowShrinking::No);
#endif
		return true;
	}

	bool EncryptTextToCode(const FString& PlainText, const FString& VerificationKey, const FString& Purpose, const TCHAR* Prefix, FString& OutCode, FString& OutError)
	{
		if (PlainText.IsEmpty())
		{
			OutError = TEXT("Authorization transport payload is empty.");
			return false;
		}

		const FTCHARToUTF8 Utf8Text(*PlainText);
		TArray<uint8> Buffer;
		Buffer.Append(reinterpret_cast<const uint8*>(Utf8Text.Get()), Utf8Text.Length());
		AddPkcs7Padding(Buffer);

		const FAES::FAESKey AesKey = BuildTransportKey(VerificationKey, Purpose);
		FAES::EncryptData(Buffer.GetData(), Buffer.Num(), AesKey);

		OutCode = FString(Prefix) + BuildBase64Url(Buffer);
		return true;
	}

	bool DecryptCodeToText(const FString& InCode, const FString& VerificationKey, const FString& Purpose, const TCHAR* Prefix, FString& OutPlainText, FString& OutError)
	{
		const FString TrimmedCode = InCode.TrimStartAndEnd();
		if (!TrimmedCode.StartsWith(Prefix, ESearchCase::CaseSensitive))
		{
			OutError = TEXT("Authorization transport code prefix is invalid.");
			return false;
		}

		TArray<uint8> Buffer;
		if (!DecodeBase64Url(TrimmedCode.RightChop(FCString::Strlen(Prefix)), Buffer, OutError))
		{
			return false;
		}

		if (Buffer.IsEmpty() || (Buffer.Num() % AesBlockSize) != 0)
		{
			OutError = TEXT("Authorization transport code length is invalid.");
			return false;
		}

		const FAES::FAESKey AesKey = BuildTransportKey(VerificationKey, Purpose);
		FAES::DecryptData(Buffer.GetData(), Buffer.Num(), AesKey);

		if (!RemovePkcs7Padding(Buffer, OutError))
		{
			return false;
		}

		const FUTF8ToTCHAR Utf8Text(reinterpret_cast<const ANSICHAR*>(Buffer.GetData()), Buffer.Num());
		OutPlainText = FString(Utf8Text.Length(), Utf8Text.Get());
		return true;
	}
}

FString FAuthorizationCodec::BuildAuthorizationRequestCode(const FString& ProductId, const FString& DeviceId, const FString& PackageFingerprint, const FString& VerificationKey)
{
	FAuthorizationRequestCodePayload Payload;
	Payload.ProductId = ProductId;
	Payload.DeviceId = DeviceId;
	Payload.PackageFingerprint = PackageFingerprint;
	Payload.IssuedAtUnixSeconds = FAuthorizationVerifier::GetCurrentUnixTimestamp();

	FString PayloadJson;
	FString ErrorMessage;
	if (!AuthorizationCodecPrivate::SerializeRequestPayloadToJson(Payload, PayloadJson, ErrorMessage))
	{
		return FString();
	}

	FString RequestCode;
	if (!AuthorizationCodecPrivate::EncryptTextToCode(PayloadJson, VerificationKey, TEXT("Request"), AuthorizationCodecPrivate::RequestCodePrefix, RequestCode, ErrorMessage))
	{
		return FString();
	}

	return RequestCode;
}

bool FAuthorizationCodec::ParseAuthorizationRequestCode(const FString& RequestCode, const FString& VerificationKey, FAuthorizationRequestCodePayload& OutPayload, FString& OutError)
{
	FString PayloadJson;
	if (!AuthorizationCodecPrivate::DecryptCodeToText(RequestCode, VerificationKey, TEXT("Request"), AuthorizationCodecPrivate::RequestCodePrefix, PayloadJson, OutError))
	{
		return false;
	}

	return AuthorizationCodecPrivate::DeserializeJsonToStruct(PayloadJson, OutPayload, OutError);
}

FString FAuthorizationCodec::BuildLicenseTokenCode(const FAuthorizationLicenseToken& LicenseToken, const FString& VerificationKey)
{
	FString LicenseTokenJson;
	FString ErrorMessage;
	if (!FAuthorizationVerifier::SerializeLicenseToken(LicenseToken, LicenseTokenJson, true, ErrorMessage))
	{
		return FString();
	}

	FString LicenseCode;
	if (!AuthorizationCodecPrivate::EncryptTextToCode(LicenseTokenJson, VerificationKey, TEXT("License"), AuthorizationCodecPrivate::LicenseCodePrefix, LicenseCode, ErrorMessage))
	{
		return FString();
	}

	return LicenseCode;
}

bool FAuthorizationCodec::TryDecodeLicenseTokenInput(const FString& LicenseTokenInput, const FString& VerificationKey, FString& OutLicenseTokenText, FString& OutError)
{
	const FString TrimmedInput = LicenseTokenInput.TrimStartAndEnd();
	if (TrimmedInput.IsEmpty())
	{
		OutError = TEXT("Authorization input is empty.");
		return false;
	}

	if (IsLicenseTokenCode(TrimmedInput))
	{
		return AuthorizationCodecPrivate::DecryptCodeToText(TrimmedInput, VerificationKey, TEXT("License"), AuthorizationCodecPrivate::LicenseCodePrefix, OutLicenseTokenText, OutError);
	}

	OutLicenseTokenText = TrimmedInput;
	OutError.Empty();
	return true;
}

bool FAuthorizationCodec::IsAuthorizationRequestCode(const FString& InText)
{
	return AuthorizationCodecPrivate::StartsWithPrefix(InText, AuthorizationCodecPrivate::RequestCodePrefix);
}

bool FAuthorizationCodec::IsLicenseTokenCode(const FString& InText)
{
	return AuthorizationCodecPrivate::StartsWithPrefix(InText, AuthorizationCodecPrivate::LicenseCodePrefix);
}
