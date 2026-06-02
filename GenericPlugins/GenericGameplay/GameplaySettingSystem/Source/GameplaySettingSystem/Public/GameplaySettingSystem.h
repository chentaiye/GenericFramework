// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/** 定义当前模块Gameplay设置ystemModule能力契约，供模块在不同实现之间解耦调用。 */
class FGameplaySettingSystemModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
