// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/GenericVersionMigrationSubsystem.h"

#include "Base/GenericVersionMigrationObject.h"
#include "Base/GenericVersionObject.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Subsystem/GenericVersionDataSubsystem.h"

UGenericVersionMigrationSubsystem* UGenericVersionMigrationSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UGenericVersionMigrationSubsystem>();
		}
	}

	if (UGameInstance* GameInstance = const_cast<UGameInstance*>(Cast<UGameInstance>(WorldContextObject)))
	{
		return GameInstance->GetSubsystem<UGenericVersionMigrationSubsystem>();
	}

	return nullptr;
}

FGenericVersionMigrationResult UGenericVersionMigrationSubsystem::MigrateObject(FGenericVersionObject* TargetObject, UObject* ContextObject)
{
	FGenericVersionContext Context;
	if (!BuildVersionContext(TargetObject, ContextObject, Context))
	{
		return MakeMigrationFailed(FGenericVersionInfo(), FGenericVersionInfo(), TEXT("VersionDataMissing"), NSLOCTEXT("GenericVersion", "MigrationVersionDataMissing", "Version data is missing from the central version subsystem."));
	}

	const FGenericVersionMigrationResult Result = TargetObject->MigrateGenericVersion(Context);
	HandleMigrationResult(TargetObject, Result);
	return Result;
}

bool UGenericVersionMigrationSubsystem::HandleMigrationResult(FGenericVersionMigrationObject* TargetObject, const FGenericVersionMigrationResult& Result)
{
	if (!TargetObject)
	{
		return false;
	}

	if (Result.bSuccess)
	{
		TargetObject->HandleVersionMigrationSuccess(Result);
	}
	else
	{
		TargetObject->HandleVersionMigrationFailure(Result);
	}
	return true;
}

FGenericVersionMigrationResult UGenericVersionMigrationSubsystem::MakeMigrationSuccess(const FGenericVersionInfo& SourceVersion, const FGenericVersionInfo& TargetVersion, const FText& Message) const
{
	return FGenericVersionMigrationResult::Success(SourceVersion, TargetVersion, Message);
}

FGenericVersionMigrationResult UGenericVersionMigrationSubsystem::MakeMigrationFailed(const FGenericVersionInfo& SourceVersion, const FGenericVersionInfo& TargetVersion, const FName ErrorCode, const FText& Message) const
{
	return FGenericVersionMigrationResult::Failed(SourceVersion, TargetVersion, ErrorCode, Message);
}

bool UGenericVersionMigrationSubsystem::BuildVersionContext(FGenericVersionObject* TargetObject, UObject* ContextObject, FGenericVersionContext& OutContext) const
{
	if (!TargetObject)
	{
		return false;
	}

	const UGenericVersionDataSubsystem* VersionSubsystem = UGenericVersionDataSubsystem::Get(this);
	if (!VersionSubsystem || !VersionSubsystem->GetVersionData(TargetObject, OutContext.VersionData))
	{
		return false;
	}

	OutContext.TargetObject = TargetObject->GetVersionTargetObject();
	OutContext.VersionKey = OutContext.VersionData.VersionKey;
	VersionSubsystem->GetVersionDefinition(OutContext.VersionKey, OutContext.VersionDefinition);
	OutContext.ContextObject = ContextObject;
	return true;
}
