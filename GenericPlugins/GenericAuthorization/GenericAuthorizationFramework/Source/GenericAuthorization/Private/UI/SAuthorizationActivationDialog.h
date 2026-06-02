// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SMultiLineEditableTextBox;
class SWindow;

DECLARE_DELEGATE_RetVal(FString, FAuthorizationRequestCodeGetter);
DECLARE_DELEGATE_RetVal_TwoParams(bool, FAuthorizationLicenseSubmitter, const FString&, FString&);

/** 授权激活 Slate 对话框，负责展示申请码、收集许可证文本，并通过回调把用户提交交给授权流程处理。 */
class SAuthorizationActivationDialog : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SAuthorizationActivationDialog)
	{
	}
		SLATE_EVENT(FAuthorizationRequestCodeGetter, OnGetAuthorizationRequestCode)
		SLATE_EVENT(FAuthorizationLicenseSubmitter, OnSubmitLicenseCode)
	SLATE_END_ARGS()

	/** 构建授权输入界面并缓存回调，初始化时同步生成可复制的授权申请码。 */
	void Construct(const FArguments& InArgs);

	/** 返回本次对话框是否成功提交授权，外层窗口关闭逻辑用它决定继续运行或退出。 */
	bool WasAuthorized() const
	{
		return bWasAuthorized;
	}

	/** 保存承载该控件的窗口，确认或取消时通过它关闭模态授权窗口。 */
	void SetOwnerWindow(const TSharedRef<SWindow>& InOwnerWindow)
	{
		OwnerWindow = InOwnerWindow;
	}

private:
	/** 处理复制申请码按钮，把当前申请码写入剪贴板并在对话框中反馈结果。 */
	FReply HandleCopyAuthorizationRequestCode();

	/** 处理粘贴授权码按钮，把剪贴板文本填入许可证输入框供用户确认。 */
	FReply HandlePasteLicense();

	/** 处理确认授权按钮，校验输入后调用提交回调，成功时标记对话框已授权并关闭窗口。 */
	FReply HandleConfirmAuthorization();

	/** 处理取消授权按钮，标记本次未完成授权并关闭窗口，让外层逻辑决定是否退出。 */
	FReply HandleCancelAuthorization();

	/** 请求销毁拥有者窗口，使模态启动提示或运行中重新授权流程回到外层关闭处理。 */
	void CloseDialogWindow();

	/** 更新对话框底部状态文本和颜色，用于显示复制、粘贴、授权失败或成功反馈。 */
	void SetStatusMessage(const FString& InMessage, bool bIsError);

	FAuthorizationRequestCodeGetter OnGetAuthorizationRequestCode;

	FAuthorizationLicenseSubmitter OnSubmitLicenseCode;

	/** 弱引用拥有者窗口，避免控件延长窗口生命周期，同时允许按钮处理关闭窗口。 */
	TWeakPtr<SWindow> OwnerWindow;

	/** 保存许可证输入框引用，粘贴和确认授权流程都需要读写用户输入的授权文本。 */
	TSharedPtr<SMultiLineEditableTextBox> LicenseInputTextBox;

	/** 缓存构造时生成的申请码，复制按钮直接使用它而不在每次点击时重新生成。 */
	FString AuthorizationRequestCode;

	/** 保存当前反馈消息，Slate 文本绑定从这里读取最新操作结果。 */
	FText StatusMessage;

	/** 保存状态文本颜色，错误消息使用醒目红色，普通反馈沿用 Slate 前景色。 */
	FSlateColor StatusColor = FSlateColor::UseForeground();

	/** 标记本次窗口是否已成功完成授权，启动守卫和重新授权窗口关闭时据此放行或退出。 */
	bool bWasAuthorized = false;
};
