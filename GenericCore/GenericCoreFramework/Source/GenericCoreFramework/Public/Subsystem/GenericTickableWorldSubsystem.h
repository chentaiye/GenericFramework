#pragma once

#include "CoreMinimal.h"
#include "GenericWorldSubsystem.h"
#include "GenericTickableWorldSubsystem.generated.h"

/** 作为通用可 Tick 世界子系统基类，承接 Unreal 生命周期并为上层模块保留扩展钩子。 */
UCLASS(MinimalAPI)
class UGenericTickableWorldSubsystem : public UGenericWorldSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

protected:
	GENERICCOREFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	GENERICCOREFRAMEWORK_API virtual void Deinitialize() override;

	/* FTickableGameObject */
protected:
	GENERICCOREFRAMEWORK_API virtual UWorld* GetTickableGameObjectWorld() const override;
	GENERICCOREFRAMEWORK_API virtual ETickableTickType GetTickableTickType() const override;
	GENERICCOREFRAMEWORK_API virtual void Tick(float DeltaTime) override;
	GENERICCOREFRAMEWORK_API virtual bool IsTickable() const override;
	GENERICCOREFRAMEWORK_API virtual bool IsTickableInEditor() const override;
	GENERICCOREFRAMEWORK_API virtual bool IsTickableWhenPaused() const override;
	GENERICCOREFRAMEWORK_API virtual TStatId GetStatId() const override;
};
