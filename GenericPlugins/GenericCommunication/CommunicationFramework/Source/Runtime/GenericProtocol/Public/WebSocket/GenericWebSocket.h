// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WebSocketType.h"
#include "Obect/GenericObject.h"
#include "GenericWebSocket.generated.h"

class UGenericJsonObject;
class IWebSocket;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWebSocketConnectedEvent, UGenericWebSocket*, WebSocket);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWebSocketConnectionErrorEvent, const FString&, Error);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWebSocketRawMessageEvent, const TArray<uint8>&, Data, int32, BytesRemaining);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWebSocketBinaryMessageEvent, const TArray<uint8>&, Data, bool, bIsLastFragment);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWebSocketMessageEvent, const FString&, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWebSocketMessageSentEvent, const FString&, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FWebSocketClosedEvent, int32, Status, const FString&, Reason, bool, bWasClean);

/** 封装 UE WebSocket 连接，提供蓝图建连、发送、关闭和自动重连事件。 */
UCLASS(MinimalAPI)
class UGenericWebSocket : public UGenericObject
{
	GENERATED_BODY()

public:
	/** 创建 WebSocket 包装对象默认状态，实际连接由 Connect 系列函数配置。 */
	UGenericWebSocket(const FObjectInitializer& ObjectInitializer);

public:
	/** 创建可由蓝图继续配置连接参数的 WebSocket 包装对象。 */
	UFUNCTION(BlueprintPure, Category="WebSocket")
	static GENERICPROTOCOL_API UGenericWebSocket* CreateWebSocket();

	/** 查询底层连接是否已建立，发送消息前会使用同样判断。 */
	UFUNCTION(BlueprintPure, Category="WebSocket")
	GENERICPROTOCOL_API bool IsConnected() const;

	/** 使用完整连接配置创建并连接 WebSocket，无效 Host 或 Port 会直接报错返回。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void ConnectWithConnection(const FGenericWebSocketConnection& InWebSocketConnect);

	/** 通过拆分参数更新连接配置并建连；已连接时先缓存新连接并关闭旧连接再切换。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket", meta=(AutoCreateRefTerm="Headers"))
	GENERICPROTOCOL_API void ConnectWithURL(FString Host, int32 Port, EGenericWebSocketProtocol Protocol, const TMap<FString, FString>& Headers);

	/** 使用当前连接配置启动底层 WebSocket 连接，并重置本轮重连计数。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void Connect();

	/** 关闭已连接的 WebSocket，并把状态码和原因传给底层关闭流程。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void Close(int32 Code = 1000, FString Reason = "Close Normal");

	/** 发送文本消息；连接无效时输出警告并阻断发送。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void SendMessage(const FString& Message);

	/** 将 UGenericJsonObject 序列化为文本消息后发送，JSON 无效或序列化失败时不发送。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void SendJsonMessage(UGenericJsonObject* JsonObject);

	/** 发送原始字节消息，可通过 bIsBinary 指定底层 WebSocket 二进制标记。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void SendBinaryMessage(const TArray<uint8>& Message, const bool bIsBinary = false);

private:
	/** 绑定WebSocket委托，保持对象生命周期内的委托连接一致。 */
	void BindWebSocketDelegate();

	/** 解除底层 WebSocket 委托，关闭或替换连接前防止旧连接继续回调当前对象。 */
	void UnBindWebSocketDelegate() const;

public:
	/** 读取当前连接配置中的目标主机。 */
	UFUNCTION(BlueprintPure, Category="WebSocket")
	GENERICPROTOCOL_API FString GetHost() const;

	/** 更新当前连接配置中的目标主机，下一次 Connect 才会使用新值。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void SetHost(FString InHost);

	/** 读取当前连接配置中的目标端口。 */
	UFUNCTION(BlueprintPure, Category="WebSocket")
	GENERICPROTOCOL_API int32 GetPort() const;

	/** 更新当前连接配置中的目标端口，下一次 Connect 才会使用新值。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void SetPort(int32 InPort);

	/** 读取当前连接配置中的 ws 或 wss 协议。 */
	UFUNCTION(BlueprintPure, Category="WebSocket")
	GENERICPROTOCOL_API EGenericWebSocketProtocol GetProtocol() const;

	/** 更新当前连接配置中的协议，影响后续生成的连接 URL。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void SetProtocol(EGenericWebSocketProtocol InProtocol);

	/** 添加或覆盖单个握手请求头，供认证或自定义协议参数使用。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void AddHeader(const FString& Header, const FString& Value);

	/** 批量追加握手请求头，异步连接节点会用它应用外部传入的 Headers。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void AddHeaders(TMap<FString, FString> Headers);

	/** 移除单个握手请求头，下一次建连时不再发送该字段。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void RemoveHeader(const FString& Header);

	/** 批量移除握手请求头，便于蓝图重置认证或临时参数。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void RemoveHeaders(TArray<FString> Headers);

	/** 读取当前连接配置中的握手请求头映射。 */
	UFUNCTION(BlueprintPure, Category="WebSocket")
	GENERICPROTOCOL_API TMap<FString, FString> GetHeaders();

	/** 替换当前连接配置中的握手请求头映射。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void SetHeaders(TMap<FString, FString> Headers);

	/** 读取自动重连最大次数，负数表示持续尝试。 */
	UFUNCTION(BlueprintPure, Category="WebSocket")
	GENERICPROTOCOL_API int32 GetMaxReconnectCount() const;

	/** 设置自动重连最大次数，后续连接错误会按该值决定是否继续重试。 */
	UFUNCTION(BlueprintCallable, Category="WebSocket")
	GENERICPROTOCOL_API void SetMaxReconnectCount(int32 MaxReconnectCount);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="WebSocket")
	FWebSocketConnectedEvent OnConnectedEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="WebSocket")
	FWebSocketConnectionErrorEvent OnConnectionErrorEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="WebSocket")
	FWebSocketRawMessageEvent OnRawMessageEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="WebSocket")
	FWebSocketBinaryMessageEvent OnBinaryMessageEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="WebSocket")
	FWebSocketMessageEvent OnMessageEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="WebSocket")
	FWebSocketMessageSentEvent OnMessageSentEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="WebSocket")
	FWebSocketClosedEvent OnCloseEvent;

protected:
	/** 底层连接成功后输出连接信息并广播蓝图连接事件。 */
	GENERICPROTOCOL_API virtual void OnConnected();

	/** 底层连接错误后广播错误并进入自动重连判断。 */
	GENERICPROTOCOL_API virtual void OnConnectionError(const FString& Error);

	/** 底层收到原始字节片段后复制为 TArray 并广播给蓝图。 */
	GENERICPROTOCOL_API virtual void OnRawMessage(const void* Data, SIZE_T Size, SIZE_T BytesRemaining);

	/** 底层收到二进制消息后复制为 TArray 并保留是否最后片段的信息。 */
	GENERICPROTOCOL_API virtual void OnBinaryMessage(const void* Data, SIZE_T Size, bool bIsLastFragment);

	/** 底层收到文本消息后输出消息信息并广播给蓝图。 */
	GENERICPROTOCOL_API virtual void OnMessage(const FString& Message);

	/** 底层确认消息发送后输出发送信息并广播发送完成事件。 */
	GENERICPROTOCOL_API virtual void OnMessageSent(const FString& Message);

	/** 底层连接关闭后广播关闭事件，并在存在缓存新连接时切换并重新连接。 */
	GENERICPROTOCOL_API virtual void OnClosed(int32 Status, const FString& Reason, bool bWasClean);

private:
	/** 根据重连次数和间隔安排下一次连接尝试。 */
	void Reconnect();

	/** 执行实际重连调用，复用当前底层 WebSocket 对象。 */
	void ReconnectInternal();

private:
	/** 当前底层 WebSocket 连接，所有发送和关闭操作都委托给它。 */
	TSharedPtr<IWebSocket> WebSocket = nullptr;

	/** 已连接状态下请求切换地址时临时保存的新连接，旧连接关闭后接管。 */
	TSharedPtr<IWebSocket> WebSocketCache = nullptr;

	/** 当前连接配置和重连状态，Connect、Reconnect 与 URL 构造共享它。 */
	FGenericWebSocketConnection WebSocketConnect;
};
