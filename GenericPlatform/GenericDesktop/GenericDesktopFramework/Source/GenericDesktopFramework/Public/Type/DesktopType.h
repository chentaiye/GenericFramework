#pragma once

#include "CoreMinimal.h"
#include "IImageWrapper.h"
#include "Misc/EngineVersionComparison.h"
#include "Misc/FileHelper.h"
#include "DesktopType.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(GenericLogWindows, Log, All);

/** 定义桌面图像格式取值。 */
UENUM(BlueprintType)
enum class EDesktopImageFormat : uint8
{
	/** 表示无效选项。 */
	Invalid,
	/** 表示PNG选项。 */
	PNG,
	/** 表示JPEG选项。 */
	JPEG,
	/** 表示灰度JPEG选项。 */
	GrayscaleJPEG,
	/** 表示BMP选项。 */
	BMP,
	/** 表示CO选项。 */
	ICO,
	/** 表示XR选项。 */
	EXR,
	/** 表示CNS选项。 */
	ICNS,
	/** 表示TGA选项。 */
	TGA,
	/** 表示HDR选项。 */
	HDR,
	/** 表示TIFF选项。 */
	TIFF,
	/** 表示DDS选项。 */
	DDS,
	/** 表示EJPEG选项。 */
	UEJPEG,
	/** 表示灰度UEJPEG选项。 */
	GrayscaleUEJPEG,
};

/** 定义桌面文本编码取值。 */
UENUM(BlueprintType)
enum class EDesktopTextEncodingOptions : uint8
{
	/** 表示自动检测选项。 */
	AutoDetect,
	/** 表示强制ANSI选项。 */
	ForceAnsi,
	/** 表示强制Unicode选项。 */
	ForceUnicode,
	/** 表示强制UTF 8选项。 */
	ForceUTF8,
	/** 表示强制UTF 8不带BOM选项。 */
	ForceUTF8WithoutBOM
};

/** 定义桌面电池状态取值。 */
UENUM(BlueprintType)
enum class EDesktopBatteryState : uint8
{
	/** 表示未知选项。 */
	Unknown,
	/** 表示无电池选项。 */
	NoBattery,
	/** 表示充电选项。 */
	Charging,
	/** 表示放电选项。 */
	Discharging,
	/** 表示满电选项。 */
	Full
};

/** 定义桌面外接电源状态取值。 */
UENUM(BlueprintType)
enum class EDesktopPowerLineStatus : uint8
{
	/** 表示未知选项。 */
	Unknown,
	/** 表示离线选项。 */
	Offline,
	/** 表示在线选项。 */
	Online
};

/** 定义桌面网络类型取值。 */
UENUM(BlueprintType)
enum class EDesktopNetworkType : uint8
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

/** 定义桌面显示方向取值。 */
UENUM(BlueprintType)
enum class EDesktopDisplayOrientation : uint8
{
	/** 表示未知选项。 */
	Unknown,
	/** 表示横向选项。 */
	Landscape,
	/** 表示纵向选项。 */
	Portrait,
	/** 表示横向翻转选项。 */
	LandscapeFlipped,
	/** 表示纵向翻转选项。 */
	PortraitFlipped
};

/** 定义桌面显示模式取值。 */
UENUM(BlueprintType)
enum class EDesktopDisplayMode : uint8
{
	/** 表示未知选项。 */
	Unknown,
	/** 表示窗口化选项。 */
	Windowed,
	/** 表示窗口化全屏选项。 */
	WindowedFullscreen,
	/** 表示全屏选项。 */
	Fullscreen
};

/** 封装桌面应用信息。 */
USTRUCT(BlueprintType)
struct FDesktopApplicationInfo
{
	GENERATED_BODY()

	/** 设备唯一标识。 */
	UPROPERTY(BlueprintReadOnly)
	FString DeviceId;

	/** 保存计算机名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ComputerName;

	/** 保存用户名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString UserName;

	/** 保存基础目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString BaseDir;

	/** 保存用户目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString UserDir;

	/** 保存用户临时目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString UserTempDir;

	/** 保存用户主目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString UserHomeDir;

	/** 保存可执行文件路径。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ExecutablePath;

	/** 保存启动目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString LaunchDir;

	/** 保存项目目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ProjectDir;

	/** 保存项目保存目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ProjectSavedDir;

	/** 保存项目内容目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ProjectContentDir;

	/** 保存命令行。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString CommandLine;

	/** 保存操作系统ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString OperatingSystemId;

	/** 保存OS版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString OSVersion;

	/** 保存OS版本标签。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString OSVersionLabel;

	/** 保存OS Sub版本标签。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString OSSubVersionLabel;

	/** 保存引擎版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString EngineVersion;

	/** 保存进程ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 ProcessId=0;

	/** 标记管理员运行状态。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsRunningAsAdministrator=false;
};

/** 封装桌面系统路径信息。 */
USTRUCT(BlueprintType)
struct FDesktopSystemPathInfo
{
	GENERATED_BODY()

	/** 保存桌面目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DesktopDir;

	/** 保存Documents目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DocumentsDir;

	/** 保存Downloads目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DownloadsDir;

	/** 保存Music目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString MusicDir;

	/** 保存Pictures目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString PicturesDir;

	/** 保存Videos目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString VideosDir;

	/** 保存应用数据目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString AppDataDir;

	/** 保存本地应用数据目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString LocalAppDataDir;

	/** 保存临时目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString TempDir;

	/** 保存Program数据目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ProgramDataDir;

	/** 保存保存Games目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString SavedGamesDir;

	/** 保存项目Extras目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ProjectExtrasDir;

	/** 保存项目保存游戏目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ProjectSaveGameDir;
};

/** 封装桌面Monitor信息。 */
USTRUCT(BlueprintType)
struct FDesktopMonitorInfo
{
	GENERATED_BODY()

	/** 保存名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Name;

	/** 保存ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Id;

	/** 保存原生宽度。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 NativeWidth=0;

	/** 保存原生高度。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 NativeHeight=0;

	/** 保存最大Resolution X。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 MaxResolutionX=0;

	/** 保存最大Resolution Y。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 MaxResolutionY=0;

	/** 保存显示Left。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 DisplayLeft=0;

	/** 保存显示Top。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 DisplayTop=0;

	/** 保存显示向右。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 DisplayRight=0;

	/** 保存显示Bottom。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 DisplayBottom=0;

	/** 保存工作区域Left。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 WorkAreaLeft=0;

	/** 保存工作区域Top。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 WorkAreaTop=0;

	/** 保存工作区域向右。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 WorkAreaRight=0;

	/** 保存工作区域Bottom。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 WorkAreaBottom=0;

	/** 保存DPI。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 DPI=0;

	/** 保存DPI 缩放。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	float DPIScale=1.f;

	/** 保存刷新速率。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 RefreshRate=0;

	/** 标记主。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsPrimary=false;

	/** 保存方向。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	EDesktopDisplayOrientation Orientation=EDesktopDisplayOrientation::Unknown;
};

/** 封装桌面显示信息。 */
USTRUCT(BlueprintType)
struct FDesktopDisplayInfo
{
	GENERATED_BODY()

	/** 保存主显示宽度。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 PrimaryDisplayWidth=0;

	/** 保存主显示高度。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 PrimaryDisplayHeight=0;

	/** 保存主工作区域Left。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 PrimaryWorkAreaLeft=0;

	/** 保存主工作区域Top。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 PrimaryWorkAreaTop=0;

	/** 保存主工作区域向右。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 PrimaryWorkAreaRight=0;

	/** 保存主工作区域Bottom。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 PrimaryWorkAreaBottom=0;

	/** 保存虚拟显示Left。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 VirtualDisplayLeft=0;

	/** 保存虚拟显示Top。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 VirtualDisplayTop=0;

	/** 保存虚拟显示向右。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 VirtualDisplayRight=0;

	/** 保存虚拟显示Bottom。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 VirtualDisplayBottom=0;

	/** 保存Monitor数量。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 MonitorCount=0;

	/** 保存应用缩放。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	float ApplicationScale=1.f;

	/** 保存Monitors。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	TArray<FDesktopMonitorInfo> Monitors;
};

/** 封装桌面Main窗口信息。 */
USTRUCT(BlueprintType)
struct FDesktopMainWindowInfo
{
	GENERATED_BODY()

	/** 标记有效。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsValid=false;

	/** 保存标题。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Title;

	/** 保存窗口句柄值。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 WindowHandleValue=0;

	/** 保存Position X。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 PositionX=0;

	/** 保存Position Y。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 PositionY=0;

	/** 保存大小X。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 SizeX=0;

	/** 保存大小Y。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 SizeY=0;

	/** 保存Client大小X。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 ClientSizeX=0;

	/** 保存Client大小Y。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 ClientSizeY=0;

	/** 保存Viewport大小X。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 ViewportSizeX=0;

	/** 保存Viewport大小Y。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 ViewportSizeY=0;

	/** 标记可见。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsVisible=false;

	/** 标记Foreground。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsForeground=false;

	/** 标记Minimized。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsMinimized=false;

	/** 标记Maximized。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsMaximized=false;

	/** 标记Top Most。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsTopMost=false;

	/** 标记Screen Capture已禁用。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsScreenCaptureDisabled=false;

	/** 保存窗口模式。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	EDesktopDisplayMode WindowMode=EDesktopDisplayMode::Unknown;
};

/** 封装桌面CPU信息。 */
USTRUCT(BlueprintType)
struct FDesktopCPUInfo
{
	GENERATED_BODY()

	/** 保存厂商。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Vendor;

	/** 保存品牌。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Brand;

	/** 保存芯片组。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Chipset;

	/** 保存物理核心数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 PhysicalCores=0;

	/** 保存逻辑核心数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 LogicalCores=0;

	/** 保存使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	float UsagePercent=0.f;

	/** 保存Frequency模式Hz。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	float FrequencyMHz=0.f;

	/** 保存进程数量。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 ProcessCount=0;

	/** 保存线程数量。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 ThreadCount=0;

	/** 保存系统Uptime秒。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	double SystemUptimeSeconds=0.0;
};

/** 封装桌面GPU信息。 */
USTRUCT(BlueprintType)
struct FDesktopGPUInfo
{
	GENERATED_BODY()

	/** 保存品牌。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Brand;

	/** 保存Adapter名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString AdapterName;

	/** 提供器名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ProviderName;

	/** 保存驱动内部版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DriverInternalVersion;

	/** 保存驱动用户版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DriverUserVersion;

	/** 保存驱动统一版本。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DriverUnifiedVersion;

	/** 保存驱动日期。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DriverDate;

	/** 保存驱动RHI名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DriverRHIName;

	/** 保存厂商 ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString VendorId;

	/** 保存设备 ID。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DeviceId;

	/** 保存设备Revision。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DeviceRevision;

	/** 保存使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	float UsagePercent=-1.f;

	/** 保存进程使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	float ProcessUsagePercent=-1.f;
};

/** 封装桌面GPU内存信息。 */
USTRUCT(BlueprintType)
struct FDesktopGPUMemoryInfo
{
	GENERATED_BODY()

	/** 标记有效。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsValid=false;

	/** 保存专用显存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 DedicatedVideoMemoryBytes=0;

	/** 保存专用系统内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 DedicatedSystemMemoryBytes=0;

	/** 保存共享系统内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 SharedSystemMemoryBytes=0;

	/** 保存图形内存总字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 TotalGraphicsMemoryBytes=0;

	/** 保存流送内存大小字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 StreamingMemorySizeBytes=0;

	/** 保存Non流送内存大小字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 NonStreamingMemorySizeBytes=0;

	/** 保存最大连续分配字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 LargestContiguousAllocationBytes=0;

	/** 保存纹理Pool大小字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 TexturePoolSizeBytes=0;

	/** 保存可用纹理池字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 AvailableTexturePoolBytes=0;
};

/** 封装桌面内存信息。 */
USTRUCT(BlueprintType)
struct FDesktopMemoryInfo
{
	GENERATED_BODY()

	/** 保存物理内存总字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 TotalPhysicalBytes=0;

	/** 保存可用物理内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 AvailablePhysicalBytes=0;

	/** 保存系统已用物理内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 SystemUsedPhysicalBytes=0;

	/** 保存进程已用物理内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 ProcessUsedPhysicalBytes=0;

	/** 保存进程峰值物理内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 PeakProcessUsedPhysicalBytes=0;

	/** 保存虚拟内存总字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 TotalVirtualBytes=0;

	/** 保存可用虚拟内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 AvailableVirtualBytes=0;

	/** 保存进程已用虚拟内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 ProcessUsedVirtualBytes=0;

	/** 保存进程峰值虚拟内存字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 PeakProcessUsedVirtualBytes=0;

	/** 保存Page大小字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 PageSizeBytes=0;

	/** 保存Os Allocation Granularity字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 OsAllocationGranularityBytes=0;

	/** 保存Binned Page大小字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 BinnedPageSizeBytes=0;

	/** 保存物理内存总量（GB）。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 TotalPhysicalGB=0;

	/** 保存系统物理内存使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	float SystemPhysicalUsagePercent=0.f;

	/** 保存进程物理内存使用率。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	float ProcessPhysicalUsagePercent=0.f;
};

/** 封装桌面磁盘信息。 */
USTRUCT(BlueprintType)
struct FDesktopDiskInfo
{
	GENERATED_BODY()

	/** 标记有效。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsValid=false;

	/** 保存路径。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Path;

	/** 保存Root路径。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString RootPath;

	/** 保存Volume名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString VolumeName;

	/** 保存文件系统名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString FileSystemName;

	/** 保存Drive类型。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 DriveType=0;

	/** 保存Drive类型名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString DriveTypeName;

	/** 保存总字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 TotalBytes=0;

	/** 保存可用字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 FreeBytes=0;

	/** 保存已用字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int64 UsedBytes=0;
};

/** 封装桌面电源信息。 */
USTRUCT(BlueprintType)
struct FDesktopPowerInfo
{
	GENERATED_BODY()

	/** 保存电源行状态。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	EDesktopPowerLineStatus PowerLineStatus=EDesktopPowerLineStatus::Unknown;

	/** 保存电池状态。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	EDesktopBatteryState BatteryState=EDesktopBatteryState::Unknown;

	/** 保存电池电量百分比。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 BatteryPercent=-1;

	/** 保存电池Life时间秒。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 BatteryLifeTimeSeconds=-1;

	/** 保存电池满Life时间秒。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 BatteryFullLifeTimeSeconds=-1;

	/** 标记是否包含电池。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bHasBattery=false;

	/** 标记运行On电池。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsRunningOnBattery=false;

	/** 标记电池Saver已启用。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bIsBatterySaverEnabled=false;
};

/** 封装桌面网络Adapter Ip。 */
USTRUCT(BlueprintType)
struct FDesktopNetworkAdapterIp
{
	GENERATED_BODY()

	/** 保存Ip。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Ip;

	/** 保存掩码。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Mask;

	/** 保存网关。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Gateway;
};

/** 封装桌面网络Adapter信息。 */
USTRUCT(BlueprintType)
struct FDesktopNetworkAdapterInfo
{
	GENERATED_BODY()

	/** 保存名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Name;

	/** 保存描述。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Description;

	/** 启用DHCP。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bEnableDHCP=false;

	/** 保存索引。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 Index=INDEX_NONE;

	/** 保存类型。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 Type=INDEX_NONE;

	/** 保存P列表。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	TArray<FDesktopNetworkAdapterIp> IPList;

	/** 保存MAC 地址。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString MacAddress;
};

/** 封装桌面网络信息。 */
USTRUCT(BlueprintType)
struct FDesktopNetworkInfo
{
	GENERATED_BODY()

	/** 保存网络类型。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	EDesktopNetworkType NetworkType=EDesktopNetworkType::Unknown;

	/** 标记是否包含网络。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bHasNetwork=false;

	/** 标记是否包含Wi-Fi Fi连接。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bHasWiFiConnection=false;

	/** 标记是否包含以太网连接。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bHasEthernetConnection=false;

	/** 保存主机地址名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString HostName;

	/** 保存主 IPv4 地址。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString PrimaryIpv4;

	/** 保存Adapter数量。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	int32 AdapterCount=0;
};

/** 封装桌面对话框结果。 */
USTRUCT(BlueprintType)
struct FDesktopDialogResult
{
	GENERATED_BODY()

	/** 标记成功。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bSuccess=false;

	/** 保存目录。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Directory;

	/** 保存文件Paths。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	TArray<FString> FilePaths;

	/** 保存错误消息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ErrorMessage;
};

/** 封装桌面字符串结果。 */
USTRUCT(BlueprintType)
struct FDesktopStringResult
{
	GENERATED_BODY()

	/** 标记成功。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bSuccess=false;

	/** 保存文件名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString FileName;

	/** 保存数据。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString Data;

	/** 保存错误消息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ErrorMessage;
};

/** 封装桌面字节数结果。 */
USTRUCT(BlueprintType)
struct FDesktopBytesResult
{
	GENERATED_BODY()

	/** 标记成功。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	bool bSuccess=false;

	/** 保存文件名称。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString FileName;

	/** 保存数据。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	TArray<uint8> Data;

	/** 保存错误消息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FString ErrorMessage;
};

/** 封装桌面硬件Snapshot。 */
USTRUCT(BlueprintType)
struct FDesktopHardwareSnapshot
{
	GENERATED_BODY()

	/** 保存Capture时间秒。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	double CaptureTimeSeconds=0.0;

	/** 保存应用信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopApplicationInfo ApplicationInfo;

	/** 保存系统路径信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopSystemPathInfo SystemPathInfo;

	/** 保存显示信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopDisplayInfo DisplayInfo;

	/** 保存Main窗口信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopMainWindowInfo MainWindowInfo;

	/** 保存CPU信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopCPUInfo CPUInfo;

	/** 保存GPU信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopGPUInfo GPUInfo;

	/** 保存GPU内存信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopGPUMemoryInfo GPUMemoryInfo;

	/** 保存内存信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopMemoryInfo MemoryInfo;

	/** 保存项目磁盘信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopDiskInfo ProjectDiskInfo;

	/** 保存磁盘信息列表。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	TArray<FDesktopDiskInfo> DiskInfos;

	/** 保存电源信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopPowerInfo PowerInfo;

	/** 保存网络信息。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	FDesktopNetworkInfo NetworkInfo;

	/** 保存网络Adapters。 */
	UPROPERTY(BlueprintReadOnly, Category="Desktop Type")
	TArray<FDesktopNetworkAdapterInfo> NetworkAdapters;
};

/** 蓝图图片格式转换为 UE 图片格式。 */
FORCEINLINE EImageFormat ConvertToDesktopImageFormat(const EDesktopImageFormat InImageFormat)
{
	switch (InImageFormat)
	{
	case EDesktopImageFormat::PNG:
		return EImageFormat::PNG;
	case EDesktopImageFormat::JPEG:
		return EImageFormat::JPEG;
	case EDesktopImageFormat::GrayscaleJPEG:
		return EImageFormat::GrayscaleJPEG;
	case EDesktopImageFormat::BMP:
		return EImageFormat::BMP;
	case EDesktopImageFormat::ICO:
		return EImageFormat::ICO;
	case EDesktopImageFormat::EXR:
		return EImageFormat::EXR;
	case EDesktopImageFormat::ICNS:
		return EImageFormat::ICNS;
	case EDesktopImageFormat::TGA:
		return EImageFormat::TGA;
	case EDesktopImageFormat::HDR:
		return EImageFormat::HDR;
	case EDesktopImageFormat::TIFF:
		return EImageFormat::TIFF;
	case EDesktopImageFormat::DDS:
		return EImageFormat::DDS;
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
	case EDesktopImageFormat::UEJPEG:
		return EImageFormat::UEJPEG;
	case EDesktopImageFormat::GrayscaleUEJPEG:
		return EImageFormat::GrayscaleUEJPEG;
#else
	case EWindowImageFormat::UEJPEG:
		return EImageFormat::JPEG;
	case EWindowImageFormat::GrayscaleUEJPEG:
		return EImageFormat::GrayscaleJPEG;
#endif
	default:
		return EImageFormat::Invalid;
	}
}

/** 转换为桌面编码选项。 */
FORCEINLINE FFileHelper::EEncodingOptions ConvertToDesktopEncodingOptions(const EDesktopTextEncodingOptions InEncodingOptions)
{
	switch (InEncodingOptions)
	{
	case EDesktopTextEncodingOptions::ForceAnsi:
		return FFileHelper::EEncodingOptions::ForceAnsi;
	case EDesktopTextEncodingOptions::ForceUnicode:
		return FFileHelper::EEncodingOptions::ForceUnicode;
	case EDesktopTextEncodingOptions::ForceUTF8:
		return FFileHelper::EEncodingOptions::ForceUTF8;
	case EDesktopTextEncodingOptions::ForceUTF8WithoutBOM:
		return FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM;
	case EDesktopTextEncodingOptions::AutoDetect:
	default:
		return FFileHelper::EEncodingOptions::AutoDetect;
	}
}
