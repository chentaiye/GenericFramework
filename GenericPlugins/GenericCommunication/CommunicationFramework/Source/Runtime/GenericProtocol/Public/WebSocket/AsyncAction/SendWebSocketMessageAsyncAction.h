// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WebSocket/WebSocketAsyncActionBase.h"
#include "SendWebSocketMessageAsyncAction.generated.h"

/** WebSocket 发送异步节点，发起文本、JSON 或二进制发送并等待发送完成事件。 */
UCLASS(MinimalAPI)
class USendWebSocketMessageAsyncAction : public UWebSocketAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FWebSocketMessageSentEvent OnMessageSent;

public:
	/** 发送文本消息并在底层 OnMessageSent 触发时广播完成。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket", meta=(BlueprintInternalUseOnly="true"))
	static GENERICPROTOCOL_API USendWebSocketMessageAsyncAction* SendWebSocketMessage(UGenericWebSocket* WebSocket, const FString& Message);

	/** 序列化 JSON 对象后发送文本消息，并等待底层发送完成事件。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket", meta=(BlueprintInternalUseOnly="true"))
	static GENERICPROTOCOL_API USendWebSocketMessageAsyncAction* SendWebSocketJsonMessage(UGenericWebSocket* WebSocket, UGenericJsonObject* JsonObject);

	/** 发送字节消息并保留是否二进制的底层标记，完成后广播原始发送内容。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket", meta=(BlueprintInternalUseOnly="true"))
	static GENERICPROTOCOL_API USendWebSocketMessageAsyncAction* SendWebSocketBinaryMessage(UGenericWebSocket* WebSocket, const TArray<uint8>& Message, const bool bIsBinary = false);

protected:
	GENERICPROTOCOL_API virtual void OnMessageSentInternal(const FString& Message) override;
};
