// Copyright ChenTaiye 2025. All Rights Reserved.

#include "UWidget/SpacingVerticalBox.h"

#include "Components/VerticalBoxSlot.h"
#include "SWidget/SpacingBoxPanels.h"

UVerticalBoxSlot* USpacingVerticalBox::AddChildToSpacingVerticalBox(UWidget* Content)
{
	return Cast<UVerticalBoxSlot>(Super::AddChild(Content));
}

void USpacingVerticalBox::SetInnerSlotPadding(const float InInnerSlotPadding)
{
	InnerSlotPadding = FMath::Max(0.0f, InInnerSlotPadding);
	if (MySpacingVerticalBox.IsValid())
	{
		MySpacingVerticalBox->SetInnerSlotPadding(InnerSlotPadding);
	}
}

float USpacingVerticalBox::GetInnerSlotPadding() const
{
	return InnerSlotPadding;
}

void USpacingVerticalBox::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	SetInnerSlotPadding(InnerSlotPadding);
}

void USpacingVerticalBox::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MySpacingVerticalBox.Reset();
}

TSharedRef<SWidget> USpacingVerticalBox::RebuildWidget()
{
	MySpacingVerticalBox = SNew(SSpacingVerticalBox)
		.InnerSlotPadding(InnerSlotPadding);
	MyVerticalBox = MySpacingVerticalBox;

	for (UPanelSlot* PanelSlot : Slots)
	{
		if (UVerticalBoxSlot* TypedSlot = Cast<UVerticalBoxSlot>(PanelSlot))
		{
			TypedSlot->Parent = this;
			TypedSlot->BuildSlot(MyVerticalBox.ToSharedRef());
		}
	}

	return MySpacingVerticalBox.ToSharedRef();
}
