// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Converter/WGS84CoordinateConverter.h"

#include "Utilities/GenericProjectionUtilities.h"

namespace
{
const FString WGS84ConverterCRS(TEXT("EPSG:4326"));
}

FGameplayTag UWGS84CoordinateConverter::GetCoordinateSystem() const
{
	return TAG_GameplayGeoreferencing_CoordinateSystem_WGS84;
}

EGenericCoordinateFormat UWGS84CoordinateConverter::GetCoordinateFormat() const
{
	return EGenericCoordinateFormat::Geographic;
}

bool UWGS84CoordinateConverter::RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const
{
	if (InCoordinate.CoordinateFormat != EGenericCoordinateFormat::Geographic)
	{
		return false;
	}

	return GenericProjectionUtilities::GeographicToECEFCentimeters(WGS84ConverterCRS, InCoordinate.GeographicCoordinate, OutECEFCentimeters);
}

bool UWGS84CoordinateConverter::ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const
{
	if (TargetFormat != EGenericCoordinateFormat::Geographic)
	{
		return false;
	}

	FGenericCoordinate GeographicCoordinate;
	if (!GenericProjectionUtilities::ECEFCentimetersToGeographic(WGS84ConverterCRS, InECEFCentimeters, GeographicCoordinate))
	{
		return false;
	}

	OutCoordinate.CoordinateSystem = GetCoordinateSystem();
	OutCoordinate.CoordinateFormat = EGenericCoordinateFormat::Geographic;
	OutCoordinate.GeographicCoordinate = GeographicCoordinate;
	return true;
}
