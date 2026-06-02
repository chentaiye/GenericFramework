// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/GenericVersionTypes.h"

class GENERICVERSIONFRAMEWORK_API FGenericVersionValidationObject
{
public:
	virtual ~FGenericVersionValidationObject() = default;

	virtual FGenericVersionValidationResult ValidateGenericVersion(const FGenericVersionContext& Context);
	virtual void HandleVersionValidationSuccess(const FGenericVersionValidationResult& Result);
	virtual void HandleVersionValidationFailure(const FGenericVersionValidationResult& Result);
};
