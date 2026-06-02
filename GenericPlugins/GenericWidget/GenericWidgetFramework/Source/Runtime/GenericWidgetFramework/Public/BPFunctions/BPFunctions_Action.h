// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericActionWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Action.generated.h"

class APlayerController;
class UGenericActionSubsystem;

/** 提供通用行为子系统的蓝图访问入口。 */
UCLASS(MinimalAPI)
class UBPFunctions_Action : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 获取指定玩家控制器对应的通用行为子系统。 */
	UFUNCTION(BlueprintPure, Category="Generic Action")
	static GENERICWIDGETFRAMEWORK_API UGenericActionSubsystem* GetGenericActionSubsystem(APlayerController* PlayerController);

	/** 登记一个通用行为控件。 */
	UFUNCTION(BlueprintCallable, Category="Generic Action")
	static GENERICWIDGETFRAMEWORK_API bool RegisterActionWidget(APlayerController* PlayerController, UGenericActionWidget* InWidget);

	/** 注销一个已登记的通用行为控件。 */
	UFUNCTION(BlueprintCallable, Category="Generic Action")
	static GENERICWIDGETFRAMEWORK_API bool UnregisterActionWidget(APlayerController* PlayerController, UGenericActionWidget* InWidget);

	/** 获取当前登记的全部有效通用行为控件。 */
	UFUNCTION(BlueprintPure, Category="Generic Action")
	static GENERICWIDGETFRAMEWORK_API TArray<UGenericActionWidget*> GetAllActionWidgets(APlayerController* PlayerController);
};
