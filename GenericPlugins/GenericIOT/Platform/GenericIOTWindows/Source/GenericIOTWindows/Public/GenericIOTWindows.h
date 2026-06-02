// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** GenericIOTWindows运行时模块，在加载期间注册Windows平台的Home Assistant地址发现提供器，供IOT子系统自动发现流程补充候选BaseUrl。 */
class FGenericIOTWindowsModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
