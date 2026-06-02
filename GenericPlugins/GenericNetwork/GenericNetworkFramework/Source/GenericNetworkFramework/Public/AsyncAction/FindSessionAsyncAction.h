// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkType.h"
#include "SessionAsyncActionBase.h"
#include "FindSessionAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFindSessionSuccess, const TArray<FGenericSessionSearchResult>&, SessionSearchResults);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFindSessionFail);

/** 蓝图搜索会话异步节点，负责编码查询条件、发起 FindSessions，并把底层搜索结果转换为框架结果数组。 */
UCLASS(MinimalAPI)
class UFindSessionAsyncAction : public USessionAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	GENERICNETWORKFRAMEWORK_API virtual void Activate() override;

public:
	/** 创建搜索异步节点实例并缓存玩家身份和查询设置，实际搜索在 Activate 中提交。 */
	UFUNCTION(BlueprintCallable, Category="Generic Session", meta=(WorldContext="InWorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICNETWORKFRAMEWORK_API UFindSessionAsyncAction* FindSessions(UObject* InWorldContextObject, const FUniqueNetworkID& InPlayerNetID, const FGenericSessionSearchSettings& InSessionSearchSettings);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FFindSessionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FFindSessionFail OnFail;

private:
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;

	/** 搜索完成后清理代理、解码查询状态，并把 SearchResults 包装成蓝图可读数组。 */
	void OnFindSessionsComplete(bool bWasSuccessful);

	/** 保存发起搜索的玩家身份，作为 OnlineSession::FindSessions 的查询主体。 */
	UPROPERTY()
	FUniqueNetworkID UniqueNetID;

	/** 保存搜索条件和底层搜索对象，回调阶段从同一对象读取搜索状态与结果。 */
	UPROPERTY()
	FGenericSessionSearchSettings SessionSearchSettings;

	/** 缓存转换后的搜索结果数组，确保广播给蓝图时结果对象在节点生命周期内有效。 */
	UPROPERTY()
	TArray<FGenericSessionSearchResult> SessionSearchResults;
};
