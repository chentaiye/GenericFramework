// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Type/IOTTypes.h"
#include "BPFunctions_IOT.generated.h"

class UIOTSubsystem;

/** 提供无组件场景下的 IOT 蓝图工具函数，方便蓝图直接访问子系统和构造命令数据。 */
UCLASS(MinimalAPI)
class UBPFunctions_IOT : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 从 WorldContextObject 解析 UIOTSubsystem，供蓝图在任意对象上下文中访问 IOT 运行时。 */
	UFUNCTION(BlueprintPure, Category="IOT", meta=(WorldContext="WorldContextObject"))
	static GENERICIOTFRAMEWORK_API UIOTSubsystem* GetIOTSubsystem(const UObject* WorldContextObject);

	/** 组装统一命令请求数据，随后可交给子系统、组件或异步命令节点执行。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	static GENERICIOTFRAMEWORK_API FIOTCommandRequest MakeCommandRequest(const FString& DeviceId, EIOTCapabilityKind CapabilityKind, const FString& CommandName, const TMap<FString, FString>& Parameters);

	/** 按 Home Assistant EntityId 构造内部 DeviceId，保持蓝图侧生成结果与子系统规则一致。 */
	UFUNCTION(BlueprintPure, Category="IOT")
	static GENERICIOTFRAMEWORK_API FString MakeIOTDeviceId(const FString& EntityId);
};
