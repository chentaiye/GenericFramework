/* Copyright Epic Games, Inc. All Rights Reserved. */
#pragma once

#include "Modules/ModuleManager.h"

/** 定义 UnrealMisc 模块 入口，负责在 Unreal 模块启动和关闭阶段接入对应服务。 */
class FUnrealMiscModule : public IModuleInterface
{
public:

	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
