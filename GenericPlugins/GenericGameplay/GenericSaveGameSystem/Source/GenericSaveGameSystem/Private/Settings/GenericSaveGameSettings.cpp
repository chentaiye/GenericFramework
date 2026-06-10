// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Settings/GenericSaveGameSettings.h"

UGenericSaveGameSettings* UGenericSaveGameSettings::Get()
{
	return GetMutableDefault<UGenericSaveGameSettings>();
}
