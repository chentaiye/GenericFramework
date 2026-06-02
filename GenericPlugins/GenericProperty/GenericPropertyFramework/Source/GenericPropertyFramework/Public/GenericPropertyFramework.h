#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(LogGenericPropertyFramework, Log, All);

/** 通用属性运行时模块，提供日志类别并承载运行时类型加载入口。 */
class FGenericPropertyFrameworkModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
