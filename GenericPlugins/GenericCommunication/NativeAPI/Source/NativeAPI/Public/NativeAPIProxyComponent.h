// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeAPIInterface.h"
#include "Components/ActorComponent.h"
#include "NativeAPIProxyComponent.generated.h"

/** 缓存代理组件暴露给外部 NativeAPI 的实体签名，编辑器示例 JSON 和运行时匹配都依赖这些字段。 */
USTRUCT()
struct FNativeAPISignature
{
	GENERATED_BODY()

	/** 保存 Owner 类路径字符串，对应 JSON 中的 EntityClass，Payload 按它定位实体类型。 */
	UPROPERTY(VisibleAnywhere, Category="Default")
	FString EntityClass;

	/** 保存逻辑实体名，对应 JSON 中的 Entity，用于区分同类多个代理目标。 */
	UPROPERTY(VisibleAnywhere, Category="Default")
	FString Entity;

	/** 保存组件实例路径，对应 JSON 中的 EntityPath，用于外部请求精确投递到这个组件。 */
	UPROPERTY(VisibleInstanceOnly, Category="Default")
	FString EntityPath;
};

/** 挂在 Actor 上的 NativeAPI 执行代理，负责注册到世界子系统并把匹配 Payload 转换为 Owner 上的 `API_` 函数调用。 */
UCLASS(MinimalAPI, meta=(BlueprintSpawnableComponent))
class UNativeAPIProxyComponent final : public UActorComponent, public INativeAPIEntityInterface
{
	GENERATED_BODY()

public:
	/** 关闭 Tick 并建立默认实体签名，使组件创建后即可注册到 NativeAPI 世界路由表。 */
	UNativeAPIProxyComponent(const FObjectInitializer& ObjectInitializer);

#if WITH_EDITOR
	virtual void PostInitProperties() override;
#endif

	/** 保留稳定的默认组件名，外部创建或查找代理组件时可使用同一名称。 */
	static FName NativeAPIProxyComponentDefaultName;

protected:
	virtual void OnRegister() override;
	virtual void OnUnregister() override;

#if WITH_EDITOR
	virtual void OnComponentCreated() override;
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
#endif

	virtual void ProcessingNativeAPI(const FNativeAPIPayload& Payload) const override;

	virtual FString GetEntity() const override;
	virtual UClass* GetEntityClass() const override;

public:
	/** 控制 Owner 隐藏时是否仍处理 Payload，允许隐藏 Actor 暂停 NativeAPI 驱动的函数调用。 */
	UFUNCTION(BlueprintCallable, Category="NativeAPI")
	void SetProcessOnOwnerHiddenEnable(bool bEnable);

private:
	/** 根据当前 Owner 刷新实体类、实体名和对象路径，保证注册表和编辑器示例 JSON 使用最新身份。 */
	void RefreshNativeAPIEntitySignature();

	/** 决定 Owner 处于 Hidden 状态时是否继续执行 API 任务，ProcessingNativeAPI 在调用函数前读取该开关。 */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Default", meta=(AllowPrivateAccess="true"))
	uint8 bProcessOnOwnerHidden : 1;

	/** 保存当前代理的对外实体签名，Payload 匹配、注册分桶和编辑器示例 JSON 都读取它。 */
	UPROPERTY(EditAnywhere, Category="Default", meta=(AllowPrivateAccess="true"))
	FNativeAPISignature NativeAPIEntity;

#if WITH_EDITOR
	/** 在编辑器中扫描 Owner 上所有 `API_` 函数并生成示例 JSON，方便配置或测试外部请求。 */
	void RefreshAPIJson();

#if WITH_EDITORONLY_DATA
	/** 显示当前 Owner 可接收的 NativeAPI 示例 Payload，包含实体签名和所有 `API_` 函数参数结构。 */
	UPROPERTY(VisibleAnywhere, Category="Default", meta=(AllowPrivateAccess="true", MultiLine))
	FString API;
#endif
#endif
};
