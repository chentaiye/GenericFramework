#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 声明通用Gameplay系统模块。 */
class FGenericGameplaySystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
