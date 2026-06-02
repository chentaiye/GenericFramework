#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 声明通用线程系统模块，接入 UE 模块启动和关闭生命周期。 */
class FGenericThreadSystemModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
