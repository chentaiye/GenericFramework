// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Setting/RealGeoreferencingWorldSettings.h"

#include "Converter/BD09CoordinateConverter.h"
#include "Converter/CGCS2000CoordinateConverter.h"
#include "Converter/GCJ02CoordinateConverter.h"
#include "Converter/GaussKrugerCoordinateConverter.h"
#include "Converter/MercatorCoordinateConverter.h"
#include "Converter/UTMCoordinateConverter.h"
#include "Converter/WGS84CoordinateConverter.h"
#include "Subsystem/RealGeoreferencingSubsystem.h"

URealGeoreferencingWorldSettings::URealGeoreferencingWorldSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GenericCoordinateConverterClasses.AddUnique(UWGS84CoordinateConverter::StaticClass());
	GenericCoordinateConverterClasses.AddUnique(UGCJ02CoordinateConverter::StaticClass());
	GenericCoordinateConverterClasses.AddUnique(UBD09CoordinateConverter::StaticClass());
	GenericCoordinateConverterClasses.AddUnique(UCGCS2000CoordinateConverter::StaticClass());
	GenericCoordinateConverterClasses.AddUnique(UUTMCoordinateConverter::StaticClass());
	GenericCoordinateConverterClasses.AddUnique(UMercatorCoordinateConverter::StaticClass());
	GenericCoordinateConverterClasses.AddUnique(UGaussKrugerCoordinateConverter::StaticClass());
}

#if WITH_EDITOR
FName URealGeoreferencingWorldSettings::GetSettingsCategory_Implementation() const
{
	return FName(TEXT("World"));
}
#endif

void URealGeoreferencingWorldSettings::OnWorldSettingsBeginPlay_Implementation(UWorld* World)
{
	Super::OnWorldSettingsBeginPlay_Implementation(World);

	if (!World)
	{
		return;
	}

	if (URealGeoreferencingSubsystem* GeoreferencingSubsystem = URealGeoreferencingSubsystem::Get(World))
	{
		GeoreferencingSubsystem->ApplyWorldSettings(this);
	}
}
