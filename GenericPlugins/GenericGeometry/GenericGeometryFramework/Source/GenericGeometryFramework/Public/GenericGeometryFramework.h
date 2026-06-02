#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 提供几何工具的基础模块入口，集中注册通用类型、日志和共享工具函数。 */
class FGenericGeometryFrameworkModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
