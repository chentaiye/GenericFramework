// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class IAuthorizationServiceFeatureInterface;

/** GenericAuthLocal 模块入口，负责在启动时发布本地文件授权 Feature，并在关闭时撤销注册，供授权子系统通过 ModularFeatures 解耦发现。 */
class GENERICAUTHLOCAL_API FGenericAuthLocalModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** 保存本模块创建的授权 Feature 指针，ShutdownModule 依赖该列表反注册并释放，避免模块卸载后 ModularFeatures 留下悬空实现。 */
	TArray<IAuthorizationServiceFeatureInterface*> RegisteredFeatures;
};
