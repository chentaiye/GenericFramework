//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "SCefViewPrivate.h"
#pragma endregion

#pragma region <Engine Headers>
// Core/Public/
#include <Async/Async.h>
#include <Containers/ResourceArray.h>
#include <HAL/UnrealMemory.h>
#include <Math/TransformCalculus2D.h>
// Engine/Classes/
#include <Engine/Engine.h>
// Engine/Public/
#include <TextureResource.h>
#include <Rendering/Texture2DResource.h>
#include <Slate/SlateTextures.h>
// RenderCore/Public/
#include <RenderingThread.h>
// RHI/Public/
#include <DynamicRHI.h>
// Slate/Public/
#include <Framework/Application/MenuStack.h>
#include <Framework/Application/SlateApplication.h>
#include <Widgets/Input/SEditableTextBox.h>
// SlateCore/Public/
#include <Fonts/FontMeasure.h>
#include <Layout/WidgetPath.h>
#include <Styling/SlateBrush.h>
#include <Widgets/SCompoundWidget.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#include <Slate/SlateCefContext.h>
#pragma endregion

#pragma region "Project Private Headers"
#include "CefViewModule.h"
#include "Common/Convert.h"
#include "Common/Log.h"
#include "Common/Platform.h"
#include "Details/Handlers/Utils/InputUtils.h"
#include "Details/Handlers/Utils/MenuUtils.h"
#include "Slate/SlateCefJSDialog.h"
#include "Slate/SlateCefContextPrivate.h"
#include "Slate/SlateCefDragDropOperation.h"
#pragma endregion

using namespace Common;

//////////////////////////////////////////////////////////////////////////
// 离屏纹理桥接
#pragma region FCefSlateTexture Implementation
FCefSlateTexture::FCefSlateTexture() {}

void
FCefSlateTexture::Deletor(FCefSlateTexture* InObj)
{
  if (InObj) {
    BeginCleanup(InObj);
  }
}

TSharedPtr<FCefSlateTexture>
FCefSlateTexture::MakeTexture()
{
  //
  return TSharedPtr<FCefSlateTexture>(new FCefSlateTexture(), &FCefSlateTexture::Deletor);
}

uint32
FCefSlateTexture::GetWidth() const
{
  if (IsValidRef(ShaderResource)) {
    return ShaderResource->GetSizeX();
  }
  return 0;
}

uint32
FCefSlateTexture::GetHeight() const
{
  if (IsValidRef(ShaderResource)) {
    return ShaderResource->GetSizeY();
  }
  return 0;
}

void
FCefSlateTexture::SetRHIRef(UETexture2DRHIRef InRenderTargetTexture)
{
  //
  ShaderResource = InRenderTargetTexture;
}

bool
FCefSlateTexture::IsValid()
{
  //
  return IsValidRef(ShaderResource);
}
#pragma endregion

//////////////////////////////////////////////////////////////////////////
// 离屏渲染帧数据
#pragma region FCefOsrBulkData Implementation
class FCefOsrBulkData::PixelBufferData
{
public:
  int32 SizeX = 0;
  int32 SizeY = 0;
  TArray<uint8> Buffer;
};

FCefOsrBulkData::FCefOsrBulkData(bool bSharedTexture)
{
  if (bSharedTexture) {
    InitSharedTextureData();
  } else {
    PixelBuffer = MakePimpl<PixelBufferData>();
  }
}

FCefOsrBulkData::~FCefOsrBulkData() {}

void
FCefOsrBulkData::RetainPixelBuffer(const void* InData, int InWidth, int InHeight, EPixelFormat InPixelFormat)
{
  FScopeLock ScopeLock(&Lock);

  PixelFormat = InPixelFormat;
  PixelBuffer->SizeX = InWidth;
  PixelBuffer->SizeY = InHeight;
  int32 Length = InWidth * InHeight * GPixelFormats[InPixelFormat].BlockBytes;
  PixelBuffer->Buffer.SetNum(Length);
  FMemory::Memcpy(PixelBuffer->Buffer.GetData(), InData, Length);
}

UETexture2DRHIRef
FCefOsrBulkData::CreateTexture(FRHICommandListImmediate& RHICommandList)
{
  if (SharedTexture) {
    return CreateTextureFromSharedTexture(RHICommandList);
  } else {
    return CreateTextureFromPixelBuffer(RHICommandList);
  }
}

UETexture2DRHIRef
FCefOsrBulkData::CreateTextureFromPixelBuffer(FRHICommandListImmediate& RHICommandList)
{
  UETexture2DRHIRef TextureRHI;
  ETextureCreateFlags TextureCreateFlags = TexCreate_ShaderResource;
  ERHIAccess TextureInitialState = ERHIAccess::Present | ERHIAccess::SRVMask;

  FScopeLock ScopeLock(&Lock);
  if (PixelBuffer->Buffer.Num() <= 0) {
    /** CPU 像素缓冲为空说明本帧没有新的离屏渲染数据。 */
    return TextureRHI;
  }

#if UE_VERSION_EQUAL_OR_GREATER(5, 7, 0)
  // 5.7+
  FRHITextureCreateDesc CreateDesc(TEXT("UCEFVIEW_OSR_PIXEL_BUFFER_TEXTURE"), ETextureDimension::Texture2D);
  CreateDesc.SetInitActionBulkData(this);
  CreateDesc.SetExtent(PixelBuffer->SizeX, PixelBuffer->SizeY);
  CreateDesc.SetFormat(PixelFormat);
  CreateDesc.SetFlags(TextureCreateFlags);
  CreateDesc.SetInitialState(TextureInitialState);
  TextureRHI = GDynamicRHI->RHICreateTextureInitializer(RHICommandList, CreateDesc).Finalize();
#elif UE_VERSION_EQUAL_OR_GREATER(5, 4, 0)
  // 5.4+
  FRHITextureCreateDesc CreateDesc(TEXT("UCEFVIEW_OSR_PIXEL_BUFFER_TEXTURE"), ETextureDimension::Texture2D);
  CreateDesc.SetBulkData(this);
  CreateDesc.SetExtent(PixelBuffer->SizeX, PixelBuffer->SizeY);
  CreateDesc.SetFormat(PixelFormat);
  CreateDesc.SetFlags(TextureCreateFlags);
  CreateDesc.SetInitialState(TextureInitialState);
  TextureRHI = GDynamicRHI->RHICreateTexture(RHICommandList, CreateDesc);
#elif UE_VERSION_EQUAL_OR_GREATER(5, 1, 0)
  // 5.1/5.2/5.3
  FRHITextureCreateDesc CreateDesc(TEXT("UCEFVIEW_OSR_PIXEL_BUFFER_TEXTURE"), ETextureDimension::Texture2D);
  CreateDesc.SetBulkData(this);
  CreateDesc.SetExtent(PixelBuffer->SizeX, PixelBuffer->SizeY);
  CreateDesc.SetFormat(PixelFormat);
  CreateDesc.SetFlags(TextureCreateFlags);
  CreateDesc.SetInitialState(TextureInitialState);
  TextureRHI = GDynamicRHI->RHICreateTexture_RenderThread(RHICommandList, CreateDesc);
#else
  // 5.0
  FRHIResourceCreateInfo CreateInfo(TEXT("UCEFVIEW_OSR_PIXEL_BUFFER_TEXTURE"), this);
  TextureRHI = GDynamicRHI->RHICreateTexture2D_RenderThread(RHICommandList,
                                                            PixelBuffer->SizeX,
                                                            PixelBuffer->SizeY,
                                                            PixelFormat,
                                                            1,
                                                            1,
                                                            TextureCreateFlags,
                                                            TextureInitialState,
                                                            CreateInfo);
#endif
  if (!TextureRHI.IsValid()) {
    logError() << "Failed to create RHI texture from shared resource";
    return TextureRHI;
  }

  DiscardPixelBuffer();
  return TextureRHI;
}

void
FCefOsrBulkData::DiscardPixelBuffer()
{
  PixelBuffer->SizeX = 0;
  PixelBuffer->SizeY = 0;
  PixelBuffer->Buffer.Empty();
}

const void*
FCefOsrBulkData::GetResourceBulkData() const
{
  if (SharedTexture) {
    return GetSharedTextureHandle();
  } else {
    return PixelBuffer->Buffer.GetData();
  }
}

uint32
FCefOsrBulkData::GetResourceBulkDataSize() const
{
  if (SharedTexture) {
    return GetSharedTextureSize();
  } else {
    return PixelBuffer->Buffer.Num();
  }
}

#if !UE_VERSION_EQUAL_OR_GREATER(5, 7, 0)
FResourceBulkDataInterface::EBulkDataType
FCefOsrBulkData::GetResourceType() const
{
  return Type;
}
#endif

void
FCefOsrBulkData::Discard()
{
  PixelFormat = PF_Unknown;
  if (SharedTexture) {
    DiscardSharedTexture();
  } else {
    DiscardPixelBuffer();
  }
}
#pragma endregion

SCefViewPrivate::SCefViewPrivate(TSharedPtr<SCefView> InHost)
  : m_pHost(InHost)
  , ChildrenOverlay(SNew(SOverlay))
  , ChildrenOverlaySlot(InHost.Get())
  , CustomCursorTexture()
  , CustomCursorImage(SNew(SImage))
  , CefViewFrameTexture(FCefSlateTexture::MakeTexture())
  , CefPopupFrameTexture(FCefSlateTexture::MakeTexture())
{
  const bool bUseAlphaHitTestPassthrough = InHost.IsValid() && InHost->IsAlphaHitTestPassthroughEnabled();
  bIsCefSharedTextureEnabled = IsSharedTextureSupported() && !bUseAlphaHitTestPassthrough;
  CefViewFrameBulkData = MakeShared<FCefOsrBulkData>(bIsCefSharedTextureEnabled);
  CefPopupFrameBulkData = MakeShared<FCefOsrBulkData>(bIsCefSharedTextureEnabled);
  ChildrenOverlaySlot.AttachWidget(ChildrenOverlay);
}

SCefViewPrivate::~SCefViewPrivate()
{
  Uninitialize();

  logDebug() << "SCefViewPrivate destructed";
}

void
SCefViewPrivate::Initialize(const FSlateCefViewSettings& InCefViewSettings)
{
  /** FLinearColor 赋值会执行 sRGB 到线性颜色转换，保持 Slate 绘制颜色空间一致。 */
  BackgroundColor = InCefViewSettings.BackgroundColor;
  RegisterIMEContext();
  ActivateIMEContext(true);
  CreateCefBrowser(InCefViewSettings);
}

void
SCefViewPrivate::Uninitialize()
{
  DestroyCefBrowser();
  ClearAlphaBuffers();
  DeactivateIMEContext();
  UnregisterIMEContext();
}

void
SCefViewPrivate::ArrangeChildren(const FGeometry& InAllottedGeometry, FArrangedChildren& InArrangedChildren) const
{
  FArrangedWidget ArrangedWidget = InAllottedGeometry.MakeChild(ChildrenOverlay, FVector2D(0, 0), CachedGeometry.Size);
  InArrangedChildren.AddWidget(ChildrenOverlay->GetVisibility(), ArrangedWidget);
}

void
SCefViewPrivate::UpdateTick(const FGeometry& InAllottedGeometry, const double& InCurrentTime, const float& InDeltaTime)
{
  /** 每帧先同步宿主窗口信息，供 CEF 屏幕坐标和 DPI 换算使用。 */
  UpdateCachedWindowInfo();

  /** 更新 Slate 几何缓存，尺寸变化时触发 CEF 视图 resize。 */
  UpdateCachedGeometry(InAllottedGeometry);

  /** 将 CEF 主视图和弹窗帧推进到 Slate 可绘制纹理。 */
  UpdateCefFrameTick();

  /** 外部 begin-frame 模式需要主动请求下一帧 CEF 渲染。 */
  RequestNextCefFrame();
}

void
SCefViewPrivate::NavigateToUrl(const FString& InTargetUrl)
{
  FScopeLock ScopedInitializationLock(&InitializationLock);
  if (pCefBrowser && pCefBrowser->GetMainFrame()) {
    pCefBrowser->GetMainFrame()->LoadURL(Convert::StringF2C(InTargetUrl));
  }
}

bool
SCefViewPrivate::TriggerCefEvent(const FString& InName,
                                 const TArray<TSharedPtr<FJsonValue>>& InArgs,
                                 const FCefFrameId& InFrameId /*= SCefView::MainFrameID*/)
{
  if (!InName.IsEmpty()) {
    return SendEventNotifyMessage(InFrameId, InName, InArgs);
  }
  return false;
}

bool
SCefViewPrivate::ResponseCefQuery(const int64 InQuery,
                                  const bool bInSuccess,
                                  const FString& InResponse,
                                  const int32 InError)
{
  if (pCefClient) {
    return pCefClient->ResponseQuery(InQuery, bInSuccess, Convert::StringF2C(InResponse), InError);
  }
  return false;
}

bool
SCefViewPrivate::ExecuteJavascript(const FCefFrameId& InFrameId, const FString& InCode, const FString& InUrl)
{
  if (InCode.IsEmpty())
    return false;

  if (pCefBrowser) {
    /** 先把 UE 侧帧标识转换成 CEF 侧标识。 */
    auto fid = Convert::FrameIdF2C(InFrameId);
    /** 主帧走 GetMainFrame，其余帧按当前 CEF 版本选择对应查找接口。 */
    auto frame = (SCefView::MainFrameID.Value == InFrameId.Value) ? //
                   pCefBrowser->GetMainFrame()
                                                                  : //
#if CEF_VERSION_MAJOR < 122
                   pCefBrowser->GetFrame(fid);
#else
                   pCefBrowser->GetFrameByIdentifier(fid);
#endif

    /** Frame 可能已经销毁，执行脚本前必须再次确认有效。 */
    if (!frame)
      return false;

    CefString Code;
    Code.FromString(Convert::StringF2C(InCode));

    CefString Url;
    if (InUrl.IsEmpty()) {
      Url = frame->GetURL();
    } else {
      Url.FromString(Convert::StringF2C(InUrl));
    }

    frame->ExecuteJavaScript(Code, Url, 0);
    return true;
  }

  return false;
}

bool
SCefViewPrivate::ExecuteJavascriptWithResult(const FCefFrameId& InFrameId,
                                             const FString& InCode,
                                             const FString& InUrl,
                                             const FString& InContext)
{
  if (InCode.IsEmpty())
    return false;

  if (pCefClient && pCefBrowser) {
    /** 先把 UE 侧帧标识转换成 CEF 侧标识。 */
    auto FrameId = Convert::FrameIdF2C(InFrameId);
    /** 主帧走 GetMainFrame，其余帧按当前 CEF 版本选择对应查找接口。 */
    auto Frame = (InFrameId.Value == SCefView::MainFrameID.Value) ? //
                   pCefBrowser->GetMainFrame()
                                                                  : //
#if CEF_VERSION_MAJOR < 122
                   pCefBrowser->GetFrame(FrameId);
#else
                   pCefBrowser->GetFrameByIdentifier(FrameId);
#endif

    /** Frame 可能已经销毁，执行脚本前必须再次确认有效。 */
    if (!Frame)
      return false;

    CefString Code;
    Code.FromString(Convert::StringF2C(InCode));

    CefString Url;
    if (InUrl.IsEmpty()) {
      Url = Frame->GetURL();
    } else {
      Url.FromString(Convert::StringF2C(InUrl));
    }

    CefString Context;
    Context.FromString(Convert::StringF2C(InContext));

    return pCefClient->AsyncExecuteJSCode(pCefBrowser, Frame, Code, Url, Context);
  }

  return false;
}

bool
SCefViewPrivate::SetPreference(const FString& InName, const TSharedPtr<FJsonValue>& InValue, FString& OutError)
{
  if (pCefBrowser) {
    CefRefPtr<CefBrowserHost> host = pCefBrowser->GetHost();
    if (host) {
      CefString Name;
      Name.FromString(Convert::StringF2C(InName));

      auto Value = CefValue::Create();
      Convert::JsonValueToCefValue(Value.get(), InValue);

      CefString Error;
      auto Result = host->GetRequestContext()->SetPreference(Name, Value, Error);
      OutError = Convert::StringC2F(Error);
      return Result;
    }
  }

  return false;
}

bool
SCefViewPrivate::SendEventNotifyMessage(const FCefFrameId& InFrameId,
                                        const FString& InName,
                                        const TArray<TSharedPtr<FJsonValue>>& InArgs)
{
  if (!pCefClient) {
    return false;
  }

  CefRefPtr<CefProcessMessage> Message = CefProcessMessage::Create(kCefViewClientBrowserTriggerEventMessage);
  CefRefPtr<CefListValue> Arguments = Message->GetArgumentList();

  /**
   * 事件消息参数布局：
   * +------------+
   * | 事件名     |
   * | 参数 1     |
   * | 参数 2     |
   * | 参数 3     |
   * | ...        |
   * +------------+
   */
  int Index = 0;
  CefString EventName = Convert::StringF2C(InName);
  Arguments->SetString(Index++, EventName);
  for (auto& jV : InArgs) {
    auto cVal = CefValue::Create();
    Convert::JsonValueToCefValue(cVal.get(), jV);
    Arguments->SetValue(Index++, cVal);
  }

  return pCefClient->TriggerEvent(pCefBrowser, Convert::FrameIdF2C(InFrameId), Message);
}

void
SCefViewPrivate::NotifyMoveOrResizeStarted()
{
  if (pCefBrowser) {
    CefRefPtr<CefBrowserHost> BrowserHost = pCefBrowser->GetHost();
    if (BrowserHost) {
      BrowserHost->NotifyMoveOrResizeStarted();
    }
  }
}

bool
SCefViewPrivate::IsCefBrowserCreated()
{
  return (pCefBrowser && pCefClient);
}

void
SCefViewPrivate::BuildCefBrowserSettings(CefBrowserSettings& InBrowserSettings, const FSlateCefViewSettings& InSettings)
{
  CefString(&InBrowserSettings.standard_font_family) = Convert::StringF2C(InSettings.StandardFontFamily);
  CefString(&InBrowserSettings.fixed_font_family) = Convert::StringF2C(InSettings.FixedFontFamily);
  CefString(&InBrowserSettings.serif_font_family) = Convert::StringF2C(InSettings.SerifFontFamily);
  CefString(&InBrowserSettings.sans_serif_font_family) = Convert::StringF2C(InSettings.SansSerifFontFamily);
  CefString(&InBrowserSettings.cursive_font_family) = Convert::StringF2C(InSettings.CursiveFontFamily);
  CefString(&InBrowserSettings.fantasy_font_family) = Convert::StringF2C(InSettings.FantasyFontFamily);
  InBrowserSettings.default_font_size = InSettings.DefaultFontSize;
  InBrowserSettings.default_fixed_font_size = InSettings.DefaultFixedFontSize;
  InBrowserSettings.minimum_font_size = InSettings.MinimumFontSize;
  InBrowserSettings.minimum_logical_font_size = InSettings.MinimumLogicalFontSize;
  CefString(&InBrowserSettings.default_encoding) = Convert::StringF2C(InSettings.DefaultEncoding);
#if CEF_VERSION_MAJOR < 118
  CefString(&InBrowserSettings.accept_language_list) = Convert::StringF2C(InSettings.AcceptLanguageList);
#endif
  InBrowserSettings.remote_fonts = (cef_state_t)InSettings.RemoteFonts;
  InBrowserSettings.javascript = (cef_state_t)InSettings.Javascript;
  InBrowserSettings.javascript_close_windows = (cef_state_t)InSettings.AllowJavascriptCloseWindows;
  InBrowserSettings.javascript_access_clipboard = (cef_state_t)InSettings.AllowJavascriptAccessClipboard;
  InBrowserSettings.javascript_dom_paste = (cef_state_t)InSettings.AllowJavascriptDomPaste;
#if CEF_VERSION_MAJOR < 100
  InBrowserSettings.plugins = (cef_state_t)InSettings.Plugins;
#endif
  InBrowserSettings.image_loading = (cef_state_t)InSettings.ImageLoading;
  InBrowserSettings.image_shrink_standalone_to_fit = (cef_state_t)InSettings.ImageShrinkStandaloneToFit;
  InBrowserSettings.text_area_resize = (cef_state_t)InSettings.TextAreaResize;
  InBrowserSettings.tab_to_links = (cef_state_t)InSettings.TabToLinks;
  InBrowserSettings.local_storage = (cef_state_t)InSettings.LocalStorage;
  InBrowserSettings.databases = (cef_state_t)InSettings.Databases;
  InBrowserSettings.webgl = (cef_state_t)InSettings.WebGL;
  InBrowserSettings.background_color = InSettings.BackgroundColor.ToPackedARGB();
}

void
SCefViewPrivate::CreateCefBrowser(const FSlateCefViewSettings& InSettings)
{
  FLog();

  auto HostWidget = m_pHost.Pin();
  if (!HostWidget) {
    logFatal() << "Host widget is invalid, cannot create browser";
    return;
  }

  check(!pCefBrowser && !pCefClient);
  if (pCefBrowser || pCefClient) {
    logDebug() << "Browser is already created, cannot create again";
    return;
  }

  if (!FSlateCefContext::IsInitialized()) {
    logError() << "CefContext is not initialized, cannot create browser";
    return;
  }

  if (!FSlateCefContext::Get().m_pImp->pApp_) {
    logError() << "CefApp is not initialized, cannot create browser";
    return;
  }

  /** 为当前 Slate 视图创建专属 CEF Client，并把回调委派到本对象处理。 */
  auto BrowserClientDelegate = std::make_shared<CCefClientDelegate>(SharedThis(this));
  auto BrowserClient = new CefViewBrowserClient(FSlateCefContext::Get().m_pImp->pApp_, BrowserClientDelegate);

  /** 合并控件实例级归档资源映射，覆盖范围只影响当前浏览器实例。 */
  for (const auto& ArchiveMapping : HostWidget->ArchiveFileResourceMapping) {
    if (ArchiveMapping.Path.FilePath.IsEmpty() || ArchiveMapping.Url.IsEmpty()) {
      continue;
    }

    auto GameDirectory = FPaths::ConvertRelativePathToFull(FPaths::ProjectDir());
    auto MappedArchivePath =
      FPaths::RemoveDuplicateSlashes(FPaths::Combine(GameDirectory, ArchiveMapping.Path.FilePath));
    BrowserClient->AddArchiveResourceProvider(Convert::StringF2C(MappedArchivePath),
                                              Convert::StringF2C(ArchiveMapping.Url),
                                              Convert::StringF2C(ArchiveMapping.Password),
                                              ArchiveMapping.Priority);
  }

  /** 合并控件实例级目录资源映射，供当前浏览器通过内置 scheme 访问。 */
  for (const auto& FolderMapping : HostWidget->LocalFolderResourceMapping) {
    if (FolderMapping.Path.Path.IsEmpty() || FolderMapping.Url.IsEmpty()) {
      continue;
    }

    auto GameContentDirectory = FPaths::ConvertRelativePathToFull(FPaths::ProjectContentDir());
    auto MappedFolderPath =
      FPaths::RemoveDuplicateSlashes((FPaths::Combine(GameContentDirectory, FolderMapping.Path.Path)));
    BrowserClient->AddLocalDirectoryResourceProvider(
      Convert::StringF2C(MappedFolderPath), Convert::StringF2C(FolderMapping.Url), FolderMapping.Priority);
  }

  /** 离屏渲染浏览器不创建原生子窗口，帧由外部 begin-frame 驱动。 */
  CefWindowInfo BrowserWindowInfo;
  BrowserWindowInfo.SetAsWindowless(0);
  BrowserWindowInfo.shared_texture_enabled = bIsCefSharedTextureEnabled;
  BrowserWindowInfo.external_begin_frame_enabled = true;

  /** 将单视图配置转换为 CEF BrowserSettings。 */
  CefBrowserSettings BrowserSettings;
  BuildCefBrowserSettings(BrowserSettings, InSettings);

  /** 创建 CEF Browser 后先缓存初始 URL，实际 browser 实例在 onAfterCreate 回调中落库。 */
  {
    FScopeLock ScopedInitializationLock(&InitializationLock);
    FString HostWidgetUrl = HostWidget->Url;
    if (!CefBrowserHost::CreateBrowser(BrowserWindowInfo,
                                       BrowserClient,
                                       Convert::StringF2C(HostWidgetUrl),
                                       BrowserSettings,
                                       nullptr,
                                       CefRequestContext::GetGlobalContext())) {
      logError() << "Failed to create cef browser";
      return;
    }

    InitializingUrl = HostWidgetUrl;
    pCefClient = BrowserClient;
    pCefClientDelegate = BrowserClientDelegate;
  }
}

void
SCefViewPrivate::DestroyCefBrowser()
{
  FLog();
  logDebug() << "destroy native browser";

  if (!pCefClient)
    return;

  /** 请求 CEF 关闭当前 Client 管理的所有 Browser，并释放本地引用。 */
  pCefClient->CloseAllBrowsers();
  pCefClient = nullptr;
  pCefBrowser = nullptr;
}

bool
SCefViewPrivate::IsSharedTextureSupported()
{
  bool bIsSupported = false;
  const TCHAR* DynamicRHIName = GDynamicRHI->GetName();

  if (0 == FCString::Stricmp(TEXT("D3D11"), DynamicRHIName)) {
    bIsSupported = true;
  } else if (0 == FCString::Stricmp(TEXT("D3D12"), DynamicRHIName)) {
    bIsSupported = true;
  } else if (0 == FCString::Stricmp(TEXT("Metal"), DynamicRHIName)) {
    bIsSupported = true;
  } else if (0 == FCString::Stricmp(TEXT("Vulkan"), DynamicRHIName)) {
    return false;
  }

  logInfo() << "Current RHI:" << DynamicRHIName << ", Shared Texture support: " << bIsSupported;
  return bIsSupported;
}

void
SCefViewPrivate::UpdateCachedWindowInfo()
{
  if (auto host = m_pHost.Pin()) {
    auto ParentWindow = FSlateApplication::Get().FindWidgetWindow(host.ToSharedRef());
    CachedParentWindow = ParentWindow;
    if (ParentWindow.IsValid() && ParentWindow->GetParentWindow().IsValid()) {
      CachedScaleFactor = ParentWindow->GetParentWindow()->GetNativeWindow()->GetDPIScaleFactor();
    } else {
      CachedScaleFactor = FSlateApplication::Get().GetApplicationScale();
    }
  }
}

void
SCefViewPrivate::UpdateCachedGeometry(const FGeometry& InAllottedGeometry)
{
  if (CachedGeometry != InAllottedGeometry) {
    CachedGeometry = InAllottedGeometry;

    /** 几何变化会影响 CEF 视图尺寸和 IME 候选窗位置。 */
    OnSizeEvent(InAllottedGeometry.GetLocalSize());
  }
}

void
SCefViewPrivate::ClearAlphaBuffers()
{
  FScopeLock ScopeLock(&AlphaHitTestLock);
  CefViewAlphaSizeX = 0;
  CefViewAlphaSizeY = 0;
  CefViewAlphaBuffer.Empty();
  CefPopupAlphaSizeX = 0;
  CefPopupAlphaSizeY = 0;
  CefPopupAlphaBuffer.Empty();
}

void
SCefViewPrivate::UpdateAlphaBuffer(TArray<uint8>& InOutAlphaBuffer,
                                   int32& OutSizeX,
                                   int32& OutSizeY,
                                   const void* InBuffer,
                                   int InWidth,
                                   int InHeight)
{
  if (!InBuffer || InWidth <= 0 || InHeight <= 0) {
    return;
  }

  const uint8* SourceBuffer = static_cast<const uint8*>(InBuffer);
  const int32 PixelCount = InWidth * InHeight;

  FScopeLock ScopeLock(&AlphaHitTestLock);
  OutSizeX = InWidth;
  OutSizeY = InHeight;
  InOutAlphaBuffer.SetNumUninitialized(PixelCount);

  for (int32 PixelIndex = 0; PixelIndex < PixelCount; ++PixelIndex) {
    InOutAlphaBuffer[PixelIndex] = SourceBuffer[PixelIndex * 4 + 3];
  }
}

bool
SCefViewPrivate::SampleAlphaBuffer(const TArray<uint8>& InAlphaBuffer,
                                   int32 InSizeX,
                                   int32 InSizeY,
                                   const FVector2D& InLocalPos,
                                   const FVector2D& InLocalSize,
                                   uint8& OutAlpha) const
{
  if (InSizeX <= 0 || InSizeY <= 0 || InAlphaBuffer.Num() != InSizeX * InSizeY) {
    return false;
  }

  if (InLocalSize.X <= 0.0f || InLocalSize.Y <= 0.0f) {
    return false;
  }

  if (InLocalPos.X < 0.0f || InLocalPos.Y < 0.0f || InLocalPos.X >= InLocalSize.X || InLocalPos.Y >= InLocalSize.Y) {
    return false;
  }

  const int32 PixelX = FMath::Clamp(FMath::FloorToInt((InLocalPos.X / InLocalSize.X) * InSizeX), 0, InSizeX - 1);
  const int32 PixelY = FMath::Clamp(FMath::FloorToInt((InLocalPos.Y / InLocalSize.Y) * InSizeY), 0, InSizeY - 1);
  OutAlpha = InAlphaBuffer[PixelY * InSizeX + PixelX];
  return true;
}

bool
SCefViewPrivate::ShouldPassthroughInput(const FVector2D& InLocalPos, const FVector2D& InLocalSize, uint8 InThreshold)
{
  auto HostWidget = m_pHost.Pin();
  if (!HostWidget || !HostWidget->IsAlphaHitTestPassthroughEnabled()) {
    return false;
  }

  if (InLocalSize.X <= 0.0f || InLocalSize.Y <= 0.0f) {
    return false;
  }

  if (InLocalPos.X < 0.0f || InLocalPos.Y < 0.0f || InLocalPos.X >= InLocalSize.X || InLocalPos.Y >= InLocalSize.Y) {
    return false;
  }

  FScopeLock ScopeLock(&AlphaHitTestLock);
  uint8 SampledAlpha = 255;

  const FVector2D PopupOffset(CefPopupFrameRect.Min.X, CefPopupFrameRect.Min.Y);
  const FVector2D PopupSize(CefPopupFrameRect.Max.X, CefPopupFrameRect.Max.Y);
  const bool bIsPointInsidePopup = bIsCefPopupShowing                                       //
    && PopupSize.X > 0.0f                                                                    //
    && PopupSize.Y > 0.0f                                                                    //
    && InLocalPos.X >= PopupOffset.X                                                         //
    && InLocalPos.Y >= PopupOffset.Y                                                         //
    && InLocalPos.X < PopupOffset.X + PopupSize.X                                            //
    && InLocalPos.Y < PopupOffset.Y + PopupSize.Y;

  if (bIsPointInsidePopup) {
    const FVector2D PopupLocalPosition = InLocalPos - PopupOffset;
    if (SampleAlphaBuffer(CefPopupAlphaBuffer, CefPopupAlphaSizeX, CefPopupAlphaSizeY, PopupLocalPosition, PopupSize, SampledAlpha)
        && SampledAlpha > InThreshold) {
      return false;
    }
  }

  if (SampleAlphaBuffer(CefViewAlphaBuffer, CefViewAlphaSizeX, CefViewAlphaSizeY, InLocalPos, InLocalSize, SampledAlpha)) {
    return SampledAlpha <= InThreshold;
  }

  return FMath::RoundToInt(BackgroundColor.A * 255.0f) <= InThreshold;
}

FIntPoint
SCefViewPrivate::GetSize() const
{
  return CachedGeometry.GetLocalSize().IntPoint();
}

FSlateShaderResource*
SCefViewPrivate::GetViewportRenderTargetTexture() const
{
  return PaintingTexture;
}

bool
SCefViewPrivate::RequiresVsync() const
{
  return false;
}

int32
SCefViewPrivate::PaintBackground(const FPaintArgs& InArgs,
                                 const FGeometry& InAllottedGeometry,
                                 const FSlateRect& InMyCullingRect,
                                 FSlateWindowElementList& InOutDrawElements,
                                 int32 InLayerId,
                                 const FWidgetStyle& InWidgetStyle)
{
  FSlateDrawElement::MakeBox(InOutDrawElements,
                             InLayerId,
                             InAllottedGeometry.ToPaintGeometry(),
                             &BackgroundBrush,
                             ESlateDrawEffect::None,
                             BackgroundColor);

  return ++InLayerId;
}

int32
SCefViewPrivate::PaintCefView(const FPaintArgs& InArgs,
                              const FGeometry& InAllottedGeometry,
                              const FSlateRect& InMyCullingRect,
                              FSlateWindowElementList& InOutDrawElements,
                              int32 InLayerId,
                              const FWidgetStyle& InWidgetStyle)
{
  if (false                                //
      || !CefViewFrameTexture.IsValid()    //
      || !CefViewFrameTexture->GetHeight() //
      || !CefViewFrameTexture->GetWidth()  //
  ) {
    return InLayerId;
  }

  PaintingTexture = CefViewFrameTexture.Get();
  FSlateDrawElement::MakeViewport(InOutDrawElements,                    //
                                  InLayerId,                            //
                                  InAllottedGeometry.ToPaintGeometry(), //
                                  SharedThis(this),                     //
                                  ESlateDrawEffect::NoGamma             //
  );
  PaintingTexture = nullptr;

  return ++InLayerId;
}

int32
SCefViewPrivate::PaintCefPopup(const FPaintArgs& InArgs,
                               const FGeometry& InAllottedGeometry,
                               const FSlateRect& InMyCullingRect,
                               FSlateWindowElementList& InOutDrawElements,
                               int32 InLayerId,
                               const FWidgetStyle& InWidgetStyle)
{
  if (!bIsCefPopupShowing                   //
      || !CefPopupFrameTexture.IsValid()    //
      || !CefPopupFrameTexture->GetHeight() //
      || !CefPopupFrameTexture->GetWidth()  //
  ) {
    return InLayerId;
  }

  auto Size = CefPopupFrameRect.Max;
  auto Offset = FSlateLayoutTransform(FVector2D(CefPopupFrameRect.Min.X, CefPopupFrameRect.Min.Y));
  PaintingTexture = CefPopupFrameTexture.Get();
  FSlateDrawElement::MakeViewport(InOutDrawElements,                                //
                                  InLayerId,                                        //
                                  InAllottedGeometry.ToPaintGeometry(Size, Offset), //
                                  SharedThis(this),                                 //
                                  ESlateDrawEffect::NoGamma                         //
  );
  PaintingTexture = nullptr;

  return ++InLayerId;
}

int32
SCefViewPrivate::PaintJSDialog(const FPaintArgs& InArgs,
                               const FGeometry& InAllottedGeometry,
                               const FSlateRect& InMyCullingRect,
                               FSlateWindowElementList& InOutDrawElements,
                               int32 InLayerId,
                               const FWidgetStyle& InWidgetStyle,
                               bool bInParentEnabled)
{
  FArrangedChildren ArrangedChildren(EVisibility::Visible);
  {
    this->ArrangeChildren(InAllottedGeometry, ArrangedChildren);
  }

  check(ArrangedChildren.Num() == 1);
  FArrangedWidget& TheChild = ArrangedChildren[0];
  InLayerId = TheChild.Widget->Paint(InArgs,            //
                                     TheChild.Geometry, //
                                     InMyCullingRect,   //
                                     InOutDrawElements, //
                                     InLayerId,         //
                                     InWidgetStyle,     //
                                     bInParentEnabled   //
  );

  return ++InLayerId;
}

#if defined(ENABLE_TRIAL_WATERMARK) && ENABLE_TRIAL_WATERMARK
#pragma message("************* ENABLE_TRIAL_WATERMARK is enabled *************")
int32
SCefViewPrivate::PaintWatermark(const FPaintArgs& InArgs,
                                const FGeometry& InAllottedGeometry,
                                const FSlateRect& InMyCullingRect,
                                FSlateWindowElementList& InOutDrawElements,
                                int32 InLayerId,
                                const FWidgetStyle& InWidgetStyle)
{
  static const FVector2D Spacing(250, 200);
  static const float RotationDegrees = -30.0f;
  static const FString TextStr = TEXT("UCefView Trial Version");
  static const FLinearColor WatermarkColor(0.0f, 0.0f, 1.0f, 0.5f);

  FSlateFontInfo FontInfo = FCoreStyle::Get().GetFontStyle("NormalFont");
  FontInfo.Size = 24.f;

  const FVector2D LocalSize = InAllottedGeometry.GetLocalSize();
  const TSharedRef<FSlateFontMeasure> FontMeasureService =
    FSlateApplication::Get().GetRenderer()->GetFontMeasureService();
  const FVector2D TextSize = FontMeasureService->Measure(TextStr, FontInfo);

  int32 RowIndex = 0;
  InOutDrawElements.PushClip(FSlateClippingZone(InAllottedGeometry.GetLayoutBoundingRect()));
  for (float Y = -Spacing.Y; Y < LocalSize.Y + Spacing.Y; Y += Spacing.Y) {
    float XOffset = (RowIndex % 2 == 0) ? 0.0f : Spacing.X * 0.5f;
    for (float X = -Spacing.X; X < LocalSize.X + Spacing.X; X += Spacing.X) {
      FPaintGeometry TextGeometry = InAllottedGeometry.ToPaintGeometry( //
        TextSize,
        FSlateLayoutTransform(FVector2D(X + XOffset, Y)),
        FSlateRenderTransform(FQuat2D(FMath::DegreesToRadians(RotationDegrees))),
        FVector2D(0.5f, 0.5f));

      FSlateDrawElement::MakeText( //
        InOutDrawElements,
        InLayerId,
        TextGeometry,
        TextStr,
        FontInfo,
        ESlateDrawEffect::None,
        WatermarkColor);
    }
    RowIndex++;
  }
  InOutDrawElements.PopClip();

  return ++InLayerId;
}
#endif

int32
SCefViewPrivate::PaintWidget(const FPaintArgs& InArgs,
                             const FGeometry& InAllottedGeometry,
                             const FSlateRect& InMyCullingRect,
                             FSlateWindowElementList& InOutDrawElements,
                             int32 InLayerId,
                             const FWidgetStyle& InWidgetStyle,
                             bool bInParentEnabled)
{
  /** 绘制顺序从背景开始，后续浏览器帧和覆盖层叠加在更高层级。 */
  InLayerId = PaintBackground( //
    InArgs,
    InAllottedGeometry,
    InMyCullingRect,
    InOutDrawElements,
    InLayerId,
    InWidgetStyle);

  /** 主浏览器帧承载普通页面内容。 */
  InLayerId = PaintCefView( //
    InArgs,
    InAllottedGeometry,
    InMyCullingRect,
    InOutDrawElements,
    InLayerId,
    InWidgetStyle);

  /** CEF 离屏弹窗需要独立纹理层覆盖在主视图之上。 */
  InLayerId = PaintCefPopup( //
    InArgs,
    InAllottedGeometry,
    InMyCullingRect,
    InOutDrawElements,
    InLayerId,
    InWidgetStyle);

  /** JavaScript 对话框使用 Slate 子控件覆盖在浏览器内容上方。 */
  InLayerId = PaintJSDialog( //
    InArgs,
    InAllottedGeometry,
    InMyCullingRect,
    InOutDrawElements,
    InLayerId,
    InWidgetStyle,
    bInParentEnabled);

#if defined(ENABLE_TRIAL_WATERMARK) && ENABLE_TRIAL_WATERMARK
  InLayerId = PaintWatermark( //
    InArgs,
    InAllottedGeometry,
    InMyCullingRect,
    InOutDrawElements,
    InLayerId,
    InWidgetStyle);
#endif

  return InLayerId;
}

void
SCefViewPrivate::OnSlateContextMenuCommand(int InCommand)
{
  FLog();

  if (CefContextMenu) {
    CefContextMenu->Continue(InCommand, EVENTFLAG_NONE);
    CefContextMenu.reset();
  }
}

void
SCefViewPrivate::OnSlateContextMenuDismissed(TSharedRef<IMenu> InMenu)
{
  DismissCefContextMenu();
  bIsShowingContextMenu = false;
}

bool
SCefViewPrivate::DisplaySlateContextMenu(FMenuBuilder& InBuilder, const FVector2D& InPos)
{
  auto HostWidget = m_pHost.Pin();
  if (!HostWidget) {
    return false;
  }

  /** 记录 Slate 菜单显示状态，避免 CEF 菜单回调被重复关闭。 */
  bIsShowingContextMenu = true;

  /** FMenuBuilder 在游戏线程生成实际 Slate 菜单控件。 */
  TSharedRef<SWidget> ContextWidget = InBuilder.MakeWidget();

  /** CEF 回调提供局部坐标，PushMenu 需要屏幕绝对坐标。 */
  FVector2D AbsolutePos = HostWidget->GetCachedGeometry().LocalToAbsolute(InPos);

  /** 将 CEF 菜单显示为 UE Slate 弹出菜单。 */
  SlateContextMenu = FSlateApplication::Get().PushMenu(          //
    HostWidget.ToSharedRef(),
    FWidgetPath(),
    ContextWidget,
    AbsolutePos,
    FPopupTransitionEffect(FPopupTransitionEffect::ContextMenu),
    false,
    FVector2D::ZeroVector
  );

  if (!SlateContextMenu) {
    /** Slate 菜单创建失败时要主动取消 CEF 回调，否则 CEF 会一直认为菜单仍在显示。 */
    DismissCefContextMenu();
    bIsShowingContextMenu = false;
    return false;
  }

  /** Slate 菜单关闭后同步通知 CEF 菜单生命周期结束。 */
  SlateContextMenu->GetOnMenuDismissed().AddSP( //
    this,
    &SCefViewPrivate::OnSlateContextMenuDismissed //
  );

  /** 菜单显示期间使用默认鼠标样式，避免页面自定义光标影响菜单交互。 */
  HostWidget->SetCursor(EMouseCursor::Type::Default);

  /** 键盘焦点切到菜单，确保方向键和快捷键由菜单消费。 */
  FSlateApplication::Get().SetKeyboardFocus(ContextWidget);

  /** Slate 菜单已接管 CEF 菜单交互。 */
  return true;
}

void
SCefViewPrivate::DismissSlateContextMenu()
{
  if (SlateContextMenu) {
    SlateContextMenu->Dismiss();
    SlateContextMenu.Reset();
  }

  bIsShowingContextMenu = false;
}

void
SCefViewPrivate::DismissCefContextMenu()
{
  FLog();

  if (CefContextMenu) {
    CefContextMenu->Cancel();
    CefContextMenu.reset();
  }
}

bool
SCefViewPrivate::CreateJSDialog(CefJSDialogHandler::JSDialogType InDialogType,
                                const FString& InOriginUrl,
                                const FString& InMessageText,
                                const FString& InDefaultPromptText,
                                CefRefPtr<CefJSDialogCallback>& InCallback)
{

  TSharedRef<SlateCefJSDialog> Dialog = SNew(SlateCefJSDialog)
                                          .Type(static_cast<SlateCefJSDialog::EDialogType>(InDialogType))
                                          .Title(InOriginUrl)
                                          .Message(InMessageText)
                                          .Prompt(InDefaultPromptText);

  /** 对话框作为覆盖层追加到当前 Overlay 末尾。 */
  int32 SlotIndex = ChildrenOverlay->GetChildren()->Num();

  ChildrenOverlay->AddSlot(INDEX_NONE).AttachWidget(Dialog);

  /** 用户响应后继续 CEF JS 对话框回调，并移除对应覆盖层。 */
  TWeakPtr<SCefViewPrivate> WeakSelf = SharedThis(this);
  Dialog->GetOnContinueDelegate().BindLambda([SlotIndex, WeakSelf, InCallback]                              //
                                             (bool bAccepted, const FString& Prompt) {                      //
                                               InCallback->Continue(bAccepted, Convert::StringF2C(Prompt)); //
                                               if (auto Self = WeakSelf.Pin()) {
                                                 Self->ChildrenOverlay->RemoveSlot(SlotIndex);
                                               }
                                             });

  /** 键盘焦点切给对话框，确保回车和输入先到达弹窗。 */
  FSlateApplication::Get().SetKeyboardFocus(Dialog);
  return true;
}

void
SCefViewPrivate::DestroyJSDialog(const TSharedPtr<SWidget>& InDialog)
{
}

void
SCefViewPrivate::RegisterIMEContext()
{
  FLog();

  ImeChangeNotifier.Reset();

  if (auto imeSystem = FSlateApplication::Get().GetTextInputMethodSystem()) {
    auto Context = SharedThis(this);
    ImeChangeNotifier = imeSystem->RegisterContext(Context);
    if (ImeChangeNotifier) {
      logInfo() << "IME Context registered successfully";
    } else {
      logError() << "IME Context registered failed";
    }
  }
}

void
SCefViewPrivate::UnregisterIMEContext()
{
  FLog();

  if (!ImeChangeNotifier.IsValid()) {
    logInfo() << "IME notifier is invalid, no need to unregister context";
    return;
  }

  if (auto imeSystem = FSlateApplication::Get().GetTextInputMethodSystem()) {
    imeSystem->UnregisterContext(SharedThis(this));
    ImeChangeNotifier.Reset();
    logInfo() << "IME Context unregistered successfully";
  }
}

void
SCefViewPrivate::ActivateIMEContext(bool bInForce /* = false*/)
{
  FLog();

  ResetComposition();
  bIsComposing = false;

  if (!ImeChangeNotifier.IsValid()) {
    logInfo() << "IME notifier is invalid, cannot activate context";
    return;
  }

  if (auto ImeSystem = FSlateApplication::Get().GetTextInputMethodSystem()) {
    UpdateCachedWindowInfo();

    if (bInForce || !ImeSystem->IsActiveContext(SharedThis(this))) {
      logDebug() << "Activate IME Context...";
      ImeSystem->ActivateContext(SharedThis(this));
    }
  }
}

void
SCefViewPrivate::DeactivateIMEContext()
{
  FLog();

  if (!ImeChangeNotifier.IsValid()) {
    logInfo() << "IME notifier is invalid, cannot deactivate context";
    return;
  }

  if (auto ImeSystem = FSlateApplication::Get().GetTextInputMethodSystem()) {
    if (ImeSystem->IsActiveContext(SharedThis(this))) {
      logDebug() << "Deactivate IME Context...";
      ImeSystem->DeactivateContext(SharedThis(this));
    }
  }

  ResetComposition();
  bIsComposing = false;
}

void
SCefViewPrivate::UpdateCefComposition()
{
  if (!pCefBrowser || !pCefBrowser->GetHost()) {
    return;
  }

  CefCompositionUnderline Underline;
  Underline.background_color = 0;
  Underline.range = CefRange(0, CompositionText.Len());

  pCefBrowser->GetHost()->ImeSetComposition(                          //
    Convert::StringF2C(CompositionText),                              //
    { Underline },                                                    //
    CefRange(UINT32_MAX, UINT32_MAX),                                 //
    CefRange(CompositionSelectionRange.X, CompositionSelectionRange.Y) //
  );
}

void
SCefViewPrivate::EndCefComposition()
{
  if (!pCefBrowser || !pCefBrowser->GetHost()) {
    return;
  }

  if (CompositionText.IsEmpty()) {
    pCefBrowser->GetHost()->ImeCancelComposition();
  } else {
    pCefBrowser->GetHost()->ImeCommitText(Convert::StringF2C(CompositionText), //
                                          CefRange(UINT32_MAX, UINT32_MAX),    //
                                          0                                    //
    );
  }
}

void
SCefViewPrivate::ResetComposition()
{
  CompositionText.Empty();
  CompositionCharBounds.Empty();
  CompositionSelectionRange = FVector2D::ZeroVector;
}

bool
SCefViewPrivate::IsComposing()
{
  return bIsComposing;
}

bool
SCefViewPrivate::IsReadOnly()
{
  return !bIsCefFocusedNodeEditable;
}

uint32
SCefViewPrivate::GetTextLength()
{
  logDebug() << CompositionText.Len();

  return CompositionText.Len();
}

void
SCefViewPrivate::GetSelectionRange(uint32& OutBeginIndex, uint32& OutLength, ECaretPosition& OutCaretPosition)
{
  OutBeginIndex = CompositionSelectionRange.X;
  OutLength = CompositionSelectionRange.Y - CompositionSelectionRange.X;
  logDebug() << CompositionSelectionRange.X << " - " << CompositionSelectionRange.Y;
}

void
SCefViewPrivate::SetSelectionRange(const uint32 InBeginIndex,
                                   const uint32 InLength,
                                   const ECaretPosition InCaretPosition)
{
  CompositionSelectionRange.X = InBeginIndex;
  CompositionSelectionRange.Y = InBeginIndex + InLength;
  logDebug() << CompositionSelectionRange.X << " - " << CompositionSelectionRange.Y;

  /** Slate 输入法选区变化后同步刷新 CEF 组合文本。 */
  UpdateCefComposition();
}

void
SCefViewPrivate::GetTextInRange(const uint32 InBeginIndex, const uint32 InLength, FString& OutString)
{
  OutString = CompositionText.Mid(InBeginIndex, InLength);
  logDebug() << InBeginIndex << " + " << InLength << ", Text:" << OutString;
}

void
SCefViewPrivate::SetTextInRange(const uint32 InBeginIndex, const uint32 InLength, const FString& InString)
{
  logDebug() << "Set Composition text in range:" << InBeginIndex << " + " << InLength << ", Text:" << InString;

  /** 根据 Slate 输入法写入范围重建本地组合文本。 */
  FString NewString;

  /** 保留替换范围左侧文本。 */
  if (InBeginIndex > 0) {
    NewString = CompositionText.Mid(0, InBeginIndex);
  }

  /** 写入输入法本次替换的文本片段。 */
  NewString += InString;

  if ((int32)(InBeginIndex + InLength) < CompositionText.Len()) {
    /** 保留替换范围右侧文本。 */
    NewString += CompositionText.Mid(InBeginIndex + InLength, CompositionText.Len() - (InBeginIndex + InLength));
  }

  /** 更新本地组合文本缓存。 */
  CompositionText = NewString;
  logDebug() << "Composition text updated:" << InString;

  /** 将新的组合文本同步到 CEF 输入法上下文。 */
  UpdateCefComposition();
}

int32
SCefViewPrivate::GetCharacterIndexFromPoint(const FVector2D& InPoint)
{
  logInfo() << "GetCharacterIndexFromPoint at:(" << InPoint.X << ", " << InPoint.Y << ")";

  const FVector2D LocalPosition = CachedGeometry.AbsoluteToLocal(InPoint);
  for (int Index = 0; Index < CompositionCharBounds.Num(); Index++) {
    if (CompositionCharBounds[Index].Contains(FIntPoint(LocalPosition.X, LocalPosition.Y))) {
      return Index;
    }
  }

  return INDEX_NONE;
}

bool
SCefViewPrivate::GetTextBounds(const uint32 InBeginIndex,
                               const uint32 InLength,
                               FVector2D& OutPosition,
                               FVector2D& OutSize)
{
  logInfo() << "GetTextBounds from:" << InBeginIndex << " to:" << InBeginIndex + InLength;

  OutPosition = FVector2D::ZeroVector;
  OutSize = FVector2D::ZeroVector;

  if (CompositionCharBounds.IsEmpty() || InBeginIndex >= static_cast<uint32>(CompositionCharBounds.Num())) {
    logInfo() << "Empty bounds or invalid index";
  } else {
    uint32 EndBoundIndex = FMath::Min<uint32>(CompositionCharBounds.Num(), InBeginIndex + InLength);
    FIntRect BoundingRect = CompositionCharBounds[InBeginIndex];
    for (uint32 CharIndex = InBeginIndex; CharIndex < EndBoundIndex; CharIndex++) {
      BoundingRect.Union(CompositionCharBounds[CharIndex]);
    }
    OutPosition = CachedGeometry.LocalToAbsolute(BoundingRect.Min);
    OutSize = CachedGeometry.LocalToAbsolute(BoundingRect.Max) - OutPosition;
    logInfo() << "Composition bound:" << "LTOP(" << OutPosition.X << " , " << OutPosition.Y << ")" << "SIZE["
              << OutSize.X << " x " << OutSize.Y << "]";
  }

  return false;
}

void
SCefViewPrivate::GetScreenBounds(FVector2D& OutPosition, FVector2D& OutSize)
{
  OutPosition = CachedGeometry.GetAbsolutePosition();
  OutSize = CachedGeometry.GetAbsoluteSize();
  logInfo() << "Screen Bounds:"                                          //
            << "Pos (" << OutPosition.X << " , " << OutPosition.Y << ")" //
            << "Size[" << OutSize.X << " x " << OutSize.Y << "]";        //
}

TSharedPtr<FGenericWindow>
SCefViewPrivate::GetWindow()
{
  auto SlateWindow = CachedParentWindow.Pin();
  if (SlateWindow) {
    return SlateWindow->GetNativeWindow();
  }

  UpdateCachedWindowInfo();

  SlateWindow = CachedParentWindow.Pin();
  return SlateWindow ? SlateWindow->GetNativeWindow() : nullptr;
}

void
SCefViewPrivate::BeginComposition()
{
  FLog();
  logDebug() << "Begin composition";

  if (!bIsComposing) {
    bIsComposing = true;

    ResetComposition();

    UpdateCefComposition();
  }
}

void
SCefViewPrivate::UpdateCompositionRange(const int32 InBeginIndex, const uint32 InLength)
{
  FLog();
  logDebug() << "InBeginIndex:" << InBeginIndex << ",InLength:" << InLength;

  if (bIsComposing) {
    logDebug() << "InBeginIndex:" << InBeginIndex << ",InLength:" << InLength;
    CompositionSelectionRange.X = InBeginIndex;
    CompositionSelectionRange.Y = InBeginIndex + InLength;
  }
}

void
SCefViewPrivate::EndComposition()
{
  FLog();
  logDebug() << "Composition end";

  EndCefComposition();

  ResetComposition();

  if (ImeChangeNotifier) {
    ImeChangeNotifier->NotifyLayoutChanged(ITextInputMethodChangeNotifier::ELayoutChangeType::Destroyed);
  }

  bIsComposing = false;
}

bool
SCefViewPrivate::OnBeforeManagedPopupBrowser(const FCefFrameId& InFrameId,
                                             const FString& InTargetUrl,
                                             FString& InTargetFrameName,
                                             int32 InTargetDisposition,
                                             FIntRect& OutRect,
                                             FSlateCefViewSettings& OutSettings,
                                             bool& bOutDisableJavascriptAccess)
{
  return false;
}

void
SCefViewPrivate::OnBeforeIsolatedPopupBrowser(const FCefFrameId& InSourceFrameId,
                                              const FString& InUrl,
                                              const FString& InName,
                                              const int32& InTargetDisposition,
                                              const FIntRect& InRect)
{
  TWeakPtr<SCefView> WeakHost = m_pHost;
  AsyncTask(ENamedThreads::GameThread, [WeakHost, InSourceFrameId, InUrl, InName, InTargetDisposition, InRect]() {
    auto Host = WeakHost.Pin();
    if (!Host) {
      return;
    }

    Host->OnNewBrowser(
      InSourceFrameId, InUrl, InName, static_cast<ECefWindowOpenDisposition>(InTargetDisposition), InRect);
  });
}

void
SCefViewPrivate::OnAfeterCefMainBrowserCreated(CefRefPtr<CefBrowser>& InBrowser)
{
  if (!InBrowser) {
    return;
  }

  if (auto Host = m_pHost.Pin()) {
    FScopeLock ScopedInitializationLock(&InitializationLock);

    /** CEF 主浏览器创建完成后缓存实例，后续导航、输入和渲染都依赖该对象。 */
    pCefBrowser = InBrowser;

    /** 创建完成立即同步 Slate 可见性和尺寸，避免首帧按默认大小渲染。 */
    auto Visibility = Host->GetVisibility();
    pCefBrowser->GetHost()->WasHidden((Visibility != EVisibility::Visible));
    pCefBrowser->GetHost()->WasResized();

    /** 构造期间 URL 可能被 UMG 属性同步覆盖，创建完成后补发最终导航。 */
    if (Host->Url != InitializingUrl) {
      pCefBrowser->GetMainFrame()->LoadURL(Convert::StringF2C(Host->Url));
      InitializingUrl.Empty();
    }
  }
}

void
SCefViewPrivate::OnAfterCefPopupBrowserCreated(CefRefPtr<CefBrowser>& InBrowser)
{
}

bool
SCefViewPrivate::OnRequestCloseFromWeb()
{
  auto HostWidget = m_pHost.Pin();
  if (!HostWidget) {
    return HostWidget->OnRequestCloseFromWeb();
  }

  return false;
}

void
SCefViewPrivate::OnOsrUpdateViewFromPixelBuffer(const void* InBuffer,
                                                int InWidth,
                                                int InHeight,
                                                const FIntRect& InRegion)
{
  CefViewFrameBulkData->RetainPixelBuffer(InBuffer, InWidth, InHeight, PF_B8G8R8A8);
  if (auto HostWidget = m_pHost.Pin(); HostWidget && HostWidget->IsAlphaHitTestPassthroughEnabled()) {
    UpdateAlphaBuffer(CefViewAlphaBuffer, CefViewAlphaSizeX, CefViewAlphaSizeY, InBuffer, InWidth, InHeight);
  }
}

void
SCefViewPrivate::OnOsrUpdatePopupFromPixelBuffer(const void* InBuffer,
                                                 int InWidth,
                                                 int InHeight,
                                                 const FIntRect& InRegion)
{
  CefPopupFrameBulkData->RetainPixelBuffer(InBuffer, InWidth, InHeight, PF_B8G8R8A8);
  if (auto HostWidget = m_pHost.Pin(); HostWidget && HostWidget->IsAlphaHitTestPassthroughEnabled()) {
    UpdateAlphaBuffer(CefPopupAlphaBuffer, CefPopupAlphaSizeX, CefPopupAlphaSizeY, InBuffer, InWidth, InHeight);
  }
}

void
SCefViewPrivate::OnOsrUpdateViewFromSharedTexture(void* InHandle, cef_color_type_t InColor, const FIntRect& InRegion)
{
  EPixelFormat PixelFormat = PF_Unknown;
  if (InColor == CEF_COLOR_TYPE_BGRA_8888) {
    PixelFormat = PF_B8G8R8A8;
  } else if (InColor == CEF_COLOR_TYPE_RGBA_8888) {
    PixelFormat = PF_R8G8B8A8;
  } else {
    /** 未支持的 CEF 颜色格式无法安全映射到 Unreal 像素格式。 */
    return;
  }

  CefViewFrameBulkData->RetainSharedTexture(InHandle, PixelFormat);
}

void
SCefViewPrivate::OnOsrUpdatePopupFromSharedTexture(void* InHandle, cef_color_type_t InColor, const FIntRect& InRegion)
{
  EPixelFormat PixelFormat = PF_Unknown;
  if (InColor == CEF_COLOR_TYPE_BGRA_8888) {
    PixelFormat = PF_B8G8R8A8;
  } else if (InColor == CEF_COLOR_TYPE_RGBA_8888) {
    PixelFormat = PF_R8G8B8A8;
  } else {
    /** 未支持的 CEF 颜色格式无法安全映射到 Unreal 像素格式。 */
    return;
  }

  CefPopupFrameBulkData->RetainSharedTexture(InHandle, PixelFormat);
}

void
SCefViewPrivate::UpdateCefFrameTick()
{
  TWeakPtr<SCefViewPrivate> WeakSelf = SharedThis(this);
  ENQUEUE_RENDER_COMMAND(UCEFVIEW_CREATE_TEXTURE_FROM_PIXEBUFFER)(
    [WeakSelf, this](FRHICommandListImmediate& RHICmdList) {
      auto Self = WeakSelf.Pin();
      if (!Self) {
        return;
      }

      /** 在渲染线程把主视图帧数据转换为 Slate 可绘制纹理。 */
      if (UETexture2DRHIRef CefViewTexture = CefViewFrameBulkData->CreateTexture(RHICmdList)) {
        CefViewFrameTexture->SetRHIRef(CefViewTexture);
      }

      /** 弹窗帧使用独立纹理，保证弹窗可以覆盖在主视图之上。 */
      if (UETexture2DRHIRef CefPopupTexture = CefPopupFrameBulkData->CreateTexture(RHICmdList)) {
        CefPopupFrameTexture->SetRHIRef(CefPopupTexture);
      }
    });
}

void
SCefViewPrivate::RequestNextCefFrame()
{
  if (pCefBrowser) {
    CefRefPtr<CefBrowserHost> host = pCefBrowser->GetHost();
    if (host) {
      host->SendExternalBeginFrame();
    }
  }
}

void
SCefViewPrivate::OnCefCursorChanged(CefCursorHandle InCursor,
                                    cef_cursor_type_t InType,
                                    const CefCursorInfo& InCustomCursorInfo)
{
  auto UpdateCursorData = [this, InType, InCustomCursorInfo]() mutable {
    auto HostWidget = m_pHost.Pin();
    if (!HostWidget) {
      return;
    }

    if (InType == CT_CUSTOM) {
      /** CEF 自定义光标以 BGRA 像素提供，必要时重建 UE 纹理承载数据。 */
      if (false                                                                //
          || !CustomCursorTexture.IsValid()                                    //
          || CustomCursorTexture->GetSizeX() != InCustomCursorInfo.size.width  //
          || CustomCursorTexture->GetSizeY() != InCustomCursorInfo.size.height //
      ) {
        CustomCursorTexture = TStrongObjectPtr<UTexture2D>(
          UTexture2D::CreateTransient(InCustomCursorInfo.size.width, InCustomCursorInfo.size.height, PF_B8G8R8A8));
      }

      /** 将 CEF 光标像素写入 UE 纹理的 mip 数据。 */
      auto TextureDataSize = InCustomCursorInfo.size.width * InCustomCursorInfo.size.height * 4;
      void* TextureData = CustomCursorTexture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
      if (TextureData) {
        FMemory::Memcpy(TextureData, InCustomCursorInfo.buffer, TextureDataSize);
      }
      CustomCursorTexture->GetPlatformData()->Mips[0].BulkData.Unlock();
      CustomCursorTexture->UpdateResource();

      /** 用 Slate Brush 包装光标纹理，供覆盖层显示。 */
      FSlateBrush* CursorBrush = new FSlateBrush();
      CursorBrush->SetResourceObject(CustomCursorTexture.Get());
      CursorBrush->ImageSize = FVector2D(CustomCursorTexture->GetSizeX(), CustomCursorTexture->GetSizeY());

      /** 更新覆盖层中的自定义光标图像。 */
      CustomCursorImage->SetImage(CursorBrush);
    }

    HostWidget->SetCursor(MapCefCursorTypeToEMouseCursorType(InType));
  };

  /** 光标纹理和 Slate 控件状态必须在游戏线程更新。 */
  if (IsInGameThread()) {
    UpdateCursorData();
  } else {
    FFunctionGraphTask::CreateAndDispatchWhenReady(
      MoveTemp(UpdateCursorData), TStatId(), nullptr, ENamedThreads::GameThread)
      ->Wait();
  }
}

void
SCefViewPrivate::OnCefReleasedFocus(bool bInNext)
{
  FLog();

  /** CEF 通过 Tab 释放焦点时，把 Slate 导航转给相邻控件。 */
  auto WeakHostWidget = m_pHost;
  AsyncTask(ENamedThreads::GameThread, [bInNext, WeakHostWidget]() {
    auto host = WeakHostWidget.Pin();
    if (!host) {
      return;
    }

    /** 按 CEF 给出的方向触发 UE 导航。 */
    auto Direction = bInNext ? EUINavigation::Next : EUINavigation::Previous;
    auto Reply = FReply::Handled().SetNavigation(Direction, ENavigationGenesis::Keyboard);
    FSlateApplication::Get().ProcessExternalReply(FWidgetPath(), Reply);
  });
}

bool
SCefViewPrivate::OnCefRequestFocus()
{
  FLog();

  /** 返回 false 允许 CEF 按默认流程获取焦点。 */
  return false;
}

void
SCefViewPrivate::OnCefGotFocus()
{
  FLog();

  bHasCefGotFocus = true;
}

void
SCefViewPrivate::OnBeforeCefContextMenu(const FCefFrameId& InSourceFrameId, const CefRefPtr<CefMenuModel>& InModel)
{
  auto HostWidget = m_pHost.Pin();
  if (!HostWidget) {
    return;
  }

  if (!HostWidget->bEnableContextMenu) {
    /** 控件关闭右键菜单时清空 CEF 菜单模型，从源头阻止菜单显示。 */
    InModel->Clear();
    return;
  }

  /** 新菜单出现前关闭旧 Slate 菜单，避免 CEF 菜单回调堆叠。 */
  TWeakPtr<SCefViewPrivate> WeakSelf = SharedThis(this);
  AsyncTask(ENamedThreads::GameThread, [WeakSelf]() {
    auto Self = WeakSelf.Pin();
    if (!Self) {
      return;
    }

    Self->DismissSlateContextMenu();
  });
}

void
SCefViewPrivate::OnRunCefContextMenu(const FCefFrameId& InSourceFrameId,
                                     const CefRefPtr<CefMenuModel>& InModel,
                                     const FVector2D& InPos,
                                     CefRefPtr<CefRunContextMenuCallback>& InCallback)
{
  if (!m_pHost.IsValid()) {
    return;
  }

  /** 用 CEF 菜单模型创建 Slate 菜单构建器。 */
  FMenuBuilder Builder( //
    false,
    nullptr,
    nullptr,
    false,
    &FCoreStyle::Get(),
    false,
    NAME_None,
    false
  );
  MenuUtils::BuildMenuFromModel(                                                                //
    Builder,                                                                                    //
    InModel.get(),                                                                              //
    MenuExecuteHandler::CreateSP(SharedThis(this), &SCefViewPrivate::OnSlateContextMenuCommand) //
  );

  TWeakPtr<SCefViewPrivate> WeakSelf = SharedThis(this);
  AsyncTask(ENamedThreads::GameThread, [WeakSelf, InCallback, Builder, InPos]() mutable {
    auto Self = WeakSelf.Pin();
    if (!Self) {
      return;
    }

    /** 在游戏线程弹出 Slate 菜单，并持有 CEF 回调直到菜单关闭。 */
    if (Self->DisplaySlateContextMenu(Builder, InPos)) {
      /** CEF 要求回调对象在菜单期间保持存活，否则菜单会被视为已取消。 */
      Self->CefContextMenu = InCallback;
    }
  });
}

void
SCefViewPrivate::OnCefContextMenuDismissed(const FCefFrameId& InSourceFrameId)
{
  TWeakPtr<SCefViewPrivate> WeakSelf = SharedThis(this);
  AsyncTask(ENamedThreads::GameThread, [WeakSelf]() {
    auto Self = WeakSelf.Pin();
    if (!Self) {
      return;
    }

    /** CEF 已通知菜单关闭，本地回调引用可以释放。 */
    Self->CefContextMenu.reset();

    /** 同步关闭 Slate 菜单，确保两边生命周期一致。 */
    Self->DismissSlateContextMenu();
  });
}

void
SCefViewPrivate::OnCefInputStateChanged(bool bInEditable)
{
  FLog();
  logDebug() << "OnCefInputStateChanged, editable:" << bInEditable;

  TWeakPtr<SCefViewPrivate> WeakSelf = SharedThis(this);
  AsyncTask(ENamedThreads::GameThread, [WeakSelf, bInEditable]() {
    auto Self = WeakSelf.Pin();
    if (!Self) {
      return;
    }

    Self->bIsCefFocusedNodeEditable = bInEditable;
    if (Self->bIsCefFocusedNodeEditable) {
      Self->ActivateIMEContext(true);
    } else {
      // Self->DeactivateIMEContext();
    }
  });
}

void
SCefViewPrivate::OnCefImeCompositionRangeChanged(const FVector2D& InSelectedRange,
                                                 const TArray<FIntRect>& InCharacterBounds)
{
  FLog();

  logDebug() << "OnCefImeCompositionRangeChanged, selectedRange:" << InSelectedRange.X << "-" << InSelectedRange.Y;

  auto UpdateIMEStatus = [this, InCharacterBounds, InSelectedRange]() mutable {
    bool bNeedUpdateIMEWindowPos = false;

    if (ImeChangeNotifier && CompositionCharBounds.IsEmpty() && IsComposing()) {
      /** 第一次收到组合字符边界时通知输入法创建候选窗口。 */
      ImeChangeNotifier->NotifyLayoutChanged(ITextInputMethodChangeNotifier::ELayoutChangeType::Created);
      bNeedUpdateIMEWindowPos = true;
    }

    /** 保存 CEF 回传的每个组合字符矩形，用于后续候选窗定位。 */
    CompositionCharBounds = InCharacterBounds;

    if (ImeChangeNotifier && IsComposing()) {
      /** 组合文本布局变化时通知输入法刷新候选窗口位置。 */
      ImeChangeNotifier->NotifyLayoutChanged(ITextInputMethodChangeNotifier::ELayoutChangeType::Changed);
    }

#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
    if (bNeedUpdateIMEWindowPos) {
      TWeakPtr<SCefViewPrivate> WeakSelf = SharedThis(this);
      AsyncTask(ENamedThreads::GameThread, [WeakSelf]() {
        if (auto Self = WeakSelf.Pin()) {
          Common::Windows::UpdateIMMWindowPositions(Self.ToSharedRef());
        }
      });
    }
#endif
  };

  if (IsInGameThread()) {
    UpdateIMEStatus();
  } else {
    FFunctionGraphTask::CreateAndDispatchWhenReady(
      MoveTemp(UpdateIMEStatus), TStatId(), nullptr, ENamedThreads::GameThread)
      ->Wait();
  }
}

void
SCefViewPrivate::OnCefTextSelectionChanged(const FString& InSelectedText, const FVector2D& InSelectedRange)
{
  FLog();
  logDebug() << "OnCefTextSelectionChanged, selectedRange:" << InSelectedRange.X << "-" << InSelectedRange.Y;
}

void
SCefViewPrivate::OnCefVirtualKeyboardRequested(CefRenderHandler::TextInputMode InInputMode)
{
  FLog();
}

bool
SCefViewPrivate::OnJSDialog(CefRefPtr<CefBrowser>& InBrowser,
                            const FString& InOriginUrl,
                            CefJSDialogHandler::JSDialogType InDialogType,
                            const FString& InMessageText,
                            const FString& InDefaultPromptText,
                            CefRefPtr<CefJSDialogCallback>& InCallback,
                            bool& bOutSuppressMessage)
{
  TWeakPtr<SCefViewPrivate> WeakSelf = SharedThis(this);
  AsyncTask(ENamedThreads::GameThread,
            [WeakSelf, InDialogType, InOriginUrl, InMessageText, InDefaultPromptText, InCallback]() mutable {
              auto Self = WeakSelf.Pin();
              if (!Self) {
                InCallback->Continue(false, "");
                return;
              }

              /** 在 Slate 覆盖层创建并显示对应的 JavaScript 对话框。 */
              if (!Self->CreateJSDialog( //
                    InDialogType,        //
                    InOriginUrl,         //
                    InMessageText,       //
                    InDefaultPromptText, //
                    InCallback)) {
                InCallback->Continue(false, "");
                return;
              }
            });
  return true;
}

bool
SCefViewPrivate::OnBeforeUnloadDialog(CefRefPtr<CefBrowser>& InBrowser,
                                      const FString& InMessageText,
                                      bool bInIsReload,
                                      CefRefPtr<CefJSDialogCallback>& InCallback)
{
  // TODO: implement JS dialog
  return false;
}

void
SCefViewPrivate::OnResetDialogState(CefRefPtr<CefBrowser>& InBrowser)
{
  TWeakPtr<SCefViewPrivate> WeakSelf = SharedThis(this);
  AsyncTask(ENamedThreads::GameThread, [WeakSelf]() mutable {
    auto Self = WeakSelf.Pin();
    if (!Self) {
      return;
    }

    /** 页面导航等事件会取消待处理对话框，覆盖层需要整体清空。 */
    Self->ChildrenOverlay->ClearChildren();
  });
}

void
SCefViewPrivate::OnDialogClosed(CefRefPtr<CefBrowser>& InBrowser)
{
  // TODO: implement JS dialog
}

void
SCefViewPrivate::OnBeforeDownload(CefRefPtr<CefBrowser>& InBrowser,
                                  CefRefPtr<CefDownloadItem>& InDownloadItem,
                                  const FString& InSuggestedName,
                                  CefRefPtr<CefBeforeDownloadCallback>& InCallback)
{
  // TODO: implement file downloading
}

void
SCefViewPrivate::OnDownloadUpdated(CefRefPtr<CefBrowser>& InBrowser,
                                   CefRefPtr<CefDownloadItem>& InDownloadItem,
                                   CefRefPtr<CefDownloadItemCallback>& InCallback)
{
  // TODO: implement file downloading
}

bool
SCefViewPrivate::ShouldAllowDrop(CefRefPtr<CefDragData>& InDragData, CefDragHandler::DragOperationsMask InAllowedOps)
{
  auto HostWidget = m_pHost.Pin();
  if (!HostWidget) {
    return false;
  }

  return HostWidget->bAcceptDrops;
}

void
SCefViewPrivate::OnDragSourceEnd(bool bDropWasHandled, const FPointerEvent& MouseEvent)
{
  if (!pCefBrowser || !(pCefBrowser->GetHost())) {
    return;
  }

  FVector2D LocalPosition = CachedGeometry.AbsoluteToLocal(MouseEvent.GetScreenSpacePosition());
  pCefBrowser->GetHost()->DragSourceEndedAt(LocalPosition.X, //
                                            LocalPosition.Y, //
                                            CefRenderHandler::DragOperation::DRAG_OPERATION_GENERIC);
  pCefBrowser->GetHost()->DragSourceSystemDragEnded();
}

bool
SCefViewPrivate::ShouldAllowDrag(CefRefPtr<CefDragData>& InDragData,
                                 CefRenderHandler::DragOperationsMask InAllowedOps,
                                 int InX,
                                 int InY)
{
  FLog();
  auto HostWidget = m_pHost.Pin();
  if (!HostWidget) {
    /** 宿主控件已失效时取消本次 CEF 拖拽。 */
    return false;
  }

  /** 该路径仅服务离屏渲染拖拽，控件未开启拖拽时让 CEF 取消操作。 */
  if (!HostWidget->bAllowDrag) {
    return false;
  }

  /** CEF 发起的拖拽需要切到游戏线程创建 Slate DragDropOperation。 */
  FFunctionGraphTask::CreateAndDispatchWhenReady(
    [this, InDragData, InX, InY]() mutable {
      /** 将 CEF 拖拽数据封装为 Slate 拖拽操作。 */
      auto Ops = CreateFCefDragDropOperation(InDragData);
      /** 拖拽结束时把结果回传给 CEF。 */
      Ops->OnDragSourceEnd.BindSP(SharedThis(this), &SCefViewPrivate::OnDragSourceEnd);
      /** 通过 Slate Reply 启动拖拽流程。 */
      auto Reply = FReply::Handled().BeginDragDrop(Ops.ToSharedRef());
      /** 将 Reply 注入 Slate 应用，使拖拽立即进入 UE 输入系统。 */
      FSlateApplication::Get().ProcessExternalReply(FWidgetPath(), Reply);

      /** 初始化允许操作，后续由 CEF DragTarget 回调刷新。 */
      CurrentAllowDragOperation = DRAG_OPERATION_EVERY;

      /** 通知 CEF 拖拽已经进入当前视图坐标。 */
      CefMouseEvent MouseEvent;
      MouseEvent.x = InX;
      MouseEvent.y = InY;
      pCefBrowser->GetHost()->DragTargetDragEnter(Ops->GetCefDragData(), MouseEvent, DRAG_OPERATION_EVERY);
      pCefBrowser->GetHost()->DragTargetDragOver(MouseEvent, DRAG_OPERATION_EVERY);
    },
    TStatId(),
    nullptr,
    ENamedThreads::GameThread)
    ->Wait();

  return true;
}

void
SCefViewPrivate::UpdateDragOperation(CefRenderHandler::DragOperationsMask InAllowedOps)
{
  logDebug() << "SCefViewPrivate::UpdateDragOperation:" << InAllowedOps;
  CurrentAllowDragOperation = InAllowedOps;
}

void
SCefViewPrivate::OnSizeEvent(const FVector2D& InNewSize)
{
  if (pCefBrowser && pCefBrowser->GetHost()) {
    /** Slate 尺寸变化时让 CEF 失效并重新按新尺寸渲染。 */
    pCefBrowser->GetHost()->Invalidate(CefBrowserHost::PaintElementType::PET_VIEW);
    pCefBrowser->GetHost()->WasResized();
  }

  if (ImeChangeNotifier) {
    ImeChangeNotifier->NotifyLayoutChanged(ITextInputMethodChangeNotifier::ELayoutChangeType::Changed);
  }
}

void
SCefViewPrivate::OnVisibilityEvent(bool bInVisible)
{
  if (pCefBrowser && pCefBrowser->GetHost())
    pCefBrowser->GetHost()->WasHidden(!bInVisible);
}

void
SCefViewPrivate::OnFocusEvent(bool bInFocused, const FFocusEvent& InFocusEvent)
{
  if (!pCefBrowser || !pCefBrowser->GetHost())
    return;

  if (bInFocused) {
    if (bHasCefGotFocus) {
      logDebug() << "CEF got focus already, skip setting";
      return;
    }

    logDebug() << "SYNC FOCUS: SCefView -> CEF";
    pCefBrowser->GetHost()->SetFocus(true);

    if (bIsCefFocusedNodeEditable) {
      ActivateIMEContext();
    }
  } else {
    if (bIsCefFocusedNodeEditable) {
      DeactivateIMEContext();
    }

    if (bIsShowingContextMenu) {
      logDebug() << "Context menu is showing, skip clear focus request";
      return;
    }

    bHasCefGotFocus = false;
    pCefBrowser->GetHost()->SetFocus(false);
  }
}

void
SCefViewPrivate::OnMouseMoveEvent(const FPointerEvent& InMouseEvent, const FVector2D& InLocalPos, bool bInLeave)
{
  if (!pCefBrowser)
    return;

  if (bIsShowingContextMenu) {
    logDebug() << "Context menu is showing, skip mouse move event";
    return;
  }

  CefMouseEvent MouseEvent;
  FMemory::Memset(&MouseEvent, 0, sizeof(MouseEvent));

  if (bInLeave) {
    pCefBrowser->GetHost()->SendMouseMoveEvent(MouseEvent, true);
    return;
  }

  MouseEvent.x = InLocalPos.X;
  MouseEvent.y = InLocalPos.Y;
  MouseEvent.modifiers = GetCefMouseModifiers(InMouseEvent);

  pCefBrowser->GetHost()->SendMouseMoveEvent(MouseEvent, false);
}

void
SCefViewPrivate::OnMouseButtonDownEvent(const FPointerEvent& InMouseEvent, const FVector2D& InLocalPos)
{
  FLog();
  if (!pCefBrowser)
    return;

  CefMouseEvent MouseEvent;
  FMemory::Memset(&MouseEvent, 0, sizeof(MouseEvent));

  MouseEvent.x = InLocalPos.X;
  MouseEvent.y = InLocalPos.Y;
  MouseEvent.modifiers = GetCefMouseModifiers(InMouseEvent);

  auto MouseButtonType = GetCefMouseButton(InMouseEvent);

  logDebug() << "SendMouseClickEvent:Down, Pos:" << MouseEvent.x << "," << MouseEvent.y;
  pCefBrowser->GetHost()->SendMouseClickEvent(MouseEvent, MouseButtonType, false, 1);
}

void
SCefViewPrivate::OnMouseButtonUpEvent(const FPointerEvent& InMouseEvent, const FVector2D& InLocalPos)
{
  FLog();
  if (!pCefBrowser)
    return;

  CefMouseEvent MouseEvent;
  FMemory::Memset(&MouseEvent, 0, sizeof(MouseEvent));

  MouseEvent.x = InLocalPos.X;
  MouseEvent.y = InLocalPos.Y;
  MouseEvent.modifiers = GetCefMouseModifiers(InMouseEvent);

  auto ButtonType = GetCefMouseButton(InMouseEvent);

  logDebug() << "SendMouseClickEvent:Up, Pos:" << MouseEvent.x << "," << MouseEvent.y;
  pCefBrowser->GetHost()->SendMouseClickEvent(MouseEvent, ButtonType, true, 1);
}

void
SCefViewPrivate::OnMouseButtonDoubleClickEvent(const FPointerEvent& InMouseEvent, const FVector2D& InLocalPos)
{
  FLog();
  if (!pCefBrowser)
    return;

  CefMouseEvent MouseEvent;
  FMemory::Memset(&MouseEvent, 0, sizeof(MouseEvent));

  MouseEvent.x = InLocalPos.X;
  MouseEvent.y = InLocalPos.Y;
  MouseEvent.modifiers = GetCefMouseModifiers(InMouseEvent);

  auto ButtonType = GetCefMouseButton(InMouseEvent);

  logDebug() << "SendMouseClickEvent:DblClick, Pos:" << MouseEvent.x << "," << MouseEvent.y;
  pCefBrowser->GetHost()->SendMouseClickEvent(MouseEvent, ButtonType, false, 2);
}

void
SCefViewPrivate::OnMouseWheelEvent(const FPointerEvent& InMouseEvent, const FVector2D& InLocalPos)
{
  FLog();
  if (!pCefBrowser)
    return;

  if (bIsShowingContextMenu) {
    logDebug() << "Context menu is showing, skip mouse move event";
    return;
  }

  CefMouseEvent MouseEvent;
  FMemory::Memset(&MouseEvent, 0, sizeof(MouseEvent));

  MouseEvent.x = InLocalPos.X;
  MouseEvent.y = InLocalPos.Y;
  MouseEvent.modifiers = GetCefMouseModifiers(InMouseEvent);

  float WheelDeltaX = InMouseEvent.GetWheelDelta() * 10.f;
  float WheelDeltaY = InMouseEvent.GetWheelDelta() * 10.f;

  if (FMath::Abs(WheelDeltaX) > FMath::Abs(WheelDeltaY)) {
    WheelDeltaY = 0;
  } else {
    WheelDeltaX = 0;
  }

  pCefBrowser->GetHost()->SendMouseWheelEvent(MouseEvent, WheelDeltaX, WheelDeltaY);
}

void
SCefViewPrivate::OnTouchStartedEvent(const FPointerEvent& InTouchEvent, const FVector2D& InLocalPos)
{
  FLog();
  if (!pCefBrowser)
    return;

  CefTouchEvent TouchEvent;
  FMemory::Memset(&TouchEvent, 0, sizeof(TouchEvent));

  TouchEvent.type = CEF_TET_PRESSED;
  TouchEvent.x = InLocalPos.X;
  TouchEvent.y = InLocalPos.Y;
  TouchEvent.id = InTouchEvent.GetPointerIndex();
  TouchEvent.pressure = InTouchEvent.GetTouchForce() / 10;

  logDebug() << "SendTouchEvent: CEF_TET_PRESSED, Pos:" << TouchEvent.x << "," << TouchEvent.y;
  pCefBrowser->GetHost()->SendTouchEvent(TouchEvent);
}

void
SCefViewPrivate::OnTouchMovedEvent(const FPointerEvent& InTouchEvent, const FVector2D& InLocalPos)
{
  FLog();
  if (!pCefBrowser)
    return;

  if (bIsShowingContextMenu) {
    logDebug() << "Context menu is showing, skip touch move event";
    return;
  }

  CefTouchEvent TouchEvent;
  FMemory::Memset(&TouchEvent, 0, sizeof(TouchEvent));

  TouchEvent.type = CEF_TET_MOVED;
  TouchEvent.x = InLocalPos.X;
  TouchEvent.y = InLocalPos.Y;
  TouchEvent.id = InTouchEvent.GetPointerIndex();
  TouchEvent.pressure = InTouchEvent.GetTouchForce() / 10;

  // logDebug() << "SendTouchEvent: CEF_TET_MOVED, Pos:" << TouchEvent.x << "," << TouchEvent.y;
  pCefBrowser->GetHost()->SendTouchEvent(TouchEvent);
}

void
SCefViewPrivate::OnTouchEndedEvent(const FPointerEvent& InTouchEvent, const FVector2D& InLocalPos)
{
  FLog();
  if (!pCefBrowser)
    return;

  CefTouchEvent TouchEvent;
  FMemory::Memset(&TouchEvent, 0, sizeof(TouchEvent));

  TouchEvent.type = CEF_TET_RELEASED;
  TouchEvent.x = InLocalPos.X;
  TouchEvent.y = InLocalPos.Y;
  TouchEvent.id = InTouchEvent.GetPointerIndex();
  TouchEvent.pressure = InTouchEvent.GetTouchForce() / 10;

  logDebug() << "SendTouchEvent: CEF_TET_RELEASED, Pos:" << TouchEvent.x << "," << TouchEvent.y;
  pCefBrowser->GetHost()->SendTouchEvent(TouchEvent);
}

void
SCefViewPrivate::OnTouchCancelledEvent(const FPointerEvent& InTouchEvent, const FVector2D& InLocalPos)
{
  FLog();
  if (!pCefBrowser)
    return;

  CefTouchEvent TouchEvent;
  FMemory::Memset(&TouchEvent, 0, sizeof(TouchEvent));

  TouchEvent.type = CEF_TET_CANCELLED;
  TouchEvent.x = InLocalPos.X;
  TouchEvent.y = InLocalPos.Y;
  TouchEvent.id = InTouchEvent.GetPointerIndex();
  TouchEvent.pressure = InTouchEvent.GetTouchForce() / 10;

  logDebug() << "SendTouchEvent: CEF_TET_CANCELLED, Pos:" << TouchEvent.x << "," << TouchEvent.y;
  pCefBrowser->GetHost()->SendTouchEvent(TouchEvent);
}

void
SCefViewPrivate::OnKeyDownEvent(const FKeyEvent& InKeyEvent)
{
  if (!pCefBrowser)
    return;

  if (!bHasCefGotFocus)
    return;

  CefKeyEvent KeyEvent;
  FMemory::Memset(&KeyEvent, 0, sizeof(KeyEvent));

  MapFKeyEventToCefKeyEvent(InKeyEvent, KeyEvent);

  KeyEvent.type = KEYEVENT_RAWKEYDOWN;
  pCefBrowser->GetHost()->SendKeyEvent(KeyEvent);
}

void
SCefViewPrivate::OnKeyCharEvent(const FCharacterEvent& InCharacterEvent)
{
  if (!pCefBrowser)
    return;

  if (!bHasCefGotFocus)
    return;

  CefKeyEvent KeyEvent;
  FMemory::Memset(&KeyEvent, 0, sizeof(KeyEvent));

#if PLATFORM_MAC || PLATFORM_LINUX
  KeyEvent.character = InCharacterEvent.GetCharacter();
  KeyEvent.windows_key_code = InCharacterEvent.GetCharacter();
#else
  KeyEvent.windows_key_code = InCharacterEvent.GetCharacter();
#endif

  KeyEvent.type = KEYEVENT_CHAR;
  KeyEvent.modifiers = GetCefInputModifiers(InCharacterEvent);
  pCefBrowser->GetHost()->SendKeyEvent(KeyEvent);
}

void
SCefViewPrivate::OnKeyUpEvent(const FKeyEvent& InKeyEvent)
{
  if (!pCefBrowser)
    return;

  if (!bHasCefGotFocus)
    return;

  CefKeyEvent KeyEvent;
  FMemory::Memset(&KeyEvent, 0, sizeof(KeyEvent));

  MapFKeyEventToCefKeyEvent(InKeyEvent, KeyEvent);

  KeyEvent.type = KEYEVENT_KEYUP;
  pCefBrowser->GetHost()->SendKeyEvent(KeyEvent);
  return;
}

void
SCefViewPrivate::OnDragEnter(const FDragDropEvent& InDragDropEvent, const FVector2D& InLocalPos)
{
  if (!pCefBrowser)
    return;

  /** Slate 拖拽事件中的操作对象需要转换为 CEF DragData。 */
  auto DragDropOperation = InDragDropEvent.GetOperation();
  if (!DragDropOperation.IsValid()) {
    return;
  }

  auto DragData = CreateCefDragData(DragDropOperation);
  if (!DragData) {
    return;
  }

  CefMouseEvent MouseEvent;
  FMemory::Memset(&MouseEvent, 0, sizeof(MouseEvent));

  MouseEvent.x = InLocalPos.X;
  MouseEvent.y = InLocalPos.Y;
  MouseEvent.modifiers = GetCefMouseModifiers(InDragDropEvent);
  pCefBrowser->GetHost()->DragTargetDragEnter(DragData, MouseEvent, DRAG_OPERATION_EVERY);
  pCefBrowser->GetHost()->DragTargetDragOver(MouseEvent, DRAG_OPERATION_EVERY);
}

FReply
SCefViewPrivate::OnDragOver(const FDragDropEvent& InDragDropEvent, const FVector2D& InLocalPos)
{
  if (!pCefBrowser)
    return FReply::Unhandled();

  /** 只处理 CEF 可接受的 Slate 拖拽数据。 */
  auto DragDropOperation = InDragDropEvent.GetOperation();
  if (!DragDropOperation.IsValid()) {
    return FReply::Unhandled();
  }

  if (!IsCefAcceptableDragData(DragDropOperation)) {
    return FReply::Unhandled();
  }

  CefMouseEvent MouseEvent;
  FMemory::Memset(&MouseEvent, 0, sizeof(MouseEvent));

  MouseEvent.x = InLocalPos.X;
  MouseEvent.y = InLocalPos.Y;
  MouseEvent.modifiers = GetCefMouseModifiers(InDragDropEvent);
  pCefBrowser->GetHost()->DragTargetDragOver(MouseEvent, DRAG_OPERATION_EVERY);

  DragDropOperation->SetCursorOverride(MapCefDragDropOperationToEMouseCursorType(CurrentAllowDragOperation));

  return FReply::Handled();
}

FReply
SCefViewPrivate::OnDrop(const FDragDropEvent& InDragDropEvent, const FVector2D& InLocalPos)
{
  if (!pCefBrowser)
    return FReply::Unhandled();

  /** Drop 时复用 Slate 拖拽对象向 CEF 完成投递。 */
  auto DragDropOperation = InDragDropEvent.GetOperation();
  if (!DragDropOperation.IsValid()) {
    return FReply::Unhandled();
  }

  if (!IsCefAcceptableDragData(DragDropOperation)) {
    return FReply::Unhandled();
  }

  CefMouseEvent MouseEvent;
  FMemory::Memset(&MouseEvent, 0, sizeof(MouseEvent));

  MouseEvent.x = InLocalPos.X;
  MouseEvent.y = InLocalPos.Y;
  MouseEvent.modifiers = GetCefMouseModifiers(InDragDropEvent);
  pCefBrowser->GetHost()->DragTargetDrop(MouseEvent);

  return FReply::Handled();
}

void
SCefViewPrivate::OnDragLeave(const FDragDropEvent& InDragDropEvent)
{
  if (!pCefBrowser)
    return;

  auto DragDropOperation = InDragDropEvent.GetOperation();
  if (DragDropOperation.IsValid() && IsCefAcceptableDragData(DragDropOperation)) {
    pCefBrowser->GetHost()->DragTargetDragLeave();
  }
}

FReply
SCefViewPrivate::OnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
  return FReply::Unhandled();
}
