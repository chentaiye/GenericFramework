// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Asset/MenuAssetEditorToolkit.h"

#include "AssetToolsModule.h"
#include "ContentBrowserModule.h"
#include "Factories/DataTableFactory.h"
#include "Editor.h"
#include "FileHelpers.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Framework/Notifications/NotificationManager.h"
#include "Framework/Commands/GenericCommands.h"
#include "Graph/MenuGraph.h"
#include "Graph/MenuGraphNode.h"
#include "Base/MenuAsset.h"
#include "Base/MenuNode.h"
#include "Node/MenuDataNode.h"
#include "Node/RootMenuDataNode.h"
#include "MenuType.h"
#include "IContentBrowserSingleton.h"
#include "Misc/DataValidation.h"
#include "Misc/PackageName.h"
#include "PropertyEditorModule.h"
#include "ScopedTransaction.h"
#include "Styling/AppStyle.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Layout/SUniformGridPanel.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/SWindow.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "MenuAssetEditorToolkit"

namespace
{
struct FMenuImportRow
{
	FName RowName;
	FMenuTableRow MenuData;
	FString MenuID;
	FString InferredParentMenuID;
	int32 SourceIndex = 0;
	int32 Depth = 0;
	bool bDerived = false;
};

struct FRootMenuIDCandidate
{
	FString MenuID;
	bool bDerived = false;
	int32 SourceIndex = 0;
	int32 Depth = 0;
};

FString JoinMenuIDSegments(const TArray<FString>& InSegments, int32 InSegmentCount = INDEX_NONE)
{
	const int32 SegmentCount = InSegmentCount == INDEX_NONE ? InSegments.Num() : FMath::Clamp(InSegmentCount, 0, InSegments.Num());
	FString Result;
	for (int32 SegmentIndex = 0; SegmentIndex < SegmentCount; ++SegmentIndex)
	{
		if (!Result.IsEmpty())
		{
			Result += TEXT(".");
		}
		Result += InSegments[SegmentIndex];
	}
	return Result;
}

FString MakeMenuIDFromSegments(const TArray<FString>& InSegments, int32 InSegmentCount = INDEX_NONE)
{
	return FMenuIDTableRow::MakeMenuID(JoinMenuIDSegments(InSegments, InSegmentCount));
}

bool SplitMenuIDPathAllowRoot(const FString& InMenuID, TArray<FString>& OutSegments, FText* OutError = nullptr)
{
	const FString MenuID = FMenuIDTableRow::MakeMenuID(FMenuIDTableRow::GetEditableMenuIDPath(InMenuID)).TrimStartAndEnd();
	if (MenuID == FMenuIDTableRow::GetMenuIDRootPath())
	{
		OutSegments.Reset();
		return true;
	}
	return FMenuIDTableRow::SplitMenuIDPath(MenuID, OutSegments, OutError);
}

bool IsMenuIDUnderRoot(const FString& InMenuID, const FString& InRootMenuID)
{
	if (InMenuID == InRootMenuID)
	{
		return true;
	}

	if (InRootMenuID == FMenuIDTableRow::GetMenuIDRootPath())
	{
		return InMenuID.StartsWith(FMenuIDTableRow::GetMenuIDRootPath() + TEXT("."));
	}

	return InMenuID.StartsWith(InRootMenuID + TEXT("."));
}

int32 GetMenuIDDepth(const FString& InMenuID)
{
	TArray<FString> Segments;
	return SplitMenuIDPathAllowRoot(InMenuID, Segments) ? Segments.Num() : 0;
}

int32 GetRelativeMenuIDDepth(const FString& InRootMenuID, const FString& InMenuID)
{
	return FMath::Max(0, GetMenuIDDepth(InMenuID) - GetMenuIDDepth(InRootMenuID));
}

FString GetParentMenuID(const FString& InMenuID)
{
	TArray<FString> Segments;
	if (!SplitMenuIDPathAllowRoot(InMenuID, Segments) || Segments.IsEmpty())
	{
		return FString();
	}

	return MakeMenuIDFromSegments(Segments, Segments.Num() - 1);
}

FString GetLastMenuIDSegment(const FString& InMenuID)
{
	TArray<FString> Segments;
	if (!SplitMenuIDPathAllowRoot(InMenuID, Segments) || Segments.IsEmpty())
	{
		return TEXT("Root");
	}
	return Segments.Last();
}

void AddRootMenuIDCandidate(TMap<FString, TSharedPtr<FRootMenuIDCandidate>>& InOutCandidateMap, const FString& InMenuID, bool bDerived, int32 InSourceIndex)
{
	if (InMenuID.IsEmpty() || InMenuID == FMenuIDTableRow::GetMenuIDRootPath())
	{
		return;
	}

	TSharedPtr<FRootMenuIDCandidate>& Candidate = InOutCandidateMap.FindOrAdd(InMenuID);
	if (!Candidate.IsValid())
	{
		Candidate = MakeShared<FRootMenuIDCandidate>();
		Candidate->MenuID = InMenuID;
		Candidate->bDerived = bDerived;
		Candidate->SourceIndex = InSourceIndex;
		Candidate->Depth = GetMenuIDDepth(InMenuID);
		return;
	}

	Candidate->SourceIndex = FMath::Min(Candidate->SourceIndex, InSourceIndex);
	if (!bDerived)
	{
		Candidate->bDerived = false;
	}
}

void BuildRootMenuIDCandidates(const TArray<FMenuImportRow>& InImportRows, TArray<TSharedPtr<FRootMenuIDCandidate>>& OutCandidates)
{
	TMap<FString, TSharedPtr<FRootMenuIDCandidate>> CandidateMap;
	for (const FMenuImportRow& ImportRow : InImportRows)
	{
		AddRootMenuIDCandidate(CandidateMap, ImportRow.MenuID, false, ImportRow.SourceIndex);

		TArray<FString> Segments;
		if (!FMenuIDTableRow::SplitMenuIDPath(ImportRow.MenuID, Segments))
		{
			continue;
		}

		for (int32 SegmentCount = 1; SegmentCount < Segments.Num(); ++SegmentCount)
		{
			AddRootMenuIDCandidate(CandidateMap, MakeMenuIDFromSegments(Segments, SegmentCount), true, ImportRow.SourceIndex);
		}
	}

	CandidateMap.GenerateValueArray(OutCandidates);
	OutCandidates.Sort([](const TSharedPtr<FRootMenuIDCandidate>& Left, const TSharedPtr<FRootMenuIDCandidate>& Right)
	{
		if (!Left.IsValid() || !Right.IsValid())
		{
			return Left.IsValid();
		}

		if (Left->Depth != Right->Depth)
		{
			return Left->Depth < Right->Depth;
		}

		if (Left->SourceIndex != Right->SourceIndex)
		{
			return Left->SourceIndex < Right->SourceIndex;
		}

		return Left->MenuID < Right->MenuID;
	});
}

FText GetRootMenuIDCandidateText(const TSharedPtr<FRootMenuIDCandidate>& InCandidate)
{
	if (!InCandidate.IsValid())
	{
		return FText::GetEmpty();
	}

	return InCandidate->bDerived
		? FText::Format(LOCTEXT("DerivedRootMenuIDCandidate", "{0} (Derived)"), FText::FromString(InCandidate->MenuID))
		: FText::FromString(InCandidate->MenuID);
}

bool PickRootMenuID(const TArray<TSharedPtr<FRootMenuIDCandidate>>& InCandidates, FString& OutRootMenuID)
{
	if (InCandidates.IsEmpty() || !GEditor)
	{
		return false;
	}

	TSharedPtr<FRootMenuIDCandidate> SelectedCandidate = InCandidates[0];
	bool bAccepted = false;

	TSharedRef<SWindow> PickerWindow = SNew(SWindow)
		.Title(LOCTEXT("PickRootMenuIDTitle", "Select Root MenuID"))
		.ClientSize(FVector2D(620.0, 150.0))
		.SupportsMaximize(false)
		.SupportsMinimize(false);

	TSharedPtr<SComboBox<TSharedPtr<FRootMenuIDCandidate>>> CandidateComboBox;
	PickerWindow->SetContent(
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(12.0, 12.0, 12.0, 4.0)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("PickRootMenuIDMessage", "The DataTable does not contain the current root row. Select the MenuID used as this MenuAsset root."))
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(12.0, 4.0)
		[
			SAssignNew(CandidateComboBox, SComboBox<TSharedPtr<FRootMenuIDCandidate>>)
			.OptionsSource(&InCandidates)
			.InitiallySelectedItem(SelectedCandidate)
			.OnGenerateWidget_Lambda([](TSharedPtr<FRootMenuIDCandidate> InItem)
			{
				return SNew(STextBlock).Text(GetRootMenuIDCandidateText(InItem));
			})
			.OnSelectionChanged_Lambda([&SelectedCandidate](TSharedPtr<FRootMenuIDCandidate> InItem, ESelectInfo::Type)
			{
				SelectedCandidate = InItem;
			})
			[
				SNew(STextBlock)
				.Text_Lambda([&SelectedCandidate]()
				{
					return GetRootMenuIDCandidateText(SelectedCandidate);
				})
			]
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.HAlign(HAlign_Right)
		.Padding(12.0, 8.0, 12.0, 12.0)
		[
			SNew(SUniformGridPanel)
			.SlotPadding(FMargin(4.0, 0.0))
			+ SUniformGridPanel::Slot(0, 0)
			[
				SNew(SButton)
				.Text(LOCTEXT("PickRootMenuIDOK", "OK"))
				.OnClicked_Lambda([&PickerWindow, &bAccepted]()
				{
					bAccepted = true;
					PickerWindow->RequestDestroyWindow();
					return FReply::Handled();
				})
			]
			+ SUniformGridPanel::Slot(1, 0)
			[
				SNew(SButton)
				.Text(LOCTEXT("PickRootMenuIDCancel", "Cancel"))
				.OnClicked_Lambda([&PickerWindow]()
				{
					PickerWindow->RequestDestroyWindow();
					return FReply::Handled();
				})
			]
		]
	);

	GEditor->EditorAddModalWindow(PickerWindow);
	if (!bAccepted || !SelectedCandidate.IsValid())
	{
		return false;
	}

	OutRootMenuID = SelectedCandidate->MenuID;
	return true;
}

void AddDerivedImportRow(const FString& InMenuID, const FString& InRootMenuID, int32 InSourceIndex, TMap<FString, FMenuImportRow>& InOutRowsByMenuID)
{
	if (InMenuID.IsEmpty() || InMenuID == InRootMenuID || InOutRowsByMenuID.Contains(InMenuID))
	{
		return;
	}

	FMenuImportRow DerivedRow;
	DerivedRow.RowName = FName(*InMenuID);
	DerivedRow.MenuID = InMenuID;
	DerivedRow.MenuData.MenuID.MenuID = InMenuID;
	DerivedRow.MenuData.Description.PrimaryName = FText::FromString(GetLastMenuIDSegment(InMenuID));
	DerivedRow.SourceIndex = InSourceIndex;
	DerivedRow.Depth = GetRelativeMenuIDDepth(InRootMenuID, InMenuID);
	DerivedRow.bDerived = true;
	InOutRowsByMenuID.Add(InMenuID, DerivedRow);
}

void AddMissingParentImportRows(const FString& InMenuID, const FString& InRootMenuID, int32 InSourceIndex, TMap<FString, FMenuImportRow>& InOutRowsByMenuID)
{
	FString ParentMenuID = GetParentMenuID(InMenuID);
	while (!ParentMenuID.IsEmpty() && ParentMenuID != InRootMenuID && IsMenuIDUnderRoot(ParentMenuID, InRootMenuID))
	{
		AddDerivedImportRow(ParentMenuID, InRootMenuID, InSourceIndex, InOutRowsByMenuID);
		ParentMenuID = GetParentMenuID(ParentMenuID);
	}
}
}

const FName FMenuAssetEditorToolkit::GraphTabId(TEXT("MenuAssetEditor_Graph"));
const FName FMenuAssetEditorToolkit::DetailsTabId(TEXT("MenuAssetEditor_Details"));

FMenuAssetEditorToolkit::FMenuAssetEditorToolkit()
{
}

FMenuAssetEditorToolkit::~FMenuAssetEditorToolkit()
{
	if (MenuGraph)
	{
		MenuGraph->SyncNodePositionsToAsset();
	}

	if (GEditor)
	{
		GEditor->UnregisterForUndo(this);
	}
}

void FMenuAssetEditorToolkit::InitMenuAssetEditor(EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UMenuAsset* InMenuAsset)
{
	MenuAsset = InMenuAsset;
	if (MenuAsset)
	{
		MenuAsset->EnsureRootNode();
	}

	MenuGraph = NewObject<UMenuGraph>(GetTransientPackage(), NAME_None, RF_Transient | RF_Transactional);
	MenuGraph->Initialize(MenuAsset);

	BindCommands();
	ExtendDataTableToolbar();
	CreateInternalWidgets();

	const TSharedRef<FTabManager::FLayout> StandaloneDefaultLayout = FTabManager::NewLayout("MenuAssetEditor_Layout_v1")
		->AddArea
		(
			FTabManager::NewPrimaryArea()
			->SetOrientation(Orient_Horizontal)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.72f)
				->AddTab(GraphTabId, ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.28f)
				->AddTab(DetailsTabId, ETabState::OpenedTab)
			)
		);

	InitAssetEditor(Mode, InitToolkitHost, TEXT("MenuAssetEditor"), StandaloneDefaultLayout, true, true, MenuAsset);

	if (GEditor)
	{
		GEditor->RegisterForUndo(this);
	}
}

void FMenuAssetEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	InTabManager->RegisterTabSpawner(GraphTabId, FOnSpawnTab::CreateSP(this, &FMenuAssetEditorToolkit::SpawnTab_Graph))
		.SetDisplayName(LOCTEXT("GraphTab", "Graph"));

	InTabManager->RegisterTabSpawner(DetailsTabId, FOnSpawnTab::CreateSP(this, &FMenuAssetEditorToolkit::SpawnTab_Details))
		.SetDisplayName(LOCTEXT("DetailsTab", "Details"));
}

void FMenuAssetEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
	InTabManager->UnregisterTabSpawner(GraphTabId);
	InTabManager->UnregisterTabSpawner(DetailsTabId);

	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
}

FName FMenuAssetEditorToolkit::GetToolkitFName() const
{
	return TEXT("MenuAssetEditor");
}

FText FMenuAssetEditorToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("BaseToolkitName", "Menu Asset");
}

FString FMenuAssetEditorToolkit::GetWorldCentricTabPrefix() const
{
	return TEXT("Menu Asset");
}

FLinearColor FMenuAssetEditorToolkit::GetWorldCentricTabColorScale() const
{
	return FLinearColor(0.1f, 0.35f, 0.9f);
}

void FMenuAssetEditorToolkit::AddReferencedObjects(FReferenceCollector& Collector)
{
	Collector.AddReferencedObject(MenuAsset);
	Collector.AddReferencedObject(MenuGraph);
}

FString FMenuAssetEditorToolkit::GetReferencerName() const
{
	return TEXT("FMenuAssetEditorToolkit");
}

void FMenuAssetEditorToolkit::PostUndo(bool bSuccess)
{
	RefreshEditorGraph();
}

void FMenuAssetEditorToolkit::PostRedo(bool bSuccess)
{
	RefreshEditorGraph();
}

void FMenuAssetEditorToolkit::SaveAsset_Execute()
{
	SyncAssetBeforeSave();

	FDataValidationContext ValidationContext;
	const EDataValidationResult ValidationResult = MenuAsset ? MenuAsset->IsDataValid(ValidationContext) : EDataValidationResult::Invalid;
	const bool bSucceeded = ValidationResult != EDataValidationResult::Invalid;
	ShowSaveValidationResult(bSucceeded, ValidationContext);
	if (!bSucceeded)
	{
		return;
	}

	FAssetEditorToolkit::SaveAsset_Execute();
}

void FMenuAssetEditorToolkit::CreateInternalWidgets()
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.bHideSelectionTip = true;
	DetailsViewArgs.bLockable = false;
	DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	DetailsView->OnFinishedChangingProperties().AddSP(this, &FMenuAssetEditorToolkit::OnFinishedChangingProperties);

	GraphEditor = CreateGraphEditorWidget();
}

TSharedRef<SGraphEditor> FMenuAssetEditorToolkit::CreateGraphEditorWidget()
{
	FGraphAppearanceInfo AppearanceInfo;
	AppearanceInfo.CornerText = LOCTEXT("GraphCornerText", "MENU");

	SGraphEditor::FGraphEditorEvents GraphEvents;
	GraphEvents.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(this, &FMenuAssetEditorToolkit::OnSelectedNodesChanged);

	return SNew(SGraphEditor)
		.AdditionalCommands(GraphEditorCommands)
		.IsEditable(true)
		.Appearance(AppearanceInfo)
		.GraphToEdit(MenuGraph)
		.GraphEvents(GraphEvents)
		.ShowGraphStateOverlay(false);
}

TSharedRef<SDockTab> FMenuAssetEditorToolkit::SpawnTab_Graph(const FSpawnTabArgs& Args)
{
	return SNew(SDockTab)
		.Label(LOCTEXT("GraphTabLabel", "Graph"))
		[
			GraphEditor.ToSharedRef()
		];
}

TSharedRef<SDockTab> FMenuAssetEditorToolkit::SpawnTab_Details(const FSpawnTabArgs& Args)
{
	return SNew(SDockTab)
		.Label(LOCTEXT("DetailsTabLabel", "Details"))
		[
			DetailsView.ToSharedRef()
		];
}

void FMenuAssetEditorToolkit::OnSelectedNodesChanged(const TSet<UObject*>& NewSelection)
{
	UMenuGraphNode* SelectedGraphNode = nullptr;
	int32 SelectedGraphNodeCount = 0;

	for (UObject* SelectedObject : NewSelection)
	{
		if (UMenuGraphNode* MenuGraphNode = Cast<UMenuGraphNode>(SelectedObject))
		{
			if (MenuGraphNode->MenuNode)
			{
				SelectedGraphNode = MenuGraphNode;
				++SelectedGraphNodeCount;
			}
		}
	}

	if (SelectedGraphNodeCount == 1)
	{
		SetDetailsObject(SelectedGraphNode->MenuNode);
	}
	else
	{
		SetDetailsObject(nullptr);
	}
}

void FMenuAssetEditorToolkit::OnFinishedChangingProperties(const FPropertyChangedEvent& PropertyChangedEvent)
{
	if (MenuAsset)
	{
		MenuAsset->MarkPackageDirty();
	}

	const FName PropertyName = PropertyChangedEvent.GetPropertyName();
	const FName MemberPropertyName = PropertyChangedEvent.MemberProperty ? PropertyChangedEvent.MemberProperty->GetFName() : NAME_None;
	if (URootMenuDataNode* RootMenuDataNode = Cast<URootMenuDataNode>(CurrentDetailsObject.Get()))
	{
		const bool bShouldParseMenuTable =
			PropertyName == GET_MEMBER_NAME_CHECKED(URootMenuDataNode, MenuTable)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(FMenuIDTableRow, MenuID)
			|| PropertyName == GET_MEMBER_NAME_CHECKED(FMenuIDTableRow, MenuTag)
			|| MemberPropertyName == GET_MEMBER_NAME_CHECKED(URootMenuDataNode, MenuID);

		if (bShouldParseMenuTable && RootMenuDataNode->MenuTable)
		{
			if (ImportMenuRows(RootMenuDataNode->MenuTable))
			{
				ShowDataTableOperationResult(LOCTEXT("RootMenuTableParsed", "Menu table parsed."), true);
			}
			return;
		}
	}

	if (GraphEditor)
	{
		GraphEditor->NotifyGraphChanged();
	}
}

void FMenuAssetEditorToolkit::BindCommands()
{
	GraphEditorCommands = MakeShared<FUICommandList>();
	GraphEditorCommands->MapAction(FGenericCommands::Get().SelectAll,
		FExecuteAction::CreateSP(this, &FMenuAssetEditorToolkit::SelectAllNodes),
		FCanExecuteAction::CreateSP(this, &FMenuAssetEditorToolkit::CanSelectAllNodes));
	GraphEditorCommands->MapAction(FGenericCommands::Get().Delete,
		FExecuteAction::CreateSP(this, &FMenuAssetEditorToolkit::DeleteSelectedNodes),
		FCanExecuteAction::CreateSP(this, &FMenuAssetEditorToolkit::CanDeleteSelectedNodes));
}

void FMenuAssetEditorToolkit::ExtendDataTableToolbar()
{
	TSharedPtr<FExtender> ToolbarExtender = MakeShared<FExtender>();
	ToolbarExtender->AddToolBarExtension(
		TEXT("Asset"),
		EExtensionHook::After,
		GraphEditorCommands,
		FToolBarExtensionDelegate::CreateSP(this, &FMenuAssetEditorToolkit::FillDataTableToolbar));
	AddToolbarExtender(ToolbarExtender);
}

void FMenuAssetEditorToolkit::FillDataTableToolbar(FToolBarBuilder& ToolbarBuilder)
{
	ToolbarBuilder.BeginSection(TEXT("DataTable"));
	ToolbarBuilder.AddToolBarButton(
		FUIAction(FExecuteAction::CreateSP(this, &FMenuAssetEditorToolkit::ImportFromDataTable)),
		NAME_None,
		LOCTEXT("ImportFromDataTable", "Import"),
		LOCTEXT("ImportFromDataTableTooltip", "Import this menu tree from a MenuTableRow DataTable."),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), TEXT("Icons.Import")));
	ToolbarBuilder.AddToolBarButton(
		FUIAction(FExecuteAction::CreateSP(this, &FMenuAssetEditorToolkit::ExportToDataTable)),
		NAME_None,
		LOCTEXT("ExportToDataTable", "Export"),
		LOCTEXT("ExportToDataTableTooltip", "Export this menu tree to a MenuTableRow DataTable."),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), TEXT("Icons.Toolbar.Export")));
	ToolbarBuilder.EndSection();
}

void FMenuAssetEditorToolkit::ImportFromDataTable()
{
	FOpenAssetDialogConfig OpenAssetDialogConfig;
	OpenAssetDialogConfig.DialogTitleOverride = LOCTEXT("ImportDataTableDialogTitle", "Import Menu From DataTable");
	OpenAssetDialogConfig.AssetClassNames.Add(UDataTable::StaticClass()->GetClassPathName());
	OpenAssetDialogConfig.bAllowMultipleSelection = false;

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	const TArray<FAssetData> SelectedAssets = ContentBrowserModule.Get().CreateModalOpenAssetDialog(OpenAssetDialogConfig);
	if (SelectedAssets.IsEmpty())
	{
		return;
	}

	UDataTable* SelectedDataTable = Cast<UDataTable>(SelectedAssets[0].GetAsset());
	if (!SelectedDataTable)
	{
		ShowDataTableOperationResult(LOCTEXT("ImportDataTableMissingAsset", "Menu import failed: selected asset is not a DataTable."), false);
		return;
	}

	if (ImportMenuRows(SelectedDataTable))
	{
		ShowDataTableOperationResult(LOCTEXT("ImportDataTableSucceeded", "Menu import succeeded."), true);
	}
}

void FMenuAssetEditorToolkit::ExportToDataTable()
{
	FDataValidationContext ValidationContext;
	if (!ValidateMenuAssetForExport(ValidationContext))
	{
		ShowDataTableOperationResult(FText::Format(LOCTEXT("ExportValidationFailed", "Menu export failed: menu asset validation failed with {0} error(s), {1} warning(s)."),
			FText::AsNumber(ValidationContext.GetNumErrors()),
			FText::AsNumber(ValidationContext.GetNumWarnings())), false);
		return;
	}

	FSaveAssetDialogConfig SaveAssetDialogConfig;
	SaveAssetDialogConfig.DialogTitleOverride = LOCTEXT("ExportDataTableDialogTitle", "Export Menu To DataTable");
	SaveAssetDialogConfig.DefaultPath = MenuAsset ? FPackageName::GetLongPackagePath(MenuAsset->GetOutermost()->GetName()) : TEXT("/Game");
	SaveAssetDialogConfig.DefaultAssetName = MenuAsset ? FString::Printf(TEXT("DT_%s"), *MenuAsset->GetName()) : TEXT("DT_Menu");
	SaveAssetDialogConfig.AssetClassNames.Add(UDataTable::StaticClass()->GetClassPathName());
	SaveAssetDialogConfig.ExistingAssetPolicy = ESaveAssetDialogExistingAssetPolicy::AllowButWarn;

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
	const FString SaveObjectPath = ContentBrowserModule.Get().CreateModalSaveAssetDialog(SaveAssetDialogConfig);
	if (SaveObjectPath.IsEmpty())
	{
		return;
	}

	UDataTable* TargetDataTable = ResolveExportDataTable(SaveObjectPath);
	if (!TargetDataTable)
	{
		return;
	}

	if (!ExportMenuRows(TargetDataTable))
	{
		return;
	}

	TArray<UPackage*> PackagesToSave;
	PackagesToSave.Add(TargetDataTable->GetOutermost());
	const bool bSaved = UEditorLoadingAndSavingUtils::SavePackages(PackagesToSave, false);
	ShowDataTableOperationResult(
		bSaved
			? LOCTEXT("ExportDataTableSucceeded", "Menu export succeeded.")
			: LOCTEXT("ExportDataTableSaveFailed", "Menu export failed: could not save the target DataTable package."),
		bSaved);
}

void FMenuAssetEditorToolkit::SetDetailsObject(UObject* InObject)
{
	if (!DetailsView)
	{
		return;
	}

	if (InObject)
	{
		if (!bDetailsViewIsEmpty && CurrentDetailsObject.Get() == InObject)
		{
			return;
		}

		CurrentDetailsObject = InObject;
		bDetailsViewIsEmpty = false;
		DetailsView->SetObject(InObject, true);
		return;
	}

	if (bDetailsViewIsEmpty)
	{
		return;
	}

	CurrentDetailsObject = nullptr;
	bDetailsViewIsEmpty = true;
	TArray<UObject*> EmptyObjects;
	DetailsView->SetObjects(EmptyObjects, true);
}

void FMenuAssetEditorToolkit::SelectAllNodes()
{
	if (GraphEditor)
	{
		GraphEditor->SelectAllNodes();
	}
}

bool FMenuAssetEditorToolkit::CanSelectAllNodes() const
{
	return GraphEditor.IsValid();
}

void FMenuAssetEditorToolkit::DeleteSelectedNodes()
{
	if (!GraphEditor || !MenuAsset || !MenuGraph)
	{
		return;
	}

	const FScopedTransaction Transaction(LOCTEXT("DeleteMenuNodes", "Delete Menu Nodes"));
	MenuGraph->SyncNodePositionsToAsset();
	MenuAsset->Modify();

	TArray<UMenuNode*> NodesToDelete;
	for (UObject* SelectedObject : GraphEditor->GetSelectedNodes())
	{
		if (UMenuGraphNode* MenuGraphNode = Cast<UMenuGraphNode>(SelectedObject))
		{
			if (MenuGraphNode->MenuNode && !MenuAsset->IsRootNode(MenuGraphNode->MenuNode))
			{
				NodesToDelete.Add(MenuGraphNode->MenuNode);
			}
		}
	}

	for (UMenuNode* NodeToDelete : NodesToDelete)
	{
		MenuAsset->DeleteNode(NodeToDelete);
	}

	GraphEditor->ClearSelectionSet();
	MenuGraph->RebuildGraph();
	SetDetailsObject(nullptr);
}

bool FMenuAssetEditorToolkit::CanDeleteSelectedNodes() const
{
	if (!GraphEditor || !MenuAsset)
	{
		return false;
	}

	for (UObject* SelectedObject : GraphEditor->GetSelectedNodes())
	{
		if (const UMenuGraphNode* MenuGraphNode = Cast<UMenuGraphNode>(SelectedObject))
		{
			if (MenuGraphNode->MenuNode && !MenuAsset->IsRootNode(MenuGraphNode->MenuNode))
			{
				return true;
			}
		}
	}

	return false;
}

void FMenuAssetEditorToolkit::RefreshEditorGraph()
{
	if (MenuAsset)
	{
		MenuAsset->EnsureRootNode();
	}

	if (MenuGraph)
	{
		MenuGraph->RebuildGraph();
	}

	if (GraphEditor)
	{
		GraphEditor->NotifyGraphChanged();
	}

	if (DetailsView)
	{
		SetDetailsObject(nullptr);
	}
}

void FMenuAssetEditorToolkit::SyncAssetBeforeSave() const
{
	if (MenuGraph)
	{
		MenuGraph->SyncNodePositionsToAsset();
	}

	if (MenuAsset)
	{
		MenuAsset->EnsureRootNode();
		MenuAsset->MarkPackageDirty();
	}
}

bool FMenuAssetEditorToolkit::ValidateMenuAssetForExport(FDataValidationContext& ValidationContext) const
{
	if (!MenuAsset)
	{
		ValidationContext.AddError(LOCTEXT("ExportMissingMenuAsset", "Menu export failed because the MenuAsset is missing."));
		return false;
	}

	SyncAssetBeforeSave();
	const EDataValidationResult ValidationResult = MenuAsset->IsDataValid(ValidationContext);
	return ValidationResult != EDataValidationResult::Invalid;
}

bool FMenuAssetEditorToolkit::ImportMenuRows(UDataTable* InDataTable)
{
	if (!MenuAsset || !InDataTable)
	{
		ShowDataTableOperationResult(LOCTEXT("ImportMissingInput", "Menu import failed: MenuAsset or DataTable is missing."), false);
		return false;
	}

	if (InDataTable->RowStruct != FMenuTableRow::StaticStruct())
	{
		ShowDataTableOperationResult(LOCTEXT("ImportInvalidRowStruct", "Menu import failed: DataTable must use MenuTableRow."), false);
		return false;
	}

	MenuAsset->EnsureRootNode();
	URootMenuDataNode* RootMenuDataNode = Cast<URootMenuDataNode>(MenuAsset->RootNode);
	if (!RootMenuDataNode)
	{
		ShowDataTableOperationResult(LOCTEXT("ImportMissingRootDataNode", "Menu import failed: MenuAsset root must be a RootMenuDataNode."), false);
		return false;
	}

	FDataValidationContext ValidationContext;
	TArray<FMenuImportRow> ExplicitRows;
	TSet<FString> MenuIDs;
	TMap<FString, int32> ExplicitRowIndexByMenuID;
	bool bIsValid = true;
	int32 SourceIndex = 0;

	InDataTable->ForeachRow<FMenuTableRow>(TEXT("MenuAssetImport"), [&](const FName& RowName, const FMenuTableRow& Row)
	{
		FMenuImportRow ImportRow;
		ImportRow.RowName = RowName;
		ImportRow.MenuData = Row;
		ImportRow.MenuData.MenuID.SyncMenuIDFromTag();
		ImportRow.MenuID = ImportRow.MenuData.MenuID.GetResolvedMenuID().TrimStartAndEnd();
		ImportRow.SourceIndex = SourceIndex++;

		if (ImportRow.MenuData.IsDataValid(ValidationContext) == EDataValidationResult::Invalid)
		{
			bIsValid = false;
		}

		TArray<FString> MenuIDSegments;
		FText MenuIDError;
		if (!FMenuIDTableRow::SplitMenuIDPath(ImportRow.MenuID, MenuIDSegments, &MenuIDError))
		{
			ValidationContext.AddError(FText::Format(LOCTEXT("ImportInvalidMenuID", "MenuID '{0}' in row '{1}' is not a valid GameplayUI.Button menu path. {2}"),
				FText::FromString(ImportRow.MenuID),
				FText::FromName(RowName),
				MenuIDError));
			bIsValid = false;
		}

		if (ImportRow.MenuID == FMenuIDTableRow::GetMenuIDRootPath())
		{
			ValidationContext.AddError(FText::Format(LOCTEXT("ImportRootMenuID", "MenuID '{0}' in row '{1}' is reserved by MenuAsset root."),
				FText::FromString(FMenuIDTableRow::GetMenuIDRootPath()),
				FText::FromName(RowName)));
			bIsValid = false;
		}

		if (MenuIDs.Contains(ImportRow.MenuID))
		{
			ValidationContext.AddError(FText::Format(LOCTEXT("ImportDuplicateMenuID", "MenuID '{0}' is duplicated in the selected DataTable."),
				FText::FromString(ImportRow.MenuID)));
			bIsValid = false;
		}
		else
		{
			MenuIDs.Add(ImportRow.MenuID);
		}

		ImportRow.Depth = MenuIDSegments.Num();
		ExplicitRowIndexByMenuID.Add(ImportRow.MenuID, ExplicitRows.Num());
		ExplicitRows.Add(ImportRow);
	});

	if (!bIsValid)
	{
		ShowDataTableOperationResult(FText::Format(LOCTEXT("ImportValidationFailed", "Menu import failed: {0} error(s), {1} warning(s)."),
			FText::AsNumber(ValidationContext.GetNumErrors()),
			FText::AsNumber(ValidationContext.GetNumWarnings())), false);
		return false;
	}

	FString RootMenuID = RootMenuDataNode->MenuID.GetResolvedMenuID().TrimStartAndEnd();
	if (RootMenuID.IsEmpty())
	{
		RootMenuID = FMenuIDTableRow::GetMenuIDRootPath();
	}

	bool bRootHasExplicitRow = ExplicitRowIndexByMenuID.Contains(RootMenuID);
	if (!bRootHasExplicitRow)
	{
		TArray<TSharedPtr<FRootMenuIDCandidate>> RootMenuIDCandidates;
		BuildRootMenuIDCandidates(ExplicitRows, RootMenuIDCandidates);
		if (!PickRootMenuID(RootMenuIDCandidates, RootMenuID))
		{
			ShowDataTableOperationResult(LOCTEXT("ImportRootMenuIDSelectionCanceled", "Menu import canceled: no root MenuID was selected."), false);
			return false;
		}
		bRootHasExplicitRow = ExplicitRowIndexByMenuID.Contains(RootMenuID);
	}

	TArray<FString> RootMenuIDSegments;
	if (!SplitMenuIDPathAllowRoot(RootMenuID, RootMenuIDSegments))
	{
		ShowDataTableOperationResult(LOCTEXT("ImportInvalidRootMenuID", "Menu import failed: selected root MenuID is invalid."), false);
		return false;
	}

	TMap<FString, FMenuImportRow> RowsByMenuID;
	for (FMenuImportRow ImportRow : ExplicitRows)
	{
		if (ImportRow.MenuID == RootMenuID || !IsMenuIDUnderRoot(ImportRow.MenuID, RootMenuID))
		{
			continue;
		}

		ImportRow.Depth = GetRelativeMenuIDDepth(RootMenuID, ImportRow.MenuID);
		RowsByMenuID.Add(ImportRow.MenuID, ImportRow);
	}

	TArray<FMenuImportRow> RowsToInspect;
	RowsByMenuID.GenerateValueArray(RowsToInspect);
	for (const FMenuImportRow& ImportRow : RowsToInspect)
	{
		AddMissingParentImportRows(ImportRow.MenuID, RootMenuID, ImportRow.SourceIndex, RowsByMenuID);
	}

	TArray<FMenuImportRow> ImportRows;
	RowsByMenuID.GenerateValueArray(ImportRows);
	for (FMenuImportRow& ImportRow : ImportRows)
	{
		const FString ParentMenuID = GetParentMenuID(ImportRow.MenuID);
		ImportRow.InferredParentMenuID = ParentMenuID == RootMenuID ? FString() : ParentMenuID;
		ImportRow.Depth = GetRelativeMenuIDDepth(RootMenuID, ImportRow.MenuID);
	}
	ImportRows.Sort([](const FMenuImportRow& Left, const FMenuImportRow& Right)
	{
		if (Left.Depth != Right.Depth)
		{
			return Left.Depth < Right.Depth;
		}

		if (Left.SourceIndex != Right.SourceIndex)
		{
			return Left.SourceIndex < Right.SourceIndex;
		}

		return Left.MenuID < Right.MenuID;
	});

	const FScopedTransaction Transaction(LOCTEXT("ImportMenuFromDataTableTransaction", "Import Menu From DataTable"));
	MenuAsset->Modify();
	RootMenuDataNode->Modify();
	RootMenuDataNode->MenuTable = InDataTable;
	if (bRootHasExplicitRow)
	{
		const int32 RootRowIndex = ExplicitRowIndexByMenuID.FindChecked(RootMenuID);
		const FMenuImportRow& RootImportRow = ExplicitRows[RootRowIndex];
		RootMenuDataNode->MenuID = RootImportRow.MenuData.MenuID;
		RootMenuDataNode->ContainerEntry = RootImportRow.MenuData.ContainerEntry;
	}
	else
	{
		RootMenuDataNode->MenuID.MenuID = RootMenuID;
		RootMenuDataNode->MenuID.NormalizeMenuID();
	}

	for (const TObjectPtr<UMenuNode>& ExistingNode : MenuAsset->AllNodes)
	{
		if (ExistingNode)
		{
			ExistingNode->Modify();
			ExistingNode->Children.Reset();
			if (ExistingNode != MenuAsset->RootNode)
			{
				ExistingNode->SetParent(nullptr);
			}
		}
	}

	UMenuNode* RootNode = RootMenuDataNode;
	RootNode->Modify();
	RootNode->Children.Reset();
	MenuAsset->AllNodes.Reset();
	MenuAsset->AllNodes.Add(RootNode);

	TMap<FString, UMenuNode*> CreatedNodes;
	for (int32 RowIndex = 0; RowIndex < ImportRows.Num(); ++RowIndex)
	{
		const FMenuImportRow& ImportRow = ImportRows[RowIndex];
		UMenuDataNode* NewNode = NewObject<UMenuDataNode>(MenuAsset, NAME_None, RF_Transactional);
		NewNode->Modify();
		NewNode->MenuData = ImportRow.MenuData;
		NewNode->GraphPosition = FVector2D(static_cast<double>(ImportRow.Depth) * 360.0, static_cast<double>(RowIndex) * 160.0);
		MenuAsset->AllNodes.Add(NewNode);
		CreatedNodes.Add(ImportRow.MenuID, NewNode);
	}

	for (const FMenuImportRow& ImportRow : ImportRows)
	{
		UMenuNode* const* NodePtr = CreatedNodes.Find(ImportRow.MenuID);
		if (!NodePtr || !*NodePtr)
		{
			continue;
		}

		UMenuNode* ParentNode = RootNode;
		if (!ImportRow.InferredParentMenuID.IsEmpty())
		{
			if (UMenuNode* const* ParentNodePtr = CreatedNodes.Find(ImportRow.InferredParentMenuID))
			{
				ParentNode = *ParentNodePtr;
			}
		}

		(*NodePtr)->SetParent(ParentNode);
		ParentNode->AddChild(*NodePtr);
	}

	MenuAsset->MarkPackageDirty();
	RefreshEditorGraph();
	return true;
}

bool FMenuAssetEditorToolkit::ExportMenuRows(UDataTable* InDataTable) const
{
	if (!MenuAsset || !InDataTable)
	{
		ShowDataTableOperationResult(LOCTEXT("ExportMissingInput", "Menu export failed: MenuAsset or DataTable is missing."), false);
		return false;
	}

	if (InDataTable->RowStruct && InDataTable->RowStruct != FMenuTableRow::StaticStruct())
	{
		ShowDataTableOperationResult(LOCTEXT("ExportInvalidRowStruct", "Menu export failed: target DataTable must use MenuTableRow."), false);
		return false;
	}

	TArray<FMenuTableRow> ExportRows;
	if (MenuAsset->RootNode)
	{
		if (const URootMenuDataNode* RootMenuDataNode = Cast<URootMenuDataNode>(MenuAsset->RootNode))
		{
			const FString RootMenuID = RootMenuDataNode->MenuID.GetResolvedMenuID().TrimStartAndEnd();
			if (!RootMenuID.IsEmpty() && RootMenuID != FMenuIDTableRow::GetMenuIDRootPath())
			{
				FMenuTableRow RootRow;
				RootRow.MenuID = RootMenuDataNode->MenuID;
				RootRow.ContainerEntry = RootMenuDataNode->ContainerEntry;
				ExportRows.Add(RootRow);
			}
		}

		for (const TObjectPtr<UMenuNode>& ChildNode : MenuAsset->RootNode->Children)
		{
			CollectExportRows(ChildNode, ExportRows);
		}
	}

	InDataTable->Modify();
	InDataTable->RowStruct = FMenuTableRow::StaticStruct();
	InDataTable->EmptyTable();
	for (FMenuTableRow ExportRow : ExportRows)
	{
		ExportRow.MenuID.SyncMenuIDFromTag();
		const FString MenuID = ExportRow.MenuID.GetResolvedMenuID().TrimStartAndEnd();
		if (!MenuID.IsEmpty())
		{
			InDataTable->AddRow(FName(*MenuID), ExportRow);
		}
	}
	InDataTable->HandleDataTableChanged();
	InDataTable->MarkPackageDirty();
	InDataTable->PostEditChange();
	return true;
}

UDataTable* FMenuAssetEditorToolkit::ResolveExportDataTable(const FString& InSaveObjectPath) const
{
	if (!FPackageName::IsValidObjectPath(InSaveObjectPath))
	{
		ShowDataTableOperationResult(LOCTEXT("ExportInvalidObjectPath", "Menu export failed: selected DataTable path is invalid."), false);
		return nullptr;
	}

	if (UObject* ExistingObject = StaticLoadObject(UObject::StaticClass(), nullptr, *InSaveObjectPath))
	{
		UDataTable* ExistingDataTable = Cast<UDataTable>(ExistingObject);
		if (!ExistingDataTable)
		{
			ShowDataTableOperationResult(LOCTEXT("ExportExistingNotDataTable", "Menu export failed: selected existing asset is not a DataTable."), false);
			return nullptr;
		}

		if (ExistingDataTable->RowStruct != FMenuTableRow::StaticStruct())
		{
			ShowDataTableOperationResult(LOCTEXT("ExportExistingWrongRowStruct", "Menu export failed: selected existing DataTable must use MenuTableRow."), false);
			return nullptr;
		}

		return ExistingDataTable;
	}

	const FString PackageName = FPackageName::ObjectPathToPackageName(InSaveObjectPath);
	const FString PackagePath = FPackageName::GetLongPackagePath(PackageName);
	const FString AssetName = FPackageName::GetLongPackageAssetName(PackageName);

	UDataTableFactory* DataTableFactory = NewObject<UDataTableFactory>();
	DataTableFactory->Struct = FMenuTableRow::StaticStruct();

	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
	UDataTable* NewDataTable = Cast<UDataTable>(AssetToolsModule.Get().CreateAsset(AssetName, PackagePath, UDataTable::StaticClass(), DataTableFactory));
	if (!NewDataTable)
	{
		ShowDataTableOperationResult(LOCTEXT("ExportCreateDataTableFailed", "Menu export failed: could not create the target DataTable."), false);
	}
	return NewDataTable;
}

void FMenuAssetEditorToolkit::CollectExportRows(UMenuNode* InNode, TArray<FMenuTableRow>& OutRows) const
{
	if (!InNode)
	{
		return;
	}

	if (const UMenuDataNode* MenuDataNode = Cast<UMenuDataNode>(InNode))
	{
		OutRows.Add(MenuDataNode->MenuData);
	}
	for (const TObjectPtr<UMenuNode>& ChildNode : InNode->Children)
	{
		CollectExportRows(ChildNode, OutRows);
	}
}

void FMenuAssetEditorToolkit::ShowSaveValidationResult(bool bSucceeded, const FDataValidationContext& ValidationContext) const
{
	const FText Message = bSucceeded
		? FText::Format(LOCTEXT("SaveValidationSucceeded", "Menu asset validation passed: {0} warning(s)."),
			FText::AsNumber(ValidationContext.GetNumWarnings()))
		: FText::Format(LOCTEXT("SaveValidationFailed", "Menu asset save blocked: {0} error(s), {1} warning(s)."),
			FText::AsNumber(ValidationContext.GetNumErrors()),
			FText::AsNumber(ValidationContext.GetNumWarnings()));

	FNotificationInfo NotificationInfo(Message);
	NotificationInfo.ExpireDuration = 3.0f;

	TSharedPtr<SNotificationItem> Notification = FSlateNotificationManager::Get().AddNotification(NotificationInfo);
	if (Notification.IsValid())
	{
		Notification->SetCompletionState(bSucceeded ? SNotificationItem::CS_Success : SNotificationItem::CS_Fail);
	}
}

void FMenuAssetEditorToolkit::ShowDataTableOperationResult(const FText& InMessage, bool bSucceeded) const
{
	FNotificationInfo NotificationInfo(InMessage);
	NotificationInfo.ExpireDuration = 3.0f;

	TSharedPtr<SNotificationItem> Notification = FSlateNotificationManager::Get().AddNotification(NotificationInfo);
	if (Notification.IsValid())
	{
		Notification->SetCompletionState(bSucceeded ? SNotificationItem::CS_Success : SNotificationItem::CS_Fail);
	}
}

#undef LOCTEXT_NAMESPACE
