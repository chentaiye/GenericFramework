// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeveloperSettings/GenericDeveloperSettings.h"
#include "GenericDeveloperEdSettings.generated.h"

/** 统一 GenericFramework 编辑器设置的分类，供编辑器扩展设置类进入同一项目设置面板。 */
UCLASS(MinimalAPI, Abstract, config=GenericEdSettings, DefaultConfig)
class UGenericDeveloperEdSettings : public UGenericDeveloperSettings
{
	GENERATED_BODY()

public:
	virtual FName GetCategoryName() const override { return TEXT("Editor"); }
};
