#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 注册 GenericLevelStreamingFramework 运行时模块，承载传统子关卡流送的蓝图函数、世界子系统和句柄类型。 */
class FGenericLevelStreamingFrameworkModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
