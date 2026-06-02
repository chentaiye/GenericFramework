// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Slate/GameplayTagSlot.h"

#include "Subsystem/GenericSlotSubsystem.h"
#include "WidgetType.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

#if WITH_EDITOR
#include "Editor/WidgetCompilerLog.h"
#endif

UGameplayTagSlot::UGameplayTagSlot(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SlotTag = TAG_GameplayUI_Slot;
}

#if WITH_EDITOR
void UGameplayTagSlot::ValidateCompiledDefaults(IWidgetCompilerLog& CompileLog) const
{
	Super::ValidateCompiledDefaults(CompileLog);

	if (!SlotTag.IsValid())
	{
		CompileLog.Error(FText::FromString(TEXT("Slot Tag Is InValid")));
	}
	else if (!SlotTag.MatchesTag(TAG_GameplayUI_Slot))
	{
		CompileLog.Error(FText::FromString(TEXT("Slot Tag Must Match GameplayUI.Slot")));
	}
}
#endif

TSharedRef<SWidget> UGameplayTagSlot::RebuildWidget()
{
	if (IsDesignTime())
	{
		return SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(EVerticalAlignment::VAlign_Center)
			[
				SNew(STextBlock)
				.Text(FText::FromString(SlotTag.GetTagName().ToString()))
			];
	}
	else
	{
		TSharedRef<SWidget> RebuiltWidget = Super::RebuildWidget();

		if (bAutoRegister)
		{
			RegisterToSlotSubsystem();
		}

		return RebuiltWidget;
	}
}

void UGameplayTagSlot::ReleaseSlateResources(bool bReleaseChildren)
{
	if (!IsDesignTime())
	{
		UnregisterFromSlotSubsystem();
	}

	Super::ReleaseSlateResources(bReleaseChildren);
}

void UGameplayTagSlot::OnSlotAdded(UPanelSlot* InSlot)
{
	Super::OnSlotAdded(InSlot);
	OnSlotContentAdded.Broadcast(GetChildAt(0));
}

void UGameplayTagSlot::SetSlotVisibility(ESlateVisibility InVisibility)
{
	SetVisibility(InVisibility);
}

FGameplayTag UGameplayTagSlot::GetRouteTag_Implementation() const
{
	return TAG_GameplayUI_Route_Slot;
}

ULocalPlayer* UGameplayTagSlot::GetRouteOwnerPlayer_Implementation() const
{
	return GetOwningLocalPlayer();
}

void UGameplayTagSlot::OnSlotRemoved(UPanelSlot* InSlot)
{
	OnSlotContentRemoved.Broadcast(GetChildAt(0));
	Super::OnSlotRemoved(InSlot);
}

void UGameplayTagSlot::RegisterToSlotSubsystem()
{
	if (UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(GetOwningLocalPlayer()))
	{
		SlotSubsystem->RegisterSlotAutomatically(this);
	}
}

void UGameplayTagSlot::UnregisterFromSlotSubsystem()
{
	if (UGenericSlotSubsystem* SlotSubsystem = UGenericSlotSubsystem::Get(GetOwningLocalPlayer()))
	{
		SlotSubsystem->UnregisterSlotAutomatically(this);
	}
}
