// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "SendHttpRequestAsyncAction.generated.h"

class UGenericHttpResponse;
class UGenericHttpRequest;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRequestEvent, EHttpRequestStatusBP, ConnectionStatus, UGenericHttpRequest*, Request);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnResponseEvent, EHttpRequestStatusBP, ConnectionStatus, UGenericHttpRequest*, Request, UGenericHttpResponse*, Response, EHttpResponseCode, ResponseCode);

/** HTTP 蓝图异步节点基类，负责创建请求、绑定进度和完成回调，并把结果派发给子类。 */
UCLASS(MinimalAPI, Abstract)
class USendHttpRequestAsyncActionBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

protected:
	/** 子类成功分支扩展点，请求完成且连接成功时由 OnRequestComplete 调用。 */
	virtual void OnSuccessInternal(UGenericHttpResponse* Response) { return; }

	/** 子类错误分支扩展点，请求提交失败或连接失败时调用。 */
	virtual void OnErrorInternal(UGenericHttpResponse* Response) { return; }

	/** 子类进度分支扩展点，底层请求更新已发送或已接收字节数时调用。 */
	virtual void OnTickInternal() { return; }

	/** 使用传入请求或新建请求，并重新绑定进度和完成委托，避免复用请求时重复回调。 */
	GENERICPROTOCOL_API void CreateRequest(UGenericHttpRequest* InRequest = nullptr);

	/** 提交当前请求，提交失败时立即触发错误分支并结束异步节点生命周期。 */
	GENERICPROTOCOL_API void SendRequest();

	/** 返回最近一次进度回调中的已发送字节数，供子类广播给蓝图。 */
	int32 GetBytesSent() const { return BytesSent; }

	/** 返回最近一次进度回调中的已接收字节数，供子类广播给蓝图。 */
	int32 GetBytesReceived() const { return BytesReceived; }

	/** 返回当前异步节点持有的请求包装对象，供子类读取状态和广播。 */
	UGenericHttpRequest* GetRequest() { return Request; }

private:
	/** 接收请求进度委托，缓存字节数后转入子类 Tick 分支。 */
	UFUNCTION(Category="HTTP")
	GENERICPROTOCOL_API void OnRequestProgress(UGenericHttpRequest* InRequest, const int32 InBytesSent, const int32 InBytesReceived);

	/** 接收请求完成委托，按连接结果派发成功或错误分支并释放异步节点。 */
	UFUNCTION(Category="HTTP")
	GENERICPROTOCOL_API void OnRequestComplete(UGenericHttpRequest* InRequest, UGenericHttpResponse* InResponse, const bool bConnectedSuccessfully);

private:
	/** 异步节点正在驱动的请求对象，作为回调广播中的上下文。 */
	UPROPERTY()
	UGenericHttpRequest* Request=nullptr;

	/** 最近一次进度回调报告的已发送字节数。 */
	int32 BytesSent = 0;

	/** 最近一次进度回调报告的已接收字节数。 */
	int32 BytesReceived = 0;
};

/** 发送已经配置好的 UGenericHttpRequest，并把进度、成功和错误广播给蓝图。 */
UCLASS(MinimalAPI)
class USendHttpRequestAsyncAction : public USendHttpRequestAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 使用外部已配置请求启动发送流程，适合蓝图先逐项配置再提交。 */
	UFUNCTION(BlueprintCallable, Category="HTTP", meta=(BlueprintInternalUseOnly="true"))
	static USendHttpRequestAsyncAction* SendHttpRequest(UGenericHttpRequest* InRequest);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnRequestEvent OnTick;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnResponseEvent OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnResponseEvent OnError;

protected:
	virtual void OnTickInternal() override;
	virtual void OnSuccessInternal(UGenericHttpResponse* Response) override;
	virtual void OnErrorInternal(UGenericHttpResponse* Response) override;
};

/** 创建并发送文本正文 HTTP 请求，适合 JSON、表单或普通字符串载荷。 */
UCLASS(MinimalAPI)
class USendHttpStringRequestAsyncAction : public USendHttpRequestAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 根据 URL、参数、Verb、MIME、正文和 Header 组装请求后立即发送。 */
	UFUNCTION(BlueprintCallable, Category="HTTP", meta=(BlueprintInternalUseOnly="true", AutoCreateRefTerm="Headers, UrlParameters"))
	static USendHttpStringRequestAsyncAction* SendHttpStringRequest(const FString& ServerUrl, const TMap<FString, FString>& UrlParameters, const EHttpVerb Verb, const EHttpMimeType MimeType, const FString& Content, const TMap<FString, FString>& Headers);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnRequestEvent OnTick;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnResponseEvent OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnResponseEvent OnError;

protected:
	virtual void OnTickInternal() override;
	virtual void OnSuccessInternal(UGenericHttpResponse* Response) override;
	virtual void OnErrorInternal(UGenericHttpResponse* Response) override;
};

/** 创建并发送二进制正文 HTTP 请求，适合文件、图片或自定义协议载荷。 */
UCLASS(MinimalAPI)
class USendHttpBinaryRequestAsyncAction : public USendHttpRequestAsyncActionBase
{
	GENERATED_BODY()

public:
	/** 根据 URL、参数、Verb、MIME、字节正文和 Header 组装请求后立即发送。 */
	UFUNCTION(BlueprintCallable, Category="HTTP", meta=(BlueprintInternalUseOnly="true", AutoCreateRefTerm="Headers, UrlParameters"))
	static USendHttpBinaryRequestAsyncAction* SendHttpBinaryRequest(const FString& ServerUrl, const TMap<FString, FString>& UrlParameters, const EHttpVerb Verb, const EHttpMimeType MimeType, const TArray<uint8>& Content, const TMap<FString, FString>& Headers);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnRequestEvent OnTick;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnResponseEvent OnSuccess;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnResponseEvent OnError;

protected:
	virtual void OnTickInternal() override;
	virtual void OnSuccessInternal(UGenericHttpResponse* Response) override;
	virtual void OnErrorInternal(UGenericHttpResponse* Response) override;
};
