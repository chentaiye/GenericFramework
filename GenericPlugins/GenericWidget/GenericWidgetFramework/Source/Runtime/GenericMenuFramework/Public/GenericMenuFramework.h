#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 提供 GenericMenuFramework 运行时模块的启动和关闭入口。 */
class FGenericMenuFrameworkModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
