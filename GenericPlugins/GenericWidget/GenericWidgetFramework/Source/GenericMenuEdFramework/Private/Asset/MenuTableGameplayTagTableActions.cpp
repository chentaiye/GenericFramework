// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Asset/MenuTableGameplayTagTableActions.h"

#include "AssetToolsModule.h"
#include "ContentBrowserMenuContexts.h"
#include "ContentBrowserModule.h"
#include "Engine/DataTable.h"
#include "Factories/DataTableFactory.h"
#include "FileHelpers.h"
#include "Framework/Application/SlateApplication.h"
#include "Framework/Notifications/NotificationManager.h"
#include "GameplayTagContainer.h"
#include "GameplayTagsManager.h"
#include "IContentBrowserSingleton.h"
#include "MenuType.h"
#include "Modules/ModuleManager.h"
#include "Misc/PackageName.h"
#include "Styling/AppStyle.h"
#include "ToolMenuSection.h"
#include "ToolMenus.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Notifications/SNotificationList.h"
#include "Widgets/SNullWidget.h"
#include "Widgets/SWindow.h"
#include "Widgets/Text/STextBlock.h"

#define LOCTEXT_NAMESPACE "FMenuTableGameplayTagTableActions"

namespace
{
struct FPreparedGameplayTagRow
{
	FName RowName;
	FGameplayTagTableRow Row;
};

struct FPreparedGameplayTagTable
{
	UDataTable* SourceMenuTable = nullptr;
	TArray<FPreparedGameplayTagRow> Rows;
};

struct FPreparedMenuRow
{
	FName RowName;
	FMenuTableRow Row;
};

const FName RowStructureTagName(TEXT("RowStructure"));

bool IsMenuTableAssetData(const FAssetData& InAssetData)
{
	if (!InAssetData.IsInstanceOf(UDataTable::StaticClass()))
	{
		return false;
	}

	FString RowStructure;
	if (!InAssetData.GetTagValue(RowStructureTagName, RowStructure))
	{
		return false;
	}

	return RowStructure == FMenuTableRow::StaticStruct()->GetStructPathName().ToString();
}

bool HasSelectedMenuTable(const UContentBrowserAssetContextMenuContext* InContext)
{
	if (!InContext)
	{
		return false;
	}

	return InContext->SelectedAssets.ContainsByPredicate([](const FAssetData& AssetData)
	{
		return IsMenuTableAssetData(AssetData);
	});
}

TArray<UDataTable*> LoadSelectedMenuTables(const UContentBrowserAssetContextMenuContext* InContext)
{
	if (!InContext)
	{
		return {};
	}

	return InContext->LoadSelectedObjectsIf<UDataTable>([](const FAssetData& AssetData)
	{
		return IsMenuTableAssetData(AssetData);
	});
}

FString GetDefaultSelectedAssetPath(const UContentBrowserAssetContextMenuContext* InContext)
{
	if (!InContext)
	{
		return TEXT("/Game");
	}

	for (const FAssetData& AssetData : InContext->SelectedAssets)
	{
		if (IsMenuTableAssetData(AssetData))
		{
			return AssetData.PackagePath.ToString();
		}
	}

	return TEXT("/Game");
}

void ShowNotification(const FText& InMessage, SNotificationItem::ECompletionState InCompletionState)
{
	FNotificationInfo NotificationInfo(InMessage);
	NotificationInfo.ExpireDuration = 3.0f;

	TSharedPtr<SNotificationItem> Notification = FSlateNotificationManager::Get().AddNotification(NotificationInfo);
	if (Notification.IsValid())
	{
		Notification->SetCompletionState(InCompletionState);
	}
}

bool PickContentPath(const FString& InDefaultPath, const FText& InTitle, FString& OutSelectedPath)
{
	FString SelectedPath = InDefaultPath.IsEmpty() ? TEXT("/Game") : InDefaultPath;
	bool bAccepted = false;

	FPathPickerConfig PathPickerConfig;
	PathPickerConfig.DefaultPath = SelectedPath;
	PathPickerConfig.OnPathSelected = FOnPathSelected::CreateLambda([&SelectedPath](const FString& InPath)
	{
		SelectedPath = InPath;
	});
	PathPickerConfig.bAllowClassesFolder = false;
	PathPickerConfig.bAllowContextMenu = false;
	PathPickerConfig.bAddDefaultPath = true;
	PathPickerConfig.bFocusSearchBoxWhenOpened = true;

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));

	TSharedPtr<SWindow> PickerWindow;
	SAssignNew(PickerWindow, SWindow)
	.Title(InTitle)
	.ClientSize(FVector2D(420.0f, 520.0f))
	.SupportsMaximize(false)
	.SupportsMinimize(false);

	PickerWindow->SetContent(
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.FillHeight(1.0f)
		[
			ContentBrowserModule.Get().CreatePathPicker(PathPickerConfig)
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		.Padding(8.0f)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.FillWidth(1.0f)
			[
				SNullWidget::NullWidget
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			.Padding(0.0f, 0.0f, 8.0f, 0.0f)
			[
				SNew(SButton)
				.Text(LOCTEXT("AcceptPath", "OK"))
				.OnClicked_Lambda([&bAccepted, &PickerWindow]()
				{
					bAccepted = true;
					if (PickerWindow.IsValid())
					{
						PickerWindow->RequestDestroyWindow();
					}
					return FReply::Handled();
				})
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SButton)
				.Text(LOCTEXT("CancelPath", "Cancel"))
				.OnClicked_Lambda([&PickerWindow]()
				{
					if (PickerWindow.IsValid())
					{
						PickerWindow->RequestDestroyWindow();
					}
					return FReply::Handled();
				})
			]
		]);

	FSlateApplication::Get().AddModalWindow(PickerWindow.ToSharedRef(), nullptr);
	if (!bAccepted || SelectedPath.IsEmpty())
	{
		return false;
	}

	OutSelectedPath = SelectedPath;
	return true;
}

bool IsStrictGameplayUIMenuID(const FString& InTagString, FText* OutError)
{
	const FString TagString = InTagString.TrimStartAndEnd();
	const FString RootPath = FMenuIDTableRow::GetMenuIDRootPath();
	const FString RootPrefix = RootPath + TEXT(".");
	if (TagString == RootPath || !TagString.StartsWith(RootPrefix))
	{
		if (OutError)
		{
			*OutError = LOCTEXT("InvalidGameplayUIMenuID", "Tag must start with GameplayUI.Button and include a value after it.");
		}
		return false;
	}

	TArray<FString> Segments;
	return FMenuIDTableRow::SplitMenuIDPath(TagString, Segments, OutError);
}

bool PrepareGameplayTagRows(UDataTable* InMenuTable, TArray<FPreparedGameplayTagRow>& OutRows, TArray<FText>& OutProblems)
{
	if (!IsValid(InMenuTable) || InMenuTable->GetRowStruct() != FMenuTableRow::StaticStruct())
	{
		OutProblems.Add(LOCTEXT("ExportInvalidMenuTable", "Selected asset is not a MenuTable."));
		return false;
	}

	TSet<FString> UsedTags;
	bool bSucceeded = true;
	InMenuTable->ForeachRow<FMenuTableRow>(TEXT("ExportMenuTableAsGameplayTagTable"), [&](const FName& RowName, const FMenuTableRow& MenuRow)
	{
		const FString TagString = FMenuIDTableRow::MakeMenuID(FMenuIDTableRow::GetEditableMenuIDPath(MenuRow.MenuID.MenuID));

		FText MenuIDError;
		if (!IsStrictGameplayUIMenuID(TagString, &MenuIDError))
		{
			OutProblems.Add(FText::Format(LOCTEXT("ExportInvalidMenuID", "{0}: row '{1}' has invalid MenuID. {2}"),
				FText::FromString(InMenuTable->GetName()),
				FText::FromName(RowName),
				MenuIDError));
			bSucceeded = false;
			return;
		}

		FText GameplayTagError;
		if (!FGameplayTag::IsValidGameplayTagString(TagString, &GameplayTagError))
		{
			OutProblems.Add(FText::Format(LOCTEXT("ExportInvalidGameplayTag", "{0}: MenuID '{1}' cannot be used as a GameplayTag. {2}"),
				FText::FromString(InMenuTable->GetName()),
				FText::FromString(TagString),
				GameplayTagError));
			bSucceeded = false;
			return;
		}

		if (UsedTags.Contains(TagString))
		{
			OutProblems.Add(FText::Format(LOCTEXT("ExportDuplicatedTag", "{0}: duplicated MenuID '{1}'."),
				FText::FromString(InMenuTable->GetName()),
				FText::FromString(TagString)));
			bSucceeded = false;
			return;
		}

		UsedTags.Add(TagString);

		FPreparedGameplayTagRow PreparedRow;
		PreparedRow.RowName = FName(*TagString);
		PreparedRow.Row = FGameplayTagTableRow(FName(*TagString), MenuRow.Description.PrimaryName.ToString());
		OutRows.Add(MoveTemp(PreparedRow));
	});

	return bSucceeded;
}

bool PrepareMenuRows(UDataTable* InGameplayTagTable, TArray<FPreparedMenuRow>& OutRows, TArray<FText>& OutProblems)
{
	if (!IsValid(InGameplayTagTable) || InGameplayTagTable->GetRowStruct() != FGameplayTagTableRow::StaticStruct())
	{
		OutProblems.Add(LOCTEXT("ImportInvalidGameplayTagTable", "Selected asset is not a GameplayTagTable."));
		return false;
	}

	TSet<FString> UsedMenuIDs;
	bool bSucceeded = true;
	InGameplayTagTable->ForeachRow<FGameplayTagTableRow>(TEXT("ImportGameplayTagTableAsMenuTable"), [&](const FName& RowName, const FGameplayTagTableRow& TagRow)
	{
		const FString TagString = TagRow.Tag.ToString().TrimStartAndEnd();

		FText MenuIDError;
		if (!IsStrictGameplayUIMenuID(TagString, &MenuIDError))
		{
			OutProblems.Add(FText::Format(LOCTEXT("ImportInvalidTag", "{0}: row '{1}' has invalid Tag '{2}'. {3}"),
				FText::FromString(InGameplayTagTable->GetName()),
				FText::FromName(RowName),
				FText::FromString(TagString),
				MenuIDError));
			bSucceeded = false;
			return;
		}

		if (UsedMenuIDs.Contains(TagString))
		{
			OutProblems.Add(FText::Format(LOCTEXT("ImportDuplicatedTag", "{0}: duplicated Tag '{1}'."),
				FText::FromString(InGameplayTagTable->GetName()),
				FText::FromString(TagString)));
			bSucceeded = false;
			return;
		}

		UsedMenuIDs.Add(TagString);

		FPreparedMenuRow PreparedRow;
		PreparedRow.RowName = FName(*TagString);
		PreparedRow.Row.MenuID.MenuID = TagString;
		PreparedRow.Row.MenuID.MenuTag.FromExportString(TagString);
		PreparedRow.Row.Description.PrimaryName = FText::FromString(TagRow.DevComment);
		OutRows.Add(MoveTemp(PreparedRow));
	});

	return bSucceeded;
}

UDataTable* CreateDataTableAsset(const FString& InPackagePath, const FString& InBaseAssetName, UScriptStruct* InRowStruct)
{
	if (!InRowStruct)
	{
		return nullptr;
	}

	FString UniquePackageName;
	FString UniqueAssetName;
	FAssetToolsModule& AssetToolsModule = FModuleManager::LoadModuleChecked<FAssetToolsModule>(TEXT("AssetTools"));
	AssetToolsModule.Get().CreateUniqueAssetName(InPackagePath / InBaseAssetName, FString(), UniquePackageName, UniqueAssetName);

	UDataTableFactory* DataTableFactory = NewObject<UDataTableFactory>();
	DataTableFactory->Struct = InRowStruct;

	return Cast<UDataTable>(AssetToolsModule.Get().CreateAsset(
		UniqueAssetName,
		FPackageName::GetLongPackagePath(UniquePackageName),
		UDataTable::StaticClass(),
		DataTableFactory));
}

void FillGameplayTagTable(UDataTable* InTargetTable, const TArray<FPreparedGameplayTagRow>& InRows)
{
	InTargetTable->Modify();
	InTargetTable->RowStruct = FGameplayTagTableRow::StaticStruct();
	InTargetTable->EmptyTable();
	for (const FPreparedGameplayTagRow& PreparedRow : InRows)
	{
		InTargetTable->AddRow(PreparedRow.RowName, PreparedRow.Row);
	}
	InTargetTable->HandleDataTableChanged();
	InTargetTable->MarkPackageDirty();
	InTargetTable->PostEditChange();
}

void FillMenuTable(UDataTable* InTargetTable, const TArray<FPreparedMenuRow>& InRows)
{
	InTargetTable->Modify();
	InTargetTable->RowStruct = FMenuTableRow::StaticStruct();
	InTargetTable->EmptyTable();
	for (const FPreparedMenuRow& PreparedRow : InRows)
	{
		InTargetTable->AddRow(PreparedRow.RowName, PreparedRow.Row);
	}
	InTargetTable->HandleDataTableChanged();
	InTargetTable->MarkPackageDirty();
	InTargetTable->PostEditChange();
}

void ExecuteExportAsGameplayTagTable(const FToolMenuContext& InContext)
{
	const UContentBrowserAssetContextMenuContext* Context = UContentBrowserAssetContextMenuContext::FindContextWithAssets(InContext);
	TArray<UDataTable*> MenuTables = LoadSelectedMenuTables(Context);
	if (MenuTables.IsEmpty())
	{
		ShowNotification(LOCTEXT("ExportNoMenuTables", "Export failed: no MenuTable asset is selected."), SNotificationItem::CS_Fail);
		return;
	}

	FString TargetPath;
	if (!PickContentPath(GetDefaultSelectedAssetPath(Context), LOCTEXT("ExportGameplayTagTablePathTitle", "Export as GameplayTag Table"), TargetPath))
	{
		return;
	}

	TArray<FPreparedGameplayTagTable> PreparedTables;
	TArray<FText> Problems;
	for (UDataTable* MenuTable : MenuTables)
	{
		FPreparedGameplayTagTable PreparedTable;
		PreparedTable.SourceMenuTable = MenuTable;
		if (PrepareGameplayTagRows(MenuTable, PreparedTable.Rows, Problems))
		{
			PreparedTables.Add(MoveTemp(PreparedTable));
		}
	}

	if (!Problems.IsEmpty())
	{
		ShowNotification(Problems[0], SNotificationItem::CS_Fail);
		return;
	}

	TArray<UPackage*> PackagesToSave;
	for (const FPreparedGameplayTagTable& PreparedTable : PreparedTables)
	{
		if (!PreparedTable.SourceMenuTable)
		{
			continue;
		}

		const FString TargetAssetName = FString::Printf(TEXT("%s_GameplayTagTable"), *PreparedTable.SourceMenuTable->GetName());
		UDataTable* TargetTable = CreateDataTableAsset(TargetPath, TargetAssetName, FGameplayTagTableRow::StaticStruct());
		if (!TargetTable)
		{
			ShowNotification(LOCTEXT("ExportCreateTargetFailed", "Export failed: could not create GameplayTagTable asset."), SNotificationItem::CS_Fail);
			return;
		}

		FillGameplayTagTable(TargetTable, PreparedTable.Rows);
		PackagesToSave.Add(TargetTable->GetOutermost());
	}

	const bool bSaved = UEditorLoadingAndSavingUtils::SavePackages(PackagesToSave, false);
	ShowNotification(
		bSaved
			? LOCTEXT("ExportSucceeded", "Export as GameplayTag Table succeeded.")
			: LOCTEXT("ExportSaveFailed", "Export failed: could not save generated GameplayTagTable assets."),
		bSaved ? SNotificationItem::CS_Success : SNotificationItem::CS_Fail);
}

void ExecuteImportFromGameplayTagTable(const FToolMenuContext& InContext)
{
	const UContentBrowserAssetContextMenuContext* Context = UContentBrowserAssetContextMenuContext::FindContextWithAssets(InContext);
	TArray<UDataTable*> MenuTables = LoadSelectedMenuTables(Context);
	if (MenuTables.IsEmpty())
	{
		ShowNotification(LOCTEXT("ImportNoMenuTables", "Import failed: no MenuTable asset is selected."), SNotificationItem::CS_Fail);
		return;
	}

	FOpenAssetDialogConfig OpenAssetDialogConfig;
	OpenAssetDialogConfig.DialogTitleOverride = LOCTEXT("ImportGameplayTagTableDialogTitle", "Import from GameplayTag Table");
	OpenAssetDialogConfig.AssetClassNames.Add(UDataTable::StaticClass()->GetClassPathName());
	OpenAssetDialogConfig.bAllowMultipleSelection = false;

	FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser"));
	const TArray<FAssetData> SelectedAssets = ContentBrowserModule.Get().CreateModalOpenAssetDialog(OpenAssetDialogConfig);
	if (SelectedAssets.IsEmpty())
	{
		return;
	}

	UDataTable* GameplayTagTable = Cast<UDataTable>(SelectedAssets[0].GetAsset());
	TArray<FPreparedMenuRow> PreparedRows;
	TArray<FText> Problems;
	if (!PrepareMenuRows(GameplayTagTable, PreparedRows, Problems))
	{
		ShowNotification(Problems.IsEmpty() ? LOCTEXT("ImportPrepareFailed", "Import failed: invalid GameplayTagTable.") : Problems[0], SNotificationItem::CS_Fail);
		return;
	}

	TArray<UPackage*> PackagesToSave;
	for (UDataTable* MenuTable : MenuTables)
	{
		if (!IsValid(MenuTable))
		{
			continue;
		}

		FillMenuTable(MenuTable, PreparedRows);
		PackagesToSave.Add(MenuTable->GetOutermost());
	}

	const bool bSaved = UEditorLoadingAndSavingUtils::SavePackages(PackagesToSave, false);
	ShowNotification(
		bSaved
			? LOCTEXT("ImportSucceeded", "Import from GameplayTag Table succeeded.")
			: LOCTEXT("ImportSaveFailed", "Import failed: could not save MenuTable assets."),
		bSaved ? SNotificationItem::CS_Success : SNotificationItem::CS_Fail);
}

void AddMenuTableEntries(FToolMenuSection& InSection)
{
	const UContentBrowserAssetContextMenuContext* Context = UContentBrowserAssetContextMenuContext::FindContextWithAssets(InSection);
	if (!HasSelectedMenuTable(Context))
	{
		return;
	}

	FToolUIAction ExportAction;
	ExportAction.ExecuteAction = FToolMenuExecuteAction::CreateStatic(&ExecuteExportAsGameplayTagTable);
	InSection.AddMenuEntry(
		TEXT("GenericMenuTable_ExportAsGameplayTagTable"),
		LOCTEXT("ExportAsGameplayTagTable", "Export as GameplayTag Table"),
		LOCTEXT("ExportAsGameplayTagTableTooltip", "Create GameplayTagTable assets from selected MenuTable MenuID values."),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), TEXT("Icons.Toolbar.Export")),
		ExportAction);

	FToolUIAction ImportAction;
	ImportAction.ExecuteAction = FToolMenuExecuteAction::CreateStatic(&ExecuteImportFromGameplayTagTable);
	InSection.AddMenuEntry(
		TEXT("GenericMenuTable_ImportFromGameplayTagTable"),
		LOCTEXT("ImportFromGameplayTagTable", "Import from GameplayTag Table"),
		LOCTEXT("ImportFromGameplayTagTableTooltip", "Replace selected MenuTable rows with rows generated from a GameplayTagTable."),
		FSlateIcon(FAppStyle::GetAppStyleSetName(), TEXT("Icons.Import")),
		ImportAction);
}
}

void FMenuTableGameplayTagTableActions::RegisterMenus(void* InOwner)
{
	FToolMenuOwnerScoped OwnerScoped(InOwner);

	UToolMenu* Menu = UE::ContentBrowser::ExtendToolMenu_AssetContextMenu(UDataTable::StaticClass());
	if (!Menu)
	{
		return;
	}

	FToolMenuSection& Section = Menu->FindOrAddSection(TEXT("DataTableActions"), LOCTEXT("DataTableActions", "DataTable Actions"));
	Section.AddDynamicEntry(TEXT("GenericMenuTableGameplayTagTableActions"), FNewToolMenuSectionDelegate::CreateStatic(&AddMenuTableEntries));
}

#undef LOCTEXT_NAMESPACE
