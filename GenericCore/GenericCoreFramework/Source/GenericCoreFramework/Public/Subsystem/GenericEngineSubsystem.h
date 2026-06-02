// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/EngineSubsystem.h"
#include "GenericEngineSubsystem.generated.h"

/** 作为通用引擎子系统基类，承接 Unreal 生命周期并为上层模块保留扩展钩子。 */
UCLASS(MinimalAPI)
class UGenericEngineSubsystem : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	GENERICCOREFRAMEWORK_API virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	GENERICCOREFRAMEWORK_API virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** 响应后置引擎Init回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	GENERICCOREFRAMEWORK_API virtual void OnPostEngineInit();

	/** 响应Start游戏实例回调，将引擎或 Slate 事件转为当前类的状态更新。 */
	GENERICCOREFRAMEWORK_API virtual void OnStartGameInstance(UGameInstance* InGameInstance);

	GENERICCOREFRAMEWORK_API virtual void Deinitialize() override;
};
