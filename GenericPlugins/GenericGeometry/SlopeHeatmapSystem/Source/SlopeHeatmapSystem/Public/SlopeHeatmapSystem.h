#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 提供坡度热力图模块入口，加载 Decal 组件、查询子系统和蓝图函数库。 */
class FSlopeHeatmapSystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
