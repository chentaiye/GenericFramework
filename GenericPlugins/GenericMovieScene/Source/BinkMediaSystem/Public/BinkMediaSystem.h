#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** BinkMediaSystem 运行时模块入口，加载后提供 Bink 播放器句柄封装能力。 */
class FBinkMediaSystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
