// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeAPIInterface.h"
#include "NativeAPITypes.h"
#include "Subsystem/GenericEngineSubsystem.h"
#include "NativeAPISubsystem.generated.h"

class UNativeAPIObject;
class UNativeAPIWorldSettings;
class UWorld;
class IModularFeature;

/** 作为引擎级 NativeAPI 调度中心，管理外部会话 Feature，并把解析后的 Payload 投递到目标世界或广播到所有运行世界。 */
UCLASS(MinimalAPI)
class UNativeAPISubsystem final : public UGenericEngineSubsystem, public INativeAPIInterface
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** 发送模拟 NativeAPI 消息，复用正式 Payload 分发链路，用于不经过 WebSocket/HTTP 的调试调用。 */
	void SendSimulationNativeAPI(const FString& NativeAPIJson);

	/** 按当前激活世界设置启动所有已注册会话 Feature，并把接收 Payload 的回调接回引擎级分发入口。 */
	void StartAllFeatureSession();

	/** 停止所有会话 Feature 并清空 Payload 回调，世界设置切换、Feature 注销和模块卸载时用它断开外部入口。 */
	void EndAllFeatureSession();

	/** 将加载中的世界设置压入激活栈；栈顶变化时重启会话以使用新世界的 WebSocket/HTTP 配置。 */
	void ActivateWorldSettings(UNativeAPIWorldSettings* InWorldSettings);

	/** 从激活栈移除正在卸载或销毁的世界设置；栈顶变化时重启会话以回落到上一有效配置。 */
	void DeactivateWorldSettings(UNativeAPIWorldSettings* InWorldSettings);

	/** 返回当前栈顶有效世界设置，WebSocket/HTTP 会话启动时读取它决定是否监听以及使用哪些连接参数。 */
	const UNativeAPIWorldSettings* GetActiveWorldSettings() const;

private:
	/** Feature Session 动态注册后，如已有激活世界配置则立即启动会话并绑定 Payload 回调。 */
	void HandleOnNativeAPISessionFeatureRegistered(const FName& FeatureName, IModularFeature* Feature);

	/** Feature Session 注销前清空回调并停止会话，避免外部通道继续回调到已释放的实现。 */
	void HandleOnNativeAPISessionFeatureUnRegistered(const FName& FeatureName, IModularFeature* Feature);

protected:
	/** 接收会话层转换出的 Payload；编辑器中会为每个 PIE 实例修正路径，再进入统一处理链路。 */
	void HandleOnReceiveNativePayload(const FNativeAPIPayload& InPayload);

	virtual void ProcessingNativeAPI(const FNativeAPIPayload& Payload) const override;

private:
	/** 按加载顺序缓存可驱动 NativeAPI 会话的世界设置，栈顶项决定当前外部入口配置。 */
	TArray<TWeakObjectPtr<UNativeAPIWorldSettings>> ActiveWorldSettingsStack;
};
