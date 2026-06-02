// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Type/AndroidType.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAndroidType() {}

// ********** Begin Cross Module References ********************************************************
GENERICANDROIDFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState();
GENERICANDROIDFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission();
GENERICANDROIDFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType();
GENERICANDROIDFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel();
GENERICANDROIDFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType();
GENERICANDROIDFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState();
GENERICANDROIDFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidAppInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidBatteryInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidCapabilityInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidCPUInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidDeviceInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidDisplayInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidGPUInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidHardwareSnapshot();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidIdInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidMemoryInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidNetworkInfo();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidStorageInfo();
UPackage* Z_Construct_UPackage__Script_GenericAndroidFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EAndroidPermissionState ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAndroidPermissionState;
static UEnum* EAndroidPermissionState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAndroidPermissionState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAndroidPermissionState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("EAndroidPermissionState"));
	}
	return Z_Registration_Info_UEnum_EAndroidPermissionState.OuterSingleton;
}
template<> GENERICANDROIDFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EAndroidPermissionState>()
{
	return EAndroidPermissionState_StaticEnum();
}
struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""Android\xe6\x9d\x83\xe9\x99\x90\xe7\x8a\xb6\xe6\x80\x81\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "Denied.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""Denied\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Denied.Name", "EAndroidPermissionState::Denied" },
		{ "Denied.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""Denied\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "Granted.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaGranted\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Granted.Name", "EAndroidPermissionState::Granted" },
		{ "Granted.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaGranted\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""Android\xe6\x9d\x83\xe9\x99\x90\xe7\x8a\xb6\xe6\x80\x81\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Unknown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Unknown.Name", "EAndroidPermissionState::Unknown" },
		{ "Unknown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAndroidPermissionState::Unknown", (int64)EAndroidPermissionState::Unknown },
		{ "EAndroidPermissionState::Granted", (int64)EAndroidPermissionState::Granted },
		{ "EAndroidPermissionState::Denied", (int64)EAndroidPermissionState::Denied },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	"EAndroidPermissionState",
	"EAndroidPermissionState",
	Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState()
{
	if (!Z_Registration_Info_UEnum_EAndroidPermissionState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAndroidPermissionState.InnerSingleton, Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAndroidPermissionState.InnerSingleton;
}
// ********** End Enum EAndroidPermissionState *****************************************************

// ********** Begin Enum EAndroidNetworkType *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAndroidNetworkType;
static UEnum* EAndroidNetworkType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAndroidNetworkType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAndroidNetworkType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("EAndroidNetworkType"));
	}
	return Z_Registration_Info_UEnum_EAndroidNetworkType.OuterSingleton;
}
template<> GENERICANDROIDFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EAndroidNetworkType>()
{
	return EAndroidNetworkType_StaticEnum();
}
struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AirplaneMode.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe9\xa3\x9e\xe8\xa1\x8c\xe6\xa8\xa1\xe5\xbc\x8f\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "AirplaneMode.Name", "EAndroidNetworkType::AirplaneMode" },
		{ "AirplaneMode.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe9\xa3\x9e\xe8\xa1\x8c\xe6\xa8\xa1\xe5\xbc\x8f\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "BlueprintType", "true" },
		{ "Bluetooth.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Bluetooth.Name", "EAndroidNetworkType::Bluetooth" },
		{ "Bluetooth.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "Cell.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x8d\x95\xe5\x85\x83\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Cell.Name", "EAndroidNetworkType::Cell" },
		{ "Cell.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x8d\x95\xe5\x85\x83\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""Android\xe7\xbd\x91\xe7\xbb\x9c\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "Ethernet.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xbb\xa5\xe5\xa4\xaa\xe7\xbd\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Ethernet.Name", "EAndroidNetworkType::Ethernet" },
		{ "Ethernet.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xbb\xa5\xe5\xa4\xaa\xe7\xbd\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
		{ "None.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x97\xa0\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "None.Name", "EAndroidNetworkType::None" },
		{ "None.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x97\xa0\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""Android\xe7\xbd\x91\xe7\xbb\x9c\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Unknown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Unknown.Name", "EAndroidNetworkType::Unknown" },
		{ "Unknown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "WiFi.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaWi-Fi\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "WiFi.Name", "EAndroidNetworkType::WiFi" },
		{ "WiFi.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaWi-Fi\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "WiMAX.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaWiMAX\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "WiMAX.Name", "EAndroidNetworkType::WiMAX" },
		{ "WiMAX.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaWiMAX\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAndroidNetworkType::Unknown", (int64)EAndroidNetworkType::Unknown },
		{ "EAndroidNetworkType::None", (int64)EAndroidNetworkType::None },
		{ "EAndroidNetworkType::AirplaneMode", (int64)EAndroidNetworkType::AirplaneMode },
		{ "EAndroidNetworkType::Cell", (int64)EAndroidNetworkType::Cell },
		{ "EAndroidNetworkType::WiFi", (int64)EAndroidNetworkType::WiFi },
		{ "EAndroidNetworkType::WiMAX", (int64)EAndroidNetworkType::WiMAX },
		{ "EAndroidNetworkType::Bluetooth", (int64)EAndroidNetworkType::Bluetooth },
		{ "EAndroidNetworkType::Ethernet", (int64)EAndroidNetworkType::Ethernet },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	"EAndroidNetworkType",
	"EAndroidNetworkType",
	Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType()
{
	if (!Z_Registration_Info_UEnum_EAndroidNetworkType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAndroidNetworkType.InnerSingleton, Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAndroidNetworkType.InnerSingleton;
}
// ********** End Enum EAndroidNetworkType *********************************************************

// ********** Begin Enum EAndroidBatteryState ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAndroidBatteryState;
static UEnum* EAndroidBatteryState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAndroidBatteryState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAndroidBatteryState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("EAndroidBatteryState"));
	}
	return Z_Registration_Info_UEnum_EAndroidBatteryState.OuterSingleton;
}
template<> GENERICANDROIDFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EAndroidBatteryState>()
{
	return EAndroidBatteryState_StaticEnum();
}
struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Charging.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x85\x85\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Charging.Name", "EAndroidBatteryState::Charging" },
		{ "Charging.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x85\x85\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""Android\xe7\x94\xb5\xe6\xb1\xa0\xe7\x8a\xb6\xe6\x80\x81\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "Discharging.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x94\xbe\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Discharging.Name", "EAndroidBatteryState::Discharging" },
		{ "Discharging.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x94\xbe\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "Full.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xbb\xa1\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Full.Name", "EAndroidBatteryState::Full" },
		{ "Full.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xbb\xa1\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
		{ "NotCharging.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe5\x85\x85\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "NotCharging.Name", "EAndroidBatteryState::NotCharging" },
		{ "NotCharging.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe5\x85\x85\xe7\x94\xb5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""Android\xe7\x94\xb5\xe6\xb1\xa0\xe7\x8a\xb6\xe6\x80\x81\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Unknown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Unknown.Name", "EAndroidBatteryState::Unknown" },
		{ "Unknown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAndroidBatteryState::Unknown", (int64)EAndroidBatteryState::Unknown },
		{ "EAndroidBatteryState::Charging", (int64)EAndroidBatteryState::Charging },
		{ "EAndroidBatteryState::Discharging", (int64)EAndroidBatteryState::Discharging },
		{ "EAndroidBatteryState::NotCharging", (int64)EAndroidBatteryState::NotCharging },
		{ "EAndroidBatteryState::Full", (int64)EAndroidBatteryState::Full },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	"EAndroidBatteryState",
	"EAndroidBatteryState",
	Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState()
{
	if (!Z_Registration_Info_UEnum_EAndroidBatteryState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAndroidBatteryState.InnerSingleton, Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAndroidBatteryState.InnerSingleton;
}
// ********** End Enum EAndroidBatteryState ********************************************************

// ********** Begin Enum EAndroidMemoryPressureLevel ***********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAndroidMemoryPressureLevel;
static UEnum* EAndroidMemoryPressureLevel_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAndroidMemoryPressureLevel.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAndroidMemoryPressureLevel.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("EAndroidMemoryPressureLevel"));
	}
	return Z_Registration_Info_UEnum_EAndroidMemoryPressureLevel.OuterSingleton;
}
template<> GENERICANDROIDFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EAndroidMemoryPressureLevel>()
{
	return EAndroidMemoryPressureLevel_StaticEnum();
}
struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""Android\xe5\x86\x85\xe5\xad\x98Pressure\xe5\x85\xb3\xe5\x8d\xa1\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "Critical.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""Critical\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Critical.Name", "EAndroidMemoryPressureLevel::Critical" },
		{ "Critical.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""Critical\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
		{ "Normal.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x99\xae\xe9\x80\x9a\xe7\x8a\xb6\xe6\x80\x81\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Normal.Name", "EAndroidMemoryPressureLevel::Normal" },
		{ "Normal.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x99\xae\xe9\x80\x9a\xe7\x8a\xb6\xe6\x80\x81\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""Android\xe5\x86\x85\xe5\xad\x98Pressure\xe5\x85\xb3\xe5\x8d\xa1\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Unknown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Unknown.Name", "EAndroidMemoryPressureLevel::Unknown" },
		{ "Unknown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "Warning.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaWarning\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Warning.Name", "EAndroidMemoryPressureLevel::Warning" },
		{ "Warning.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaWarning\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAndroidMemoryPressureLevel::Unknown", (int64)EAndroidMemoryPressureLevel::Unknown },
		{ "EAndroidMemoryPressureLevel::Normal", (int64)EAndroidMemoryPressureLevel::Normal },
		{ "EAndroidMemoryPressureLevel::Warning", (int64)EAndroidMemoryPressureLevel::Warning },
		{ "EAndroidMemoryPressureLevel::Critical", (int64)EAndroidMemoryPressureLevel::Critical },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	"EAndroidMemoryPressureLevel",
	"EAndroidMemoryPressureLevel",
	Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel()
{
	if (!Z_Registration_Info_UEnum_EAndroidMemoryPressureLevel.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAndroidMemoryPressureLevel.InnerSingleton, Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAndroidMemoryPressureLevel.InnerSingleton;
}
// ********** End Enum EAndroidMemoryPressureLevel *************************************************

// ********** Begin Enum EAndroidScreenOrientationType *********************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAndroidScreenOrientationType;
static UEnum* EAndroidScreenOrientationType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAndroidScreenOrientationType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAndroidScreenOrientationType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("EAndroidScreenOrientationType"));
	}
	return Z_Registration_Info_UEnum_EAndroidScreenOrientationType.OuterSingleton;
}
template<> GENERICANDROIDFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EAndroidScreenOrientationType>()
{
	return EAndroidScreenOrientationType_StaticEnum();
}
struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""Android Screen\xe6\x96\xb9\xe5\x90\x91\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "FaceDown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""Face\xe5\x90\x91\xe4\xb8\x8b\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "FaceDown.Name", "EAndroidScreenOrientationType::FaceDown" },
		{ "FaceDown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""Face\xe5\x90\x91\xe4\xb8\x8b\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "FaceUp.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""Face Up\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "FaceUp.Name", "EAndroidScreenOrientationType::FaceUp" },
		{ "FaceUp.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""Face Up\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "FullSensor.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xbb\xa1Sensor\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "FullSensor.Name", "EAndroidScreenOrientationType::FullSensor" },
		{ "FullSensor.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xbb\xa1Sensor\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "LandscapeLeft.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaLandscape Left\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "LandscapeLeft.Name", "EAndroidScreenOrientationType::LandscapeLeft" },
		{ "LandscapeLeft.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaLandscape Left\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "LandscapeRight.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaLandscape\xe5\x90\x91\xe5\x8f\xb3\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "LandscapeRight.Name", "EAndroidScreenOrientationType::LandscapeRight" },
		{ "LandscapeRight.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaLandscape\xe5\x90\x91\xe5\x8f\xb3\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "LandscapeSensor.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaLandscape Sensor\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "LandscapeSensor.Name", "EAndroidScreenOrientationType::LandscapeSensor" },
		{ "LandscapeSensor.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaLandscape Sensor\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
		{ "Portrait.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xb5\xe5\x90\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Portrait.Name", "EAndroidScreenOrientationType::Portrait" },
		{ "Portrait.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xb5\xe5\x90\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "PortraitSensor.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xb5\xe5\x90\x91Sensor\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "PortraitSensor.Name", "EAndroidScreenOrientationType::PortraitSensor" },
		{ "PortraitSensor.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xb5\xe5\x90\x91Sensor\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "PortraitUpsideDown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xb5\xe5\x90\x91Upside\xe5\x90\x91\xe4\xb8\x8b\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "PortraitUpsideDown.Name", "EAndroidScreenOrientationType::PortraitUpsideDown" },
		{ "PortraitUpsideDown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xb5\xe5\x90\x91Upside\xe5\x90\x91\xe4\xb8\x8b\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""Android Screen\xe6\x96\xb9\xe5\x90\x91\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Unknown.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Unknown.Name", "EAndroidScreenOrientationType::Unknown" },
		{ "Unknown.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\xaa\xe7\x9f\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAndroidScreenOrientationType::Unknown", (int64)EAndroidScreenOrientationType::Unknown },
		{ "EAndroidScreenOrientationType::Portrait", (int64)EAndroidScreenOrientationType::Portrait },
		{ "EAndroidScreenOrientationType::PortraitUpsideDown", (int64)EAndroidScreenOrientationType::PortraitUpsideDown },
		{ "EAndroidScreenOrientationType::LandscapeLeft", (int64)EAndroidScreenOrientationType::LandscapeLeft },
		{ "EAndroidScreenOrientationType::LandscapeRight", (int64)EAndroidScreenOrientationType::LandscapeRight },
		{ "EAndroidScreenOrientationType::FaceUp", (int64)EAndroidScreenOrientationType::FaceUp },
		{ "EAndroidScreenOrientationType::FaceDown", (int64)EAndroidScreenOrientationType::FaceDown },
		{ "EAndroidScreenOrientationType::PortraitSensor", (int64)EAndroidScreenOrientationType::PortraitSensor },
		{ "EAndroidScreenOrientationType::LandscapeSensor", (int64)EAndroidScreenOrientationType::LandscapeSensor },
		{ "EAndroidScreenOrientationType::FullSensor", (int64)EAndroidScreenOrientationType::FullSensor },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	"EAndroidScreenOrientationType",
	"EAndroidScreenOrientationType",
	Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType()
{
	if (!Z_Registration_Info_UEnum_EAndroidScreenOrientationType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAndroidScreenOrientationType.InnerSingleton, Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAndroidScreenOrientationType.InnerSingleton;
}
// ********** End Enum EAndroidScreenOrientationType ***********************************************

// ********** Begin Enum EAndroidHapticType ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAndroidHapticType;
static UEnum* EAndroidHapticType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAndroidHapticType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAndroidHapticType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("EAndroidHapticType"));
	}
	return Z_Registration_Info_UEnum_EAndroidHapticType.OuterSingleton;
}
template<> GENERICANDROIDFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EAndroidHapticType>()
{
	return EAndroidHapticType_StaticEnum();
}
struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""Android Haptic\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "FeedbackError.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""Feedback\xe9\x94\x99\xe8\xaf\xaf\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "FeedbackError.Name", "EAndroidHapticType::FeedbackError" },
		{ "FeedbackError.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""Feedback\xe9\x94\x99\xe8\xaf\xaf\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "FeedbackSuccess.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""Feedback\xe6\x88\x90\xe5\x8a\x9f\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "FeedbackSuccess.Name", "EAndroidHapticType::FeedbackSuccess" },
		{ "FeedbackSuccess.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""Feedback\xe6\x88\x90\xe5\x8a\x9f\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "FeedbackWarning.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""Feedback Warning\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "FeedbackWarning.Name", "EAndroidHapticType::FeedbackWarning" },
		{ "FeedbackWarning.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""Feedback Warning\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ImpactHeavy.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaImpact Heavy\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ImpactHeavy.Name", "EAndroidHapticType::ImpactHeavy" },
		{ "ImpactHeavy.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaImpact Heavy\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ImpactLight.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaImpact Light\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ImpactLight.Name", "EAndroidHapticType::ImpactLight" },
		{ "ImpactLight.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaImpact Light\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ImpactMedium.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaImpact Medium\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ImpactMedium.Name", "EAndroidHapticType::ImpactMedium" },
		{ "ImpactMedium.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaImpact Medium\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
		{ "SelectionChanged.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe9\x80\x89\xe4\xb8\xad""Changed\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "SelectionChanged.Name", "EAndroidHapticType::SelectionChanged" },
		{ "SelectionChanged.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe9\x80\x89\xe4\xb8\xad""Changed\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""Android Haptic\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAndroidHapticType::FeedbackSuccess", (int64)EAndroidHapticType::FeedbackSuccess },
		{ "EAndroidHapticType::FeedbackWarning", (int64)EAndroidHapticType::FeedbackWarning },
		{ "EAndroidHapticType::FeedbackError", (int64)EAndroidHapticType::FeedbackError },
		{ "EAndroidHapticType::SelectionChanged", (int64)EAndroidHapticType::SelectionChanged },
		{ "EAndroidHapticType::ImpactLight", (int64)EAndroidHapticType::ImpactLight },
		{ "EAndroidHapticType::ImpactMedium", (int64)EAndroidHapticType::ImpactMedium },
		{ "EAndroidHapticType::ImpactHeavy", (int64)EAndroidHapticType::ImpactHeavy },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	"EAndroidHapticType",
	"EAndroidHapticType",
	Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType()
{
	if (!Z_Registration_Info_UEnum_EAndroidHapticType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAndroidHapticType.InnerSingleton, Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAndroidHapticType.InnerSingleton;
}
// ********** End Enum EAndroidHapticType **********************************************************

// ********** Begin Enum EAndroidCommonPermission **************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EAndroidCommonPermission;
static UEnum* EAndroidCommonPermission_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EAndroidCommonPermission.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EAndroidCommonPermission.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("EAndroidCommonPermission"));
	}
	return Z_Registration_Info_UEnum_EAndroidCommonPermission.OuterSingleton;
}
template<> GENERICANDROIDFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EAndroidCommonPermission>()
{
	return EAndroidCommonPermission_StaticEnum();
}
struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "AccessCoarseLocation.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xae\xbf\xe9\x97\xae""Coarse\xe4\xbd\x8d\xe7\xbd\xae\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "AccessCoarseLocation.Name", "EAndroidCommonPermission::AccessCoarseLocation" },
		{ "AccessCoarseLocation.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xae\xbf\xe9\x97\xae""Coarse\xe4\xbd\x8d\xe7\xbd\xae\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "AccessFineLocation.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xae\xbf\xe9\x97\xae""Fine\xe4\xbd\x8d\xe7\xbd\xae\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "AccessFineLocation.Name", "EAndroidCommonPermission::AccessFineLocation" },
		{ "AccessFineLocation.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xae\xbf\xe9\x97\xae""Fine\xe4\xbd\x8d\xe7\xbd\xae\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "AccessWifiState.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xae\xbf\xe9\x97\xaeWi-Fi\xe7\x8a\xb6\xe6\x80\x81\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "AccessWifiState.Name", "EAndroidCommonPermission::AccessWifiState" },
		{ "AccessWifiState.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xae\xbf\xe9\x97\xaeWi-Fi\xe7\x8a\xb6\xe6\x80\x81\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "BlueprintType", "true" },
		{ "Bluetooth.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Bluetooth.Name", "EAndroidCommonPermission::Bluetooth" },
		{ "Bluetooth.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "BluetoothAdmin.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99""Admin\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "BluetoothAdmin.Name", "EAndroidCommonPermission::BluetoothAdmin" },
		{ "BluetoothAdmin.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99""Admin\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "BluetoothAdvertise.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99""Advertise\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "BluetoothAdvertise.Name", "EAndroidCommonPermission::BluetoothAdvertise" },
		{ "BluetoothAdvertise.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99""Advertise\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "BluetoothConnect.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99\xe8\xbf\x9e\xe6\x8e\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "BluetoothConnect.Name", "EAndroidCommonPermission::BluetoothConnect" },
		{ "BluetoothConnect.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99\xe8\xbf\x9e\xe6\x8e\xa5\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "BluetoothScan.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99Scan\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "BluetoothScan.Name", "EAndroidCommonPermission::BluetoothScan" },
		{ "BluetoothScan.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\x93\x9d\xe7\x89\x99Scan\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "BodySensors.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""Body Sensors\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "BodySensors.Name", "EAndroidCommonPermission::BodySensors" },
		{ "BodySensors.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""Body Sensors\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "Camera.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\x9b\xb8\xe6\x9c\xba\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Camera.Name", "EAndroidCommonPermission::Camera" },
		{ "Camera.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\x9b\xb8\xe6\x9c\xba\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ChangeWifiState.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba""Change Wi-Fi\xe7\x8a\xb6\xe6\x80\x81\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ChangeWifiState.Name", "EAndroidCommonPermission::ChangeWifiState" },
		{ "ChangeWifiState.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba""Change Wi-Fi\xe7\x8a\xb6\xe6\x80\x81\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""Android Common\xe6\x9d\x83\xe9\x99\x90\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "Internet.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaInternet\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Internet.Name", "EAndroidCommonPermission::Internet" },
		{ "Internet.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaInternet\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
		{ "Nfc.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaNfc\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Nfc.Name", "EAndroidCommonPermission::Nfc" },
		{ "Nfc.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaNfc\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "PostNotifications.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaPost Notifications\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "PostNotifications.Name", "EAndroidCommonPermission::PostNotifications" },
		{ "PostNotifications.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaPost Notifications\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ReadExternalStorage.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xbb\xe5\x8f\x96\xe5\xa4\x96\xe9\x83\xa8Storage\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ReadExternalStorage.Name", "EAndroidCommonPermission::ReadExternalStorage" },
		{ "ReadExternalStorage.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xbb\xe5\x8f\x96\xe5\xa4\x96\xe9\x83\xa8Storage\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ReadMediaAudio.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xbb\xe5\x8f\x96\xe5\xaa\x92\xe4\xbd\x93\xe9\x9f\xb3\xe9\xa2\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ReadMediaAudio.Name", "EAndroidCommonPermission::ReadMediaAudio" },
		{ "ReadMediaAudio.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xbb\xe5\x8f\x96\xe5\xaa\x92\xe4\xbd\x93\xe9\x9f\xb3\xe9\xa2\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ReadMediaImages.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xbb\xe5\x8f\x96\xe5\xaa\x92\xe4\xbd\x93Images\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ReadMediaImages.Name", "EAndroidCommonPermission::ReadMediaImages" },
		{ "ReadMediaImages.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xbb\xe5\x8f\x96\xe5\xaa\x92\xe4\xbd\x93Images\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ReadMediaVideo.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xbb\xe5\x8f\x96\xe5\xaa\x92\xe4\xbd\x93\xe8\xa7\x86\xe9\xa2\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ReadMediaVideo.Name", "EAndroidCommonPermission::ReadMediaVideo" },
		{ "ReadMediaVideo.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xbb\xe5\x8f\x96\xe5\xaa\x92\xe4\xbd\x93\xe8\xa7\x86\xe9\xa2\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "ReadPhoneState.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xbb\xe5\x8f\x96Phone\xe7\x8a\xb6\xe6\x80\x81\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "ReadPhoneState.Name", "EAndroidCommonPermission::ReadPhoneState" },
		{ "ReadPhoneState.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xaf\xbb\xe5\x8f\x96Phone\xe7\x8a\xb6\xe6\x80\x81\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "RecordAudio.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaRecord\xe9\x9f\xb3\xe9\xa2\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "RecordAudio.Name", "EAndroidCommonPermission::RecordAudio" },
		{ "RecordAudio.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaRecord\xe9\x9f\xb3\xe9\xa2\x91\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""Android Common\xe6\x9d\x83\xe9\x99\x90\xe5\x8f\x96\xe5\x80\xbc\xe3\x80\x82" },
#endif
		{ "Vibrate.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaVibrate\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "Vibrate.Name", "EAndroidCommonPermission::Vibrate" },
		{ "Vibrate.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaVibrate\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "WakeLock.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaWake\xe9\x94\x81\xe5\xae\x9a\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "WakeLock.Name", "EAndroidCommonPermission::WakeLock" },
		{ "WakeLock.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaWake\xe9\x94\x81\xe5\xae\x9a\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
		{ "WriteExternalStorage.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x86\x99\xe5\x85\xa5\xe5\xa4\x96\xe9\x83\xa8Storage\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82 */" },
		{ "WriteExternalStorage.Name", "EAndroidCommonPermission::WriteExternalStorage" },
		{ "WriteExternalStorage.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x86\x99\xe5\x85\xa5\xe5\xa4\x96\xe9\x83\xa8Storage\xe9\x80\x89\xe9\xa1\xb9\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EAndroidCommonPermission::Camera", (int64)EAndroidCommonPermission::Camera },
		{ "EAndroidCommonPermission::RecordAudio", (int64)EAndroidCommonPermission::RecordAudio },
		{ "EAndroidCommonPermission::ReadExternalStorage", (int64)EAndroidCommonPermission::ReadExternalStorage },
		{ "EAndroidCommonPermission::WriteExternalStorage", (int64)EAndroidCommonPermission::WriteExternalStorage },
		{ "EAndroidCommonPermission::ReadMediaImages", (int64)EAndroidCommonPermission::ReadMediaImages },
		{ "EAndroidCommonPermission::ReadMediaVideo", (int64)EAndroidCommonPermission::ReadMediaVideo },
		{ "EAndroidCommonPermission::ReadMediaAudio", (int64)EAndroidCommonPermission::ReadMediaAudio },
		{ "EAndroidCommonPermission::PostNotifications", (int64)EAndroidCommonPermission::PostNotifications },
		{ "EAndroidCommonPermission::AccessFineLocation", (int64)EAndroidCommonPermission::AccessFineLocation },
		{ "EAndroidCommonPermission::AccessCoarseLocation", (int64)EAndroidCommonPermission::AccessCoarseLocation },
		{ "EAndroidCommonPermission::AccessWifiState", (int64)EAndroidCommonPermission::AccessWifiState },
		{ "EAndroidCommonPermission::ChangeWifiState", (int64)EAndroidCommonPermission::ChangeWifiState },
		{ "EAndroidCommonPermission::Internet", (int64)EAndroidCommonPermission::Internet },
		{ "EAndroidCommonPermission::Bluetooth", (int64)EAndroidCommonPermission::Bluetooth },
		{ "EAndroidCommonPermission::BluetoothAdmin", (int64)EAndroidCommonPermission::BluetoothAdmin },
		{ "EAndroidCommonPermission::BluetoothConnect", (int64)EAndroidCommonPermission::BluetoothConnect },
		{ "EAndroidCommonPermission::BluetoothScan", (int64)EAndroidCommonPermission::BluetoothScan },
		{ "EAndroidCommonPermission::BluetoothAdvertise", (int64)EAndroidCommonPermission::BluetoothAdvertise },
		{ "EAndroidCommonPermission::WakeLock", (int64)EAndroidCommonPermission::WakeLock },
		{ "EAndroidCommonPermission::Vibrate", (int64)EAndroidCommonPermission::Vibrate },
		{ "EAndroidCommonPermission::ReadPhoneState", (int64)EAndroidCommonPermission::ReadPhoneState },
		{ "EAndroidCommonPermission::BodySensors", (int64)EAndroidCommonPermission::BodySensors },
		{ "EAndroidCommonPermission::Nfc", (int64)EAndroidCommonPermission::Nfc },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	"EAndroidCommonPermission",
	"EAndroidCommonPermission",
	Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission()
{
	if (!Z_Registration_Info_UEnum_EAndroidCommonPermission.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EAndroidCommonPermission.InnerSingleton, Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EAndroidCommonPermission.InnerSingleton;
}
// ********** End Enum EAndroidCommonPermission ****************************************************

// ********** Begin ScriptStruct FAndroidDeviceInfo ************************************************
struct Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidDeviceInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidDeviceInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android\xe8\xae\xbe\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android\xe8\xae\xbe\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Brand_MetaData[] = {
		{ "Category", "AndroidDeviceInfo" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Model_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xa8\xa1\xe5\x9e\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xa8\xa1\xe5\x9e\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProductName_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xba\xa7\xe5\x93\x81\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xba\xa7\xe5\x93\x81\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceBuildNumber_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87\xe6\x9e\x84\xe5\xbb\xba\xe5\x8f\xb7\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87\xe6\x9e\x84\xe5\xbb\xba\xe5\x8f\xb7\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AndroidVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Android \xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Android \xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AndroidMajorVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Android \xe4\xb8\xbb\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Android \xe4\xb8\xbb\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AndroidBuildVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Android \xe6\x9e\x84\xe5\xbb\xba\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Android \xe6\x9e\x84\xe5\xbb\xba\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OSLanguage_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xaf\xad\xe8\xa8\x80\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xaf\xad\xe8\xa8\x80\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultLocale_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xbb\x98\xe8\xae\xa4\xe5\x8c\xba\xe5\x9f\x9f\xe8\xae\xbe\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xbb\x98\xe8\xae\xa4\xe5\x8c\xba\xe5\x9f\x9f\xe8\xae\xbe\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TimeZoneId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x97\xb6\xe9\x97\xb4Zone ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x97\xb6\xe9\x97\xb4Zone ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xae\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidDeviceInfo constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Brand;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Model;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProductName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DeviceBuildNumber;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AndroidVersion;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AndroidMajorVersion;
	static const UECodeGen_Private::FIntPropertyParams NewProp_AndroidBuildVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OSLanguage;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DefaultLocale;
	static const UECodeGen_Private::FStrPropertyParams NewProp_TimeZoneId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ProjectVersion;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidDeviceInfo constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidDeviceInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidDeviceInfo;
class UScriptStruct* FAndroidDeviceInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidDeviceInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidDeviceInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidDeviceInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidDeviceInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidDeviceInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidDeviceInfo Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_Brand = { "Brand", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, Brand), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Brand_MetaData), NewProp_Brand_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_Model = { "Model", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, Model), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Model_MetaData), NewProp_Model_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_ProductName = { "ProductName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, ProductName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProductName_MetaData), NewProp_ProductName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_DeviceBuildNumber = { "DeviceBuildNumber", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, DeviceBuildNumber), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceBuildNumber_MetaData), NewProp_DeviceBuildNumber_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_AndroidVersion = { "AndroidVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, AndroidVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AndroidVersion_MetaData), NewProp_AndroidVersion_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_AndroidMajorVersion = { "AndroidMajorVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, AndroidMajorVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AndroidMajorVersion_MetaData), NewProp_AndroidMajorVersion_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_AndroidBuildVersion = { "AndroidBuildVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, AndroidBuildVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AndroidBuildVersion_MetaData), NewProp_AndroidBuildVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_OSLanguage = { "OSLanguage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, OSLanguage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OSLanguage_MetaData), NewProp_OSLanguage_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_DefaultLocale = { "DefaultLocale", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, DefaultLocale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultLocale_MetaData), NewProp_DefaultLocale_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_TimeZoneId = { "TimeZoneId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, TimeZoneId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TimeZoneId_MetaData), NewProp_TimeZoneId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_ProjectVersion = { "ProjectVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDeviceInfo, ProjectVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectVersion_MetaData), NewProp_ProjectVersion_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_Brand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_Model,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_ProductName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_DeviceBuildNumber,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_AndroidVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_AndroidMajorVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_AndroidBuildVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_OSLanguage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_DefaultLocale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_TimeZoneId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewProp_ProjectVersion,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidDeviceInfo Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidDeviceInfo",
	Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::PropPointers),
	sizeof(FAndroidDeviceInfo),
	alignof(FAndroidDeviceInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidDeviceInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidDeviceInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidDeviceInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidDeviceInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidDeviceInfo **************************************************

// ********** Begin ScriptStruct FAndroidAppInfo ***************************************************
struct Z_Construct_UScriptStruct_FAndroidAppInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidAppInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidAppInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PackageName_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Package\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Package\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionDisplayName_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x89\x88\xe6\x9c\xac\xe6\x98\xbe\xe7\xa4\xba\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x89\x88\xe6\x9c\xac\xe6\x98\xbe\xe7\xa4\xba\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StoreVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x95\x86\xe5\xba\x97\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x95\x86\xe5\xba\x97\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinSDKVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xb0\x8fSDK\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xb0\x8fSDK\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetSDKVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x9b\xae\xe6\xa0\x87 SDK \xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x9b\xae\xe6\xa0\x87 SDK \xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DistributionChannel_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x88\x86\xe5\x8f\x91\xe6\xb8\xa0\xe9\x81\x93\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x88\x86\xe5\x8f\x91\xe6\xb8\xa0\xe9\x81\x93\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidAppInfo constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_PackageName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VersionDisplayName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StoreVersion;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinSDKVersion;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TargetSDKVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DistributionChannel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidAppInfo constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidAppInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidAppInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidAppInfo;
class UScriptStruct* FAndroidAppInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidAppInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidAppInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidAppInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidAppInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidAppInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidAppInfo Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_PackageName = { "PackageName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidAppInfo, PackageName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PackageName_MetaData), NewProp_PackageName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_VersionDisplayName = { "VersionDisplayName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidAppInfo, VersionDisplayName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionDisplayName_MetaData), NewProp_VersionDisplayName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_StoreVersion = { "StoreVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidAppInfo, StoreVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StoreVersion_MetaData), NewProp_StoreVersion_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_MinSDKVersion = { "MinSDKVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidAppInfo, MinSDKVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinSDKVersion_MetaData), NewProp_MinSDKVersion_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_TargetSDKVersion = { "TargetSDKVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidAppInfo, TargetSDKVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetSDKVersion_MetaData), NewProp_TargetSDKVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_DistributionChannel = { "DistributionChannel", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidAppInfo, DistributionChannel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DistributionChannel_MetaData), NewProp_DistributionChannel_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_PackageName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_VersionDisplayName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_StoreVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_MinSDKVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_TargetSDKVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewProp_DistributionChannel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidAppInfo Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidAppInfo",
	Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::PropPointers),
	sizeof(FAndroidAppInfo),
	alignof(FAndroidAppInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidAppInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidAppInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidAppInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidAppInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidAppInfo *****************************************************

// ********** Begin ScriptStruct FAndroidIdInfo ****************************************************
struct Z_Construct_UScriptStruct_FAndroidIdInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidIdInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidIdInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android ID\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android ID\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87 ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87 ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AndroidId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Android ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Android ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AdvertisingId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xb9\xbf\xe5\x91\x8a ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xb9\xbf\xe5\x91\x8a ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x99\xbb\xe5\xbd\x95 ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x99\xbb\xe5\xbd\x95 ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasAndroidId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab""Android ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab""Android ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasAdvertisingId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe5\xb9\xbf\xe5\x91\x8a ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe5\xb9\xbf\xe5\x91\x8a ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasLoginId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe7\x99\xbb\xe5\xbd\x95 ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe7\x99\xbb\xe5\xbd\x95 ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidIdInfo constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_DeviceId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AndroidId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_AdvertisingId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_LoginId;
	static void NewProp_bHasAndroidId_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasAndroidId;
	static void NewProp_bHasAdvertisingId_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasAdvertisingId;
	static void NewProp_bHasLoginId_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasLoginId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidIdInfo constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidIdInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidIdInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidIdInfo;
class UScriptStruct* FAndroidIdInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidIdInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidIdInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidIdInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidIdInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidIdInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidIdInfo Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_DeviceId = { "DeviceId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidIdInfo, DeviceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceId_MetaData), NewProp_DeviceId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_AndroidId = { "AndroidId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidIdInfo, AndroidId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AndroidId_MetaData), NewProp_AndroidId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_AdvertisingId = { "AdvertisingId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidIdInfo, AdvertisingId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AdvertisingId_MetaData), NewProp_AdvertisingId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_LoginId = { "LoginId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidIdInfo, LoginId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginId_MetaData), NewProp_LoginId_MetaData) };
void Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasAndroidId_SetBit(void* Obj)
{
	((FAndroidIdInfo*)Obj)->bHasAndroidId = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasAndroidId = { "bHasAndroidId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidIdInfo), &Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasAndroidId_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasAndroidId_MetaData), NewProp_bHasAndroidId_MetaData) };
void Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasAdvertisingId_SetBit(void* Obj)
{
	((FAndroidIdInfo*)Obj)->bHasAdvertisingId = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasAdvertisingId = { "bHasAdvertisingId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidIdInfo), &Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasAdvertisingId_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasAdvertisingId_MetaData), NewProp_bHasAdvertisingId_MetaData) };
void Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasLoginId_SetBit(void* Obj)
{
	((FAndroidIdInfo*)Obj)->bHasLoginId = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasLoginId = { "bHasLoginId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidIdInfo), &Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasLoginId_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasLoginId_MetaData), NewProp_bHasLoginId_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_DeviceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_AndroidId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_AdvertisingId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_LoginId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasAndroidId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasAdvertisingId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewProp_bHasLoginId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidIdInfo Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidIdInfo",
	Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::PropPointers),
	sizeof(FAndroidIdInfo),
	alignof(FAndroidIdInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidIdInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidIdInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidIdInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidIdInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidIdInfo ******************************************************

// ********** Begin ScriptStruct FAndroidCPUInfo ***************************************************
struct Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidCPUInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidCPUInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android CPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android CPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Vendor_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x82\xe5\x95\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x82\xe5\x95\x86\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Brand_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Chipset_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x8a\xaf\xe7\x89\x87\xe7\xbb\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x8a\xaf\xe7\x89\x87\xe7\xbb\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PhysicalCores_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LogicalCores_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x80\xbb\xe8\xbe\x91\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x80\xbb\xe8\xbe\x91\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveCores_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xbf\x80\xe6\xb4\xbb\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xbf\x80\xe6\xb4\xbb\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AverageUsagePercent_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xb9\xb3\xe5\x9d\x87\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xb9\xb3\xe5\x9d\x87\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PerCoreUsagePercent_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8d\x95\xe6\xa0\xb8\xe5\xbf\x83\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8d\x95\xe6\xa0\xb8\xe5\xbf\x83\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentFrequenciesMHz_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xbd\x93\xe5\x89\x8d""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xbd\x93\xe5\x89\x8d""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxFrequenciesMHz_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinFrequenciesMHz_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xb0\x8f""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xb0\x8f""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemperatureCelsius_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x91\x84\xe6\xb0\x8f\xe6\xb8\xa9\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x91\x84\xe6\xb0\x8f\xe6\xb8\xa9\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidCPUInfo constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Vendor;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Brand;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Chipset;
	static const UECodeGen_Private::FIntPropertyParams NewProp_PhysicalCores;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LogicalCores;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ActiveCores;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_AverageUsagePercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PerCoreUsagePercent_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_PerCoreUsagePercent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CurrentFrequenciesMHz_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_CurrentFrequenciesMHz;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxFrequenciesMHz_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MaxFrequenciesMHz;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MinFrequenciesMHz_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MinFrequenciesMHz;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TemperatureCelsius;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidCPUInfo constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidCPUInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidCPUInfo;
class UScriptStruct* FAndroidCPUInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidCPUInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidCPUInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidCPUInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidCPUInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidCPUInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidCPUInfo Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_Vendor = { "Vendor", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, Vendor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Vendor_MetaData), NewProp_Vendor_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_Brand = { "Brand", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, Brand), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Brand_MetaData), NewProp_Brand_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_Chipset = { "Chipset", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, Chipset), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Chipset_MetaData), NewProp_Chipset_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_PhysicalCores = { "PhysicalCores", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, PhysicalCores), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PhysicalCores_MetaData), NewProp_PhysicalCores_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_LogicalCores = { "LogicalCores", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, LogicalCores), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LogicalCores_MetaData), NewProp_LogicalCores_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_ActiveCores = { "ActiveCores", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, ActiveCores), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveCores_MetaData), NewProp_ActiveCores_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_AverageUsagePercent = { "AverageUsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, AverageUsagePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AverageUsagePercent_MetaData), NewProp_AverageUsagePercent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_PerCoreUsagePercent_Inner = { "PerCoreUsagePercent", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_PerCoreUsagePercent = { "PerCoreUsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, PerCoreUsagePercent), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PerCoreUsagePercent_MetaData), NewProp_PerCoreUsagePercent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_CurrentFrequenciesMHz_Inner = { "CurrentFrequenciesMHz", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_CurrentFrequenciesMHz = { "CurrentFrequenciesMHz", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, CurrentFrequenciesMHz), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentFrequenciesMHz_MetaData), NewProp_CurrentFrequenciesMHz_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_MaxFrequenciesMHz_Inner = { "MaxFrequenciesMHz", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_MaxFrequenciesMHz = { "MaxFrequenciesMHz", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, MaxFrequenciesMHz), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxFrequenciesMHz_MetaData), NewProp_MaxFrequenciesMHz_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_MinFrequenciesMHz_Inner = { "MinFrequenciesMHz", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_MinFrequenciesMHz = { "MinFrequenciesMHz", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, MinFrequenciesMHz), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinFrequenciesMHz_MetaData), NewProp_MinFrequenciesMHz_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_TemperatureCelsius = { "TemperatureCelsius", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidCPUInfo, TemperatureCelsius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemperatureCelsius_MetaData), NewProp_TemperatureCelsius_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_Vendor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_Brand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_Chipset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_PhysicalCores,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_LogicalCores,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_ActiveCores,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_AverageUsagePercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_PerCoreUsagePercent_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_PerCoreUsagePercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_CurrentFrequenciesMHz_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_CurrentFrequenciesMHz,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_MaxFrequenciesMHz_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_MaxFrequenciesMHz,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_MinFrequenciesMHz_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_MinFrequenciesMHz,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewProp_TemperatureCelsius,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidCPUInfo Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidCPUInfo",
	Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::PropPointers),
	sizeof(FAndroidCPUInfo),
	alignof(FAndroidCPUInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidCPUInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidCPUInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidCPUInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidCPUInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidCPUInfo *****************************************************

// ********** Begin ScriptStruct FAndroidGPUInfo ***************************************************
struct Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidGPUInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidGPUInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android GPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android GPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Brand_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GPUFamily_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98GPU \xe7\xb3\xbb\xe5\x88\x97\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98GPU \xe7\xb3\xbb\xe5\x88\x97\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Renderer_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xb8\xb2\xe6\x9f\x93\xe5\x99\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xb8\xb2\xe6\x9f\x93\xe5\x99\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorName_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x82\xe5\x95\x86\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x82\xe5\x95\x86\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriverInternalVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe5\x86\x85\xe9\x83\xa8\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe5\x86\x85\xe9\x83\xa8\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriverUserVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe7\x94\xa8\xe6\x88\xb7\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe7\x94\xa8\xe6\x88\xb7\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriverUnifiedVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DriverDate_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x97\xa5\xe6\x9c\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x97\xa5\xe6\x9c\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GLVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98GL \xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98GL \xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VulkanVersion_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Vulkan \xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Vulkan \xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RHIName_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98RHI\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98RHI\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasVulkanDriverSupport_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabVulkan\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x94\xaf\xe6\x8c\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabVulkan\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x94\xaf\xe6\x8c\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsVulkanAvailable_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Vulkan\xe5\x8f\xaf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Vulkan\xe5\x8f\xaf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShouldUseVulkan_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe9\x9c\x80\xe8\xa6\x81Use Vulkan\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe9\x9c\x80\xe8\xa6\x81Use Vulkan\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UsagePercent_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessUsagePercent_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidGPUInfo constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Brand;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GPUFamily;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Renderer;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VendorName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DriverInternalVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DriverUserVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DriverUnifiedVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_DriverDate;
	static const UECodeGen_Private::FStrPropertyParams NewProp_GLVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_VulkanVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RHIName;
	static void NewProp_bHasVulkanDriverSupport_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasVulkanDriverSupport;
	static void NewProp_bIsVulkanAvailable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsVulkanAvailable;
	static void NewProp_bShouldUseVulkan_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldUseVulkan;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_UsagePercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProcessUsagePercent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidGPUInfo constinit property declarations *********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidGPUInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidGPUInfo;
class UScriptStruct* FAndroidGPUInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidGPUInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidGPUInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidGPUInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidGPUInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidGPUInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidGPUInfo Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_Brand = { "Brand", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, Brand), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Brand_MetaData), NewProp_Brand_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_GPUFamily = { "GPUFamily", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, GPUFamily), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GPUFamily_MetaData), NewProp_GPUFamily_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_Renderer = { "Renderer", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, Renderer), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Renderer_MetaData), NewProp_Renderer_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_VendorName = { "VendorName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, VendorName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorName_MetaData), NewProp_VendorName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_DriverInternalVersion = { "DriverInternalVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, DriverInternalVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriverInternalVersion_MetaData), NewProp_DriverInternalVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_DriverUserVersion = { "DriverUserVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, DriverUserVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriverUserVersion_MetaData), NewProp_DriverUserVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_DriverUnifiedVersion = { "DriverUnifiedVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, DriverUnifiedVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriverUnifiedVersion_MetaData), NewProp_DriverUnifiedVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_DriverDate = { "DriverDate", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, DriverDate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DriverDate_MetaData), NewProp_DriverDate_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_GLVersion = { "GLVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, GLVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GLVersion_MetaData), NewProp_GLVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_VulkanVersion = { "VulkanVersion", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, VulkanVersion), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VulkanVersion_MetaData), NewProp_VulkanVersion_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_RHIName = { "RHIName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, RHIName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RHIName_MetaData), NewProp_RHIName_MetaData) };
void Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bHasVulkanDriverSupport_SetBit(void* Obj)
{
	((FAndroidGPUInfo*)Obj)->bHasVulkanDriverSupport = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bHasVulkanDriverSupport = { "bHasVulkanDriverSupport", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidGPUInfo), &Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bHasVulkanDriverSupport_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasVulkanDriverSupport_MetaData), NewProp_bHasVulkanDriverSupport_MetaData) };
void Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bIsVulkanAvailable_SetBit(void* Obj)
{
	((FAndroidGPUInfo*)Obj)->bIsVulkanAvailable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bIsVulkanAvailable = { "bIsVulkanAvailable", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidGPUInfo), &Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bIsVulkanAvailable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsVulkanAvailable_MetaData), NewProp_bIsVulkanAvailable_MetaData) };
void Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bShouldUseVulkan_SetBit(void* Obj)
{
	((FAndroidGPUInfo*)Obj)->bShouldUseVulkan = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bShouldUseVulkan = { "bShouldUseVulkan", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidGPUInfo), &Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bShouldUseVulkan_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShouldUseVulkan_MetaData), NewProp_bShouldUseVulkan_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_UsagePercent = { "UsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, UsagePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UsagePercent_MetaData), NewProp_UsagePercent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_ProcessUsagePercent = { "ProcessUsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUInfo, ProcessUsagePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessUsagePercent_MetaData), NewProp_ProcessUsagePercent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_Brand,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_GPUFamily,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_Renderer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_VendorName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_DriverInternalVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_DriverUserVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_DriverUnifiedVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_DriverDate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_GLVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_VulkanVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_RHIName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bHasVulkanDriverSupport,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bIsVulkanAvailable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_bShouldUseVulkan,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_UsagePercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewProp_ProcessUsagePercent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidGPUInfo Property Definitions ********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidGPUInfo",
	Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::PropPointers),
	sizeof(FAndroidGPUInfo),
	alignof(FAndroidGPUInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidGPUInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidGPUInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidGPUInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidGPUInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidGPUInfo *****************************************************

// ********** Begin ScriptStruct FAndroidGPUMemoryInfo *********************************************
struct Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidGPUMemoryInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidGPUMemoryInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsValid_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x9c\x89\xe6\x95\x88\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x9c\x89\xe6\x95\x88\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DedicatedVideoMemoryBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\x93\xe7\x94\xa8\xe6\x98\xbe\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\x93\xe7\x94\xa8\xe6\x98\xbe\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DedicatedSystemMemoryBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\x93\xe7\x94\xa8\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xb8\x93\xe7\x94\xa8\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SharedSystemMemoryBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x85\xb1\xe4\xba\xab\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x85\xb1\xe4\xba\xab\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalGraphicsMemoryBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe5\xbd\xa2\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe5\xbd\xa2\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StreamingMemorySizeBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xb5\x81\xe9\x80\x81\xe5\x86\x85\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xb5\x81\xe9\x80\x81\xe5\x86\x85\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NonStreamingMemorySizeBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Non\xe6\xb5\x81\xe9\x80\x81\xe5\x86\x85\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Non\xe6\xb5\x81\xe9\x80\x81\xe5\x86\x85\xe5\xad\x98\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LargestContiguousAllocationBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7\xe8\xbf\x9e\xe7\xbb\xad\xe5\x88\x86\xe9\x85\x8d\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7\xe8\xbf\x9e\xe7\xbb\xad\xe5\x88\x86\xe9\x85\x8d\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TexturePoolSizeBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xba\xb9\xe7\x90\x86Pool\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xba\xb9\xe7\x90\x86Pool\xe5\xa4\xa7\xe5\xb0\x8f\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvailableTexturePoolBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe7\xba\xb9\xe7\x90\x86\xe6\xb1\xa0\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe7\xba\xb9\xe7\x90\x86\xe6\xb1\xa0\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidGPUMemoryInfo constinit property declarations *************
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
// ********** End ScriptStruct FAndroidGPUMemoryInfo constinit property declarations ***************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidGPUMemoryInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidGPUMemoryInfo;
class UScriptStruct* FAndroidGPUMemoryInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidGPUMemoryInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidGPUMemoryInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidGPUMemoryInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidGPUMemoryInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidGPUMemoryInfo Property Definitions ************************
void Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_bIsValid_SetBit(void* Obj)
{
	((FAndroidGPUMemoryInfo*)Obj)->bIsValid = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidGPUMemoryInfo), &Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsValid_MetaData), NewProp_bIsValid_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_DedicatedVideoMemoryBytes = { "DedicatedVideoMemoryBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUMemoryInfo, DedicatedVideoMemoryBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DedicatedVideoMemoryBytes_MetaData), NewProp_DedicatedVideoMemoryBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_DedicatedSystemMemoryBytes = { "DedicatedSystemMemoryBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUMemoryInfo, DedicatedSystemMemoryBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DedicatedSystemMemoryBytes_MetaData), NewProp_DedicatedSystemMemoryBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_SharedSystemMemoryBytes = { "SharedSystemMemoryBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUMemoryInfo, SharedSystemMemoryBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SharedSystemMemoryBytes_MetaData), NewProp_SharedSystemMemoryBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_TotalGraphicsMemoryBytes = { "TotalGraphicsMemoryBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUMemoryInfo, TotalGraphicsMemoryBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalGraphicsMemoryBytes_MetaData), NewProp_TotalGraphicsMemoryBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_StreamingMemorySizeBytes = { "StreamingMemorySizeBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUMemoryInfo, StreamingMemorySizeBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StreamingMemorySizeBytes_MetaData), NewProp_StreamingMemorySizeBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_NonStreamingMemorySizeBytes = { "NonStreamingMemorySizeBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUMemoryInfo, NonStreamingMemorySizeBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NonStreamingMemorySizeBytes_MetaData), NewProp_NonStreamingMemorySizeBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_LargestContiguousAllocationBytes = { "LargestContiguousAllocationBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUMemoryInfo, LargestContiguousAllocationBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LargestContiguousAllocationBytes_MetaData), NewProp_LargestContiguousAllocationBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_TexturePoolSizeBytes = { "TexturePoolSizeBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUMemoryInfo, TexturePoolSizeBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TexturePoolSizeBytes_MetaData), NewProp_TexturePoolSizeBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_AvailableTexturePoolBytes = { "AvailableTexturePoolBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidGPUMemoryInfo, AvailableTexturePoolBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvailableTexturePoolBytes_MetaData), NewProp_AvailableTexturePoolBytes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_bIsValid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_DedicatedVideoMemoryBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_DedicatedSystemMemoryBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_SharedSystemMemoryBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_TotalGraphicsMemoryBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_StreamingMemorySizeBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_NonStreamingMemorySizeBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_LargestContiguousAllocationBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_TexturePoolSizeBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewProp_AvailableTexturePoolBytes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidGPUMemoryInfo Property Definitions **************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidGPUMemoryInfo",
	Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::PropPointers),
	sizeof(FAndroidGPUMemoryInfo),
	alignof(FAndroidGPUMemoryInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidGPUMemoryInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidGPUMemoryInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidGPUMemoryInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidGPUMemoryInfo ***********************************************

// ********** Begin ScriptStruct FAndroidMemoryInfo ************************************************
struct Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidMemoryInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidMemoryInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalPhysicalBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvailablePhysicalBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemUsedPhysicalBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessUsedPhysicalBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeakProcessUsedPhysicalBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb3\xb0\xe5\x80\xbc\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb3\xb0\xe5\x80\xbc\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalVirtualBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AvailableVirtualBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessUsedVirtualBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb7\xb2\xe7\x94\xa8\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb7\xb2\xe7\x94\xa8\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PeakProcessUsedVirtualBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb3\xb0\xe5\x80\xbc\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb3\xb0\xe5\x80\xbc\xe8\x99\x9a\xe6\x8b\x9f\xe5\x86\x85\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalPhysicalGB_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe9\x87\x8f\xef\xbc\x88GB\xef\xbc\x89\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe9\x87\x8f\xef\xbc\x88GB\xef\xbc\x89\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SystemPhysicalUsagePercent_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProcessPhysicalUsagePercent_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe7\x89\xa9\xe7\x90\x86\xe5\x86\x85\xe5\xad\x98\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLowMemory_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Low\xe5\x86\x85\xe5\xad\x98\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Low\xe5\x86\x85\xe5\xad\x98\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressureLevel_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Pressure\xe5\x85\xb3\xe5\x8d\xa1\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Pressure\xe5\x85\xb3\xe5\x8d\xa1\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidMemoryInfo constinit property declarations ****************
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalPhysicalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_AvailablePhysicalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_SystemUsedPhysicalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ProcessUsedPhysicalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PeakProcessUsedPhysicalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalVirtualBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_AvailableVirtualBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ProcessUsedVirtualBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PeakProcessUsedVirtualBytes;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TotalPhysicalGB;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SystemPhysicalUsagePercent;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ProcessPhysicalUsagePercent;
	static void NewProp_bLowMemory_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLowMemory;
	static const UECodeGen_Private::FBytePropertyParams NewProp_PressureLevel_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_PressureLevel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidMemoryInfo constinit property declarations ******************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidMemoryInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidMemoryInfo;
class UScriptStruct* FAndroidMemoryInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidMemoryInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidMemoryInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidMemoryInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidMemoryInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidMemoryInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidMemoryInfo Property Definitions ***************************
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_TotalPhysicalBytes = { "TotalPhysicalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, TotalPhysicalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalPhysicalBytes_MetaData), NewProp_TotalPhysicalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_AvailablePhysicalBytes = { "AvailablePhysicalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, AvailablePhysicalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvailablePhysicalBytes_MetaData), NewProp_AvailablePhysicalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_SystemUsedPhysicalBytes = { "SystemUsedPhysicalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, SystemUsedPhysicalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemUsedPhysicalBytes_MetaData), NewProp_SystemUsedPhysicalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_ProcessUsedPhysicalBytes = { "ProcessUsedPhysicalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, ProcessUsedPhysicalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessUsedPhysicalBytes_MetaData), NewProp_ProcessUsedPhysicalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_PeakProcessUsedPhysicalBytes = { "PeakProcessUsedPhysicalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, PeakProcessUsedPhysicalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeakProcessUsedPhysicalBytes_MetaData), NewProp_PeakProcessUsedPhysicalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_TotalVirtualBytes = { "TotalVirtualBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, TotalVirtualBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalVirtualBytes_MetaData), NewProp_TotalVirtualBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_AvailableVirtualBytes = { "AvailableVirtualBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, AvailableVirtualBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AvailableVirtualBytes_MetaData), NewProp_AvailableVirtualBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_ProcessUsedVirtualBytes = { "ProcessUsedVirtualBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, ProcessUsedVirtualBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessUsedVirtualBytes_MetaData), NewProp_ProcessUsedVirtualBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_PeakProcessUsedVirtualBytes = { "PeakProcessUsedVirtualBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, PeakProcessUsedVirtualBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PeakProcessUsedVirtualBytes_MetaData), NewProp_PeakProcessUsedVirtualBytes_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_TotalPhysicalGB = { "TotalPhysicalGB", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, TotalPhysicalGB), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalPhysicalGB_MetaData), NewProp_TotalPhysicalGB_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_SystemPhysicalUsagePercent = { "SystemPhysicalUsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, SystemPhysicalUsagePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SystemPhysicalUsagePercent_MetaData), NewProp_SystemPhysicalUsagePercent_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_ProcessPhysicalUsagePercent = { "ProcessPhysicalUsagePercent", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, ProcessPhysicalUsagePercent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProcessPhysicalUsagePercent_MetaData), NewProp_ProcessPhysicalUsagePercent_MetaData) };
void Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_bLowMemory_SetBit(void* Obj)
{
	((FAndroidMemoryInfo*)Obj)->bLowMemory = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_bLowMemory = { "bLowMemory", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidMemoryInfo), &Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_bLowMemory_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLowMemory_MetaData), NewProp_bLowMemory_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_PressureLevel_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_PressureLevel = { "PressureLevel", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidMemoryInfo, PressureLevel), Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressureLevel_MetaData), NewProp_PressureLevel_MetaData) }; // 1578426560
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_TotalPhysicalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_AvailablePhysicalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_SystemUsedPhysicalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_ProcessUsedPhysicalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_PeakProcessUsedPhysicalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_TotalVirtualBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_AvailableVirtualBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_ProcessUsedVirtualBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_PeakProcessUsedVirtualBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_TotalPhysicalGB,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_SystemPhysicalUsagePercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_ProcessPhysicalUsagePercent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_bLowMemory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_PressureLevel_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewProp_PressureLevel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidMemoryInfo Property Definitions *****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidMemoryInfo",
	Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::PropPointers),
	sizeof(FAndroidMemoryInfo),
	alignof(FAndroidMemoryInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidMemoryInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidMemoryInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidMemoryInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidMemoryInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidMemoryInfo **************************************************

// ********** Begin ScriptStruct FAndroidStorageInfo ***********************************************
struct Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidStorageInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidStorageInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android Storage\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android Storage\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsValid_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x9c\x89\xe6\x95\x88\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x9c\x89\xe6\x95\x88\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bExists_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0""Exists\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0""Exists\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RootPath_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Root\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Root\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TotalBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FreeBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UsedBytes_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xb2\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xb2\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidStorageInfo constinit property declarations ***************
	static void NewProp_bIsValid_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsValid;
	static void NewProp_bExists_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bExists;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
	static const UECodeGen_Private::FStrPropertyParams NewProp_RootPath;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_TotalBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_FreeBytes;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_UsedBytes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidStorageInfo constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidStorageInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidStorageInfo;
class UScriptStruct* FAndroidStorageInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidStorageInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidStorageInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidStorageInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidStorageInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidStorageInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidStorageInfo Property Definitions **************************
void Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_bIsValid_SetBit(void* Obj)
{
	((FAndroidStorageInfo*)Obj)->bIsValid = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_bIsValid = { "bIsValid", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidStorageInfo), &Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_bIsValid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsValid_MetaData), NewProp_bIsValid_MetaData) };
void Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_bExists_SetBit(void* Obj)
{
	((FAndroidStorageInfo*)Obj)->bExists = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_bExists = { "bExists", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidStorageInfo), &Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_bExists_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bExists_MetaData), NewProp_bExists_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidStorageInfo, Path), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Path_MetaData), NewProp_Path_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_RootPath = { "RootPath", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidStorageInfo, RootPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RootPath_MetaData), NewProp_RootPath_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_TotalBytes = { "TotalBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidStorageInfo, TotalBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TotalBytes_MetaData), NewProp_TotalBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_FreeBytes = { "FreeBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidStorageInfo, FreeBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FreeBytes_MetaData), NewProp_FreeBytes_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_UsedBytes = { "UsedBytes", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidStorageInfo, UsedBytes), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UsedBytes_MetaData), NewProp_UsedBytes_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_bIsValid,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_bExists,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_Path,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_RootPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_TotalBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_FreeBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewProp_UsedBytes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidStorageInfo Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidStorageInfo",
	Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::PropPointers),
	sizeof(FAndroidStorageInfo),
	alignof(FAndroidStorageInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidStorageInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidStorageInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidStorageInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidStorageInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidStorageInfo *************************************************

// ********** Begin ScriptStruct FAndroidBatteryInfo ***********************************************
struct Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidBatteryInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidBatteryInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android\xe7\x94\xb5\xe6\xb1\xa0\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android\xe7\x94\xb5\xe6\xb1\xa0\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_State_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x85\xb3\xe5\x8d\xa1\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x85\xb3\xe5\x8d\xa1\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TemperatureCelsius_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x91\x84\xe6\xb0\x8f\xe6\xb8\xa9\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x91\x84\xe6\xb0\x8f\xe6\xb8\xa9\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bCharging_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe5\x85\x85\xe7\x94\xb5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe5\x85\x85\xe7\x94\xb5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bRunningOnBattery_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe8\xbf\x90\xe8\xa1\x8cOn\xe7\x94\xb5\xe6\xb1\xa0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe8\xbf\x90\xe8\xa1\x8cOn\xe7\x94\xb5\xe6\xb1\xa0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bLowPowerMode_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Low\xe7\x94\xb5\xe6\xba\x90\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Low\xe7\x94\xb5\xe6\xba\x90\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidBatteryInfo constinit property declarations ***************
	static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TemperatureCelsius;
	static void NewProp_bCharging_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCharging;
	static void NewProp_bRunningOnBattery_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRunningOnBattery;
	static void NewProp_bLowPowerMode_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bLowPowerMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidBatteryInfo constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidBatteryInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidBatteryInfo;
class UScriptStruct* FAndroidBatteryInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidBatteryInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidBatteryInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidBatteryInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidBatteryInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidBatteryInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidBatteryInfo Property Definitions **************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidBatteryInfo, State), Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_State_MetaData), NewProp_State_MetaData) }; // 1500105897
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidBatteryInfo, Level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Level_MetaData), NewProp_Level_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_TemperatureCelsius = { "TemperatureCelsius", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidBatteryInfo, TemperatureCelsius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TemperatureCelsius_MetaData), NewProp_TemperatureCelsius_MetaData) };
void Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bCharging_SetBit(void* Obj)
{
	((FAndroidBatteryInfo*)Obj)->bCharging = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bCharging = { "bCharging", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidBatteryInfo), &Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bCharging_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bCharging_MetaData), NewProp_bCharging_MetaData) };
void Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bRunningOnBattery_SetBit(void* Obj)
{
	((FAndroidBatteryInfo*)Obj)->bRunningOnBattery = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bRunningOnBattery = { "bRunningOnBattery", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidBatteryInfo), &Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bRunningOnBattery_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bRunningOnBattery_MetaData), NewProp_bRunningOnBattery_MetaData) };
void Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bLowPowerMode_SetBit(void* Obj)
{
	((FAndroidBatteryInfo*)Obj)->bLowPowerMode = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bLowPowerMode = { "bLowPowerMode", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidBatteryInfo), &Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bLowPowerMode_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bLowPowerMode_MetaData), NewProp_bLowPowerMode_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_State_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_State,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_Level,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_TemperatureCelsius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bCharging,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bRunningOnBattery,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewProp_bLowPowerMode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidBatteryInfo Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidBatteryInfo",
	Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::PropPointers),
	sizeof(FAndroidBatteryInfo),
	alignof(FAndroidBatteryInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidBatteryInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidBatteryInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidBatteryInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidBatteryInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidBatteryInfo *************************************************

// ********** Begin ScriptStruct FAndroidNetworkInfo ***********************************************
struct Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidNetworkInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidNetworkInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NetworkType_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe7\xbb\x9c\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe7\xbb\x9c\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasNetwork_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe7\xbd\x91\xe7\xbb\x9c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe7\xbd\x91\xe7\xbb\x9c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasWiFiConnection_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabWi-Fi Fi\xe8\xbf\x9e\xe6\x8e\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabWi-Fi Fi\xe8\xbf\x9e\xe6\x8e\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CellularPreference_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x9c\x82\xe7\xaa\x9d\xe7\xbd\x91\xe7\xbb\x9c\xe5\x81\x8f\xe5\xa5\xbd\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x9c\x82\xe7\xaa\x9d\xe7\xbd\x91\xe7\xbb\x9c\xe5\x81\x8f\xe5\xa5\xbd\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidNetworkInfo constinit property declarations ***************
	static const UECodeGen_Private::FBytePropertyParams NewProp_NetworkType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_NetworkType;
	static void NewProp_bHasNetwork_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasNetwork;
	static void NewProp_bHasWiFiConnection_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasWiFiConnection;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CellularPreference;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidNetworkInfo constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidNetworkInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidNetworkInfo;
class UScriptStruct* FAndroidNetworkInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidNetworkInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidNetworkInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidNetworkInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidNetworkInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidNetworkInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidNetworkInfo Property Definitions **************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_NetworkType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_NetworkType = { "NetworkType", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidNetworkInfo, NetworkType), Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NetworkType_MetaData), NewProp_NetworkType_MetaData) }; // 3732971660
void Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_bHasNetwork_SetBit(void* Obj)
{
	((FAndroidNetworkInfo*)Obj)->bHasNetwork = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_bHasNetwork = { "bHasNetwork", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidNetworkInfo), &Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_bHasNetwork_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasNetwork_MetaData), NewProp_bHasNetwork_MetaData) };
void Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_bHasWiFiConnection_SetBit(void* Obj)
{
	((FAndroidNetworkInfo*)Obj)->bHasWiFiConnection = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_bHasWiFiConnection = { "bHasWiFiConnection", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidNetworkInfo), &Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_bHasWiFiConnection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasWiFiConnection_MetaData), NewProp_bHasWiFiConnection_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_CellularPreference = { "CellularPreference", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidNetworkInfo, CellularPreference), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CellularPreference_MetaData), NewProp_CellularPreference_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_NetworkType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_NetworkType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_bHasNetwork,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_bHasWiFiConnection,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewProp_CellularPreference,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidNetworkInfo Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidNetworkInfo",
	Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::PropPointers),
	sizeof(FAndroidNetworkInfo),
	alignof(FAndroidNetworkInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidNetworkInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidNetworkInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidNetworkInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidNetworkInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidNetworkInfo *************************************************

// ********** Begin ScriptStruct FAndroidDisplayInfo ***********************************************
struct Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidDisplayInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidDisplayInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScreenWidth_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Screen\xe5\xae\xbd\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Screen\xe5\xae\xbd\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ScreenHeight_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Screen\xe9\xab\x98\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Screen\xe9\xab\x98\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewportWidth_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Viewport\xe5\xae\xbd\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Viewport\xe5\xae\xbd\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ViewportHeight_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Viewport\xe9\xab\x98\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Viewport\xe9\xab\x98\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DPIScale_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""DPI \xe7\xbc\xa9\xe6\x94\xbe\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""DPI \xe7\xbc\xa9\xe6\x94\xbe\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_EstimatedDPI_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xbc\xb0\xe7\xae\x97 DPI\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xbc\xb0\xe7\xae\x97 DPI\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeRefreshRate_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x9f\xe7\x94\x9f\xe5\x88\xb7\xe6\x96\xb0\xe9\x80\x9f\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x9f\xe7\x94\x9f\xe5\x88\xb7\xe6\x96\xb0\xe9\x80\x9f\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SupportedRefreshRates_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x94\xaf\xe6\x8c\x81\xe7\x9a\x84\xe5\x88\xb7\xe6\x96\xb0\xe7\x8e\x87\xe5\x88\x97\xe8\xa1\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x94\xaf\xe6\x8c\x81\xe7\x9a\x84\xe5\x88\xb7\xe6\x96\xb0\xe7\x8e\x87\xe5\x88\x97\xe8\xa1\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Orientation_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\xb9\xe5\x90\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\xb9\xe5\x90\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidDisplayInfo constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ScreenWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ScreenHeight;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ViewportWidth;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ViewportHeight;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DPIScale;
	static const UECodeGen_Private::FIntPropertyParams NewProp_EstimatedDPI;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NativeRefreshRate;
	static const UECodeGen_Private::FIntPropertyParams NewProp_SupportedRefreshRates_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_SupportedRefreshRates;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Orientation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Orientation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidDisplayInfo constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidDisplayInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidDisplayInfo;
class UScriptStruct* FAndroidDisplayInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidDisplayInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidDisplayInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidDisplayInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidDisplayInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidDisplayInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidDisplayInfo Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_ScreenWidth = { "ScreenWidth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDisplayInfo, ScreenWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScreenWidth_MetaData), NewProp_ScreenWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_ScreenHeight = { "ScreenHeight", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDisplayInfo, ScreenHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ScreenHeight_MetaData), NewProp_ScreenHeight_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_ViewportWidth = { "ViewportWidth", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDisplayInfo, ViewportWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewportWidth_MetaData), NewProp_ViewportWidth_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_ViewportHeight = { "ViewportHeight", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDisplayInfo, ViewportHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ViewportHeight_MetaData), NewProp_ViewportHeight_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_DPIScale = { "DPIScale", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDisplayInfo, DPIScale), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DPIScale_MetaData), NewProp_DPIScale_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_EstimatedDPI = { "EstimatedDPI", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDisplayInfo, EstimatedDPI), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_EstimatedDPI_MetaData), NewProp_EstimatedDPI_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_NativeRefreshRate = { "NativeRefreshRate", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDisplayInfo, NativeRefreshRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeRefreshRate_MetaData), NewProp_NativeRefreshRate_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_SupportedRefreshRates_Inner = { "SupportedRefreshRates", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_SupportedRefreshRates = { "SupportedRefreshRates", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDisplayInfo, SupportedRefreshRates), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SupportedRefreshRates_MetaData), NewProp_SupportedRefreshRates_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_Orientation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_Orientation = { "Orientation", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidDisplayInfo, Orientation), Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Orientation_MetaData), NewProp_Orientation_MetaData) }; // 2301464795
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_ScreenWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_ScreenHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_ViewportWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_ViewportHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_DPIScale,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_EstimatedDPI,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_NativeRefreshRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_SupportedRefreshRates_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_SupportedRefreshRates,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_Orientation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewProp_Orientation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidDisplayInfo Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidDisplayInfo",
	Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::PropPointers),
	sizeof(FAndroidDisplayInfo),
	alignof(FAndroidDisplayInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidDisplayInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidDisplayInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidDisplayInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidDisplayInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidDisplayInfo *************************************************

// ********** Begin ScriptStruct FAndroidInputDeviceInfoData ***************************************
struct Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidInputDeviceInfoData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidInputDeviceInfoData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android\xe8\xbe\x93\xe5\x85\xa5\xe8\xae\xbe\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android\xe8\xbe\x93\xe5\x85\xa5\xe8\xae\xbe\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87 ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87 ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VendorId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x82\xe5\x95\x86 ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x82\xe5\x95\x86 ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProductId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe4\xba\xa7\xe5\x93\x81ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe4\xba\xa7\xe5\x93\x81ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ControllerId_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x8e\xa7\xe5\x88\xb6\xe5\x99\xa8ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x8e\xa7\xe5\x88\xb6\xe5\x99\xa8ID\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Descriptor_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x8f\xe8\xbf\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x8f\xe8\xbf\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FeedbackMotorCount_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Feedback Motor\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Feedback Motor\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidInputDeviceInfoData constinit property declarations *******
	static const UECodeGen_Private::FIntPropertyParams NewProp_DeviceId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_VendorId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ProductId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ControllerId;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Descriptor;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FeedbackMotorCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidInputDeviceInfoData constinit property declarations *********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidInputDeviceInfoData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidInputDeviceInfoData;
class UScriptStruct* FAndroidInputDeviceInfoData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidInputDeviceInfoData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidInputDeviceInfoData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidInputDeviceInfoData"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidInputDeviceInfoData.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidInputDeviceInfoData Property Definitions ******************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_DeviceId = { "DeviceId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidInputDeviceInfoData, DeviceId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceId_MetaData), NewProp_DeviceId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_VendorId = { "VendorId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidInputDeviceInfoData, VendorId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VendorId_MetaData), NewProp_VendorId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_ProductId = { "ProductId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidInputDeviceInfoData, ProductId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProductId_MetaData), NewProp_ProductId_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_ControllerId = { "ControllerId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidInputDeviceInfoData, ControllerId), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ControllerId_MetaData), NewProp_ControllerId_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidInputDeviceInfoData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_Descriptor = { "Descriptor", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidInputDeviceInfoData, Descriptor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Descriptor_MetaData), NewProp_Descriptor_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_FeedbackMotorCount = { "FeedbackMotorCount", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidInputDeviceInfoData, FeedbackMotorCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FeedbackMotorCount_MetaData), NewProp_FeedbackMotorCount_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_DeviceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_VendorId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_ProductId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_ControllerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_Descriptor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewProp_FeedbackMotorCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidInputDeviceInfoData Property Definitions ********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidInputDeviceInfoData",
	Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::PropPointers),
	sizeof(FAndroidInputDeviceInfoData),
	alignof(FAndroidInputDeviceInfoData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidInputDeviceInfoData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidInputDeviceInfoData.InnerSingleton, Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidInputDeviceInfoData.InnerSingleton);
}
// ********** End ScriptStruct FAndroidInputDeviceInfoData *****************************************

// ********** Begin ScriptStruct FAndroidCapabilityInfo ********************************************
struct Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidCapabilityInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidCapabilityInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android Capability\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android Capability\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsSupportedDevice_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x94\xaf\xe6\x8c\x81\xe8\xae\xbe\xe5\xa4\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x94\xaf\xe6\x8c\x81\xe8\xae\xbe\xe5\xa4\x87\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bHasVulkanDriverSupport_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabVulkan\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x94\xaf\xe6\x8c\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabVulkan\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x94\xaf\xe6\x8c\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsVulkanAvailable_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Vulkan\xe5\x8f\xaf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Vulkan\xe5\x8f\xaf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bShouldUseVulkan_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe9\x9c\x80\xe8\xa6\x81Use Vulkan\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0\xe6\x98\xaf\xe5\x90\xa6\xe9\x9c\x80\xe8\xa6\x81Use Vulkan\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSupportsFloatingPointRenderTargets_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Supports Floating Point\xe6\xb8\xb2\xe6\x9f\x93Targets\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Supports Floating Point\xe6\xb8\xb2\xe6\x9f\x93Targets\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSupportsShaderFramebufferFetch_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Supports Shader Framebuffer Fetch\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Supports Shader Framebuffer Fetch\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSupportsShaderIOBlocks_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Supports Shader IO\xe5\x8c\xba\xe5\x9d\x97\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Supports Shader IO\xe5\x8c\xba\xe5\x9d\x97\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSupportsBackbufferSampling_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0Supports Backbuffer Sampling\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0Supports Backbuffer Sampling\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bExpand16BitIndicesTo32BitOnLoad_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xae\xb0""Expand 16 Bit Indices To 32 Bit On\xe5\x8a\xa0\xe8\xbd\xbd\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xae\xb0""Expand 16 Bit Indices To 32 Bit On\xe5\x8a\xa0\xe8\xbd\xbd\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidCapabilityInfo constinit property declarations ************
	static void NewProp_bIsSupportedDevice_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsSupportedDevice;
	static void NewProp_bHasVulkanDriverSupport_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bHasVulkanDriverSupport;
	static void NewProp_bIsVulkanAvailable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsVulkanAvailable;
	static void NewProp_bShouldUseVulkan_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldUseVulkan;
	static void NewProp_bSupportsFloatingPointRenderTargets_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSupportsFloatingPointRenderTargets;
	static void NewProp_bSupportsShaderFramebufferFetch_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSupportsShaderFramebufferFetch;
	static void NewProp_bSupportsShaderIOBlocks_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSupportsShaderIOBlocks;
	static void NewProp_bSupportsBackbufferSampling_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSupportsBackbufferSampling;
	static void NewProp_bExpand16BitIndicesTo32BitOnLoad_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bExpand16BitIndicesTo32BitOnLoad;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidCapabilityInfo constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidCapabilityInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidCapabilityInfo;
class UScriptStruct* FAndroidCapabilityInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidCapabilityInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidCapabilityInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidCapabilityInfo, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidCapabilityInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidCapabilityInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidCapabilityInfo Property Definitions ***********************
void Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bIsSupportedDevice_SetBit(void* Obj)
{
	((FAndroidCapabilityInfo*)Obj)->bIsSupportedDevice = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bIsSupportedDevice = { "bIsSupportedDevice", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidCapabilityInfo), &Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bIsSupportedDevice_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsSupportedDevice_MetaData), NewProp_bIsSupportedDevice_MetaData) };
void Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bHasVulkanDriverSupport_SetBit(void* Obj)
{
	((FAndroidCapabilityInfo*)Obj)->bHasVulkanDriverSupport = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bHasVulkanDriverSupport = { "bHasVulkanDriverSupport", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidCapabilityInfo), &Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bHasVulkanDriverSupport_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bHasVulkanDriverSupport_MetaData), NewProp_bHasVulkanDriverSupport_MetaData) };
void Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bIsVulkanAvailable_SetBit(void* Obj)
{
	((FAndroidCapabilityInfo*)Obj)->bIsVulkanAvailable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bIsVulkanAvailable = { "bIsVulkanAvailable", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidCapabilityInfo), &Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bIsVulkanAvailable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsVulkanAvailable_MetaData), NewProp_bIsVulkanAvailable_MetaData) };
void Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bShouldUseVulkan_SetBit(void* Obj)
{
	((FAndroidCapabilityInfo*)Obj)->bShouldUseVulkan = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bShouldUseVulkan = { "bShouldUseVulkan", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidCapabilityInfo), &Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bShouldUseVulkan_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bShouldUseVulkan_MetaData), NewProp_bShouldUseVulkan_MetaData) };
void Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsFloatingPointRenderTargets_SetBit(void* Obj)
{
	((FAndroidCapabilityInfo*)Obj)->bSupportsFloatingPointRenderTargets = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsFloatingPointRenderTargets = { "bSupportsFloatingPointRenderTargets", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidCapabilityInfo), &Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsFloatingPointRenderTargets_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSupportsFloatingPointRenderTargets_MetaData), NewProp_bSupportsFloatingPointRenderTargets_MetaData) };
void Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsShaderFramebufferFetch_SetBit(void* Obj)
{
	((FAndroidCapabilityInfo*)Obj)->bSupportsShaderFramebufferFetch = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsShaderFramebufferFetch = { "bSupportsShaderFramebufferFetch", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidCapabilityInfo), &Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsShaderFramebufferFetch_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSupportsShaderFramebufferFetch_MetaData), NewProp_bSupportsShaderFramebufferFetch_MetaData) };
void Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsShaderIOBlocks_SetBit(void* Obj)
{
	((FAndroidCapabilityInfo*)Obj)->bSupportsShaderIOBlocks = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsShaderIOBlocks = { "bSupportsShaderIOBlocks", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidCapabilityInfo), &Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsShaderIOBlocks_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSupportsShaderIOBlocks_MetaData), NewProp_bSupportsShaderIOBlocks_MetaData) };
void Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsBackbufferSampling_SetBit(void* Obj)
{
	((FAndroidCapabilityInfo*)Obj)->bSupportsBackbufferSampling = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsBackbufferSampling = { "bSupportsBackbufferSampling", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidCapabilityInfo), &Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsBackbufferSampling_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSupportsBackbufferSampling_MetaData), NewProp_bSupportsBackbufferSampling_MetaData) };
void Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bExpand16BitIndicesTo32BitOnLoad_SetBit(void* Obj)
{
	((FAndroidCapabilityInfo*)Obj)->bExpand16BitIndicesTo32BitOnLoad = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bExpand16BitIndicesTo32BitOnLoad = { "bExpand16BitIndicesTo32BitOnLoad", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FAndroidCapabilityInfo), &Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bExpand16BitIndicesTo32BitOnLoad_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bExpand16BitIndicesTo32BitOnLoad_MetaData), NewProp_bExpand16BitIndicesTo32BitOnLoad_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bIsSupportedDevice,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bHasVulkanDriverSupport,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bIsVulkanAvailable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bShouldUseVulkan,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsFloatingPointRenderTargets,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsShaderFramebufferFetch,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsShaderIOBlocks,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bSupportsBackbufferSampling,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewProp_bExpand16BitIndicesTo32BitOnLoad,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidCapabilityInfo Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidCapabilityInfo",
	Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::PropPointers),
	sizeof(FAndroidCapabilityInfo),
	alignof(FAndroidCapabilityInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidCapabilityInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidCapabilityInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidCapabilityInfo.InnerSingleton, Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidCapabilityInfo.InnerSingleton);
}
// ********** End ScriptStruct FAndroidCapabilityInfo **********************************************

// ********** Begin ScriptStruct FAndroidHardwareSnapshot ******************************************
struct Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FAndroidHardwareSnapshot); }
	static inline consteval int16 GetStructAlignment() { return alignof(FAndroidHardwareSnapshot); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""Android\xe7\xa1\xac\xe4\xbb\xb6Snapshot\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""Android\xe7\xa1\xac\xe4\xbb\xb6Snapshot\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CaptureTimeSeconds_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Capture\xe6\x97\xb6\xe9\x97\xb4\xe7\xa7\x92\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Capture\xe6\x97\xb6\xe9\x97\xb4\xe7\xa7\x92\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DeviceInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AppInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IdInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98ID\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98ID\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CPUInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""CPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""CPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GPUInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98GPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98GPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GPUMemoryInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MemoryInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InternalStorage_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x86\x85\xe9\x83\xa8Storage\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x86\x85\xe9\x83\xa8Storage\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ExternalStorage_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xa4\x96\xe9\x83\xa8Storage\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xa4\x96\xe9\x83\xa8Storage\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ProjectStorage_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xaeStorage\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa1\xb9\xe7\x9b\xaeStorage\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BatteryInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xb1\xa0\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xb5\xe6\xb1\xa0\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NetworkInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisplayInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CapabilityInfo_MetaData[] = {
		{ "Category", "Android Type" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Capability\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Type/AndroidType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Capability\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FAndroidHardwareSnapshot constinit property declarations **********
	static const UECodeGen_Private::FDoublePropertyParams NewProp_CaptureTimeSeconds;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DeviceInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_AppInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_IdInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CPUInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GPUInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_GPUMemoryInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MemoryInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InternalStorage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ExternalStorage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ProjectStorage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BatteryInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NetworkInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DisplayInfo;
	static const UECodeGen_Private::FStructPropertyParams NewProp_CapabilityInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FAndroidHardwareSnapshot constinit property declarations ************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAndroidHardwareSnapshot>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FAndroidHardwareSnapshot;
class UScriptStruct* FAndroidHardwareSnapshot::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidHardwareSnapshot.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FAndroidHardwareSnapshot.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAndroidHardwareSnapshot, (UObject*)Z_Construct_UPackage__Script_GenericAndroidFramework(), TEXT("AndroidHardwareSnapshot"));
	}
	return Z_Registration_Info_UScriptStruct_FAndroidHardwareSnapshot.OuterSingleton;
	}

// ********** Begin ScriptStruct FAndroidHardwareSnapshot Property Definitions *********************
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_CaptureTimeSeconds = { "CaptureTimeSeconds", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, CaptureTimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CaptureTimeSeconds_MetaData), NewProp_CaptureTimeSeconds_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_DeviceInfo = { "DeviceInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, DeviceInfo), Z_Construct_UScriptStruct_FAndroidDeviceInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DeviceInfo_MetaData), NewProp_DeviceInfo_MetaData) }; // 144324224
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_AppInfo = { "AppInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, AppInfo), Z_Construct_UScriptStruct_FAndroidAppInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AppInfo_MetaData), NewProp_AppInfo_MetaData) }; // 1504359235
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_IdInfo = { "IdInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, IdInfo), Z_Construct_UScriptStruct_FAndroidIdInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IdInfo_MetaData), NewProp_IdInfo_MetaData) }; // 3822200990
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_CPUInfo = { "CPUInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, CPUInfo), Z_Construct_UScriptStruct_FAndroidCPUInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CPUInfo_MetaData), NewProp_CPUInfo_MetaData) }; // 1700421681
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_GPUInfo = { "GPUInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, GPUInfo), Z_Construct_UScriptStruct_FAndroidGPUInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GPUInfo_MetaData), NewProp_GPUInfo_MetaData) }; // 1182927782
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_GPUMemoryInfo = { "GPUMemoryInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, GPUMemoryInfo), Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GPUMemoryInfo_MetaData), NewProp_GPUMemoryInfo_MetaData) }; // 2779028896
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_MemoryInfo = { "MemoryInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, MemoryInfo), Z_Construct_UScriptStruct_FAndroidMemoryInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MemoryInfo_MetaData), NewProp_MemoryInfo_MetaData) }; // 669988889
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_InternalStorage = { "InternalStorage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, InternalStorage), Z_Construct_UScriptStruct_FAndroidStorageInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InternalStorage_MetaData), NewProp_InternalStorage_MetaData) }; // 1287974701
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_ExternalStorage = { "ExternalStorage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, ExternalStorage), Z_Construct_UScriptStruct_FAndroidStorageInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ExternalStorage_MetaData), NewProp_ExternalStorage_MetaData) }; // 1287974701
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_ProjectStorage = { "ProjectStorage", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, ProjectStorage), Z_Construct_UScriptStruct_FAndroidStorageInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ProjectStorage_MetaData), NewProp_ProjectStorage_MetaData) }; // 1287974701
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_BatteryInfo = { "BatteryInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, BatteryInfo), Z_Construct_UScriptStruct_FAndroidBatteryInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BatteryInfo_MetaData), NewProp_BatteryInfo_MetaData) }; // 1242804202
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_NetworkInfo = { "NetworkInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, NetworkInfo), Z_Construct_UScriptStruct_FAndroidNetworkInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NetworkInfo_MetaData), NewProp_NetworkInfo_MetaData) }; // 315038320
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_DisplayInfo = { "DisplayInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, DisplayInfo), Z_Construct_UScriptStruct_FAndroidDisplayInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisplayInfo_MetaData), NewProp_DisplayInfo_MetaData) }; // 1202672333
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_CapabilityInfo = { "CapabilityInfo", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAndroidHardwareSnapshot, CapabilityInfo), Z_Construct_UScriptStruct_FAndroidCapabilityInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CapabilityInfo_MetaData), NewProp_CapabilityInfo_MetaData) }; // 92126383
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_CaptureTimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_DeviceInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_AppInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_IdInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_CPUInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_GPUInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_GPUMemoryInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_MemoryInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_InternalStorage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_ExternalStorage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_ProjectStorage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_BatteryInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_NetworkInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_DisplayInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewProp_CapabilityInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FAndroidHardwareSnapshot Property Definitions ***********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
	nullptr,
	&NewStructOps,
	"AndroidHardwareSnapshot",
	Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::PropPointers),
	sizeof(FAndroidHardwareSnapshot),
	alignof(FAndroidHardwareSnapshot),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAndroidHardwareSnapshot()
{
	if (!Z_Registration_Info_UScriptStruct_FAndroidHardwareSnapshot.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FAndroidHardwareSnapshot.InnerSingleton, Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FAndroidHardwareSnapshot.InnerSingleton);
}
// ********** End ScriptStruct FAndroidHardwareSnapshot ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_Type_AndroidType_h__Script_GenericAndroidFramework_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EAndroidPermissionState_StaticEnum, TEXT("EAndroidPermissionState"), &Z_Registration_Info_UEnum_EAndroidPermissionState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 208015091U) },
		{ EAndroidNetworkType_StaticEnum, TEXT("EAndroidNetworkType"), &Z_Registration_Info_UEnum_EAndroidNetworkType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3732971660U) },
		{ EAndroidBatteryState_StaticEnum, TEXT("EAndroidBatteryState"), &Z_Registration_Info_UEnum_EAndroidBatteryState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1500105897U) },
		{ EAndroidMemoryPressureLevel_StaticEnum, TEXT("EAndroidMemoryPressureLevel"), &Z_Registration_Info_UEnum_EAndroidMemoryPressureLevel, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1578426560U) },
		{ EAndroidScreenOrientationType_StaticEnum, TEXT("EAndroidScreenOrientationType"), &Z_Registration_Info_UEnum_EAndroidScreenOrientationType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2301464795U) },
		{ EAndroidHapticType_StaticEnum, TEXT("EAndroidHapticType"), &Z_Registration_Info_UEnum_EAndroidHapticType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3080846989U) },
		{ EAndroidCommonPermission_StaticEnum, TEXT("EAndroidCommonPermission"), &Z_Registration_Info_UEnum_EAndroidCommonPermission, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3584124646U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAndroidDeviceInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidDeviceInfo_Statics::NewStructOps, TEXT("AndroidDeviceInfo"),&Z_Registration_Info_UScriptStruct_FAndroidDeviceInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidDeviceInfo), 144324224U) },
		{ FAndroidAppInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidAppInfo_Statics::NewStructOps, TEXT("AndroidAppInfo"),&Z_Registration_Info_UScriptStruct_FAndroidAppInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidAppInfo), 1504359235U) },
		{ FAndroidIdInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidIdInfo_Statics::NewStructOps, TEXT("AndroidIdInfo"),&Z_Registration_Info_UScriptStruct_FAndroidIdInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidIdInfo), 3822200990U) },
		{ FAndroidCPUInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidCPUInfo_Statics::NewStructOps, TEXT("AndroidCPUInfo"),&Z_Registration_Info_UScriptStruct_FAndroidCPUInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidCPUInfo), 1700421681U) },
		{ FAndroidGPUInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidGPUInfo_Statics::NewStructOps, TEXT("AndroidGPUInfo"),&Z_Registration_Info_UScriptStruct_FAndroidGPUInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidGPUInfo), 1182927782U) },
		{ FAndroidGPUMemoryInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo_Statics::NewStructOps, TEXT("AndroidGPUMemoryInfo"),&Z_Registration_Info_UScriptStruct_FAndroidGPUMemoryInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidGPUMemoryInfo), 2779028896U) },
		{ FAndroidMemoryInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidMemoryInfo_Statics::NewStructOps, TEXT("AndroidMemoryInfo"),&Z_Registration_Info_UScriptStruct_FAndroidMemoryInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidMemoryInfo), 669988889U) },
		{ FAndroidStorageInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidStorageInfo_Statics::NewStructOps, TEXT("AndroidStorageInfo"),&Z_Registration_Info_UScriptStruct_FAndroidStorageInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidStorageInfo), 1287974701U) },
		{ FAndroidBatteryInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidBatteryInfo_Statics::NewStructOps, TEXT("AndroidBatteryInfo"),&Z_Registration_Info_UScriptStruct_FAndroidBatteryInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidBatteryInfo), 1242804202U) },
		{ FAndroidNetworkInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidNetworkInfo_Statics::NewStructOps, TEXT("AndroidNetworkInfo"),&Z_Registration_Info_UScriptStruct_FAndroidNetworkInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidNetworkInfo), 315038320U) },
		{ FAndroidDisplayInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidDisplayInfo_Statics::NewStructOps, TEXT("AndroidDisplayInfo"),&Z_Registration_Info_UScriptStruct_FAndroidDisplayInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidDisplayInfo), 1202672333U) },
		{ FAndroidInputDeviceInfoData::StaticStruct, Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData_Statics::NewStructOps, TEXT("AndroidInputDeviceInfoData"),&Z_Registration_Info_UScriptStruct_FAndroidInputDeviceInfoData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidInputDeviceInfoData), 2597401251U) },
		{ FAndroidCapabilityInfo::StaticStruct, Z_Construct_UScriptStruct_FAndroidCapabilityInfo_Statics::NewStructOps, TEXT("AndroidCapabilityInfo"),&Z_Registration_Info_UScriptStruct_FAndroidCapabilityInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidCapabilityInfo), 92126383U) },
		{ FAndroidHardwareSnapshot::StaticStruct, Z_Construct_UScriptStruct_FAndroidHardwareSnapshot_Statics::NewStructOps, TEXT("AndroidHardwareSnapshot"),&Z_Registration_Info_UScriptStruct_FAndroidHardwareSnapshot, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAndroidHardwareSnapshot), 434754212U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_Type_AndroidType_h__Script_GenericAndroidFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_Type_AndroidType_h__Script_GenericAndroidFramework_1710740520{
	TEXT("/Script/GenericAndroidFramework"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_Type_AndroidType_h__Script_GenericAndroidFramework_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_Type_AndroidType_h__Script_GenericAndroidFramework_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_Type_AndroidType_h__Script_GenericAndroidFramework_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_Type_AndroidType_h__Script_GenericAndroidFramework_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
