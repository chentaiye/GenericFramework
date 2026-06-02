// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Config/VoiceWakeupPicovoiceConfigDataAsset.h"

UPicovoiceWakeupConfigDataAsset::UPicovoiceWakeupConfigDataAsset()
{
	ProviderName = TEXT("Picovoice");
	RouteSource = EVoiceRouteSource::Offline;
}

bool UPicovoiceWakeupConfigDataAsset::ValidateConfig(FString& OutMessage) const
{
	if (!Super::ValidateConfig(OutMessage))
	{
		return false;
	}

	if (PicovoiceKeywordFiles.IsEmpty())
	{
		OutMessage = TEXT("Picovoice wakeup config requires at least one PicovoiceKeywordFiles entry.");
		return false;
	}

	OutMessage = TEXT("Picovoice wakeup config is valid.");
	return true;
}
