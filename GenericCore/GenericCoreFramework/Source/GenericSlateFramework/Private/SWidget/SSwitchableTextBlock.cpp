// Copyright ChenTaiye 2025. All Rights Reserved.

#include "SWidget/SSwitchableTextBlock.h"

#include "Widgets/Input/SEditableText.h"
#include "Widgets/Layout/SWidgetSwitcher.h"
#include "Widgets/Text/STextBlock.h"

SLATE_IMPLEMENT_WIDGET(SSwitchableTextBlock)
void SSwitchableTextBlock::PrivateRegisterAttributes(FSlateAttributeInitializer& AttributeInitializer)
{
}

void SSwitchableTextBlock::Construct(const FArguments& InArgs)
{
	ExternalOnTextChanged = InArgs._OnTextChanged;
	ExternalOnTextCommitted = InArgs._OnTextCommitted;
	Mode = InArgs._Mode;
	Text = InArgs._Text;
	HintText = InArgs._HintText;
	Font = InArgs._Font;
	ColorAndOpacity = InArgs._ColorAndOpacity;
	ShadowOffset = InArgs._ShadowOffset;
	ShadowColorAndOpacity = InArgs._ShadowColorAndOpacity;
	StrikeBrush = InArgs._StrikeBrush;
	MinDesiredWidth = InArgs._MinDesiredWidth;
	OverflowPolicy = InArgs._OverflowPolicy;
	TransformPolicy = InArgs._TransformPolicy;
	Justification = InArgs._Justification;
	TextShapingMethod = InArgs._TextShapingMethod;
	TextFlowDirection = InArgs._TextFlowDirection;
	bIsReadOnly = InArgs._IsReadOnly;

	ChildSlot
	[
		SAssignNew(WidgetSwitcher, SWidgetSwitcher)
		+ SWidgetSwitcher::Slot()
		[
			SAssignNew(DisplayTextBlock, STextBlock)
		]
		+ SWidgetSwitcher::Slot()
		[
			SAssignNew(EditableText, SEditableText)
			.OnTextChanged(this, &SSwitchableTextBlock::HandleEditableTextChanged)
			.OnTextCommitted(this, &SSwitchableTextBlock::HandleEditableTextCommitted)
		]
	];

	SetMode(Mode);
	SetFont(Font);
	SetColorAndOpacity(ColorAndOpacity);
	SetShadowOffset(ShadowOffset);
	SetShadowColorAndOpacity(ShadowColorAndOpacity);
	SetStrikeBrush(StrikeBrush);
	SetMinDesiredWidth(MinDesiredWidth);
	SetOverflowPolicy(OverflowPolicy);
	SetTransformPolicy(TransformPolicy);
	SetJustification(Justification);
	SetTextShapingMethod(TextShapingMethod);
	SetTextFlowDirection(TextFlowDirection);
	SetHintText(HintText);
	SetIsReadOnly(bIsReadOnly);
	SetText(Text);
}

void SSwitchableTextBlock::SetMode(ESwitchableTextBlockMode InMode)
{
	Mode = InMode;
	if (WidgetSwitcher.IsValid())
	{
		WidgetSwitcher->SetActiveWidgetIndex(Mode == ESwitchableTextBlockMode::Display ? 0 : 1);
	}
}

void SSwitchableTextBlock::SetText(const FText& InText)
{
	Text = InText;
	SynchronizeDisplayText();
}

void SSwitchableTextBlock::SetHintText(const FText& InHintText)
{
	HintText = InHintText;
	if (EditableText.IsValid())
	{
		EditableText->SetHintText(HintText);
	}
}

void SSwitchableTextBlock::SetFont(const FSlateFontInfo& InFont)
{
	Font = InFont;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetFont(Font);
	}
	if (EditableText.IsValid())
	{
		EditableText->SetFont(Font);
	}
}

void SSwitchableTextBlock::SetColorAndOpacity(const FSlateColor& InColorAndOpacity)
{
	ColorAndOpacity = InColorAndOpacity;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetColorAndOpacity(ColorAndOpacity);
	}
	if (EditableText.IsValid())
	{
		EditableText->SetColorAndOpacity(ColorAndOpacity);
	}
}

void SSwitchableTextBlock::SetShadowOffset(FVector2D InShadowOffset)
{
	ShadowOffset = InShadowOffset;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetShadowOffset(ShadowOffset);
	}
}

void SSwitchableTextBlock::SetShadowColorAndOpacity(FLinearColor InShadowColorAndOpacity)
{
	ShadowColorAndOpacity = InShadowColorAndOpacity;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetShadowColorAndOpacity(ShadowColorAndOpacity);
	}
}

void SSwitchableTextBlock::SetStrikeBrush(const FSlateBrush& InStrikeBrush)
{
	StrikeBrush = InStrikeBrush;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetStrikeBrush(&StrikeBrush);
	}
}

void SSwitchableTextBlock::SetMinDesiredWidth(float InMinDesiredWidth)
{
	MinDesiredWidth = InMinDesiredWidth;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetMinDesiredWidth(MinDesiredWidth);
	}
	if (EditableText.IsValid())
	{
		EditableText->SetMinDesiredWidth(MinDesiredWidth);
	}
}

void SSwitchableTextBlock::SetOverflowPolicy(ETextOverflowPolicy InOverflowPolicy)
{
	OverflowPolicy = InOverflowPolicy;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetOverflowPolicy(OverflowPolicy);
	}
	if (EditableText.IsValid())
	{
		EditableText->SetOverflowPolicy(OverflowPolicy);
	}
}

void SSwitchableTextBlock::SetTransformPolicy(ETextTransformPolicy InTransformPolicy)
{
	TransformPolicy = InTransformPolicy;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetTransformPolicy(TransformPolicy);
	}
}

void SSwitchableTextBlock::SetJustification(ETextJustify::Type InJustification)
{
	Justification = InJustification;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetJustification(Justification);
	}
	if (EditableText.IsValid())
	{
		EditableText->SetJustification(Justification);
	}
}

void SSwitchableTextBlock::SetTextShapingMethod(const TOptional<ETextShapingMethod>& InTextShapingMethod)
{
	TextShapingMethod = InTextShapingMethod;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetTextShapingMethod(TextShapingMethod);
	}
	if (EditableText.IsValid())
	{
		EditableText->SetTextShapingMethod(TextShapingMethod);
	}
}

void SSwitchableTextBlock::SetTextFlowDirection(const TOptional<ETextFlowDirection>& InTextFlowDirection)
{
	TextFlowDirection = InTextFlowDirection;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetTextFlowDirection(TextFlowDirection);
	}
	if (EditableText.IsValid())
	{
		EditableText->SetTextFlowDirection(TextFlowDirection);
	}
}

void SSwitchableTextBlock::SetIsReadOnly(bool bInIsReadOnly)
{
	bIsReadOnly = bInIsReadOnly;
	if (EditableText.IsValid())
	{
		EditableText->SetIsReadOnly(bIsReadOnly);
	}
}

void SSwitchableTextBlock::HandleEditableTextChanged(const FText& InText)
{
	Text = InText;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetText(Text);
	}
	ExternalOnTextChanged.ExecuteIfBound(InText);
}

void SSwitchableTextBlock::HandleEditableTextCommitted(const FText& InText, ETextCommit::Type InCommitMethod)
{
	Text = InText;
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetText(Text);
	}
	ExternalOnTextCommitted.ExecuteIfBound(InText, InCommitMethod);
}

void SSwitchableTextBlock::SynchronizeDisplayText()
{
	if (DisplayTextBlock.IsValid())
	{
		DisplayTextBlock->SetText(Text);
	}
	if (EditableText.IsValid() && !EditableText->GetText().EqualTo(Text))
	{
		EditableText->SetText(Text);
	}
}
