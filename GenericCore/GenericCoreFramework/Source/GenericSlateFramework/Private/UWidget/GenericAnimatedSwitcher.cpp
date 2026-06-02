// Copyright ChenTaiye 2025. All Rights Reserved.

#include "UWidget/GenericAnimatedSwitcher.h"

#include "Components/WidgetSwitcherSlot.h"
#include "Widgets/Layout/SSpacer.h"
#include "Widgets/SOverlay.h"

UGenericAnimatedSwitcher::UGenericAnimatedSwitcher(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, TransitionType(EGenericSwitcherTransition::FadeOnly)
	, TransitionCurveType(EGenericTransitionCurve::CubicInOut)
	, TransitionDuration(0.4f)
{
}

void UGenericAnimatedSwitcher::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	bSetOnce = false;

	MyOverlay.Reset();
	MyInputGuard.Reset();
	MyAnimatedSwitcher.Reset();
}

void UGenericAnimatedSwitcher::SetActiveWidgetIndex(int32 Index)
{
	SetActiveWidgetIndex_Internal(Index);
}

void UGenericAnimatedSwitcher::SetActiveWidget(UWidget* Widget)
{
	SetActiveWidgetIndex_Internal(GetChildIndex(Widget));
}

PRAGMA_DISABLE_DEPRECATION_WARNINGS
void UGenericAnimatedSwitcher::ActivateNextWidget(bool bCanWrap)
{
	if (Slots.Num() <= 1)
	{
		return;
	}

	const int32 CurrentIndex = GetActiveWidgetIndex();
	if (CurrentIndex == Slots.Num() - 1)
	{
		if (bCanWrap)
		{
			SetActiveWidgetIndex(0);
		}
	}
	else
	{
		SetActiveWidgetIndex(CurrentIndex + 1);
	}
}

void UGenericAnimatedSwitcher::ActivatePreviousWidget(bool bCanWrap)
{
	if (Slots.Num() <= 1)
	{
		return;
	}

	const int32 CurrentIndex = GetActiveWidgetIndex();
	if (CurrentIndex == 0)
	{
		if (bCanWrap)
		{
			SetActiveWidgetIndex(Slots.Num() - 1);
		}
	}
	else
	{
		SetActiveWidgetIndex(CurrentIndex - 1);
	}
}

bool UGenericAnimatedSwitcher::HasWidgets() const
{
	return Slots.Num() > 0;
}

void UGenericAnimatedSwitcher::SetDisableTransitionAnimation(bool bDisableAnimation)
{
	bInstantTransition = bDisableAnimation;
}

bool UGenericAnimatedSwitcher::IsCurrentlySwitching() const
{
	return bCurrentlySwitching;
}
PRAGMA_ENABLE_DEPRECATION_WARNINGS

bool UGenericAnimatedSwitcher::IsTransitionPlaying() const
{
	return MyAnimatedSwitcher.IsValid() ? MyAnimatedSwitcher->IsTransitionPlaying() : false;
}

UWidget* UGenericAnimatedSwitcher::GetPendingActiveWidget() const
{
	const int32 PendingIndex = GetPendingActiveWidgetIndex();
	return PendingIndex >= 0 ? GetWidgetAtIndex(PendingIndex) : nullptr;
}

int32 UGenericAnimatedSwitcher::GetPendingActiveWidgetIndex() const
{
	return MyAnimatedSwitcher.IsValid() ? MyAnimatedSwitcher->GetPendingActiveWidgetIndex() : INDEX_NONE;
}

void UGenericAnimatedSwitcher::HandleSlateActiveIndexChanged(int32 ActiveIndex)
{
	if (Slots.IsValidIndex(ActiveIndex))
	{
		UWidget* ActiveWidget = GetWidgetAtIndex(ActiveIndex);
		OnActiveWidgetIndexChanged.Broadcast(ActiveWidget, ActiveIndex);
		OnActiveWidgetIndexChangedBP.Broadcast(ActiveWidget, ActiveIndex);
		OnActiveIndexChangedFinish.Broadcast(ActiveWidget, ActiveIndex);
	}
}

void UGenericAnimatedSwitcher::HandleSlateIsTransitioningChanged(bool bIsTransitioning)
{
	if (MyInputGuard.IsValid())
	{
		MyInputGuard->SetVisibility(bIsTransitioning ? EVisibility::Visible : EVisibility::Collapsed);
	}

	OnTransitioningChanged.Broadcast(bIsTransitioning);
}

TSharedRef<SWidget> UGenericAnimatedSwitcher::RebuildWidget()
{
PRAGMA_DISABLE_DEPRECATION_WARNINGS
	MyWidgetSwitcher = MyAnimatedSwitcher = SNew(SGenericAnimatedSwitcher)
		.InitialIndex(GetActiveWidgetIndex())
		.TransitionCurveType(TransitionCurveType)
		.TransitionDuration(TransitionDuration)
		.TransitionType(TransitionType)
		.TransitionFallbackStrategy(TransitionFallbackStrategy)
		.OnActiveIndexChanged_UObject(this, &UGenericAnimatedSwitcher::HandleSlateActiveIndexChanged)
		.OnIsTransitioningChanged_UObject(this, &UGenericAnimatedSwitcher::HandleSlateIsTransitioningChanged);
PRAGMA_ENABLE_DEPRECATION_WARNINGS

	for (UPanelSlot* CurrentSlot : Slots)
	{
		if (UWidgetSwitcherSlot* TypedSlot = Cast<UWidgetSwitcherSlot>(CurrentSlot))
		{
			TypedSlot->Parent = this;
			TypedSlot->BuildSlot(MyWidgetSwitcher.ToSharedRef());
		}
	}

	return SAssignNew(MyOverlay, SOverlay)
		+ SOverlay::Slot()
		[
			MyAnimatedSwitcher.ToSharedRef()
		]
		+ SOverlay::Slot()
		[
			SAssignNew(MyInputGuard, SSpacer)
			.Visibility(EVisibility::Collapsed)
		];
}

void UGenericAnimatedSwitcher::SetActiveWidgetIndex_Internal(int32 Index)
{
#if WITH_EDITOR
	if (IsDesignTime())
	{
		Super::SetActiveWidgetIndex(Index);
		return;
	}
#endif

	TGuardValue<bool> SwitchingGuard(bCurrentlySwitching, true);

PRAGMA_DISABLE_DEPRECATION_WARNINGS
	const int32 CurrentIndex = GetActiveWidgetIndex();
	if (Index >= 0 && Index < Slots.Num() && (Index != CurrentIndex || !bSetOnce))
	{
		HandleOutgoingWidget();

		const bool bIsSettingInitialIndex = !bSetOnce && (!MyAnimatedSwitcher.IsValid() || Index == MyAnimatedSwitcher->GetActiveWidgetIndex());
		if (CurrentIndex != Index)
		{
			ActiveWidgetIndex = Index;
			BroadcastFieldValueChanged(FFieldNotificationClassDescriptor::ActiveWidgetIndex);
		}

		if (MyAnimatedSwitcher.IsValid())
		{
			const int32 SafeIndex = FMath::Clamp(GetActiveWidgetIndex(), 0, FMath::Max(0, Slots.Num() - 1));
			MyAnimatedSwitcher->TransitionToIndex(SafeIndex, bInstantTransition);
		}

		if (bIsSettingInitialIndex)
		{
			HandleSlateActiveIndexChanged(GetActiveWidgetIndex());
		}

		bSetOnce = true;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
}
