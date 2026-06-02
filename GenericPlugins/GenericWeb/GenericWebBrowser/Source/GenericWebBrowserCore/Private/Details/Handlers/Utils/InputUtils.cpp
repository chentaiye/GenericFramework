//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "InputUtils.h"
#pragma endregion

#pragma region <Engine Headers>
// InputCore/Classes/
#include <InputCoreTypes.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#pragma endregion

#if PLATFORM_LINUX

// From ui/events/keycodes/keyboard_codes_posix.h.
enum KeyboardCode
{
  VKEY_BACK = 0x08,
  VKEY_TAB = 0x09,
  VKEY_BACKTAB = 0x0A,
  VKEY_CLEAR = 0x0C,
  VKEY_RETURN = 0x0D,
  VKEY_SHIFT = 0x10,
  VKEY_CONTROL = 0x11,
  VKEY_MENU = 0x12,
  VKEY_PAUSE = 0x13,
  VKEY_CAPITAL = 0x14,
  VKEY_KANA = 0x15,
  VKEY_HANGUL = 0x15,
  VKEY_JUNJA = 0x17,
  VKEY_FINAL = 0x18,
  VKEY_HANJA = 0x19,
  VKEY_KANJI = 0x19,
  VKEY_ESCAPE = 0x1B,
  VKEY_CONVERT = 0x1C,
  VKEY_NONCONVERT = 0x1D,
  VKEY_ACCEPT = 0x1E,
  VKEY_MODECHANGE = 0x1F,
  VKEY_SPACE = 0x20,
  VKEY_PRIOR = 0x21,
  VKEY_NEXT = 0x22,
  VKEY_END = 0x23,
  VKEY_HOME = 0x24,
  VKEY_LEFT = 0x25,
  VKEY_UP = 0x26,
  VKEY_RIGHT = 0x27,
  VKEY_DOWN = 0x28,
  VKEY_SELECT = 0x29,
  VKEY_PRINT = 0x2A,
  VKEY_EXECUTE = 0x2B,
  VKEY_SNAPSHOT = 0x2C,
  VKEY_INSERT = 0x2D,
  VKEY_DELETE = 0x2E,
  VKEY_HELP = 0x2F,
  VKEY_0 = 0x30,
  VKEY_1 = 0x31,
  VKEY_2 = 0x32,
  VKEY_3 = 0x33,
  VKEY_4 = 0x34,
  VKEY_5 = 0x35,
  VKEY_6 = 0x36,
  VKEY_7 = 0x37,
  VKEY_8 = 0x38,
  VKEY_9 = 0x39,
  VKEY_A = 0x41,
  VKEY_B = 0x42,
  VKEY_C = 0x43,
  VKEY_D = 0x44,
  VKEY_E = 0x45,
  VKEY_F = 0x46,
  VKEY_G = 0x47,
  VKEY_H = 0x48,
  VKEY_I = 0x49,
  VKEY_J = 0x4A,
  VKEY_K = 0x4B,
  VKEY_L = 0x4C,
  VKEY_M = 0x4D,
  VKEY_N = 0x4E,
  VKEY_O = 0x4F,
  VKEY_P = 0x50,
  VKEY_Q = 0x51,
  VKEY_R = 0x52,
  VKEY_S = 0x53,
  VKEY_T = 0x54,
  VKEY_U = 0x55,
  VKEY_V = 0x56,
  VKEY_W = 0x57,
  VKEY_X = 0x58,
  VKEY_Y = 0x59,
  VKEY_Z = 0x5A,
  VKEY_LWIN = 0x5B,
  VKEY_COMMAND = VKEY_LWIN, // Provide the Mac name for convenience.
  VKEY_RWIN = 0x5C,
  VKEY_APPS = 0x5D,
  VKEY_SLEEP = 0x5F,
  VKEY_NUMPAD0 = 0x60,
  VKEY_NUMPAD1 = 0x61,
  VKEY_NUMPAD2 = 0x62,
  VKEY_NUMPAD3 = 0x63,
  VKEY_NUMPAD4 = 0x64,
  VKEY_NUMPAD5 = 0x65,
  VKEY_NUMPAD6 = 0x66,
  VKEY_NUMPAD7 = 0x67,
  VKEY_NUMPAD8 = 0x68,
  VKEY_NUMPAD9 = 0x69,
  VKEY_MULTIPLY = 0x6A,
  VKEY_ADD = 0x6B,
  VKEY_SEPARATOR = 0x6C,
  VKEY_SUBTRACT = 0x6D,
  VKEY_DECIMAL = 0x6E,
  VKEY_DIVIDE = 0x6F,
  VKEY_F1 = 0x70,
  VKEY_F2 = 0x71,
  VKEY_F3 = 0x72,
  VKEY_F4 = 0x73,
  VKEY_F5 = 0x74,
  VKEY_F6 = 0x75,
  VKEY_F7 = 0x76,
  VKEY_F8 = 0x77,
  VKEY_F9 = 0x78,
  VKEY_F10 = 0x79,
  VKEY_F11 = 0x7A,
  VKEY_F12 = 0x7B,
  VKEY_F13 = 0x7C,
  VKEY_F14 = 0x7D,
  VKEY_F15 = 0x7E,
  VKEY_F16 = 0x7F,
  VKEY_F17 = 0x80,
  VKEY_F18 = 0x81,
  VKEY_F19 = 0x82,
  VKEY_F20 = 0x83,
  VKEY_F21 = 0x84,
  VKEY_F22 = 0x85,
  VKEY_F23 = 0x86,
  VKEY_F24 = 0x87,
  VKEY_NUMLOCK = 0x90,
  VKEY_SCROLL = 0x91,
  VKEY_LSHIFT = 0xA0,
  VKEY_RSHIFT = 0xA1,
  VKEY_LCONTROL = 0xA2,
  VKEY_RCONTROL = 0xA3,
  VKEY_LMENU = 0xA4,
  VKEY_RMENU = 0xA5,
  VKEY_BROWSER_BACK = 0xA6,
  VKEY_BROWSER_FORWARD = 0xA7,
  VKEY_BROWSER_REFRESH = 0xA8,
  VKEY_BROWSER_STOP = 0xA9,
  VKEY_BROWSER_SEARCH = 0xAA,
  VKEY_BROWSER_FAVORITES = 0xAB,
  VKEY_BROWSER_HOME = 0xAC,
  VKEY_VOLUME_MUTE = 0xAD,
  VKEY_VOLUME_DOWN = 0xAE,
  VKEY_VOLUME_UP = 0xAF,
  VKEY_MEDIA_NEXT_TRACK = 0xB0,
  VKEY_MEDIA_PREV_TRACK = 0xB1,
  VKEY_MEDIA_STOP = 0xB2,
  VKEY_MEDIA_PLAY_PAUSE = 0xB3,
  VKEY_MEDIA_LAUNCH_MAIL = 0xB4,
  VKEY_MEDIA_LAUNCH_MEDIA_SELECT = 0xB5,
  VKEY_MEDIA_LAUNCH_APP1 = 0xB6,
  VKEY_MEDIA_LAUNCH_APP2 = 0xB7,
  VKEY_OEM_1 = 0xBA,
  VKEY_OEM_PLUS = 0xBB,
  VKEY_OEM_COMMA = 0xBC,
  VKEY_OEM_MINUS = 0xBD,
  VKEY_OEM_PERIOD = 0xBE,
  VKEY_OEM_2 = 0xBF,
  VKEY_OEM_3 = 0xC0,
  VKEY_OEM_4 = 0xDB,
  VKEY_OEM_5 = 0xDC,
  VKEY_OEM_6 = 0xDD,
  VKEY_OEM_7 = 0xDE,
  VKEY_OEM_8 = 0xDF,
  VKEY_OEM_102 = 0xE2,
  VKEY_OEM_103 = 0xE3, // GTV KEYCODE_MEDIA_REWIND
  VKEY_OEM_104 = 0xE4, // GTV KEYCODE_MEDIA_FAST_FORWARD
  VKEY_PROCESSKEY = 0xE5,
  VKEY_PACKET = 0xE7,
  VKEY_DBE_SBCSCHAR = 0xF3,
  VKEY_DBE_DBCSCHAR = 0xF4,
  VKEY_ATTN = 0xF6,
  VKEY_CRSEL = 0xF7,
  VKEY_EXSEL = 0xF8,
  VKEY_EREOF = 0xF9,
  VKEY_PLAY = 0xFA,
  VKEY_ZOOM = 0xFB,
  VKEY_NONAME = 0xFC,
  VKEY_PA1 = 0xFD,
  VKEY_OEM_CLEAR = 0xFE,
  VKEY_UNKNOWN = 0,

  // POSIX specific VKEYs. Note that as of Windows SDK 7.1, 0x97-9F, 0xD8-DA,
  // and 0xE8 are unassigned.
  VKEY_WLAN = 0x97,
  VKEY_POWER = 0x98,
  VKEY_BRIGHTNESS_DOWN = 0xD8,
  VKEY_BRIGHTNESS_UP = 0xD9,
  VKEY_KBD_BRIGHTNESS_DOWN = 0xDA,
  VKEY_KBD_BRIGHTNESS_UP = 0xE8,

  // Windows does not have a specific key code for AltGr. We use the unused 0xE1
  // (VK_OEM_AX) code to represent AltGr, matching the behaviour of Firefox on
  // Linux.
  VKEY_ALTGR = 0xE1,
  // Windows does not have a specific key code for Compose. We use the unused
  // 0xE6 (VK_ICO_CLEAR) code to represent Compose.
  VKEY_COMPOSE = 0xE6,
};

#endif

int32
GetCefInputModifiers(const FInputEvent& InputEvent)
{
  int32 Modifiers = 0;

  if (InputEvent.IsShiftDown()) {
    Modifiers |= EVENTFLAG_SHIFT_DOWN;
  }
  if (InputEvent.IsControlDown()) {
#if PLATFORM_MAC
    // Slate swaps the flags for Command and Control on OSX, so we need to swap them back for CEF
    Modifiers |= EVENTFLAG_COMMAND_DOWN;
#else
    Modifiers |= EVENTFLAG_CONTROL_DOWN;
#endif
  }
  if (InputEvent.IsAltDown()) {
    Modifiers |= EVENTFLAG_ALT_DOWN;
  }
  if (InputEvent.IsCommandDown()) {
#if PLATFORM_MAC
    // Slate swaps the flags for Command and Control on OSX, so we need to swap them back for CEF
    Modifiers |= EVENTFLAG_CONTROL_DOWN;
#else
    Modifiers |= EVENTFLAG_COMMAND_DOWN;
#endif
  }
  if (InputEvent.AreCapsLocked()) {
    Modifiers |= EVENTFLAG_CAPS_LOCK_ON;
  }

#if defined(PLATFORM_WINDOWS) && PLATFORM_WINDOWS
  if (InputEvent.IsAltDown() && InputEvent.IsLeftControlDown()) {
    // For german and other keyboards with an AltGR state, windows sets alt and left control down
    // as well as VK_RMENU. So check for that state here and set the ALTGR flag if needed.
    // See https://bitbucket.org/chromiumembedded/cef/commits/30d83cb94a79#chg-tests/cefclient/browser/osr_window_win.cc
    // from which the concept behind this check was taken
    SHORT keystate = ::GetKeyState(VK_RMENU);
    if ((keystate & 0x8000) != 0) {
      Modifiers &= ~(EVENTFLAG_CONTROL_DOWN | EVENTFLAG_ALT_DOWN);
      Modifiers |= EVENTFLAG_ALTGR_DOWN;
    }
  }
#endif

  return Modifiers;
}

int32
GetCefMouseModifiers(const FPointerEvent& InMouseEvent)
{
  int32 Modifiers = GetCefInputModifiers(InMouseEvent);

  if (InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton)) {
    Modifiers |= EVENTFLAG_LEFT_MOUSE_BUTTON;
  }
  if (InMouseEvent.IsMouseButtonDown(EKeys::MiddleMouseButton)) {
    Modifiers |= EVENTFLAG_MIDDLE_MOUSE_BUTTON;
  }
  if (InMouseEvent.IsMouseButtonDown(EKeys::RightMouseButton)) {
    Modifiers |= EVENTFLAG_RIGHT_MOUSE_BUTTON;
  }

  return Modifiers;
}

CefBrowserHost::MouseButtonType
GetCefMouseButton(const FPointerEvent& InMouseEvent)
{
  CefBrowserHost::MouseButtonType mbt = MBT_LEFT;
  if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton) {
    mbt = MBT_LEFT;
  } else if (InMouseEvent.GetEffectingButton() == EKeys::RightMouseButton) {
    mbt = MBT_RIGHT;
  } else if (InMouseEvent.GetEffectingButton() == EKeys::MiddleMouseButton) {
    mbt = MBT_MIDDLE;
  }
  return mbt;
}

int32
GetCefKeyboardModifiers(const FKeyEvent& KeyEvent)
{
  int32 Modifiers = GetCefInputModifiers(KeyEvent);

  const FKey Key = KeyEvent.GetKey();
  if (Key == EKeys::LeftAlt || Key == EKeys::LeftCommand || Key == EKeys::LeftControl || Key == EKeys::LeftShift) {
    Modifiers |= EVENTFLAG_IS_LEFT;
  }
  if (Key == EKeys::RightAlt || Key == EKeys::RightCommand || Key == EKeys::RightControl || Key == EKeys::RightShift) {
    Modifiers |= EVENTFLAG_IS_RIGHT;
  }
  if (Key == EKeys::NumPadZero || Key == EKeys::NumPadOne || Key == EKeys::NumPadTwo || Key == EKeys::NumPadThree ||
      Key == EKeys::NumPadFour || Key == EKeys::NumPadFive || Key == EKeys::NumPadSix || Key == EKeys::NumPadSeven ||
      Key == EKeys::NumPadEight || Key == EKeys::NumPadNine) {
    Modifiers |= EVENTFLAG_IS_KEY_PAD;
  }

  return Modifiers;
}

void
MapFKeyEventToCefKeyEvent(const FKeyEvent& InKeyEvent, CefKeyEvent& OutKeyEvent)
{
#if PLATFORM_MAC
  OutKeyEvent.native_key_code = InKeyEvent.GetKeyCode();

  FKey Key = InKeyEvent.GetKey();
  if (Key == EKeys::BackSpace) {
    OutKeyEvent.unmodified_character = kBackspaceCharCode;
  } else if (Key == EKeys::Tab) {
    OutKeyEvent.unmodified_character = kTabCharCode;
  } else if (Key == EKeys::Enter) {
    OutKeyEvent.unmodified_character = kReturnCharCode;
  } else if (Key == EKeys::Pause) {
    OutKeyEvent.unmodified_character = NSPauseFunctionKey;
  } else if (Key == EKeys::Escape) {
    OutKeyEvent.unmodified_character = kEscapeCharCode;
  } else if (Key == EKeys::PageUp) {
    OutKeyEvent.unmodified_character = NSPageUpFunctionKey;
  } else if (Key == EKeys::PageDown) {
    OutKeyEvent.unmodified_character = NSPageDownFunctionKey;
  } else if (Key == EKeys::End) {
    OutKeyEvent.unmodified_character = NSEndFunctionKey;
  } else if (Key == EKeys::Home) {
    OutKeyEvent.unmodified_character = NSHomeFunctionKey;
  } else if (Key == EKeys::Left) {
    OutKeyEvent.unmodified_character = NSLeftArrowFunctionKey;
  } else if (Key == EKeys::Up) {
    OutKeyEvent.unmodified_character = NSUpArrowFunctionKey;
  } else if (Key == EKeys::Right) {
    OutKeyEvent.unmodified_character = NSRightArrowFunctionKey;
  } else if (Key == EKeys::Down) {
    OutKeyEvent.unmodified_character = NSDownArrowFunctionKey;
  } else if (Key == EKeys::Insert) {
    OutKeyEvent.unmodified_character = NSInsertFunctionKey;
  } else if (Key == EKeys::Delete) {
    OutKeyEvent.unmodified_character = kDeleteCharCode;
  } else if (Key == EKeys::F1) {
    OutKeyEvent.unmodified_character = NSF1FunctionKey;
  } else if (Key == EKeys::F2) {
    OutKeyEvent.unmodified_character = NSF2FunctionKey;
  } else if (Key == EKeys::F3) {
    OutKeyEvent.unmodified_character = NSF3FunctionKey;
  } else if (Key == EKeys::F4) {
    OutKeyEvent.unmodified_character = NSF4FunctionKey;
  } else if (Key == EKeys::F5) {
    OutKeyEvent.unmodified_character = NSF5FunctionKey;
  } else if (Key == EKeys::F6) {
    OutKeyEvent.unmodified_character = NSF6FunctionKey;
  } else if (Key == EKeys::F7) {
    OutKeyEvent.unmodified_character = NSF7FunctionKey;
  } else if (Key == EKeys::F8) {
    OutKeyEvent.unmodified_character = NSF8FunctionKey;
  } else if (Key == EKeys::F9) {
    OutKeyEvent.unmodified_character = NSF9FunctionKey;
  } else if (Key == EKeys::F10) {
    OutKeyEvent.unmodified_character = NSF10FunctionKey;
  } else if (Key == EKeys::F11) {
    OutKeyEvent.unmodified_character = NSF11FunctionKey;
  } else if (Key == EKeys::F12) {
    OutKeyEvent.unmodified_character = NSF12FunctionKey;
  } else if (Key == EKeys::CapsLock) {
    OutKeyEvent.unmodified_character = 0;
    OutKeyEvent.native_key_code = kVK_CapsLock;
  } else if (Key.IsModifierKey()) {
    // Setting both unmodified_character and character to 0 tells CEF that it needs to generate a NSFlagsChanged event
    // instead of NSKeyDown/Up
    OutKeyEvent.unmodified_character = 0;

    // CEF expects modifier key codes as one of the Carbon kVK_* key codes.
    if (Key == EKeys::LeftCommand) {
      OutKeyEvent.native_key_code = kVK_Command;
    } else if (Key == EKeys::LeftShift) {
      OutKeyEvent.native_key_code = kVK_Shift;
    } else if (Key == EKeys::LeftAlt) {
      OutKeyEvent.native_key_code = kVK_Option;
    } else if (Key == EKeys::LeftControl) {
      OutKeyEvent.native_key_code = kVK_Control;
    } else if (Key == EKeys::RightCommand) {
      // There isn't a separate code for the right hand command key defined, but CEF seems to use the unused value
      // before the left command keycode
      OutKeyEvent.native_key_code = kVK_Command - 1;
    } else if (Key == EKeys::RightShift) {
      OutKeyEvent.native_key_code = kVK_RightShift;
    } else if (Key == EKeys::RightAlt) {
      OutKeyEvent.native_key_code = kVK_RightOption;
    } else if (Key == EKeys::RightControl) {
      OutKeyEvent.native_key_code = kVK_RightControl;
    }
  } else {
    OutKeyEvent.unmodified_character = InKeyEvent.GetCharacter();
  }
  OutKeyEvent.character = OutKeyEvent.unmodified_character;

#elif PLATFORM_LINUX
  OutKeyEvent.native_key_code = InKeyEvent.GetKeyCode();
  FKey Key = InKeyEvent.GetKey();
  // helper macro so we can fill in all the A-Z, 0-9 keys
#define LETTER_KEY_MACRO(val, vkey)                                                                                    \
  else if (Key == EKeys::val)                                                                                          \
  {                                                                                                                    \
    OutKeyEvent.unmodified_character = InKeyEvent.GetCharacter();                                                      \
    OutKeyEvent.windows_key_code = vkey;                                                                               \
  }

  if (Key == EKeys::BackSpace) {
    OutKeyEvent.windows_key_code = VKEY_BACK;
  } else if (Key == EKeys::Tab) {
    OutKeyEvent.windows_key_code = VKEY_TAB;
  } else if (Key == EKeys::Enter) {
    OutKeyEvent.windows_key_code = VKEY_RETURN;
  } else if (Key == EKeys::Pause) {
    OutKeyEvent.windows_key_code = VKEY_PAUSE;
  } else if (Key == EKeys::Escape) {
    OutKeyEvent.windows_key_code = VKEY_ESCAPE;
  } else if (Key == EKeys::PageUp) {
    OutKeyEvent.windows_key_code = VKEY_PRIOR;
  } else if (Key == EKeys::PageDown) {
    OutKeyEvent.windows_key_code = VKEY_NEXT;
  } else if (Key == EKeys::End) {
    OutKeyEvent.windows_key_code = VKEY_END;
  } else if (Key == EKeys::Home) {
    OutKeyEvent.windows_key_code = VKEY_HOME;
  } else if (Key == EKeys::Left) {
    OutKeyEvent.windows_key_code = VKEY_LEFT;
  } else if (Key == EKeys::Up) {
    OutKeyEvent.windows_key_code = VKEY_UP;
  } else if (Key == EKeys::Right) {
    OutKeyEvent.windows_key_code = VKEY_RIGHT;
  } else if (Key == EKeys::Down) {
    OutKeyEvent.windows_key_code = VKEY_DOWN;
  } else if (Key == EKeys::Insert) {
    OutKeyEvent.windows_key_code = VKEY_INSERT;
  } else if (Key == EKeys::Delete) {
    OutKeyEvent.windows_key_code = VKEY_DELETE;
  } else if (Key == EKeys::F1) {
    OutKeyEvent.windows_key_code = VKEY_F1;
  } else if (Key == EKeys::F2) {
    OutKeyEvent.windows_key_code = VKEY_F2;
  } else if (Key == EKeys::F3) {
    OutKeyEvent.windows_key_code = VKEY_F3;
  } else if (Key == EKeys::F4) {
    OutKeyEvent.windows_key_code = VKEY_F4;
  } else if (Key == EKeys::F5) {
    OutKeyEvent.windows_key_code = VKEY_F5;
  } else if (Key == EKeys::F6) {
    OutKeyEvent.windows_key_code = VKEY_F6;
  } else if (Key == EKeys::F7) {
    OutKeyEvent.windows_key_code = VKEY_F7;
  } else if (Key == EKeys::F8) {
    OutKeyEvent.windows_key_code = VKEY_F8;
  } else if (Key == EKeys::F9) {
    OutKeyEvent.windows_key_code = VKEY_F9;
  } else if (Key == EKeys::F10) {
    OutKeyEvent.windows_key_code = VKEY_F10;
  } else if (Key == EKeys::F11) {
    OutKeyEvent.windows_key_code = VKEY_F11;
  } else if (Key == EKeys::F12) {
    OutKeyEvent.windows_key_code = VKEY_F12;
  } else if (Key == EKeys::CapsLock) {
    OutKeyEvent.windows_key_code = VKEY_CAPITAL;
  } else if (Key == EKeys::LeftCommand) {
    OutKeyEvent.windows_key_code = VKEY_MENU;
  } else if (Key == EKeys::LeftShift) {
    OutKeyEvent.windows_key_code = VKEY_SHIFT;
  } else if (Key == EKeys::LeftAlt) {
    OutKeyEvent.windows_key_code = VKEY_MENU;
  } else if (Key == EKeys::LeftControl) {
    OutKeyEvent.windows_key_code = VKEY_CONTROL;
  } else if (Key == EKeys::RightCommand) {
    OutKeyEvent.windows_key_code = VKEY_MENU;
  } else if (Key == EKeys::RightShift) {
    OutKeyEvent.windows_key_code = VKEY_SHIFT;
  } else if (Key == EKeys::RightAlt) {
    OutKeyEvent.windows_key_code = VKEY_MENU;
  } else if (Key == EKeys::RightControl) {
    OutKeyEvent.windows_key_code = VKEY_CONTROL;
  } else if (Key == EKeys::NumPadOne) {
    OutKeyEvent.windows_key_code = VKEY_NUMPAD1;
  } else if (Key == EKeys::NumPadTwo) {
    OutKeyEvent.windows_key_code = VKEY_NUMPAD2;
  } else if (Key == EKeys::NumPadThree) {
    OutKeyEvent.windows_key_code = VKEY_NUMPAD3;
  } else if (Key == EKeys::NumPadFour) {
    OutKeyEvent.windows_key_code = VKEY_NUMPAD4;
  } else if (Key == EKeys::NumPadFive) {
    OutKeyEvent.windows_key_code = VKEY_NUMPAD5;
  } else if (Key == EKeys::NumPadSix) {
    OutKeyEvent.windows_key_code = VKEY_NUMPAD6;
  } else if (Key == EKeys::NumPadSeven) {
    OutKeyEvent.windows_key_code = VKEY_NUMPAD7;
  } else if (Key == EKeys::NumPadEight) {
    OutKeyEvent.windows_key_code = VKEY_NUMPAD8;
  } else if (Key == EKeys::NumPadNine) {
    OutKeyEvent.windows_key_code = VKEY_NUMPAD9;
  } else if (Key == EKeys::NumPadZero) {
    OutKeyEvent.windows_key_code = VKEY_NUMPAD0;
  }
  LETTER_KEY_MACRO(A, VKEY_A)
  LETTER_KEY_MACRO(B, VKEY_B)
  LETTER_KEY_MACRO(C, VKEY_C)
  LETTER_KEY_MACRO(D, VKEY_D)
  LETTER_KEY_MACRO(E, VKEY_E)
  LETTER_KEY_MACRO(F, VKEY_F)
  LETTER_KEY_MACRO(G, VKEY_G)
  LETTER_KEY_MACRO(H, VKEY_H)
  LETTER_KEY_MACRO(I, VKEY_I)
  LETTER_KEY_MACRO(J, VKEY_J)
  LETTER_KEY_MACRO(K, VKEY_K)
  LETTER_KEY_MACRO(L, VKEY_L)
  LETTER_KEY_MACRO(M, VKEY_M)
  LETTER_KEY_MACRO(N, VKEY_N)
  LETTER_KEY_MACRO(O, VKEY_O)
  LETTER_KEY_MACRO(P, VKEY_P)
  LETTER_KEY_MACRO(Q, VKEY_Q)
  LETTER_KEY_MACRO(R, VKEY_R)
  LETTER_KEY_MACRO(S, VKEY_S)
  LETTER_KEY_MACRO(T, VKEY_T)
  LETTER_KEY_MACRO(U, VKEY_U)
  LETTER_KEY_MACRO(V, VKEY_V)
  LETTER_KEY_MACRO(W, VKEY_W)
  LETTER_KEY_MACRO(X, VKEY_X)
  LETTER_KEY_MACRO(Y, VKEY_Y)
  LETTER_KEY_MACRO(Z, VKEY_Z)
  LETTER_KEY_MACRO(Zero, VKEY_0)
  LETTER_KEY_MACRO(One, VKEY_1)
  LETTER_KEY_MACRO(Two, VKEY_2)
  LETTER_KEY_MACRO(Three, VKEY_3)
  LETTER_KEY_MACRO(Four, VKEY_4)
  LETTER_KEY_MACRO(Five, VKEY_5)
  LETTER_KEY_MACRO(Six, VKEY_6)
  LETTER_KEY_MACRO(Seven, VKEY_7)
  LETTER_KEY_MACRO(Eight, VKEY_8)
  LETTER_KEY_MACRO(Nine, VKEY_9)
  else
  {
    OutKeyEvent.unmodified_character = InKeyEvent.GetCharacter();
    OutKeyEvent.windows_key_code = VKEY_UNKNOWN;
  }
#else
  OutKeyEvent.windows_key_code = InKeyEvent.GetKeyCode();
#endif

  OutKeyEvent.modifiers = GetCefKeyboardModifiers(InKeyEvent);
}

EMouseCursor::Type
MapCefCursorTypeToEMouseCursorType(const cef_cursor_type_t& t)
{
  static EMouseCursor::Type sCursorTable[] = {
    EMouseCursor::Type::Default,         // CT_POINTER = 0,
    EMouseCursor::Type::Crosshairs,      // CT_CROSS,
    EMouseCursor::Type::Hand,            // CT_HAND,
    EMouseCursor::Type::TextEditBeam,    // CT_IBEAM,
    EMouseCursor::Type::Default,         // CT_WAIT,
    EMouseCursor::Type::Default,         // CT_HELP,
    EMouseCursor::Type::ResizeLeftRight, // CT_EASTRESIZE,
    EMouseCursor::Type::ResizeUpDown,    // CT_NORTHRESIZE,
    EMouseCursor::Type::ResizeSouthWest, // CT_NORTHEASTRESIZE,
    EMouseCursor::Type::ResizeSouthEast, // CT_NORTHWESTRESIZE,
    EMouseCursor::Type::ResizeUpDown,    // CT_SOUTHRESIZE,
    EMouseCursor::Type::ResizeSouthEast, // CT_SOUTHEASTRESIZE,
    EMouseCursor::Type::ResizeSouthWest, // CT_SOUTHWESTRESIZE,
    EMouseCursor::Type::ResizeLeftRight, // CT_WESTRESIZE,
    EMouseCursor::Type::ResizeUpDown,    // CT_NORTHSOUTHRESIZE,
    EMouseCursor::Type::ResizeLeftRight, // CT_EASTWESTRESIZE,
    EMouseCursor::Type::ResizeSouthWest, // CT_NORTHEASTSOUTHWESTRESIZE,
    EMouseCursor::Type::ResizeSouthEast, // CT_NORTHWESTSOUTHEASTRESIZE,
    EMouseCursor::Type::ResizeLeftRight, // CT_COLUMNRESIZE,
    EMouseCursor::Type::ResizeUpDown,    // CT_ROWRESIZE,
    EMouseCursor::Type::CardinalCross,   // CT_MIDDLEPANNING,
    EMouseCursor::Type::CardinalCross,   // CT_EASTPANNING,
    EMouseCursor::Type::CardinalCross,   // CT_NORTHPANNING,
    EMouseCursor::Type::CardinalCross,   // CT_NORTHEASTPANNING,
    EMouseCursor::Type::CardinalCross,   // CT_NORTHWESTPANNING,
    EMouseCursor::Type::CardinalCross,   // CT_SOUTHPANNING,
    EMouseCursor::Type::CardinalCross,   // CT_SOUTHEASTPANNING,
    EMouseCursor::Type::CardinalCross,   // CT_SOUTHWESTPANNING,
    EMouseCursor::Type::CardinalCross,   // CT_WESTPANNING,
    EMouseCursor::Type::CardinalCross,   // CT_MOVE,
    EMouseCursor::Type::TextEditBeam,    // CT_VERTICALTEXT,
    EMouseCursor::Type::Default,         // CT_CELL,
    EMouseCursor::Type::Default,         // CT_CONTEXTMENU,
    EMouseCursor::Type::Default,         // CT_ALIAS,
    EMouseCursor::Type::Default,         // CT_PROGRESS,
    EMouseCursor::Type::SlashedCircle,   // CT_NODROP,
    EMouseCursor::Type::Default,         // CT_COPY,
    EMouseCursor::Type::None,            // CT_NONE,
    EMouseCursor::Type::SlashedCircle,   // CT_NOTALLOWED,
    EMouseCursor::Type::Default,         // CT_ZOOMIN,
    EMouseCursor::Type::Default,         // CT_ZOOMOUT,
    EMouseCursor::Type::GrabHand,        // CT_GRAB,
    EMouseCursor::Type::GrabHandClosed,  // CT_GRABBING,
    EMouseCursor::Type::Default,         // CT_MIDDLE_PANNING_VERTICAL,
    EMouseCursor::Type::Default,         // CT_MIDDLE_PANNING_HORIZONTAL,
    EMouseCursor::Type::Custom,          // CT_CUSTOM,
    EMouseCursor::Type::Default,         // CT_DND_NONE,
    EMouseCursor::Type::Default,         // CT_DND_MOVE,
    EMouseCursor::Type::Default,         // CT_DND_COPY,
    EMouseCursor::Type::Default,         // CT_DND_LINK,
  };
  return sCursorTable[t];
}
