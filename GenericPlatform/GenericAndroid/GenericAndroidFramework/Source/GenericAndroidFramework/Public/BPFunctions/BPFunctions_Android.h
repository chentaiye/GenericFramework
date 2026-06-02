#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Type/AndroidType.h"
#include "BPFunctions_Android.generated.h"

/** 提供Android蓝图函数。 */
UCLASS(MinimalAPI)
class UBPFunctions_Android : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 获取Android设备信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API void GetAndroidDeviceInfo(FAndroidDeviceInfo& OutInfo);

	/** 获取Android应用信息。 */
	UFUNCTION(BlueprintPure, Category="Android|App|Info")
	static GENERICANDROIDFRAMEWORK_API void GetAndroidAppInfo(FAndroidAppInfo& OutInfo);

	/** 获取Android ID信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Identifiers")
	static GENERICANDROIDFRAMEWORK_API void GetAndroidIdInfo(FAndroidIdInfo& OutInfo);

	/** 获取设备品牌。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API FString GetDeviceBrand();

	/** 获取设备模型。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API FString GetDeviceModel();

	/** 获取产品名称。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API FString GetProductName();

	/** 获取设备构建号。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API FString GetDeviceBuildNumber();

	/** 获取Android 版本。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidVersion();

	/** 获取Android 主版本。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API int32 GetAndroidMajorVersion();

	/** 获取Android 构建版本。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API int32 GetAndroidBuildVersion();

	/** 获取系统语言。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API FString GetOSLanguage();

	/** 获取默认区域设置。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API FString GetDefaultLocale();

	/** 获取时间Zone ID。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Basic")
	static GENERICANDROIDFRAMEWORK_API FString GetTimeZoneId();

	/** 获取设备 ID。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Identifiers")
	static GENERICANDROIDFRAMEWORK_API FString GetDeviceId();

	/** 获取Android ID。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Identifiers")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidId();

	/** 获取广告 ID。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Identifiers")
	static GENERICANDROIDFRAMEWORK_API FString GetAdvertisingId();

	/** 获取登录 ID。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Identifiers")
	static GENERICANDROIDFRAMEWORK_API FString GetLoginId();

	/** 判断是否包含广告 ID。 */
	UFUNCTION(BlueprintPure, Category="Android|Device|Identifiers")
	static GENERICANDROIDFRAMEWORK_API bool HasAdvertisingId();

public:
	/** 检查Android权限。 */
	UFUNCTION(BlueprintPure, Category="Android|Permissions|Query")
	static GENERICANDROIDFRAMEWORK_API bool CheckAndroidPermission(const FString& InPermission);

	/** 检查Android Permissions。 */
	UFUNCTION(BlueprintPure, Category="Android|Permissions|Query")
	static GENERICANDROIDFRAMEWORK_API bool CheckAndroidPermissions(const TArray<FString>& InPermissions, TArray<FString>& MissingPermissions);

	/** 获取Android权限状态。 */
	UFUNCTION(BlueprintPure, Category="Android|Permissions|Query")
	static GENERICANDROIDFRAMEWORK_API EAndroidPermissionState GetAndroidPermissionState(const FString& InPermission);

	/** 检查Android Common权限。 */
	UFUNCTION(BlueprintPure, Category="Android|Permissions|Constants")
	static GENERICANDROIDFRAMEWORK_API bool CheckAndroidCommonPermission(EAndroidCommonPermission InPermission);

	/** 获取Android Common权限字符串。 */
	UFUNCTION(BlueprintPure, Category="Android|Permissions|Constants")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidCommonPermissionString(EAndroidCommonPermission InPermission);

	/** 获取全部Android Common权限Strings。 */
	UFUNCTION(BlueprintPure, Category="Android|Permissions|Constants")
	static GENERICANDROIDFRAMEWORK_API void GetAllAndroidCommonPermissionStrings(TArray<FString>& OutPermissions);

	/** 处理Android权限状态To字符串。 */
	UFUNCTION(BlueprintPure, Category="Android|Permissions|Constants")
	static GENERICANDROIDFRAMEWORK_API FString AndroidPermissionStateToString(EAndroidPermissionState InState);

public:
	/** 获取Android外部Root目录。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Paths")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidExternalRootDir();

	/** 获取Android外部项目目录。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Paths")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidExternalProjectDir();

	/** 获取Android外部配置目录。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Paths")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidExternalConfigDir();

	/** 获取Android外部Extras目录。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Paths")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidExternalExtrasDir();

	/** 获取Android外部保存目录。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Paths")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidExternalSaveDir();

	/** 获取Android内部应用目录。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Paths")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidInternalAppDir();

	/** 获取Android外部应用目录。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Paths")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidExternalAppDir();

	/** 获取Android文件路径基础。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Paths")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidFilePathBase();

	/** 判断是否包含Android Persistent Download目录。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Paths")
	static GENERICANDROIDFRAMEWORK_API bool HasAndroidPersistentDownloadDir();

	/** 获取Android Persistent Download目录。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Paths")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidPersistentDownloadDir();

	/** 获取Storage信息。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Storage")
	static GENERICANDROIDFRAMEWORK_API bool GetStorageInfo(const FString& InPath, FAndroidStorageInfo& OutInfo);

	/** 获取内部Storage信息。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Storage")
	static GENERICANDROIDFRAMEWORK_API void GetInternalStorageInfo(FAndroidStorageInfo& OutInfo);

	/** 获取外部Storage信息。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Storage")
	static GENERICANDROIDFRAMEWORK_API void GetExternalStorageInfo(FAndroidStorageInfo& OutInfo);

	/** 获取项目Storage信息。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Storage")
	static GENERICANDROIDFRAMEWORK_API void GetProjectStorageInfo(FAndroidStorageInfo& OutInfo);

	/** 获取全部Known Storage Infos。 */
	UFUNCTION(BlueprintPure, Category="Android|FileSystem|Storage")
	static GENERICANDROIDFRAMEWORK_API void GetAllKnownStorageInfos(TArray<FAndroidStorageInfo>& OutInfos);

public:
	/** 获取CPU硬件信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|CPU")
	static GENERICANDROIDFRAMEWORK_API void GetCPUHardwareInfo(FAndroidCPUInfo& OutInfo);

	/** 获取CPU平均使用率。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|CPU")
	static GENERICANDROIDFRAMEWORK_API float GetCPUAverageUsage();

	/** 获取CPU核心Usages。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|CPU")
	static GENERICANDROIDFRAMEWORK_API void GetCPUCoreUsages(TArray<float>& OutUsages);

	/** 获取CPU当前Frequencies模式Hz。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|CPU")
	static GENERICANDROIDFRAMEWORK_API void GetCPUCurrentFrequenciesMHz(TArray<int32>& OutFrequencies);

	/** 获取CPU最大Frequencies模式Hz。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|CPU")
	static GENERICANDROIDFRAMEWORK_API void GetCPUMaxFrequenciesMHz(TArray<int32>& OutFrequencies);

	/** 获取CPU最小Frequencies模式Hz。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|CPU")
	static GENERICANDROIDFRAMEWORK_API void GetCPUMinFrequenciesMHz(TArray<int32>& OutFrequencies);

	/** 获取CPU温度摄氏度。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|CPU")
	static GENERICANDROIDFRAMEWORK_API float GetCPUTemperatureCelsius();

	/** 获取GPU硬件信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|GPU")
	static GENERICANDROIDFRAMEWORK_API void GetGPUHardwareInfo(FAndroidGPUInfo& OutInfo);

	/** 获取GPU内存信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|GPU")
	static GENERICANDROIDFRAMEWORK_API void GetGPUMemoryInfo(FAndroidGPUMemoryInfo& OutInfo);

	/** 获取GPU使用率。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|GPU")
	static GENERICANDROIDFRAMEWORK_API float GetGPUUsage();

	/** 获取GPURHI名称。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|GPU")
	static GENERICANDROIDFRAMEWORK_API FString GetGPURHIName();

	/** 判断Using Vulkan是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|GPU")
	static GENERICANDROIDFRAMEWORK_API bool IsUsingVulkan();

	/** 获取内存硬件信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|Memory")
	static GENERICANDROIDFRAMEWORK_API void GetMemoryHardwareInfo(FAndroidMemoryInfo& OutInfo);

	/** 判断Low内存设备是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|Memory")
	static GENERICANDROIDFRAMEWORK_API bool IsLowMemoryDevice();

	/** 获取内存Pressure关卡。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|Memory")
	static GENERICANDROIDFRAMEWORK_API EAndroidMemoryPressureLevel GetMemoryPressureLevel();

	/** 获取电池信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|Battery")
	static GENERICANDROIDFRAMEWORK_API void GetBatteryInfo(FAndroidBatteryInfo& OutInfo);

	/** 获取电池状态字符串。 */
	UFUNCTION(BlueprintPure, Category="Android|Hardware|Battery")
	static GENERICANDROIDFRAMEWORK_API FString GetBatteryStateString(EAndroidBatteryState InState);

public:
	/** 获取网络信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Network|Status")
	static GENERICANDROIDFRAMEWORK_API void GetNetworkInfo(FAndroidNetworkInfo& OutInfo);

	/** 获取网络类型字符串。 */
	UFUNCTION(BlueprintPure, Category="Android|Network|Status")
	static GENERICANDROIDFRAMEWORK_API FString GetNetworkTypeString(EAndroidNetworkType InType);

	/** 获取显示信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Display|Basic")
	static GENERICANDROIDFRAMEWORK_API void GetDisplayInfo(FAndroidDisplayInfo& OutInfo);

	/** 获取方向字符串。 */
	UFUNCTION(BlueprintPure, Category="Android|Display|Basic")
	static GENERICANDROIDFRAMEWORK_API FString GetOrientationString(EAndroidScreenOrientationType InOrientation);

public:
	/** 获取Capability信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Capabilities|Query")
	static GENERICANDROIDFRAMEWORK_API void GetCapabilityInfo(FAndroidCapabilityInfo& OutInfo);

	/** 判断支持Android设备是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|Capabilities|Query")
	static GENERICANDROIDFRAMEWORK_API bool IsSupportedAndroidDevice();

	/** 判断是否包含Vulkan驱动支持。 */
	UFUNCTION(BlueprintPure, Category="Android|Capabilities|Query")
	static GENERICANDROIDFRAMEWORK_API bool HasVulkanDriverSupport();

	/** 判断Vulkan可用是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|Capabilities|Query")
	static GENERICANDROIDFRAMEWORK_API bool IsVulkanAvailable();

	/** 判断是否需要Use Vulkan。 */
	UFUNCTION(BlueprintPure, Category="Android|Capabilities|Query")
	static GENERICANDROIDFRAMEWORK_API bool ShouldUseVulkan();

	/** 处理Supports Floating Point渲染Targets。 */
	UFUNCTION(BlueprintPure, Category="Android|Capabilities|Graphics")
	static GENERICANDROIDFRAMEWORK_API bool SupportsFloatingPointRenderTargets();

	/** 处理Supports Shader Framebuffer Fetch。 */
	UFUNCTION(BlueprintPure, Category="Android|Capabilities|Graphics")
	static GENERICANDROIDFRAMEWORK_API bool SupportsShaderFramebufferFetch();

	/** 处理Supports Shader IO区块。 */
	UFUNCTION(BlueprintPure, Category="Android|Capabilities|Graphics")
	static GENERICANDROIDFRAMEWORK_API bool SupportsShaderIOBlocks();

public:
	/** 处理Are Headphones Connected。 */
	UFUNCTION(BlueprintPure, Category="Android|Audio|Devices")
	static GENERICANDROIDFRAMEWORK_API bool AreHeadphonesConnected();

	/** 获取当前Volume Step。 */
	UFUNCTION(BlueprintPure, Category="Android|Audio|Volume")
	static GENERICANDROIDFRAMEWORK_API int32 GetCurrentVolumeStep();

	/** 获取当前Volume百分比。 */
	UFUNCTION(BlueprintPure, Category="Android|Audio|Volume")
	static GENERICANDROIDFRAMEWORK_API int32 GetCurrentVolumePercent();

	/** 获取Volume Buttons Handled按系统。 */
	UFUNCTION(BlueprintPure, Category="Android|Audio|Volume")
	static GENERICANDROIDFRAMEWORK_API bool GetVolumeButtonsHandledBySystem();

	/** 设置Volume Buttons Handled按系统。 */
	UFUNCTION(BlueprintCallable, Category="Android|Audio|Volume")
	static GENERICANDROIDFRAMEWORK_API void SetVolumeButtonsHandledBySystem(bool bEnabled);

	/** 判断Music激活是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|Audio|Status")
	static GENERICANDROIDFRAMEWORK_API bool IsMusicActive();

	/** 判断Screensaver已启用是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|Audio|Status")
	static GENERICANDROIDFRAMEWORK_API bool IsScreensaverEnabled();

	/** 判断Gamepad Attached是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|Input|Devices")
	static GENERICANDROIDFRAMEWORK_API bool IsGamepadAttached();

	/** 获取输入设备信息。 */
	UFUNCTION(BlueprintPure, Category="Android|Input|Devices")
	static GENERICANDROIDFRAMEWORK_API bool GetInputDeviceInfo(int32 InDeviceId, FAndroidInputDeviceInfoData& OutInfo);

	/** 设置输入设备Vibration。 */
	UFUNCTION(BlueprintCallable, Category="Android|Input|Haptics")
	static GENERICANDROIDFRAMEWORK_API bool SetInputDeviceVibration(int32 InDeviceId, int32 LeftIntensity, int32 LeftDurationMs, int32 RightIntensity, int32 RightDurationMs);

	/** 处理Trigger Simple Vibration。 */
	UFUNCTION(BlueprintCallable, Category="Android|Input|Haptics")
	static GENERICANDROIDFRAMEWORK_API void TriggerSimpleVibration(int32 Intensity, int32 DurationMs);

	/** 处理Trigger Haptic。 */
	UFUNCTION(BlueprintCallable, Category="Android|Input|Haptics")
	static GENERICANDROIDFRAMEWORK_API void TriggerHaptic(EAndroidHapticType InHapticType);

	/** 判断MU Sampling已启用是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|Input|Sensors")
	static GENERICANDROIDFRAMEWORK_API bool IsIMUSamplingEnabled();

	/** 获取输入Motion状态。 */
	UFUNCTION(BlueprintPure, Category="Android|Input|Sensors", meta=(WorldContext="WorldContextObject"))
	static GENERICANDROIDFRAMEWORK_API bool GetInputMotionState(UObject* WorldContextObject, FVector& Tilt, FVector& RotationRate, FVector& Gravity, FVector& Acceleration);

public:
	/** 设置Clipboard文本。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Clipboard")
	static GENERICANDROIDFRAMEWORK_API void SetClipboardText(const FString& InText);

	/** 获取Clipboard文本。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Clipboard")
	static GENERICANDROIDFRAMEWORK_API FString GetClipboardText();

	/** 注册用于Remote Notifications。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API void RegisterForRemoteNotifications();

	/** 取消注册用于Remote Notifications。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API void UnregisterForRemoteNotifications();

	/** 判断Allowed Remote Notifications是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API bool IsAllowedRemoteNotifications();

	/** 处理Clear全部本地Notifications。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API void ClearAllLocalNotifications();

	/** 处理Schedule本地Notification At时间。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API int32 ScheduleLocalNotificationAtTime(const FDateTime& FireDateTime, bool bUseLocalTime, const FText& Title, const FText& Body, const FText& Action, const FString& ActivationEvent);

	/** 处理Schedule本地Notification From Now。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API int32 ScheduleLocalNotificationFromNow(int32 InSecondsFromNow, const FText& Title, const FText& Body, const FText& Action, const FString& ActivationEvent);

	/** 处理Schedule本地Notification Badge At时间。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API int32 ScheduleLocalNotificationBadgeAtTime(const FDateTime& FireDateTime, bool bUseLocalTime, const FString& ActivationEvent);

	/** 处理Schedule本地Notification Badge From Now。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API void ScheduleLocalNotificationBadgeFromNow(int32 InSecondsFromNow, const FString& ActivationEvent);

	/** 判断是否可以cel本地Notification。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API void CancelLocalNotification(const FString& ActivationEvent);

	/** 判断是否可以cel本地Notification按ID。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API void CancelLocalNotificationById(int32 NotificationId);

	/** 获取启动Notification。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Notifications")
	static GENERICANDROIDFRAMEWORK_API void GetLaunchNotification(bool& bNotificationLaunchedApp, FString& ActivationEvent, int32& FireDate);

	/** 判断是否可以启动URL。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Intent")
	static GENERICANDROIDFRAMEWORK_API bool CanLaunchUrl(const FString& InUrl);

	/** 处理启动URL。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Intent")
	static GENERICANDROIDFRAMEWORK_API bool LaunchUrl(const FString& InUrl);

	/** 判断Package Installed是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Intent")
	static GENERICANDROIDFRAMEWORK_API bool IsPackageInstalled(const FString& InPackageName);

	/** 处理启动Package。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Intent")
	static GENERICANDROIDFRAMEWORK_API bool LaunchPackage(const FString& InPackageName, const FString& InExtraKey, const FString& InExtraValue);

	/** 发送广播。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Intent")
	static GENERICANDROIDFRAMEWORK_API bool SendBroadcast(const FString& InPackageName, const FString& InExtraKey, const FString& InExtraValue, bool bExitApplication);

	/** 判断是否包含Manifest Meta数据键。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Manifest")
	static GENERICANDROIDFRAMEWORK_API bool HasManifestMetaDataKey(const FString& InKey);

	/** 获取Manifest Meta数据布尔。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Manifest")
	static GENERICANDROIDFRAMEWORK_API bool GetManifestMetaDataBoolean(const FString& InKey);

	/** 获取Manifest Meta数据整数。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Manifest")
	static GENERICANDROIDFRAMEWORK_API int32 GetManifestMetaDataInt(const FString& InKey);

	/** 获取Manifest Meta数据Long。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Manifest")
	static GENERICANDROIDFRAMEWORK_API int64 GetManifestMetaDataLong(const FString& InKey);

	/** 获取Manifest Meta数据浮点。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Manifest")
	static GENERICANDROIDFRAMEWORK_API float GetManifestMetaDataFloat(const FString& InKey);

	/** 获取Manifest Meta数据字符串。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Manifest")
	static GENERICANDROIDFRAMEWORK_API FString GetManifestMetaDataString(const FString& InKey);

	/** 判断是否包含共享偏好。 */
	UFUNCTION(BlueprintPure, Category="Android|System|SharedPreferences")
	static GENERICANDROIDFRAMEWORK_API bool HasSharedPreference(const FString& InGroup, const FString& InKey);

	/** 设置共享偏好布尔。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|SharedPreferences")
	static GENERICANDROIDFRAMEWORK_API void SetSharedPreferenceBool(const FString& InGroup, const FString& InKey, bool bValue);

	/** 获取共享偏好布尔。 */
	UFUNCTION(BlueprintPure, Category="Android|System|SharedPreferences")
	static GENERICANDROIDFRAMEWORK_API bool GetSharedPreferenceBool(const FString& InGroup, const FString& InKey, bool bDefaultValue);

	/** 设置共享偏好整数。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|SharedPreferences")
	static GENERICANDROIDFRAMEWORK_API void SetSharedPreferenceInt(const FString& InGroup, const FString& InKey, int32 InValue);

	/** 获取共享偏好整数。 */
	UFUNCTION(BlueprintPure, Category="Android|System|SharedPreferences")
	static GENERICANDROIDFRAMEWORK_API int32 GetSharedPreferenceInt(const FString& InGroup, const FString& InKey, int32 InDefaultValue);

	/** 设置共享偏好字符串。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|SharedPreferences")
	static GENERICANDROIDFRAMEWORK_API void SetSharedPreferenceString(const FString& InGroup, const FString& InKey, const FString& InValue);

	/** 获取共享偏好字符串。 */
	UFUNCTION(BlueprintPure, Category="Android|System|SharedPreferences")
	static GENERICANDROIDFRAMEWORK_API FString GetSharedPreferenceString(const FString& InGroup, const FString& InKey, const FString& InDefaultValue);

	/** 处理Delete共享偏好。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|SharedPreferences")
	static GENERICANDROIDFRAMEWORK_API void DeleteSharedPreference(const FString& InGroup, const FString& InKey);

	/** 处理Delete共享偏好组。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|SharedPreferences")
	static GENERICANDROIDFRAMEWORK_API void DeleteSharedPreferenceGroup(const FString& InGroup);

	/** 设置Keep Screen On。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Screen")
	static GENERICANDROIDFRAMEWORK_API void SetKeepScreenOn(bool bEnable);

	/** 判断Screen Capture已禁用是否成立。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Screen")
	static GENERICANDROIDFRAMEWORK_API bool IsScreenCaptureDisabled();

	/** 设置Screen Capture已禁用。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Screen")
	static GENERICANDROIDFRAMEWORK_API void SetScreenCaptureDisabled(bool bDisable);

	/** 请求Minimize应用。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Screen")
	static GENERICANDROIDFRAMEWORK_API void RequestMinimizeApplication();

	/** 处理Restart应用。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Screen")
	static GENERICANDROIDFRAMEWORK_API bool RestartApplication();

	/** 处理Restart应用带Intent。 */
	UFUNCTION(BlueprintCallable, Category="Android|System|Screen")
	static GENERICANDROIDFRAMEWORK_API void RestartApplicationWithIntent(const FString& InIntentString);

	/** 获取系统Font字节数。 */
	UFUNCTION(BlueprintPure, Category="Android|System|Fonts")
	static GENERICANDROIDFRAMEWORK_API void GetSystemFontBytes(TArray<uint8>& OutBytes);

public:
	/** 获取硬件快照。 */
	UFUNCTION(BlueprintPure, Category="Android|Diagnostics|Hardware Snapshot")
	static GENERICANDROIDFRAMEWORK_API void GetHardwareSnapshot(FAndroidHardwareSnapshot& OutSnapshot);

	/** 获取Android调试Report。 */
	UFUNCTION(BlueprintPure, Category="Android|Diagnostics|Report")
	static GENERICANDROIDFRAMEWORK_API FString GetAndroidDebugReport();
};
