#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 声明通用Gameplay流程系统模块。 */
class FGenericGameplayFlowSystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
