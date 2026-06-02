//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/Array.h>
#include <Containers/UnrealString.h>
#include <Delegates/DelegateCombinations.h>
#include <HAL/Platform.h>
#include <Math/IntRect.h>
#include <Templates/PimplPtr.h>
#include <UObject/NameTypes.h>
// CoreUObject/Public/
#include <UObject/ObjectMacros.h>
// UMG/Public/
#include <Components/Widget.h>
#include <Blueprint/UserWidget.h>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefViewTypes.h>
#include <CefContext.h>
#include <CefViewEvent.h>
#include <CefViewQuery.h>
#include <UMG/CefViewSettings.h>
#include <Slate/SCefView.h>
#pragma endregion

#pragma region "Generated Header"
#include "CefView.generated.h"
#pragma endregion

/** UMG 层的 CEF 浏览器控件，负责把蓝图 API 和事件桥接到 Slate CEF 视图。 */
UCLASS(MinimalAPI, BlueprintType)
class UCefView : public UWidget
{
  GENERATED_BODY()

public:
  /** 表示当前浏览器主框架的特殊帧标识。 */
  static UCEFVIEW_API const FCefFrameId MainFrameID;

  /** 表示向当前浏览器全部框架广播的特殊帧标识。 */
  static UCEFVIEW_API const FCefFrameId AllFrameID;

#pragma region Properties

public:
  /** 底层浏览器创建后导航到的目标地址。 */
  UPROPERTY(//
    BlueprintReadWrite, //
    EditInstanceOnly, //
    Category="CefView")
  FString Url;

  /** 控制页面右键菜单是否交由 Slate 菜单构建。 */
  UPROPERTY(//
    BlueprintReadWrite, //
    EditInstanceOnly, //
    Category="CefView")
  bool bEnableContextMenu=true;

  /** 控制控件是否接受外部拖拽数据进入浏览器。 */
  UPROPERTY(//
    BlueprintReadWrite, //
    EditInstanceOnly, //
    Category="CefView")
  bool bAcceptDrops=true;

  /** 控制页面发起的拖拽是否传递给 Slate 拖拽流程。 */
  UPROPERTY(//
    BlueprintReadWrite, //
    EditInstanceOnly, //
    Category="CefView")
  bool bAllowDrag=true;

  /** 允许低透明度像素把鼠标命中透传给下层控件。 */
  UPROPERTY(//
    BlueprintReadWrite, //
    EditInstanceOnly, //
    Category="CefView")
  bool bEnableAlphaHitTestPassthrough=false;

  /** 低于该透明度阈值的像素会被视为可透传区域。 */
  UPROPERTY(//
    BlueprintReadWrite, //
    EditInstanceOnly, //
    Category="CefView", //
    meta=(ClampMin="0", ClampMax="255", UIMin="0", UIMax="255", //
      EditCondition="bEnableAlphaHitTestPassthrough", //
      EditConditionHides))
  uint8 AlphaHitTestThreshold=0;

  /** 仅作用于当前视图的本地目录资源映射。 */
  UPROPERTY(//
    BlueprintReadOnly, //
    EditInstanceOnly, //
    Category="CefView")
  TArray<FLocalFolderResourceMapping> LocalFolderResourceMapping;

  /** 仅作用于当前视图的归档文件资源映射。 */
  UPROPERTY(//
    BlueprintReadOnly, //
    EditInstanceOnly, //
    Category="CefView")
  TArray<FArchiveFileResourceMapping> ArchiveFileResourceMapping;

  /** 当前视图使用的字体、语言和 Web 能力开关。 */
  UPROPERTY(//
    BlueprintReadOnly, //
    EditInstanceOnly, //
    Category="CefView")
  FCefViewSettings Settings;

#pragma endregion

#pragma region Constructor

public:
  /** 初始化 UMG 包装控件的默认浏览器状态。 */
  UCEFVIEW_API UCefView();

  UCEFVIEW_API virtual ~UCefView();
#pragma endregion

#pragma region Overrides

protected:
  /** Slate 控件桥接 */
  TSharedPtr<SCefView> SlateCefView;

  UCEFVIEW_API virtual TSharedRef<SWidget> RebuildWidget() override;

public:
  UCEFVIEW_API virtual void SynchronizeProperties() override;
  UCEFVIEW_API virtual void ReleaseSlateResources(bool bInReleaseChildren) override;

#if WITH_EDITOR
  UCEFVIEW_API virtual const FText GetPaletteCategory() override;
#endif
#pragma endregion

#pragma region Methods

public:
  /** 为当前视图追加本地目录资源映射。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void AddLocalFolderResource(const FString& InFolderPath, const FString& InTargetUrl, int32 InPriority = 0);

  /** 为当前视图追加归档文件资源映射。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void AddArchiveFileResource(const FString& InArchivePath,
                              const FString& InTargetUrl,
                              const FString& InPassword = "",
                              int32 InPriority = 0);

  /** 返回底层 CEF Browser 标识，浏览器尚未创建时返回无效值。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API int64 GetBrowserId();

  /** 请求底层浏览器导航到指定地址。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void NavigateToUrl(const FString& InTargetUrl);

  /** 查询底层浏览器历史栈是否可以后退。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool BrowserCanGoBack();

  /** 查询底层浏览器历史栈是否可以前进。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool BrowserCanGoForward();

  /** 让底层浏览器执行后退导航。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void BrowserGoBack();

  /** 让底层浏览器执行前进导航。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void BrowserGoForward();

  /** 查询底层浏览器当前是否处于加载中。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool IsBrowserLoading();

  /** 请求底层浏览器重新加载当前页面。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void BrowserReload();

  /** 请求底层浏览器停止当前加载流程。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void BrowserStopLoad();

  /** 向指定 CEF Frame 触发页面脚本事件。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool TriggerEventForFrame(const UCefViewEvent* InCefViewEvent, const FCefFrameId& InFrameId);

  /** 向主框架触发页面脚本事件。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool TriggerEventForMainFrame(const UCefViewEvent* InCefViewEvent);

  /** 向当前浏览器的所有框架广播页面脚本事件。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool BroadcastEvent(const UCefViewEvent* InCefViewEvent);

  /** 回复页面脚本发起并等待结果的 CEF 查询。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool ResponseUCefQuery(const UCefViewQuery* InCefQuery);

  /** 在指定框架执行脚本，不等待返回值。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool ExecuteJavascript(const FCefFrameId& InFrameId, const FString& InJavascriptCode, const FString& InTargetUrl);

  /** 在指定框架执行脚本，并通过结果事件携带上下文返回。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool ExecuteJavascriptWithResult(const FCefFrameId& InFrameId,
                                   const FString& InJavascriptCode,
                                   const FString& InTargetUrl,
                                   const FString& InExecuteContext);

  /** 写入 CEF 浏览器偏好项，并返回失败原因。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool SetPreference(const FString& InPreferenceName, const FString& InPreferenceValue, FString& InError);

  /** 控制弹窗浏览器是否禁用右键上下文菜单。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void SetDisablePopupContextMenu(bool bInIsDisable);

  /** 查询弹窗浏览器当前是否禁用了右键上下文菜单。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool IsPopupContextMenuDisabled();

  /** 查询当前浏览器是否已经打开开发者工具。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool HasDevTools();

  /** 打开当前浏览器的开发者工具窗口。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void ShowDevTools();

  /** 关闭当前浏览器的开发者工具窗口。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void CloseDevTools();

  /** 运行时切换浏览器拖放功能。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API void SetEnableDragAndDrop(bool bInIsEnable);

  /** 查询浏览器拖放功能是否启用。 */
  UFUNCTION(BlueprintCallable, Category="Default")
  UCEFVIEW_API bool IsDragAndDropEnabled() const;
#pragma endregion

#pragma region Events

public:
  DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnLoadStateChangedEvent,
                                                const int64&,
                                                InBrowserId,
                                                bool,
                                                bInIsLoading,
                                                bool,
                                                bInCanGoBack,
                                                bool,
                                                bInCanGoForward
    );

  /** 底层浏览器加载中状态或历史导航能力变化时广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnLoadStateChangedEvent OnLoadStateChanged;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnLoadStartEvent,
                                                const int64&,
                                                InBrowserId,
                                                const FCefFrameId&,
                                                InFrameId,
                                                bool,
                                                bInIsMainFrame,
                                                int,
                                                InTransitionType
    );

  /** CEF 报告某个 Frame 开始加载时广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnLoadStartEvent OnLoadStart;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnLoadEndEvent,
                                                const int64&,
                                                InBrowserId,
                                                const FCefFrameId&,
                                                InFrameId,
                                                bool,
                                                bInIsMainFrame,
                                                int,
                                                InHttpStatusCode
    );

  /** CEF 报告某个 Frame 加载结束时广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnLoadEndEvent OnLoadEnd;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FOnLoadErrorEvent,
                                               const int64&,
                                               InBrowserId,
                                               const FCefFrameId&,
                                               InFrameId,
                                               bool,
                                               bInIsMainFrame,
                                               int,
                                               InErrorCode,
                                               const FString&,
                                               InErrorMsg,
                                               const FString&,
                                               InFailedUrl
    );

  /** CEF 报告某个 Frame 加载失败时广播错误详情。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnLoadErrorEvent OnLoadError;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDraggableRegionChangedEvent,
                                               const FVector4&,
                                               InDraggableRegion,
                                               const FVector4&,
                                               InNonDraggableRegion
    );

  /** 页面可拖拽区域变化时广播给宿主窗口逻辑。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnDraggableRegionChangedEvent OnDraggableRegionChanged;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAddressChangedEvent,
                                               const FCefFrameId&,
                                               InFrameId,
                                               const FString&,
                                               InNewAddress
    );

  /** Frame 地址变化时广播最新地址。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnAddressChangedEvent OnAddressChanged;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTitleChangedEvent, const FString&, InTitle);

  /** 页面标题变化时广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnTitleChangedEvent OnTitleChanged;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFaviconUrlChangedEvent, const TArray<FString>&, InUrls);

  /** 页面图标 URL 列表变化时广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnFaviconUrlChangedEvent OnFaviconUrlChanged;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFullscreenModeChangedEvent, bool, bInFullscreen);

  /** 页面请求进入或退出全屏时广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnFullscreenModeChangedEvent OnFullscreenModeChanged;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStatusMessageEvent, const FString&, InMessage);

  /** CEF 状态栏消息变化时广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnStatusMessageEvent OnStatusMessage;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnConsoleMessageEvent, const FString&, InMessage, int32, InLevel);

  /** 页面控制台输出消息时广播文本和级别。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnConsoleMessageEvent OnConsoleMessage;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLoadingProgressChangedEvent, double, InProgress);

  /** CEF 报告加载进度变化时广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnLoadingProgressChangedEvent OnLoadingProgressChanged;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnUrlRequestEvent,
                                                 const int64&,
                                                 InBrowserId,
                                                 const FCefFrameId&,
                                                 InFrameId,
                                                 const FString&,
                                                 InRequestUrl
    );

  /** 在Url请求时广播给蓝图或上层监听者。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnUrlRequestEvent OnUrlRequest;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnQueryRequestEvent,
                                                 const int64&,
                                                 InBrowserId,
                                                 const FCefFrameId&,
                                                 InFrameId,
                                                 UCefViewQuery*,
                                                 InQuery
    );

  /** 页面脚本发起可回复查询时广播查询对象。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnQueryRequestEvent OnQueryRequest;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnInvokeMethodEvent,
                                                const int64&,
                                                InBrowserId,
                                                const FCefFrameId&,
                                                InFrameId,
                                                const FString&,
                                                InMethod,
                                                const FString&,
                                                InArguments
    );

  /** 页面脚本调用原生方法时广播方法名和参数文本。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnInvokeMethodEvent OnInvokeMethod;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnReportJavascriptResultEvent,
                                                const int64&,
                                                InBrowserId,
                                                const FCefFrameId&,
                                                InFrameId,
                                                const FString&,
                                                InContext,
                                                const FString&,
                                                InResult
    );

  /** 脚本执行完成并回传结果时广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnReportJavascriptResultEvent OnReportJavascriptResult;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNativeBrowserCreatedEvent);

  /** CEF 原生 Browser 对象创建完成后广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnNativeBrowserCreatedEvent OnNativeBrowserCreated;

  DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(FOnCreateNewBrowserEvent,
                                                const FCefFrameId&,
                                                InSourceFrameId,
                                                const FString&,
                                                InUrl,
                                                const FString&,
                                                InName,
                                                const ECefWindowOpenDisposition&,
                                                InTargetDisposition,
                                                const FVector4&,
                                                InRect
    );

  /** 页面请求创建新浏览器窗口时广播。 */
  UPROPERTY(BlueprintAssignable, Category="Events")
  FOnCreateNewBrowserEvent OnCreateNewBrowser;

#pragma endregion

protected:
  /** 将 Slate 层的新浏览器请求转发为蓝图事件。 */
  UCEFVIEW_API void OnNewBrowser(const FCefFrameId& InSourceFrameId,
                    const FString& InUrl,
                    const FString& InName,
                    ECefWindowOpenDisposition InTargetDisposition,
                    FIntRect& InRect);

  /** 允许宿主在 CEF 创建弹窗前修改目标、设置和脚本访问权限。 */
  UCEFVIEW_API bool OnNewPopup(const FCefFrameId& InFrameId,
                  const FString& InTargetUrl,
                  FString& InTargetFrameName,
                  ECefWindowOpenDisposition InTargetDisposition,
                  FIntRect& InRect,
                  FSlateCefViewSettings& InSettings,
                  bool& bInDisableJavascriptAccess);

  /** 响应请求Close来源Web回调，并把外部事件转换为当前对象状态或委托通知。 */
  UCEFVIEW_API bool OnRequestCloseFromWeb();

#pragma region Slate Event Handlers

protected:
  /** 接收 Slate 加载状态变化并广播给 UMG 订阅者。 */
  UCEFVIEW_API void OnSlateLoadStateChangedEvent(const int64& InBrowserId,
                                    bool bInIsLoading,
                                    bool bInCanGoBack,
                                    bool bInCanGoForward);

  /** 接收 Slate 加载开始事件并广播给 UMG 订阅者。 */
  UCEFVIEW_API void OnSlateLoadStartEvent(const int64& InBrowserId,
                             const FCefFrameId& InFrameId,
                             bool bInIsMainFrame,
                             int InTransitionType);

  /** 接收 Slate 加载结束事件并广播给 UMG 订阅者。 */
  UCEFVIEW_API void OnSlateLoadEndEvent(const int64& InBrowserId,
                           const FCefFrameId& InFrameId,
                           bool bInIsMainFrame,
                           int InHttpStatusCode);

  /** 接收 Slate 加载错误事件并允许 UMG 层标记是否已处理。 */
  UCEFVIEW_API void OnSlateLoadErrorEvent(const int64& InBrowserId,
                             const FCefFrameId& InFrameId,
                             bool bInIsMainFrame,
                             int InErrorCode,
                             const FString& InErrorMsg,
                             const FString& InFailedUrl,
                             bool& bInHandled);

  /** 转发页面可拖拽区域变化。 */
  UCEFVIEW_API void OnSlateDraggableRegionChangedEvent(const FVector4& InDraggableRegion, const FVector4& InNonDraggableRegion);

  /** 转发 Frame 地址变化。 */
  UCEFVIEW_API void OnSlateAddressChangedEvent(const FCefFrameId& InFrameId, const FString& InNewAddress);

  /** 转发页面标题变化。 */
  UCEFVIEW_API void OnSlateTitleChangedEvent(const FString& InTitle);

  /** 转发页面图标 URL 列表变化。 */
  UCEFVIEW_API void OnSlateFaviconUrlChangedEvent(const TArray<FString>& InUrls);

  /** 转发页面全屏状态变化。 */
  UCEFVIEW_API void OnSlateFullscreenModeChangedEvent(bool bInFullscreen);

  /** 转发 CEF 状态消息。 */
  UCEFVIEW_API void OnSlateStatusMessageEvent(const FString& InMessage);

  /** 转发页面控制台消息。 */
  UCEFVIEW_API void OnSlateConsoleMessageEvent(const FString& InMessage, int32 InLevel);

  /** 转发页面加载进度变化。 */
  UCEFVIEW_API void OnSlateLoadingProgressChangedEvent(double InProgress);

  /** 转发页面脚本提交的 URL 请求。 */
  UCEFVIEW_API void OnSlateUrlRequestEvent(const int64& InBrowserId, const FCefFrameId& InFrameId, const FString& InRequestUrl);

  /** 将 Slate 查询请求包装为 UCefViewQuery 后广播。 */
  UCEFVIEW_API void OnSlateQueryRequestEvent(const int64& InBrowserId,
                                const FCefFrameId& InFrameId,
                                const int64& InQueryId,
                                const FString& InRequest);

  /** 将 Slate 原生方法调用参数序列化后广播。 */
  UCEFVIEW_API void OnSlateInvokeMethodEvent(const int64& InBrowserId,
                                const FCefFrameId& InFrameId,
                                const FString& InMethod,
                                const TArray<TSharedPtr<FJsonValue>>& InArguments);

  /** 将 Slate 脚本结果转换为字符串后广播。 */
  UCEFVIEW_API void OnSlateReportJavascriptResultEvent(const int64& InBrowserId,
                                          const FCefFrameId& InFrameId,
                                          const FString& InContext,
                                          const TSharedPtr<FJsonValue>& InResult);

  /** 转发原生 CEF Browser 创建完成事件。 */
  UCEFVIEW_API void OnSlateNativeBrowserCreatedEvent();

  /** 转发页面新窗口请求给 UMG 事件订阅者。 */
  UCEFVIEW_API void OnSlateCreateNewBrowserEvent(const FCefFrameId& InSourceFrameId,
                                    const FString& InUrl,
                                    const FString& InName,
                                    const ECefWindowOpenDisposition& InTargetDisposition,
                                    const FIntRect& InRect);
};
