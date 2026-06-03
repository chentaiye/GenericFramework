// Copyright ChenTaiye 2025. All Rights Reserved.

#include "SWidget/SGenericAnimatedSwitcher.h"

#include "Containers/Ticker.h"
#include "Misc/EngineVersionComparison.h"

SLATE_IMPLEMENT_WIDGET(SGenericAnimatedSwitcher)
void SGenericAnimatedSwitcher::PrivateRegisterAttributes(FSlateAttributeInitializer& AttributeInitializer)
{
}

void SGenericAnimatedSwitcher::Construct(const FArguments& InArgs)
{
	SWidgetSwitcher::Construct(SWidgetSwitcher::FArguments().WidgetIndex(InArgs._InitialIndex));

	SetCanTick(false);
	bTransitioningOut = false;
	PendingActiveWidget = nullptr;
	PendingActiveWidgetIndex = INDEX_NONE;

	TransitionType = InArgs._TransitionType;
	TransitionFallbackStrategy = InArgs._TransitionFallbackStrategy;

	SetTransition(InArgs._TransitionDuration, InArgs._TransitionCurveType);

	OnActiveIndexChanged = InArgs._OnActiveIndexChanged;
	OnIsTransitioningChanged = InArgs._OnIsTransitioningChanged;
}

int32 SGenericAnimatedSwitcher::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const
{
	FWidgetStyle CompoundedWidgetStyle = FWidgetStyle(InWidgetStyle);

	if (TransitionSequence.IsPlaying())
	{
		float Alpha = TransitionSequence.GetLerp();

		if ((bTransitioningOut && !TransitionSequence.IsInReverse()) || (!bTransitioningOut && TransitionSequence.IsInReverse()))
		{
			Alpha = 1.0f - Alpha;
		}

		CompoundedWidgetStyle.BlendColorAndOpacityTint(FLinearColor(1.0f, 1.0f, 1.0f, Alpha));
	}

	return SWidgetSwitcher::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, CompoundedWidgetStyle, bParentEnabled);
}

void SGenericAnimatedSwitcher::TransitionToIndex(const int32 NewWidgetIndex, const bool bInstantTransition)
{
	PendingActiveWidget = GetWidget(NewWidgetIndex);
	if (PendingActiveWidget.IsValid())
	{
		PendingActiveWidgetIndex = NewWidgetIndex;
	}
	else
	{
		PendingActiveWidgetIndex = INDEX_NONE;
		UE_LOG(LogSlate, Verbose, TEXT("Called SGenericAnimatedSwitcher::TransitionToIndex('%d') to an invalid index"), NewWidgetIndex);
		return;
	}

	const int32 CurrentIndex = GetActiveWidgetIndex();
	const bool bNewGoalHigher = NewWidgetIndex > CurrentIndex;
	const bool bNewGoalLower = NewWidgetIndex < CurrentIndex;

	if (bInstantTransition || TransitionSequence.GetCurve(0).DurationSeconds <= 0.0f)
	{
		if (TransitionSequence.IsPlaying() || bNewGoalHigher || bNewGoalLower)
		{
			TransitionSequence.JumpToEnd();
			SetActiveWidgetIndex(NewWidgetIndex);
			OnActiveIndexChanged.ExecuteIfBound(NewWidgetIndex);
		}
	}
	else if (TransitionSequence.IsPlaying())
	{
		const bool bNeedsReverse =
			(TransitionSequence.IsInReverse() && bNewGoalHigher) ||
			(!TransitionSequence.IsInReverse() && bNewGoalLower) ||
			(bTransitioningOut && NewWidgetIndex == CurrentIndex);

		if (bNeedsReverse)
		{
			bTransitioningOut = !bTransitioningOut;
			TransitionSequence.Reverse();

			if (NewWidgetIndex == CurrentIndex)
			{
				OnActiveIndexChanged.ExecuteIfBound(NewWidgetIndex);
			}
		}
	}
	else if (bNewGoalHigher || bNewGoalLower)
	{
		SetVisibility(EVisibility::HitTestInvisible);
		OnIsTransitioningChanged.ExecuteIfBound(true);

		if (bNewGoalHigher)
		{
			TransitionSequence.Play(AsShared());
		}
		else
		{
			TransitionSequence.PlayReverse(AsShared());
		}

		const TSharedPtr<SWidget> CurrentWidget = GetActiveWidget();
		bTransitioningOut = CurrentWidget && CurrentWidget != SNullWidget::NullWidget;

		if (!bTransitioningOut)
		{
			SetActiveWidgetIndex(NewWidgetIndex);
			OnActiveIndexChanged.ExecuteIfBound(NewWidgetIndex);
		}

		if (!bIsTransitionTimerRegistered)
		{
			bIsTransitionTimerRegistered = true;
			RegisterActiveTimer(0.0f, FWidgetActiveTimerDelegate::CreateSP(this, &SGenericAnimatedSwitcher::UpdateTransition));
		}
	}
}

SWidgetSwitcher::FSlot* SGenericAnimatedSwitcher::GetChildSlot(const int32 SlotIndex)
{
	return GetTypedChildren().IsValidIndex(SlotIndex) ? &GetTypedChildren()[SlotIndex] : nullptr;
}

void SGenericAnimatedSwitcher::SetTransition(const float Duration, const EGenericTransitionCurve Curve)
{
	TransitionSequence = FCurveSequence(0.0f, Duration * 0.5f, GenericTransitionCurveToCurveEaseFunction(Curve));
}

void SGenericAnimatedSwitcher::SetTransition(float Duration, EGenericTransitionCurve Curve, EGenericSwitcherTransition NewTransitionType)
{
	SetTransition(Duration, Curve);
	SetTransitionType(NewTransitionType);
}

void SGenericAnimatedSwitcher::SetTransitionType(const EGenericSwitcherTransition NewTransitionType)
{
	TransitionType = NewTransitionType;
}

#if !UE_VERSION_OLDER_THAN(5, 5, 0)
void SGenericAnimatedSwitcher::OnSlotAdded(const int32 AddedIndex)
{
	SWidgetSwitcher::OnSlotAdded(AddedIndex);

	if (PendingActiveWidgetIndex >= 0 && PendingActiveWidgetIndex >= AddedIndex)
	{
		++PendingActiveWidgetIndex;
	}
}

void SGenericAnimatedSwitcher::OnSlotRemoved(const int32 RemovedIndex, TSharedRef<SWidget> RemovedWidget, const bool bWasActiveSlot)
{
	SWidgetSwitcher::OnSlotRemoved(RemovedIndex, RemovedWidget, bWasActiveSlot);

	if (PendingActiveWidgetIndex >= 0)
	{
		if (PendingActiveWidgetIndex == RemovedIndex)
		{
			TryTransitionFallbackOfPendingWidget();
		}
		else if (PendingActiveWidgetIndex < RemovedIndex)
		{
			--PendingActiveWidgetIndex;
		}
	}

	if (bWasActiveSlot && TransitionSequence.IsPlaying())
	{
		if (TransitionSequence.IsForward())
		{
			TransitionSequence.JumpToEnd();
		}
		else
		{
			TransitionSequence.JumpToStart();
		}

		if (!bTransitioningOut)
		{
			TryTransitionFallbackOfActiveWidget(RemovedIndex);
		}
	}
}
#endif

EActiveTimerReturnType SGenericAnimatedSwitcher::UpdateTransition(double InCurrentTime, float InDeltaTime)
{
	if (TransitionType == EGenericSwitcherTransition::Zoom)
	{
		static const float MaxScaleModifier = 0.25f;

		SetRenderTransform(FSlateRenderTransform(1.0f + (MaxScaleModifier * GetTransitionProgress())));
	}
	else if (TransitionType != EGenericSwitcherTransition::FadeOnly)
	{
		static const float MaxTranslation = 200.0f;

		const float Offset = MaxTranslation * GetTransitionProgress();
		FVector2D Translation = FVector2D::ZeroVector;

		if (TransitionType == EGenericSwitcherTransition::Horizontal)
		{
			Translation.X = -Offset;
		}
		else
		{
			Translation.Y = Offset;
		}

		SetRenderTransform(Translation);
	}

	if (!TransitionSequence.IsPlaying())
	{
		TSharedPtr<SWidget> PinnedPendingActiveWidget = PendingActiveWidget.Pin();
		if (bTransitioningOut && (!PinnedPendingActiveWidget.IsValid() || GetWidgetIndex(PinnedPendingActiveWidget.ToSharedRef()) == INDEX_NONE))
		{
			UE_LOG(LogSlate, Verbose, TEXT("SGenericAnimatedSwitcher pending widget was removed or became invalid while a transition was happening"));
			if (TryTransitionFallbackOfPendingWidget())
			{
				PinnedPendingActiveWidget = PendingActiveWidget.Pin();
			}
		}

		if (PinnedPendingActiveWidget.IsValid() && GetActiveWidget().Get() != PinnedPendingActiveWidget.Get())
		{
			const bool bWasTransitioningOut = bTransitioningOut;
			bTransitioningOut = !bTransitioningOut;

			if (bWasTransitioningOut)
			{
				SetActiveWidget(PinnedPendingActiveWidget.ToSharedRef());
				PendingActiveWidget = nullptr;
				PendingActiveWidgetIndex = INDEX_NONE;
				OnActiveIndexChanged.ExecuteIfBound(GetActiveWidgetIndex());
			}

			const TSharedPtr<SWidget> CurrentWidget = GetActiveWidget();
			if (CurrentWidget && CurrentWidget != SNullWidget::NullWidget)
			{
				if (TransitionSequence.IsInReverse())
				{
					TransitionSequence.PlayReverse(AsShared());
				}
				else
				{
					TransitionSequence.Play(AsShared());
				}
			}
		}
		else
		{
			PendingActiveWidget = nullptr;
			PendingActiveWidgetIndex = INDEX_NONE;
		}
	}

	if (!TransitionSequence.IsPlaying())
	{
		SetVisibility(EVisibility::SelfHitTestInvisible);
		OnIsTransitioningChanged.ExecuteIfBound(false);
		bIsTransitionTimerRegistered = false;

		ForceVolatile(true);
		FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateSPLambda(this, [this](float DeltaTime)
		{
			ForceVolatile(false);
			return false;
		}));

		return EActiveTimerReturnType::Stop;
	}

	Invalidate(EInvalidateWidget::Paint);
	return EActiveTimerReturnType::Continue;
}

float SGenericAnimatedSwitcher::GetTransitionProgress() const
{
	float Progress = TransitionSequence.GetLerp();

	if ((bTransitioningOut && TransitionSequence.IsInReverse()) || (!bTransitioningOut && TransitionSequence.IsForward()))
	{
		Progress += -1.0f;
	}

	return Progress;
}

int32 SGenericAnimatedSwitcher::GetTransitionFallbackForIndex(const int32 RemovedWidgetIndex) const
{
	int32 DesiredIndex = 0;
	switch (TransitionFallbackStrategy)
	{
	case EGenericSwitcherTransitionFallbackStrategy::First:
		DesiredIndex = 0;
		break;
	case EGenericSwitcherTransitionFallbackStrategy::Last:
		DesiredIndex = GetNumWidgets() - 1;
		break;
	case EGenericSwitcherTransitionFallbackStrategy::Next:
		DesiredIndex = RemovedWidgetIndex;
		break;
	case EGenericSwitcherTransitionFallbackStrategy::Previous:
	default:
		DesiredIndex = RemovedWidgetIndex - 1;
		break;
	}

	return FMath::Clamp(DesiredIndex, 0, GetNumWidgets() - 1);
}

bool SGenericAnimatedSwitcher::TryTransitionFallbackOfPendingWidget()
{
	if (IsTransitionFallbackEnabled() && GetNumWidgets() > 0)
	{
		const int32 NewPendingWidgetIndex = GetTransitionFallbackForIndex(PendingActiveWidgetIndex);
		PendingActiveWidget = GetWidget(NewPendingWidgetIndex);
		if (PendingActiveWidget.IsValid())
		{
			PendingActiveWidgetIndex = NewPendingWidgetIndex;
			return true;
		}

		PendingActiveWidgetIndex = INDEX_NONE;
		UE_LOG(LogSlate, Verbose, TEXT("SGenericAnimatedSwitcher failed to fall back to another pending widget for the transition"));
	}

	return false;
}

bool SGenericAnimatedSwitcher::TryTransitionFallbackOfActiveWidget(const int32 RemovedWidgetIndex)
{
	if (IsTransitionFallbackEnabled() && GetNumWidgets() > 0)
	{
		const int32 NewActiveWidgetIndex = GetTransitionFallbackForIndex(RemovedWidgetIndex);
		SetActiveWidgetIndex(NewActiveWidgetIndex);
		OnActiveIndexChanged.ExecuteIfBound(GetActiveWidgetIndex());
		return true;
	}

	return false;
}

bool SGenericAnimatedSwitcher::IsTransitionPlaying() const
{
	return TransitionSequence.IsPlaying();
}
