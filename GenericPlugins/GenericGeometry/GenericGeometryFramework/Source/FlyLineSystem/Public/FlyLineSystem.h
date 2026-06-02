#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 提供飞线系统模块入口，注册端点组件、飞线子系统和蓝图辅助函数。 */
class FFlyLineSystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
