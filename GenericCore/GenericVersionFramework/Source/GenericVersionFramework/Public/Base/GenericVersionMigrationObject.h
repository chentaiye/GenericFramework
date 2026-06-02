// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/GenericVersionTypes.h"

class GENERICVERSIONFRAMEWORK_API FGenericVersionMigrationObject
{
public:
	virtual ~FGenericVersionMigrationObject() = default;

	virtual FGenericVersionMigrationResult MigrateGenericVersion(const FGenericVersionContext& Context);
	virtual void HandleVersionMigrationSuccess(const FGenericVersionMigrationResult& Result);
	virtual void HandleVersionMigrationFailure(const FGenericVersionMigrationResult& Result);
};
