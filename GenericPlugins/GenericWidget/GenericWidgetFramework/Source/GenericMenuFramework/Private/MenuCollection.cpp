// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Base/MenuCollection.h"

#include "Base/GenericButtonGroup.h"
#include "Base/MenuContainer.h"
#include "Base/MenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "Group/MultiSelectionButtonGroup.h"
#include "Group/SingleSelectionButtonGroup.h"
#include "Base/MenuAsset.h"
#include "Base/MenuNode.h"
#include "Node/MenuDataNode.h"
#include "Node/RootMenuDataNode.h"
#include "Subsystem/GenericRouteSubsystem.h"
#include "Subsystem/GenericWidgetSubsystem.h"
#include "WidgetType.h"

namespace
{
	FString GetRuntimeMenuID(const UMenuNode* InNode)
	{
		const URootMenuDataNode* RootDataNode = Cast<URootMenuDataNode>(InNode);
		if (IsValid(RootDataNode))
		{
			return RootDataNode->MenuID.GetResolvedMenuID().TrimStartAndEnd();
		}

		const UMenuDataNode* MenuDataNode = Cast<UMenuDataNode>(InNode);
		return IsValid(MenuDataNode) ? MenuDataNode->MenuData.MenuID.GetResolvedMenuID().TrimStartAndEnd() : FString();
	}

	const FMenuTableRow* GetMenuData(const UMenuNode* InNode)
	{
		const UMenuDataNode* MenuDataNode = Cast<UMenuDataNode>(InNode);
		return IsValid(MenuDataNode) ? &MenuDataNode->MenuData : nullptr;
	}

	const FMenuContainerEntryTableRow* GetMenuContainerEntry(const UMenuNode* InNode)
	{
		const URootMenuDataNode* RootDataNode = Cast<URootMenuDataNode>(InNode);
		if (IsValid(RootDataNode))
		{
			return &RootDataNode->ContainerEntry;
		}

		if (const FMenuTableRow* MenuData = GetMenuData(InNode))
		{
			return &MenuData->ContainerEntry;
		}

		return nullptr;
	}

	ESlateVisibility GetMenuLevelVisibility(const UMenuNode* InNode)
	{
		const FMenuTableRow* MenuData = GetMenuData(InNode);
		return MenuData ? MenuData->Entry.Visibility : ESlateVisibility::Visible;
	}

	FString SanitizeMenuIDForFunctionName(const FString& InMenuID)
	{
		FString SanitizedMenuID = InMenuID.TrimStartAndEnd();
		for (TCHAR& Character : SanitizedMenuID)
		{
			if (!FChar::IsAlnum(Character) && Character != TEXT('_'))
			{
				Character = TEXT('_');
			}
		}

		return SanitizedMenuID;
	}
}

FString UMenuCollection::GetMenuButtonEventTypeName(EGenericButtonEvent InEventType)
{
	switch (InEventType)
	{
	case EGenericButtonEvent::OnPressed:
		return TEXT("OnPressed");
	case EGenericButtonEvent::OnReleased:
		return TEXT("OnReleased");
	case EGenericButtonEvent::OnHovered:
		return TEXT("OnHovered");
	case EGenericButtonEvent::OnUnhovered:
		return TEXT("OnUnhovered");
	case EGenericButtonEvent::OnClicked:
		return TEXT("OnClicked");
	case EGenericButtonEvent::OnDoubleClicked:
		return TEXT("OnDoubleClicked");
	case EGenericButtonEvent::OnSelected:
		return TEXT("OnSelected");
	case EGenericButtonEvent::OnDeSelected:
		return TEXT("OnDeSelected");
	default:
		return TEXT("Unknown");
	}
}

FName UMenuCollection::MakeMenuButtonEventGraphName(EGenericButtonEvent InEventType)
{
	return FName(*FString::Printf(TEXT("%sGraph"), *GetMenuButtonEventTypeName(InEventType)));
}

FName UMenuCollection::MakeMenuButtonEventFunctionName(EGenericButtonEvent InEventType, const FString& InMenuID)
{
	const FString SanitizedMenuID = SanitizeMenuIDForFunctionName(InMenuID);
	if (SanitizedMenuID.IsEmpty())
	{
		return NAME_None;
	}

	return FName(*FString::Printf(TEXT("Event_%s_%s"), *GetMenuButtonEventTypeName(InEventType), *SanitizedMenuID));
}

void UMenuCollection::OnMenuInitialized_Implementation(APlayerController* PlayerController)
{
}

void UMenuCollection::OnMenuBuildStarted_Implementation()
{
}

void UMenuCollection::OnMenuBuildFinished_Implementation(bool bSucceeded)
{
}

void UMenuCollection::OnMenuClearStarted_Implementation()
{
}

void UMenuCollection::OnMenuClearFinished_Implementation()
{
}

void UMenuCollection::OnMenuLevelBuildStarted_Implementation(UMenuNode* OwnerNode)
{
}

void UMenuCollection::OnMenuLevelBuilt_Implementation(UMenuNode* OwnerNode, UMenuContainer* Container, UGenericButtonGroup* ButtonGroup)
{
}

void UMenuCollection::OnMenuLevelClearStarted_Implementation(UMenuNode* OwnerNode, UMenuContainer* Container)
{
}

void UMenuCollection::OnMenuLevelCleared_Implementation(UMenuNode* OwnerNode)
{
}

void UMenuCollection::OnMenuButtonBuilt_Implementation(UMenuNode* ButtonNode, UMenuWidget* ButtonWidget)
{
}

void UMenuCollection::OnMenuButtonDestroyed_Implementation(UMenuNode* ButtonNode, UMenuWidget* ButtonWidget)
{
}

void UMenuCollection::OnMenuButtonEventReceived_Implementation(EGenericButtonEvent EventType, UMenuNode* ButtonNode, UMenuWidget* ButtonWidget)
{
}

void UMenuCollection::OnMenuButtonGeneratedEventExecuted_Implementation(EGenericButtonEvent EventType, UMenuNode* ButtonNode, bool bExecuted)
{
}

bool UMenuCollection::Initialize(APlayerController* PlayerController)
{
	if (!IsValid(PlayerController))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("Initialize menu collection failed because PlayerController is null. Collection: %s"), *GetName());
		return false;
	}

	if (OwningPlayerController.Get() != PlayerController)
	{
		ClearMenu();
		OwningPlayerController = PlayerController;
	}

	OnMenuInitialized(PlayerController);
	return true;
}

void UMenuCollection::BuildMenu()
{
	OnMenuBuildStarted();
	ClearMenu();

	bool bSucceeded = false;
	if (!IsValid(OwningPlayerController))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed because OwningPlayerController is null. Collection: %s"), *GetName());
		OnMenuBuildFinished(false);
		return;
	}

	if (!IsValid(MenuAsset))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed because MenuAsset is null. Collection: %s"), *GetName());
		OnMenuBuildFinished(false);
		return;
	}

	MenuAsset->EnsureRootNode();
	UMenuNode* RootNode = MenuAsset->RootNode;
	if (!IsValid(RootNode))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed because root node is missing. Collection: %s"), *GetName());
		OnMenuBuildFinished(false);
		return;
	}

	const int32 RootLevelIndex = BuildMenuLevel(RootNode, false);
	if (!RuntimeLevels.IsValidIndex(RootLevelIndex))
	{
		OnMenuBuildFinished(false);
		return;
	}

	bSucceeded = true;
	OnMenuBuildFinished(bSucceeded);
}

void UMenuCollection::ClearMenu()
{
	OnMenuClearStarted();
	for (int32 LevelIndex = RuntimeLevels.Num() - 1; LevelIndex >= 0; --LevelIndex)
	{
		ClearLevelAtIndex(LevelIndex);
	}

	RuntimeLevels.Reset();
	OnMenuClearFinished();
}

int32 UMenuCollection::BuildMenuLevel(UMenuNode* OwnerNode, bool bRequireSlotTag)
{
	if (!IsValid(OwningPlayerController) || !IsValid(OwnerNode))
	{
		return INDEX_NONE;
	}

	OnMenuLevelBuildStarted(OwnerNode);

	FMenuCollectionRuntimeLevelEntry RuntimeLevel;
	RuntimeLevel.OwnerNode = OwnerNode;
	RuntimeLevel.Container = CreateButtonContainer(OwnerNode);
	if (!IsValid(RuntimeLevel.Container))
	{
		return INDEX_NONE;
	}

	RuntimeLevel.ButtonGroup = CreateButtonGroup(OwnerNode);
	if (!RegisterButtonContainer(RuntimeLevel.Container, OwnerNode, bRequireSlotTag))
	{
		if (bRequireSlotTag)
		{
			return INDEX_NONE;
		}
	}
	else
	{
		const FMenuContainerEntryTableRow* ContainerEntry = GetMenuContainerEntry(OwnerNode);
		const FGameplayTag SlotTag = ContainerEntry ? ContainerEntry->ButtonContainerSlotTag : FGameplayTag();
		if (SlotTag.IsValid())
		{
			RuntimeLevel.RegisteredSlotTag = SlotTag;
		}
	}

	RuntimeLevel.Container->OnMenuBuilt(this, OwnerNode);

	const int32 LevelIndex = RuntimeLevels.Add(MoveTemp(RuntimeLevel));
	FMenuCollectionRuntimeLevelEntry& AddedLevel = RuntimeLevels[LevelIndex];

	for (const TObjectPtr<UMenuNode>& ChildNode : OwnerNode->Children)
	{
		if (!IsValid(ChildNode))
		{
			continue;
		}

		UMenuWidget* ButtonWidget = CreateButtonWidget(ChildNode);
		if (!IsValid(ButtonWidget))
		{
			continue;
		}

		if (!AddedLevel.Container->AddButton(ButtonWidget))
		{
			UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed to add button '%s' to container '%s'."), *ButtonWidget->GetName(), *AddedLevel.Container->GetName());
		}

		if (IsValid(AddedLevel.ButtonGroup) && !AddedLevel.ButtonGroup->AddButton(ButtonWidget))
		{
			UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed to add button '%s' to button group '%s'."), *ButtonWidget->GetName(), *AddedLevel.ButtonGroup->GetName());
		}

		if (!RegisterButton(AddedLevel.Container, ButtonWidget, ChildNode))
		{
			UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed to register button '%s' to parent container '%s'."), *ButtonWidget->GetName(), *AddedLevel.Container->GetName());
			if (IsValid(AddedLevel.ButtonGroup))
			{
				AddedLevel.ButtonGroup->RemoveButton(ButtonWidget);
			}
			AddedLevel.Container->RemoveButton(ButtonWidget);
			continue;
		}

		FMenuCollectionRuntimeButtonEntry& ButtonEntry = AddedLevel.Buttons.AddDefaulted_GetRef();
		ButtonEntry.Node = ChildNode;
		ButtonEntry.ButtonWidget = ButtonWidget;
		ButtonEntry.PressedHandle = ButtonWidget->Delegate_OnButtonPressedEvent.AddUObject(this, &ThisClass::HandleButtonEvent, EGenericButtonEvent::OnPressed, ChildNode.Get());
		ButtonEntry.ReleasedHandle = ButtonWidget->Delegate_OnButtonReleasedEvent.AddUObject(this, &ThisClass::HandleButtonEvent, EGenericButtonEvent::OnReleased, ChildNode.Get());
		ButtonEntry.HoveredHandle = ButtonWidget->Delegate_OnButtonHoveredEvent.AddUObject(this, &ThisClass::HandleButtonEvent, EGenericButtonEvent::OnHovered, ChildNode.Get());
		ButtonEntry.UnhoveredHandle = ButtonWidget->Delegate_OnButtonUnhoveredEvent.AddUObject(this, &ThisClass::HandleButtonEvent, EGenericButtonEvent::OnUnhovered, ChildNode.Get());
		ButtonEntry.ClickedHandle = ButtonWidget->Delegate_OnButtonClickedEvent.AddUObject(this, &ThisClass::HandleButtonEvent, EGenericButtonEvent::OnClicked, ChildNode.Get());
		ButtonEntry.DoubleClickedHandle = ButtonWidget->Delegate_OnButtonDoubleClickedEvent.AddUObject(this, &ThisClass::HandleButtonEvent, EGenericButtonEvent::OnDoubleClicked, ChildNode.Get());
		ButtonEntry.SelectionChangedHandle = ButtonWidget->Delegate_OnButtonSelectionChangedEvent.AddUObject(this, &ThisClass::HandleButtonSelectionChanged, ChildNode.Get());
		ButtonWidget->OnMenuBuilt(this, ChildNode);
		OnMenuButtonBuilt(ChildNode, ButtonWidget);
	}

	ApplyDefaultSelections(OwnerNode);
	OnMenuLevelBuilt(OwnerNode, AddedLevel.Container, AddedLevel.ButtonGroup);
	return LevelIndex;
}

UMenuContainer* UMenuCollection::CreateButtonContainer_Implementation(UMenuNode* OwnerNode)
{
	if (!IsValid(OwnerNode))
	{
		return nullptr;
	}

	const FMenuContainerEntryTableRow* ContainerEntry = GetMenuContainerEntry(OwnerNode);
	if (!ContainerEntry)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed because owner node has no container data. Node: %s, Collection: %s"), *OwnerNode->GetName(), *GetName());
		return nullptr;
	}

	UClass* ContainerClass = ContainerEntry->ButtonContainerClass.LoadSynchronous();
	if (!ContainerClass)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed because ButtonContainerClass is missing. Node: %s, Collection: %s"), *OwnerNode->GetName(), *GetName());
		return nullptr;
	}

	UMenuContainer* CreatedContainer = CreateWidget<UMenuContainer>(OwningPlayerController.Get(), ContainerClass);
	if (!IsValid(CreatedContainer))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed because container widget could not be created. Node: %s, Class: %s"), *OwnerNode->GetName(), *ContainerClass->GetName());
		return nullptr;
	}

	CreatedContainer->SetVisibility(GetMenuLevelVisibility(OwnerNode));
	return CreatedContainer;
}

UGenericButtonGroup* UMenuCollection::CreateButtonGroup_Implementation(UMenuNode* OwnerNode)
{
	if (!IsValid(OwnerNode))
	{
		return nullptr;
	}

	const FMenuContainerEntryTableRow* ContainerEntry = GetMenuContainerEntry(OwnerNode);
	if (!ContainerEntry)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu could not create button group because owner node has no container data. Node: %s"), *OwnerNode->GetName());
		return nullptr;
	}

	UClass* ButtonGroupClass = ContainerEntry->ButtonGroupClass.LoadSynchronous();
	if (!ButtonGroupClass)
	{
		if (OwnerNode->Children.Num() > 0)
		{
			UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu could not create button group because ButtonGroupClass is missing. Node: %s"), *OwnerNode->GetName());
		}
		return nullptr;
	}

	UGenericButtonGroup* CreatedGroup = NewObject<UGenericButtonGroup>(this, ButtonGroupClass);
	if (!IsValid(CreatedGroup))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed to create button group. Node: %s, Class: %s"), *OwnerNode->GetName(), *ButtonGroupClass->GetName());
	}
	return CreatedGroup;
}

UMenuWidget* UMenuCollection::CreateButtonWidget_Implementation(UMenuNode* ButtonNode)
{
	if (!IsValid(ButtonNode))
	{
		return nullptr;
	}

	const FMenuTableRow* MenuData = GetMenuData(ButtonNode);
	if (!MenuData)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu skipped menu node '%s' because it has no menu data."), *ButtonNode->GetName());
		return nullptr;
	}

	UClass* ButtonWidgetClass = MenuData->Entry.ButtonWidgetClass.LoadSynchronous();
	if (!ButtonWidgetClass)
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu skipped menu node '%s' because ButtonWidgetClass is missing."), *ButtonNode->GetName());
		return nullptr;
	}

	UMenuWidget* CreatedButton = CreateWidget<UMenuWidget>(OwningPlayerController.Get(), ButtonWidgetClass);
	if (!IsValid(CreatedButton))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu skipped menu node '%s' because button widget could not be created. Class: %s"), *ButtonNode->GetName(), *ButtonWidgetClass->GetName());
		return nullptr;
	}

	ApplyButtonState(CreatedButton, ButtonNode);
	return CreatedButton;
}

bool UMenuCollection::RegisterButtonContainer_Implementation(UMenuContainer* Container, UMenuNode* OwnerNode, bool bRequireSlotTag)
{
	if (!IsValid(Container) || !IsValid(OwnerNode))
	{
		return false;
	}

	const FMenuContainerEntryTableRow* ContainerEntry = GetMenuContainerEntry(OwnerNode);
	if (!ContainerEntry)
	{
		return false;
	}

	const FGameplayTag SlotTag = ContainerEntry->ButtonContainerSlotTag;
	if (!SlotTag.IsValid())
	{
		if (bRequireSlotTag)
		{
			UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed because submenu ButtonContainerSlotTag is invalid. Node: %s"), *OwnerNode->GetName());
		}
		return false;
	}

	UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(OwningPlayerController.Get());
	if (!IsValid(WidgetSubsystem))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu could not register root container because GenericWidgetSubsystem is missing. SlotTag: %s"), *SlotTag.ToString());
		return false;
	}

	if (!WidgetSubsystem->RegisterWidget(Container, SlotTag, GetMenuLevelVisibility(OwnerNode)))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu could not register container '%s' to slot '%s'."), *Container->GetName(), *SlotTag.ToString());
		return false;
	}

	return true;
}

bool UMenuCollection::RegisterButton_Implementation(UMenuContainer* ParentContainer, UMenuWidget* ButtonWidget, UMenuNode* ButtonNode)
{
	if (!IsValid(ButtonNode) || !IsValid(ButtonWidget) || !IsValid(ParentContainer))
	{
		return false;
	}

	UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(OwningPlayerController.Get());
	if (!IsValid(WidgetSubsystem))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu could not register button because GenericWidgetSubsystem is missing. Button: %s"), *ButtonWidget->GetName());
		return false;
	}

	return WidgetSubsystem->RegisterWidget(
		ButtonWidget,
		UGenericRouteSubsystem::MakeRouteInterface(ParentContainer),
		ButtonWidget->GetVisibility()
	);
}

void UMenuCollection::ApplyButtonState_Implementation(UMenuWidget* ButtonWidget, UMenuNode* ButtonNode)
{
	if (!IsValid(ButtonWidget) || !IsValid(ButtonNode))
	{
		return;
	}

	const FMenuTableRow* MenuData = GetMenuData(ButtonNode);
	if (!MenuData)
	{
		return;
	}

	ButtonWidget->SetVisibility(MenuData->Entry.Visibility);
	ButtonWidget->SetButtonSelectable(MenuData->Entry.bSelectable);
	ButtonWidget->SetButtonToggleable(MenuData->Entry.bToggleable);
	ButtonWidget->SetButtonDefaultSelected(false);
	ButtonWidget->SetButtonTag(MenuData->MenuID.MenuTag);
	ButtonWidget->SetButtonEnabled(MenuData->Entry.bButtonEnabled);
	ButtonWidget->SetButtonInteractionEnabled(MenuData->Entry.bInteractionEnabled);
}

void UMenuCollection::ApplyDefaultSelections_Implementation(UMenuNode* OwnerNode)
{
	FMenuCollectionRuntimeLevelEntry* RuntimeLevel = FindRuntimeLevel(OwnerNode);
	if (!RuntimeLevel)
	{
		return;
	}

	if (!IsValid(RuntimeLevel->ButtonGroup))
	{
		if (RuntimeLevel->Buttons.Num() > 0)
		{
			UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu skipped default selection because button group is missing. Node: %s"), IsValid(RuntimeLevel->OwnerNode) ? *RuntimeLevel->OwnerNode->GetName() : TEXT("None"));
		}
		return;
	}

	bool bHasSingleSelection = false;
	for (FMenuCollectionRuntimeButtonEntry& ButtonEntry : RuntimeLevel->Buttons)
	{
		if (!IsValid(ButtonEntry.Node) || !IsValid(ButtonEntry.ButtonWidget))
		{
			continue;
		}

		const FMenuTableRow* MenuData = GetMenuData(ButtonEntry.Node);
		const bool bDefaultSelected = MenuData ? MenuData->Entry.bDefaultSelected : false;
		ButtonEntry.ButtonWidget->SetButtonDefaultSelected(bDefaultSelected);
		if (!ButtonEntry.ButtonWidget->GetButtonDefaultSelected())
		{
			continue;
		}

		if (RuntimeLevel->ButtonGroup->GetSelectionMode() == EGenericButtonGroupSelectionMode::Single)
		{
			if (bHasSingleSelection)
			{
				UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu ignored duplicated default selection in single-selection group. Button: %s, Group: %s"), *ButtonEntry.ButtonWidget->GetName(), *RuntimeLevel->ButtonGroup->GetName());
				continue;
			}

			if (USingleSelectionButtonGroup* SingleSelectionGroup = Cast<USingleSelectionButtonGroup>(RuntimeLevel->ButtonGroup))
			{
				SingleSelectionGroup->SetSelectedButton(ButtonEntry.ButtonWidget);
			}
			else
			{
				UE_LOG(GenericLogUI, Verbose, TEXT("BuildMenu applied single default selection with generic button selection because group '%s' is custom."), *RuntimeLevel->ButtonGroup->GetName());
				ButtonEntry.ButtonWidget->SetButtonSelected(true);
			}
			bHasSingleSelection = true;
		}
		else
		{
			if (UMultiSelectionButtonGroup* MultiSelectionGroup = Cast<UMultiSelectionButtonGroup>(RuntimeLevel->ButtonGroup))
			{
				MultiSelectionGroup->SetButtonSelected(ButtonEntry.ButtonWidget, true);
			}
			else
			{
				UE_LOG(GenericLogUI, Verbose, TEXT("BuildMenu applied multi default selection with generic button selection because group '%s' is custom."), *RuntimeLevel->ButtonGroup->GetName());
				ButtonEntry.ButtonWidget->SetButtonSelected(true);
			}
		}
	}
}

void UMenuCollection::ClearLevelAtIndex(int32 InLevelIndex)
{
	if (!RuntimeLevels.IsValidIndex(InLevelIndex))
	{
		return;
	}

	FMenuCollectionRuntimeLevelEntry& RuntimeLevel = RuntimeLevels[InLevelIndex];
	UMenuNode* ClearedOwnerNode = RuntimeLevel.OwnerNode;
	OnMenuLevelClearStarted(ClearedOwnerNode, RuntimeLevel.Container);

	for (FMenuCollectionRuntimeButtonEntry& ButtonEntry : RuntimeLevel.Buttons)
	{
		if (IsValid(ButtonEntry.ButtonWidget))
		{
			OnMenuButtonDestroyed(ButtonEntry.Node, ButtonEntry.ButtonWidget);
			ButtonEntry.ButtonWidget->OnMenuDestroyed(this, ButtonEntry.Node);
		}

		if (IsValid(ButtonEntry.ButtonWidget))
		{
			ButtonEntry.ButtonWidget->Delegate_OnButtonPressedEvent.Remove(ButtonEntry.PressedHandle);
			ButtonEntry.ButtonWidget->Delegate_OnButtonReleasedEvent.Remove(ButtonEntry.ReleasedHandle);
			ButtonEntry.ButtonWidget->Delegate_OnButtonHoveredEvent.Remove(ButtonEntry.HoveredHandle);
			ButtonEntry.ButtonWidget->Delegate_OnButtonUnhoveredEvent.Remove(ButtonEntry.UnhoveredHandle);
			ButtonEntry.ButtonWidget->Delegate_OnButtonClickedEvent.Remove(ButtonEntry.ClickedHandle);
			ButtonEntry.ButtonWidget->Delegate_OnButtonDoubleClickedEvent.Remove(ButtonEntry.DoubleClickedHandle);
			ButtonEntry.ButtonWidget->Delegate_OnButtonSelectionChangedEvent.Remove(ButtonEntry.SelectionChangedHandle);

			if (UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(OwningPlayerController.Get()))
			{
				WidgetSubsystem->UnregisterWidget(ButtonEntry.ButtonWidget);
			}
		}
	}

	if (IsValid(RuntimeLevel.ButtonGroup))
	{
		RuntimeLevel.ButtonGroup->ClearButtons();
	}

	if (IsValid(RuntimeLevel.Container))
	{
		for (FMenuCollectionRuntimeButtonEntry& ButtonEntry : RuntimeLevel.Buttons)
		{
			if (IsValid(ButtonEntry.ButtonWidget))
			{
				RuntimeLevel.Container->RemoveButton(ButtonEntry.ButtonWidget);
			}
		}
	}

	if (IsValid(RuntimeLevel.Container))
	{
		RuntimeLevel.Container->OnMenuDestroyed(this, RuntimeLevel.OwnerNode);
	}

	if (RuntimeLevel.RegisteredSlotTag.IsValid() && IsValid(OwningPlayerController))
	{
		if (UGenericWidgetSubsystem* WidgetSubsystem = UGenericWidgetSubsystem::Get(OwningPlayerController.Get()))
		{
			WidgetSubsystem->UnregisterWidgetBySlotTag(RuntimeLevel.RegisteredSlotTag, true);
		}
	}

	if (IsValid(RuntimeLevel.Container))
	{
		RuntimeLevel.Container->RemoveFromParent();
	}

	RuntimeLevels.RemoveAt(InLevelIndex);
	OnMenuLevelCleared(ClearedOwnerNode);
}

void UMenuCollection::ClearDescendantLevels(UMenuNode* OwnerNode)
{
	if (!IsValid(OwnerNode))
	{
		return;
	}

	for (int32 LevelIndex = RuntimeLevels.Num() - 1; LevelIndex >= 0; --LevelIndex)
	{
		UMenuNode* LevelOwnerNode = RuntimeLevels[LevelIndex].OwnerNode;
		if (IsValid(LevelOwnerNode) && IsNodeInSubtree(LevelOwnerNode, OwnerNode))
		{
			ClearLevelAtIndex(LevelIndex);
		}
	}
}

void UMenuCollection::ClearChildLevelsOfParent(UMenuNode* ParentNode)
{
	if (!IsValid(ParentNode))
	{
		return;
	}

	for (const TObjectPtr<UMenuNode>& ChildNode : ParentNode->Children)
	{
		if (IsValid(ChildNode))
		{
			ClearDescendantLevels(ChildNode);
		}
	}
}

bool UMenuCollection::IsNodeInSubtree(UMenuNode* CandidateNode, UMenuNode* RootNode) const
{
	for (UMenuNode* CurrentNode = CandidateNode; IsValid(CurrentNode); CurrentNode = CurrentNode->Parent)
	{
		if (CurrentNode == RootNode)
		{
			return true;
		}
	}

	return false;
}

FMenuCollectionRuntimeLevelEntry* UMenuCollection::FindRuntimeLevel(UMenuNode* OwnerNode)
{
	if (!IsValid(OwnerNode))
	{
		return nullptr;
	}

	for (FMenuCollectionRuntimeLevelEntry& RuntimeLevel : RuntimeLevels)
	{
		if (RuntimeLevel.OwnerNode == OwnerNode)
		{
			return &RuntimeLevel;
		}
	}

	return nullptr;
}

const FMenuCollectionRuntimeLevelEntry* UMenuCollection::FindRuntimeLevel(UMenuNode* OwnerNode) const
{
	if (!IsValid(OwnerNode))
	{
		return nullptr;
	}

	for (const FMenuCollectionRuntimeLevelEntry& RuntimeLevel : RuntimeLevels)
	{
		if (RuntimeLevel.OwnerNode == OwnerNode)
		{
			return &RuntimeLevel;
		}
	}

	return nullptr;
}

UMenuWidget* UMenuCollection::FindRuntimeButtonWidget(UMenuNode* ButtonNode) const
{
	if (!IsValid(ButtonNode))
	{
		return nullptr;
	}

	for (const FMenuCollectionRuntimeLevelEntry& RuntimeLevel : RuntimeLevels)
	{
		for (const FMenuCollectionRuntimeButtonEntry& ButtonEntry : RuntimeLevel.Buttons)
		{
			if (ButtonEntry.Node == ButtonNode)
			{
				return ButtonEntry.ButtonWidget;
			}
		}
	}

	return nullptr;
}

bool UMenuCollection::ExecuteMenuButtonEvent(EGenericButtonEvent InEventType, UMenuNode* ButtonNode)
{
	if (!IsValid(ButtonNode))
	{
		return false;
	}

	const FName FunctionName = MakeMenuButtonEventFunctionName(InEventType, GetRuntimeMenuID(ButtonNode));
	if (FunctionName.IsNone())
	{
		return false;
	}

	UFunction* EventFunction = FindFunction(FunctionName);
	if (!EventFunction)
	{
		return false;
	}

	ProcessEvent(EventFunction, nullptr);
	return true;
}

void UMenuCollection::HandleButtonEvent(EGenericButtonEvent InEventType, UMenuNode* ButtonNode)
{
	UMenuWidget* ButtonWidget = FindRuntimeButtonWidget(ButtonNode);
	OnMenuButtonEventReceived(InEventType, ButtonNode, ButtonWidget);
	const bool bExecuted = ExecuteMenuButtonEvent(InEventType, ButtonNode);
	OnMenuButtonGeneratedEventExecuted(InEventType, ButtonNode, bExecuted);
}

void UMenuCollection::HandleButtonSelectionChanged(bool bSelected, UMenuNode* ButtonNode)
{
	if (!IsValid(OwningPlayerController) || !IsValid(ButtonNode))
	{
		return;
	}

	const EGenericButtonEvent SelectionEvent = bSelected ? EGenericButtonEvent::OnSelected : EGenericButtonEvent::OnDeSelected;
	UMenuWidget* ButtonWidget = FindRuntimeButtonWidget(ButtonNode);
	OnMenuButtonEventReceived(SelectionEvent, ButtonNode, ButtonWidget);
	const bool bExecuted = ExecuteMenuButtonEvent(SelectionEvent, ButtonNode);
	OnMenuButtonGeneratedEventExecuted(SelectionEvent, ButtonNode, bExecuted);

	if (!bSelected)
	{
		ClearDescendantLevels(ButtonNode);
		return;
	}

	ClearChildLevelsOfParent(ButtonNode->Parent);
	ClearDescendantLevels(ButtonNode);

	const int32 ChildCount = ButtonNode->Children.Num();
	if (ChildCount == 0)
	{
		return;
	}

	const int32 RuntimeLevelIndex = BuildMenuLevel(ButtonNode, true);
	if (!RuntimeLevels.IsValidIndex(RuntimeLevelIndex))
	{
		UE_LOG(GenericLogUI, Warning, TEXT("BuildMenu failed to expand menu node. Node: %s, MenuID: %s, ChildCount: %d"),
		       *ButtonNode->GetName(),
		       *GetRuntimeMenuID(ButtonNode),
		       ChildCount
		);
	}
}
