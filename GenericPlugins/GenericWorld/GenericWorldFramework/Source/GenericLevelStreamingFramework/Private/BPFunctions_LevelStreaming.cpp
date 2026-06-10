// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_LevelStreaming.h"

#include "Handle/LevelStreamingHandle.h"
#include "Handle/LoadLevelStreamingHandle.h"
#include "Handle/SetLevelStreamingVisibilityHandle.h"
#include "Handle/UnLoadLevelStreamingHandle.h"
#include "Subsystem/GenericLevelStreamingSubsystem.h"

namespace
{
FOnHandleLevelStreamingOnceFinish MakeOnceFinishDelegate(FHandleLevelStreamingOnceFinish InDelegate)
{
	return FOnHandleLevelStreamingOnceFinish::CreateLambda([InDelegate]() mutable
	{
		InDelegate.ExecuteIfBound();
	});
}

FOnHandleLevelStreamingFinish MakeFinishDelegate(FHandleLevelStreamingFinish InDelegate)
{
	return FOnHandleLevelStreamingFinish::CreateLambda([InDelegate]() mutable
	{
		InDelegate.ExecuteIfBound();
	});
}

void BindK2NodeDelegates(ULevelStreamingHandle* Handle, FHandleLevelStreamingK2OnceFinish OnOnceFinish, FHandleLevelStreamingK2Finish OnFinish)
{
	if (!Handle)
	{
		OnFinish.ExecuteIfBound();
		return;
	}

	Handle->GetHandleOnceFinishEvent().AddLambda([OnOnceFinish](ULevelStreamingHandle*, TSoftObjectPtr<UWorld> CompletedLevel) mutable
	{
		OnOnceFinish.ExecuteIfBound(CompletedLevel);
	});

	Handle->GetHandleFinishEvent().AddLambda([OnFinish](ULevelStreamingHandle*) mutable
	{
		OnFinish.ExecuteIfBound();
	});
}
}

void UBPFunctions_LevelStreaming::LoadLevel(const UObject* WorldContextObject, const TSoftObjectPtr<UWorld> Level, const bool bMakeVisibleAfterLoad, const bool bShouldBlockOnLoad, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->LoadLevel(Level, bMakeVisibleAfterLoad, bShouldBlockOnLoad, MakeFinishDelegate(OnFinish));
	}
}

void UBPFunctions_LevelStreaming::LoadLevels(const UObject* WorldContextObject, const TArray<TSoftObjectPtr<UWorld>> Levels, const bool bMakeVisibleAfterLoad, const bool bShouldBlockOnLoad, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->LoadLevels(Levels, bMakeVisibleAfterLoad, bShouldBlockOnLoad, MakeOnceFinishDelegate(OnOnceFinish), MakeFinishDelegate(OnFinish));
	}
}

void UBPFunctions_LevelStreaming::LoadLevelsBySetting(const UObject* WorldContextObject, const TArray<FLoadLevelStreamingSetting> LoadLevelStreamingSettings, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->LoadLevelsBySetting(LoadLevelStreamingSettings, MakeOnceFinishDelegate(OnOnceFinish), MakeFinishDelegate(OnFinish));
	}
}

void UBPFunctions_LevelStreaming::UnloadLevel(const UObject* WorldContextObject, const TSoftObjectPtr<UWorld> Level, const bool bShouldBlockOnUnload, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->UnloadLevel(Level, bShouldBlockOnUnload, MakeFinishDelegate(OnFinish));
	}
}

void UBPFunctions_LevelStreaming::UnloadLevels(const UObject* WorldContextObject, const TArray<TSoftObjectPtr<UWorld>> Levels, const bool bShouldBlockOnUnload, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->UnloadLevels(Levels, bShouldBlockOnUnload, MakeOnceFinishDelegate(OnOnceFinish), MakeFinishDelegate(OnFinish));
	}
}

void UBPFunctions_LevelStreaming::UnloadLevelsBySetting(const UObject* WorldContextObject, const TArray<FUnloadLevelStreamingSetting> UnloadLevelStreamingSettings, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->UnloadLevelsBySetting(UnloadLevelStreamingSettings, MakeOnceFinishDelegate(OnOnceFinish), MakeFinishDelegate(OnFinish));
	}
}

void UBPFunctions_LevelStreaming::SetLevelVisibility(const UObject* WorldContextObject, const TSoftObjectPtr<UWorld> Level, const bool bVisible, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->SetLevelVisibility(Level, bVisible, MakeFinishDelegate(OnFinish));
	}
}

void UBPFunctions_LevelStreaming::SetLevelsVisibility(const UObject* WorldContextObject, const TArray<TSoftObjectPtr<UWorld>> Levels, const bool bVisible, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->SetLevelsVisibility(Levels, bVisible, MakeOnceFinishDelegate(OnOnceFinish), MakeFinishDelegate(OnFinish));
	}
}

void UBPFunctions_LevelStreaming::SetLevelsVisibilityBySetting(const UObject* WorldContextObject, const TArray<FSetLevelStreamingVisibilitySetting> SetLevelStreamingVisibilitySettings, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->SetLevelsVisibilityBySetting(SetLevelStreamingVisibilitySettings, MakeOnceFinishDelegate(OnOnceFinish), MakeFinishDelegate(OnFinish));
	}
}

ULevelStreamingHandle* UBPFunctions_LevelStreaming::K2Node_LoadLevels(const UObject* WorldContextObject, const TArray<TSoftObjectPtr<UWorld>> Levels, const bool bMakeVisibleAfterLoad, const bool bShouldBlockOnLoad, FHandleLevelStreamingK2OnceFinish OnOnceFinish, FHandleLevelStreamingK2Finish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		ULevelStreamingHandle* Handle = GenericLevelStreamingSubsystem->LoadLevels(Levels, bMakeVisibleAfterLoad, bShouldBlockOnLoad);
		BindK2NodeDelegates(Handle, OnOnceFinish, OnFinish);
		return Handle;
	}

	OnFinish.ExecuteIfBound();
	return nullptr;
}

ULevelStreamingHandle* UBPFunctions_LevelStreaming::K2Node_UnloadLevels(const UObject* WorldContextObject, const TArray<TSoftObjectPtr<UWorld>> Levels, const bool bShouldBlockOnUnload, FHandleLevelStreamingK2OnceFinish OnOnceFinish, FHandleLevelStreamingK2Finish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		ULevelStreamingHandle* Handle = GenericLevelStreamingSubsystem->UnloadLevels(Levels, bShouldBlockOnUnload);
		BindK2NodeDelegates(Handle, OnOnceFinish, OnFinish);
		return Handle;
	}

	OnFinish.ExecuteIfBound();
	return nullptr;
}

ULevelStreamingHandle* UBPFunctions_LevelStreaming::K2Node_SetLevelsVisibility(const UObject* WorldContextObject, const TArray<TSoftObjectPtr<UWorld>> Levels, const bool bVisible, FHandleLevelStreamingK2OnceFinish OnOnceFinish, FHandleLevelStreamingK2Finish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		ULevelStreamingHandle* Handle = GenericLevelStreamingSubsystem->SetLevelsVisibility(Levels, bVisible);
		BindK2NodeDelegates(Handle, OnOnceFinish, OnFinish);
		return Handle;
	}

	OnFinish.ExecuteIfBound();
	return nullptr;
}

void UBPFunctions_LevelStreaming::LoadCurrentWorldLevelStreaming(const UObject* WorldContextObject, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->LoadCurrentWorldLevelStreaming(MakeOnceFinishDelegate(OnOnceFinish), MakeFinishDelegate(OnFinish));
	}
}

void UBPFunctions_LevelStreaming::UnLoadCurrentWorldLevelStreaming(const UObject* WorldContextObject, FHandleLevelStreamingOnceFinish OnOnceFinish, FHandleLevelStreamingFinish OnFinish)
{
	if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		GenericLevelStreamingSubsystem->UnLoadCurrentWorldLevelStreaming(MakeOnceFinishDelegate(OnOnceFinish), MakeFinishDelegate(OnFinish));
	}
}

TArray<TSoftObjectPtr<UWorld>> UBPFunctions_LevelStreaming::GetCurrentWorldLevelStreamingList(const UObject* WorldContextObject)
{
	if (const UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		return GenericLevelStreamingSubsystem->GetCurrentWorldLevelStreamingList();
	}
	return TArray<TSoftObjectPtr<UWorld>>{};
}

ULevelStreaming* UBPFunctions_LevelStreaming::GetLevelStreaming(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level)
{
	if (const UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		return GenericLevelStreamingSubsystem->GetLevelStreaming(Level);
	}
	return nullptr;
}

bool UBPFunctions_LevelStreaming::IsLevelLoaded(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level)
{
	if (const ULevelStreaming* LevelStreaming = GetLevelStreaming(WorldContextObject, Level))
	{
		return LevelStreaming->IsLevelLoaded();
	}
	return false;
}

bool UBPFunctions_LevelStreaming::IsCurrentWorldContainLevel(const UObject* WorldContextObject, TSoftObjectPtr<UWorld> Level, bool& Contain)
{
	if (const UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(WorldContextObject))
	{
		Contain = GenericLevelStreamingSubsystem->IsCurrentWorldContainLevel(Level);
		return true;
	}
	return false;
}
