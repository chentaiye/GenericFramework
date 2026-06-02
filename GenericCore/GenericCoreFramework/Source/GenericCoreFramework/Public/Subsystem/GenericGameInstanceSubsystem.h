// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GenericGameInstanceSubsystem.generated.h"

/** 作为通用游戏实例子系统基类，承接 Unreal 生命周期并为上层模块保留扩展钩子。 */
UCLASS(MinimalAPI)
class UGenericGameInstanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	GENERICCOREFRAMEWORK_API virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
#if WITH_EDITOR
	/* Before Subsystem Initialize, Delegate Broadcast From FWorldDelegates::OnPIEMapCreated */
#endif
	GENERICCOREFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
#if WITH_EDITOR
	/* After Subsystem Initialize, Delegate Broadcast From FWorldDelegates::OnPIEMapReady */
#endif
	GENERICCOREFRAMEWORK_API virtual void Deinitialize() override;

public:
	/** 读取外部对象，供调用方复用当前对象缓存或引擎状态。 */
	template <typename T>
	T* GetGameInstance() { return Cast<T>(GetOuter()); }
};
