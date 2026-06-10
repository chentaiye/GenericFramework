#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 定义存档系统保存游戏SystemModule能力契约，供模块在不同实现之间解耦调用。 */
class FGenericSaveGameSystemModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
