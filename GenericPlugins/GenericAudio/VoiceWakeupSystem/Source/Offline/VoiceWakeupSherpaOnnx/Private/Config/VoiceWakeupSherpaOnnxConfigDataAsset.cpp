// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceWakeupSherpaOnnxConfigDataAsset.h"

#include "Misc/Paths.h"

USherpaOnnxWakeupConfigDataAsset::USherpaOnnxWakeupConfigDataAsset()
{
	ProviderName = TEXT("SherpaOnnx");
	RouteSource = EVoiceRouteSource::Offline;
}

bool USherpaOnnxWakeupConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (SherpaOnnxModelRoot.Path.IsEmpty())
	{
		OutMessage = TEXT("SherpaOnnx wakeup config requires SherpaOnnxModelRoot.");
		return false;
	}

	OutMessage = TEXT("SherpaOnnx wakeup config is valid.");
	return true;
}
