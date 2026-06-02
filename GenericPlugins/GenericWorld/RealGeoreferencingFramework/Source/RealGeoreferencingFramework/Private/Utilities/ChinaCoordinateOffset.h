// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RealGeoreferencingType.h"

namespace ChinaCoordinateOffset
{
bool IsOutsideChina(double Longitude, double Latitude);
FGenericCoordinate WGS84ToGCJ02(const FGenericCoordinate& InCoordinate);
FGenericCoordinate GCJ02ToWGS84(const FGenericCoordinate& InCoordinate);
FGenericCoordinate GCJ02ToBD09(const FGenericCoordinate& InCoordinate);
FGenericCoordinate BD09ToGCJ02(const FGenericCoordinate& InCoordinate);
}
