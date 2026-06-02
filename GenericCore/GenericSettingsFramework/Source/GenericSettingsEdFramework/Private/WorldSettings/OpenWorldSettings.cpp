// Copyright ChenTaiye 2025. All Rights Reserved.

#include "WorldSettings/OpenWorldSettings.h"

#include "Base/GenericSlateStyle.h"
#include "Editor.h"
#include "Framework/Docking/TabManager.h"
#include "Subsystem/GenericFrameworkEdSubsystem.h"
#include "ToolMenus.h"
#include "WorldSettings/GenericWorldSettingsEdSubsystem.h"

#define LOCTEXT_NAMESPACE "OpenWorldSettings"

void UOpenWorldSettings::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UGenericFrameworkEdSubsystem::OnToolBarSectionExtend.AddUObject(this, &UOpenWorldSettings::RegisterToolBarOpenWorldSettings);
}

void UOpenWorldSettings::Deinitialize()
{
	Super::Deinitialize();

	UGenericFrameworkEdSubsystem::OnToolBarSectionExtend.RemoveAll(this);
}

void UOpenWorldSettings::RegisterToolBarOpenWorldSettings(FToolMenuSection& ToolMenuSection)
{
	FToolMenuEntry Entry = FToolMenuEntry::InitToolBarButton
	(
		"OpenWorldSettings",
		FUIAction(FExecuteAction::CreateUObject(this, &UOpenWorldSettings::OpenWorldSettings)),
		TAttribute<FText>(),
		LOCTEXT("OpenWorldSettings_ToolTip", "Open Generic World Settings"),
		FSlateIcon(FGenericSlateStyle::GetStyleSetName(), "WorldSettings", "WorldSettings.Small")
	);
	Entry.InsertPosition = FToolMenuInsert("ReadMe", EToolMenuInsertType::After);
	ToolMenuSection.AddEntry(Entry);
}

void UOpenWorldSettings::OpenWorldSettings()
{
	FGlobalTabmanager::Get()->TryInvokeTab(GenericWorldSettingsEditor::WorldSettingsTabName);

	if (GEditor)
	{
		if (UGenericWorldSettingsEdSubsystem* SettingsSubsystem = GEditor->GetEditorSubsystem<UGenericWorldSettingsEdSubsystem>())
		{
			SettingsSubsystem->RequestAsyncRefreshWorldSettingsClasses(true);
		}
	}
}

#undef LOCTEXT_NAMESPACE
