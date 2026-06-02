// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ExtraProcType.h"
#include "DeveloperSettings/GenericDeveloperSettings.h"
#include "ExtraProcSettings.generated.h"

/** 保存外部进程开发者设置，ExtraProc 子系统在初始化和 PIE 流程中读取自动启动配置。 */
UCLASS(MinimalAPI)
class UExtraProcSettings : public UGenericDeveloperSettings
{
	GENERATED_BODY()

public:
	/** 返回可变默认设置对象，供 ExtraProc 子系统读取自动启动列表。 */
	static ThisClass* Get() { return GetMutableDefault<ThisClass>(); }

public:
	/** 自动启动外部进程配置列表，LaunchAllProc 只处理启用 bAutoLaunch 的条目。 */
	UPROPERTY(Config, EditAnywhere, Category="ExtraProc")
	TArray<FProcAutoStartUpInfo> AutoStartUpExtraProcList;
};
