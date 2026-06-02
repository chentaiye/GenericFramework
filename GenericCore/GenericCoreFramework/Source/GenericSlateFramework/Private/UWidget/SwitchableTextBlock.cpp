// Copyright ChenTaiye 2025. All Rights Reserved.

#include "UWidget/SwitchableTextBlock.h"

#include "Engine/Font.h"
#include "SWidget/SSwitchableTextBlock.h"
#include "UObject/ConstructorHelpers.h"

USwitchableTextBlock::USwitchableTextBlock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ColorAndOpacity = FLinearColor::White;
	ShadowOffset = FVector2D::ZeroVector;
	ShadowColorAndOpacity = FLinearColor::Transparent;
	Justification = ETextJustify::Left;

	if (!IsRunningDedicatedServer())
	{
		static ConstructorHelpers::FObjectFinder<UFont> RobotoFontObj(*GetDefaultFontName());
		Font = FSlateFontInfo(RobotoFontObj.Object, 18, FName("Regular"));
	}
}

void USwitchableTextBlock::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetMode(Mode);
		MySwitchableTextBlock->SetText(Text);
		MySwitchableTextBlock->SetHintText(HintText);
		MySwitchableTextBlock->SetFont(Font);
		MySwitchableTextBlock->SetColorAndOpacity(ColorAndOpacity);
		MySwitchableTextBlock->SetShadowOffset(ShadowOffset);
		MySwitchableTextBlock->SetShadowColorAndOpacity(ShadowColorAndOpacity);
		MySwitchableTextBlock->SetStrikeBrush(StrikeBrush);
		MySwitchableTextBlock->SetMinDesiredWidth(MinDesiredWidth);
		MySwitchableTextBlock->SetOverflowPolicy(OverflowPolicy);
		MySwitchableTextBlock->SetTransformPolicy(TransformPolicy);
		MySwitchableTextBlock->SetJustification(Justification);
		MySwitchableTextBlock->SetTextShapingMethod(ShapedTextOptions.bOverride_TextShapingMethod ? TOptional<ETextShapingMethod>(ShapedTextOptions.TextShapingMethod) : TOptional<ETextShapingMethod>());
		MySwitchableTextBlock->SetTextFlowDirection(ShapedTextOptions.bOverride_TextFlowDirection ? TOptional<ETextFlowDirection>(ShapedTextOptions.TextFlowDirection) : TOptional<ETextFlowDirection>());
		MySwitchableTextBlock->SetIsReadOnly(bIsReadOnly);
	}
}

void USwitchableTextBlock::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MySwitchableTextBlock.Reset();
}

FText USwitchableTextBlock::GetText() const
{
	return Text;
}

void USwitchableTextBlock::SetText(FText InText)
{
	Text = InText;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetText(Text);
	}
}

FText USwitchableTextBlock::GetHintText() const
{
	return HintText;
}

void USwitchableTextBlock::SetHintText(FText InHintText)
{
	HintText = InHintText;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetHintText(HintText);
	}
}

ESwitchableTextBlockMode USwitchableTextBlock::GetMode() const
{
	return Mode;
}

void USwitchableTextBlock::SetMode(ESwitchableTextBlockMode InMode)
{
	Mode = InMode;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetMode(Mode);
	}
}

const FSlateFontInfo& USwitchableTextBlock::GetFont() const
{
	return Font;
}

void USwitchableTextBlock::SetFont(FSlateFontInfo InFontInfo)
{
	Font = MoveTemp(InFontInfo);
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetFont(Font);
	}
}

FSlateColor USwitchableTextBlock::GetColorAndOpacity() const
{
	return ColorAndOpacity;
}

void USwitchableTextBlock::SetColorAndOpacity(FSlateColor InColorAndOpacity)
{
	ColorAndOpacity = InColorAndOpacity;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetColorAndOpacity(ColorAndOpacity);
	}
}

FVector2D USwitchableTextBlock::GetShadowOffset() const
{
	return ShadowOffset;
}

void USwitchableTextBlock::SetShadowOffset(FVector2D InShadowOffset)
{
	ShadowOffset = InShadowOffset;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetShadowOffset(ShadowOffset);
	}
}

FLinearColor USwitchableTextBlock::GetShadowColorAndOpacity() const
{
	return ShadowColorAndOpacity;
}

void USwitchableTextBlock::SetShadowColorAndOpacity(FLinearColor InShadowColorAndOpacity)
{
	ShadowColorAndOpacity = InShadowColorAndOpacity;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetShadowColorAndOpacity(ShadowColorAndOpacity);
	}
}

const FSlateBrush& USwitchableTextBlock::GetStrikeBrush() const
{
	return StrikeBrush;
}

void USwitchableTextBlock::SetStrikeBrush(FSlateBrush InStrikeBrush)
{
	StrikeBrush = MoveTemp(InStrikeBrush);
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetStrikeBrush(StrikeBrush);
	}
}

float USwitchableTextBlock::GetMinDesiredWidth() const
{
	return MinDesiredWidth;
}

void USwitchableTextBlock::SetMinDesiredWidth(float InMinDesiredWidth)
{
	MinDesiredWidth = InMinDesiredWidth;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetMinDesiredWidth(MinDesiredWidth);
	}
}

ETextOverflowPolicy USwitchableTextBlock::GetTextOverflowPolicy() const
{
	return OverflowPolicy;
}

void USwitchableTextBlock::SetTextOverflowPolicy(ETextOverflowPolicy InOverflowPolicy)
{
	OverflowPolicy = InOverflowPolicy;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetOverflowPolicy(OverflowPolicy);
	}
}

ETextTransformPolicy USwitchableTextBlock::GetTextTransformPolicy() const
{
	return TransformPolicy;
}

void USwitchableTextBlock::SetTextTransformPolicy(ETextTransformPolicy InTransformPolicy)
{
	TransformPolicy = InTransformPolicy;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetTransformPolicy(TransformPolicy);
	}
}

ETextJustify::Type USwitchableTextBlock::GetJustification() const
{
	return Justification;
}

void USwitchableTextBlock::SetJustification(ETextJustify::Type InJustification)
{
	Justification = InJustification;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetJustification(Justification);
	}
}

bool USwitchableTextBlock::GetIsReadOnly() const
{
	return bIsReadOnly;
}

void USwitchableTextBlock::SetIsReadOnly(bool bInIsReadOnly)
{
	bIsReadOnly = bInIsReadOnly;
	if (MySwitchableTextBlock.IsValid())
	{
		MySwitchableTextBlock->SetIsReadOnly(bIsReadOnly);
	}
}

TSharedRef<SWidget> USwitchableTextBlock::RebuildWidget()
{
	MySwitchableTextBlock = SNew(SSwitchableTextBlock)
		.OnTextChanged(BIND_UOBJECT_DELEGATE(FOnTextChanged, HandleSlateTextChanged))
		.OnTextCommitted(BIND_UOBJECT_DELEGATE(FOnTextCommitted, HandleSlateTextCommitted));
	return MySwitchableTextBlock.ToSharedRef();
}

void USwitchableTextBlock::HandleSlateTextChanged(const FText& InText)
{
	Text = InText;
	OnTextChanged.Broadcast(Text);
}

void USwitchableTextBlock::HandleSlateTextCommitted(const FText& InText, ETextCommit::Type InCommitMethod)
{
	Text = InText;
	OnTextCommitted.Broadcast(Text, InCommitMethod);
}
