// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

IOTPLATFORMHOMEASSISTANT_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogIOTHomeAssistant, Log, All);

/** 在模块启动和关闭时注册 Home Assistant 平台适配器工厂，让 GenericIOT 子系统可以通过 ModularFeatures 创建对应平台适配器。 */
class FIOTPlatformHomeAssistantModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
