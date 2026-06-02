// Copyright ChenTaiye 2025. All Rights Reserved.

#include "SWidget/SGenericVisualAttachmentBox.h"

SLATE_IMPLEMENT_WIDGET(SGenericVisualAttachmentBox)
void SGenericVisualAttachmentBox::PrivateRegisterAttributes(FSlateAttributeInitializer& AttributeInitializer)
{
}

void SGenericVisualAttachmentBox::Construct(const FArguments& InArgs)
{
	SBox::Construct(InArgs);
}

void SGenericVisualAttachmentBox::SetContentAnchor(FVector2D InContentAnchor)
{
	if (!ContentAnchor.Equals(InContentAnchor))
	{
		ContentAnchor = InContentAnchor;
		Invalidate(EInvalidateWidget::Layout);
	}
}

FVector2D SGenericVisualAttachmentBox::ComputeDesiredSize(float InScale) const
{
	InnerDesiredSize = SBox::ComputeDesiredSize(InScale);
	return FVector2D::ZeroVector;
}

void SGenericVisualAttachmentBox::OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const
{
	const FGeometry NewGeometry = AllottedGeometry.MakeChild(InnerDesiredSize, FSlateLayoutTransform(-(ContentAnchor * InnerDesiredSize)));
	SBox::OnArrangeChildren(NewGeometry, ArrangedChildren);
}

int32 SGenericVisualAttachmentBox::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	return SBox::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
}
