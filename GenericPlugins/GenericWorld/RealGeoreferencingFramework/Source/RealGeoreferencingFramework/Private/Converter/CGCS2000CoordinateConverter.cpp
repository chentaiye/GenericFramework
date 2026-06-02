// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Converter/CGCS2000CoordinateConverter.h"

#include "Utilities/GenericProjectionUtilities.h"

namespace
{
const FString CGCS2000CRS(TEXT("EPSG:4490"));
}

FGameplayTag UCGCS2000CoordinateConverter::GetCoordinateSystem() const
{
	return TAG_GameplayGeoreferencing_CoordinateSystem_CGCS2000;
}

EGenericCoordinateFormat UCGCS2000CoordinateConverter::GetCoordinateFormat() const
{
	return EGenericCoordinateFormat::Geographic;
}

bool UCGCS2000CoordinateConverter::RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const
{
	if (InCoordinate.CoordinateFormat != EGenericCoordinateFormat::Geographic)
	{
		return false;
	}

	return GenericProjectionUtilities::GeographicToECEFCentimeters(CGCS2000CRS, InCoordinate.GeographicCoordinate, OutECEFCentimeters);
}

bool UCGCS2000CoordinateConverter::ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const
{
	if (TargetFormat != EGenericCoordinateFormat::Geographic)
	{
		return false;
	}

	FGenericCoordinate GeographicCoordinate;
	if (!GenericProjectionUtilities::ECEFCentimetersToGeographic(CGCS2000CRS, InECEFCentimeters, GeographicCoordinate))
	{
		return false;
	}

	OutCoordinate.CoordinateSystem = GetCoordinateSystem();
	OutCoordinate.CoordinateFormat = EGenericCoordinateFormat::Geographic;
	OutCoordinate.GeographicCoordinate = GeographicCoordinate;
	return true;
}
