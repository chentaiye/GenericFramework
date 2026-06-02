//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "MenuUtils.h"
#pragma endregion

#pragma region <Engine Headers>
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
#include "Common/Convert.h"
#include "Common/Log.h"
#pragma endregion

using namespace Common;

namespace MenuUtils {
void
BuildMenuFromModel(FMenuBuilder& builder, CefMenuModel* model, const MenuExecuteHandler& handler)
{
  if (!model)
    return;

  for (int i = 0; i < model->GetCount(); i++) {
    FUIAction action;

    /** 菜单项被点击时只回传 CEF command id，具体处理由调用方持有的 CEF 回调完成。 */
    auto commandId = model->GetCommandIdAt(i);
    action.ExecuteAction.BindLambda( //
      [handler, commandId]() {
        //
        handler.ExecuteIfBound(commandId);
      });

    /** Slate 菜单需要在构建时绑定可执行状态，状态来源保持与 CEF 模型一致。 */
    auto enable = model->IsEnabledAt(i);
    action.CanExecuteAction.BindLambda( //
      [enable]() {
        //
        return enable;
      });

    /** CEF 可见性会影响 Slate 菜单项是否参与本次菜单展示。 */
    auto visible = model->IsVisibleAt(i);
    action.IsActionVisibleDelegate.BindLambda( //
      [visible]() {                            //
        return visible;
      });

    // int keyCode = 0;
    // bool shift = false;
    // bool ctrl = false;
    // bool alt = false;
    // if (model->GetAcceleratorAt(i, keyCode, shift, ctrl, alt)) {
    // }

    auto label = Convert::StringC2F(model->GetLabelAt(i));
    auto type = model->GetTypeAt(i);
    switch (type) {
      case MENUITEMTYPE_COMMAND: {
        builder.AddMenuEntry(FText::FromString(label), FText(), FSlateIcon(), action);
      } break;
      case MENUITEMTYPE_CHECK: {
        auto checked = model->IsCheckedAt(i);
        action.GetActionCheckState.BindLambda( //
          [checked]() { return checked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; });
        builder.AddMenuEntry(
          FText::FromString(label), FText(), FSlateIcon(), action, NAME_None, EUserInterfaceActionType::ToggleButton);
      } break;
      case MENUITEMTYPE_RADIO: {
        auto checked = model->IsCheckedAt(i);
        auto groupId = model->GetGroupIdAt(i);
        action.GetActionCheckState.BindLambda( //
          [checked]() { return checked ? ECheckBoxState::Checked : ECheckBoxState::Unchecked; });
        builder.AddMenuEntry(
          FText::FromString(label), FText(), FSlateIcon(), action, NAME_None, EUserInterfaceActionType::RadioButton);
      } break;
      case MENUITEMTYPE_SEPARATOR: {
        builder.AddSeparator();
      } break;
      case MENUITEMTYPE_SUBMENU: {
        auto cefSubMenu = model->GetSubMenuAt(i);
        FMenuBuilder subBuilder(true, nullptr);
        BuildMenuFromModel(subBuilder, cefSubMenu.get(), handler);
        builder.AddWrapperSubMenu(FText::FromString(label),
                                  FText(),
                                  FOnGetContent::CreateLambda([subBuilder]() {
                                    FMenuBuilder builder(subBuilder);
                                    return builder.MakeWidget();
                                  }),
                                  FSlateIcon());
      } break;
      default:
        break;
    }
  }
}

} // namespace MenuUtils
