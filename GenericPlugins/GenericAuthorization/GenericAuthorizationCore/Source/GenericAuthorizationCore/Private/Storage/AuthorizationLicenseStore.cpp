// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Storage/AuthorizationLicenseStore.h"

#include "HAL/FileManager.h"
#include "HAL/PlatformProcess.h"
#include "JsonObjectConverter.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Settings/AuthorizationSettings.h"
#include "Verify/AuthorizationVerifier.h"

namespace AuthorizationLicenseStorePrivate
{
	template <typename StructType>
	bool LoadStructFile(const FString& FilePath, StructType& OutStruct, FString& OutError)
	{
		FString FileText;
		if (!FAuthorizationLicenseStore::ReadTextFile(FilePath, FileText, OutError))
		{
			return false;
		}

		if (!FJsonObjectConverter::JsonObjectStringToUStruct(FileText, &OutStruct, 0, 0))
		{
			OutError = FString::Printf(TEXT("Failed to deserialize authorization file: %s"), *FilePath);
			return false;
		}

		return true;
	}

	template <typename StructType>
	bool SaveStructFile(const FString& FilePath, const StructType& InStruct, FString& OutError)
	{
		FString FileText;
		if (!FJsonObjectConverter::UStructToJsonObjectString(InStruct, FileText))
		{
			OutError = FString::Printf(TEXT("Failed to serialize authorization file: %s"), *FilePath);
			return false;
		}

		return FAuthorizationLicenseStore::WriteTextFile(FilePath, FileText, OutError);
	}

	FString ResolveSourceDirectoryName(const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
	{
		const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();

		switch (InSource)
		{
		case EAuthorizationSourceType::Online:
			return Settings->OnlineCacheDirectoryName;

		case EAuthorizationSourceType::Offline:
			return Settings->OfflineCacheDirectoryName;

		default:
			return FString();
		}
	}
}

FString FAuthorizationLicenseStore::GetCommonCacheRootDirectory(const UAuthorizationSettings* InSettings)
{
	const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();
	FString ProductId = FAuthorizationVerifier::ResolveProductId(Settings);

	if (ProductId.IsEmpty())
	{
		ProductId = TEXT("UnknownProduct");
	}

	return FPaths::Combine(
		FString(FPlatformProcess::ApplicationSettingsDir()),
		Settings->CacheRelativeDirectory,
		FPaths::MakeValidFileName(ProductId),
		GetCurrentBuildCacheKey(Settings));
}

FString FAuthorizationLicenseStore::GetCurrentBuildCacheKey(const UAuthorizationSettings* InSettings)
{
	const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();
	if (!Settings->bRequirePackageBinding)
	{
		return TEXT("Shared");
	}

	return FPaths::MakeValidFileName(FAuthorizationVerifier::BuildCurrentPackageFingerprint());
}

FString FAuthorizationLicenseStore::GetCacheDirectory(const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
{
	const FString SourceDirectoryName = AuthorizationLicenseStorePrivate::ResolveSourceDirectoryName(InSource, InSettings);
	if (SourceDirectoryName.IsEmpty())
	{
		return GetCommonCacheRootDirectory(InSettings);
	}

	return FPaths::Combine(GetCommonCacheRootDirectory(InSettings), SourceDirectoryName);
}

FString FAuthorizationLicenseStore::GetLicenseTokenFilePath(const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
{
	const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();
	return FPaths::Combine(GetCacheDirectory(InSource, Settings), Settings->LicenseFileName);
}

FString FAuthorizationLicenseStore::GetManifestFilePath(const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
{
	const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();
	return FPaths::Combine(GetCacheDirectory(InSource, Settings), Settings->ManifestFileName);
}

FString FAuthorizationLicenseStore::GetRuntimeStateFilePath(const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
{
	const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();
	return FPaths::Combine(GetCacheDirectory(InSource, Settings), Settings->RuntimeStateFileName);
}

FString FAuthorizationLicenseStore::GetResolvedOfflineAuthorizationDirectoryPath(const UAuthorizationSettings* InSettings)
{
	const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();
	FString DirectoryPath = Settings->OfflineAuthorizationDirectory.Path;

	if (DirectoryPath.IsEmpty())
	{
		DirectoryPath = TEXT("Authorization");
	}

	if (FPaths::IsRelative(DirectoryPath))
	{
		return FPaths::ConvertRelativePathToFull(FPaths::ProjectDir(), DirectoryPath);
	}

	return DirectoryPath;
}

FString FAuthorizationLicenseStore::GetBundledOfflineLicenseTokenFilePath(const UAuthorizationSettings* InSettings)
{
	const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();
	return FPaths::Combine(GetResolvedOfflineAuthorizationDirectoryPath(Settings), Settings->LicenseFileName);
}

FString FAuthorizationLicenseStore::GetBundledOfflineManifestFilePath(const UAuthorizationSettings* InSettings)
{
	const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();
	return FPaths::Combine(GetResolvedOfflineAuthorizationDirectoryPath(Settings), Settings->ManifestFileName);
}

FString FAuthorizationLicenseStore::GetResolvedProjectManifestFilePath(const UAuthorizationSettings* InSettings)
{
	const UAuthorizationSettings* Settings = InSettings != nullptr ? InSettings : UAuthorizationSettings::Get();
	if (Settings->ProjectManifestFile.FilePath.IsEmpty())
	{
		return FString();
	}

	if (FPaths::IsRelative(Settings->ProjectManifestFile.FilePath))
	{
		return FPaths::ConvertRelativePathToFull(FPaths::ProjectDir(), Settings->ProjectManifestFile.FilePath);
	}

	return Settings->ProjectManifestFile.FilePath;
}

bool FAuthorizationLicenseStore::LoadLicenseToken(FAuthorizationLicenseToken& OutToken, FString& OutError, const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
{
	const FString FilePath = GetLicenseTokenFilePath(InSource, InSettings);
	if (!FPaths::FileExists(FilePath))
	{
		OutError = FString::Printf(TEXT("Authorization license token file does not exist: %s"), *FilePath);
		return false;
	}

	FString FileText;
	if (!ReadTextFile(FilePath, FileText, OutError))
	{
		return false;
	}

	return FAuthorizationVerifier::ParseLicenseToken(FileText, OutToken, OutError);
}

bool FAuthorizationLicenseStore::LoadBundledOfflineLicenseToken(FAuthorizationLicenseToken& OutToken, FString& OutError, const UAuthorizationSettings* InSettings)
{
	const FString FilePath = GetBundledOfflineLicenseTokenFilePath(InSettings);
	if (!FPaths::FileExists(FilePath))
	{
		OutError = FString::Printf(TEXT("Bundled offline authorization license token file does not exist: %s"), *FilePath);
		return false;
	}

	FString FileText;
	if (!ReadTextFile(FilePath, FileText, OutError))
	{
		return false;
	}

	return FAuthorizationVerifier::ParseLicenseToken(FileText, OutToken, OutError);
}

bool FAuthorizationLicenseStore::SaveLicenseToken(const FAuthorizationLicenseToken& InToken, FString& OutError, const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
{
	FString FileText;
	if (!FAuthorizationVerifier::SerializeLicenseToken(InToken, FileText, true, OutError))
	{
		return false;
	}

	return WriteTextFile(GetLicenseTokenFilePath(InSource, InSettings), FileText, OutError);
}

bool FAuthorizationLicenseStore::LoadManifest(FAuthorizationManifest& OutManifest, FString& OutError, const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
{
	const FString FilePath = GetManifestFilePath(InSource, InSettings);
	if (!FPaths::FileExists(FilePath))
	{
		OutError = FString::Printf(TEXT("Authorization manifest file does not exist: %s"), *FilePath);
		return false;
	}

	FString FileText;
	if (!ReadTextFile(FilePath, FileText, OutError))
	{
		return false;
	}

	return FAuthorizationVerifier::ParseManifest(FileText, OutManifest, OutError);
}

bool FAuthorizationLicenseStore::LoadProjectManifest(FAuthorizationManifest& OutManifest, FString& OutError, const UAuthorizationSettings* InSettings)
{
	const FString FilePath = GetResolvedProjectManifestFilePath(InSettings);
	if (FilePath.IsEmpty())
	{
		OutError = TEXT("Authorization project manifest file path is empty.");
		return false;
	}

	if (!FPaths::FileExists(FilePath))
	{
		OutError = FString::Printf(TEXT("Authorization project manifest file does not exist: %s"), *FilePath);
		return false;
	}

	FString FileText;
	if (!ReadTextFile(FilePath, FileText, OutError))
	{
		return false;
	}

	return FAuthorizationVerifier::ParseManifest(FileText, OutManifest, OutError);
}

bool FAuthorizationLicenseStore::LoadBundledOfflineManifest(FAuthorizationManifest& OutManifest, FString& OutError, const UAuthorizationSettings* InSettings)
{
	const FString FilePath = GetBundledOfflineManifestFilePath(InSettings);
	if (!FPaths::FileExists(FilePath))
	{
		OutError = FString::Printf(TEXT("Bundled offline authorization manifest file does not exist: %s"), *FilePath);
		return false;
	}

	FString FileText;
	if (!ReadTextFile(FilePath, FileText, OutError))
	{
		return false;
	}

	return FAuthorizationVerifier::ParseManifest(FileText, OutManifest, OutError);
}

bool FAuthorizationLicenseStore::SaveManifest(const FAuthorizationManifest& InManifest, FString& OutError, const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
{
	FString FileText;
	if (!FAuthorizationVerifier::SerializeManifest(InManifest, FileText, true, OutError))
	{
		return false;
	}

	return WriteTextFile(GetManifestFilePath(InSource, InSettings), FileText, OutError);
}

bool FAuthorizationLicenseStore::LoadRuntimeState(FAuthorizationRuntimeState& OutRuntimeState, FString& OutError, const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
{
	const FString FilePath = GetRuntimeStateFilePath(InSource, InSettings);
	if (!FPaths::FileExists(FilePath))
	{
		OutError = FString::Printf(TEXT("Authorization runtime state file does not exist: %s"), *FilePath);
		return false;
	}

	return AuthorizationLicenseStorePrivate::LoadStructFile(FilePath, OutRuntimeState, OutError);
}

bool FAuthorizationLicenseStore::SaveRuntimeState(const FAuthorizationRuntimeState& InRuntimeState, FString& OutError, const EAuthorizationSourceType InSource, const UAuthorizationSettings* InSettings)
{
	return AuthorizationLicenseStorePrivate::SaveStructFile(GetRuntimeStateFilePath(InSource, InSettings), InRuntimeState, OutError);
}

bool FAuthorizationLicenseStore::DeletePersistedAuthorization(const EAuthorizationSourceType InSource, FString& OutError, const UAuthorizationSettings* InSettings)
{
	OutError.Empty();

	const TArray<FString> FilePaths =
	{
		GetLicenseTokenFilePath(InSource, InSettings),
		GetManifestFilePath(InSource, InSettings),
		GetRuntimeStateFilePath(InSource, InSettings)
	};

	for (const FString& FilePath : FilePaths)
	{
		if (FPaths::FileExists(FilePath) && !IFileManager::Get().Delete(*FilePath, false, true))
		{
			OutError = FString::Printf(TEXT("Failed to delete authorization file: %s"), *FilePath);
			return false;
		}
	}

	return true;
}

bool FAuthorizationLicenseStore::DeleteAllPersistedAuthorization(FString& OutError, const UAuthorizationSettings* InSettings)
{
	if (!DeletePersistedAuthorization(EAuthorizationSourceType::Online, OutError, InSettings))
	{
		return false;
	}

	return DeletePersistedAuthorization(EAuthorizationSourceType::Offline, OutError, InSettings);
}

bool FAuthorizationLicenseStore::ReadTextFile(const FString& FilePath, FString& OutText, FString& OutError)
{
	if (!FFileHelper::LoadFileToString(OutText, *FilePath))
	{
		OutError = FString::Printf(TEXT("Failed to read authorization file: %s"), *FilePath);
		return false;
	}

	return true;
}

bool FAuthorizationLicenseStore::WriteTextFile(const FString& FilePath, const FString& InText, FString& OutError)
{
	const FString DirectoryPath = FPaths::GetPath(FilePath);
	if (!IFileManager::Get().MakeDirectory(*DirectoryPath, true))
	{
		OutError = FString::Printf(TEXT("Failed to create authorization cache directory: %s"), *DirectoryPath);
		return false;
	}

	if (!FFileHelper::SaveStringToFile(InText, *FilePath))
	{
		OutError = FString::Printf(TEXT("Failed to write authorization file: %s"), *FilePath);
		return false;
	}

	return true;
}
