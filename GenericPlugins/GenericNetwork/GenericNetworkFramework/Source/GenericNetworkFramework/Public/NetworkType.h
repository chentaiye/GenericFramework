// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "NetworkType.generated.h"

GENERICNETWORKFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogNetwork, Log, All);

/** 同时保存本机设备标识和 OnlineSubsystem 的复制标识，作为会话创建、查找、加入和注册玩家时传递的统一玩家身份。 */
USTRUCT(BlueprintType)
struct GENERICNETWORKFRAMEWORK_API FUniqueNetworkID
{
	GENERATED_BODY()

public:
	/** 构造仅带本机设备标识的默认身份，用于还未能从玩家对象取得 Online UniqueId 的临时状态。 */
	FUniqueNetworkID();

	/** 从玩家控制器的 PlayerState 提取 Online UniqueId，供蓝图自动转换后直接参与会话请求。 */
	FUniqueNetworkID(const APlayerController* InPlayer);

	/** 从玩家状态读取已复制的 UniqueId，服务于 PlayerState 注册和组件刷新身份的路径。 */
	FUniqueNetworkID(const APlayerState* InPlayerState);

	/** 将外部传入的 FUniqueNetIdRepl 包装成框架身份，便于 Blueprint 和会话子系统使用同一种参数类型。 */
	FUniqueNetworkID(const FUniqueNetIdRepl& InUniqueNetIDRepl);
	bool operator==(const FUniqueNetworkID& Other) const { return UniqueID == Other.UniqueID; }
	bool operator!=(const FUniqueNetworkID& Other) const { return !(*this == Other); }

	/** 在调用 OnlineSession 接口前校验本机标识和 Online UniqueId 都可用，避免把无效玩家身份传入底层接口。 */
	bool CheckIsValid() const { return !UniqueID.IsEmpty() && UniqueNetIdRepl.IsValid(); }

	/** 为需要可空共享指针的调用点提供 Online UniqueId，保留底层接口的有效性语义。 */
	FUniqueNetIdPtr GetUniqueNetIDPtr() const { return UniqueNetIdRepl.GetUniqueNetId(); }

	/** 为 CreateSession、FindSessions、JoinSession 等要求引用参数的接口提供解包后的 Online UniqueId。 */
	const FUniqueNetId& GetUniqueNetID() const { return *UniqueNetIdRepl.GetUniqueNetId(); }

public:
	/** 保存本机设备 ID，作为框架层的额外身份信息并参与相等性判断。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	FString UniqueID;

	/** 保存 OnlineSubsystem 复制身份，实际传给会话创建、查找、加入和玩家注册逻辑。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	FUniqueNetIdRepl UniqueNetIdRepl;
};

/** 缓存框架发起的会话身份、名称和底层设置，供子系统按玩家或会话名回查并驱动 PlayerState 注册。 */
USTRUCT(BlueprintType)
struct GENERICNETWORKFRAMEWORK_API FGenericSessionHandle
{
	GENERATED_BODY()

public:
	/** 构造空句柄，作为蓝图输出参数或数组缓存项的初始值。 */
	FGenericSessionHandle()
	{
	}

	/** 在创建会话请求被接受后记录玩家身份、会话名和底层设置，供 UGenericSessionSubsystem 后续查询。 */
	FGenericSessionHandle(const FUniqueNetworkID& InUniqueNetID, const FName InSessionName, const FOnlineSessionSettings& InSessionSettings)
	{
		UniqueNetworkID = InUniqueNetID;
		SessionName = InSessionName;
		SessionSettings = InSessionSettings;
	}

	bool operator==(const FGenericSessionHandle& Other) const { return SessionName == Other.SessionName; }
	bool operator==(const FName OtherSessionName) const { return SessionName == OtherSessionName; }
	bool operator!=(const FGenericSessionHandle& Other) const { return !(*this == Other); }
	bool operator!=(const FName OtherSessionName) const { return !(*this == OtherSessionName); }

	/** 校验句柄是否能定位到一个已命名会话，并且其中的玩家身份足以供 OnlineSession 使用。 */
	bool CheckIsValid() const { return UniqueNetworkID.CheckIsValid() && SessionName != NAME_None; }

public:
	/** 保存创建或关联该会话的玩家身份，子系统可据此从 PlayerState 的 UniqueId 反查会话。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	FUniqueNetworkID UniqueNetworkID;

	/** 保存 OnlineSession 中的会话名，用于 Start、End、Destroy、RegisterPlayer 等生命周期调用。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	FName SessionName=NAME_None;

	/** 保留创建时传给 OnlineSession 的底层设置，便于运行期查询或调试会话配置。 */
	FOnlineSessionSettings SessionSettings;
};

/** 提供蓝图友好的会话创建配置，并负责与 FOnlineSessionSettings 之间相互编码和解码。 */
USTRUCT(BlueprintType)
struct GENERICNETWORKFRAMEWORK_API FGenericSessionSettings
{
	GENERATED_BODY()

public:
	/** 使用默认 GameSession 名称和常用 OnlineSession 开关初始化蓝图可编辑配置。 */
	FGenericSessionSettings();

	/** 从已有底层设置解码出蓝图字段，便于搜索结果和外部系统复用同一份配置结构。 */
	FGenericSessionSettings(const FOnlineSessionSettings& InSettings);

	/** 返回编码后的底层会话设置，供 UGenericSessionSubsystem 直接传入 OnlineSession。 */
	const FOnlineSessionSettings& GetSessionSettings() const;

	/** 替换底层会话设置并立即解码到蓝图字段，保持视图模型和搜索结果中的显示数据同步。 */
	void SetSessionSettings(const FOnlineSessionSettings& InSettings);

	/** 将蓝图字段写入 FOnlineSessionSettings，创建会话前用它生成 OnlineSubsystem 可识别的数据。 */
	void EncodeSessionSettings();

	/** 从 FOnlineSessionSettings 读取字段，搜索结果回填或外部设置导入时用于恢复蓝图可见状态。 */
	void DecodeSessionSettings();

public:
	/** 控制创建会话异步节点在 CreateSession 成功后是否继续调用 StartSession，再决定何时广播成功。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bIsAutoStart=true;

public:
	/** 写入公开连接数量，决定可通过匹配或大厅加入的玩家容量。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	int32 NumPublicConnections=4;

	/** 写入私有连接数量，保留给邀请或平台私有入口使用。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	int32 NumPrivateConnections=4;

	/** 决定会话是否向 OnlineSubsystem 广播，影响 FindSessions 能否搜索到该会话。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bShouldAdvertise=true;

	/** 控制会话开始后是否仍允许新玩家加入。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bAllowJoinInProgress=true;

	/** 标记会话是否按局域网匹配处理，创建和搜索双方需保持一致才能命中。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bIsLANMatch=false;

	/** 标记会话是否由专用服务器承载，供平台匹配和搜索过滤识别服务器形态。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bIsDedicated=false;

	/** 控制会话是否启用平台统计能力，编码后传给底层 OnlineSession 设置。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bUsesStats=true;

	/** 控制平台邀请入口是否允许玩家进入该会话。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bAllowInvites=true;

	/** 控制会话是否发布 Presence 信息，使好友和平台界面能感知玩家所在会话。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bUsesPresence=true;

	/** 控制玩家是否可以通过 Presence 入口加入该会话。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bAllowJoinViaPresence=true;

	/** 在允许 Presence 加入时进一步限制为好友入口，编码到对应的底层会话开关。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type", meta=(EditCondition="bAllowJoinViaPresence"))
	bool bAllowJoinViaPresenceFriendsOnly=false;

	/** 标记该会话是否启用反作弊保护，供平台服务和搜索结果识别安全状态。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bAntiCheatProtected=true;

	/** 当 OnlineSubsystem 支持大厅时优先使用大厅承载会话。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bUseLobbiesIfAvailable=true;

	/** 当使用大厅且平台支持时开启大厅语音通道。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bUseLobbiesVoiceChatIfAvailable=false;

public:
	/** 创建异步节点会在发起前写入当前地图名，并通过 SETTING_MAPNAME 对外广播。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	FString MapName;

	/** 保存框架层会话名，创建时转换为 FName，搜索结果解码后也用它恢复可加入的会话标识。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Network Type")
	FString SessionName;

	/** 作为自定义会话属性写入 SETTING_NUMBOTS，用于搜索结果展示或匹配过滤机器人数量。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	int32 NumRobots=0;

	/** 作为自定义会话属性写入 SETTING_NEEDS，用于表达房间还需要的玩家数量或匹配需求。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	int32 PlayerNeed=0;

	/** 作为自定义会话属性写入 SETTING_SESSIONKEY，供业务层区分或过滤同类会话。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	FString SessionKey;

private:
	/** 缓存实际传递给 OnlineSession 的底层设置，所有蓝图字段最终都会编码到这里。 */
	FOnlineSessionSettings SessionSettings;
};

/** 提供蓝图友好的会话搜索配置，并维护底层 FOnlineSessionSearch 对象供 OnlineSession 查询使用。 */
USTRUCT(BlueprintType)
struct GENERICNETWORKFRAMEWORK_API FGenericSessionSearchSettings
{
	GENERATED_BODY()

public:
	/** 构造默认搜索对象，保证后续 Encode 和 FindSessions 始终有有效的底层查询实例。 */
	FGenericSessionSearchSettings();

	/** 以外部搜索对象初始化并解码查询字段，便于视图模型复用正在进行或已完成的搜索。 */
	FGenericSessionSearchSettings(const TSharedRef<FOnlineSessionSearch>& InSettings);

	/** 返回底层搜索对象，FindSessions 会直接把它传给 OnlineSubsystem 并在完成后读取 SearchResults。 */
	TSharedRef<FOnlineSessionSearch> GetSessionSearchSettings() const;

	/** 替换底层搜索对象并解码到蓝图字段，确保 UI 展示的查询条件与实际对象一致。 */
	void SetSessionSearchSettings(const TSharedRef<FOnlineSessionSearch>& InSettings);

	/** 将蓝图查询字段写入 FOnlineSessionSearch，执行 FindSessions 前调用以生成实际搜索条件。 */
	void EncodeSessionSearchSettings();

	/** 从 FOnlineSessionSearch 读取查询字段，搜索完成或外部替换搜索对象后用于恢复 UI 状态。 */
	void DecodeSessionSearchSettings();

public:
	/** 限制一次搜索返回的最大会话数量，避免列表控件和回调承载过多结果。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	int32 MaxSearchResults=10;

	/** 指定搜索是否走局域网查询，需要与创建会话时的 LAN 标记匹配。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bIsLanQuery=false;

	/** 控制 OnlineSubsystem 搜索超时时间，影响异步查询等待多久后完成或失败。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	float TimeoutInSeconds=60.f;

public:
	/** 将 SEARCH_DEDICATED_ONLY 写入查询条件，只返回专用服务器会话。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bDedicatedOnly=false;

	/** 将 SEARCH_EMPTY_SERVERS_ONLY 写入查询条件，只返回无人占用的会话。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bEmptyServerOnly=false;

	/** 将 SEARCH_NONEMPTY_SERVERS_ONLY 写入查询条件，只返回已有玩家的会话。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	bool bNotEmptyServerOnly=false;

	/** 写入 SEARCH_USER 查询条件，用于按拥有者或平台用户名称筛选搜索结果。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	FString SearchUserName;

	/** 写入 SEARCH_KEYWORDS 查询条件，用于按业务关键字筛选会话。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Network Type")
	FString SearchKeywords;

private:
	/** 持有实际搜索对象，异步查询完成后也从这里读取搜索状态和结果数组。 */
	TSharedPtr<FOnlineSessionSearch> SessionSearchSettings = nullptr;
};

/** 将 OnlineSession 搜索结果拆解为蓝图可见字段，同时保留原始结果供 JoinSession 使用。 */
USTRUCT(BlueprintType)
struct GENERICNETWORKFRAMEWORK_API FGenericSessionSearchResult
{
	GENERATED_BODY()

public:
	/** 构造空搜索结果，用于列表和蓝图变量的默认占位。 */
	FGenericSessionSearchResult();

	/** 从底层搜索结果同步 Ping、拥有者、人数和会话设置，供 UI 展示和加入流程使用。 */
	FGenericSessionSearchResult(const FOnlineSessionSearchResult& InResult);

	/** 返回原始搜索结果，JoinSession 需要它解析连接地址并提交给 OnlineSubsystem。 */
	const FOnlineSessionSearchResult& GetSessionSearchResult() const;

	/** 替换原始搜索结果并同步蓝图字段，列表刷新和单会话刷新完成时都会调用。 */
	void SetSessionSearchResult(const FOnlineSessionSearchResult& InResult);

	/** 从解码出的会话设置中还原会话名，供 JoinSession 回调过滤和命名加入使用。 */
	FName GetSessionName() const;

public:
	/** 保存搜索结果的延迟数据，供会话列表排序或展示连接质量。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	int32 PingInMs=0;

	/** 保存会话拥有者的 Online UniqueId，单会话刷新会用它调用 FindSessionById。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	FUniqueNetIdRepl OwnerPlayerID;

	/** 保存会话拥有者名称，供搜索列表展示房主信息。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	FString OwningPlayerName;

	/** 根据最大连接数和剩余开放连接数计算出的当前玩家数量。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	int32 CurrentPlayers=0;

	/** 保存公开和私有连接总数，用作会话容量显示。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	int32 MaxPlayers=0;

	/** 保存从搜索结果解码出的会话设置，列表和详情面板通过它读取地图名、会话名和自定义属性。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network Type")
	FGenericSessionSettings SessionSettings;

private:
	/** 保留底层搜索结果对象，加入会话时必须把它原样传回 OnlineSession。 */
	FOnlineSessionSearchResult SessionSearchResult;
};

/** 蓝图可用的加入会话结果枚举，与 EOnJoinSessionCompleteResult 保持一一映射。 */
UENUM(BlueprintType)
enum class EJoinSessionResult : uint8
{
	/** 已加入会话，异步节点会尝试解析连接地址并让玩家 ClientTravel。 */
	Success,

	/** 目标会话容量已满，调用方应提示用户重新选择房间。 */
	SessionIsFull,

	/** 目标会话在平台服务中不存在或已失效。 */
	SessionDoesNotExist,

	/** 加入成功回调无法解析连接地址，玩家无法跳转到目标会话。 */
	CouldNotRetrieveAddress,

	/** 玩家已经处于同一会话中，无需再次加入。 */
	AlreadyInSession,

	/** 平台返回未细分的失败原因，作为兜底错误分支广播给蓝图。 */
	UnknownError
};

/** 将蓝图枚举转换为 OnlineSession 原生结果，供需要回写底层类型的代码路径使用。 */
inline EOnJoinSessionCompleteResult::Type ConvertToJoinSessionResult(const EJoinSessionResult EnumBP)
{
	switch (EnumBP)
	{
	case EJoinSessionResult::Success:
		return EOnJoinSessionCompleteResult::Success;
	case EJoinSessionResult::SessionIsFull:
		return EOnJoinSessionCompleteResult::SessionIsFull;
	case EJoinSessionResult::SessionDoesNotExist:
		return EOnJoinSessionCompleteResult::SessionDoesNotExist;
	case EJoinSessionResult::CouldNotRetrieveAddress:
		return EOnJoinSessionCompleteResult::CouldNotRetrieveAddress;
	case EJoinSessionResult::AlreadyInSession:
		return EOnJoinSessionCompleteResult::AlreadyInSession;
	case EJoinSessionResult::UnknownError:
		return EOnJoinSessionCompleteResult::UnknownError;
	}
	return EOnJoinSessionCompleteResult::UnknownError;
}

/** 将 OnlineSession 原生加入结果转换为蓝图枚举，JoinSession 异步节点完成广播时使用。 */
inline EJoinSessionResult ConvertToJoinSessionResultBP(EOnJoinSessionCompleteResult::Type Enum)
{
	switch (Enum)
	{
	case EOnJoinSessionCompleteResult::Success:
		return EJoinSessionResult::Success;
	case EOnJoinSessionCompleteResult::SessionIsFull:
		return EJoinSessionResult::SessionIsFull;
	case EOnJoinSessionCompleteResult::SessionDoesNotExist:
		return EJoinSessionResult::SessionDoesNotExist;
	case EOnJoinSessionCompleteResult::CouldNotRetrieveAddress:
		return EJoinSessionResult::CouldNotRetrieveAddress;
	case EOnJoinSessionCompleteResult::AlreadyInSession:
		return EJoinSessionResult::AlreadyInSession;
	case EOnJoinSessionCompleteResult::UnknownError:
		return EJoinSessionResult::UnknownError;
	}
	return EJoinSessionResult::UnknownError;
}
