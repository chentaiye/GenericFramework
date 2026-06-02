// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Subsystems/WorldSubsystem.h"
#include "GenericWorldSubsystem.generated.h"

/** 作为通用世界子系统基类，承接 Unreal 生命周期并为上层模块保留扩展钩子。 */
UCLASS(MinimalAPI)
class UGenericWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

protected:
	GENERICCOREFRAMEWORK_API virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	GENERICCOREFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** 响应前置世界初始化回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	GENERICCOREFRAMEWORK_API virtual void OnPreWorldInitialization(UWorld* InWorld, const UWorld::InitializationValues IVS);

	/** 响应后置世界初始化回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	GENERICCOREFRAMEWORK_API virtual void OnPostWorldInitialization(UWorld* InWorld, const UWorld::InitializationValues IVS);

	GENERICCOREFRAMEWORK_API virtual void PostInitialize() override;
	
	GENERICCOREFRAMEWORK_API virtual void OnWorldBeginPlay(UWorld& InWorld) override;

	/** 响应世界前置开始播放回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	GENERICCOREFRAMEWORK_API virtual void OnWorldPreBeginPlay();

	/** 响应世界匹配启动回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	GENERICCOREFRAMEWORK_API virtual void OnWorldMatchStarting();

	/** 响应世界后置开始播放回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	GENERICCOREFRAMEWORK_API virtual void OnWorldPostBeginPlay();

	/** 在地图加载完成并取得世界对象后通知派生类继续处理运行时初始化。 */
	GENERICCOREFRAMEWORK_API virtual void PostLoadMapWithWorld(UWorld* InWorld);

	/** 响应世界开始Tear下方回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	GENERICCOREFRAMEWORK_API virtual void OnWorldBeginTearDown(UWorld* InWorld);

	/** 响应世界清理回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	GENERICCOREFRAMEWORK_API virtual void OnWorldCleanup(UWorld* InWorld, bool bSessionEnded, bool bCleanupResources);

	/** 响应后置世界清理回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	GENERICCOREFRAMEWORK_API virtual void OnPostWorldCleanup(UWorld* InWorld, bool bSessionEnded, bool bCleanupResources);

	GENERICCOREFRAMEWORK_API virtual void Deinitialize() override;
	GENERICCOREFRAMEWORK_API virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

protected:
	/** 判断世界生命周期钩子是否已经完成初始化阶段。 */
	bool IsInitialized() const { return bInitialized; }

private:
	/** 记录世界初始化完成状态，防止生命周期回调重复进入初始化路径。 */
	bool bInitialized = false;
};
