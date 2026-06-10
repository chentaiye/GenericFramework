// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericWidget.h"
#include "GameplayTagContainer.h"
#include "Input/GenericActionInputTypes.h"
#include "GenericActionWidget.generated.h"

/** 表示可登记到通用行为系统中的业务UI控件。 */
UCLASS(MinimalAPI)
class UGenericActionWidget : public UGenericWidget
{
	GENERATED_BODY()

public:
	/** 初始化通用行为标识默认值。 */
	GENERICWIDGETFRAMEWORK_API UGenericActionWidget(const FObjectInitializer& ObjectInitializer);

	/** 构造 ActionTag 阶段事件对应的蓝图函数名。 */
	GENERICWIDGETFRAMEWORK_API static FName MakeActionTagEventFunctionName(FGameplayTag InActionTag);

	/** 如果蓝图中存在对应 ActionTag 阶段事件，则执行它并返回 true。 */
	GENERICWIDGETFRAMEWORK_API bool ExecuteActionTagEvent(FGameplayTag InActionTag, EGenericActionTriggerEvent InTriggerEvent, const FGenericActionInputEventData& InEventData);

public:
	/** 记录动作标签。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Action", meta=(Categories="GameplayUI.Action"))
	FGameplayTag ActionTag;

protected:
	GENERICWIDGETFRAMEWORK_API virtual void NativeConstruct() override;
	GENERICWIDGETFRAMEWORK_API virtual void NativeDestruct() override;
};
