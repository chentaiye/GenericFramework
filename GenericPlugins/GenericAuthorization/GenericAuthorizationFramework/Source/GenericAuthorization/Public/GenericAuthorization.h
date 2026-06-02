// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Templates/UniquePtr.h"
#include "Modules/ModuleManager.h"

class FAuthorizationStartupGuard;

/** 管理 GenericAuthorization 模块生命周期，启动时创建启动守卫以在地图加载前拦截未授权运行。 */
class FGenericAuthorizationModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** 持有模块级启动守卫，模块卸载时通过它注销引擎委托和等待 Slate 的 Ticker。 */
	TUniquePtr<FAuthorizationStartupGuard> StartupGuard;
};
