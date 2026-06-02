// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceSynthesisSherpaOnnxConfigDataAsset.h"

USherpaOnnxSynthesisConfigDataAsset::USherpaOnnxSynthesisConfigDataAsset()
{
	ProviderName = TEXT("SherpaOnnx");
	RouteSource = EVoiceRouteSource::Offline;
}

bool USherpaOnnxSynthesisConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (SherpaOnnxModelRoot.Path.IsEmpty())
	{
		OutMessage = TEXT("SherpaOnnx synthesis config requires SherpaOnnxModelRoot.");
		return false;
	}

	OutMessage = TEXT("SherpaOnnx synthesis config is valid.");
	return true;
}
