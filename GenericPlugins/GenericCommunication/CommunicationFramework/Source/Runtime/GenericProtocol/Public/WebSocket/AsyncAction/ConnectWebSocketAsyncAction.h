// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WebSocket/WebSocketAsyncActionBase.h"
#include "ConnectWebSocketAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWebSocketConnectionEvent, UGenericWebSocket*, WebSocket, const FString&, Message);

/** WebSocket 连接异步节点，绑定连接结果并在成功或错误时广播给蓝图。 */
UCLASS(MinimalAPI)
class UConnectWebSocketAsyncAction : public UWebSocketAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FWebSocketConnectionEvent OnConnected;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FWebSocketConnectionEvent OnConnectionError;

public:
	/** 使用完整连接配置启动 WebSocket 连接，并等待底层连接事件返回。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket", meta=(BlueprintInternalUseOnly="true"))
	static UConnectWebSocketAsyncAction* ConnectWebSocketWithConnection(UGenericWebSocket* InWebSocket, FGenericWebSocketConnection InWebSocketConnect);

	/** 使用主机、端口、协议和 Header 参数更新连接配置后启动连接。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket", meta=(BlueprintInternalUseOnly="true", AutoCreateRefTerm="Headers"))
	static UConnectWebSocketAsyncAction* ConnectWebSocketWithURL(UGenericWebSocket* InWebSocket, FString Host, int32 Port, EGenericWebSocketProtocol Protocol, TMap<FString, FString> Headers);

	/** 复用 WebSocket 当前配置启动连接，适合蓝图先配置后执行。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket", meta=(BlueprintInternalUseOnly="true"))
	static UConnectWebSocketAsyncAction* ConnectWebSocket(UGenericWebSocket* InWebSocket);

protected:
	virtual void OnConnectedInternal(UGenericWebSocket* WebSocket) override;
	virtual void OnConnectionErrorInternal(const FString& Error) override;
};
