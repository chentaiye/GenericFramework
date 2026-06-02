// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceRecognitionSherpaOnnxConfigDataAsset.h"

USherpaOnnxRecognitionConfigDataAsset::USherpaOnnxRecognitionConfigDataAsset()
{
	ProviderName = TEXT("SherpaOnnx");
	RouteSource = EVoiceRouteSource::Offline;
}

bool USherpaOnnxRecognitionConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (SherpaOnnxModelRoot.Path.IsEmpty())
	{
		OutMessage = TEXT("SherpaOnnx recognition config requires SherpaOnnxModelRoot.");
		return false;
	}

	OutMessage = TEXT("SherpaOnnx recognition config is valid.");
	return true;
}
