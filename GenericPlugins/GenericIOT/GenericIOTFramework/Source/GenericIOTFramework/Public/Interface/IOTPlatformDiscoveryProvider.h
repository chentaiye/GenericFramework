// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/** 定义平台发现提供器的 ModularFeature 契约，子系统通过它收集自动发现候选地址。 */
class GENERICIOTFRAMEWORK_API IIOTPlatformDiscoveryProviderInterface : public IModularFeature
{
public:
	/** 返回发现提供器注册使用的 ModularFeature 名称，子系统按该名称枚举实现。 */
	static FName GetModularFeatureName();

	/** 允许通过接口指针安全销毁实现对象，匹配 ModularFeature 的插件注册生命周期。 */
	virtual ~IIOTPlatformDiscoveryProviderInterface() = default;

	/** 返回提供器名称，便于日志或调试时识别候选地址来源。 */
	virtual FName GetProviderName() const = 0;

	/** 判断当前运行平台是否适合该提供器，避免在不支持的系统上返回无效候选地址。 */
	virtual bool CanHandleCurrentPlatform() const = 0;

	/** 向子系统追加可探测的基础 URL，后续会被归一化、去重并逐个请求 /api/。 */
	virtual void GatherDiscoveryBaseUrls(TArray<FString>& OutBaseUrls) const = 0;
};
