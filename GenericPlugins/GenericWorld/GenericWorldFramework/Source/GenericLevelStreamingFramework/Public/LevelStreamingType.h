#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
#include "LevelStreamingType.generated.h"

GENERICLEVELSTREAMINGFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogLevelStreaming, Log, All);

GENERICLEVELSTREAMINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelStreaming);
GENERICLEVELSTREAMINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelStreaming_OnLoadLevelStreamingHandleRegister);
GENERICLEVELSTREAMINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelStreaming_OnUnLoadLevelStreamingHandleRegister);
GENERICLEVELSTREAMINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelStreaming_OnSetLevelStreamingVisibilityHandleRegister);
GENERICLEVELSTREAMINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelStreaming_OnDefaultLevelsLoadStart);
GENERICLEVELSTREAMINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelStreaming_OnDefaultLevelsLoadOnceFinish);
GENERICLEVELSTREAMINGFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_LevelStreaming_OnDefaultLevelsLoadFinish);

DECLARE_DELEGATE(FOnHandleLevelStreamingOnceFinish);
DECLARE_DELEGATE(FOnHandleLevelStreamingFinish);
DECLARE_DELEGATE(FOnLevelVisibilityChanged);

class UGenericLevelStreamingSubsystem;
class UWorld;

UENUM(BlueprintType)
enum class EDefaultLevelStreamingLoadPhase : uint8
{
	Load,
	Visibility
};

USTRUCT(BlueprintType)
struct GENERICLEVELSTREAMINGFRAMEWORK_API FOnDefaultLevelsLoadStartMessage
{
	GENERATED_BODY()

	/** 标识发出默认关卡加载事件的世界级流送子系统，监听方可据此区分 PIE 多世界上下文。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	TObjectPtr<UGenericLevelStreamingSubsystem> GenericLevelStreamingSubsystem = nullptr;

	/** 本次任务会先提交为 LoadedNotVisible 的关卡队列，Visible 队列中的关卡也会先经过这一阶段。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	TArray<TSoftObjectPtr<UWorld>> LevelsToLoad;

	/** 所有关卡加载阶段完成后，继续切换到可见状态的关卡队列。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	TArray<TSoftObjectPtr<UWorld>> LevelsToSetVisible;

	/** 加载项与可视性项的总数，用于外部进度条或流程编排判断整体进度。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	int32 TotalCount = 0;
};

USTRUCT(BlueprintType)
struct GENERICLEVELSTREAMINGFRAMEWORK_API FOnDefaultLevelsLoadOnceFinishMessage
{
	GENERATED_BODY()

	/** 标识发出默认关卡加载事件的世界级流送子系统，监听方可据此区分 PIE 多世界上下文。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	TObjectPtr<UGenericLevelStreamingSubsystem> GenericLevelStreamingSubsystem = nullptr;

	/** 刚完成加载或可视性切换的关卡。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	TSoftObjectPtr<UWorld> Level = nullptr;

	/** 标识本次完成来自预加载阶段还是可视性切换阶段。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	EDefaultLevelStreamingLoadPhase Phase = EDefaultLevelStreamingLoadPhase::Load;

	/** 从任务开始到当前为止已经完成的加载项或可视性项数量。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	int32 FinishedCount = 0;

	/** 本轮任务需要等待的总项数。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	int32 TotalCount = 0;
};

USTRUCT(BlueprintType)
struct GENERICLEVELSTREAMINGFRAMEWORK_API FOnDefaultLevelsLoadFinishMessage
{
	GENERATED_BODY()

	/** 标识发出默认关卡加载事件的世界级流送子系统，监听方可据此区分 PIE 多世界上下文。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	TObjectPtr<UGenericLevelStreamingSubsystem> GenericLevelStreamingSubsystem = nullptr;

	/** 本次任务实际提交过的隐藏加载队列。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	TArray<TSoftObjectPtr<UWorld>> LevelsToLoad;

	/** 本次任务在加载完成后实际提交过的可见队列。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	TArray<TSoftObjectPtr<UWorld>> LevelsToSetVisible;

	/** 最终完成时的总项数，正常情况下应与完成项数一致。 */
	UPROPERTY(BlueprintReadOnly, Category="Default Levels Load Message")
	int32 TotalCount = 0;
};

/** 描述一次关卡加载请求的目标与策略，供蓝图函数、异步节点和句柄队列共用同一份参数。 */
USTRUCT(BlueprintType)
struct FLoadLevelStreamingSetting
{
	GENERATED_BODY()

public:
	/** 指向当前 Persistent World 中某个流关卡资产；子系统会在提交前确认它属于当前世界。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level Streaming Type")
	TSoftObjectPtr<UWorld> Level = nullptr;

	/** 控制 UE 加载完成后是否立即进入可见状态，用于区分预加载和直接展示。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level Streaming Type")
	bool bMakeVisibleAfterLoad = false;

	/** 透传给 LatentAction 的阻塞加载选项，通常保持异步以避免卡住游戏线程。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level Streaming Type")
	bool bShouldBlockOnLoad = false;

public:
	/** 创建空请求，等待调用方后续填入目标关卡。 */
	FLoadLevelStreamingSetting() { return; }

	/** 将蓝图或 C++ 调用侧的加载参数打包成句柄可以顺序执行的设置项。 */
	FLoadLevelStreamingSetting(const TSoftObjectPtr<UWorld>& InLevel, const bool MakeVisibleAfterLoad, const bool ShouldBlockOnLoad)
		: Level(InLevel),
		  bMakeVisibleAfterLoad(MakeVisibleAfterLoad),
		  bShouldBlockOnLoad(ShouldBlockOnLoad) { return; }

	/** 只有配置了目标关卡时才允许进入子系统的调度队列。 */
	bool IsValid() const { return !Level.IsNull(); }

	bool operator==(const FLoadLevelStreamingSetting& Other) const { return Level == Other.Level; }
	bool operator==(const TSoftObjectPtr<UWorld>& Other) const { return Level == Other; }
	bool operator!=(const FLoadLevelStreamingSetting& Other) const { return !(*this == Other); }
	bool operator!=(const TSoftObjectPtr<UWorld>& Other) const { return !(*this == Other); }
};

/** 描述一次关卡卸载请求，和加载设置保持同一套去重与冲突裁剪规则。 */
USTRUCT(BlueprintType)
struct FUnloadLevelStreamingSetting
{
	GENERATED_BODY()

public:
	/** 指向要从当前世界卸载的流关卡资产。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level Streaming Type")
	TSoftObjectPtr<UWorld> Level = nullptr;

	/** 透传给 UE 卸载接口的阻塞选项，适合少数必须同步完成的切换流程。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level Streaming Type")
	bool bShouldBlockOnUnload = false;

public:
	/** 创建空卸载请求，保持无目标时不会被子系统执行。 */
	FUnloadLevelStreamingSetting() { return; }

	/** 将卸载目标和阻塞策略合并为句柄队列中的一个执行项。 */
	FUnloadLevelStreamingSetting(const TSoftObjectPtr<UWorld>& InLevel, const bool ShouldBlockOnUnload)
		: Level(InLevel),
		  bShouldBlockOnUnload(ShouldBlockOnUnload) { return; }

	/** 只有存在目标关卡时才参与卸载请求过滤和调度。 */
	bool IsValid() const { return !Level.IsNull(); }

	bool operator==(const FUnloadLevelStreamingSetting& Other) const { return Level == Other.Level; }
	bool operator==(const TSoftObjectPtr<UWorld>& Other) const { return Level == Other; }
	bool operator!=(const FUnloadLevelStreamingSetting& Other) const { return !(*this == Other); }
	bool operator!=(const TSoftObjectPtr<UWorld>& Other) const { return !(*this == Other); }
};

/** 描述一次关卡可见性请求；需要可见但尚未加载时，句柄会先发起加载再应用可见性。 */
USTRUCT(BlueprintType)
struct FSetLevelStreamingVisibilitySetting
{
	GENERATED_BODY()

public:
	/** 指向要切换渲染可见性的流关卡资产。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level Streaming Type")
	TSoftObjectPtr<UWorld> Level = nullptr;

	/** 目标可见状态；为 true 时会确保关卡已加载，为 false 时只处理已加载关卡。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Level Streaming Type")
	bool bVisible = false;

public:
	/** 创建空可见性请求，避免未指定关卡时进入执行队列。 */
	FSetLevelStreamingVisibilitySetting() { return; }

	/** 将目标关卡和期望可见状态打包给可见性句柄顺序处理。 */
	FSetLevelStreamingVisibilitySetting(const TSoftObjectPtr<UWorld>& InLevel, const bool Visible)
		: Level(InLevel),
		  bVisible(Visible) { return; }

	/** 只有存在目标关卡时才允许提交可见性切换。 */
	bool IsValid() const { return !Level.IsNull(); }

	bool operator==(const FSetLevelStreamingVisibilitySetting& Other) const { return Level == Other.Level; }
	bool operator==(const TSoftObjectPtr<UWorld>& Other) const { return Level == Other; }
	bool operator!=(const FSetLevelStreamingVisibilitySetting& Other) const { return !(*this == Other); }
	bool operator!=(const TSoftObjectPtr<UWorld>& Other) const { return !(*this == Other); }
};
