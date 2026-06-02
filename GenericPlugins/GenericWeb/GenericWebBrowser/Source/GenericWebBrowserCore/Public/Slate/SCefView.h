//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Containers/UnrealString.h>
#include <Delegates/DelegateCombinations.h>
// Core/Public/
#include <HAL/Platform.h>
#include <Misc/Optional.h>
#include <Templates/SharedPointer.h>
// Json/Public/
#include <Dom/JsonValue.h>
// SlateCore/Public/
#include <Layout/Children.h>
#include <Widgets/DeclarativeSyntaxSupport.h>
#include <Widgets/SWidget.h>
#pragma endregion

#pragma region <Project Public Headers>
#include <CefViewTypes.h>
#include <CefContext.h>
#include <Slate/SlateCefViewSettings.h>
#pragma endregion

class SCefViewPrivate;
class CCefClientDelegate;

/** Slate 层的 CEF 浏览器控件，直接承接渲染、输入和 CEF 客户端回调。 */
class UCEFVIEW_API SCefView : public SWidget
{
  SLATE_DECLARE_WIDGET(SCefView, SWidget)

private:
  /** 隐藏平台渲染、输入桥接和 CEF Browser 生命周期实现。 */
  TSharedPtr<SCefViewPrivate> m_pImpl = nullptr;

  friend class SCefViewPrivate;
  friend class CCefClientDelegate;

  /** 创建原生浏览器后导航到的目标地址。 */
  FString Url;

  /** 控制 CEF 上下文菜单是否映射到 Slate 菜单。 */
  bool bEnableContextMenu = true;

  /** 控制 Slate 拖放事件是否传入 CEF。 */
  bool bAcceptDrops = true;

  /** 控制 CEF 页面发起的拖拽是否交给 Slate 拖拽系统。 */
  bool bAllowDrag = true;

  /** 允许透明区域把鼠标命中透传给下层控件。 */
  bool bEnableAlphaHitTestPassthrough = false;

  /** 低于该透明度阈值的像素会被视为可透传区域。 */
  uint8 AlphaHitTestThreshold = 0;

  /** 记录外部请求的可见性，便于在 CEF 视图和 Slate 命中逻辑间同步。 */
  EVisibility RequestedVisibility = EVisibility::Visible;

  /** 标记当前指针位置是否已经进入透明透传状态。 */
  bool bIsAlphaInputPassthroughActive = false;

  /** 当前视图独有的本地目录资源映射。 */
  TArray<FLocalFolderResourceMapping> LocalFolderResourceMapping;

  /** 当前视图独有的归档文件资源映射。 */
  TArray<FArchiveFileResourceMapping> ArchiveFileResourceMapping;

#pragma region Type/Constans
public:
  /** 表示当前浏览器主框架的特殊帧标识。 */
  static const FCefFrameId MainFrameID;

  /** 表示向当前浏览器全部框架广播的特殊帧标识。 */
  static const FCefFrameId AllFrameID;

  DECLARE_DELEGATE_FourParams(FOnLoadStateChangedEvent,
                              const int64& InBrowserId,
                              bool bInIsLoading,
                              bool bInCanGoBack,
                              bool bInCanGoForward);

  DECLARE_DELEGATE_FourParams(FOnLoadStartEvent,
                              const int64& InBrowserId,
                              const FCefFrameId& InFrameId,
                              bool bInIsMainFrame,
                              int InTransitionType);

  DECLARE_DELEGATE_FourParams(FOnLoadEndEvent,
                              const int64& InBrowserId,
                              const FCefFrameId& InFrameId,
                              bool bInIsMainFrame,
                              int InHttpStatusCode);

  DECLARE_DELEGATE_SevenParams(FOnLoadErrorEvent,
                               const int64& InBrowserId,
                               const FCefFrameId& InFrameId,
                               bool bInIsMainFrame,
                               int InErrorCode,
                               const FString& InErrorMsg,
                               const FString& InOutFailedUrl,
                               bool& InOutHandled);

  DECLARE_DELEGATE_TwoParams(FOnDraggableRegionChangedEvent,
                             const FVector4& InDraggableRegion,
                             const FVector4& InNonDraggableRegion);

  DECLARE_DELEGATE_TwoParams(FOnAddressChangedEvent, const FCefFrameId& InFrameId, const FString& InUrl);
  DECLARE_DELEGATE_OneParam(FOnTitleChangedEvent, const FString& InTitle);
  DECLARE_DELEGATE_OneParam(FOnFaviconUrlChangedEvent, const TArray<FString>& InUrls);
  DECLARE_DELEGATE_OneParam(FOnFullscreenModeChangedEvent, bool bInIsFullscreen);
  DECLARE_DELEGATE_OneParam(FOnStatusMessageEvent, const FString& InMessage);
  DECLARE_DELEGATE_TwoParams(FOnConsoleMessageEvent, const FString& InMessage, int32 InLevel);
  DECLARE_DELEGATE_OneParam(FOnLoadingProgressChangedEvent, double InProgress);
  DECLARE_DELEGATE_ThreeParams(FOnUrlRequestEvent,
                               const int64& InBrowserId,
                               const FCefFrameId& InFrameId,
                               const FString& InQuery);

  DECLARE_DELEGATE_FourParams(FOnQueryRequestEvent,
                              const int64& InBrowserId,
                              const FCefFrameId& InFrameId,
                              const int64& InQueryId,
                              const FString& InRequest);

  DECLARE_DELEGATE_FourParams(FOnInvokeMethodEvent,
                              const int64& InBrowserId,
                              const FCefFrameId& InFrameId,
                              const FString& InMethod,
                              const TArray<TSharedPtr<FJsonValue>>& InArguments);

  DECLARE_DELEGATE_FourParams(FOnReportJavascriptResultEvent,
                              const int64& InBrowserId,
                              const FCefFrameId& InFrameId,
                              const FString& InContext,
                              const TSharedPtr<FJsonValue>& InResult);

  DECLARE_DELEGATE(FOnNativeBrowserCreatedEvent);
  DECLARE_DELEGATE_FiveParams(FOnCreateNewBrowserEvent,
                              const FCefFrameId& InSourceFrameId,
                              const FString& InUrl,
                              const FString& InName,
                              const ECefWindowOpenDisposition& InTargetDisposition,
                              const FIntRect& InRect);
#pragma endregion

#pragma region Agurments & Properties
  /** 声明 Slate 创建参数，供 UMG 包装层传入初始配置和事件。 */
  SLATE_BEGIN_ARGS(SCefView) {}

  /** 初始导航地址。 */
  SLATE_ARGUMENT(FString, Url)

  /** 是否启用页面上下文菜单。 */
  SLATE_ARGUMENT(bool, bEnableContextMenu);

  /** 是否接受外部拖放数据。 */
  SLATE_ARGUMENT(bool, bAcceptDrops);

  /** 是否允许页面发起拖拽。 */
  SLATE_ARGUMENT(bool, bAllowDrag);

  /** 是否启用透明区域命中透传。 */
  SLATE_ARGUMENT(bool, bEnableAlphaHitTestPassthrough);

  /** 透明区域命中透传阈值。 */
  SLATE_ARGUMENT(uint8, AlphaHitTestThreshold);

  /** 单个视图的 CEF 设置。 */
  SLATE_ARGUMENT(FSlateCefViewSettings, Settings)

  /** CEF 加载状态变化事件。 */
  SLATE_EVENT(FOnLoadStateChangedEvent, OnLoadStateChanged)

  /** CEF Frame 加载开始事件。 */
  SLATE_EVENT(FOnLoadStartEvent, OnLoadStart)

  /** CEF Frame 加载结束事件。 */
  SLATE_EVENT(FOnLoadEndEvent, OnLoadEnd)

  /** CEF Frame 加载失败事件。 */
  SLATE_EVENT(FOnLoadErrorEvent, OnLoadError)

  /** 页面可拖拽区域变化事件。 */
  SLATE_EVENT(FOnDraggableRegionChangedEvent, OnDraggableRegionChanged)

  /** Frame 地址变化事件。 */
  SLATE_EVENT(FOnAddressChangedEvent, OnAddressChanged)

  /** 页面标题变化事件。 */
  SLATE_EVENT(FOnTitleChangedEvent, OnTitleChanged)

  /** 页面图标 URL 列表变化事件。 */
  SLATE_EVENT(FOnFaviconUrlChangedEvent, OnFaviconUrlChanged)

  /** 页面全屏状态变化事件。 */
  SLATE_EVENT(FOnFullscreenModeChangedEvent, OnFullscreenModeChanged)

  /** CEF 状态栏消息事件。 */
  SLATE_EVENT(FOnStatusMessageEvent, OnStatusMessage)

  /** 页面控制台消息事件。 */
  SLATE_EVENT(FOnConsoleMessageEvent, OnConsoleMessage)

  /** 页面加载进度变化事件。 */
  SLATE_EVENT(FOnLoadingProgressChangedEvent, OnLoadingProgressChanged)

  /** 页面脚本 URL 请求事件。 */
  SLATE_EVENT(FOnUrlRequestEvent, OnUrlRequest)

  /** 页面脚本可回复查询事件。 */
  SLATE_EVENT(FOnQueryRequestEvent, OnQueryRequest)

  /** 页面脚本调用原生方法事件。 */
  SLATE_EVENT(FOnInvokeMethodEvent, OnInvokeMethod)

  /** 页面脚本执行结果回传事件。 */
  SLATE_EVENT(FOnReportJavascriptResultEvent, OnReportJavascriptResult)

  /** CEF 原生 Browser 创建完成事件。 */
  SLATE_EVENT(FOnNativeBrowserCreatedEvent, OnNativeBrowserCreated)

  /** 页面请求创建新浏览器事件。 */
  SLATE_EVENT(FOnCreateNewBrowserEvent, OnCreateNewBrowser)

  //
  SLATE_END_ARGS()
#pragma endregion

#pragma region Constructors
  /** 创建尚未绑定原生浏览器的 Slate CEF 视图。 */
  SCefView();

  ~SCefView();

  /** 读取 Slate 参数并创建底层 CEF 浏览器。 */
  void Construct(const FArguments& InArgs);
#pragma endregion

#pragma region Getters & Setters
  /** 更新目标地址并驱动底层浏览器导航。 */
  void SetUrl(const FString& InUrl);

  /** 返回当前记录的目标地址。 */
  FString GetUrl() const;

  /** 切换页面右键菜单映射。 */
  void SetEnableContextMenu(bool bInEnableContextMenu);

  /** 查询页面右键菜单是否启用。 */
  bool IsContextMenuEnabled() const;

  /** 切换外部拖放数据接收。 */
  void SetAcceptDrops(bool bInAcceptDrops);

  /** 查询当前是否接受外部拖放数据。 */
  bool IsAcceptDrops() const;

  /** 切换页面发起拖拽的支持。 */
  void SetAllowDrag(bool bInAllowDrag);

  /** 查询页面发起拖拽是否启用。 */
  bool IsAllowDrag() const;

  /** 切换透明区域命中透传。 */
  void SetEnableAlphaHitTestPassthrough(bool bInEnableAlphaHitTestPassthrough);

  /** 查询透明区域命中透传是否启用。 */
  bool IsAlphaHitTestPassthroughEnabled() const;

  /** 设置透明区域命中透传阈值。 */
  void SetAlphaHitTestThreshold(uint8 InAlphaHitTestThreshold);

  /** 返回透明区域命中透传阈值。 */
  uint8 GetAlphaHitTestThreshold() const;
#pragma endregion

protected:
  /** 根据当前 Slate 参数创建原生 CEF Browser。 */
  void CreateNativeBrowser(const FSlateCefViewSettings& InCefViewSettings);

  /** 销毁原生 CEF Browser 并释放渲染资源。 */
  void DestroyNativeBrowser();

#pragma region Methods
public:
  /** 为当前视图追加本地目录资源映射。 */
  void AddLocalFolderResource(const FString& InFolderPath, const FString& InTargetUrl, int32 InPriority = 0);

  /** 为当前视图追加归档文件资源映射。 */
  void AddArchiveFileResource(const FString& InArchivePath,
                              const FString& InTargetUrl,
                              const FString& InPassword = "",
                              int32 InPriority = 0);

  /** 返回底层 CEF Browser 标识，浏览器尚未创建时返回无效值。 */
  int64 GetBrowserId() const;

  /** 查询底层浏览器历史栈是否可以后退。 */
  bool BrowserCanGoBack();

  /** 查询底层浏览器历史栈是否可以前进。 */
  bool BrowserCanGoForward();

  /** 让底层浏览器执行后退导航。 */
  void BrowserGoBack();

  /** 让底层浏览器执行前进导航。 */
  void BrowserGoForward();

  /** 查询底层浏览器当前是否处于加载中。 */
  bool IsBrowserLoading();

  /** 请求底层浏览器重新加载当前页面。 */
  void BrowserReload();

  /** 请求底层浏览器停止当前加载流程。 */
  void BrowserStopLoad();

  /** 向指定 CEF Frame 触发页面脚本事件。 */
  bool TriggerEventForFrame(const FString& InName,
                            const TArray<TSharedPtr<FJsonValue>>& InArgs,
                            const FCefFrameId& InFrameId);

  /** 向主框架触发页面脚本事件。 */
  bool TriggerEventForMainFrame(const FString& InName, const TArray<TSharedPtr<FJsonValue>>& InArgs);

  /** 向当前浏览器的所有框架广播页面脚本事件。 */
  bool BroadcastEvent(const FString& InName, const TArray<TSharedPtr<FJsonValue>>& InArgs);

  /** 回复页面脚本发起并等待结果的 CEF 查询。 */
  bool ResponseUCefQuery(const int64 InQueryId,
                         const bool bInIsSuccess,
                         const FString& InResponse,
                         const int32 InError);

  /** 在指定框架执行脚本，不等待返回值。 */
  bool ExecuteJavascript(const FCefFrameId& InFrameId, const FString& InJavascriptCode, const FString& InTargetUrl);

  /** 在指定框架执行脚本，并通过结果事件携带上下文返回。 */
  bool ExecuteJavascriptWithResult(const FCefFrameId& InFrameId,
                                   const FString& InJavascriptCode,
                                   const FString& InTargetUrl,
                                   const FString& InExecuteContext);

  /** 写入 CEF 浏览器偏好项，并返回失败原因。 */
  bool SetPreference(const FString& InPreferenceName, const FString& InPreferenceValue, FString& OutError);

  /** 控制弹窗浏览器是否禁用右键上下文菜单。 */
  void SetDisablePopupContextMenu(bool bInIsDisable);

  /** 查询弹窗浏览器当前是否禁用了右键上下文菜单。 */
  bool IsPopupContextMenuDisabled();

  /** 查询当前浏览器是否已经打开开发者工具。 */
  bool HasDevTools();

  /** 打开当前浏览器的开发者工具窗口。 */
  void ShowDevTools();

  /** 关闭当前浏览器的开发者工具窗口。 */
  void CloseDevTools();

#pragma endregion

#pragma region Events
protected:
  /** CEF 加载中状态或历史导航能力变化时触发。 */
  FOnLoadStateChangedEvent OnLoadStateChanged;

  /** CEF Frame 开始加载时触发。 */
  FOnLoadStartEvent OnLoadStart;

  /** CEF Frame 加载结束时触发。 */
  FOnLoadEndEvent OnLoadEnd;

  /** CEF Frame 加载失败时触发。 */
  FOnLoadErrorEvent OnLoadError;

  /** 页面可拖拽区域变化时触发。 */
  FOnDraggableRegionChangedEvent OnDraggableRegionChanged;

  /** Frame 地址变化时触发。 */
  FOnAddressChangedEvent OnAddressChanged;

  /** 页面标题变化时触发。 */
  FOnTitleChangedEvent OnTitleChanged;

  /** 页面图标 URL 列表变化时触发。 */
  FOnFaviconUrlChangedEvent OnFaviconUrlChanged;

  /** 页面全屏状态变化时触发。 */
  FOnFullscreenModeChangedEvent OnFullscreenModeChanged;

  /** CEF 状态栏消息变化时触发。 */
  FOnStatusMessageEvent OnStatusMessage;

  /** 页面控制台输出消息时触发。 */
  FOnConsoleMessageEvent OnConsoleMessage;

  /** 页面加载进度变化时触发。 */
  FOnLoadingProgressChangedEvent OnLoadingProgressChanged;

  /** 页面脚本提交 URL 请求时触发。 */
  FOnUrlRequestEvent OnUrlRequest;

  /** 页面脚本发起可回复查询时触发。 */
  FOnQueryRequestEvent OnQueryRequest;

  /** 页面脚本调用原生方法时触发。 */
  FOnInvokeMethodEvent OnInvokeMethod;

  /** 脚本执行结果回传时触发。 */
  FOnReportJavascriptResultEvent OnReportJavascriptResult;

  /** CEF 原生 Browser 创建完成时触发。 */
  FOnNativeBrowserCreatedEvent OnNativeBrowserCreated;

  /** 页面请求创建新浏览器时触发。 */
  FOnCreateNewBrowserEvent OnCreateNewBrowser;
#pragma endregion

#pragma region Inner Methods
protected:
  /** 将新浏览器请求转交给上层事件。 */
  void OnNewBrowser(const FCefFrameId& InSourceFrameId,
                    const FString& InTargetUrl,
                    const FString& InFrameName,
                    const ECefWindowOpenDisposition& InTargetDisposition,
                    const FIntRect& InDesiredRect);

  /** 允许宿主在 CEF 创建弹窗前修改目标、设置和脚本访问权限。 */
  bool OnNewPopup(const FCefFrameId& InSourceFrameId,
                  const FString& InTargetUrl,
                  FString& InFrameName,
                  ECefWindowOpenDisposition InTargetDisposition,
                  FIntRect& InDesiredRect,
                  FSlateCefViewSettings& InBrowserSettings,
                  bool& bInDisableJavascriptAccess);

  /** 响应请求Close来源Web回调，并把外部事件转换为当前对象状态或委托通知。 */
  bool OnRequestCloseFromWeb();
#pragma endregion

#pragma region Overrides Parent
protected:
  void SetVisibility(TAttribute<EVisibility> InVisibility) override;

  /** 将外部请求可见性与透明透传状态合成为最终 Slate 可见性。 */
  void UpdateResolvedVisibility();

  /** 根据当前几何和鼠标位置刷新透明命中透传状态。 */
  void UpdateAlphaHitTestState(const FGeometry& InGeometry);

  /** 判断指定局部坐标是否落在需要透传的透明像素上。 */
  bool ShouldPassthroughPointerInput(const FGeometry& InGeometry, const FVector2D& InLocalPos);

  /** 切换透传状态并同步最终可见性。 */
  void SetAlphaInputPassthroughActive(bool bInIsActive);

  void Tick(const FGeometry& InAllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
  FChildren* GetChildren() override;
  void OnArrangeChildren(const FGeometry& InAllottedGeometry, FArrangedChildren& InArrangedChildren) const override;
  FVector2D ComputeDesiredSize(float InLayoutScaleMultiplier) const override;

  int32 OnPaint(const FPaintArgs& InArgs,
                const FGeometry& InAllottedGeometry,
                const FSlateRect& InMyCullingRect,
                FSlateWindowElementList& InOutDrawElements,
                int32 InLayerId,
                const FWidgetStyle& InWidgetStyle,
                bool bInParentEnabled) const override;

  /** 将 CEF 返回的鼠标形状映射为 Slate Cursor 回复。 */
  TOptional<TSharedRef<SWidget>> OnMapCursor(const FCursorReply& InCursorReply) const;

  bool SupportsKeyboardFocus() const override;
  FReply OnFocusReceived(const FGeometry& InGeometry, const FFocusEvent& InFocusEvent) override;
  void OnFocusLost(const FFocusEvent& InFocusEvent) override;
  FNavigationReply OnNavigation(const FGeometry& InGeometry, const FNavigationEvent& InNavigationEvent) override;

#pragma region Mouse Events
  void OnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
  void OnMouseLeave(const FPointerEvent& InMouseEvent) override;
  FReply OnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
  FReply OnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
  FReply OnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
  FReply OnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
  FReply OnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
  FReply OnMouseWheel(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
#pragma endregion

#pragma region Touch Events
  FReply OnTouchGesture(const FGeometry& InGeometry, const FPointerEvent& InGestureEvent) override;
  FReply OnTouchStarted(const FGeometry& InGeometry, const FPointerEvent& InTouchEvent) override;
  FReply OnTouchFirstMove(const FGeometry& InGeometry, const FPointerEvent& InTouchEvent) override;
  FReply OnTouchMoved(const FGeometry& InGeometry, const FPointerEvent& InTouchEvent) override;
  FReply OnTouchEnded(const FGeometry& InGeometry, const FPointerEvent& InTouchEvent) override;
  FReply OnTouchForceChanged(const FGeometry& InGeometry, const FPointerEvent& InTouchEvent) override;

#pragma endregion

#pragma region Keyboard Events
  FReply OnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
  FReply OnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
  FReply OnKeyChar(const FGeometry& InGeometry, const FCharacterEvent& InCharacterEvent) override;
  FReply OnKeyUp(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
  void OnDragEnter(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent) override;
  FReply OnDragOver(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent) override;
  FReply OnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent) override;
  void OnDragLeave(const FDragDropEvent& DragDropEvent) override;
  FReply OnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
#pragma endregion

#pragma endregion
};
