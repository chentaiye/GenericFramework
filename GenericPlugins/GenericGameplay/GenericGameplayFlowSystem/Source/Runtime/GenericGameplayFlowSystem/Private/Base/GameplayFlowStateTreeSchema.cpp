// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Base/GameplayFlowStateTreeSchema.h"

#include "Engine/World.h"
#include "Settings/GameplayFlowWorldSettings.h"
#include "StateTreeConditionBase.h"
#include "StateTreeConsiderationBase.h"
#include "StateTreeEvaluatorBase.h"
#include "StateTreeExecutionTypes.h"
#include "StateTreeTaskBase.h"

namespace UE::GenericGameplayFlow::StateTreeContextDataNames
{
	const FName World(TEXT("World"));
	const FName WorldSettings(TEXT("WorldSettings"));
}

UGameplayFlowStateTreeSchema::UGameplayFlowStateTreeSchema()
{
	RebuildContextDataDescs();
}

void UGameplayFlowStateTreeSchema::PostLoad()
{
	Super::PostLoad();
	RebuildContextDataDescs();
}

void UGameplayFlowStateTreeSchema::RebuildContextDataDescs()
{
	ContextDataDescs.Reset();
	ContextDataDescs.Append({
		FStateTreeExternalDataDesc(
			UE::GenericGameplayFlow::StateTreeContextDataNames::World,
			UWorld::StaticClass(),
			FGuid(0x8F2E2C18, 0x64D74468, 0xB1A9504D, 0xAF697C35)),
		FStateTreeExternalDataDesc(
			UE::GenericGameplayFlow::StateTreeContextDataNames::WorldSettings,
			UGameplayFlowWorldSettings::StaticClass(),
			FGuid(0x52C6A9F7, 0x47274E36, 0xA9C67739, 0x4B19F0E2)),
	});
}

bool UGameplayFlowStateTreeSchema::IsStructAllowed(const UScriptStruct* InScriptStruct) const
{
	return InScriptStruct
		&& (InScriptStruct->IsChildOf(FStateTreeConditionCommonBase::StaticStruct())
			|| InScriptStruct->IsChildOf(FStateTreeConsiderationCommonBase::StaticStruct())
			|| InScriptStruct->IsChildOf(FStateTreeEvaluatorCommonBase::StaticStruct())
			|| InScriptStruct->IsChildOf(FStateTreeTaskCommonBase::StaticStruct()));
}

bool UGameplayFlowStateTreeSchema::IsClassAllowed(const UClass* InClass) const
{
	return UStateTreeSchema::IsChildOfBlueprintBase(InClass);
}

bool UGameplayFlowStateTreeSchema::IsExternalItemAllowed(const UStruct& InStruct) const
{
	return true;
}

bool UGameplayFlowStateTreeSchema::IsScheduledTickAllowed() const
{
	return true;
}

TConstArrayView<FStateTreeExternalDataDesc> UGameplayFlowStateTreeSchema::GetContextDataDescs() const
{
	return ContextDataDescs;
}
