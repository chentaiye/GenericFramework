//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "Platform.h"
#pragma endregion

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <limits>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#include "HeadersCefViewCore.h"
#pragma endregion

namespace Common {
namespace Windows {
#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
/** 按需加载 Windows 系统 DLL，并以 RAII 方式释放模块句柄。 */
class WinApiModule
{
public:
  /** 加载指定系统模块，后续通过模块句柄查询 Win32 API。 */
  WinApiModule(const std::wstring& InModulePathName)
    : m_ModuleHandle(::LoadLibraryW(InModulePathName.c_str()))
  {
  }

  /** 释放已加载模块句柄。 */
  ~WinApiModule()
  {
    if (m_ModuleHandle) {
      ::FreeLibrary(m_ModuleHandle);
      m_ModuleHandle = nullptr;
    }
  }

  /** 判断模块是否加载成功。 */
  bool IsValid() const { return m_ModuleHandle != nullptr; }

  /** 便于调用点直接把模块对象作为有效性条件使用。 */
  operator bool() const { return IsValid(); }

  /** 从模块中解析指定 API 并立即调用，解析失败时返回默认值。 */
  template<typename ReturnType, typename... Arguments>
  ReturnType Invoke(const std::string& InApiName, Arguments... InArgs)
  {
    typedef ReturnType(WINAPI * FunType)(Arguments... InArgs);
#pragma warning(push)
#pragma warning(disable : 4191) // GetProcAddress 需要按目标函数签名转换函数指针。
    auto pFunc = reinterpret_cast<FunType>(::GetProcAddress(m_ModuleHandle, InApiName.c_str()));
#pragma warning(push)
    if (!pFunc) {
      return ReturnType{};
    }
    logDebug() << "Invoke:" << InApiName;
    return pFunc(InArgs...);
  }

private:
  HMODULE m_ModuleHandle = nullptr;
};

void
UpdateIMMWindowPositions(const TSharedRef<ITextInputMethodContext>& InInputContext)
{
  /** IMM32 在 Windows 输入法路径中按需加载，避免非 Windows 平台或无 IME 场景额外依赖。 */
  WinApiModule IMM32Lib(L"imm32.dll");
  if (!IMM32Lib.IsValid()) {
    return;
  }

  /** 候选窗和组合窗需要原生窗口句柄才能定位到 Slate 控件对应的屏幕区域。 */
  TSharedPtr<FGenericWindow> GenericWindow = InInputContext->GetWindow();
  HWND WindowHandle = reinterpret_cast<HWND>(GenericWindow->GetOSWindowHandle());
  if (!WindowHandle) {
    return;
  }

  struct HIMCWrapper
  {
    HIMCWrapper(WinApiModule& InIMM32Lib, HWND InWindowHandle)
      : IMM32Lib(InIMM32Lib)
      , WindowHandle(InWindowHandle)
    {
      if (WindowHandle) {
        IMMContextHandle = IMM32Lib.Invoke<HIMC, HWND>("ImmGetContext", WindowHandle);
      }
    }

    ~HIMCWrapper()
    {
      if (WindowHandle && IMMContextHandle) {
        IMM32Lib.Invoke<BOOL, HWND, HIMC>("ImmReleaseContext", WindowHandle, IMMContextHandle);
        WindowHandle = nullptr;
        IMMContextHandle = nullptr;
      }
    }

    operator bool() const { return IMMContextHandle != nullptr; }

    operator HIMC() const { return IMMContextHandle; }

  private:
    WinApiModule& IMM32Lib;
    HWND WindowHandle = nullptr;
    HIMC IMMContextHandle = nullptr;
  };

  /** 取得当前窗口的 IMM 上下文，并在离开作用域时自动归还。 */
  HIMCWrapper IMMContext(IMM32Lib, WindowHandle);
  if (!IMMContext) {
    return;
  }

  /** Slate 输入法上下文给出光标文本区域，后续换算到原生窗口坐标。 */
  FVector2D Position;
  FVector2D Size;
  InInputContext->GetTextBounds(0, InInputContext->GetTextLength(), Position, Size);
  logDebug() << "TextBounds:" << "(" << Position.X << ", " << Position.Y << ")";

  /** Win32 IMM API 使用窗口本地坐标，需要扣除窗口左上角屏幕位置。 */
  RECT WindowRect;
  ::GetWindowRect(WindowHandle, &(WindowRect));
  Position.X -= WindowRect.left;
  Position.Y -= WindowRect.top;
  logDebug() << "WindowRect:" << "(" << WindowRect.left << ", " << WindowRect.top << ")";

  /** 候选窗贴近当前文本区域，避免中文候选列表漂移到浏览器视图外。 */
  CANDIDATEFORM CandidateForm;
  CandidateForm.dwIndex = 0;
  CandidateForm.dwStyle = CFS_EXCLUDE;
  CandidateForm.ptCurrentPos.x = Position.X;
  CandidateForm.ptCurrentPos.y = Position.Y;
  CandidateForm.rcArea.left = CandidateForm.ptCurrentPos.x;
  CandidateForm.rcArea.right = CandidateForm.ptCurrentPos.x;
  CandidateForm.rcArea.top = CandidateForm.ptCurrentPos.y;
  CandidateForm.rcArea.bottom = CandidateForm.ptCurrentPos.y + Size.Y;
  logDebug() << "ImmSetCandidateWindow at:"
             << "(" << CandidateForm.ptCurrentPos.x << ", " << CandidateForm.ptCurrentPos.y << ")";
  if (!IMM32Lib.Invoke<BOOL, HIMC, LPCANDIDATEFORM>("ImmSetCandidateWindow", IMMContext, &CandidateForm)) {
    logDebug() << "Failed to call ImmSetCandidateWindow";
  }

  /** 组合窗放在文本区域下方，与 CEF 回传的编辑节点位置保持一致。 */
  COMPOSITIONFORM CompositionForm;
  CompositionForm.dwStyle = CFS_POINT;
  CompositionForm.ptCurrentPos.x = Position.X;
  CompositionForm.ptCurrentPos.y = Position.Y + Size.Y;
  logDebug() << "ImmSetCompositionWindow at:"
             << "(" << CompositionForm.ptCurrentPos.x << ", " << CompositionForm.ptCurrentPos.y << ")";
  if (!IMM32Lib.Invoke<BOOL, HIMC, LPCOMPOSITIONFORM>("ImmSetCompositionWindow", IMMContext, &CompositionForm)) {
    logDebug() << "Failed to call ImmSetCompositionWindow";
  }
}
#endif
} // namespace Windows
} // namespace Common
