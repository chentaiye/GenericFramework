#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 声明窗口生成模块。 */
class FGenericWindowFrameworkModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
