#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 声明 ExtraProc 模块，接入 UE 模块启动和关闭生命周期。 */
class FExtraProcModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
