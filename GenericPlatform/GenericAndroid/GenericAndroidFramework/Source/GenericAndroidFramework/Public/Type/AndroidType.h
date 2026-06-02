#pragma once

#include "CoreMinimal.h"
#include "AndroidType.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(GenericLogAndroid, Log, All);

/** 定义Android权限状态取值。 */
UENUM(BlueprintType)
enum class EAndroidPermissionState : uint8
{
	/** 表示未知选项。 */
	Unknown,
	/** 表示Granted选项。 */
	Granted,
	/** 表示Denied选项。 */
	Denied
};

/** 定义Android网络类型取值。 */
UENUM(BlueprintType)
enum class EAndroidNetworkType : uint8
{
	/** 表示未知选项。 */
	Unknown,
	/** 表示无选项。 */
	None,
	/** 表示飞行模式选项。 */
	AirplaneMode,
	/** 表示单元选项。 */
	Cell,
	/** 表示Wi-Fi选项。 */
	WiFi,
	/** 表示WiMAX选项。 */
	WiMAX,
	/** 表示蓝牙选项。 */
	Bluetooth,
	/** 表示以太网选项。 */
	Ethernet
};

/** 定义Android电池状态取值。 */
UENUM(BlueprintType)
enum class EAndroidBatteryState : uint8
{
	/** 表示未知选项。 */
	Unknown,
	/** 表示充电选项。 */
	Charging,
	/** 表示放电选项。 */
	Discharging,
	/** 表示未充电选项。 */
	NotCharging,
	/** 表示满电选项。 */
	Full
};

/** 定义Android内存Pressure关卡取值。 */
UENUM(BlueprintType)
enum class EAndroidMemoryPressureLevel : uint8
{
	/** 表示未知选项。 */
	Unknown,
	/** 表示普通状态选项。 */
	Normal,
	/** 表示Warning选项。 */
	Warning,
	/** 表示Critical选项。 */
	Critical
};

/** 定义Android Screen方向类型取值。 */
UENUM(BlueprintType)
enum class EAndroidScreenOrientationType : uint8
{
	/** 表示未知选项。 */
	Unknown,
	/** 表示纵向选项。 */
	Portrait,
	/** 表示纵向Upside向下选项。 */
	PortraitUpsideDown,
	/** 表示Landscape Left选项。 */
	LandscapeLeft,
	/** 表示Landscape向右选项。 */
	LandscapeRight,
	/** 表示Face Up选项。 */
	FaceUp,
	/** 表示Face向下选项。 */
	FaceDown,
	/** 表示纵向Sensor选项。 */
	PortraitSensor,
	/** 表示Landscape Sensor选项。 */
	LandscapeSensor,
	/** 表示满Sensor选项。 */
	FullSensor
};

/** 定义Android Haptic类型取值。 */
UENUM(BlueprintType)
enum class EAndroidHapticType : uint8
{
	/** 表示Feedback成功选项。 */
	FeedbackSuccess,
	/** 表示Feedback Warning选项。 */
	FeedbackWarning,
	/** 表示Feedback错误选项。 */
	FeedbackError,
	/** 表示选中Changed选项。 */
	SelectionChanged,
	/** 表示Impact Light选项。 */
	ImpactLight,
	/** 表示Impact Medium选项。 */
	ImpactMedium,
	/** 表示Impact Heavy选项。 */
	ImpactHeavy
};

/** 定义Android Common权限取值。 */
UENUM(BlueprintType)
enum class EAndroidCommonPermission : uint8
{
	/** 表示相机选项。 */
	Camera,
	/** 表示Record音频选项。 */
	RecordAudio,
	/** 表示读取外部Storage选项。 */
	ReadExternalStorage,
	/** 表示写入外部Storage选项。 */
	WriteExternalStorage,
	/** 表示读取媒体Images选项。 */
	ReadMediaImages,
	/** 表示读取媒体视频选项。 */
	ReadMediaVideo,
	/** 表示读取媒体音频选项。 */
	ReadMediaAudio,
	/** 表示Post Notifications选项。 */
	PostNotifications,
	/** 表示访问Fine位置选项。 */
	AccessFineLocation,
	/** 表示访问Coarse位置选项。 */
	AccessCoarseLocation,
	/** 表示访问Wi-Fi状态选项。 */
	AccessWifiState,
	/** 表示Change Wi-Fi状态选项。 */
	ChangeWifiState,
	/** 表示Internet选项。 */
	Internet,
	/** 表示蓝牙选项。 */
	Bluetooth,
	/** 表示蓝牙Admin选项。 */
	BluetoothAdmin,
	/** 表示蓝牙连接选项。 */
	BluetoothConnect,
	/** 表示蓝牙Scan选项。 */
	BluetoothScan,
	/** 表示蓝牙Advertise选项。 */
	BluetoothAdvertise,
	/** 表示Wake锁定选项。 */
	WakeLock,
	/** 表示Vibrate选项。 */
	Vibrate,
	/** 表示读取Phone状态选项。 */
	ReadPhoneState,
	/** 表示Body Sensors选项。 */
	BodySensors,
	/** 表示Nfc选项。 */
	Nfc
};

/** 封装Android设备信息。 */
USTRUCT(BlueprintType)
struct FAndroidDeviceInfo
{
	GENERATED_BODY()

	/** 保存品牌。 */
	UPROPERTY(BlueprintReadOnly)
	FString Brand;

	/** 保存模型。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString Model;

	/** 保存产品名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString ProductName;

	/** 保存设备构建号。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString DeviceBuildNumber;

	/** 保存Android 版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString AndroidVersion;

	/** 保存Android 主版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 AndroidMajorVersion=0;

	/** 保存Android 构建版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 AndroidBuildVersion=0;

	/** 保存系统语言。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString OSLanguage;

	/** 保存默认区域设置。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString DefaultLocale;

	/** 保存时间Zone ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString TimeZoneId;

	/** 保存项目版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString ProjectVersion;
};

/** 封装Android应用信息。 */
USTRUCT(BlueprintType)
struct FAndroidAppInfo
{
	GENERATED_BODY()

	/** 保存Package名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString PackageName;

	/** 保存版本显示名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString VersionDisplayName;

	/** 保存商店版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 StoreVersion=0;

	/** 保存最小SDK版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 MinSDKVersion=0;

	/** 保存目标 SDK 版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 TargetSDKVersion=0;

	/** 保存分发渠道。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString DistributionChannel;
};

/** 封装Android ID信息。 */
USTRUCT(BlueprintType)
struct FAndroidIdInfo
{
	GENERATED_BODY()

	/** 保存设备 ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString DeviceId;

	/** 保存Android ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString AndroidId;

	/** 保存广告 ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString AdvertisingId;

	/** 保存登录 ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString LoginId;

	/** 标记是否包含Android ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bHasAndroidId=false;

	/** 标记是否包含广告 ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bHasAdvertisingId=false;

	/** 标记是否包含登录 ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bHasLoginId=false;
};

/** 封装Android CPU信息。 */
USTRUCT(BlueprintType)
struct FAndroidCPUInfo
{
	GENERATED_BODY()

	/** 保存厂商。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString Vendor;

	/** 保存品牌。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString Brand;

	/** 保存芯片组。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString Chipset;

	/** 保存物理核心数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 PhysicalCores=0;

	/** 保存逻辑核心数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 LogicalCores=0;

	/** 保存激活核心数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 ActiveCores=0;

	/** 保存平均使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	float AverageUsagePercent=0.f;

	/** 保存单核心使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	TArray<float> PerCoreUsagePercent;

	/** 保存当前Frequencies模式Hz。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	TArray<int32> CurrentFrequenciesMHz;

	/** 保存最大Frequencies模式Hz。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	TArray<int32> MaxFrequenciesMHz;

	/** 保存最小Frequencies模式Hz。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	TArray<int32> MinFrequenciesMHz;

	/** 保存摄氏温度。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	float TemperatureCelsius=0.f;
};

/** 封装Android GPU信息。 */
USTRUCT(BlueprintType)
struct FAndroidGPUInfo
{
	GENERATED_BODY()

	/** 保存品牌。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString Brand;

	/** 保存GPU 系列。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString GPUFamily;

	/** 保存渲染器。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString Renderer;

	/** 保存厂商名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString VendorName;

	/** 保存驱动内部版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString DriverInternalVersion;

	/** 保存驱动用户版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString DriverUserVersion;

	/** 保存驱动统一版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString DriverUnifiedVersion;

	/** 保存驱动日期。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString DriverDate;

	/** 保存GL 版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString GLVersion;

	/** 保存Vulkan 版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString VulkanVersion;

	/** 保存RHI名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString RHIName;

	/** 标记是否包含Vulkan驱动支持。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bHasVulkanDriverSupport=false;

	/** 标记Vulkan可用。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bIsVulkanAvailable=false;

	/** 标记是否需要Use Vulkan。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bShouldUseVulkan=false;

	/** 保存使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	float UsagePercent=-1.f;

	/** 保存进程使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	float ProcessUsagePercent=-1.f;
};

/** 封装Android GPU内存信息。 */
USTRUCT(BlueprintType)
struct FAndroidGPUMemoryInfo
{
	GENERATED_BODY()

	/** 标记有效。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bIsValid=false;

	/** 保存专用显存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 DedicatedVideoMemoryBytes=0;

	/** 保存专用系统内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 DedicatedSystemMemoryBytes=0;

	/** 保存共享系统内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 SharedSystemMemoryBytes=0;

	/** 保存图形内存总字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 TotalGraphicsMemoryBytes=0;

	/** 保存流送内存大小字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 StreamingMemorySizeBytes=0;

	/** 保存Non流送内存大小字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 NonStreamingMemorySizeBytes=0;

	/** 保存最大连续分配字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 LargestContiguousAllocationBytes=0;

	/** 保存纹理Pool大小字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 TexturePoolSizeBytes=0;

	/** 保存可用纹理池字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 AvailableTexturePoolBytes=0;
};

/** 封装Android内存信息。 */
USTRUCT(BlueprintType)
struct FAndroidMemoryInfo
{
	GENERATED_BODY()

	/** 保存物理内存总字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 TotalPhysicalBytes=0;

	/** 保存可用物理内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 AvailablePhysicalBytes=0;

	/** 保存系统已用物理内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 SystemUsedPhysicalBytes=0;

	/** 保存进程已用物理内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 ProcessUsedPhysicalBytes=0;

	/** 保存进程峰值物理内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 PeakProcessUsedPhysicalBytes=0;

	/** 保存虚拟内存总字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 TotalVirtualBytes=0;

	/** 保存可用虚拟内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 AvailableVirtualBytes=0;

	/** 保存进程已用虚拟内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 ProcessUsedVirtualBytes=0;

	/** 保存进程峰值虚拟内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 PeakProcessUsedVirtualBytes=0;

	/** 保存物理内存总量（GB）。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 TotalPhysicalGB=0;

	/** 保存系统物理内存使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	float SystemPhysicalUsagePercent=0.f;

	/** 保存进程物理内存使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	float ProcessPhysicalUsagePercent=0.f;

	/** 标记Low内存。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bLowMemory=false;

	/** 保存Pressure关卡。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	EAndroidMemoryPressureLevel PressureLevel=EAndroidMemoryPressureLevel::Unknown;
};

/** 封装Android Storage信息。 */
USTRUCT(BlueprintType)
struct FAndroidStorageInfo
{
	GENERATED_BODY()

	/** 标记有效。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bIsValid=false;

	/** 标记Exists。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bExists=false;

	/** 保存路径。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString Path;

	/** 保存Root路径。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString RootPath;

	/** 保存总字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 TotalBytes=0;

	/** 保存可用字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 FreeBytes=0;

	/** 保存已用字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int64 UsedBytes=0;
};

/** 封装Android电池信息。 */
USTRUCT(BlueprintType)
struct FAndroidBatteryInfo
{
	GENERATED_BODY()

	/** 保存状态。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	EAndroidBatteryState State=EAndroidBatteryState::Unknown;

	/** 保存关卡。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 Level=0;

	/** 保存摄氏温度。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	float TemperatureCelsius=0.f;

	/** 标记充电。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bCharging=false;

	/** 标记运行On电池。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bRunningOnBattery=false;

	/** 标记Low电源模式。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bLowPowerMode=false;
};

/** 封装Android网络信息。 */
USTRUCT(BlueprintType)
struct FAndroidNetworkInfo
{
	GENERATED_BODY()

	/** 保存网络类型。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	EAndroidNetworkType NetworkType=EAndroidNetworkType::Unknown;

	/** 标记是否包含网络。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bHasNetwork=false;

	/** 标记是否包含Wi-Fi Fi连接。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bHasWiFiConnection=false;

	/** 保存蜂窝网络偏好。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 CellularPreference=0;
};

/** 封装Android显示信息。 */
USTRUCT(BlueprintType)
struct FAndroidDisplayInfo
{
	GENERATED_BODY()

	/** 保存Screen宽度。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 ScreenWidth=0;

	/** 保存Screen高度。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 ScreenHeight=0;

	/** 保存Viewport宽度。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 ViewportWidth=0;

	/** 保存Viewport高度。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 ViewportHeight=0;

	/** 保存DPI 缩放。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	float DPIScale=1.f;

	/** 保存估算 DPI。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 EstimatedDPI=160;

	/** 保存原生刷新速率。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 NativeRefreshRate=0;

	/** 保存支持的刷新率列表。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	TArray<int32> SupportedRefreshRates;

	/** 保存方向。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	EAndroidScreenOrientationType Orientation=EAndroidScreenOrientationType::Unknown;
};

/** 封装Android输入设备信息数据。 */
USTRUCT(BlueprintType)
struct FAndroidInputDeviceInfoData
{
	GENERATED_BODY()

	/** 保存设备 ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 DeviceId=-1;

	/** 保存厂商 ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 VendorId=0;

	/** 保存产品ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 ProductId=0;

	/** 保存控制器ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 ControllerId=-1;

	/** 保存名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString Name;

	/** 描述。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FString Descriptor;

	/** 保存Feedback Motor数量。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	int32 FeedbackMotorCount=0;
};

/** 封装Android Capability信息。 */
USTRUCT(BlueprintType)
struct FAndroidCapabilityInfo
{
	GENERATED_BODY()

	/** 标记支持设备。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bIsSupportedDevice=false;

	/** 标记是否包含Vulkan驱动支持。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bHasVulkanDriverSupport=false;

	/** 标记Vulkan可用。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bIsVulkanAvailable=false;

	/** 标记是否需要Use Vulkan。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bShouldUseVulkan=false;

	/** 标记Supports Floating Point渲染Targets。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bSupportsFloatingPointRenderTargets=false;

	/** 标记Supports Shader Framebuffer Fetch。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bSupportsShaderFramebufferFetch=false;

	/** 标记Supports Shader IO区块。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bSupportsShaderIOBlocks=false;

	/** 标记Supports Backbuffer Sampling。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bSupportsBackbufferSampling=false;

	/** 标记Expand 16 Bit Indices To 32 Bit On加载。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	bool bExpand16BitIndicesTo32BitOnLoad=false;
};

/** 封装Android硬件Snapshot。 */
USTRUCT(BlueprintType)
struct FAndroidHardwareSnapshot
{
	GENERATED_BODY()

	/** 保存Capture时间秒。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	double CaptureTimeSeconds=0.0;

	/** 保存设备信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidDeviceInfo DeviceInfo;

	/** 保存应用信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidAppInfo AppInfo;

	/** 保存ID信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidIdInfo IdInfo;

	/** 保存CPU信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidCPUInfo CPUInfo;

	/** 保存GPU信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidGPUInfo GPUInfo;

	/** 保存GPU内存信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidGPUMemoryInfo GPUMemoryInfo;

	/** 保存内存信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidMemoryInfo MemoryInfo;

	/** 保存内部Storage。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidStorageInfo InternalStorage;

	/** 保存外部Storage。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidStorageInfo ExternalStorage;

	/** 保存项目Storage。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidStorageInfo ProjectStorage;

	/** 保存电池信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidBatteryInfo BatteryInfo;

	/** 保存网络信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidNetworkInfo NetworkInfo;

	/** 保存显示信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidDisplayInfo DisplayInfo;

	/** 保存Capability信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Android Type")
	FAndroidCapabilityInfo CapabilityInfo;
};
