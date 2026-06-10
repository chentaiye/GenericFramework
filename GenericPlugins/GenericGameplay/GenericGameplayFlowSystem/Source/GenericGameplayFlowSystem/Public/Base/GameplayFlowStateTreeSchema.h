// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeSchema.h"
#include "GameplayFlowStateTreeSchema.generated.h"

namespace UE::GenericGameplayFlow::StateTreeContextDataNames
{
	extern GENERICGAMEPLAYFLOWSYSTEM_API const FName World;
	extern GENERICGAMEPLAYFLOWSYSTEM_API const FName WorldSettings;
}

/** 限定 Gameplay Flow 状态树可访问的世界上下文，节点逻辑使用标准 StateTree Task/Condition/Evaluator。 */
UCLASS(BlueprintType, EditInlineNew, CollapseCategories, meta=(DisplayName="Gameplay Flow StateTree Schema", CommonSchema))
class GENERICGAMEPLAYFLOWSYSTEM_API UGameplayFlowStateTreeSchema : public UStateTreeSchema
{
	GENERATED_BODY()

public:
	UGameplayFlowStateTreeSchema();
	virtual void PostLoad() override;

protected:
	virtual bool IsStructAllowed(const UScriptStruct* InScriptStruct) const override;
	virtual bool IsClassAllowed(const UClass* InClass) const override;
	virtual bool IsExternalItemAllowed(const UStruct& InStruct) const override;
	virtual bool IsScheduledTickAllowed() const override;
	virtual TConstArrayView<FStateTreeExternalDataDesc> GetContextDataDescs() const override;

#if WITH_EDITOR
	virtual bool AllowEnterConditions() const override { return true; }
	virtual bool AllowEvaluators() const override { return true; }
	virtual bool AllowMultipleTasks() const override { return true; }
	virtual bool AllowGlobalParameters() const override { return true; }
	virtual bool AllowTasksCompletion() const override { return true; }
#endif

private:
	void RebuildContextDataDescs();

private:
	UPROPERTY()
	TArray<FStateTreeExternalDataDesc> ContextDataDescs;
};
