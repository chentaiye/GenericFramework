// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Obect/GenericObject.h"
#include "GenericHttpResponse.generated.h"

class UGenericJsonObject;
class IHttpResponse;

/** 封装 UE IHttpResponse 为蓝图对象，保留所属请求并提供正文、头和状态码读取。 */
UCLASS(MinimalAPI)
class UGenericHttpResponse : public UGenericObject
{
	GENERATED_BODY()

private:
	friend class UGenericHttpRequest;

	/** 由请求包装对象写入底层响应和所属请求，确保响应查询能回溯请求耗时。 */
	void InitInternal(TWeakObjectPtr<UGenericHttpRequest> InRequest, TSharedPtr<IHttpResponse, ESPMode::ThreadSafe> InResponse);

public:
	/** 将响应头列表解析为映射，供蓝图按名称读取或整体检查。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API TMap<FString, FString> GetHeaders() const;

	/** 读取响应正文原始字节，供二进制协议或文件下载流程使用。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API void GetContent(TArray<uint8>& OutContent) const;

	/** 读取响应正文文本，供 JSON、HTML 或普通文本接口处理。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetContentAsString() const;

	/** 将响应正文解析到复用的 UGenericJsonObject，便于蓝图继续按字段读取。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API UGenericJsonObject* GetContentAsJson();

	/** 返回响应正文长度，响应无效时返回 0。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API int32 GetContentLength() const;

	/** 读取响应 Content-Type，用于蓝图选择文本、JSON 或二进制处理路径。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetContentType() const;

	/** 读取指定响应头，响应无效时返回空字符串。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetHeader(const FString& Key) const;

	/** 返回 HTTP 响应码，响应无效时用 -1 表示没有可用状态。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API int32 GetResponseCode() const;

	/** 读取最终响应 URL，供重定向或参数拼接后的结果检查。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetURL() const;

	/** 从响应 URL 中读取查询参数，供蓝图确认服务端最终地址。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetURLParameter(const FString& ParameterName) const;

	/** 通过所属请求返回耗时，响应本身无请求时返回 0。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API float GetElapsedTime() const;

public:
	/** 返回生成该响应的请求包装对象，便于回调中继续读取请求配置。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API UGenericHttpRequest* GetRequest() const;

private:
	/** 弱引用所属请求，避免响应对象延长请求生命周期。 */
	TWeakObjectPtr<UGenericHttpRequest> Request = nullptr;

	/** 底层线程安全响应对象，所有正文、头和响应码读取都委托给它。 */
	TSharedPtr<IHttpResponse, ESPMode::ThreadSafe> Response = nullptr;

	/** 缓存正文解析出的 JSON 包装对象，重复 GetContentAsJson 时复用同一实例。 */
	UPROPERTY()
	TObjectPtr<UGenericJsonObject> JsonObject=nullptr;
};
