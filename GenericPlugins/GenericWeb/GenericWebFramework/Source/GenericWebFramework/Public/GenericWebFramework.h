#pragma once

#include "Modules/ModuleManager.h"

GENERICWEBFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogGenericWeb, Log, All);

/** 注册通用 Web 框架模块，提供基础日志分类和模块生命周期入口。 */
class FGenericWebFrameworkModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
