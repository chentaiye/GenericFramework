#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** GenericInputSystem 运行时模块入口，提供输入相关类型随模块加载和卸载的生命周期钩子。 */
class FGenericInputSystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
