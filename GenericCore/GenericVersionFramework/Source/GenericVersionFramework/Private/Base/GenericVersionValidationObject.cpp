// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Base/GenericVersionValidationObject.h"

FGenericVersionValidationResult FGenericVersionValidationObject::ValidateGenericVersion(const FGenericVersionContext& Context)
{
	if (!Context.VersionData.IsValid())
	{
		return FGenericVersionValidationResult::Failed(TEXT("InvalidVersionData"), NSLOCTEXT("GenericVersion", "BaseValidationInvalidVersionData", "Version data is invalid."));
	}

	return FGenericVersionValidationResult::Success();
}

void FGenericVersionValidationObject::HandleVersionValidationSuccess(const FGenericVersionValidationResult& Result)
{
}

void FGenericVersionValidationObject::HandleVersionValidationFailure(const FGenericVersionValidationResult& Result)
{
}
