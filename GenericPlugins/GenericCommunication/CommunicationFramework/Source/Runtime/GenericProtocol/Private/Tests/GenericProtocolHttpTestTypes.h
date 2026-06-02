// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Http/HTTPType.h"
#include "Http/Async/SendHttpRequestAsyncAction.h"
#include "GenericProtocolHttpTestTypes.generated.h"

class UGenericHttpRequest;
class UGenericHttpResponse;

/** 自动化测试用监听器，捕获 HTTP 异步节点错误分支中的请求、响应和响应码。 */
UCLASS(MinimalAPI)
class UGenericProtocolHttpTestListener : public UObject
{
	GENERATED_BODY()

public:
	/** 标记错误分支是否被触发，用于测试立即失败请求的广播行为。 */
	UPROPERTY()
	bool bReceivedError=false;

	/** 错误分支传出的响应码，立即失败时应保持 CodeUnKnown。 */
	UPROPERTY()
	EHttpResponseCode ResponseCode=EHttpResponseCode::CodeUnKnown;

	/** 错误分支传回的请求对象，用于确认异步节点上下文仍然可用。 */
	UPROPERTY()
	UGenericHttpRequest* Request=nullptr;

	/** 错误分支传回的响应对象，立即失败时应为空。 */
	UPROPERTY()
	UGenericHttpResponse* Response=nullptr;

	/** 绑定到 OnError 委托，将回调参数保存到测试可断言的字段中。 */
	UFUNCTION(Category="Generic Protocol Http Test Types")
	void HandleResponse(EHttpRequestStatusBP ConnectionStatus, UGenericHttpRequest* InRequest, UGenericHttpResponse* InResponse, EHttpResponseCode InResponseCode)
	{
		bReceivedError = true;
		Request = InRequest;
		Response = InResponse;
		ResponseCode = InResponseCode;
	}
};

/** 暴露基类受保护请求创建和发送流程，方便自动化测试直接驱动失败路径。 */
UCLASS()
class UGenericProtocolHttpTestAction : public USendHttpRequestAsyncAction
{
	GENERATED_BODY()

public:
	/** 绑定测试请求但暂不发送，使测试能先连接监听器。 */
	void Prepare(UGenericHttpRequest* InRequest)
	{
		CreateRequest(InRequest);
	}

	/** 触发基类发送流程，用于验证提交失败时的错误广播。 */
	void Execute()
	{
		SendRequest();
	}
};
