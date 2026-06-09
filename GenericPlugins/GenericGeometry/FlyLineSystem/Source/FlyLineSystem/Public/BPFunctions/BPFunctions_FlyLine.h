#pragma once

#include "CoreMinimal.h"
#include "FlyLine/FlyLineTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_FlyLine.generated.h"

class UFlyLineSubsystem;

/** 提供飞线子系统的蓝图静态入口，用 WorldContext 转发连接注册和重建请求。 */
UCLASS(MinimalAPI)
class UBPFunctions_FlyLine : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 向当前世界的飞线子系统注册一条显式连接并立即重建。 */
	UFUNCTION(BlueprintCallable, Category="FlyLine", meta=(WorldContext="WorldContextObject"))
	static FLYLINESYSTEM_API void RegisterFlyLineConnection(const UObject* WorldContextObject, const FFlyLineConnection& Connection);

	/** 创建一个源端点到多个目标端点的连接，返回生成的连接 ID 供后续移除。 */
	UFUNCTION(BlueprintCallable, Category="FlyLine", meta=(WorldContext="WorldContextObject"))
	static FLYLINESYSTEM_API TArray<FName> ConnectOneToMany(const UObject* WorldContextObject, FName SourceEndpointId, const TArray<FName>& TargetEndpointIds, const FFlyLineStyle& Style, FName ConnectionPrefix);

	/** 创建多源到多目标的成对连接，适合蓝图批量绘制关系网络。 */
	UFUNCTION(BlueprintCallable, Category="FlyLine", meta=(WorldContext="WorldContextObject"))
	static FLYLINESYSTEM_API TArray<FName> ConnectManyToMany(const UObject* WorldContextObject, const TArray<FName>& SourceEndpointIds, const TArray<FName>& TargetEndpointIds, const FFlyLineStyle& Style, FName ConnectionPrefix);

	/** 手动触发当前世界所有飞线批次重新解析和渲染。 */
	UFUNCTION(BlueprintCallable, Category="FlyLine", meta=(WorldContext="WorldContextObject"))
	static FLYLINESYSTEM_API void RebuildFlyLines(const UObject* WorldContextObject);
};
