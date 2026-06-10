// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "Base/MenuNode.h"
#include "MenuType.h"
#include "RootMenuDataNode.generated.h"

class UDataTable;

UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class GENERICMENUFRAMEWORK_API URootMenuDataNode : public UMenuNode
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	TObjectPtr<UDataTable> MenuTable = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FMenuIDTableRow MenuID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Menu")
	FMenuContainerEntryTableRow ContainerEntry;
};
