// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SBoxPanel.h"

/** 实现带间距水平 Slate 面板，负责组织子控件、同步属性并转发 Slate 事件。 */
class GENERICSLATEFRAMEWORK_API SSpacingHorizontalBox : public SHorizontalBox
{
	SLATE_DECLARE_WIDGET(SSpacingHorizontalBox, SHorizontalBox)

public:
	SLATE_BEGIN_ARGS(SSpacingHorizontalBox)

		: _InnerSlotPadding(0.0f)
	{
		_Visibility = EVisibility::SelfHitTestInvisible;
	}
		SLATE_ARGUMENT(float, InnerSlotPadding)
	SLATE_END_ARGS()

	/** 构建底层 Slate 控件，并绑定初始属性、子控件和事件回调。 */
	void Construct(const FArguments& InArgs);

	/** 写入InnerSlot内边距，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetInnerSlotPadding(float InInnerSlotPadding);

	/** 读取InnerSlot内边距，供调用方复用当前对象缓存或引擎状态。 */
	float GetInnerSlotPadding() const;

	virtual void OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const override;

protected:
	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;

private:
	/** 保存InnerSlot内边距数值，供布局、渲染或运行时逻辑读取。 */
	float InnerSlotPadding = 0.0f;
};

/** 实现带间距垂直 Slate 面板，负责组织子控件、同步属性并转发 Slate 事件。 */
class GENERICSLATEFRAMEWORK_API SSpacingVerticalBox : public SVerticalBox
{
	SLATE_DECLARE_WIDGET(SSpacingVerticalBox, SVerticalBox)

public:
	SLATE_BEGIN_ARGS(SSpacingVerticalBox)

		: _InnerSlotPadding(0.0f)
	{
		_Visibility = EVisibility::SelfHitTestInvisible;
	}
		SLATE_ARGUMENT(float, InnerSlotPadding)
	SLATE_END_ARGS()

	/** 构建底层 Slate 控件，并绑定初始属性、子控件和事件回调。 */
	void Construct(const FArguments& InArgs);

	/** 写入InnerSlot内边距，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetInnerSlotPadding(float InInnerSlotPadding);

	/** 读取InnerSlot内边距，供调用方复用当前对象缓存或引擎状态。 */
	float GetInnerSlotPadding() const;

	virtual void OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const override;

protected:
	virtual FVector2D ComputeDesiredSize(float LayoutScaleMultiplier) const override;

private:
	/** 保存InnerSlot内边距数值，供布局、渲染或运行时逻辑读取。 */
	float InnerSlotPadding = 0.0f;
};
