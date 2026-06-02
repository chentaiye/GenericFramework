#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 声明通用资源加载系统模块。 */
class FGenericAssetLoadSystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
