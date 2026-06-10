#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/** 注册 GenericWorldPartitionFramework 运行时模块，具体功能由子系统、句柄和蓝图函数库承载。 */
class FGenericWorldPartitionFrameworkModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
