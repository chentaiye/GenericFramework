// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Input/SButton.h"
#include "Framework/SlateDelegates.h"
#include "Types/SlateEnums.h"
#include "Widgets/SCompoundWidget.h"

/** 实现通用按钮 Slate 控件，负责组织子控件、同步属性并转发 Slate 事件。 */
class GENERICSLATEFRAMEWORK_API SGenericButton : public SButton
{
public:
	SLATE_BEGIN_ARGS(SGenericButton)

			: _Content()
			  , _HAlign(HAlign_Fill)
			  , _VAlign(VAlign_Fill)
			  , _ClickMethod(EButtonClickMethod::DownAndUp)
			  , _TouchMethod(EButtonTouchMethod::DownAndUp)
			  , _PressMethod(EButtonPressMethod::DownAndUp)
			  , _IsFocusable(true)
			  , _IsInteractionEnabled(true)
		{
		}

		SLATE_DEFAULT_SLOT(FArguments, Content)
		SLATE_STYLE_ARGUMENT(FButtonStyle, ButtonStyle)
		SLATE_ARGUMENT(EHorizontalAlignment, HAlign)
		SLATE_ARGUMENT(EVerticalAlignment, VAlign)
		SLATE_EVENT(FOnClicked, OnClicked)
		SLATE_EVENT(FOnClicked, OnDoubleClicked)
		SLATE_EVENT(FSimpleDelegate, OnPressed)
		SLATE_EVENT(FSimpleDelegate, OnReleased)
		SLATE_ARGUMENT(EButtonClickMethod::Type, ClickMethod)
		SLATE_ARGUMENT(EButtonTouchMethod::Type, TouchMethod)
		SLATE_ARGUMENT(EButtonPressMethod::Type, PressMethod)
		SLATE_ARGUMENT(bool, IsFocusable)
		SLATE_EVENT(FSimpleDelegate, OnReceivedFocus)
		SLATE_EVENT(FSimpleDelegate, OnLostFocus)

		SLATE_ARGUMENT(bool, IsButtonEnabled)
		SLATE_ARGUMENT(bool, IsInteractionEnabled)

	SLATE_END_ARGS()

	/** 构建底层 Slate 控件，并绑定初始属性、子控件和事件回调。 */
	void Construct(const FArguments& InArgs);

public:
	virtual void OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual void OnMouseLeave(const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent) override;
	virtual FReply OnTouchMoved(const FGeometry& MyGeometry, const FPointerEvent& InTouchEvent) override;
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnFocusReceived(const FGeometry& MyGeometry, const FFocusEvent& InFocusEvent) override;
	virtual void OnFocusLost(const FFocusEvent& InFocusEvent) override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual bool IsInteractable() const override;

public:
	/** 写入是否按钮Enabled，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetIsButtonEnabled(bool bInIsButtonEnabled);

	/** 写入是否InteractionEnabled，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetIsInteractionEnabled(bool bInIsInteractionEnabled);

	/** 写入是否按钮Focusable，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetIsButtonFocusable(bool bInIsButtonFocusable);

private:
	FOnClicked OnDoubleClicked;

	FSimpleDelegate OnReceivedFocus;

	FSimpleDelegate OnLostFocus;

	/** 记录是否按钮Enabled，用于在生命周期、同步或输入流程中选择后续路径。 */
	bool bIsButtonEnabled = true;

	/** 记录是否InteractionEnabled，用于在生命周期、同步或输入流程中选择后续路径。 */
	bool bIsInteractionEnabled = true;

	/** 记录Hovered，用于在生命周期、同步或输入流程中选择后续路径。 */
	bool bHovered = false;
};
