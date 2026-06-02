// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Base/GenericVersionObject.h"

UObject* FGenericVersionObject::GetVersionTargetObject() const
{
	return nullptr;
}

FGenericVersionData FGenericVersionObject::GetVersion() const
{
	return Version;
}

void FGenericVersionObject::SetVersion(const FGenericVersionData& InVersion)
{
	Version = InVersion;
}

FString FGenericVersionObject::GetPropertySchemaSignature() const
{
	return PropertySchemaSignature;
}

void FGenericVersionObject::SetPropertySchemaSignature(const FString& InPropertySchemaSignature)
{
	PropertySchemaSignature = InPropertySchemaSignature;
}

FString FGenericVersionObject::BuildCurrentPropertySchemaSignature() const
{
	return PropertySchemaSignature;
}
