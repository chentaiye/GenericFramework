// Copyright ChenTaiye 2025. All Rights Reserved.

#include "SWidget/SpacingBoxPanels.h"

#include "Layout/LayoutUtils.h"
#include "Misc/EngineVersionComparison.h"

namespace UE::DevSlateCore::Private
{
#if UE_VERSION_OLDER_THAN(5, 7, 0)
	struct FSpacingSlotProxy
	{
		template <typename SlotType>
		FSpacingSlotProxy(const int32 InSlotIndex, const SlotType& InSlot)
			: SlotIndex(InSlotIndex)
			, Widget(InSlot.GetWidget())
			, Padding(InSlot.GetPadding())
			, DesiredSize(InSlot.GetWidget()->GetDesiredSize())
			, SizeRule(InSlot.GetSizeRule())
			, SizeValue(InSlot.GetSizeValue())
			, ShrinkSizeValue(InSlot.GetShrinkSizeValue())
			, MinSize(InSlot.GetMinSize())
			, MaxSize(InSlot.GetMaxSize())
			, Visibility(InSlot.GetWidget()->GetVisibility())
			, HorizontalAlignment(InSlot.GetHorizontalAlignment())
			, VerticalAlignment(InSlot.GetVerticalAlignment())
		{
		}

		TSharedRef<SWidget> GetWidget() const { return Widget.ToSharedRef(); }
		EHorizontalAlignment GetHorizontalAlignment() const { return HorizontalAlignment; }
		EVerticalAlignment GetVerticalAlignment() const { return VerticalAlignment; }

		int32 SlotIndex = INDEX_NONE;
		TSharedPtr<SWidget> Widget;
		FMargin Padding = FMargin();
		FVector2f DesiredSize = FVector2f::ZeroVector;
		FSizeParam::ESizeRule SizeRule = FSizeParam::SizeRule_Auto;
		float SizeValue = 0.0f;
		float ShrinkSizeValue = 0.0f;
		float MinSize = 0.0f;
		float MaxSize = 0.0f;
		EVisibility Visibility = EVisibility::Visible;
		EHorizontalAlignment HorizontalAlignment = HAlign_Fill;
		EVerticalAlignment VerticalAlignment = VAlign_Fill;
	};

	using FSpacingSlotProxyType = FSpacingSlotProxy;
#else
	using FSpacingSlotProxyType = FSlotProxy;
#endif

	template <typename SlotType>
	void BuildSlotProxies(const TPanelChildren<SlotType>& InChildren, const EOrientation Orientation, const float InnerSlotPadding, TArray<FSpacingSlotProxyType>& OutSlotProxies)
	{
		OutSlotProxies.Reset();
		OutSlotProxies.Reserve(InChildren.Num());

		bool bHasVisibleChild = false;
		for (int32 ChildIndex = 0; ChildIndex < InChildren.Num(); ++ChildIndex)
		{
			const SlotType& ChildSlot = InChildren[ChildIndex];
			FSpacingSlotProxyType Proxy(ChildIndex, ChildSlot);

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
	FVector2D ComputeDesiredSizeForProxies(const TArray<FSpacingSlotProxyType>& InSlotProxies)
	{
		FVector2D DesiredSize(0.0f, 0.0f);

		for (const FSpacingSlotProxyType& SlotProxy : InSlotProxies)
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

#if UE_VERSION_OLDER_THAN(5, 7, 0)
	template <EOrientation Orientation>
	void ArrangeChildrenInSpacingStack(EFlowDirection InLayoutFlow, const TArray<FSpacingSlotProxyType>& InChildren, const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren, float InOffset, bool bInAllowShrink)
	{
		if (InChildren.Num() == 0)
		{
			return;
		}

		auto ClampSize = [](const float Size, const float MinSize, const float MaxSize)
		{
			return FMath::Clamp(
				Size,
				MinSize > 0.0f ? MinSize : 0.0f,
				MaxSize > 0.0f ? MaxSize : std::numeric_limits<float>::max());
		};

		float GrowStretchCoefficientTotal = 0.0f;
		float ShrinkStretchCoefficientTotal = 0.0f;
		float FixedSizeTotal = 0.0f;
		float StretchSizeTotal = 0.0f;

		struct FStretchItem
		{
			float Size = 0.0f;
			float BasisSize = 0.0f;
			float MinSize = 0.0f;
			float MaxSize = 0.0f;
			float GrowStretchValue = 0.0f;
			float ShrinkStretchValue = 0.0f;
			bool bFrozen = false;
			FSizeParam::ESizeRule SizeRule = FSizeParam::SizeRule_Auto;
		};

		TArray<FStretchItem, TInlineAllocator<16>> StretchItems;
		StretchItems.Init({}, InChildren.Num());

		bool bAnyChildVisible = false;
		bool bAnyStretchContentItems = false;
		bool bAnyStretchItems = false;

		for (int32 ChildIndex = 0; ChildIndex < InChildren.Num(); ++ChildIndex)
		{
			const FSpacingSlotProxyType& CurChild = InChildren[ChildIndex];
			if (CurChild.Visibility == EVisibility::Collapsed)
			{
				continue;
			}

			bAnyChildVisible = true;
			FixedSizeTotal += CurChild.Padding.template GetTotalSpaceAlong<Orientation>();

			const float ChildDesiredSize = Orientation == Orient_Vertical ? CurChild.DesiredSize.Y : CurChild.DesiredSize.X;
			float ChildSize = ClampSize(ChildDesiredSize, CurChild.MinSize, CurChild.MaxSize);

			FStretchItem& Item = StretchItems[ChildIndex];
			Item.MinSize = CurChild.MinSize;
			Item.MaxSize = CurChild.MaxSize;
			Item.SizeRule = CurChild.SizeRule;

			if (Item.SizeRule == FSizeParam::SizeRule_Stretch)
			{
				Item.GrowStretchValue = CurChild.SizeValue;
				Item.ShrinkStretchValue = Item.GrowStretchValue;
				GrowStretchCoefficientTotal += Item.GrowStretchValue;
				ShrinkStretchCoefficientTotal += Item.ShrinkStretchValue;
				StretchSizeTotal += ChildSize;
				bAnyStretchItems = true;
			}
			else if (Item.SizeRule == FSizeParam::SizeRule_StretchContent)
			{
				Item.GrowStretchValue = FMath::Max(0.0f, CurChild.SizeValue);
				Item.ShrinkStretchValue = FMath::Max(0.0f, CurChild.ShrinkSizeValue);
				Item.Size = ChildSize;
				Item.BasisSize = ChildSize;
				GrowStretchCoefficientTotal += Item.GrowStretchValue;
				ShrinkStretchCoefficientTotal += Item.ShrinkStretchValue;
				StretchSizeTotal += ChildSize;
				bAnyStretchContentItems = true;
			}
			else
			{
				FixedSizeTotal += ChildSize;
				Item.Size = ChildSize;
				Item.BasisSize = ChildSize;
			}
		}

		if (!bAnyChildVisible)
		{
			return;
		}

		const float MinAvailableSpace = bInAllowShrink ? 0.0f : StretchSizeTotal;
		const float AllottedSize = Orientation == Orient_Vertical ? AllottedGeometry.GetLocalSize().Y : AllottedGeometry.GetLocalSize().X;
		float AvailableSpace = FMath::Max(MinAvailableSpace, AllottedSize - FixedSizeTotal);

		if (bAnyStretchItems && GrowStretchCoefficientTotal > 0.0f)
		{
			float UsedSpace = 0.0f;
			for (FStretchItem& Item : StretchItems)
			{
				if (Item.SizeRule == FSizeParam::SizeRule_Stretch)
				{
					Item.Size = ClampSize(AvailableSpace * Item.GrowStretchValue / GrowStretchCoefficientTotal, Item.MinSize, Item.MaxSize);
					UsedSpace += Item.Size;
				}
			}
			AvailableSpace -= UsedSpace;
		}

		const bool bIsGrowing = AvailableSpace > StretchSizeTotal;
		const bool bCanStretch = bIsGrowing ? GrowStretchCoefficientTotal > 0.0f : ShrinkStretchCoefficientTotal > 0.0f;
		if (bAnyStretchContentItems && bCanStretch)
		{
			int32 NumStretchContentItems = 0;
			for (FStretchItem& Item : StretchItems)
			{
				if (Item.SizeRule == FSizeParam::SizeRule_StretchContent)
				{
					AvailableSpace -= Item.Size;
					++NumStretchContentItems;
					Item.bFrozen |= bIsGrowing ? FMath::IsNearlyZero(Item.GrowStretchValue) : FMath::IsNearlyZero(Item.ShrinkStretchValue);
				}
			}

			const int32 MaxPasses = FMath::Min(NumStretchContentItems, 5);
			for (int32 Pass = 0; Pass < MaxPasses; ++Pass)
			{
				if (FMath::IsNearlyZero(AvailableSpace))
				{
					break;
				}

				GrowStretchCoefficientTotal = 0.0f;
				ShrinkStretchCoefficientTotal = 0.0f;
				for (const FStretchItem& Item : StretchItems)
				{
					if (Item.SizeRule == FSizeParam::SizeRule_StretchContent && !Item.bFrozen)
					{
						GrowStretchCoefficientTotal += Item.GrowStretchValue;
						ShrinkStretchCoefficientTotal += Item.ShrinkStretchValue * Item.BasisSize;
					}
				}

				const float StretchCoefficientTotal = bIsGrowing ? GrowStretchCoefficientTotal : ShrinkStretchCoefficientTotal;
				if (StretchCoefficientTotal < UE_KINDA_SMALL_NUMBER)
				{
					break;
				}

				float ConsumedSpace = 0.0f;
				for (FStretchItem& Item : StretchItems)
				{
					if (Item.SizeRule != FSizeParam::SizeRule_StretchContent || Item.bFrozen)
					{
						continue;
					}

					const float SizeAdjust = bIsGrowing
						? AvailableSpace * (Item.GrowStretchValue / GrowStretchCoefficientTotal)
						: AvailableSpace * (Item.ShrinkStretchValue * Item.BasisSize / ShrinkStretchCoefficientTotal);
					if (FMath::IsNearlyZero(SizeAdjust))
					{
						Item.bFrozen = true;
						continue;
					}

					if (Item.Size + SizeAdjust <= Item.MinSize)
					{
						ConsumedSpace += Item.MinSize - Item.Size;
						Item.Size = Item.MinSize;
						Item.bFrozen = true;
					}
					else if (Item.MaxSize > 0.0f && Item.Size + SizeAdjust >= Item.MaxSize)
					{
						ConsumedSpace += Item.MaxSize - Item.Size;
						Item.Size = Item.MaxSize;
						Item.bFrozen = true;
					}
					else
					{
						ConsumedSpace += SizeAdjust;
						Item.Size += SizeAdjust;
					}
				}

				AvailableSpace -= ConsumedSpace;
			}
		}

		float PositionSoFar = 0.0f;
#if !UE_VERSION_OLDER_THAN(5, 7, 0)
		ArrangedChildren.Reserve(ArrangedChildren.Num() + InChildren.Num());
#endif

		auto ArrangeAtIndex = [&](const int32 ChildIndex)
		{
			const FSpacingSlotProxyType& CurChild = InChildren[ChildIndex];
			const EVisibility ChildVisibility = CurChild.Visibility;
			const float ChildSize = StretchItems[ChildIndex].Size;
			const FMargin SlotPadding(LayoutPaddingWithFlow(InLayoutFlow, CurChild.Padding));
			const FVector2f SlotSize = Orientation == Orient_Vertical
				? FVector2f(AllottedGeometry.GetLocalSize().X, ChildSize + SlotPadding.template GetTotalSpaceAlong<Orient_Vertical>())
				: FVector2f(ChildSize + SlotPadding.template GetTotalSpaceAlong<Orient_Horizontal>(), AllottedGeometry.GetLocalSize().Y);

			const AlignmentArrangeResult XAlignmentResult = AlignChild<Orient_Horizontal>(InLayoutFlow, SlotSize.X, CurChild, SlotPadding);
			const AlignmentArrangeResult YAlignmentResult = AlignChild<Orient_Vertical>(SlotSize.Y, CurChild, SlotPadding);
			const FVector2f LocalPosition = Orientation == Orient_Vertical
				? FVector2f(XAlignmentResult.Offset, PositionSoFar + YAlignmentResult.Offset + InOffset)
				: FVector2f(PositionSoFar + XAlignmentResult.Offset + InOffset, YAlignmentResult.Offset);
			const FVector2f LocalSize(XAlignmentResult.Size, YAlignmentResult.Size);

			ArrangedChildren.AddWidget(
				ChildVisibility,
				AllottedGeometry.MakeChild(CurChild.GetWidget(), LocalSize, FSlateLayoutTransform(LocalPosition)));

			if (ChildVisibility != EVisibility::Collapsed)
			{
				PositionSoFar += Orientation == Orient_Vertical ? SlotSize.Y : SlotSize.X;
			}
		};

		if (Orientation == Orient_Horizontal && InLayoutFlow == EFlowDirection::RightToLeft)
		{
			for (int32 ChildIndex = InChildren.Num() - 1; ChildIndex >= 0; --ChildIndex)
			{
				ArrangeAtIndex(ChildIndex);
			}
		}
		else
		{
			for (int32 ChildIndex = 0; ChildIndex < InChildren.Num(); ++ChildIndex)
			{
				ArrangeAtIndex(ChildIndex);
			}
		}
	}
#endif
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
	TArray<UE::DevSlateCore::Private::FSpacingSlotProxyType> SlotProxies;
	UE::DevSlateCore::Private::BuildSlotProxies(Children, Orient_Horizontal, InnerSlotPadding, SlotProxies);

	const float Offset = 0.0f;
	const bool bAllowShrink = true;
#if UE_VERSION_OLDER_THAN(5, 7, 0)
	UE::DevSlateCore::Private::ArrangeChildrenInSpacingStack<Orient_Horizontal>(GSlateFlowDirection, SlotProxies, AllottedGeometry, ArrangedChildren, Offset, bAllowShrink);
#else
	FVector2D UnusedArrangedSize = FVector2D::ZeroVector;
	ArrangeChildrenInStack<Orient_Horizontal>(GSlateFlowDirection, MakeArrayView(SlotProxies), AllottedGeometry, ArrangedChildren, Offset, bAllowShrink, UnusedArrangedSize);
#endif
}

FVector2D SSpacingHorizontalBox::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	TArray<UE::DevSlateCore::Private::FSpacingSlotProxyType> SlotProxies;
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
	TArray<UE::DevSlateCore::Private::FSpacingSlotProxyType> SlotProxies;
	UE::DevSlateCore::Private::BuildSlotProxies(Children, Orient_Vertical, InnerSlotPadding, SlotProxies);

	const float Offset = 0.0f;
	const bool bAllowShrink = true;
#if UE_VERSION_OLDER_THAN(5, 7, 0)
	UE::DevSlateCore::Private::ArrangeChildrenInSpacingStack<Orient_Vertical>(GSlateFlowDirection, SlotProxies, AllottedGeometry, ArrangedChildren, Offset, bAllowShrink);
#else
	FVector2D UnusedArrangedSize = FVector2D::ZeroVector;
	ArrangeChildrenInStack<Orient_Vertical>(GSlateFlowDirection, MakeArrayView(SlotProxies), AllottedGeometry, ArrangedChildren, Offset, bAllowShrink, UnusedArrangedSize);
#endif
}

FVector2D SSpacingVerticalBox::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	TArray<UE::DevSlateCore::Private::FSpacingSlotProxyType> SlotProxies;
	UE::DevSlateCore::Private::BuildSlotProxies(Children, Orient_Vertical, InnerSlotPadding, SlotProxies);
	return UE::DevSlateCore::Private::ComputeDesiredSizeForProxies<Orient_Vertical>(SlotProxies);
}
