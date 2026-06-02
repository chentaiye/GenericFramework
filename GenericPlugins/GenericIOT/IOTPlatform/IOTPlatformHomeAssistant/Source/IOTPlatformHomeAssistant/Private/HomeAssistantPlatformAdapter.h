// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HomeAssistant/HomeAssistantClient.h"
#include "Interface/IOTPlatformAdapter.h"
#include "HomeAssistantPlatformAdapter.generated.h"

class UIOTSubsystem;
class UHomeAssistantClient;

/** 将 Home Assistant 的 REST 与实时事件能力接入 GenericIOT 平台接口，负责配置客户端、同步设备快照并把通用命令翻译成 Home Assistant 服务调用。 */
UCLASS(MinimalAPI)
class UHomeAssistantPlatformAdapter : public UObject, public IIOTPlatformAdapterInterface
{
	GENERATED_BODY()

public:
	virtual void InitializeAdapter(UIOTSubsystem* InSubsystem) override;
	virtual void ShutdownAdapter() override;
	virtual EIOTPlatformKind GetPlatformKind() const override;
	virtual void ApplyEndpointConfig(const FIOTPlatformEndpointConfig& InConfig) override;
	virtual FIOTPlatformEndpointConfig GetEndpointConfig() const override;
	virtual bool CanConnect() const override;
	virtual void Connect() override;
	virtual void Disconnect() override;
	virtual void RefreshDevices() override;
	virtual void SubscribeRealtime() override;
	virtual void ExecuteCommand(const FIOTCommandRequest& InRequest) override;
	virtual void ExecuteRawService(const FString& InRequestId, const FString& InDeviceId, const FName& InDomain, const FName& InService, const TMap<FString, FString>& InParams) override;

private:
	/** 处理连接校验请求的异步响应，把认证失败、传输失败或成功连接状态回写到 IOT 子系统。 */
	void HandleConnectionValidated(const FHomeAssistantClientResponse& InResponse);

	/** 处理 Home Assistant states 接口返回的实体数组，构建设备描述与状态快照后替换子系统中的设备缓存。 */
	void HandleStatesReceived(const FHomeAssistantClientResponse& InResponse);

	/** 处理服务调用响应，根据 PendingRequests 找回原始命令并生成完成结果，同时吸收响应里返回的最新设备状态。 */
	void HandleServiceCalled(const FHomeAssistantClientResponse& InResponse);

	/** 解析 Home Assistant 实时事件消息，将 new_state 更新为设备当前状态，或在仅收到 old_state 时标记设备不可用。 */
	void HandleRealtimeMessage(const FString& InMessage);

	/** 在客户端上报传输错误时，根据当前连接阶段决定是进入连接错误状态，还是只关闭实时订阅状态。 */
	void HandleTransportError(const FString& InErrorMessage);

	/** 同步 WebSocket 实时订阅的启停状态，订阅成功时维持平台连接为已连接。 */
	void HandleRealtimeStateChanged(bool bInRealtimeActive);

private:
	/** 指向拥有该适配器的 IOT 子系统，所有连接状态、设备快照和命令完成通知都通过它回传。 */
	TWeakObjectPtr<UIOTSubsystem> Subsystem;

	/** 保存当前平台端点参数，Connect 前用于校验连接条件，Client 已创建时会同步应用到请求配置。 */
	FIOTPlatformEndpointConfig EndpointConfig;

	/** 承载 Home Assistant REST 请求和实时订阅的客户端实例，适配器在连接、刷新、命令执行和关闭流程中复用并管理其委托绑定。 */
	UPROPERTY()
	TObjectPtr<UHomeAssistantClient> Client=nullptr;

	/** 按 RequestId 保存等待服务调用响应的命令请求，使异步响应能够补回设备、命令名和参数上下文。 */
	TMap<FString, FIOTCommandRequest> PendingRequests;
};
