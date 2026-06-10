// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUndoClient.h"
#include "GraphEditor.h"
#include "Toolkits/AssetEditorToolkit.h"
#include "UObject/GCObject.h"

class IDetailsView;
class UMenuAsset;
class UMenuGraph;
class UDataTable;
class FDataValidationContext;
class FToolBarBuilder;
struct FPropertyChangedEvent;

/** Editor toolkit for menu tree assets. */
class FMenuAssetEditorToolkit : public FAssetEditorToolkit, public FGCObject, public FEditorUndoClient
{
public:
	FMenuAssetEditorToolkit();
	virtual ~FMenuAssetEditorToolkit() override;

	void InitMenuAssetEditor(EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UMenuAsset* InMenuAsset);

	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	virtual FString GetReferencerName() const override;
	virtual void PostUndo(bool bSuccess) override;
	virtual void PostRedo(bool bSuccess) override;
	virtual void SaveAsset_Execute() override;

private:
	void CreateInternalWidgets();
	TSharedRef<SGraphEditor> CreateGraphEditorWidget();
	TSharedRef<SDockTab> SpawnTab_Graph(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_Details(const FSpawnTabArgs& Args);
	void OnSelectedNodesChanged(const TSet<UObject*>& NewSelection);
	void OnFinishedChangingProperties(const FPropertyChangedEvent& PropertyChangedEvent);
	void BindCommands();
	void ExtendDataTableToolbar();
	void FillDataTableToolbar(FToolBarBuilder& ToolbarBuilder);
	void ImportFromDataTable();
	void ExportToDataTable();
	void SetDetailsObject(UObject* InObject);
	void SelectAllNodes();
	bool CanSelectAllNodes() const;
	void DeleteSelectedNodes();
	bool CanDeleteSelectedNodes() const;
	void RefreshEditorGraph();
	void SyncAssetBeforeSave() const;
	bool ValidateMenuAssetForExport(FDataValidationContext& ValidationContext) const;
	bool ImportMenuRows(UDataTable* InDataTable);
	bool ExportMenuRows(UDataTable* InDataTable) const;
	UDataTable* ResolveExportDataTable(const FString& InSaveObjectPath) const;
	void CollectExportRows(class UMenuNode* InNode, TArray<struct FMenuTableRow>& OutRows) const;
	void ShowSaveValidationResult(bool bSucceeded, const FDataValidationContext& ValidationContext) const;
	void ShowDataTableOperationResult(const FText& InMessage, bool bSucceeded) const;

private:
	TObjectPtr<UMenuAsset> MenuAsset = nullptr;
	TObjectPtr<UMenuGraph> MenuGraph = nullptr;
	TSharedPtr<SGraphEditor> GraphEditor;
	TSharedPtr<IDetailsView> DetailsView;
	TSharedPtr<FUICommandList> GraphEditorCommands;
	TWeakObjectPtr<UObject> CurrentDetailsObject;
	bool bDetailsViewIsEmpty = true;

	static const FName GraphTabId;
	static const FName DetailsTabId;
};
