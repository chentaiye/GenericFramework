// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Converter/GaussKrugerCoordinateConverter.h"

#include "Utilities/GenericProjectionUtilities.h"

namespace
{
const FString GaussKrugerWGS84CRS(TEXT("EPSG:4326"));
}

FGameplayTag UGaussKrugerCoordinateConverter::GetCoordinateSystem() const
{
	return TAG_GameplayGeoreferencing_CoordinateSystem_GaussKruger;
}

EGenericCoordinateFormat UGaussKrugerCoordinateConverter::GetCoordinateFormat() const
{
	return EGenericCoordinateFormat::Projected;
}

bool UGaussKrugerCoordinateConverter::RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const
{
	if (InCoordinate.CoordinateFormat == EGenericCoordinateFormat::Geographic)
	{
		return GenericProjectionUtilities::GeographicToECEFCentimeters(GaussKrugerWGS84CRS, InCoordinate.GeographicCoordinate, OutECEFCentimeters);
	}

	return GenericProjectionUtilities::ProjectedToECEFCentimeters(
		GenericProjectionUtilities::BuildGaussKrugerCRSString(bUseZoneNumber, ZoneNumber, bSixDegreeZone, CentralMeridian, FalseEasting, FalseNorthing, ScaleFactor),
		InCoordinate.ProjectedCoordinate,
		OutECEFCentimeters);
}

bool UGaussKrugerCoordinateConverter::ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const
{
	OutCoordinate.CoordinateSystem = GetCoordinateSystem();
	OutCoordinate.CoordinateFormat = TargetFormat;

	if (TargetFormat == EGenericCoordinateFormat::Geographic)
	{
		return GenericProjectionUtilities::ECEFCentimetersToGeographic(GaussKrugerWGS84CRS, InECEFCentimeters, OutCoordinate.GeographicCoordinate);
	}

	return GenericProjectionUtilities::ECEFCentimetersToProjected(
		GenericProjectionUtilities::BuildGaussKrugerCRSString(bUseZoneNumber, ZoneNumber, bSixDegreeZone, CentralMeridian, FalseEasting, FalseNorthing, ScaleFactor),
		InECEFCentimeters,
		OutCoordinate.ProjectedCoordinate);
}
