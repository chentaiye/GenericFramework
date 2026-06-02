// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Types/GenericVersionTypes.h"

UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayVersion, "GameplayVersion");

FGenericVersionValidationResult FGenericVersionValidationResult::Success(const FText& InMessage)
{
	FGenericVersionValidationResult Result;
	Result.Status = EGenericVersionValidationStatus::Success;
	Result.Message = InMessage;
	return Result;
}

FGenericVersionValidationResult FGenericVersionValidationResult::Warning(const FName InErrorCode, const FText& InMessage)
{
	FGenericVersionValidationResult Result;
	Result.Status = EGenericVersionValidationStatus::Warning;
	Result.ErrorCode = InErrorCode;
	Result.Message = InMessage;
	return Result;
}

FGenericVersionValidationResult FGenericVersionValidationResult::Failed(const FName InErrorCode, const FText& InMessage)
{
	FGenericVersionValidationResult Result;
	Result.Status = EGenericVersionValidationStatus::Failed;
	Result.ErrorCode = InErrorCode;
	Result.Message = InMessage;
	return Result;
}

FGenericVersionMigrationResult FGenericVersionMigrationResult::Success(const FGenericVersionInfo& InSourceVersion, const FGenericVersionInfo& InTargetVersion, const FText& InMessage)
{
	FGenericVersionMigrationResult Result;
	Result.SourceVersion = InSourceVersion;
	Result.TargetVersion = InTargetVersion;
	Result.bSuccess = true;
	Result.Message = InMessage;
	return Result;
}

FGenericVersionMigrationResult FGenericVersionMigrationResult::Failed(const FGenericVersionInfo& InSourceVersion, const FGenericVersionInfo& InTargetVersion, const FName InErrorCode, const FText& InMessage)
{
	FGenericVersionMigrationResult Result;
	Result.SourceVersion = InSourceVersion;
	Result.TargetVersion = InTargetVersion;
	Result.bSuccess = false;
	Result.ErrorCode = InErrorCode;
	Result.Message = InMessage;
	return Result;
}
