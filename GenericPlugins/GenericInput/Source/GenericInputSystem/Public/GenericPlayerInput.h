// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedPlayerInput.h"
#include "GenericPlayerInput.generated.h"

/** 通用玩家输入对象，作为 Enhanced PlayerInput 的项目默认派生类承接后续输入扩展点。 */
UCLASS(MinimalAPI)
class UGenericPlayerInput : public UEnhancedPlayerInput
{
	GENERATED_BODY()

public:
	/** 在编辑器配置中把默认 PlayerInput 类切换为本类，使玩家输入栈创建时进入 GenericInput 类型。 */
	GENERICINPUTSYSTEM_API UGenericPlayerInput();
};
