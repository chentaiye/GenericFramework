// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeReference.h"
#include "WorldSettings/GenericWorldSettings.h"
#include "GameplayFlowWorldSettings.generated.h"

/** 按世界保存 Gameplay Flow 的 StateTree 入口配置，世界开始时只负责进入指定状态树。 */
UCLASS(BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced, MinimalAPI)
class UGameplayFlowWorldSettings : public UGenericWorldSettings
{
	GENERATED_BODY()

public:
	/** 世界 BeginPlay 后进入的 Gameplay Flow 状态树，资产必须使用 GameplayFlowStateTreeSchema。 */
	UPROPERTY(EditAnywhere, Category="GameplayFlow", meta=(Schema="/Script/GenericGameplayFlowSystem.GameplayFlowStateTreeSchema"))
	FStateTreeReference StateTreeReference;

protected:
	virtual void OnWorldSettingsBeginPlay_Implementation(UWorld* World) override;

#if WITH_EDITOR
	virtual FName GetSettingsCategory_Implementation() const override;
#endif
};
