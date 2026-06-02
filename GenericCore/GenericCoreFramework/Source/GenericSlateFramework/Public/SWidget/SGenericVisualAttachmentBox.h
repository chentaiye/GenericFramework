// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Layout/SBox.h"

/** 实现可视附着 Slate 容器，负责组织子控件、同步属性并转发 Slate 事件。 */
class GENERICSLATEFRAMEWORK_API SGenericVisualAttachmentBox : public SBox
{
	SLATE_DECLARE_WIDGET(SGenericVisualAttachmentBox, SBox)

public:
	/** 构建底层 Slate 控件，并绑定初始属性、子控件和事件回调。 */
	void Construct(const FArguments& InArgs);

	/** 写入内容锚点，并同步到当前对象缓存和底层 Slate 控件。 */
	void SetContentAnchor(FVector2D InContentAnchor);

	virtual FVector2D ComputeDesiredSize(float InScale) const override;
	virtual void OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;

private:
	/** 保存Inner期望尺寸显示参数，供 Slate 构建或 UMG 属性同步时使用。 */
	mutable FVector2D InnerDesiredSize = FVector2D::ZeroVector;

	/** 保存附着内容锚点，决定子控件在目标区域中的对齐位置。 */
	FVector2D ContentAnchor = FVector2D::ZeroVector;
};
