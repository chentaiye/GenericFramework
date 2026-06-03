// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Utilities/GenericProjectionUtilities.h"

#include "HAL/FileManager.h"
#include "HAL/PlatformFileManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "proj.h"

namespace
{
constexpr double CentimetersPerMeter = 100.0;
const FString ECEFCRS(TEXT("EPSG:4978"));
const FString ProjectionWGS84CRS(TEXT("EPSG:4326"));
const FString ProjectionMercatorCRS(TEXT("EPSG:3857"));

static void GenericProjLog(void* AppData, int Level, const char* Message)
{
	FUTF8ToTCHAR MessageText(Message);
	switch (Level)
	{
	case PJ_LOG_ERROR:
		UE_LOG(LogTemp, Error, TEXT("RealGeoreferencing PROJ: %s"), MessageText.Get());
		break;
	case PJ_LOG_DEBUG:
		UE_LOG(LogTemp, Verbose, TEXT("RealGeoreferencing PROJ: %s"), MessageText.Get());
		break;
	case PJ_LOG_TRACE:
		UE_LOG(LogTemp, VeryVerbose, TEXT("RealGeoreferencing PROJ: %s"), MessageText.Get());
		break;
	default:
		break;
	}
}

class FGenericProjContext
{
public:
	FGenericProjContext()
	{
		ProjContext = proj_context_create();
		if (!ProjContext)
		{
			UE_LOG(LogTemp, Error, TEXT("RealGeoreferencing PROJ context creation failed."));
			return;
		}

		proj_log_func(ProjContext, nullptr, GenericProjLog);
		proj_log_level(ProjContext, PJ_LOG_TRACE);

		const TSharedPtr<IPlugin> GeoReferencingPlugin = IPluginManager::Get().FindPlugin(TEXT("GeoReferencing"));
		if (!GeoReferencingPlugin.IsValid())
		{
			UE_LOG(LogTemp, Error, TEXT("GeoReferencing plugin is not available for RealGeoreferencing."));
			return;
		}

		ProjDataPath = FPaths::Combine(*GeoReferencingPlugin->GetBaseDir(), TEXT("Resources/PROJ"));
		FTCHARToUTF8 UTF8ProjDataPath(*ProjDataPath);
		const char* ProjSearchPaths[] = { UTF8ProjDataPath.Get() };
		proj_context_set_search_paths(ProjContext, UE_ARRAY_COUNT(ProjSearchPaths), ProjSearchPaths);
		proj_context_set_autoclose_database(ProjContext, true);

		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		const FString ProjDBFilePath = FPaths::Combine(*ProjDataPath, TEXT("proj.db"));
		PlatformFile.SetReadOnly(*ProjDBFilePath, true);

		if (PlatformFile.IsSandboxEnabled())
		{
			const FString ProjDBSandboxPath = PlatformFile.ConvertToAbsolutePathForExternalAppForWrite(*ProjDBFilePath);
			if (!IFileManager::Get().FileExists(*ProjDBSandboxPath))
			{
				const FString TargetFolder = IFileManager::Get().ConvertToAbsolutePathForExternalAppForWrite(*ProjDataPath);
				PlatformFile.GetLowerLevel()->CreateDirectoryTree(*TargetFolder);
				PlatformFile.GetLowerLevel()->CopyDirectoryTree(*TargetFolder, *ProjDataPath, false);
				PlatformFile.SetReadOnly(*ProjDBSandboxPath, true);
			}
		}

	}

	~FGenericProjContext()
	{
		if (ProjContext)
		{
			proj_context_destroy(ProjContext);
			ProjContext = nullptr;
		}
	}

	PJ_CONTEXT* Get() const { return ProjContext; }

private:
	PJ_CONTEXT* ProjContext = nullptr;
	FString ProjDataPath;
};

FGenericProjContext& GetProjContext()
{
	static FGenericProjContext Context;
	return Context;
}

bool TransformMeters(const FString& SourceCRS, const FString& TargetCRS, const FVector& InMeters, FVector& OutMeters)
{
	PJ_CONTEXT* ProjContext = GetProjContext().Get();
	if (!ProjContext)
	{
		return false;
	}

	FTCHARToUTF8 SourceUTF8(*SourceCRS);
	FTCHARToUTF8 TargetUTF8(*TargetCRS);
	PJ* RawProjection = proj_create_crs_to_crs(ProjContext, SourceUTF8.Get(), TargetUTF8.Get(), nullptr);
	if (!RawProjection)
	{
		const int ErrorNumber = proj_context_errno(ProjContext);
		UE_LOG(LogTemp, Error, TEXT("RealGeoreferencing failed to create PROJ transform from '%s' to '%s': %s"), *SourceCRS, *TargetCRS, ANSI_TO_TCHAR(proj_errno_string(ErrorNumber)));
		return false;
	}

	PJ* Projection = proj_normalize_for_visualization(ProjContext, RawProjection);
	proj_destroy(RawProjection);
	if (!Projection)
	{
		const int ErrorNumber = proj_context_errno(ProjContext);
		UE_LOG(LogTemp, Error, TEXT("RealGeoreferencing failed to normalize PROJ transform from '%s' to '%s': %s"), *SourceCRS, *TargetCRS, ANSI_TO_TCHAR(proj_errno_string(ErrorNumber)));
		return false;
	}

	const PJ_COORD Input = proj_coord(InMeters.X, InMeters.Y, InMeters.Z, 0.0);
	const PJ_COORD Output = proj_trans(Projection, PJ_FWD, Input);
	proj_destroy(Projection);

	if (!FMath::IsFinite(Output.xyz.x) || !FMath::IsFinite(Output.xyz.y) || !FMath::IsFinite(Output.xyz.z))
	{
		UE_LOG(LogTemp, Error, TEXT("RealGeoreferencing PROJ transform produced non-finite output from '%s' to '%s'."), *SourceCRS, *TargetCRS);
		return false;
	}

	OutMeters = FVector(Output.xyz.x, Output.xyz.y, Output.xyz.z);
	return true;
}

FVector GeographicCentimetersToMeters(const FGenericCoordinate& InCoordinate)
{
	return FVector(InCoordinate.CoordinateLon, InCoordinate.CoordinateLat, InCoordinate.CoordinateAlt / CentimetersPerMeter);
}

FGenericCoordinate MetersToGeographicCentimeters(const FVector& InMeters)
{
	FGenericCoordinate Coordinate;
	Coordinate.CoordinateLon = InMeters.X;
	Coordinate.CoordinateLat = InMeters.Y;
	Coordinate.CoordinateAlt = InMeters.Z * CentimetersPerMeter;
	return Coordinate;
}

FVector ProjectedCentimetersToMeters(const FGenericProjectedCoordinate& InCoordinate)
{
	return FVector(
		InCoordinate.CoordinateX / CentimetersPerMeter,
		InCoordinate.CoordinateY / CentimetersPerMeter,
		InCoordinate.CoordinateZ / CentimetersPerMeter);
}

FGenericProjectedCoordinate MetersToProjectedCentimeters(const FVector& InMeters)
{
	FGenericProjectedCoordinate Coordinate;
	Coordinate.CoordinateX = InMeters.X * CentimetersPerMeter;
	Coordinate.CoordinateY = InMeters.Y * CentimetersPerMeter;
	Coordinate.CoordinateZ = InMeters.Z * CentimetersPerMeter;
	return Coordinate;
}

double ResolveGaussKrugerCentralMeridian(bool bUseZoneNumber, int32 ZoneNumber, bool bSixDegreeZone, double CentralMeridian)
{
	if (!bUseZoneNumber)
	{
		return CentralMeridian;
	}

	const int32 SafeZoneNumber = FMath::Max(ZoneNumber, 1);
	return bSixDegreeZone ? SafeZoneNumber * 6.0 - 3.0 : SafeZoneNumber * 3.0;
}
}

namespace GenericProjectionUtilities
{
bool GeographicToECEFCentimeters(const FString& GeographicCRS, const FGenericCoordinate& InCoordinate, FVector& OutECEFCentimeters)
{
	FVector ECEFMeters;
	if (!TransformMeters(GeographicCRS, ECEFCRS, GeographicCentimetersToMeters(InCoordinate), ECEFMeters))
	{
		return false;
	}

	OutECEFCentimeters = ECEFMeters * CentimetersPerMeter;
	return true;
}

bool ECEFCentimetersToGeographic(const FString& GeographicCRS, const FVector& InECEFCentimeters, FGenericCoordinate& OutCoordinate)
{
	FVector GeographicMeters;
	if (!TransformMeters(ECEFCRS, GeographicCRS, InECEFCentimeters / CentimetersPerMeter, GeographicMeters))
	{
		return false;
	}

	OutCoordinate = MetersToGeographicCentimeters(GeographicMeters);
	return true;
}

bool ProjectedToECEFCentimeters(const FString& ProjectedCRS, const FGenericProjectedCoordinate& InCoordinate, FVector& OutECEFCentimeters)
{
	FVector ECEFMeters;
	if (!TransformMeters(ProjectedCRS, ECEFCRS, ProjectedCentimetersToMeters(InCoordinate), ECEFMeters))
	{
		return false;
	}

	OutECEFCentimeters = ECEFMeters * CentimetersPerMeter;
	return true;
}

bool ECEFCentimetersToProjected(const FString& ProjectedCRS, const FVector& InECEFCentimeters, FGenericProjectedCoordinate& OutCoordinate)
{
	FVector ProjectedMeters;
	if (!TransformMeters(ECEFCRS, ProjectedCRS, InECEFCentimeters / CentimetersPerMeter, ProjectedMeters))
	{
		return false;
	}

	OutCoordinate = MetersToProjectedCentimeters(ProjectedMeters);
	return true;
}

bool ProjectionSettingsToECEFCentimeters(const FGenericProjectionSettings& ProjectionSettings, const FGenericProjectedCoordinate& InCoordinate, FVector& OutECEFCentimeters)
{
	return ProjectedToECEFCentimeters(BuildProjectionCRSString(ProjectionSettings), InCoordinate, OutECEFCentimeters);
}

bool ECEFCentimetersToProjectionSettings(const FGenericProjectionSettings& ProjectionSettings, const FVector& InECEFCentimeters, FGenericProjectedCoordinate& OutCoordinate)
{
	return ECEFCentimetersToProjected(BuildProjectionCRSString(ProjectionSettings), InECEFCentimeters, OutCoordinate);
}

FString BuildProjectionCRSString(const FGenericProjectionSettings& ProjectionSettings)
{
	switch (ProjectionSettings.ProjectedCrsType)
	{
	case EGenericProjectedCrsType::UTM:
		return BuildUTMCRSString(ProjectionSettings.UTMZone, ProjectionSettings.bUTMSouthernHemisphere);
	case EGenericProjectedCrsType::Mercator:
		return ProjectionMercatorCRS;
	case EGenericProjectedCrsType::GaussKruger:
		return BuildGaussKrugerCRSString(
			ProjectionSettings.bGaussKrugerUseZoneNumber,
			ProjectionSettings.GaussKrugerZoneNumber,
			ProjectionSettings.bGaussKrugerSixDegreeZone,
			ProjectionSettings.GaussKrugerCentralMeridian,
			ProjectionSettings.GaussKrugerFalseEasting,
			ProjectionSettings.GaussKrugerFalseNorthing,
			ProjectionSettings.GaussKrugerScaleFactor);
	case EGenericProjectedCrsType::Custom:
	{
		const FString CustomCRS = ProjectionSettings.CustomCrsString.TrimStartAndEnd();
		return CustomCRS.IsEmpty() ? ProjectionMercatorCRS : CustomCRS;
	}
	default:
		return ProjectionMercatorCRS;
	}
}

FString BuildUTMCRSString(int32 Zone, bool bSouthernHemisphere)
{
	const int32 SafeZone = FMath::Clamp(Zone, 1, 60);
	return FString::Printf(TEXT("EPSG:%d"), (bSouthernHemisphere ? 32700 : 32600) + SafeZone);
}

FString BuildGaussKrugerCRSString(bool bUseZoneNumber, int32 ZoneNumber, bool bSixDegreeZone, double CentralMeridian, double FalseEasting, double FalseNorthing, double ScaleFactor)
{
	const double SafeScaleFactor = FMath::Max(ScaleFactor, 0.000001);
	const double ResolvedCentralMeridian = ResolveGaussKrugerCentralMeridian(bUseZoneNumber, ZoneNumber, bSixDegreeZone, CentralMeridian);
	return FString::Printf(
		TEXT("+proj=tmerc +lat_0=0 +lon_0=%.12f +k=%.12f +x_0=%.12f +y_0=%.12f +ellps=GRS80 +units=m +no_defs"),
		ResolvedCentralMeridian,
		SafeScaleFactor,
		FalseEasting / CentimetersPerMeter,
		FalseNorthing / CentimetersPerMeter);
}
}
