// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Provider/LocalFileAuthorizationServiceFeature.h"

#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Settings/AuthorizationSettings.h"
#include "Verify/AuthorizationVerifier.h"

FName FLocalFileAuthorizationServiceFeature::GetProviderName() const
{
	static const FName ProviderName(TEXT("LocalFile"));
	return ProviderName;
}

bool FLocalFileAuthorizationServiceFeature::IsOnlineService() const
{
	return false;
}

bool FLocalFileAuthorizationServiceFeature::SupportsActivation() const
{
	return true;
}

bool FLocalFileAuthorizationServiceFeature::SupportsRefresh() const
{
	return true;
}

bool FLocalFileAuthorizationServiceFeature::Activate(const FAuthorizationActivationRequest& InRequest, FAuthorizationServiceResponse& OutResponse)
{
	OutResponse = FAuthorizationServiceResponse();
	OutResponse.ProviderName = GetProviderName();

	FString ResolvedLicenseFilePath;
	if (!ResolveLicenseTokenText(InRequest.AuthorizationCode, OutResponse.LicenseTokenText, ResolvedLicenseFilePath, OutResponse.Message))
	{
		return false;
	}

	if (!ResolvedLicenseFilePath.IsEmpty())
	{
		TryLoadSiblingManifestText(ResolvedLicenseFilePath, OutResponse.ManifestText);
		OutResponse.Message = FString::Printf(TEXT("Authorization license token loaded from local file: %s"), *ResolvedLicenseFilePath);
	}
	else
	{
		OutResponse.Message = TEXT("Authorization license token loaded from inline text.");
	}

	OutResponse.bSuccessful = true;
	return true;
}

bool FLocalFileAuthorizationServiceFeature::Refresh(const FAuthorizationRefreshRequest& InRequest, FAuthorizationServiceResponse& OutResponse)
{
	OutResponse = FAuthorizationServiceResponse();
	OutResponse.ProviderName = GetProviderName();

	if (InRequest.CurrentLicenseToken.IsEmpty())
	{
		OutResponse.Message = TEXT("Current authorization cache is empty.");
		return false;
	}

	FString SerializeError;
	if (!FAuthorizationVerifier::SerializeLicenseToken(InRequest.CurrentLicenseToken, OutResponse.LicenseTokenText, true, SerializeError))
	{
		OutResponse.Message = SerializeError;
		return false;
	}

	if (!InRequest.CurrentManifest.IsEmpty() && !FAuthorizationVerifier::SerializeManifest(InRequest.CurrentManifest, OutResponse.ManifestText, true, SerializeError))
	{
		OutResponse.Message = SerializeError;
		return false;
	}

	OutResponse.bSuccessful = true;
	OutResponse.Message = TEXT("Authorization refresh replayed the locally cached authorization payload.");
	return true;
}

bool FLocalFileAuthorizationServiceFeature::ResolveLicenseTokenText(const FString& AuthorizationCode, FString& OutLicenseTokenText, FString& OutResolvedFilePath, FString& OutError)
{
	OutLicenseTokenText.Empty();
	OutResolvedFilePath.Empty();

	FString TrimmedAuthorizationCode = AuthorizationCode;
	TrimmedAuthorizationCode.TrimStartAndEndInline();

	if (TrimmedAuthorizationCode.IsEmpty())
	{
		OutError = TEXT("Authorization code is empty.");
		return false;
	}

	const TArray<FString> CandidatePaths =
	{
		TrimmedAuthorizationCode,
		FPaths::ConvertRelativePathToFull(FPaths::ProjectDir(), TrimmedAuthorizationCode)
	};

	for (const FString& CandidatePath : CandidatePaths)
	{
		if (!FPaths::FileExists(CandidatePath))
		{
			continue;
		}

		if (!FFileHelper::LoadFileToString(OutLicenseTokenText, *CandidatePath))
		{
			OutError = FString::Printf(TEXT("Failed to load local authorization license file: %s"), *CandidatePath);
			return false;
		}

		OutResolvedFilePath = CandidatePath;
		return true;
	}

	if (TrimmedAuthorizationCode.StartsWith(TEXT("{")))
	{
		OutLicenseTokenText = TrimmedAuthorizationCode;
		return true;
	}

	OutError = TEXT("Authorization code must be a readable license file path or an inline license token json payload.");
	return false;
}

bool FLocalFileAuthorizationServiceFeature::TryLoadSiblingManifestText(const FString& ResolvedLicenseFilePath, FString& OutManifestText)
{
	OutManifestText.Empty();

	if (ResolvedLicenseFilePath.IsEmpty())
	{
		return false;
	}

	const FString DirectoryPath = FPaths::GetPath(ResolvedLicenseFilePath);
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	const TArray<FString> CandidatePaths =
	{
		FPaths::Combine(DirectoryPath, Settings->ManifestFileName),
		FPaths::Combine(DirectoryPath, TEXT("content.manifest.json"))
	};

	for (const FString& CandidatePath : CandidatePaths)
	{
		if (!FPaths::FileExists(CandidatePath))
		{
			continue;
		}

		if (FFileHelper::LoadFileToString(OutManifestText, *CandidatePath))
		{
			return true;
		}
	}

	return false;
}
