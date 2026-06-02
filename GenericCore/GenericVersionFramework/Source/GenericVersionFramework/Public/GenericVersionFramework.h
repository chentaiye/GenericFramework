// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FGenericVersionFrameworkModule : public IModuleInterface
{
public:
	/** 接入 Unreal 模块生命周期，当前模块只提供运行时基础类型和子系统。 */
	virtual void StartupModule() override;

	virtual void ShutdownModule() override;
};
