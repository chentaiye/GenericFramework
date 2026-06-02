// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Asset/MenuAssetFactory.h"

#include "Base/MenuAsset.h"

UMenuAssetFactory::UMenuAssetFactory()
{
	SupportedClass = UMenuAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

bool UMenuAssetFactory::CanCreateNew() const
{
	return true;
}

UObject* UMenuAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UMenuAsset* MenuAsset = NewObject<UMenuAsset>(InParent, Class, Name, Flags);
	if (MenuAsset)
	{
		MenuAsset->EnsureRootNode();
	}
	return MenuAsset;
}
