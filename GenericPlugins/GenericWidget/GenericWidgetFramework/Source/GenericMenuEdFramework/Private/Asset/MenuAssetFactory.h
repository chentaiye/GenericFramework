// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MenuAssetFactory.generated.h"

/** Creates menu tree assets from the content browser. */
UCLASS()
class GENERICMENUEDFRAMEWORK_API UMenuAssetFactory : public UFactory
{
	GENERATED_BODY()

public:
	UMenuAssetFactory();
	virtual bool CanCreateNew() const override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
