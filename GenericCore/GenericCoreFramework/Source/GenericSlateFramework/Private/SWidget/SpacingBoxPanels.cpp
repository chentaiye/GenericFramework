// Copyright ChenTaiye 2025. All Rights Reserved.

#include "SWidget/SpacingBoxPanels.h"

#include "Layout/LayoutUtils.h"

namespace UE::DevSlateCore::Private
{
	template <typename SlotType>
	void BuildSlotProxies(const TPanelChildren<SlotType>& InChildren, const EOrientation Orientation, const float InnerSlotPadding, TArray<FSlotProxy>& OutSlotProxies)
	{
		OutSlotProxies.Reset();
		OutSlotProxies.Reserve(InChildren.Num());

		bool bHasVisibleChild = false;
		for (int32 ChildIndex = 0; ChildIndex < InChildren.Num(); ++ChildIndex)
		{
			const SlotType& ChildSlot = InChildren[ChildIndex];
			FSlotProxy Proxy(ChildIndex, ChildSlot);

			if (Proxy.Visibility != EVisibility::Collapsed && bHasVisibleChild && InnerSlotPadding > 0.0f)
			{
				if (Orientation == Orient_Horizontal)
				{
					Proxy.Padding.Left += InnerSlotPadding;
				}
				else
				{
					Proxy.Padding.Top += InnerSlotPadding;
				}
			}

			bHasVisibleChild |= Proxy.Visibility != EVisibility::Collapsed;
			OutSlotProxies.Emplace(MoveTemp(Proxy));
		}
	}

	template <EOrientation Orientation>
	FVector2D ComputeDesiredSizeForProxies(const TArray<FSlotProxy>& InSlotProxies)
	{
		FVector2D DesiredSize(0.0f, 0.0f);

		for (const FSlotProxy& SlotProxy : InSlotProxies)
		{
			if (SlotProxy.Visibility == EVisibility::Collapsed)
			{
				continue;
			}

			auto ClampMinMax = [&SlotProxy](float& InOutDesiredSize)
			{
				if (SlotProxy.MinSize > 0.0f)
				{
					InOutDesiredSize = FMath::Max(SlotProxy.MinSize, InOutDesiredSize);
				}

				if (SlotProxy.MaxSize > 0.0f)
				{
					InOutDesiredSize = FMath::Min(SlotProxy.MaxSize, InOutDesiredSize);
				}
			};

			const FVector2f ChildDesiredSize = SlotProxy.DesiredSize;
			if constexpr (Orientation == Orient_Horizontal)
			{
				DesiredSize.Y = FMath::Max(DesiredSize.Y, ChildDesiredSize.Y + SlotProxy.Padding.GetTotalSpaceAlong<Orient_Vertical>());

				float FinalChildWidth = ChildDesiredSize.X;
				ClampMinMax(FinalChildWidth);
				DesiredSize.X += FinalChildWidth + SlotProxy.Padding.GetTotalSpaceAlong<Orient_Horizontal>();
			}
			else
			{
				DesiredSize.X = FMath::Max(DesiredSize.X, ChildDesiredSize.X + SlotProxy.Padding.GetTotalSpaceAlong<Orient_Horizontal>());

				float FinalChildHeight = ChildDesiredSize.Y;
				ClampMinMax(FinalChildHeight);
				DesiredSize.Y += FinalChildHeight + SlotProxy.Padding.GetTotalSpaceAlong<Orient_Vertical>();
			}
		}

		return DesiredSize;
	}
}

SLATE_IMPLEMENT_WIDGET(SSpacingHorizontalBox)
void SSpacingHorizontalBox::PrivateRegisterAttributes(FSlateAttributeInitializer& AttributeInitializer)
{
}

void SSpacingHorizontalBox::Construct(const FArguments& InArgs)
{
	InnerSlotPadding = InArgs._InnerSlotPadding;
	SHorizontalBox::Construct(SHorizontalBox::FArguments());
}

void SSpacingHorizontalBox::SetInnerSlotPadding(const float InInnerSlotPadding)
{
	if (!FMath::IsNearlyEqual(InnerSlotPadding, InInnerSlotPadding))
	{
		InnerSlotPadding = InInnerSlotPadding;
		Invalidate(EInvalidateWidgetReason::Layout);
	}
}

float SSpacingHorizontalBox::GetInnerSlotPadding() const
{
	return InnerSlotPadding;
}

void SSpacingHorizontalBox::OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const
{
	TArray<FSlotProxy> SlotProxies;
	UE::DevSlateCore::Private::BuildSlotProxies(Children, Orient_Horizontal, InnerSlotPadding, SlotProxies);

	const float Offset = 0.0f;
	const bool bAllowShrink = true;
	FVector2D UnusedArrangedSize = FVector2D::ZeroVector;
	ArrangeChildrenInStack<Orient_Horizontal>(GSlateFlowDirection, MakeArrayView(SlotProxies), AllottedGeometry, ArrangedChildren, Offset, bAllowShrink, UnusedArrangedSize);
}

FVector2D SSpacingHorizontalBox::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	TArray<FSlotProxy> SlotProxies;
	UE::DevSlateCore::Private::BuildSlotProxies(Children, Orient_Horizontal, InnerSlotPadding, SlotProxies);
	return UE::DevSlateCore::Private::ComputeDesiredSizeForProxies<Orient_Horizontal>(SlotProxies);
}

SLATE_IMPLEMENT_WIDGET(SSpacingVerticalBox)
void SSpacingVerticalBox::PrivateRegisterAttributes(FSlateAttributeInitializer& AttributeInitializer)
{
}

void SSpacingVerticalBox::Construct(const FArguments& InArgs)
{
	InnerSlotPadding = InArgs._InnerSlotPadding;
	SVerticalBox::Construct(SVerticalBox::FArguments());
}

void SSpacingVerticalBox::SetInnerSlotPadding(const float InInnerSlotPadding)
{
	if (!FMath::IsNearlyEqual(InnerSlotPadding, InInnerSlotPadding))
	{
		InnerSlotPadding = InInnerSlotPadding;
		Invalidate(EInvalidateWidgetReason::Layout);
	}
}

float SSpacingVerticalBox::GetInnerSlotPadding() const
{
	return InnerSlotPadding;
}

void SSpacingVerticalBox::OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const
{
	TArray<FSlotProxy> SlotProxies;
	UE::DevSlateCore::Private::BuildSlotProxies(Children, Orient_Vertical, InnerSlotPadding, SlotProxies);

	const float Offset = 0.0f;
	const bool bAllowShrink = true;
	FVector2D UnusedArrangedSize = FVector2D::ZeroVector;
	ArrangeChildrenInStack<Orient_Vertical>(GSlateFlowDirection, MakeArrayView(SlotProxies), AllottedGeometry, ArrangedChildren, Offset, bAllowShrink, UnusedArrangedSize);
}

FVector2D SSpacingVerticalBox::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	TArray<FSlotProxy> SlotProxies;
	UE::DevSlateCore::Private::BuildSlotProxies(Children, Orient_Vertical, InnerSlotPadding, SlotProxies);
	return UE::DevSlateCore::Private::ComputeDesiredSizeForProxies<Orient_Vertical>(SlotProxies);
}
