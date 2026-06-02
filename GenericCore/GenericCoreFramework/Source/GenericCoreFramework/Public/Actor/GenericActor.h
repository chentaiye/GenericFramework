// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenericActor.generated.h"

/** 定义A通用Actor类型，作为 运行时核心 模块内复用的稳定入口。 */
UCLASS(MinimalAPI)
class AGenericActor : public AActor
{
	GENERATED_BODY()

public:
	/** 初始化通用 Actor 基类实例，保留统一 Actor 创建入口。 */
	GENERICCOREFRAMEWORK_API AGenericActor();
	GENERICCOREFRAMEWORK_API virtual void BeginPlay() override;
	GENERICCOREFRAMEWORK_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
