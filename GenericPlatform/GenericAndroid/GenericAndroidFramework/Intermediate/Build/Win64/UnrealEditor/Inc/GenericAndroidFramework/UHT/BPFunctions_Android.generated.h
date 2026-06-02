// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPFunctions/BPFunctions_Android.h"

#ifdef GENERICANDROIDFRAMEWORK_BPFunctions_Android_generated_h
#error "BPFunctions_Android.generated.h already included, missing '#pragma once' in BPFunctions_Android.h"
#endif
#define GENERICANDROIDFRAMEWORK_BPFunctions_Android_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
enum class EAndroidBatteryState : uint8;
enum class EAndroidCommonPermission : uint8;
enum class EAndroidHapticType : uint8;
enum class EAndroidMemoryPressureLevel : uint8;
enum class EAndroidNetworkType : uint8;
enum class EAndroidPermissionState : uint8;
enum class EAndroidScreenOrientationType : uint8;
struct FAndroidAppInfo;
struct FAndroidBatteryInfo;
struct FAndroidCapabilityInfo;
struct FAndroidCPUInfo;
struct FAndroidDeviceInfo;
struct FAndroidDisplayInfo;
struct FAndroidGPUInfo;
struct FAndroidGPUMemoryInfo;
struct FAndroidHardwareSnapshot;
struct FAndroidIdInfo;
struct FAndroidInputDeviceInfoData;
struct FAndroidMemoryInfo;
struct FAndroidNetworkInfo;
struct FAndroidStorageInfo;
struct FDateTime;

// ********** Begin Class UBPFunctions_Android *****************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetAndroidDebugReport); \
	DECLARE_FUNCTION(execGetHardwareSnapshot); \
	DECLARE_FUNCTION(execGetSystemFontBytes); \
	DECLARE_FUNCTION(execRestartApplicationWithIntent); \
	DECLARE_FUNCTION(execRestartApplication); \
	DECLARE_FUNCTION(execRequestMinimizeApplication); \
	DECLARE_FUNCTION(execSetScreenCaptureDisabled); \
	DECLARE_FUNCTION(execIsScreenCaptureDisabled); \
	DECLARE_FUNCTION(execSetKeepScreenOn); \
	DECLARE_FUNCTION(execDeleteSharedPreferenceGroup); \
	DECLARE_FUNCTION(execDeleteSharedPreference); \
	DECLARE_FUNCTION(execGetSharedPreferenceString); \
	DECLARE_FUNCTION(execSetSharedPreferenceString); \
	DECLARE_FUNCTION(execGetSharedPreferenceInt); \
	DECLARE_FUNCTION(execSetSharedPreferenceInt); \
	DECLARE_FUNCTION(execGetSharedPreferenceBool); \
	DECLARE_FUNCTION(execSetSharedPreferenceBool); \
	DECLARE_FUNCTION(execHasSharedPreference); \
	DECLARE_FUNCTION(execGetManifestMetaDataString); \
	DECLARE_FUNCTION(execGetManifestMetaDataFloat); \
	DECLARE_FUNCTION(execGetManifestMetaDataLong); \
	DECLARE_FUNCTION(execGetManifestMetaDataInt); \
	DECLARE_FUNCTION(execGetManifestMetaDataBoolean); \
	DECLARE_FUNCTION(execHasManifestMetaDataKey); \
	DECLARE_FUNCTION(execSendBroadcast); \
	DECLARE_FUNCTION(execLaunchPackage); \
	DECLARE_FUNCTION(execIsPackageInstalled); \
	DECLARE_FUNCTION(execLaunchUrl); \
	DECLARE_FUNCTION(execCanLaunchUrl); \
	DECLARE_FUNCTION(execGetLaunchNotification); \
	DECLARE_FUNCTION(execCancelLocalNotificationById); \
	DECLARE_FUNCTION(execCancelLocalNotification); \
	DECLARE_FUNCTION(execScheduleLocalNotificationBadgeFromNow); \
	DECLARE_FUNCTION(execScheduleLocalNotificationBadgeAtTime); \
	DECLARE_FUNCTION(execScheduleLocalNotificationFromNow); \
	DECLARE_FUNCTION(execScheduleLocalNotificationAtTime); \
	DECLARE_FUNCTION(execClearAllLocalNotifications); \
	DECLARE_FUNCTION(execIsAllowedRemoteNotifications); \
	DECLARE_FUNCTION(execUnregisterForRemoteNotifications); \
	DECLARE_FUNCTION(execRegisterForRemoteNotifications); \
	DECLARE_FUNCTION(execGetClipboardText); \
	DECLARE_FUNCTION(execSetClipboardText); \
	DECLARE_FUNCTION(execGetInputMotionState); \
	DECLARE_FUNCTION(execIsIMUSamplingEnabled); \
	DECLARE_FUNCTION(execTriggerHaptic); \
	DECLARE_FUNCTION(execTriggerSimpleVibration); \
	DECLARE_FUNCTION(execSetInputDeviceVibration); \
	DECLARE_FUNCTION(execGetInputDeviceInfo); \
	DECLARE_FUNCTION(execIsGamepadAttached); \
	DECLARE_FUNCTION(execIsScreensaverEnabled); \
	DECLARE_FUNCTION(execIsMusicActive); \
	DECLARE_FUNCTION(execSetVolumeButtonsHandledBySystem); \
	DECLARE_FUNCTION(execGetVolumeButtonsHandledBySystem); \
	DECLARE_FUNCTION(execGetCurrentVolumePercent); \
	DECLARE_FUNCTION(execGetCurrentVolumeStep); \
	DECLARE_FUNCTION(execAreHeadphonesConnected); \
	DECLARE_FUNCTION(execSupportsShaderIOBlocks); \
	DECLARE_FUNCTION(execSupportsShaderFramebufferFetch); \
	DECLARE_FUNCTION(execSupportsFloatingPointRenderTargets); \
	DECLARE_FUNCTION(execShouldUseVulkan); \
	DECLARE_FUNCTION(execIsVulkanAvailable); \
	DECLARE_FUNCTION(execHasVulkanDriverSupport); \
	DECLARE_FUNCTION(execIsSupportedAndroidDevice); \
	DECLARE_FUNCTION(execGetCapabilityInfo); \
	DECLARE_FUNCTION(execGetOrientationString); \
	DECLARE_FUNCTION(execGetDisplayInfo); \
	DECLARE_FUNCTION(execGetNetworkTypeString); \
	DECLARE_FUNCTION(execGetNetworkInfo); \
	DECLARE_FUNCTION(execGetBatteryStateString); \
	DECLARE_FUNCTION(execGetBatteryInfo); \
	DECLARE_FUNCTION(execGetMemoryPressureLevel); \
	DECLARE_FUNCTION(execIsLowMemoryDevice); \
	DECLARE_FUNCTION(execGetMemoryHardwareInfo); \
	DECLARE_FUNCTION(execIsUsingVulkan); \
	DECLARE_FUNCTION(execGetGPURHIName); \
	DECLARE_FUNCTION(execGetGPUUsage); \
	DECLARE_FUNCTION(execGetGPUMemoryInfo); \
	DECLARE_FUNCTION(execGetGPUHardwareInfo); \
	DECLARE_FUNCTION(execGetCPUTemperatureCelsius); \
	DECLARE_FUNCTION(execGetCPUMinFrequenciesMHz); \
	DECLARE_FUNCTION(execGetCPUMaxFrequenciesMHz); \
	DECLARE_FUNCTION(execGetCPUCurrentFrequenciesMHz); \
	DECLARE_FUNCTION(execGetCPUCoreUsages); \
	DECLARE_FUNCTION(execGetCPUAverageUsage); \
	DECLARE_FUNCTION(execGetCPUHardwareInfo); \
	DECLARE_FUNCTION(execGetAllKnownStorageInfos); \
	DECLARE_FUNCTION(execGetProjectStorageInfo); \
	DECLARE_FUNCTION(execGetExternalStorageInfo); \
	DECLARE_FUNCTION(execGetInternalStorageInfo); \
	DECLARE_FUNCTION(execGetStorageInfo); \
	DECLARE_FUNCTION(execGetAndroidPersistentDownloadDir); \
	DECLARE_FUNCTION(execHasAndroidPersistentDownloadDir); \
	DECLARE_FUNCTION(execGetAndroidFilePathBase); \
	DECLARE_FUNCTION(execGetAndroidExternalAppDir); \
	DECLARE_FUNCTION(execGetAndroidInternalAppDir); \
	DECLARE_FUNCTION(execGetAndroidExternalSaveDir); \
	DECLARE_FUNCTION(execGetAndroidExternalExtrasDir); \
	DECLARE_FUNCTION(execGetAndroidExternalConfigDir); \
	DECLARE_FUNCTION(execGetAndroidExternalProjectDir); \
	DECLARE_FUNCTION(execGetAndroidExternalRootDir); \
	DECLARE_FUNCTION(execAndroidPermissionStateToString); \
	DECLARE_FUNCTION(execGetAllAndroidCommonPermissionStrings); \
	DECLARE_FUNCTION(execGetAndroidCommonPermissionString); \
	DECLARE_FUNCTION(execCheckAndroidCommonPermission); \
	DECLARE_FUNCTION(execGetAndroidPermissionState); \
	DECLARE_FUNCTION(execCheckAndroidPermissions); \
	DECLARE_FUNCTION(execCheckAndroidPermission); \
	DECLARE_FUNCTION(execHasAdvertisingId); \
	DECLARE_FUNCTION(execGetLoginId); \
	DECLARE_FUNCTION(execGetAdvertisingId); \
	DECLARE_FUNCTION(execGetAndroidId); \
	DECLARE_FUNCTION(execGetDeviceId); \
	DECLARE_FUNCTION(execGetTimeZoneId); \
	DECLARE_FUNCTION(execGetDefaultLocale); \
	DECLARE_FUNCTION(execGetOSLanguage); \
	DECLARE_FUNCTION(execGetAndroidBuildVersion); \
	DECLARE_FUNCTION(execGetAndroidMajorVersion); \
	DECLARE_FUNCTION(execGetAndroidVersion); \
	DECLARE_FUNCTION(execGetDeviceBuildNumber); \
	DECLARE_FUNCTION(execGetProductName); \
	DECLARE_FUNCTION(execGetDeviceModel); \
	DECLARE_FUNCTION(execGetDeviceBrand); \
	DECLARE_FUNCTION(execGetAndroidIdInfo); \
	DECLARE_FUNCTION(execGetAndroidAppInfo); \
	DECLARE_FUNCTION(execGetAndroidDeviceInfo);


struct Z_Construct_UClass_UBPFunctions_Android_Statics;
GENERICANDROIDFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_Android_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPFunctions_Android(); \
	friend struct ::Z_Construct_UClass_UBPFunctions_Android_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICANDROIDFRAMEWORK_API UClass* ::Z_Construct_UClass_UBPFunctions_Android_NoRegister(); \
public: \
	DECLARE_CLASS2(UBPFunctions_Android, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericAndroidFramework"), Z_Construct_UClass_UBPFunctions_Android_NoRegister) \
	DECLARE_SERIALIZER(UBPFunctions_Android)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICANDROIDFRAMEWORK_API UBPFunctions_Android(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBPFunctions_Android(UBPFunctions_Android&&) = delete; \
	UBPFunctions_Android(const UBPFunctions_Android&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICANDROIDFRAMEWORK_API, UBPFunctions_Android); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPFunctions_Android); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBPFunctions_Android) \
	GENERICANDROIDFRAMEWORK_API virtual ~UBPFunctions_Android();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h_9_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h_12_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBPFunctions_Android;

// ********** End Class UBPFunctions_Android *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_BPFunctions_BPFunctions_Android_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
