#pragma once

#include "CoreMinimal.h"
#include "CefViewTypes.h"
#include "UMG/CefView.h"
#include "GenericWebBrowserSettings.h"
#include "GenericWebWidgetBase.h"
#include "GenericWebBrowserWidget.generated.h"

#if WITH_EDITOR
class SWebBrowser;
#endif

/** 将通用 Web 控件接口适配到 UCefView 后端，负责状态同步、事件转发和脚本回调匹配。 */
UCLASS(MinimalAPI, BlueprintType)
class UGenericWebBrowserWidget : public UGenericWebWidgetBase
{
	GENERATED_BODY()

public:
	/** 初始化浏览器控件并声明自身使用 CEF 浏览器后端。 */
	GENERICWEBBROWSER_API UGenericWebBrowserWidget(const FObjectInitializer& ObjectInitializer);

	/** 传递给底层 UCefView 的输入命中和显示配置。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GenericWebBrowser")
	FGenericWebBrowserViewSettings ViewSettings;

	GENERICWEBBROWSER_API virtual void LoadUrl(const FString& InUrl) override;
	GENERICWEBBROWSER_API virtual void Reload() override;
	GENERICWEBBROWSER_API virtual void StopLoad() override;
	GENERICWEBBROWSER_API virtual void ExecuteJavascript(const FString& Script, FOnGenericWebScriptExecuted Callback) override;
	GENERICWEBBROWSER_API virtual void SetWebViewVisibility(ESlateVisibility InVisibility) override;

protected:
	GENERICWEBBROWSER_API virtual TSharedRef<SWidget> BuildWidgetInternal() override;
	GENERICWEBBROWSER_API virtual void DestroyWidgetInternal() override;
	GENERICWEBBROWSER_API virtual void SynchronizePropertiesInternal() override;

private:
	/** 判断当前平台或模块状态是否无法创建真实 CEF 视图。 */
	bool ShouldUsePlaceholderWidget() const;

#if WITH_EDITOR
	/** 尝试初始化 UCefView 使用的独立 CEF 上下文，失败时交给引擎 WebBrowser 兜底。 */
	bool TryEnsureLegacyCefBackend();

	/** 创建引擎 WebBrowser 后端，用于独立 CEF 已被占用或初始化失败时继续显示网页。 */
	TSharedRef<SWidget> BuildFallbackBrowserWidget();
#endif

	/** 根据当前导航状态和传入消息构造统一监控事件。 */
	void CreateMonitorEvent(EGenericWebMonitorEventType EventType, const FString& Message = FString(), bool bSuccess = false);

	/** 把通用配置写入底层 UCefView 实例。 */
	void ApplySettingsToLegacy();

#if WITH_EDITOR
	/** 接收引擎 WebBrowser 的加载开始事件并同步到通用导航状态。 */
	void HandleFallbackLoadStarted();

	/** 接收引擎 WebBrowser 的加载完成事件并广播通用加载结果。 */
	void HandleFallbackLoadCompleted();

	/** 接收引擎 WebBrowser 的加载失败事件并写入通用错误状态。 */
	void HandleFallbackLoadError();

	/** 接收引擎 WebBrowser 的地址变化并同步通用 URL 状态。 */
	void HandleFallbackUrlChanged(const FText& NewUrl);

	/** 接收引擎 WebBrowser 的标题变化并同步通用标题状态。 */
	void HandleFallbackTitleChanged(const FText& NewTitle);

	/** 禁用引擎 WebBrowser 的默认右键菜单，使行为与 UCefView 包装层保持一致。 */
	bool HandleFallbackSuppressContextMenu() const;
#endif

	/** 接收 UCefView 的加载状态变化并更新通用导航快照。 */
	UFUNCTION(Category="GenericWebBrowser")
	GENERICWEBBROWSER_API void HandleLegacyLoadStateChanged(const int64& BrowserId, bool bIsLoading, bool bCanGoBack, bool bCanGoForward);

	/** 接收 UCefView 的加载开始事件并广播通用加载开始。 */
	UFUNCTION(Category="GenericWebBrowser")
	GENERICWEBBROWSER_API void HandleLegacyLoadStart(const int64& BrowserId, const FCefFrameId& FrameId, bool bIsMainFrame, int TransitionType);

	/** 接收 UCefView 的加载结束事件并广播通用加载结果。 */
	UFUNCTION(Category="GenericWebBrowser")
	GENERICWEBBROWSER_API void HandleLegacyLoadEnd(const int64& BrowserId, const FCefFrameId& FrameId, bool bIsMainFrame, int HttpStatusCode);

	/** 接收 UCefView 的加载错误并写入通用错误状态。 */
	UFUNCTION(Category="GenericWebBrowser")
	GENERICWEBBROWSER_API void HandleLegacyLoadError(const int64& BrowserId, const FCefFrameId& FrameId, bool bIsMainFrame, int ErrorCode, const FString& ErrorMessage, const FString& FailedUrl);

	/** 接收 UCefView 地址变化并同步通用 URL 状态。 */
	UFUNCTION(Category="GenericWebBrowser")
	GENERICWEBBROWSER_API void HandleLegacyAddressChanged(const FCefFrameId& FrameId, const FString& NewAddress);

	/** 接收 UCefView 标题变化并同步通用标题状态。 */
	UFUNCTION(Category="GenericWebBrowser")
	GENERICWEBBROWSER_API void HandleLegacyTitleChanged(const FString& Title);

	/** 将页面主动调用的方法封装成通用消息事件。 */
	UFUNCTION(Category="GenericWebBrowser")
	GENERICWEBBROWSER_API void HandleLegacyInvokeMethod(const int64& BrowserId, const FCefFrameId& FrameId, const FString& Method, const FString& Arguments);

	/** 根据脚本上下文取回挂起回调并发送执行结果。 */
	UFUNCTION(Category="GenericWebBrowser")
	GENERICWEBBROWSER_API void HandleLegacyScriptResult(const int64& BrowserId, const FCefFrameId& FrameId, const FString& Context, const FString& Result);

	/** 持有实际承载 CEF 浏览器的 UMG 控件实例。 */
	UPROPERTY(Transient, DuplicateTransient, TextExportTransient)
	TObjectPtr<UCefView> LegacyWidget;

#if WITH_EDITOR
	/** 当 UCefView 无法接管进程级 CEF 时持有引擎 WebBrowser 的 Slate 实例。 */
	TSharedPtr<SWebBrowser> FallbackBrowserWidget;
#endif

	/** 按上下文标识缓存等待 CEF 异步返回的脚本回调。 */
	TMap<FString, FOnGenericWebScriptExecuted> PendingScriptCallbacks;
};
