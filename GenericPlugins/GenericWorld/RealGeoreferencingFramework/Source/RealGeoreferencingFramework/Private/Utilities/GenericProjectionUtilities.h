// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RealGeoreferencingType.h"

namespace GenericProjectionUtilities
{
bool GeographicToECEFCentimeters(const FString& GeographicCRS, const FGenericCoordinate& InCoordinate, FVector& OutECEFCentimeters);
bool ECEFCentimetersToGeographic(const FString& GeographicCRS, const FVector& InECEFCentimeters, FGenericCoordinate& OutCoordinate);
bool ProjectedToECEFCentimeters(const FString& ProjectedCRS, const FGenericProjectedCoordinate& InCoordinate, FVector& OutECEFCentimeters);
bool ECEFCentimetersToProjected(const FString& ProjectedCRS, const FVector& InECEFCentimeters, FGenericProjectedCoordinate& OutCoordinate);
bool ProjectionSettingsToECEFCentimeters(const FGenericProjectionSettings& ProjectionSettings, const FGenericProjectedCoordinate& InCoordinate, FVector& OutECEFCentimeters);
bool ECEFCentimetersToProjectionSettings(const FGenericProjectionSettings& ProjectionSettings, const FVector& InECEFCentimeters, FGenericProjectedCoordinate& OutCoordinate);
FString BuildProjectionCRSString(const FGenericProjectionSettings& ProjectionSettings);
FString BuildUTMCRSString(int32 Zone, bool bSouthernHemisphere);
FString BuildGaussKrugerCRSString(bool bUseZoneNumber, int32 ZoneNumber, bool bSixDegreeZone, double CentralMeridian, double FalseEasting, double FalseNorthing, double ScaleFactor);
}
