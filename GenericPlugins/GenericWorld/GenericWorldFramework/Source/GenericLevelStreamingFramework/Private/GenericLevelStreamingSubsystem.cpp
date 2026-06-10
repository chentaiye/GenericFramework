// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericLevelStreamingSubsystem.h"

#include "BPFunctions/BPFunctions_LevelStreaming.h"
#include "Engine/Engine.h"
#include "Engine/LevelStreaming.h"
#include "Type/DebugType.h"
#include "Engine/LevelStreamingAlwaysLoaded.h"
#include "Engine/World.h"
#include "GameplayMessageSubsystem.h"
#include "Handle/LoadLevelStreamingHandle.h"
#include "Handle/SetLevelStreamingVisibilityHandle.h"
#include "Handle/UnLoadLevelStreamingHandle.h"
#include "Kismet/GameplayStatics.h"
#include "Misc/PackageName.h"
#include "TimerManager.h"

namespace
{
	void BroadcastLoadLevelStreamingHandleRegisteredMessage(const UObject* WorldContextObject, UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem, ULoadLevelStreamingHandle* Handle)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnLoadLevelStreamingHandleRegisteredMessage Message;
		Message.GenericLevelStreamingSubsystem = GenericLevelStreamingSubsystem;
		Message.Handle = Handle;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_LevelStreaming_OnLoadLevelStreamingHandleRegister, Message);
	}

	void BroadcastUnLoadLevelStreamingHandleRegisteredMessage(const UObject* WorldContextObject, UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem, UUnLoadLevelStreamingHandle* Handle)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnUnLoadLevelStreamingHandleRegisteredMessage Message;
		Message.GenericLevelStreamingSubsystem = GenericLevelStreamingSubsystem;
		Message.Handle = Handle;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_LevelStreaming_OnUnLoadLevelStreamingHandleRegister, Message);
	}

	void BroadcastSetLevelStreamingVisibilityHandleRegisteredMessage(const UObject* WorldContextObject, UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem, USetLevelStreamingVisibilityHandle* Handle)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSetLevelStreamingVisibilityHandleRegisteredMessage Message;
		Message.GenericLevelStreamingSubsystem = GenericLevelStreamingSubsystem;
		Message.Handle = Handle;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_LevelStreaming_OnSetLevelStreamingVisibilityHandleRegister, Message);
	}
}

UGenericLevelStreamingSubsystem* UGenericLevelStreamingSubsystem::Get(const UObject* WorldContextObject)
{
	if (const UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		return World->GetSubsystem<ThisClass>();
	}
	return nullptr;
}

bool UGenericLevelStreamingSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	return Super::ShouldCreateSubsystem(Outer) && !Cast<UWorld>(Outer)->IsPartitionedWorld();
}

ULoadLevelStreamingHandle* UGenericLevelStreamingSubsystem::LoadLevel(const TSoftObjectPtr<UWorld>& Level, const bool bMakeVisibleAfterLoad, const bool bShouldBlockOnLoad, const FOnHandleLevelStreamingFinish& OnFinish)
{
	const FLoadLevelStreamingSetting Setting = FLoadLevelStreamingSetting(Level, bMakeVisibleAfterLoad, bShouldBlockOnLoad);
	return LoadLevelsBySetting(TArray<FLoadLevelStreamingSetting>{Setting}, nullptr, OnFinish);
}

ULoadLevelStreamingHandle* UGenericLevelStreamingSubsystem::LoadLevels(const TArray<TSoftObjectPtr<UWorld>>& Levels, const bool bMakeVisibleAfterLoad, const bool bShouldBlockOnLoad, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	TArray<FLoadLevelStreamingSetting> Settings;

	for (auto& Level : Levels)
	{
		Settings.Add(FLoadLevelStreamingSetting(Level, bMakeVisibleAfterLoad, bShouldBlockOnLoad));
	}

	return LoadLevelsBySetting(Settings, OnOnceFinish, OnFinish);
}

ULoadLevelStreamingHandle* UGenericLevelStreamingSubsystem::LoadLevelsBySetting(const TArray<FLoadLevelStreamingSetting>& InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	/** 没有任何加载设置时直接完成调用方回调，避免创建空句柄占用队列。 */
	if (InSettings.IsEmpty())
	{
		GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Settings Is Empty"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	TArray<FLoadLevelStreamingSetting> ValidSettings;

	/** 只保留当前世界实际管理的流关卡，防止跨世界软引用进入 UE latent 加载流程。 */
	for (auto Setting : InSettings)
	{
		if (!Setting.IsValid())
		{
			GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Setting Is InValid"))
			continue;
		}

		if (!IsCurrentWorldContainLevel(Setting.Level))
		{
			GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Current World Is Not Contain The Level"))
			continue;
		}

		ValidSettings.Add(Setting);
	}

	if (ValidSettings.IsEmpty())
	{
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	ULoadLevelStreamingHandle* LoadLevelStreamingHandle = NewObject<ULoadLevelStreamingHandle>(this);
	LoadLevelStreamingHandle->GetHandleOnceFinishEvent().AddUObject(this, &UGenericLevelStreamingSubsystem::OnHandleLevelOnceFinish);
	LoadLevelStreamingHandle->GetHandleFinishEvent().AddUObject(this, &UGenericLevelStreamingSubsystem::OnHandleLevelFinish);
	LoadLevelStreamingHandle->Initialize(ValidSettings, OnOnceFinish, OnFinish);

	TargetLevelStreamingHandles.Add(LoadLevelStreamingHandle);

	GenericLOG(GenericLogLevelStreaming, Log, TEXT("Broadcast gameplay message OnLoadLevelStreamingHandleRegister"))
	BroadcastLoadLevelStreamingHandleRegisteredMessage(this, this, LoadLevelStreamingHandle);

	ExecuteHandleNextTick();

	return LoadLevelStreamingHandle;
}

UUnLoadLevelStreamingHandle* UGenericLevelStreamingSubsystem::UnloadLevel(const TSoftObjectPtr<UWorld>& Level, const bool bShouldBlockOnUnload, const FOnHandleLevelStreamingFinish& OnFinish)
{
	const FUnloadLevelStreamingSetting Setting = FUnloadLevelStreamingSetting(Level, bShouldBlockOnUnload);
	return UnloadLevelsBySetting(TArray<FUnloadLevelStreamingSetting>{Setting}, nullptr, OnFinish);
}

UUnLoadLevelStreamingHandle* UGenericLevelStreamingSubsystem::UnloadLevels(const TArray<TSoftObjectPtr<UWorld>>& Levels, const bool bShouldBlockOnUnload, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	TArray<FUnloadLevelStreamingSetting> Settings;

	for (auto& Level : Levels)
	{
		Settings.Add(FUnloadLevelStreamingSetting(Level, bShouldBlockOnUnload));
	}

	return UnloadLevelsBySetting(Settings, OnOnceFinish, OnFinish);
}

UUnLoadLevelStreamingHandle* UGenericLevelStreamingSubsystem::UnloadLevelsBySetting(const TArray<FUnloadLevelStreamingSetting>& InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	/** 没有卸载目标时直接结束，保持批量 API 的完成回调语义。 */
	if (InSettings.IsEmpty())
	{
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	/** 卸载也只允许作用于当前 Persistent World 的流关卡，避免误卸载同名外部地图。 */
	TArray<FUnloadLevelStreamingSetting> ValidSettings;
	for (auto Setting : InSettings)
	{
		if (!Setting.IsValid())
		{
			GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Setting Is InValid"))
			continue;
		}

		if (!IsCurrentWorldContainLevel(Setting.Level))
		{
			GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Current World Is Not Contain The Level"))
			continue;
		}

		ValidSettings.Add(Setting);
	}

	if (ValidSettings.IsEmpty())
	{
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	UUnLoadLevelStreamingHandle* UnLoadLevelStreamingHandle = NewObject<UUnLoadLevelStreamingHandle>(this);
	UnLoadLevelStreamingHandle->GetHandleOnceFinishEvent().AddUObject(this, &UGenericLevelStreamingSubsystem::OnHandleLevelOnceFinish);
	UnLoadLevelStreamingHandle->GetHandleFinishEvent().AddUObject(this, &UGenericLevelStreamingSubsystem::OnHandleLevelFinish);
	UnLoadLevelStreamingHandle->Initialize(ValidSettings, OnOnceFinish, OnFinish);

	TargetLevelStreamingHandles.Add(UnLoadLevelStreamingHandle);

	GenericLOG(GenericLogLevelStreaming, Log, TEXT("Broadcast gameplay message OnUnLoadLevelStreamingHandleRegister"))
	BroadcastUnLoadLevelStreamingHandleRegisteredMessage(this, this, UnLoadLevelStreamingHandle);

	ExecuteHandleNextTick();

	return UnLoadLevelStreamingHandle;
}

USetLevelStreamingVisibilityHandle* UGenericLevelStreamingSubsystem::SetLevelVisibility(const TSoftObjectPtr<UWorld>& Level, const bool bVisible, const FOnHandleLevelStreamingFinish& OnFinish)
{
	const FSetLevelStreamingVisibilitySetting Setting = FSetLevelStreamingVisibilitySetting(Level, bVisible);
	return SetLevelsVisibilityBySetting(TArray<FSetLevelStreamingVisibilitySetting>{Setting}, nullptr, OnFinish);
}

USetLevelStreamingVisibilityHandle* UGenericLevelStreamingSubsystem::SetLevelsVisibility(const TArray<TSoftObjectPtr<UWorld>>& Levels, const bool bVisible, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	TArray<FSetLevelStreamingVisibilitySetting> Settings;

	for (auto& Level : Levels)
	{
		Settings.Add(FSetLevelStreamingVisibilitySetting(Level, bVisible));
	}

	return SetLevelsVisibilityBySetting(Settings, OnOnceFinish, OnFinish);
}

USetLevelStreamingVisibilityHandle* UGenericLevelStreamingSubsystem::SetLevelsVisibilityBySetting(const TArray<FSetLevelStreamingVisibilitySetting>& InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	/** 没有可见性目标时直接完成，避免后续创建无效句柄。 */
	if (InSettings.IsEmpty())
	{
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	TArray<FSetLevelStreamingVisibilitySetting> ValidSettings;

	/** 可见性切换必须绑定当前世界已有的流关卡；真正加载缺失关卡由可见性句柄内部处理。 */
	for (auto Setting : InSettings)
	{
		if (!Setting.IsValid())
		{
			GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Setting Is InValid"))
			continue;
		}

		if (Setting.Level.IsNull())
		{
			GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Level Is InValid"))
			continue;
		}

		if (!IsCurrentWorldContainLevel(Setting.Level))
		{
			GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Current World Is Not Contain The Level"))
			continue;
		}

		ValidSettings.Add(Setting);
	}

	if (ValidSettings.IsEmpty())
	{
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	USetLevelStreamingVisibilityHandle* SetLevelStreamingVisibilityHandle = NewObject<USetLevelStreamingVisibilityHandle>(this);
	SetLevelStreamingVisibilityHandle->GetHandleOnceFinishEvent().AddUObject(this, &UGenericLevelStreamingSubsystem::OnHandleLevelOnceFinish);
	SetLevelStreamingVisibilityHandle->GetHandleFinishEvent().AddUObject(this, &UGenericLevelStreamingSubsystem::OnHandleLevelFinish);
	SetLevelStreamingVisibilityHandle->Initialize(ValidSettings, OnOnceFinish, OnFinish);

	TargetLevelStreamingHandles.Add(SetLevelStreamingVisibilityHandle);

	GenericLOG(GenericLogLevelStreaming, Log, TEXT("Broadcast gameplay message OnSetLevelStreamingVisibilityHandleRegister"))
	BroadcastSetLevelStreamingVisibilityHandleRegisteredMessage(this, this, SetLevelStreamingVisibilityHandle);
	ExecuteHandleNextTick();
	return SetLevelStreamingVisibilityHandle;
}

TArray<TSoftObjectPtr<UWorld>> UGenericLevelStreamingSubsystem::GetCurrentWorldLevelStreamingList() const
{
	TArray<TSoftObjectPtr<UWorld>> WorldToLoad;
	for (const auto StreamingLevel : GetWorld()->GetStreamingLevels())
	{
		/** 已加载或已可见的关卡不再加入预加载队列，避免重复触发 LoadStreamLevel。 */
		if (StreamingLevel->IsLevelVisible() || StreamingLevel->IsLevelLoaded())
		{
			continue;
		}

		/** AlwaysLoaded 由引擎随 Persistent World 管理，不应被手动预加载接口接管。 */
		if (Cast<ULevelStreamingAlwaysLoaded>(StreamingLevel))
		{
			continue;
		}

		WorldToLoad.Add(StreamingLevel->GetWorldAsset());
	}
	return WorldToLoad;
}

ULoadLevelStreamingHandle* UGenericLevelStreamingSubsystem::LoadCurrentWorldLevelStreaming(const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	/** 复用列表查询逻辑，确保一键预加载和 WorldSettings 启动预加载使用同一套过滤规则。 */
	const TArray<TSoftObjectPtr<UWorld>>& WorldToLoad = GetCurrentWorldLevelStreamingList();

	if (WorldToLoad.IsEmpty())
	{
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	return LoadLevels(WorldToLoad, false, false, OnOnceFinish, OnFinish);
}

UUnLoadLevelStreamingHandle* UGenericLevelStreamingSubsystem::UnLoadCurrentWorldLevelStreaming(const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	/** 当前世界批量卸载只处理已经加载的手动流关卡，避免把引擎常驻关卡从世界中移除。 */
	TArray<TSoftObjectPtr<UWorld>> WorldToUnLoad;
	for (const auto StreamingLevel : GetWorld()->GetStreamingLevels())
	{
		/** 未加载关卡已经处于目标状态，跳过后仍保持整批完成回调语义。 */
		if (!StreamingLevel->IsLevelLoaded())
		{
			continue;
		}

		/** AlwaysLoaded 关卡不参与手动卸载，否则会破坏 Persistent World 的常驻内容。 */
		if (Cast<ULevelStreamingAlwaysLoaded>(StreamingLevel))
		{
			continue;
		}

		WorldToUnLoad.Add(StreamingLevel->GetWorldAsset());
	}

	if (WorldToUnLoad.IsEmpty())
	{
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	return UnloadLevels(WorldToUnLoad, false, OnOnceFinish, OnFinish);
}

ULevelStreaming* UGenericLevelStreamingSubsystem::GetLevelStreaming(const TSoftObjectPtr<UWorld>& Level) const
{
	if (Level.IsNull())
	{
		GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Level Is InValid"))
		return nullptr;
	}

	const FString PackageName = FPackageName::ObjectPathToPackageName(Level.ToString());
	if (PackageName.IsEmpty())
	{
		GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Level Package Is Not Found"))
		return nullptr;
	}

	ULevelStreaming* LevelStreaming = UGameplayStatics::GetStreamingLevel(this, FName(*PackageName));
	if (!IsValid(LevelStreaming))
	{
		GenericLOG(GenericLogLevelStreaming, Warning, TEXT("Level Streaming Is Not Found"));
		return nullptr;
	}

	return LevelStreaming;
}

bool UGenericLevelStreamingSubsystem::IsCurrentWorldContainLevel(const TSoftObjectPtr<UWorld>& Level) const
{
	for (const auto StreamingLevel : GetWorld()->GetStreamingLevels())
	{
		FString PackageName;
		Level.GetLongPackageName().Split("/", &PackageName, nullptr, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		PackageName += ("/" + Level.GetAssetName());

		if (StreamingLevel->GetWorldAssetPackageFName() == PackageName || StreamingLevel->PackageNameToLoad == PackageName)
		{
			return true;
		}
	}
	return false;
}

void UGenericLevelStreamingSubsystem::ExecuteHandleNextTick()
{
	if (NextTickTimerHandle.IsValid())
	{
		NextTickTimerHandle.Invalidate();
	}

	NextTickTimerHandle = GetWorld()->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateUObject(this, &UGenericLevelStreamingSubsystem::ExecuteHandles));
}

void UGenericLevelStreamingSubsystem::ExecuteHandles()
{
	TArray<FLevelStreamConflict> LevelStreamConflicts;
	for (auto& LevelStream : GetWorld()->GetStreamingLevels())
	{
		FLevelStreamConflict LevelStreamConflict;
		LevelStreamConflict.Level = LevelStream->GetWorldAsset();
		LevelStreamConflict.bIsLevelLoaded = LevelStream->IsLevelLoaded();
		LevelStreamConflict.bIsLevelVisible = LevelStream->IsLevelVisible();
		LevelStreamConflicts.Add(LevelStreamConflict);
	}

	/** 将本帧待执行句柄按目标关卡归入冲突桶，后续只保留每个关卡最后提交的操作。 */
	for (auto& TargetLevelStreamingHandle : TargetLevelStreamingHandles)
	{
		for (auto& Level : TargetLevelStreamingHandle->GetLevels())
		{
			FLevelStreamConflict* Found = LevelStreamConflicts.FindByKey(Level);
			Found->ModifyHandles.AddUnique(TargetLevelStreamingHandle);
		}
	}

	/** 同一关卡在同一帧收到多次修改时，保留 TargetLevelStreamingHandles 中顺序最后的请求。 */
	for (auto& LevelStreamConflict : LevelStreamConflicts)
	{
		/** 单个句柄触达该关卡时无需裁剪，多个句柄才存在加载/卸载/可见性互相覆盖。 */
		if (LevelStreamConflict.ModifyHandles.Num() > 1)
		{
			/** 删除较早句柄中的同关卡项，避免同一轮执行里先加载又卸载或先隐藏又显示。 */
			int32 ModifyHandleIndex = INDEX_NONE;
			for (auto& ModifyHandle : LevelStreamConflict.ModifyHandles)
			{
				if (ModifyHandleIndex == INDEX_NONE)
				{
					ModifyHandleIndex = TargetLevelStreamingHandles.Find(ModifyHandle);
				}
				else
				{
					int32 CurrentHandleIndex = TargetLevelStreamingHandles.Find(ModifyHandle);
					if (CurrentHandleIndex > ModifyHandleIndex)
					{
						TargetLevelStreamingHandles[ModifyHandleIndex]->RemoveLevel(LevelStreamConflict.Level);
						ModifyHandleIndex = CurrentHandleIndex;
					}
					else
					{
						TargetLevelStreamingHandles[CurrentHandleIndex]->RemoveLevel(LevelStreamConflict.Level);
					}
				}
			}
		}
	}

	LevelStreamingHandles.Append(TargetLevelStreamingHandles);

	TArray<ULevelStreamingHandle*> TargetHandles = TargetLevelStreamingHandles;
	for (auto& TargetHandle : TargetHandles)
	{
		TargetHandle->Startup();
	}

	TargetLevelStreamingHandles.Reset();
}

void UGenericLevelStreamingSubsystem::OnHandleLevelOnceFinish(ULevelStreamingHandle* InHandle, TSoftObjectPtr<UWorld> InLevel)
{
}

void UGenericLevelStreamingSubsystem::OnHandleLevelFinish(ULevelStreamingHandle* InHandle)
{
	InHandle->GetHandleOnceFinishEvent().RemoveAll(this);
	InHandle->GetHandleFinishEvent().RemoveAll(this);
	LevelStreamingHandles.Remove(InHandle);
}
