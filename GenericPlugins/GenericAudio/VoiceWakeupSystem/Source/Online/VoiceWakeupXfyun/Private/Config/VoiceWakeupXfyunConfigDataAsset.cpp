// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceWakeupXfyunConfigDataAsset.h"

#include "Misc/Paths.h"

UXfyunWakeupConfigDataAsset::UXfyunWakeupConfigDataAsset()
{
	ProviderName = TEXT("Xfyun");
	RouteSource = EVoiceRouteSource::Online;
}

bool UXfyunWakeupConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (XfyunAppId.IsEmpty())
	{
		OutMessage = TEXT("Xfyun wakeup config requires XfyunAppId.");
		return false;
	}

	if (!XfyunWakeupResourceFile.FilePath.IsEmpty() && !FPaths::FileExists(FPaths::ConvertRelativePathToFull(XfyunWakeupResourceFile.FilePath)))
	{
		OutMessage = FString::Printf(TEXT("Xfyun wakeup resource file is missing: %s"), *XfyunWakeupResourceFile.FilePath);
		return false;
	}

	OutMessage = TEXT("Xfyun wakeup config is valid.");
	return true;
}
