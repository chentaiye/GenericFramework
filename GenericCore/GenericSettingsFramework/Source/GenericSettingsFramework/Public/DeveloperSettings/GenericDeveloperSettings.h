// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GenericDeveloperSettings.generated.h"

/** 统一 GenericFramework 运行时设置的容器与分类，供各业务设置类继承后进入同一项目设置面板。 */
UCLASS(MinimalAPI, Abstract, config=GenericSettings, DefaultConfig)
class UGenericDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	virtual FName GetContainerName() const override { return TEXT("GenericFramework"); }
	virtual FName GetCategoryName() const override { return TEXT("Runtime"); }
	virtual FName GetSectionName() const override { return Super::GetSectionName(); }
};
