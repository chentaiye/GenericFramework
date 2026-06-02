// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SessionAsyncActionBase.h"
#include "CreateSessionAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreateSessionSuccess, const FGenericSessionSettings&, SessionSettings);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCreateSessionFail);

/** 蓝图创建会话异步节点，负责编码会话设置、发起 CreateSession，并按配置决定是否继续 StartSession。 */
UCLASS(MinimalAPI)
class UCreateSessionAsyncAction : public USessionAsyncActionBase
{
	GENERATED_UCLASS_BODY()

public:
	GENERICNETWORKFRAMEWORK_API virtual void Activate() override;

public:
	/** 创建异步节点实例并缓存玩家身份和会话设置，真正的 OnlineSession 请求会在 Activate 中执行。 */
	UFUNCTION(BlueprintCallable, Category="Generic Session", meta=(WorldContext="InWorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICNETWORKFRAMEWORK_API UCreateSessionAsyncAction* CreateSession(UObject* InWorldContextObject, const FUniqueNetworkID& InPlayerNetID, const FGenericSessionSettings& InSessionSettings);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FCreateSessionSuccess OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FCreateSessionFail OnFail;

private:
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;

	/** 处理 CreateSession 完成回调：清理创建代理，并按 bIsAutoStart 决定继续启动或直接广播结果。 */
	void OnCreateSessionComplete(FName InSessionName, bool bWasSuccessful);

	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;

	/** 处理自动 StartSession 的完成回调，只有匹配本节点会话名时才广播最终成功或失败。 */
	void OnStartSessionComplete(FName InSessionName, bool bWasSuccessful);

	/** 保存创建会话的玩家身份，传入 UGenericSessionSubsystem 后用于 OnlineSession::CreateSession。 */
	UPROPERTY()
	FUniqueNetworkID UniqueNetID;

	/** 保存蓝图传入的会话配置，Activate 会补充当前地图名并编码到底层设置。 */
	UPROPERTY()
	FGenericSessionSettings SessionSettings;
};
