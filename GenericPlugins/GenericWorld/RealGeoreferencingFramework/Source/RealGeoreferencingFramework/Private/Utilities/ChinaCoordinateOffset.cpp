// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Utilities/ChinaCoordinateOffset.h"

namespace
{
constexpr double KrasovskyA = 6378245.0;
constexpr double KrasovskyEE = 0.00669342162296594323;
constexpr double BaiduXPi = UE_DOUBLE_PI * 3000.0 / 180.0;

double TransformLatitude(double LongitudeDelta, double LatitudeDelta)
{
	double Result = -100.0 + 2.0 * LongitudeDelta + 3.0 * LatitudeDelta + 0.2 * LatitudeDelta * LatitudeDelta + 0.1 * LongitudeDelta * LatitudeDelta + 0.2 * FMath::Sqrt(FMath::Abs(LongitudeDelta));
	Result += (20.0 * FMath::Sin(6.0 * LongitudeDelta * UE_DOUBLE_PI) + 20.0 * FMath::Sin(2.0 * LongitudeDelta * UE_DOUBLE_PI)) * 2.0 / 3.0;
	Result += (20.0 * FMath::Sin(LatitudeDelta * UE_DOUBLE_PI) + 40.0 * FMath::Sin(LatitudeDelta / 3.0 * UE_DOUBLE_PI)) * 2.0 / 3.0;
	Result += (160.0 * FMath::Sin(LatitudeDelta / 12.0 * UE_DOUBLE_PI) + 320.0 * FMath::Sin(LatitudeDelta * UE_DOUBLE_PI / 30.0)) * 2.0 / 3.0;
	return Result;
}

double TransformLongitude(double LongitudeDelta, double LatitudeDelta)
{
	double Result = 300.0 + LongitudeDelta + 2.0 * LatitudeDelta + 0.1 * LongitudeDelta * LongitudeDelta + 0.1 * LongitudeDelta * LatitudeDelta + 0.1 * FMath::Sqrt(FMath::Abs(LongitudeDelta));
	Result += (20.0 * FMath::Sin(6.0 * LongitudeDelta * UE_DOUBLE_PI) + 20.0 * FMath::Sin(2.0 * LongitudeDelta * UE_DOUBLE_PI)) * 2.0 / 3.0;
	Result += (20.0 * FMath::Sin(LongitudeDelta * UE_DOUBLE_PI) + 40.0 * FMath::Sin(LongitudeDelta / 3.0 * UE_DOUBLE_PI)) * 2.0 / 3.0;
	Result += (150.0 * FMath::Sin(LongitudeDelta / 12.0 * UE_DOUBLE_PI) + 300.0 * FMath::Sin(LongitudeDelta / 30.0 * UE_DOUBLE_PI)) * 2.0 / 3.0;
	return Result;
}
}

namespace ChinaCoordinateOffset
{
bool IsOutsideChina(double Longitude, double Latitude)
{
	return Longitude < 72.004 || Longitude > 137.8347 || Latitude < 0.8293 || Latitude > 55.8271;
}

FGenericCoordinate WGS84ToGCJ02(const FGenericCoordinate& InCoordinate)
{
	if (IsOutsideChina(InCoordinate.CoordinateLon, InCoordinate.CoordinateLat))
	{
		return InCoordinate;
	}

	const double LatitudeRadians = FMath::DegreesToRadians(InCoordinate.CoordinateLat);
	const double Magic = 1.0 - KrasovskyEE * FMath::Sin(LatitudeRadians) * FMath::Sin(LatitudeRadians);
	const double SqrtMagic = FMath::Sqrt(Magic);
	double LatitudeDelta = TransformLatitude(InCoordinate.CoordinateLon - 105.0, InCoordinate.CoordinateLat - 35.0);
	double LongitudeDelta = TransformLongitude(InCoordinate.CoordinateLon - 105.0, InCoordinate.CoordinateLat - 35.0);
	LatitudeDelta = (LatitudeDelta * 180.0) / ((KrasovskyA * (1.0 - KrasovskyEE)) / (Magic * SqrtMagic) * UE_DOUBLE_PI);
	LongitudeDelta = (LongitudeDelta * 180.0) / (KrasovskyA / SqrtMagic * FMath::Cos(LatitudeRadians) * UE_DOUBLE_PI);

	FGenericCoordinate Coordinate = InCoordinate;
	Coordinate.CoordinateLat = InCoordinate.CoordinateLat + LatitudeDelta;
	Coordinate.CoordinateLon = InCoordinate.CoordinateLon + LongitudeDelta;
	return Coordinate;
}

FGenericCoordinate GCJ02ToWGS84(const FGenericCoordinate& InCoordinate)
{
	if (IsOutsideChina(InCoordinate.CoordinateLon, InCoordinate.CoordinateLat))
	{
		return InCoordinate;
	}

	const FGenericCoordinate OffsetCoordinate = WGS84ToGCJ02(InCoordinate);
	FGenericCoordinate Coordinate = InCoordinate;
	Coordinate.CoordinateLat = InCoordinate.CoordinateLat * 2.0 - OffsetCoordinate.CoordinateLat;
	Coordinate.CoordinateLon = InCoordinate.CoordinateLon * 2.0 - OffsetCoordinate.CoordinateLon;
	return Coordinate;
}

FGenericCoordinate GCJ02ToBD09(const FGenericCoordinate& InCoordinate)
{
	const double X = InCoordinate.CoordinateLon;
	const double Y = InCoordinate.CoordinateLat;
	const double Z = FMath::Sqrt(X * X + Y * Y) + 0.00002 * FMath::Sin(Y * BaiduXPi);
	const double Theta = FMath::Atan2(Y, X) + 0.000003 * FMath::Cos(X * BaiduXPi);

	FGenericCoordinate Coordinate = InCoordinate;
	Coordinate.CoordinateLon = Z * FMath::Cos(Theta) + 0.0065;
	Coordinate.CoordinateLat = Z * FMath::Sin(Theta) + 0.006;
	return Coordinate;
}

FGenericCoordinate BD09ToGCJ02(const FGenericCoordinate& InCoordinate)
{
	const double X = InCoordinate.CoordinateLon - 0.0065;
	const double Y = InCoordinate.CoordinateLat - 0.006;
	const double Z = FMath::Sqrt(X * X + Y * Y) - 0.00002 * FMath::Sin(Y * BaiduXPi);
	const double Theta = FMath::Atan2(Y, X) - 0.000003 * FMath::Cos(X * BaiduXPi);

	FGenericCoordinate Coordinate = InCoordinate;
	Coordinate.CoordinateLon = Z * FMath::Cos(Theta);
	Coordinate.CoordinateLat = Z * FMath::Sin(Theta);
	return Coordinate;
}
}
