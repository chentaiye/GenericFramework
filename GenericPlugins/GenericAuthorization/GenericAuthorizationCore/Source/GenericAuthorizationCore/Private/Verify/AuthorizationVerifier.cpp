// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Verify/AuthorizationVerifier.h"

#include "HAL/FileManager.h"
#include "JsonObjectConverter.h"
#include "HAL/PlatformMisc.h"
#include "HAL/PlatformProcess.h"
#include "Misc/App.h"
#include "Misc/Paths.h"
#include "Misc/SecureHash.h"
#include "Misc/StringBuilder.h"
#include "Settings/AuthorizationSettings.h"

namespace AuthorizationVerifierPrivate
{
	FString BuildRelativeFingerprintPath(const FString& FullPath, const FString& ProjectRoot)
	{
		FString RelativePath = FPaths::ConvertRelativePathToFull(FullPath);
		if (!FPaths::MakePathRelativeTo(RelativePath, *ProjectRoot))
		{
			RelativePath = FPaths::GetCleanFilename(FullPath);
		}

		RelativePath.ReplaceInline(TEXT("\\"), TEXT("/"));
		RelativePath.ToLowerInline();
		return RelativePath;
	}

	void AddFingerprintFileIfExists(const FString& FullPath, TArray<FString>& OutFilePaths)
	{
		const FString ResolvedPath = FPaths::ConvertRelativePathToFull(FullPath);
		if (FPaths::FileExists(ResolvedPath))
		{
			OutFilePaths.Add(ResolvedPath);
		}
	}

	void GatherPackageMarkerFiles(TArray<FString>& OutFilePaths)
	{
		const FString ExecutablePath = FPaths::ConvertRelativePathToFull(FPlatformProcess::ExecutablePath());
		TArray<FString> CandidateRoots;
		CandidateRoots.Add(FPaths::GetPath(ExecutablePath));
		CandidateRoots.Add(FPaths::ConvertRelativePathToFull(FPaths::ProjectDir()));
		CandidateRoots.Add(FPaths::GetPath(FPaths::ConvertRelativePathToFull(FPaths::ProjectDir())));

		for (const FString& CandidateRoot : CandidateRoots)
		{
			if (CandidateRoot.IsEmpty())
			{
				continue;
			}

			TArray<FString> ManifestFileNames;
			IFileManager::Get().FindFiles(ManifestFileNames, *FPaths::Combine(CandidateRoot, TEXT("Manifest_*.txt")), true, false);
			for (const FString& ManifestFileName : ManifestFileNames)
			{
				AddFingerprintFileIfExists(FPaths::Combine(CandidateRoot, ManifestFileName), OutFilePaths);
			}

			TArray<FString> StagedBuildFileNames;
			IFileManager::Get().FindFiles(StagedBuildFileNames, *FPaths::Combine(CandidateRoot, TEXT("Engine/Config/StagedBuild_*.ini")), true, false);
			for (const FString& StagedBuildFileName : StagedBuildFileNames)
			{
				AddFingerprintFileIfExists(FPaths::Combine(CandidateRoot, TEXT("Engine/Config"), StagedBuildFileName), OutFilePaths);
			}
		}
	}

	void GatherPackageContainerFiles(TArray<FString>& OutFilePaths)
	{
		const FString PackageContainerDirectory = FPaths::Combine(FPaths::ProjectContentDir(), TEXT("Paks"));
		if (!IFileManager::Get().DirectoryExists(*PackageContainerDirectory))
		{
			return;
		}

		const TCHAR* FilePatterns[] =
		{
			TEXT("*.pak"),
			TEXT("*.utoc"),
			TEXT("*.ucas")
		};

		for (const TCHAR* FilePattern : FilePatterns)
		{
			IFileManager::Get().FindFilesRecursive(OutFilePaths, *PackageContainerDirectory, FilePattern, true, false, false);
		}

		OutFilePaths.Sort();

		FString PreviousFilePath;
		OutFilePaths.RemoveAll([&PreviousFilePath](const FString& CurrentFilePath)
		{
			if (CurrentFilePath.Equals(PreviousFilePath, ESearchCase::CaseSensitive))
			{
				return true;
			}

			PreviousFilePath = CurrentFilePath;
			return false;
		});
	}

	template <typename EnumType>
	FString GetEnumName(const EnumType InValue)
	{
		if (const UEnum* Enum = StaticEnum<EnumType>())
		{
			return Enum->GetNameStringByValue(static_cast<int64>(InValue));
		}

		return FString::FromInt(static_cast<int32>(InValue));
	}

	void AppendCanonicalField(FStringBuilderBase& Builder, const FStringView FieldName, const FStringView Value)
	{
		Builder.Append(FieldName);
		Builder.Append(TEXT("="));
		Builder.Appendf(TEXT("%d"), Value.Len());
		Builder.Append(TEXT(":"));
		Builder.Append(Value);
		Builder.Append(TEXT("|"));
	}

	void AppendCanonicalField(FStringBuilderBase& Builder, const FStringView FieldName, const FString& Value)
	{
		AppendCanonicalField(Builder, FieldName, FStringView(Value));
	}

	void AppendCanonicalField(FStringBuilderBase& Builder, const FStringView FieldName, const TCHAR* Value)
	{
		AppendCanonicalField(Builder, FieldName, FStringView(Value));
	}

	void AppendCanonicalField(FStringBuilderBase& Builder, const FStringView FieldName, const int64 Value)
	{
		AppendCanonicalField(Builder, FieldName, LexToString(Value));
	}

	void AppendCanonicalField(FStringBuilderBase& Builder, const FStringView FieldName, const bool bValue)
	{
		AppendCanonicalField(Builder, FieldName, bValue ? TEXT("1") : TEXT("0"));
	}

	template <typename StructType>
	bool StructToJson(const StructType& InStruct, FString& OutJsonText, FString& OutError)
	{
		if (!FJsonObjectConverter::UStructToJsonObjectString(InStruct, OutJsonText))
		{
			OutError = TEXT("Failed to serialize authorization payload.");
			return false;
		}

		return true;
	}

	template <typename StructType>
	bool JsonToStruct(const FString& InJsonText, StructType& OutStruct, FString& OutError)
	{
		if (InJsonText.IsEmpty())
		{
			OutError = TEXT("Authorization payload text is empty.");
			return false;
		}

		if (!FJsonObjectConverter::JsonObjectStringToUStruct(InJsonText, &OutStruct, 0, 0))
		{
			OutError = TEXT("Failed to parse authorization payload.");
			return false;
		}

		return true;
	}

	FString HashPayload(const FString& InPayload, const FString& VerificationKey)
	{
		const FString CombinedPayload = InPayload + TEXT("|") + VerificationKey;
		const FTCHARToUTF8 Utf8Payload(*CombinedPayload);
		return FMD5::HashBytes(reinterpret_cast<const uint8*>(Utf8Payload.Get()), Utf8Payload.Length());
	}

	void SortGrants(TArray<FAuthorizationGrant>& InGrants)
	{
		InGrants.Sort([](const FAuthorizationGrant& Left, const FAuthorizationGrant& Right)
		{
			if (Left.ScopeId != Right.ScopeId)
			{
				return Left.ScopeId.LexicalLess(Right.ScopeId);
			}

			if (Left.ScopeType != Right.ScopeType)
			{
				return static_cast<uint8>(Left.ScopeType) < static_cast<uint8>(Right.ScopeType);
			}

			if (Left.Version != Right.Version)
			{
				return Left.Version < Right.Version;
			}

			if (Left.GrantType != Right.GrantType)
			{
				return static_cast<uint8>(Left.GrantType) < static_cast<uint8>(Right.GrantType);
			}

			if (Left.IssuedAtUnixSeconds != Right.IssuedAtUnixSeconds)
			{
				return Left.IssuedAtUnixSeconds < Right.IssuedAtUnixSeconds;
			}

			if (Left.ExpireAtUnixSeconds != Right.ExpireAtUnixSeconds)
			{
				return Left.ExpireAtUnixSeconds < Right.ExpireAtUnixSeconds;
			}

			if (Left.bRevoked != Right.bRevoked)
			{
				return !Left.bRevoked && Right.bRevoked;
			}

			return Left.DisplayName < Right.DisplayName;
		});
	}

	void SortManifestScopes(TArray<FAuthorizationManifestScope>& InScopes)
	{
		for (FAuthorizationManifestScope& Scope : InScopes)
		{
			Scope.PakFiles.Sort([](const FString& Left, const FString& Right)
			{
				return Left < Right;
			});
		}

		InScopes.Sort([](const FAuthorizationManifestScope& Left, const FAuthorizationManifestScope& Right)
		{
			if (Left.ScopeId != Right.ScopeId)
			{
				return Left.ScopeId.LexicalLess(Right.ScopeId);
			}

			if (Left.ScopeType != Right.ScopeType)
			{
				return static_cast<uint8>(Left.ScopeType) < static_cast<uint8>(Right.ScopeType);
			}

			if (Left.Version != Right.Version)
			{
				return Left.Version < Right.Version;
			}

			if (Left.bRequiresAuthorization != Right.bRequiresAuthorization)
			{
				return !Left.bRequiresAuthorization && Right.bRequiresAuthorization;
			}

			return Left.DisplayName < Right.DisplayName;
		});
	}

	FAuthorizationLicenseToken MakeNormalizedToken(const FAuthorizationLicenseToken& InToken, const bool bIncludeSignature)
	{
		FAuthorizationLicenseToken NormalizedToken = InToken;
		SortGrants(NormalizedToken.Grants);

		if (!bIncludeSignature)
		{
			NormalizedToken.Signature.Empty();
		}

		return NormalizedToken;
	}

	FAuthorizationManifest MakeNormalizedManifest(const FAuthorizationManifest& InManifest, const bool bIncludeSignature)
	{
		FAuthorizationManifest NormalizedManifest = InManifest;
		SortManifestScopes(NormalizedManifest.Scopes);

		if (!bIncludeSignature)
		{
			NormalizedManifest.Signature.Empty();
		}

		return NormalizedManifest;
	}

	FString BuildCanonicalLicenseTokenPayload(const FAuthorizationLicenseToken& InToken)
	{
		const FAuthorizationLicenseToken NormalizedToken = MakeNormalizedToken(InToken, false);
		TStringBuilder<2048> Builder;
		AppendCanonicalField(Builder, TEXT("SchemaVersion"), NormalizedToken.SchemaVersion);
		AppendCanonicalField(Builder, TEXT("LicenseId"), NormalizedToken.LicenseId);
		AppendCanonicalField(Builder, TEXT("ProductId"), NormalizedToken.ProductId);
		AppendCanonicalField(Builder, TEXT("DeviceId"), NormalizedToken.DeviceId);
		AppendCanonicalField(Builder, TEXT("PackageFingerprint"), NormalizedToken.PackageFingerprint);
		AppendCanonicalField(Builder, TEXT("IssuedAtUnixSeconds"), NormalizedToken.IssuedAtUnixSeconds);
		AppendCanonicalField(Builder, TEXT("GrantCount"), static_cast<int64>(NormalizedToken.Grants.Num()));

		for (int32 GrantIndex = 0; GrantIndex < NormalizedToken.Grants.Num(); ++GrantIndex)
		{
			const FAuthorizationGrant& Grant = NormalizedToken.Grants[GrantIndex];
			const FString Prefix = FString::Printf(TEXT("Grant[%d]."), GrantIndex);
			AppendCanonicalField(Builder, Prefix + TEXT("ScopeId"), Grant.ScopeId.ToString());
			AppendCanonicalField(Builder, Prefix + TEXT("ScopeType"), GetEnumName(Grant.ScopeType));
			AppendCanonicalField(Builder, Prefix + TEXT("GrantType"), GetEnumName(Grant.GrantType));
			AppendCanonicalField(Builder, Prefix + TEXT("DisplayName"), Grant.DisplayName);
			AppendCanonicalField(Builder, Prefix + TEXT("Version"), Grant.Version);
			AppendCanonicalField(Builder, Prefix + TEXT("IssuedAtUnixSeconds"), Grant.IssuedAtUnixSeconds);
			AppendCanonicalField(Builder, Prefix + TEXT("ExpireAtUnixSeconds"), Grant.ExpireAtUnixSeconds);
			AppendCanonicalField(Builder, Prefix + TEXT("Revoked"), Grant.bRevoked);
		}

		return Builder.ToString();
	}

	FString BuildCanonicalManifestPayload(const FAuthorizationManifest& InManifest)
	{
		const FAuthorizationManifest NormalizedManifest = MakeNormalizedManifest(InManifest, false);
		TStringBuilder<2048> Builder;
		AppendCanonicalField(Builder, TEXT("SchemaVersion"), NormalizedManifest.SchemaVersion);
		AppendCanonicalField(Builder, TEXT("ProductId"), NormalizedManifest.ProductId);
		AppendCanonicalField(Builder, TEXT("IssuedAtUnixSeconds"), NormalizedManifest.IssuedAtUnixSeconds);
		AppendCanonicalField(Builder, TEXT("ScopeCount"), static_cast<int64>(NormalizedManifest.Scopes.Num()));

		for (int32 ScopeIndex = 0; ScopeIndex < NormalizedManifest.Scopes.Num(); ++ScopeIndex)
		{
			const FAuthorizationManifestScope& Scope = NormalizedManifest.Scopes[ScopeIndex];
			const FString Prefix = FString::Printf(TEXT("Scope[%d]."), ScopeIndex);
			AppendCanonicalField(Builder, Prefix + TEXT("ScopeId"), Scope.ScopeId.ToString());
			AppendCanonicalField(Builder, Prefix + TEXT("ScopeType"), GetEnumName(Scope.ScopeType));
			AppendCanonicalField(Builder, Prefix + TEXT("DisplayName"), Scope.DisplayName);
			AppendCanonicalField(Builder, Prefix + TEXT("Version"), Scope.Version);
			AppendCanonicalField(Builder, Prefix + TEXT("RequiresAuthorization"), Scope.bRequiresAuthorization);
			AppendCanonicalField(Builder, Prefix + TEXT("PakCount"), static_cast<int64>(Scope.PakFiles.Num()));

			for (int32 PakIndex = 0; PakIndex < Scope.PakFiles.Num(); ++PakIndex)
			{
				AppendCanonicalField(Builder, Prefix + FString::Printf(TEXT("Pak[%d]"), PakIndex), Scope.PakFiles[PakIndex]);
			}
		}

		return Builder.ToString();
	}
}

int64 FAuthorizationVerifier::GetCurrentUnixTimestamp()
{
	return FDateTime::UtcNow().ToUnixTimestamp();
}

FString FAuthorizationVerifier::ResolveProductId(const UAuthorizationSettings* InSettings)
{
	const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();
	return Settings->ProductId.IsEmpty() ? FString(FApp::GetProjectName()) : Settings->ProductId;
}

FString FAuthorizationVerifier::BuildCurrentDeviceId()
{
	const FString DeviceId = FPlatformMisc::GetDeviceId();
	const FString LoginId = FPlatformMisc::GetLoginId();
	const FString ComputerName = FPlatformProcess::ComputerName();
	const FString DeviceFingerprint = FString::Printf(TEXT("%s|%s|%s"), *DeviceId, *LoginId, *ComputerName);

	return AuthorizationVerifierPrivate::HashPayload(DeviceFingerprint, TEXT("GenericAuthorizationDevice"));
}

FString FAuthorizationVerifier::BuildCurrentPackageFingerprint()
{
	const FString ProjectRoot = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
	const FString ExecutablePath = FPaths::ConvertRelativePathToFull(FPlatformProcess::ExecutablePath());
	const FString BuildVersion = FApp::GetBuildVersion();
	TArray<FString> FingerprintFiles;
	FingerprintFiles.Add(ExecutablePath);
	AuthorizationVerifierPrivate::GatherPackageMarkerFiles(FingerprintFiles);
	AuthorizationVerifierPrivate::GatherPackageContainerFiles(FingerprintFiles);

	TStringBuilder<4096> BuildFingerprintSeed;
	BuildFingerprintSeed.Append(FApp::GetProjectName());
	BuildFingerprintSeed.Append(TEXT("|"));
	BuildFingerprintSeed.Append(BuildVersion);
	BuildFingerprintSeed.Append(TEXT("|FileCount="));
	BuildFingerprintSeed.Append(LexToString(FingerprintFiles.Num()));
	BuildFingerprintSeed.Append(TEXT("|"));

	for (const FString& FingerprintFile : FingerprintFiles)
	{
		const int64 FileSize = IFileManager::Get().FileSize(*FingerprintFile);
		const FDateTime FileTimestamp = IFileManager::Get().GetTimeStamp(*FingerprintFile);
		BuildFingerprintSeed.Append(AuthorizationVerifierPrivate::BuildRelativeFingerprintPath(FingerprintFile, ProjectRoot));
		BuildFingerprintSeed.Append(TEXT("|"));
		BuildFingerprintSeed.Append(LexToString(FileSize));
		BuildFingerprintSeed.Append(TEXT("|"));
		BuildFingerprintSeed.Append(LexToString(FileTimestamp.ToUnixTimestamp()));
		BuildFingerprintSeed.Append(TEXT("|"));
	}

	return AuthorizationVerifierPrivate::HashPayload(BuildFingerprintSeed.ToString(), TEXT("GenericAuthorizationPackage"));
}

FString FAuthorizationVerifier::NormalizeContentPath(const FString& InPath)
{
	FString NormalizedPath = InPath;
	NormalizedPath.ReplaceInline(TEXT("\\"), TEXT("/"));
	NormalizedPath.TrimStartAndEndInline();
	NormalizedPath = NormalizedPath.ToLower();
	return NormalizedPath;
}

bool FAuthorizationVerifier::MatchesContentPath(const FString& LeftPath, const FString& RightPath)
{
	const FString NormalizedLeft = NormalizeContentPath(LeftPath);
	const FString NormalizedRight = NormalizeContentPath(RightPath);

	if (NormalizedLeft == NormalizedRight)
	{
		return true;
	}

	return FPaths::GetCleanFilename(NormalizedLeft) == FPaths::GetCleanFilename(NormalizedRight);
}

bool FAuthorizationVerifier::ParseLicenseToken(const FString& InJsonText, FAuthorizationLicenseToken& OutToken, FString& OutError)
{
	return AuthorizationVerifierPrivate::JsonToStruct(InJsonText, OutToken, OutError);
}

bool FAuthorizationVerifier::SerializeLicenseToken(const FAuthorizationLicenseToken& InToken, FString& OutJsonText, const bool bIncludeSignature, FString& OutError)
{
	return AuthorizationVerifierPrivate::StructToJson(AuthorizationVerifierPrivate::MakeNormalizedToken(InToken, bIncludeSignature), OutJsonText, OutError);
}

FString FAuthorizationVerifier::SignLicenseToken(const FAuthorizationLicenseToken& InToken, const FString& VerificationKey)
{
	return AuthorizationVerifierPrivate::HashPayload(BuildCanonicalLicenseTokenPayload(InToken), VerificationKey);
}

bool FAuthorizationVerifier::VerifyLicenseToken(const FAuthorizationLicenseToken& InToken, const FString& ExpectedProductId, const FString& CurrentDeviceId, const FString& CurrentPackageFingerprint, const FString& VerificationKey, const bool bRequireDeviceBinding, const bool bRequirePackageBinding, EAuthorizationState& OutState, FString& OutError)
{
	OutState = EAuthorizationState::Unauthorized;

	if (InToken.IsEmpty())
	{
		OutError = TEXT("Authorization license token is empty.");
		return false;
	}

	if (!ExpectedProductId.IsEmpty() && !InToken.ProductId.Equals(ExpectedProductId, ESearchCase::IgnoreCase))
	{
		OutState = EAuthorizationState::ProductMismatch;
		OutError = TEXT("Authorization license token product does not match current product.");
		return false;
	}

	if (InToken.Signature.IsEmpty())
	{
		OutState = EAuthorizationState::InvalidSignature;
		OutError = TEXT("Authorization license token signature is empty.");
		return false;
	}

	if (!SignLicenseToken(InToken, VerificationKey).Equals(InToken.Signature, ESearchCase::IgnoreCase))
	{
		OutState = EAuthorizationState::InvalidSignature;
		OutError = TEXT("Authorization license token signature is invalid.");
		return false;
	}

	if (bRequireDeviceBinding)
	{
		if (CurrentDeviceId.IsEmpty() || InToken.DeviceId.IsEmpty() || !InToken.DeviceId.Equals(CurrentDeviceId, ESearchCase::IgnoreCase))
		{
			OutState = EAuthorizationState::DeviceMismatch;
			OutError = TEXT("Authorization license token device binding does not match current device.");
			return false;
		}
	}

	if (bRequirePackageBinding)
	{
		if (CurrentPackageFingerprint.IsEmpty() || InToken.PackageFingerprint.IsEmpty() || !InToken.PackageFingerprint.Equals(CurrentPackageFingerprint, ESearchCase::IgnoreCase))
		{
			OutState = EAuthorizationState::PackageMismatch;
			OutError = TEXT("Authorization license token package binding does not match current package.");
			return false;
		}
	}

	OutState = EAuthorizationState::Authorized;
	OutError.Empty();
	return true;
}

bool FAuthorizationVerifier::ParseManifest(const FString& InJsonText, FAuthorizationManifest& OutManifest, FString& OutError)
{
	return AuthorizationVerifierPrivate::JsonToStruct(InJsonText, OutManifest, OutError);
}

bool FAuthorizationVerifier::SerializeManifest(const FAuthorizationManifest& InManifest, FString& OutJsonText, const bool bIncludeSignature, FString& OutError)
{
	return AuthorizationVerifierPrivate::StructToJson(AuthorizationVerifierPrivate::MakeNormalizedManifest(InManifest, bIncludeSignature), OutJsonText, OutError);
}

FString FAuthorizationVerifier::BuildCanonicalLicenseTokenPayload(const FAuthorizationLicenseToken& InToken)
{
	return AuthorizationVerifierPrivate::BuildCanonicalLicenseTokenPayload(InToken);
}

FString FAuthorizationVerifier::BuildCanonicalManifestPayload(const FAuthorizationManifest& InManifest)
{
	return AuthorizationVerifierPrivate::BuildCanonicalManifestPayload(InManifest);
}

FString FAuthorizationVerifier::SignManifest(const FAuthorizationManifest& InManifest, const FString& VerificationKey)
{
	return AuthorizationVerifierPrivate::HashPayload(BuildCanonicalManifestPayload(InManifest), VerificationKey);
}

bool FAuthorizationVerifier::VerifyManifest(const FAuthorizationManifest& InManifest, const FString& ExpectedProductId, const FString& VerificationKey, const bool bRequireSignature, EAuthorizationState& OutState, FString& OutError)
{
	OutState = EAuthorizationState::MissingManifest;

	if (InManifest.IsEmpty())
	{
		OutError = TEXT("Authorization manifest is empty.");
		return false;
	}

	if (!ExpectedProductId.IsEmpty() && !InManifest.ProductId.Equals(ExpectedProductId, ESearchCase::IgnoreCase))
	{
		OutState = EAuthorizationState::ProductMismatch;
		OutError = TEXT("Authorization manifest product does not match current product.");
		return false;
	}

	if (bRequireSignature)
	{
		if (InManifest.Signature.IsEmpty())
		{
			OutState = EAuthorizationState::InvalidManifest;
			OutError = TEXT("Authorization manifest signature is empty.");
			return false;
		}

		if (!SignManifest(InManifest, VerificationKey).Equals(InManifest.Signature, ESearchCase::IgnoreCase))
		{
			OutState = EAuthorizationState::InvalidManifest;
			OutError = TEXT("Authorization manifest signature is invalid.");
			return false;
		}
	}

	OutState = EAuthorizationState::Authorized;
	OutError.Empty();
	return true;
}
