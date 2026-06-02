// Copyright ChenTaiye 2026. All Rights Reserved.

#include "UI/SAuthorizationActivationDialog.h"

#include "HAL/PlatformApplicationMisc.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SMultiLineEditableTextBox.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SWindow.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "AuthorizationActivationDialog"

void SAuthorizationActivationDialog::Construct(const FArguments& InArgs)
{
	OnGetAuthorizationRequestCode = InArgs._OnGetAuthorizationRequestCode;
	OnSubmitLicenseCode = InArgs._OnSubmitLicenseCode;

	if (OnGetAuthorizationRequestCode.IsBound())
	{
		AuthorizationRequestCode = OnGetAuthorizationRequestCode.Execute();
	}

	ChildSlot
	[
		SNew(SBorder)
		.Padding(18.0f)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(STextBlock)
				.Text(LOCTEXT("DialogTitle", "需要完成授权后才能继续"))
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 8.0f, 0.0f, 0.0f)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Text(LOCTEXT("DialogDescription", "请先复制申请码并发送给签发方。拿到授权码后，粘贴到下方并确认授权。"))
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 16.0f, 0.0f, 0.0f)
			[
				SNew(SButton)
				.Text(LOCTEXT("CopyRequestCodeButton", "复制申请码"))
				.OnClicked(this, &SAuthorizationActivationDialog::HandleCopyAuthorizationRequestCode)
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 8.0f, 0.0f, 0.0f)
			[
				SNew(SButton)
				.Text(LOCTEXT("PasteLicenseButton", "粘贴授权码"))
				.OnClicked(this, &SAuthorizationActivationDialog::HandlePasteLicense)
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 18.0f, 0.0f, 4.0f)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("LicenseTextLabel", "授权码"))
			]
			+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			[
				SAssignNew(LicenseInputTextBox, SMultiLineEditableTextBox)
				.HintText(LOCTEXT("LicenseInputHint", "请将签发工具生成的授权码粘贴到这里"))
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 12.0f, 0.0f, 0.0f)
			[
				SNew(STextBlock)
				.Text_Lambda([this]()
				{
					return StatusMessage;
				})
				.ColorAndOpacity_Lambda([this]()
				{
					return StatusColor;
				})
				.AutoWrapText(true)
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(0.0f, 16.0f, 0.0f, 0.0f)
			[
				SNew(SUniformGridPanel)
				.SlotPadding(FMargin(4.0f, 0.0f))
				+ SUniformGridPanel::Slot(0, 0)
				[
					SNew(SButton)
					.Text(LOCTEXT("ConfirmAuthorizationButton", "确认授权"))
					.OnClicked(this, &SAuthorizationActivationDialog::HandleConfirmAuthorization)
				]
				+ SUniformGridPanel::Slot(1, 0)
				[
					SNew(SButton)
					.Text(LOCTEXT("CancelAuthorizationButton", "退出程序"))
					.OnClicked(this, &SAuthorizationActivationDialog::HandleCancelAuthorization)
				]
			]
		]
	];
}

FReply SAuthorizationActivationDialog::HandleCopyAuthorizationRequestCode()
{
	if (AuthorizationRequestCode.IsEmpty())
	{
		SetStatusMessage(TEXT("申请码生成失败，请检查授权配置。"), true);
		return FReply::Handled();
	}

	FPlatformApplicationMisc::ClipboardCopy(*AuthorizationRequestCode);
	SetStatusMessage(TEXT("申请码已复制到剪贴板。"), false);
	return FReply::Handled();
}

FReply SAuthorizationActivationDialog::HandlePasteLicense()
{
	FString ClipboardText;
	FPlatformApplicationMisc::ClipboardPaste(ClipboardText);

	if (LicenseInputTextBox.IsValid())
	{
		LicenseInputTextBox->SetText(FText::FromString(ClipboardText));
	}

	SetStatusMessage(TEXT("已从剪贴板粘贴授权码。"), false);
	return FReply::Handled();
}

FReply SAuthorizationActivationDialog::HandleConfirmAuthorization()
{
	if (!OnSubmitLicenseCode.IsBound())
	{
		SetStatusMessage(TEXT("授权系统当前不可用。"), true);
		return FReply::Handled();
	}

	const FString LicenseText = LicenseInputTextBox.IsValid() ? LicenseInputTextBox->GetText().ToString() : FString();
	if (LicenseText.TrimStartAndEnd().IsEmpty())
	{
		SetStatusMessage(TEXT("授权码不能为空。"), true);
		return FReply::Handled();
	}

	FString Message;
	if (!OnSubmitLicenseCode.Execute(LicenseText, Message))
	{
		SetStatusMessage(Message, true);
		return FReply::Handled();
	}

	bWasAuthorized = true;
	SetStatusMessage(Message, false);
	CloseDialogWindow();
	return FReply::Handled();
}

FReply SAuthorizationActivationDialog::HandleCancelAuthorization()
{
	bWasAuthorized = false;
	CloseDialogWindow();
	return FReply::Handled();
}

void SAuthorizationActivationDialog::CloseDialogWindow()
{
	if (const TSharedPtr<SWindow> ResolvedWindow = OwnerWindow.Pin())
	{
		ResolvedWindow->RequestDestroyWindow();
	}
}

void SAuthorizationActivationDialog::SetStatusMessage(const FString& InMessage, const bool bIsError)
{
	StatusMessage = FText::FromString(InMessage);
	StatusColor = bIsError ? FSlateColor(FLinearColor(0.9f, 0.2f, 0.2f, 1.0f)) : FSlateColor::UseForeground();
}

#undef LOCTEXT_NAMESPACE
