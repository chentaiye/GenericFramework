// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Converter/MercatorCoordinateConverter.h"

#include "Utilities/GenericProjectionUtilities.h"

namespace
{
const FString WGS84CRS(TEXT("EPSG:4326"));
const FString MercatorCRS(TEXT("EPSG:3857"));
}

FGameplayTag UMercatorCoordinateConverter::GetCoordinateSystem() const
{
	return TAG_GameplayGeoreferencing_CoordinateSystem_Mercator;
}

EGenericCoordinateFormat UMercatorCoordinateConverter::GetCoordinateFormat() const
{
	return EGenericCoordinateFormat::Projected;
}

bool UMercatorCoordinateConverter::RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const
{
	if (InCoordinate.CoordinateFormat == EGenericCoordinateFormat::Geographic)
	{
		return GenericProjectionUtilities::GeographicToECEFCentimeters(WGS84CRS, InCoordinate.GeographicCoordinate, OutECEFCentimeters);
	}

	return GenericProjectionUtilities::ProjectedToECEFCentimeters(MercatorCRS, InCoordinate.ProjectedCoordinate, OutECEFCentimeters);
}

bool UMercatorCoordinateConverter::ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const
{
	OutCoordinate.CoordinateSystem = GetCoordinateSystem();
	OutCoordinate.CoordinateFormat = TargetFormat;

	if (TargetFormat == EGenericCoordinateFormat::Geographic)
	{
		return GenericProjectionUtilities::ECEFCentimetersToGeographic(WGS84CRS, InECEFCentimeters, OutCoordinate.GeographicCoordinate);
	}

	return GenericProjectionUtilities::ECEFCentimetersToProjected(MercatorCRS, InECEFCentimeters, OutCoordinate.ProjectedCoordinate);
}
