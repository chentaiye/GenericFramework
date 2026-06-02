// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Movement/CharacterInputMovement.h"
#include "ThirdPersonCharacterInputMovement.generated.h"

class AThirdPersonCharacter;

/** 使用第三人称摇臂视角执行 Character 输入移动和缩放。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UThirdPersonCharacterInputMovement : public UCharacterInputMovement
{
	GENERATED_BODY()

public:
	/** 初始化 ThirdPersonCharacter 输入移动策略的默认对象状态。 */
	GENERICGAMEPLAYSYSTEM_API UThirdPersonCharacterInputMovement();

	/* IPawnInputMovementInterface */
public:
	GENERICGAMEPLAYSYSTEM_API virtual void AddZoom_Implementation(float InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetLocation_Implementation(FVector InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetRotation_Implementation(FRotator InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual void SetZoom_Implementation(float InValue) override;
	GENERICGAMEPLAYSYSTEM_API virtual FVector GetLocation() override;
	GENERICGAMEPLAYSYSTEM_API virtual FRotator GetRotation() override;
	GENERICGAMEPLAYSYSTEM_API virtual float GetZoom() override;

protected:
	/** 获取当前策略绑定的第三人称 Character。 */
	GENERICGAMEPLAYSYSTEM_API AThirdPersonCharacter* GetThirdPersonCharacter() const;
};
