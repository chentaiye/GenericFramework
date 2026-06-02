// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

/** 作为 GenericAuthOnline 运行时模块入口，随插件默认加载阶段建立在线授权扩展边界；当前生命周期实现保持空操作，后续在线授权 Provider 注册应集中在这里接入 GenericAuthorizationCore 的授权服务接口。 */
class GENERICAUTHONLINE_API FGenericAuthOnlineModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
