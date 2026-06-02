// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Type/IOTTypes.h"
#include "IOTPlatformAdapter.generated.h"

class UIOTSubsystem;
struct FIOTPlatformEndpointConfig;
struct FIOTCommandRequest;

/** 声明平台适配器的 UObject 接口类型，便于子系统持有适配器对象并通过接口调用平台逻辑。 */
UINTERFACE()
class GENERICIOTFRAMEWORK_API UIOTPlatformAdapterInterface : public UInterface
{
	GENERATED_BODY()
};

/** 平台适配接口，负责把具体协议转换为 GenericIOT 的设备、状态、命令和连接事件。 */
class GENERICIOTFRAMEWORK_API IIOTPlatformAdapterInterface
{
	GENERATED_BODY()

public:
	/** 接收拥有者子系统指针，适配器后续用它回写连接状态、设备快照和命令结果。 */
	virtual void InitializeAdapter(UIOTSubsystem* InSubsystem) = 0;

	/** 关闭平台连接与回调绑定，子系统 Deinitialize 时会调用以释放运行时状态。 */
	virtual void ShutdownAdapter() = 0;

	/** 返回适配器支持的平台类型，子系统和工厂用它确认是否匹配目标配置。 */
	virtual EIOTPlatformKind GetPlatformKind() const = 0;

	/** 应用子系统当前 Endpoint 配置，连接、刷新和命令请求都会基于该配置发起。 */
	virtual void ApplyEndpointConfig(const FIOTPlatformEndpointConfig& InConfig) = 0;

	/** 返回适配器实际持有的 Endpoint 配置，用于调试或连接成功后回传给蓝图。 */
	virtual FIOTPlatformEndpointConfig GetEndpointConfig() const = 0;

	/** 判断当前配置是否足以发起连接，适配器可在这里校验 URL、令牌和平台约束。 */
	virtual bool CanConnect() const = 0;

	/** 发起平台连接流程，并通过子系统 NotifyConnectionStateChanged 回写进度和结果。 */
	virtual void Connect() = 0;

	/** 主动断开平台连接，并清理适配器维护的连接或订阅句柄。 */
	virtual void Disconnect() = 0;

	/** 拉取平台设备和状态快照，并通过子系统 ReplaceDeviceSnapshot 更新缓存。 */
	virtual void RefreshDevices() = 0;

	/** 建立平台实时状态通道，状态变化通过子系统 UpdateDeviceState 广播给组件。 */
	virtual void SubscribeRealtime() = 0;

	/** 执行统一能力命令，完成后必须通过子系统 CompleteCommand 广播结果。 */
	virtual void ExecuteCommand(const FIOTCommandRequest& InRequest) = 0;

	/** 执行平台原生服务调用，供统一能力未覆盖的场景仍能复用命令完成广播。 */
	virtual void ExecuteRawService(const FString& InRequestId, const FString& InDeviceId, const FName& InDomain, const FName& InService, const TMap<FString, FString>& InParams) = 0;
};

/** 平台适配器工厂接口，由具体平台插件注册到 ModularFeature 供子系统按平台类型创建适配器。 */
class GENERICIOTFRAMEWORK_API IIOTPlatformAdapterFactoryInterface : public IModularFeature
{
public:
	/** 返回适配器工厂注册使用的 ModularFeature 名称，子系统按该名称枚举工厂实现。 */
	static FName GetModularFeatureName();

	/** 允许平台插件通过接口指针管理工厂对象生命周期。 */
	virtual ~IIOTPlatformAdapterFactoryInterface() = default;

	/** 返回该工厂可创建的目标平台类型，子系统据此筛选 Home Assistant 工厂。 */
	virtual EIOTPlatformKind GetPlatformKind() const = 0;

	/** 创建平台适配器 UObject，Outer 通常为 IOT 子系统以绑定运行时生命周期。 */
	virtual UObject* CreateAdapter(UObject* Outer) = 0;
};
