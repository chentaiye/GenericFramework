// Copyright ChenTaiye 2025. All Rights Reserved.

#include "WorldSettings/SGenericWorldSettingsEditor.h"

#include "Editor.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "GameFramework/WorldSettings.h"
#include "IDetailsView.h"
#include "Misc/MessageDialog.h"
#include "PropertyEditorModule.h"
#include "Styling/AppStyle.h"
#include "Widgets/Images/SThrobber.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Layout/SSplitter.h"
#include "Widgets/Layout/SWidgetSwitcher.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/STreeView.h"
#include "WorldSettings/GenericWorldSettings.h"
#include "WorldSettings/GenericWorldSettingsCollection.h"
#include "WorldSettings/GenericWorldSettingsEdSubsystem.h"

#define LOCTEXT_NAMESPACE "SGenericWorldSettingsEditor"

namespace GenericWorldSettingsEditor
{
	const FName DefaultCategoryName(TEXT("Default"));
}

SGenericWorldSettingsEditor::~SGenericWorldSettingsEditor()
{
	FEditorDelegates::MapChange.RemoveAll(this);

	if (UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get())
	{
		Subsystem->OnWorldSettingsClassesChanged().Remove(ClassesChangedHandle);
	}
}

void SGenericWorldSettingsEditor::Construct(const FArguments& InArgs)
{
	SettingsSubsystem = InArgs._SettingsSubsystem;

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.bHideSelectionTip = true;
	DetailsViewArgs.bLockable = false;
	DetailsViewArgs.bUpdatesFromSelection = false;
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	DetailsView->OnFinishedChangingProperties().AddSP(this, &SGenericWorldSettingsEditor::HandleFinishedChangingProperties);

	FEditorDelegates::MapChange.AddSP(this, &SGenericWorldSettingsEditor::HandleMapChanged);

	if (UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get())
	{
		ClassesChangedHandle = Subsystem->OnWorldSettingsClassesChanged().AddSP(this, &SGenericWorldSettingsEditor::HandleWorldSettingsClassesChanged);
	}

	ChildSlot
	[
		SAssignNew(RootSwitcher, SWidgetSwitcher)
		+ SWidgetSwitcher::Slot()
		[
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Center)
				[
					SNew(SThrobber)
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.0f, 10.0f, 0.0f, 0.0f)
				.HAlign(HAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("LoadingWorldSettings", "Loading World Settings..."))
				]
			]
		]
		+ SWidgetSwitcher::Slot()
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				SNew(SBorder)
				.BorderImage(FAppStyle::GetBrush("AssetEditorToolbar.Background"))
				.Padding(FMargin(4.0f, 2.0f))
				[
					BuildToolbar()
				]
			]
			+ SVerticalBox::Slot()
			.FillHeight(1.0f)
			.Padding(6.0f)
			[
				SAssignNew(ContentSwitcher, SWidgetSwitcher)
				+ SWidgetSwitcher::Slot()
				[
					SNew(SBox)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					[
						SNew(SButton)
						.ContentPadding(FMargin(18.0f, 8.0f))
						.IsEnabled(this, &SGenericWorldSettingsEditor::IsCreateCollectionEnabled)
						.OnClicked(this, &SGenericWorldSettingsEditor::HandleCreateCollectionClicked)
						[
							SNew(STextBlock)
							.Text(LOCTEXT("CreateCollectionButton", "Create Setting Collection"))
						]
					]
				]
				+ SWidgetSwitcher::Slot()
				[
					SNew(SSplitter)
					+ SSplitter::Slot()
					.Value(0.28f)
					[
						SAssignNew(SettingsTreeView, STreeView<TSharedPtr<FGenericWorldSettingsEditorEntry>>)
						.TreeItemsSource(&Entries)
						.OnGenerateRow(this, &SGenericWorldSettingsEditor::HandleGenerateSettingsRow)
						.OnGetChildren(this, &SGenericWorldSettingsEditor::HandleGetSettingsChildren)
						.OnExpansionChanged(this, &SGenericWorldSettingsEditor::HandleSettingsExpansionChanged)
						.OnMouseButtonDoubleClick(this, &SGenericWorldSettingsEditor::HandleSettingsRowDoubleClicked)
						.OnSelectionChanged(this, &SGenericWorldSettingsEditor::HandleSettingsSelectionChanged)
						.SelectionMode(ESelectionMode::Single)
					]
					+ SSplitter::Slot()
					.Value(0.72f)
					[
						SNew(SOverlay)
						+ SOverlay::Slot()
						[
							SNew(SBox)
							.Visibility(this, &SGenericWorldSettingsEditor::GetDetailsEmptyPromptVisibility)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							[
								SNew(STextBlock)
								.Text(this, &SGenericWorldSettingsEditor::GetDetailsStatusText)
								.ColorAndOpacity(FSlateColor::UseSubduedForeground())
							]
						]
						+ SOverlay::Slot()
						[
							SNew(SVerticalBox)
							.Visibility(this, &SGenericWorldSettingsEditor::GetDetailsViewVisibility)
							+ SVerticalBox::Slot()
							.AutoHeight()
							.Padding(0.0f, 0.0f, 0.0f, 6.0f)
							[
								SNew(STextBlock)
								.Text(this, &SGenericWorldSettingsEditor::GetDetailsStatusText)
							]
							+ SVerticalBox::Slot()
							.FillHeight(1.0f)
							[
								DetailsView.ToSharedRef()
							]
						]
					]
				]
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(8.0f, 0.0f, 8.0f, 6.0f)
			.HAlign(HAlign_Left)
			[
				SNew(STextBlock)
				.Text(this, &SGenericWorldSettingsEditor::GetStatusText)
				.ColorAndOpacity(FSlateColor::UseSubduedForeground())
			]
		]
	];

	if (UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get())
	{
		RefreshRootSwitcher();
		Subsystem->RequestAsyncRefreshWorldSettingsClasses(true);
	}
	else
	{
		Refresh();
	}
}

TSharedRef<SWidget> SGenericWorldSettingsEditor::BuildToolbar()
{
	FSlimHorizontalToolBarBuilder LeftToolbarBuilder(TSharedPtr<const FUICommandList>(), FMultiBoxCustomization::None, nullptr, true);

	LeftToolbarBuilder.BeginSection("WorldSettings");
	LeftToolbarBuilder.AddToolBarButton
	(
		FUIAction
		(
			FExecuteAction::CreateSP(this, &SGenericWorldSettingsEditor::ExecuteSaveWorld),
			FCanExecuteAction::CreateSP(this, &SGenericWorldSettingsEditor::CanSaveWorld)
		),
		NAME_None,
		LOCTEXT("SaveWorldButton", "Save World"),
		LOCTEXT("SaveWorldButtonTooltip", "Save the current world package."),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Save")
	);
	LeftToolbarBuilder.EndSection();

	FSlimHorizontalToolBarBuilder RightToolbarBuilder(TSharedPtr<const FUICommandList>(), FMultiBoxCustomization::None, nullptr, true);
	RightToolbarBuilder.BeginSection("WorldSettingsDanger");
	RightToolbarBuilder.AddToolBarButton
	(
		FUIAction
		(
			FExecuteAction::CreateSP(this, &SGenericWorldSettingsEditor::ExecuteDeleteCollection),
			FCanExecuteAction::CreateSP(this, &SGenericWorldSettingsEditor::CanDeleteCollection)
		),
		NAME_None,
		LOCTEXT("DeleteCollectionButton", "Delete"),
		LOCTEXT("DeleteCollectionButtonTooltip", "Delete the Generic World Settings collection from the current world."),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), "Icons.Delete")
	);
	RightToolbarBuilder.EndSection();

	return SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			LeftToolbarBuilder.MakeWidget()
		]
		+ SHorizontalBox::Slot()
		.FillWidth(1.0f)
		[
			SNullWidget::NullWidget
		]
		+ SHorizontalBox::Slot()
		.AutoWidth()
		[
			RightToolbarBuilder.MakeWidget()
		];
}

void SGenericWorldSettingsEditor::Refresh()
{
	UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get();
	if (!Subsystem)
	{
		Entries.Reset();
		SelectedEntry.Reset();
		RefreshRootSwitcher();
		if (ContentSwitcher.IsValid())
		{
			ContentSwitcher->SetActiveWidgetIndex(GetContentSwitcherIndex());
		}
		if (SettingsTreeView.IsValid())
		{
			SettingsTreeView->RequestTreeRefresh();
			SettingsTreeView->ClearSelection();
		}
		RefreshDetailsView();
		return;
	}

	RefreshRootSwitcher();
	if (Subsystem->IsRefreshingWorldSettingsClasses() || !Subsystem->HasLoadedWorldSettingsClasses())
	{
		Entries.Reset();
		SelectedEntry.Reset();
		if (SettingsTreeView.IsValid())
		{
			SettingsTreeView->RequestTreeRefresh();
			SettingsTreeView->ClearSelection();
		}
		RefreshDetailsView();
		return;
	}

	const bool bPreviouslySelectedCategoryHeader = SelectedEntry.IsValid() && SelectedEntry->bIsCategoryHeader;
	const UClass* PreviouslySelectedClass = SelectedEntry.IsValid() && !SelectedEntry->bIsCategoryHeader ? SelectedEntry->SettingsClass.Get() : nullptr;
	const FName PreviouslySelectedCategory = SelectedEntry.IsValid() ? SelectedEntry->CategoryName : NAME_None;

	TMap<FName, TArray<TSharedPtr<FGenericWorldSettingsEditorEntry>>> EntriesByCategory;

	UWorld* EditorWorld = Subsystem->GetEditorWorld();
	Entries.Reset();
	for (const TSubclassOf<UGenericWorldSettings>& SettingsClass : Subsystem->GetWorldSettingsClasses())
	{
		if (!SettingsClass)
		{
			continue;
		}

		UGenericWorldSettings* ExistingSettings = Subsystem->FindSettingsInstance(SettingsClass);
		const UGenericWorldSettings* DisplaySource = ExistingSettings ? ExistingSettings : Cast<UGenericWorldSettings>(SettingsClass->GetDefaultObject());

		TSharedRef<FGenericWorldSettingsEditorEntry> Entry = MakeShared<FGenericWorldSettingsEditorEntry>();
		Entry->SettingsClass = SettingsClass;
		Entry->DisplayName = ResolveEntryDisplayName(DisplaySource, SettingsClass.Get());
		Entry->Description = DisplaySource ? DisplaySource->GetSettingsDescription() : FText::GetEmpty();
		Entry->CategoryName = ResolveEntryCategory(DisplaySource);
		Entry->bHasInstance = ExistingSettings != nullptr;
		Entry->bIsEnabled = DisplaySource ? DisplaySource->IsWorldSettingsEnabled(EditorWorld) : true;
		if (!Entry->bIsEnabled)
		{
			Entry->DisabledReason = DisplaySource ? DisplaySource->GetWorldSettingsDisabledReason(EditorWorld) : FText::GetEmpty();
			if (Entry->DisabledReason.IsEmpty())
			{
				Entry->DisabledReason = LOCTEXT("DefaultDisabledSettingsReason", "This setting is not available for the current world.");
			}
		}

		EntriesByCategory.FindOrAdd(Entry->CategoryName).Add(Entry);
	}

	TArray<FName> CategoryNames;
	EntriesByCategory.GenerateKeyArray(CategoryNames);
	CategoryNames.Sort([](const FName& Left, const FName& Right)
	{
		return Left.ToString().Compare(Right.ToString(), ESearchCase::IgnoreCase) < 0;
	});

	for (const FName& CategoryName : CategoryNames)
	{
		TArray<TSharedPtr<FGenericWorldSettingsEditorEntry>>& CategoryEntries = EntriesByCategory.FindChecked(CategoryName);
		CategoryEntries.Sort([](const TSharedPtr<FGenericWorldSettingsEditorEntry>& Left, const TSharedPtr<FGenericWorldSettingsEditorEntry>& Right)
		{
			const FString LeftName = Left.IsValid() ? Left->DisplayName.ToString() : FString();
			const FString RightName = Right.IsValid() ? Right->DisplayName.ToString() : FString();
			return LeftName.Compare(RightName, ESearchCase::IgnoreCase) < 0;
		});

		TSharedRef<FGenericWorldSettingsEditorEntry> CategoryEntry = MakeShared<FGenericWorldSettingsEditorEntry>();
		CategoryEntry->CategoryName = CategoryName;
		CategoryEntry->DisplayName = FText::FromName(CategoryName);
		CategoryEntry->bIsCategoryHeader = true;
		CategoryEntry->Children = MoveTemp(CategoryEntries);
		Entries.Add(CategoryEntry);
	}

	if (bShouldExpandAllCategoriesOnNextRefresh)
	{
		ExpandedCategoryNames.Reset();
		for (const TSharedPtr<FGenericWorldSettingsEditorEntry>& Entry : Entries)
		{
			if (Entry.IsValid() && Entry->bIsCategoryHeader)
			{
				ExpandedCategoryNames.Add(Entry->CategoryName);
			}
		}
		bShouldExpandAllCategoriesOnNextRefresh = false;
	}

	SelectedEntry.Reset();
	for (const TSharedPtr<FGenericWorldSettingsEditorEntry>& Entry : Entries)
	{
		if (!Entry.IsValid())
		{
			continue;
		}

		if (bPreviouslySelectedCategoryHeader && Entry->bIsCategoryHeader && Entry->CategoryName == PreviouslySelectedCategory)
		{
			SelectedEntry = Entry;
			break;
		}

		for (const TSharedPtr<FGenericWorldSettingsEditorEntry>& ChildEntry : Entry->Children)
		{
			if (ChildEntry.IsValid() && ChildEntry->SettingsClass.Get() == PreviouslySelectedClass)
			{
				SelectedEntry = ChildEntry;
				break;
			}
		}

		if (SelectedEntry.IsValid())
		{
			break;
		}
	}

	if (SettingsTreeView.IsValid())
	{
		SettingsTreeView->RequestTreeRefresh();
		SettingsTreeView->ClearExpandedItems();
		for (const TSharedPtr<FGenericWorldSettingsEditorEntry>& Entry : Entries)
		{
			if (Entry.IsValid() && ExpandedCategoryNames.Contains(Entry->CategoryName))
			{
				SettingsTreeView->SetItemExpansion(Entry, true);
			}
		}

		if (SelectedEntry.IsValid())
		{
			SettingsTreeView->SetSelection(SelectedEntry);
		}
		else
		{
			SettingsTreeView->ClearSelection();
		}
	}

	if (ContentSwitcher.IsValid())
	{
		ContentSwitcher->SetActiveWidgetIndex(GetContentSwitcherIndex());
	}

	RefreshDetailsView();
}

void SGenericWorldSettingsEditor::HandleWorldSettingsClassesChanged()
{
	RefreshRootSwitcher();

	const UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get();
	if (Subsystem && Subsystem->HasLoadedWorldSettingsClasses() && !Subsystem->IsRefreshingWorldSettingsClasses())
	{
		SyncMissingSettingsOnOpen();
		Refresh();
	}
}

void SGenericWorldSettingsEditor::SyncMissingSettingsOnOpen()
{
	UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get();
	if (!Subsystem || !Subsystem->HasMissingSettings())
	{
		return;
	}

	Subsystem->SyncMissingSettings();
}

void SGenericWorldSettingsEditor::RefreshRootSwitcher()
{
	if (!RootSwitcher.IsValid())
	{
		return;
	}

	const UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get();
	const bool bShowLoading = Subsystem && (Subsystem->IsRefreshingWorldSettingsClasses() || !Subsystem->HasLoadedWorldSettingsClasses());
	RootSwitcher->SetActiveWidgetIndex(bShowLoading ? 0 : 1);
}

TSharedRef<ITableRow> SGenericWorldSettingsEditor::HandleGenerateSettingsRow(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry, const TSharedRef<STableViewBase>& OwnerTable)
{
	if (Entry.IsValid() && Entry->bIsCategoryHeader)
	{
		return SNew(STableRow<TSharedPtr<FGenericWorldSettingsEditorEntry>>, OwnerTable)
			.Padding(FMargin(2.0f, 6.0f, 2.0f, 2.0f))
			[
				SNew(SBox)
				.Padding(FMargin(4.0f, 4.0f))
				[
					SNew(STextBlock)
					.Text(this, &SGenericWorldSettingsEditor::GetEntryDisplayName, Entry)
					.Font(FAppStyle::GetFontStyle("NormalFontBold"))
				]
			];
	}

	return SNew(STableRow<TSharedPtr<FGenericWorldSettingsEditorEntry>>, OwnerTable)
		.Padding(4.0f)
		[
			SNew(SBox)
			.Padding(FMargin(12.0f, 0.0f, 0.0f, 0.0f))
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(STextBlock)
					.Text(this, &SGenericWorldSettingsEditor::GetEntryDisplayName, Entry)
					.Font(FAppStyle::GetFontStyle("NormalFontBold"))
					.ColorAndOpacity(this, &SGenericWorldSettingsEditor::GetEntryTextColor, Entry)
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.0f, 3.0f, 0.0f, 0.0f)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.Padding(0.0f, 0.0f, 8.0f, 0.0f)
					[
						SNew(STextBlock)
						.Text(this, &SGenericWorldSettingsEditor::GetEntryStateText, Entry)
						.ColorAndOpacity(this, &SGenericWorldSettingsEditor::GetEntryStateColor, Entry)
					]
					+ SHorizontalBox::Slot()
					.FillWidth(1.0f)
					[
						SNew(STextBlock)
						.Text(this, &SGenericWorldSettingsEditor::GetEntryDescription, Entry)
						.ColorAndOpacity(this, &SGenericWorldSettingsEditor::GetEntryTextColor, Entry)
					]
				]
			]
		];
}

void SGenericWorldSettingsEditor::HandleGetSettingsChildren(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry, TArray<TSharedPtr<FGenericWorldSettingsEditorEntry>>& OutChildren) const
{
	if (Entry.IsValid() && Entry->bIsCategoryHeader)
	{
		OutChildren.Append(Entry->Children);
	}
}

void SGenericWorldSettingsEditor::HandleSettingsExpansionChanged(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry, bool bExpanded)
{
	if (!Entry.IsValid() || !Entry->bIsCategoryHeader)
	{
		return;
	}

	if (bExpanded)
	{
		ExpandedCategoryNames.Add(Entry->CategoryName);
	}
	else
	{
		ExpandedCategoryNames.Remove(Entry->CategoryName);
	}
}

void SGenericWorldSettingsEditor::HandleSettingsRowDoubleClicked(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry)
{
	if (!Entry.IsValid() || !Entry->bIsCategoryHeader || !SettingsTreeView.IsValid())
	{
		return;
	}

	SettingsTreeView->SetItemExpansion(Entry, !SettingsTreeView->IsItemExpanded(Entry));
}

void SGenericWorldSettingsEditor::HandleSettingsSelectionChanged(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry, ESelectInfo::Type SelectInfo)
{
	SelectedEntry = Entry;
	RefreshDetailsView();
}

void SGenericWorldSettingsEditor::HandleFinishedChangingProperties(const FPropertyChangedEvent& PropertyChangedEvent)
{
	if (UWorld* World = SettingsSubsystem.IsValid() ? SettingsSubsystem->GetEditorWorld() : nullptr)
	{
		World->MarkPackageDirty();
	}

	Refresh();
}

void SGenericWorldSettingsEditor::HandleMapChanged(uint32 MapChangeFlags)
{
	ExpandedCategoryNames.Reset();
	bShouldExpandAllCategoriesOnNextRefresh = true;
	SelectedEntry.Reset();

	if (UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get())
	{
		Subsystem->RequestAsyncRefreshWorldSettingsClasses(true);
	}
}

FReply SGenericWorldSettingsEditor::HandleCreateCollectionClicked()
{
	if (UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get())
	{
		if (Subsystem->CreateSettingsCollection())
		{
			Subsystem->SyncMissingSettings();
		}
	}

	Refresh();
	return FReply::Handled();
}

FReply SGenericWorldSettingsEditor::HandleSaveWorldClicked()
{
	ExecuteSaveWorld();
	return FReply::Handled();
}

void SGenericWorldSettingsEditor::ExecuteSaveWorld()
{
	if (UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get())
	{
		Subsystem->SaveCurrentWorld();
	}

	Refresh();
}

void SGenericWorldSettingsEditor::ExecuteDeleteCollection()
{
	if (!CanDeleteCollection())
	{
		return;
	}

	const EAppReturnType::Type ConfirmResult = FMessageDialog::Open
	(
		EAppMsgType::YesNo,
		LOCTEXT("DeleteCollectionConfirmMessage", "Delete the Generic World Settings collection from the current world? This removes all world setting instances stored in this map."),
		LOCTEXT("DeleteCollectionConfirmTitle", "Delete World Settings Collection")
	);

	if (ConfirmResult != EAppReturnType::Yes)
	{
		return;
	}

	if (UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get())
	{
		if (Subsystem->DeleteSettingsCollection())
		{
			SelectedEntry.Reset();
			Refresh();
		}
	}
}

bool SGenericWorldSettingsEditor::CanSaveWorld() const
{
	const UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get();
	return Subsystem && Subsystem->GetEditorWorld() != nullptr;
}

bool SGenericWorldSettingsEditor::CanDeleteCollection() const
{
	const UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get();
	return Subsystem
		&& Subsystem->HasLoadedWorldSettingsClasses()
		&& !Subsystem->IsRefreshingWorldSettingsClasses()
		&& Subsystem->GetSettingsCollection();
}

UGenericWorldSettings* SGenericWorldSettingsEditor::GetSelectedSettingsInstance() const
{
	const UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get();
	return Subsystem && SelectedEntry.IsValid() && !SelectedEntry->bIsCategoryHeader && SelectedEntry->bIsEnabled ? Subsystem->FindSettingsInstance(SelectedEntry->SettingsClass) : nullptr;
}

FText SGenericWorldSettingsEditor::GetStatusText() const
{
	const UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get();
	if (!Subsystem)
	{
		return LOCTEXT("UnavailableStatus", "Unavailable");
	}

	UWorld* World = Subsystem->GetEditorWorld();
	if (!World)
	{
		return LOCTEXT("NoWorldStatus", "No World");
	}

	const UPackage* WorldPackage = World->GetOutermost();
	const FString WorldName = WorldPackage ? WorldPackage->GetName() : World->GetName();
	return FText::Format(LOCTEXT("EditingWorldStatusFormat", "World: {0}"), FText::FromString(WorldName));
}

FText SGenericWorldSettingsEditor::GetDetailsStatusText() const
{
	if (!SelectedEntry.IsValid() || SelectedEntry->bIsCategoryHeader)
	{
		return LOCTEXT("NoSelectedSettings", "Select a world setting class from the list.");
	}

	if (!SelectedEntry->bIsEnabled)
	{
		return SelectedEntry->DisabledReason.IsEmpty()
			? LOCTEXT("DefaultDisabledSettingsReason", "This setting is not available for the current world.")
			: SelectedEntry->DisabledReason;
	}

	if (GetSelectedSettingsInstance())
	{
		return FText::Format(LOCTEXT("EditingSettingsFormat", "Editing: {0}"), SelectedEntry->DisplayName);
	}

	return LOCTEXT("MissingSettingsInstance", "This setting has no instance in the current world. Create or sync the collection first.");
}

EVisibility SGenericWorldSettingsEditor::GetDetailsViewVisibility() const
{
	return GetSelectedSettingsInstance() ? EVisibility::Visible : EVisibility::Collapsed;
}

EVisibility SGenericWorldSettingsEditor::GetDetailsEmptyPromptVisibility() const
{
	return GetSelectedSettingsInstance() ? EVisibility::Collapsed : EVisibility::Visible;
}

bool SGenericWorldSettingsEditor::IsCreateCollectionEnabled() const
{
	const UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get();
	return Subsystem
		&& Subsystem->HasLoadedWorldSettingsClasses()
		&& !Subsystem->IsRefreshingWorldSettingsClasses()
		&& Subsystem->GetEditorWorldSettings()
		&& !Subsystem->GetSettingsCollection();
}

int32 SGenericWorldSettingsEditor::GetContentSwitcherIndex() const
{
	const UGenericWorldSettingsEdSubsystem* Subsystem = SettingsSubsystem.Get();
	return Subsystem && Subsystem->GetSettingsCollection() ? 1 : 0;
}

FText SGenericWorldSettingsEditor::GetEntryDisplayName(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry) const
{
	return Entry.IsValid() ? Entry->DisplayName : FText::GetEmpty();
}

FText SGenericWorldSettingsEditor::ResolveEntryDisplayName(const UGenericWorldSettings* DisplaySource, const UClass* SettingsClass)
{
	if (DisplaySource)
	{
		const FText SettingsDisplayName = DisplaySource->GetSettingsDisplayName();
		if (!SettingsDisplayName.IsEmpty())
		{
			return SettingsDisplayName;
		}
	}

	if (SettingsClass)
	{
		const FText ClassDisplayName = SettingsClass->GetDisplayNameText();
		if (!ClassDisplayName.IsEmpty())
		{
			return ClassDisplayName;
		}

		return FText::FromString(SettingsClass->GetName());
	}

	return LOCTEXT("UnknownWorldSettingsDisplayName", "Unknown");
}

FName SGenericWorldSettingsEditor::ResolveEntryCategory(const UGenericWorldSettings* DisplaySource)
{
	if (!DisplaySource)
	{
		return GenericWorldSettingsEditor::DefaultCategoryName;
	}

	const FName CategoryName = DisplaySource->GetSettingsCategory();
	return CategoryName.IsNone() ? GenericWorldSettingsEditor::DefaultCategoryName : CategoryName;
}

FText SGenericWorldSettingsEditor::GetEntryDescription(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry) const
{
	if (!Entry.IsValid())
	{
		return FText::GetEmpty();
	}

	if (Entry->bIsCategoryHeader)
	{
		return FText::GetEmpty();
	}

	if (!Entry->Description.IsEmpty())
	{
		return Entry->Description;
	}

	const UClass* SettingsClass = Entry->SettingsClass.Get();
	return SettingsClass ? FText::FromString(SettingsClass->GetPathName()) : FText::GetEmpty();
}

FText SGenericWorldSettingsEditor::GetEntryStateText(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry) const
{
	if (Entry.IsValid() && Entry->bIsCategoryHeader)
	{
		return FText::GetEmpty();
	}

	if (Entry.IsValid() && !Entry->bIsEnabled)
	{
		return LOCTEXT("EntryDisabled", "Invalid");
	}

	return Entry.IsValid() && Entry->bHasInstance ? LOCTEXT("EntryCreated", "Created") : LOCTEXT("EntryMissing", "Missing");
}

FSlateColor SGenericWorldSettingsEditor::GetEntryStateColor(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry) const
{
	if (Entry.IsValid() && Entry->bIsCategoryHeader)
	{
		return FSlateColor::UseSubduedForeground();
	}

	if (Entry.IsValid() && !Entry->bIsEnabled)
	{
		return FSlateColor(FLinearColor(0.85f, 0.12f, 0.12f, 1.0f));
	}

	return Entry.IsValid() && Entry->bHasInstance
		? FSlateColor(FLinearColor(0.15f, 0.65f, 0.25f, 1.0f))
		: FSlateColor(FLinearColor(0.9f, 0.48f, 0.1f, 1.0f));
}

FSlateColor SGenericWorldSettingsEditor::GetEntryTextColor(TSharedPtr<FGenericWorldSettingsEditorEntry> Entry) const
{
	return Entry.IsValid() && !Entry->bIsCategoryHeader && !Entry->bIsEnabled
		? FSlateColor(FLinearColor(0.45f, 0.45f, 0.45f, 1.0f))
		: FSlateColor::UseForeground();
}

void SGenericWorldSettingsEditor::RefreshDetailsView()
{
	if (!DetailsView.IsValid())
	{
		return;
	}

	DetailsView->SetObject(GetSelectedSettingsInstance());
}

#undef LOCTEXT_NAMESPACE
