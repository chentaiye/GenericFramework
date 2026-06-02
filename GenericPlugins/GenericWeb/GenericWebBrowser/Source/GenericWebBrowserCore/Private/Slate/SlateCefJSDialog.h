//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma once

#pragma region <Engine Headers>
// Core/Public/
#include <Math/Color.h>
#include <CoreFwd.h>
#include <Delegates/DelegateCombinations.h>
// Slate/Public/
#include <Widgets/Layout/SBorder.h>
// SlateCore/Public/
#include <Widgets/DeclarativeSyntaxSupport.h>
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
#pragma endregion

#pragma once

/** 用 Slate 实现 CEF JavaScript alert、confirm 和 prompt 对话框。 */
class SlateCefJSDialog : public SBorder
{
public:
  enum EDialogType
  {
    /** 仅展示消息并等待确认。 */
    AlertDialog = 0,

    /** 展示确认和取消按钮。 */
    ConfirmDialog = 1,

    /** 展示文本输入并等待用户提交。 */
    PromptDialog = 2
  };

  DECLARE_DELEGATE_TwoParams(FOnContinueDelegate, bool, const FString&);

  SLATE_BEGIN_ARGS(SlateCefJSDialog)
    : _Type(AlertDialog)
    , _Title(FString())
    , _Message(FString())
    , _Prompt(FString())
    , _MaskColor(FLinearColor(0.f, 0.0f, 0.0f, 0.5f))
  {
  }
  SLATE_ARGUMENT(EDialogType, Type)
  SLATE_ARGUMENT(FString, Title)
  SLATE_ARGUMENT(FString, Message)
  SLATE_ARGUMENT(FString, Prompt)
  SLATE_ARGUMENT(FLinearColor, MaskColor)
  SLATE_EVENT(FOnContinueDelegate, OnContinue)
  SLATE_END_ARGS()

  /** 根据对话框类型构建对应的 Slate 内容。 */
  void Construct(const FArguments& InArgs);

  /** 返回用于把用户选择结果传回 CEF 的委托。 */
  SlateCefJSDialog::FOnContinueDelegate& GetOnContinueDelegate();

protected:
  /** 创建 alert 对话框内容。 */
  TSharedRef<SWidget> CreateAlert();

  /** 创建 confirm 对话框内容。 */
  TSharedRef<SWidget> CreateConfirm();

  /** 创建 prompt 对话框内容。 */
  TSharedRef<SWidget> CreatePrompt();

  /** 响应OkButtonClicked回调，并把外部事件转换为当前对象状态或委托通知。 */
  FReply OnOkButtonClicked();

  /** 执行取消ButtonClicked，并同步当前模块的状态缓存与回调。 */
  FReply OnCancelButtonClicked();

  /** 同步 prompt 输入框文本。 */
  void OnPromptTextChanged(const FText& NewText);

protected:
  bool SupportsKeyboardFocus() const override;
  FReply OnPreviewKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

private:
  /** 当前对话框类型。 */
  EDialogType Type = EDialogType::AlertDialog;

  /** 对话框标题。 */
  FString Title;

  /** 对话框消息正文。 */
  FString Message;

  /** prompt 对话框当前输入内容。 */
  FString Prompt;

  /** 覆盖浏览器内容的遮罩颜色。 */
  FLinearColor MaskColor;

  FOnContinueDelegate OnContinueDelegate;
};
