// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_NativeAPI.generated.h"

class UNativeAPIProxyComponent;

/** 暴露 NativeAPI 调试和注册控制给蓝图，内部转发到引擎或世界子系统以复用 C++ 分发链路。 */
UCLASS(MinimalAPI)
class UBPFunctions_NativeAPI : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 把蓝图传入的 JSON 字符串交给引擎子系统，用于模拟一次不经过外部会话的 NativeAPI 消息。 */
	UFUNCTION(BlueprintCallable, Category="NativeAPI")
	static NATIVEAPI_API void SendSimulationNativeAPI(const FString& NativeAPIJson);

	/** 从蓝图手动启动所有会话 Feature，打开当前世界设置允许的 WebSocket/HTTP 外部入口。 */
	UFUNCTION(BlueprintCallable, Category="NativeAPI")
	static NATIVEAPI_API void StartAllFeatureSession();

	/** 从蓝图手动停止所有会话 Feature，关闭外部入口并解绑 Payload 回调。 */
	UFUNCTION(BlueprintCallable, Category="NativeAPI")
	static NATIVEAPI_API void EndAllFeatureSession();

public:
	/** 把指定代理注册到 WorldContext 对应的世界子系统，供运行时手动接入 NativeAPI 广播表。 */
	UFUNCTION(BlueprintCallable, Category="NativeAPI", meta=(WorldContext="WorldContextObject"))
	static NATIVEAPI_API void RegisterNativeAPI(const UObject* WorldContextObject, UNativeAPIProxyComponent* InProxy);

	/** 把指定代理从 WorldContext 对应的世界子系统移除，防止后续 Payload 继续投递给该组件。 */
	UFUNCTION(BlueprintCallable, Category="NativeAPI", meta=(WorldContext="WorldContextObject"))
	static NATIVEAPI_API void UnRegisterNativeAPI(const UObject* WorldContextObject, UNativeAPIProxyComponent* InProxy);
};
