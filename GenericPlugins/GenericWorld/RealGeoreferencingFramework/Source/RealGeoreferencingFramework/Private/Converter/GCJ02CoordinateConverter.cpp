// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Converter/GCJ02CoordinateConverter.h"

#include "Utilities/ChinaCoordinateOffset.h"
#include "Utilities/GenericProjectionUtilities.h"

namespace
{
const FString WGS84CRS(TEXT("EPSG:4326"));
}

FGameplayTag UGCJ02CoordinateConverter::GetCoordinateSystem() const
{
	return TAG_GameplayGeoreferencing_CoordinateSystem_GCJ02;
}

EGenericCoordinateFormat UGCJ02CoordinateConverter::GetCoordinateFormat() const
{
	return EGenericCoordinateFormat::Geographic;
}

bool UGCJ02CoordinateConverter::RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const
{
	if (InCoordinate.CoordinateFormat != EGenericCoordinateFormat::Geographic)
	{
		return false;
	}

	const FGenericCoordinate WGS84Coordinate = ChinaCoordinateOffset::GCJ02ToWGS84(InCoordinate.GeographicCoordinate);
	return GenericProjectionUtilities::GeographicToECEFCentimeters(WGS84CRS, WGS84Coordinate, OutECEFCentimeters);
}

bool UGCJ02CoordinateConverter::ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const
{
	if (TargetFormat != EGenericCoordinateFormat::Geographic)
	{
		return false;
	}

	FGenericCoordinate WGS84Coordinate;
	if (!GenericProjectionUtilities::ECEFCentimetersToGeographic(WGS84CRS, InECEFCentimeters, WGS84Coordinate))
	{
		return false;
	}

	OutCoordinate.CoordinateSystem = GetCoordinateSystem();
	OutCoordinate.CoordinateFormat = EGenericCoordinateFormat::Geographic;
	OutCoordinate.GeographicCoordinate = ChinaCoordinateOffset::WGS84ToGCJ02(WGS84Coordinate);
	return true;
}
