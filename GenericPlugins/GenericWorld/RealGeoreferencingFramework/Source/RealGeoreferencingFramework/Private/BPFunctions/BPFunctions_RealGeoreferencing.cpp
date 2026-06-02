// Copyright ChenTaiye 2025. All Rights Reserved.

#include "BPFunctions/BPFunctions_RealGeoreferencing.h"

#include "Subsystem/RealGeoreferencingSubsystem.h"

namespace
{
FGenericRealCoordinate MakeGeographicRealCoordinate(FGameplayTag CoordinateSystem, const FGenericCoordinate& Coordinate)
{
	FGenericRealCoordinate RealCoordinate;
	RealCoordinate.CoordinateSystem = CoordinateSystem;
	RealCoordinate.CoordinateFormat = EGenericCoordinateFormat::Geographic;
	RealCoordinate.GeographicCoordinate = Coordinate;
	return RealCoordinate;
}

FGenericRealCoordinate MakeProjectedRealCoordinate(FGameplayTag CoordinateSystem, const FGenericProjectedCoordinate& Coordinate)
{
	FGenericRealCoordinate RealCoordinate;
	RealCoordinate.CoordinateSystem = CoordinateSystem;
	RealCoordinate.CoordinateFormat = EGenericCoordinateFormat::Projected;
	RealCoordinate.ProjectedCoordinate = Coordinate;
	return RealCoordinate;
}
}

bool UBPFunctions_RealGeoreferencing::RealCoordinateToUnreal(const UObject* WorldContextObject, const FGenericRealCoordinate& InRealCoordinate, FVector& OutLocation)
{
	if (const URealGeoreferencingSubsystem* GeoreferencingSubsystem = URealGeoreferencingSubsystem::Get(WorldContextObject))
	{
		return GeoreferencingSubsystem->RealCoordinateToUnreal(InRealCoordinate, OutLocation);
	}

	return false;
}

bool UBPFunctions_RealGeoreferencing::UnrealToRealCoordinate(const UObject* WorldContextObject, FGameplayTag TargetCoordinateSystem, EGenericCoordinateFormat TargetFormat, const FVector& InLocation, FGenericRealCoordinate& OutRealCoordinate)
{
	if (const URealGeoreferencingSubsystem* GeoreferencingSubsystem = URealGeoreferencingSubsystem::Get(WorldContextObject))
	{
		return GeoreferencingSubsystem->UnrealToRealCoordinate(TargetCoordinateSystem, TargetFormat, InLocation, OutRealCoordinate);
	}

	return false;
}

bool UBPFunctions_RealGeoreferencing::RealCoordinateToRealCoordinate(const UObject* WorldContextObject, const FGenericRealCoordinate& InRealCoordinate, FGameplayTag TargetCoordinateSystem, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutRealCoordinate)
{
	if (const URealGeoreferencingSubsystem* GeoreferencingSubsystem = URealGeoreferencingSubsystem::Get(WorldContextObject))
	{
		return GeoreferencingSubsystem->RealCoordinateToRealCoordinate(InRealCoordinate, TargetCoordinateSystem, TargetFormat, OutRealCoordinate);
	}

	return false;
}

bool UBPFunctions_RealGeoreferencing::GeographicCoordinateToUnreal(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericCoordinate& InCoordinate, FVector& OutLocation)
{
	return RealCoordinateToUnreal(WorldContextObject, MakeGeographicRealCoordinate(SourceCoordinateSystem, InCoordinate), OutLocation);
}

bool UBPFunctions_RealGeoreferencing::ProjectedCoordinateToUnreal(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericProjectedCoordinate& InCoordinate, FVector& OutLocation)
{
	return RealCoordinateToUnreal(WorldContextObject, MakeProjectedRealCoordinate(SourceCoordinateSystem, InCoordinate), OutLocation);
}

bool UBPFunctions_RealGeoreferencing::UnrealToGeographicCoordinate(const UObject* WorldContextObject, FGameplayTag TargetCoordinateSystem, const FVector& InLocation, FGenericCoordinate& OutCoordinate)
{
	FGenericRealCoordinate RealCoordinate;
	if (!UnrealToRealCoordinate(WorldContextObject, TargetCoordinateSystem, EGenericCoordinateFormat::Geographic, InLocation, RealCoordinate))
	{
		return false;
	}

	OutCoordinate = RealCoordinate.GeographicCoordinate;
	return true;
}

bool UBPFunctions_RealGeoreferencing::UnrealToProjectedCoordinate(const UObject* WorldContextObject, FGameplayTag TargetCoordinateSystem, const FVector& InLocation, FGenericProjectedCoordinate& OutCoordinate)
{
	FGenericRealCoordinate RealCoordinate;
	if (!UnrealToRealCoordinate(WorldContextObject, TargetCoordinateSystem, EGenericCoordinateFormat::Projected, InLocation, RealCoordinate))
	{
		return false;
	}

	OutCoordinate = RealCoordinate.ProjectedCoordinate;
	return true;
}

bool UBPFunctions_RealGeoreferencing::GeographicCoordinateToGeographicCoordinate(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, FGenericCoordinate& OutCoordinate)
{
	FGenericRealCoordinate RealCoordinate;
	if (!RealCoordinateToRealCoordinate(WorldContextObject, MakeGeographicRealCoordinate(SourceCoordinateSystem, InCoordinate), TargetCoordinateSystem, EGenericCoordinateFormat::Geographic, RealCoordinate))
	{
		return false;
	}

	OutCoordinate = RealCoordinate.GeographicCoordinate;
	return true;
}

bool UBPFunctions_RealGeoreferencing::GeographicCoordinateToProjectedCoordinate(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, FGenericProjectedCoordinate& OutCoordinate)
{
	FGenericRealCoordinate RealCoordinate;
	if (!RealCoordinateToRealCoordinate(WorldContextObject, MakeGeographicRealCoordinate(SourceCoordinateSystem, InCoordinate), TargetCoordinateSystem, EGenericCoordinateFormat::Projected, RealCoordinate))
	{
		return false;
	}

	OutCoordinate = RealCoordinate.ProjectedCoordinate;
	return true;
}

bool UBPFunctions_RealGeoreferencing::ProjectedCoordinateToGeographicCoordinate(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericProjectedCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, FGenericCoordinate& OutCoordinate)
{
	FGenericRealCoordinate RealCoordinate;
	if (!RealCoordinateToRealCoordinate(WorldContextObject, MakeProjectedRealCoordinate(SourceCoordinateSystem, InCoordinate), TargetCoordinateSystem, EGenericCoordinateFormat::Geographic, RealCoordinate))
	{
		return false;
	}

	OutCoordinate = RealCoordinate.GeographicCoordinate;
	return true;
}

bool UBPFunctions_RealGeoreferencing::ProjectedCoordinateToProjectedCoordinate(const UObject* WorldContextObject, FGameplayTag SourceCoordinateSystem, const FGenericProjectedCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, FGenericProjectedCoordinate& OutCoordinate)
{
	FGenericRealCoordinate RealCoordinate;
	if (!RealCoordinateToRealCoordinate(WorldContextObject, MakeProjectedRealCoordinate(SourceCoordinateSystem, InCoordinate), TargetCoordinateSystem, EGenericCoordinateFormat::Projected, RealCoordinate))
	{
		return false;
	}

	OutCoordinate = RealCoordinate.ProjectedCoordinate;
	return true;
}
