// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericVersionMigrationObject.h"
#include "Base/GenericVersionValidationObject.h"

class GENERICVERSIONFRAMEWORK_API FGenericVersionObject : public FGenericVersionMigrationObject, public FGenericVersionValidationObject
{
public:
	virtual ~FGenericVersionObject() override = default;

	virtual UObject* GetVersionTargetObject() const;
	virtual FGenericVersionData GetVersion() const;
	virtual void SetVersion(const FGenericVersionData& InVersion);

	virtual FString GetPropertySchemaSignature() const;
	virtual void SetPropertySchemaSignature(const FString& InPropertySchemaSignature);
	virtual FString BuildCurrentPropertySchemaSignature() const;

private:
	FGenericVersionData Version;
	FString PropertySchemaSignature;
};
