// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceProviderConfigDataAsset.h"

bool UVoiceProviderConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!bEnableProviderConfig)
	{
		OutMessage = FString::Printf(TEXT("Provider config is disabled. Provider=%s"), *ProviderName.ToString());
		return false;
	}

	if (ProviderName.IsNone())
	{
		OutMessage = TEXT("Provider config requires a ProviderName.");
		return false;
	}

	OutMessage = FString::Printf(TEXT("Provider config is valid. Provider=%s"), *ProviderName.ToString());
	return true;
}

bool UVoiceProviderConfigDataAsset::MatchesProvider(const FName InProviderName, const EVoiceRouteSource InRouteSource) const
{
	if (!bEnableProviderConfig || ProviderName != InProviderName)
	{
		return false;
	}

	return InRouteSource == EVoiceRouteSource::None || RouteSource == EVoiceRouteSource::None || RouteSource == InRouteSource;
}

const UVoiceProviderConfigDataAsset* UVoiceProviderConfigDataAsset::FindFirstValidConfig(
	const TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>>& InConfigs,
	const FName InProviderName,
	const EVoiceRouteSource InRouteSource,
	FString& OutMessage)
{
	FString LastMessage = FString::Printf(TEXT("No valid provider config found. Provider=%s Route=%d"),
		*InProviderName.ToString(),
		static_cast<int32>(InRouteSource));

	for (const TSoftObjectPtr<UVoiceProviderConfigDataAsset>& ConfigPtr : InConfigs)
	{
		const UVoiceProviderConfigDataAsset* Config = ConfigPtr.LoadSynchronous();
		if (Config == nullptr || !Config->MatchesProvider(InProviderName, InRouteSource))
		{
			continue;
		}

		FString ValidationMessage;
		if (Config->ValidateConfig(ValidationMessage))
		{
			OutMessage = ValidationMessage;
			return Config;
		}

		LastMessage = ValidationMessage;
	}

	OutMessage = LastMessage;
	return nullptr;
}
