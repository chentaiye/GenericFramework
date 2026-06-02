// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Type/WorldType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_World.generated.h"

/** 集中暴露世界蓝图函数库接口，让蓝图通过稳定入口访问Unreal 通用工具功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_World : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 判断Partitioned世界，供调用方选择后续流程或过滤无效输入。 */
	UFUNCTION(BlueprintPure, Category="World", meta=(WorldContext="WorldContextObject"))
	static UNREALMISC_API bool IsPartitionedWorld(const UObject* WorldContextObject);

	/** 读取世界类型，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="World", meta=(WorldContext="WorldContextObject"))
	static UNREALMISC_API EWorldTypeBP GetWorldType(const UObject* WorldContextObject);

public:
	/* static FString GetUnrealUnitsFormatString(float UnrealUnits); */
};
