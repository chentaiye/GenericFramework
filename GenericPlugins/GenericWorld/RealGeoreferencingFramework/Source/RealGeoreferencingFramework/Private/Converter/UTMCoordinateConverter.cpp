// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Converter/UTMCoordinateConverter.h"

#include "Utilities/GenericProjectionUtilities.h"

namespace
{
const FString UTMWGS84CRS(TEXT("EPSG:4326"));
}

FGameplayTag UUTMCoordinateConverter::GetCoordinateSystem() const
{
	return TAG_GameplayGeoreferencing_CoordinateSystem_UTM;
}

EGenericCoordinateFormat UUTMCoordinateConverter::GetCoordinateFormat() const
{
	return EGenericCoordinateFormat::Projected;
}

bool UUTMCoordinateConverter::RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const
{
	if (InCoordinate.CoordinateFormat == EGenericCoordinateFormat::Geographic)
	{
		return GenericProjectionUtilities::GeographicToECEFCentimeters(UTMWGS84CRS, InCoordinate.GeographicCoordinate, OutECEFCentimeters);
	}

	return GenericProjectionUtilities::ProjectedToECEFCentimeters(GenericProjectionUtilities::BuildUTMCRSString(Zone, bSouthernHemisphere), InCoordinate.ProjectedCoordinate, OutECEFCentimeters);
}

bool UUTMCoordinateConverter::ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const
{
	OutCoordinate.CoordinateSystem = GetCoordinateSystem();
	OutCoordinate.CoordinateFormat = TargetFormat;

	if (TargetFormat == EGenericCoordinateFormat::Geographic)
	{
		return GenericProjectionUtilities::ECEFCentimetersToGeographic(UTMWGS84CRS, InECEFCentimeters, OutCoordinate.GeographicCoordinate);
	}

	return GenericProjectionUtilities::ECEFCentimetersToProjected(GenericProjectionUtilities::BuildUTMCRSString(Zone, bSouthernHemisphere), InECEFCentimeters, OutCoordinate.ProjectedCoordinate);
}
