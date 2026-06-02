#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 声明随机Seed生成模块。 */
class FGenerateRandomSeedFrameworkModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
