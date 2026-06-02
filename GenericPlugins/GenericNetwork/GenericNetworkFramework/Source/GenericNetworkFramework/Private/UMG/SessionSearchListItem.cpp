// Copyright ChenTaiye 2025. All Rights Reserved. 

#include "UMG/SessionSearchListItem.h"

#include "Base/GenericButtonWidget.h"
#include "GenericSessionSubsystem.h"
#include "WidgetType.h"
#include "ViewModel/SessionSearchResultViewModel.h"

void USessionSearchListItem::NativeConstruct()
{
	Super::NativeConstruct();

	if (GenericButtonWidget_Join)
	{
		GenericButtonWidget_Join->Delegate_OnButtonClickedEvent.AddUObject(this, &ThisClass::OnJoinButtonClicked);
		GenericButtonWidget_Join->SetVisibility(ESlateVisibility::Hidden);
	}
}

void USessionSearchListItem::NativeDestruct()
{
	Super::NativeDestruct();

	if (GenericButtonWidget_Join)
	{
		GenericButtonWidget_Join->Delegate_OnButtonClickedEvent.RemoveAll(this);
	}
}

void USessionSearchListItem::OnJoinButtonClicked()
{
	if (UGenericSessionSubsystem* GenericSessionSubsystem = UGenericSessionSubsystem::Get(this))
	{
		if (SessionSearchResultViewModel)
		{
			GenericSessionSubsystem->JoinSession(GetOwningPlayer(), SessionSearchResultViewModel->SessionSearchResult);
		}
	}
}

void USessionSearchListItem::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	if (USessionSearchListItemObject* Object = Cast<USessionSearchListItemObject>(ListItemObject))
	{
		SetSessionSearchResultViewModel(Object->SessionSearchResultViewModel);
	}
}

void USessionSearchListItem::NativeOnItemSelectionChanged(bool bIsSelected)
{
	IUserObjectListEntry::NativeOnItemSelectionChanged(bIsSelected);

	if (bIsSelected)
	{
		RefreshSelectedSession();
	}

	if (GenericButtonWidget_Join)
	{
		GenericButtonWidget_Join->SetVisibility(bIsSelected ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Hidden);
	}
}

void USessionSearchListItem::NativeOnItemExpansionChanged(bool bIsExpanded)
{
	IUserObjectListEntry::NativeOnItemExpansionChanged(bIsExpanded);
}

void USessionSearchListItem::NativeOnEntryReleased()
{
	IUserObjectListEntry::NativeOnEntryReleased();
	SetSessionSearchResultViewModel(nullptr);
}

void USessionSearchListItem::SetSessionSearchResultViewModel(USessionSearchResultViewModel* InViewModel)
{
	UNREGISTER_MVVM_PROPERTY(SessionSearchResultViewModel);

	SessionSearchResultViewModel = InViewModel;

	if (SessionSearchResultViewModel)
	{
		OnSessionSearchResultViewModelSet(SessionSearchResultViewModel);
	}
}

void USessionSearchListItem::RefreshSelectedSession()
{
	if (UGenericSessionSubsystem* GenericSessionSubsystem = UGenericSessionSubsystem::Get(this))
	{
		/** FOnlineSessionNull 未实现 FindSessionByID，因此 Null 子系统下该刷新请求不会得到有效房间详情。 */
		GenericSessionSubsystem->FindSingleSession
		(
			GetOwningPlayer(),
			SessionSearchResultViewModel->SessionSearchResult.OwnerPlayerID,
			FOnSingleSessionResultCompleteDelegate::CreateUObject(this, &USessionSearchListItem::OnRefreshSelectedSessionComplete)
		);
	}
}

void USessionSearchListItem::OnRefreshSelectedSessionComplete(int32 InPlayerIndex, bool bWasSuccessful, const FOnlineSessionSearchResult& InResult)
{
	if (bWasSuccessful)
	{
		SessionSearchResultViewModel->SetSessionSearchResult(InResult);
	}

	if (IsListItemSelected())
	{
		RefreshSelectedSession();
	}
}

void USessionSearchListItem::OnSessionSearchResultViewModelSet_Implementation(USessionSearchResultViewModel* InViewModel)
{
}
