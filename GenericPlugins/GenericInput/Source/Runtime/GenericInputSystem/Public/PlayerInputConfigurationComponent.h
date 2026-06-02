// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystemInterface.h"
#include "InputMappingContext.h"
#include "Components/ActorComponent.h"
#include "PlayerInputConfigurationComponent.generated.h"

class UEnhancedInputLocalPlayerSubsystem;
class UPlayerInputManager;

/** 描述一个运行时要注册到本地玩家 Enhanced Input 子系统的 Mapping Context 条目。 */
USTRUCT(BlueprintType)
struct FEnhancedInputMappingContext
{
	GENERATED_BODY()

public:
	bool operator==(const FEnhancedInputMappingContext& Other) const { return InputMappingContext == Other.InputMappingContext; }
	bool operator==(const UInputMappingContext* Other) const { return InputMappingContext == Other; }

public:
	/** BeginPlay 注册、EndPlay 移除的输入映射上下文资源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Input Configuration Component")
	UInputMappingContext* InputMappingContext=nullptr;

	/** 添加 Mapping Context 时传给 Enhanced Input 的优先级，决定输入映射冲突时的覆盖顺序。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Input Configuration Component")
	int32 Priority=0;

	/** 注册上下文时传递给 Enhanced Input 的修改选项，用于控制刷新和按键处理策略。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Input Configuration Component")
	FModifyContextOptions ModifyContextOptions;
};

/** 玩家输入配置组件，随拥有者生命周期把一组 Mapping Context 添加到或移出本地玩家输入栈。 */
UCLASS(MinimalAPI, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UPlayerInputConfigurationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** 关闭组件 Tick，因为该组件只在 BeginPlay 和 EndPlay 同步输入映射配置。 */
	GENERICINPUTSYSTEM_API UPlayerInputConfigurationComponent();
	GENERICINPUTSYSTEM_API virtual void BeginPlay() override;
	GENERICINPUTSYSTEM_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	/** 在 BeginPlay 或蓝图扩展中把 EnhancedInputMappingContexts 批量添加到本地玩家子系统。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Player Input Configuration Component")
	GENERICINPUTSYSTEM_API void SetupPlayerInput();

	/** 在 EndPlay 或蓝图扩展中移除本组件添加的输入映射，避免拥有者销毁后残留输入配置。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Player Input Configuration Component")
	GENERICINPUTSYSTEM_API void RemovePlayerInput();

protected:
	/** 从拥有者 PlayerController 或玩家控制的 Pawn 解析 LocalPlayer，并返回其 Enhanced Input 子系统。 */
	virtual UEnhancedInputLocalPlayerSubsystem* GetEnhancedInputLocalPlayerSubsystem();

public:
	/** 组件生命周期内要同步到 Enhanced Input 的上下文列表，数组顺序会按配置逐项注册和移除。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Player Input Configuration Component")
	TArray<FEnhancedInputMappingContext> EnhancedInputMappingContexts;
};
