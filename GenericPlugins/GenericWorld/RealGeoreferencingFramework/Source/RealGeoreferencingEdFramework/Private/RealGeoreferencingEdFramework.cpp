#include "RealGeoreferencingEdFramework.h"

#include "Detail/GenericCoordinateCustomization.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "RealGeoreferencingType.h"

#define LOCTEXT_NAMESPACE "FRealGeoreferencingEdFrameworkModule"

void FRealGeoreferencingEdFrameworkModule::StartupModule()
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyEditorModule.RegisterCustomPropertyTypeLayout(
		FGenericCoordinate::StaticStruct()->GetFName(),
		FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FGenericCoordinateCustomization::MakeInstance));
	PropertyEditorModule.NotifyCustomizationModuleChanged();
}

void FRealGeoreferencingEdFrameworkModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded(TEXT("PropertyEditor")))
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
		PropertyEditorModule.UnregisterCustomPropertyTypeLayout(FGenericCoordinate::StaticStruct()->GetFName());
		PropertyEditorModule.NotifyCustomizationModuleChanged();
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FRealGeoreferencingEdFrameworkModule, RealGeoreferencingEdFramework)
