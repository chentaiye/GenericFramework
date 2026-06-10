// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericWorldPartitionSubsystem.h"

#include "Algo/AllOf.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameplayMessageSubsystem.h"
#include "Handle/LoadWorldPartitionHandle.h"
#include "Handle/SetWorldPartitionVisibilityHandle.h"
#include "Handle/UnLoadWorldPartitionHandle.h"
#include "TimerManager.h"
#include "Type/DebugType.h"
#include "WorldPartition/WorldPartition.h"
#include "WorldPartition/DataLayer/DataLayerAsset.h"
#include "WorldPartition/DataLayer/DataLayerManager.h"
#include "WorldPartition/WorldPartitionRuntimeHash.h"
#include "WorldPartition/WorldPartitionSubsystem.h"

namespace
{
	void BroadcastLoadWorldPartitionHandleRegisteredMessage(const UObject* WorldContextObject, UGenericWorldPartitionSubsystem* GenericWorldPartitionSubsystem, ULoadWorldPartitionHandle* Handle)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnLoadWorldPartitionHandleRegisteredMessage Message;
		Message.GenericWorldPartitionSubsystem = GenericWorldPartitionSubsystem;
		Message.Handle = Handle;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_WorldPartition_OnLoadWorldPartitionHandleRegister, Message);
	}

	void BroadcastUnLoadWorldPartitionHandleRegisteredMessage(const UObject* WorldContextObject, UGenericWorldPartitionSubsystem* GenericWorldPartitionSubsystem, UUnLoadWorldPartitionHandle* Handle)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnUnLoadWorldPartitionHandleRegisteredMessage Message;
		Message.GenericWorldPartitionSubsystem = GenericWorldPartitionSubsystem;
		Message.Handle = Handle;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_WorldPartition_OnUnLoadWorldPartitionHandleRegister, Message);
	}

	void BroadcastSetWorldPartitionVisibilityHandleRegisteredMessage(const UObject* WorldContextObject, UGenericWorldPartitionSubsystem* GenericWorldPartitionSubsystem, USetWorldPartitionVisibilityHandle* Handle)
	{
		if (!UGameplayMessageSubsystem::HasInstance(WorldContextObject))
		{
			return;
		}

		FOnSetWorldPartitionVisibilityHandleRegisteredMessage Message;
		Message.GenericWorldPartitionSubsystem = GenericWorldPartitionSubsystem;
		Message.Handle = Handle;
		UGameplayMessageSubsystem::Get(WorldContextObject).BroadcastMessage(TAG_GameplayMessage_Channel_WorldPartition_OnSetWorldPartitionVisibilityHandleRegister, Message);
	}
}

UGenericWorldPartitionSubsystem* UGenericWorldPartitionSubsystem::Get(const UObject* WorldContextObject)
{
	if (!::IsValid(WorldContextObject) || !GEngine)
	{
		return nullptr;
	}

	if (const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull))
	{
		return World->GetSubsystem<ThisClass>();
	}

	return nullptr;
}

bool UGenericWorldPartitionSubsystem::ShouldCreateSubsystem(UObject* Outer) const
{
	const UWorld* World = Cast<UWorld>(Outer);
	return Super::ShouldCreateSubsystem(Outer) && ::IsValid(World) && World->IsPartitionedWorld();
}

ULoadWorldPartitionHandle* UGenericWorldPartitionSubsystem::LoadCell(UWorldPartitionRuntimeCell* Cell, const FOnHandleWorldPartitionFinish& OnFinish)
{
	return LoadCellsBySetting(TArray<FLoadWorldPartitionSetting>{FLoadWorldPartitionSetting(Cell)}, FOnHandleWorldPartitionOnceFinish(), OnFinish);
}

ULoadWorldPartitionHandle* UGenericWorldPartitionSubsystem::LoadCells(const TArray<UWorldPartitionRuntimeCell*>& Cells, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	TArray<FLoadWorldPartitionSetting> Settings;
	Settings.Reserve(Cells.Num());

	for (UWorldPartitionRuntimeCell* Cell : Cells)
	{
		Settings.Add(FLoadWorldPartitionSetting(Cell));
	}

	return LoadCellsBySetting(Settings, OnOnceFinish, OnFinish);
}

ULoadWorldPartitionHandle* UGenericWorldPartitionSubsystem::LoadCellsBySetting(const TArray<FLoadWorldPartitionSetting>& InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	if (InSettings.IsEmpty())
	{
		GenericLOG(GenericLogWorldPartition, Warning, TEXT("Load settings are empty"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	/** 入队前先过滤空 Cell、跨世界 Cell 和重复 Cell，避免句柄在执行阶段处理无效目标。 */
	TArray<FLoadWorldPartitionSetting> ValidSettings;
	for (const FLoadWorldPartitionSetting& Setting : InSettings)
	{
		if (!Setting.IsValid())
		{
			GenericLOG(GenericLogWorldPartition, Warning, TEXT("Load setting is invalid"))
			continue;
		}

		if (!IsCurrentWorldContainCell(Setting.Cell))
		{
			GenericLOG(GenericLogWorldPartition, Warning, TEXT("Current world does not contain target cell"))
			continue;
		}

		if (!ValidSettings.Contains(Setting))
		{
			ValidSettings.Add(Setting);
		}
	}

	if (ValidSettings.IsEmpty())
	{
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	/** 新建句柄后先放入待执行队列，下一帧会统一合并同一 Cell 的冲突请求。 */
	ULoadWorldPartitionHandle* Handle = NewObject<ULoadWorldPartitionHandle>(this);
	Handle->GetHandleOnceFinishEvent().AddUObject(this, &UGenericWorldPartitionSubsystem::OnHandleCellOnceFinish);
	Handle->GetHandleFinishEvent().AddUObject(this, &UGenericWorldPartitionSubsystem::OnHandleCellFinish);
	Handle->Initialize(ValidSettings, OnOnceFinish, OnFinish);

	TargetWorldPartitionHandles.Add(Handle);

	GenericLOG(GenericLogWorldPartition, Log, TEXT("Broadcast gameplay message OnLoadWorldPartitionHandleRegister"))
	BroadcastLoadWorldPartitionHandleRegisteredMessage(this, this, Handle);
	ExecuteHandleNextTick();

	return Handle;
}

UUnLoadWorldPartitionHandle* UGenericWorldPartitionSubsystem::UnloadCell(UWorldPartitionRuntimeCell* Cell, const FOnHandleWorldPartitionFinish& OnFinish)
{
	return UnloadCellsBySetting(TArray<FUnloadWorldPartitionSetting>{FUnloadWorldPartitionSetting(Cell)}, FOnHandleWorldPartitionOnceFinish(), OnFinish);
}

UUnLoadWorldPartitionHandle* UGenericWorldPartitionSubsystem::UnloadCells(const TArray<UWorldPartitionRuntimeCell*>& Cells, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	TArray<FUnloadWorldPartitionSetting> Settings;
	Settings.Reserve(Cells.Num());

	for (UWorldPartitionRuntimeCell* Cell : Cells)
	{
		Settings.Add(FUnloadWorldPartitionSetting(Cell));
	}

	return UnloadCellsBySetting(Settings, OnOnceFinish, OnFinish);
}

UUnLoadWorldPartitionHandle* UGenericWorldPartitionSubsystem::UnloadCellsBySetting(const TArray<FUnloadWorldPartitionSetting>& InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	if (InSettings.IsEmpty())
	{
		GenericLOG(GenericLogWorldPartition, Warning, TEXT("Unload settings are empty"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	/** 卸载请求需要额外排除 AlwaysLoaded 或 CanUnload 为 false 的 Cell，避免提交后永远等不到 Unloaded。 */
	TArray<FUnloadWorldPartitionSetting> ValidSettings;
	for (const FUnloadWorldPartitionSetting& Setting : InSettings)
	{
		if (!Setting.IsValid())
		{
			GenericLOG(GenericLogWorldPartition, Warning, TEXT("Unload setting is invalid"))
			continue;
		}

		if (!IsCurrentWorldContainCell(Setting.Cell))
		{
			GenericLOG(GenericLogWorldPartition, Warning, TEXT("Current world does not contain target cell"))
			continue;
		}

		if (Setting.Cell->IsAlwaysLoaded() || !Setting.Cell->CanUnload())
		{
			GenericLOG(GenericLogWorldPartition, Warning, TEXT("Target cell cannot be unloaded"))
			continue;
		}

		if (!ValidSettings.Contains(Setting))
		{
			ValidSettings.Add(Setting);
		}
	}

	if (ValidSettings.IsEmpty())
	{
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	/** 卸载句柄同样进入下一帧调度，便于和同帧加载/可见性请求按最后提交者合并。 */
	UUnLoadWorldPartitionHandle* Handle = NewObject<UUnLoadWorldPartitionHandle>(this);
	Handle->GetHandleOnceFinishEvent().AddUObject(this, &UGenericWorldPartitionSubsystem::OnHandleCellOnceFinish);
	Handle->GetHandleFinishEvent().AddUObject(this, &UGenericWorldPartitionSubsystem::OnHandleCellFinish);
	Handle->Initialize(ValidSettings, OnOnceFinish, OnFinish);

	TargetWorldPartitionHandles.Add(Handle);

	GenericLOG(GenericLogWorldPartition, Log, TEXT("Broadcast gameplay message OnUnLoadWorldPartitionHandleRegister"))
	BroadcastUnLoadWorldPartitionHandleRegisteredMessage(this, this, Handle);
	ExecuteHandleNextTick();

	return Handle;
}

USetWorldPartitionVisibilityHandle* UGenericWorldPartitionSubsystem::SetCellVisibility(UWorldPartitionRuntimeCell* Cell, bool bVisible, const FOnHandleWorldPartitionFinish& OnFinish)
{
	return SetCellsVisibilityBySetting(TArray<FSetWorldPartitionVisibilitySetting>{FSetWorldPartitionVisibilitySetting(Cell, bVisible)}, FOnHandleWorldPartitionOnceFinish(), OnFinish);
}

USetWorldPartitionVisibilityHandle* UGenericWorldPartitionSubsystem::SetCellsVisibility(const TArray<UWorldPartitionRuntimeCell*>& Cells, bool bVisible, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	TArray<FSetWorldPartitionVisibilitySetting> Settings;
	Settings.Reserve(Cells.Num());

	for (UWorldPartitionRuntimeCell* Cell : Cells)
	{
		Settings.Add(FSetWorldPartitionVisibilitySetting(Cell, bVisible));
	}

	return SetCellsVisibilityBySetting(Settings, OnOnceFinish, OnFinish);
}

USetWorldPartitionVisibilityHandle* UGenericWorldPartitionSubsystem::SetCellsVisibilityBySetting(const TArray<FSetWorldPartitionVisibilitySetting>& InSettings, const FOnHandleWorldPartitionOnceFinish& OnOnceFinish, const FOnHandleWorldPartitionFinish& OnFinish)
{
	if (InSettings.IsEmpty())
	{
		GenericLOG(GenericLogWorldPartition, Warning, TEXT("Visibility settings are empty"))
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	/** 可见性请求只处理当前世界 Cell，并阻止隐藏 AlwaysLoaded Cell 这类不会退出可见状态的目标。 */
	TArray<FSetWorldPartitionVisibilitySetting> ValidSettings;
	for (const FSetWorldPartitionVisibilitySetting& Setting : InSettings)
	{
		if (!Setting.IsValid())
		{
			GenericLOG(GenericLogWorldPartition, Warning, TEXT("Visibility setting is invalid"))
			continue;
		}

		if (!IsCurrentWorldContainCell(Setting.Cell))
		{
			GenericLOG(GenericLogWorldPartition, Warning, TEXT("Current world does not contain target cell"))
			continue;
		}

		if (!Setting.bVisible && Setting.Cell->IsAlwaysLoaded())
		{
			GenericLOG(GenericLogWorldPartition, Warning, TEXT("Always loaded cell cannot be hidden"))
			continue;
		}

		if (!ValidSettings.Contains(Setting))
		{
			ValidSettings.Add(Setting);
		}
	}

	if (ValidSettings.IsEmpty())
	{
		OnFinish.ExecuteIfBound();
		return nullptr;
	}

	/** 可见性句柄与加载/卸载句柄共用冲突合并队列，保证同一 Cell 同帧只有最新操作生效。 */
	USetWorldPartitionVisibilityHandle* Handle = NewObject<USetWorldPartitionVisibilityHandle>(this);
	Handle->GetHandleOnceFinishEvent().AddUObject(this, &UGenericWorldPartitionSubsystem::OnHandleCellOnceFinish);
	Handle->GetHandleFinishEvent().AddUObject(this, &UGenericWorldPartitionSubsystem::OnHandleCellFinish);
	Handle->Initialize(ValidSettings, OnOnceFinish, OnFinish);

	TargetWorldPartitionHandles.Add(Handle);

	GenericLOG(GenericLogWorldPartition, Log, TEXT("Broadcast gameplay message OnSetWorldPartitionVisibilityHandleRegister"))
	BroadcastSetWorldPartitionVisibilityHandleRegisteredMessage(this, this, Handle);
	ExecuteHandleNextTick();

	return Handle;
}

UWorldPartition* UGenericWorldPartitionSubsystem::GetCurrentWorldPartition() const
{
	return GetWorld() ? GetWorld()->GetWorldPartition() : nullptr;
}

TArray<UWorldPartitionRuntimeCell*> UGenericWorldPartitionSubsystem::GetCurrentWorldPartitionRuntimeCells() const
{
	TArray<UWorldPartitionRuntimeCell*> Cells;

	/** RuntimeHash 是 Streaming Cell 的权威来源；这里仅枚举有效 Cell，不触发任何加载。 */
	if (const UWorldPartition* WorldPartition = GetCurrentWorldPartition())
	{
		if (const UWorldPartitionRuntimeHash* RuntimeHash = WorldPartition->RuntimeHash)
		{
			RuntimeHash->ForEachStreamingCells([&Cells](const UWorldPartitionRuntimeCell* Cell)
			{
				if (::IsValid(Cell))
				{
					Cells.Add(const_cast<UWorldPartitionRuntimeCell*>(Cell));
				}

				return true;
			});
		}
	}

	Cells.Sort([](const UWorldPartitionRuntimeCell& A, const UWorldPartitionRuntimeCell& B)
	{
		return A.GetFName().LexicalLess(B.GetFName());
	});

	return Cells;
}

EWorldPartitionRuntimeCellState UGenericWorldPartitionSubsystem::GetCellState(UWorldPartitionRuntimeCell* Cell) const
{
	return ::IsValid(Cell) ? Cell->GetCurrentState() : EWorldPartitionRuntimeCellState::Unloaded;
}

bool UGenericWorldPartitionSubsystem::IsCellLoaded(UWorldPartitionRuntimeCell* Cell) const
{
	return GetCellState(Cell) >= EWorldPartitionRuntimeCellState::Loaded;
}

bool UGenericWorldPartitionSubsystem::IsCellVisible(UWorldPartitionRuntimeCell* Cell) const
{
	return GetCellState(Cell) == EWorldPartitionRuntimeCellState::Activated;
}

bool UGenericWorldPartitionSubsystem::IsCurrentWorldContainCell(UWorldPartitionRuntimeCell* Cell) const
{
	if (!::IsValid(Cell))
	{
		return false;
	}

	bool bContain = false;

	/** 通过 RuntimeHash 做归属校验，避免外部缓存的 Cell 被错误提交到当前世界。 */
	if (const UWorldPartition* WorldPartition = GetCurrentWorldPartition())
	{
		if (const UWorldPartitionRuntimeHash* RuntimeHash = WorldPartition->RuntimeHash)
		{
			RuntimeHash->ForEachStreamingCells([Cell, &bContain](const UWorldPartitionRuntimeCell* CurrentCell)
			{
				bContain = CurrentCell == Cell;
				return !bContain;
			});
		}
	}

	return bContain;
}

bool UGenericWorldPartitionSubsystem::IsStreamingCompleted() const
{
	if (UWorldPartitionSubsystem* NativeSubsystem = const_cast<UGenericWorldPartitionSubsystem*>(this)->GetNativeWorldPartitionSubsystem())
	{
		return NativeSubsystem->IsAllStreamingCompleted();
	}

	return true;
}

UDataLayerManager* UGenericWorldPartitionSubsystem::GetDataLayerManager() const
{
	return UDataLayerManager::GetDataLayerManager(GetWorld());
}

TArray<UDataLayerInstance*> UGenericWorldPartitionSubsystem::GetDataLayerInstances() const
{
	TArray<UDataLayerInstance*> Result;

	if (const UDataLayerManager* DataLayerManager = GetDataLayerManager())
	{
		DataLayerManager->ForEachDataLayerInstance([&Result](UDataLayerInstance* DataLayerInstance)
		{
			if (::IsValid(DataLayerInstance))
			{
				Result.Add(DataLayerInstance);
			}

			return true;
		});
	}

	return Result;
}

UDataLayerInstance* UGenericWorldPartitionSubsystem::GetDataLayerInstanceFromAsset(const UDataLayerAsset* DataLayerAsset) const
{
	if (const UDataLayerManager* DataLayerManager = GetDataLayerManager())
	{
		return const_cast<UDataLayerInstance*>(DataLayerManager->GetDataLayerInstanceFromAsset(DataLayerAsset));
	}

	return nullptr;
}

UDataLayerInstance* UGenericWorldPartitionSubsystem::GetDataLayerInstanceFromName(FName DataLayerInstanceName) const
{
	if (const UDataLayerManager* DataLayerManager = GetDataLayerManager())
	{
		return const_cast<UDataLayerInstance*>(DataLayerManager->GetDataLayerInstanceFromName(DataLayerInstanceName));
	}

	return nullptr;
}

bool UGenericWorldPartitionSubsystem::SetDataLayerInstanceRuntimeState(const UDataLayerInstance* DataLayerInstance, EDataLayerRuntimeState State, bool bIsRecursive) const
{
	if (UDataLayerManager* DataLayerManager = GetDataLayerManager())
	{
		return DataLayerManager->SetDataLayerInstanceRuntimeState(DataLayerInstance, State, bIsRecursive);
	}

	return false;
}

bool UGenericWorldPartitionSubsystem::SetDataLayerRuntimeState(const UDataLayerAsset* DataLayerAsset, EDataLayerRuntimeState State, bool bIsRecursive) const
{
	if (UDataLayerManager* DataLayerManager = GetDataLayerManager())
	{
		return DataLayerManager->SetDataLayerRuntimeState(DataLayerAsset, State, bIsRecursive);
	}

	return false;
}

bool UGenericWorldPartitionSubsystem::SetDataLayerRuntimeStateByName(FName DataLayerInstanceName, EDataLayerRuntimeState State, bool bIsRecursive) const
{
	if (const UDataLayerInstance* DataLayerInstance = GetDataLayerInstanceFromName(DataLayerInstanceName))
	{
		return SetDataLayerInstanceRuntimeState(DataLayerInstance, State, bIsRecursive);
	}

	return false;
}

EDataLayerRuntimeState UGenericWorldPartitionSubsystem::GetDataLayerInstanceRuntimeState(const UDataLayerInstance* DataLayerInstance) const
{
	if (const UDataLayerManager* DataLayerManager = GetDataLayerManager())
	{
		return DataLayerManager->GetDataLayerInstanceRuntimeState(DataLayerInstance);
	}

	return EDataLayerRuntimeState::Unloaded;
}

EDataLayerRuntimeState UGenericWorldPartitionSubsystem::GetDataLayerInstanceEffectiveRuntimeState(const UDataLayerInstance* DataLayerInstance) const
{
	if (const UDataLayerManager* DataLayerManager = GetDataLayerManager())
	{
		return DataLayerManager->GetDataLayerInstanceEffectiveRuntimeState(DataLayerInstance);
	}

	return EDataLayerRuntimeState::Unloaded;
}

EDataLayerRuntimeState UGenericWorldPartitionSubsystem::GetDataLayerRuntimeStateByAsset(const UDataLayerAsset* DataLayerAsset) const
{
	return GetDataLayerInstanceRuntimeState(GetDataLayerInstanceFromAsset(DataLayerAsset));
}

EDataLayerRuntimeState UGenericWorldPartitionSubsystem::GetDataLayerEffectiveRuntimeStateByAsset(const UDataLayerAsset* DataLayerAsset) const
{
	return GetDataLayerInstanceEffectiveRuntimeState(GetDataLayerInstanceFromAsset(DataLayerAsset));
}

EDataLayerRuntimeState UGenericWorldPartitionSubsystem::GetDataLayerRuntimeStateByName(FName DataLayerInstanceName) const
{
	return GetDataLayerInstanceRuntimeState(GetDataLayerInstanceFromName(DataLayerInstanceName));
}

EDataLayerRuntimeState UGenericWorldPartitionSubsystem::GetDataLayerEffectiveRuntimeStateByName(FName DataLayerInstanceName) const
{
	return GetDataLayerInstanceEffectiveRuntimeState(GetDataLayerInstanceFromName(DataLayerInstanceName));
}

TArray<FName> UGenericWorldPartitionSubsystem::GetEffectiveLoadedDataLayerNames() const
{
	TArray<FName> Result;

	if (const UDataLayerManager* DataLayerManager = GetDataLayerManager())
	{
		Result = DataLayerManager->GetEffectiveLoadedDataLayerNames().Array();
	}

	return Result;
}

TArray<FName> UGenericWorldPartitionSubsystem::GetEffectiveActiveDataLayerNames() const
{
	TArray<FName> Result;

	if (const UDataLayerManager* DataLayerManager = GetDataLayerManager())
	{
		Result = DataLayerManager->GetEffectiveActiveDataLayerNames().Array();
	}

	return Result;
}

bool UGenericWorldPartitionSubsystem::IsAnyDataLayerInEffectiveRuntimeState(const TArray<FName>& DataLayerNames, EDataLayerRuntimeState State) const
{
	if (const UDataLayerManager* DataLayerManager = GetDataLayerManager())
	{
		return DataLayerManager->IsAnyDataLayerInEffectiveRuntimeState(DataLayerNames, State);
	}

	return false;
}

bool UGenericWorldPartitionSubsystem::IsAllDataLayerInEffectiveRuntimeState(const TArray<FName>& DataLayerNames, EDataLayerRuntimeState State) const
{
	return Algo::AllOf(DataLayerNames, [this, State](const FName& DataLayerName)
	{
		return GetDataLayerEffectiveRuntimeStateByName(DataLayerName) == State;
	});
}

TArray<UDataLayerInstance*> UGenericWorldPartitionSubsystem::GetActorDataLayerInstances(const AActor* Actor) const
{
	TArray<UDataLayerInstance*> Result;

	if (::IsValid(Actor))
	{
		for (const UDataLayerInstance* DataLayerInstance : Actor->GetDataLayerInstances())
		{
			Result.Add(const_cast<UDataLayerInstance*>(DataLayerInstance));
		}
	}

	return Result;
}

TArray<FName> UGenericWorldPartitionSubsystem::GetActorDataLayerInstanceNames(const AActor* Actor) const
{
	TArray<FName> Result;

	if (!::IsValid(Actor))
	{
		return Result;
	}

#if WITH_EDITOR
	return Actor->GetDataLayerInstanceNames();
#else
	for (const UDataLayerInstance* DataLayerInstance : Actor->GetDataLayerInstances())
	{
		if (::IsValid(DataLayerInstance))
		{
			Result.AddUnique(DataLayerInstance->GetDataLayerFName());
		}
	}

	return Result;
#endif
}

TArray<UDataLayerInstance*> UGenericWorldPartitionSubsystem::GetCellDataLayerInstances(UWorldPartitionRuntimeCell* Cell) const
{
	TArray<UDataLayerInstance*> Result;

	if (::IsValid(Cell))
	{
		for (const UDataLayerInstance* DataLayerInstance : Cell->GetDataLayerInstances())
		{
			Result.Add(const_cast<UDataLayerInstance*>(DataLayerInstance));
		}
	}

	return Result;
}

TArray<FName> UGenericWorldPartitionSubsystem::GetCellDataLayerInstanceNames(UWorldPartitionRuntimeCell* Cell) const
{
	return ::IsValid(Cell) ? Cell->GetDataLayers() : TArray<FName>();
}

UWorldPartitionSubsystem* UGenericWorldPartitionSubsystem::GetNativeWorldPartitionSubsystem() const
{
	return GetWorld() ? GetWorld()->GetSubsystem<UWorldPartitionSubsystem>() : nullptr;
}

void UGenericWorldPartitionSubsystem::ExecuteHandleNextTick()
{
	if (NextTickTimerHandle.IsValid() && GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(NextTickTimerHandle);
	}

	if (GetWorld())
	{
		NextTickTimerHandle = GetWorld()->GetTimerManager().SetTimerForNextTick(FTimerDelegate::CreateUObject(this, &UGenericWorldPartitionSubsystem::ExecuteHandles));
	}
}

void UGenericWorldPartitionSubsystem::ExecuteHandles()
{
	TArray<FWorldPartitionCellConflict> CellConflicts;

	/** 先建立 Cell 到句柄的反向索引，后续才能发现同一 Cell 被多个新请求同时修改。 */
	for (UWorldPartitionHandle* TargetHandle : TargetWorldPartitionHandles)
	{
		if (!::IsValid(TargetHandle))
		{
			continue;
		}

		for (UWorldPartitionRuntimeCell* Cell : TargetHandle->GetCells())
		{
			if (!::IsValid(Cell))
			{
				continue;
			}

			FWorldPartitionCellConflict* FoundConflict = CellConflicts.FindByPredicate([Cell](const FWorldPartitionCellConflict& Conflict)
			{
				return Conflict.Cell == Cell;
			});

			if (FoundConflict == nullptr)
			{
				FoundConflict = &CellConflicts.AddDefaulted_GetRef();
				FoundConflict->Cell = Cell;
			}

			FoundConflict->ModifyHandles.AddUnique(TargetHandle);
		}
	}

	/** 冲突合并采用“后提交覆盖先提交”策略，只移除尚未执行的 Cell，不打断已经开始等待的句柄。 */
	for (const FWorldPartitionCellConflict& Conflict : CellConflicts)
	{
		if (Conflict.ModifyHandles.Num() <= 1)
		{
			continue;
		}

		int32 RetainedHandleIndex = INDEX_NONE;

		for (UWorldPartitionHandle* ModifyHandle : Conflict.ModifyHandles)
		{
			const int32 CurrentHandleIndex = TargetWorldPartitionHandles.Find(ModifyHandle);
			if (CurrentHandleIndex == INDEX_NONE)
			{
				continue;
			}

			if (RetainedHandleIndex == INDEX_NONE)
			{
				RetainedHandleIndex = CurrentHandleIndex;
				continue;
			}

			if (CurrentHandleIndex > RetainedHandleIndex)
			{
				TargetWorldPartitionHandles[RetainedHandleIndex]->RemoveCell(Conflict.Cell);
				RetainedHandleIndex = CurrentHandleIndex;
			}
			else
			{
				TargetWorldPartitionHandles[CurrentHandleIndex]->RemoveCell(Conflict.Cell);
			}
		}
	}

	WorldPartitionHandles.Append(TargetWorldPartitionHandles);

	/** 冲突处理完成后再启动句柄，确保每个句柄看到的目标列表已经是最终列表。 */
	TArray<UWorldPartitionHandle*> PendingHandles = TargetWorldPartitionHandles;
	for (UWorldPartitionHandle* PendingHandle : PendingHandles)
	{
		if (::IsValid(PendingHandle))
		{
			PendingHandle->Startup();
		}
	}

	TargetWorldPartitionHandles.Reset();
}

void UGenericWorldPartitionSubsystem::OnHandleCellOnceFinish(UWorldPartitionHandle* InHandle, UWorldPartitionRuntimeCell* InCell)
{
}

void UGenericWorldPartitionSubsystem::OnHandleCellFinish(UWorldPartitionHandle* InHandle)
{
	if (!::IsValid(InHandle))
	{
		return;
	}

	InHandle->GetHandleOnceFinishEvent().RemoveAll(this);
	InHandle->GetHandleFinishEvent().RemoveAll(this);
	WorldPartitionHandles.Remove(InHandle);
	TargetWorldPartitionHandles.Remove(InHandle);
}
