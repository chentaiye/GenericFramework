// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class INativeAPISessionFeatureInterface;

/** 负责在 NativeAPI 模块生命周期内创建 WebSocket 和 HTTPRoute 会话 Feature，并注册到 ModularFeatures。 */
class FNativeAPIModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** 持有模块启动时创建的会话 Feature 实例，ShutdownModule 中逐个注销并释放。 */
	TArray<INativeAPISessionFeatureInterface*> RegisteredSessionFeatures;
};
