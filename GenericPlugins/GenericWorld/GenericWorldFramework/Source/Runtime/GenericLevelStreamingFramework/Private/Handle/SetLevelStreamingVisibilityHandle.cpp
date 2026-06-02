// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Handle/SetLevelStreamingVisibilityHandle.h"

#include "BPFunctions/BPFunctions_LevelStreaming.h"
#include "Subsystem/GenericLevelStreamingSubsystem.h"

void USetLevelStreamingVisibilityHandle::Initialize(const FSetLevelStreamingVisibilitySetting& InSetting, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	Initialize(TArray<FSetLevelStreamingVisibilitySetting>{InSetting}, OnOnceFinish, OnFinish);
}

void USetLevelStreamingVisibilityHandle::Initialize(TArray<FSetLevelStreamingVisibilitySetting> InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish)
{
	for (const FSetLevelStreamingVisibilitySetting& Setting : InSettings)
	{
		if (Setting.IsValid() && !SetLevelStreamingVisibilitySettings.Contains(Setting))
		{
			SetLevelStreamingVisibilitySettings.Add(Setting);
		}
	}

	OnSetLevelStreamingVisibilityOnceFinish = OnOnceFinish;
	OnSetLevelStreamingVisibilityFinish = OnFinish;
}

void USetLevelStreamingVisibilityHandle::RemoveLevel(const TSoftObjectPtr<UWorld>& InLevel)
{
	const int32 Index = GetIndexByLevel(InLevel);
	if (Index >= GetLevelIndex())
	{
		SetLevelStreamingVisibilitySettings.RemoveAll([&InLevel](const FSetLevelStreamingVisibilitySetting& Setting)
		{
			return Setting.Level.ToSoftObjectPath() == InLevel.ToSoftObjectPath();
		});
	}
}

TArray<TSoftObjectPtr<UWorld>> USetLevelStreamingVisibilityHandle::GetLevels()
{
	TArray<TSoftObjectPtr<UWorld>> HandleLevels;

	for (const FSetLevelStreamingVisibilitySetting& Setting : SetLevelStreamingVisibilitySettings)
	{
		HandleLevels.Add(Setting.Level);
	}

	return HandleLevels;
}

void USetLevelStreamingVisibilityHandle::ExecuteHandle(int32 Index)
{
	if (!SetLevelStreamingVisibilitySettings.IsValidIndex(Index))
	{
		OnOnceFinish();
		return;
	}

	const FSetLevelStreamingVisibilitySetting& Setting = SetLevelStreamingVisibilitySettings[Index];
	if (!Setting.IsValid())
	{
		OnOnceFinish();
		return;
	}

	const bool bIsLevelLoaded = UBPFunctions_LevelStreaming::IsLevelLoaded(this, Setting.Level);
	if (!Setting.bVisible && !bIsLevelLoaded)
	{
		OnOnceFinish();
		return;
	}

	if (Setting.bVisible && !bIsLevelLoaded)
	{
		if (UGenericLevelStreamingSubsystem* GenericLevelStreamingSubsystem = UGenericLevelStreamingSubsystem::Get(this))
		{
			GenericLevelStreamingSubsystem->LoadLevel(Setting.Level, false, false, FOnHandleLevelStreamingFinish::CreateUObject(this, &USetLevelStreamingVisibilityHandle::ApplyCurrentLevelVisibility));
		}
		else
		{
			OnOnceFinish();
		}
		return;
	}

	ApplyCurrentLevelVisibility();
}

void USetLevelStreamingVisibilityHandle::HandleOnOnceFinish()
{
	Super::HandleOnOnceFinish();
	OnSetLevelStreamingVisibilityOnceFinish.ExecuteIfBound();
}

void USetLevelStreamingVisibilityHandle::HandleOnFinish()
{
	Super::HandleOnFinish();
	OnSetLevelStreamingVisibilityFinish.ExecuteIfBound();
}

TArray<FSetLevelStreamingVisibilitySetting> USetLevelStreamingVisibilityHandle::GetSetLevelStreamingVisibilitySettingsCopy() const
{
	return SetLevelStreamingVisibilitySettings;
}

bool USetLevelStreamingVisibilityHandle::GetCurrentSetLevelStreamingVisibilitySetting(FSetLevelStreamingVisibilitySetting& OutSetting) const
{
	if (SetLevelStreamingVisibilitySettings.IsValidIndex(GetLevelIndex()))
	{
		OutSetting = SetLevelStreamingVisibilitySettings[GetLevelIndex()];
		return true;
	}

	OutSetting = FSetLevelStreamingVisibilitySetting();
	return false;
}

void USetLevelStreamingVisibilityHandle::ApplyCurrentLevelVisibility()
{
	if (SetLevelStreamingVisibilitySettings.IsValidIndex(GetLevelIndex()))
	{
		const FSetLevelStreamingVisibilitySetting& Setting = SetLevelStreamingVisibilitySettings[GetLevelIndex()];
		SetLevelVisibility(Setting.Level, Setting.bVisible);
		return;
	}

	OnOnceFinish();
}

void USetLevelStreamingVisibilityHandle::SetLevelVisibility(const TSoftObjectPtr<UWorld>& Level, const bool bVisible)
{
	if (ULevelStreaming* LevelStreaming = UBPFunctions_LevelStreaming::GetLevelStreaming(this, Level))
	{
		if (LevelStreaming->ShouldBeVisible() != bVisible)
		{
			LevelStreaming->OnLevelShown.RemoveAll(this);
			LevelStreaming->OnLevelHidden.RemoveAll(this);
			LevelStreaming->OnLevelHidden.AddUniqueDynamic(this, &USetLevelStreamingVisibilityHandle::OnLevelVisibilityChanged);
			LevelStreaming->OnLevelShown.AddUniqueDynamic(this, &USetLevelStreamingVisibilityHandle::OnLevelVisibilityChanged);

			LevelStreaming->SetShouldBeVisible(bVisible);
			return;
		}
	}

	OnOnceFinish();
}

void USetLevelStreamingVisibilityHandle::OnLevelVisibilityChanged()
{
	if (SetLevelStreamingVisibilitySettings.IsValidIndex(GetLevelIndex()))
	{
		if (ULevelStreaming* LevelStreaming = UBPFunctions_LevelStreaming::GetLevelStreaming(this, SetLevelStreamingVisibilitySettings[GetLevelIndex()].Level))
		{
			LevelStreaming->OnLevelShown.RemoveAll(this);
			LevelStreaming->OnLevelHidden.RemoveAll(this);
		}
	}

	OnOnceFinish();
}
