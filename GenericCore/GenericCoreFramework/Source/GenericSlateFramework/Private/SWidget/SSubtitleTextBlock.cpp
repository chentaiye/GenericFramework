// Copyright ChenTaiye 2025. All Rights Reserved.

#include "SWidget/SSubtitleTextBlock.h"

#include "Framework/Text/SlateTextLayout.h"
#include "Framework/Text/SlateTextRun.h"
#include "Misc/EngineVersionComparison.h"

SLATE_IMPLEMENT_WIDGET(SSubtitleTextBlock)
void SSubtitleTextBlock::PrivateRegisterAttributes(FSlateAttributeInitializer& AttributeInitializer)
{
}

void SSubtitleTextBlock::Construct(const FArguments& InArgs)
{
	TextLines = InArgs._TextLines;
	Font = InArgs._Font;
	ColorAndOpacity = InArgs._ColorAndOpacity;
	ShadowOffset = InArgs._ShadowOffset;
	ShadowColorAndOpacity = InArgs._ShadowColorAndOpacity;
	MinDesiredWidth = InArgs._MinDesiredWidth;
	TransformPolicy = InArgs._TextTransformPolicy;
	OverflowPolicy = InArgs._TextOverflowPolicy;
	TextShapingMethod = InArgs._TextShapingMethod;
	TextFlowDirection = InArgs._TextFlowDirection;
	bAutoWrapText = InArgs._AutoWrapText;
	WrapTextAt = InArgs._WrapTextAt;
	WrappingPolicy = InArgs._WrappingPolicy;
	Margin = InArgs._Margin;
	LineHeightPercentage = InArgs._LineHeightPercentage;
	bApplyLineHeightToBottomLine = InArgs._ApplyLineHeightToBottomLine;
	Justification = InArgs._Justification;
	TailVisibleLineCount = InArgs._TailVisibleLineCount;
	MaxDisplayHeight = InArgs._MaxDisplayHeight;
	GradientLineCount = InArgs._GradientLineCount;
	LineOpacityStep = InArgs._LineOpacityStep;

	SetCanTick(false);
	bCanSupportFocus = false;
}

void SSubtitleTextBlock::SetTextLines(const TArray<FText>& InTextLines)
{
	TextLines = InTextLines;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetFont(const FSlateFontInfo& InFont)
{
	Font = InFont;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetColorAndOpacity(const FSlateColor& InColorAndOpacity)
{
	ColorAndOpacity = InColorAndOpacity;
	InvalidateSubtitle(EInvalidateWidgetReason::Paint);
}

void SSubtitleTextBlock::SetShadowOffset(FVector2D InShadowOffset)
{
	ShadowOffset = InShadowOffset;
	InvalidateSubtitle(EInvalidateWidgetReason::Paint);
}

void SSubtitleTextBlock::SetShadowColorAndOpacity(FLinearColor InShadowColorAndOpacity)
{
	ShadowColorAndOpacity = InShadowColorAndOpacity;
	InvalidateSubtitle(EInvalidateWidgetReason::Paint);
}

void SSubtitleTextBlock::SetMinDesiredWidth(float InMinDesiredWidth)
{
	MinDesiredWidth = InMinDesiredWidth;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetTransformPolicy(ETextTransformPolicy InTransformPolicy)
{
	TransformPolicy = InTransformPolicy;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetOverflowPolicy(ETextOverflowPolicy InOverflowPolicy)
{
	OverflowPolicy = InOverflowPolicy;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetTextShapingMethod(const TOptional<ETextShapingMethod>& InTextShapingMethod)
{
	TextShapingMethod = InTextShapingMethod;
	ResetLayouts();
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetTextFlowDirection(const TOptional<ETextFlowDirection>& InTextFlowDirection)
{
	TextFlowDirection = InTextFlowDirection;
	ResetLayouts();
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetAutoWrapText(bool bInAutoWrapText)
{
	bAutoWrapText = bInAutoWrapText;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetWrapTextAt(float InWrapTextAt)
{
	WrapTextAt = InWrapTextAt;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetWrapTextAt(const TAttribute<float>& InWrapTextAt)
{
	SetWrapTextAt(InWrapTextAt.Get(0.0f));
}

void SSubtitleTextBlock::SetWrappingPolicy(ETextWrappingPolicy InWrappingPolicy)
{
	WrappingPolicy = InWrappingPolicy;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetMargin(const FMargin& InMargin)
{
	Margin = InMargin;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetLineHeightPercentage(float InLineHeightPercentage)
{
	LineHeightPercentage = InLineHeightPercentage;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetApplyLineHeightToBottomLine(bool bInApplyLineHeightToBottomLine)
{
	bApplyLineHeightToBottomLine = bInApplyLineHeightToBottomLine;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetJustification(ETextJustify::Type InJustification)
{
	Justification = InJustification;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetTailVisibleLineCount(int32 InTailVisibleLineCount)
{
	TailVisibleLineCount = InTailVisibleLineCount;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetMaxDisplayHeight(float InMaxDisplayHeight)
{
	MaxDisplayHeight = InMaxDisplayHeight;
	InvalidateSubtitle(EInvalidateWidgetReason::Layout);
}

void SSubtitleTextBlock::SetGradientLineCount(int32 InGradientLineCount)
{
	GradientLineCount = InGradientLineCount;
	InvalidateSubtitle(EInvalidateWidgetReason::Paint);
}

void SSubtitleTextBlock::SetLineOpacityStep(float InLineOpacityStep)
{
	LineOpacityStep = InLineOpacityStep;
	InvalidateSubtitle(EInvalidateWidgetReason::Paint);
}

FVector2D SSubtitleTextBlock::ComputeDesiredSize(float LayoutScaleMultiplier) const
{
	UpdateLayouts(LayoutScaleMultiplier);
	return FVector2D(FMath::Max(MinDesiredWidth, CachedDesiredSize.X), CachedDesiredSize.Y);
}

int32 SSubtitleTextBlock::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	const FVector2D LastDesiredSize = CachedDesiredSize;
	CachedSize = FVector2f(AllottedGeometry.GetLocalSize());

	UpdateLayouts(AllottedGeometry.Scale);

	if (DisplayTextLayout.IsValid())
	{
		DisplayTextLayout->SetVisibleRegion(AllottedGeometry.GetLocalSize(), FVector2D::ZeroVector);
		DisplayTextLayout->UpdateIfNeeded();
		LayerId = DisplayTextLayout->OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle, bParentEnabled);
	}

	const bool bCanWrap = WrapTextAt > 0.0f || bAutoWrapText;
	if (bCanWrap && !CachedDesiredSize.Equals(LastDesiredSize))
	{
		const_cast<SSubtitleTextBlock*>(this)->Invalidate(EInvalidateWidgetReason::Layout);
	}

	return LayerId;
}

void SSubtitleTextBlock::InvalidateSubtitle(EInvalidateWidgetReason InvalidationReason)
{
	Invalidate(InvalidationReason);
}

void SSubtitleTextBlock::ResetLayouts() const
{
	SourceTextLayout.Reset();
	DisplayTextLayout.Reset();
}

float SSubtitleTextBlock::CalculateWrappingWidth() const
{
	float WrappingWidth = WrapTextAt;
	if (bAutoWrapText && CachedSize.X >= 1.0f)
	{
		WrappingWidth = WrappingWidth >= 1.0f ? FMath::Min(WrappingWidth, CachedSize.X) : CachedSize.X;
	}

	return FMath::Max(0.0f, WrappingWidth);
}

FTextBlockStyle SSubtitleTextBlock::BuildLineStyle(float InLineAlpha) const
{
	const FLinearColor BaseTextColor = ColorAndOpacity.GetSpecifiedColor();
	const FLinearColor BaseShadowColor = ShadowColorAndOpacity;
	const float BaseTextAlpha = FMath::Clamp(BaseTextColor.A, 0.0f, 1.0f);
	const float FinalTextAlpha = FMath::Clamp(InLineAlpha, 0.0f, 1.0f);
	const float AlphaScale = BaseTextAlpha > UE_SMALL_NUMBER ? (FinalTextAlpha / BaseTextAlpha) : 0.0f;

	FTextBlockStyle Style = FTextBlockStyle::GetDefault();
	Style.SetFont(Font);
	Style.SetColorAndOpacity(FSlateColor(FLinearColor(BaseTextColor.R, BaseTextColor.G, BaseTextColor.B, FinalTextAlpha)));
	Style.SetShadowOffset(ShadowOffset);
	Style.SetShadowColorAndOpacity(FLinearColor(BaseShadowColor.R, BaseShadowColor.G, BaseShadowColor.B, FMath::Clamp(BaseShadowColor.A * AlphaScale, 0.0f, 1.0f)));
	Style.SetOverflowPolicy(OverflowPolicy);
	return Style;
}

FString SSubtitleTextBlock::TransformString(const FString& InSource) const
{
	FString Result = InSource;
	if (TransformPolicy == ETextTransformPolicy::ToLower)
	{
		Result.ToLowerInline();
	}
	else if (TransformPolicy == ETextTransformPolicy::ToUpper)
	{
		Result.ToUpperInline();
	}
	return Result;
}

void SSubtitleTextBlock::ApplyCommonLayoutSettings(FSlateTextLayout& InLayout, float LayoutScaleMultiplier, float WrappingWidth, ETextOverflowPolicy InOverflowPolicy) const
{
	InLayout.SetScale(LayoutScaleMultiplier);
	InLayout.SetWrappingWidth(WrappingWidth);
	InLayout.SetWrappingPolicy(WrappingPolicy);
	InLayout.SetMargin(Margin);
	InLayout.SetJustification(Justification);
	InLayout.SetLineHeightPercentage(LineHeightPercentage);
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
	InLayout.SetApplyLineHeightToBottomLine(bApplyLineHeightToBottomLine);
#endif
	InLayout.SetTextOverflowPolicy(InOverflowPolicy);
	if (TextShapingMethod.IsSet())
	{
		InLayout.SetTextShapingMethod(TextShapingMethod.GetValue());
	}
	if (TextFlowDirection.IsSet())
	{
		InLayout.SetTextFlowDirection(TextFlowDirection.GetValue());
	}
}

void SSubtitleTextBlock::UpdateLayouts(float LayoutScaleMultiplier) const
{
	if (!SourceTextLayout.IsValid())
	{
		SourceTextLayout = FSlateTextLayout::Create(const_cast<SSubtitleTextBlock*>(this), BuildLineStyle(1.0f));
	}

	if (!DisplayTextLayout.IsValid())
	{
		DisplayTextLayout = FSlateTextLayout::Create(const_cast<SSubtitleTextBlock*>(this), BuildLineStyle(1.0f));
	}

	const float WrappingWidth = CalculateWrappingWidth();

	SourceTextLayout->ClearLines();
	ApplyCommonLayoutSettings(*SourceTextLayout, LayoutScaleMultiplier, WrappingWidth, ETextOverflowPolicy::Clip);
	for (const FText& TextLine : TextLines)
	{
		TSharedRef<FString> LineText = MakeShared<FString>(TransformString(TextLine.ToString()));
		TArray<TSharedRef<IRun>> Runs;
		Runs.Add(FSlateTextRun::Create(FRunInfo(), LineText, BuildLineStyle(1.0f), FTextRange(0, LineText->Len())));
		SourceTextLayout->AddLine(FTextLayout::FNewLineData(LineText, MoveTemp(Runs)));
	}
	SourceTextLayout->UpdateIfNeeded();

	DisplayTextLayout->ClearLines();
	ApplyCommonLayoutSettings(*DisplayTextLayout, LayoutScaleMultiplier, 0.0f, OverflowPolicy);

	const TArray<FTextLayout::FLineView>& SourceLineViews = SourceTextLayout->GetLineViews();
	const TArray<FTextLayout::FLineModel>& SourceLineModels = SourceTextLayout->GetLineModels();
	if (SourceLineViews.Num() == 0)
	{
		DisplayTextLayout->UpdateIfNeeded();
		CachedDesiredSize = FVector2D(FMath::Max(MinDesiredWidth, 0.0f), 0.0f);
		return;
	}

	int32 StartLineIndex = 0;
	if (TailVisibleLineCount > 0)
	{
		StartLineIndex = FMath::Max(0, SourceLineViews.Num() - TailVisibleLineCount);
	}

	if (MaxDisplayHeight > 0.0f)
	{
		float AccumulatedHeight = 0.0f;
		int32 HeightStartIndex = SourceLineViews.Num() - 1;
		for (; HeightStartIndex >= StartLineIndex; --HeightStartIndex)
		{
			const float CandidateHeight = AccumulatedHeight + SourceLineViews[HeightStartIndex].Size.Y;
			if (AccumulatedHeight > 0.0f && CandidateHeight > MaxDisplayHeight)
			{
				break;
			}

			AccumulatedHeight = CandidateHeight;
		}

		StartLineIndex = FMath::Max(StartLineIndex, HeightStartIndex + 1);
	}

	for (int32 VisibleLineIndex = StartLineIndex; VisibleLineIndex < SourceLineViews.Num(); ++VisibleLineIndex)
	{
		const FTextLayout::FLineView& LineView = SourceLineViews[VisibleLineIndex];
		const FString& SourceLineText = *SourceLineModels[LineView.ModelIndex].Text;
		const FString DisplayLineText = SourceLineText.Mid(LineView.Range.BeginIndex, LineView.Range.Len());
		TSharedRef<FString> LineText = MakeShared<FString>(DisplayLineText);

		const int32 DistanceFromBottom = (SourceLineViews.Num() - 1) - VisibleLineIndex;
		const float BaseLineAlpha = FMath::Clamp(ColorAndOpacity.GetSpecifiedColor().A, 0.0f, 1.0f);
		float LineAlpha = BaseLineAlpha;
		if (GradientLineCount > 0)
		{
			const int32 GradientStep = FMath::Min(DistanceFromBottom, GradientLineCount - 1);
			LineAlpha = FMath::Clamp(BaseLineAlpha - (LineOpacityStep * GradientStep), 0.0f, 1.0f);
		}

		TArray<TSharedRef<IRun>> Runs;
		Runs.Add(FSlateTextRun::Create(FRunInfo(), LineText, BuildLineStyle(LineAlpha), FTextRange(0, LineText->Len())));
		DisplayTextLayout->AddLine(FTextLayout::FNewLineData(LineText, MoveTemp(Runs)));
	}

	DisplayTextLayout->UpdateIfNeeded();
	CachedDesiredSize = DisplayTextLayout->GetWrappedSize();
	CachedDesiredSize.X = FMath::Max(MinDesiredWidth, CachedDesiredSize.X);
}
