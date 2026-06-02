// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Base/GenericVersionMigrationObject.h"

FGenericVersionMigrationResult FGenericVersionMigrationObject::MigrateGenericVersion(const FGenericVersionContext& Context)
{
	return FGenericVersionMigrationResult::Failed(
		Context.VersionData.Version,
		Context.VersionDefinition.Version,
		TEXT("MigrationNotImplemented"),
		NSLOCTEXT("GenericVersion", "BaseMigrationNotImplemented", "Version migration is not implemented."));
}

void FGenericVersionMigrationObject::HandleVersionMigrationSuccess(const FGenericVersionMigrationResult& Result)
{
}

void FGenericVersionMigrationObject::HandleVersionMigrationFailure(const FGenericVersionMigrationResult& Result)
{
}
