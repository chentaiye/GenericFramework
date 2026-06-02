// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Provider/AuthorizationServiceFeature.h"

/** 在线授权 Provider 的基础接口，继承者自动标记为在线来源，子系统会按在线开关和在线缓存策略处理其响应。 */
class GENERICAUTHORIZATIONCORE_API IOnlineAuthorizationServiceFeatureInterface : public IAuthorizationServiceFeatureInterface
{
public:
	virtual bool IsOnlineService() const override { return true; }
};
