// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Subsystem/GenericFrameworkEdSubsystem.h"

#include "CoreEdType.h"
#include "LevelEditor.h"
#include "Type/DebugType.h"

FOnCommandListInitialize UGenericFrameworkEdSubsystem::OnCommandListInitialize;
FToolMenuDelegate UGenericFrameworkEdSubsystem::OnMenuBarExtend;
FToolMenuDelegate UGenericFrameworkEdSubsystem::OnMenuExtend;
FToolMenuDelegate UGenericFrameworkEdSubsystem::OnToolBarExtend;
FFToolMenuSectionDelegate UGenericFrameworkEdSubsystem::OnToolBarSectionExtend;
FToolMenuDelegate UGenericFrameworkEdSubsystem::OnToolBarOptionExtend;

FName UGenericFrameworkEdSubsystem::MenuBarSectionName = "GenericFrameworkMenuBar";
FName UGenericFrameworkEdSubsystem::ToolBarSectionName = "GenericFrameworkTooBar";

UGenericFrameworkEdSubsystem* UGenericFrameworkEdSubsystem::Get()
{
	return GEditor->GetEditorSubsystem<UGenericFrameworkEdSubsystem>();
}

void UGenericFrameworkEdSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	FLevelEditorModule& LevelEditorModule = FModuleManager::Get().GetModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.OnLevelEditorCreated().AddUObject(this, &UGenericFrameworkEdSubsystem::OnLevelEditorCreated);
}

void UGenericFrameworkEdSubsystem::Deinitialize()
{
	Super::Deinitialize();

	FLevelEditorModule& LevelEditorModule = FModuleManager::Get().GetModuleChecked<FLevelEditorModule>("LevelEditor");
	LevelEditorModule.OnLevelEditorCreated().RemoveAll(this);
}

void UGenericFrameworkEdSubsystem::OnLevelEditorCreated(TSharedPtr<ILevelEditor> LevelEditor)
{
	CommandList = MakeShareable(new FUICommandList);
	OnCommandListInitialize.Broadcast(CommandList);

	RegisterMenuBar();

	RegisterToolBar();

	RegisterToolBarOption();
}

void UGenericFrameworkEdSubsystem::RegisterMenuBar()
{
	UToolMenu* MenuBar = UToolMenus::Get()->ExtendMenu("MainFrame.MainMenu");

	FToolMenuSection& MenuBarSection = MenuBar->FindOrAddSection(MenuBarSectionName);
	MenuBarSection.AddSubMenu
	(
		"GenericFrameworkMenuBar",
		NSLOCTEXT("FGenericEditorFrameworkModule", "MenuBarLabel", "Generic Framework"),
		NSLOCTEXT("FGenericEditorFrameworkModule", "MenuBarToolTip", "Open the Generic Framework menu"),
		FNewToolMenuDelegate::CreateUObject(this, &UGenericFrameworkEdSubsystem::RegisterMenu)
	);

	GenericLOG(GenericLogEditorFramework, Log, TEXT("On Register : MenuBar"))
	OnMenuBarExtend.Broadcast(MenuBar);
}

void UGenericFrameworkEdSubsystem::RegisterMenu(UToolMenu* InToolMenu)
{
	GenericLOG(GenericLogEditorFramework, Log, TEXT("On Register : MenuBar Menu"))
	OnMenuExtend.Broadcast(InToolMenu);
}

void UGenericFrameworkEdSubsystem::RegisterToolBar()
{
	UToolMenu* ToolBar = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.User");
	GenericLOG(GenericLogEditorFramework, Log, TEXT("On Register : ToolBar"))
	OnToolBarExtend.Broadcast(ToolBar);

	FToolMenuSection& ToolBarSection = ToolBar->FindOrAddSection(ToolBarSectionName);
	GenericLOG(GenericLogEditorFramework, Log, TEXT("On Register : ToolBar Section"))
	OnToolBarSectionExtend.Broadcast(ToolBarSection);

	for (auto& Block : ToolBarSection.Blocks)
	{
		Block.SetCommandList(CommandList);
	}

	UToolMenu* AssetToolbar = UToolMenus::Get()->ExtendMenu("AssetEditor.DefaultToolBar");
	FToolMenuSection& AssetToolbarSection = AssetToolbar->FindOrAddSection(ToolBarSectionName);
	AssetToolbarSection = ToolBarSection;
}

void UGenericFrameworkEdSubsystem::RegisterToolBarOption()
{
	UToolMenu* ToolBar = UToolMenus::Get()->FindMenu("LevelEditor.LevelEditorToolBar.User");
	FToolMenuSection& ToolBarSection = ToolBar->FindOrAddSection(ToolBarSectionName);
	ToolBarSection.AddEntry
	(
		FToolMenuEntry::InitComboButton
		(
			"GenericFrameworkToolBar",
			FUIAction(),
			FNewToolMenuDelegate::CreateUObject(this, &UGenericFrameworkEdSubsystem::RegisterToolBarOptionMenu),
			NSLOCTEXT("FGenericEditorFrameworkModule", "GenericFrameworkToolBarLabel", "ToolBar Options"),
			NSLOCTEXT("FGenericEditorFrameworkModule", "GenericFrameworkToolBarTooltip", "Open ToolBar Options"),
			FSlateIcon(),
			true
		)
	);

	UToolMenu* AssetToolbar = UToolMenus::Get()->ExtendMenu("AssetEditor.DefaultToolBar");
	FToolMenuSection& AssetToolbarSection = AssetToolbar->FindOrAddSection(ToolBarSectionName);
	AssetToolbarSection = ToolBarSection;

	GenericLOG(GenericLogEditorFramework, Log, TEXT("On Register : ToolBar Option"))
}

void UGenericFrameworkEdSubsystem::RegisterToolBarOptionMenu(UToolMenu* InToolMenu)
{
	if (!InToolMenu->FindSection("Tools"))
	{
		InToolMenu->AddSection(FName("Tools"),NSLOCTEXT("FGenericEditorFrameworkModule", "ToolsSectionLabel", "Tools"));
	}

	GenericLOG(GenericLogEditorFramework, Log, TEXT("On Register : ToolBar Option Menu"))
	OnToolBarOptionExtend.Broadcast(InToolMenu);
}
