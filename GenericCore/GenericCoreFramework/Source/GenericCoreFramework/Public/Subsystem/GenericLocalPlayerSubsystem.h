// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "GenericLocalPlayerSubsystem.generated.h"

/** 作为通用本地玩家子系统基类，承接 Unreal 生命周期并为上层模块保留扩展钩子。 */
UCLASS(MinimalAPI)
class UGenericLocalPlayerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	GENERICCOREFRAMEWORK_API virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	GENERICCOREFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICCOREFRAMEWORK_API virtual void Deinitialize() override;
	GENERICCOREFRAMEWORK_API virtual void PlayerControllerChanged(APlayerController* NewPlayerController) override;

public:
	/** 读取玩家控制器，供调用方复用当前对象缓存或引擎状态。 */
	template <typename PlayerType = APlayerController>
	PlayerType* GetPlayerController() const { return Cast<PlayerType>(Player); }

	/** 读取必需玩家控制器，供调用方复用当前对象缓存或引擎状态。 */
	template <typename PlayerType = APlayerController>
	PlayerType* GetPlayerControllerChecked() const { return CastChecked<PlayerType>(Player); }

private:
	/** 保存玩家状态，供当前对象后续生命周期和同步逻辑读取。 */
	UPROPERTY()
	TObjectPtr<APlayerController> Player = nullptr;
};
