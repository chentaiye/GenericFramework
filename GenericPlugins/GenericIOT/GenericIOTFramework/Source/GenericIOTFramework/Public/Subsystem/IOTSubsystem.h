// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
#include "Type/IOTTypes.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "IOTSubsystem.generated.h"

class IIOTPlatformAdapterInterface;

/** 管理 IOT 平台连接、设备快照、实时状态和命令派发，是运行时与平台适配器之间的中心协调点。 */
UCLASS(MinimalAPI)
class UIOTSubsystem final : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static GENERICIOTFRAMEWORK_API UIOTSubsystem* Get(const UObject* WorldContextObject);

	GENERICIOTFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICIOTFRAMEWORK_API virtual void Deinitialize() override;

	/** 写入并持久化平台入口配置，同时把归一化后的配置同步给当前适配器。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API void SetEndpointConfig(const FIOTPlatformEndpointConfig& InConfig);

	/** 返回子系统当前使用的连接配置，异步连接成功后会通过它回传最终 Endpoint。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	GENERICIOTFRAMEWORK_API FIOTPlatformEndpointConfig GetEndpointConfig() const;

	/** 确保 Home Assistant 适配器存在，并根据 BaseUrl 是否为空选择自动发现或直接连接。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API bool ConnectHomeAssistant();

	/** 通知适配器断开平台连接，并重置实时订阅和连接状态广播。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API bool DisconnectPlatform();

	/** 让当前适配器重新拉取设备列表，刷新完成后会替换本地设备与状态缓存。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API bool RefreshDevices();

	/** 启动平台实时状态订阅，并把连接状态推进到等待实时通道建立的阶段。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API bool SubscribeRealtime();

	/** 读取当前连接生命周期状态，蓝图和异步节点用它判断是否已完成连接。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	EIOTConnectionState GetConnectionState() const { return ConnectionState; }

	/** 判断平台连接是否已经可用于命令或实时订阅流程。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	bool IsConnected() const { return ConnectionState == EIOTConnectionState::Connected || ConnectionState == EIOTConnectionState::Subscribing; }

	/** 判断实时通道是否已由适配器确认可用，订阅异步节点会据此直接成功返回。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	bool IsRealtimeActive() const { return bRealtimeActive; }

	/** 读取最近一次连接、发现、刷新或订阅失败原因，供异步失败分支展示。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	FString GetLastErrorMessage() const { return LastErrorMessage; }

	/** 导出当前设备快照缓存，列表顺序来自内部映射生成结果。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	TArray<FIOTDeviceDescriptor> GetAllDevices() const;

	/** 按内部 DeviceId 查询设备描述，用于组件缓存和命令目标校验。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	GENERICIOTFRAMEWORK_API bool TryGetDeviceById(const FString& DeviceId, FIOTDeviceDescriptor& OutDevice) const;

	/** 按平台 EntityId 反查内部设备描述，场景组件绑定实体时会走该索引。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	GENERICIOTFRAMEWORK_API bool TryGetDeviceByEntityId(const FString& EntityId, FIOTDeviceDescriptor& OutDevice) const;

	/** 按内部 DeviceId 查询最近一次状态快照，组件刷新绑定缓存时会读取它。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	GENERICIOTFRAMEWORK_API bool TryGetDeviceState(const FString& DeviceId, FIOTDeviceState& OutState) const;

	/** 为统一命令补全请求 ID 并交给平台适配器执行，返回值用于异步结果匹配。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API FString ExecuteCommand(FIOTCommandRequest InRequest);

	/** 绕过统一能力映射直接调用平台原生服务，并生成请求 ID 供完成事件关联。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API FString ExecuteRawService(const FString& DeviceId, FName Domain, FName Service, const TMap<FString, FString>& Params);

	/** 从设备缓存中解析平台 EntityId，供适配器把内部 DeviceId 还原成平台服务目标。 */
	GENERICIOTFRAMEWORK_API bool TryResolveEntityIdForDevice(const FString& DeviceId, FString& OutEntityId) const;

	/** 按当前 Home Assistant 约定从 EntityId 构造内部 DeviceId，保持蓝图工具和子系统缓存一致。 */
	GENERICIOTFRAMEWORK_API FString MakeDeviceIdFromEntityId(const FString& EntityId) const;

	/** 统一更新连接状态、错误消息和广播，并在首次连接成功后触发自动刷新与订阅配置。 */
	GENERICIOTFRAMEWORK_API void NotifyConnectionStateChanged(EIOTConnectionState InState, const FString& InErrorMessage = TEXT(""));

	/** 用适配器返回的完整快照重建设备、状态和 EntityId 索引，并广播刷新与状态变化事件。 */
	GENERICIOTFRAMEWORK_API void ReplaceDeviceSnapshot(const TArray<FIOTDeviceDescriptor>& InDevices, const TArray<FIOTDeviceState>& InStates);

	/** 增量写入单个设备描述与状态，实时订阅回调用它同步缓存并通知绑定组件。 */
	GENERICIOTFRAMEWORK_API void UpdateDeviceState(const FIOTDeviceDescriptor& InDevice, const FIOTDeviceState& InState);

	/** 广播命令完成事件，异步命令节点和组件会按 RequestId 或 DeviceId 过滤结果。 */
	GENERICIOTFRAMEWORK_API void CompleteCommand(const FIOTCommandRequest& InRequest, const FIOTCommandResult& InResult);

	/** 更新实时订阅可用标记并广播结果，订阅异步节点会监听该事件完成自身生命周期。 */
	GENERICIOTFRAMEWORK_API void NotifyRealtimeStateChanged(bool bInRealtimeActive, const FString& InErrorMessage = TEXT(""));

	UPROPERTY(BlueprintAssignable, Category="IOT")
	FIOTConnectionStateChangedSignature OnConnectionStateChanged;

	UPROPERTY(BlueprintAssignable, Category="IOT")
	FIOTDevicesRefreshedSignature OnDevicesRefreshed;

	UPROPERTY(BlueprintAssignable, Category="IOT")
	FIOTDeviceStateChangedSignature OnDeviceStateChanged;

	UPROPERTY(BlueprintAssignable, Category="IOT")
	FIOTCommandCompletedSignature OnCommandCompleted;

	UPROPERTY(BlueprintAssignable, Category="IOT")
	FIOTRealtimeStateChangedSignature OnRealtimeStateChanged;

private:
	/** 从开发者设置读取 Home Assistant 配置，并同步自动发现开关到运行时 Endpoint。 */
	void LoadSettingsConfig();

	/** 将当前 Endpoint 写回开发者设置并保存配置文件，供下次子系统初始化复用。 */
	void PersistEndpointConfig() const;

	/** 加载 Home Assistant 平台模块并通过 ModularFeature 创建适配器实例。 */
	bool EnsureHomeAssistantAdapter();

	/** 把缓存的 UObject 适配器转换为平台接口，所有平台调用都通过该接口派发。 */
	IIOTPlatformAdapterInterface* GetPlatformAdapter() const;

	/** 收集候选地址并进入自动发现状态，随后按顺序发起探测请求。 */
	void BeginAutoDiscovery();

	/** 释放上一轮探测请求并请求下一个候选地址，候选耗尽时报告发现失败。 */
	void ProbeNextDiscoveryCandidate();

	/** 处理自动发现 HTTP 探测结果，命中 Home Assistant 后保存 BaseUrl 并继续连接。 */
	void HandleDiscoveryProbeComplete(FHttpRequestPtr InRequest, FHttpResponsePtr InResponse, bool bConnectedSuccessfully);

	/** 合并设置项和发现提供器返回的基础地址，并去重归一化后供自动发现使用。 */
	void GatherDiscoveryBaseUrls(TArray<FString>& OutBaseUrls) const;

	/** 去除空白和尾部斜杠，保证后续拼接 /api/ 或平台服务路径时格式稳定。 */
	FString NormalizeBaseUrl(const FString& InBaseUrl) const;

	/** 根据响应内容或 401 鉴权提示判断候选地址是否像 Home Assistant API。 */
	bool IsCandidateResponseLikelyHomeAssistant(const FHttpResponsePtr& InResponse) const;

private:
	/** 持有通过工厂创建的平台适配器 UObject，避免重复加载模块或重复创建实例。 */
	UPROPERTY()
	TObjectPtr<UObject> PlatformAdapterObject=nullptr;

	/** 按内部 DeviceId 缓存设备描述，查询、组件绑定和命令目标校验都读取该映射。 */
	UPROPERTY()
	TMap<FString, FIOTDeviceDescriptor> DevicesById;

	/** 按内部 DeviceId 缓存最新设备状态，实时更新和刷新快照都会覆盖该映射。 */
	UPROPERTY()
	TMap<FString, FIOTDeviceState> DeviceStatesById;

	/** 建立平台 EntityId 到内部 DeviceId 的反向索引，场景组件按实体绑定时依赖它。 */
	UPROPERTY()
	TMap<FString, FString> DeviceIdByEntityId;

	/** 当前运行时平台入口配置，初始化、连接、自动发现和适配器调用共享该对象。 */
	FIOTPlatformEndpointConfig EndpointConfig;

	/** 当前连接生命周期状态，所有连接状态广播都以该字段为准。 */
	EIOTConnectionState ConnectionState = EIOTConnectionState::Disconnected;

	/** 最近一次失败说明，异步节点在收到 Error 状态时会读取并转交蓝图。 */
	FString LastErrorMessage;

	/** 当前实时订阅是否已建立，避免重复订阅并驱动订阅异步节点完成。 */
	bool bRealtimeActive = false;

	/** 自动发现流程是否正在运行，防止重复发起候选地址探测。 */
	bool bDiscoveryInProgress = false;

	/** 自动发现候选基础地址列表，由设置项和 ModularFeature 发现提供器共同填充。 */
	TArray<FString> DiscoveryCandidates;

	/** 当前正在探测的候选地址索引，探测失败时递增以继续尝试下一项。 */
	int32 DiscoveryCandidateIndex = INDEX_NONE;

	/** 当前自动发现 HTTP 请求句柄，用于在子系统关闭或下一轮探测前释放回调绑定。 */
	TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> DiscoveryRequest;

	/** 命令请求递增计数器，子系统用它生成本地唯一的 iot-* RequestId。 */
	uint64 RequestCounter = 0;
};
