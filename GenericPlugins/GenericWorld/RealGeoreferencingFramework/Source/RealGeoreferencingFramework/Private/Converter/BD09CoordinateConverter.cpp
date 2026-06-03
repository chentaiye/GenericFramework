// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Converter/BD09CoordinateConverter.h"

#include "Utilities/ChinaCoordinateOffset.h"
#include "Utilities/GenericProjectionUtilities.h"

namespace
{
const FString BD09WGS84CRS(TEXT("EPSG:4326"));
}

FGameplayTag UBD09CoordinateConverter::GetCoordinateSystem() const
{
	return TAG_GameplayGeoreferencing_CoordinateSystem_BD09;
}

EGenericCoordinateFormat UBD09CoordinateConverter::GetCoordinateFormat() const
{
	return EGenericCoordinateFormat::Geographic;
}

bool UBD09CoordinateConverter::RealCoordinateToECEF(const FGenericRealCoordinate& InCoordinate, FVector& OutECEFCentimeters) const
{
	if (InCoordinate.CoordinateFormat != EGenericCoordinateFormat::Geographic)
	{
		return false;
	}

	const FGenericCoordinate GCJ02Coordinate = ChinaCoordinateOffset::BD09ToGCJ02(InCoordinate.GeographicCoordinate);
	const FGenericCoordinate WGS84Coordinate = ChinaCoordinateOffset::GCJ02ToWGS84(GCJ02Coordinate);
	return GenericProjectionUtilities::GeographicToECEFCentimeters(BD09WGS84CRS, WGS84Coordinate, OutECEFCentimeters);
}

bool UBD09CoordinateConverter::ECEFToRealCoordinate(const FVector& InECEFCentimeters, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const
{
	if (TargetFormat != EGenericCoordinateFormat::Geographic)
	{
		return false;
	}

	FGenericCoordinate WGS84Coordinate;
	if (!GenericProjectionUtilities::ECEFCentimetersToGeographic(BD09WGS84CRS, InECEFCentimeters, WGS84Coordinate))
	{
		return false;
	}

	const FGenericCoordinate GCJ02Coordinate = ChinaCoordinateOffset::WGS84ToGCJ02(WGS84Coordinate);
	OutCoordinate.CoordinateSystem = GetCoordinateSystem();
	OutCoordinate.CoordinateFormat = EGenericCoordinateFormat::Geographic;
	OutCoordinate.GeographicCoordinate = ChinaCoordinateOffset::GCJ02ToBD09(GCJ02Coordinate);
	return true;
}
