// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GenericInputComponent.generated.h"

/** 通用增强输入组件，作为项目默认 InputComponent 类型承接玩家控制器的输入绑定入口。 */
UCLASS(MinimalAPI)
class UGenericInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	/** 开启组件 Tick，并在编辑器配置中把默认输入组件类切换为本类。 */
	GENERICINPUTSYSTEM_API UGenericInputComponent();
	GENERICINPUTSYSTEM_API virtual void BeginPlay() override;
	GENERICINPUTSYSTEM_API virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
