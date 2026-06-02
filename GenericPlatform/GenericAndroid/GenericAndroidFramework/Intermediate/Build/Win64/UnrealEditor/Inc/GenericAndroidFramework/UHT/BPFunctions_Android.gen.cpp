// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/BPFunctions_Android.h"
#include "Type/AndroidType.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBPFunctions_Android() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
GENERICANDROIDFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_Android();
GENERICANDROIDFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_Android_NoRegister();
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

// ********** Begin Class UBPFunctions_Android Function AndroidPermissionStateToString *************
struct Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics
{
	struct BPFunctions_Android_eventAndroidPermissionStateToString_Parms
	{
		EAndroidPermissionState InState;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Permissions|Constants" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Android\xe6\x9d\x83\xe9\x99\x90\xe7\x8a\xb6\xe6\x80\x81To\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Android\xe6\x9d\x83\xe9\x99\x90\xe7\x8a\xb6\xe6\x80\x81To\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AndroidPermissionStateToString constinit property declarations ********
	static const UECodeGen_Private::FBytePropertyParams NewProp_InState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InState;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AndroidPermissionStateToString constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AndroidPermissionStateToString Property Definitions *******************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::NewProp_InState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::NewProp_InState = { "InState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventAndroidPermissionStateToString_Parms, InState), Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState, METADATA_PARAMS(0, nullptr) }; // 208015091
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventAndroidPermissionStateToString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::NewProp_InState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::NewProp_InState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::PropPointers) < 2048);
// ********** End Function AndroidPermissionStateToString Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "AndroidPermissionStateToString", 	Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::BPFunctions_Android_eventAndroidPermissionStateToString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::BPFunctions_Android_eventAndroidPermissionStateToString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execAndroidPermissionStateToString)
{
	P_GET_ENUM(EAndroidPermissionState,Z_Param_InState);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::AndroidPermissionStateToString(EAndroidPermissionState(Z_Param_InState));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function AndroidPermissionStateToString ***************

// ********** Begin Class UBPFunctions_Android Function AreHeadphonesConnected *********************
struct Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics
{
	struct BPFunctions_Android_eventAreHeadphonesConnected_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Audio|Devices" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Are Headphones Connected\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Are Headphones Connected\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AreHeadphonesConnected constinit property declarations ****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AreHeadphonesConnected constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AreHeadphonesConnected Property Definitions ***************************
void Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventAreHeadphonesConnected_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventAreHeadphonesConnected_Parms), &Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::PropPointers) < 2048);
// ********** End Function AreHeadphonesConnected Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "AreHeadphonesConnected", 	Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::BPFunctions_Android_eventAreHeadphonesConnected_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::BPFunctions_Android_eventAreHeadphonesConnected_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execAreHeadphonesConnected)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::AreHeadphonesConnected();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function AreHeadphonesConnected ***********************

// ********** Begin Class UBPFunctions_Android Function CancelLocalNotification ********************
struct Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics
{
	struct BPFunctions_Android_eventCancelLocalNotification_Parms
	{
		FString ActivationEvent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\xaf\xe4\xbb\xa5""cel\xe6\x9c\xac\xe5\x9c\xb0Notification\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\xaf\xe4\xbb\xa5""cel\xe6\x9c\xac\xe5\x9c\xb0Notification\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationEvent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CancelLocalNotification constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActivationEvent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CancelLocalNotification constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CancelLocalNotification Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::NewProp_ActivationEvent = { "ActivationEvent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventCancelLocalNotification_Parms, ActivationEvent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationEvent_MetaData), NewProp_ActivationEvent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::NewProp_ActivationEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::PropPointers) < 2048);
// ********** End Function CancelLocalNotification Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "CancelLocalNotification", 	Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::BPFunctions_Android_eventCancelLocalNotification_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::BPFunctions_Android_eventCancelLocalNotification_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execCancelLocalNotification)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ActivationEvent);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::CancelLocalNotification(Z_Param_ActivationEvent);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function CancelLocalNotification **********************

// ********** Begin Class UBPFunctions_Android Function CancelLocalNotificationById ****************
struct Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics
{
	struct BPFunctions_Android_eventCancelLocalNotificationById_Parms
	{
		int32 NotificationId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\xaf\xe4\xbb\xa5""cel\xe6\x9c\xac\xe5\x9c\xb0Notification\xe6\x8c\x89ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\xaf\xe4\xbb\xa5""cel\xe6\x9c\xac\xe5\x9c\xb0Notification\xe6\x8c\x89ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CancelLocalNotificationById constinit property declarations ***********
	static const UECodeGen_Private::FIntPropertyParams NewProp_NotificationId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CancelLocalNotificationById constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CancelLocalNotificationById Property Definitions **********************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::NewProp_NotificationId = { "NotificationId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventCancelLocalNotificationById_Parms, NotificationId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::NewProp_NotificationId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::PropPointers) < 2048);
// ********** End Function CancelLocalNotificationById Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "CancelLocalNotificationById", 	Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::BPFunctions_Android_eventCancelLocalNotificationById_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::BPFunctions_Android_eventCancelLocalNotificationById_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execCancelLocalNotificationById)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NotificationId);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::CancelLocalNotificationById(Z_Param_NotificationId);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function CancelLocalNotificationById ******************

// ********** Begin Class UBPFunctions_Android Function CanLaunchUrl *******************************
struct Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics
{
	struct BPFunctions_Android_eventCanLaunchUrl_Parms
	{
		FString InUrl;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Intent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\xaf\xe4\xbb\xa5\xe5\x90\xaf\xe5\x8a\xa8URL\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\xaf\xe4\xbb\xa5\xe5\x90\xaf\xe5\x8a\xa8URL\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InUrl_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanLaunchUrl constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InUrl;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanLaunchUrl constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanLaunchUrl Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::NewProp_InUrl = { "InUrl", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventCanLaunchUrl_Parms, InUrl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InUrl_MetaData), NewProp_InUrl_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventCanLaunchUrl_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventCanLaunchUrl_Parms), &Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::NewProp_InUrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::PropPointers) < 2048);
// ********** End Function CanLaunchUrl Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "CanLaunchUrl", 	Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::BPFunctions_Android_eventCanLaunchUrl_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::BPFunctions_Android_eventCanLaunchUrl_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execCanLaunchUrl)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InUrl);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::CanLaunchUrl(Z_Param_InUrl);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function CanLaunchUrl *********************************

// ********** Begin Class UBPFunctions_Android Function CheckAndroidCommonPermission ***************
struct Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics
{
	struct BPFunctions_Android_eventCheckAndroidCommonPermission_Parms
	{
		EAndroidCommonPermission InPermission;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Permissions|Constants" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa3\x80\xe6\x9f\xa5""Android Common\xe6\x9d\x83\xe9\x99\x90\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa3\x80\xe6\x9f\xa5""Android Common\xe6\x9d\x83\xe9\x99\x90\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CheckAndroidCommonPermission constinit property declarations **********
	static const UECodeGen_Private::FBytePropertyParams NewProp_InPermission_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InPermission;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CheckAndroidCommonPermission constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CheckAndroidCommonPermission Property Definitions *********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::NewProp_InPermission_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::NewProp_InPermission = { "InPermission", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventCheckAndroidCommonPermission_Parms, InPermission), Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission, METADATA_PARAMS(0, nullptr) }; // 3584124646
void Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventCheckAndroidCommonPermission_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventCheckAndroidCommonPermission_Parms), &Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::NewProp_InPermission_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::NewProp_InPermission,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::PropPointers) < 2048);
// ********** End Function CheckAndroidCommonPermission Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "CheckAndroidCommonPermission", 	Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::BPFunctions_Android_eventCheckAndroidCommonPermission_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::BPFunctions_Android_eventCheckAndroidCommonPermission_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execCheckAndroidCommonPermission)
{
	P_GET_ENUM(EAndroidCommonPermission,Z_Param_InPermission);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::CheckAndroidCommonPermission(EAndroidCommonPermission(Z_Param_InPermission));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function CheckAndroidCommonPermission *****************

// ********** Begin Class UBPFunctions_Android Function CheckAndroidPermission *********************
struct Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics
{
	struct BPFunctions_Android_eventCheckAndroidPermission_Parms
	{
		FString InPermission;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Permissions|Query" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa3\x80\xe6\x9f\xa5""Android\xe6\x9d\x83\xe9\x99\x90\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa3\x80\xe6\x9f\xa5""Android\xe6\x9d\x83\xe9\x99\x90\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPermission_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CheckAndroidPermission constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPermission;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CheckAndroidPermission constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CheckAndroidPermission Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::NewProp_InPermission = { "InPermission", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventCheckAndroidPermission_Parms, InPermission), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPermission_MetaData), NewProp_InPermission_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventCheckAndroidPermission_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventCheckAndroidPermission_Parms), &Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::NewProp_InPermission,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::PropPointers) < 2048);
// ********** End Function CheckAndroidPermission Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "CheckAndroidPermission", 	Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::BPFunctions_Android_eventCheckAndroidPermission_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::BPFunctions_Android_eventCheckAndroidPermission_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execCheckAndroidPermission)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPermission);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::CheckAndroidPermission(Z_Param_InPermission);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function CheckAndroidPermission ***********************

// ********** Begin Class UBPFunctions_Android Function CheckAndroidPermissions ********************
struct Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics
{
	struct BPFunctions_Android_eventCheckAndroidPermissions_Parms
	{
		TArray<FString> InPermissions;
		TArray<FString> MissingPermissions;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Permissions|Query" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa3\x80\xe6\x9f\xa5""Android Permissions\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa3\x80\xe6\x9f\xa5""Android Permissions\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPermissions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CheckAndroidPermissions constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPermissions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InPermissions;
	static const UECodeGen_Private::FStrPropertyParams NewProp_MissingPermissions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_MissingPermissions;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CheckAndroidPermissions constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CheckAndroidPermissions Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_InPermissions_Inner = { "InPermissions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_InPermissions = { "InPermissions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventCheckAndroidPermissions_Parms, InPermissions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPermissions_MetaData), NewProp_InPermissions_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_MissingPermissions_Inner = { "MissingPermissions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_MissingPermissions = { "MissingPermissions", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventCheckAndroidPermissions_Parms, MissingPermissions), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventCheckAndroidPermissions_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventCheckAndroidPermissions_Parms), &Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_InPermissions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_InPermissions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_MissingPermissions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_MissingPermissions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::PropPointers) < 2048);
// ********** End Function CheckAndroidPermissions Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "CheckAndroidPermissions", 	Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::BPFunctions_Android_eventCheckAndroidPermissions_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::BPFunctions_Android_eventCheckAndroidPermissions_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execCheckAndroidPermissions)
{
	P_GET_TARRAY_REF(FString,Z_Param_Out_InPermissions);
	P_GET_TARRAY_REF(FString,Z_Param_Out_MissingPermissions);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::CheckAndroidPermissions(Z_Param_Out_InPermissions,Z_Param_Out_MissingPermissions);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function CheckAndroidPermissions **********************

// ********** Begin Class UBPFunctions_Android Function ClearAllLocalNotifications *****************
struct Z_Construct_UFunction_UBPFunctions_Android_ClearAllLocalNotifications_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Clear\xe5\x85\xa8\xe9\x83\xa8\xe6\x9c\xac\xe5\x9c\xb0Notifications\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Clear\xe5\x85\xa8\xe9\x83\xa8\xe6\x9c\xac\xe5\x9c\xb0Notifications\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ClearAllLocalNotifications constinit property declarations ************
// ********** End Function ClearAllLocalNotifications constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_ClearAllLocalNotifications_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "ClearAllLocalNotifications", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ClearAllLocalNotifications_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_ClearAllLocalNotifications_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UBPFunctions_Android_ClearAllLocalNotifications()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_ClearAllLocalNotifications_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execClearAllLocalNotifications)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::ClearAllLocalNotifications();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function ClearAllLocalNotifications *******************

// ********** Begin Class UBPFunctions_Android Function DeleteSharedPreference *********************
struct Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics
{
	struct BPFunctions_Android_eventDeleteSharedPreference_Parms
	{
		FString InGroup;
		FString InKey;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|SharedPreferences" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Delete\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Delete\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function DeleteSharedPreference constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InGroup;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DeleteSharedPreference constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DeleteSharedPreference Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::NewProp_InGroup = { "InGroup", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventDeleteSharedPreference_Parms, InGroup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGroup_MetaData), NewProp_InGroup_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventDeleteSharedPreference_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::NewProp_InGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::NewProp_InKey,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::PropPointers) < 2048);
// ********** End Function DeleteSharedPreference Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "DeleteSharedPreference", 	Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::BPFunctions_Android_eventDeleteSharedPreference_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::BPFunctions_Android_eventDeleteSharedPreference_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execDeleteSharedPreference)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InGroup);
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::DeleteSharedPreference(Z_Param_InGroup,Z_Param_InKey);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function DeleteSharedPreference ***********************

// ********** Begin Class UBPFunctions_Android Function DeleteSharedPreferenceGroup ****************
struct Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics
{
	struct BPFunctions_Android_eventDeleteSharedPreferenceGroup_Parms
	{
		FString InGroup;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|SharedPreferences" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Delete\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe7\xbb\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Delete\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe7\xbb\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function DeleteSharedPreferenceGroup constinit property declarations ***********
	static const UECodeGen_Private::FStrPropertyParams NewProp_InGroup;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DeleteSharedPreferenceGroup constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DeleteSharedPreferenceGroup Property Definitions **********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::NewProp_InGroup = { "InGroup", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventDeleteSharedPreferenceGroup_Parms, InGroup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGroup_MetaData), NewProp_InGroup_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::NewProp_InGroup,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::PropPointers) < 2048);
// ********** End Function DeleteSharedPreferenceGroup Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "DeleteSharedPreferenceGroup", 	Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::BPFunctions_Android_eventDeleteSharedPreferenceGroup_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::BPFunctions_Android_eventDeleteSharedPreferenceGroup_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execDeleteSharedPreferenceGroup)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InGroup);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::DeleteSharedPreferenceGroup(Z_Param_InGroup);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function DeleteSharedPreferenceGroup ******************

// ********** Begin Class UBPFunctions_Android Function GetAdvertisingId ***************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics
{
	struct BPFunctions_Android_eventGetAdvertisingId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Identifiers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\xb9\xbf\xe5\x91\x8a ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\xb9\xbf\xe5\x91\x8a ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAdvertisingId constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAdvertisingId constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAdvertisingId Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAdvertisingId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::PropPointers) < 2048);
// ********** End Function GetAdvertisingId Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAdvertisingId", 	Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::BPFunctions_Android_eventGetAdvertisingId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::BPFunctions_Android_eventGetAdvertisingId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAdvertisingId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAdvertisingId();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAdvertisingId *****************************

// ********** Begin Class UBPFunctions_Android Function GetAllAndroidCommonPermissionStrings *******
struct Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics
{
	struct BPFunctions_Android_eventGetAllAndroidCommonPermissionStrings_Parms
	{
		TArray<FString> OutPermissions;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Permissions|Constants" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xa8\xe9\x83\xa8""Android Common\xe6\x9d\x83\xe9\x99\x90Strings\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xa8\xe9\x83\xa8""Android Common\xe6\x9d\x83\xe9\x99\x90Strings\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllAndroidCommonPermissionStrings constinit property declarations **
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutPermissions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutPermissions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllAndroidCommonPermissionStrings constinit property declarations ****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllAndroidCommonPermissionStrings Property Definitions *************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::NewProp_OutPermissions_Inner = { "OutPermissions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::NewProp_OutPermissions = { "OutPermissions", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAllAndroidCommonPermissionStrings_Parms, OutPermissions), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::NewProp_OutPermissions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::NewProp_OutPermissions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::PropPointers) < 2048);
// ********** End Function GetAllAndroidCommonPermissionStrings Property Definitions ***************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAllAndroidCommonPermissionStrings", 	Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::BPFunctions_Android_eventGetAllAndroidCommonPermissionStrings_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::BPFunctions_Android_eventGetAllAndroidCommonPermissionStrings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAllAndroidCommonPermissionStrings)
{
	P_GET_TARRAY_REF(FString,Z_Param_Out_OutPermissions);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetAllAndroidCommonPermissionStrings(Z_Param_Out_OutPermissions);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAllAndroidCommonPermissionStrings *********

// ********** Begin Class UBPFunctions_Android Function GetAllKnownStorageInfos ********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics
{
	struct BPFunctions_Android_eventGetAllKnownStorageInfos_Parms
	{
		TArray<FAndroidStorageInfo> OutInfos;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Storage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xa8\xe9\x83\xa8Known Storage Infos\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xa8\xe9\x83\xa8Known Storage Infos\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllKnownStorageInfos constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfos_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutInfos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllKnownStorageInfos constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllKnownStorageInfos Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::NewProp_OutInfos_Inner = { "OutInfos", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FAndroidStorageInfo, METADATA_PARAMS(0, nullptr) }; // 1287974701
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::NewProp_OutInfos = { "OutInfos", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAllKnownStorageInfos_Parms, OutInfos), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1287974701
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::NewProp_OutInfos_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::NewProp_OutInfos,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::PropPointers) < 2048);
// ********** End Function GetAllKnownStorageInfos Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAllKnownStorageInfos", 	Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::BPFunctions_Android_eventGetAllKnownStorageInfos_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::BPFunctions_Android_eventGetAllKnownStorageInfos_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAllKnownStorageInfos)
{
	P_GET_TARRAY_REF(FAndroidStorageInfo,Z_Param_Out_OutInfos);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetAllKnownStorageInfos(Z_Param_Out_OutInfos);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAllKnownStorageInfos **********************

// ********** Begin Class UBPFunctions_Android Function GetAndroidAppInfo **************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics
{
	struct BPFunctions_Android_eventGetAndroidAppInfo_Parms
	{
		FAndroidAppInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|App|Info" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidAppInfo constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidAppInfo constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidAppInfo Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidAppInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidAppInfo, METADATA_PARAMS(0, nullptr) }; // 1504359235
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidAppInfo Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidAppInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::BPFunctions_Android_eventGetAndroidAppInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::BPFunctions_Android_eventGetAndroidAppInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidAppInfo)
{
	P_GET_STRUCT_REF(FAndroidAppInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetAndroidAppInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidAppInfo ****************************

// ********** Begin Class UBPFunctions_Android Function GetAndroidBuildVersion *********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics
{
	struct BPFunctions_Android_eventGetAndroidBuildVersion_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android \xe6\x9e\x84\xe5\xbb\xba\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android \xe6\x9e\x84\xe5\xbb\xba\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidBuildVersion constinit property declarations ****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidBuildVersion constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidBuildVersion Property Definitions ***************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidBuildVersion_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidBuildVersion Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidBuildVersion", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::BPFunctions_Android_eventGetAndroidBuildVersion_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::BPFunctions_Android_eventGetAndroidBuildVersion_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidBuildVersion)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Android::GetAndroidBuildVersion();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidBuildVersion ***********************

// ********** Begin Class UBPFunctions_Android Function GetAndroidCommonPermissionString ***********
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics
{
	struct BPFunctions_Android_eventGetAndroidCommonPermissionString_Parms
	{
		EAndroidCommonPermission InPermission;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Permissions|Constants" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android Common\xe6\x9d\x83\xe9\x99\x90\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android Common\xe6\x9d\x83\xe9\x99\x90\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidCommonPermissionString constinit property declarations ******
	static const UECodeGen_Private::FBytePropertyParams NewProp_InPermission_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InPermission;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidCommonPermissionString constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidCommonPermissionString Property Definitions *****************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::NewProp_InPermission_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::NewProp_InPermission = { "InPermission", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidCommonPermissionString_Parms, InPermission), Z_Construct_UEnum_GenericAndroidFramework_EAndroidCommonPermission, METADATA_PARAMS(0, nullptr) }; // 3584124646
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidCommonPermissionString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::NewProp_InPermission_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::NewProp_InPermission,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidCommonPermissionString Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidCommonPermissionString", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::BPFunctions_Android_eventGetAndroidCommonPermissionString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::BPFunctions_Android_eventGetAndroidCommonPermissionString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidCommonPermissionString)
{
	P_GET_ENUM(EAndroidCommonPermission,Z_Param_InPermission);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidCommonPermissionString(EAndroidCommonPermission(Z_Param_InPermission));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidCommonPermissionString *************

// ********** Begin Class UBPFunctions_Android Function GetAndroidDebugReport **********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics
{
	struct BPFunctions_Android_eventGetAndroidDebugReport_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Diagnostics|Report" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe8\xb0\x83\xe8\xaf\x95Report\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe8\xb0\x83\xe8\xaf\x95Report\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidDebugReport constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidDebugReport constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidDebugReport Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidDebugReport_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidDebugReport Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidDebugReport", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::BPFunctions_Android_eventGetAndroidDebugReport_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::BPFunctions_Android_eventGetAndroidDebugReport_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidDebugReport)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidDebugReport();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidDebugReport ************************

// ********** Begin Class UBPFunctions_Android Function GetAndroidDeviceInfo ***********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics
{
	struct BPFunctions_Android_eventGetAndroidDeviceInfo_Parms
	{
		FAndroidDeviceInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe8\xae\xbe\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe8\xae\xbe\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidDeviceInfo constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidDeviceInfo constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidDeviceInfo Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidDeviceInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidDeviceInfo, METADATA_PARAMS(0, nullptr) }; // 144324224
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidDeviceInfo Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidDeviceInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::BPFunctions_Android_eventGetAndroidDeviceInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::BPFunctions_Android_eventGetAndroidDeviceInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidDeviceInfo)
{
	P_GET_STRUCT_REF(FAndroidDeviceInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetAndroidDeviceInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidDeviceInfo *************************

// ********** Begin Class UBPFunctions_Android Function GetAndroidExternalAppDir *******************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics
{
	struct BPFunctions_Android_eventGetAndroidExternalAppDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Paths" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8\xe5\xba\x94\xe7\x94\xa8\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8\xe5\xba\x94\xe7\x94\xa8\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidExternalAppDir constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidExternalAppDir constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidExternalAppDir Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidExternalAppDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidExternalAppDir Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidExternalAppDir", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::BPFunctions_Android_eventGetAndroidExternalAppDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::BPFunctions_Android_eventGetAndroidExternalAppDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidExternalAppDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidExternalAppDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidExternalAppDir *********************

// ********** Begin Class UBPFunctions_Android Function GetAndroidExternalConfigDir ****************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics
{
	struct BPFunctions_Android_eventGetAndroidExternalConfigDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Paths" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8\xe9\x85\x8d\xe7\xbd\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8\xe9\x85\x8d\xe7\xbd\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidExternalConfigDir constinit property declarations ***********
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidExternalConfigDir constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidExternalConfigDir Property Definitions **********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidExternalConfigDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidExternalConfigDir Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidExternalConfigDir", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::BPFunctions_Android_eventGetAndroidExternalConfigDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::BPFunctions_Android_eventGetAndroidExternalConfigDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidExternalConfigDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidExternalConfigDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidExternalConfigDir ******************

// ********** Begin Class UBPFunctions_Android Function GetAndroidExternalExtrasDir ****************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics
{
	struct BPFunctions_Android_eventGetAndroidExternalExtrasDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Paths" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8""Extras\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8""Extras\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidExternalExtrasDir constinit property declarations ***********
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidExternalExtrasDir constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidExternalExtrasDir Property Definitions **********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidExternalExtrasDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidExternalExtrasDir Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidExternalExtrasDir", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::BPFunctions_Android_eventGetAndroidExternalExtrasDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::BPFunctions_Android_eventGetAndroidExternalExtrasDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidExternalExtrasDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidExternalExtrasDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidExternalExtrasDir ******************

// ********** Begin Class UBPFunctions_Android Function GetAndroidExternalProjectDir ***************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics
{
	struct BPFunctions_Android_eventGetAndroidExternalProjectDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Paths" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8\xe9\xa1\xb9\xe7\x9b\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8\xe9\xa1\xb9\xe7\x9b\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidExternalProjectDir constinit property declarations **********
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidExternalProjectDir constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidExternalProjectDir Property Definitions *********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidExternalProjectDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidExternalProjectDir Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidExternalProjectDir", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::BPFunctions_Android_eventGetAndroidExternalProjectDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::BPFunctions_Android_eventGetAndroidExternalProjectDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidExternalProjectDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidExternalProjectDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidExternalProjectDir *****************

// ********** Begin Class UBPFunctions_Android Function GetAndroidExternalRootDir ******************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics
{
	struct BPFunctions_Android_eventGetAndroidExternalRootDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Paths" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8Root\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8Root\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidExternalRootDir constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidExternalRootDir constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidExternalRootDir Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidExternalRootDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidExternalRootDir Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidExternalRootDir", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::BPFunctions_Android_eventGetAndroidExternalRootDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::BPFunctions_Android_eventGetAndroidExternalRootDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidExternalRootDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidExternalRootDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidExternalRootDir ********************

// ********** Begin Class UBPFunctions_Android Function GetAndroidExternalSaveDir ******************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics
{
	struct BPFunctions_Android_eventGetAndroidExternalSaveDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Paths" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8\xe4\xbf\x9d\xe5\xad\x98\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\xa4\x96\xe9\x83\xa8\xe4\xbf\x9d\xe5\xad\x98\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidExternalSaveDir constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidExternalSaveDir constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidExternalSaveDir Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidExternalSaveDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidExternalSaveDir Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidExternalSaveDir", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::BPFunctions_Android_eventGetAndroidExternalSaveDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::BPFunctions_Android_eventGetAndroidExternalSaveDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidExternalSaveDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidExternalSaveDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidExternalSaveDir ********************

// ********** Begin Class UBPFunctions_Android Function GetAndroidFilePathBase *********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics
{
	struct BPFunctions_Android_eventGetAndroidFilePathBase_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Paths" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84\xe5\x9f\xba\xe7\xa1\x80\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84\xe5\x9f\xba\xe7\xa1\x80\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidFilePathBase constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidFilePathBase constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidFilePathBase Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidFilePathBase_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidFilePathBase Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidFilePathBase", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::BPFunctions_Android_eventGetAndroidFilePathBase_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::BPFunctions_Android_eventGetAndroidFilePathBase_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidFilePathBase)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidFilePathBase();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidFilePathBase ***********************

// ********** Begin Class UBPFunctions_Android Function GetAndroidId *******************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics
{
	struct BPFunctions_Android_eventGetAndroidId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Identifiers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidId constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidId constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidId Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidId Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidId", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::BPFunctions_Android_eventGetAndroidId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::BPFunctions_Android_eventGetAndroidId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidId();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidId *********************************

// ********** Begin Class UBPFunctions_Android Function GetAndroidIdInfo ***************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics
{
	struct BPFunctions_Android_eventGetAndroidIdInfo_Parms
	{
		FAndroidIdInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Identifiers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android ID\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android ID\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidIdInfo constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidIdInfo constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidIdInfo Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidIdInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidIdInfo, METADATA_PARAMS(0, nullptr) }; // 3822200990
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidIdInfo Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidIdInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::BPFunctions_Android_eventGetAndroidIdInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::BPFunctions_Android_eventGetAndroidIdInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidIdInfo)
{
	P_GET_STRUCT_REF(FAndroidIdInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetAndroidIdInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidIdInfo *****************************

// ********** Begin Class UBPFunctions_Android Function GetAndroidInternalAppDir *******************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics
{
	struct BPFunctions_Android_eventGetAndroidInternalAppDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Paths" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\x86\x85\xe9\x83\xa8\xe5\xba\x94\xe7\x94\xa8\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe5\x86\x85\xe9\x83\xa8\xe5\xba\x94\xe7\x94\xa8\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidInternalAppDir constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidInternalAppDir constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidInternalAppDir Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidInternalAppDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidInternalAppDir Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidInternalAppDir", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::BPFunctions_Android_eventGetAndroidInternalAppDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::BPFunctions_Android_eventGetAndroidInternalAppDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidInternalAppDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidInternalAppDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidInternalAppDir *********************

// ********** Begin Class UBPFunctions_Android Function GetAndroidMajorVersion *********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics
{
	struct BPFunctions_Android_eventGetAndroidMajorVersion_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android \xe4\xb8\xbb\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android \xe4\xb8\xbb\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidMajorVersion constinit property declarations ****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidMajorVersion constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidMajorVersion Property Definitions ***************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidMajorVersion_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidMajorVersion Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidMajorVersion", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::BPFunctions_Android_eventGetAndroidMajorVersion_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::BPFunctions_Android_eventGetAndroidMajorVersion_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidMajorVersion)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Android::GetAndroidMajorVersion();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidMajorVersion ***********************

// ********** Begin Class UBPFunctions_Android Function GetAndroidPermissionState ******************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics
{
	struct BPFunctions_Android_eventGetAndroidPermissionState_Parms
	{
		FString InPermission;
		EAndroidPermissionState ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Permissions|Query" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android\xe6\x9d\x83\xe9\x99\x90\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android\xe6\x9d\x83\xe9\x99\x90\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPermission_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidPermissionState constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPermission;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidPermissionState constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidPermissionState Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::NewProp_InPermission = { "InPermission", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidPermissionState_Parms, InPermission), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPermission_MetaData), NewProp_InPermission_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidPermissionState_Parms, ReturnValue), Z_Construct_UEnum_GenericAndroidFramework_EAndroidPermissionState, METADATA_PARAMS(0, nullptr) }; // 208015091
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::NewProp_InPermission,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidPermissionState Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidPermissionState", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::BPFunctions_Android_eventGetAndroidPermissionState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::BPFunctions_Android_eventGetAndroidPermissionState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidPermissionState)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPermission);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EAndroidPermissionState*)Z_Param__Result=UBPFunctions_Android::GetAndroidPermissionState(Z_Param_InPermission);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidPermissionState ********************

// ********** Begin Class UBPFunctions_Android Function GetAndroidPersistentDownloadDir ************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics
{
	struct BPFunctions_Android_eventGetAndroidPersistentDownloadDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Paths" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android Persistent Download\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android Persistent Download\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidPersistentDownloadDir constinit property declarations *******
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidPersistentDownloadDir constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidPersistentDownloadDir Property Definitions ******************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidPersistentDownloadDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidPersistentDownloadDir Property Definitions ********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidPersistentDownloadDir", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::BPFunctions_Android_eventGetAndroidPersistentDownloadDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::BPFunctions_Android_eventGetAndroidPersistentDownloadDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidPersistentDownloadDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidPersistentDownloadDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidPersistentDownloadDir **************

// ********** Begin Class UBPFunctions_Android Function GetAndroidVersion **************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics
{
	struct BPFunctions_Android_eventGetAndroidVersion_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Android \xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Android \xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAndroidVersion constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAndroidVersion constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAndroidVersion Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetAndroidVersion_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::PropPointers) < 2048);
// ********** End Function GetAndroidVersion Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetAndroidVersion", 	Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::BPFunctions_Android_eventGetAndroidVersion_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::BPFunctions_Android_eventGetAndroidVersion_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetAndroidVersion)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetAndroidVersion();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetAndroidVersion ****************************

// ********** Begin Class UBPFunctions_Android Function GetBatteryInfo *****************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics
{
	struct BPFunctions_Android_eventGetBatteryInfo_Parms
	{
		FAndroidBatteryInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|Battery" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\x94\xb5\xe6\xb1\xa0\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\x94\xb5\xe6\xb1\xa0\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetBatteryInfo constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBatteryInfo constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBatteryInfo Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetBatteryInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidBatteryInfo, METADATA_PARAMS(0, nullptr) }; // 1242804202
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::PropPointers) < 2048);
// ********** End Function GetBatteryInfo Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetBatteryInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::BPFunctions_Android_eventGetBatteryInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::BPFunctions_Android_eventGetBatteryInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetBatteryInfo)
{
	P_GET_STRUCT_REF(FAndroidBatteryInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetBatteryInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetBatteryInfo *******************************

// ********** Begin Class UBPFunctions_Android Function GetBatteryStateString **********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics
{
	struct BPFunctions_Android_eventGetBatteryStateString_Parms
	{
		EAndroidBatteryState InState;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|Battery" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\x94\xb5\xe6\xb1\xa0\xe7\x8a\xb6\xe6\x80\x81\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\x94\xb5\xe6\xb1\xa0\xe7\x8a\xb6\xe6\x80\x81\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetBatteryStateString constinit property declarations *****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InState;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBatteryStateString constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBatteryStateString Property Definitions ****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::NewProp_InState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::NewProp_InState = { "InState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetBatteryStateString_Parms, InState), Z_Construct_UEnum_GenericAndroidFramework_EAndroidBatteryState, METADATA_PARAMS(0, nullptr) }; // 1500105897
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetBatteryStateString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::NewProp_InState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::NewProp_InState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::PropPointers) < 2048);
// ********** End Function GetBatteryStateString Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetBatteryStateString", 	Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::BPFunctions_Android_eventGetBatteryStateString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::BPFunctions_Android_eventGetBatteryStateString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetBatteryStateString)
{
	P_GET_ENUM(EAndroidBatteryState,Z_Param_InState);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetBatteryStateString(EAndroidBatteryState(Z_Param_InState));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetBatteryStateString ************************

// ********** Begin Class UBPFunctions_Android Function GetCapabilityInfo **************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics
{
	struct BPFunctions_Android_eventGetCapabilityInfo_Parms
	{
		FAndroidCapabilityInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Capabilities|Query" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Capability\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Capability\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCapabilityInfo constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCapabilityInfo constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCapabilityInfo Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetCapabilityInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidCapabilityInfo, METADATA_PARAMS(0, nullptr) }; // 92126383
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::PropPointers) < 2048);
// ********** End Function GetCapabilityInfo Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetCapabilityInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::BPFunctions_Android_eventGetCapabilityInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::BPFunctions_Android_eventGetCapabilityInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetCapabilityInfo)
{
	P_GET_STRUCT_REF(FAndroidCapabilityInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetCapabilityInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetCapabilityInfo ****************************

// ********** Begin Class UBPFunctions_Android Function GetClipboardText ***************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics
{
	struct BPFunctions_Android_eventGetClipboardText_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Clipboard" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Clipboard\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Clipboard\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetClipboardText constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetClipboardText constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetClipboardText Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetClipboardText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::PropPointers) < 2048);
// ********** End Function GetClipboardText Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetClipboardText", 	Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::BPFunctions_Android_eventGetClipboardText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::BPFunctions_Android_eventGetClipboardText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetClipboardText)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetClipboardText();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetClipboardText *****************************

// ********** Begin Class UBPFunctions_Android Function GetCPUAverageUsage *************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics
{
	struct BPFunctions_Android_eventGetCPUAverageUsage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe5\xb9\xb3\xe5\x9d\x87\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe5\xb9\xb3\xe5\x9d\x87\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUAverageUsage constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUAverageUsage constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUAverageUsage Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetCPUAverageUsage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::PropPointers) < 2048);
// ********** End Function GetCPUAverageUsage Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetCPUAverageUsage", 	Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::BPFunctions_Android_eventGetCPUAverageUsage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::BPFunctions_Android_eventGetCPUAverageUsage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetCPUAverageUsage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UBPFunctions_Android::GetCPUAverageUsage();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetCPUAverageUsage ***************************

// ********** Begin Class UBPFunctions_Android Function GetCPUCoreUsages ***************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics
{
	struct BPFunctions_Android_eventGetCPUCoreUsages_Parms
	{
		TArray<float> OutUsages;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe6\xa0\xb8\xe5\xbf\x83Usages\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe6\xa0\xb8\xe5\xbf\x83Usages\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUCoreUsages constinit property declarations **********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_OutUsages_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutUsages;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUCoreUsages constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUCoreUsages Property Definitions *********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::NewProp_OutUsages_Inner = { "OutUsages", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::NewProp_OutUsages = { "OutUsages", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetCPUCoreUsages_Parms, OutUsages), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::NewProp_OutUsages_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::NewProp_OutUsages,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::PropPointers) < 2048);
// ********** End Function GetCPUCoreUsages Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetCPUCoreUsages", 	Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::BPFunctions_Android_eventGetCPUCoreUsages_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::BPFunctions_Android_eventGetCPUCoreUsages_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetCPUCoreUsages)
{
	P_GET_TARRAY_REF(float,Z_Param_Out_OutUsages);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetCPUCoreUsages(Z_Param_Out_OutUsages);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetCPUCoreUsages *****************************

// ********** Begin Class UBPFunctions_Android Function GetCPUCurrentFrequenciesMHz ****************
struct Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics
{
	struct BPFunctions_Android_eventGetCPUCurrentFrequenciesMHz_Parms
	{
		TArray<int32> OutFrequencies;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe5\xbd\x93\xe5\x89\x8d""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe5\xbd\x93\xe5\x89\x8d""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUCurrentFrequenciesMHz constinit property declarations ***********
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutFrequencies_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutFrequencies;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUCurrentFrequenciesMHz constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUCurrentFrequenciesMHz Property Definitions **********************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::NewProp_OutFrequencies_Inner = { "OutFrequencies", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::NewProp_OutFrequencies = { "OutFrequencies", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetCPUCurrentFrequenciesMHz_Parms, OutFrequencies), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::NewProp_OutFrequencies_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::NewProp_OutFrequencies,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::PropPointers) < 2048);
// ********** End Function GetCPUCurrentFrequenciesMHz Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetCPUCurrentFrequenciesMHz", 	Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::BPFunctions_Android_eventGetCPUCurrentFrequenciesMHz_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::BPFunctions_Android_eventGetCPUCurrentFrequenciesMHz_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetCPUCurrentFrequenciesMHz)
{
	P_GET_TARRAY_REF(int32,Z_Param_Out_OutFrequencies);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetCPUCurrentFrequenciesMHz(Z_Param_Out_OutFrequencies);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetCPUCurrentFrequenciesMHz ******************

// ********** Begin Class UBPFunctions_Android Function GetCPUHardwareInfo *************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics
{
	struct BPFunctions_Android_eventGetCPUHardwareInfo_Parms
	{
		FAndroidCPUInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUHardwareInfo constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUHardwareInfo constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUHardwareInfo Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetCPUHardwareInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidCPUInfo, METADATA_PARAMS(0, nullptr) }; // 1700421681
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::PropPointers) < 2048);
// ********** End Function GetCPUHardwareInfo Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetCPUHardwareInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::BPFunctions_Android_eventGetCPUHardwareInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::BPFunctions_Android_eventGetCPUHardwareInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetCPUHardwareInfo)
{
	P_GET_STRUCT_REF(FAndroidCPUInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetCPUHardwareInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetCPUHardwareInfo ***************************

// ********** Begin Class UBPFunctions_Android Function GetCPUMaxFrequenciesMHz ********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics
{
	struct BPFunctions_Android_eventGetCPUMaxFrequenciesMHz_Parms
	{
		TArray<int32> OutFrequencies;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe6\x9c\x80\xe5\xa4\xa7""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe6\x9c\x80\xe5\xa4\xa7""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUMaxFrequenciesMHz constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutFrequencies_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutFrequencies;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUMaxFrequenciesMHz constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUMaxFrequenciesMHz Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::NewProp_OutFrequencies_Inner = { "OutFrequencies", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::NewProp_OutFrequencies = { "OutFrequencies", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetCPUMaxFrequenciesMHz_Parms, OutFrequencies), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::NewProp_OutFrequencies_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::NewProp_OutFrequencies,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::PropPointers) < 2048);
// ********** End Function GetCPUMaxFrequenciesMHz Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetCPUMaxFrequenciesMHz", 	Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::BPFunctions_Android_eventGetCPUMaxFrequenciesMHz_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::BPFunctions_Android_eventGetCPUMaxFrequenciesMHz_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetCPUMaxFrequenciesMHz)
{
	P_GET_TARRAY_REF(int32,Z_Param_Out_OutFrequencies);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetCPUMaxFrequenciesMHz(Z_Param_Out_OutFrequencies);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetCPUMaxFrequenciesMHz **********************

// ********** Begin Class UBPFunctions_Android Function GetCPUMinFrequenciesMHz ********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics
{
	struct BPFunctions_Android_eventGetCPUMinFrequenciesMHz_Parms
	{
		TArray<int32> OutFrequencies;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe6\x9c\x80\xe5\xb0\x8f""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe6\x9c\x80\xe5\xb0\x8f""Frequencies\xe6\xa8\xa1\xe5\xbc\x8fHz\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUMinFrequenciesMHz constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutFrequencies_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutFrequencies;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUMinFrequenciesMHz constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUMinFrequenciesMHz Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::NewProp_OutFrequencies_Inner = { "OutFrequencies", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::NewProp_OutFrequencies = { "OutFrequencies", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetCPUMinFrequenciesMHz_Parms, OutFrequencies), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::NewProp_OutFrequencies_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::NewProp_OutFrequencies,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::PropPointers) < 2048);
// ********** End Function GetCPUMinFrequenciesMHz Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetCPUMinFrequenciesMHz", 	Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::BPFunctions_Android_eventGetCPUMinFrequenciesMHz_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::BPFunctions_Android_eventGetCPUMinFrequenciesMHz_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetCPUMinFrequenciesMHz)
{
	P_GET_TARRAY_REF(int32,Z_Param_Out_OutFrequencies);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetCPUMinFrequenciesMHz(Z_Param_Out_OutFrequencies);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetCPUMinFrequenciesMHz **********************

// ********** Begin Class UBPFunctions_Android Function GetCPUTemperatureCelsius *******************
struct Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics
{
	struct BPFunctions_Android_eventGetCPUTemperatureCelsius_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe6\xb8\xa9\xe5\xba\xa6\xe6\x91\x84\xe6\xb0\x8f\xe5\xba\xa6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe6\xb8\xa9\xe5\xba\xa6\xe6\x91\x84\xe6\xb0\x8f\xe5\xba\xa6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUTemperatureCelsius constinit property declarations **************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUTemperatureCelsius constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUTemperatureCelsius Property Definitions *************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetCPUTemperatureCelsius_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::PropPointers) < 2048);
// ********** End Function GetCPUTemperatureCelsius Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetCPUTemperatureCelsius", 	Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::BPFunctions_Android_eventGetCPUTemperatureCelsius_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::BPFunctions_Android_eventGetCPUTemperatureCelsius_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetCPUTemperatureCelsius)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UBPFunctions_Android::GetCPUTemperatureCelsius();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetCPUTemperatureCelsius *********************

// ********** Begin Class UBPFunctions_Android Function GetCurrentVolumePercent ********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics
{
	struct BPFunctions_Android_eventGetCurrentVolumePercent_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Audio|Volume" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8dVolume\xe7\x99\xbe\xe5\x88\x86\xe6\xaf\x94\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8dVolume\xe7\x99\xbe\xe5\x88\x86\xe6\xaf\x94\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentVolumePercent constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentVolumePercent constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentVolumePercent Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetCurrentVolumePercent_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentVolumePercent Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetCurrentVolumePercent", 	Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::BPFunctions_Android_eventGetCurrentVolumePercent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::BPFunctions_Android_eventGetCurrentVolumePercent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetCurrentVolumePercent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Android::GetCurrentVolumePercent();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetCurrentVolumePercent **********************

// ********** Begin Class UBPFunctions_Android Function GetCurrentVolumeStep ***********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics
{
	struct BPFunctions_Android_eventGetCurrentVolumeStep_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Audio|Volume" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8dVolume Step\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8dVolume Step\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentVolumeStep constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentVolumeStep constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentVolumeStep Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetCurrentVolumeStep_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentVolumeStep Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetCurrentVolumeStep", 	Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::BPFunctions_Android_eventGetCurrentVolumeStep_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::BPFunctions_Android_eventGetCurrentVolumeStep_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetCurrentVolumeStep)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Android::GetCurrentVolumeStep();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetCurrentVolumeStep *************************

// ********** Begin Class UBPFunctions_Android Function GetDefaultLocale ***************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics
{
	struct BPFunctions_Android_eventGetDefaultLocale_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe9\xbb\x98\xe8\xae\xa4\xe5\x8c\xba\xe5\x9f\x9f\xe8\xae\xbe\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe9\xbb\x98\xe8\xae\xa4\xe5\x8c\xba\xe5\x9f\x9f\xe8\xae\xbe\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDefaultLocale constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDefaultLocale constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDefaultLocale Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetDefaultLocale_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::PropPointers) < 2048);
// ********** End Function GetDefaultLocale Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetDefaultLocale", 	Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::BPFunctions_Android_eventGetDefaultLocale_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::BPFunctions_Android_eventGetDefaultLocale_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetDefaultLocale)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetDefaultLocale();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetDefaultLocale *****************************

// ********** Begin Class UBPFunctions_Android Function GetDeviceBrand *****************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics
{
	struct BPFunctions_Android_eventGetDeviceBrand_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe8\xae\xbe\xe5\xa4\x87\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe8\xae\xbe\xe5\xa4\x87\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDeviceBrand constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDeviceBrand constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDeviceBrand Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetDeviceBrand_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::PropPointers) < 2048);
// ********** End Function GetDeviceBrand Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetDeviceBrand", 	Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::BPFunctions_Android_eventGetDeviceBrand_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::BPFunctions_Android_eventGetDeviceBrand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetDeviceBrand)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetDeviceBrand();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetDeviceBrand *******************************

// ********** Begin Class UBPFunctions_Android Function GetDeviceBuildNumber ***********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics
{
	struct BPFunctions_Android_eventGetDeviceBuildNumber_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe8\xae\xbe\xe5\xa4\x87\xe6\x9e\x84\xe5\xbb\xba\xe5\x8f\xb7\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe8\xae\xbe\xe5\xa4\x87\xe6\x9e\x84\xe5\xbb\xba\xe5\x8f\xb7\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDeviceBuildNumber constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDeviceBuildNumber constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDeviceBuildNumber Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetDeviceBuildNumber_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::PropPointers) < 2048);
// ********** End Function GetDeviceBuildNumber Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetDeviceBuildNumber", 	Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::BPFunctions_Android_eventGetDeviceBuildNumber_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::BPFunctions_Android_eventGetDeviceBuildNumber_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetDeviceBuildNumber)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetDeviceBuildNumber();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetDeviceBuildNumber *************************

// ********** Begin Class UBPFunctions_Android Function GetDeviceId ********************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics
{
	struct BPFunctions_Android_eventGetDeviceId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Identifiers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe8\xae\xbe\xe5\xa4\x87 ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe8\xae\xbe\xe5\xa4\x87 ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDeviceId constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDeviceId constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDeviceId Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetDeviceId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::PropPointers) < 2048);
// ********** End Function GetDeviceId Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetDeviceId", 	Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::BPFunctions_Android_eventGetDeviceId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::BPFunctions_Android_eventGetDeviceId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetDeviceId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetDeviceId();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetDeviceId **********************************

// ********** Begin Class UBPFunctions_Android Function GetDeviceModel *****************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics
{
	struct BPFunctions_Android_eventGetDeviceModel_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe8\xae\xbe\xe5\xa4\x87\xe6\xa8\xa1\xe5\x9e\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe8\xae\xbe\xe5\xa4\x87\xe6\xa8\xa1\xe5\x9e\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDeviceModel constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDeviceModel constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDeviceModel Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetDeviceModel_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::PropPointers) < 2048);
// ********** End Function GetDeviceModel Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetDeviceModel", 	Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::BPFunctions_Android_eventGetDeviceModel_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::BPFunctions_Android_eventGetDeviceModel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetDeviceModel)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetDeviceModel();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetDeviceModel *******************************

// ********** Begin Class UBPFunctions_Android Function GetDisplayInfo *****************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics
{
	struct BPFunctions_Android_eventGetDisplayInfo_Parms
	{
		FAndroidDisplayInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Display|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDisplayInfo constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDisplayInfo constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDisplayInfo Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetDisplayInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidDisplayInfo, METADATA_PARAMS(0, nullptr) }; // 1202672333
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::PropPointers) < 2048);
// ********** End Function GetDisplayInfo Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetDisplayInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::BPFunctions_Android_eventGetDisplayInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::BPFunctions_Android_eventGetDisplayInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetDisplayInfo)
{
	P_GET_STRUCT_REF(FAndroidDisplayInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetDisplayInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetDisplayInfo *******************************

// ********** Begin Class UBPFunctions_Android Function GetExternalStorageInfo *********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics
{
	struct BPFunctions_Android_eventGetExternalStorageInfo_Parms
	{
		FAndroidStorageInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Storage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\xa4\x96\xe9\x83\xa8Storage\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\xa4\x96\xe9\x83\xa8Storage\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetExternalStorageInfo constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetExternalStorageInfo constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetExternalStorageInfo Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetExternalStorageInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidStorageInfo, METADATA_PARAMS(0, nullptr) }; // 1287974701
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::PropPointers) < 2048);
// ********** End Function GetExternalStorageInfo Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetExternalStorageInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::BPFunctions_Android_eventGetExternalStorageInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::BPFunctions_Android_eventGetExternalStorageInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetExternalStorageInfo)
{
	P_GET_STRUCT_REF(FAndroidStorageInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetExternalStorageInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetExternalStorageInfo ***********************

// ********** Begin Class UBPFunctions_Android Function GetGPUHardwareInfo *************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics
{
	struct BPFunctions_Android_eventGetGPUHardwareInfo_Parms
	{
		FAndroidGPUInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUHardwareInfo constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUHardwareInfo constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUHardwareInfo Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetGPUHardwareInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidGPUInfo, METADATA_PARAMS(0, nullptr) }; // 1182927782
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::PropPointers) < 2048);
// ********** End Function GetGPUHardwareInfo Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetGPUHardwareInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::BPFunctions_Android_eventGetGPUHardwareInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::BPFunctions_Android_eventGetGPUHardwareInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetGPUHardwareInfo)
{
	P_GET_STRUCT_REF(FAndroidGPUInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetGPUHardwareInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetGPUHardwareInfo ***************************

// ********** Begin Class UBPFunctions_Android Function GetGPUMemoryInfo ***************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics
{
	struct BPFunctions_Android_eventGetGPUMemoryInfo_Parms
	{
		FAndroidGPUMemoryInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUMemoryInfo constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUMemoryInfo constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUMemoryInfo Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetGPUMemoryInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidGPUMemoryInfo, METADATA_PARAMS(0, nullptr) }; // 2779028896
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::PropPointers) < 2048);
// ********** End Function GetGPUMemoryInfo Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetGPUMemoryInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::BPFunctions_Android_eventGetGPUMemoryInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::BPFunctions_Android_eventGetGPUMemoryInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetGPUMemoryInfo)
{
	P_GET_STRUCT_REF(FAndroidGPUMemoryInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetGPUMemoryInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetGPUMemoryInfo *****************************

// ********** Begin Class UBPFunctions_Android Function GetGPURHIName ******************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics
{
	struct BPFunctions_Android_eventGetGPURHIName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPURHI\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPURHI\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPURHIName constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPURHIName constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPURHIName Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetGPURHIName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::PropPointers) < 2048);
// ********** End Function GetGPURHIName Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetGPURHIName", 	Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::BPFunctions_Android_eventGetGPURHIName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::BPFunctions_Android_eventGetGPURHIName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetGPURHIName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetGPURHIName();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetGPURHIName ********************************

// ********** Begin Class UBPFunctions_Android Function GetGPUUsage ********************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics
{
	struct BPFunctions_Android_eventGetGPUUsage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUUsage constinit property declarations ***************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUUsage constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUUsage Property Definitions **************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetGPUUsage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::PropPointers) < 2048);
// ********** End Function GetGPUUsage Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetGPUUsage", 	Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::BPFunctions_Android_eventGetGPUUsage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::BPFunctions_Android_eventGetGPUUsage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetGPUUsage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UBPFunctions_Android::GetGPUUsage();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetGPUUsage **********************************

// ********** Begin Class UBPFunctions_Android Function GetHardwareSnapshot ************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics
{
	struct BPFunctions_Android_eventGetHardwareSnapshot_Parms
	{
		FAndroidHardwareSnapshot OutSnapshot;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Diagnostics|Hardware Snapshot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xa1\xac\xe4\xbb\xb6\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xa1\xac\xe4\xbb\xb6\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetHardwareSnapshot constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSnapshot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHardwareSnapshot constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHardwareSnapshot Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::NewProp_OutSnapshot = { "OutSnapshot", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetHardwareSnapshot_Parms, OutSnapshot), Z_Construct_UScriptStruct_FAndroidHardwareSnapshot, METADATA_PARAMS(0, nullptr) }; // 434754212
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::NewProp_OutSnapshot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::PropPointers) < 2048);
// ********** End Function GetHardwareSnapshot Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetHardwareSnapshot", 	Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::BPFunctions_Android_eventGetHardwareSnapshot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::BPFunctions_Android_eventGetHardwareSnapshot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetHardwareSnapshot)
{
	P_GET_STRUCT_REF(FAndroidHardwareSnapshot,Z_Param_Out_OutSnapshot);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetHardwareSnapshot(Z_Param_Out_OutSnapshot);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetHardwareSnapshot **************************

// ********** Begin Class UBPFunctions_Android Function GetInputDeviceInfo *************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics
{
	struct BPFunctions_Android_eventGetInputDeviceInfo_Parms
	{
		int32 InDeviceId;
		FAndroidInputDeviceInfoData OutInfo;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Input|Devices" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe8\xbe\x93\xe5\x85\xa5\xe8\xae\xbe\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe8\xbe\x93\xe5\x85\xa5\xe8\xae\xbe\xe5\xa4\x87\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetInputDeviceInfo constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InDeviceId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInputDeviceInfo constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInputDeviceInfo Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::NewProp_InDeviceId = { "InDeviceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetInputDeviceInfo_Parms, InDeviceId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetInputDeviceInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidInputDeviceInfoData, METADATA_PARAMS(0, nullptr) }; // 2597401251
void Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventGetInputDeviceInfo_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventGetInputDeviceInfo_Parms), &Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::NewProp_InDeviceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::NewProp_OutInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::PropPointers) < 2048);
// ********** End Function GetInputDeviceInfo Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetInputDeviceInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::BPFunctions_Android_eventGetInputDeviceInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::BPFunctions_Android_eventGetInputDeviceInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetInputDeviceInfo)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InDeviceId);
	P_GET_STRUCT_REF(FAndroidInputDeviceInfoData,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::GetInputDeviceInfo(Z_Param_InDeviceId,Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetInputDeviceInfo ***************************

// ********** Begin Class UBPFunctions_Android Function GetInputMotionState ************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics
{
	struct BPFunctions_Android_eventGetInputMotionState_Parms
	{
		UObject* WorldContextObject;
		FVector Tilt;
		FVector RotationRate;
		FVector Gravity;
		FVector Acceleration;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Input|Sensors" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe8\xbe\x93\xe5\x85\xa5Motion\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe8\xbe\x93\xe5\x85\xa5Motion\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInputMotionState constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Tilt;
	static const UECodeGen_Private::FStructPropertyParams NewProp_RotationRate;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Gravity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Acceleration;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInputMotionState constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInputMotionState Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetInputMotionState_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_Tilt = { "Tilt", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetInputMotionState_Parms, Tilt), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_RotationRate = { "RotationRate", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetInputMotionState_Parms, RotationRate), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_Gravity = { "Gravity", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetInputMotionState_Parms, Gravity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_Acceleration = { "Acceleration", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetInputMotionState_Parms, Acceleration), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventGetInputMotionState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventGetInputMotionState_Parms), &Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_Tilt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_RotationRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_Gravity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_Acceleration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::PropPointers) < 2048);
// ********** End Function GetInputMotionState Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetInputMotionState", 	Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::BPFunctions_Android_eventGetInputMotionState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::BPFunctions_Android_eventGetInputMotionState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetInputMotionState)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Tilt);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_RotationRate);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Gravity);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Acceleration);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::GetInputMotionState(Z_Param_WorldContextObject,Z_Param_Out_Tilt,Z_Param_Out_RotationRate,Z_Param_Out_Gravity,Z_Param_Out_Acceleration);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetInputMotionState **************************

// ********** Begin Class UBPFunctions_Android Function GetInternalStorageInfo *********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics
{
	struct BPFunctions_Android_eventGetInternalStorageInfo_Parms
	{
		FAndroidStorageInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Storage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe9\x83\xa8Storage\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe9\x83\xa8Storage\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetInternalStorageInfo constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInternalStorageInfo constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInternalStorageInfo Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetInternalStorageInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidStorageInfo, METADATA_PARAMS(0, nullptr) }; // 1287974701
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::PropPointers) < 2048);
// ********** End Function GetInternalStorageInfo Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetInternalStorageInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::BPFunctions_Android_eventGetInternalStorageInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::BPFunctions_Android_eventGetInternalStorageInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetInternalStorageInfo)
{
	P_GET_STRUCT_REF(FAndroidStorageInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetInternalStorageInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetInternalStorageInfo ***********************

// ********** Begin Class UBPFunctions_Android Function GetLaunchNotification **********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics
{
	struct BPFunctions_Android_eventGetLaunchNotification_Parms
	{
		bool bNotificationLaunchedApp;
		FString ActivationEvent;
		int32 FireDate;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x90\xaf\xe5\x8a\xa8Notification\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x90\xaf\xe5\x8a\xa8Notification\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetLaunchNotification constinit property declarations *****************
	static void NewProp_bNotificationLaunchedApp_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNotificationLaunchedApp;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActivationEvent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_FireDate;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLaunchNotification constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLaunchNotification Property Definitions ****************************
void Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::NewProp_bNotificationLaunchedApp_SetBit(void* Obj)
{
	((BPFunctions_Android_eventGetLaunchNotification_Parms*)Obj)->bNotificationLaunchedApp = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::NewProp_bNotificationLaunchedApp = { "bNotificationLaunchedApp", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventGetLaunchNotification_Parms), &Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::NewProp_bNotificationLaunchedApp_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::NewProp_ActivationEvent = { "ActivationEvent", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetLaunchNotification_Parms, ActivationEvent), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::NewProp_FireDate = { "FireDate", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetLaunchNotification_Parms, FireDate), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::NewProp_bNotificationLaunchedApp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::NewProp_ActivationEvent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::NewProp_FireDate,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::PropPointers) < 2048);
// ********** End Function GetLaunchNotification Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetLaunchNotification", 	Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::BPFunctions_Android_eventGetLaunchNotification_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::BPFunctions_Android_eventGetLaunchNotification_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetLaunchNotification)
{
	P_GET_UBOOL_REF(Z_Param_Out_bNotificationLaunchedApp);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_ActivationEvent);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_FireDate);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetLaunchNotification(Z_Param_Out_bNotificationLaunchedApp,Z_Param_Out_ActivationEvent,Z_Param_Out_FireDate);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetLaunchNotification ************************

// ********** Begin Class UBPFunctions_Android Function GetLoginId *********************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics
{
	struct BPFunctions_Android_eventGetLoginId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Identifiers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\x99\xbb\xe5\xbd\x95 ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\x99\xbb\xe5\xbd\x95 ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetLoginId constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLoginId constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLoginId Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetLoginId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::PropPointers) < 2048);
// ********** End Function GetLoginId Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetLoginId", 	Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::BPFunctions_Android_eventGetLoginId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::BPFunctions_Android_eventGetLoginId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetLoginId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetLoginId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetLoginId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetLoginId();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetLoginId ***********************************

// ********** Begin Class UBPFunctions_Android Function GetManifestMetaDataBoolean *****************
struct Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics
{
	struct BPFunctions_Android_eventGetManifestMetaDataBoolean_Parms
	{
		FString InKey;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Manifest" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Manifest Meta\xe6\x95\xb0\xe6\x8d\xae\xe5\xb8\x83\xe5\xb0\x94\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Manifest Meta\xe6\x95\xb0\xe6\x8d\xae\xe5\xb8\x83\xe5\xb0\x94\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetManifestMetaDataBoolean constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetManifestMetaDataBoolean constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetManifestMetaDataBoolean Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetManifestMetaDataBoolean_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventGetManifestMetaDataBoolean_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventGetManifestMetaDataBoolean_Parms), &Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::PropPointers) < 2048);
// ********** End Function GetManifestMetaDataBoolean Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetManifestMetaDataBoolean", 	Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::BPFunctions_Android_eventGetManifestMetaDataBoolean_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::BPFunctions_Android_eventGetManifestMetaDataBoolean_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetManifestMetaDataBoolean)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::GetManifestMetaDataBoolean(Z_Param_InKey);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetManifestMetaDataBoolean *******************

// ********** Begin Class UBPFunctions_Android Function GetManifestMetaDataFloat *******************
struct Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics
{
	struct BPFunctions_Android_eventGetManifestMetaDataFloat_Parms
	{
		FString InKey;
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Manifest" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Manifest Meta\xe6\x95\xb0\xe6\x8d\xae\xe6\xb5\xae\xe7\x82\xb9\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Manifest Meta\xe6\x95\xb0\xe6\x8d\xae\xe6\xb5\xae\xe7\x82\xb9\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetManifestMetaDataFloat constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetManifestMetaDataFloat constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetManifestMetaDataFloat Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetManifestMetaDataFloat_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetManifestMetaDataFloat_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::PropPointers) < 2048);
// ********** End Function GetManifestMetaDataFloat Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetManifestMetaDataFloat", 	Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::BPFunctions_Android_eventGetManifestMetaDataFloat_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::BPFunctions_Android_eventGetManifestMetaDataFloat_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetManifestMetaDataFloat)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UBPFunctions_Android::GetManifestMetaDataFloat(Z_Param_InKey);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetManifestMetaDataFloat *********************

// ********** Begin Class UBPFunctions_Android Function GetManifestMetaDataInt *********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics
{
	struct BPFunctions_Android_eventGetManifestMetaDataInt_Parms
	{
		FString InKey;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Manifest" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Manifest Meta\xe6\x95\xb0\xe6\x8d\xae\xe6\x95\xb4\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Manifest Meta\xe6\x95\xb0\xe6\x8d\xae\xe6\x95\xb4\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetManifestMetaDataInt constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetManifestMetaDataInt constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetManifestMetaDataInt Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetManifestMetaDataInt_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetManifestMetaDataInt_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::PropPointers) < 2048);
// ********** End Function GetManifestMetaDataInt Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetManifestMetaDataInt", 	Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::BPFunctions_Android_eventGetManifestMetaDataInt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::BPFunctions_Android_eventGetManifestMetaDataInt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetManifestMetaDataInt)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Android::GetManifestMetaDataInt(Z_Param_InKey);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetManifestMetaDataInt ***********************

// ********** Begin Class UBPFunctions_Android Function GetManifestMetaDataLong ********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics
{
	struct BPFunctions_Android_eventGetManifestMetaDataLong_Parms
	{
		FString InKey;
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Manifest" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Manifest Meta\xe6\x95\xb0\xe6\x8d\xaeLong\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Manifest Meta\xe6\x95\xb0\xe6\x8d\xaeLong\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetManifestMetaDataLong constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetManifestMetaDataLong constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetManifestMetaDataLong Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetManifestMetaDataLong_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetManifestMetaDataLong_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::PropPointers) < 2048);
// ********** End Function GetManifestMetaDataLong Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetManifestMetaDataLong", 	Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::BPFunctions_Android_eventGetManifestMetaDataLong_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::BPFunctions_Android_eventGetManifestMetaDataLong_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetManifestMetaDataLong)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=UBPFunctions_Android::GetManifestMetaDataLong(Z_Param_InKey);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetManifestMetaDataLong **********************

// ********** Begin Class UBPFunctions_Android Function GetManifestMetaDataString ******************
struct Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics
{
	struct BPFunctions_Android_eventGetManifestMetaDataString_Parms
	{
		FString InKey;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Manifest" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Manifest Meta\xe6\x95\xb0\xe6\x8d\xae\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Manifest Meta\xe6\x95\xb0\xe6\x8d\xae\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetManifestMetaDataString constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetManifestMetaDataString constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetManifestMetaDataString Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetManifestMetaDataString_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetManifestMetaDataString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::PropPointers) < 2048);
// ********** End Function GetManifestMetaDataString Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetManifestMetaDataString", 	Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::BPFunctions_Android_eventGetManifestMetaDataString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::BPFunctions_Android_eventGetManifestMetaDataString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetManifestMetaDataString)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetManifestMetaDataString(Z_Param_InKey);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetManifestMetaDataString ********************

// ********** Begin Class UBPFunctions_Android Function GetMemoryHardwareInfo **********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics
{
	struct BPFunctions_Android_eventGetMemoryHardwareInfo_Parms
	{
		FAndroidMemoryInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|Memory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMemoryHardwareInfo constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMemoryHardwareInfo constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMemoryHardwareInfo Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetMemoryHardwareInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidMemoryInfo, METADATA_PARAMS(0, nullptr) }; // 669988889
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::PropPointers) < 2048);
// ********** End Function GetMemoryHardwareInfo Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetMemoryHardwareInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::BPFunctions_Android_eventGetMemoryHardwareInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::BPFunctions_Android_eventGetMemoryHardwareInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetMemoryHardwareInfo)
{
	P_GET_STRUCT_REF(FAndroidMemoryInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetMemoryHardwareInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetMemoryHardwareInfo ************************

// ********** Begin Class UBPFunctions_Android Function GetMemoryPressureLevel *********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics
{
	struct BPFunctions_Android_eventGetMemoryPressureLevel_Parms
	{
		EAndroidMemoryPressureLevel ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|Memory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98Pressure\xe5\x85\xb3\xe5\x8d\xa1\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98Pressure\xe5\x85\xb3\xe5\x8d\xa1\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMemoryPressureLevel constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMemoryPressureLevel constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMemoryPressureLevel Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetMemoryPressureLevel_Parms, ReturnValue), Z_Construct_UEnum_GenericAndroidFramework_EAndroidMemoryPressureLevel, METADATA_PARAMS(0, nullptr) }; // 1578426560
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::PropPointers) < 2048);
// ********** End Function GetMemoryPressureLevel Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetMemoryPressureLevel", 	Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::BPFunctions_Android_eventGetMemoryPressureLevel_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::BPFunctions_Android_eventGetMemoryPressureLevel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetMemoryPressureLevel)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EAndroidMemoryPressureLevel*)Z_Param__Result=UBPFunctions_Android::GetMemoryPressureLevel();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetMemoryPressureLevel ***********************

// ********** Begin Class UBPFunctions_Android Function GetNetworkInfo *****************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics
{
	struct BPFunctions_Android_eventGetNetworkInfo_Parms
	{
		FAndroidNetworkInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Network|Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetNetworkInfo constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNetworkInfo constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNetworkInfo Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetNetworkInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidNetworkInfo, METADATA_PARAMS(0, nullptr) }; // 315038320
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::PropPointers) < 2048);
// ********** End Function GetNetworkInfo Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetNetworkInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::BPFunctions_Android_eventGetNetworkInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::BPFunctions_Android_eventGetNetworkInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetNetworkInfo)
{
	P_GET_STRUCT_REF(FAndroidNetworkInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetNetworkInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetNetworkInfo *******************************

// ********** Begin Class UBPFunctions_Android Function GetNetworkTypeString ***********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics
{
	struct BPFunctions_Android_eventGetNetworkTypeString_Parms
	{
		EAndroidNetworkType InType;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Network|Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xbd\x91\xe7\xbb\x9c\xe7\xb1\xbb\xe5\x9e\x8b\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xbd\x91\xe7\xbb\x9c\xe7\xb1\xbb\xe5\x9e\x8b\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetNetworkTypeString constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNetworkTypeString constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNetworkTypeString Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::NewProp_InType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::NewProp_InType = { "InType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetNetworkTypeString_Parms, InType), Z_Construct_UEnum_GenericAndroidFramework_EAndroidNetworkType, METADATA_PARAMS(0, nullptr) }; // 3732971660
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetNetworkTypeString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::NewProp_InType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::NewProp_InType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::PropPointers) < 2048);
// ********** End Function GetNetworkTypeString Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetNetworkTypeString", 	Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::BPFunctions_Android_eventGetNetworkTypeString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::BPFunctions_Android_eventGetNetworkTypeString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetNetworkTypeString)
{
	P_GET_ENUM(EAndroidNetworkType,Z_Param_InType);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetNetworkTypeString(EAndroidNetworkType(Z_Param_InType));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetNetworkTypeString *************************

// ********** Begin Class UBPFunctions_Android Function GetOrientationString ***********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics
{
	struct BPFunctions_Android_eventGetOrientationString_Parms
	{
		EAndroidScreenOrientationType InOrientation;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Display|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\xb9\xe5\x90\x91\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\xb9\xe5\x90\x91\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetOrientationString constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InOrientation_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InOrientation;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOrientationString constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOrientationString Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::NewProp_InOrientation_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::NewProp_InOrientation = { "InOrientation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetOrientationString_Parms, InOrientation), Z_Construct_UEnum_GenericAndroidFramework_EAndroidScreenOrientationType, METADATA_PARAMS(0, nullptr) }; // 2301464795
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetOrientationString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::NewProp_InOrientation_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::NewProp_InOrientation,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::PropPointers) < 2048);
// ********** End Function GetOrientationString Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetOrientationString", 	Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::BPFunctions_Android_eventGetOrientationString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::BPFunctions_Android_eventGetOrientationString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetOrientationString)
{
	P_GET_ENUM(EAndroidScreenOrientationType,Z_Param_InOrientation);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetOrientationString(EAndroidScreenOrientationType(Z_Param_InOrientation));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetOrientationString *************************

// ********** Begin Class UBPFunctions_Android Function GetOSLanguage ******************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics
{
	struct BPFunctions_Android_eventGetOSLanguage_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xaf\xad\xe8\xa8\x80\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xaf\xad\xe8\xa8\x80\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetOSLanguage constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOSLanguage constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOSLanguage Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetOSLanguage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::PropPointers) < 2048);
// ********** End Function GetOSLanguage Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetOSLanguage", 	Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::BPFunctions_Android_eventGetOSLanguage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::BPFunctions_Android_eventGetOSLanguage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetOSLanguage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetOSLanguage();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetOSLanguage ********************************

// ********** Begin Class UBPFunctions_Android Function GetProductName *****************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics
{
	struct BPFunctions_Android_eventGetProductName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe4\xba\xa7\xe5\x93\x81\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe4\xba\xa7\xe5\x93\x81\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetProductName constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetProductName constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetProductName Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetProductName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::PropPointers) < 2048);
// ********** End Function GetProductName Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetProductName", 	Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::BPFunctions_Android_eventGetProductName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::BPFunctions_Android_eventGetProductName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetProductName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetProductName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetProductName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetProductName();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetProductName *******************************

// ********** Begin Class UBPFunctions_Android Function GetProjectStorageInfo **********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics
{
	struct BPFunctions_Android_eventGetProjectStorageInfo_Parms
	{
		FAndroidStorageInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Storage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe9\xa1\xb9\xe7\x9b\xaeStorage\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe9\xa1\xb9\xe7\x9b\xaeStorage\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetProjectStorageInfo constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetProjectStorageInfo constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetProjectStorageInfo Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetProjectStorageInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidStorageInfo, METADATA_PARAMS(0, nullptr) }; // 1287974701
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::PropPointers) < 2048);
// ********** End Function GetProjectStorageInfo Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetProjectStorageInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::BPFunctions_Android_eventGetProjectStorageInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::BPFunctions_Android_eventGetProjectStorageInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetProjectStorageInfo)
{
	P_GET_STRUCT_REF(FAndroidStorageInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetProjectStorageInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetProjectStorageInfo ************************

// ********** Begin Class UBPFunctions_Android Function GetSharedPreferenceBool ********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics
{
	struct BPFunctions_Android_eventGetSharedPreferenceBool_Parms
	{
		FString InGroup;
		FString InKey;
		bool bDefaultValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|SharedPreferences" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe5\xb8\x83\xe5\xb0\x94\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe5\xb8\x83\xe5\xb0\x94\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSharedPreferenceBool constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InGroup;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static void NewProp_bDefaultValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefaultValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSharedPreferenceBool constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSharedPreferenceBool Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_InGroup = { "InGroup", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSharedPreferenceBool_Parms, InGroup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGroup_MetaData), NewProp_InGroup_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSharedPreferenceBool_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_bDefaultValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventGetSharedPreferenceBool_Parms*)Obj)->bDefaultValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_bDefaultValue = { "bDefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventGetSharedPreferenceBool_Parms), &Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_bDefaultValue_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventGetSharedPreferenceBool_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventGetSharedPreferenceBool_Parms), &Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_InGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_bDefaultValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::PropPointers) < 2048);
// ********** End Function GetSharedPreferenceBool Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetSharedPreferenceBool", 	Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::BPFunctions_Android_eventGetSharedPreferenceBool_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::BPFunctions_Android_eventGetSharedPreferenceBool_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetSharedPreferenceBool)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InGroup);
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_GET_UBOOL(Z_Param_bDefaultValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::GetSharedPreferenceBool(Z_Param_InGroup,Z_Param_InKey,Z_Param_bDefaultValue);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetSharedPreferenceBool **********************

// ********** Begin Class UBPFunctions_Android Function GetSharedPreferenceInt *********************
struct Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics
{
	struct BPFunctions_Android_eventGetSharedPreferenceInt_Parms
	{
		FString InGroup;
		FString InKey;
		int32 InDefaultValue;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|SharedPreferences" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe6\x95\xb4\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe6\x95\xb4\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSharedPreferenceInt constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InGroup;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InDefaultValue;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSharedPreferenceInt constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSharedPreferenceInt Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::NewProp_InGroup = { "InGroup", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSharedPreferenceInt_Parms, InGroup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGroup_MetaData), NewProp_InGroup_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSharedPreferenceInt_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::NewProp_InDefaultValue = { "InDefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSharedPreferenceInt_Parms, InDefaultValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSharedPreferenceInt_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::NewProp_InGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::NewProp_InDefaultValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::PropPointers) < 2048);
// ********** End Function GetSharedPreferenceInt Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetSharedPreferenceInt", 	Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::BPFunctions_Android_eventGetSharedPreferenceInt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::BPFunctions_Android_eventGetSharedPreferenceInt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetSharedPreferenceInt)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InGroup);
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_GET_PROPERTY(FIntProperty,Z_Param_InDefaultValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Android::GetSharedPreferenceInt(Z_Param_InGroup,Z_Param_InKey,Z_Param_InDefaultValue);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetSharedPreferenceInt ***********************

// ********** Begin Class UBPFunctions_Android Function GetSharedPreferenceString ******************
struct Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics
{
	struct BPFunctions_Android_eventGetSharedPreferenceString_Parms
	{
		FString InGroup;
		FString InKey;
		FString InDefaultValue;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|SharedPreferences" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InDefaultValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetSharedPreferenceString constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InGroup;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InDefaultValue;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSharedPreferenceString constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSharedPreferenceString Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::NewProp_InGroup = { "InGroup", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSharedPreferenceString_Parms, InGroup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGroup_MetaData), NewProp_InGroup_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSharedPreferenceString_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::NewProp_InDefaultValue = { "InDefaultValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSharedPreferenceString_Parms, InDefaultValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InDefaultValue_MetaData), NewProp_InDefaultValue_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSharedPreferenceString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::NewProp_InGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::NewProp_InDefaultValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::PropPointers) < 2048);
// ********** End Function GetSharedPreferenceString Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetSharedPreferenceString", 	Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::BPFunctions_Android_eventGetSharedPreferenceString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::BPFunctions_Android_eventGetSharedPreferenceString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetSharedPreferenceString)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InGroup);
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_GET_PROPERTY(FStrProperty,Z_Param_InDefaultValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetSharedPreferenceString(Z_Param_InGroup,Z_Param_InKey,Z_Param_InDefaultValue);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetSharedPreferenceString ********************

// ********** Begin Class UBPFunctions_Android Function GetStorageInfo *****************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics
{
	struct BPFunctions_Android_eventGetStorageInfo_Parms
	{
		FString InPath;
		FAndroidStorageInfo OutInfo;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Storage" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Storage\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Storage\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetStorageInfo constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetStorageInfo constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetStorageInfo Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::NewProp_InPath = { "InPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetStorageInfo_Parms, InPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPath_MetaData), NewProp_InPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetStorageInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FAndroidStorageInfo, METADATA_PARAMS(0, nullptr) }; // 1287974701
void Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventGetStorageInfo_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventGetStorageInfo_Parms), &Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::NewProp_InPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::NewProp_OutInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::PropPointers) < 2048);
// ********** End Function GetStorageInfo Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetStorageInfo", 	Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::BPFunctions_Android_eventGetStorageInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::BPFunctions_Android_eventGetStorageInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetStorageInfo)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPath);
	P_GET_STRUCT_REF(FAndroidStorageInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::GetStorageInfo(Z_Param_InPath,Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetStorageInfo *******************************

// ********** Begin Class UBPFunctions_Android Function GetSystemFontBytes *************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics
{
	struct BPFunctions_Android_eventGetSystemFontBytes_Parms
	{
		TArray<uint8> OutBytes;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Fonts" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xb3\xbb\xe7\xbb\x9f""Font\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xb3\xbb\xe7\xbb\x9f""Font\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSystemFontBytes constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutBytes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutBytes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSystemFontBytes constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSystemFontBytes Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::NewProp_OutBytes_Inner = { "OutBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::NewProp_OutBytes = { "OutBytes", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetSystemFontBytes_Parms, OutBytes), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::NewProp_OutBytes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::NewProp_OutBytes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::PropPointers) < 2048);
// ********** End Function GetSystemFontBytes Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetSystemFontBytes", 	Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::BPFunctions_Android_eventGetSystemFontBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::BPFunctions_Android_eventGetSystemFontBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetSystemFontBytes)
{
	P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBytes);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::GetSystemFontBytes(Z_Param_Out_OutBytes);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetSystemFontBytes ***************************

// ********** Begin Class UBPFunctions_Android Function GetTimeZoneId ******************************
struct Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics
{
	struct BPFunctions_Android_eventGetTimeZoneId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Basic" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x97\xb6\xe9\x97\xb4Zone ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x97\xb6\xe9\x97\xb4Zone ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTimeZoneId constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTimeZoneId constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTimeZoneId Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventGetTimeZoneId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::PropPointers) < 2048);
// ********** End Function GetTimeZoneId Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetTimeZoneId", 	Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::BPFunctions_Android_eventGetTimeZoneId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::BPFunctions_Android_eventGetTimeZoneId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetTimeZoneId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Android::GetTimeZoneId();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetTimeZoneId ********************************

// ********** Begin Class UBPFunctions_Android Function GetVolumeButtonsHandledBySystem ************
struct Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics
{
	struct BPFunctions_Android_eventGetVolumeButtonsHandledBySystem_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Audio|Volume" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Volume Buttons Handled\xe6\x8c\x89\xe7\xb3\xbb\xe7\xbb\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Volume Buttons Handled\xe6\x8c\x89\xe7\xb3\xbb\xe7\xbb\x9f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetVolumeButtonsHandledBySystem constinit property declarations *******
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVolumeButtonsHandledBySystem constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVolumeButtonsHandledBySystem Property Definitions ******************
void Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventGetVolumeButtonsHandledBySystem_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventGetVolumeButtonsHandledBySystem_Parms), &Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::PropPointers) < 2048);
// ********** End Function GetVolumeButtonsHandledBySystem Property Definitions ********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "GetVolumeButtonsHandledBySystem", 	Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::BPFunctions_Android_eventGetVolumeButtonsHandledBySystem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::BPFunctions_Android_eventGetVolumeButtonsHandledBySystem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execGetVolumeButtonsHandledBySystem)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::GetVolumeButtonsHandledBySystem();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function GetVolumeButtonsHandledBySystem **************

// ********** Begin Class UBPFunctions_Android Function HasAdvertisingId ***************************
struct Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics
{
	struct BPFunctions_Android_eventHasAdvertisingId_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Device|Identifiers" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe5\xb9\xbf\xe5\x91\x8a ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe5\xb9\xbf\xe5\x91\x8a ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HasAdvertisingId constinit property declarations **********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasAdvertisingId constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasAdvertisingId Property Definitions *********************************
void Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventHasAdvertisingId_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventHasAdvertisingId_Parms), &Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::PropPointers) < 2048);
// ********** End Function HasAdvertisingId Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "HasAdvertisingId", 	Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::BPFunctions_Android_eventHasAdvertisingId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::BPFunctions_Android_eventHasAdvertisingId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execHasAdvertisingId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::HasAdvertisingId();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function HasAdvertisingId *****************************

// ********** Begin Class UBPFunctions_Android Function HasAndroidPersistentDownloadDir ************
struct Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics
{
	struct BPFunctions_Android_eventHasAndroidPersistentDownloadDir_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|FileSystem|Paths" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab""Android Persistent Download\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab""Android Persistent Download\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HasAndroidPersistentDownloadDir constinit property declarations *******
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasAndroidPersistentDownloadDir constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasAndroidPersistentDownloadDir Property Definitions ******************
void Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventHasAndroidPersistentDownloadDir_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventHasAndroidPersistentDownloadDir_Parms), &Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::PropPointers) < 2048);
// ********** End Function HasAndroidPersistentDownloadDir Property Definitions ********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "HasAndroidPersistentDownloadDir", 	Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::BPFunctions_Android_eventHasAndroidPersistentDownloadDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::BPFunctions_Android_eventHasAndroidPersistentDownloadDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execHasAndroidPersistentDownloadDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::HasAndroidPersistentDownloadDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function HasAndroidPersistentDownloadDir **************

// ********** Begin Class UBPFunctions_Android Function HasManifestMetaDataKey *********************
struct Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics
{
	struct BPFunctions_Android_eventHasManifestMetaDataKey_Parms
	{
		FString InKey;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Manifest" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabManifest Meta\xe6\x95\xb0\xe6\x8d\xae\xe9\x94\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabManifest Meta\xe6\x95\xb0\xe6\x8d\xae\xe9\x94\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasManifestMetaDataKey constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasManifestMetaDataKey constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasManifestMetaDataKey Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventHasManifestMetaDataKey_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventHasManifestMetaDataKey_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventHasManifestMetaDataKey_Parms), &Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::PropPointers) < 2048);
// ********** End Function HasManifestMetaDataKey Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "HasManifestMetaDataKey", 	Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::BPFunctions_Android_eventHasManifestMetaDataKey_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::BPFunctions_Android_eventHasManifestMetaDataKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execHasManifestMetaDataKey)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::HasManifestMetaDataKey(Z_Param_InKey);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function HasManifestMetaDataKey ***********************

// ********** Begin Class UBPFunctions_Android Function HasSharedPreference ************************
struct Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics
{
	struct BPFunctions_Android_eventHasSharedPreference_Parms
	{
		FString InGroup;
		FString InKey;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|SharedPreferences" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function HasSharedPreference constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InGroup;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasSharedPreference constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasSharedPreference Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::NewProp_InGroup = { "InGroup", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventHasSharedPreference_Parms, InGroup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGroup_MetaData), NewProp_InGroup_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventHasSharedPreference_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventHasSharedPreference_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventHasSharedPreference_Parms), &Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::NewProp_InGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::PropPointers) < 2048);
// ********** End Function HasSharedPreference Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "HasSharedPreference", 	Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::BPFunctions_Android_eventHasSharedPreference_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::BPFunctions_Android_eventHasSharedPreference_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execHasSharedPreference)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InGroup);
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::HasSharedPreference(Z_Param_InGroup,Z_Param_InKey);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function HasSharedPreference **************************

// ********** Begin Class UBPFunctions_Android Function HasVulkanDriverSupport *********************
struct Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics
{
	struct BPFunctions_Android_eventHasVulkanDriverSupport_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Capabilities|Query" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabVulkan\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x94\xaf\xe6\x8c\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xabVulkan\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x94\xaf\xe6\x8c\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HasVulkanDriverSupport constinit property declarations ****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasVulkanDriverSupport constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasVulkanDriverSupport Property Definitions ***************************
void Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventHasVulkanDriverSupport_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventHasVulkanDriverSupport_Parms), &Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::PropPointers) < 2048);
// ********** End Function HasVulkanDriverSupport Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "HasVulkanDriverSupport", 	Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::BPFunctions_Android_eventHasVulkanDriverSupport_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::BPFunctions_Android_eventHasVulkanDriverSupport_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execHasVulkanDriverSupport)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::HasVulkanDriverSupport();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function HasVulkanDriverSupport ***********************

// ********** Begin Class UBPFunctions_Android Function IsAllowedRemoteNotifications ***************
struct Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics
{
	struct BPFunctions_Android_eventIsAllowedRemoteNotifications_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad""Allowed Remote Notifications\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad""Allowed Remote Notifications\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsAllowedRemoteNotifications constinit property declarations **********
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsAllowedRemoteNotifications constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsAllowedRemoteNotifications Property Definitions *********************
void Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsAllowedRemoteNotifications_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsAllowedRemoteNotifications_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::PropPointers) < 2048);
// ********** End Function IsAllowedRemoteNotifications Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsAllowedRemoteNotifications", 	Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::BPFunctions_Android_eventIsAllowedRemoteNotifications_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::BPFunctions_Android_eventIsAllowedRemoteNotifications_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsAllowedRemoteNotifications)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsAllowedRemoteNotifications();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsAllowedRemoteNotifications *****************

// ********** Begin Class UBPFunctions_Android Function IsGamepadAttached **************************
struct Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics
{
	struct BPFunctions_Android_eventIsGamepadAttached_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Input|Devices" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadGamepad Attached\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadGamepad Attached\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsGamepadAttached constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsGamepadAttached constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsGamepadAttached Property Definitions ********************************
void Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsGamepadAttached_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsGamepadAttached_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::PropPointers) < 2048);
// ********** End Function IsGamepadAttached Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsGamepadAttached", 	Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::BPFunctions_Android_eventIsGamepadAttached_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::BPFunctions_Android_eventIsGamepadAttached_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsGamepadAttached)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsGamepadAttached();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsGamepadAttached ****************************

// ********** Begin Class UBPFunctions_Android Function IsIMUSamplingEnabled ***********************
struct Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics
{
	struct BPFunctions_Android_eventIsIMUSamplingEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Input|Sensors" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadMU Sampling\xe5\xb7\xb2\xe5\x90\xaf\xe7\x94\xa8\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadMU Sampling\xe5\xb7\xb2\xe5\x90\xaf\xe7\x94\xa8\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsIMUSamplingEnabled constinit property declarations ******************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsIMUSamplingEnabled constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsIMUSamplingEnabled Property Definitions *****************************
void Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsIMUSamplingEnabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsIMUSamplingEnabled_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::PropPointers) < 2048);
// ********** End Function IsIMUSamplingEnabled Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsIMUSamplingEnabled", 	Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::BPFunctions_Android_eventIsIMUSamplingEnabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::BPFunctions_Android_eventIsIMUSamplingEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsIMUSamplingEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsIMUSamplingEnabled();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsIMUSamplingEnabled *************************

// ********** Begin Class UBPFunctions_Android Function IsLowMemoryDevice **************************
struct Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics
{
	struct BPFunctions_Android_eventIsLowMemoryDevice_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|Memory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadLow\xe5\x86\x85\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadLow\xe5\x86\x85\xe5\xad\x98\xe8\xae\xbe\xe5\xa4\x87\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsLowMemoryDevice constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsLowMemoryDevice constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsLowMemoryDevice Property Definitions ********************************
void Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsLowMemoryDevice_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsLowMemoryDevice_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::PropPointers) < 2048);
// ********** End Function IsLowMemoryDevice Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsLowMemoryDevice", 	Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::BPFunctions_Android_eventIsLowMemoryDevice_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::BPFunctions_Android_eventIsLowMemoryDevice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsLowMemoryDevice)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsLowMemoryDevice();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsLowMemoryDevice ****************************

// ********** Begin Class UBPFunctions_Android Function IsMusicActive ******************************
struct Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics
{
	struct BPFunctions_Android_eventIsMusicActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Audio|Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadMusic\xe6\xbf\x80\xe6\xb4\xbb\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadMusic\xe6\xbf\x80\xe6\xb4\xbb\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsMusicActive constinit property declarations *************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsMusicActive constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsMusicActive Property Definitions ************************************
void Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsMusicActive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsMusicActive_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::PropPointers) < 2048);
// ********** End Function IsMusicActive Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsMusicActive", 	Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::BPFunctions_Android_eventIsMusicActive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::BPFunctions_Android_eventIsMusicActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsMusicActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsMusicActive();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsMusicActive ********************************

// ********** Begin Class UBPFunctions_Android Function IsPackageInstalled *************************
struct Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics
{
	struct BPFunctions_Android_eventIsPackageInstalled_Parms
	{
		FString InPackageName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Intent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadPackage Installed\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadPackage Installed\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPackageName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsPackageInstalled constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPackageName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsPackageInstalled constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsPackageInstalled Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::NewProp_InPackageName = { "InPackageName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventIsPackageInstalled_Parms, InPackageName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPackageName_MetaData), NewProp_InPackageName_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsPackageInstalled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsPackageInstalled_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::NewProp_InPackageName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::PropPointers) < 2048);
// ********** End Function IsPackageInstalled Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsPackageInstalled", 	Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::BPFunctions_Android_eventIsPackageInstalled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::BPFunctions_Android_eventIsPackageInstalled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsPackageInstalled)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPackageName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsPackageInstalled(Z_Param_InPackageName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsPackageInstalled ***************************

// ********** Begin Class UBPFunctions_Android Function IsScreenCaptureDisabled ********************
struct Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics
{
	struct BPFunctions_Android_eventIsScreenCaptureDisabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Screen" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadScreen Capture\xe5\xb7\xb2\xe7\xa6\x81\xe7\x94\xa8\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadScreen Capture\xe5\xb7\xb2\xe7\xa6\x81\xe7\x94\xa8\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsScreenCaptureDisabled constinit property declarations ***************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsScreenCaptureDisabled constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsScreenCaptureDisabled Property Definitions **************************
void Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsScreenCaptureDisabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsScreenCaptureDisabled_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::PropPointers) < 2048);
// ********** End Function IsScreenCaptureDisabled Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsScreenCaptureDisabled", 	Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::BPFunctions_Android_eventIsScreenCaptureDisabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::BPFunctions_Android_eventIsScreenCaptureDisabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsScreenCaptureDisabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsScreenCaptureDisabled();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsScreenCaptureDisabled **********************

// ********** Begin Class UBPFunctions_Android Function IsScreensaverEnabled ***********************
struct Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics
{
	struct BPFunctions_Android_eventIsScreensaverEnabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Audio|Status" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadScreensaver\xe5\xb7\xb2\xe5\x90\xaf\xe7\x94\xa8\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadScreensaver\xe5\xb7\xb2\xe5\x90\xaf\xe7\x94\xa8\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsScreensaverEnabled constinit property declarations ******************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsScreensaverEnabled constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsScreensaverEnabled Property Definitions *****************************
void Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsScreensaverEnabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsScreensaverEnabled_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::PropPointers) < 2048);
// ********** End Function IsScreensaverEnabled Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsScreensaverEnabled", 	Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::BPFunctions_Android_eventIsScreensaverEnabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::BPFunctions_Android_eventIsScreensaverEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsScreensaverEnabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsScreensaverEnabled();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsScreensaverEnabled *************************

// ********** Begin Class UBPFunctions_Android Function IsSupportedAndroidDevice *******************
struct Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics
{
	struct BPFunctions_Android_eventIsSupportedAndroidDevice_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Capabilities|Query" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x94\xaf\xe6\x8c\x81""Android\xe8\xae\xbe\xe5\xa4\x87\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x94\xaf\xe6\x8c\x81""Android\xe8\xae\xbe\xe5\xa4\x87\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsSupportedAndroidDevice constinit property declarations **************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsSupportedAndroidDevice constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsSupportedAndroidDevice Property Definitions *************************
void Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsSupportedAndroidDevice_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsSupportedAndroidDevice_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::PropPointers) < 2048);
// ********** End Function IsSupportedAndroidDevice Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsSupportedAndroidDevice", 	Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::BPFunctions_Android_eventIsSupportedAndroidDevice_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::BPFunctions_Android_eventIsSupportedAndroidDevice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsSupportedAndroidDevice)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsSupportedAndroidDevice();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsSupportedAndroidDevice *********************

// ********** Begin Class UBPFunctions_Android Function IsUsingVulkan ******************************
struct Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics
{
	struct BPFunctions_Android_eventIsUsingVulkan_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadUsing Vulkan\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadUsing Vulkan\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsUsingVulkan constinit property declarations *************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsUsingVulkan constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsUsingVulkan Property Definitions ************************************
void Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsUsingVulkan_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsUsingVulkan_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::PropPointers) < 2048);
// ********** End Function IsUsingVulkan Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsUsingVulkan", 	Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::BPFunctions_Android_eventIsUsingVulkan_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::BPFunctions_Android_eventIsUsingVulkan_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsUsingVulkan)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsUsingVulkan();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsUsingVulkan ********************************

// ********** Begin Class UBPFunctions_Android Function IsVulkanAvailable **************************
struct Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics
{
	struct BPFunctions_Android_eventIsVulkanAvailable_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Capabilities|Query" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadVulkan\xe5\x8f\xaf\xe7\x94\xa8\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadVulkan\xe5\x8f\xaf\xe7\x94\xa8\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsVulkanAvailable constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsVulkanAvailable constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsVulkanAvailable Property Definitions ********************************
void Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventIsVulkanAvailable_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventIsVulkanAvailable_Parms), &Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::PropPointers) < 2048);
// ********** End Function IsVulkanAvailable Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "IsVulkanAvailable", 	Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::BPFunctions_Android_eventIsVulkanAvailable_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::BPFunctions_Android_eventIsVulkanAvailable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execIsVulkanAvailable)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::IsVulkanAvailable();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function IsVulkanAvailable ****************************

// ********** Begin Class UBPFunctions_Android Function LaunchPackage ******************************
struct Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics
{
	struct BPFunctions_Android_eventLaunchPackage_Parms
	{
		FString InPackageName;
		FString InExtraKey;
		FString InExtraValue;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Intent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\x90\xaf\xe5\x8a\xa8Package\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\x90\xaf\xe5\x8a\xa8Package\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPackageName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InExtraKey_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InExtraValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LaunchPackage constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPackageName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InExtraKey;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InExtraValue;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LaunchPackage constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LaunchPackage Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::NewProp_InPackageName = { "InPackageName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventLaunchPackage_Parms, InPackageName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPackageName_MetaData), NewProp_InPackageName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::NewProp_InExtraKey = { "InExtraKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventLaunchPackage_Parms, InExtraKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InExtraKey_MetaData), NewProp_InExtraKey_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::NewProp_InExtraValue = { "InExtraValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventLaunchPackage_Parms, InExtraValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InExtraValue_MetaData), NewProp_InExtraValue_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventLaunchPackage_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventLaunchPackage_Parms), &Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::NewProp_InPackageName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::NewProp_InExtraKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::NewProp_InExtraValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::PropPointers) < 2048);
// ********** End Function LaunchPackage Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "LaunchPackage", 	Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::BPFunctions_Android_eventLaunchPackage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::BPFunctions_Android_eventLaunchPackage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execLaunchPackage)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPackageName);
	P_GET_PROPERTY(FStrProperty,Z_Param_InExtraKey);
	P_GET_PROPERTY(FStrProperty,Z_Param_InExtraValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::LaunchPackage(Z_Param_InPackageName,Z_Param_InExtraKey,Z_Param_InExtraValue);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function LaunchPackage ********************************

// ********** Begin Class UBPFunctions_Android Function LaunchUrl **********************************
struct Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics
{
	struct BPFunctions_Android_eventLaunchUrl_Parms
	{
		FString InUrl;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Intent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\x90\xaf\xe5\x8a\xa8URL\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\x90\xaf\xe5\x8a\xa8URL\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InUrl_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LaunchUrl constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InUrl;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LaunchUrl constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LaunchUrl Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::NewProp_InUrl = { "InUrl", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventLaunchUrl_Parms, InUrl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InUrl_MetaData), NewProp_InUrl_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventLaunchUrl_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventLaunchUrl_Parms), &Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::NewProp_InUrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::PropPointers) < 2048);
// ********** End Function LaunchUrl Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "LaunchUrl", 	Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::BPFunctions_Android_eventLaunchUrl_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::BPFunctions_Android_eventLaunchUrl_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execLaunchUrl)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InUrl);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::LaunchUrl(Z_Param_InUrl);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function LaunchUrl ************************************

// ********** Begin Class UBPFunctions_Android Function RegisterForRemoteNotifications *************
struct Z_Construct_UFunction_UBPFunctions_Android_RegisterForRemoteNotifications_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb3\xa8\xe5\x86\x8c\xe7\x94\xa8\xe4\xba\x8eRemote Notifications\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb3\xa8\xe5\x86\x8c\xe7\x94\xa8\xe4\xba\x8eRemote Notifications\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterForRemoteNotifications constinit property declarations ********
// ********** End Function RegisterForRemoteNotifications constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_RegisterForRemoteNotifications_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "RegisterForRemoteNotifications", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_RegisterForRemoteNotifications_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_RegisterForRemoteNotifications_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UBPFunctions_Android_RegisterForRemoteNotifications()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_RegisterForRemoteNotifications_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execRegisterForRemoteNotifications)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::RegisterForRemoteNotifications();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function RegisterForRemoteNotifications ***************

// ********** Begin Class UBPFunctions_Android Function RequestMinimizeApplication *****************
struct Z_Construct_UFunction_UBPFunctions_Android_RequestMinimizeApplication_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Screen" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xb7\xe6\xb1\x82Minimize\xe5\xba\x94\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xb7\xe6\xb1\x82Minimize\xe5\xba\x94\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestMinimizeApplication constinit property declarations ************
// ********** End Function RequestMinimizeApplication constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_RequestMinimizeApplication_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "RequestMinimizeApplication", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_RequestMinimizeApplication_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_RequestMinimizeApplication_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UBPFunctions_Android_RequestMinimizeApplication()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_RequestMinimizeApplication_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execRequestMinimizeApplication)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::RequestMinimizeApplication();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function RequestMinimizeApplication *******************

// ********** Begin Class UBPFunctions_Android Function RestartApplication *************************
struct Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics
{
	struct BPFunctions_Android_eventRestartApplication_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Screen" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Restart\xe5\xba\x94\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Restart\xe5\xba\x94\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RestartApplication constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestartApplication constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestartApplication Property Definitions *******************************
void Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventRestartApplication_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventRestartApplication_Parms), &Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::PropPointers) < 2048);
// ********** End Function RestartApplication Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "RestartApplication", 	Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::BPFunctions_Android_eventRestartApplication_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::BPFunctions_Android_eventRestartApplication_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_RestartApplication()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_RestartApplication_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execRestartApplication)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::RestartApplication();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function RestartApplication ***************************

// ********** Begin Class UBPFunctions_Android Function RestartApplicationWithIntent ***************
struct Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics
{
	struct BPFunctions_Android_eventRestartApplicationWithIntent_Parms
	{
		FString InIntentString;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Screen" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Restart\xe5\xba\x94\xe7\x94\xa8\xe5\xb8\xa6Intent\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Restart\xe5\xba\x94\xe7\x94\xa8\xe5\xb8\xa6Intent\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InIntentString_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RestartApplicationWithIntent constinit property declarations **********
	static const UECodeGen_Private::FStrPropertyParams NewProp_InIntentString;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestartApplicationWithIntent constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestartApplicationWithIntent Property Definitions *********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::NewProp_InIntentString = { "InIntentString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventRestartApplicationWithIntent_Parms, InIntentString), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InIntentString_MetaData), NewProp_InIntentString_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::NewProp_InIntentString,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::PropPointers) < 2048);
// ********** End Function RestartApplicationWithIntent Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "RestartApplicationWithIntent", 	Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::BPFunctions_Android_eventRestartApplicationWithIntent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::BPFunctions_Android_eventRestartApplicationWithIntent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execRestartApplicationWithIntent)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InIntentString);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::RestartApplicationWithIntent(Z_Param_InIntentString);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function RestartApplicationWithIntent *****************

// ********** Begin Class UBPFunctions_Android Function ScheduleLocalNotificationAtTime ************
struct Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics
{
	struct BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms
	{
		FDateTime FireDateTime;
		bool bUseLocalTime;
		FText Title;
		FText Body;
		FText Action;
		FString ActivationEvent;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Schedule\xe6\x9c\xac\xe5\x9c\xb0Notification At\xe6\x97\xb6\xe9\x97\xb4\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Schedule\xe6\x9c\xac\xe5\x9c\xb0Notification At\xe6\x97\xb6\xe9\x97\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireDateTime_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Body_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Action_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationEvent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ScheduleLocalNotificationAtTime constinit property declarations *******
	static const UECodeGen_Private::FStructPropertyParams NewProp_FireDateTime;
	static void NewProp_bUseLocalTime_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseLocalTime;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Title;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Body;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Action;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActivationEvent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ScheduleLocalNotificationAtTime constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ScheduleLocalNotificationAtTime Property Definitions ******************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_FireDateTime = { "FireDateTime", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms, FireDateTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireDateTime_MetaData), NewProp_FireDateTime_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_bUseLocalTime_SetBit(void* Obj)
{
	((BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms*)Obj)->bUseLocalTime = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_bUseLocalTime = { "bUseLocalTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms), &Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_bUseLocalTime_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_Body = { "Body", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms, Body), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Body_MetaData), NewProp_Body_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms, Action), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Action_MetaData), NewProp_Action_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_ActivationEvent = { "ActivationEvent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms, ActivationEvent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationEvent_MetaData), NewProp_ActivationEvent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_FireDateTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_bUseLocalTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_Body,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_ActivationEvent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::PropPointers) < 2048);
// ********** End Function ScheduleLocalNotificationAtTime Property Definitions ********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "ScheduleLocalNotificationAtTime", 	Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::BPFunctions_Android_eventScheduleLocalNotificationAtTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execScheduleLocalNotificationAtTime)
{
	P_GET_STRUCT_REF(FDateTime,Z_Param_Out_FireDateTime);
	P_GET_UBOOL(Z_Param_bUseLocalTime);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Title);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Body);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Action);
	P_GET_PROPERTY(FStrProperty,Z_Param_ActivationEvent);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Android::ScheduleLocalNotificationAtTime(Z_Param_Out_FireDateTime,Z_Param_bUseLocalTime,Z_Param_Out_Title,Z_Param_Out_Body,Z_Param_Out_Action,Z_Param_ActivationEvent);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function ScheduleLocalNotificationAtTime **************

// ********** Begin Class UBPFunctions_Android Function ScheduleLocalNotificationBadgeAtTime *******
struct Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics
{
	struct BPFunctions_Android_eventScheduleLocalNotificationBadgeAtTime_Parms
	{
		FDateTime FireDateTime;
		bool bUseLocalTime;
		FString ActivationEvent;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Schedule\xe6\x9c\xac\xe5\x9c\xb0Notification Badge At\xe6\x97\xb6\xe9\x97\xb4\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Schedule\xe6\x9c\xac\xe5\x9c\xb0Notification Badge At\xe6\x97\xb6\xe9\x97\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FireDateTime_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationEvent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ScheduleLocalNotificationBadgeAtTime constinit property declarations **
	static const UECodeGen_Private::FStructPropertyParams NewProp_FireDateTime;
	static void NewProp_bUseLocalTime_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bUseLocalTime;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActivationEvent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ScheduleLocalNotificationBadgeAtTime constinit property declarations ****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ScheduleLocalNotificationBadgeAtTime Property Definitions *************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::NewProp_FireDateTime = { "FireDateTime", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationBadgeAtTime_Parms, FireDateTime), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FireDateTime_MetaData), NewProp_FireDateTime_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::NewProp_bUseLocalTime_SetBit(void* Obj)
{
	((BPFunctions_Android_eventScheduleLocalNotificationBadgeAtTime_Parms*)Obj)->bUseLocalTime = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::NewProp_bUseLocalTime = { "bUseLocalTime", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventScheduleLocalNotificationBadgeAtTime_Parms), &Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::NewProp_bUseLocalTime_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::NewProp_ActivationEvent = { "ActivationEvent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationBadgeAtTime_Parms, ActivationEvent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationEvent_MetaData), NewProp_ActivationEvent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationBadgeAtTime_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::NewProp_FireDateTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::NewProp_bUseLocalTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::NewProp_ActivationEvent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::PropPointers) < 2048);
// ********** End Function ScheduleLocalNotificationBadgeAtTime Property Definitions ***************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "ScheduleLocalNotificationBadgeAtTime", 	Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::BPFunctions_Android_eventScheduleLocalNotificationBadgeAtTime_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::BPFunctions_Android_eventScheduleLocalNotificationBadgeAtTime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execScheduleLocalNotificationBadgeAtTime)
{
	P_GET_STRUCT_REF(FDateTime,Z_Param_Out_FireDateTime);
	P_GET_UBOOL(Z_Param_bUseLocalTime);
	P_GET_PROPERTY(FStrProperty,Z_Param_ActivationEvent);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Android::ScheduleLocalNotificationBadgeAtTime(Z_Param_Out_FireDateTime,Z_Param_bUseLocalTime,Z_Param_ActivationEvent);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function ScheduleLocalNotificationBadgeAtTime *********

// ********** Begin Class UBPFunctions_Android Function ScheduleLocalNotificationBadgeFromNow ******
struct Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics
{
	struct BPFunctions_Android_eventScheduleLocalNotificationBadgeFromNow_Parms
	{
		int32 InSecondsFromNow;
		FString ActivationEvent;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Schedule\xe6\x9c\xac\xe5\x9c\xb0Notification Badge From Now\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Schedule\xe6\x9c\xac\xe5\x9c\xb0Notification Badge From Now\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationEvent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ScheduleLocalNotificationBadgeFromNow constinit property declarations *
	static const UECodeGen_Private::FIntPropertyParams NewProp_InSecondsFromNow;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActivationEvent;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ScheduleLocalNotificationBadgeFromNow constinit property declarations ***
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ScheduleLocalNotificationBadgeFromNow Property Definitions ************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::NewProp_InSecondsFromNow = { "InSecondsFromNow", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationBadgeFromNow_Parms, InSecondsFromNow), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::NewProp_ActivationEvent = { "ActivationEvent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationBadgeFromNow_Parms, ActivationEvent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationEvent_MetaData), NewProp_ActivationEvent_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::NewProp_InSecondsFromNow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::NewProp_ActivationEvent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::PropPointers) < 2048);
// ********** End Function ScheduleLocalNotificationBadgeFromNow Property Definitions **************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "ScheduleLocalNotificationBadgeFromNow", 	Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::BPFunctions_Android_eventScheduleLocalNotificationBadgeFromNow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::BPFunctions_Android_eventScheduleLocalNotificationBadgeFromNow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execScheduleLocalNotificationBadgeFromNow)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InSecondsFromNow);
	P_GET_PROPERTY(FStrProperty,Z_Param_ActivationEvent);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::ScheduleLocalNotificationBadgeFromNow(Z_Param_InSecondsFromNow,Z_Param_ActivationEvent);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function ScheduleLocalNotificationBadgeFromNow ********

// ********** Begin Class UBPFunctions_Android Function ScheduleLocalNotificationFromNow ***********
struct Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics
{
	struct BPFunctions_Android_eventScheduleLocalNotificationFromNow_Parms
	{
		int32 InSecondsFromNow;
		FText Title;
		FText Body;
		FText Action;
		FString ActivationEvent;
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Schedule\xe6\x9c\xac\xe5\x9c\xb0Notification From Now\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Schedule\xe6\x9c\xac\xe5\x9c\xb0Notification From Now\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Title_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Body_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Action_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActivationEvent_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ScheduleLocalNotificationFromNow constinit property declarations ******
	static const UECodeGen_Private::FIntPropertyParams NewProp_InSecondsFromNow;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Title;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Body;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Action;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ActivationEvent;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ScheduleLocalNotificationFromNow constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ScheduleLocalNotificationFromNow Property Definitions *****************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_InSecondsFromNow = { "InSecondsFromNow", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationFromNow_Parms, InSecondsFromNow), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_Title = { "Title", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationFromNow_Parms, Title), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Title_MetaData), NewProp_Title_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_Body = { "Body", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationFromNow_Parms, Body), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Body_MetaData), NewProp_Body_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_Action = { "Action", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationFromNow_Parms, Action), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Action_MetaData), NewProp_Action_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_ActivationEvent = { "ActivationEvent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationFromNow_Parms, ActivationEvent), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActivationEvent_MetaData), NewProp_ActivationEvent_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventScheduleLocalNotificationFromNow_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_InSecondsFromNow,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_Title,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_Body,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_Action,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_ActivationEvent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::PropPointers) < 2048);
// ********** End Function ScheduleLocalNotificationFromNow Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "ScheduleLocalNotificationFromNow", 	Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::BPFunctions_Android_eventScheduleLocalNotificationFromNow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::BPFunctions_Android_eventScheduleLocalNotificationFromNow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execScheduleLocalNotificationFromNow)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InSecondsFromNow);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Title);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Body);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Action);
	P_GET_PROPERTY(FStrProperty,Z_Param_ActivationEvent);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Android::ScheduleLocalNotificationFromNow(Z_Param_InSecondsFromNow,Z_Param_Out_Title,Z_Param_Out_Body,Z_Param_Out_Action,Z_Param_ActivationEvent);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function ScheduleLocalNotificationFromNow *************

// ********** Begin Class UBPFunctions_Android Function SendBroadcast ******************************
struct Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics
{
	struct BPFunctions_Android_eventSendBroadcast_Parms
	{
		FString InPackageName;
		FString InExtraKey;
		FString InExtraValue;
		bool bExitApplication;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Intent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x8f\x91\xe9\x80\x81\xe5\xb9\xbf\xe6\x92\xad\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x8f\x91\xe9\x80\x81\xe5\xb9\xbf\xe6\x92\xad\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPackageName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InExtraKey_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InExtraValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SendBroadcast constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPackageName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InExtraKey;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InExtraValue;
	static void NewProp_bExitApplication_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bExitApplication;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SendBroadcast constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SendBroadcast Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_InPackageName = { "InPackageName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSendBroadcast_Parms, InPackageName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPackageName_MetaData), NewProp_InPackageName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_InExtraKey = { "InExtraKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSendBroadcast_Parms, InExtraKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InExtraKey_MetaData), NewProp_InExtraKey_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_InExtraValue = { "InExtraValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSendBroadcast_Parms, InExtraValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InExtraValue_MetaData), NewProp_InExtraValue_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_bExitApplication_SetBit(void* Obj)
{
	((BPFunctions_Android_eventSendBroadcast_Parms*)Obj)->bExitApplication = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_bExitApplication = { "bExitApplication", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventSendBroadcast_Parms), &Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_bExitApplication_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventSendBroadcast_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventSendBroadcast_Parms), &Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_InPackageName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_InExtraKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_InExtraValue,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_bExitApplication,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::PropPointers) < 2048);
// ********** End Function SendBroadcast Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SendBroadcast", 	Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::BPFunctions_Android_eventSendBroadcast_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::BPFunctions_Android_eventSendBroadcast_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSendBroadcast)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPackageName);
	P_GET_PROPERTY(FStrProperty,Z_Param_InExtraKey);
	P_GET_PROPERTY(FStrProperty,Z_Param_InExtraValue);
	P_GET_UBOOL(Z_Param_bExitApplication);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::SendBroadcast(Z_Param_InPackageName,Z_Param_InExtraKey,Z_Param_InExtraValue,Z_Param_bExitApplication);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SendBroadcast ********************************

// ********** Begin Class UBPFunctions_Android Function SetClipboardText ***************************
struct Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics
{
	struct BPFunctions_Android_eventSetClipboardText_Parms
	{
		FString InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Clipboard" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xae""Clipboard\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xae""Clipboard\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetClipboardText constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetClipboardText constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetClipboardText Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetClipboardText_Parms, InText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InText_MetaData), NewProp_InText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::PropPointers) < 2048);
// ********** End Function SetClipboardText Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SetClipboardText", 	Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::BPFunctions_Android_eventSetClipboardText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::BPFunctions_Android_eventSetClipboardText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSetClipboardText)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::SetClipboardText(Z_Param_InText);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SetClipboardText *****************************

// ********** Begin Class UBPFunctions_Android Function SetInputDeviceVibration ********************
struct Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics
{
	struct BPFunctions_Android_eventSetInputDeviceVibration_Parms
	{
		int32 InDeviceId;
		int32 LeftIntensity;
		int32 LeftDurationMs;
		int32 RightIntensity;
		int32 RightDurationMs;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Input|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xae\xe8\xbe\x93\xe5\x85\xa5\xe8\xae\xbe\xe5\xa4\x87Vibration\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xae\xe8\xbe\x93\xe5\x85\xa5\xe8\xae\xbe\xe5\xa4\x87Vibration\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetInputDeviceVibration constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InDeviceId;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LeftIntensity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_LeftDurationMs;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RightIntensity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_RightDurationMs;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetInputDeviceVibration constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetInputDeviceVibration Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_InDeviceId = { "InDeviceId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetInputDeviceVibration_Parms, InDeviceId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_LeftIntensity = { "LeftIntensity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetInputDeviceVibration_Parms, LeftIntensity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_LeftDurationMs = { "LeftDurationMs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetInputDeviceVibration_Parms, LeftDurationMs), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_RightIntensity = { "RightIntensity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetInputDeviceVibration_Parms, RightIntensity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_RightDurationMs = { "RightDurationMs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetInputDeviceVibration_Parms, RightDurationMs), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventSetInputDeviceVibration_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventSetInputDeviceVibration_Parms), &Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_InDeviceId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_LeftIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_LeftDurationMs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_RightIntensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_RightDurationMs,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::PropPointers) < 2048);
// ********** End Function SetInputDeviceVibration Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SetInputDeviceVibration", 	Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::BPFunctions_Android_eventSetInputDeviceVibration_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::BPFunctions_Android_eventSetInputDeviceVibration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSetInputDeviceVibration)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InDeviceId);
	P_GET_PROPERTY(FIntProperty,Z_Param_LeftIntensity);
	P_GET_PROPERTY(FIntProperty,Z_Param_LeftDurationMs);
	P_GET_PROPERTY(FIntProperty,Z_Param_RightIntensity);
	P_GET_PROPERTY(FIntProperty,Z_Param_RightDurationMs);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::SetInputDeviceVibration(Z_Param_InDeviceId,Z_Param_LeftIntensity,Z_Param_LeftDurationMs,Z_Param_RightIntensity,Z_Param_RightDurationMs);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SetInputDeviceVibration **********************

// ********** Begin Class UBPFunctions_Android Function SetKeepScreenOn ****************************
struct Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics
{
	struct BPFunctions_Android_eventSetKeepScreenOn_Parms
	{
		bool bEnable;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Screen" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xaeKeep Screen On\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xaeKeep Screen On\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetKeepScreenOn constinit property declarations ***********************
	static void NewProp_bEnable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetKeepScreenOn constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetKeepScreenOn Property Definitions **********************************
void Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::NewProp_bEnable_SetBit(void* Obj)
{
	((BPFunctions_Android_eventSetKeepScreenOn_Parms*)Obj)->bEnable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::NewProp_bEnable = { "bEnable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventSetKeepScreenOn_Parms), &Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::NewProp_bEnable_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::NewProp_bEnable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::PropPointers) < 2048);
// ********** End Function SetKeepScreenOn Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SetKeepScreenOn", 	Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::BPFunctions_Android_eventSetKeepScreenOn_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::BPFunctions_Android_eventSetKeepScreenOn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSetKeepScreenOn)
{
	P_GET_UBOOL(Z_Param_bEnable);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::SetKeepScreenOn(Z_Param_bEnable);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SetKeepScreenOn ******************************

// ********** Begin Class UBPFunctions_Android Function SetScreenCaptureDisabled *******************
struct Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics
{
	struct BPFunctions_Android_eventSetScreenCaptureDisabled_Parms
	{
		bool bDisable;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Screen" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xaeScreen Capture\xe5\xb7\xb2\xe7\xa6\x81\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xaeScreen Capture\xe5\xb7\xb2\xe7\xa6\x81\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetScreenCaptureDisabled constinit property declarations **************
	static void NewProp_bDisable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisable;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetScreenCaptureDisabled constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetScreenCaptureDisabled Property Definitions *************************
void Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::NewProp_bDisable_SetBit(void* Obj)
{
	((BPFunctions_Android_eventSetScreenCaptureDisabled_Parms*)Obj)->bDisable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::NewProp_bDisable = { "bDisable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventSetScreenCaptureDisabled_Parms), &Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::NewProp_bDisable_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::NewProp_bDisable,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::PropPointers) < 2048);
// ********** End Function SetScreenCaptureDisabled Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SetScreenCaptureDisabled", 	Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::BPFunctions_Android_eventSetScreenCaptureDisabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::BPFunctions_Android_eventSetScreenCaptureDisabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSetScreenCaptureDisabled)
{
	P_GET_UBOOL(Z_Param_bDisable);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::SetScreenCaptureDisabled(Z_Param_bDisable);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SetScreenCaptureDisabled *********************

// ********** Begin Class UBPFunctions_Android Function SetSharedPreferenceBool ********************
struct Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics
{
	struct BPFunctions_Android_eventSetSharedPreferenceBool_Parms
	{
		FString InGroup;
		FString InKey;
		bool bValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|SharedPreferences" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xae\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe5\xb8\x83\xe5\xb0\x94\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xae\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe5\xb8\x83\xe5\xb0\x94\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSharedPreferenceBool constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InGroup;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static void NewProp_bValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSharedPreferenceBool constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSharedPreferenceBool Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::NewProp_InGroup = { "InGroup", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetSharedPreferenceBool_Parms, InGroup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGroup_MetaData), NewProp_InGroup_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetSharedPreferenceBool_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::NewProp_bValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventSetSharedPreferenceBool_Parms*)Obj)->bValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::NewProp_bValue = { "bValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventSetSharedPreferenceBool_Parms), &Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::NewProp_bValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::NewProp_InGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::NewProp_bValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::PropPointers) < 2048);
// ********** End Function SetSharedPreferenceBool Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SetSharedPreferenceBool", 	Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::BPFunctions_Android_eventSetSharedPreferenceBool_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::BPFunctions_Android_eventSetSharedPreferenceBool_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSetSharedPreferenceBool)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InGroup);
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_GET_UBOOL(Z_Param_bValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::SetSharedPreferenceBool(Z_Param_InGroup,Z_Param_InKey,Z_Param_bValue);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SetSharedPreferenceBool **********************

// ********** Begin Class UBPFunctions_Android Function SetSharedPreferenceInt *********************
struct Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics
{
	struct BPFunctions_Android_eventSetSharedPreferenceInt_Parms
	{
		FString InGroup;
		FString InKey;
		int32 InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|SharedPreferences" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xae\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe6\x95\xb4\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xae\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe6\x95\xb4\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSharedPreferenceInt constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InGroup;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSharedPreferenceInt constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSharedPreferenceInt Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::NewProp_InGroup = { "InGroup", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetSharedPreferenceInt_Parms, InGroup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGroup_MetaData), NewProp_InGroup_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetSharedPreferenceInt_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetSharedPreferenceInt_Parms, InValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::NewProp_InGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::PropPointers) < 2048);
// ********** End Function SetSharedPreferenceInt Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SetSharedPreferenceInt", 	Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::BPFunctions_Android_eventSetSharedPreferenceInt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::BPFunctions_Android_eventSetSharedPreferenceInt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSetSharedPreferenceInt)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InGroup);
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_GET_PROPERTY(FIntProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::SetSharedPreferenceInt(Z_Param_InGroup,Z_Param_InKey,Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SetSharedPreferenceInt ***********************

// ********** Begin Class UBPFunctions_Android Function SetSharedPreferenceString ******************
struct Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics
{
	struct BPFunctions_Android_eventSetSharedPreferenceString_Parms
	{
		FString InGroup;
		FString InKey;
		FString InValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|SharedPreferences" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xae\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xae\xe5\x85\xb1\xe4\xba\xab\xe5\x81\x8f\xe5\xa5\xbd\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InGroup_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InKey_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetSharedPreferenceString constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InGroup;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InKey;
	static const UECodeGen_Private::FStrPropertyParams NewProp_InValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSharedPreferenceString constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSharedPreferenceString Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::NewProp_InGroup = { "InGroup", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetSharedPreferenceString_Parms, InGroup), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InGroup_MetaData), NewProp_InGroup_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::NewProp_InKey = { "InKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetSharedPreferenceString_Parms, InKey), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InKey_MetaData), NewProp_InKey_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventSetSharedPreferenceString_Parms, InValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InValue_MetaData), NewProp_InValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::NewProp_InGroup,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::NewProp_InKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::NewProp_InValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::PropPointers) < 2048);
// ********** End Function SetSharedPreferenceString Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SetSharedPreferenceString", 	Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::BPFunctions_Android_eventSetSharedPreferenceString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::BPFunctions_Android_eventSetSharedPreferenceString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSetSharedPreferenceString)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InGroup);
	P_GET_PROPERTY(FStrProperty,Z_Param_InKey);
	P_GET_PROPERTY(FStrProperty,Z_Param_InValue);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::SetSharedPreferenceString(Z_Param_InGroup,Z_Param_InKey,Z_Param_InValue);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SetSharedPreferenceString ********************

// ********** Begin Class UBPFunctions_Android Function SetVolumeButtonsHandledBySystem ************
struct Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics
{
	struct BPFunctions_Android_eventSetVolumeButtonsHandledBySystem_Parms
	{
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Audio|Volume" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xaeVolume Buttons Handled\xe6\x8c\x89\xe7\xb3\xbb\xe7\xbb\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xaeVolume Buttons Handled\xe6\x8c\x89\xe7\xb3\xbb\xe7\xbb\x9f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetVolumeButtonsHandledBySystem constinit property declarations *******
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVolumeButtonsHandledBySystem constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVolumeButtonsHandledBySystem Property Definitions ******************
void Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((BPFunctions_Android_eventSetVolumeButtonsHandledBySystem_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventSetVolumeButtonsHandledBySystem_Parms), &Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::PropPointers) < 2048);
// ********** End Function SetVolumeButtonsHandledBySystem Property Definitions ********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SetVolumeButtonsHandledBySystem", 	Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::BPFunctions_Android_eventSetVolumeButtonsHandledBySystem_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::BPFunctions_Android_eventSetVolumeButtonsHandledBySystem_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSetVolumeButtonsHandledBySystem)
{
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::SetVolumeButtonsHandledBySystem(Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SetVolumeButtonsHandledBySystem **************

// ********** Begin Class UBPFunctions_Android Function ShouldUseVulkan ****************************
struct Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics
{
	struct BPFunctions_Android_eventShouldUseVulkan_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Capabilities|Query" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe9\x9c\x80\xe8\xa6\x81Use Vulkan\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe9\x9c\x80\xe8\xa6\x81Use Vulkan\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ShouldUseVulkan constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ShouldUseVulkan constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ShouldUseVulkan Property Definitions **********************************
void Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventShouldUseVulkan_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventShouldUseVulkan_Parms), &Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::PropPointers) < 2048);
// ********** End Function ShouldUseVulkan Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "ShouldUseVulkan", 	Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::BPFunctions_Android_eventShouldUseVulkan_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::BPFunctions_Android_eventShouldUseVulkan_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execShouldUseVulkan)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::ShouldUseVulkan();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function ShouldUseVulkan ******************************

// ********** Begin Class UBPFunctions_Android Function SupportsFloatingPointRenderTargets *********
struct Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics
{
	struct BPFunctions_Android_eventSupportsFloatingPointRenderTargets_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Capabilities|Graphics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Supports Floating Point\xe6\xb8\xb2\xe6\x9f\x93Targets\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Supports Floating Point\xe6\xb8\xb2\xe6\x9f\x93Targets\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SupportsFloatingPointRenderTargets constinit property declarations ****
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SupportsFloatingPointRenderTargets constinit property declarations ******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SupportsFloatingPointRenderTargets Property Definitions ***************
void Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventSupportsFloatingPointRenderTargets_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventSupportsFloatingPointRenderTargets_Parms), &Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::PropPointers) < 2048);
// ********** End Function SupportsFloatingPointRenderTargets Property Definitions *****************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SupportsFloatingPointRenderTargets", 	Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::BPFunctions_Android_eventSupportsFloatingPointRenderTargets_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::BPFunctions_Android_eventSupportsFloatingPointRenderTargets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSupportsFloatingPointRenderTargets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::SupportsFloatingPointRenderTargets();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SupportsFloatingPointRenderTargets ***********

// ********** Begin Class UBPFunctions_Android Function SupportsShaderFramebufferFetch *************
struct Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics
{
	struct BPFunctions_Android_eventSupportsShaderFramebufferFetch_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Capabilities|Graphics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Supports Shader Framebuffer Fetch\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Supports Shader Framebuffer Fetch\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SupportsShaderFramebufferFetch constinit property declarations ********
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SupportsShaderFramebufferFetch constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SupportsShaderFramebufferFetch Property Definitions *******************
void Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventSupportsShaderFramebufferFetch_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventSupportsShaderFramebufferFetch_Parms), &Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::PropPointers) < 2048);
// ********** End Function SupportsShaderFramebufferFetch Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SupportsShaderFramebufferFetch", 	Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::BPFunctions_Android_eventSupportsShaderFramebufferFetch_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::BPFunctions_Android_eventSupportsShaderFramebufferFetch_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSupportsShaderFramebufferFetch)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::SupportsShaderFramebufferFetch();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SupportsShaderFramebufferFetch ***************

// ********** Begin Class UBPFunctions_Android Function SupportsShaderIOBlocks *********************
struct Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics
{
	struct BPFunctions_Android_eventSupportsShaderIOBlocks_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Capabilities|Graphics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Supports Shader IO\xe5\x8c\xba\xe5\x9d\x97\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Supports Shader IO\xe5\x8c\xba\xe5\x9d\x97\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SupportsShaderIOBlocks constinit property declarations ****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SupportsShaderIOBlocks constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SupportsShaderIOBlocks Property Definitions ***************************
void Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Android_eventSupportsShaderIOBlocks_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Android_eventSupportsShaderIOBlocks_Parms), &Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::PropPointers) < 2048);
// ********** End Function SupportsShaderIOBlocks Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "SupportsShaderIOBlocks", 	Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::BPFunctions_Android_eventSupportsShaderIOBlocks_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::BPFunctions_Android_eventSupportsShaderIOBlocks_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execSupportsShaderIOBlocks)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Android::SupportsShaderIOBlocks();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function SupportsShaderIOBlocks ***********************

// ********** Begin Class UBPFunctions_Android Function TriggerHaptic ******************************
struct Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics
{
	struct BPFunctions_Android_eventTriggerHaptic_Parms
	{
		EAndroidHapticType InHapticType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Input|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Trigger Haptic\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Trigger Haptic\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function TriggerHaptic constinit property declarations *************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InHapticType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InHapticType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TriggerHaptic constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TriggerHaptic Property Definitions ************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::NewProp_InHapticType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::NewProp_InHapticType = { "InHapticType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventTriggerHaptic_Parms, InHapticType), Z_Construct_UEnum_GenericAndroidFramework_EAndroidHapticType, METADATA_PARAMS(0, nullptr) }; // 3080846989
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::NewProp_InHapticType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::NewProp_InHapticType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::PropPointers) < 2048);
// ********** End Function TriggerHaptic Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "TriggerHaptic", 	Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::BPFunctions_Android_eventTriggerHaptic_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::BPFunctions_Android_eventTriggerHaptic_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execTriggerHaptic)
{
	P_GET_ENUM(EAndroidHapticType,Z_Param_InHapticType);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::TriggerHaptic(EAndroidHapticType(Z_Param_InHapticType));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function TriggerHaptic ********************************

// ********** Begin Class UBPFunctions_Android Function TriggerSimpleVibration *********************
struct Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics
{
	struct BPFunctions_Android_eventTriggerSimpleVibration_Parms
	{
		int32 Intensity;
		int32 DurationMs;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|Input|Haptics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Trigger Simple Vibration\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Trigger Simple Vibration\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function TriggerSimpleVibration constinit property declarations ****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Intensity;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DurationMs;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function TriggerSimpleVibration constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function TriggerSimpleVibration Property Definitions ***************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::NewProp_Intensity = { "Intensity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventTriggerSimpleVibration_Parms, Intensity), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::NewProp_DurationMs = { "DurationMs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Android_eventTriggerSimpleVibration_Parms, DurationMs), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::NewProp_Intensity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::NewProp_DurationMs,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::PropPointers) < 2048);
// ********** End Function TriggerSimpleVibration Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "TriggerSimpleVibration", 	Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::BPFunctions_Android_eventTriggerSimpleVibration_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::BPFunctions_Android_eventTriggerSimpleVibration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execTriggerSimpleVibration)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Intensity);
	P_GET_PROPERTY(FIntProperty,Z_Param_DurationMs);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::TriggerSimpleVibration(Z_Param_Intensity,Z_Param_DurationMs);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function TriggerSimpleVibration ***********************

// ********** Begin Class UBPFunctions_Android Function UnregisterForRemoteNotifications ***********
struct Z_Construct_UFunction_UBPFunctions_Android_UnregisterForRemoteNotifications_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Android|System|Notifications" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x8f\x96\xe6\xb6\x88\xe6\xb3\xa8\xe5\x86\x8c\xe7\x94\xa8\xe4\xba\x8eRemote Notifications\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x8f\x96\xe6\xb6\x88\xe6\xb3\xa8\xe5\x86\x8c\xe7\x94\xa8\xe4\xba\x8eRemote Notifications\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function UnregisterForRemoteNotifications constinit property declarations ******
// ********** End Function UnregisterForRemoteNotifications constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Android_UnregisterForRemoteNotifications_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Android, nullptr, "UnregisterForRemoteNotifications", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Android_UnregisterForRemoteNotifications_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Android_UnregisterForRemoteNotifications_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UBPFunctions_Android_UnregisterForRemoteNotifications()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Android_UnregisterForRemoteNotifications_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Android::execUnregisterForRemoteNotifications)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Android::UnregisterForRemoteNotifications();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Android Function UnregisterForRemoteNotifications *************

// ********** Begin Class UBPFunctions_Android *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBPFunctions_Android;
UClass* UBPFunctions_Android::GetPrivateStaticClass()
{
	using TClass = UBPFunctions_Android;
	if (!Z_Registration_Info_UClass_UBPFunctions_Android.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BPFunctions_Android"),
			Z_Registration_Info_UClass_UBPFunctions_Android.InnerSingleton,
			StaticRegisterNativesUBPFunctions_Android,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UBPFunctions_Android.InnerSingleton;
}
UClass* Z_Construct_UClass_UBPFunctions_Android_NoRegister()
{
	return UBPFunctions_Android::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBPFunctions_Android_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x90\xe4\xbe\x9b""Android\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "BPFunctions/BPFunctions_Android.h" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Android.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x90\xe4\xbe\x9b""Android\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBPFunctions_Android constinit property declarations *********************
// ********** End Class UBPFunctions_Android constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AndroidPermissionStateToString"), .Pointer = &UBPFunctions_Android::execAndroidPermissionStateToString },
		{ .NameUTF8 = UTF8TEXT("AreHeadphonesConnected"), .Pointer = &UBPFunctions_Android::execAreHeadphonesConnected },
		{ .NameUTF8 = UTF8TEXT("CancelLocalNotification"), .Pointer = &UBPFunctions_Android::execCancelLocalNotification },
		{ .NameUTF8 = UTF8TEXT("CancelLocalNotificationById"), .Pointer = &UBPFunctions_Android::execCancelLocalNotificationById },
		{ .NameUTF8 = UTF8TEXT("CanLaunchUrl"), .Pointer = &UBPFunctions_Android::execCanLaunchUrl },
		{ .NameUTF8 = UTF8TEXT("CheckAndroidCommonPermission"), .Pointer = &UBPFunctions_Android::execCheckAndroidCommonPermission },
		{ .NameUTF8 = UTF8TEXT("CheckAndroidPermission"), .Pointer = &UBPFunctions_Android::execCheckAndroidPermission },
		{ .NameUTF8 = UTF8TEXT("CheckAndroidPermissions"), .Pointer = &UBPFunctions_Android::execCheckAndroidPermissions },
		{ .NameUTF8 = UTF8TEXT("ClearAllLocalNotifications"), .Pointer = &UBPFunctions_Android::execClearAllLocalNotifications },
		{ .NameUTF8 = UTF8TEXT("DeleteSharedPreference"), .Pointer = &UBPFunctions_Android::execDeleteSharedPreference },
		{ .NameUTF8 = UTF8TEXT("DeleteSharedPreferenceGroup"), .Pointer = &UBPFunctions_Android::execDeleteSharedPreferenceGroup },
		{ .NameUTF8 = UTF8TEXT("GetAdvertisingId"), .Pointer = &UBPFunctions_Android::execGetAdvertisingId },
		{ .NameUTF8 = UTF8TEXT("GetAllAndroidCommonPermissionStrings"), .Pointer = &UBPFunctions_Android::execGetAllAndroidCommonPermissionStrings },
		{ .NameUTF8 = UTF8TEXT("GetAllKnownStorageInfos"), .Pointer = &UBPFunctions_Android::execGetAllKnownStorageInfos },
		{ .NameUTF8 = UTF8TEXT("GetAndroidAppInfo"), .Pointer = &UBPFunctions_Android::execGetAndroidAppInfo },
		{ .NameUTF8 = UTF8TEXT("GetAndroidBuildVersion"), .Pointer = &UBPFunctions_Android::execGetAndroidBuildVersion },
		{ .NameUTF8 = UTF8TEXT("GetAndroidCommonPermissionString"), .Pointer = &UBPFunctions_Android::execGetAndroidCommonPermissionString },
		{ .NameUTF8 = UTF8TEXT("GetAndroidDebugReport"), .Pointer = &UBPFunctions_Android::execGetAndroidDebugReport },
		{ .NameUTF8 = UTF8TEXT("GetAndroidDeviceInfo"), .Pointer = &UBPFunctions_Android::execGetAndroidDeviceInfo },
		{ .NameUTF8 = UTF8TEXT("GetAndroidExternalAppDir"), .Pointer = &UBPFunctions_Android::execGetAndroidExternalAppDir },
		{ .NameUTF8 = UTF8TEXT("GetAndroidExternalConfigDir"), .Pointer = &UBPFunctions_Android::execGetAndroidExternalConfigDir },
		{ .NameUTF8 = UTF8TEXT("GetAndroidExternalExtrasDir"), .Pointer = &UBPFunctions_Android::execGetAndroidExternalExtrasDir },
		{ .NameUTF8 = UTF8TEXT("GetAndroidExternalProjectDir"), .Pointer = &UBPFunctions_Android::execGetAndroidExternalProjectDir },
		{ .NameUTF8 = UTF8TEXT("GetAndroidExternalRootDir"), .Pointer = &UBPFunctions_Android::execGetAndroidExternalRootDir },
		{ .NameUTF8 = UTF8TEXT("GetAndroidExternalSaveDir"), .Pointer = &UBPFunctions_Android::execGetAndroidExternalSaveDir },
		{ .NameUTF8 = UTF8TEXT("GetAndroidFilePathBase"), .Pointer = &UBPFunctions_Android::execGetAndroidFilePathBase },
		{ .NameUTF8 = UTF8TEXT("GetAndroidId"), .Pointer = &UBPFunctions_Android::execGetAndroidId },
		{ .NameUTF8 = UTF8TEXT("GetAndroidIdInfo"), .Pointer = &UBPFunctions_Android::execGetAndroidIdInfo },
		{ .NameUTF8 = UTF8TEXT("GetAndroidInternalAppDir"), .Pointer = &UBPFunctions_Android::execGetAndroidInternalAppDir },
		{ .NameUTF8 = UTF8TEXT("GetAndroidMajorVersion"), .Pointer = &UBPFunctions_Android::execGetAndroidMajorVersion },
		{ .NameUTF8 = UTF8TEXT("GetAndroidPermissionState"), .Pointer = &UBPFunctions_Android::execGetAndroidPermissionState },
		{ .NameUTF8 = UTF8TEXT("GetAndroidPersistentDownloadDir"), .Pointer = &UBPFunctions_Android::execGetAndroidPersistentDownloadDir },
		{ .NameUTF8 = UTF8TEXT("GetAndroidVersion"), .Pointer = &UBPFunctions_Android::execGetAndroidVersion },
		{ .NameUTF8 = UTF8TEXT("GetBatteryInfo"), .Pointer = &UBPFunctions_Android::execGetBatteryInfo },
		{ .NameUTF8 = UTF8TEXT("GetBatteryStateString"), .Pointer = &UBPFunctions_Android::execGetBatteryStateString },
		{ .NameUTF8 = UTF8TEXT("GetCapabilityInfo"), .Pointer = &UBPFunctions_Android::execGetCapabilityInfo },
		{ .NameUTF8 = UTF8TEXT("GetClipboardText"), .Pointer = &UBPFunctions_Android::execGetClipboardText },
		{ .NameUTF8 = UTF8TEXT("GetCPUAverageUsage"), .Pointer = &UBPFunctions_Android::execGetCPUAverageUsage },
		{ .NameUTF8 = UTF8TEXT("GetCPUCoreUsages"), .Pointer = &UBPFunctions_Android::execGetCPUCoreUsages },
		{ .NameUTF8 = UTF8TEXT("GetCPUCurrentFrequenciesMHz"), .Pointer = &UBPFunctions_Android::execGetCPUCurrentFrequenciesMHz },
		{ .NameUTF8 = UTF8TEXT("GetCPUHardwareInfo"), .Pointer = &UBPFunctions_Android::execGetCPUHardwareInfo },
		{ .NameUTF8 = UTF8TEXT("GetCPUMaxFrequenciesMHz"), .Pointer = &UBPFunctions_Android::execGetCPUMaxFrequenciesMHz },
		{ .NameUTF8 = UTF8TEXT("GetCPUMinFrequenciesMHz"), .Pointer = &UBPFunctions_Android::execGetCPUMinFrequenciesMHz },
		{ .NameUTF8 = UTF8TEXT("GetCPUTemperatureCelsius"), .Pointer = &UBPFunctions_Android::execGetCPUTemperatureCelsius },
		{ .NameUTF8 = UTF8TEXT("GetCurrentVolumePercent"), .Pointer = &UBPFunctions_Android::execGetCurrentVolumePercent },
		{ .NameUTF8 = UTF8TEXT("GetCurrentVolumeStep"), .Pointer = &UBPFunctions_Android::execGetCurrentVolumeStep },
		{ .NameUTF8 = UTF8TEXT("GetDefaultLocale"), .Pointer = &UBPFunctions_Android::execGetDefaultLocale },
		{ .NameUTF8 = UTF8TEXT("GetDeviceBrand"), .Pointer = &UBPFunctions_Android::execGetDeviceBrand },
		{ .NameUTF8 = UTF8TEXT("GetDeviceBuildNumber"), .Pointer = &UBPFunctions_Android::execGetDeviceBuildNumber },
		{ .NameUTF8 = UTF8TEXT("GetDeviceId"), .Pointer = &UBPFunctions_Android::execGetDeviceId },
		{ .NameUTF8 = UTF8TEXT("GetDeviceModel"), .Pointer = &UBPFunctions_Android::execGetDeviceModel },
		{ .NameUTF8 = UTF8TEXT("GetDisplayInfo"), .Pointer = &UBPFunctions_Android::execGetDisplayInfo },
		{ .NameUTF8 = UTF8TEXT("GetExternalStorageInfo"), .Pointer = &UBPFunctions_Android::execGetExternalStorageInfo },
		{ .NameUTF8 = UTF8TEXT("GetGPUHardwareInfo"), .Pointer = &UBPFunctions_Android::execGetGPUHardwareInfo },
		{ .NameUTF8 = UTF8TEXT("GetGPUMemoryInfo"), .Pointer = &UBPFunctions_Android::execGetGPUMemoryInfo },
		{ .NameUTF8 = UTF8TEXT("GetGPURHIName"), .Pointer = &UBPFunctions_Android::execGetGPURHIName },
		{ .NameUTF8 = UTF8TEXT("GetGPUUsage"), .Pointer = &UBPFunctions_Android::execGetGPUUsage },
		{ .NameUTF8 = UTF8TEXT("GetHardwareSnapshot"), .Pointer = &UBPFunctions_Android::execGetHardwareSnapshot },
		{ .NameUTF8 = UTF8TEXT("GetInputDeviceInfo"), .Pointer = &UBPFunctions_Android::execGetInputDeviceInfo },
		{ .NameUTF8 = UTF8TEXT("GetInputMotionState"), .Pointer = &UBPFunctions_Android::execGetInputMotionState },
		{ .NameUTF8 = UTF8TEXT("GetInternalStorageInfo"), .Pointer = &UBPFunctions_Android::execGetInternalStorageInfo },
		{ .NameUTF8 = UTF8TEXT("GetLaunchNotification"), .Pointer = &UBPFunctions_Android::execGetLaunchNotification },
		{ .NameUTF8 = UTF8TEXT("GetLoginId"), .Pointer = &UBPFunctions_Android::execGetLoginId },
		{ .NameUTF8 = UTF8TEXT("GetManifestMetaDataBoolean"), .Pointer = &UBPFunctions_Android::execGetManifestMetaDataBoolean },
		{ .NameUTF8 = UTF8TEXT("GetManifestMetaDataFloat"), .Pointer = &UBPFunctions_Android::execGetManifestMetaDataFloat },
		{ .NameUTF8 = UTF8TEXT("GetManifestMetaDataInt"), .Pointer = &UBPFunctions_Android::execGetManifestMetaDataInt },
		{ .NameUTF8 = UTF8TEXT("GetManifestMetaDataLong"), .Pointer = &UBPFunctions_Android::execGetManifestMetaDataLong },
		{ .NameUTF8 = UTF8TEXT("GetManifestMetaDataString"), .Pointer = &UBPFunctions_Android::execGetManifestMetaDataString },
		{ .NameUTF8 = UTF8TEXT("GetMemoryHardwareInfo"), .Pointer = &UBPFunctions_Android::execGetMemoryHardwareInfo },
		{ .NameUTF8 = UTF8TEXT("GetMemoryPressureLevel"), .Pointer = &UBPFunctions_Android::execGetMemoryPressureLevel },
		{ .NameUTF8 = UTF8TEXT("GetNetworkInfo"), .Pointer = &UBPFunctions_Android::execGetNetworkInfo },
		{ .NameUTF8 = UTF8TEXT("GetNetworkTypeString"), .Pointer = &UBPFunctions_Android::execGetNetworkTypeString },
		{ .NameUTF8 = UTF8TEXT("GetOrientationString"), .Pointer = &UBPFunctions_Android::execGetOrientationString },
		{ .NameUTF8 = UTF8TEXT("GetOSLanguage"), .Pointer = &UBPFunctions_Android::execGetOSLanguage },
		{ .NameUTF8 = UTF8TEXT("GetProductName"), .Pointer = &UBPFunctions_Android::execGetProductName },
		{ .NameUTF8 = UTF8TEXT("GetProjectStorageInfo"), .Pointer = &UBPFunctions_Android::execGetProjectStorageInfo },
		{ .NameUTF8 = UTF8TEXT("GetSharedPreferenceBool"), .Pointer = &UBPFunctions_Android::execGetSharedPreferenceBool },
		{ .NameUTF8 = UTF8TEXT("GetSharedPreferenceInt"), .Pointer = &UBPFunctions_Android::execGetSharedPreferenceInt },
		{ .NameUTF8 = UTF8TEXT("GetSharedPreferenceString"), .Pointer = &UBPFunctions_Android::execGetSharedPreferenceString },
		{ .NameUTF8 = UTF8TEXT("GetStorageInfo"), .Pointer = &UBPFunctions_Android::execGetStorageInfo },
		{ .NameUTF8 = UTF8TEXT("GetSystemFontBytes"), .Pointer = &UBPFunctions_Android::execGetSystemFontBytes },
		{ .NameUTF8 = UTF8TEXT("GetTimeZoneId"), .Pointer = &UBPFunctions_Android::execGetTimeZoneId },
		{ .NameUTF8 = UTF8TEXT("GetVolumeButtonsHandledBySystem"), .Pointer = &UBPFunctions_Android::execGetVolumeButtonsHandledBySystem },
		{ .NameUTF8 = UTF8TEXT("HasAdvertisingId"), .Pointer = &UBPFunctions_Android::execHasAdvertisingId },
		{ .NameUTF8 = UTF8TEXT("HasAndroidPersistentDownloadDir"), .Pointer = &UBPFunctions_Android::execHasAndroidPersistentDownloadDir },
		{ .NameUTF8 = UTF8TEXT("HasManifestMetaDataKey"), .Pointer = &UBPFunctions_Android::execHasManifestMetaDataKey },
		{ .NameUTF8 = UTF8TEXT("HasSharedPreference"), .Pointer = &UBPFunctions_Android::execHasSharedPreference },
		{ .NameUTF8 = UTF8TEXT("HasVulkanDriverSupport"), .Pointer = &UBPFunctions_Android::execHasVulkanDriverSupport },
		{ .NameUTF8 = UTF8TEXT("IsAllowedRemoteNotifications"), .Pointer = &UBPFunctions_Android::execIsAllowedRemoteNotifications },
		{ .NameUTF8 = UTF8TEXT("IsGamepadAttached"), .Pointer = &UBPFunctions_Android::execIsGamepadAttached },
		{ .NameUTF8 = UTF8TEXT("IsIMUSamplingEnabled"), .Pointer = &UBPFunctions_Android::execIsIMUSamplingEnabled },
		{ .NameUTF8 = UTF8TEXT("IsLowMemoryDevice"), .Pointer = &UBPFunctions_Android::execIsLowMemoryDevice },
		{ .NameUTF8 = UTF8TEXT("IsMusicActive"), .Pointer = &UBPFunctions_Android::execIsMusicActive },
		{ .NameUTF8 = UTF8TEXT("IsPackageInstalled"), .Pointer = &UBPFunctions_Android::execIsPackageInstalled },
		{ .NameUTF8 = UTF8TEXT("IsScreenCaptureDisabled"), .Pointer = &UBPFunctions_Android::execIsScreenCaptureDisabled },
		{ .NameUTF8 = UTF8TEXT("IsScreensaverEnabled"), .Pointer = &UBPFunctions_Android::execIsScreensaverEnabled },
		{ .NameUTF8 = UTF8TEXT("IsSupportedAndroidDevice"), .Pointer = &UBPFunctions_Android::execIsSupportedAndroidDevice },
		{ .NameUTF8 = UTF8TEXT("IsUsingVulkan"), .Pointer = &UBPFunctions_Android::execIsUsingVulkan },
		{ .NameUTF8 = UTF8TEXT("IsVulkanAvailable"), .Pointer = &UBPFunctions_Android::execIsVulkanAvailable },
		{ .NameUTF8 = UTF8TEXT("LaunchPackage"), .Pointer = &UBPFunctions_Android::execLaunchPackage },
		{ .NameUTF8 = UTF8TEXT("LaunchUrl"), .Pointer = &UBPFunctions_Android::execLaunchUrl },
		{ .NameUTF8 = UTF8TEXT("RegisterForRemoteNotifications"), .Pointer = &UBPFunctions_Android::execRegisterForRemoteNotifications },
		{ .NameUTF8 = UTF8TEXT("RequestMinimizeApplication"), .Pointer = &UBPFunctions_Android::execRequestMinimizeApplication },
		{ .NameUTF8 = UTF8TEXT("RestartApplication"), .Pointer = &UBPFunctions_Android::execRestartApplication },
		{ .NameUTF8 = UTF8TEXT("RestartApplicationWithIntent"), .Pointer = &UBPFunctions_Android::execRestartApplicationWithIntent },
		{ .NameUTF8 = UTF8TEXT("ScheduleLocalNotificationAtTime"), .Pointer = &UBPFunctions_Android::execScheduleLocalNotificationAtTime },
		{ .NameUTF8 = UTF8TEXT("ScheduleLocalNotificationBadgeAtTime"), .Pointer = &UBPFunctions_Android::execScheduleLocalNotificationBadgeAtTime },
		{ .NameUTF8 = UTF8TEXT("ScheduleLocalNotificationBadgeFromNow"), .Pointer = &UBPFunctions_Android::execScheduleLocalNotificationBadgeFromNow },
		{ .NameUTF8 = UTF8TEXT("ScheduleLocalNotificationFromNow"), .Pointer = &UBPFunctions_Android::execScheduleLocalNotificationFromNow },
		{ .NameUTF8 = UTF8TEXT("SendBroadcast"), .Pointer = &UBPFunctions_Android::execSendBroadcast },
		{ .NameUTF8 = UTF8TEXT("SetClipboardText"), .Pointer = &UBPFunctions_Android::execSetClipboardText },
		{ .NameUTF8 = UTF8TEXT("SetInputDeviceVibration"), .Pointer = &UBPFunctions_Android::execSetInputDeviceVibration },
		{ .NameUTF8 = UTF8TEXT("SetKeepScreenOn"), .Pointer = &UBPFunctions_Android::execSetKeepScreenOn },
		{ .NameUTF8 = UTF8TEXT("SetScreenCaptureDisabled"), .Pointer = &UBPFunctions_Android::execSetScreenCaptureDisabled },
		{ .NameUTF8 = UTF8TEXT("SetSharedPreferenceBool"), .Pointer = &UBPFunctions_Android::execSetSharedPreferenceBool },
		{ .NameUTF8 = UTF8TEXT("SetSharedPreferenceInt"), .Pointer = &UBPFunctions_Android::execSetSharedPreferenceInt },
		{ .NameUTF8 = UTF8TEXT("SetSharedPreferenceString"), .Pointer = &UBPFunctions_Android::execSetSharedPreferenceString },
		{ .NameUTF8 = UTF8TEXT("SetVolumeButtonsHandledBySystem"), .Pointer = &UBPFunctions_Android::execSetVolumeButtonsHandledBySystem },
		{ .NameUTF8 = UTF8TEXT("ShouldUseVulkan"), .Pointer = &UBPFunctions_Android::execShouldUseVulkan },
		{ .NameUTF8 = UTF8TEXT("SupportsFloatingPointRenderTargets"), .Pointer = &UBPFunctions_Android::execSupportsFloatingPointRenderTargets },
		{ .NameUTF8 = UTF8TEXT("SupportsShaderFramebufferFetch"), .Pointer = &UBPFunctions_Android::execSupportsShaderFramebufferFetch },
		{ .NameUTF8 = UTF8TEXT("SupportsShaderIOBlocks"), .Pointer = &UBPFunctions_Android::execSupportsShaderIOBlocks },
		{ .NameUTF8 = UTF8TEXT("TriggerHaptic"), .Pointer = &UBPFunctions_Android::execTriggerHaptic },
		{ .NameUTF8 = UTF8TEXT("TriggerSimpleVibration"), .Pointer = &UBPFunctions_Android::execTriggerSimpleVibration },
		{ .NameUTF8 = UTF8TEXT("UnregisterForRemoteNotifications"), .Pointer = &UBPFunctions_Android::execUnregisterForRemoteNotifications },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBPFunctions_Android_AndroidPermissionStateToString, "AndroidPermissionStateToString" }, // 3339587749
		{ &Z_Construct_UFunction_UBPFunctions_Android_AreHeadphonesConnected, "AreHeadphonesConnected" }, // 3952101348
		{ &Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotification, "CancelLocalNotification" }, // 3877262213
		{ &Z_Construct_UFunction_UBPFunctions_Android_CancelLocalNotificationById, "CancelLocalNotificationById" }, // 1328507400
		{ &Z_Construct_UFunction_UBPFunctions_Android_CanLaunchUrl, "CanLaunchUrl" }, // 1781338437
		{ &Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidCommonPermission, "CheckAndroidCommonPermission" }, // 2550772212
		{ &Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermission, "CheckAndroidPermission" }, // 2306593240
		{ &Z_Construct_UFunction_UBPFunctions_Android_CheckAndroidPermissions, "CheckAndroidPermissions" }, // 2233000346
		{ &Z_Construct_UFunction_UBPFunctions_Android_ClearAllLocalNotifications, "ClearAllLocalNotifications" }, // 3137514283
		{ &Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreference, "DeleteSharedPreference" }, // 809055602
		{ &Z_Construct_UFunction_UBPFunctions_Android_DeleteSharedPreferenceGroup, "DeleteSharedPreferenceGroup" }, // 3093915271
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAdvertisingId, "GetAdvertisingId" }, // 2589588488
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAllAndroidCommonPermissionStrings, "GetAllAndroidCommonPermissionStrings" }, // 2381162865
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAllKnownStorageInfos, "GetAllKnownStorageInfos" }, // 2981087503
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidAppInfo, "GetAndroidAppInfo" }, // 374782318
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidBuildVersion, "GetAndroidBuildVersion" }, // 3238660775
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidCommonPermissionString, "GetAndroidCommonPermissionString" }, // 1628613028
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDebugReport, "GetAndroidDebugReport" }, // 3849671745
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidDeviceInfo, "GetAndroidDeviceInfo" }, // 4189655014
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalAppDir, "GetAndroidExternalAppDir" }, // 191771209
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalConfigDir, "GetAndroidExternalConfigDir" }, // 3305958048
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalExtrasDir, "GetAndroidExternalExtrasDir" }, // 17849875
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalProjectDir, "GetAndroidExternalProjectDir" }, // 2767706024
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalRootDir, "GetAndroidExternalRootDir" }, // 2253766235
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidExternalSaveDir, "GetAndroidExternalSaveDir" }, // 1364964337
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidFilePathBase, "GetAndroidFilePathBase" }, // 3826716133
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidId, "GetAndroidId" }, // 2677333662
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidIdInfo, "GetAndroidIdInfo" }, // 3891066783
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidInternalAppDir, "GetAndroidInternalAppDir" }, // 3096728340
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidMajorVersion, "GetAndroidMajorVersion" }, // 784829209
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPermissionState, "GetAndroidPermissionState" }, // 317004069
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidPersistentDownloadDir, "GetAndroidPersistentDownloadDir" }, // 1400743803
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetAndroidVersion, "GetAndroidVersion" }, // 2912840693
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetBatteryInfo, "GetBatteryInfo" }, // 2131960845
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetBatteryStateString, "GetBatteryStateString" }, // 2853333610
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetCapabilityInfo, "GetCapabilityInfo" }, // 1699752942
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetClipboardText, "GetClipboardText" }, // 2184312209
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetCPUAverageUsage, "GetCPUAverageUsage" }, // 3820500615
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetCPUCoreUsages, "GetCPUCoreUsages" }, // 326818836
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetCPUCurrentFrequenciesMHz, "GetCPUCurrentFrequenciesMHz" }, // 717073636
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetCPUHardwareInfo, "GetCPUHardwareInfo" }, // 125528138
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetCPUMaxFrequenciesMHz, "GetCPUMaxFrequenciesMHz" }, // 996374364
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetCPUMinFrequenciesMHz, "GetCPUMinFrequenciesMHz" }, // 322660158
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetCPUTemperatureCelsius, "GetCPUTemperatureCelsius" }, // 3696599706
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumePercent, "GetCurrentVolumePercent" }, // 1877514851
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetCurrentVolumeStep, "GetCurrentVolumeStep" }, // 555866421
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetDefaultLocale, "GetDefaultLocale" }, // 3070587294
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBrand, "GetDeviceBrand" }, // 3817354510
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetDeviceBuildNumber, "GetDeviceBuildNumber" }, // 1353792149
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetDeviceId, "GetDeviceId" }, // 524609797
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetDeviceModel, "GetDeviceModel" }, // 1669243101
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetDisplayInfo, "GetDisplayInfo" }, // 758963145
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetExternalStorageInfo, "GetExternalStorageInfo" }, // 3297422786
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetGPUHardwareInfo, "GetGPUHardwareInfo" }, // 4137383891
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetGPUMemoryInfo, "GetGPUMemoryInfo" }, // 2586259234
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetGPURHIName, "GetGPURHIName" }, // 631034017
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetGPUUsage, "GetGPUUsage" }, // 1383442410
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetHardwareSnapshot, "GetHardwareSnapshot" }, // 1920207175
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetInputDeviceInfo, "GetInputDeviceInfo" }, // 3586281588
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetInputMotionState, "GetInputMotionState" }, // 1203644358
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetInternalStorageInfo, "GetInternalStorageInfo" }, // 65853431
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetLaunchNotification, "GetLaunchNotification" }, // 2609443452
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetLoginId, "GetLoginId" }, // 1894102059
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataBoolean, "GetManifestMetaDataBoolean" }, // 269135916
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataFloat, "GetManifestMetaDataFloat" }, // 1737906617
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataInt, "GetManifestMetaDataInt" }, // 3590717228
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataLong, "GetManifestMetaDataLong" }, // 431111072
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetManifestMetaDataString, "GetManifestMetaDataString" }, // 1289014538
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetMemoryHardwareInfo, "GetMemoryHardwareInfo" }, // 2401576814
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetMemoryPressureLevel, "GetMemoryPressureLevel" }, // 3137446531
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetNetworkInfo, "GetNetworkInfo" }, // 3238585207
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetNetworkTypeString, "GetNetworkTypeString" }, // 1973508349
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetOrientationString, "GetOrientationString" }, // 1446545264
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetOSLanguage, "GetOSLanguage" }, // 583831903
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetProductName, "GetProductName" }, // 4036835139
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetProjectStorageInfo, "GetProjectStorageInfo" }, // 3716153229
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceBool, "GetSharedPreferenceBool" }, // 813923761
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceInt, "GetSharedPreferenceInt" }, // 3673451184
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetSharedPreferenceString, "GetSharedPreferenceString" }, // 747155069
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetStorageInfo, "GetStorageInfo" }, // 1016422185
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetSystemFontBytes, "GetSystemFontBytes" }, // 1065133756
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetTimeZoneId, "GetTimeZoneId" }, // 2786292258
		{ &Z_Construct_UFunction_UBPFunctions_Android_GetVolumeButtonsHandledBySystem, "GetVolumeButtonsHandledBySystem" }, // 3410836757
		{ &Z_Construct_UFunction_UBPFunctions_Android_HasAdvertisingId, "HasAdvertisingId" }, // 2412628783
		{ &Z_Construct_UFunction_UBPFunctions_Android_HasAndroidPersistentDownloadDir, "HasAndroidPersistentDownloadDir" }, // 841400722
		{ &Z_Construct_UFunction_UBPFunctions_Android_HasManifestMetaDataKey, "HasManifestMetaDataKey" }, // 2522370543
		{ &Z_Construct_UFunction_UBPFunctions_Android_HasSharedPreference, "HasSharedPreference" }, // 3822672743
		{ &Z_Construct_UFunction_UBPFunctions_Android_HasVulkanDriverSupport, "HasVulkanDriverSupport" }, // 2442890573
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsAllowedRemoteNotifications, "IsAllowedRemoteNotifications" }, // 1307799462
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsGamepadAttached, "IsGamepadAttached" }, // 1100375937
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsIMUSamplingEnabled, "IsIMUSamplingEnabled" }, // 604268325
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsLowMemoryDevice, "IsLowMemoryDevice" }, // 3105561699
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsMusicActive, "IsMusicActive" }, // 213681157
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsPackageInstalled, "IsPackageInstalled" }, // 4091469109
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsScreenCaptureDisabled, "IsScreenCaptureDisabled" }, // 4014907194
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsScreensaverEnabled, "IsScreensaverEnabled" }, // 4165716465
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsSupportedAndroidDevice, "IsSupportedAndroidDevice" }, // 1742189673
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsUsingVulkan, "IsUsingVulkan" }, // 4243665720
		{ &Z_Construct_UFunction_UBPFunctions_Android_IsVulkanAvailable, "IsVulkanAvailable" }, // 1592398460
		{ &Z_Construct_UFunction_UBPFunctions_Android_LaunchPackage, "LaunchPackage" }, // 2691070126
		{ &Z_Construct_UFunction_UBPFunctions_Android_LaunchUrl, "LaunchUrl" }, // 1892905531
		{ &Z_Construct_UFunction_UBPFunctions_Android_RegisterForRemoteNotifications, "RegisterForRemoteNotifications" }, // 589574112
		{ &Z_Construct_UFunction_UBPFunctions_Android_RequestMinimizeApplication, "RequestMinimizeApplication" }, // 3577333514
		{ &Z_Construct_UFunction_UBPFunctions_Android_RestartApplication, "RestartApplication" }, // 4191609148
		{ &Z_Construct_UFunction_UBPFunctions_Android_RestartApplicationWithIntent, "RestartApplicationWithIntent" }, // 503029387
		{ &Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationAtTime, "ScheduleLocalNotificationAtTime" }, // 4113449268
		{ &Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeAtTime, "ScheduleLocalNotificationBadgeAtTime" }, // 4270110325
		{ &Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationBadgeFromNow, "ScheduleLocalNotificationBadgeFromNow" }, // 2950495753
		{ &Z_Construct_UFunction_UBPFunctions_Android_ScheduleLocalNotificationFromNow, "ScheduleLocalNotificationFromNow" }, // 1037160003
		{ &Z_Construct_UFunction_UBPFunctions_Android_SendBroadcast, "SendBroadcast" }, // 2732079746
		{ &Z_Construct_UFunction_UBPFunctions_Android_SetClipboardText, "SetClipboardText" }, // 266189776
		{ &Z_Construct_UFunction_UBPFunctions_Android_SetInputDeviceVibration, "SetInputDeviceVibration" }, // 4183014329
		{ &Z_Construct_UFunction_UBPFunctions_Android_SetKeepScreenOn, "SetKeepScreenOn" }, // 138788424
		{ &Z_Construct_UFunction_UBPFunctions_Android_SetScreenCaptureDisabled, "SetScreenCaptureDisabled" }, // 3760612088
		{ &Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceBool, "SetSharedPreferenceBool" }, // 3694668793
		{ &Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceInt, "SetSharedPreferenceInt" }, // 3473438917
		{ &Z_Construct_UFunction_UBPFunctions_Android_SetSharedPreferenceString, "SetSharedPreferenceString" }, // 59208385
		{ &Z_Construct_UFunction_UBPFunctions_Android_SetVolumeButtonsHandledBySystem, "SetVolumeButtonsHandledBySystem" }, // 3635580034
		{ &Z_Construct_UFunction_UBPFunctions_Android_ShouldUseVulkan, "ShouldUseVulkan" }, // 1769076037
		{ &Z_Construct_UFunction_UBPFunctions_Android_SupportsFloatingPointRenderTargets, "SupportsFloatingPointRenderTargets" }, // 1378000448
		{ &Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderFramebufferFetch, "SupportsShaderFramebufferFetch" }, // 2107965204
		{ &Z_Construct_UFunction_UBPFunctions_Android_SupportsShaderIOBlocks, "SupportsShaderIOBlocks" }, // 1784579643
		{ &Z_Construct_UFunction_UBPFunctions_Android_TriggerHaptic, "TriggerHaptic" }, // 192807597
		{ &Z_Construct_UFunction_UBPFunctions_Android_TriggerSimpleVibration, "TriggerSimpleVibration" }, // 1295813489
		{ &Z_Construct_UFunction_UBPFunctions_Android_UnregisterForRemoteNotifications, "UnregisterForRemoteNotifications" }, // 2992283656
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctions_Android>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBPFunctions_Android_Statics
UObject* (*const Z_Construct_UClass_UBPFunctions_Android_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Android_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctions_Android_Statics::ClassParams = {
	&UBPFunctions_Android::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Android_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPFunctions_Android_Statics::Class_MetaDataParams)
};
void UBPFunctions_Android::StaticRegisterNativesUBPFunctions_Android()
{
	UClass* Class = UBPFunctions_Android::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UBPFunctions_Android_Statics::Funcs));
}
UClass* Z_Construct_UClass_UBPFunctions_Android()
{
	if (!Z_Registration_Info_UClass_UBPFunctions_Android.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPFunctions_Android.OuterSingleton, Z_Construct_UClass_UBPFunctions_Android_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPFunctions_Android.OuterSingleton;
}
UBPFunctions_Android::UBPFunctions_Android(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBPFunctions_Android);
UBPFunctions_Android::~UBPFunctions_Android() {}
// ********** End Class UBPFunctions_Android *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h__Script_GenericAndroidFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPFunctions_Android, UBPFunctions_Android::StaticClass, TEXT("UBPFunctions_Android"), &Z_Registration_Info_UClass_UBPFunctions_Android, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPFunctions_Android), 1088442458U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h__Script_GenericAndroidFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h__Script_GenericAndroidFramework_2484023886{
	TEXT("/Script/GenericAndroidFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h__Script_GenericAndroidFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h__Script_GenericAndroidFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
