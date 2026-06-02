// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Components/ActorComponent.h"
#include "PlayerInputIdleActionComponent.generated.h"

class UPlayerInputIdleAction;
class UPlayerInputManager;
class UInputAction;

/** 定义刷新空闲输入时如何选择 PlayerInputIdleActions 中的动作。 */
UENUM(BlueprintType)
enum class EIdleActionMethod : uint8
{
	/** 每次刷新时对列表内所有空闲动作同时执行 Stop 或 Start 流程。 */
	All,

	/** ResetInputIdleAction 中从动作列表随机选出一个动作继续等待或播放。 */
	Random,

	/** ResetInputIdleAction 中按数组顺序推进到下一个动作，末尾后回到第一个。 */
	Sequence
};

/** 玩家输入空闲动作组件，绑定刷新输入动作并管理一组可实例化的空闲动作对象。 */
UCLASS(MinimalAPI,ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent) )
class UPlayerInputIdleActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	/** 开启组件 Tick，并保留刷新输入动作资源由配置提供。 */
	UPlayerInputIdleActionComponent();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	/** 响应 Enhanced Input 触发的刷新动作，先过滤排除键，再重置空闲动作计时。 */
	UFUNCTION(Category="Player Input Idle Action Component")
	void HandleRefreshInputIdleAction(const FInputActionInstance& Value);

public:
	/** 按 RefreshMethod 停止当前空闲动作并启动下一轮等待，All 模式会处理整个动作列表。 */
	UFUNCTION(BlueprintCallable, Category="Player Input Idle Action Component")
	GENERICINPUTSYSTEM_API void ResetInputIdleAction();

	/** 从拥有者 PlayerController 或玩家控制的 Pawn 解析玩家控制器，供输入绑定和按键检测使用。 */
	UFUNCTION(BlueprintPure, Category="Player Input Idle Action Component")
	GENERICINPUTSYSTEM_API APlayerController* GetOwnerPlayerController() const;

	/** 沿拥有者玩家控制器解析 EnhancedInputComponent，BeginPlay 用它绑定 RefreshInputIdleAction。 */
	UFUNCTION(BlueprintPure, Category="Player Input Idle Action Component")
	GENERICINPUTSYSTEM_API UEnhancedInputComponent* GetOwnerEnhancedInputComponent() const;

protected:
	/** BeginPlay 绑定到 Enhanced Input 的刷新动作，触发后会调用 HandleRefreshInputIdleAction。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input Idle Action Component")
	TObjectPtr<UInputAction> RefreshInputIdleAction=nullptr;

	/** 控制 ResetInputIdleAction 在动作列表中批量、随机或顺序选择空闲动作的策略。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input Idle Action Component")
	EIdleActionMethod RefreshMethod=EIdleActionMethod::All;

	/** 组件级刷新排除键，触发刷新动作时任一按键按下都会跳过本次重置。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Player Input Idle Action Component")
	TSet<FKey> ExcludeKeysWhenRefresh;

	/** 由组件持有的空闲动作实例列表，BeginPlay 和 ResetInputIdleAction 根据 RefreshMethod 调度它们。 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category="Player Input Idle Action Component")
	TArray<UPlayerInputIdleAction*> PlayerInputIdleActions;

private:
	/** 保存 Random 和 Sequence 模式当前管理的动作索引，刷新时用于停止旧动作并选择新动作。 */
	int32 CurrentActionIndex=-1;
};
