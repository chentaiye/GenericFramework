// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DeveloperSettings/GenericDeveloperSettings.h"
#include "GenericGlobalSettings.generated.h"

/** 保存框架级全局设置，供 Settings 面板注册入口和运行时框架公共逻辑读取。 */
UCLASS(MinimalAPI)
class UGenericGlobalSettings : public UGenericDeveloperSettings
{
	GENERATED_BODY()

public:
	static ThisClass* Get() { return GetMutableDefault<ThisClass>(); }

	virtual FName GetContainerName() const override { return "GenericFramework"; }
	virtual FName GetCategoryName() const override { return "Global"; }
	virtual FName GetSectionName() const override { return "Global"; }

public:
	/** 保留框架全局验证开关，便于设置面板和运行时代码确认配置通路是否生效。 */
	UPROPERTY(Config, EditAnywhere, Category="Generic Global Settings|Settings")
	bool bTest=false;
};
