// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Common/UdpSocketReceiver.h"
#include "Obect/GenericObject.h"
#include "GenericUdpSocket.generated.h"

class FUdpSocketReceiver;
class UGenericUdpSocketBuilder;

/* ==================== Sender ==================== */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUdpSocketSenderConnectedEvent, const FString&, SendBoundIp, const int32&, SendBoundPort);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUdpSocketSenderConnectionErrorEvent, const FString&, SendIp, const int32&, SendPort);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUdpSocketMessageSentEvent, const FString&, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUdpSocketMessageSentErrorEvent, const FString&, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUdpSocketSenderClosedEvent, const FString&, SendIp, const int32&, SendPort);

/* ==================== Receiver ==================== */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUdpSocketReceiverConnectedEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUdpSocketReceiverConnectionErrorEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUdpSocketMessageEvent, const FString&, Message);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUdpSocketReceiverClosedEvent);

/** 使用构建器创建 UDP 发送和接收 Socket，并把连接、发送、接收事件暴露给蓝图。 */
UCLASS(MinimalAPI)
class UGenericUdpSocket : public UGenericObject
{
	GENERATED_BODY()

public:
	/** 按构建器参数创建 UDP 包装对象，并立即构建发送和接收 Socket。 */
	UFUNCTION(BlueprintPure, Category="UDP")
	static GENERICPROTOCOL_API UGenericUdpSocket* CreateUdpSocket(UGenericUdpSocketBuilder* InBuilder);

public:
	/** 替换构建器并重建底层 Socket，调用前会销毁旧的发送和接收资源。 */
	UFUNCTION(BlueprintCallable, Category="UDP")
	GENERICPROTOCOL_API void UpdateUdpSocket(UGenericUdpSocketBuilder* Builder);

public:
	/** 使用构建器中的发送地址连接发送 Socket，并回填实际本地绑定地址。 */
	UFUNCTION(BlueprintCallable, Category="UDP")
	GENERICPROTOCOL_API bool ConnectSender();

	/** 将字符串转换为字节后通过已连接的发送 Socket 发送，并广播成功或失败事件。 */
	UFUNCTION(BlueprintCallable, Category="UDP")
	GENERICPROTOCOL_API bool SendMessage(FString InMessage);

	/** 关闭并销毁发送 Socket，成功时广播关闭前的远端地址。 */
	UFUNCTION(BlueprintCallable, Category="UDP")
	GENERICPROTOCOL_API bool CloseSender();

	/** 启动 UDP 接收线程并绑定数据回调，同时回填实际本地接收地址。 */
	UFUNCTION(BlueprintCallable, Category="UDP")
	GENERICPROTOCOL_API bool ConnectReceiver();

	/** 停止接收线程并销毁接收 Socket，成功时广播接收端关闭事件。 */
	UFUNCTION(BlueprintCallable, Category="UDP")
	GENERICPROTOCOL_API bool CloseReceiver();

protected:
	virtual void BeginDestroy() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="UDP")
	FUdpSocketSenderConnectedEvent OnSenderConnectedEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="UDP")
	FUdpSocketSenderConnectionErrorEvent OnSenderConnectionErrorEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="UDP")
	FUdpSocketMessageSentEvent OnMessageSentEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="UDP")
	FUdpSocketMessageSentErrorEvent OnMessageSentErrorEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="UDP")
	FUdpSocketSenderClosedEvent OnSenderClosedEvent;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="UDP")
	FUdpSocketReceiverConnectedEvent OnReceiverConnectedEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="UDP")
	FUdpSocketReceiverConnectionErrorEvent OnReceiverConnectionErrorEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="UDP")
	FUdpSocketMessageEvent OnMessageEvent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="UDP")
	FUdpSocketReceiverClosedEvent OnReceiverClosedEvent;

private:
	/** 关闭并释放发送 Socket，供重建、关闭和销毁流程共同复用。 */
	void DestroySenderSocket();

	/** 停止接收线程并释放接收 Socket，供重建、关闭和销毁流程共同复用。 */
	void DestroyReceiverSocket();

private:
	/** 接收线程收到字节后切回游戏线程，把数据转换为字符串并广播给蓝图。 */
	void HandleOnDataReceived(const FArrayReaderPtr& DataPtr, const FIPv4Endpoint& Endpoint) const;

protected:
	/** 当前 Socket 构建参数，连接成功后也用于回填本地绑定地址。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP")
	UGenericUdpSocketBuilder* Builder=nullptr;

	/** 发送端底层 Socket，ConnectSender、SendMessage 和 CloseSender 共享它。 */
	FSocket* SenderSocket=nullptr;

	/** 接收端底层 Socket，ConnectReceiver、CloseReceiver 和接收线程共享它。 */
	FSocket* ReceiverSocket=nullptr;

	/** UDP 接收线程对象，负责从 ReceiverSocket 拉取数据并触发回调。 */
	FUdpSocketReceiver* UDPReceiver=nullptr;
};
