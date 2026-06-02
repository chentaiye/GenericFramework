#include "GenericEditorFramework.h"

#include "Base/GenericSlateStyle.h"
#include "Brushes/SlateImageBrush.h"
#include "Interfaces/IPluginManager.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FGenericEditorFrameworkModule"

namespace
{
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon16x16(16.0f, 16.0f);

void RegisterEditorIcons()
{
	const TSharedPtr<IPlugin> CorePlugin = IPluginManager::Get().FindPlugin("GenericCoreFramework");
	if (!CorePlugin.IsValid())
	{
		return;
	}

	const FString ResourceRoot = CorePlugin->GetBaseDir() / TEXT("Resources") / TEXT("Icons");

	const FString FastSwitchLanguageIcon = ResourceRoot / TEXT("FastSwitchLanguage.svg");
	FGenericSlateStyle::Set(FName(TEXT("FastSwitchLanguage")), new FSlateVectorImageBrush(FastSwitchLanguageIcon, Icon20x20));
	FGenericSlateStyle::Set(FName(TEXT("FastSwitchLanguage.Small")), new FSlateVectorImageBrush(FastSwitchLanguageIcon, Icon16x16));

	const FString ReadMeIcon = ResourceRoot / TEXT("ReadMe.svg");
	FGenericSlateStyle::Set(FName(TEXT("ReadMe")), new FSlateVectorImageBrush(ReadMeIcon, Icon20x20));
	FGenericSlateStyle::Set(FName(TEXT("ReadMe.Small")), new FSlateVectorImageBrush(ReadMeIcon, Icon16x16));
}
}

void FGenericEditorFrameworkModule::StartupModule()
{
	IModuleInterface::StartupModule();
	FModuleManager::LoadModuleChecked<IModuleInterface>(TEXT("GenericCoreFramework"));
	RegisterEditorIcons();
}

void FGenericEditorFrameworkModule::ShutdownModule()
{
	IModuleInterface::ShutdownModule();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericEditorFrameworkModule, GenericEditorFramework)
