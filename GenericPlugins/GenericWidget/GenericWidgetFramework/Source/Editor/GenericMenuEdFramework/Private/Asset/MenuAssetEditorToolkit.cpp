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
#include "MenuType.h"
#include "IContentBrowserSingleton.h"
#include "Misc/DataValidation.h"
#include "Misc/PackageName.h"
#include "PropertyEditorModule.h"
#include "ScopedTransaction.h"
#include "Styling/AppStyle.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Notifications/SNotificationList.h"

#define LOCTEXT_NAMESPACE "MenuAssetEditorToolkit"

namespace
{
struct FMenuImportRow
{
	FName RowName;
	FMenuTableRow MenuData;
	FString MenuID;
	FString ParentMenuID;
	int32 Depth = 0;
};

bool SplitMenuID(const FString& InMenuID, TArray<FString>& OutSegments)
{
	InMenuID.ParseIntoArray(OutSegments, TEXT("."), false);
	if (OutSegments.IsEmpty())
	{
		return false;
	}

	FString RebuiltMenuID;
	for (int32 SegmentIndex = 0; SegmentIndex < OutSegments.Num(); ++SegmentIndex)
	{
		OutSegments[SegmentIndex] = OutSegments[SegmentIndex].TrimStartAndEnd();
		if (OutSegments[SegmentIndex].IsEmpty())
		{
			return false;
		}

		if (SegmentIndex > 0)
		{
			RebuiltMenuID += TEXT(".");
		}
		RebuiltMenuID += OutSegments[SegmentIndex];
	}

	return RebuiltMenuID == InMenuID.TrimStartAndEnd();
}

FString GetParentMenuID(const TArray<FString>& InSegments)
{
	if (InSegments.Num() <= 1)
	{
		return FString();
	}

	FString ParentMenuID = InSegments[0];
	for (int32 SegmentIndex = 1; SegmentIndex < InSegments.Num() - 1; ++SegmentIndex)
	{
		ParentMenuID += TEXT(".");
		ParentMenuID += InSegments[SegmentIndex];
	}
	return ParentMenuID;
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
		SetDetailsObject(SelectedGraphNode);
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

	FDataValidationContext ValidationContext;
	TArray<FMenuImportRow> ImportRows;
	TSet<FString> MenuIDs;
	bool bIsValid = true;

	InDataTable->ForeachRow<FMenuTableRow>(TEXT("MenuAssetImport"), [&](const FName& RowName, const FMenuTableRow& Row)
	{
		FMenuImportRow ImportRow;
		ImportRow.RowName = RowName;
		ImportRow.MenuData = Row;
		ImportRow.MenuData.MenuID.SyncMenuIDFromTag();
		ImportRow.MenuID = ImportRow.MenuData.MenuID.GetResolvedMenuID().TrimStartAndEnd();

		if (ImportRow.MenuData.IsDataValid(ValidationContext) == EDataValidationResult::Invalid)
		{
			bIsValid = false;
		}

		TArray<FString> MenuIDSegments;
		if (!SplitMenuID(ImportRow.MenuID, MenuIDSegments))
		{
			ValidationContext.AddError(FText::Format(LOCTEXT("ImportInvalidMenuID", "MenuID '{0}' in row '{1}' is not a valid dotted menu path."),
				FText::FromString(ImportRow.MenuID),
				FText::FromName(RowName)));
			bIsValid = false;
		}

		if (ImportRow.MenuID == TEXT("Root"))
		{
			ValidationContext.AddError(FText::Format(LOCTEXT("ImportRootMenuID", "MenuID 'Root' in row '{0}' is reserved by MenuAsset root."),
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

		ImportRow.ParentMenuID = GetParentMenuID(MenuIDSegments);
		ImportRow.Depth = MenuIDSegments.Num();
		ImportRows.Add(ImportRow);
	});

	for (const FMenuImportRow& ImportRow : ImportRows)
	{
		if (!ImportRow.ParentMenuID.IsEmpty() && !MenuIDs.Contains(ImportRow.ParentMenuID))
		{
			ValidationContext.AddError(FText::Format(LOCTEXT("ImportMissingParent", "MenuID '{0}' requires missing parent MenuID '{1}'."),
				FText::FromString(ImportRow.MenuID),
				FText::FromString(ImportRow.ParentMenuID)));
			bIsValid = false;
		}
	}

	if (!bIsValid)
	{
		ShowDataTableOperationResult(FText::Format(LOCTEXT("ImportValidationFailed", "Menu import failed: {0} error(s), {1} warning(s)."),
			FText::AsNumber(ValidationContext.GetNumErrors()),
			FText::AsNumber(ValidationContext.GetNumWarnings())), false);
		return false;
	}

	const FScopedTransaction Transaction(LOCTEXT("ImportMenuFromDataTableTransaction", "Import Menu From DataTable"));
	MenuAsset->Modify();
	MenuAsset->EnsureRootNode();

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

	UMenuNode* RootNode = MenuAsset->RootNode;
	RootNode->Modify();
	RootNode->Children.Reset();
	MenuAsset->AllNodes.Reset();
	MenuAsset->AllNodes.Add(RootNode);

	TMap<FString, UMenuNode*> CreatedNodes;
	for (int32 RowIndex = 0; RowIndex < ImportRows.Num(); ++RowIndex)
	{
		const FMenuImportRow& ImportRow = ImportRows[RowIndex];
		UMenuNode* NewNode = NewObject<UMenuNode>(MenuAsset, NAME_None, RF_Transactional);
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
		if (!ImportRow.ParentMenuID.IsEmpty())
		{
			if (UMenuNode* const* ParentNodePtr = CreatedNodes.Find(ImportRow.ParentMenuID))
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

	OutRows.Add(InNode->MenuData);
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
