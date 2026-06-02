// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkType.h"
#include "SessionAsyncActionBase.h"
#include "JoinSessionAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJoinSessionComplete, EJoinSessionResult, Result);

/** 蓝图加入会话异步节点，提交 JoinSession 后在成功时解析连接地址并驱动本地玩家 ClientTravel。 */
UCLASS(MinimalAPI)
class UJoinSessionAsyncAction : public USessionAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	GENERICNETWORKFRAMEWORK_API virtual void Activate() override;

public:
	/** 创建加入会话节点并缓存玩家身份和搜索结果，Activate 会把原始搜索结果提交给会话子系统。 */
	UFUNCTION(BlueprintCallable, Category="Generic Session", meta=(WorldContext="InWorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICNETWORKFRAMEWORK_API UJoinSessionAsyncAction* JoinSession(UObject* InWorldContextObject, const FUniqueNetworkID& InPlayerNetID, const FGenericSessionSearchResult& InSessionSearchResult);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FJoinSessionComplete OnComplete;

private:
	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;

	/** 处理加入结果：匹配会话名后清理代理，成功时解析连接串并让对应玩家跳转。 */
	void OnJoinSessionComplete(FName InSessionName, EOnJoinSessionCompleteResult::Type Result);

	/** 保存加入会话的玩家身份，既用于 JoinSession 请求，也用于成功后查找需要跳转的 PlayerController。 */
	UPROPERTY()
	FUniqueNetworkID UniqueNetID;

	/** 保存目标会话搜索结果，JoinSession 和完成回调都依赖其中的原始结果与会话名。 */
	UPROPERTY()
	FGenericSessionSearchResult SessionSearchResult;
};
