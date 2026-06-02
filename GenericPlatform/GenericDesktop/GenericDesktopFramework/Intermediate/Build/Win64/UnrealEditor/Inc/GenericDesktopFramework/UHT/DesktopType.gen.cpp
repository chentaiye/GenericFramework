// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Type/DesktopType.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDesktopType() {}

// ********** Begin Cross Module References ********************************************************
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState();
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode();
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation();
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat();
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType();
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus();
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopApplicationInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopBytesResult();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopCPUInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopDialogResult();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopDiskInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopDisplayInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopGPUInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopHardwareSnapshot();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopMainWindowInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopMemoryInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopMonitorInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopNetworkInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopPowerInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopStringResult();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopSystemPathInfo();
UPackage* Z_Construct_UPackage__Script_GenericDesktopFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EDesktopImageFormat *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDesktopImageFormat;
static UEnum* EDesktopImageFormat_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDesktopImageFormat.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDesktopImageFormat.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("EDesktopImageFormat"));
	}
	return Z_Registration_Info_UEnum_EDesktopImageFormat.OuterSingleton;
}
template<> GENERICDESKTOPFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDesktopImageFormat>()
{
	return EDesktopImageFormat_StaticEnum();
}
struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "BMP.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""BMP\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "BMP.Name", "EDesktopImageFormat::BMP" },
		{ "BMP.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""BMP\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe5\x9b\xbe\xe5\x83\x8f\xe6\xa0\xbc\xe5\xbc\x8f\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "DDS.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""DDS\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "DDS.Name", "EDesktopImageFormat::DDS" },
		{ "DDS.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""DDS\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "EXR.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaXR\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "EXR.Name", "EDesktopImageFormat::EXR" },
		{ "EXR.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaXR\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "GrayscaleJPEG.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\x81\xb0\xe5\xba\xa6JPEG\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "GrayscaleJPEG.Name", "EDesktopImageFormat::GrayscaleJPEG" },
		{ "GrayscaleJPEG.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\x81\xb0\xe5\xba\xa6JPEG\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "GrayscaleUEJPEG.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\x81\xb0\xe5\xba\xa6UEJPEG\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "GrayscaleUEJPEG.Name", "EDesktopImageFormat::GrayscaleUEJPEG" },
		{ "GrayscaleUEJPEG.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\x81\xb0\xe5\xba\xa6UEJPEG\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "HDR.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaHDR\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "HDR.Name", "EDesktopImageFormat::HDR" },
		{ "HDR.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaHDR\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ICNS.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""CNS\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ICNS.Name", "EDesktopImageFormat::ICNS" },
		{ "ICNS.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""CNS\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ICO.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""CO\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ICO.Name", "EDesktopImageFormat::ICO" },
		{ "ICO.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""CO\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "Invalid.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x97\xa0\xe6\x95\x88\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Invalid.Name", "EDesktopImageFormat::Invalid" },
		{ "Invalid.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x97\xa0\xe6\x95\x88\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "JPEG.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaJPEG\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "JPEG.Name", "EDesktopImageFormat::JPEG" },
		{ "JPEG.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaJPEG\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
		{ "PNG.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaPNG\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "PNG.Name", "EDesktopImageFormat::PNG" },
		{ "PNG.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaPNG\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "TGA.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaTGA\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "TGA.Name", "EDesktopImageFormat::TGA" },
		{ "TGA.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaTGA\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "TIFF.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaTIFF\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "TIFF.Name", "EDesktopImageFormat::TIFF" },
		{ "TIFF.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaTIFF\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe5\x9b\xbe\xe5\x83\x8f\xe6\xa0\xbc\xe5\xbc\x8f\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "UEJPEG.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""EJPEG\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "UEJPEG.Name", "EDesktopImageFormat::UEJPEG" },
		{ "UEJPEG.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""EJPEG\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDesktopImageFormat::Invalid", (int64)EDesktopImageFormat::Invalid },
		{ "EDesktopImageFormat::PNG", (int64)EDesktopImageFormat::PNG },
		{ "EDesktopImageFormat::JPEG", (int64)EDesktopImageFormat::JPEG },
		{ "EDesktopImageFormat::GrayscaleJPEG", (int64)EDesktopImageFormat::GrayscaleJPEG },
		{ "EDesktopImageFormat::BMP", (int64)EDesktopImageFormat::BMP },
		{ "EDesktopImageFormat::ICO", (int64)EDesktopImageFormat::ICO },
		{ "EDesktopImageFormat::EXR", (int64)EDesktopImageFormat::EXR },
		{ "EDesktopImageFormat::ICNS", (int64)EDesktopImageFormat::ICNS },
		{ "EDesktopImageFormat::TGA", (int64)EDesktopImageFormat::TGA },
		{ "EDesktopImageFormat::HDR", (int64)EDesktopImageFormat::HDR },
		{ "EDesktopImageFormat::TIFF", (int64)EDesktopImageFormat::TIFF },
		{ "EDesktopImageFormat::DDS", (int64)EDesktopImageFormat::DDS },
		{ "EDesktopImageFormat::UEJPEG", (int64)EDesktopImageFormat::UEJPEG },
		{ "EDesktopImageFormat::GrayscaleUEJPEG", (int64)EDesktopImageFormat::GrayscaleUEJPEG },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	"EDesktopImageFormat",
	"EDesktopImageFormat",
	Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat()
{
	if (!Z_Registration_Info_UEnum_EDesktopImageFormat.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDesktopImageFormat.InnerSingleton, Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDesktopImageFormat.InnerSingleton;
}
// ********** End Enum EDesktopImageFormat *********************************************************

// ********** Begin Enum EDesktopTextEncodingOptions ***********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDesktopTextEncodingOptions;
static UEnum* EDesktopTextEncodingOptions_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDesktopTextEncodingOptions.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDesktopTextEncodingOptions.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("EDesktopTextEncodingOptions"));
	}
	return Z_Registration_Info_UEnum_EDesktopTextEncodingOptions.OuterSingleton;
}
template<> GENERICDESKTOPFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDesktopTextEncodingOptions>()
{
	return EDesktopTextEncodingOptions_StaticEnum();
}
struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AutoDetect.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\x87\xaa\xe5\x8a\xa8\xe6\xa3\x80\xe6\xb5\x8b\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "AutoDetect.Name", "EDesktopTextEncodingOptions::AutoDetect" },
		{ "AutoDetect.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\x87\xaa\xe5\x8a\xa8\xe6\xa3\x80\xe6\xb5\x8b\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe6\x96\x87\xe6\x9c\xac\xe7\xbc\x96\xe7\xa0\x81\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "ForceAnsi.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\xbc\xba\xe5\x88\xb6""ANSI\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ForceAnsi.Name", "EDesktopTextEncodingOptions::ForceAnsi" },
		{ "ForceAnsi.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\xbc\xba\xe5\x88\xb6""ANSI\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ForceUnicode.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\xbc\xba\xe5\x88\xb6Unicode\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ForceUnicode.Name", "EDesktopTextEncodingOptions::ForceUnicode" },
		{ "ForceUnicode.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\xbc\xba\xe5\x88\xb6Unicode\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ForceUTF8.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\xbc\xba\xe5\x88\xb6UTF 8\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ForceUTF8.Name", "EDesktopTextEncodingOptions::ForceUTF8" },
		{ "ForceUTF8.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\xbc\xba\xe5\x88\xb6UTF 8\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ForceUTF8WithoutBOM.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\xbc\xba\xe5\x88\xb6UTF 8\xe4\xb8\x8d\xe5\xb8\xa6""BOM\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ForceUTF8WithoutBOM.Name", "EDesktopTextEncodingOptions::ForceUTF8WithoutBOM" },
		{ "ForceUTF8WithoutBOM.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\xbc\xba\xe5\x88\xb6UTF 8\xe4\xb8\x8d\xe5\xb8\xa6""BOM\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe6\x96\x87\xe6\x9c\xac\xe7\xbc\x96\xe7\xa0\x81\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDesktopTextEncodingOptions::AutoDetect", (int64)EDesktopTextEncodingOptions::AutoDetect },
		{ "EDesktopTextEncodingOptions::ForceAnsi", (int64)EDesktopTextEncodingOptions::ForceAnsi },
		{ "EDesktopTextEncodingOptions::ForceUnicode", (int64)EDesktopTextEncodingOptions::ForceUnicode },
		{ "EDesktopTextEncodingOptions::ForceUTF8", (int64)EDesktopTextEncodingOptions::ForceUTF8 },
		{ "EDesktopTextEncodingOptions::ForceUTF8WithoutBOM", (int64)EDesktopTextEncodingOptions::ForceUTF8WithoutBOM },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	"EDesktopTextEncodingOptions",
	"EDesktopTextEncodingOptions",
	Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions()
{
	if (!Z_Registration_Info_UEnum_EDesktopTextEncodingOptions.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDesktopTextEncodingOptions.InnerSingleton, Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDesktopTextEncodingOptions.InnerSingleton;
}
// ********** End Enum EDesktopTextEncodingOptions *************************************************

// ********** Begin Enum EDesktopBatteryState ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDesktopBatteryState;
static UEnum* EDesktopBatteryState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDesktopBatteryState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDesktopBatteryState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("EDesktopBatteryState"));
	}
	return Z_Registration_Info_UEnum_EDesktopBatteryState.OuterSingleton;
}
template<> GENERICDESKTOPFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDesktopBatteryState>()
{
	return EDesktopBatteryState_StaticEnum();
}
struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Charging.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x85\x85\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Charging.Name", "EDesktopBatteryState::Charging" },
		{ "Charging.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x85\x85\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xb5\xe6\xb1\xa0\xe7\x8a\xb6\xe6\x80\x81\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "Discharging.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x94\xbe\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Discharging.Name", "EDesktopBatteryState::Discharging" },
		{ "Discharging.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x94\xbe\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "Full.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xbb\xa1\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Full.Name", "EDesktopBatteryState::Full" },
		{ "Full.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xbb\xa1\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
		{ "NoBattery.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x97\xa0\xe7\x94\xb5\xe6\xb1\xa0\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "NoBattery.Name", "EDesktopBatteryState::NoBattery" },
		{ "NoBattery.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x97\xa0\xe7\x94\xb5\xe6\xb1\xa0\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xb5\xe6\xb1\xa0\xe7\x8a\xb6\xe6\x80\x81\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Unknown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Unknown.Name", "EDesktopBatteryState::Unknown" },
		{ "Unknown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDesktopBatteryState::Unknown", (int64)EDesktopBatteryState::Unknown },
		{ "EDesktopBatteryState::NoBattery", (int64)EDesktopBatteryState::NoBattery },
		{ "EDesktopBatteryState::Charging", (int64)EDesktopBatteryState::Charging },
		{ "EDesktopBatteryState::Discharging", (int64)EDesktopBatteryState::Discharging },
		{ "EDesktopBatteryState::Full", (int64)EDesktopBatteryState::Full },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	"EDesktopBatteryState",
	"EDesktopBatteryState",
	Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState()
{
	if (!Z_Registration_Info_UEnum_EDesktopBatteryState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDesktopBatteryState.InnerSingleton, Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDesktopBatteryState.InnerSingleton;
}
// ********** End Enum EDesktopBatteryState ********************************************************

// ********** Begin Enum EDesktopPowerLineStatus ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDesktopPowerLineStatus;
static UEnum* EDesktopPowerLineStatus_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDesktopPowerLineStatus.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDesktopPowerLineStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("EDesktopPowerLineStatus"));
	}
	return Z_Registration_Info_UEnum_EDesktopPowerLineStatus.OuterSingleton;
}
template<> GENERICDESKTOPFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDesktopPowerLineStatus>()
{
	return EDesktopPowerLineStatus_StaticEnum();
}
struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xa4\x96\xe6\x8e\xa5\xe7\x94\xb5\xe6\xba\x90\xe7\x8a\xb6\xe6\x80\x81\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
		{ "Offline.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xa6\xbb\xe7\xba\xbf\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Offline.Name", "EDesktopPowerLineStatus::Offline" },
		{ "Offline.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xa6\xbb\xe7\xba\xbf\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "Online.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x9c\xa8\xe7\xba\xbf\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Online.Name", "EDesktopPowerLineStatus::Online" },
		{ "Online.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x9c\xa8\xe7\xba\xbf\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xa4\x96\xe6\x8e\xa5\xe7\x94\xb5\xe6\xba\x90\xe7\x8a\xb6\xe6\x80\x81\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Unknown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Unknown.Name", "EDesktopPowerLineStatus::Unknown" },
		{ "Unknown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDesktopPowerLineStatus::Unknown", (int64)EDesktopPowerLineStatus::Unknown },
		{ "EDesktopPowerLineStatus::Offline", (int64)EDesktopPowerLineStatus::Offline },
		{ "EDesktopPowerLineStatus::Online", (int64)EDesktopPowerLineStatus::Online },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	"EDesktopPowerLineStatus",
	"EDesktopPowerLineStatus",
	Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus()
{
	if (!Z_Registration_Info_UEnum_EDesktopPowerLineStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDesktopPowerLineStatus.InnerSingleton, Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDesktopPowerLineStatus.InnerSingleton;
}
// ********** End Enum EDesktopPowerLineStatus *****************************************************

// ********** Begin Enum EDesktopNetworkType *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDesktopNetworkType;
static UEnum* EDesktopNetworkType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDesktopNetworkType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDesktopNetworkType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("EDesktopNetworkType"));
	}
	return Z_Registration_Info_UEnum_EDesktopNetworkType.OuterSingleton;
}
template<> GENERICDESKTOPFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDesktopNetworkType>()
{
	return EDesktopNetworkType_StaticEnum();
}
struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AirplaneMode.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe9\xa3\x9e\xe8\xa1\x8c\xe6\xa8\xa1\xe5\xbc\x8f\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "AirplaneMode.Name", "EDesktopNetworkType::AirplaneMode" },
		{ "AirplaneMode.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe9\xa3\x9e\xe8\xa1\x8c\xe6\xa8\xa1\xe5\xbc\x8f\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "BlueprintType", "true" },
		{ "Bluetooth.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Bluetooth.Name", "EDesktopNetworkType::Bluetooth" },
		{ "Bluetooth.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "Cell.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x8d\x95\xe5\x85\x83\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Cell.Name", "EDesktopNetworkType::Cell" },
		{ "Cell.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x8d\x95\xe5\x85\x83\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xbd\x91\xe7\xbb\x9c\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "Ethernet.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xbb\xa5\xe5\xa4\xaa\xe7\xbd\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Ethernet.Name", "EDesktopNetworkType::Ethernet" },
		{ "Ethernet.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xbb\xa5\xe5\xa4\xaa\xe7\xbd\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
		{ "None.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x97\xa0\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "None.Name", "EDesktopNetworkType::None" },
		{ "None.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x97\xa0\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xbd\x91\xe7\xbb\x9c\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Unknown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Unknown.Name", "EDesktopNetworkType::Unknown" },
		{ "Unknown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "WiFi.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaWi-Fi\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "WiFi.Name", "EDesktopNetworkType::WiFi" },
		{ "WiFi.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaWi-Fi\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "WiMAX.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaWiMAX\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "WiMAX.Name", "EDesktopNetworkType::WiMAX" },
		{ "WiMAX.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaWiMAX\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDesktopNetworkType::Unknown", (int64)EDesktopNetworkType::Unknown },
		{ "EDesktopNetworkType::None", (int64)EDesktopNetworkType::None },
		{ "EDesktopNetworkType::AirplaneMode", (int64)EDesktopNetworkType::AirplaneMode },
		{ "EDesktopNetworkType::Cell", (int64)EDesktopNetworkType::Cell },
		{ "EDesktopNetworkType::WiFi", (int64)EDesktopNetworkType::WiFi },
		{ "EDesktopNetworkType::WiMAX", (int64)EDesktopNetworkType::WiMAX },
		{ "EDesktopNetworkType::Bluetooth", (int64)EDesktopNetworkType::Bluetooth },
		{ "EDesktopNetworkType::Ethernet", (int64)EDesktopNetworkType::Ethernet },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	"EDesktopNetworkType",
	"EDesktopNetworkType",
	Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType()
{
	if (!Z_Registration_Info_UEnum_EDesktopNetworkType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDesktopNetworkType.InnerSingleton, Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDesktopNetworkType.InnerSingleton;
}
// ********** End Enum EDesktopNetworkType *********************************************************

// ********** Begin Enum EDesktopDisplayOrientation ************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDesktopDisplayOrientation;
static UEnum* EDesktopDisplayOrientation_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDesktopDisplayOrientation.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDesktopDisplayOrientation.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("EDesktopDisplayOrientation"));
	}
	return Z_Registration_Info_UEnum_EDesktopDisplayOrientation.OuterSingleton;
}
template<> GENERICDESKTOPFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDesktopDisplayOrientation>()
{
	return EDesktopDisplayOrientation_StaticEnum();
}
struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe6\x98\xbe\xe7\xa4\xba\xe6\x96\xb9\xe5\x90\x91\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "Landscape.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xa8\xaa\xe5\x90\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Landscape.Name", "EDesktopDisplayOrientation::Landscape" },
		{ "Landscape.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xa8\xaa\xe5\x90\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "LandscapeFlipped.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xa8\xaa\xe5\x90\x91\xe7\xbf\xbb\xe8\xbd\xac\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "LandscapeFlipped.Name", "EDesktopDisplayOrientation::LandscapeFlipped" },
		{ "LandscapeFlipped.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xa8\xaa\xe5\x90\x91\xe7\xbf\xbb\xe8\xbd\xac\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
		{ "Portrait.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xb5\xe5\x90\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Portrait.Name", "EDesktopDisplayOrientation::Portrait" },
		{ "Portrait.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xb5\xe5\x90\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "PortraitFlipped.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xb5\xe5\x90\x91\xe7\xbf\xbb\xe8\xbd\xac\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "PortraitFlipped.Name", "EDesktopDisplayOrientation::PortraitFlipped" },
		{ "PortraitFlipped.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xb5\xe5\x90\x91\xe7\xbf\xbb\xe8\xbd\xac\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe6\x98\xbe\xe7\xa4\xba\xe6\x96\xb9\xe5\x90\x91\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Unknown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Unknown.Name", "EDesktopDisplayOrientation::Unknown" },
		{ "Unknown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDesktopDisplayOrientation::Unknown", (int64)EDesktopDisplayOrientation::Unknown },
		{ "EDesktopDisplayOrientation::Landscape", (int64)EDesktopDisplayOrientation::Landscape },
		{ "EDesktopDisplayOrientation::Portrait", (int64)EDesktopDisplayOrientation::Portrait },
		{ "EDesktopDisplayOrientation::LandscapeFlipped", (int64)EDesktopDisplayOrientation::LandscapeFlipped },
		{ "EDesktopDisplayOrientation::PortraitFlipped", (int64)EDesktopDisplayOrientation::PortraitFlipped },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	"EDesktopDisplayOrientation",
	"EDesktopDisplayOrientation",
	Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation()
{
	if (!Z_Registration_Info_UEnum_EDesktopDisplayOrientation.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDesktopDisplayOrientation.InnerSingleton, Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDesktopDisplayOrientation.InnerSingleton;
}
// ********** End Enum EDesktopDisplayOrientation **************************************************

// ********** Begin Enum EDesktopDisplayMode *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDesktopDisplayMode;
static UEnum* EDesktopDisplayMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDesktopDisplayMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDesktopDisplayMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("EDesktopDisplayMode"));
	}
	return Z_Registration_Info_UEnum_EDesktopDisplayMode.OuterSingleton;
}
template<> GENERICDESKTOPFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EDesktopDisplayMode>()
{
	return EDesktopDisplayMode_StaticEnum();
}
struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe6\x98\xbe\xe7\xa4\xba\xe6\xa8\xa1\xe5\xbc\x8f\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "Fullscreen.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x85\xa8\xe5\xb1\x8f\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Fullscreen.Name", "EDesktopDisplayMode::Fullscreen" },
		{ "Fullscreen.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x85\xa8\xe5\xb1\x8f\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe6\xa1\x8c\xe9\x9d\xa2\xe6\x98\xbe\xe7\xa4\xba\xe6\xa8\xa1\xe5\xbc\x8f\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Unknown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Unknown.Name", "EDesktopDisplayMode::Unknown" },
		{ "Unknown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "Windowed.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xaa\x97\xe5\x8f\xa3\xe5\x8c\x96\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Windowed.Name", "EDesktopDisplayMode::Windowed" },
		{ "Windowed.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xaa\x97\xe5\x8f\xa3\xe5\x8c\x96\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "WindowedFullscreen.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xaa\x97\xe5\x8f\xa3\xe5\x8c\x96\xe5\x85\xa8\xe5\xb1\x8f\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "WindowedFullscreen.Name", "EDesktopDisplayMode::WindowedFullscreen" },
		{ "WindowedFullscreen.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xaa\x97\xe5\x8f\xa3\xe5\x8c\x96\xe5\x85\xa8\xe5\xb1\x8f\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDesktopDisplayMode::Unknown", (int64)EDesktopDisplayMode::Unknown },
		{ "EDesktopDisplayMode::Windowed", (int64)EDesktopDisplayMode::Windowed },
		{ "EDesktopDisplayMode::WindowedFullscreen", (int64)EDesktopDisplayMode::WindowedFullscreen },
		{ "EDesktopDisplayMode::Fullscreen", (int64)EDesktopDisplayMode::Fullscreen },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	"EDesktopDisplayMode",
	"EDesktopDisplayMode",
	Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode()
{
	if (!Z_Registration_Info_UEnum_EDesktopDisplayMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDesktopDisplayMode.InnerSingleton, Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDesktopDisplayMode.InnerSingleton;
}
// ********** End Enum EDesktopDisplayMode *********************************************************

// ********** Begin ScriptStruct FDesktopApplicationInfo *******************************************
struct Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopApplicationInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopApplicationInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceId_MetaData[] = {
		{ "Category", "DesktopApplicationInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe5\xa4\x87\xe5\x94\xaf\xe4\xb8\x80\xe6\xa0\x87\xe8\xaf\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe5\xa4\x87\xe5\x94\xaf\xe4\xb8\x80\xe6\xa0\x87\xe8\xaf\x86\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ComputerName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xa1\xe7\xae\x97\xe6\x9c\xba\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xa1\xe7\xae\x97\xe6\x9c\xba\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xa8\xe6\x88\xb7\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xa8\xe6\x88\xb7\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BaseDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x9f\xba\xe7\xa1\x80\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x9f\xba\xe7\xa1\x80\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xa8\xe6\x88\xb7\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xa8\xe6\x88\xb7\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserTempDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xa8\xe6\x88\xb7\xe4\xb8\xb4\xe6\x97\xb6\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xa8\xe6\x88\xb7\xe4\xb8\xb4\xe6\x97\xb6\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UserHomeDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xa8\xe6\x88\xb7\xe4\xb8\xbb\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xa8\xe6\x88\xb7\xe4\xb8\xbb\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExecutablePath_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe6\x89\xa7\xe8\xa1\x8c\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe6\x89\xa7\xe8\xa1\x8c\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LaunchDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x90\xaf\xe5\x8a\xa8\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x90\xaf\xe5\x8a\xa8\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectSavedDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe4\xbf\x9d\xe5\xad\x98\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe4\xbf\x9d\xe5\xad\x98\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectContentDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe5\x86\x85\xe5\xae\xb9\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe5\x86\x85\xe5\xae\xb9\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CommandLine_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x91\xbd\xe4\xbb\xa4\xe8\xa1\x8c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x91\xbd\xe4\xbb\xa4\xe8\xa1\x8c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OperatingSystemId_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x93\x8d\xe4\xbd\x9c\xe7\xb3\xbb\xe7\xbb\x9fID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x93\x8d\xe4\xbd\x9c\xe7\xb3\xbb\xe7\xbb\x9fID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OSVersion_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98OS\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98OS\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OSVersionLabel_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98OS\xe7\x89\x88\xe6\x9c\xac\xe6\xa0\x87\xe7\xad\xbe\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98OS\xe7\x89\x88\xe6\x9c\xac\xe6\xa0\x87\xe7\xad\xbe\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OSSubVersionLabel_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98OS Sub\xe7\x89\x88\xe6\x9c\xac\xe6\xa0\x87\xe7\xad\xbe\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98OS Sub\xe7\x89\x88\xe6\x9c\xac\xe6\xa0\x87\xe7\xad\xbe\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EngineVersion_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xbc\x95\xe6\x93\x8e\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xbc\x95\xe6\x93\x8e\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessId_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8bID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8bID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsRunningAsAdministrator_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe7\xae\xa1\xe7\x90\x86\xe5\x91\x98\xe8\xbf\x90\xe8\xa1\x8c\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe7\xae\xa1\xe7\x90\x86\xe5\x91\x98\xe8\xbf\x90\xe8\xa1\x8c\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopApplicationInfo constinit property declarations ***********
	static const UECodeGen_Private::FStrPropertyParams NewProp_DeviceId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ComputerName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_UserName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_BaseDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_UserDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_UserTempDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_UserHomeDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ExecutablePath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LaunchDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProjectDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProjectSavedDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProjectContentDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_CommandLine;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OperatingSystemId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OSVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OSVersionLabel;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OSSubVersionLabel;
	static const UECodeGen_Private::FStrPropertyParams NewProp_EngineVersion;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ProcessId;
	static void NewProp_bIsRunningAsAdministrator_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRunningAsAdministrator;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopApplicationInfo constinit property declarations *************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopApplicationInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopApplicationInfo;
class UScriptStruct* FDesktopApplicationInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopApplicationInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopApplicationInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopApplicationInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopApplicationInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopApplicationInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopApplicationInfo Property Definitions **********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_DeviceId = { "DeviceId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, DeviceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceId_MetaData), NewProp_DeviceId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ComputerName = { "ComputerName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, ComputerName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ComputerName_MetaData), NewProp_ComputerName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_UserName = { "UserName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, UserName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserName_MetaData), NewProp_UserName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_BaseDir = { "BaseDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, BaseDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BaseDir_MetaData), NewProp_BaseDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_UserDir = { "UserDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, UserDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserDir_MetaData), NewProp_UserDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_UserTempDir = { "UserTempDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, UserTempDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserTempDir_MetaData), NewProp_UserTempDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_UserHomeDir = { "UserHomeDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, UserHomeDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UserHomeDir_MetaData), NewProp_UserHomeDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ExecutablePath = { "ExecutablePath", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, ExecutablePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExecutablePath_MetaData), NewProp_ExecutablePath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_LaunchDir = { "LaunchDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, LaunchDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LaunchDir_MetaData), NewProp_LaunchDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ProjectDir = { "ProjectDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, ProjectDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectDir_MetaData), NewProp_ProjectDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ProjectSavedDir = { "ProjectSavedDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, ProjectSavedDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectSavedDir_MetaData), NewProp_ProjectSavedDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ProjectContentDir = { "ProjectContentDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, ProjectContentDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectContentDir_MetaData), NewProp_ProjectContentDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_CommandLine = { "CommandLine", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, CommandLine), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CommandLine_MetaData), NewProp_CommandLine_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_OperatingSystemId = { "OperatingSystemId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, OperatingSystemId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OperatingSystemId_MetaData), NewProp_OperatingSystemId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_OSVersion = { "OSVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, OSVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OSVersion_MetaData), NewProp_OSVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_OSVersionLabel = { "OSVersionLabel", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, OSVersionLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OSVersionLabel_MetaData), NewProp_OSVersionLabel_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_OSSubVersionLabel = { "OSSubVersionLabel", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, OSSubVersionLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OSSubVersionLabel_MetaData), NewProp_OSSubVersionLabel_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_EngineVersion = { "EngineVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, EngineVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EngineVersion_MetaData), NewProp_EngineVersion_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ProcessId = { "ProcessId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopApplicationInfo, ProcessId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessId_MetaData), NewProp_ProcessId_MetaData) };
void Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_bIsRunningAsAdministrator_SetBit(void* Obj)
{
	((FDesktopApplicationInfo*)Obj)->bIsRunningAsAdministrator = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_bIsRunningAsAdministrator = { "bIsRunningAsAdministrator", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopApplicationInfo), &Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_bIsRunningAsAdministrator_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsRunningAsAdministrator_MetaData), NewProp_bIsRunningAsAdministrator_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_DeviceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ComputerName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_UserName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_BaseDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_UserDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_UserTempDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_UserHomeDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ExecutablePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_LaunchDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ProjectDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ProjectSavedDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ProjectContentDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_CommandLine,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_OperatingSystemId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_OSVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_OSVersionLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_OSSubVersionLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_EngineVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_ProcessId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewProp_bIsRunningAsAdministrator,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopApplicationInfo Property Definitions ************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopApplicationInfo",
	Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::PropPointers),
	sizeof(FDesktopApplicationInfo),
	alignof(FDesktopApplicationInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopApplicationInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopApplicationInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopApplicationInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopApplicationInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopApplicationInfo *********************************************

// ********** Begin ScriptStruct FDesktopSystemPathInfo ********************************************
struct Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopSystemPathInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopSystemPathInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xb7\xaf\xe5\xbe\x84\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xb7\xaf\xe5\xbe\x84\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DesktopDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DocumentsDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Documents\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Documents\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DownloadsDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Downloads\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Downloads\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MusicDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Music\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Music\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PicturesDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Pictures\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Pictures\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VideosDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Videos\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Videos\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AppDataDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xba\x94\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xba\x94\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LocalAppDataDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\xac\xe5\x9c\xb0\xe5\xba\x94\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\xac\xe5\x9c\xb0\xe5\xba\x94\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TempDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xb4\xe6\x97\xb6\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xb4\xe6\x97\xb6\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProgramDataDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Program\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Program\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SavedGamesDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xbf\x9d\xe5\xad\x98Games\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xbf\x9d\xe5\xad\x98Games\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectExtrasDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae""Extras\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae""Extras\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectSaveGameDir_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe4\xbf\x9d\xe5\xad\x98\xe6\xb8\xb8\xe6\x88\x8f\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe4\xbf\x9d\xe5\xad\x98\xe6\xb8\xb8\xe6\x88\x8f\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopSystemPathInfo constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_DesktopDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DocumentsDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DownloadsDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MusicDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PicturesDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VideosDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AppDataDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LocalAppDataDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TempDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProgramDataDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SavedGamesDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProjectExtrasDir;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProjectSaveGameDir;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopSystemPathInfo constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopSystemPathInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopSystemPathInfo;
class UScriptStruct* FDesktopSystemPathInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopSystemPathInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopSystemPathInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopSystemPathInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopSystemPathInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopSystemPathInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopSystemPathInfo Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_DesktopDir = { "DesktopDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, DesktopDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DesktopDir_MetaData), NewProp_DesktopDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_DocumentsDir = { "DocumentsDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, DocumentsDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DocumentsDir_MetaData), NewProp_DocumentsDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_DownloadsDir = { "DownloadsDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, DownloadsDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DownloadsDir_MetaData), NewProp_DownloadsDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_MusicDir = { "MusicDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, MusicDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MusicDir_MetaData), NewProp_MusicDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_PicturesDir = { "PicturesDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, PicturesDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PicturesDir_MetaData), NewProp_PicturesDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_VideosDir = { "VideosDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, VideosDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VideosDir_MetaData), NewProp_VideosDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_AppDataDir = { "AppDataDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, AppDataDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AppDataDir_MetaData), NewProp_AppDataDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_LocalAppDataDir = { "LocalAppDataDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, LocalAppDataDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LocalAppDataDir_MetaData), NewProp_LocalAppDataDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_TempDir = { "TempDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, TempDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TempDir_MetaData), NewProp_TempDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_ProgramDataDir = { "ProgramDataDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, ProgramDataDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProgramDataDir_MetaData), NewProp_ProgramDataDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_SavedGamesDir = { "SavedGamesDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, SavedGamesDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SavedGamesDir_MetaData), NewProp_SavedGamesDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_ProjectExtrasDir = { "ProjectExtrasDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, ProjectExtrasDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectExtrasDir_MetaData), NewProp_ProjectExtrasDir_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_ProjectSaveGameDir = { "ProjectSaveGameDir", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopSystemPathInfo, ProjectSaveGameDir), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectSaveGameDir_MetaData), NewProp_ProjectSaveGameDir_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_DesktopDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_DocumentsDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_DownloadsDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_MusicDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_PicturesDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_VideosDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_AppDataDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_LocalAppDataDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_TempDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_ProgramDataDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_SavedGamesDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_ProjectExtrasDir,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewProp_ProjectSaveGameDir,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopSystemPathInfo Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopSystemPathInfo",
	Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::PropPointers),
	sizeof(FDesktopSystemPathInfo),
	alignof(FDesktopSystemPathInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopSystemPathInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopSystemPathInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopSystemPathInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopSystemPathInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopSystemPathInfo **********************************************

// ********** Begin ScriptStruct FDesktopMonitorInfo ***********************************************
struct Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopMonitorInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopMonitorInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2Monitor\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2Monitor\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeWidth_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x9f\xe7\x94\x9f\xe5\xae\xbd\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x9f\xe7\x94\x9f\xe5\xae\xbd\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeHeight_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x9f\xe7\x94\x9f\xe9\xab\x98\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x9f\xe7\x94\x9f\xe9\xab\x98\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxResolutionX_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7Resolution X\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7Resolution X\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxResolutionY_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7Resolution Y\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7Resolution Y\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayLeft_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xbaLeft\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xbaLeft\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayTop_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xbaTop\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xbaTop\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayRight_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xba\xe5\x90\x91\xe5\x8f\xb3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xba\xe5\x90\x91\xe5\x8f\xb3\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayBottom_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xba""Bottom\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xba""Bottom\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorkAreaLeft_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9fLeft\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9fLeft\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorkAreaTop_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9fTop\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9fTop\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorkAreaRight_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9f\xe5\x90\x91\xe5\x8f\xb3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9f\xe5\x90\x91\xe5\x8f\xb3\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorkAreaBottom_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9f""Bottom\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9f""Bottom\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DPI_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""DPI\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""DPI\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DPIScale_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""DPI \xe7\xbc\xa9\xe6\x94\xbe\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""DPI \xe7\xbc\xa9\xe6\x94\xbe\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RefreshRate_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x88\xb7\xe6\x96\xb0\xe9\x80\x9f\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x88\xb7\xe6\x96\xb0\xe9\x80\x9f\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsPrimary_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe4\xb8\xbb\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe4\xb8\xbb\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\xb9\xe5\x90\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\xb9\xe5\x90\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopMonitorInfo constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Id;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NativeWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NativeHeight;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxResolutionX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxResolutionY;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DisplayLeft;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DisplayTop;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DisplayRight;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DisplayBottom;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WorkAreaLeft;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WorkAreaTop;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WorkAreaRight;
	static const UECodeGen_Private::FIntPropertyParams NewProp_WorkAreaBottom;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DPI;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DPIScale;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RefreshRate;
	static void NewProp_bIsPrimary_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsPrimary;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Orientation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Orientation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopMonitorInfo constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopMonitorInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopMonitorInfo;
class UScriptStruct* FDesktopMonitorInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopMonitorInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopMonitorInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopMonitorInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopMonitorInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopMonitorInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopMonitorInfo Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, Id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_NativeWidth = { "NativeWidth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, NativeWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeWidth_MetaData), NewProp_NativeWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_NativeHeight = { "NativeHeight", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, NativeHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeHeight_MetaData), NewProp_NativeHeight_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_MaxResolutionX = { "MaxResolutionX", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, MaxResolutionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxResolutionX_MetaData), NewProp_MaxResolutionX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_MaxResolutionY = { "MaxResolutionY", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, MaxResolutionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxResolutionY_MetaData), NewProp_MaxResolutionY_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DisplayLeft = { "DisplayLeft", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, DisplayLeft), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayLeft_MetaData), NewProp_DisplayLeft_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DisplayTop = { "DisplayTop", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, DisplayTop), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayTop_MetaData), NewProp_DisplayTop_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DisplayRight = { "DisplayRight", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, DisplayRight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayRight_MetaData), NewProp_DisplayRight_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DisplayBottom = { "DisplayBottom", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, DisplayBottom), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayBottom_MetaData), NewProp_DisplayBottom_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_WorkAreaLeft = { "WorkAreaLeft", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, WorkAreaLeft), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorkAreaLeft_MetaData), NewProp_WorkAreaLeft_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_WorkAreaTop = { "WorkAreaTop", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, WorkAreaTop), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorkAreaTop_MetaData), NewProp_WorkAreaTop_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_WorkAreaRight = { "WorkAreaRight", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, WorkAreaRight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorkAreaRight_MetaData), NewProp_WorkAreaRight_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_WorkAreaBottom = { "WorkAreaBottom", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, WorkAreaBottom), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorkAreaBottom_MetaData), NewProp_WorkAreaBottom_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DPI = { "DPI", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, DPI), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DPI_MetaData), NewProp_DPI_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DPIScale = { "DPIScale", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, DPIScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DPIScale_MetaData), NewProp_DPIScale_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_RefreshRate = { "RefreshRate", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, RefreshRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RefreshRate_MetaData), NewProp_RefreshRate_MetaData) };
void Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_bIsPrimary_SetBit(void* Obj)
{
	((FDesktopMonitorInfo*)Obj)->bIsPrimary = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_bIsPrimary = { "bIsPrimary", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopMonitorInfo), &Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_bIsPrimary_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsPrimary_MetaData), NewProp_bIsPrimary_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_Orientation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMonitorInfo, Orientation), Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayOrientation, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orientation_MetaData), NewProp_Orientation_MetaData) }; // 2902332089
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_NativeWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_NativeHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_MaxResolutionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_MaxResolutionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DisplayLeft,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DisplayTop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DisplayRight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DisplayBottom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_WorkAreaLeft,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_WorkAreaTop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_WorkAreaRight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_WorkAreaBottom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DPI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_DPIScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_RefreshRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_bIsPrimary,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_Orientation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewProp_Orientation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopMonitorInfo Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopMonitorInfo",
	Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::PropPointers),
	sizeof(FDesktopMonitorInfo),
	alignof(FDesktopMonitorInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopMonitorInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopMonitorInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopMonitorInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopMonitorInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopMonitorInfo *************************************************

// ********** Begin ScriptStruct FDesktopDisplayInfo ***********************************************
struct Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopDisplayInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopDisplayInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrimaryDisplayWidth_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe6\x98\xbe\xe7\xa4\xba\xe5\xae\xbd\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe6\x98\xbe\xe7\xa4\xba\xe5\xae\xbd\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrimaryDisplayHeight_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe6\x98\xbe\xe7\xa4\xba\xe9\xab\x98\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe6\x98\xbe\xe7\xa4\xba\xe9\xab\x98\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrimaryWorkAreaLeft_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9fLeft\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9fLeft\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrimaryWorkAreaTop_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9fTop\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9fTop\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrimaryWorkAreaRight_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9f\xe5\x90\x91\xe5\x8f\xb3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9f\xe5\x90\x91\xe5\x8f\xb3\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrimaryWorkAreaBottom_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9f""Bottom\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe5\xb7\xa5\xe4\xbd\x9c\xe5\x8c\xba\xe5\x9f\x9f""Bottom\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VirtualDisplayLeft_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe6\x98\xbe\xe7\xa4\xbaLeft\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe6\x98\xbe\xe7\xa4\xbaLeft\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VirtualDisplayTop_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe6\x98\xbe\xe7\xa4\xbaTop\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe6\x98\xbe\xe7\xa4\xbaTop\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VirtualDisplayRight_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe6\x98\xbe\xe7\xa4\xba\xe5\x90\x91\xe5\x8f\xb3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe6\x98\xbe\xe7\xa4\xba\xe5\x90\x91\xe5\x8f\xb3\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VirtualDisplayBottom_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe6\x98\xbe\xe7\xa4\xba""Bottom\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe6\x98\xbe\xe7\xa4\xba""Bottom\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MonitorCount_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Monitor\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Monitor\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApplicationScale_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xba\x94\xe7\x94\xa8\xe7\xbc\xa9\xe6\x94\xbe\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xba\x94\xe7\x94\xa8\xe7\xbc\xa9\xe6\x94\xbe\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Monitors_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Monitors\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Monitors\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopDisplayInfo constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_PrimaryDisplayWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PrimaryDisplayHeight;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PrimaryWorkAreaLeft;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PrimaryWorkAreaTop;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PrimaryWorkAreaRight;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PrimaryWorkAreaBottom;
	static const UECodeGen_Private::FIntPropertyParams NewProp_VirtualDisplayLeft;
	static const UECodeGen_Private::FIntPropertyParams NewProp_VirtualDisplayTop;
	static const UECodeGen_Private::FIntPropertyParams NewProp_VirtualDisplayRight;
	static const UECodeGen_Private::FIntPropertyParams NewProp_VirtualDisplayBottom;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MonitorCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ApplicationScale;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Monitors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Monitors;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopDisplayInfo constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopDisplayInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopDisplayInfo;
class UScriptStruct* FDesktopDisplayInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopDisplayInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopDisplayInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopDisplayInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopDisplayInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopDisplayInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopDisplayInfo Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryDisplayWidth = { "PrimaryDisplayWidth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, PrimaryDisplayWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrimaryDisplayWidth_MetaData), NewProp_PrimaryDisplayWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryDisplayHeight = { "PrimaryDisplayHeight", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, PrimaryDisplayHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrimaryDisplayHeight_MetaData), NewProp_PrimaryDisplayHeight_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryWorkAreaLeft = { "PrimaryWorkAreaLeft", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, PrimaryWorkAreaLeft), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrimaryWorkAreaLeft_MetaData), NewProp_PrimaryWorkAreaLeft_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryWorkAreaTop = { "PrimaryWorkAreaTop", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, PrimaryWorkAreaTop), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrimaryWorkAreaTop_MetaData), NewProp_PrimaryWorkAreaTop_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryWorkAreaRight = { "PrimaryWorkAreaRight", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, PrimaryWorkAreaRight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrimaryWorkAreaRight_MetaData), NewProp_PrimaryWorkAreaRight_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryWorkAreaBottom = { "PrimaryWorkAreaBottom", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, PrimaryWorkAreaBottom), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrimaryWorkAreaBottom_MetaData), NewProp_PrimaryWorkAreaBottom_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_VirtualDisplayLeft = { "VirtualDisplayLeft", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, VirtualDisplayLeft), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VirtualDisplayLeft_MetaData), NewProp_VirtualDisplayLeft_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_VirtualDisplayTop = { "VirtualDisplayTop", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, VirtualDisplayTop), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VirtualDisplayTop_MetaData), NewProp_VirtualDisplayTop_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_VirtualDisplayRight = { "VirtualDisplayRight", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, VirtualDisplayRight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VirtualDisplayRight_MetaData), NewProp_VirtualDisplayRight_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_VirtualDisplayBottom = { "VirtualDisplayBottom", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, VirtualDisplayBottom), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VirtualDisplayBottom_MetaData), NewProp_VirtualDisplayBottom_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_MonitorCount = { "MonitorCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, MonitorCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MonitorCount_MetaData), NewProp_MonitorCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_ApplicationScale = { "ApplicationScale", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, ApplicationScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApplicationScale_MetaData), NewProp_ApplicationScale_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_Monitors_Inner = { "Monitors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDesktopMonitorInfo, METADATA_PARAMS(0, nullptr) }; // 1496936958
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_Monitors = { "Monitors", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDisplayInfo, Monitors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Monitors_MetaData), NewProp_Monitors_MetaData) }; // 1496936958
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryDisplayWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryDisplayHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryWorkAreaLeft,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryWorkAreaTop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryWorkAreaRight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_PrimaryWorkAreaBottom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_VirtualDisplayLeft,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_VirtualDisplayTop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_VirtualDisplayRight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_VirtualDisplayBottom,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_MonitorCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_ApplicationScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_Monitors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewProp_Monitors,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopDisplayInfo Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopDisplayInfo",
	Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::PropPointers),
	sizeof(FDesktopDisplayInfo),
	alignof(FDesktopDisplayInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopDisplayInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopDisplayInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopDisplayInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopDisplayInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopDisplayInfo *************************************************

// ********** Begin ScriptStruct FDesktopMainWindowInfo ********************************************
struct Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopMainWindowInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopMainWindowInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2Main\xe7\xaa\x97\xe5\x8f\xa3\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2Main\xe7\xaa\x97\xe5\x8f\xa3\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsValid_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x9c\x89\xe6\x95\x88\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x9c\x89\xe6\x95\x88\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xa0\x87\xe9\xa2\x98\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xa0\x87\xe9\xa2\x98\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WindowHandleValue_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xaa\x97\xe5\x8f\xa3\xe5\x8f\xa5\xe6\x9f\x84\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xaa\x97\xe5\x8f\xa3\xe5\x8f\xa5\xe6\x9f\x84\xe5\x80\xbc\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionX_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Position X\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Position X\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PositionY_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Position Y\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Position Y\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SizeX_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8fX\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8fX\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SizeY_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8fY\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8fY\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClientSizeX_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Client\xe5\xa4\xa7\xe5\xb0\x8fX\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Client\xe5\xa4\xa7\xe5\xb0\x8fX\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClientSizeY_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Client\xe5\xa4\xa7\xe5\xb0\x8fY\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Client\xe5\xa4\xa7\xe5\xb0\x8fY\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewportSizeX_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Viewport\xe5\xa4\xa7\xe5\xb0\x8fX\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Viewport\xe5\xa4\xa7\xe5\xb0\x8fX\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewportSizeY_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Viewport\xe5\xa4\xa7\xe5\xb0\x8fY\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Viewport\xe5\xa4\xa7\xe5\xb0\x8fY\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsVisible_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe5\x8f\xaf\xe8\xa7\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe5\x8f\xaf\xe8\xa7\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsForeground_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0""Foreground\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0""Foreground\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsMinimized_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Minimized\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Minimized\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsMaximized_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Maximized\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Maximized\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsTopMost_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Top Most\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Top Most\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsScreenCaptureDisabled_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Screen Capture\xe5\xb7\xb2\xe7\xa6\x81\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Screen Capture\xe5\xb7\xb2\xe7\xa6\x81\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WindowMode_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopMainWindowInfo constinit property declarations ************
	static void NewProp_bIsValid_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsValid;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Title;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_WindowHandleValue;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PositionX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PositionY;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SizeY;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ClientSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ClientSizeY;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ViewportSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ViewportSizeY;
	static void NewProp_bIsVisible_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsVisible;
	static void NewProp_bIsForeground_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsForeground;
	static void NewProp_bIsMinimized_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMinimized;
	static void NewProp_bIsMaximized_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsMaximized;
	static void NewProp_bIsTopMost_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsTopMost;
	static void NewProp_bIsScreenCaptureDisabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsScreenCaptureDisabled;
	static const UECodeGen_Private::FBytePropertyParams NewProp_WindowMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_WindowMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopMainWindowInfo constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopMainWindowInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopMainWindowInfo;
class UScriptStruct* FDesktopMainWindowInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopMainWindowInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopMainWindowInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopMainWindowInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopMainWindowInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopMainWindowInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopMainWindowInfo Property Definitions ***********************
void Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsValid_SetBit(void* Obj)
{
	((FDesktopMainWindowInfo*)Obj)->bIsValid = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopMainWindowInfo), &Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsValid_MetaData), NewProp_bIsValid_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_WindowHandleValue = { "WindowHandleValue", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, WindowHandleValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WindowHandleValue_MetaData), NewProp_WindowHandleValue_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_PositionX = { "PositionX", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, PositionX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionX_MetaData), NewProp_PositionX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_PositionY = { "PositionY", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, PositionY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PositionY_MetaData), NewProp_PositionY_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_SizeX = { "SizeX", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, SizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SizeX_MetaData), NewProp_SizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_SizeY = { "SizeY", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, SizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SizeY_MetaData), NewProp_SizeY_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_ClientSizeX = { "ClientSizeX", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, ClientSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClientSizeX_MetaData), NewProp_ClientSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_ClientSizeY = { "ClientSizeY", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, ClientSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClientSizeY_MetaData), NewProp_ClientSizeY_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_ViewportSizeX = { "ViewportSizeX", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, ViewportSizeX), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewportSizeX_MetaData), NewProp_ViewportSizeX_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_ViewportSizeY = { "ViewportSizeY", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, ViewportSizeY), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewportSizeY_MetaData), NewProp_ViewportSizeY_MetaData) };
void Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsVisible_SetBit(void* Obj)
{
	((FDesktopMainWindowInfo*)Obj)->bIsVisible = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsVisible = { "bIsVisible", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopMainWindowInfo), &Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsVisible_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsVisible_MetaData), NewProp_bIsVisible_MetaData) };
void Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsForeground_SetBit(void* Obj)
{
	((FDesktopMainWindowInfo*)Obj)->bIsForeground = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsForeground = { "bIsForeground", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopMainWindowInfo), &Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsForeground_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsForeground_MetaData), NewProp_bIsForeground_MetaData) };
void Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsMinimized_SetBit(void* Obj)
{
	((FDesktopMainWindowInfo*)Obj)->bIsMinimized = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsMinimized = { "bIsMinimized", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopMainWindowInfo), &Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsMinimized_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsMinimized_MetaData), NewProp_bIsMinimized_MetaData) };
void Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsMaximized_SetBit(void* Obj)
{
	((FDesktopMainWindowInfo*)Obj)->bIsMaximized = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsMaximized = { "bIsMaximized", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopMainWindowInfo), &Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsMaximized_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsMaximized_MetaData), NewProp_bIsMaximized_MetaData) };
void Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsTopMost_SetBit(void* Obj)
{
	((FDesktopMainWindowInfo*)Obj)->bIsTopMost = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsTopMost = { "bIsTopMost", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopMainWindowInfo), &Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsTopMost_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsTopMost_MetaData), NewProp_bIsTopMost_MetaData) };
void Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsScreenCaptureDisabled_SetBit(void* Obj)
{
	((FDesktopMainWindowInfo*)Obj)->bIsScreenCaptureDisabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsScreenCaptureDisabled = { "bIsScreenCaptureDisabled", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopMainWindowInfo), &Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsScreenCaptureDisabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsScreenCaptureDisabled_MetaData), NewProp_bIsScreenCaptureDisabled_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_WindowMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_WindowMode = { "WindowMode", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMainWindowInfo, WindowMode), Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WindowMode_MetaData), NewProp_WindowMode_MetaData) }; // 59183459
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsValid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_WindowHandleValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_PositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_PositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_SizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_SizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_ClientSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_ClientSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_ViewportSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_ViewportSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsVisible,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsForeground,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsMinimized,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsMaximized,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsTopMost,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_bIsScreenCaptureDisabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_WindowMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewProp_WindowMode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopMainWindowInfo Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopMainWindowInfo",
	Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::PropPointers),
	sizeof(FDesktopMainWindowInfo),
	alignof(FDesktopMainWindowInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopMainWindowInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopMainWindowInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopMainWindowInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopMainWindowInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopMainWindowInfo **********************************************

// ********** Begin ScriptStruct FDesktopCPUInfo ***************************************************
struct Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopCPUInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopCPUInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2""CPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2""CPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Vendor_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x82\xe5\x95\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x82\xe5\x95\x86\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Brand_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Chipset_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x8a\xaf\xe7\x89\x87\xe7\xbb\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x8a\xaf\xe7\x89\x87\xe7\xbb\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PhysicalCores_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LogicalCores_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x80\xbb\xe8\xbe\x91\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x80\xbb\xe8\xbe\x91\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UsagePercent_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FrequencyMHz_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Frequency\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Frequency\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessCount_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ThreadCount_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xba\xbf\xe7\xa8\x8b\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xba\xbf\xe7\xa8\x8b\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemUptimeSeconds_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9fUptime\xe7\xa7\x92\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9fUptime\xe7\xa7\x92\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopCPUInfo constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Vendor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Brand;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Chipset;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PhysicalCores;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LogicalCores;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UsagePercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_FrequencyMHz;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ProcessCount;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ThreadCount;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_SystemUptimeSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopCPUInfo constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopCPUInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopCPUInfo;
class UScriptStruct* FDesktopCPUInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopCPUInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopCPUInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopCPUInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopCPUInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopCPUInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopCPUInfo Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_Vendor = { "Vendor", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopCPUInfo, Vendor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Vendor_MetaData), NewProp_Vendor_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_Brand = { "Brand", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopCPUInfo, Brand), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Brand_MetaData), NewProp_Brand_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_Chipset = { "Chipset", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopCPUInfo, Chipset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Chipset_MetaData), NewProp_Chipset_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_PhysicalCores = { "PhysicalCores", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopCPUInfo, PhysicalCores), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PhysicalCores_MetaData), NewProp_PhysicalCores_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_LogicalCores = { "LogicalCores", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopCPUInfo, LogicalCores), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LogicalCores_MetaData), NewProp_LogicalCores_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_UsagePercent = { "UsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopCPUInfo, UsagePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UsagePercent_MetaData), NewProp_UsagePercent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_FrequencyMHz = { "FrequencyMHz", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopCPUInfo, FrequencyMHz), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FrequencyMHz_MetaData), NewProp_FrequencyMHz_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_ProcessCount = { "ProcessCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopCPUInfo, ProcessCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessCount_MetaData), NewProp_ProcessCount_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_ThreadCount = { "ThreadCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopCPUInfo, ThreadCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ThreadCount_MetaData), NewProp_ThreadCount_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_SystemUptimeSeconds = { "SystemUptimeSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopCPUInfo, SystemUptimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemUptimeSeconds_MetaData), NewProp_SystemUptimeSeconds_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_Vendor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_Brand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_Chipset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_PhysicalCores,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_LogicalCores,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_UsagePercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_FrequencyMHz,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_ProcessCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_ThreadCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewProp_SystemUptimeSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopCPUInfo Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopCPUInfo",
	Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::PropPointers),
	sizeof(FDesktopCPUInfo),
	alignof(FDesktopCPUInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopCPUInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopCPUInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopCPUInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopCPUInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopCPUInfo *****************************************************

// ********** Begin ScriptStruct FDesktopGPUInfo ***************************************************
struct Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopGPUInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopGPUInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2GPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2GPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Brand_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdapterName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Adapter\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Adapter\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProviderName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x90\xe4\xbe\x9b\xe5\x99\xa8\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x90\xe4\xbe\x9b\xe5\x99\xa8\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriverInternalVersion_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe5\x86\x85\xe9\x83\xa8\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe5\x86\x85\xe9\x83\xa8\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriverUserVersion_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe7\x94\xa8\xe6\x88\xb7\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe7\x94\xa8\xe6\x88\xb7\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriverUnifiedVersion_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriverDate_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x97\xa5\xe6\x9c\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x97\xa5\xe6\x9c\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriverRHIName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8RHI\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8RHI\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorId_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x82\xe5\x95\x86 ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x82\xe5\x95\x86 ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceId_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87 ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87 ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceRevision_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87Revision\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87Revision\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UsagePercent_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessUsagePercent_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopGPUInfo constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Brand;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdapterName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProviderName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DriverInternalVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DriverUserVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DriverUnifiedVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DriverDate;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DriverRHIName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VendorId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DeviceId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DeviceRevision;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UsagePercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProcessUsagePercent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopGPUInfo constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopGPUInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopGPUInfo;
class UScriptStruct* FDesktopGPUInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopGPUInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopGPUInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopGPUInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopGPUInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopGPUInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopGPUInfo Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_Brand = { "Brand", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, Brand), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Brand_MetaData), NewProp_Brand_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_AdapterName = { "AdapterName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, AdapterName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdapterName_MetaData), NewProp_AdapterName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_ProviderName = { "ProviderName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, ProviderName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProviderName_MetaData), NewProp_ProviderName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DriverInternalVersion = { "DriverInternalVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, DriverInternalVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriverInternalVersion_MetaData), NewProp_DriverInternalVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DriverUserVersion = { "DriverUserVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, DriverUserVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriverUserVersion_MetaData), NewProp_DriverUserVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DriverUnifiedVersion = { "DriverUnifiedVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, DriverUnifiedVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriverUnifiedVersion_MetaData), NewProp_DriverUnifiedVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DriverDate = { "DriverDate", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, DriverDate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriverDate_MetaData), NewProp_DriverDate_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DriverRHIName = { "DriverRHIName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, DriverRHIName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriverRHIName_MetaData), NewProp_DriverRHIName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_VendorId = { "VendorId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, VendorId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorId_MetaData), NewProp_VendorId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DeviceId = { "DeviceId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, DeviceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceId_MetaData), NewProp_DeviceId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DeviceRevision = { "DeviceRevision", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, DeviceRevision), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceRevision_MetaData), NewProp_DeviceRevision_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_UsagePercent = { "UsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, UsagePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UsagePercent_MetaData), NewProp_UsagePercent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_ProcessUsagePercent = { "ProcessUsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUInfo, ProcessUsagePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessUsagePercent_MetaData), NewProp_ProcessUsagePercent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_Brand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_AdapterName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_ProviderName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DriverInternalVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DriverUserVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DriverUnifiedVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DriverDate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DriverRHIName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_VendorId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DeviceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_DeviceRevision,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_UsagePercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewProp_ProcessUsagePercent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopGPUInfo Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopGPUInfo",
	Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::PropPointers),
	sizeof(FDesktopGPUInfo),
	alignof(FDesktopGPUInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopGPUInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopGPUInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopGPUInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopGPUInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopGPUInfo *****************************************************

// ********** Begin ScriptStruct FDesktopGPUMemoryInfo *********************************************
struct Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopGPUMemoryInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopGPUMemoryInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsValid_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x9c\x89\xe6\x95\x88\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x9c\x89\xe6\x95\x88\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DedicatedVideoMemoryBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\x93\xe7\x94\xa8\xe6\x98\xbe\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\x93\xe7\x94\xa8\xe6\x98\xbe\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DedicatedSystemMemoryBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\x93\xe7\x94\xa8\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\x93\xe7\x94\xa8\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SharedSystemMemoryBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x85\xb1\xe4\xba\xab\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x85\xb1\xe4\xba\xab\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalGraphicsMemoryBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe5\xbd\xa2\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe5\xbd\xa2\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StreamingMemorySizeBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xb5\x81\xe9\x80\x81\xe5\x86\x85\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xb5\x81\xe9\x80\x81\xe5\x86\x85\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NonStreamingMemorySizeBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Non\xe6\xb5\x81\xe9\x80\x81\xe5\x86\x85\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Non\xe6\xb5\x81\xe9\x80\x81\xe5\x86\x85\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LargestContiguousAllocationBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7\xe8\xbf\x9e\xe7\xbb\xad\xe5\x88\x86\xe9\x85\x8d\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7\xe8\xbf\x9e\xe7\xbb\xad\xe5\x88\x86\xe9\x85\x8d\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TexturePoolSizeBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xba\xb9\xe7\x90\x86Pool\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xba\xb9\xe7\x90\x86Pool\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvailableTexturePoolBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe7\xba\xb9\xe7\x90\x86\xe6\xb1\xa0\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe7\xba\xb9\xe7\x90\x86\xe6\xb1\xa0\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopGPUMemoryInfo constinit property declarations *************
	static void NewProp_bIsValid_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsValid;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_DedicatedVideoMemoryBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_DedicatedSystemMemoryBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SharedSystemMemoryBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalGraphicsMemoryBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_StreamingMemorySizeBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_NonStreamingMemorySizeBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_LargestContiguousAllocationBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TexturePoolSizeBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_AvailableTexturePoolBytes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopGPUMemoryInfo constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopGPUMemoryInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopGPUMemoryInfo;
class UScriptStruct* FDesktopGPUMemoryInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopGPUMemoryInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopGPUMemoryInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopGPUMemoryInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopGPUMemoryInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopGPUMemoryInfo Property Definitions ************************
void Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_bIsValid_SetBit(void* Obj)
{
	((FDesktopGPUMemoryInfo*)Obj)->bIsValid = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopGPUMemoryInfo), &Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsValid_MetaData), NewProp_bIsValid_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_DedicatedVideoMemoryBytes = { "DedicatedVideoMemoryBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUMemoryInfo, DedicatedVideoMemoryBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DedicatedVideoMemoryBytes_MetaData), NewProp_DedicatedVideoMemoryBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_DedicatedSystemMemoryBytes = { "DedicatedSystemMemoryBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUMemoryInfo, DedicatedSystemMemoryBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DedicatedSystemMemoryBytes_MetaData), NewProp_DedicatedSystemMemoryBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_SharedSystemMemoryBytes = { "SharedSystemMemoryBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUMemoryInfo, SharedSystemMemoryBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SharedSystemMemoryBytes_MetaData), NewProp_SharedSystemMemoryBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_TotalGraphicsMemoryBytes = { "TotalGraphicsMemoryBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUMemoryInfo, TotalGraphicsMemoryBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalGraphicsMemoryBytes_MetaData), NewProp_TotalGraphicsMemoryBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_StreamingMemorySizeBytes = { "StreamingMemorySizeBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUMemoryInfo, StreamingMemorySizeBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StreamingMemorySizeBytes_MetaData), NewProp_StreamingMemorySizeBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_NonStreamingMemorySizeBytes = { "NonStreamingMemorySizeBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUMemoryInfo, NonStreamingMemorySizeBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NonStreamingMemorySizeBytes_MetaData), NewProp_NonStreamingMemorySizeBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_LargestContiguousAllocationBytes = { "LargestContiguousAllocationBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUMemoryInfo, LargestContiguousAllocationBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LargestContiguousAllocationBytes_MetaData), NewProp_LargestContiguousAllocationBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_TexturePoolSizeBytes = { "TexturePoolSizeBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUMemoryInfo, TexturePoolSizeBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TexturePoolSizeBytes_MetaData), NewProp_TexturePoolSizeBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_AvailableTexturePoolBytes = { "AvailableTexturePoolBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopGPUMemoryInfo, AvailableTexturePoolBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvailableTexturePoolBytes_MetaData), NewProp_AvailableTexturePoolBytes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_bIsValid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_DedicatedVideoMemoryBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_DedicatedSystemMemoryBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_SharedSystemMemoryBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_TotalGraphicsMemoryBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_StreamingMemorySizeBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_NonStreamingMemorySizeBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_LargestContiguousAllocationBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_TexturePoolSizeBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewProp_AvailableTexturePoolBytes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopGPUMemoryInfo Property Definitions **************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopGPUMemoryInfo",
	Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::PropPointers),
	sizeof(FDesktopGPUMemoryInfo),
	alignof(FDesktopGPUMemoryInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopGPUMemoryInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopGPUMemoryInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopGPUMemoryInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopGPUMemoryInfo ***********************************************

// ********** Begin ScriptStruct FDesktopMemoryInfo ************************************************
struct Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopMemoryInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopMemoryInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalPhysicalBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvailablePhysicalBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemUsedPhysicalBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessUsedPhysicalBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeakProcessUsedPhysicalBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb3\xb0\xe5\x80\xbc\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb3\xb0\xe5\x80\xbc\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalVirtualBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvailableVirtualBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessUsedVirtualBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb7\xb2\xe7\x94\xa8\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb7\xb2\xe7\x94\xa8\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeakProcessUsedVirtualBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb3\xb0\xe5\x80\xbc\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb3\xb0\xe5\x80\xbc\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PageSizeBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Page\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Page\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OsAllocationGranularityBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Os Allocation Granularity\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Os Allocation Granularity\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BinnedPageSizeBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Binned Page\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Binned Page\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalPhysicalGB_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe9\x87\x8f\xef\xbc\x88GB\xef\xbc\x89\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe9\x87\x8f\xef\xbc\x88GB\xef\xbc\x89\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemPhysicalUsagePercent_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessPhysicalUsagePercent_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopMemoryInfo constinit property declarations ****************
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalPhysicalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_AvailablePhysicalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SystemUsedPhysicalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ProcessUsedPhysicalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PeakProcessUsedPhysicalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalVirtualBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_AvailableVirtualBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ProcessUsedVirtualBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PeakProcessUsedVirtualBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PageSizeBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_OsAllocationGranularityBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_BinnedPageSizeBytes;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalPhysicalGB;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SystemPhysicalUsagePercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProcessPhysicalUsagePercent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopMemoryInfo constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopMemoryInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopMemoryInfo;
class UScriptStruct* FDesktopMemoryInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopMemoryInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopMemoryInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopMemoryInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopMemoryInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopMemoryInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopMemoryInfo Property Definitions ***************************
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_TotalPhysicalBytes = { "TotalPhysicalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, TotalPhysicalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalPhysicalBytes_MetaData), NewProp_TotalPhysicalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_AvailablePhysicalBytes = { "AvailablePhysicalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, AvailablePhysicalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvailablePhysicalBytes_MetaData), NewProp_AvailablePhysicalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_SystemUsedPhysicalBytes = { "SystemUsedPhysicalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, SystemUsedPhysicalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemUsedPhysicalBytes_MetaData), NewProp_SystemUsedPhysicalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_ProcessUsedPhysicalBytes = { "ProcessUsedPhysicalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, ProcessUsedPhysicalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessUsedPhysicalBytes_MetaData), NewProp_ProcessUsedPhysicalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_PeakProcessUsedPhysicalBytes = { "PeakProcessUsedPhysicalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, PeakProcessUsedPhysicalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeakProcessUsedPhysicalBytes_MetaData), NewProp_PeakProcessUsedPhysicalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_TotalVirtualBytes = { "TotalVirtualBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, TotalVirtualBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalVirtualBytes_MetaData), NewProp_TotalVirtualBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_AvailableVirtualBytes = { "AvailableVirtualBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, AvailableVirtualBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvailableVirtualBytes_MetaData), NewProp_AvailableVirtualBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_ProcessUsedVirtualBytes = { "ProcessUsedVirtualBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, ProcessUsedVirtualBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessUsedVirtualBytes_MetaData), NewProp_ProcessUsedVirtualBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_PeakProcessUsedVirtualBytes = { "PeakProcessUsedVirtualBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, PeakProcessUsedVirtualBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeakProcessUsedVirtualBytes_MetaData), NewProp_PeakProcessUsedVirtualBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_PageSizeBytes = { "PageSizeBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, PageSizeBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PageSizeBytes_MetaData), NewProp_PageSizeBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_OsAllocationGranularityBytes = { "OsAllocationGranularityBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, OsAllocationGranularityBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OsAllocationGranularityBytes_MetaData), NewProp_OsAllocationGranularityBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_BinnedPageSizeBytes = { "BinnedPageSizeBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, BinnedPageSizeBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BinnedPageSizeBytes_MetaData), NewProp_BinnedPageSizeBytes_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_TotalPhysicalGB = { "TotalPhysicalGB", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, TotalPhysicalGB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalPhysicalGB_MetaData), NewProp_TotalPhysicalGB_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_SystemPhysicalUsagePercent = { "SystemPhysicalUsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, SystemPhysicalUsagePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemPhysicalUsagePercent_MetaData), NewProp_SystemPhysicalUsagePercent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_ProcessPhysicalUsagePercent = { "ProcessPhysicalUsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopMemoryInfo, ProcessPhysicalUsagePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessPhysicalUsagePercent_MetaData), NewProp_ProcessPhysicalUsagePercent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_TotalPhysicalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_AvailablePhysicalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_SystemUsedPhysicalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_ProcessUsedPhysicalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_PeakProcessUsedPhysicalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_TotalVirtualBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_AvailableVirtualBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_ProcessUsedVirtualBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_PeakProcessUsedVirtualBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_PageSizeBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_OsAllocationGranularityBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_BinnedPageSizeBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_TotalPhysicalGB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_SystemPhysicalUsagePercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewProp_ProcessPhysicalUsagePercent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopMemoryInfo Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopMemoryInfo",
	Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::PropPointers),
	sizeof(FDesktopMemoryInfo),
	alignof(FDesktopMemoryInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopMemoryInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopMemoryInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopMemoryInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopMemoryInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopMemoryInfo **************************************************

// ********** Begin ScriptStruct FDesktopDiskInfo **************************************************
struct Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopDiskInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopDiskInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xa3\x81\xe7\x9b\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xa3\x81\xe7\x9b\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsValid_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x9c\x89\xe6\x95\x88\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x9c\x89\xe6\x95\x88\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootPath_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Root\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Root\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VolumeName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Volume\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Volume\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileSystemName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriveType_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Drive\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Drive\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriveTypeName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Drive\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Drive\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FreeBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UsedBytes_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xb2\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xb2\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopDiskInfo constinit property declarations ******************
	static void NewProp_bIsValid_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsValid;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RootPath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VolumeName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileSystemName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DriveType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DriveTypeName;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_FreeBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_UsedBytes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopDiskInfo constinit property declarations ********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopDiskInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopDiskInfo;
class UScriptStruct* FDesktopDiskInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopDiskInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopDiskInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopDiskInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopDiskInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopDiskInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopDiskInfo Property Definitions *****************************
void Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_bIsValid_SetBit(void* Obj)
{
	((FDesktopDiskInfo*)Obj)->bIsValid = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopDiskInfo), &Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsValid_MetaData), NewProp_bIsValid_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDiskInfo, Path), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_RootPath = { "RootPath", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDiskInfo, RootPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootPath_MetaData), NewProp_RootPath_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_VolumeName = { "VolumeName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDiskInfo, VolumeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VolumeName_MetaData), NewProp_VolumeName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_FileSystemName = { "FileSystemName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDiskInfo, FileSystemName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileSystemName_MetaData), NewProp_FileSystemName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_DriveType = { "DriveType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDiskInfo, DriveType), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriveType_MetaData), NewProp_DriveType_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_DriveTypeName = { "DriveTypeName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDiskInfo, DriveTypeName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriveTypeName_MetaData), NewProp_DriveTypeName_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_TotalBytes = { "TotalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDiskInfo, TotalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalBytes_MetaData), NewProp_TotalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_FreeBytes = { "FreeBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDiskInfo, FreeBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FreeBytes_MetaData), NewProp_FreeBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_UsedBytes = { "UsedBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDiskInfo, UsedBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UsedBytes_MetaData), NewProp_UsedBytes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_bIsValid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_RootPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_VolumeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_FileSystemName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_DriveType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_DriveTypeName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_TotalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_FreeBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewProp_UsedBytes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopDiskInfo Property Definitions *******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopDiskInfo",
	Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::PropPointers),
	sizeof(FDesktopDiskInfo),
	alignof(FDesktopDiskInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopDiskInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopDiskInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopDiskInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopDiskInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopDiskInfo ****************************************************

// ********** Begin ScriptStruct FDesktopPowerInfo *************************************************
struct Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopPowerInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopPowerInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xb5\xe6\xba\x90\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xb5\xe6\xba\x90\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PowerLineStatus_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xba\x90\xe8\xa1\x8c\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xba\x90\xe8\xa1\x8c\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BatteryState_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xb1\xa0\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xb1\xa0\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BatteryPercent_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xb1\xa0\xe7\x94\xb5\xe9\x87\x8f\xe7\x99\xbe\xe5\x88\x86\xe6\xaf\x94\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xb1\xa0\xe7\x94\xb5\xe9\x87\x8f\xe7\x99\xbe\xe5\x88\x86\xe6\xaf\x94\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BatteryLifeTimeSeconds_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xb1\xa0Life\xe6\x97\xb6\xe9\x97\xb4\xe7\xa7\x92\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xb1\xa0Life\xe6\x97\xb6\xe9\x97\xb4\xe7\xa7\x92\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BatteryFullLifeTimeSeconds_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xb1\xa0\xe6\xbb\xa1Life\xe6\x97\xb6\xe9\x97\xb4\xe7\xa7\x92\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xb1\xa0\xe6\xbb\xa1Life\xe6\x97\xb6\xe9\x97\xb4\xe7\xa7\x92\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasBattery_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe7\x94\xb5\xe6\xb1\xa0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe7\x94\xb5\xe6\xb1\xa0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsRunningOnBattery_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe8\xbf\x90\xe8\xa1\x8cOn\xe7\x94\xb5\xe6\xb1\xa0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe8\xbf\x90\xe8\xa1\x8cOn\xe7\x94\xb5\xe6\xb1\xa0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsBatterySaverEnabled_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe7\x94\xb5\xe6\xb1\xa0Saver\xe5\xb7\xb2\xe5\x90\xaf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe7\x94\xb5\xe6\xb1\xa0Saver\xe5\xb7\xb2\xe5\x90\xaf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopPowerInfo constinit property declarations *****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_PowerLineStatus_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PowerLineStatus;
	static const UECodeGen_Private::FBytePropertyParams NewProp_BatteryState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BatteryState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BatteryPercent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BatteryLifeTimeSeconds;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BatteryFullLifeTimeSeconds;
	static void NewProp_bHasBattery_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasBattery;
	static void NewProp_bIsRunningOnBattery_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsRunningOnBattery;
	static void NewProp_bIsBatterySaverEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsBatterySaverEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopPowerInfo constinit property declarations *******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopPowerInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopPowerInfo;
class UScriptStruct* FDesktopPowerInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopPowerInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopPowerInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopPowerInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopPowerInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopPowerInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopPowerInfo Property Definitions ****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_PowerLineStatus_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_PowerLineStatus = { "PowerLineStatus", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopPowerInfo, PowerLineStatus), Z_Construct_UEnum_GenericDesktopFramework_EDesktopPowerLineStatus, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PowerLineStatus_MetaData), NewProp_PowerLineStatus_MetaData) }; // 2562197675
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_BatteryState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_BatteryState = { "BatteryState", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopPowerInfo, BatteryState), Z_Construct_UEnum_GenericDesktopFramework_EDesktopBatteryState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BatteryState_MetaData), NewProp_BatteryState_MetaData) }; // 73634874
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_BatteryPercent = { "BatteryPercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopPowerInfo, BatteryPercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BatteryPercent_MetaData), NewProp_BatteryPercent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_BatteryLifeTimeSeconds = { "BatteryLifeTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopPowerInfo, BatteryLifeTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BatteryLifeTimeSeconds_MetaData), NewProp_BatteryLifeTimeSeconds_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_BatteryFullLifeTimeSeconds = { "BatteryFullLifeTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopPowerInfo, BatteryFullLifeTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BatteryFullLifeTimeSeconds_MetaData), NewProp_BatteryFullLifeTimeSeconds_MetaData) };
void Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bHasBattery_SetBit(void* Obj)
{
	((FDesktopPowerInfo*)Obj)->bHasBattery = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bHasBattery = { "bHasBattery", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopPowerInfo), &Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bHasBattery_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasBattery_MetaData), NewProp_bHasBattery_MetaData) };
void Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bIsRunningOnBattery_SetBit(void* Obj)
{
	((FDesktopPowerInfo*)Obj)->bIsRunningOnBattery = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bIsRunningOnBattery = { "bIsRunningOnBattery", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopPowerInfo), &Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bIsRunningOnBattery_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsRunningOnBattery_MetaData), NewProp_bIsRunningOnBattery_MetaData) };
void Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bIsBatterySaverEnabled_SetBit(void* Obj)
{
	((FDesktopPowerInfo*)Obj)->bIsBatterySaverEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bIsBatterySaverEnabled = { "bIsBatterySaverEnabled", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopPowerInfo), &Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bIsBatterySaverEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsBatterySaverEnabled_MetaData), NewProp_bIsBatterySaverEnabled_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_PowerLineStatus_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_PowerLineStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_BatteryState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_BatteryState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_BatteryPercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_BatteryLifeTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_BatteryFullLifeTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bHasBattery,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bIsRunningOnBattery,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewProp_bIsBatterySaverEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopPowerInfo Property Definitions ******************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopPowerInfo",
	Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::PropPointers),
	sizeof(FDesktopPowerInfo),
	alignof(FDesktopPowerInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopPowerInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopPowerInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopPowerInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopPowerInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopPowerInfo ***************************************************

// ********** Begin ScriptStruct FDesktopNetworkAdapterIp ******************************************
struct Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopNetworkAdapterIp); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopNetworkAdapterIp); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xbd\x91\xe7\xbb\x9c""Adapter Ip\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xbd\x91\xe7\xbb\x9c""Adapter Ip\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ip_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Ip\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Ip\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mask_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x8e\xa9\xe7\xa0\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x8e\xa9\xe7\xa0\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gateway_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe5\x85\xb3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe5\x85\xb3\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopNetworkAdapterIp constinit property declarations **********
	static const UECodeGen_Private::FStrPropertyParams NewProp_Ip;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Mask;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Gateway;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopNetworkAdapterIp constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopNetworkAdapterIp>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterIp;
class UScriptStruct* FDesktopNetworkAdapterIp::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterIp.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterIp.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopNetworkAdapterIp"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterIp.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopNetworkAdapterIp Property Definitions *********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::NewProp_Ip = { "Ip", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkAdapterIp, Ip), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ip_MetaData), NewProp_Ip_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::NewProp_Mask = { "Mask", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkAdapterIp, Mask), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mask_MetaData), NewProp_Mask_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::NewProp_Gateway = { "Gateway", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkAdapterIp, Gateway), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gateway_MetaData), NewProp_Gateway_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::NewProp_Ip,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::NewProp_Mask,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::NewProp_Gateway,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopNetworkAdapterIp Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopNetworkAdapterIp",
	Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::PropPointers),
	sizeof(FDesktopNetworkAdapterIp),
	alignof(FDesktopNetworkAdapterIp),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterIp.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterIp.InnerSingleton, Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterIp.InnerSingleton);
}
// ********** End ScriptStruct FDesktopNetworkAdapterIp ********************************************

// ********** Begin ScriptStruct FDesktopNetworkAdapterInfo ****************************************
struct Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopNetworkAdapterInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopNetworkAdapterInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xbd\x91\xe7\xbb\x9c""Adapter\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xbd\x91\xe7\xbb\x9c""Adapter\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x8f\x8f\xe8\xbf\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x8f\x8f\xe8\xbf\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDHCP_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x90\xaf\xe7\x94\xa8""DHCP\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x90\xaf\xe7\x94\xa8""DHCP\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Index_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xb4\xa2\xe5\xbc\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xb4\xa2\xe5\xbc\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IPList_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98P\xe5\x88\x97\xe8\xa1\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98P\xe5\x88\x97\xe8\xa1\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MacAddress_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98MAC \xe5\x9c\xb0\xe5\x9d\x80\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98MAC \xe5\x9c\xb0\xe5\x9d\x80\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopNetworkAdapterInfo constinit property declarations ********
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Description;
	static void NewProp_bEnableDHCP_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDHCP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Type;
	static const UECodeGen_Private::FStructPropertyParams NewProp_IPList_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_IPList;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MacAddress;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopNetworkAdapterInfo constinit property declarations **********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopNetworkAdapterInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterInfo;
class UScriptStruct* FDesktopNetworkAdapterInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopNetworkAdapterInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopNetworkAdapterInfo Property Definitions *******************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkAdapterInfo, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkAdapterInfo, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
void Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_bEnableDHCP_SetBit(void* Obj)
{
	((FDesktopNetworkAdapterInfo*)Obj)->bEnableDHCP = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_bEnableDHCP = { "bEnableDHCP", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopNetworkAdapterInfo), &Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_bEnableDHCP_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDHCP_MetaData), NewProp_bEnableDHCP_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkAdapterInfo, Index), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Index_MetaData), NewProp_Index_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkAdapterInfo, Type), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Type_MetaData), NewProp_Type_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_IPList_Inner = { "IPList", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp, METADATA_PARAMS(0, nullptr) }; // 90853674
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_IPList = { "IPList", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkAdapterInfo, IPList), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IPList_MetaData), NewProp_IPList_MetaData) }; // 90853674
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_MacAddress = { "MacAddress", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkAdapterInfo, MacAddress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MacAddress_MetaData), NewProp_MacAddress_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_bEnableDHCP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_Index,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_Type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_IPList_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_IPList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewProp_MacAddress,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopNetworkAdapterInfo Property Definitions *********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopNetworkAdapterInfo",
	Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::PropPointers),
	sizeof(FDesktopNetworkAdapterInfo),
	alignof(FDesktopNetworkAdapterInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopNetworkAdapterInfo ******************************************

// ********** Begin ScriptStruct FDesktopNetworkInfo ***********************************************
struct Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopNetworkInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopNetworkInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NetworkType_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe7\xbb\x9c\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe7\xbb\x9c\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasNetwork_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe7\xbd\x91\xe7\xbb\x9c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe7\xbd\x91\xe7\xbb\x9c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasWiFiConnection_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabWi-Fi Fi\xe8\xbf\x9e\xe6\x8e\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabWi-Fi Fi\xe8\xbf\x9e\xe6\x8e\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasEthernetConnection_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe4\xbb\xa5\xe5\xa4\xaa\xe7\xbd\x91\xe8\xbf\x9e\xe6\x8e\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe4\xbb\xa5\xe5\xa4\xaa\xe7\xbd\x91\xe8\xbf\x9e\xe6\x8e\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HostName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe6\x9c\xba\xe5\x9c\xb0\xe5\x9d\x80\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb\xe6\x9c\xba\xe5\x9c\xb0\xe5\x9d\x80\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PrimaryIpv4_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb IPv4 \xe5\x9c\xb0\xe5\x9d\x80\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\xbb IPv4 \xe5\x9c\xb0\xe5\x9d\x80\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdapterCount_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Adapter\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Adapter\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopNetworkInfo constinit property declarations ***************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NetworkType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NetworkType;
	static void NewProp_bHasNetwork_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasNetwork;
	static void NewProp_bHasWiFiConnection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasWiFiConnection;
	static void NewProp_bHasEthernetConnection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasEthernetConnection;
	static const UECodeGen_Private::FStrPropertyParams NewProp_HostName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_PrimaryIpv4;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AdapterCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopNetworkInfo constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopNetworkInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopNetworkInfo;
class UScriptStruct* FDesktopNetworkInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopNetworkInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopNetworkInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopNetworkInfo, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopNetworkInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopNetworkInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopNetworkInfo Property Definitions **************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_NetworkType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_NetworkType = { "NetworkType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkInfo, NetworkType), Z_Construct_UEnum_GenericDesktopFramework_EDesktopNetworkType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NetworkType_MetaData), NewProp_NetworkType_MetaData) }; // 1283303553
void Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasNetwork_SetBit(void* Obj)
{
	((FDesktopNetworkInfo*)Obj)->bHasNetwork = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasNetwork = { "bHasNetwork", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopNetworkInfo), &Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasNetwork_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasNetwork_MetaData), NewProp_bHasNetwork_MetaData) };
void Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasWiFiConnection_SetBit(void* Obj)
{
	((FDesktopNetworkInfo*)Obj)->bHasWiFiConnection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasWiFiConnection = { "bHasWiFiConnection", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopNetworkInfo), &Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasWiFiConnection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasWiFiConnection_MetaData), NewProp_bHasWiFiConnection_MetaData) };
void Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasEthernetConnection_SetBit(void* Obj)
{
	((FDesktopNetworkInfo*)Obj)->bHasEthernetConnection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasEthernetConnection = { "bHasEthernetConnection", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopNetworkInfo), &Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasEthernetConnection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasEthernetConnection_MetaData), NewProp_bHasEthernetConnection_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_HostName = { "HostName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkInfo, HostName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HostName_MetaData), NewProp_HostName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_PrimaryIpv4 = { "PrimaryIpv4", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkInfo, PrimaryIpv4), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PrimaryIpv4_MetaData), NewProp_PrimaryIpv4_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_AdapterCount = { "AdapterCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopNetworkInfo, AdapterCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdapterCount_MetaData), NewProp_AdapterCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_NetworkType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_NetworkType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasNetwork,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasWiFiConnection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_bHasEthernetConnection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_HostName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_PrimaryIpv4,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewProp_AdapterCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopNetworkInfo Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopNetworkInfo",
	Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::PropPointers),
	sizeof(FDesktopNetworkInfo),
	alignof(FDesktopNetworkInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopNetworkInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopNetworkInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopNetworkInfo.InnerSingleton, Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopNetworkInfo.InnerSingleton);
}
// ********** End ScriptStruct FDesktopNetworkInfo *************************************************

// ********** Begin ScriptStruct FDesktopDialogResult **********************************************
struct Z_Construct_UScriptStruct_FDesktopDialogResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopDialogResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopDialogResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xaf\xb9\xe8\xaf\x9d\xe6\xa1\x86\xe7\xbb\x93\xe6\x9e\x9c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xaf\xb9\xe8\xaf\x9d\xe6\xa1\x86\xe7\xbb\x93\xe6\x9e\x9c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Directory_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FilePaths_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6Paths\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6Paths\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x94\x99\xe8\xaf\xaf\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x94\x99\xe8\xaf\xaf\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopDialogResult constinit property declarations **************
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePaths_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FilePaths;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopDialogResult constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopDialogResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopDialogResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopDialogResult;
class UScriptStruct* FDesktopDialogResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopDialogResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopDialogResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopDialogResult, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopDialogResult"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopDialogResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopDialogResult Property Definitions *************************
void Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((FDesktopDialogResult*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopDialogResult), &Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSuccess_MetaData), NewProp_bSuccess_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDialogResult, Directory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Directory_MetaData), NewProp_Directory_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_FilePaths_Inner = { "FilePaths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_FilePaths = { "FilePaths", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDialogResult, FilePaths), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FilePaths_MetaData), NewProp_FilePaths_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopDialogResult, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_FilePaths_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_FilePaths,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopDialogResult Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopDialogResult",
	Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::PropPointers),
	sizeof(FDesktopDialogResult),
	alignof(FDesktopDialogResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopDialogResult()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopDialogResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopDialogResult.InnerSingleton, Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopDialogResult.InnerSingleton);
}
// ********** End ScriptStruct FDesktopDialogResult ************************************************

// ********** Begin ScriptStruct FDesktopStringResult **********************************************
struct Z_Construct_UScriptStruct_FDesktopStringResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopStringResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopStringResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe7\xbb\x93\xe6\x9e\x9c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe7\xbb\x93\xe6\x9e\x9c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x94\x99\xe8\xaf\xaf\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x94\x99\xe8\xaf\xaf\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopStringResult constinit property declarations **************
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Data;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopStringResult constinit property declarations ****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopStringResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopStringResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopStringResult;
class UScriptStruct* FDesktopStringResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopStringResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopStringResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopStringResult, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopStringResult"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopStringResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopStringResult Property Definitions *************************
void Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((FDesktopStringResult*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopStringResult), &Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSuccess_MetaData), NewProp_bSuccess_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopStringResult, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopStringResult, Data), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Data_MetaData), NewProp_Data_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopStringResult, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopStringResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewProp_Data,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopStringResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopStringResult Property Definitions ***************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopStringResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopStringResult",
	Z_Construct_UScriptStruct_FDesktopStringResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopStringResult_Statics::PropPointers),
	sizeof(FDesktopStringResult),
	alignof(FDesktopStringResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopStringResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopStringResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopStringResult()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopStringResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopStringResult.InnerSingleton, Z_Construct_UScriptStruct_FDesktopStringResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopStringResult.InnerSingleton);
}
// ********** End ScriptStruct FDesktopStringResult ************************************************

// ********** Begin ScriptStruct FDesktopBytesResult ***********************************************
struct Z_Construct_UScriptStruct_FDesktopBytesResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopBytesResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopBytesResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe7\xbb\x93\xe6\x9e\x9c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe7\xbb\x93\xe6\x9e\x9c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x94\x99\xe8\xaf\xaf\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x94\x99\xe8\xaf\xaf\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopBytesResult constinit property declarations ***************
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Data_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Data;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopBytesResult constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopBytesResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopBytesResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopBytesResult;
class UScriptStruct* FDesktopBytesResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopBytesResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopBytesResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopBytesResult, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopBytesResult"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopBytesResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopBytesResult Property Definitions **************************
void Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((FDesktopBytesResult*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FDesktopBytesResult), &Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSuccess_MetaData), NewProp_bSuccess_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopBytesResult, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_Data_Inner = { "Data", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopBytesResult, Data), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Data_MetaData), NewProp_Data_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopBytesResult, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_Data_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_Data,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopBytesResult Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopBytesResult",
	Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::PropPointers),
	sizeof(FDesktopBytesResult),
	alignof(FDesktopBytesResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopBytesResult()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopBytesResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopBytesResult.InnerSingleton, Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopBytesResult.InnerSingleton);
}
// ********** End ScriptStruct FDesktopBytesResult *************************************************

// ********** Begin ScriptStruct FDesktopHardwareSnapshot ******************************************
struct Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FDesktopHardwareSnapshot); }
	static inline consteval int16 GetStructAlignment() { return alignof(FDesktopHardwareSnapshot); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xa1\xac\xe4\xbb\xb6Snapshot\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe6\xa1\x8c\xe9\x9d\xa2\xe7\xa1\xac\xe4\xbb\xb6Snapshot\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CaptureTimeSeconds_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Capture\xe6\x97\xb6\xe9\x97\xb4\xe7\xa7\x92\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Capture\xe6\x97\xb6\xe9\x97\xb4\xe7\xa7\x92\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ApplicationInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemPathInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xb7\xaf\xe5\xbe\x84\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xb7\xaf\xe5\xbe\x84\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MainWindowInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Main\xe7\xaa\x97\xe5\x8f\xa3\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Main\xe7\xaa\x97\xe5\x8f\xa3\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CPUInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""CPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""CPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GPUInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98GPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98GPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GPUMemoryInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MemoryInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectDiskInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe7\xa3\x81\xe7\x9b\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe7\xa3\x81\xe7\x9b\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DiskInfos_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xa3\x81\xe7\x9b\x98\xe4\xbf\xa1\xe6\x81\xaf\xe5\x88\x97\xe8\xa1\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xa3\x81\xe7\x9b\x98\xe4\xbf\xa1\xe6\x81\xaf\xe5\x88\x97\xe8\xa1\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PowerInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xba\x90\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xba\x90\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NetworkInfo_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NetworkAdapters_MetaData[] = {
		{ "Category", "Desktop Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe7\xbb\x9c""Adapters\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/DesktopType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe7\xbb\x9c""Adapters\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FDesktopHardwareSnapshot constinit property declarations **********
	static const UECodeGen_Private::FDoublePropertyParams NewProp_CaptureTimeSeconds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ApplicationInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SystemPathInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DisplayInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MainWindowInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CPUInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GPUInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GPUMemoryInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MemoryInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectDiskInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DiskInfos_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_DiskInfos;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PowerInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NetworkInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NetworkAdapters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NetworkAdapters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FDesktopHardwareSnapshot constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FDesktopHardwareSnapshot>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FDesktopHardwareSnapshot;
class UScriptStruct* FDesktopHardwareSnapshot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopHardwareSnapshot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FDesktopHardwareSnapshot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FDesktopHardwareSnapshot, (UObject*)Z_Construct_UPackage__Script_GenericDesktopFramework(), TEXT("DesktopHardwareSnapshot"));
	}
	return Z_Registration_Info_UScriptStruct_FDesktopHardwareSnapshot.OuterSingleton;
	}

// ********** Begin ScriptStruct FDesktopHardwareSnapshot Property Definitions *********************
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_CaptureTimeSeconds = { "CaptureTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, CaptureTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CaptureTimeSeconds_MetaData), NewProp_CaptureTimeSeconds_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_ApplicationInfo = { "ApplicationInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, ApplicationInfo), Z_Construct_UScriptStruct_FDesktopApplicationInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ApplicationInfo_MetaData), NewProp_ApplicationInfo_MetaData) }; // 3859191725
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_SystemPathInfo = { "SystemPathInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, SystemPathInfo), Z_Construct_UScriptStruct_FDesktopSystemPathInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemPathInfo_MetaData), NewProp_SystemPathInfo_MetaData) }; // 2957347215
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_DisplayInfo = { "DisplayInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, DisplayInfo), Z_Construct_UScriptStruct_FDesktopDisplayInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayInfo_MetaData), NewProp_DisplayInfo_MetaData) }; // 1657045473
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_MainWindowInfo = { "MainWindowInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, MainWindowInfo), Z_Construct_UScriptStruct_FDesktopMainWindowInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MainWindowInfo_MetaData), NewProp_MainWindowInfo_MetaData) }; // 3579282865
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_CPUInfo = { "CPUInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, CPUInfo), Z_Construct_UScriptStruct_FDesktopCPUInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CPUInfo_MetaData), NewProp_CPUInfo_MetaData) }; // 2400951084
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_GPUInfo = { "GPUInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, GPUInfo), Z_Construct_UScriptStruct_FDesktopGPUInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GPUInfo_MetaData), NewProp_GPUInfo_MetaData) }; // 2697188576
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_GPUMemoryInfo = { "GPUMemoryInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, GPUMemoryInfo), Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GPUMemoryInfo_MetaData), NewProp_GPUMemoryInfo_MetaData) }; // 128937207
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_MemoryInfo = { "MemoryInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, MemoryInfo), Z_Construct_UScriptStruct_FDesktopMemoryInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MemoryInfo_MetaData), NewProp_MemoryInfo_MetaData) }; // 1857295326
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_ProjectDiskInfo = { "ProjectDiskInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, ProjectDiskInfo), Z_Construct_UScriptStruct_FDesktopDiskInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectDiskInfo_MetaData), NewProp_ProjectDiskInfo_MetaData) }; // 1522185633
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_DiskInfos_Inner = { "DiskInfos", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDesktopDiskInfo, METADATA_PARAMS(0, nullptr) }; // 1522185633
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_DiskInfos = { "DiskInfos", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, DiskInfos), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DiskInfos_MetaData), NewProp_DiskInfos_MetaData) }; // 1522185633
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_PowerInfo = { "PowerInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, PowerInfo), Z_Construct_UScriptStruct_FDesktopPowerInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PowerInfo_MetaData), NewProp_PowerInfo_MetaData) }; // 2907703197
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_NetworkInfo = { "NetworkInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, NetworkInfo), Z_Construct_UScriptStruct_FDesktopNetworkInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NetworkInfo_MetaData), NewProp_NetworkInfo_MetaData) }; // 251845637
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_NetworkAdapters_Inner = { "NetworkAdapters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo, METADATA_PARAMS(0, nullptr) }; // 3376853757
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_NetworkAdapters = { "NetworkAdapters", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FDesktopHardwareSnapshot, NetworkAdapters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NetworkAdapters_MetaData), NewProp_NetworkAdapters_MetaData) }; // 3376853757
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_CaptureTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_ApplicationInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_SystemPathInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_DisplayInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_MainWindowInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_CPUInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_GPUInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_GPUMemoryInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_MemoryInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_ProjectDiskInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_DiskInfos_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_DiskInfos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_PowerInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_NetworkInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_NetworkAdapters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewProp_NetworkAdapters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FDesktopHardwareSnapshot Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
	nullptr,
	&NewStructOps,
	"DesktopHardwareSnapshot",
	Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::PropPointers),
	sizeof(FDesktopHardwareSnapshot),
	alignof(FDesktopHardwareSnapshot),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FDesktopHardwareSnapshot()
{
	if (!Z_Registration_Info_UScriptStruct_FDesktopHardwareSnapshot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FDesktopHardwareSnapshot.InnerSingleton, Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FDesktopHardwareSnapshot.InnerSingleton);
}
// ********** End ScriptStruct FDesktopHardwareSnapshot ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_Type_DesktopType_h__Script_GenericDesktopFramework_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EDesktopImageFormat_StaticEnum, TEXT("EDesktopImageFormat"), &Z_Registration_Info_UEnum_EDesktopImageFormat, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2623952161U) },
		{ EDesktopTextEncodingOptions_StaticEnum, TEXT("EDesktopTextEncodingOptions"), &Z_Registration_Info_UEnum_EDesktopTextEncodingOptions, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2503097535U) },
		{ EDesktopBatteryState_StaticEnum, TEXT("EDesktopBatteryState"), &Z_Registration_Info_UEnum_EDesktopBatteryState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 73634874U) },
		{ EDesktopPowerLineStatus_StaticEnum, TEXT("EDesktopPowerLineStatus"), &Z_Registration_Info_UEnum_EDesktopPowerLineStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2562197675U) },
		{ EDesktopNetworkType_StaticEnum, TEXT("EDesktopNetworkType"), &Z_Registration_Info_UEnum_EDesktopNetworkType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1283303553U) },
		{ EDesktopDisplayOrientation_StaticEnum, TEXT("EDesktopDisplayOrientation"), &Z_Registration_Info_UEnum_EDesktopDisplayOrientation, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2902332089U) },
		{ EDesktopDisplayMode_StaticEnum, TEXT("EDesktopDisplayMode"), &Z_Registration_Info_UEnum_EDesktopDisplayMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 59183459U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FDesktopApplicationInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopApplicationInfo_Statics::NewStructOps, TEXT("DesktopApplicationInfo"),&Z_Registration_Info_UScriptStruct_FDesktopApplicationInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopApplicationInfo), 3859191725U) },
		{ FDesktopSystemPathInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopSystemPathInfo_Statics::NewStructOps, TEXT("DesktopSystemPathInfo"),&Z_Registration_Info_UScriptStruct_FDesktopSystemPathInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopSystemPathInfo), 2957347215U) },
		{ FDesktopMonitorInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopMonitorInfo_Statics::NewStructOps, TEXT("DesktopMonitorInfo"),&Z_Registration_Info_UScriptStruct_FDesktopMonitorInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopMonitorInfo), 1496936958U) },
		{ FDesktopDisplayInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopDisplayInfo_Statics::NewStructOps, TEXT("DesktopDisplayInfo"),&Z_Registration_Info_UScriptStruct_FDesktopDisplayInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopDisplayInfo), 1657045473U) },
		{ FDesktopMainWindowInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopMainWindowInfo_Statics::NewStructOps, TEXT("DesktopMainWindowInfo"),&Z_Registration_Info_UScriptStruct_FDesktopMainWindowInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopMainWindowInfo), 3579282865U) },
		{ FDesktopCPUInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopCPUInfo_Statics::NewStructOps, TEXT("DesktopCPUInfo"),&Z_Registration_Info_UScriptStruct_FDesktopCPUInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopCPUInfo), 2400951084U) },
		{ FDesktopGPUInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopGPUInfo_Statics::NewStructOps, TEXT("DesktopGPUInfo"),&Z_Registration_Info_UScriptStruct_FDesktopGPUInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopGPUInfo), 2697188576U) },
		{ FDesktopGPUMemoryInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo_Statics::NewStructOps, TEXT("DesktopGPUMemoryInfo"),&Z_Registration_Info_UScriptStruct_FDesktopGPUMemoryInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopGPUMemoryInfo), 128937207U) },
		{ FDesktopMemoryInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopMemoryInfo_Statics::NewStructOps, TEXT("DesktopMemoryInfo"),&Z_Registration_Info_UScriptStruct_FDesktopMemoryInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopMemoryInfo), 1857295326U) },
		{ FDesktopDiskInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopDiskInfo_Statics::NewStructOps, TEXT("DesktopDiskInfo"),&Z_Registration_Info_UScriptStruct_FDesktopDiskInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopDiskInfo), 1522185633U) },
		{ FDesktopPowerInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopPowerInfo_Statics::NewStructOps, TEXT("DesktopPowerInfo"),&Z_Registration_Info_UScriptStruct_FDesktopPowerInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopPowerInfo), 2907703197U) },
		{ FDesktopNetworkAdapterIp::StaticStruct, Z_Construct_UScriptStruct_FDesktopNetworkAdapterIp_Statics::NewStructOps, TEXT("DesktopNetworkAdapterIp"),&Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterIp, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopNetworkAdapterIp), 90853674U) },
		{ FDesktopNetworkAdapterInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo_Statics::NewStructOps, TEXT("DesktopNetworkAdapterInfo"),&Z_Registration_Info_UScriptStruct_FDesktopNetworkAdapterInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopNetworkAdapterInfo), 3376853757U) },
		{ FDesktopNetworkInfo::StaticStruct, Z_Construct_UScriptStruct_FDesktopNetworkInfo_Statics::NewStructOps, TEXT("DesktopNetworkInfo"),&Z_Registration_Info_UScriptStruct_FDesktopNetworkInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopNetworkInfo), 251845637U) },
		{ FDesktopDialogResult::StaticStruct, Z_Construct_UScriptStruct_FDesktopDialogResult_Statics::NewStructOps, TEXT("DesktopDialogResult"),&Z_Registration_Info_UScriptStruct_FDesktopDialogResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopDialogResult), 2546226925U) },
		{ FDesktopStringResult::StaticStruct, Z_Construct_UScriptStruct_FDesktopStringResult_Statics::NewStructOps, TEXT("DesktopStringResult"),&Z_Registration_Info_UScriptStruct_FDesktopStringResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopStringResult), 3654214038U) },
		{ FDesktopBytesResult::StaticStruct, Z_Construct_UScriptStruct_FDesktopBytesResult_Statics::NewStructOps, TEXT("DesktopBytesResult"),&Z_Registration_Info_UScriptStruct_FDesktopBytesResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopBytesResult), 1985964648U) },
		{ FDesktopHardwareSnapshot::StaticStruct, Z_Construct_UScriptStruct_FDesktopHardwareSnapshot_Statics::NewStructOps, TEXT("DesktopHardwareSnapshot"),&Z_Registration_Info_UScriptStruct_FDesktopHardwareSnapshot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FDesktopHardwareSnapshot), 369114559U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_Type_DesktopType_h__Script_GenericDesktopFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_Type_DesktopType_h__Script_GenericDesktopFramework_343174438{
	TEXT("/Script/GenericDesktopFramework"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_Type_DesktopType_h__Script_GenericDesktopFramework_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_Type_DesktopType_h__Script_GenericDesktopFramework_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_Type_DesktopType_h__Script_GenericDesktopFramework_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_Type_DesktopType_h__Script_GenericDesktopFramework_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
