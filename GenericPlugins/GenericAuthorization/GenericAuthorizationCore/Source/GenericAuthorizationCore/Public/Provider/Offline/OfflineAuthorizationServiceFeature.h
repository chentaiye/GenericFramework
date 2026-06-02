// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Provider/AuthorizationServiceFeature.h"

/** 离线授权 Provider 的基础接口，继承者自动标记为离线来源，子系统会按离线开关和离线缓存策略处理其响应。 */
class GENERICAUTHORIZATIONCORE_API IOfflineAuthorizationServiceFeatureInterface : public IAuthorizationServiceFeatureInterface
{
public:
	virtual bool IsOnlineService() const override { return false; }
};
