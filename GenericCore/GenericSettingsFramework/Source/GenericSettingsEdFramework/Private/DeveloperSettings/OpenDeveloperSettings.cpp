// Copyright ChenTaiye 2025. All Rights Reserved.

#include "DeveloperSettings/OpenDeveloperSettings.h"

#include "Base/GenericSlateStyle.h"
#include "DeveloperSettings/GenericGlobalSettings.h"
#include "Framework/Docking/TabManager.h"
#include "ISettingsCategory.h"
#include "ISettingsContainer.h"
#include "ISettingsEditorModel.h"
#include "ISettingsEditorModule.h"
#include "ISettingsModule.h"
#include "Subsystem/GenericFrameworkEdSubsystem.h"
#include "ToolMenus.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/SNullWidget.h"

#define LOCTEXT_NAMESPACE "FApplicationEditorModule"

void UOpenDeveloperSettings::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UGenericFrameworkEdSubsystem::OnToolBarSectionExtend.AddUObject(this, &UOpenDeveloperSettings::RegisterToolBarOpenDeveloperSettings);

	/* Create Developer Settings */
	{
		ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

		if (SettingsModule != nullptr)
		{
			SettingsModule->RegisterSettings
			(
				"GenericFramework", "Global", "Global",
				LOCTEXT("DeveloperSettingsName", "Developer Settings"),
				LOCTEXT("DeveloperSettingsDescription", "Developer Settings"),
				GetMutableDefault<UGenericGlobalSettings>()
			);

			SettingsModule->RegisterViewer("GenericFramework", *this);
		}

		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(DeveloperSettingsTabName, FOnSpawnTab::CreateUObject(this, &UOpenDeveloperSettings::HandleSpawnSettingsTab))
			.SetDisplayName(LOCTEXT("DeveloperSettingsTabTitle", "Developer Settings"))
			.SetMenuType(ETabSpawnerMenuType::Hidden)
			.SetIcon(FSlateIcon(FGenericSlateStyle::GetStyleSetName(), "DeveloperSettings", "DeveloperSettings.Small"));
	}
}

void UOpenDeveloperSettings::Deinitialize()
{
	Super::Deinitialize();

	UGenericFrameworkEdSubsystem::OnToolBarSectionExtend.RemoveAll(this);

	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("GenericFramework", "Global", "Global");
		SettingsModule->UnregisterViewer("GenericFramework");
	}
}

void UOpenDeveloperSettings::ShowSettings(const FName& CategoryName, const FName& SectionName)
{
	FGlobalTabmanager::Get()->TryInvokeTab(DeveloperSettingsTabName);
	const ISettingsEditorModelPtr SettingsEditorModel = SettingsEditorModelPtr.Pin();

	if (SettingsEditorModel.IsValid())
	{
		const ISettingsCategoryPtr Category = SettingsEditorModel->GetSettingsContainer()->GetCategory(CategoryName);

		if (Category.IsValid())
		{
			SettingsEditorModel->SelectSection(Category->GetSection(SectionName));
		}
	}
}

TSharedRef<SDockTab> UOpenDeveloperSettings::HandleSpawnSettingsTab(const FSpawnTabArgs& SpawnTabArgs)
{
	TSharedRef<SWidget> SettingsEditor = SNullWidget::NullWidget;
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");

	if (SettingsModule != nullptr)
	{
		const ISettingsContainerPtr DeveloperSettingsContainer = SettingsModule->GetContainer("GenericFramework");

		if (DeveloperSettingsContainer.IsValid())
		{
			ISettingsEditorModule& SettingsEditorModule = FModuleManager::GetModuleChecked<ISettingsEditorModule>("SettingsEditor");
			const ISettingsEditorModelRef SettingsEditorModel = SettingsEditorModule.CreateModel(DeveloperSettingsContainer.ToSharedRef());

			SettingsEditor = SettingsEditorModule.CreateEditor(SettingsEditorModel);
			SettingsEditorModelPtr = SettingsEditorModel;
		}
	}

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SettingsEditor
		];
}

void UOpenDeveloperSettings::RegisterToolBarOpenDeveloperSettings(FToolMenuSection& ToolMenuSection)
{
	FToolMenuEntry Entry = FToolMenuEntry::InitToolBarButton
	(
		"OpenDeveloperSettings",
		FUIAction(FExecuteAction::CreateUObject(this, &UOpenDeveloperSettings::OpenDeveloperSettings)),
		TAttribute<FText>(),
		LOCTEXT("OpenDeveloperSettings_ToolTip", "Open Developer Settings"),
		FSlateIcon(FGenericSlateStyle::GetStyleSetName(), "DeveloperSettings", "DeveloperSettings.Small")
	);
	Entry.InsertPosition = FToolMenuInsert("OpenWorldSettings", EToolMenuInsertType::After);
	ToolMenuSection.AddEntry(Entry);
}

void UOpenDeveloperSettings::OpenDeveloperSettings()
{
	ISettingsModule& SettingsModule = FModuleManager::LoadModuleChecked<ISettingsModule>("Settings");
	SettingsModule.ShowViewer("GenericFramework", "Global", "Global");
}

#undef LOCTEXT_NAMESPACE
