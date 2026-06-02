// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/GenericCharacter.h"
#include "ThirdPersonCharacter.generated.h"

class UCameraComponent;
class UPawnSpringArmComponent;
class USpringArmComponent;

/** 定义第三人称 Character 能力宿主，具体输入移动行为由策略对象执行。 */
UCLASS(MinimalAPI)
class AThirdPersonCharacter : public AGenericCharacter
{
	GENERATED_BODY()

public:
	/** 初始化 ThirdPersonCharacter 的默认组件和输入移动标签。 */
	GENERICGAMEPLAYSYSTEM_API AThirdPersonCharacter();
	GENERICGAMEPLAYSYSTEM_API virtual void BeginPlay() override;
	GENERICGAMEPLAYSYSTEM_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	/** 持有第三人称相机摇臂组件。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Third Person Character")
	TObjectPtr<UPawnSpringArmComponent> SpringArmComponent=nullptr;

	/** 持有第三人称相机组件。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Third Person Character")
	TObjectPtr<UCameraComponent> CameraComponent=nullptr;
};
