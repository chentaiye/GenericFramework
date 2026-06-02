// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/** 作为 GenericAuthorizationCore 运行时模块入口，承载授权类型、校验、存储和传输工具的加载边界；当前启动和关闭逻辑保持空实现，供依赖模块按 Unreal 模块生命周期引用核心 API。 */
class FGenericAuthorizationCoreModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
