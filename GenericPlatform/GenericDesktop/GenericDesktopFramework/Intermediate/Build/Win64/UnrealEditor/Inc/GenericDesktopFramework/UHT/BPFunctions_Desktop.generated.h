// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPFunctions/BPFunctions_Desktop.h"

#ifdef GENERICDESKTOPFRAMEWORK_BPFunctions_Desktop_generated_h
#error "BPFunctions_Desktop.generated.h already included, missing '#pragma once' in BPFunctions_Desktop.h"
#endif
#define GENERICDESKTOPFRAMEWORK_BPFunctions_Desktop_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UTexture2D;
enum class EDesktopDisplayMode : uint8;
enum class EDesktopImageFormat : uint8;
enum class EDesktopTextEncodingOptions : uint8;
struct FDateTime;
struct FDesktopApplicationInfo;
struct FDesktopCPUInfo;
struct FDesktopDiskInfo;
struct FDesktopDisplayInfo;
struct FDesktopGPUInfo;
struct FDesktopGPUMemoryInfo;
struct FDesktopHardwareSnapshot;
struct FDesktopMainWindowInfo;
struct FDesktopMemoryInfo;
struct FDesktopMonitorInfo;
struct FDesktopNetworkAdapterInfo;
struct FDesktopNetworkInfo;
struct FDesktopPowerInfo;
struct FDesktopSystemPathInfo;

// ********** Begin Class UBPFunctions_Desktop *****************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetWindowDebugReport); \
	DECLARE_FUNCTION(execGetHardwareSnapshot); \
	DECLARE_FUNCTION(execGetNetworkInfo); \
	DECLARE_FUNCTION(execGetNetworkAdapterInfo); \
	DECLARE_FUNCTION(execGetBatteryPercent); \
	DECLARE_FUNCTION(execIsRunningOnBattery); \
	DECLARE_FUNCTION(execIsLaptopDevice); \
	DECLARE_FUNCTION(execGetPowerInfo); \
	DECLARE_FUNCTION(execGetDiskUsedBytes); \
	DECLARE_FUNCTION(execGetDiskFreeBytes); \
	DECLARE_FUNCTION(execGetDiskTotalBytes); \
	DECLARE_FUNCTION(execGetAllDiskInfos); \
	DECLARE_FUNCTION(execGetProjectDiskInfo); \
	DECLARE_FUNCTION(execGetDiskInfo); \
	DECLARE_FUNCTION(execGetMemoryProcessUsedPhysicalBytes); \
	DECLARE_FUNCTION(execGetMemorySystemUsedPhysicalBytes); \
	DECLARE_FUNCTION(execGetMemoryAvailablePhysicalBytes); \
	DECLARE_FUNCTION(execGetMemoryTotalPhysicalBytes); \
	DECLARE_FUNCTION(execGetMemoryHardwareInfo); \
	DECLARE_FUNCTION(execGetGPUUsage); \
	DECLARE_FUNCTION(execGetGPUVendorId); \
	DECLARE_FUNCTION(execGetGPUDeviceRevision); \
	DECLARE_FUNCTION(execGetGPUDeviceId); \
	DECLARE_FUNCTION(execGetGPURHIName); \
	DECLARE_FUNCTION(execGetGPUDriverUnifiedVersion); \
	DECLARE_FUNCTION(execGetGPUProviderName); \
	DECLARE_FUNCTION(execGetGPUAdapterDriverDate); \
	DECLARE_FUNCTION(execGetGPUAdapterUserDriverVersion); \
	DECLARE_FUNCTION(execGetGPUAdapterInternalDriverVersion); \
	DECLARE_FUNCTION(execGetGPUAdapterName); \
	DECLARE_FUNCTION(execGetGPUBrand); \
	DECLARE_FUNCTION(execTest_GPUInfo); \
	DECLARE_FUNCTION(execGetGPUMemoryInfo); \
	DECLARE_FUNCTION(execGetGPUHardwareInfo); \
	DECLARE_FUNCTION(execGetSystemUptimeSecond); \
	DECLARE_FUNCTION(execGetCPUThreadCount); \
	DECLARE_FUNCTION(execGetCPUProcessCount); \
	DECLARE_FUNCTION(execGetCPUFrequency); \
	DECLARE_FUNCTION(execGetCPUUsage); \
	DECLARE_FUNCTION(execGetCPULogicalCores); \
	DECLARE_FUNCTION(execGetCPUCores); \
	DECLARE_FUNCTION(execGetCPUPhysicalCores); \
	DECLARE_FUNCTION(execGetCPUChipset); \
	DECLARE_FUNCTION(execGetCPUBrand); \
	DECLARE_FUNCTION(execGetCPUVendor); \
	DECLARE_FUNCTION(execTest_CPUInfo); \
	DECLARE_FUNCTION(execGetCPUHardwareInfo); \
	DECLARE_FUNCTION(execSetScreenCaptureDisabled); \
	DECLARE_FUNCTION(execIsScreenCaptureDisabled); \
	DECLARE_FUNCTION(execRestartApplication); \
	DECLARE_FUNCTION(execRequestMinimizeApplication); \
	DECLARE_FUNCTION(execSetWindowMode); \
	DECLARE_FUNCTION(execGetWindowMode); \
	DECLARE_FUNCTION(execFlashMainWindow); \
	DECLARE_FUNCTION(execSetMainWindowTopMost); \
	DECLARE_FUNCTION(execResizeMainWindow); \
	DECLARE_FUNCTION(execMoveMainWindow); \
	DECLARE_FUNCTION(execRestoreMainWindow); \
	DECLARE_FUNCTION(execMaximizeMainWindow); \
	DECLARE_FUNCTION(execMinimizeMainWindow); \
	DECLARE_FUNCTION(execBringMainWindowToFront); \
	DECLARE_FUNCTION(execIsMainWindowMaximized); \
	DECLARE_FUNCTION(execIsMainWindowMinimized); \
	DECLARE_FUNCTION(execIsMainWindowActive); \
	DECLARE_FUNCTION(execIsMainWindowValid); \
	DECLARE_FUNCTION(execGetMainWindowHandleValue); \
	DECLARE_FUNCTION(execSetMainWindowTitle); \
	DECLARE_FUNCTION(execGetMainWindowTitle); \
	DECLARE_FUNCTION(execGetMainWindowInfo); \
	DECLARE_FUNCTION(execGetMonitorCount); \
	DECLARE_FUNCTION(execGetAllMonitorInfos); \
	DECLARE_FUNCTION(execGetCurrentMonitorInfo); \
	DECLARE_FUNCTION(execGetPrimaryMonitorInfo); \
	DECLARE_FUNCTION(execGetDisplayInfo); \
	DECLARE_FUNCTION(execGetSystemFontBytes); \
	DECLARE_FUNCTION(execRevealFileInExplorer); \
	DECLARE_FUNCTION(execOpenDirectoryInShell); \
	DECLARE_FUNCTION(execOpenFileInShell); \
	DECLARE_FUNCTION(execLaunchUrl); \
	DECLARE_FUNCTION(execCanLaunchUrl); \
	DECLARE_FUNCTION(execGetClipboardText); \
	DECLARE_FUNCTION(execSetClipboardText); \
	DECLARE_FUNCTION(execConvTexture2DToBytes); \
	DECLARE_FUNCTION(execConvBytesToTexture2D); \
	DECLARE_FUNCTION(execLoadImageFromFile); \
	DECLARE_FUNCTION(execLoadImageFromDialog); \
	DECLARE_FUNCTION(execBase64StringToBytes); \
	DECLARE_FUNCTION(execBytesToBase64String); \
	DECLARE_FUNCTION(execBase64StringToString); \
	DECLARE_FUNCTION(execStringToBase64String); \
	DECLARE_FUNCTION(execWriteStringToFile); \
	DECLARE_FUNCTION(execReadStringFromFile); \
	DECLARE_FUNCTION(execAddBytesToFile); \
	DECLARE_FUNCTION(execSaveBytesToFile); \
	DECLARE_FUNCTION(execReadBytesFromFile); \
	DECLARE_FUNCTION(execSaveFileDialog); \
	DECLARE_FUNCTION(execOpenFileDialog); \
	DECLARE_FUNCTION(execMakeValidFileName); \
	DECLARE_FUNCTION(execIsUnderDirectory); \
	DECLARE_FUNCTION(execConvertToFullPath); \
	DECLARE_FUNCTION(execConvertToRelativePath); \
	DECLARE_FUNCTION(execIsRelative); \
	DECLARE_FUNCTION(execGetTimeStamp); \
	DECLARE_FUNCTION(execGetFilePathLeaf); \
	DECLARE_FUNCTION(execGetFilePath); \
	DECLARE_FUNCTION(execGetBaseFilename); \
	DECLARE_FUNCTION(execGetCleanFilename); \
	DECLARE_FUNCTION(execSetFileExtension); \
	DECLARE_FUNCTION(execGetFileExtension); \
	DECLARE_FUNCTION(execIsFileReadOnly); \
	DECLARE_FUNCTION(execIsDrive); \
	DECLARE_FUNCTION(execNormalizeFileName); \
	DECLARE_FUNCTION(execFileSize); \
	DECLARE_FUNCTION(execDeleteFile); \
	DECLARE_FUNCTION(execMoveFile); \
	DECLARE_FUNCTION(execCopyFile); \
	DECLARE_FUNCTION(execExistFile); \
	DECLARE_FUNCTION(execFindFileRecursive); \
	DECLARE_FUNCTION(execFindFile); \
	DECLARE_FUNCTION(execOpenDirectoryDialog); \
	DECLARE_FUNCTION(execNormalizeDirectory); \
	DECLARE_FUNCTION(execFindDirectoryRecursive); \
	DECLARE_FUNCTION(execFindDirectory); \
	DECLARE_FUNCTION(execDeleteDirectoryRecursively); \
	DECLARE_FUNCTION(execDeleteDirectory); \
	DECLARE_FUNCTION(execCreateDirectory); \
	DECLARE_FUNCTION(execExistDirectory); \
	DECLARE_FUNCTION(execGetTempDir); \
	DECLARE_FUNCTION(execGetSavedGamesDir); \
	DECLARE_FUNCTION(execGetProgramDataDir); \
	DECLARE_FUNCTION(execGetLocalAppDataDir); \
	DECLARE_FUNCTION(execGetAppDataDir); \
	DECLARE_FUNCTION(execGetDownloadsDir); \
	DECLARE_FUNCTION(execGetDocumentsDir); \
	DECLARE_FUNCTION(execGetDesktopDir); \
	DECLARE_FUNCTION(execGetExtrasDir); \
	DECLARE_FUNCTION(execGetSaveGameDir); \
	DECLARE_FUNCTION(execGetPluginExtraDir); \
	DECLARE_FUNCTION(execGetPluginSourceDir); \
	DECLARE_FUNCTION(execGetPluginResourcesDir); \
	DECLARE_FUNCTION(execGetPluginIntermediateDir); \
	DECLARE_FUNCTION(execGetPluginContentDir); \
	DECLARE_FUNCTION(execGetPluginBinariesDir); \
	DECLARE_FUNCTION(execGetPluginBaseDir); \
	DECLARE_FUNCTION(execGetEnvironmentVariable); \
	DECLARE_FUNCTION(execIsRunningAsAdministrator); \
	DECLARE_FUNCTION(execGetOSVersions); \
	DECLARE_FUNCTION(execGetOSVersion); \
	DECLARE_FUNCTION(execGetOperatingSystemId); \
	DECLARE_FUNCTION(execGetCommandLineString); \
	DECLARE_FUNCTION(execGetProcessId); \
	DECLARE_FUNCTION(execGetExecutablePath); \
	DECLARE_FUNCTION(execGetDesktopUserHomeDir); \
	DECLARE_FUNCTION(execGetDesktopUserTempDir); \
	DECLARE_FUNCTION(execGetDesktopUserDir); \
	DECLARE_FUNCTION(execGetDesktopBaseDir); \
	DECLARE_FUNCTION(execGetDesktopUserName); \
	DECLARE_FUNCTION(execGetDesktopName); \
	DECLARE_FUNCTION(execGetDeviceID); \
	DECLARE_FUNCTION(execGetSystemPathInfo); \
	DECLARE_FUNCTION(execGetApplicationInfo);


struct Z_Construct_UClass_UBPFunctions_Desktop_Statics;
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_Desktop_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPFunctions_Desktop(); \
	friend struct ::Z_Construct_UClass_UBPFunctions_Desktop_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICDESKTOPFRAMEWORK_API UClass* ::Z_Construct_UClass_UBPFunctions_Desktop_NoRegister(); \
public: \
	DECLARE_CLASS2(UBPFunctions_Desktop, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericDesktopFramework"), Z_Construct_UClass_UBPFunctions_Desktop_NoRegister) \
	DECLARE_SERIALIZER(UBPFunctions_Desktop)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h_12_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICDESKTOPFRAMEWORK_API UBPFunctions_Desktop(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBPFunctions_Desktop(UBPFunctions_Desktop&&) = delete; \
	UBPFunctions_Desktop(const UBPFunctions_Desktop&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICDESKTOPFRAMEWORK_API, UBPFunctions_Desktop); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPFunctions_Desktop); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBPFunctions_Desktop) \
	GENERICDESKTOPFRAMEWORK_API virtual ~UBPFunctions_Desktop();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h_9_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h_12_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBPFunctions_Desktop;

// ********** End Class UBPFunctions_Desktop *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
