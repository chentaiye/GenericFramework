// Copyright ChenTaiye 2025. All Rights Reserved.

#include "SWidget/SpacingBoxPanels.h"

#include "Layout/LayoutUtils.h"
#include "Misc/EngineVersionComparison.h"
#include "Widgets/SNullWidget.h"

namespace UE::DevSlateCore::Private
{
#if UE_VERSION_OLDER_THAN(5, 7, 0)
	struct FSlotProxy
	{
		FSlotProxy() = default;

		template <typename SlotType>
		FSlotProxy(const int32 InSlotIndex, const SlotType& InSlot)
			: SlotIndex(InSlotIndex)
			, Widget(InSlot.GetWidget())
			, Padding(InSlot.GetPadding())
			, DesiredSize(InSlot.GetWidget()->GetDesiredSize())
			, Visibility(InSlot.GetWidget()->GetVisibility())
			, SizeRule(InSlot.GetSizeRule())
			, SizeValue(InSlot.GetSizeValue())
			, MaxSize(InSlot.GetMaxSize())
			, HorizontalAlignment(InSlot.GetHorizontalAlignment())
			, VerticalAlignment(InSlot.GetVerticalAlignment())
		{
		}

		const TSharedRef<SWidget>& GetWidget() const { return Widget; }
		FMargin GetPadding() const { return Padding; }
		FSizeParam::ESizeRule GetSizeRule() const { return SizeRule; }
		float GetSizeValue() const { return SizeValue; }
		float GetMaxSize() const { return MaxSize; }
		EHorizontalAlignment GetHorizontalAlignment() const { return HorizontalAlignment; }
		EVerticalAlignment GetVerticalAlignment() const { return VerticalAlignment; }

		int32 SlotIndex = INDEX_NONE;
		TSharedRef<SWidget> Widget = SNullWidget::NullWidget;
		FMargin Padding;
		FVector2f DesiredSize = FVector2f::ZeroVector;
		EVisibility Visibility = EVisibility::Visible;
		FSizeParam::ESizeRule SizeRule = FSizeParam::SizeRule_Auto;
		float SizeValue = 0.0f;
		float MinSize = 0.0f;
		float MaxSize = 0.0f;
		EHorizontalAlignment HorizontalAlignment = HAlign_Fill;
		EVerticalAlignment VerticalAlignment = VAlign_Fill;
	};

	template <EOrientation Orientation>
	void ArrangeChildrenInStackForProxies(EFlowDirection InLayoutFlow, const TArray<FSlotProxy>& InSlotProxies, const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren, const float InOffset, const bool bInAllowShrink)
	{
		if (InSlotProxies.IsEmpty())
		{
			return;
		}

		float StretchCoefficientTotal = 0.0f;
		float FixedTotal = 0.0f;
		float StretchSizeTotal = 0.0f;
		bool bAnyChildVisible = false;

		for (const FSlotProxy& CurChild : InSlotProxies)
		{
			if (CurChild.Visibility == EVisibility::Collapsed)
			{
				continue;
			}

			bAnyChildVisible = true;
			FixedTotal += CurChild.Padding.GetTotalSpaceAlong<Orientation>();

			const float ChildSize = Orientation == Orient_Vertical ? CurChild.DesiredSize.Y : CurChild.DesiredSize.X;
			if (CurChild.SizeRule == FSizeParam::SizeRule_Stretch)
			{
				StretchCoefficientTotal += CurChild.SizeValue;
				StretchSizeTotal += ChildSize;
			}
			else
			{
				FixedTotal += CurChild.MaxSize > 0.0f ? FMath::Min(CurChild.MaxSize, ChildSize) : ChildSize;
			}
		}

		if (!bAnyChildVisible)
		{
			return;
		}

		const float MinSize = bInAllowShrink ? 0.0f : StretchSizeTotal;
		const float NonFixedSpace = FMath::Max(MinSize, Orientation == Orient_Vertical ? AllottedGeometry.GetLocalSize().Y - FixedTotal : AllottedGeometry.GetLocalSize().X - FixedTotal);
		float PositionSoFar = 0.0f;

		auto ArrangeChild = [&](const FSlotProxy& CurChild)
		{
			const EVisibility ChildVisibility = CurChild.Visibility;

			float ChildSize = 0.0f;
			if (ChildVisibility != EVisibility::Collapsed)
			{
				if (CurChild.SizeRule == FSizeParam::SizeRule_Stretch)
				{
					if (StretchCoefficientTotal > 0.0f)
					{
						ChildSize = NonFixedSpace * CurChild.SizeValue / StretchCoefficientTotal;
					}
				}
				else
				{
					ChildSize = Orientation == Orient_Vertical ? CurChild.DesiredSize.Y : CurChild.DesiredSize.X;
				}

				if (CurChild.MaxSize > 0.0f)
				{
					ChildSize = FMath::Min(CurChild.MaxSize, ChildSize);
				}
			}

			const FMargin SlotPadding(LayoutPaddingWithFlow(InLayoutFlow, CurChild.Padding));
			const FVector2f SlotSize = Orientation == Orient_Vertical
				? FVector2f(AllottedGeometry.GetLocalSize().X, ChildSize + SlotPadding.GetTotalSpaceAlong<Orient_Vertical>())
				: FVector2f(ChildSize + SlotPadding.GetTotalSpaceAlong<Orient_Horizontal>(), AllottedGeometry.GetLocalSize().Y);

			const AlignmentArrangeResult XAlignmentResult = AlignChild<Orient_Horizontal>(InLayoutFlow, SlotSize.X, CurChild, SlotPadding);
			const AlignmentArrangeResult YAlignmentResult = AlignChild<Orient_Vertical>(SlotSize.Y, CurChild, SlotPadding);

			const FVector2f LocalPosition = Orientation == Orient_Vertical
				? FVector2f(XAlignmentResult.Offset, PositionSoFar + YAlignmentResult.Offset + InOffset)
				: FVector2f(PositionSoFar + XAlignmentResult.Offset + InOffset, YAlignmentResult.Offset);
			const FVector2f LocalSize(XAlignmentResult.Size, YAlignmentResult.Size);

			if (ArrangedChildren.Accepts(ChildVisibility))
			{
				ArrangedChildren.AddWidget(ChildVisibility, AllottedGeometry.MakeChild(
					CurChild.GetWidget(),
					LocalSize,
					FSlateLayoutTransform(LocalPosition)));
			}

			if (ChildVisibility != EVisibility::Collapsed)
			{
				PositionSoFar += Orientation == Orient_Vertical ? SlotSize.Y : SlotSize.X;
			}
		};

		if (Orientation == Orient_Horizontal && InLayoutFlow == EFlowDirection::RightToLeft)
		{
			for (int32 ChildIndex = InSlotProxies.Num() - 1; ChildIndex >= 0; --ChildIndex)
			{
				ArrangeChild(InSlotProxies[ChildIndex]);
			}
		}
		else
		{
			for (const FSlotProxy& CurChild : InSlotProxies)
			{
				ArrangeChild(CurChild);
			}
		}
	}
#endif

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

#if UE_VERSION_OLDER_THAN(5, 7, 0)
using UE::DevSlateCore::Private::FSlotProxy;
#endif

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
#if UE_VERSION_OLDER_THAN(5, 7, 0)
	UE::DevSlateCore::Private::ArrangeChildrenInStackForProxies<Orient_Horizontal>(GSlateFlowDirection, SlotProxies, AllottedGeometry, ArrangedChildren, Offset, bAllowShrink);
#else
	FVector2D UnusedArrangedSize = FVector2D::ZeroVector;
	ArrangeChildrenInStack<Orient_Horizontal>(GSlateFlowDirection, MakeArrayView(SlotProxies), AllottedGeometry, ArrangedChildren, Offset, bAllowShrink, UnusedArrangedSize);
#endif
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
#if UE_VERSION_OLDER_THAN(5, 7, 0)
	UE::DevSlateCore::Private::ArrangeChildrenInStackForProxies<Orient_Vertical>(GSlateFlowDirection, SlotProxies, AllottedGeometry, ArrangedChildren, Offset, bAllowShrink);
#else
	FVector2D UnusedArrangedSize = FVector2D::ZeroVector;
	ArrangeChildrenInStack<Orient_Vertical>(GSlateFlowDirection, MakeArrayView(SlotProxies), AllottedGeometry, ArrangedChildren, Offset, bAllowShrink, UnusedArrangedSize);
#endif
}

FVector2D SSpacingVerticalBox::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	TArray<FSlotProxy> SlotProxies;
	UE::DevSlateCore::Private::BuildSlotProxies(Children, Orient_Vertical, InnerSlotPadding, SlotProxies);
	return UE::DevSlateCore::Private::ComputeDesiredSizeForProxies<Orient_Vertical>(SlotProxies);
}
