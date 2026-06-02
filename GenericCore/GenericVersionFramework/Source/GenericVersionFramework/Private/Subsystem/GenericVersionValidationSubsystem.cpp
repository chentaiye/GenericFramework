// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/GenericVersionValidationSubsystem.h"

#include "Base/GenericVersionObject.h"
#include "Base/GenericVersionValidationObject.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Subsystem/GenericVersionDataSubsystem.h"

namespace
{
	int32 GetValidationSeverity(const FGenericVersionValidationResult& Result)
	{
		if (Result.IsFailed())
		{
			return 2;
		}
		if (Result.IsWarning())
		{
			return 1;
		}
		return 0;
	}

	FGenericVersionValidationResult SelectMoreSevereValidationResult(const FGenericVersionValidationResult& A, const FGenericVersionValidationResult& B)
	{
		return GetValidationSeverity(B) > GetValidationSeverity(A) ? B : A;
	}
}

UGenericVersionValidationSubsystem* UGenericVersionValidationSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UGenericVersionValidationSubsystem>();
		}
	}

	if (UGameInstance* GameInstance = const_cast<UGameInstance*>(Cast<UGameInstance>(WorldContextObject)))
	{
		return GameInstance->GetSubsystem<UGenericVersionValidationSubsystem>();
	}

	return nullptr;
}

FGenericVersionValidationResult UGenericVersionValidationSubsystem::ValidateObject(FGenericVersionObject* TargetObject, UObject* ContextObject)
{
	FGenericVersionContext Context;
	if (!BuildVersionContext(TargetObject, ContextObject, Context))
	{
		return MakeValidationFailed(TEXT("VersionDataMissing"), NSLOCTEXT("GenericVersion", "VersionDataMissing", "Version data is missing from the central version subsystem."));
	}

	FGenericVersionValidationResult Result = ValidateVersionContext(Context);
	const FGenericVersionValidationResult ObjectResult = TargetObject->ValidateGenericVersion(Context);
	Result = SelectMoreSevereValidationResult(Result, ObjectResult);

	HandleValidationResult(TargetObject, Result);
	return Result;
}

FGenericVersionValidationResult UGenericVersionValidationSubsystem::ValidateVersionContext(const FGenericVersionContext& Context) const
{
	if (!Context.VersionData.IsValid() || !Context.VersionDefinition.IsValid())
	{
		return MakeValidationFailed(TEXT("InvalidVersionContext"), NSLOCTEXT("GenericVersion", "InvalidVersionContext", "Version context is invalid."));
	}

	if (Context.VersionData.Version < Context.VersionDefinition.MinimumSupportedVersion)
	{
		return MakeValidationFailed(TEXT("VersionBelowMinimumSupported"), NSLOCTEXT("GenericVersion", "VersionBelowMinimumSupported", "Object version is below the minimum supported version."));
	}

	if (Context.VersionData.Version > Context.VersionDefinition.Version)
	{
		return MakeValidationFailed(TEXT("VersionNewerThanDefinition"), NSLOCTEXT("GenericVersion", "VersionNewerThanDefinition", "Object version is newer than the current version definition."));
	}

	if (Context.VersionData.Version < Context.VersionDefinition.Version)
	{
		return MakeValidationWarning(TEXT("VersionRequiresMigration"), NSLOCTEXT("GenericVersion", "VersionRequiresMigration", "Object version is older than the current version definition and may need migration."));
	}

	return MakeValidationSuccess(NSLOCTEXT("GenericVersion", "VersionValidationSuccess", "Object version matches the current version definition."));
}

bool UGenericVersionValidationSubsystem::HandleValidationResult(FGenericVersionValidationObject* TargetObject, const FGenericVersionValidationResult& Result)
{
	if (!TargetObject)
	{
		return false;
	}

	if (Result.IsBlocking())
	{
		TargetObject->HandleVersionValidationFailure(Result);
	}
	else
	{
		TargetObject->HandleVersionValidationSuccess(Result);
	}
	return true;
}

FGenericVersionValidationResult UGenericVersionValidationSubsystem::MakeValidationSuccess(const FText& Message) const
{
	return FGenericVersionValidationResult::Success(Message);
}

FGenericVersionValidationResult UGenericVersionValidationSubsystem::MakeValidationWarning(const FName ErrorCode, const FText& Message) const
{
	return FGenericVersionValidationResult::Warning(ErrorCode, Message);
}

FGenericVersionValidationResult UGenericVersionValidationSubsystem::MakeValidationFailed(const FName ErrorCode, const FText& Message) const
{
	return FGenericVersionValidationResult::Failed(ErrorCode, Message);
}

bool UGenericVersionValidationSubsystem::BuildVersionContext(FGenericVersionObject* TargetObject, UObject* ContextObject, FGenericVersionContext& OutContext) const
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
