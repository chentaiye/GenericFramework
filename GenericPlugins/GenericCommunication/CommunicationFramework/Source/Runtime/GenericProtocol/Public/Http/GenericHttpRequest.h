// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "HTTPType.h"
#include "Obect/GenericObject.h"
#include "Interfaces/IHttpRequest.h"
#include "GenericHttpRequest.generated.h"

class UGenericHttpResponse;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnRequestComplete, UGenericHttpRequest*, Request, UGenericHttpResponse*, Response, bool, bConnectedSuccessfully);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnRequestProgress, UGenericHttpRequest*, Request, int32, BytesSent, int32, BytesReceived);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnRequestHeaderReceived, UGenericHttpRequest*, Request, FString, HeaderName, FString, NewHeaderValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnRequestWillRetry, UGenericHttpRequest*, Request, UGenericHttpResponse*, Response, float, SecondsToRetry);

/** 封装 UE IHttpRequest 为蓝图对象，集中管理请求配置、发送和回调广播。 */
UCLASS(MinimalAPI)
class UGenericHttpRequest : public UGenericObject
{
	GENERATED_BODY()

public:
	/** 创建底层 IHttpRequest 并绑定进度、完成、重试和响应头回调。 */
	UGenericHttpRequest(const FObjectInitializer& ObjectInitializer);

	/** 创建可由蓝图继续配置的 HTTP 请求包装对象。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	static GENERICPROTOCOL_API UGenericHttpRequest* CreateHTTPRequest();

public:
	/** 读取当前请求正文的原始字节，供二进制上传或调试配置使用。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API void GetContent(TArray<uint8>& OutContent) const;

	/** 设置请求正文原始字节，供二进制异步请求发送文件或协议载荷。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetContent(const TArray<uint8>& InContent);

	/** 将当前请求正文字节转为字符串，便于蓝图检查文本载荷。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetContentAsString() const;

	/** 设置请求正文文本，供 JSON、表单或普通文本请求发送。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetContentAsString(const FString& InContent);

	/** 以文件流作为请求正文，避免大文件上传时在蓝图侧保留整份字节数组。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetContentAsStreamedFile(const FString& InFileName, bool& bFileValid);

	/** 返回当前请求正文长度，供发送前校验或进度显示对照。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API int32 GetContentLength() const;

	/** 读取请求的 Content-Type，ProcessRequest 会在为空时补充 text/plain。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetContentType() const;

	/** 返回请求从开始处理到当前的耗时，响应对象也通过请求读取该值。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API float GetElapsedTime() const;

	/** 读取单个请求头，供蓝图确认最终发送配置。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetHeader(const FString& Key) const;

	/** 设置或覆盖单个请求头，供认证、内容类型和自定义协议参数使用。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetHeader(const FString& Key, const FString& Value);

	/** 将底层请求头列表解析为映射，便于蓝图批量查看当前头配置。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API TMap<FString, FString> GetHeaders() const;

	/** 批量设置请求头，异步快捷节点会用它应用外部传入的 Headers。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetHeaders(const TMap<FString, FString>& Headers);

	/** 追加目标头字段，保留底层 HTTP 模块支持的多值头语义。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void AppendToHeader(const FString& Key, const FString& Value);

	/** 返回底层请求状态的蓝图枚举，供异步节点 Tick、成功和错误分支输出。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API EHttpRequestStatusBP GetStatus() const;

	/** 读取最终请求 URL，包含 SetURLWithParameter 追加后的查询参数。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetURL() const;

	/** 设置请求目标 URL，后续 ProcessRequest 会按该地址发送。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetURL(FString InURL);

	/** 设置 URL 并追加查询参数，参数会通过平台 HTTP 工具进行编码。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetURLWithParameter(FString InURL, const TMap<FString, FString>& InParameters);

	/** 从当前 URL 中读取指定查询参数，供蓝图检查自动拼接结果。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetURLParameter(const FString& InParameterName) const;

	/** 读取底层请求 Verb 字符串，供文本配置和调试使用。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API FString GetVerb() const;

	/** 直接设置底层请求 Verb 字符串，允许蓝图传入枚举外的自定义方法。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetVerb(FString InVerb);

	/** 将当前 Verb 字符串转换为蓝图枚举，转换失败时返回枚举哨兵值。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API EHttpVerb GetVerbAsEnum() const;

	/** 通过蓝图枚举设置请求 Verb，异步快捷节点会用它保持参数类型稳定。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetVerbAsEnum(const EHttpVerb InVerb);

	/** 按 MIME 枚举写入 Content-Type 头，实际头值来自枚举 DisplayName。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetMimeType(const EHttpMimeType InMimeType);

	/** 直接写入 Content-Type 字符串，用于枚举未覆盖的自定义媒体类型。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetMimeTypeAsString(const FString& InMimeType);

	/* Timeout */
public:
	/** 读取底层请求的整体超时时间，供蓝图展示或调整前比较。 */
	UFUNCTION(BlueprintPure, Category="HTTP")
	GENERICPROTOCOL_API float GetTimeout() const;

	/** 设置请求整体超时时间，限制请求从开始到完成的最长等待。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetTimeout(float InTimeoutSecs);

	/** 设置活动超时；旧引擎版本会退化为整体超时以保持兼容。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void SetActivityTimeout(float InTimeoutSecs);

	/** 清理底层请求的超时设置，允许后续使用模块默认值。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void ClearTimeout();

	/** 重置底层请求的超时状态；旧引擎版本使用 ClearTimeout 兼容。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void ResetTimeoutStatus();

public:
	/** 提交请求到底层 HTTP 模块，并在缺省 Content-Type 时补 text/plain。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API bool ProcessRequest();

	/** 取消正在处理的请求，让底层 HTTP 模块触发相应完成状态。 */
	UFUNCTION(BlueprintCallable, Category="HTTP")
	GENERICPROTOCOL_API void CancelRequest();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="HTTP")
	FOnRequestComplete OnRequestComplete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="HTTP")
	FOnRequestProgress OnRequestProgress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="HTTP")
	FOnRequestHeaderReceived OnRequestHeaderReceived;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, Category="HTTP")
	FOnRequestWillRetry OnRequestWillRetry;

protected:
	/** 底层收到响应头时转发给蓝图委托，保持包装对象作为事件来源。 */
	virtual void OnHeaderReceivedInternal(TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> RawRequest, const FString& HeaderName, const FString& HeaderValue);

	/** 底层发送或接收字节数变化时转发进度，兼容 32/64 位进度回调。 */
	virtual void OnRequestProgressInternal(TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> RawRequest, uint64 BytesSent, uint64 BytesReceived);

	/** 底层请求完成时创建响应包装对象并广播完成委托。 */
	virtual void OnRequestCompleteInternal(TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> RawRequest, TSharedPtr<IHttpResponse, ESPMode::ThreadSafe> RawResponse, bool bConnectedSuccessfully);

	/** 底层计划重试时包装当前响应并广播重试等待时间。 */
	virtual void OnRequestWillRetryInternal(TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> RawRequest, TSharedPtr<IHttpResponse, ESPMode::ThreadSafe> RawResponse, float SecondsToRetry);

	/** 将底层响应和当前请求组合成 UGenericHttpResponse，供完成或重试事件传递给蓝图。 */
	virtual UGenericHttpResponse* CreateResponse(TSharedPtr<IHttpRequest, ESPMode::ThreadSafe>& RawRequest, TSharedPtr<IHttpResponse, ESPMode::ThreadSafe>& RawResponse);

private:
	/** 底层线程安全 HTTP 请求对象，所有蓝图配置最终写入这里。 */
	TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> Request;
};
