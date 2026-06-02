// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeAPITypes.h"
#include "INativeAPISessionFeature.h"
#include "WebSocket/WebSocketType.h"

#if WITH_WEBSOCKETS
class IWebSocket;
#endif

/** 实现 WebSocket NativeAPI 会话 Feature，按激活世界设置建立连接并把收到的文本消息转换为 Payload。 */
class FNativeAPISession_WebSocket : public INativeAPISessionFeatureInterface
{
public:
	/** 初始化空 WebSocket 句柄，等待 StartSession 按激活世界设置创建实际连接。 */
	FNativeAPISession_WebSocket();

	virtual FName GetSessionName() override;
	virtual bool StartSession() override;
	virtual void EndSession() override;

private:
	/** 连接成功后写出当前 URL，帮助确认激活世界设置驱动的 WebSocket 入口已经上线。 */
	void HandleOnWebSocketConnection();

	/** 处理连接失败；若世界设置要求持续重连则复用当前 Socket 重试，否则解绑回调并释放句柄。 */
	void HandleOnWebSocketConnectionError(const FString& Error);

	/** 把 WebSocket 文本消息反序列化为 Payload，成功后通知引擎子系统继续分发。 */
	void HandleOnWebSocketMessage(const FString& InMessage);

#if WITH_WEBSOCKETS
	/** 持有当前连接对象和事件绑定，EndSession 或连接失败停止重试时负责解绑并释放。 */
	TSharedPtr<IWebSocket> WebSocket;
#endif

	/** 缓存启动会话时从世界设置读取的连接参数，创建 Socket、日志输出和错误重连都使用它。 */
	FGenericWebSocketConnection Connection;
};
