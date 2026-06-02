// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeAPIInterface.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "NativeAPIWorldSubsystem.generated.h"

class UNativeAPIProxyComponent;

/** 维护单个 World 内的 NativeAPI 代理注册表，接收引擎级广播后按实体类型转发给本世界代理。 */
UCLASS(MinimalAPI)
class UNativeAPIWorldSubsystem final : public UGenericWorldSubsystem, public INativeAPIInterface
{
	GENERATED_BODY()

	friend class UNativeAPISubsystem;

public:
	static NATIVEAPI_API UNativeAPIWorldSubsystem* Get(const UObject* WorldContextObject);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** 在组件注册时把代理加入本世界的实体类型分桶，使无 EntityPath 的 Payload 能按类型广播到可处理对象。 */
	void RegisterNativeAPI(UNativeAPIProxyComponent* InProxy);

	/** 在组件注销时从类型分桶移除代理，避免世界广播继续访问已离开世界的组件。 */
	void UnRegisterNativeAPI(UNativeAPIProxyComponent* InProxy);

protected:
	virtual void ProcessingNativeAPI(const FNativeAPIPayload& Payload) const override;

private:
	/** 按实体类聚合本世界代理组件，ProcessingNativeAPI 会先匹配 ClassPath 再遍历对应代理。 */
	using FNativeAPIProxyCollection = TMap<UClass*, TArray<TObjectPtr<UNativeAPIProxyComponent>>>;

	/** 缓存当前世界可接收 NativeAPI 的代理组件，Key 为 Owner 实体类，Value 为已注册代理列表。 */
	FNativeAPIProxyCollection NativeAPIProxyCollection;
};
