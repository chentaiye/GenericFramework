// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Handle/LoadLevelStreamingHandle.h"

#include "BPFunctions/BPFunctions_LevelStreaming.h"
#include "Kismet/GameplayStatics.h"

void ULoadLevelStreamingHandle::Initialize(const FLoadLevelStreamingSetting& InSetting, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	Initialize(TArray<FLoadLevelStreamingSetting>{InSetting}, OnOnceFinish, OnFinish);
}

void ULoadLevelStreamingHandle::Initialize(TArray<FLoadLevelStreamingSetting> InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	for (const FLoadLevelStreamingSetting& Setting : InSettings)
	{
		if (Setting.IsValid() && !LoadLevelStreamingSettings.Contains(Setting))
		{
			LoadLevelStreamingSettings.Add(Setting);
		}
	}

	OnLoadLevelStreamingOnceFinish = OnOnceFinish;
	OnLoadLevelStreamingFinish = OnFinish;
}

void ULoadLevelStreamingHandle::RemoveLevel(const TSoftObjectPtr<UWorld>& InLevel)
{
	const int32 Index = GetIndexByLevel(InLevel);
	if (Index >= GetLevelIndex())
	{
		LoadLevelStreamingSettings.RemoveAll([&InLevel](const FLoadLevelStreamingSetting& Setting)
		{
			return Setting.Level.ToSoftObjectPath() == InLevel.ToSoftObjectPath();
		});
	}
}

TArray<TSoftObjectPtr<UWorld>> ULoadLevelStreamingHandle::GetLevels()
{
	TArray<TSoftObjectPtr<UWorld>> HandleLevels;

	for (const FLoadLevelStreamingSetting& Setting : LoadLevelStreamingSettings)
	{
		HandleLevels.Add(Setting.Level);
	}

	return HandleLevels;
}

void ULoadLevelStreamingHandle::ExecuteHandle(int32 Index)
{
	if (!LoadLevelStreamingSettings.IsValidIndex(Index))
	{
		OnOnceFinish();
		return;
	}

	if (UBPFunctions_LevelStreaming::IsLevelLoaded(this, LoadLevelStreamingSettings[Index].Level))
	{
		OnOnceFinish();
		return;
	}

	LoadLevel(LoadLevelStreamingSettings[Index].Level, LoadLevelStreamingSettings[Index].bMakeVisibleAfterLoad, LoadLevelStreamingSettings[Index].bShouldBlockOnLoad);
}

void ULoadLevelStreamingHandle::HandleOnOnceFinish()
{
	Super::HandleOnOnceFinish();
	OnLoadLevelStreamingOnceFinish.ExecuteIfBound();
}

void ULoadLevelStreamingHandle::HandleOnFinish()
{
	Super::HandleOnFinish();
	OnLoadLevelStreamingFinish.ExecuteIfBound();
}

TArray<FLoadLevelStreamingSetting> ULoadLevelStreamingHandle::GetLoadLevelStreamingSettingsCopy() const
{
	return LoadLevelStreamingSettings;
}

bool ULoadLevelStreamingHandle::GetCurrentLoadLevelStreamingSetting(FLoadLevelStreamingSetting& OutSetting) const
{
	if (LoadLevelStreamingSettings.IsValidIndex(GetLevelIndex()))
	{
		OutSetting = LoadLevelStreamingSettings[GetLevelIndex()];
		return true;
	}

	OutSetting = FLoadLevelStreamingSetting();
	return false;
}

void ULoadLevelStreamingHandle::LoadLevel(const TSoftObjectPtr<UWorld>& Level, const bool bMakeVisibleAfterLoad, const bool bShouldBlockOnLoad)
{
	const FLatentActionInfo LatentActionInfo(FMath::Rand(), FMath::Rand(), TEXT("OnOnceFinish"), this);
	UGameplayStatics::LoadStreamLevelBySoftObjectPtr(this, Level, bMakeVisibleAfterLoad, bShouldBlockOnLoad, LatentActionInfo);
}
