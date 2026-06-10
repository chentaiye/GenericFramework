// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeveloperSettings/GenericDeveloperSettings.h"
#include "GenericSaveGameSettings.generated.h"

UCLASS(MinimalAPI, config=GenericSettings, DefaultConfig)
class UGenericSaveGameSettings : public UGenericDeveloperSettings
{
	GENERATED_BODY()

public:
	static GENERICSAVEGAMESYSTEM_API UGenericSaveGameSettings* Get();

	virtual FName GetSectionName() const override { return TEXT("SaveGameSettings"); }
#if WITH_EDITOR
	virtual FText GetSectionText() const override { return NSLOCTEXT("GenericSaveGame", "SaveGameSettingsSectionText", "SaveGameSettings"); }
#endif

public:
	UPROPERTY(Config, EditAnywhere, Category="AutoSave")
	bool bEnableAutoSave = true;

	UPROPERTY(Config, EditAnywhere, Category="AutoSave", meta=(ClampMin="0.1", UIMin="0.1"))
	float AutoSaveInterval = 30.0f;
};
