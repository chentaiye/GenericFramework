// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IOTTypes.generated.h"

/** 描述 GenericIOT 运行时可接入的平台类型，子系统会用它选择对应的平台适配器工厂。 */
UENUM(BlueprintType)
enum class EIOTPlatformKind : uint8
{
	/** 无法识别或尚未绑定具体平台时的兜底值，避免设备描述误绑定到适配器。 */
	Unknown UMETA(DisplayName="未知平台"),

	/** 当前核心流程支持的 Home Assistant 平台，连接、发现和命令都会路由到对应适配器。 */
	HomeAssistant UMETA(DisplayName="Home Assistant")
};

/** 描述 IOT 子系统连接生命周期，异步节点和组件依赖该状态判断成功、失败与后续自动流程。 */
UENUM(BlueprintType)
enum class EIOTConnectionState : uint8
{
	/** 未保持平台连接，断开流程会回到该状态并关闭实时订阅标记。 */
	Disconnected UMETA(DisplayName="未连接"),

	/** 正在按发现候选地址逐个探测 Home Assistant 实例，尚未进入适配器连接阶段。 */
	Discovering UMETA(DisplayName="发现中"),

	/** 平台适配器已经开始连接握手，等待协议层回调最终结果。 */
	Connecting UMETA(DisplayName="连接中"),

	/** 平台连接可用，子系统会在进入该状态后触发自动刷新设备和自动订阅实时流。 */
	Connected UMETA(DisplayName="已连接"),

	/** 已连接并正在建立实时订阅通道，订阅异步节点会监听后续实时状态广播。 */
	Subscribing UMETA(DisplayName="订阅中"),

	/** 最近一次连接、发现、刷新或订阅流程失败，LastErrorMessage 会保存失败原因。 */
	Error UMETA(DisplayName="错误")
};

/** 将平台实体域归一为设备类型，供设备快照、组件绑定和蓝图筛选使用。 */
UENUM(BlueprintType)
enum class EIOTDeviceKind : uint8
{
	/** 平台域无法映射到已知设备时使用，保留实体但不假设可用能力。 */
	Unknown UMETA(DisplayName="未知设备"),

	/** 灯光类实体，通常提供电源、亮度、色温或颜色能力。 */
	Light UMETA(DisplayName="灯光"),

	/** 开关类实体，通常只需要开关或切换命令。 */
	Switch UMETA(DisplayName="开关"),

	/** 风扇类实体，适配器可为其补充电源、档位或模式能力。 */
	Fan UMETA(DisplayName="风扇"),

	/** 窗帘、卷帘等覆盖物实体，通常与位置或开合命令关联。 */
	Cover UMETA(DisplayName="窗帘"),

	/** 温控设备实体，状态和命令通常围绕目标温度、模式与预设展开。 */
	Climate UMETA(DisplayName="空调"),

	/** 加湿器实体，适配器会把开关、湿度目标或模式折叠为统一能力。 */
	Humidifier UMETA(DisplayName="加湿器"),

	/** 热水器实体，用于承载目标温度、运行模式等 Home Assistant 域能力。 */
	WaterHeater UMETA(DisplayName="热水器"),

	/** 媒体播放器实体，命令会围绕播放、音量和静音能力构建。 */
	MediaPlayer UMETA(DisplayName="媒体设备"),

	/** 扫地机实体，通常通过触发或模式类能力发起清扫动作。 */
	Vacuum UMETA(DisplayName="扫地机"),

	/** 门锁实体，使用锁控制能力表达上锁、解锁等安全动作。 */
	Lock UMETA(DisplayName="门锁"),

	/** 安防面板实体，使用布防控制能力表达布防、撤防等命令。 */
	Alarm UMETA(DisplayName="安防"),

	/** 警报器实体，通常通过触发或开关能力控制告警输出。 */
	Siren UMETA(DisplayName="警报器"),

	/** Home Assistant 场景实体，作为可触发动作暴露给蓝图和组件。 */
	Scene UMETA(DisplayName="场景"),

	/** Home Assistant 脚本实体，作为命令入口参与统一触发流程。 */
	Script UMETA(DisplayName="脚本"),

	/** 按钮实体，主要通过 Trigger 能力发起一次性动作。 */
	Button UMETA(DisplayName="按钮"),

	/** 输入布尔实体，归一为可读写的布尔开关能力。 */
	InputBoolean UMETA(DisplayName="布尔输入"),

	/** 输入数字实体，归一为可设置的数值能力并携带范围信息。 */
	InputNumber UMETA(DisplayName="数值输入"),

	/** 输入选择实体，归一为可写入的选项能力。 */
	InputSelect UMETA(DisplayName="选项输入"),

	/** 数字实体，作为平台暴露的数值控制或读数入口。 */
	Number UMETA(DisplayName="数值"),

	/** 选择实体，使用选项能力描述允许的枚举值。 */
	Select UMETA(DisplayName="选项"),

	/** 计时器实体，保留计时状态并允许适配器映射启动或取消动作。 */
	Timer UMETA(DisplayName="计时器"),

	/** 遥控器实体，通常以触发命令承载发送按键或场景动作。 */
	Remote UMETA(DisplayName="遥控器"),

	/** 传感器实体，作为只读读数进入设备状态缓存。 */
	Sensor UMETA(DisplayName="传感器"),

	/** 二值传感器实体，作为只读布尔状态进入设备状态缓存。 */
	BinarySensor UMETA(DisplayName="二值传感器")
};

/** 描述设备可读写能力的统一类型，命令请求和能力描述都会用它脱离具体平台服务名。 */
UENUM(BlueprintType)
enum class EIOTCapabilityKind : uint8
{
	/** 未识别能力，保留原始数据但不参与组件快捷命令。 */
	Unknown UMETA(DisplayName="未知能力"),

	/** 设备主电源控制能力，TurnOn 与 TurnOff 快捷方法会使用该类型。 */
	Power UMETA(DisplayName="电源控制"),

	/** 在当前开关状态基础上反转设备状态，组件 Toggle 会发出该类型命令。 */
	Toggle UMETA(DisplayName="切换控制"),

	/** 灯光或显示类设备的亮度控制，通常对应 0 到 1 或平台原始亮度范围。 */
	Brightness UMETA(DisplayName="亮度"),

	/** 灯光色温能力，适配器可用 MinValue 和 MaxValue 描述可调范围。 */
	ColorTemperature UMETA(DisplayName="色温"),

	/** 灯光颜色能力，用于把颜色参数映射到平台服务调用。 */
	Color UMETA(DisplayName="颜色"),

	/** 设备运行模式能力，通常配合 OptionValues 暴露可选模式。 */
	Mode UMETA(DisplayName="模式"),

	/** 平台预设能力，用于温控、风扇等设备的快捷预设切换。 */
	Preset UMETA(DisplayName="预设"),

	/** 通用选项写入能力，组件 SetOption 会使用该类型提交字符串选项。 */
	Option UMETA(DisplayName="选项"),

	/** 温控或热水器的目标温度能力，通常需要数值范围约束。 */
	TargetTemperature UMETA(DisplayName="目标温度"),

	/** 窗帘、覆盖物等设备的位置能力，用于表达百分比或平台位置值。 */
	Position UMETA(DisplayName="位置"),

	/** 媒体设备音量能力，通常作为可写数值同步给平台。 */
	Volume UMETA(DisplayName="音量"),

	/** 媒体设备静音能力，用布尔或切换命令表达。 */
	Mute UMETA(DisplayName="静音"),

	/** 媒体播放控制能力，用于播放、暂停或其他播放状态命令。 */
	Playback UMETA(DisplayName="媒体播放"),

	/** 一次性触发能力，按钮、场景、脚本等实体会通过该能力发起动作。 */
	Trigger UMETA(DisplayName="触发"),

	/** 门锁控制能力，适配器据此区分上锁、解锁等安全命令。 */
	LockControl UMETA(DisplayName="门锁控制"),

	/** 安防面板布撤防能力，用于把 arm/disarm 类服务统一到命令请求。 */
	ArmControl UMETA(DisplayName="安防控制"),

	/** 通用数值写入能力，组件 SetNumericValue 会通过该类型传递 value 参数。 */
	NumericValue UMETA(DisplayName="数值控制"),

	/** 只读传感器读数能力，状态缓存会用它承载平台读数。 */
	SensorValue UMETA(DisplayName="传感器读数")
};

/** 描述命令执行结果，适配器用它把平台错误归一后交给异步节点和组件事件。 */
UENUM(BlueprintType)
enum class EIOTCommandStatus : uint8
{
	/** 平台已接受并完成命令，结果可用于刷新组件或蓝图上的成功分支。 */
	Success UMETA(DisplayName="成功"),

	/** 当前设备或能力没有对应平台服务，调用方应隐藏或禁用该命令入口。 */
	Unsupported UMETA(DisplayName="不支持"),

	/** 命令参数缺失或格式不符合平台要求，通常不会真正发起平台调用。 */
	InvalidArgument UMETA(DisplayName="参数错误"),

	/** 目标实体在平台侧不可用，设备存在但当前不能执行命令。 */
	EntityUnavailable UMETA(DisplayName="实体不可用"),

	/** 平台适配器、连接或子系统不可用，命令无法被派发。 */
	PlatformUnavailable UMETA(DisplayName="平台不可用"),

	/** 平台鉴权失败，通常表示访问令牌无效或已过期。 */
	AuthenticationFailed UMETA(DisplayName="鉴权失败"),

	/** HTTP、WebSocket 或其他传输层失败，平台未能返回有效业务结果。 */
	TransportError UMETA(DisplayName="传输错误"),

	/** 平台返回业务错误或未归类异常，保留 ErrorCode 与 ErrorMessage 供上层展示。 */
	PlatformError UMETA(DisplayName="平台错误")
};

/** 保存平台连接入口配置，子系统初始化、自动发现和适配器连接都会读取该结构。 */
USTRUCT(BlueprintType)
struct GENERICIOTFRAMEWORK_API FIOTPlatformEndpointConfig
{
	GENERATED_BODY()

	/** 指定连接目标平台，当前用于选择 Home Assistant 适配器工厂。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	EIOTPlatformKind PlatformKind = EIOTPlatformKind::HomeAssistant;

	/** 平台 HTTP 基础地址，子系统保存时会去掉尾部斜杠以便拼接 API 路径。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString BaseUrl;

	/** 平台访问令牌，适配器执行连接、刷新和命令请求时用于鉴权。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString AccessToken;

	/** 用户可读实例名称，用于区分多个平台配置或在界面中显示当前连接目标。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString InstanceName=TEXT("Home Assistant");

	/** 当 BaseUrl 为空时允许子系统进入自动发现流程并探测候选地址。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	bool bAutoDiscover=true;

	/** 预留给平台适配器的自动重连开关，用于连接断开后的恢复策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	bool bAutoReconnect=true;

	/** 平台请求超时时间，自动发现探测和适配器请求可用它限制等待时长。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT", meta=(ClampMin="1.0"))
	float RequestTimeoutSeconds=8.0f;

	/** 判断归一化后的 BaseUrl 是否可用于构造平台 API 地址。 */
	bool HasBaseUrl() const { return !BaseUrl.TrimStartAndEnd().IsEmpty(); }

	/** 判断连接所需的地址与令牌是否齐备，供适配器在发起连接前快速拦截无效配置。 */
	bool IsValidForConnection() const { return HasBaseUrl() && !AccessToken.TrimStartAndEnd().IsEmpty(); }
};

/** 描述设备暴露给 GenericIOT 的单项能力，命令 UI 和快捷组件会按该结构决定可用操作。 */
USTRUCT(BlueprintType)
struct GENERICIOTFRAMEWORK_API FIOTCapabilityDescriptor
{
	GENERATED_BODY()

	/** 统一能力类型，用于把平台服务映射到组件快捷命令和蓝图命令请求。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	EIOTCapabilityKind CapabilityKind = EIOTCapabilityKind::Unknown;

	/** 平台或适配器提供的能力名称，供界面展示或调试时识别原始能力。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString CapabilityName;

	/** 标识能力是否会出现在状态缓存中，传感器和当前模式等读数依赖它。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	bool bReadable=true;

	/** 标识能力是否可以生成命令请求，界面可据此决定是否显示控制入口。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	bool bWritable=false;

	/** 数值能力的最小值，组件或蓝图控件可用它限制输入范围。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	float MinValue=0.0f;

	/** 数值能力的最大值，和 MinValue 一起描述平台允许的控制区间。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	float MaxValue=1.0f;

	/** 模式、预设或选择类能力的候选值列表，SetOption 会从这些值中提交目标选项。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	TArray<FString> OptionValues;
};

/** 表示平台实体在 GenericIOT 中的设备快照，子系统用它建立 DeviceId 与 EntityId 索引。 */
USTRUCT(BlueprintType)
struct GENERICIOTFRAMEWORK_API FIOTDeviceDescriptor
{
	GENERATED_BODY()

	/** GenericIOT 内部设备 ID，子系统缓存和组件绑定都以它作为主键。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString DeviceId;

	/** 设备来源平台，避免跨平台缓存或命令派发时丢失适配器上下文。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	EIOTPlatformKind PlatformKind=EIOTPlatformKind::Unknown;

	/** 平台原生实体 ID，组件可通过它绑定场景对象并反查内部 DeviceId。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString EntityId;

	/** 面向用户的设备名称，蓝图列表和 UI 展示通常使用该字段。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString DisplayName;

	/** 归一后的设备类型，用于筛选设备并决定默认能力展示方式。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	EIOTDeviceKind DeviceKind=EIOTDeviceKind::Unknown;

	/** 设备支持的能力集合，组件快捷命令和蓝图控制面板会据此决定可操作项。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	TArray<FIOTCapabilityDescriptor> CapabilityDescriptors;

	/** 平台原始域名，原生服务调用或调试映射问题时可回溯到平台实体分类。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString RawDomain;

	/** 平台原始属性快照，保留暂未归一的字段供扩展逻辑或蓝图读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	TMap<FString, FString> RawAttributes;
};

/** 保存设备当前状态快照，子系统按 DeviceId 缓存并通过组件事件同步到场景对象。 */
USTRUCT(BlueprintType)
struct GENERICIOTFRAMEWORK_API FIOTDeviceState
{
	GENERATED_BODY()

	/** 标识平台实体当前是否可用，组件 IsBoundEntityAvailable 直接读取该值。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	bool bAvailable=false;

	/** 平台主状态字符串，例如 on、off 或 unavailable，用于 UI 快速展示当前状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString PrimaryState;

	/** 按能力名称保存的当前值集合，读数和控制面板可按键读取状态。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	TMap<FString, FString> CapabilityValues;

	/** 平台侧最后更新时间，帮助上层判断状态新鲜度和事件顺序。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString LastUpdatedUtc;

	/** 平台原始状态文本，保留未解析状态以便调试或自定义扩展。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString RawState;
};

/** 表示一次发往设备的统一命令请求，子系统负责补全 RequestId 并交给平台适配器执行。 */
USTRUCT(BlueprintType)
struct GENERICIOTFRAMEWORK_API FIOTCommandRequest
{
	GENERATED_BODY()

	/** 命令请求标识，若为空子系统会生成 iot-* ID，用于异步结果匹配。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString RequestId;

	/** 目标内部设备 ID，适配器会通过它解析平台实体并派发服务调用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString DeviceId;

	/** 本次命令要操作的统一能力类型，平台适配器据此选择具体服务或参数格式。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	EIOTCapabilityKind CapabilityKind=EIOTCapabilityKind::Unknown;

	/** 命令语义名称，例如 TurnOn、SetValue 或 Raw:domain.service，用于适配器分派和日志。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString CommandName;

	/** 命令参数映射，数值、选项和原生服务参数都会通过该集合传给适配器。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	TMap<FString, FString> Parameters;
};

/** 表示平台命令执行后的统一结果，子系统广播后由异步节点和组件分发成功或失败事件。 */
USTRUCT(BlueprintType)
struct GENERICIOTFRAMEWORK_API FIOTCommandResult
{
	GENERATED_BODY()

	/** 对应请求的 ID，异步命令节点用它只接收自己发起的命令结果。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString RequestId;

	/** 命令目标设备 ID，组件用它过滤并只广播绑定设备的命令事件。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString DeviceId;

	/** 归一后的执行状态，蓝图可据此区分参数错误、鉴权失败或平台错误。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	EIOTCommandStatus Status=EIOTCommandStatus::PlatformError;

	/** 是否进入成功分支的快捷标记，组件和异步节点用它选择广播成功或失败委托。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	bool bSucceeded=false;

	/** 平台返回的错误代码或适配器定义的错误标识，用于诊断失败来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString ErrorCode;

	/** 面向调用方的失败说明，异步节点会把它随结果传给蓝图失败分支。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString ErrorMessage;

	/** 命令完成后得到的最新设备状态，适配器可用它帮助上层立即同步 UI。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FIOTDeviceState UpdatedState;

	/** 平台响应摘要，保留简化后的原始响应信息以便日志和蓝图调试。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="IOT")
	FString PlatformResponseSummary;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIOTConnectionStateChangedSignature, EIOTConnectionState, ConnectionState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIOTDeviceStateChangedSignature, FIOTDeviceDescriptor, Device, FIOTDeviceState, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIOTDevicesRefreshedSignature, int32, DeviceCount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIOTRealtimeStateChangedSignature, bool, bRealtimeActive);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIOTCommandCompletedSignature, FIOTCommandRequest, Request, FIOTCommandResult, Result);
