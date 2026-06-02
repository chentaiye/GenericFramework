// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Obect/GenericObject.h"
#include "TimerManager.h"
#include "HomeAssistantClient.generated.h"

class IWebSocket;

/** 封装 Home Assistant HTTP 操作结果，供验证连接、拉取状态和调用服务的回调共享。 */
struct FHomeAssistantClientResponse
{
	/** 发起该响应的操作名称，用于上层区分验证、状态拉取或服务调用。 */
	FString OperationName;

	/** 调用方传入的请求标识，服务调用完成后可用它关联外部任务。 */
	FString RequestId;

	/** HTTP 请求成功且响应码为 OK 时为 true。 */
	bool bSucceeded = false;

	/** Home Assistant HTTP 响应码，无响应时保持 0。 */
	int32 ResponseCode = 0;

	/** 成功或失败时返回的响应正文，通常是 JSON 文本。 */
	FString Payload;

	/** 请求失败时的错误正文或传输错误描述。 */
	FString ErrorMessage;
};

DECLARE_MULTICAST_DELEGATE_OneParam(FHomeAssistantClientResponseNative, const FHomeAssistantClientResponse&);
DECLARE_MULTICAST_DELEGATE_OneParam(FHomeAssistantClientMessageNative, const FString&);
DECLARE_MULTICAST_DELEGATE_OneParam(FHomeAssistantClientRealtimeStateNative, bool);

/** 管理 Home Assistant REST 与 WebSocket 通信，封装授权请求、实时订阅和自动重连。 */
UCLASS(MinimalAPI)
class UHomeAssistantClient : public UGenericObject
{
	GENERATED_BODY()

public:
	/** 初始化 Home Assistant 客户端对象，实际地址和令牌由 Configure 写入。 */
	GENERICPROTOCOL_API UHomeAssistantClient(const FObjectInitializer& ObjectInitializer);

	/** 创建客户端对象，未传 Outer 时挂到 TransientPackage 以便非蓝图调用使用。 */
	static GENERICPROTOCOL_API UHomeAssistantClient* CreateHomeAssistantClient(UObject* Outer);

	/** 写入基础 URL、访问令牌、超时和自动重连设置，并规整 URL 末尾斜杠。 */
	GENERICPROTOCOL_API void Configure(const FString& InBaseUrl, const FString& InAccessToken, float InTimeoutSeconds, bool bInAutoReconnect);

	/** 检查基础 URL 和访问令牌是否齐备，所有 REST 与实时连接入口都会依赖该判断。 */
	GENERICPROTOCOL_API bool HasValidConfiguration() const;

	/** 向 `/api/` 发送授权 GET 请求，用于验证地址和令牌是否可用。 */
	GENERICPROTOCOL_API void ValidateConnection();

	/** 向 `/api/states` 发送授权 GET 请求，拉取 Home Assistant 当前实体状态列表。 */
	GENERICPROTOCOL_API void FetchStates();

	/** 建立 `/api/websocket` 实时连接，并在认证成功后订阅 state_changed 事件。 */
	GENERICPROTOCOL_API void StartRealtime();

	/** 停止实时订阅、关闭 WebSocket 并清理重连计时器。 */
	GENERICPROTOCOL_API void StopRealtime();

	/** 通过 `/api/services/{domain}/{service}` 调用服务，并把请求 ID 传回完成回调。 */
	GENERICPROTOCOL_API void CallService(const FString& InRequestId, const FName& InDomain, const FName& InService, const FString& InJsonPayload);

	/** 返回实时订阅是否已由 Home Assistant 确认成功。 */
	bool IsRealtimeActive() const { return bRealtimeActive; }

	/** 返回当前基础 URL，供外部调试或 UI 显示已配置的 Home Assistant 地址。 */
	const FString& GetBaseUrl() const { return BaseUrl; }

	FHomeAssistantClientResponseNative OnConnectionValidated;
	FHomeAssistantClientResponseNative OnStatesReceived;
	FHomeAssistantClientResponseNative OnServiceCalled;
	FHomeAssistantClientMessageNative OnRealtimeMessage;
	FHomeAssistantClientMessageNative OnTransportError;
	FHomeAssistantClientRealtimeStateNative OnRealtimeStateChanged;

private:
	/** 创建带 Bearer Token 的 HTTP 请求，统一填充响应结构并广播指定回调。 */
	void SendAuthorizedRequest(const FString& InOperationName, const FString& InRequestId, const FString& InRelativePath, const FString& InVerb, const FString& InPayload, FHomeAssistantClientResponseNative* InDelegate);

	/** 将基础 URL 与 REST 相对路径拼接成完整 HTTP 地址。 */
	FString BuildHttpUrl(const FString& InRelativePath) const;

	/** 将 http/https 基础 URL 转换为 ws/wss，并指向 Home Assistant WebSocket API。 */
	FString BuildWebSocketUrl() const;

	/** 处理 WebSocket 已连接事件；Home Assistant 会随后发送 auth_required 消息。 */
	void HandleRealtimeConnected();

	/** 处理 WebSocket 连接错误，广播传输错误并按配置安排重连。 */
	void HandleRealtimeConnectionError(const FString& InErrorMessage);

	/** 处理 WebSocket 关闭事件，更新实时状态并在非主动关闭时触发重连。 */
	void HandleRealtimeClosed(int32 InStatusCode, const FString& InReason, bool bWasClean);

	/** 解析 Home Assistant WebSocket 消息，完成认证、订阅确认或转发实时事件。 */
	void HandleRealtimeMessage(const FString& InMessage);

	/** 收到 auth_required 后发送访问令牌认证消息。 */
	void SendRealtimeAuthMessage();

	/** 认证成功后发送 state_changed 订阅请求，并保存请求 ID 等待 result 确认。 */
	void SendRealtimeSubscribeMessage();

	/** 在自动重连开启且不是主动关闭时，延迟重新启动实时连接。 */
	void ScheduleRealtimeReconnect();

private:
	/** 去除末尾斜杠后的 Home Assistant 基础 URL。 */
	FString BaseUrl;

	/** REST 和 WebSocket 认证共用的长期访问令牌。 */
	FString AccessToken;

	/** REST 请求超时时间，Configure 会限制为至少 1 秒。 */
	float TimeoutSeconds = 8.0f;

	/** 控制实时连接断开后是否自动重连。 */
	bool bAutoReconnect = true;

	/** 标记 state_changed 订阅是否已被服务端确认。 */
	bool bRealtimeActive = false;

	/** 标记认证成功后是否还需要发送实时订阅请求。 */
	bool bPendingRealtimeSubscription = false;

	/** 标记 StopRealtime 正在主动关闭，避免关闭回调再次安排重连。 */
	bool bShuttingDown = false;

	/** 下一个 WebSocket 请求 ID，订阅请求会递增使用。 */
	int32 NextWebSocketMessageId = 1;

	/** 当前实时订阅请求 ID，用于从 result 消息识别订阅是否成功。 */
	int32 RealtimeSubscriptionRequestId = INDEX_NONE;

	/** 当前 Home Assistant WebSocket 连接，负责认证和实时事件订阅。 */
	TSharedPtr<IWebSocket> WebSocket;

	/** 延迟重连计时器句柄，StartRealtime 和 StopRealtime 会清理它避免重复重连。 */
	FTimerHandle ReconnectTimerHandle;
};
