#pragma once

#include "Modules/ModuleInterface.h"

/** 注册浏览器后端模块，使 GenericWeb 控件可以使用 CEF 实现。 */
class FGenericWebBrowserModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
