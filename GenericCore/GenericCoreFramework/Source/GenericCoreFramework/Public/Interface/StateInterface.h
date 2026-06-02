// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "StateInterface.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnActivedFinish, UObject*)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnInactivedFinish, UObject*)

/** 声明状态接口的 UObject 反射类型，供蓝图和 C++ 共享同一接口契约。 */
UINTERFACE(MinimalAPI)
class UStateInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义状态接口类型，作为 运行时核心 模块内复用的稳定入口。 */
class GENERICCOREFRAMEWORK_API IStateInterface
{
	GENERATED_BODY()

public:
	/** 触发创建阶段蓝图事件，作为对象进入状态机时的外部通知。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="State Interface")
	void HandleOnCreate();

	/** 处理创建阶段的 C++ 扩展点，供实现类在蓝图事件之外更新内部状态。 */
	virtual void NativeOnCreate();

	/** 触发激活阶段蓝图事件，并串联激活完成通知。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="State Interface")
	void HandleOnActived();

	/** 处理激活阶段的 C++ 扩展点，供实现类更新内部激活状态。 */
	virtual void NativeOnActived();

	/** 触发激活完成蓝图事件，通知外部状态切换已经结束。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="State Interface")
	void HandleOnActivedFinish();

	/** 处理激活完成的 C++ 扩展点，供实现类收尾激活流程。 */
	virtual void NativeOnActivedFinish();

	/** 触发失活阶段蓝图事件，并串联失活完成通知。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="State Interface")
	void HandleOnInactived();

	/** 处理失活阶段的 C++ 扩展点，供实现类释放激活态资源。 */
	virtual void NativeOnInactived();

	/** 触发失活完成蓝图事件，通知外部状态切换已经结束。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="State Interface")
	void HandleOnInactivedFinish();

	/** 处理失活完成的 C++ 扩展点，供实现类收尾失活流程。 */
	virtual void NativeOnInactivedFinish();

	/** 触发销毁阶段蓝图事件，让状态对象在释放前完成外部通知。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="State Interface")
	void HandleOnDestroy();

	/** 处理销毁阶段的 C++ 扩展点，供实现类清理内部资源。 */
	virtual void NativeOnDestroy();

	/** 读取是否激活，供调用方复用当前对象缓存或引擎状态。 */
	virtual bool GetIsActived() const;

	/** 写入是否激活，并保持当前对象状态与外部调用结果一致。 */
	virtual void SetIsActived(const bool InActived);

	/** 读取激活完成事件，供调用方复用当前对象缓存或引擎状态。 */
	FOnActivedFinish& GetOnActivedFinishEvent() { return OnActivedFinishEvent; }

	/** 读取失活完成事件，供调用方复用当前对象缓存或引擎状态。 */
	FOnInactivedFinish& GetOnInactivedFinishEvent() { return OnInactivedFinishEvent; }

protected:
	/** 记录状态激活标记，用于在生命周期、同步或输入流程中选择后续路径。 */
	bool bIsActived = false;

	FOnActivedFinish OnActivedFinishEvent;

	FOnInactivedFinish OnInactivedFinishEvent;
};
