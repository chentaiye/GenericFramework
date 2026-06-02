// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Features/IModularFeature.h"
#include "NativeAPITypes.h"

DECLARE_DELEGATE_OneParam(FOnReceiveNativePayload, const FNativeAPIPayload&);

/** 约束 NativeAPI 外部会话 Feature 入口，WebSocket 和 HTTPRoute 实现通过它接入统一 Payload 分发。 */
class NATIVEAPI_API INativeAPISessionFeatureInterface : public IModularFeature
{
public:
	/** 返回模块化 Feature 注册名，模块启动和子系统查询会话实现时必须使用同一个名称。 */
	static FName GetFeatureName()
	{
		static FName NativeAPISessionFeatureName(TEXT("NativeAPISession"));
		return NativeAPISessionFeatureName;
	};

	/** 保证模块通过接口指针释放会话实现时，派生类持有的外部通道资源可以正确析构。 */
	virtual ~INativeAPISessionFeatureInterface()
	{
	}

	/** 返回具体会话通道名称，用于日志和区分 WebSocket、HTTPRoute 等实现。 */
	virtual FName GetSessionName() = 0;

	/** 按当前激活世界设置打开外部输入通道，成功后由子系统绑定 Payload 回调。 */
	virtual bool StartSession() = 0;

	/** 关闭外部输入通道并释放句柄，世界切换、Feature 注销和模块卸载时调用。 */
	virtual void EndSession() = 0;

protected:
	/** 由引擎子系统注入 Payload 接收回调，把会话层解析结果接回统一分发入口。 */
	void SetReceiveSessionPayloadBinding(FOnReceiveNativePayload&& InDelegate)
	{
		ReceiveNativePayload = MoveTemp(InDelegate);
	}

	/** 会话实现解析出有效 Payload 后调用，触发绑定的子系统回调继续路由。 */
	void NotifyReceiveNativePayload(const FNativeAPIPayload& Payload) const
	{
		ReceiveNativePayload.ExecuteIfBound(Payload);
	}

	FOnReceiveNativePayload ReceiveNativePayload;
	friend class UNativeAPISubsystem;
};
