// Copyright ChenTaiye 2025. All Rights Reserved.

#include "UWidget/SubtitleTextBlock.h"

#include "Engine/Font.h"
#include "Misc/EngineVersionComparison.h"
#include "SWidget/SSubtitleTextBlock.h"
#include "UObject/ConstructorHelpers.h"

USubtitleTextBlock::USubtitleTextBlock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ColorAndOpacity = FLinearColor::White;
	ShadowOffset = FVector2D(1.0f, 1.0f);
	ShadowColorAndOpacity = FLinearColor(0.0f, 0.0f, 0.0f, 0.75f);
	WrappingPolicy = ETextWrappingPolicy::DefaultWrapping;
	AutoWrapText = true;
#if !UE_VERSION_OLDER_THAN(5, 5, 0)
	ApplyLineHeightToBottomLine = true;
#endif
	WrapTextAt = 0.0f;
	Margin = FMargin(0.0f);
	LineHeightPercentage = 1.0f;
	Justification = ETextJustify::Center;

	if (!IsRunningDedicatedServer())
	{
		static ConstructorHelpers::FObjectFinder<UFont> RobotoFontObj(*GetDefaultFontName());
		Font = FSlateFontInfo(RobotoFontObj.Object, 18, FName("Regular"));
	}

	ParseTextIntoStoredLines(Text, DefaultLineLifetimeSeconds);
}

void USubtitleTextBlock::BeginDestroy()
{
	StopExpirationTicker();
	Super::BeginDestroy();
}

void USubtitleTextBlock::SynchronizeProperties()
{
	Super::SynchronizeProperties();
	if (StoredLines.IsEmpty() && !Text.IsEmpty())
	{
		ParseTextIntoStoredLines(Text, DefaultLineLifetimeSeconds);
	}
	PushLinesToSlate();

	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetFont(Font);
		MySubtitleTextBlock->SetColorAndOpacity(ColorAndOpacity);
		MySubtitleTextBlock->SetShadowOffset(ShadowOffset);
		MySubtitleTextBlock->SetShadowColorAndOpacity(ShadowColorAndOpacity);
		MySubtitleTextBlock->SetMinDesiredWidth(MinDesiredWidth);
		MySubtitleTextBlock->SetTransformPolicy(TextTransformPolicy);
		MySubtitleTextBlock->SetOverflowPolicy(TextOverflowPolicy);
		MySubtitleTextBlock->SetTailVisibleLineCount(TailVisibleLineCount);
		MySubtitleTextBlock->SetMaxDisplayHeight(MaxDisplayHeight);
		MySubtitleTextBlock->SetGradientLineCount(GradientLineCount);
		MySubtitleTextBlock->SetLineOpacityStep(LineOpacityStep);
		Super::SynchronizeTextLayoutProperties(*MySubtitleTextBlock);
	}

	RefreshExpirationTicker();
}

void USubtitleTextBlock::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);
	MySubtitleTextBlock.Reset();
}

FText USubtitleTextBlock::GetText() const
{
	return Text;
}

void USubtitleTextBlock::SetText(FText InText)
{
	ParseTextIntoStoredLines(InText, DefaultLineLifetimeSeconds);
	EnforceMaxStoredLines();
	RebuildTextProperty();
	PushLinesToSlate();
	RefreshExpirationTicker();
}

TArray<FText> USubtitleTextBlock::GetLines()
{
	if (PruneExpiredLines())
	{
		RebuildTextProperty();
		RefreshExpirationTicker();
	}

	TArray<FText> Result;
	Result.Reserve(StoredLines.Num());
	for (const FStoredSubtitleLine& StoredLine : StoredLines)
	{
		Result.Add(StoredLine.Text);
	}
	return Result;
}

void USubtitleTextBlock::SetLines(const TArray<FText>& InLines)
{
	StoredLines.Reset();
	for (const FText& Line : InLines)
	{
		AppendLineInternal(Line, DefaultLineLifetimeSeconds, false);
	}

	EnforceMaxStoredLines();
	RebuildTextProperty();
	PushLinesToSlate();
	RefreshExpirationTicker();
}

void USubtitleTextBlock::AppendLines(const TArray<FText>& InLines)
{
	for (const FText& Line : InLines)
	{
		AppendLineInternal(Line, DefaultLineLifetimeSeconds, true);
	}

	EnforceMaxStoredLines();
	RebuildTextProperty();
	PushLinesToSlate();
	RefreshExpirationTicker();
}

void USubtitleTextBlock::ClearLines()
{
	StoredLines.Reset();
	RebuildTextProperty();
	PushLinesToSlate();
	RefreshExpirationTicker();
}

void USubtitleTextBlock::AddText(FText InText)
{
	AppendLineInternal(InText, DefaultLineLifetimeSeconds, true);
	EnforceMaxStoredLines();
	RebuildTextProperty();
	PushLinesToSlate();
	RefreshExpirationTicker();
}

void USubtitleTextBlock::AddTextWithLifetime(FText InText, float InLifetimeSeconds)
{
	AppendLineInternal(InText, InLifetimeSeconds, true);
	EnforceMaxStoredLines();
	RebuildTextProperty();
	PushLinesToSlate();
	RefreshExpirationTicker();
}

const FSlateFontInfo& USubtitleTextBlock::GetFont() const
{
	return Font;
}

void USubtitleTextBlock::SetFont(FSlateFontInfo InFont)
{
	Font = MoveTemp(InFont);
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetFont(Font);
	}
}

FSlateColor USubtitleTextBlock::GetColorAndOpacity() const
{
	return ColorAndOpacity;
}

void USubtitleTextBlock::SetColorAndOpacity(FSlateColor InColorAndOpacity)
{
	ColorAndOpacity = InColorAndOpacity;
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetColorAndOpacity(ColorAndOpacity);
	}
}

FVector2D USubtitleTextBlock::GetShadowOffset() const
{
	return ShadowOffset;
}

void USubtitleTextBlock::SetShadowOffset(FVector2D InShadowOffset)
{
	ShadowOffset = InShadowOffset;
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetShadowOffset(ShadowOffset);
	}
}

FLinearColor USubtitleTextBlock::GetShadowColorAndOpacity() const
{
	return ShadowColorAndOpacity;
}

void USubtitleTextBlock::SetShadowColorAndOpacity(FLinearColor InShadowColorAndOpacity)
{
	ShadowColorAndOpacity = InShadowColorAndOpacity;
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetShadowColorAndOpacity(ShadowColorAndOpacity);
	}
}

float USubtitleTextBlock::GetMinDesiredWidth() const
{
	return MinDesiredWidth;
}

void USubtitleTextBlock::SetMinDesiredWidth(float InMinDesiredWidth)
{
	MinDesiredWidth = InMinDesiredWidth;
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetMinDesiredWidth(MinDesiredWidth);
	}
}

ETextTransformPolicy USubtitleTextBlock::GetTextTransformPolicy() const
{
	return TextTransformPolicy;
}

void USubtitleTextBlock::SetTextTransformPolicy(ETextTransformPolicy InTransformPolicy)
{
	TextTransformPolicy = InTransformPolicy;
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetTransformPolicy(TextTransformPolicy);
	}
}

ETextOverflowPolicy USubtitleTextBlock::GetTextOverflowPolicy() const
{
	return TextOverflowPolicy;
}

void USubtitleTextBlock::SetTextOverflowPolicy(ETextOverflowPolicy InOverflowPolicy)
{
	TextOverflowPolicy = InOverflowPolicy;
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetOverflowPolicy(TextOverflowPolicy);
	}
}

void USubtitleTextBlock::SetTailVisibleLineCount(int32 InTailVisibleLineCount)
{
	TailVisibleLineCount = InTailVisibleLineCount;
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetTailVisibleLineCount(TailVisibleLineCount);
	}
}

void USubtitleTextBlock::SetMaxDisplayHeight(float InMaxDisplayHeight)
{
	MaxDisplayHeight = InMaxDisplayHeight;
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetMaxDisplayHeight(MaxDisplayHeight);
	}
}

void USubtitleTextBlock::SetGradientLineCount(int32 InGradientLineCount)
{
	GradientLineCount = InGradientLineCount;
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetGradientLineCount(GradientLineCount);
	}
}

void USubtitleTextBlock::SetLineOpacityStep(float InLineOpacityStep)
{
	LineOpacityStep = InLineOpacityStep;
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetLineOpacityStep(LineOpacityStep);
	}
}

void USubtitleTextBlock::SetMaxStoredLines(int32 InMaxStoredLines)
{
	MaxStoredLines = InMaxStoredLines;
	EnforceMaxStoredLines();
	RebuildTextProperty();
	PushLinesToSlate();
}

void USubtitleTextBlock::SetDefaultLineLifetimeSeconds(float InDefaultLineLifetimeSeconds)
{
	DefaultLineLifetimeSeconds = InDefaultLineLifetimeSeconds;
	RefreshExpirationTicker();
}

void USubtitleTextBlock::SetPauseExpiration(bool bInPauseExpiration)
{
	bPauseExpiration = bInPauseExpiration;
	RefreshExpirationTicker();
}

TSharedRef<SWidget> USubtitleTextBlock::RebuildWidget()
{
	MySubtitleTextBlock = SNew(SSubtitleTextBlock);
	return MySubtitleTextBlock.ToSharedRef();
}

#if !UE_VERSION_OLDER_THAN(5, 5, 0)
void USubtitleTextBlock::OnShapedTextOptionsChanged(FShapedTextOptions InShapedTextOptions)
{
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetTextShapingMethod(InShapedTextOptions.bOverride_TextShapingMethod ? TOptional<ETextShapingMethod>(InShapedTextOptions.TextShapingMethod) : TOptional<ETextShapingMethod>());
		MySubtitleTextBlock->SetTextFlowDirection(InShapedTextOptions.bOverride_TextFlowDirection ? TOptional<ETextFlowDirection>(InShapedTextOptions.TextFlowDirection) : TOptional<ETextFlowDirection>());
	}
}

void USubtitleTextBlock::OnJustificationChanged(ETextJustify::Type InJustification)
{
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetJustification(InJustification);
	}
}

void USubtitleTextBlock::OnWrappingPolicyChanged(ETextWrappingPolicy InWrappingPolicy)
{
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetWrappingPolicy(InWrappingPolicy);
	}
}

void USubtitleTextBlock::OnAutoWrapTextChanged(bool InAutoWrapText)
{
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetAutoWrapText(InAutoWrapText);
	}
}

void USubtitleTextBlock::OnWrapTextAtChanged(float InWrapTextAt)
{
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetWrapTextAt(InWrapTextAt);
	}
}

void USubtitleTextBlock::OnLineHeightPercentageChanged(float InLineHeightPercentage)
{
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetLineHeightPercentage(InLineHeightPercentage);
	}
}

void USubtitleTextBlock::OnApplyLineHeightToBottomLineChanged(bool InApplyLineHeightToBottomLine)
{
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetApplyLineHeightToBottomLine(InApplyLineHeightToBottomLine);
	}
}

void USubtitleTextBlock::OnMarginChanged(const FMargin& InMargin)
{
	if (MySubtitleTextBlock.IsValid())
	{
		MySubtitleTextBlock->SetMargin(InMargin);
	}
}
#endif

void USubtitleTextBlock::ParseTextIntoStoredLines(const FText& InText, float InLifetimeSeconds)
{
	StoredLines.Reset();

	TArray<FString> ParsedLines;
	InText.ToString().ParseIntoArrayLines(ParsedLines);
	if (ParsedLines.Num() == 0 && !InText.IsEmpty())
	{
		ParsedLines.Add(InText.ToString());
	}

	for (const FString& ParsedLine : ParsedLines)
	{
		AppendLineInternal(FText::FromString(ParsedLine), InLifetimeSeconds, false);
	}

	Text = InText;
}

void USubtitleTextBlock::AppendLineInternal(const FText& InText, float InLifetimeSeconds, bool bBroadcastEvent)
{
	FStoredSubtitleLine& NewLine = StoredLines.AddDefaulted_GetRef();
	NewLine.Text = InText;
	NewLine.AddedAtSeconds = GetNowSeconds();
	NewLine.LifetimeSeconds = FMath::Max(0.0f, InLifetimeSeconds);

	if (bBroadcastEvent)
	{
		OnLineAdded.Broadcast(InText);
	}
}

void USubtitleTextBlock::EnforceMaxStoredLines()
{
	if (MaxStoredLines > 0 && StoredLines.Num() > MaxStoredLines)
	{
		StoredLines.RemoveAt(0, StoredLines.Num() - MaxStoredLines);
	}
}

void USubtitleTextBlock::RebuildTextProperty()
{
	FString CombinedText;
	for (int32 LineIndex = 0; LineIndex < StoredLines.Num(); ++LineIndex)
	{
		if (LineIndex > 0)
		{
			CombinedText.AppendChar(TEXT('\n'));
		}

		CombinedText += StoredLines[LineIndex].Text.ToString();
	}

	Text = FText::FromString(CombinedText);
}

void USubtitleTextBlock::PushLinesToSlate()
{
	if (PruneExpiredLines())
	{
		RebuildTextProperty();
		RefreshExpirationTicker();
	}

	if (MySubtitleTextBlock.IsValid())
	{
		TArray<FText> CurrentLines;
		CurrentLines.Reserve(StoredLines.Num());
		for (const FStoredSubtitleLine& StoredLine : StoredLines)
		{
			CurrentLines.Add(StoredLine.Text);
		}

		MySubtitleTextBlock->SetTextLines(CurrentLines);
	}
}

void USubtitleTextBlock::RefreshExpirationTicker()
{
	StopExpirationTicker();

	if (bPauseExpiration)
	{
		return;
	}

	for (const FStoredSubtitleLine& StoredLine : StoredLines)
	{
		if (StoredLine.LifetimeSeconds > 0.0f)
		{
			ExpirationTickerHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &USubtitleTextBlock::HandleExpirationTicker), 0.1f);
			break;
		}
	}
}

void USubtitleTextBlock::StopExpirationTicker()
{
	if (ExpirationTickerHandle.IsValid())
	{
		FTSTicker::GetCoreTicker().RemoveTicker(ExpirationTickerHandle);
		ExpirationTickerHandle.Reset();
	}
}

bool USubtitleTextBlock::HandleExpirationTicker(float DeltaTime)
{
	if (bPauseExpiration)
	{
		return false;
	}

	const bool bRemovedAnyLine = PruneExpiredLines();
	if (bRemovedAnyLine)
	{
		RebuildTextProperty();
		PushLinesToSlate();
	}

	for (const FStoredSubtitleLine& StoredLine : StoredLines)
	{
		if (StoredLine.LifetimeSeconds > 0.0f)
		{
			return true;
		}
	}

	ExpirationTickerHandle.Reset();
	return false;
}

bool USubtitleTextBlock::PruneExpiredLines()
{
	if (bPauseExpiration)
	{
		return false;
	}

	const double NowSeconds = GetNowSeconds();
	const int32 PreviousNum = StoredLines.Num();
	StoredLines.RemoveAll([NowSeconds](const FStoredSubtitleLine& StoredLine)
		{
			return StoredLine.LifetimeSeconds > 0.0f && (StoredLine.AddedAtSeconds + StoredLine.LifetimeSeconds) <= NowSeconds;
		}
	);
	return StoredLines.Num() != PreviousNum;
}

double USubtitleTextBlock::GetNowSeconds() const
{
	return FPlatformTime::Seconds();
}
