// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NetworkType.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "GenericSessionSubsystem.generated.h"

class USessionSearchSettingViewModel;
class USessionSettingViewModel;

/** 作为 GameInstance 级会话调度入口，封装 OnlineSession 请求、回调绑定和框架会话句柄缓存。 */
UCLASS(MinimalAPI)
class UGenericSessionSubsystem : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static GENERICNETWORKFRAMEWORK_API UGenericSessionSubsystem* Get(const UObject* WorldContextObject);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

public:
	/** 使用蓝图友好的会话设置发起创建请求，并按设置中的会话名写入框架句柄缓存。 */
	GENERICNETWORKFRAMEWORK_API bool CreateSession(const FUniqueNetworkID& InUniqueNetID, const FGenericSessionSettings& InSessionSettings, const FOnCreateSessionCompleteDelegate& OnComplete = FOnCreateSessionCompleteDelegate());

	/** 直接以底层会话设置调用 OnlineSession::CreateSession，并在请求被接受后缓存玩家、会话名和设置。 */
	GENERICNETWORKFRAMEWORK_API bool CreateSession(const FUniqueNetworkID& InUniqueNetID, FName InSessionName, const FOnlineSessionSettings& InSessionSettings, const FOnCreateSessionCompleteDelegate& OnComplete = FOnCreateSessionCompleteDelegate());

	/** 将指定会话推进到已开始状态，创建异步节点的自动开始分支和蓝图 Start 节点都会走这里。 */
	GENERICNETWORKFRAMEWORK_API bool StartSession(FName InSessionName, const FOnStartSessionCompleteDelegate& OnComplete = FOnStartSessionCompleteDelegate());

	/** 使用蓝图搜索设置发起会话搜索，内部会取出底层 FOnlineSessionSearch 对象提交给 OnlineSession。 */
	GENERICNETWORKFRAMEWORK_API bool FindSessions(const FUniqueNetworkID& InUniqueNetID, const FGenericSessionSearchSettings& InSessionSearchSettings, const FOnFindSessionsCompleteDelegate& OnComplete = FOnFindSessionsCompleteDelegate());

	/** 直接提交底层搜索对象并绑定完成回调，搜索结果会保留在传入的 FOnlineSessionSearch 中。 */
	GENERICNETWORKFRAMEWORK_API bool FindSessions(const FUniqueNetworkID& InUniqueNetID, const TSharedRef<FOnlineSessionSearch>& InSessionSearchSettings, const FOnFindSessionsCompleteDelegate& OnComplete = FOnFindSessionsCompleteDelegate());

	/** 从搜索结果中提取拥有者身份并查询单个会话，用于列表项选中后刷新房间详情。 */
	GENERICNETWORKFRAMEWORK_API bool FindSingleSession(const FUniqueNetworkID& InUniqueNetID, const FGenericSessionSearchResult& InResult, const FOnSingleSessionResultCompleteDelegate& OnComplete = FOnSingleSessionResultCompleteDelegate());

	/** 使用本地玩家身份和目标会话拥有者身份调用 FindSessionById，刷新指定房间的最新状态。 */
	GENERICNETWORKFRAMEWORK_API bool FindSingleSession(const FUniqueNetworkID& InPlayerUniqueNetID, const FUniqueNetworkID& InSessionPlayerUniqueNetID, const FOnSingleSessionResultCompleteDelegate& OnComplete = FOnSingleSessionResultCompleteDelegate());

	/** 请求取消当前会话搜索，并把 OnlineSession 的取消完成结果转发给调用方。 */
	GENERICNETWORKFRAMEWORK_API bool CancelFindSessions(const FOnCancelFindSessionsCompleteDelegate& OnComplete = FOnCancelFindSessionsCompleteDelegate());

	/** 使用搜索结果中的会话名和原始搜索结果加入会话，供蓝图异步节点的常规路径调用。 */
	GENERICNETWORKFRAMEWORK_API bool JoinSession(const FUniqueNetworkID& InUniqueNetID, const FGenericSessionSearchResult& InResult, const FOnJoinSessionCompleteDelegate& OnComplete = FOnJoinSessionCompleteDelegate());

	/** 使用指定会话名和封装搜索结果加入会话，允许调用方覆盖搜索结果中解码出的名称。 */
	GENERICNETWORKFRAMEWORK_API bool JoinSession(const FUniqueNetworkID& InUniqueNetID, FName InSessionName, const FGenericSessionSearchResult& InResult, const FOnJoinSessionCompleteDelegate& OnComplete = FOnJoinSessionCompleteDelegate());

	/** 直接把底层搜索结果提交给 OnlineSession::JoinSession，是所有加入重载的最终执行路径。 */
	GENERICNETWORKFRAMEWORK_API bool JoinSession(const FUniqueNetworkID& InUniqueNetID, FName InSessionName, const FOnlineSessionSearchResult& InResult, const FOnJoinSessionCompleteDelegate& OnComplete = FOnJoinSessionCompleteDelegate());

	/** 结束指定会话的活动状态，给保留会话但停止对局的流程使用。 */
	GENERICNETWORKFRAMEWORK_API bool EndSession(FName InSessionName, const FOnEndSessionCompleteDelegate& OnComplete = FOnEndSessionCompleteDelegate());

	/** 销毁指定会话并转发完成回调，调用失败时立即清理本次绑定的完成代理。 */
	GENERICNETWORKFRAMEWORK_API bool DestroySession(FName InSessionName, const FOnDestroySessionCompleteDelegate& OnComplete = FOnDestroySessionCompleteDelegate());

	/** 向 OnlineSession 查询指定玩家是否已经注册到目标会话中。 */
	GENERICNETWORKFRAMEWORK_API bool IsPlayerInSession(FName InSessionName, const FUniqueNetworkID& InUniqueNetID);

public:
	/** 按框架玩家身份查找已缓存的会话句柄，蓝图辅助函数和 PlayerState 注册会使用该查询。 */
	GENERICNETWORKFRAMEWORK_API bool GetSessionHandle(const FUniqueNetworkID& UniqueNetworkID, FGenericSessionHandle& OutHandle);

	/** 按 Online UniqueId 查找会话句柄，避免调用方必须先构造完整的 FUniqueNetworkID。 */
	GENERICNETWORKFRAMEWORK_API bool GetSessionHandle(const FUniqueNetIdRepl& UniqueNetIDRepl, FGenericSessionHandle& OutHandle);

	/** 按会话名查找缓存句柄，供只持有 SessionName 的生命周期流程回查设置。 */
	GENERICNETWORKFRAMEWORK_API bool GetSessionHandle(FName InSessionName, FGenericSessionHandle& OutHandle);

private:
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;

	/** 创建会话失败时移除预先缓存的句柄，避免后续 PlayerState 注册使用无效会话名。 */
	void OnCreateSessionComplete(FName InSessionName, bool bWasSuccessful);

	/** 保存本框架已发起创建的会话句柄，使玩家注册、蓝图查询和生命周期调用能复用同一会话上下文。 */
	UPROPERTY()
	TArray<FGenericSessionHandle> SessionHandles;
};
