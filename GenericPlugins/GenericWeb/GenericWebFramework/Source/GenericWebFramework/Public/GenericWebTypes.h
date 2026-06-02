#pragma once

#include "CoreMinimal.h"
#include "GenericWebTypes.generated.h"

/** 标识通用 Web 控件当前使用的渲染后端，供上层在不同实现之间做能力判断。 */
UENUM(BlueprintType)
enum class EGenericWebBackendType : uint8
{
	/** 尚未绑定任何可用后端。 */
	None UMETA(DisplayName="None"),

	/** 使用项目配置或运行环境选择的默认后端。 */
	Default UMETA(DisplayName="Default"),

	/** 使用原生窗口承载 Web 内容。 */
	Window UMETA(DisplayName="Window"),

	/** 使用内嵌浏览器控件承载 Web 内容。 */
	Browser UMETA(DisplayName="Browser")
};

/** 描述页面加载生命周期，供控件状态和加载结果事件复用。 */
UENUM(BlueprintType)
enum class EGenericWebLoadState : uint8
{
	/** 尚未开始加载或后端尚未完成初始化。 */
	Uninitialized UMETA(DisplayName="Uninitialized"),

	/** 当前存在进行中的导航或资源加载。 */
	Loading UMETA(DisplayName="Loading"),

	/** 最近一次主流程加载已完成。 */
	Completed UMETA(DisplayName="Completed"),

	/** 最近一次加载因网络、后端或页面错误失败。 */
	Failed UMETA(DisplayName="Failed")
};

/** 映射浏览器下载回调中的进度状态，用于向蓝图层报告下载生命周期。 */
UENUM(BlueprintType)
enum class EGenericWebDownloadState : uint8
{
	/** 下载仍在进行，字节计数可能继续变化。 */
	InProgress UMETA(DisplayName="In Progress"),

	/** 下载被浏览器、网络或用户操作中断。 */
	Interrupted UMETA(DisplayName="Interrupted"),

	/** 下载已经写入目标路径并结束。 */
	Completed UMETA(DisplayName="Completed")
};

/** 统一描述 Web 控件可观测事件，便于外层只订阅一个监控通道。 */
UENUM(BlueprintType)
enum class EGenericWebMonitorEventType : uint8
{
	/** 无法归类或后端未提供明确语义的事件。 */
	Unknown UMETA(DisplayName="Unknown"),

	/** 页面或主框架开始加载。 */
	LoadStarted UMETA(DisplayName="Load Started"),

	/** 页面或主框架加载结束。 */
	LoadCompleted UMETA(DisplayName="Load Completed"),

	/** 当前地址发生变化。 */
	UrlChanged UMETA(DisplayName="URL Changed"),

	/** 页面标题发生变化。 */
	TitleChanged UMETA(DisplayName="Title Changed"),

	/** 页面脚本向原生层发送消息。 */
	MessageReceived UMETA(DisplayName="Message Received"),

	/** 下载任务的进度或状态发生变化。 */
	DownloadUpdated UMETA(DisplayName="Download Updated"),

	/** 页面请求浏览器或宿主授权某项能力。 */
	PermissionRequested UMETA(DisplayName="Permission Requested"),

	/** 页面脚本发起需要原生层响应的查询。 */
	QueryReceived UMETA(DisplayName="Query Received"),

	/** 页面控制台输出消息。 */
	ConsoleMessage UMETA(DisplayName="Console Message")
};

/** 保存当前模块流程中的通用WebNavigation状态数据，供运行时传递和蓝图访问。 */
USTRUCT(BlueprintType)
struct GENERICWEBFRAMEWORK_API FGenericWebNavigationState
{
	GENERATED_BODY()

	/** 当前主框架地址。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Url;

	/** 浏览器最近一次回调的页面标题。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Title;

	/** 指示后端当前是否仍在加载页面或资源。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	bool bIsLoading = false;

	/** 指示浏览器历史栈是否可以后退。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	bool bCanGoBack = false;

	/** 指示浏览器历史栈是否可以前进。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	bool bCanGoForward = false;

	/** 主流程加载阶段，补充区分未初始化、加载中、完成和失败。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	EGenericWebLoadState LoadState = EGenericWebLoadState::Uninitialized;
};

/** 表示一次页面加载完成后的结果，随加载完成事件向外广播。 */
USTRUCT(BlueprintType)
struct GENERICWEBFRAMEWORK_API FGenericWebLoadResult
{
	GENERATED_BODY()

	/** 指示这次加载是否被视为成功。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	bool bSuccess = false;

	/** 后端提供的 HTTP 状态码或错误码。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	int32 StatusCode = 0;

	/** 触发结果的页面地址。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Url;

	/** 加载失败时提供给业务层的错误说明。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString ErrorText;
};

/** 汇总浏览器下载任务的地址、目标文件和进度信息。 */
USTRUCT(BlueprintType)
struct GENERICWEBFRAMEWORK_API FGenericWebDownloadInfo
{
	GENERATED_BODY()

	/** 下载源地址。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Uri;

	/** 浏览器识别出的资源 MIME 类型。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString MimeType;

	/** 下载任务最终写入的本地文件路径。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString ResultFilePath;

	/** 当前已经接收的字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	int64 BytesReceived = 0;

	/** 预计需要接收的总字节数，未知时保持为负值。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	int64 TotalBytesToReceive = -1;

	/** 下载任务当前阶段。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	EGenericWebDownloadState State = EGenericWebDownloadState::InProgress;
};

/** 承载脚本执行回调的数据，允许调用方用上下文串匹配异步结果。 */
USTRUCT(BlueprintType)
struct GENERICWEBFRAMEWORK_API FGenericWebScriptResult
{
	GENERATED_BODY()

	/** 指示脚本是否成功执行并返回结果。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	bool bSuccess = false;

	/** 后端返回的脚本结果文本。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Result;

	/** 调用脚本时注入的上下文标识，用于匹配回调。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Context;

	/** 脚本执行失败时的错误说明。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString ErrorText;
};

/** 表示页面脚本发往宿主层的一条通用消息。 */
USTRUCT(BlueprintType)
struct GENERICWEBFRAMEWORK_API FGenericWebMessage
{
	GENERATED_BODY()

	/** 记录名称。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Name;

	/** 页面传入的消息载荷，通常是 JSON 或约定文本。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Payload;

	/** 消息来源地址或框架标识。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Source;
};

/** 记录最近一次后端或操作错误，供控件查询和失败事件复用。 */
USTRUCT(BlueprintType)
struct GENERICWEBFRAMEWORK_API FGenericWebError
{
	GENERATED_BODY()

	/** 指示当前快照是否包含有效错误。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	bool bHasError = false;

	/** 业务层可判断的错误码。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	int32 Code = 0;

	/** 面向日志或 UI 展示的错误说明。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Message;

	/** 产生错误的后端类型。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	EGenericWebBackendType Backend = EGenericWebBackendType::None;
};

/** 表示页面尝试打开新窗口时传递给宿主层的请求信息。 */
USTRUCT(BlueprintType)
struct GENERICWEBFRAMEWORK_API FGenericWebPopupRequest
{
	GENERATED_BODY()

	/** 弹窗目标地址。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Url;

	/** 页面指定的新窗口或目标框架名称。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString TargetFrameName;
};

/** 保存当前模块流程中的通用WebMonitor事件数据，供运行时传递和蓝图访问。 */
USTRUCT(BlueprintType)
struct GENERICWEBFRAMEWORK_API FGenericWebMonitorEvent
{
	GENERATED_BODY()

	/** 说明当前事件快照对应的监控类型。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	EGenericWebMonitorEventType EventType = EGenericWebMonitorEventType::Unknown;

	/** 事件关联的页面或资源地址。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Url;

	/** 事件发生时后端记录的页面标题。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Title;

	/** 事件的主要文本内容。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Message;

	/** 事件的补充详情，供日志或调试面板展示。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString Detail;

	/** 下载类事件关联的本地文件路径。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	FString ResultFilePath;

	/** 下载类事件已接收的字节数。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	int64 BytesReceived = 0;

	/** 下载类事件预计接收的总字节数，未知时保持为负值。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	int64 TotalBytesToReceive = -1;

	/** 说明事件对应操作是否成功完成。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	bool bSuccess = false;

	/** 导航类事件发生时浏览器是否可以后退。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	bool bCanGoBack = false;

	/** 导航类事件发生时浏览器是否可以前进。 */
	UPROPERTY(BlueprintReadOnly, Category="GenericWeb")
	bool bCanGoForward = false;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGenericWebLoadStarted, const FString&, Url);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGenericWebLoadCompleted, const FGenericWebLoadResult&, Result);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGenericWebNavigationStateChanged, const FGenericWebNavigationState&, State);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGenericWebMessageReceived, const FGenericWebMessage&, Message);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGenericWebDownloadUpdated, const FGenericWebDownloadInfo&, DownloadInfo);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnGenericWebMonitorEventReceived, const FGenericWebMonitorEvent&, EventInfo);

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnGenericWebScriptExecuted, const FGenericWebScriptResult&, Result);
