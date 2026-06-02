// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceConversationDifyConfigDataAsset.h"

UDifyConversationConfigDataAsset::UDifyConversationConfigDataAsset()
{
	ProviderName = TEXT("Dify");
	RouteSource = EVoiceRouteSource::Online;
}

bool UDifyConversationConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (DifyBaseUrl.IsEmpty() || DifyApiKey.IsEmpty())
	{
		OutMessage = TEXT("Dify conversation config requires DifyBaseUrl and DifyApiKey.");
		return false;
	}

	OutMessage = TEXT("Dify conversation config is valid.");
	return true;
}
