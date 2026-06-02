// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProtocolType.h"
#include "Obect/GenericObject.h"
#include "GenericUdpSocketBuilder.generated.h"

class FUdpSocketBuilder;
class UGenericUdpSocket;

/** 保存 UDP Socket 构建参数，并负责为发送端和接收端创建底层 FSocket。 */
UCLASS(MinimalAPI)
class UGenericUdpSocketBuilder : public UGenericObject
{
	GENERATED_BODY()

public:
	/** 在启用发送时按当前参数创建发送 Socket，发送缓冲区大小会在这里应用。 */
	GENERICPROTOCOL_API virtual FSocket* BuildSenderSocket();

	/** 在启用接收时按当前参数创建接收 Socket，并绑定到配置的接收端点。 */
	GENERICPROTOCOL_API virtual FSocket* BuildReceiverSocket();

private:
	/** 把UDP构建参数写入底层Socket Builder，供发送端和接收端复用。 */
	void Build(FUdpSocketBuilder* UdpSocketBuilder) const;

public:
	/** 设置 Socket 阻塞模式，Build 会据此选择 AsBlocking 或 AsNonBlocking。 */
	UFUNCTION(BlueprintCallable, Category="UDP")
	GENERICPROTOCOL_API void SetIsBlocking(bool IsBlocking = false);

	/** 控制底层 Socket 是否允许地址复用，影响多实例绑定同一端口的行为。 */
	UFUNCTION(BlueprintCallable, Category="UDP")
	GENERICPROTOCOL_API void SetEnableReusable(bool EnableReusable);

	/** 控制底层 Socket 是否启用广播能力，平台支持时 Build 会写入该选项。 */
	UFUNCTION(BlueprintCallable, Category="UDP")
	GENERICPROTOCOL_API void SetEnableBroadcast(bool EnableBroadcast);

	/** 控制底层 Socket 是否启用组播回环，平台支持时 Build 会写入该选项。 */
	UFUNCTION(BlueprintCallable, Category="UDP")
	GENERICPROTOCOL_API void SetEnableMulticastLoopback(bool EnableMulticastLoopback);

protected:
	/** 传给 FUdpSocketBuilder 的名称，用于日志和底层 Socket 标识。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true"))
	FString SocketName=TEXT("GenericUdpSocket");

	/** 决定构建出的 Socket 使用阻塞还是非阻塞模式。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true"))
	bool bIsBlocking=false;

	/** 构建时是否启用地址复用。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true"))
	bool bEnableReusable=true;

	/** 构建时是否启用广播发送。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true"))
	bool bEnableBroadcast=false;

	/** 构建时是否启用组播回环。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true"))
	bool bEnableMulticastLoopback=false;

public:
	/** 是否创建发送 Socket，关闭后 BuildSenderSocket 返回空指针。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true"))
	bool bEnableSend=true;

	/** 发送 Socket 的缓冲区大小，传入 0 时使用底层默认值。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true", EditConditionHides, EditCondition="bEnableSend"))
	int32 SendBufferSize=0;

	/** 发送目标 IP，ConnectSender 会用它创建远端地址。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true", EditConditionHides, EditCondition="bEnableSend"))
	FString SendIp=TEXT("127.0.0.1");

	/** 发送目标端口，ConnectSender 会用它创建远端地址。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true", EditConditionHides, EditCondition="bEnableSend"))
	int32 SendPort=8060;

	/** 发送 Socket 连接后实际绑定的本地 IP，由 ConnectSender 回填。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP")
	FString SendBoundIp=TEXT("127.0.0.1");

	/** 发送 Socket 连接后实际绑定的本地端口，由 ConnectSender 回填。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP")
	int32 SendBoundPort=8060;

public:
	/** 是否创建接收 Socket，关闭后 BuildReceiverSocket 返回空指针。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true"))
	bool bEnableReceive=true;

	/** 接收 Socket 的缓冲区大小，传入 0 时使用底层默认值。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true", EditConditionHides, EditCondition="bEnableReceive"))
	int32 ReceiveBufferSize=0;

	/** 接收绑定 IP，BuildReceiverSocket 会用它创建本地端点。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true", EditConditionHides, EditCondition="bEnableReceive"))
	FString ReceiveIp=TEXT("0.0.0.0");

	/** 接收绑定端口，BuildReceiverSocket 会用它创建本地端点。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP", meta=(ExposeOnSpawn="true", EditConditionHides, EditCondition="bEnableReceive"))
	int32 ReceivePort=8060;

	/** 接收 Socket 启动后实际绑定的本地 IP，由 ConnectReceiver 回填。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP")
	FString ReceiveBoundIp=TEXT("127.0.0.1");

	/** 接收 Socket 启动后实际绑定的本地端口，由 ConnectReceiver 回填。 */
	UPROPERTY(BlueprintReadOnly, Category="UDP")
	int32 ReceiveBoundPort=8060;
};
