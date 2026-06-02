// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WebSocket/WebSocketAsyncActionBase.h"
#include "CloseWebSocketAsyncAction.generated.h"

/** WebSocket 关闭异步节点，发起关闭并把底层关闭状态广播给蓝图。 */
UCLASS(MinimalAPI)
class UCloseWebSocketAsyncAction : public UWebSocketAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FWebSocketClosedEvent OnClosed;

public:
	/** 按指定状态码和原因关闭 WebSocket，并等待 OnClosed 回调。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket", meta=(BlueprintInternalUseOnly="true"))
	static UCloseWebSocketAsyncAction* CloseWebSocket(UGenericWebSocket* WebSocket, int32 Code = 1000, FString Reason = "Close Normal");

protected:
	virtual void OnClosedInternal(int32 Status, const FString& Reason, bool bWasClean) override;
};
