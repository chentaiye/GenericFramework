// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/GenericSaveGame.h"

#include "GameplayMessageSubsystem.h"
#include "Misc/SecureHash.h"
#include "Subsystem/Base/GenericSaveGameSubsystem.h"
#include "UObject/FieldIterator.h"
#include "UObject/UnrealType.h"

namespace
{
	FString GetSaveGameClassPackageName(const UGenericSaveGame* SaveGame)
	{
		return SaveGame && SaveGame->GetClass() && SaveGame->GetClass()->GetPackage()
			       ? SaveGame->GetClass()->GetPackage()->GetName()
			       : FString();
	}

	bool IsFrameworkSaveGameProperty(const FProperty* Property)
	{
		const UStruct* OwnerStruct = Property ? Property->GetOwnerStruct() : nullptr;
		return OwnerStruct == UGenericSaveGame::StaticClass() || OwnerStruct == USaveGame::StaticClass();
	}

	void BroadcastSaveGameDirtyMessage(const UObject* WorldContextObject, const FString& SlotName, UGenericSaveGame* SaveGame)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSaveGameDirtyMessage Message;
		Message.SlotName = SlotName;
		Message.SaveGame = SaveGame;
		Message.bIsDirty = SaveGame ? SaveGame->GetIsDirty() : false;
		Message.DirtySerial = SaveGame ? SaveGame->GetDirtySerial() : 0;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_SaveGame_OnSaveGameDirty, Message);
	}
}

UGenericSaveGame::UGenericSaveGame(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SetClassPackageName(GetClass()->GetPackage() ? GetClass()->GetPackage()->GetName() : FString());
	SetSaveTime(FDateTime::Now());
	Version.VersionKey = TAG_GameplayVersion_SaveGame;
	if (Version.SourceName.IsEmpty())
	{
		Version.SourceName = TEXT("SaveGame");
	}
}

void UGenericSaveGame::OnInitialized_Implementation()
{
}

void UGenericSaveGame::OnRefresh_Implementation()
{
}

void UGenericSaveGame::OnDeinitialized_Implementation()
{
}

FString UGenericSaveGame::GetSlotName()
{
	return SlotName;
}

void UGenericSaveGame::SetSlotName(const FString& InSlotName)
{
	SlotName = InSlotName;
}

FString UGenericSaveGame::GetPathName()
{
	return PathName;
}

void UGenericSaveGame::SetPathName(const FString& InPathName)
{
	PathName = InPathName;
}

FString UGenericSaveGame::GetClassPackageName()
{
	return ClassPackageName;
}

void UGenericSaveGame::SetClassPackageName(const FString& InClassPackageName)
{
	ClassPackageName = InClassPackageName;
}

FDateTime UGenericSaveGame::GetSaveTime()
{
	return SaveTime;
}

void UGenericSaveGame::SetSaveTime(const FDateTime& InSaveTime)
{
	SaveTime = InSaveTime;
}

bool UGenericSaveGame::GetIsDirty() const
{
	return bIsDirty;
}

void UGenericSaveGame::MarkAsDirty()
{
	SetDirtyState(true, true);
}

bool UGenericSaveGame::SaveInstant()
{
	UGenericSaveGameSubsystem* SaveGameSubsystem = UGenericSaveGameSubsystem::Get(this);
	return SaveGameSubsystem && SaveGameSubsystem->AsyncSaveGameToSlot(this);
}

bool UGenericSaveGame::ClearDirty(const int32 ExpectedDirtySerial)
{
	if (ExpectedDirtySerial != INDEX_NONE && DirtySerial != ExpectedDirtySerial)
	{
		return false;
	}

	SetDirtyState(false, true);
	return true;
}

int32 UGenericSaveGame::GetDirtySerial() const
{
	return DirtySerial;
}

UObject* UGenericSaveGame::GetVersionTargetObject() const
{
	return const_cast<UGenericSaveGame*>(this);
}

FGenericVersionData UGenericSaveGame::GetVersion() const
{
	return Version;
}

void UGenericSaveGame::SetVersion(const FGenericVersionData& InVersion)
{
	Version = InVersion;
}

FString UGenericSaveGame::GetPropertySchemaSignature() const
{
	return PropertySchemaSignature;
}

void UGenericSaveGame::SetPropertySchemaSignature(const FString& InPropertySchemaSignature)
{
	PropertySchemaSignature = InPropertySchemaSignature;
}

FString UGenericSaveGame::BuildCurrentPropertySchemaSignature() const
{
	TArray<FString> PropertyEntries;
	for (TFieldIterator<FProperty> PropertyIt(GetClass(), EFieldIteratorFlags::IncludeSuper); PropertyIt; ++PropertyIt)
	{
		const FProperty* Property = *PropertyIt;
		if (!Property || !Property->HasAnyPropertyFlags(CPF_SaveGame) || IsFrameworkSaveGameProperty(Property))
		{
			continue;
		}

		const UStruct* OwnerStruct = Property->GetOwnerStruct();
		PropertyEntries.Add(FString::Printf(
			TEXT("%s.%s|%s|%d"),
			OwnerStruct ? *OwnerStruct->GetName() : TEXT("Unknown"),
			*Property->GetName(),
			*Property->GetCPPType(),
			Property->ArrayDim));
	}

	if (PropertyEntries.IsEmpty())
	{
		return FString();
	}

	PropertyEntries.Sort();
	return FMD5::HashAnsiString(*FString::Join(PropertyEntries, TEXT(";")));
}

void UGenericSaveGame::SetDirtyState(const bool bInIsDirty, const bool bBroadcast)
{
	if (bIsDirty == bInIsDirty && !bBroadcast)
	{
		return;
	}

	if (bInIsDirty)
	{
		++DirtySerial;
	}

	bIsDirty = bInIsDirty;
	if (bBroadcast)
	{
		const UObject* MessageContextObject = UGenericSaveGameSubsystem::Get(this);
		if (!MessageContextObject)
		{
			MessageContextObject = this;
		}
		BroadcastSaveGameDirtyMessage(MessageContextObject, SlotName, this);
	}
}

FGenericVersionValidationResult UGenericSaveGame::ValidateGenericVersion(const FGenericVersionContext& Context)
{
	if (!Context.VersionData.VersionKey.MatchesTag(TAG_GameplayVersion_SaveGame))
	{
		return FGenericVersionValidationResult::Failed(
			TEXT("InvalidSaveGameVersionKey"),
			NSLOCTEXT("GenericSaveGame", "InvalidSaveGameVersionKey", "SaveGame version key must be under GameplayVersion.SaveGame."));
	}

	const FString CurrentClassPackageName = GetSaveGameClassPackageName(this);
	if (!ClassPackageName.IsEmpty() && !CurrentClassPackageName.IsEmpty() && ClassPackageName != CurrentClassPackageName)
	{
		return FGenericVersionValidationResult::Warning(
			TEXT("SaveGameClassPackageChanged"),
			NSLOCTEXT("GenericSaveGame", "SaveGameClassPackageChanged", "SaveGame class package changed and should be migrated before registration."));
	}

	const FString CurrentPropertySchemaSignature = BuildCurrentPropertySchemaSignature();
	if (!CurrentPropertySchemaSignature.IsEmpty())
	{
		if (PropertySchemaSignature.IsEmpty())
		{
			return FGenericVersionValidationResult::Warning(
				TEXT("SaveGamePropertySchemaMissing"),
				NSLOCTEXT("GenericSaveGame", "SaveGamePropertySchemaMissing", "SaveGame property schema metadata is missing and should be initialized before registration."));
		}

		if (PropertySchemaSignature != CurrentPropertySchemaSignature)
		{
			return FGenericVersionValidationResult::Warning(
				TEXT("SaveGamePropertySchemaChanged"),
				NSLOCTEXT("GenericSaveGame", "SaveGamePropertySchemaChanged", "SaveGame persisted property schema differs from the current class and should be migrated before registration."));
		}
	}
	else if (!PropertySchemaSignature.IsEmpty())
	{
		return FGenericVersionValidationResult::Warning(
			TEXT("SaveGamePropertySchemaChanged"),
			NSLOCTEXT("GenericSaveGame", "SaveGamePropertySchemaCleared", "SaveGame persisted property schema no longer exists on the current class and should be migrated before registration."));
	}

	return FGenericVersionValidationResult::Success(NSLOCTEXT("GenericSaveGame", "SaveGameVersionValidationSuccess", "SaveGame version metadata is compatible."));
}

void UGenericSaveGame::HandleVersionValidationSuccess(const FGenericVersionValidationResult& Result)
{
}

void UGenericSaveGame::HandleVersionValidationFailure(const FGenericVersionValidationResult& Result)
{
}

FGenericVersionMigrationResult UGenericSaveGame::MigrateGenericVersion(const FGenericVersionContext& Context)
{
	if (!Context.VersionData.IsValid() || !Context.VersionDefinition.IsValid())
	{
		return FGenericVersionMigrationResult::Failed(
			Context.VersionData.Version,
			Context.VersionDefinition.Version,
			TEXT("InvalidSaveGameVersionContext"),
			NSLOCTEXT("GenericSaveGame", "InvalidSaveGameVersionContext", "SaveGame version context is invalid."));
	}

	if (!Context.VersionData.VersionKey.MatchesTag(TAG_GameplayVersion_SaveGame))
	{
		return FGenericVersionMigrationResult::Failed(
			Context.VersionData.Version,
			Context.VersionDefinition.Version,
			TEXT("InvalidSaveGameVersionKey"),
			NSLOCTEXT("GenericSaveGame", "MigrationInvalidSaveGameVersionKey", "SaveGame version key must be under GameplayVersion.SaveGame."));
	}

	FGenericVersionData MigratedVersion = Context.VersionData;
	MigratedVersion.Version = Context.VersionDefinition.Version;
	if (MigratedVersion.SourceName.IsEmpty())
	{
		MigratedVersion.SourceName = Context.VersionDefinition.SourceName;
	}
	
	SetVersion(MigratedVersion);
	SetClassPackageName(GetSaveGameClassPackageName(this));
	SetPropertySchemaSignature(BuildCurrentPropertySchemaSignature());

	return FGenericVersionMigrationResult::Success(
		Context.VersionData.Version,
		Context.VersionDefinition.Version,
		NSLOCTEXT("GenericSaveGame", "SaveGameVersionMigrationSuccess", "SaveGame version metadata was migrated."));
}

void UGenericSaveGame::HandleVersionMigrationSuccess(const FGenericVersionMigrationResult& Result)
{
}

void UGenericSaveGame::HandleVersionMigrationFailure(const FGenericVersionMigrationResult& Result)
{
}
