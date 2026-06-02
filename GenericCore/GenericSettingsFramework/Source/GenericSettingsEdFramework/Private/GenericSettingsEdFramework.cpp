#include "GenericSettingsEdFramework.h"

#include "Base/GenericSlateStyle.h"
#include "Brushes/SlateImageBrush.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FGenericSettingsEdFrameworkModule"

namespace
{
const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon32x32(32.0f, 32.0f);
const FVector2D Icon48x48(48.0f, 48.0f);
const FVector2D Icon64x64(64.0f, 64.0f);

void RegisterSettingsIcons()
{
	const TSharedPtr<IPlugin> SettingsPlugin = IPluginManager::Get().FindPlugin("GenericSettingsFramework");
	if (!SettingsPlugin.IsValid())
	{
		return;
	}

	const FString ResourceRoot = SettingsPlugin->GetBaseDir() / TEXT("Resources");

	const FString DeveloperSettingsIcon = ResourceRoot / TEXT("DeveloperSettings.svg");
	FGenericSlateStyle::Set(FName(TEXT("DeveloperSettings.Small")), new FSlateVectorImageBrush(DeveloperSettingsIcon, Icon16x16));
	FGenericSlateStyle::Set(FName(TEXT("DeveloperSettings")), new FSlateVectorImageBrush(DeveloperSettingsIcon, Icon32x32));
	FGenericSlateStyle::Set(FName(TEXT("DeveloperSettings.Large")), new FSlateVectorImageBrush(DeveloperSettingsIcon, Icon48x48));
	FGenericSlateStyle::Set(FName(TEXT("DeveloperSettings.Large2x")), new FSlateVectorImageBrush(DeveloperSettingsIcon, Icon64x64));

	const FString WorldSettingsIcon = ResourceRoot / TEXT("WorldSettings.svg");
	FGenericSlateStyle::Set(FName(TEXT("WorldSettings.Small")), new FSlateVectorImageBrush(WorldSettingsIcon, Icon16x16));
	FGenericSlateStyle::Set(FName(TEXT("WorldSettings")), new FSlateVectorImageBrush(WorldSettingsIcon, Icon32x32));
	FGenericSlateStyle::Set(FName(TEXT("WorldSettings.Large")), new FSlateVectorImageBrush(WorldSettingsIcon, Icon48x48));
	FGenericSlateStyle::Set(FName(TEXT("WorldSettings.Large2x")), new FSlateVectorImageBrush(WorldSettingsIcon, Icon64x64));
}
}

void FGenericSettingsEdFrameworkModule::StartupModule()
{
	RegisterSettingsIcons();
}

void FGenericSettingsEdFrameworkModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericSettingsEdFrameworkModule, GenericSettingsEdFramework)
