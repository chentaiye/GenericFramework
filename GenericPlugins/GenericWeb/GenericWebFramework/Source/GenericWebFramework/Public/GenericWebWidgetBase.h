#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "GenericWebTypes.h"
#include "GenericWebWidgetBase.generated.h"

/** 抽象 Web 控件的公共状态、事件和后端能力查询，具体后端在派生类中接入。 */
UCLASS(MinimalAPI, Abstract)
class UGenericWebWidgetBase : public UWidget
{
	GENERATED_BODY()

public:
	/** 初始化控件基础状态，使尚未绑定后端时也能返回一致的查询结果。 */
	GENERICWEBFRAMEWORK_API UGenericWebWidgetBase(const FObjectInitializer& ObjectInitializer);

	GENERICWEBFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;
	GENERICWEBFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;
	GENERICWEBFRAMEWORK_API virtual void SynchronizeProperties() override;

	/** 控件创建底层 Web 视图后首次导航到的地址。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GenericWeb")
	FString InitialUrl;

	/** 当后端报告页面加载开始时向蓝图广播。 */
	UPROPERTY(BlueprintAssignable, Category="GenericWeb|Events")
	FOnGenericWebLoadStarted OnLoadStarted;

	/** 当后端报告页面加载结束或失败时向蓝图广播结果。 */
	UPROPERTY(BlueprintAssignable, Category="GenericWeb|Events")
	FOnGenericWebLoadCompleted OnLoadCompleted;

	/** 当地址、标题、加载中状态或历史导航能力变化时广播最新快照。 */
	UPROPERTY(BlueprintAssignable, Category="GenericWeb|Events")
	FOnGenericWebNavigationStateChanged OnNavigationStateChanged;

	/** 当页面脚本向宿主发送通用消息时广播。 */
	UPROPERTY(BlueprintAssignable, Category="GenericWeb|Events")
	FOnGenericWebMessageReceived OnMessageReceived;

	/** 当浏览器下载任务创建、更新或结束时广播。 */
	UPROPERTY(BlueprintAssignable, Category="GenericWeb|Events")
	FOnGenericWebDownloadUpdated OnDownloadUpdated;

	/** 汇总加载、导航、消息和下载等事件，供外部监控统一订阅。 */
	UPROPERTY(BlueprintAssignable, Category="GenericWeb|Events")
	FOnGenericWebMonitorEventReceived OnMonitorEvent;

	/** 启动URL，并把结果写入输出参数、持久化存储或回调链路。 */
	UFUNCTION(BlueprintCallable, Category="GenericWeb")
	GENERICWEBFRAMEWORK_API virtual void LoadUrl(const FString& InUrl);

	/** 请求后端重新加载当前页面。 */
	UFUNCTION(BlueprintCallable, Category="GenericWeb")
	GENERICWEBFRAMEWORK_API virtual void Reload();

	/** 请求后端停止当前加载流程。 */
	UFUNCTION(BlueprintCallable, Category="GenericWeb")
	GENERICWEBFRAMEWORK_API virtual void StopLoad();

	/** 在页面上下文执行脚本，并通过回调返回后端提供的执行结果。 */
	UFUNCTION(BlueprintCallable, Category="GenericWeb")
	GENERICWEBFRAMEWORK_API virtual void ExecuteJavascript(const FString& Script, FOnGenericWebScriptExecuted Callback);

	/** 同步 UMG 可见性到实际承载 Web 内容的底层控件。 */
	UFUNCTION(BlueprintCallable, Category="GenericWeb")
	GENERICWEBFRAMEWORK_API virtual void SetWebViewVisibility(ESlateVisibility InVisibility);

	/** 返回当前绑定的后端类型，便于业务层按实现能力分支。 */
	UFUNCTION(BlueprintPure, Category="GenericWeb")
	GENERICWEBFRAMEWORK_API virtual EGenericWebBackendType GetBackendType() const;

	/** 返回后端是否已初始化并可接收导航、脚本等操作。 */
	UFUNCTION(BlueprintPure, Category="GenericWeb")
	GENERICWEBFRAMEWORK_API virtual bool IsBackendAvailable() const;

	/** 返回最近一次由后端事件维护的导航状态快照。 */
	UFUNCTION(BlueprintPure, Category="GenericWeb")
	GENERICWEBFRAMEWORK_API virtual FGenericWebNavigationState GetNavigationState() const;

	/** 返回最近一次后端或操作失败记录。 */
	UFUNCTION(BlueprintPure, Category="GenericWeb")
	GENERICWEBFRAMEWORK_API virtual FGenericWebError GetLastError() const;

protected:
	/** 由派生类在完成后端选择后写入实际类型。 */
	GENERICWEBFRAMEWORK_API void SetBackendTypeInternal(EGenericWebBackendType InBackendType);

	/** 由派生类在后端初始化或失效时更新可用性。 */
	GENERICWEBFRAMEWORK_API void SetBackendAvailabilityInternal(bool bInAvailable);

	/** 统一记录派生实现遇到的最后一次错误。 */
	GENERICWEBFRAMEWORK_API void SetLastErrorInternal(const FGenericWebError& InError);

	/** 更新加载状态并广播加载开始事件。 */
	GENERICWEBFRAMEWORK_API void BroadcastLoadStartedInternal(const FString& Url);

	/** 更新加载结果、错误状态和导航快照后广播加载完成事件。 */
	GENERICWEBFRAMEWORK_API void BroadcastLoadCompletedInternal(const FGenericWebLoadResult& Result);

	/** 写入最新地址并触发导航状态变化广播。 */
	GENERICWEBFRAMEWORK_API void BroadcastUrlChangedInternal(const FString& Url);

	/** 写入最新标题并触发导航状态变化广播。 */
	GENERICWEBFRAMEWORK_API void BroadcastTitleChangedInternal(const FString& Title);

	/** 将当前导航状态快照发送给所有订阅者。 */
	GENERICWEBFRAMEWORK_API void BroadcastNavigationStateChangedInternal();

	/** 将页面脚本消息转发给普通消息事件和监控事件。 */
	GENERICWEBFRAMEWORK_API void BroadcastMessageReceivedInternal(const FGenericWebMessage& Message);

	/** 将下载进度转发给下载事件和监控事件。 */
	GENERICWEBFRAMEWORK_API void BroadcastDownloadUpdatedInternal(const FGenericWebDownloadInfo& DownloadInfo);

	/** 发送派生实现构造好的统一监控事件。 */
	GENERICWEBFRAMEWORK_API void BroadcastMonitorEventInternal(const FGenericWebMonitorEvent& EventInfo);

	/** 由派生类创建实际 Slate 控件，基类在 RebuildWidget 中调用。 */
	GENERICWEBFRAMEWORK_API virtual TSharedRef<SWidget> BuildWidgetInternal();

	/** 由派生类释放实际 Web 控件和后端引用。 */
	GENERICWEBFRAMEWORK_API virtual void DestroyWidgetInternal();

	/** 由派生类把 UPROPERTY 配置同步到底层控件。 */
	GENERICWEBFRAMEWORK_API virtual void SynchronizePropertiesInternal();

	/** 缓存供蓝图查询和事件广播使用的导航状态。 */
	FGenericWebNavigationState NavigationState;

	/** 缓存最近一次后端或操作失败详情。 */
	FGenericWebError LastError;

private:
	/** 当前派生类绑定的后端类型。 */
	EGenericWebBackendType BackendType = EGenericWebBackendType::None;

	/** 当前后端是否已准备好接收外部操作。 */
	bool bBackendAvailable = false;
};
