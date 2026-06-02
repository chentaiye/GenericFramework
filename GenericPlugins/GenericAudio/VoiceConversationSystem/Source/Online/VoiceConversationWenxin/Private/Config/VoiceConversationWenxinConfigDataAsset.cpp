// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceConversationWenxinConfigDataAsset.h"

UWenxinConversationConfigDataAsset::UWenxinConversationConfigDataAsset()
{
	ProviderName = TEXT("Wenxin");
	RouteSource = EVoiceRouteSource::Online;
}

bool UWenxinConversationConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (WenxinAccessToken.IsEmpty() && (WenxinApiKey.IsEmpty() || WenxinSecretKey.IsEmpty()))
	{
		OutMessage = TEXT("Wenxin conversation config requires WenxinAccessToken or WenxinApiKey plus WenxinSecretKey.");
		return false;
	}

	OutMessage = TEXT("Wenxin conversation config is valid.");
	return true;
}
