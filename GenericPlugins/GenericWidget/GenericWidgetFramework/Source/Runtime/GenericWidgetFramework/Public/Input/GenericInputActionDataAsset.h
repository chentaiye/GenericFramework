// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Input/GenericInputTrigger.h"
#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif
#include "GenericInputActionDataAsset.generated.h"

/** 保存通用 UI流程中的通用Input键Trigger数据，供运行时传递和蓝图访问。 */
USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FGenericInputKeyTrigger
{
	GENERATED_BODY()

	/** 记录键。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	FKey Key;

	/** 持有Trigger实例，供通用 UI运行时复用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="Input")
	TObjectPtr<UGenericInputTrigger> Trigger = nullptr;
};

/** 保存通用 UI流程中的通用Input动作键TriggerMapping数据，供运行时传递和蓝图访问。 */
USTRUCT(BlueprintType)
struct GENERICWIDGETFRAMEWORK_API FGenericInputActionKeyTriggerMapping
{
	GENERATED_BODY()

	/** 记录动作标签。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input", meta=(Categories="GameplayUI.Action"))
	FGameplayTag ActionTag;

	/** 控制触发该行为后是否阻止继续向低优先级层传递。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	bool bConsumeInput = true;

	/** 保存键Triggers列表，供通用 UI批量处理。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	TArray<FGenericInputKeyTrigger> KeyTriggers;
};

/** 描述通用UI行为如何由物理按键和触发方式驱动的数据资产。 */
UCLASS(BlueprintType, MinimalAPI)
class UGenericInputActionDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	/** 保存动作Mappings列表，供通用 UI批量处理。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TArray<FGenericInputActionKeyTriggerMapping> ActionMappings;

public:
#if WITH_EDITOR
	GENERICWIDGETFRAMEWORK_API virtual EDataValidationResult IsDataValid(FDataValidationContext& Context) const override;
#endif
};
