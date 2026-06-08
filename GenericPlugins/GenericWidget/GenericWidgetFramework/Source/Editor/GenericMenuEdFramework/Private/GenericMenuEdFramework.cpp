#include "GenericMenuEdFramework.h"

#include "Asset/MenuTableGameplayTagTableActions.h"
#include "Base/MenuCollection.h"
#include "Detail/MenuCollectionCustomization.h"
#include "Detail/MenuIDTableRowCustomization.h"
#include "MenuType.h"
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "ToolMenus.h"

#define LOCTEXT_NAMESPACE "FGenericMenuEdFrameworkModule"

void FGenericMenuEdFrameworkModule::StartupModule()
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
	PropertyEditorModule.RegisterCustomClassLayout(
		UMenuCollection::StaticClass()->GetFName(),
		FOnGetDetailCustomizationInstance::CreateStatic(&FMenuCollectionCustomization::MakeInstance));
	PropertyEditorModule.RegisterCustomPropertyTypeLayout(
		FMenuIDTableRow::StaticStruct()->GetFName(),
		FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FMenuIDTableRowCustomization::MakeInstance));
	PropertyEditorModule.NotifyCustomizationModuleChanged();

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FGenericMenuEdFrameworkModule::RegisterMenus));
}

void FGenericMenuEdFrameworkModule::ShutdownModule()
{
	UToolMenus::UnRegisterStartupCallback(this);
	if (UToolMenus* ToolMenus = UToolMenus::TryGet())
	{
		ToolMenus->UnregisterOwner(this);
	}

	if (FModuleManager::Get().IsModuleLoaded(TEXT("PropertyEditor")))
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
		PropertyEditorModule.UnregisterCustomClassLayout(UMenuCollection::StaticClass()->GetFName());
		PropertyEditorModule.UnregisterCustomPropertyTypeLayout(FMenuIDTableRow::StaticStruct()->GetFName());
		PropertyEditorModule.NotifyCustomizationModuleChanged();
	}
}

void FGenericMenuEdFrameworkModule::RegisterMenus()
{
	FMenuTableGameplayTagTableActions::RegisterMenus(this);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGenericMenuEdFrameworkModule, GenericMenuEdFramework)
