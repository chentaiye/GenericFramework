#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 提供坡向分析模块入口，加载 Aspect 组件、子系统和蓝图函数库。 */
class FAspectSystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
