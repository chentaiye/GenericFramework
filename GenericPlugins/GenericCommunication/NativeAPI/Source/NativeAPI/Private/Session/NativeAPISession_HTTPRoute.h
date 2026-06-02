// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HttpRouteHandle.h"
#include "INativeAPISessionFeature.h"

class IHttpRouter;

/** 实现 HTTP POST `/NativeAPI` 会话 Feature，按激活世界设置监听端口并把请求体转换为 Payload。 */
class FNativeAPISession_HTTPRoute : public INativeAPISessionFeatureInterface
{
public:
	virtual FName GetSessionName() override;
	virtual bool StartSession() override;
	virtual void EndSession() override;

private:
	/** 持有当前端口的 HTTP 路由器，StartSession 绑定和 EndSession 解绑 NativeAPI 入口时使用。 */
	TSharedPtr<IHttpRouter> HttpRouter;

	/** 保存 `/NativeAPI` POST 路由绑定句柄，停止会话时用它精确解绑当前路由。 */
	FHttpRouteHandle RouteHandle;
};
