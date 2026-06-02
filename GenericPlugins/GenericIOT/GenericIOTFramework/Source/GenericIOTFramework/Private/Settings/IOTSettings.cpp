// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Settings/IOTSettings.h"

UIOTSettings::UIOTSettings()
{
	if (DiscoveryBaseUrls.Num() == 0)
	{
		DiscoveryBaseUrls =
		{
			TEXT("http://homeassistant.local:8123"),
			TEXT("http://homeassistant:8123"),
			TEXT("http://127.0.0.1:8123")
		};
	}
}
