//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Delegates/DelegateCombinations.h>
#include <Templates/SharedPointer.h>
// Slate/Public/
#include <Framework/MultiBox/MultiBoxBuilder.h>
// SlateCore/Public/
#include <Widgets/SWidget.h>
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
#include "HeadersCefViewCore.h"
#pragma endregion

DECLARE_DELEGATE_OneParam(MenuExecuteHandler, int);

namespace MenuUtils {
/** 将 CEF 菜单模型转换为 Slate 菜单项，并把命令执行回传给 CEF 回调。 */
void
BuildMenuFromModel(FMenuBuilder& builder, CefMenuModel* model, const MenuExecuteHandler& handler);
}; // namespace MenuUtils
