// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MovieSceneSequencePlaybackSettings.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "GenericLevelSequenceSubsystem.generated.h"

class ULevelSequence;
class UGenericLevelSequenceHandle;

/** 世界级关卡序列句柄管理器，负责创建、登记并关闭基于 LevelSequencePlayer 的电影场景句柄。 */
UCLASS(MinimalAPI)
class UGenericLevelSequenceSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	static LEVELSEQUENCESYSTEM_API UGenericLevelSequenceSubsystem* Get(const UObject* WorldContextObject);

public:
	/** 校验 LevelSequence 后创建 Actor/Player 组合，并把它们交给句柄统一管理。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Subsystem", meta=(WorldContext="WorldContextObject"))
	static LEVELSEQUENCESYSTEM_API UGenericLevelSequenceHandle* ConstructLevelSequenceHandle(const UObject* WorldContextObject, ULevelSequence* InLevelSequence, const FMovieSceneSequencePlaybackSettings& InSettings);

	/** 从子系统移除句柄并触发 CloseMovieScene，确保序列播放器委托和 Actor 被清理。 */
	UFUNCTION(BlueprintCallable, Category="Generic Level Sequence Subsystem", meta=(WorldContext="WorldContextObject"))
	static LEVELSEQUENCESYSTEM_API void DeconstructLevelSequenceHandle(const UObject* WorldContextObject, UGenericLevelSequenceHandle* InHandle);

	/** 将有效关卡序列句柄加入活动列表，并在注册完成后打开电影场景。 */
	LEVELSEQUENCESYSTEM_API void RegisterLevelSequenceHandle(UGenericLevelSequenceHandle* InHandle);

	/** 关闭并移除活动句柄，使外部释放句柄时不会遗留播放器委托或临时 Actor。 */
	LEVELSEQUENCESYSTEM_API void UnRegisterLevelSequenceHandle(UGenericLevelSequenceHandle* InHandle);

private:
	/** 当前世界中由子系统托管的关卡序列句柄列表，用于集中执行关闭和反注册流程。 */
	TArray<TObjectPtr<UGenericLevelSequenceHandle>> LevelSequenceHandles;
};
