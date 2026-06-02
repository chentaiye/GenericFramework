// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WebSocket/WebSocketType.h"
#include "WebSocket/GenericWebSocket.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "WebSocketAsyncActionBase.generated.h"

class UGenericWebSocket;

/** WebSocket 蓝图异步节点基类，负责绑定连接对象事件并把事件派发给子类扩展点。 */
UCLASS(MinimalAPI, Abstract)
class UWebSocketAsyncActionBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	GENERICPROTOCOL_API virtual void SetReadyToDestroy() override;

protected:
	/** 保存目标 WebSocket 并绑定其事件，后续子类节点可等待连接、发送或关闭结果。 */
	GENERICPROTOCOL_API void InitWebSocket(UGenericWebSocket* InWebSocket);

	/** 返回当前异步节点绑定的 WebSocket，供静态工厂函数继续调用具体操作。 */
	GENERICPROTOCOL_API UGenericWebSocket* GetWebSocket();

private:
	/** 绑定WebSocket委托，保持对象生命周期内的委托连接一致。 */
	void BindWebSocketDelegate();

	/** 解除当前异步节点绑定的 WebSocket 委托，避免节点销毁后继续收到事件。 */
	void UnBindWebSocketDelegate() const;

private:
	/** 接收 WebSocket 连接成功事件，并转入子类连接成功扩展点。 */
	UFUNCTION(Category="Web Socket Async Action Base")
	GENERICPROTOCOL_API void HandleOnConnected(UGenericWebSocket* WebSocket);

	/** 接收 WebSocket 连接错误事件，并转入子类错误扩展点。 */
	UFUNCTION(Category="Web Socket Async Action Base")
	GENERICPROTOCOL_API void HandleOnConnectionError(const FString& Error);

	/** 接收原始字节消息事件，并转入子类原始消息扩展点。 */
	UFUNCTION(Category="Web Socket Async Action Base")
	GENERICPROTOCOL_API void HandleOnRawMessage(const TArray<uint8>& Data, int32 BytesRemaining);

	/** 接收二进制消息事件，并转入子类二进制消息扩展点。 */
	UFUNCTION(Category="Web Socket Async Action Base")
	GENERICPROTOCOL_API void HandleOnBinaryMessage(const TArray<uint8>& Data, bool bIsLastFragment);

	/** 接收文本消息事件，并转入子类文本消息扩展点。 */
	UFUNCTION(Category="Web Socket Async Action Base")
	GENERICPROTOCOL_API void HandleOnMessage(const FString& Message);

	/** 接收消息发送完成事件，并转入子类发送完成扩展点。 */
	UFUNCTION(Category="Web Socket Async Action Base")
	GENERICPROTOCOL_API void HandleOnMessageSent(const FString& Message);

	/** 接收关闭事件，并转入子类关闭扩展点。 */
	UFUNCTION(Category="Web Socket Async Action Base")
	GENERICPROTOCOL_API void HandleOnClosed(int32 Status, const FString& Reason, bool bWasClean);

	/** 预留重连开始事件入口，子类可在支持该事件时覆盖处理。 */
	UFUNCTION(Category="Web Socket Async Action Base")
	GENERICPROTOCOL_API void HandleOnReStarted();

	/** 预留重连错误事件入口，子类可在支持该事件时覆盖处理。 */
	UFUNCTION(Category="Web Socket Async Action Base")
	GENERICPROTOCOL_API void HandleOnReStartError(const FString& Error);

protected:
	/** 子类连接成功扩展点，默认不处理。 */
	virtual void OnConnectedInternal(UGenericWebSocket* WebSocket) { return; }

	/** 子类连接错误扩展点，默认不处理。 */
	virtual void OnConnectionErrorInternal(const FString& Error) { return; }

	/** 子类原始字节消息扩展点，默认不处理。 */
	virtual void OnRawMessageInternal(const TArray<uint8>& Data, int32 BytesRemaining) { return; }

	/** 子类二进制消息扩展点，默认不处理。 */
	virtual void OnBinaryMessageInternal(const TArray<uint8>& Data, bool bIsLastFragment) { return; }

	/** 子类文本消息扩展点，默认不处理。 */
	virtual void OnMessageInternal(const FString& Message) { return; }

	/** 子类发送完成扩展点，默认不处理。 */
	virtual void OnMessageSentInternal(const FString& Message) { return; }

	/** 子类关闭扩展点，默认不处理。 */
	virtual void OnClosedInternal(int32 Status, const FString& Reason, bool bWasClean) { return; }

	/** 子类重连开始扩展点，默认不处理。 */
	virtual void OnReStartedInternal() { return; }

	/** 子类重连错误扩展点，默认不处理。 */
	virtual void OnReStartErrorInternal(const FString& Error) { return; }

private:
	/** 当前绑定的 WebSocket 包装对象，UPROPERTY 保证异步节点持有期间不被 GC 回收。 */
	UPROPERTY()
	UGenericWebSocket* WebSocketInternal=nullptr;
};
