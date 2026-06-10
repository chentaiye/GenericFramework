// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Handle/UnLoadLevelStreamingHandle.h"

#include "BPFunctions/BPFunctions_LevelStreaming.h"
#include "Kismet/GameplayStatics.h"

void UUnLoadLevelStreamingHandle::Initialize(const FUnloadLevelStreamingSetting& InSetting, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	Initialize(TArray<FUnloadLevelStreamingSetting>{InSetting}, OnOnceFinish, OnFinish);
}

void UUnLoadLevelStreamingHandle::Initialize(TArray<FUnloadLevelStreamingSetting> InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	for (const FUnloadLevelStreamingSetting& Setting : InSettings)
	{
		if (Setting.IsValid() && !UnLoadLevelStreamingSettings.Contains(Setting))
		{
			UnLoadLevelStreamingSettings.Add(Setting);
		}
	}

	OnUnLoadLevelStreamingOnceFinish = OnOnceFinish;
	OnUnLoadLevelStreamingFinish = OnFinish;
}

void UUnLoadLevelStreamingHandle::RemoveLevel(const TSoftObjectPtr<UWorld>& InLevel)
{
	const int32 Index = GetIndexByLevel(InLevel);
	if (Index >= GetLevelIndex())
	{
		UnLoadLevelStreamingSettings.RemoveAll([&InLevel](const FUnloadLevelStreamingSetting& Setting)
		{
			return Setting.Level.ToSoftObjectPath() == InLevel.ToSoftObjectPath();
		});
	}
}

TArray<TSoftObjectPtr<UWorld>> UUnLoadLevelStreamingHandle::GetLevels()
{
	TArray<TSoftObjectPtr<UWorld>> HandleLevels;

	for (const FUnloadLevelStreamingSetting& Setting : UnLoadLevelStreamingSettings)
	{
		HandleLevels.Add(Setting.Level);
	}

	return HandleLevels;
}

void UUnLoadLevelStreamingHandle::ExecuteHandle(int32 Index)
{
	if (!UnLoadLevelStreamingSettings.IsValidIndex(Index))
	{
		OnOnceFinish();
		return;
	}

	if (!UBPFunctions_LevelStreaming::IsLevelLoaded(this, UnLoadLevelStreamingSettings[Index].Level))
	{
		OnOnceFinish();
		return;
	}

	UnLoadLevel(UnLoadLevelStreamingSettings[Index].Level, UnLoadLevelStreamingSettings[Index].bShouldBlockOnUnload);
}

void UUnLoadLevelStreamingHandle::HandleOnOnceFinish()
{
	Super::HandleOnOnceFinish();
	OnUnLoadLevelStreamingOnceFinish.ExecuteIfBound();
}

void UUnLoadLevelStreamingHandle::HandleOnFinish()
{
	Super::HandleOnFinish();
	OnUnLoadLevelStreamingFinish.ExecuteIfBound();
}

TArray<FUnloadLevelStreamingSetting> UUnLoadLevelStreamingHandle::GetUnLoadLevelStreamingSettingsCopy() const
{
	return UnLoadLevelStreamingSettings;
}

bool UUnLoadLevelStreamingHandle::GetCurrentUnLoadLevelStreamingSetting(FUnloadLevelStreamingSetting& OutSetting) const
{
	if (UnLoadLevelStreamingSettings.IsValidIndex(GetLevelIndex()))
	{
		OutSetting = UnLoadLevelStreamingSettings[GetLevelIndex()];
		return true;
	}

	OutSetting = FUnloadLevelStreamingSetting();
	return false;
}

void UUnLoadLevelStreamingHandle::UnLoadLevel(const TSoftObjectPtr<UWorld>& Level, const bool bShouldBlockOnUnload)
{
	const FLatentActionInfo LatentActionInfo(FMath::Rand(), FMath::Rand(), TEXT("OnOnceFinish"), this);
	UGameplayStatics::UnloadStreamLevelBySoftObjectPtr(this, Level, LatentActionInfo, bShouldBlockOnUnload);
}
