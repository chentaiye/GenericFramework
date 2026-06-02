// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "GenericMediaSubsystem.generated.h"

class UMediaSource;
class UMediaPlayer;
class UGenericMediaHandle;

/** 世界级媒体句柄管理器，负责创建、登记并关闭基于 UMediaPlayer 的电影场景句柄。 */
UCLASS(MinimalAPI)
class UGenericMediaSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	static MEDIASYSTEM_API UGenericMediaSubsystem* Get(const UObject* WorldContextObject);

public:
	/** 校验播放器和媒体源后创建句柄，Register 会立即绑定媒体事件并尝试打开来源。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Subsystem", meta=(WorldContext="WorldContextObject"))
	static MEDIASYSTEM_API UGenericMediaHandle* ConstructMediaHandle(const UObject* WorldContextObject, UMediaPlayer* InMediaPlayer, UMediaSource* InMediaSource, const FMediaPlayerOptions& InOptions);

	/** 从子系统移除句柄并触发 CloseMovieScene，确保媒体播放器委托和缓存对象被清理。 */
	UFUNCTION(BlueprintCallable, Category="Generic Media Subsystem", meta=(WorldContext="WorldContextObject"))
	static MEDIASYSTEM_API void DeconstructMediaHandle(const UObject* WorldContextObject, UGenericMediaHandle* InHandle);

	/** 将有效句柄加入活动列表，避免同一媒体句柄被重复管理。 */
	MEDIASYSTEM_API void RegisterMediaHandle(UGenericMediaHandle* InHandle);

	/** 关闭并移除活动句柄，使外部释放句柄时不会遗留播放状态或动态委托。 */
	MEDIASYSTEM_API void UnRegisterMediaHandle(UGenericMediaHandle* InHandle);

private:
	/** 当前世界中由子系统托管的媒体句柄列表，用来保证析构路径统一走反注册流程。 */
	TArray<TObjectPtr<UGenericMediaHandle>> MediaHandles;
};
