// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkType.h"
#include "Components/ActorComponent.h"
#include "UniqueNetworkIDComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUniqueNetworkIDChanged, const FUniqueNetworkID&, UniqueNetworkID);

/** 可复制的网络身份组件，负责从拥有者提取玩家 UniqueId，在权威端刷新并向客户端广播变化。 */
UCLASS(MinimalAPI, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UUniqueNetworkIDComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** 禁用 Tick 并开启默认复制，使组件只在身份刷新或复制回调时更新状态。 */
	UUniqueNetworkIDComponent();
	virtual void BeginPlay() override;
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

public:
	/** 在当前缓存身份有效时输出 FUniqueNetworkID，供蓝图安全读取复制后的玩家身份。 */
	UFUNCTION(BlueprintPure, Category="Unique Network ID Component")
	GENERICNETWORKFRAMEWORK_API bool GetUniqueNetworkID(FUniqueNetworkID& OutUniqueNetworkID) const;

	/** 根据拥有者类型在权威端重新生成身份；自治代理会通过 Server RPC 请求服务器执行刷新。 */
	UFUNCTION(BlueprintCallable, Category="Unique Network ID Component")
	GENERICNETWORKFRAMEWORK_API void RefreshUniqueNetworkID();

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnUniqueNetworkIDChanged OnUniqueNetworkIDChangedEvent;

protected:
	/** 身份复制或本地刷新后触发的蓝图扩展点，允许拥有者同步 UI 或业务状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Unique Network ID Component")
	GENERICNETWORKFRAMEWORK_API void OnUniqueNetworkIDChanged(const FUniqueNetworkID& InUniqueNetworkID);

private:
	/** 自治代理请求服务器刷新身份，确保复制变量只由权威端写入。 */
	UFUNCTION(Server, Reliable, Category="Unique Network ID Component")
	void Server_RefreshUniqueNetworkID();

	/** 复制身份变化时统一触发蓝图事件和动态委托，保持本地刷新与网络复制后的通知路径一致。 */
	UFUNCTION(Category="Unique Network ID Component")
	virtual void OnRep_UniqueNetworkID();

	/** 保存权威端生成并复制到客户端的框架网络身份。 */
	UPROPERTY(ReplicatedUsing="OnRep_UniqueNetworkID")
	FUniqueNetworkID UniqueNetworkID;
};
