// Copyright ChenTaiye 2025. All Rights Reserved.

#include "UWidget/SpacingHorizontalBox.h"

#include "Components/HorizontalBoxSlot.h"
#include "SWidget/SpacingBoxPanels.h"

UHorizontalBoxSlot* USpacingHorizontalBox::AddChildToSpacingHorizontalBox(UWidget* Content)
{
	return Cast<UHorizontalBoxSlot>(Super::AddChild(Content));
}

void USpacingHorizontalBox::SetInnerSlotPadding(const float InInnerSlotPadding)
{
	InnerSlotPadding = FMath::Max(0.0f, InInnerSlotPadding);
	if (MySpacingHorizontalBox.IsValid())
	{
		MySpacingHorizontalBox->SetInnerSlotPadding(InnerSlotPadding);
	}
}

float USpacingHorizontalBox::GetInnerSlotPadding() const
{
	return InnerSlotPadding;
}

void USpacingHorizontalBox::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	SetInnerSlotPadding(InnerSlotPadding);
}

void USpacingHorizontalBox::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MySpacingHorizontalBox.Reset();
}

TSharedRef<SWidget> USpacingHorizontalBox::RebuildWidget()
{
	MySpacingHorizontalBox = SNew(SSpacingHorizontalBox)
		.InnerSlotPadding(InnerSlotPadding);
	MyHorizontalBox = MySpacingHorizontalBox;

	for (UPanelSlot* PanelSlot : Slots)
	{
		if (UHorizontalBoxSlot* TypedSlot = Cast<UHorizontalBoxSlot>(PanelSlot))
		{
			TypedSlot->Parent = this;
			TypedSlot->BuildSlot(MyHorizontalBox.ToSharedRef());
		}
	}

	return MySpacingHorizontalBox.ToSharedRef();
}
