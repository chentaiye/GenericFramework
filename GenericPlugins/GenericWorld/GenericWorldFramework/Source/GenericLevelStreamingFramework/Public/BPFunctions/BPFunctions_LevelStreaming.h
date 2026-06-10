// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelStreamingType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_LevelStreaming.generated.h"

class ULevelStreamingHandle;

DECLARE_DYNAMIC_DELEGATE(FHandleLevelStreamingOnceFinish);
DECLARE_DYNAMIC_DELEGATE(FHandleLevelStreamingFinish);
DECLARE_DYNAMIC_DELEGATE_OneParam(FHandleLevelStreamingK2OnceFinish, TSoftObjectPtr<UWorld>, CompletedLevel);
DECLARE_DYNAMIC_DELEGATE(FHandleLevelStreamingK2Finish);

/** 提供蓝图可直接调用的关卡流送入口，内部统一转发到当前世界的 GenericLevelStreamingSubsystem。 */
UCLASS(MinimalAPI)
class UBPFunctions_LevelStreaming : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 提交单个流关卡加载请求，并在句柄整批完成时触发回调。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void LoadLevel(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FHandleLevelStreamingFinish OnFinish);

	/** 用同一套加载策略批量提交关卡列表，按句柄顺序逐个完成。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void LoadLevels(const UObject* WorldContextObject, TArray<TSoftObjectPtr<UWorld>> Levels, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish);

	/** 批量提交带独立加载策略的设置项，适合预加载和立即显示混用的流程。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void LoadLevelsBySetting(const UObject* WorldContextObject, TArray<FLoadLevelStreamingSetting> LoadLevelStreamingSettings, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish);

	/** 提交单个流关卡卸载请求，并在卸载句柄完成时触发回调。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void UnloadLevel(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level, bool bShouldBlockOnUnload, FHandleLevelStreamingFinish OnFinish);

	/** 用同一套卸载策略批量提交关卡列表，适合退出某个区域时按队列清理子关卡。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void UnloadLevels(const UObject* WorldContextObject, TArray<TSoftObjectPtr<UWorld>> Levels, bool bShouldBlockOnUnload, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish);

	/** 批量提交带独立阻塞策略的卸载设置项。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void UnloadLevelsBySetting(const UObject* WorldContextObject, TArray<FUnloadLevelStreamingSetting> UnloadLevelStreamingSettings, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish);

	/** 切换单个流关卡可见性；显示未加载关卡时由底层句柄先加载再显示。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void SetLevelVisibility(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level, bool bVisible, FHandleLevelStreamingFinish OnFinish);

	/** 用同一个目标状态批量切换关卡可见性，并为每个关卡触发一次完成回调。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void SetLevelsVisibility(const UObject* WorldContextObject, TArray<TSoftObjectPtr<UWorld>> Levels, bool bVisible, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish);

	/** 批量提交带独立目标状态的可见性设置项，允许同批次内同时显示和隐藏不同关卡。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void SetLevelsVisibilityBySetting(const UObject* WorldContextObject, TArray<FSetLevelStreamingVisibilitySetting> SetLevelStreamingVisibilitySettings, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish);

	/** K2Node 专用加载入口：返回底层句柄，并把句柄的单项完成关卡转成节点输出数据。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming|K2Node", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API ULevelStreamingHandle* K2Node_LoadLevels(const UObject* WorldContextObject, TArray<TSoftObjectPtr<UWorld>> Levels, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FHandleLevelStreamingK2OnceFinish OnOnceFinish, FHandleLevelStreamingK2Finish OnFinish);

	/** K2Node 专用卸载入口：复用子系统队列，同时保留每个完成关卡的输出。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming|K2Node", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API ULevelStreamingHandle* K2Node_UnloadLevels(const UObject* WorldContextObject, TArray<TSoftObjectPtr<UWorld>> Levels, bool bShouldBlockOnUnload, FHandleLevelStreamingK2OnceFinish OnOnceFinish, FHandleLevelStreamingK2Finish OnFinish);

	/** K2Node 专用可见性入口：显示未加载关卡时仍由可见性句柄先加载再切换显示。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming|K2Node", meta=(WorldContext="WorldContextObject", BlueprintInternalUseOnly="true"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API ULevelStreamingHandle* K2Node_SetLevelsVisibility(const UObject* WorldContextObject, TArray<TSoftObjectPtr<UWorld>> Levels, bool bVisible, FHandleLevelStreamingK2OnceFinish OnOnceFinish, FHandleLevelStreamingK2Finish OnFinish);

public:
	/** 预加载当前世界中尚未加载且不是 AlwaysLoaded 的全部流关卡，加载后默认保持隐藏。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void LoadCurrentWorldLevelStreaming(const UObject* WorldContextObject, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish);

	/** 卸载当前世界中已经加载且不是 AlwaysLoaded 的流关卡。 */
	UFUNCTION(BlueprintCallable, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API void UnLoadCurrentWorldLevelStreaming(const UObject* WorldContextObject, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish);

public:
	/** 查询当前世界里可由本系统批量加载的流关卡列表，过滤已加载和 AlwaysLoaded 关卡。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API TArray<TSoftObjectPtr<UWorld>> GetCurrentWorldLevelStreamingList(const UObject* WorldContextObject);

	/** 根据软引用解析当前世界中的 ULevelStreaming 对象，供状态查询或句柄内部复用。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API ULevelStreaming* GetLevelStreaming(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level);

	/** 判断目标流关卡当前是否已经处于加载完成状态。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API bool IsLevelLoaded(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level);

	/** 检查软引用是否指向当前 Persistent World 管理的流关卡，避免跨世界提交无效请求。 */
	UFUNCTION(BlueprintPure, Category="Level Streaming", meta=(WorldContext="WorldContextObject"))
	static GENERICLEVELSTREAMINGFRAMEWORK_API bool IsCurrentWorldContainLevel(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level, bool& Contain);
};
