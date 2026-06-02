// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Type/IOTTypes.h"
#include "Components/ActorComponent.h"
#include "IOTComponent.generated.h"

class UIOTSubsystem;

/** 将一个场景 Actor 绑定到 IOT 实体，缓存设备快照并把子系统事件转发为组件级蓝图事件。 */
UCLASS(MinimalAPI, ClassGroup="IOT", meta=(BlueprintSpawnableComponent))
class UIOTComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** 初始化组件运行状态，禁用 Tick 并把后续同步完全交给子系统事件驱动。 */
	GENERICIOTFRAMEWORK_API UIOTComponent(const FObjectInitializer& ObjectInitializer);

	GENERICIOTFRAMEWORK_API virtual void OnRegister() override;
	GENERICIOTFRAMEWORK_API virtual void OnUnregister() override;

	/** 绑定平台 EntityId 并立即刷新本地缓存，让场景对象跟随对应 IOT 设备状态。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API void BindEntityId(const FString& InEntityId);

	/** 清空实体绑定和已缓存的设备状态，组件会停止响应旧设备的状态更新。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API void ClearBinding();

	/** 返回当前绑定的平台 EntityId，供蓝图确认组件正在跟随哪个平台实体。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	FString GetEntityId() const { return EntityId; }

	/** 返回子系统解析出的内部 DeviceId，命令请求会使用该值定位目标设备。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	FString GetDeviceId() const { return DeviceId; }

	/** 根据缓存状态判断绑定实体是否可用，避免蓝图在 unavailable 状态下发起快捷命令。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	bool IsBoundEntityAvailable() const { return CurrentState.bAvailable; }

	/** 返回最近一次由子系统同步到组件的设备描述快照。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	FIOTDeviceDescriptor GetCurrentDescriptor() const { return CurrentDescriptor; }

	/** 返回最近一次由子系统同步到组件的设备状态快照。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	FIOTDeviceState GetCurrentState() const { return CurrentState; }

	/** 返回当前设备能力列表，蓝图可据此生成适合该实体的控制入口。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	TArray<FIOTCapabilityDescriptor> GetCapabilityDescriptors() const { return CurrentDescriptor.CapabilityDescriptors; }

	/** 基于当前绑定设备构造统一命令请求，并通过子系统交给平台适配器执行。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	FString ExecuteCommand(EIOTCapabilityKind CapabilityKind, const FString& CommandName, const TMap<FString, FString>& Parameters);

	/** 对当前绑定设备执行平台原生服务，适合统一能力尚未覆盖的 Home Assistant 调用。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API FString ExecuteRawService(FName Domain, FName Service, const TMap<FString, FString>& Params);

	/** 向绑定设备发送电源开启命令，结果会通过命令成功或失败事件回到组件。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API FString TurnOn();

	/** 向绑定设备发送电源关闭命令，返回的 RequestId 可用于追踪平台回调。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API FString TurnOff();

	/** 向绑定设备发送状态切换命令，适用于开关或支持 Toggle 能力的实体。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API FString Toggle();

	/** 向绑定设备写入通用数值能力，内部会把数值转换为 value 参数提交。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API FString SetNumericValue(float InValue);

	/** 向绑定设备写入通用选项能力，适用于模式、预设或选择类实体。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API FString SetOption(const FString& InOption);

	/** 向绑定设备发送一次性触发命令，适用于按钮、场景、脚本等实体。 */
	UFUNCTION(BlueprintCallable, Category="IOT")
	GENERICIOTFRAMEWORK_API FString Trigger();

	UPROPERTY(BlueprintAssignable, Category="IOT")
	FIOTDeviceStateChangedSignature OnStateChanged;

	UPROPERTY(BlueprintAssignable, Category="IOT")
	FIOTConnectionStateChangedSignature OnConnectionChanged;

	UPROPERTY(BlueprintAssignable, Category="IOT")
	FIOTCommandCompletedSignature OnCommandSucceeded;

	UPROPERTY(BlueprintAssignable, Category="IOT")
	FIOTCommandCompletedSignature OnCommandFailed;

protected:
	/** 接收子系统连接状态广播，并转发给绑定到该组件的蓝图监听者。 */
	UFUNCTION(Category="IOT")
	GENERICIOTFRAMEWORK_API void HandleSubsystemConnectionStateChanged(EIOTConnectionState InConnectionState);

	/** 接收设备状态广播，仅在 EntityId 或 DeviceId 匹配当前绑定时更新组件缓存。 */
	UFUNCTION(Category="IOT")
	GENERICIOTFRAMEWORK_API void HandleSubsystemDeviceStateChanged(FIOTDeviceDescriptor InDevice, FIOTDeviceState InState);

	/** 接收命令完成广播，仅对当前绑定设备拆分成功和失败组件事件。 */
	UFUNCTION(Category="IOT")
	GENERICIOTFRAMEWORK_API void HandleSubsystemCommandCompleted(FIOTCommandRequest InRequest, FIOTCommandResult InResult);

private:
	/** 在组件注册时绑定子系统委托，使连接、状态和命令完成事件能流入组件。 */
	void BindToSubsystem();

	/** 在组件反注册时移除子系统委托，防止组件销毁后继续收到事件。 */
	void UnbindFromSubsystem();

	/** 根据当前 EntityId 从子系统读取设备描述和状态，初始化组件本地缓存。 */
	void RefreshCachedBinding();

	/** 从组件上下文解析 GameInstance 子系统，所有命令和缓存刷新都通过它访问 IOT 运行时。 */
	UIOTSubsystem* ResolveSubsystem() const;

private:
	/** 组件绑定的平台原生实体 ID，设计时或运行时设置后用于反查 DeviceId。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="IOT", meta=(AllowPrivateAccess="true"))
	FString EntityId;

	/** 子系统解析得到的内部设备 ID，命令派发和事件过滤都依赖该字段。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="IOT", meta=(AllowPrivateAccess="true"))
	FString DeviceId;

	/** 当前绑定设备的描述缓存，随刷新快照或实时状态事件更新。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="IOT", meta=(AllowPrivateAccess="true"))
	FIOTDeviceDescriptor CurrentDescriptor;

	/** 当前绑定设备的状态缓存，蓝图查询和可用性判断直接读取它。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="IOT", meta=(AllowPrivateAccess="true"))
	FIOTDeviceState CurrentState;
};
