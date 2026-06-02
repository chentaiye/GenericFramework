#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 提供天际线后期处理模块入口，加载 Skyline 组件、子系统和蓝图函数库。 */
class FSkylineSystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
