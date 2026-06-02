// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "GenericAssetFactory.generated.h"

/** 描述通用资产工厂在编辑器资产系统中的创建、分类和展示信息。 */
UCLASS(Abstract, MinimalAPI)
class UGenericAssetFactory : public UFactory
{
	GENERATED_BODY()

public:
	GENERICEDITORFRAMEWORK_API virtual bool CanCreateNew() const override;
	GENERICEDITORFRAMEWORK_API virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
