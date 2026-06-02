// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CoreType.h"
#include "UObject/Object.h"
#include "GenericObject.generated.h"

/** 定义通用 UObject类型，作为 运行时核心 模块内复用的稳定入口。 */
UCLASS(MinimalAPI, Abstract, BlueprintType)
class UGenericObject : public UObject
{
	GENERATED_BODY()

public:
	/** 初始化通用 UObject 基类实例，保留统一对象创建入口。 */
	GENERICCOREFRAMEWORK_API UGenericObject(const FObjectInitializer& ObjectInitializer);
	GENERICCOREFRAMEWORK_API virtual UWorld* GetWorld() const override;
};
