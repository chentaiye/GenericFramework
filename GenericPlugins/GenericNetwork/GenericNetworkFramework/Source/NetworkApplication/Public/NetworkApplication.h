#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 注册 NetworkApplication 模块，使网络专用 GameMode、GameState、PlayerController 和 PlayerState 类型可被项目引用。 */
class FNetworkApplicationModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};
