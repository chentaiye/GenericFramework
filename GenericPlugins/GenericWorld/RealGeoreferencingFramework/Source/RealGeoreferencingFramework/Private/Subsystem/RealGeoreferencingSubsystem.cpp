// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/RealGeoreferencingSubsystem.h"

#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Setting/RealGeoreferencingWorldSettings.h"
#include "Utilities/GenericProjectionUtilities.h"

namespace
{
constexpr double MinCoordinateScale = 0.000001;
}

URealGeoreferencingSubsystem* URealGeoreferencingSubsystem::Get(const UObject* WorldContextObject)
{
	if (!GEngine)
	{
		return nullptr;
	}

	const UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World)
	{
		return nullptr;
	}

	UGameInstance* GameInstance = World->GetGameInstance();
	return GameInstance ? GameInstance->GetSubsystem<URealGeoreferencingSubsystem>() : nullptr;
}

void URealGeoreferencingSubsystem::ApplyWorldSettings(const URealGeoreferencingWorldSettings* Settings)
{
	RegisteredConverters.Reset();
	ActiveConverter = nullptr;
	ActiveCoordinateSystem = FGameplayTag();
	ActiveCoordinateScale = 1.0;
	ActiveCenterCoordinateSystem = TAG_GameplayGeoreferencing_CoordinateSystem_WGS84;
	ActiveCenterCoordinate = FGenericCoordinate();
	ActiveUnrealProjectionSettings = FGenericProjectionSettings();
	ActiveUnrealProjectionCenter = FGenericProjectedCoordinate();
	bHasValidUnrealProjectionCenter = false;

	if (!Settings)
	{
		return;
	}

	ActiveCoordinateScale = FMath::Max(Settings->CoordinateScale, MinCoordinateScale);
	ActiveCenterCoordinateSystem = Settings->CenterCoordinateSystem;
	ActiveCenterCoordinate = Settings->CenterCoordinate;
	ActiveUnrealProjectionSettings = Settings->UnrealProjectionSettings;

	RegisterConverters(Settings->GenericCoordinateConverterClasses);
	if (Settings->GenericCoordinateConverterClass)
	{
		SetActiveConverter(Settings->GenericCoordinateConverterClass);
	}

	const UGenericCoordinateConverter* CenterConverter = GetConverter(ActiveCenterCoordinateSystem);
	if (!CenterConverter)
	{
		UE_LOG(LogTemp, Warning, TEXT("RealGeoreferencing failed to resolve center coordinate converter: %s"), *ActiveCenterCoordinateSystem.ToString());
		return;
	}

	FGenericRealCoordinate CenterRealCoordinate;
	CenterRealCoordinate.CoordinateSystem = ActiveCenterCoordinateSystem;
	CenterRealCoordinate.CoordinateFormat = EGenericCoordinateFormat::Geographic;
	CenterRealCoordinate.GeographicCoordinate = ActiveCenterCoordinate;

	FVector CenterECEFCentimeters;
	if (!CenterConverter->RealCoordinateToECEF(CenterRealCoordinate, CenterECEFCentimeters))
	{
		UE_LOG(LogTemp, Warning, TEXT("RealGeoreferencing failed to convert center coordinate to ECEF."));
		return;
	}

	bHasValidUnrealProjectionCenter = GenericProjectionUtilities::ECEFCentimetersToProjectionSettings(
		ActiveUnrealProjectionSettings,
		CenterECEFCentimeters,
		ActiveUnrealProjectionCenter);
}

bool URealGeoreferencingSubsystem::RegisterConverter(TSubclassOf<UGenericCoordinateConverter> ConverterClass)
{
	if (!ConverterClass || ConverterClass->HasAnyClassFlags(CLASS_Abstract))
	{
		return false;
	}

	UGenericCoordinateConverter* Converter = NewObject<UGenericCoordinateConverter>(this, ConverterClass);
	if (!Converter)
	{
		return false;
	}

	const FGameplayTag CoordinateSystem = Converter->GetCoordinateSystem();
	if (!CoordinateSystem.IsValid()
		|| CoordinateSystem == TAG_GameplayGeoreferencing_CoordinateSystem
		|| !CoordinateSystem.MatchesTag(TAG_GameplayGeoreferencing_CoordinateSystem))
	{
		return false;
	}

	RegisteredConverters.Add(CoordinateSystem, Converter);
	return true;
}

void URealGeoreferencingSubsystem::RegisterConverters(const TArray<TSubclassOf<UGenericCoordinateConverter>>& ConverterClasses)
{
	for (const TSubclassOf<UGenericCoordinateConverter>& ConverterClass : ConverterClasses)
	{
		RegisterConverter(ConverterClass);
	}
}

bool URealGeoreferencingSubsystem::UnregisterConverter(FGameplayTag CoordinateSystem)
{
	if (!CoordinateSystem.IsValid())
	{
		return false;
	}

	if (ActiveCoordinateSystem == CoordinateSystem)
	{
		ActiveConverter = nullptr;
		ActiveCoordinateSystem = FGameplayTag();
	}

	return RegisteredConverters.Remove(CoordinateSystem) > 0;
}

UGenericCoordinateConverter* URealGeoreferencingSubsystem::GetConverter(FGameplayTag CoordinateSystem) const
{
	if (const TObjectPtr<UGenericCoordinateConverter>* Converter = RegisteredConverters.Find(CoordinateSystem))
	{
		return Converter->Get();
	}

	return nullptr;
}

UGenericCoordinateConverter* URealGeoreferencingSubsystem::GetActiveConverter() const
{
	return ActiveConverter.Get();
}

bool URealGeoreferencingSubsystem::SetActiveConverter(TSubclassOf<UGenericCoordinateConverter> ConverterClass)
{
	if (!RegisterConverter(ConverterClass))
	{
		return false;
	}

	const UGenericCoordinateConverter* DefaultConverter = ConverterClass->GetDefaultObject<UGenericCoordinateConverter>();
	return DefaultConverter ? SetActiveCoordinateSystem(DefaultConverter->GetCoordinateSystem()) : false;
}

FGameplayTag URealGeoreferencingSubsystem::GetActiveCoordinateSystem() const
{
	return ActiveCoordinateSystem;
}

bool URealGeoreferencingSubsystem::SetActiveCoordinateSystem(FGameplayTag CoordinateSystem)
{
	UGenericCoordinateConverter* Converter = GetConverter(CoordinateSystem);
	if (!Converter)
	{
		return false;
	}

	ActiveConverter = Converter;
	ActiveCoordinateSystem = CoordinateSystem;
	return true;
}

double URealGeoreferencingSubsystem::GetActiveCoordinateScale() const
{
	return ActiveCoordinateScale;
}

FGameplayTag URealGeoreferencingSubsystem::GetActiveCenterCoordinateSystem() const
{
	return ActiveCenterCoordinateSystem;
}

const FGenericCoordinate& URealGeoreferencingSubsystem::GetActiveCenterCoordinate() const
{
	return ActiveCenterCoordinate;
}

const FGenericProjectionSettings& URealGeoreferencingSubsystem::GetActiveUnrealProjectionSettings() const
{
	return ActiveUnrealProjectionSettings;
}

bool URealGeoreferencingSubsystem::RealCoordinateToUnreal(const FGenericRealCoordinate& InCoordinate, FVector& OutLocation) const
{
	if (!bHasValidUnrealProjectionCenter)
	{
		return false;
	}

	const UGenericCoordinateConverter* SourceConverter = GetConverter(InCoordinate.CoordinateSystem);
	if (!SourceConverter)
	{
		return false;
	}

	FVector SourceECEFCentimeters;
	if (!SourceConverter->RealCoordinateToECEF(InCoordinate, SourceECEFCentimeters))
	{
		return false;
	}

	FGenericProjectedCoordinate ProjectedCoordinate;
	if (!GenericProjectionUtilities::ECEFCentimetersToProjectionSettings(ActiveUnrealProjectionSettings, SourceECEFCentimeters, ProjectedCoordinate))
	{
		return false;
	}

	OutLocation.X = (ProjectedCoordinate.CoordinateX - ActiveUnrealProjectionCenter.CoordinateX) * ActiveCoordinateScale;
	OutLocation.Y = (ProjectedCoordinate.CoordinateY - ActiveUnrealProjectionCenter.CoordinateY) * ActiveCoordinateScale;
	OutLocation.Z = ProjectedCoordinate.CoordinateZ * ActiveCoordinateScale;
	return true;
}

bool URealGeoreferencingSubsystem::UnrealToRealCoordinate(FGameplayTag TargetCoordinateSystem, EGenericCoordinateFormat TargetFormat, const FVector& InLocation, FGenericRealCoordinate& OutCoordinate) const
{
	if (!bHasValidUnrealProjectionCenter || ActiveCoordinateScale <= 0.0)
	{
		return false;
	}

	const UGenericCoordinateConverter* TargetConverter = GetConverter(TargetCoordinateSystem);
	if (!TargetConverter)
	{
		return false;
	}

	FGenericProjectedCoordinate ProjectedCoordinate;
	ProjectedCoordinate.CoordinateX = InLocation.X / ActiveCoordinateScale + ActiveUnrealProjectionCenter.CoordinateX;
	ProjectedCoordinate.CoordinateY = InLocation.Y / ActiveCoordinateScale + ActiveUnrealProjectionCenter.CoordinateY;
	ProjectedCoordinate.CoordinateZ = InLocation.Z / ActiveCoordinateScale;

	FVector TargetECEFCentimeters;
	if (!GenericProjectionUtilities::ProjectionSettingsToECEFCentimeters(ActiveUnrealProjectionSettings, ProjectedCoordinate, TargetECEFCentimeters))
	{
		return false;
	}

	return TargetConverter->ECEFToRealCoordinate(TargetECEFCentimeters, TargetFormat, OutCoordinate);
}

bool URealGeoreferencingSubsystem::RealCoordinateToRealCoordinate(const FGenericRealCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, EGenericCoordinateFormat TargetFormat, FGenericRealCoordinate& OutCoordinate) const
{
	const UGenericCoordinateConverter* SourceConverter = GetConverter(InCoordinate.CoordinateSystem);
	const UGenericCoordinateConverter* TargetConverter = GetConverter(TargetCoordinateSystem);
	if (!SourceConverter || !TargetConverter)
	{
		return false;
	}

	FVector ECEFCentimeters;
	if (!SourceConverter->RealCoordinateToECEF(InCoordinate, ECEFCentimeters))
	{
		return false;
	}

	return TargetConverter->ECEFToRealCoordinate(ECEFCentimeters, TargetFormat, OutCoordinate);
}

bool URealGeoreferencingSubsystem::RealCoordinateToUnreal(FGameplayTag SourceCoordinateSystem, const FGenericCoordinate& InCoordinate, FVector& OutLocation) const
{
	FGenericRealCoordinate RealCoordinate;
	RealCoordinate.CoordinateSystem = SourceCoordinateSystem;
	RealCoordinate.CoordinateFormat = EGenericCoordinateFormat::Geographic;
	RealCoordinate.GeographicCoordinate = InCoordinate;
	return RealCoordinateToUnreal(RealCoordinate, OutLocation);
}

bool URealGeoreferencingSubsystem::UnrealToRealCoordinate(FGameplayTag TargetCoordinateSystem, const FVector& InLocation, FGenericCoordinate& OutCoordinate) const
{
	FGenericRealCoordinate RealCoordinate;
	if (!UnrealToRealCoordinate(TargetCoordinateSystem, EGenericCoordinateFormat::Geographic, InLocation, RealCoordinate))
	{
		return false;
	}

	OutCoordinate = RealCoordinate.GeographicCoordinate;
	return true;
}

bool URealGeoreferencingSubsystem::RealCoordinateToRealCoordinate(FGameplayTag SourceCoordinateSystem, const FGenericCoordinate& InCoordinate, FGameplayTag TargetCoordinateSystem, FGenericCoordinate& OutCoordinate) const
{
	FGenericRealCoordinate SourceCoordinate;
	SourceCoordinate.CoordinateSystem = SourceCoordinateSystem;
	SourceCoordinate.CoordinateFormat = EGenericCoordinateFormat::Geographic;
	SourceCoordinate.GeographicCoordinate = InCoordinate;

	FGenericRealCoordinate TargetCoordinate;
	if (!RealCoordinateToRealCoordinate(SourceCoordinate, TargetCoordinateSystem, EGenericCoordinateFormat::Geographic, TargetCoordinate))
	{
		return false;
	}

	OutCoordinate = TargetCoordinate.GeographicCoordinate;
	return true;
}
