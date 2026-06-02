#include "GenericMenuEdFramework.h"

#include "Base/MenuCollection.h"
#include "Detail/MenuCollectionCustomization.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"

#define LOCTEXT_NAMESPACE "FGenericMenuEdFrameworkModule"

void FGenericMenuEdFrameworkModule::StartupModule()
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyEditorModule.RegisterCustomClassLayout(
		UMenuCollection::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FMenuCollectionCustomization::MakeInstance));
	PropertyEditorModule.NotifyCustomizationModuleChanged();
}

void FGenericMenuEdFrameworkModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded(TEXT("PropertyEditor")))
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
		PropertyEditorModule.UnregisterCustomClassLayout(UMenuCollection::StaticClass()->GetFName());
		PropertyEditorModule.NotifyCustomizationModuleChanged();
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericMenuEdFrameworkModule, GenericMenuEdFramework)
