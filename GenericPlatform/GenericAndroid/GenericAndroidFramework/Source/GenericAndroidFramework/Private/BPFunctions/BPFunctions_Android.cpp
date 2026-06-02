#include "BPFunctions/BPFunctions_Android.h"

#include "Async/Async.h"
#include "DynamicRHI.h"
#include "GameFramework/PlayerController.h"
#include "GenericPlatform/GenericApplication.h"
#include "GenericPlatform/GenericPlatformDriver.h"
#include "GenericPlatform/GenericPlatformMemory.h"
#include "HAL/PlatformApplicationMisc.h"
#include "HAL/PlatformFileManager.h"
#include "HAL/PlatformProcess.h"
#include "Kismet/BlueprintPlatformLibrary.h"
#include "Misc/App.h"
#include "Misc/ConfigCacheIni.h"
#include "Misc/Paths.h"
#include "RHIStats.h"
#include "RHIGlobals.h"

#if PLATFORM_ANDROID
#include "AndroidPermissionFunctionLibrary.h"
#include "Android/AndroidInputInterface.h"
#include "Android/AndroidPlatformMisc.h"
#endif

#if PLATFORM_ANDROID
extern FString GFilePathBase;
extern FString GInternalFilePath;
extern FString GExternalFilePath;

extern FString AndroidThunkCpp_GetAndroidId();
extern bool AndroidThunkCpp_IsPackageInstalled(const FString& PackageName);
extern bool AndroidThunkCpp_LaunchPackage(const FString& PackageName, const FString& ExtraKey, const FString& ExtraValue);
extern bool AndroidThunkCpp_SendBroadcast(const FString& PackageName, const FString& ExtraKey, const FString& ExtraValue, bool bExit);
extern bool AndroidThunkCpp_HasSharedPreference(const FString& Group, const FString& Key);
extern void AndroidThunkCpp_SetSharedPreferenceBool(const FString& Group, const FString& Key, bool Value);
extern bool AndroidThunkCpp_GetSharedPreferenceBool(const FString& Group, const FString& Key, bool DefaultValue);
extern void AndroidThunkCpp_SetSharedPreferenceInt(const FString& Group, const FString& Key, int32 Value);
extern int32 AndroidThunkCpp_GetSharedPreferenceInt(const FString& Group, const FString& Key, int32 DefaultValue);
extern void AndroidThunkCpp_SetSharedPreferenceString(const FString& Group, const FString& Key, const FString& Value);
extern FString AndroidThunkCpp_GetSharedPreferenceString(const FString& Group, const FString& Key, const FString& DefaultValue);
extern void AndroidThunkCpp_DeleteSharedPreference(const FString& Group, const FString& Key);
extern void AndroidThunkCpp_DeleteSharedPreferenceGroup(const FString& Group);
extern void AndroidThunkCpp_ClipboardCopy(const FString& Str);
extern FString AndroidThunkCpp_ClipboardPaste();
extern bool AndroidThunkCpp_HasMetaDataKey(const FString& Key);
extern bool AndroidThunkCpp_GetMetaDataBoolean(const FString& Key);
extern int32 AndroidThunkCpp_GetMetaDataInt(const FString& Key);
extern int64 AndroidThunkCpp_GetMetaDataLong(const FString& Key);
extern float AndroidThunkCpp_GetMetaDataFloat(const FString& Key);
extern FString AndroidThunkCpp_GetMetaDataString(const FString& Key);
extern bool AndroidThunkCpp_GetInputDeviceInfo(int32 DeviceId, FAndroidInputDeviceInfo& Results);
extern bool AndroidThunkCpp_SetInputDeviceVibrators(int32 DeviceId, int32 LeftIntensity, int32 LeftDuration, int32 RightIntensity, int32 RightDuration);
extern bool AndroidThunkCpp_IsGamepadAttached();
extern void AndroidThunkCpp_KeepScreenOn(bool Enable);
extern bool AndroidThunkCpp_IsScreenCaptureDisabled();
extern void AndroidThunkCpp_DisableScreenCapture(bool bDisable);
extern void AndroidThunkCpp_RestartApplication(const FString& IntentString);
extern void AndroidThunkCpp_Vibrate(int32 Intensity, int32 Duration);
extern bool AndroidThunkCpp_IsMusicActive();
extern bool AndroidThunkCpp_IsScreensaverEnabled();
#endif

namespace
{
	const TCHAR* AndroidRuntimeSettingsSection = TEXT("/Script/AndroidRuntimeSettings.AndroidRuntimeSettings");

	int64 ClampByteSizeToInt64(const uint64 Value)
	{
		return Value > static_cast<uint64>(MAX_int64) ? MAX_int64 : static_cast<int64>(Value);
	}

	float GetCurrentProcessGPUUsageFraction(const FRHIGPUUsageFractions& Usage)
	{
#if ENGINE_MAJOR_VERSION > 5 || (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 7)
		return Usage.CurrentProcessMHz;
#else
		return Usage.CurrentProcess;
#endif
	}

	float GetExternalProcessGPUUsageFraction(const FRHIGPUUsageFractions& Usage)
	{
#if ENGINE_MAJOR_VERSION > 5 || (ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 7)
		return Usage.ExternalProcessesMHz;
#else
		return Usage.ExternalProcesses;
#endif
	}

	FString GetAndroidRuntimeString(const TCHAR* Key)
	{
		FString Value;
		if (GConfig != nullptr)
		{
			GConfig->GetString(AndroidRuntimeSettingsSection, Key, Value, GEngineIni);
		}

		if (Key != nullptr && FCString::Stricmp(Key, TEXT("PackageName")) == 0 && Value.Contains(TEXT("[PROJECT]")))
		{
			Value = Value.Replace(TEXT("[PROJECT]"), FApp::GetProjectName());
		}

		return Value;
	}

	int32 GetAndroidRuntimeInt(const TCHAR* Key)
	{
		int32 Value = 0;
		if (GConfig != nullptr)
		{
			GConfig->GetInt(AndroidRuntimeSettingsSection, Key, Value, GEngineIni);
		}
		return Value;
	}

	bool GetAndroidRuntimeBool(const TCHAR* Key, const bool bDefaultValue = false)
	{
		bool bValue = bDefaultValue;
		if (GConfig != nullptr)
		{
			GConfig->GetBool(AndroidRuntimeSettingsSection, Key, bValue, GEngineIni);
		}
		return bValue;
	}

	TArray<EAndroidCommonPermission> GetAllCommonPermissions()
	{
		return {
			EAndroidCommonPermission::Camera,
			EAndroidCommonPermission::RecordAudio,
			EAndroidCommonPermission::ReadExternalStorage,
			EAndroidCommonPermission::WriteExternalStorage,
			EAndroidCommonPermission::ReadMediaImages,
			EAndroidCommonPermission::ReadMediaVideo,
			EAndroidCommonPermission::ReadMediaAudio,
			EAndroidCommonPermission::PostNotifications,
			EAndroidCommonPermission::AccessFineLocation,
			EAndroidCommonPermission::AccessCoarseLocation,
			EAndroidCommonPermission::AccessWifiState,
			EAndroidCommonPermission::ChangeWifiState,
			EAndroidCommonPermission::Internet,
			EAndroidCommonPermission::Bluetooth,
			EAndroidCommonPermission::BluetoothAdmin,
			EAndroidCommonPermission::BluetoothConnect,
			EAndroidCommonPermission::BluetoothScan,
			EAndroidCommonPermission::BluetoothAdvertise,
			EAndroidCommonPermission::WakeLock,
			EAndroidCommonPermission::Vibrate,
			EAndroidCommonPermission::ReadPhoneState,
			EAndroidCommonPermission::BodySensors,
			EAndroidCommonPermission::Nfc
		};
	}

	FString ToPermissionString(const EAndroidCommonPermission Permission)
	{
		switch (Permission)
		{
		case EAndroidCommonPermission::Camera:
			return TEXT("android.permission.CAMERA");
		case EAndroidCommonPermission::RecordAudio:
			return TEXT("android.permission.RECORD_AUDIO");
		case EAndroidCommonPermission::ReadExternalStorage:
			return TEXT("android.permission.READ_EXTERNAL_STORAGE");
		case EAndroidCommonPermission::WriteExternalStorage:
			return TEXT("android.permission.WRITE_EXTERNAL_STORAGE");
		case EAndroidCommonPermission::ReadMediaImages:
			return TEXT("android.permission.READ_MEDIA_IMAGES");
		case EAndroidCommonPermission::ReadMediaVideo:
			return TEXT("android.permission.READ_MEDIA_VIDEO");
		case EAndroidCommonPermission::ReadMediaAudio:
			return TEXT("android.permission.READ_MEDIA_AUDIO");
		case EAndroidCommonPermission::PostNotifications:
			return TEXT("android.permission.POST_NOTIFICATIONS");
		case EAndroidCommonPermission::AccessFineLocation:
			return TEXT("android.permission.ACCESS_FINE_LOCATION");
		case EAndroidCommonPermission::AccessCoarseLocation:
			return TEXT("android.permission.ACCESS_COARSE_LOCATION");
		case EAndroidCommonPermission::AccessWifiState:
			return TEXT("android.permission.ACCESS_WIFI_STATE");
		case EAndroidCommonPermission::ChangeWifiState:
			return TEXT("android.permission.CHANGE_WIFI_STATE");
		case EAndroidCommonPermission::Internet:
			return TEXT("android.permission.INTERNET");
		case EAndroidCommonPermission::Bluetooth:
			return TEXT("android.permission.BLUETOOTH");
		case EAndroidCommonPermission::BluetoothAdmin:
			return TEXT("android.permission.BLUETOOTH_ADMIN");
		case EAndroidCommonPermission::BluetoothConnect:
			return TEXT("android.permission.BLUETOOTH_CONNECT");
		case EAndroidCommonPermission::BluetoothScan:
			return TEXT("android.permission.BLUETOOTH_SCAN");
		case EAndroidCommonPermission::BluetoothAdvertise:
			return TEXT("android.permission.BLUETOOTH_ADVERTISE");
		case EAndroidCommonPermission::WakeLock:
			return TEXT("android.permission.WAKE_LOCK");
		case EAndroidCommonPermission::Vibrate:
			return TEXT("android.permission.VIBRATE");
		case EAndroidCommonPermission::ReadPhoneState:
			return TEXT("android.permission.READ_PHONE_STATE");
		case EAndroidCommonPermission::BodySensors:
			return TEXT("android.permission.BODY_SENSORS");
		case EAndroidCommonPermission::Nfc:
			return TEXT("android.permission.NFC");
		default:
			return TEXT("");
		}
	}

	FString PermissionStateToStringInternal(const EAndroidPermissionState State)
	{
		switch (State)
		{
		case EAndroidPermissionState::Granted:
			return TEXT("Granted");
		case EAndroidPermissionState::Denied:
			return TEXT("Denied");
		default:
			return TEXT("Unknown");
		}
	}

	EAndroidNetworkType ConvertNetworkType(const ENetworkConnectionType Type)
	{
		switch (Type)
		{
		case ENetworkConnectionType::None:
			return EAndroidNetworkType::None;
		case ENetworkConnectionType::AirplaneMode:
			return EAndroidNetworkType::AirplaneMode;
		case ENetworkConnectionType::Cell:
			return EAndroidNetworkType::Cell;
		case ENetworkConnectionType::WiFi:
			return EAndroidNetworkType::WiFi;
		case ENetworkConnectionType::WiMAX:
			return EAndroidNetworkType::WiMAX;
		case ENetworkConnectionType::Bluetooth:
			return EAndroidNetworkType::Bluetooth;
		case ENetworkConnectionType::Ethernet:
			return EAndroidNetworkType::Ethernet;
		default:
			return EAndroidNetworkType::Unknown;
		}
	}

	FString NetworkTypeToStringInternal(const EAndroidNetworkType Type)
	{
		switch (Type)
		{
		case EAndroidNetworkType::None:
			return TEXT("None");
		case EAndroidNetworkType::AirplaneMode:
			return TEXT("AirplaneMode");
		case EAndroidNetworkType::Cell:
			return TEXT("Cell");
		case EAndroidNetworkType::WiFi:
			return TEXT("WiFi");
		case EAndroidNetworkType::WiMAX:
			return TEXT("WiMAX");
		case EAndroidNetworkType::Bluetooth:
			return TEXT("Bluetooth");
		case EAndroidNetworkType::Ethernet:
			return TEXT("Ethernet");
		default:
			return TEXT("Unknown");
		}
	}

	EAndroidBatteryState ConvertBatteryState(
#if PLATFORM_ANDROID
		const FAndroidMisc::EBatteryState State
#else
		const int32 State
#endif
	)
	{
#if PLATFORM_ANDROID
		switch (State)
		{
		case FAndroidMisc::BATTERY_STATE_CHARGING:
			return EAndroidBatteryState::Charging;
		case FAndroidMisc::BATTERY_STATE_DISCHARGING:
			return EAndroidBatteryState::Discharging;
		case FAndroidMisc::BATTERY_STATE_NOT_CHARGING:
			return EAndroidBatteryState::NotCharging;
		case FAndroidMisc::BATTERY_STATE_FULL:
			return EAndroidBatteryState::Full;
		default:
			return EAndroidBatteryState::Unknown;
		}
#else
		return EAndroidBatteryState::Unknown;
#endif
	}

	FString BatteryStateToStringInternal(const EAndroidBatteryState State)
	{
		switch (State)
		{
		case EAndroidBatteryState::Charging:
			return TEXT("Charging");
		case EAndroidBatteryState::Discharging:
			return TEXT("Discharging");
		case EAndroidBatteryState::NotCharging:
			return TEXT("NotCharging");
		case EAndroidBatteryState::Full:
			return TEXT("Full");
		default:
			return TEXT("Unknown");
		}
	}

	EAndroidScreenOrientationType ConvertOrientation(const EDeviceScreenOrientation Orientation)
	{
		switch (Orientation)
		{
		case EDeviceScreenOrientation::Portrait:
			return EAndroidScreenOrientationType::Portrait;
		case EDeviceScreenOrientation::PortraitUpsideDown:
			return EAndroidScreenOrientationType::PortraitUpsideDown;
		case EDeviceScreenOrientation::LandscapeLeft:
			return EAndroidScreenOrientationType::LandscapeLeft;
		case EDeviceScreenOrientation::LandscapeRight:
			return EAndroidScreenOrientationType::LandscapeRight;
		case EDeviceScreenOrientation::FaceUp:
			return EAndroidScreenOrientationType::FaceUp;
		case EDeviceScreenOrientation::FaceDown:
			return EAndroidScreenOrientationType::FaceDown;
		case EDeviceScreenOrientation::PortraitSensor:
			return EAndroidScreenOrientationType::PortraitSensor;
		case EDeviceScreenOrientation::LandscapeSensor:
			return EAndroidScreenOrientationType::LandscapeSensor;
		case EDeviceScreenOrientation::FullSensor:
			return EAndroidScreenOrientationType::FullSensor;
		default:
			return EAndroidScreenOrientationType::Unknown;
		}
	}

	FString OrientationToStringInternal(const EAndroidScreenOrientationType Orientation)
	{
		switch (Orientation)
		{
		case EAndroidScreenOrientationType::Portrait:
			return TEXT("Portrait");
		case EAndroidScreenOrientationType::PortraitUpsideDown:
			return TEXT("PortraitUpsideDown");
		case EAndroidScreenOrientationType::LandscapeLeft:
			return TEXT("LandscapeLeft");
		case EAndroidScreenOrientationType::LandscapeRight:
			return TEXT("LandscapeRight");
		case EAndroidScreenOrientationType::FaceUp:
			return TEXT("FaceUp");
		case EAndroidScreenOrientationType::FaceDown:
			return TEXT("FaceDown");
		case EAndroidScreenOrientationType::PortraitSensor:
			return TEXT("PortraitSensor");
		case EAndroidScreenOrientationType::LandscapeSensor:
			return TEXT("LandscapeSensor");
		case EAndroidScreenOrientationType::FullSensor:
			return TEXT("FullSensor");
		default:
			return TEXT("Unknown");
		}
	}

	EMobileHapticsType ConvertHapticType(const EAndroidHapticType Type)
	{
		switch (Type)
		{
		case EAndroidHapticType::FeedbackSuccess:
			return EMobileHapticsType::FeedbackSuccess;
		case EAndroidHapticType::FeedbackWarning:
			return EMobileHapticsType::FeedbackWarning;
		case EAndroidHapticType::FeedbackError:
			return EMobileHapticsType::FeedbackError;
		case EAndroidHapticType::SelectionChanged:
			return EMobileHapticsType::SelectionChanged;
		case EAndroidHapticType::ImpactLight:
			return EMobileHapticsType::ImpactLight;
		case EAndroidHapticType::ImpactMedium:
			return EMobileHapticsType::ImpactMedium;
		case EAndroidHapticType::ImpactHeavy:
		default:
			return EMobileHapticsType::ImpactHeavy;
		}
	}

	EAndroidMemoryPressureLevel CalculateMemoryPressureLevel(const FPlatformMemoryStats& Stats)
	{
		if (Stats.TotalPhysical == 0)
		{
			return EAndroidMemoryPressureLevel::Unknown;
		}

		const double AvailableRatio = static_cast<double>(Stats.AvailablePhysical) / static_cast<double>(Stats.TotalPhysical);
		if (AvailableRatio <= 0.10)
		{
			return EAndroidMemoryPressureLevel::Critical;
		}
		if (AvailableRatio <= 0.20)
		{
			return EAndroidMemoryPressureLevel::Warning;
		}
		return EAndroidMemoryPressureLevel::Normal;
	}

	FGPUDriverInfo GetCurrentGPUDriverInfo()
	{
		FString DeviceDescription = GRHIGlobals.GpuInfo.AdapterName;
		if (DeviceDescription.IsEmpty())
		{
			DeviceDescription = FPlatformMisc::GetPrimaryGPUBrand();
		}
		return FPlatformMisc::GetGPUDriverInfo(DeviceDescription);
	}

	FAndroidGPUMemoryInfo BuildGPUMemoryInfo()
	{
		FAndroidGPUMemoryInfo Info;

		if (!GRHIGlobals.IsRHIInitialized || GDynamicRHI == nullptr)
		{
			return Info;
		}

		FTextureMemoryStats TextureMemoryStats;
		RHIGetTextureMemoryStats(TextureMemoryStats);

		Info.bIsValid = TextureMemoryStats.AreHardwareStatsValid()
			|| TextureMemoryStats.TotalGraphicsMemory >= 0
			|| TextureMemoryStats.TexturePoolSize > 0
			|| TextureMemoryStats.StreamingMemorySize > 0
			|| TextureMemoryStats.NonStreamingMemorySize > 0;
		Info.DedicatedVideoMemoryBytes = TextureMemoryStats.DedicatedVideoMemory;
		Info.DedicatedSystemMemoryBytes = TextureMemoryStats.DedicatedSystemMemory;
		Info.SharedSystemMemoryBytes = TextureMemoryStats.SharedSystemMemory;
		Info.TotalGraphicsMemoryBytes = TextureMemoryStats.TotalGraphicsMemory;
		Info.StreamingMemorySizeBytes = ClampByteSizeToInt64(TextureMemoryStats.StreamingMemorySize);
		Info.NonStreamingMemorySizeBytes = ClampByteSizeToInt64(TextureMemoryStats.NonStreamingMemorySize);
		Info.LargestContiguousAllocationBytes = TextureMemoryStats.LargestContiguousAllocation;
		Info.TexturePoolSizeBytes = TextureMemoryStats.TexturePoolSize;
		Info.AvailableTexturePoolBytes = TextureMemoryStats.ComputeAvailableMemorySize();

		return Info;
	}

	FAndroidMemoryInfo BuildMemoryInfo()
	{
		const FPlatformMemoryStats Stats = FPlatformMemory::GetStats();
		const FPlatformMemoryConstants& Constants = FPlatformMemory::GetConstants();

		FAndroidMemoryInfo Info;
		Info.TotalPhysicalBytes = ClampByteSizeToInt64(Stats.TotalPhysical);
		Info.AvailablePhysicalBytes = ClampByteSizeToInt64(Stats.AvailablePhysical);
		Info.SystemUsedPhysicalBytes = ClampByteSizeToInt64(Stats.TotalPhysical > Stats.AvailablePhysical ? Stats.TotalPhysical - Stats.AvailablePhysical : 0);
		Info.ProcessUsedPhysicalBytes = ClampByteSizeToInt64(Stats.UsedPhysical);
		Info.PeakProcessUsedPhysicalBytes = ClampByteSizeToInt64(Stats.PeakUsedPhysical);
		Info.TotalVirtualBytes = ClampByteSizeToInt64(Stats.TotalVirtual);
		Info.AvailableVirtualBytes = ClampByteSizeToInt64(Stats.AvailableVirtual);
		Info.ProcessUsedVirtualBytes = ClampByteSizeToInt64(Stats.UsedVirtual);
		Info.PeakProcessUsedVirtualBytes = ClampByteSizeToInt64(Stats.PeakUsedVirtual);
		Info.TotalPhysicalGB = Constants.TotalPhysicalGB;

		if (Stats.TotalPhysical > 0)
		{
			Info.SystemPhysicalUsagePercent = static_cast<float>((static_cast<double>(Info.SystemUsedPhysicalBytes) / static_cast<double>(Stats.TotalPhysical)) * 100.0);
			Info.ProcessPhysicalUsagePercent = static_cast<float>((static_cast<double>(Stats.UsedPhysical) / static_cast<double>(Stats.TotalPhysical)) * 100.0);
		}

		Info.PressureLevel = CalculateMemoryPressureLevel(Stats);
		Info.bLowMemory = Info.PressureLevel == EAndroidMemoryPressureLevel::Warning || Info.PressureLevel == EAndroidMemoryPressureLevel::Critical;
		return Info;
	}

	FAndroidStorageInfo BuildStorageInfo(const FString& InPath)
	{
		FAndroidStorageInfo Info;
		Info.Path = InPath.IsEmpty() ? FPaths::ProjectDir() : InPath;

		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		Info.bExists = PlatformFile.DirectoryExists(*Info.Path) || PlatformFile.FileExists(*Info.Path);

		uint64 TotalBytes = 0;
		uint64 FreeBytes = 0;
		Info.bIsValid = FPlatformMisc::GetDiskTotalAndFreeSpace(Info.Path, TotalBytes, FreeBytes);
		Info.TotalBytes = ClampByteSizeToInt64(TotalBytes);
		Info.FreeBytes = ClampByteSizeToInt64(FreeBytes);
		Info.UsedBytes = ClampByteSizeToInt64(TotalBytes >= FreeBytes ? TotalBytes - FreeBytes : 0);
		Info.RootPath = FPaths::GetPath(Info.Path);
		return Info;
	}

	FAndroidDeviceInfo BuildDeviceInfo()
	{
		FAndroidDeviceInfo Info;
		Info.Brand = UBPFunctions_Android::GetDeviceBrand();
		Info.Model = UBPFunctions_Android::GetDeviceModel();
		Info.ProductName = UBPFunctions_Android::GetProductName();
		Info.DeviceBuildNumber = UBPFunctions_Android::GetDeviceBuildNumber();
		Info.AndroidVersion = UBPFunctions_Android::GetAndroidVersion();
		Info.AndroidMajorVersion = UBPFunctions_Android::GetAndroidMajorVersion();
		Info.AndroidBuildVersion = UBPFunctions_Android::GetAndroidBuildVersion();
		Info.OSLanguage = UBPFunctions_Android::GetOSLanguage();
		Info.DefaultLocale = UBPFunctions_Android::GetDefaultLocale();
		Info.TimeZoneId = UBPFunctions_Android::GetTimeZoneId();
		Info.ProjectVersion = GetAndroidRuntimeString(TEXT("VersionDisplayName"));
		return Info;
	}

	FAndroidAppInfo BuildAppInfo()
	{
		FAndroidAppInfo Info;
		Info.PackageName = GetAndroidRuntimeString(TEXT("PackageName"));
		Info.VersionDisplayName = GetAndroidRuntimeString(TEXT("VersionDisplayName"));
		Info.StoreVersion = GetAndroidRuntimeInt(TEXT("StoreVersion"));
		Info.MinSDKVersion = GetAndroidRuntimeInt(TEXT("MinSDKVersion"));
		Info.TargetSDKVersion = GetAndroidRuntimeInt(TEXT("TargetSDKVersion"));
		Info.DistributionChannel = UBPFunctions_Android::GetManifestMetaDataString(TEXT("channel"));
		if (Info.DistributionChannel.IsEmpty())
		{
			Info.DistributionChannel = UBPFunctions_Android::GetManifestMetaDataString(TEXT("CHANNEL"));
		}
		return Info;
	}

	FAndroidIdInfo BuildIdInfo()
	{
		FAndroidIdInfo Info;
		Info.DeviceId = UBPFunctions_Android::GetDeviceId();
		Info.AndroidId = UBPFunctions_Android::GetAndroidId();
		Info.AdvertisingId = UBPFunctions_Android::GetAdvertisingId();
		Info.LoginId = UBPFunctions_Android::GetLoginId();
		Info.bHasAndroidId = !Info.AndroidId.IsEmpty();
		Info.bHasAdvertisingId = !Info.AdvertisingId.IsEmpty();
		Info.bHasLoginId = !Info.LoginId.IsEmpty();
		return Info;
	}

	FAndroidCPUInfo BuildCPUInfo()
	{
		FAndroidCPUInfo Info;
		Info.Vendor = FPlatformMisc::GetCPUVendor();
		Info.Brand = FPlatformMisc::GetCPUBrand();
		Info.Chipset = FPlatformMisc::GetCPUChipset();
		Info.PhysicalCores = FPlatformMisc::NumberOfCores();
		Info.LogicalCores = FPlatformMisc::NumberOfCoresIncludingHyperthreads();

#if PLATFORM_ANDROID
		FAndroidMisc::FCPUState& CpuState = FAndroidMisc::GetCPUState();
		const int32 CoreCount = FMath::Clamp(CpuState.CoreCount, 0, FAndroidMisc::FCPUState::MaxSupportedCores);
		Info.ActiveCores = CpuState.ActivatedCoreCount;
		Info.AverageUsagePercent = static_cast<float>(CpuState.AverageUtilization * 100.0);

		for (int32 CoreIndex = 0; CoreIndex < CoreCount; ++CoreIndex)
		{
			Info.PerCoreUsagePercent.Add(static_cast<float>(CpuState.Utilization[CoreIndex] * 100.0));
			Info.CurrentFrequenciesMHz.Add(static_cast<int32>(FAndroidMisc::GetCoreFrequency(CoreIndex, FAndroidMisc::ECoreFrequencyProperty::CurrentFrequency) / 1000));
			Info.MaxFrequenciesMHz.Add(static_cast<int32>(FAndroidMisc::GetCoreFrequency(CoreIndex, FAndroidMisc::ECoreFrequencyProperty::MaxFrequency) / 1000));
			Info.MinFrequenciesMHz.Add(static_cast<int32>(FAndroidMisc::GetCoreFrequency(CoreIndex, FAndroidMisc::ECoreFrequencyProperty::MinFrequency) / 1000));
		}

		Info.TemperatureCelsius = FAndroidMisc::GetCPUTemperature();
#endif

		return Info;
	}

	FAndroidGPUInfo BuildGPUInfo()
	{
		FAndroidGPUInfo Info;
		const FGPUDriverInfo DriverInfo = GetCurrentGPUDriverInfo();

		float TotalUsagePercent = -1.f;
		float CurrentProcessUsagePercent = -1.f;
		if (GRHIGlobals.IsRHIInitialized && GRHISupportsGPUUsage && RHIGetGPUUsage != nullptr)
		{
			const FRHIGPUUsageFractions Usage = RHIGetGPUUsage(0);
			const float CurrentProcessUsageFraction = GetCurrentProcessGPUUsageFraction(Usage);
			TotalUsagePercent = FMath::Clamp((CurrentProcessUsageFraction + GetExternalProcessGPUUsageFraction(Usage)) * 100.f, 0.f, 100.f);
			CurrentProcessUsagePercent = FMath::Clamp(CurrentProcessUsageFraction * 100.f, 0.f, 100.f);
		}

		Info.Brand = FPlatformMisc::GetPrimaryGPUBrand();
#if PLATFORM_ANDROID
		Info.GPUFamily = FAndroidMisc::GetGPUFamily();
		Info.GLVersion = FAndroidMisc::GetGLVersion();
		Info.VulkanVersion = FAndroidMisc::GetVulkanVersion();
		Info.bHasVulkanDriverSupport = FAndroidMisc::HasVulkanDriverSupport();
		Info.bIsVulkanAvailable = FAndroidMisc::IsVulkanAvailable();
		Info.bShouldUseVulkan = FAndroidMisc::ShouldUseVulkan();
#endif
		Info.Renderer = GRHIGlobals.GpuInfo.AdapterName.IsEmpty() ? Info.Brand : GRHIGlobals.GpuInfo.AdapterName;
		Info.VendorName = DriverInfo.ProviderName.IsEmpty() ? Info.Brand : DriverInfo.ProviderName;
		Info.DriverInternalVersion = GRHIGlobals.GpuInfo.AdapterInternalDriverVersion;
		Info.DriverUserVersion = GRHIGlobals.GpuInfo.AdapterUserDriverVersion;
		Info.DriverUnifiedVersion = DriverInfo.GetUnifiedDriverVersion();
		Info.DriverDate = GRHIGlobals.GpuInfo.AdapterDriverDate;
		Info.RHIName = DriverInfo.RHIName;
		Info.UsagePercent = TotalUsagePercent;
		Info.ProcessUsagePercent = CurrentProcessUsagePercent;
		return Info;
	}

	FAndroidBatteryInfo BuildBatteryInfo()
	{
		FAndroidBatteryInfo Info;
#if PLATFORM_ANDROID
		const FAndroidMisc::FBatteryState BatteryState = FAndroidMisc::GetBatteryState();
		Info.State = ConvertBatteryState(BatteryState.State);
		Info.Level = BatteryState.Level;
		Info.TemperatureCelsius = BatteryState.Temperature;
		Info.bCharging = Info.State == EAndroidBatteryState::Charging || Info.State == EAndroidBatteryState::Full;
		Info.bRunningOnBattery = FAndroidMisc::IsRunningOnBattery();
		Info.bLowPowerMode = FAndroidMisc::IsInLowPowerMode();
#endif
		return Info;
	}

	FAndroidNetworkInfo BuildNetworkInfo()
	{
		FAndroidNetworkInfo Info;
		Info.NetworkType = ConvertNetworkType(FPlatformMisc::GetNetworkConnectionType());
		Info.bHasNetwork = Info.NetworkType != EAndroidNetworkType::Unknown
			&& Info.NetworkType != EAndroidNetworkType::None
			&& Info.NetworkType != EAndroidNetworkType::AirplaneMode;
#if PLATFORM_ANDROID
		Info.bHasWiFiConnection = FAndroidMisc::HasActiveWiFiConnection();
		Info.CellularPreference = FAndroidMisc::GetCellularPreference();
#else
		Info.bHasWiFiConnection = Info.NetworkType == EAndroidNetworkType::WiFi;
#endif
		return Info;
	}

	FAndroidDisplayInfo BuildDisplayInfo()
	{
		FAndroidDisplayInfo Info;

		FDisplayMetrics DisplayMetrics;
		FDisplayMetrics::RebuildDisplayMetrics(DisplayMetrics);
		Info.ScreenWidth = DisplayMetrics.PrimaryDisplayWidth;
		Info.ScreenHeight = DisplayMetrics.PrimaryDisplayHeight;
		Info.ViewportWidth = DisplayMetrics.PrimaryDisplayWidth;
		Info.ViewportHeight = DisplayMetrics.PrimaryDisplayHeight;
		Info.DPIScale = FPlatformApplicationMisc::GetDPIScaleFactorAtPoint(0.f, 0.f);
		Info.EstimatedDPI = FMath::RoundToInt(160.f * Info.DPIScale);
		Info.Orientation = ConvertOrientation(FPlatformMisc::GetDeviceOrientation());

#if PLATFORM_ANDROID
		Info.NativeRefreshRate = FAndroidMisc::GetNativeDisplayRefreshRate();
		Info.SupportedRefreshRates = FAndroidMisc::GetSupportedNativeDisplayRefreshRates();
#endif

		return Info;
	}

	FAndroidCapabilityInfo BuildCapabilityInfo()
	{
		FAndroidCapabilityInfo Info;
#if PLATFORM_ANDROID
		Info.bIsSupportedDevice = FAndroidMisc::IsSupportedAndroidDevice();
		Info.bHasVulkanDriverSupport = FAndroidMisc::HasVulkanDriverSupport();
		Info.bIsVulkanAvailable = FAndroidMisc::IsVulkanAvailable();
		Info.bShouldUseVulkan = FAndroidMisc::ShouldUseVulkan();
		Info.bSupportsFloatingPointRenderTargets = FAndroidMisc::SupportsFloatingPointRenderTargets();
		Info.bSupportsShaderFramebufferFetch = FAndroidMisc::SupportsShaderFramebufferFetch();
		// UE 5.5 在 Android 头文件中声明了 SupportsShaderIOBlocks，但当前运行时未提供实现。
		// 这里使用保守回退值，避免 Android 链接阶段失败。
		Info.bSupportsShaderIOBlocks = false;
		Info.bSupportsBackbufferSampling = FAndroidMisc::SupportsBackbufferSampling();
		Info.bExpand16BitIndicesTo32BitOnLoad = FAndroidMisc::Expand16BitIndicesTo32BitOnLoad();
#endif
		return Info;
	}

	FAndroidHardwareSnapshot BuildHardwareSnapshotInternal()
	{
		FAndroidHardwareSnapshot Snapshot;
		Snapshot.CaptureTimeSeconds = FPlatformTime::Seconds();
		Snapshot.DeviceInfo = BuildDeviceInfo();
		Snapshot.AppInfo = BuildAppInfo();
		Snapshot.IdInfo = BuildIdInfo();
		Snapshot.CPUInfo = BuildCPUInfo();
		Snapshot.GPUInfo = BuildGPUInfo();
		Snapshot.GPUMemoryInfo = BuildGPUMemoryInfo();
		Snapshot.MemoryInfo = BuildMemoryInfo();
		Snapshot.InternalStorage = BuildStorageInfo(UBPFunctions_Android::GetAndroidInternalAppDir());
		Snapshot.ExternalStorage = BuildStorageInfo(UBPFunctions_Android::GetAndroidExternalAppDir());
		Snapshot.ProjectStorage = BuildStorageInfo(UBPFunctions_Android::GetAndroidExternalProjectDir());
		Snapshot.BatteryInfo = BuildBatteryInfo();
		Snapshot.NetworkInfo = BuildNetworkInfo();
		Snapshot.DisplayInfo = BuildDisplayInfo();
		Snapshot.CapabilityInfo = BuildCapabilityInfo();
		return Snapshot;
	}
}

void UBPFunctions_Android::GetAndroidDeviceInfo(FAndroidDeviceInfo& OutInfo)
{
	OutInfo = BuildDeviceInfo();
}

void UBPFunctions_Android::GetAndroidAppInfo(FAndroidAppInfo& OutInfo)
{
	OutInfo = BuildAppInfo();
}

void UBPFunctions_Android::GetAndroidIdInfo(FAndroidIdInfo& OutInfo)
{
	OutInfo = BuildIdInfo();
}

FString UBPFunctions_Android::GetDeviceBrand()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetDeviceMake();
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetDeviceModel()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetDeviceModel();
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetProductName()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetProductName();
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetDeviceBuildNumber()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetDeviceBuildNumber();
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetAndroidVersion()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetAndroidVersion();
#else
	return TEXT("");
#endif
}

int32 UBPFunctions_Android::GetAndroidMajorVersion()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetAndroidMajorVersion();
#else
	return 0;
#endif
}

int32 UBPFunctions_Android::GetAndroidBuildVersion()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetAndroidBuildVersion();
#else
	return 0;
#endif
}

FString UBPFunctions_Android::GetOSLanguage()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetOSLanguage();
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetDefaultLocale()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetDefaultLocale();
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetTimeZoneId()
{
	return FPlatformMisc::GetTimeZoneId();
}

FString UBPFunctions_Android::GetDeviceId()
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	return FAndroidMisc::GetDeviceId();
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetAndroidId()
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	return AndroidThunkCpp_GetAndroidId();
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetAdvertisingId()
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	return FAndroidMisc::GetUniqueAdvertisingId();
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetLoginId()
{
#if PLATFORM_ANDROID && USE_ANDROID_FILE
	return FAndroidMisc::GetLoginId();
#else
	return TEXT("");
#endif
}

bool UBPFunctions_Android::HasAdvertisingId()
{
	return !GetAdvertisingId().IsEmpty();
}

bool UBPFunctions_Android::CheckAndroidPermission(const FString& InPermission)
{
#if PLATFORM_ANDROID
	return UAndroidPermissionFunctionLibrary::CheckPermission(InPermission);
#else
	return false;
#endif
}

bool UBPFunctions_Android::CheckAndroidPermissions(const TArray<FString>& InPermissions, TArray<FString>& MissingPermissions)
{
	MissingPermissions.Reset();
	bool bAllGranted = true;
	for (const FString& Permission : InPermissions)
	{
		if (!CheckAndroidPermission(Permission))
		{
			bAllGranted = false;
			MissingPermissions.Add(Permission);
		}
	}
	return bAllGranted;
}

EAndroidPermissionState UBPFunctions_Android::GetAndroidPermissionState(const FString& InPermission)
{
	return CheckAndroidPermission(InPermission) ? EAndroidPermissionState::Granted : EAndroidPermissionState::Denied;
}

bool UBPFunctions_Android::CheckAndroidCommonPermission(const EAndroidCommonPermission InPermission)
{
	return CheckAndroidPermission(GetAndroidCommonPermissionString(InPermission));
}

FString UBPFunctions_Android::GetAndroidCommonPermissionString(const EAndroidCommonPermission InPermission)
{
	return ToPermissionString(InPermission);
}

void UBPFunctions_Android::GetAllAndroidCommonPermissionStrings(TArray<FString>& OutPermissions)
{
	OutPermissions.Reset();
	for (const EAndroidCommonPermission Permission : GetAllCommonPermissions())
	{
		OutPermissions.Add(ToPermissionString(Permission));
	}
}

FString UBPFunctions_Android::AndroidPermissionStateToString(const EAndroidPermissionState InState)
{
	return PermissionStateToStringInternal(InState);
}

FString UBPFunctions_Android::GetAndroidExternalRootDir()
{
#if PLATFORM_ANDROID
	return GExternalFilePath;
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetAndroidExternalProjectDir()
{
	return FPaths::ProjectDir();
}

FString UBPFunctions_Android::GetAndroidExternalConfigDir()
{
	return FPaths::ProjectConfigDir();
}

FString UBPFunctions_Android::GetAndroidExternalExtrasDir()
{
	return FPaths::Combine(FPaths::ProjectDir(), TEXT("Extras"));
}

FString UBPFunctions_Android::GetAndroidExternalSaveDir()
{
	return FPaths::ProjectSavedDir();
}

FString UBPFunctions_Android::GetAndroidInternalAppDir()
{
#if PLATFORM_ANDROID
	return GInternalFilePath;
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetAndroidExternalAppDir()
{
#if PLATFORM_ANDROID
	return GExternalFilePath;
#else
	return TEXT("");
#endif
}

FString UBPFunctions_Android::GetAndroidFilePathBase()
{
#if PLATFORM_ANDROID
	return GFilePathBase;
#else
	return TEXT("");
#endif
}

bool UBPFunctions_Android::HasAndroidPersistentDownloadDir()
{
	return FPaths::HasProjectPersistentDownloadDir();
}

FString UBPFunctions_Android::GetAndroidPersistentDownloadDir()
{
	return FPaths::HasProjectPersistentDownloadDir() ? FPaths::ProjectPersistentDownloadDir() : FString();
}

bool UBPFunctions_Android::GetStorageInfo(const FString& InPath, FAndroidStorageInfo& OutInfo)
{
	OutInfo = BuildStorageInfo(InPath);
	return OutInfo.bIsValid;
}

void UBPFunctions_Android::GetInternalStorageInfo(FAndroidStorageInfo& OutInfo)
{
	OutInfo = BuildStorageInfo(GetAndroidInternalAppDir());
}

void UBPFunctions_Android::GetExternalStorageInfo(FAndroidStorageInfo& OutInfo)
{
	OutInfo = BuildStorageInfo(GetAndroidExternalAppDir());
}

void UBPFunctions_Android::GetProjectStorageInfo(FAndroidStorageInfo& OutInfo)
{
	OutInfo = BuildStorageInfo(GetAndroidExternalProjectDir());
}

void UBPFunctions_Android::GetAllKnownStorageInfos(TArray<FAndroidStorageInfo>& OutInfos)
{
	OutInfos.Reset();

	const TArray<FString> Paths = {
		GetAndroidInternalAppDir(),
		GetAndroidExternalAppDir(),
		GetAndroidExternalProjectDir(),
		GetAndroidExternalSaveDir(),
		GetAndroidPersistentDownloadDir()
	};

	TSet<FString> UniquePaths;
	for (const FString& Path : Paths)
	{
		if (!Path.IsEmpty() && !UniquePaths.Contains(Path))
		{
			UniquePaths.Add(Path);
			OutInfos.Add(BuildStorageInfo(Path));
		}
	}
}

void UBPFunctions_Android::GetCPUHardwareInfo(FAndroidCPUInfo& OutInfo)
{
	OutInfo = BuildCPUInfo();
}

float UBPFunctions_Android::GetCPUAverageUsage()
{
	return BuildCPUInfo().AverageUsagePercent;
}

void UBPFunctions_Android::GetCPUCoreUsages(TArray<float>& OutUsages)
{
	OutUsages = BuildCPUInfo().PerCoreUsagePercent;
}

void UBPFunctions_Android::GetCPUCurrentFrequenciesMHz(TArray<int32>& OutFrequencies)
{
	OutFrequencies = BuildCPUInfo().CurrentFrequenciesMHz;
}

void UBPFunctions_Android::GetCPUMaxFrequenciesMHz(TArray<int32>& OutFrequencies)
{
	OutFrequencies = BuildCPUInfo().MaxFrequenciesMHz;
}

void UBPFunctions_Android::GetCPUMinFrequenciesMHz(TArray<int32>& OutFrequencies)
{
	OutFrequencies = BuildCPUInfo().MinFrequenciesMHz;
}

float UBPFunctions_Android::GetCPUTemperatureCelsius()
{
	return BuildCPUInfo().TemperatureCelsius;
}

void UBPFunctions_Android::GetGPUHardwareInfo(FAndroidGPUInfo& OutInfo)
{
	OutInfo = BuildGPUInfo();
}

void UBPFunctions_Android::GetGPUMemoryInfo(FAndroidGPUMemoryInfo& OutInfo)
{
	OutInfo = BuildGPUMemoryInfo();
}

float UBPFunctions_Android::GetGPUUsage()
{
	return BuildGPUInfo().UsagePercent;
}

FString UBPFunctions_Android::GetGPURHIName()
{
	return BuildGPUInfo().RHIName;
}

bool UBPFunctions_Android::IsUsingVulkan()
{
	return BuildGPUInfo().bShouldUseVulkan;
}

void UBPFunctions_Android::GetMemoryHardwareInfo(FAndroidMemoryInfo& OutInfo)
{
	OutInfo = BuildMemoryInfo();
}

bool UBPFunctions_Android::IsLowMemoryDevice()
{
	return BuildMemoryInfo().bLowMemory;
}

EAndroidMemoryPressureLevel UBPFunctions_Android::GetMemoryPressureLevel()
{
	return BuildMemoryInfo().PressureLevel;
}

void UBPFunctions_Android::GetBatteryInfo(FAndroidBatteryInfo& OutInfo)
{
	OutInfo = BuildBatteryInfo();
}

FString UBPFunctions_Android::GetBatteryStateString(const EAndroidBatteryState InState)
{
	return BatteryStateToStringInternal(InState);
}

void UBPFunctions_Android::GetNetworkInfo(FAndroidNetworkInfo& OutInfo)
{
	OutInfo = BuildNetworkInfo();
}

FString UBPFunctions_Android::GetNetworkTypeString(const EAndroidNetworkType InType)
{
	return NetworkTypeToStringInternal(InType);
}

void UBPFunctions_Android::GetDisplayInfo(FAndroidDisplayInfo& OutInfo)
{
	OutInfo = BuildDisplayInfo();
}

FString UBPFunctions_Android::GetOrientationString(const EAndroidScreenOrientationType InOrientation)
{
	return OrientationToStringInternal(InOrientation);
}

void UBPFunctions_Android::GetCapabilityInfo(FAndroidCapabilityInfo& OutInfo)
{
	OutInfo = BuildCapabilityInfo();
}

bool UBPFunctions_Android::IsSupportedAndroidDevice()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::IsSupportedAndroidDevice();
#else
	return false;
#endif
}

bool UBPFunctions_Android::HasVulkanDriverSupport()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::HasVulkanDriverSupport();
#else
	return false;
#endif
}

bool UBPFunctions_Android::IsVulkanAvailable()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::IsVulkanAvailable();
#else
	return false;
#endif
}

bool UBPFunctions_Android::ShouldUseVulkan()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::ShouldUseVulkan();
#else
	return false;
#endif
}

bool UBPFunctions_Android::SupportsFloatingPointRenderTargets()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::SupportsFloatingPointRenderTargets();
#else
	return false;
#endif
}

bool UBPFunctions_Android::SupportsShaderFramebufferFetch()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::SupportsShaderFramebufferFetch();
#else
	return false;
#endif
}

bool UBPFunctions_Android::SupportsShaderIOBlocks()
{
#if PLATFORM_ANDROID
	// UE 5.5 Android 运行时缺少该符号实现，统一返回保守回退值。
	return false;
#else
	return false;
#endif
}

bool UBPFunctions_Android::AreHeadphonesConnected()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::AreHeadPhonesPluggedIn();
#else
	return false;
#endif
}

int32 UBPFunctions_Android::GetCurrentVolumeStep()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::GetVolumeState();
#else
	return -1;
#endif
}

int32 UBPFunctions_Android::GetCurrentVolumePercent()
{
	return FPlatformMisc::GetDeviceVolume();
}

bool UBPFunctions_Android::GetVolumeButtonsHandledBySystem()
{
	return FPlatformMisc::GetVolumeButtonsHandledBySystem();
}

void UBPFunctions_Android::SetVolumeButtonsHandledBySystem(const bool bEnabled)
{
	FPlatformMisc::SetVolumeButtonsHandledBySystem(bEnabled);
}

bool UBPFunctions_Android::IsMusicActive()
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_IsMusicActive();
#else
	return false;
#endif
}

bool UBPFunctions_Android::IsScreensaverEnabled()
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_IsScreensaverEnabled();
#else
	return false;
#endif
}

bool UBPFunctions_Android::IsGamepadAttached()
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_IsGamepadAttached();
#else
	return false;
#endif
}

bool UBPFunctions_Android::GetInputDeviceInfo(const int32 InDeviceId, FAndroidInputDeviceInfoData& OutInfo)
{
	OutInfo = FAndroidInputDeviceInfoData();

#if PLATFORM_ANDROID
	FAndroidInputDeviceInfo DeviceInfo;
	if (AndroidThunkCpp_GetInputDeviceInfo(InDeviceId, DeviceInfo))
	{
		OutInfo.DeviceId = DeviceInfo.DeviceId;
		OutInfo.VendorId = DeviceInfo.VendorId;
		OutInfo.ProductId = DeviceInfo.ProductId;
		OutInfo.ControllerId = DeviceInfo.ControllerId;
		OutInfo.Name = DeviceInfo.Name;
		OutInfo.Descriptor = DeviceInfo.Descriptor;
		OutInfo.FeedbackMotorCount = DeviceInfo.FeedbackMotorCount;
		return true;
	}
#endif

	return false;
}

bool UBPFunctions_Android::SetInputDeviceVibration(const int32 InDeviceId, const int32 LeftIntensity, const int32 LeftDurationMs, const int32 RightIntensity, const int32 RightDurationMs)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_SetInputDeviceVibrators(InDeviceId, LeftIntensity, LeftDurationMs, RightIntensity, RightDurationMs);
#else
	return false;
#endif
}

void UBPFunctions_Android::TriggerSimpleVibration(const int32 Intensity, const int32 DurationMs)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_Vibrate(Intensity, DurationMs);
#endif
}

void UBPFunctions_Android::TriggerHaptic(const EAndroidHapticType InHapticType)
{
	FPlatformMisc::PrepareMobileHaptics(ConvertHapticType(InHapticType));
	FPlatformMisc::TriggerMobileHaptics();
	FPlatformMisc::ReleaseMobileHaptics();
}

bool UBPFunctions_Android::IsIMUSamplingEnabled()
{
	return GetAndroidRuntimeBool(TEXT("bAllowIMU"));
}

bool UBPFunctions_Android::GetInputMotionState(UObject* WorldContextObject, FVector& Tilt, FVector& RotationRate, FVector& Gravity, FVector& Acceleration)
{
	Tilt = FVector::ZeroVector;
	RotationRate = FVector::ZeroVector;
	Gravity = FVector::ZeroVector;
	Acceleration = FVector::ZeroVector;

	if (WorldContextObject == nullptr)
	{
		return false;
	}

	UWorld* World = WorldContextObject->GetWorld();
	if (World == nullptr)
	{
		return false;
	}

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (PlayerController == nullptr)
	{
		return false;
	}

	PlayerController->GetInputMotionState(Tilt, RotationRate, Gravity, Acceleration);
	return true;
}

void UBPFunctions_Android::SetClipboardText(const FString& InText)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_ClipboardCopy(InText);
#else
	FPlatformApplicationMisc::ClipboardCopy(*InText);
#endif
}

FString UBPFunctions_Android::GetClipboardText()
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_ClipboardPaste();
#else
	FString ClipboardText;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardText);
	return ClipboardText;
#endif
}

void UBPFunctions_Android::RegisterForRemoteNotifications()
{
	FPlatformMisc::RegisterForRemoteNotifications();
}

void UBPFunctions_Android::UnregisterForRemoteNotifications()
{
	FPlatformMisc::UnregisterForRemoteNotifications();
}

bool UBPFunctions_Android::IsAllowedRemoteNotifications()
{
#if PLATFORM_ANDROID
	return FAndroidMisc::IsAllowedRemoteNotifications();
#else
	return false;
#endif
}

void UBPFunctions_Android::ClearAllLocalNotifications()
{
	UBlueprintPlatformLibrary::ClearAllLocalNotifications();
}

int32 UBPFunctions_Android::ScheduleLocalNotificationAtTime(const FDateTime& FireDateTime, const bool bUseLocalTime, const FText& Title, const FText& Body, const FText& Action, const FString& ActivationEvent)
{
	return UBlueprintPlatformLibrary::ScheduleLocalNotificationAtTime(FireDateTime, bUseLocalTime, Title, Body, Action, ActivationEvent);
}

int32 UBPFunctions_Android::ScheduleLocalNotificationFromNow(const int32 InSecondsFromNow, const FText& Title, const FText& Body, const FText& Action, const FString& ActivationEvent)
{
	return UBlueprintPlatformLibrary::ScheduleLocalNotificationFromNow(InSecondsFromNow, Title, Body, Action, ActivationEvent);
}

int32 UBPFunctions_Android::ScheduleLocalNotificationBadgeAtTime(const FDateTime& FireDateTime, const bool bUseLocalTime, const FString& ActivationEvent)
{
	return UBlueprintPlatformLibrary::ScheduleLocalNotificationBadgeAtTime(FireDateTime, bUseLocalTime, ActivationEvent);
}

void UBPFunctions_Android::ScheduleLocalNotificationBadgeFromNow(const int32 InSecondsFromNow, const FString& ActivationEvent)
{
	UBlueprintPlatformLibrary::ScheduleLocalNotificationBadgeFromNow(InSecondsFromNow, ActivationEvent);
}

void UBPFunctions_Android::CancelLocalNotification(const FString& ActivationEvent)
{
	UBlueprintPlatformLibrary::CancelLocalNotification(ActivationEvent);
}

void UBPFunctions_Android::CancelLocalNotificationById(const int32 NotificationId)
{
	UBlueprintPlatformLibrary::CancelLocalNotificationById(NotificationId);
}

void UBPFunctions_Android::GetLaunchNotification(bool& bNotificationLaunchedApp, FString& ActivationEvent, int32& FireDate)
{
	UBlueprintPlatformLibrary::GetLaunchNotification(bNotificationLaunchedApp, ActivationEvent, FireDate);
}

bool UBPFunctions_Android::CanLaunchUrl(const FString& InUrl)
{
	return FPlatformProcess::CanLaunchURL(*InUrl);
}

bool UBPFunctions_Android::LaunchUrl(const FString& InUrl)
{
	FString Error;
	FPlatformProcess::LaunchURL(*InUrl, nullptr, &Error);
	return Error.IsEmpty();
}

bool UBPFunctions_Android::IsPackageInstalled(const FString& InPackageName)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_IsPackageInstalled(InPackageName);
#else
	return false;
#endif
}

bool UBPFunctions_Android::LaunchPackage(const FString& InPackageName, const FString& InExtraKey, const FString& InExtraValue)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_LaunchPackage(InPackageName, InExtraKey, InExtraValue);
#else
	return false;
#endif
}

bool UBPFunctions_Android::SendBroadcast(const FString& InPackageName, const FString& InExtraKey, const FString& InExtraValue, const bool bExitApplication)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_SendBroadcast(InPackageName, InExtraKey, InExtraValue, bExitApplication);
#else
	return false;
#endif
}

bool UBPFunctions_Android::HasManifestMetaDataKey(const FString& InKey)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_HasMetaDataKey(InKey);
#else
	return false;
#endif
}

bool UBPFunctions_Android::GetManifestMetaDataBoolean(const FString& InKey)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_GetMetaDataBoolean(InKey);
#else
	return false;
#endif
}

int32 UBPFunctions_Android::GetManifestMetaDataInt(const FString& InKey)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_GetMetaDataInt(InKey);
#else
	return 0;
#endif
}

int64 UBPFunctions_Android::GetManifestMetaDataLong(const FString& InKey)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_GetMetaDataLong(InKey);
#else
	return 0;
#endif
}

float UBPFunctions_Android::GetManifestMetaDataFloat(const FString& InKey)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_GetMetaDataFloat(InKey);
#else
	return 0.f;
#endif
}

FString UBPFunctions_Android::GetManifestMetaDataString(const FString& InKey)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_GetMetaDataString(InKey);
#else
	return TEXT("");
#endif
}

bool UBPFunctions_Android::HasSharedPreference(const FString& InGroup, const FString& InKey)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_HasSharedPreference(InGroup, InKey);
#else
	return false;
#endif
}

void UBPFunctions_Android::SetSharedPreferenceBool(const FString& InGroup, const FString& InKey, const bool bValue)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_SetSharedPreferenceBool(InGroup, InKey, bValue);
#endif
}

bool UBPFunctions_Android::GetSharedPreferenceBool(const FString& InGroup, const FString& InKey, const bool bDefaultValue)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_GetSharedPreferenceBool(InGroup, InKey, bDefaultValue);
#else
	return bDefaultValue;
#endif
}

void UBPFunctions_Android::SetSharedPreferenceInt(const FString& InGroup, const FString& InKey, const int32 InValue)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_SetSharedPreferenceInt(InGroup, InKey, InValue);
#endif
}

int32 UBPFunctions_Android::GetSharedPreferenceInt(const FString& InGroup, const FString& InKey, const int32 InDefaultValue)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_GetSharedPreferenceInt(InGroup, InKey, InDefaultValue);
#else
	return InDefaultValue;
#endif
}

void UBPFunctions_Android::SetSharedPreferenceString(const FString& InGroup, const FString& InKey, const FString& InValue)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_SetSharedPreferenceString(InGroup, InKey, InValue);
#endif
}

FString UBPFunctions_Android::GetSharedPreferenceString(const FString& InGroup, const FString& InKey, const FString& InDefaultValue)
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_GetSharedPreferenceString(InGroup, InKey, InDefaultValue);
#else
	return InDefaultValue;
#endif
}

void UBPFunctions_Android::DeleteSharedPreference(const FString& InGroup, const FString& InKey)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_DeleteSharedPreference(InGroup, InKey);
#endif
}

void UBPFunctions_Android::DeleteSharedPreferenceGroup(const FString& InGroup)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_DeleteSharedPreferenceGroup(InGroup);
#endif
}

void UBPFunctions_Android::SetKeepScreenOn(const bool bEnable)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_KeepScreenOn(bEnable);
#endif
}

bool UBPFunctions_Android::IsScreenCaptureDisabled()
{
#if PLATFORM_ANDROID
	return AndroidThunkCpp_IsScreenCaptureDisabled();
#else
	return false;
#endif
}

void UBPFunctions_Android::SetScreenCaptureDisabled(const bool bDisable)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_DisableScreenCapture(bDisable);
#endif
}

void UBPFunctions_Android::RequestMinimizeApplication()
{
	FPlatformApplicationMisc::RequestMinimize();
}

bool UBPFunctions_Android::RestartApplication()
{
	return FPlatformMisc::RestartApplication();
}

void UBPFunctions_Android::RestartApplicationWithIntent(const FString& InIntentString)
{
#if PLATFORM_ANDROID
	AndroidThunkCpp_RestartApplication(InIntentString);
#else
	FPlatformMisc::RestartApplication();
#endif
}

void UBPFunctions_Android::GetSystemFontBytes(TArray<uint8>& OutBytes)
{
	OutBytes = FPlatformMisc::GetSystemFontBytes();
}

void UBPFunctions_Android::GetHardwareSnapshot(FAndroidHardwareSnapshot& OutSnapshot)
{
	OutSnapshot = BuildHardwareSnapshotInternal();
}

FString UBPFunctions_Android::GetAndroidDebugReport()
{
	const FAndroidHardwareSnapshot Snapshot = BuildHardwareSnapshotInternal();

	FString Report;
	Report += FString::Printf(TEXT("Android Version: %s\n"), *Snapshot.DeviceInfo.AndroidVersion);
	Report += FString::Printf(TEXT("Brand/Model: %s / %s\n"), *Snapshot.DeviceInfo.Brand, *Snapshot.DeviceInfo.Model);
	Report += FString::Printf(TEXT("Product: %s\n"), *Snapshot.DeviceInfo.ProductName);
	Report += FString::Printf(TEXT("Build Number: %s\n"), *Snapshot.DeviceInfo.DeviceBuildNumber);
	Report += FString::Printf(TEXT("Package: %s\n"), *Snapshot.AppInfo.PackageName);
	Report += FString::Printf(TEXT("Version Name: %s\n"), *Snapshot.AppInfo.VersionDisplayName);
	Report += FString::Printf(TEXT("SDK: min=%d target=%d api=%d\n"), Snapshot.AppInfo.MinSDKVersion, Snapshot.AppInfo.TargetSDKVersion, Snapshot.DeviceInfo.AndroidBuildVersion);
	Report += FString::Printf(TEXT("Locale: %s | Language: %s | TimeZone: %s\n"), *Snapshot.DeviceInfo.DefaultLocale, *Snapshot.DeviceInfo.OSLanguage, *Snapshot.DeviceInfo.TimeZoneId);
	Report += FString::Printf(TEXT("CPU: %s | %s | Cores=%d/%d | AvgUsage=%.2f%% | Temp=%.2fC\n"), *Snapshot.CPUInfo.Vendor, *Snapshot.CPUInfo.Brand, Snapshot.CPUInfo.PhysicalCores, Snapshot.CPUInfo.LogicalCores, Snapshot.CPUInfo.AverageUsagePercent, Snapshot.CPUInfo.TemperatureCelsius);
	Report += FString::Printf(TEXT("GPU: %s | Family=%s | Renderer=%s | RHI=%s | Usage=%.2f%%\n"), *Snapshot.GPUInfo.Brand, *Snapshot.GPUInfo.GPUFamily, *Snapshot.GPUInfo.Renderer, *Snapshot.GPUInfo.RHIName, Snapshot.GPUInfo.UsagePercent);
	Report += FString::Printf(TEXT("Memory: Total=%lld | Available=%lld | Used=%lld | Pressure=%d\n"), Snapshot.MemoryInfo.TotalPhysicalBytes, Snapshot.MemoryInfo.AvailablePhysicalBytes, Snapshot.MemoryInfo.SystemUsedPhysicalBytes, static_cast<int32>(Snapshot.MemoryInfo.PressureLevel));
	Report += FString::Printf(TEXT("Storage Internal: Path=%s | Free=%lld | Total=%lld\n"), *Snapshot.InternalStorage.Path, Snapshot.InternalStorage.FreeBytes, Snapshot.InternalStorage.TotalBytes);
	Report += FString::Printf(TEXT("Storage External: Path=%s | Free=%lld | Total=%lld\n"), *Snapshot.ExternalStorage.Path, Snapshot.ExternalStorage.FreeBytes, Snapshot.ExternalStorage.TotalBytes);
	Report += FString::Printf(TEXT("Battery: State=%s | Level=%d | Temp=%.2fC | LowPower=%s\n"), *BatteryStateToStringInternal(Snapshot.BatteryInfo.State), Snapshot.BatteryInfo.Level, Snapshot.BatteryInfo.TemperatureCelsius, Snapshot.BatteryInfo.bLowPowerMode ? TEXT("true") : TEXT("false"));
	Report += FString::Printf(TEXT("Network: %s | WiFi=%s | CellularPreference=%d\n"), *NetworkTypeToStringInternal(Snapshot.NetworkInfo.NetworkType), Snapshot.NetworkInfo.bHasWiFiConnection ? TEXT("true") : TEXT("false"), Snapshot.NetworkInfo.CellularPreference);
	Report += FString::Printf(TEXT("Display: %dx%d | DPI=%d | Refresh=%d | Orientation=%s\n"), Snapshot.DisplayInfo.ScreenWidth, Snapshot.DisplayInfo.ScreenHeight, Snapshot.DisplayInfo.EstimatedDPI, Snapshot.DisplayInfo.NativeRefreshRate, *OrientationToStringInternal(Snapshot.DisplayInfo.Orientation));
	Report += FString::Printf(TEXT("Capabilities: Supported=%s VulkanDriver=%s VulkanAvailable=%s UsingVulkan=%s FP16RT=%s FramebufferFetch=%s\n"),
		Snapshot.CapabilityInfo.bIsSupportedDevice ? TEXT("true") : TEXT("false"),
		Snapshot.CapabilityInfo.bHasVulkanDriverSupport ? TEXT("true") : TEXT("false"),
		Snapshot.CapabilityInfo.bIsVulkanAvailable ? TEXT("true") : TEXT("false"),
		Snapshot.CapabilityInfo.bShouldUseVulkan ? TEXT("true") : TEXT("false"),
		Snapshot.CapabilityInfo.bSupportsFloatingPointRenderTargets ? TEXT("true") : TEXT("false"),
		Snapshot.CapabilityInfo.bSupportsShaderFramebufferFetch ? TEXT("true") : TEXT("false"));

	return Report;
}
