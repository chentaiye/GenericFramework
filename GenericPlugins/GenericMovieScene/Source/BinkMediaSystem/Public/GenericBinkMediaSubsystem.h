// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystem/GenericWorldSubsystem.h"
#include "GenericBinkMediaSubsystem.generated.h"

class UBinkMediaPlayer;
class UBinkMediaTexture;
class UGenericBinkMediaHandle;

/** 世界级 Bink 媒体句柄管理器，负责创建、登记并关闭基于 UBinkMediaPlayer 的电影场景句柄。 */
UCLASS(MinimalAPI)
class UGenericBinkMediaSubsystem : public UGenericWorldSubsystem
{
	GENERATED_BODY()

public:
	static BINKMEDIASYSTEM_API UGenericBinkMediaSubsystem* Get(const UObject* WorldContextObject);

public:
	/** 校验 Bink 播放器后创建句柄，Register 会绑定纹理、注册事件并尝试打开 Bink URL。 */
	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Subsystem", meta=(WorldContext="WorldContextObject"))
	static BINKMEDIASYSTEM_API UGenericBinkMediaHandle* ConstructBinkMediaHandle(const UObject* WorldContextObject, UBinkMediaPlayer* InBinkMediaPlayer, UBinkMediaTexture* InBinkMediaTexture = nullptr);

	/** 从子系统移除句柄并触发 CloseMovieScene，确保 Bink 播放器和纹理引用被解除。 */
	UFUNCTION(BlueprintCallable, Category="Generic Bink Media Subsystem", meta=(WorldContext="WorldContextObject"))
	static BINKMEDIASYSTEM_API void DeconstructBinkMediaHandle(const UObject* WorldContextObject, UGenericBinkMediaHandle* InHandle);

	/** 将有效 Bink 句柄加入活动列表，防止同一句柄被重复托管。 */
	BINKMEDIASYSTEM_API void RegisterBinkMediaHandle(UGenericBinkMediaHandle* InHandle);

	/** 关闭并移除 Bink 句柄，使外部释放句柄时统一走事件解绑和纹理清理流程。 */
	BINKMEDIASYSTEM_API void UnRegisterBinkMediaHandle(UGenericBinkMediaHandle* InHandle);

private:
	/** 当前世界中由子系统托管的 Bink 句柄列表，用来集中管理关闭和反注册路径。 */
	TArray<TObjectPtr<UGenericBinkMediaHandle>> BinkMediaHandles;
};
