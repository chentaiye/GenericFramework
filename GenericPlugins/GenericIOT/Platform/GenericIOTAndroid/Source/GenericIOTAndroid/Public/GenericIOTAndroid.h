// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** Android 平台 IOT 模块入口，负责在模块生命周期内注册平台发现提供器，使 UIOTSubsystem 自动发现流程能获得适用于 Android 的 Home Assistant 候选地址。 */
class FGenericIOTAndroidModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
