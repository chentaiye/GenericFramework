// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SessionAsyncActionBase.h"
#include "FindSingleSessionAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFindSingleSessionSuccess, const FGenericSessionSearchResult&, SessionSearchResult);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFindSingleSessionFail);

/** 蓝图单会话刷新异步节点，通过 FindSessionById 拉取指定会话的最新搜索结果。 */
UCLASS(MinimalAPI)
class UFindSingleSessionAsyncAction : public USessionAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	GENERICNETWORKFRAMEWORK_API virtual void Activate() override;

public:
	/** 创建单会话查询节点，并缓存本地玩家身份与目标会话拥有者身份。 */
	UFUNCTION(BlueprintCallable, Category="Generic Session", meta=(WorldContext="InWorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICNETWORKFRAMEWORK_API UFindSingleSessionAsyncAction* FindSingleSession(UObject* InWorldContextObject, const FUniqueNetworkID& InPlayerUniqueNetID, const FUniqueNetworkID& InSessionPlayerUniqueNetID);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FFindSingleSessionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FFindSingleSessionFail OnFail;

private:
	FOnSingleSessionResultCompleteDelegate OnSingleSessionResultCompleteDelegate;

	/** 接收 FindSessionById 的结果并直接广播刷新后的底层搜索结果或失败分支。 */
	void OnFindSessionComplete(int32 InPlayerIndex, bool bWasSuccessful, const FOnlineSessionSearchResult& InResult);

	/** 保存发起查询的本地玩家身份，作为 FindSessionById 的查询者。 */
	UPROPERTY()
	FUniqueNetworkID PlayerUniqueNetID;

	/** 保存目标会话拥有者身份，用于定位需要刷新的单个会话。 */
	UPROPERTY()
	FUniqueNetworkID SessionPlayerUniqueNetID;
};
