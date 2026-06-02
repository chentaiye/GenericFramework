/* Copyright Epic Games, Inc. All Rights Reserved. */
#pragma once

#include "Modules/ModuleManager.h"

/** 注册 GenericNetworkFramework 运行时模块，当前模块的会话类型、子系统和蓝图节点都随模块加载可用。 */
class FGenericNetworkFrameworkModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
