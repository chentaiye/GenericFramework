//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// ApplicationCore/Public/
#include <GenericPlatform/ICursor.h>
#include <GenericPlatform/ITextInputMethodSystem.h>
// Core/Public/
#include <CoreFwd.h>
#include <Containers/ResourceArray.h>
#include <HAL/IConsoleManager.h>
#include <Math/Color.h>
#include <Math/IntRect.h>
#include <Misc/EngineVersionComparison.h>
#include <Misc/ScopeLock.h>
#include <PixelFormat.h>
#include <Templates/PimplPtr.h>
#include <Templates/SharedPointer.h>
// CoreUObject/Public/
#include <UObject/StrongObjectPtr.h>
// Engine/Classes/
#include <Engine/Texture2D.h>
#include <Engine/Texture2DDynamic.h>
// Engine/Public/
#include <Slate/SlateTextures.h>
// Json/Public/
#include <Dom/JsonValue.h>
#include <Dom/JsonObject.h>
// RHI/Public/
#include <RHICommandList.h>
// Slate/Public/
#include <Framework/MultiBox/MultiBoxBuilder.h>
#include <Widgets/Images/SImage.h>
#include <Widgets/SOverlay.h>
#include <Rendering/RenderingCommon.h>
#include <Styling/SlateBrush.h>
#include <Textures/SlateShaderResource.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#include "HeadersCefViewCore.h"
#pragma endregion

#pragma region <Project Public Headers>
#include <Slate/SCefView.h>
#pragma endregion

#pragma region "Project Private Headers"
#include "Details/CCefClientDelegate.h"
#include "Common/Common.h"
#pragma endregion

#if UE_VERSION_EQUAL_OR_GREATER(5, 2, 0)
using UETexture2DRHIRef = FTextureRHIRef;
#else
using UETexture2DRHIRef = FTexture2DRHIRef;
#endif

/** 将 CEF 渲染结果包装成 Slate 可绘制纹理资源。 */
class FCefSlateTexture
  : public TSlateTexture<UETexture2DRHIRef>
  , public FDeferredCleanupInterface
{
protected:
  FCefSlateTexture();

  /** 延迟清理 Slate 纹理对象，避免 RHI 资源在渲染线程仍使用时释放。 */
  static void Deletor(FCefSlateTexture* InObj);

public:
  /** 创建带延迟清理能力的 CEF Slate 纹理。 */
  static TSharedPtr<FCefSlateTexture> MakeTexture();

  uint32 GetWidth() const override;
  uint32 GetHeight() const override;

  /** 更新当前纹理引用的 RHI 资源。 */
  void SetRHIRef(UETexture2DRHIRef InRenderTargetTexture);

  /** 判断当前纹理是否持有可绘制的 RHI 资源。 */
  bool IsValid();
};

/** 作为当前模块CefOsrBulk数据能力控件，负责把运行时状态呈现到Slate或UMG层。 */
class FCefOsrBulkData : public FResourceBulkDataInterface
{
public:
  FCefOsrBulkData(bool bSharedTexture);

  ~FCefOsrBulkData();

  /** 复制 CEF 像素缓冲，供后续创建普通纹理。 */
  void RetainPixelBuffer(const void* InData, int InWidth, int InHeight, EPixelFormat InPixelFormat);

  /** 缓存 CEF 共享纹理句柄，供后续跨 API 打开为 RHI 纹理。 */
  void RetainSharedTexture(void* InHandle, EPixelFormat InPixelFormat);

  /** 按当前数据来源创建 RHI 纹理。 */
  UETexture2DRHIRef CreateTexture(FRHICommandListImmediate& RHICommandList);

protected:
  /** 初始化平台共享纹理数据结构。 */
  void InitSharedTextureData();

  /** 返回当前缓存的共享纹理句柄。 */
  void* GetSharedTextureHandle() const;

  /** 返回共享纹理数据大小。 */
  uint32 GetSharedTextureSize() const;

  /** 从 CPU 像素缓冲创建 RHI 纹理。 */
  UETexture2DRHIRef CreateTextureFromPixelBuffer(FRHICommandListImmediate& RHICommandList);

  /** 从平台共享纹理创建 RHI 纹理。 */
  UETexture2DRHIRef CreateTextureFromSharedTexture(FRHICommandListImmediate& RHICommandList);

  /** 丢弃已消费的 CPU 像素缓冲。 */
  void DiscardPixelBuffer();

  /** 丢弃已消费的共享纹理句柄。 */
  void DiscardSharedTexture();

  const void* GetResourceBulkData() const override;
  uint32 GetResourceBulkDataSize() const override;
  void Discard() override;

private:
  /** 同步锁 */
  FCriticalSection Lock;

  /** 像素格式 */
  EPixelFormat PixelFormat = EPixelFormat::PF_Unknown;

  /** 共享纹理 */
  class SharedTextureData;

  /** 平台相关的共享纹理数据。 */
  TPimplPtr<SharedTextureData> SharedTexture = nullptr;

  /** 像素缓冲 */
  class PixelBufferData;

  /** CPU 侧像素缓冲数据。 */
  TPimplPtr<PixelBufferData> PixelBuffer = nullptr;

  /** 旧版引擎兼容字段 */
#if !UE_VERSION_EQUAL_OR_GREATER(5, 7, 0)
  EBulkDataType GetResourceType() const override;

  /** 旧版引擎要求的 BulkData 类型缓存。 */
  EBulkDataType Type = FResourceBulkDataInterface::EBulkDataType::Default;
#endif
};

/** 承载 SCefView 的 CEF 浏览器、离屏渲染、输入、IME 和弹窗状态。 */
class SCefViewPrivate
  : public ITextInputMethodContext
  , public ISlateViewport
  , public TSharedFromThis<SCefViewPrivate>
{
  friend class SCefView;
  friend class CCefClientDelegate;

public:
  SCefViewPrivate(TSharedPtr<SCefView> InHost);

  ~SCefViewPrivate();

  /** 创建 CEF Browser、渲染资源和输入上下文。 */
  void Initialize(const FSlateCefViewSettings& InCefViewSettings);

  /** 释放 CEF Browser、渲染资源和输入上下文。 */
  void Uninitialize();

  /** 布局用于弹窗、对话框和自定义光标的子控件。 */
  void ArrangeChildren(const FGeometry& InAllottedGeometry, FArrangedChildren& InArrangedChildren) const;

private:
  /** 弱引用宿主 SCefView，避免私有实现延长 Slate 控件生命周期。 */
  TWeakPtr<SCefView> m_pHost;

  /** 子控件槽位 */
  TSharedRef<SOverlay> ChildrenOverlay;

  /** 管理 Overlay 子项布局的单槽位封装。 */
  FSingleWidgetChildrenWithSlot ChildrenOverlaySlot;

  /** 光标状态 */
  TStrongObjectPtr<UTexture2D> CustomCursorTexture;

  /** 显示 CEF 自定义光标的 Slate 图像。 */
  TSharedPtr<SImage> CustomCursorImage;

  // 内部方法
#pragma region Internal Methods
protected:
  /** 每帧同步几何、窗口状态、CEF 渲染请求和输入法位置。 */
  void UpdateTick(const FGeometry& InAllottedGeometry, const double& InCurrentTime, const float& InDeltaTime);

  /** 请求当前 CEF Browser 导航到目标地址。 */
  void NavigateToUrl(const FString& InTargetUrl);

  /** 向指定 CEF Frame 发送页面事件通知。 */
  bool TriggerCefEvent(const FString& InName,
                       const TArray<TSharedPtr<FJsonValue>>& InArgs,
                       const FCefFrameId& InFrameId = SCefView::MainFrameID);

  /** 回复页面脚本发起的 CEF 查询。 */
  bool ResponseCefQuery(const int64 InQuery, const bool bInSuccess, const FString& InResponse, const int32 InError);

  /** 在指定 Frame 执行脚本，不等待返回值。 */
  bool ExecuteJavascript(const FCefFrameId& InFrameId, const FString& InCode, const FString& InUrl);

  /** 在指定 Frame 执行脚本，并让 CEF View Core 回传结果。 */
  bool ExecuteJavascriptWithResult(const FCefFrameId& InFrameId,
                                   const FString& InCode,
                                   const FString& InUrl,
                                   const FString& InContext);

  /** 将 JSON 值写入 CEF 浏览器偏好项。 */
  bool SetPreference(const FString& InName, const TSharedPtr<FJsonValue>& InValue, FString& OutError);

  /** 组装并发送 CEF View Core 的事件通知消息。 */
  bool SendEventNotifyMessage(const FCefFrameId& InFrameId,
                              const FString& InName,
                              const TArray<TSharedPtr<FJsonValue>>& InArgs);

  /** 通知 CEF 宿主窗口移动或尺寸变化，触发内部布局刷新。 */
  void NotifyMoveOrResizeStarted();
#pragma endregion

  // 浏览器创建与销毁
#pragma region CEF Browser Create/Destroy
protected:
  /** 接收 CEF Client 回调并转发到本对象的委托。 */
  CCefClientDelegate::RefPtr pCefClientDelegate = nullptr;

  /** CEF View Core Browser Client 对象。 */
  CefRefPtr<CefViewBrowserClient> pCefClient = nullptr;

  /** 当前主浏览器实例。 */
  CefRefPtr<CefBrowser> pCefBrowser = nullptr;

  /** 保护浏览器创建和销毁流程。 */
  FCriticalSection InitializationLock;

  /** 创建浏览器过程中暂存的初始导航地址。 */
  FString InitializingUrl;

  /** 判断主 CEF Browser 是否已经创建完成。 */
  bool IsCefBrowserCreated();

/** 构建CefBrowser设置，供CEF浏览器创建和运行时配置复用。 */
  void BuildCefBrowserSettings(CefBrowserSettings& InBrowserSettings, const FSlateCefViewSettings& InSettings);

  /** 创建离屏渲染模式下的 CEF Browser。 */
  void CreateCefBrowser(const FSlateCefViewSettings& InSettings);

  /** 关闭并释放当前 CEF Browser。 */
  void DestroyCefBrowser();
#pragma endregion

  // 渲染工具
#pragma region Rendering Utility
protected:
  /** 绘制浏览器背景时使用的 Slate 画刷。 */
  FSlateBrush BackgroundBrush;

  /** 当前视图背景色。 */
  FLinearColor BackgroundColor;

  /** 保护透明度采样缓冲在渲染回调和输入线程间的访问。 */
  mutable FCriticalSection AlphaHitTestLock;

  /** 主视图透明度缓冲宽度。 */
  int32 CefViewAlphaSizeX = 0;

  /** 主视图透明度缓冲高度。 */
  int32 CefViewAlphaSizeY = 0;

  /** 主视图透明度采样缓冲。 */
  TArray<uint8> CefViewAlphaBuffer;

  /** 弹窗透明度缓冲宽度。 */
  int32 CefPopupAlphaSizeX = 0;

  /** 弹窗透明度缓冲高度。 */
  int32 CefPopupAlphaSizeY = 0;

  /** 弹窗透明度采样缓冲。 */
  TArray<uint8> CefPopupAlphaBuffer;

  /** 标记当前平台和 CEF 版本是否使用共享纹理渲染。 */
  bool bIsCefSharedTextureEnabled = false;

  /** 标记 CEF 当前是否正在显示离屏弹窗。 */
  bool bIsCefPopupShowing = false;

  /** 最近一次 Tick 解析到的宿主窗口。 */
  TWeakPtr<SWindow> CachedParentWindow;

  /** 最近一次 Tick 解析到的窗口缩放。 */
  float CachedScaleFactor = 1.0f;

  /** 最近一次 Tick 记录的控件几何。 */
  FGeometry CachedGeometry;

  /** CEF 离屏弹窗在视图内的矩形区域。 */
  FIntRect CefPopupFrameRect;

  /** 显示帧纹理 */
  TSharedPtr<FCefSlateTexture> CefViewFrameTexture;

  /** 弹窗当前可绘制帧纹理。 */
  TSharedPtr<FCefSlateTexture> CefPopupFrameTexture;

  /** 视口绘制访问辅助 */
  FSlateShaderResource* PaintingTexture = nullptr;

  /** 帧像素数据 */
  TSharedPtr<FCefOsrBulkData> CefViewFrameBulkData;

  /** 弹窗等待上传到 RHI 的帧数据。 */
  TSharedPtr<FCefOsrBulkData> CefPopupFrameBulkData;

  /** 判断当前平台、RHI 和 CEF 版本是否支持共享纹理路径。 */
  bool IsSharedTextureSupported();

  /** 刷新宿主窗口和缩放缓存。 */
  void UpdateCachedWindowInfo();

  /** 缓存本帧布局几何供 CEF 回调换算坐标。 */
  void UpdateCachedGeometry(const FGeometry& InAllottedGeometry);

  /** 清空主视图和弹窗透明度采样缓冲。 */
  void ClearAlphaBuffers();

  /** 从 CEF 像素帧提取透明度通道用于命中透传判断。 */
  void UpdateAlphaBuffer(TArray<uint8>& InOutAlphaBuffer,
                         int32& OutSizeX,
                         int32& OutSizeY,
                         const void* InBuffer,
                         int InWidth,
                         int InHeight);

  /** 在透明度缓冲中采样局部坐标对应的 Alpha 值。 */
  bool SampleAlphaBuffer(const TArray<uint8>& InAlphaBuffer,
                         int32 InSizeX,
                         int32 InSizeY,
                         const FVector2D& InLocalPos,
                         const FVector2D& InLocalSize,
                         uint8& OutAlpha) const;

  /** 判断指定坐标是否应把输入透传给下层 Slate 控件。 */
  bool ShouldPassthroughInput(const FVector2D& InLocalPos, const FVector2D& InLocalSize, uint8 InThreshold);

  // Slate 视口接口
#pragma region ISlateViewport
  FIntPoint GetSize() const override;
  FSlateShaderResource* GetViewportRenderTargetTexture() const override;
  bool RequiresVsync() const override;
#pragma endregion

#pragma region Paint Operations
  /** 绘制 CEF 视图背景。 */
  int32 PaintBackground(const FPaintArgs& InArgs,
                        const FGeometry& InAllottedGeometry,
                        const FSlateRect& InMyCullingRect,
                        FSlateWindowElementList& InOutDrawElements,
                        int32 InLayerId,
                        const FWidgetStyle& InWidgetStyle);

  /** 绘制主浏览器离屏帧。 */
  int32 PaintCefView(const FPaintArgs& InArgs,
                     const FGeometry& InAllottedGeometry,
                     const FSlateRect& InMyCullingRect,
                     FSlateWindowElementList& InOutDrawElements,
                     int32 InLayerId,
                     const FWidgetStyle& InWidgetStyle);

  /** 绘制 CEF 离屏弹窗帧。 */
  int32 PaintCefPopup(const FPaintArgs& InArgs,
                      const FGeometry& InAllottedGeometry,
                      const FSlateRect& InMyCullingRect,
                      FSlateWindowElementList& InOutDrawElements,
                      int32 InLayerId,
                      const FWidgetStyle& InWidgetStyle);

  /** 绘制覆盖在浏览器上的 JavaScript 对话框。 */
  int32 PaintJSDialog(const FPaintArgs& InArgs,
                      const FGeometry& InAllottedGeometry,
                      const FSlateRect& InMyCullingRect,
                      FSlateWindowElementList& InOutDrawElements,
                      int32 InLayerId,
                      const FWidgetStyle& InWidgetStyle,
                      bool bInParentEnabled);

#if defined(ENABLE_TRIAL_WATERMARK) && ENABLE_TRIAL_WATERMARK
  /** 绘制试用版本水印。 */
  int32 PaintWatermark(const FPaintArgs& InArgs,
                       const FGeometry& InAllottedGeometry,
                       const FSlateRect& InMyCullingRect,
                       FSlateWindowElementList& InOutDrawElements,
                       int32 InLayerId,
                       const FWidgetStyle& InWidgetStyle);
#endif

  /** 汇总背景、浏览器帧、弹窗、对话框和水印的绘制顺序。 */
  int32 PaintWidget(const FPaintArgs& InArgs,
                    const FGeometry& InAllottedGeometry,
                    const FSlateRect& InMyCullingRect,
                    FSlateWindowElementList& InOutDrawElements,
                    int32 InLayerId,
                    const FWidgetStyle& InWidgetStyle,
                    bool bInParentEnabled);
#pragma endregion
#pragma endregion

  // 上下文菜单
#pragma region Context Menu
protected:
  /** 标记 Slate 上下文菜单当前是否正在显示。 */
  bool bIsShowingContextMenu = false;

  /** 当前显示的 Slate 上下文菜单实例。 */
  TSharedPtr<IMenu> SlateContextMenu;

  /** CEF 上下文菜单回调，用于执行命令或通知关闭。 */
  CefRefPtr<CefRunContextMenuCallback> CefContextMenu;

  /** 将 Slate 菜单命令回传给 CEF。 */
  void OnSlateContextMenuCommand(int InCommand);

  /** 在 Slate 菜单关闭时通知 CEF 菜单生命周期结束。 */
  void OnSlateContextMenuDismissed(TSharedRef<IMenu> InMenu);

  /** 使用 CEF 菜单模型构建并显示 Slate 菜单。 */
  bool DisplaySlateContextMenu(FMenuBuilder& InBuilder, const FVector2D& InPos);

  /** 主动关闭 Slate 上下文菜单。 */
  void DismissSlateContextMenu();

  /** 主动通知 CEF 上下文菜单已关闭。 */
  void DismissCefContextMenu();
#pragma endregion

  // JavaScript 对话框
#pragma region JS Dialog
  /** 根据 CEF JS 对话框请求创建对应的 Slate 覆盖层。 */
  bool CreateJSDialog(CefJSDialogHandler::JSDialogType InDialogType,
                      const FString& InOriginUrl,
                      const FString& InMessageText,
                      const FString& InDefaultPromptText,
                      CefRefPtr<CefJSDialogCallback>& InCallback);

  /** 移除已完成或取消的 JS 对话框覆盖层。 */
  void DestroyJSDialog(const TSharedPtr<SWidget>& InDialog);
#pragma endregion

  // 输入法
#pragma region Input Method
protected:
  /** CEF 当前聚焦节点是否可编辑，用于决定是否启用 IME。 */
  bool bIsCefFocusedNodeEditable = false;

  /** Slate 输入法上下文是否处于组合输入中。 */
  bool bIsComposing = false;

  /** 当前 IME 组合文本。 */
  FString CompositionText;

  /** CEF 提供的组合文本字符边界。 */
  TArray<FIntRect> CompositionCharBounds;

  /** 当前组合文本选区范围。 */
  FVector2D CompositionSelectionRange;

  /** Slate 输入法变化通知器。 */
  TSharedPtr<ITextInputMethodChangeNotifier> ImeChangeNotifier;

  /** 向 Slate 输入法系统注册本控件上下文。 */
  void RegisterIMEContext();

  /** 从 Slate 输入法系统注销本控件上下文。 */
  void UnregisterIMEContext();

  /** 在 CEF 聚焦可编辑节点时激活输入法上下文。 */
  void ActivateIMEContext(bool bInForce = false);

  /** 在 CEF 失焦或不可编辑时停用输入法上下文。 */
  void DeactivateIMEContext();

  /** 将当前 IME 组合文本同步给 CEF。 */
  void UpdateCefComposition();

  /** 通知 CEF 结束当前组合输入。 */
  void EndCefComposition();

  /** 清空本地组合输入状态。 */
  void ResetComposition();

#pragma region ITextInputMethodContext Overrides
  bool IsComposing() override;
  bool IsReadOnly() override;
  uint32 GetTextLength() override;
  void GetSelectionRange(uint32& OutBeginIndex, uint32& OutLength, ECaretPosition& OutCaretPosition) override;
  void SetSelectionRange(const uint32 InBeginIndex,
                         const uint32 InLength,
                         const ECaretPosition InCaretPosition) override;
  void GetTextInRange(const uint32 InBeginIndex, const uint32 InLength, FString& OutString) override;
  void SetTextInRange(const uint32 InBeginIndex, const uint32 InLength, const FString& InString) override;
  int32 GetCharacterIndexFromPoint(const FVector2D& InPoint) override;
  bool GetTextBounds(const uint32 InBeginIndex,
                     const uint32 InLength,
                     FVector2D& OutPosition,
                     FVector2D& OutSize) override;
  void GetScreenBounds(FVector2D& OutPosition, FVector2D& OutSize) override;
  TSharedPtr<FGenericWindow> GetWindow() override;
  void BeginComposition() override;
  void UpdateCompositionRange(const int32 InBeginIndex, const uint32 InLength) override;
  void EndComposition() override;
#pragma endregion
#pragma endregion

  // CEF 回调
#pragma region CEF Callbacks
protected:
  /** 生命周期 */
  bool OnBeforeManagedPopupBrowser(const FCefFrameId& InFrameId,
                                   const FString& InTargetUrl,
                                   FString& InTargetFrameName,
                                   int32 InTargetDisposition,
                                   FIntRect& OutRect,
                                   FSlateCefViewSettings& OutSettings,
                                   bool& bOutDisableJavascriptAccess);

  /** 在 CEF 请求独立弹窗时通知上层创建新浏览器承载。 */
  void OnBeforeIsolatedPopupBrowser(const FCefFrameId& InSourceFrameId,
                                    const FString& InUrl,
                                    const FString& InName,
                                    const int32& InTargetDisposition,
                                    const FIntRect& InRect);

  /** 记录主浏览器创建完成并触发上层通知。 */
  void OnAfeterCefMainBrowserCreated(CefRefPtr<CefBrowser>& InBrowser);

  /** 记录弹窗浏览器创建完成。 */
  void OnAfterCefPopupBrowserCreated(CefRefPtr<CefBrowser>& InBrowser);

  /** 响应请求Close来源Web回调，并把外部事件转换为当前对象状态或委托通知。 */
  bool OnRequestCloseFromWeb();

  // 内容渲染
#pragma region Rendering With Pixel Buffer
  /** 接收主视图像素缓冲帧并准备 Slate 绘制资源。 */
  void OnOsrUpdateViewFromPixelBuffer(const void* InBuffer, int InWidth, int InHeight, const FIntRect& InRegion);

  /** 接收弹窗像素缓冲帧并准备 Slate 绘制资源。 */
  void OnOsrUpdatePopupFromPixelBuffer(const void* InBuffer, int InWidth, int InHeight, const FIntRect& InRegion);
#pragma endregion

#pragma region Rendering With Shared Texture
  /** 接收主视图共享纹理帧并准备 Slate 绘制资源。 */
  void OnOsrUpdateViewFromSharedTexture(void* InHandle, cef_color_type_t InColor, const FIntRect& InRegion);

  /** 接收弹窗共享纹理帧并准备 Slate 绘制资源。 */
  void OnOsrUpdatePopupFromSharedTexture(void* InHandle, cef_color_type_t InColor, const FIntRect& InRegion);
#pragma endregion

  /** 帧推进 */
  void UpdateCefFrameTick();

  /** 帧请求 */
  void RequestNextCefFrame();

  /** 根据 CEF 光标回调更新 Slate 光标。 */
  void OnCefCursorChanged(CefCursorHandle InCursor, cef_cursor_type_t InType, const CefCursorInfo& InCustomCursorInfo);

  /** 焦点 */
  bool bHasCefGotFocus = false;

  /** 响应CefReleased聚焦回调，并把外部事件转换为当前对象状态或委托通知。 */
  void OnCefReleasedFocus(bool bInNext);

  /** 响应Cef请求聚焦回调，并把外部事件转换为当前对象状态或委托通知。 */
  bool OnCefRequestFocus();

  /** 记录 CEF 已获得焦点并同步 Slate 状态。 */
  void OnCefGotFocus();

  /** 上下文菜单 */
  void OnBeforeCefContextMenu(const FCefFrameId& InSourceFrameId, const CefRefPtr<CefMenuModel>& InModel);

  /** 将 CEF 菜单模型转换为 Slate 菜单并显示。 */
  void OnRunCefContextMenu(const FCefFrameId& InSourceFrameId,
                           const CefRefPtr<CefMenuModel>& InModel,
                           const FVector2D& InPos,
                           CefRefPtr<CefRunContextMenuCallback>& InCallback);

  /** 同步 CEF 菜单关闭状态。 */
  void OnCefContextMenuDismissed(const FCefFrameId& InSourceFrameId);

  /** 输入法 */
  void OnCefInputStateChanged(bool bInEditable);

  /** 接收 CEF IME 组合文本范围变化。 */
  void OnCefImeCompositionRangeChanged(const FVector2D& InSelectedRange, const TArray<FIntRect>& InCharacterBounds);

  /** 接收 CEF 文本选区变化。 */
  void OnCefTextSelectionChanged(const FString& InSelectedText, const FVector2D& InSelectedRange);

  /** 接收 CEF 虚拟键盘请求。 */
  void OnCefVirtualKeyboardRequested(CefRenderHandler::TextInputMode InInputMode);

  /** JavaScript 对话框 */
  bool OnJSDialog(CefRefPtr<CefBrowser>& InBrowser,
                  const FString& InOriginUrl,
                  CefJSDialogHandler::JSDialogType InDialogType,
                  const FString& InMessageText,
                  const FString& InDefaultPromptText,
                  CefRefPtr<CefJSDialogCallback>& InCallback,
                  bool& bOutSuppressMessage);

  /** 接收页面卸载确认对话框请求。 */
  bool OnBeforeUnloadDialog(CefRefPtr<CefBrowser>& InBrowser,
                            const FString& InMessageText,
                            bool bInIsReload,
                            CefRefPtr<CefJSDialogCallback>& InCallback);

  /** 响应ResetDialog状态回调，并把外部事件转换为当前对象状态或委托通知。 */
  void OnResetDialogState(CefRefPtr<CefBrowser>& browser);

  /** 在 CEF 通知对话框关闭时同步本地覆盖层。 */
  void OnDialogClosed(CefRefPtr<CefBrowser>& browser);

  /** 下载 */
  void OnBeforeDownload(CefRefPtr<CefBrowser>& InBrowser,
                        CefRefPtr<CefDownloadItem>& InDownloadItem,
                        const FString& InSuggestedName,
                        CefRefPtr<CefBeforeDownloadCallback>& InCallback);

  /** 接收下载进度变化并转发给上层事件。 */
  void OnDownloadUpdated(CefRefPtr<CefBrowser>& InBrowser,
                         CefRefPtr<CefDownloadItem>& InDownloadItem,
                         CefRefPtr<CefDownloadItemCallback>& InCallback);

  /** 拖放 */
  CefRenderHandler::DragOperation CurrentAllowDragOperation = DRAG_OPERATION_NONE;

  /** 判断当前拖拽数据和操作掩码是否允许 Drop。 */
  bool ShouldAllowDrop(CefRefPtr<CefDragData>& InDragData, CefDragHandler::DragOperationsMask InAllowedOps);

  /** 将 Slate 拖拽结束结果回传给 CEF。 */
  void OnDragSourceEnd(bool bDropWasHandled, const FPointerEvent& MouseEvent);

  /** 判断页面发起的拖拽是否允许进入 Slate 拖拽流程。 */
  bool ShouldAllowDrag(CefRefPtr<CefDragData>& InDragData,
                       CefRenderHandler::DragOperationsMask InAllowedOps,
                       int InX,
                       int InY);

  /** 根据 CEF 操作掩码更新当前拖拽操作。 */
  void UpdateDragOperation(CefRenderHandler::DragOperationsMask InAllowedOps);

#pragma endregion

  // SWidget 重写
#pragma region SWidget Overrides
protected:
  /** 将 Slate 尺寸变化同步给 CEF。 */
  void OnSizeEvent(const FVector2D& InNewSize);

  /** 将 Slate 可见性变化同步给 CEF。 */
  void OnVisibilityEvent(bool bInVisible);

  /** 将 Slate 焦点变化同步给 CEF。 */
  void OnFocusEvent(bool bInFocused, const FFocusEvent& InFocusEvent);

  /** 将 Slate 鼠标移动或离开事件转换为 CEF 鼠标事件。 */
  void OnMouseMoveEvent(const FPointerEvent& InMouseEvent, const FVector2D& InLocalPos, bool bInLeave);

  /** 将 Slate 鼠标按下事件转换为 CEF 鼠标事件。 */
  void OnMouseButtonDownEvent(const FPointerEvent& InMouseEvent, const FVector2D& InLocalPos);

  /** 将 Slate 鼠标抬起事件转换为 CEF 鼠标事件。 */
  void OnMouseButtonUpEvent(const FPointerEvent& InMouseEvent, const FVector2D& InLocalPos);

  /** 将 Slate 鼠标双击事件转换为 CEF 鼠标事件。 */
  void OnMouseButtonDoubleClickEvent(const FPointerEvent& InMouseEvent, const FVector2D& InLocalPos);

  /** 将 Slate 鼠标滚轮事件转换为 CEF 滚轮事件。 */
  void OnMouseWheelEvent(const FPointerEvent& InMouseEvent, const FVector2D& InLocalPos);

  /** 将 Slate 触摸开始事件转换为 CEF 触摸事件。 */
  void OnTouchStartedEvent(const FPointerEvent& InTouchEvent, const FVector2D& InLocalPos);

  /** 将 Slate 触摸移动事件转换为 CEF 触摸事件。 */
  void OnTouchMovedEvent(const FPointerEvent& InTouchEvent, const FVector2D& InLocalPos);

  /** 将 Slate 触摸结束事件转换为 CEF 触摸事件。 */
  void OnTouchEndedEvent(const FPointerEvent& InTouchEvent, const FVector2D& InLocalPos);

  /** 将 Slate 触摸取消事件转换为 CEF 触摸事件。 */
  void OnTouchCancelledEvent(const FPointerEvent& InTouchEvent, const FVector2D& InLocalPos);

  /** 将 Slate 按键按下事件转换为 CEF 键盘事件。 */
  void OnKeyDownEvent(const FKeyEvent& InKeyEvent);

  /** 将 Slate 字符输入事件转换为 CEF 字符事件。 */
  void OnKeyCharEvent(const FCharacterEvent& InCharacterEvent);

  /** 将 Slate 按键抬起事件转换为 CEF 键盘事件。 */
  void OnKeyUpEvent(const FKeyEvent& InKeyEvent);

  /** 将 Slate 拖拽进入事件转换为 CEF 拖拽事件。 */
  void OnDragEnter(const FDragDropEvent& InDragDropEvent, const FVector2D& InLocalPos);

  /** 将 Slate 拖拽悬停事件转换为 CEF 拖拽事件。 */
  FReply OnDragOver(const FDragDropEvent& InDragDropEvent, const FVector2D& InLocalPos);

  /** 将 Slate Drop 事件转换为 CEF Drop 事件。 */
  FReply OnDrop(const FDragDropEvent& InDragDropEvent, const FVector2D& InLocalPos);

  /** 将 Slate 拖拽离开事件转换为 CEF 拖拽取消事件。 */
  void OnDragLeave(const FDragDropEvent& InDragDropEvent);

  /** 从 CEF 发起的拖拽创建 Slate 拖放操作。 */
  FReply OnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent);
#pragma endregion
};
