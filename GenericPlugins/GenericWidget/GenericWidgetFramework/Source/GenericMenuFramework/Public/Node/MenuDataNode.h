// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "Base/MenuNode.h"
#include "MenuType.h"
#include "MenuDataNode.generated.h"

/** Runtime menu tree node that owns editable menu data. */
UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class GENERICMENUFRAMEWORK_API UMenuDataNode : public UMenuNode
{
	GENERATED_BODY()

public:
	/** Menu data used to build the runtime button and child menu level. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FMenuTableRow MenuData;
};
