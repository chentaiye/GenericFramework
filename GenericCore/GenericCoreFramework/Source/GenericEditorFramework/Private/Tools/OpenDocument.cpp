// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Tools/OpenDocument.h"

#include "Base/GenericSlateStyle.h"
#include "Subsystem/GenericFrameworkEdSubsystem.h"

#define LOCTEXT_NAMESPACE "FApplicationEditorModule"

void UOpenDocument::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UGenericFrameworkEdSubsystem::OnToolBarSectionExtend.AddUObject(this, &UOpenDocument::OnToolBarSectionExtend);

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(DocumentTabName, FOnSpawnTab::CreateUObject(this, &UOpenDocument::HandleSpawnDocumentTab))
		.SetDisplayName(LOCTEXT("DocumentTabTitle", "Developer Document"))
		.SetMenuType(ETabSpawnerMenuType::Hidden)
		.SetIcon(FSlateIcon(FGenericSlateStyle::GetStyleSetName(), "ReadMe", "ReadMe.Small"));
}

void UOpenDocument::Deinitialize()
{
	Super::Deinitialize();
	UGenericFrameworkEdSubsystem::OnToolBarSectionExtend.RemoveAll(this);
}

void UOpenDocument::OnToolBarSectionExtend(FToolMenuSection& InToolMenuSection)
{
	InToolMenuSection.AddEntry
	(
		FToolMenuEntry::InitToolBarButton
		(
			"ReadMe",
			FUIAction(FExecuteAction::CreateUObject(this, &UOpenDocument::OpenDocument)),
			TAttribute<FText>(),
			LOCTEXT("ReadMe_ToolTip", "Open Ducument About DevPlugin"),
			FSlateIcon(FGenericSlateStyle::GetStyleSetName(), "ReadMe", "ReadMe.Small")
		)
	);
}

void UOpenDocument::OpenDocument()
{
	FGlobalTabmanager::Get()->TryInvokeTab(DocumentTabName);
}

TSharedRef<SDockTab> UOpenDocument::HandleSpawnDocumentTab(const FSpawnTabArgs& SpawnTabArgs)
{
	TSharedRef<SWidget> SettingsEditor = SNullWidget::NullWidget;

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SettingsEditor
		];
}

#undef LOCTEXT_NAMESPACE
