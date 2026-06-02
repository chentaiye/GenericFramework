// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HTTPType.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_HTTP.generated.h"

/** 提供 HTTP 枚举转换、全局配置和 URL 参数拼接的蓝图入口。 */
UCLASS(MinimalAPI)
class UBPFunctions_HTTP : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 将 Verb 字符串转为蓝图枚举，支持配置表或文本输入驱动请求方法。 */
	UFUNCTION(BlueprintPure, Category="HTTP", meta=(DisplayName="To Http Verb Enum", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICPROTOCOL_API EHttpVerb BP_ConvertToHttpVerbEnum(FString InVerb);

	/** 将蓝图 Verb 枚举转为底层 HTTP 请求使用的字符串。 */
	UFUNCTION(BlueprintPure, Category="HTTP", meta=(DisplayName="To Http Verb String", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICPROTOCOL_API FString BP_ConvertToHttpVerbString(EHttpVerb InVerb);

	/** 将 MIME 枚举名转为蓝图枚举，供外部配置选择 Content-Type。 */
	UFUNCTION(BlueprintPure, Category="HTTP", meta=(DisplayName="To Http Mime Type Enum", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICPROTOCOL_API EHttpMimeType BP_ConvertToMimeTypeEnum(FString InMimeType);

	/** 将 MIME 枚举转为枚举名字符串，便于蓝图保存或显示配置。 */
	UFUNCTION(BlueprintPure, Category="HTTP", meta=(DisplayName="To Http Mime Type String", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICPROTOCOL_API FString BP_ConvertToMimeTypeString(EHttpMimeType InMimeType);

	/** 将整数响应码转为蓝图枚举，供异步回调中做稳定分支判断。 */
	UFUNCTION(BlueprintPure, Category="HTTP", meta=(DisplayName="To Response Code Enum", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICPROTOCOL_API EHttpResponseCode BP_ConvertToResponseCodeEnum(int32 InCode);

	/** 将响应码枚举还原为整数，便于日志、UI 或外部协议继续使用原始状态码。 */
	UFUNCTION(BlueprintPure, Category="HTTP", meta=(DisplayName="To Response Code Int", CompactNodeTitle="->", BlueprintAutocast))
	static GENERICPROTOCOL_API int32 BP_ConvertToResponseCodeInt(EHttpResponseCode InCode);

	/* HTTP Global */
public:
	/** 读取 HTTP 模块每个服务器允许的最大连接数，用于调试全局并发限制。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	GENERICPROTOCOL_API int32 GetHttpMaxConnectionsPerServer();

	/** 读取 HTTP 模块当前代理地址，供蓝图显示或诊断网络配置。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	GENERICPROTOCOL_API FString GetProxyAddress();

	/** 读取 HTTP 模块最大读取缓冲区大小，用于排查大响应下载限制。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	GENERICPROTOCOL_API int32 GetMaxReadBufferSize();

	/** 向 HTTP 模块添加默认头，后续新建请求会自动携带该字段。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	static GENERICPROTOCOL_API void AddDefaultHeader(const FString& HeaderName, const FString& HeaderValue);

	/** 设置 HTTP 模块代理地址，影响后续底层请求的网络出口。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	static GENERICPROTOCOL_API void SetProxyAddress(const FString& InProxyAddress);

	/** 设置 HTTP 模块最大读取缓冲区大小，影响后续响应读取能力。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	static GENERICPROTOCOL_API void SetMaxReadBufferSize(const int32 SizeInBytes);

	/** 设置 HTTP 线程空闲时的最小睡眠时间，用于调节后台轮询开销。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	static GENERICPROTOCOL_API void SetHttpThreadIdleMinimumSleepTimeInSeconds(const float Time);

	/** 设置 HTTP 线程空闲时每帧处理预算，用于调节低负载下的响应延迟。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	static GENERICPROTOCOL_API void SetHttpThreadIdleFrameTimeInSeconds(const float Time);

	/** 设置 HTTP 线程活跃时的最小睡眠时间，用于调节高负载轮询频率。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	static GENERICPROTOCOL_API void SetHttpThreadActiveMinimumSleepTimeInSeconds(const float Time);

	/** 设置 HTTP 线程活跃时每帧处理预算，用于平衡吞吐和游戏线程压力。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	static GENERICPROTOCOL_API void SetHttpThreadActiveFrameTimeInSeconds(const float Time);

	/** 设置 HTTP 模块延迟时间，供全局请求节流或调试网络时序使用。 */
	UFUNCTION(BlueprintCallable, Category="HTTP Global")
	static GENERICPROTOCOL_API void SetHttpDelayTime(const float Delay);

public:
	/** 将参数映射编码并追加到 URL 查询串，供请求对象和异步节点统一构造地址。 */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="HTTP")
	static GENERICPROTOCOL_API FString AddParametersToUrl(FString InUrl, const TMap<FString, FString>& Parameters);
};
