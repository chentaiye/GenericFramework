// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Subsystem/GenericVersionDataSubsystem.h"

#include "Base/GenericVersionObject.h"
#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Settings/GenericVersionSettings.h"

UGenericVersionDataSubsystem* UGenericVersionDataSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			return GameInstance->GetSubsystem<UGenericVersionDataSubsystem>();
		}
	}

	if (UGameInstance* GameInstance = const_cast<UGameInstance*>(Cast<UGameInstance>(WorldContextObject)))
	{
		return GameInstance->GetSubsystem<UGenericVersionDataSubsystem>();
	}

	return nullptr;
}

void UGenericVersionDataSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	RegisterVersionDefinitionsFromSettings();
}

int32 UGenericVersionDataSubsystem::RegisterVersionDefinitionsFromSettings()
{
	const UGenericVersionSettings* VersionSettings = UGenericVersionSettings::Get();
	if (!VersionSettings)
	{
		return 0;
	}

	int32 RegisteredCount = 0;
	for (const FGenericVersionDefinition& VersionDefinition : VersionSettings->VersionDefinitions)
	{
		if (SetVersionDefinition(VersionDefinition))
		{
			++RegisteredCount;
		}
	}
	return RegisteredCount;
}

bool UGenericVersionDataSubsystem::SetVersionDefinition(const FGenericVersionDefinition& VersionDefinition)
{
	if (!VersionDefinition.IsValid())
	{
		return false;
	}

	VersionDefinitionByKey.Add(VersionDefinition.VersionKey, VersionDefinition);
	return true;
}

bool UGenericVersionDataSubsystem::GetVersionDefinition(const FGameplayTag VersionKey, FGenericVersionDefinition& OutVersionDefinition) const
{
	if (!VersionKey.IsValid())
	{
		return false;
	}

	if (const FGenericVersionDefinition* VersionDefinition = VersionDefinitionByKey.Find(VersionKey))
	{
		OutVersionDefinition = *VersionDefinition;
		return true;
	}

	return false;
}

bool UGenericVersionDataSubsystem::RemoveVersionDefinition(const FGameplayTag VersionKey)
{
	return VersionKey.IsValid() && VersionDefinitionByKey.Remove(VersionKey) > 0;
}

void UGenericVersionDataSubsystem::ClearVersionDefinitions()
{
	VersionDefinitionByKey.Reset();
}

bool UGenericVersionDataSubsystem::ResolveVersionData(const FGenericVersionData& SourceVersionData, FGenericVersionData& OutVersionData) const
{
	if (!SourceVersionData.IsValid())
	{
		return false;
	}

	const FGenericVersionDefinition* VersionDefinition = VersionDefinitionByKey.Find(SourceVersionData.VersionKey);
	if (!VersionDefinition || !VersionDefinition->IsValid())
	{
		return false;
	}

	OutVersionData = SourceVersionData;
	if (OutVersionData.SourceName.IsEmpty())
	{
		OutVersionData.SourceName = VersionDefinition->SourceName;
	}
	return OutVersionData.IsValid();
}

bool UGenericVersionDataSubsystem::RefreshVersionData(UObject* TargetObject, const FGenericVersionData& VersionData, FGenericVersionData& OutVersionData)
{
	if (!SetVersionData(TargetObject, VersionData))
	{
		return false;
	}

	return GetVersionData(TargetObject, OutVersionData);
}

bool UGenericVersionDataSubsystem::RefreshVersionData(FGenericVersionObject* TargetObject, const FGenericVersionData& VersionData, FGenericVersionData& OutVersionData)
{
	if (!SetVersionData(TargetObject, VersionData))
	{
		return false;
	}

	return GetVersionData(TargetObject, OutVersionData);
}

bool UGenericVersionDataSubsystem::GetVersionData(UObject* TargetObject, FGenericVersionData& OutVersionData) const
{
	if (!IsValid(TargetObject))
	{
		return false;
	}

	if (const FGenericVersionData* VersionData = VersionDataByObject.Find(FObjectKey(TargetObject)))
	{
		OutVersionData = *VersionData;
		return true;
	}

	return false;
}

bool UGenericVersionDataSubsystem::GetVersionData(FGenericVersionObject* TargetObject, FGenericVersionData& OutVersionData) const
{
	if (!TargetObject)
	{
		return false;
	}

	if (const FGenericVersionData* VersionData = VersionDataByVersionObject.Find(TargetObject))
	{
		OutVersionData = *VersionData;
		return true;
	}

	return false;
}

bool UGenericVersionDataSubsystem::SetVersionData(UObject* TargetObject, const FGenericVersionData& VersionData)
{
	FGenericVersionData ResolvedVersionData;
	if (!IsValid(TargetObject) || !ResolveVersionData(VersionData, ResolvedVersionData))
	{
		return false;
	}

	VersionDataByObject.Add(FObjectKey(TargetObject), ResolvedVersionData);
	return true;
}

bool UGenericVersionDataSubsystem::SetVersionData(FGenericVersionObject* TargetObject, const FGenericVersionData& VersionData)
{
	FGenericVersionData ResolvedVersionData;
	if (!TargetObject || !ResolveVersionData(VersionData, ResolvedVersionData))
	{
		return false;
	}

	VersionDataByVersionObject.Add(TargetObject, ResolvedVersionData);
	return true;
}

bool UGenericVersionDataSubsystem::RemoveVersionData(UObject* TargetObject)
{
	if (!IsValid(TargetObject))
	{
		return false;
	}

	const FObjectKey ObjectKey(TargetObject);
	const FGenericVersionData* VersionData = VersionDataByObject.Find(ObjectKey);
	if (!VersionData)
	{
		return false;
	}

	VersionDataByObject.Remove(ObjectKey);
	return true;
}

bool UGenericVersionDataSubsystem::RemoveVersionData(FGenericVersionObject* TargetObject)
{
	return TargetObject && VersionDataByVersionObject.Remove(TargetObject) > 0;
}

bool UGenericVersionDataSubsystem::RemoveVersionDataByKey(const FGameplayTag VersionKey)
{
	if (!VersionKey.IsValid())
	{
		return false;
	}

	bool bRemoved = false;
	for (TMap<FObjectKey, FGenericVersionData>::TIterator It(VersionDataByObject); It; ++It)
	{
		if (It.Value().VersionKey == VersionKey)
		{
			It.RemoveCurrent();
			bRemoved = true;
		}
	}
	for (TMap<const FGenericVersionObject*, FGenericVersionData>::TIterator It(VersionDataByVersionObject); It; ++It)
	{
		if (It.Value().VersionKey == VersionKey)
		{
			It.RemoveCurrent();
			bRemoved = true;
		}
	}
	return bRemoved;
}

void UGenericVersionDataSubsystem::ClearVersionData()
{
	VersionDataByObject.Reset();
	VersionDataByVersionObject.Reset();
}
