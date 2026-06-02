//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// ApplicationCore/Public/
#include <GenericPlatform/ICursor.h>
// SlateCore/Public/
#include <Input/Events.h>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#include <string>
#include <list>
#include <vector>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private Headers"
#include "HeadersCefViewCore.h"
#pragma endregion

int32
GetCefInputModifiers(const FInputEvent& InputEvent);

int32
GetCefMouseModifiers(const FPointerEvent& InMouseEvent);

CefBrowserHost::MouseButtonType
GetCefMouseButton(const FPointerEvent& InMouseEvent);

int32
GetCefKeyboardModifiers(const FKeyEvent& KeyEvent);

void
MapFKeyEventToCefKeyEvent(const FKeyEvent& InKeyEvent, CefKeyEvent& OutKeyEvent);

EMouseCursor::Type
MapCefCursorTypeToEMouseCursorType(const cef_cursor_type_t& t);
