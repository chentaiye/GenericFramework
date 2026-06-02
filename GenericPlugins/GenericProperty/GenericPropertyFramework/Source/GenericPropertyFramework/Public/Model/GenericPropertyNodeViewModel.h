#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyDescriptor.h"
#include "UObject/Object.h"
#include "GenericPropertyNodeViewModel.generated.h"

class UGenericPropertyValueHandleBase;

/** 基于新值句柄 API 的属性节点视图模型，组合描述符、状态和值句柄供 UI 直接消费。 */
UCLASS(MinimalAPI, BlueprintType, Transient)
class UGenericPropertyNodeViewModel : public UObject
{
	GENERATED_BODY()

public:
	/** 写入句柄、描述符和状态快照，建立 UI 可读取的节点上下文。 */
	GENERICPROPERTYFRAMEWORK_API void Initialize(UGenericPropertyValueHandleBase* InValueHandle, const FGenericPropertyDescriptor& InDescriptor, const FGenericPropertyState& InState);

	/** 返回负责实际读写目标属性的值句柄。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	UGenericPropertyValueHandleBase* GetValueHandle() const { return ValueHandle; }

	/** 返回属性描述符快照，供蓝图读取名称、类型和元数据。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	FGenericPropertyDescriptor GetDescriptor() const { return Descriptor; }

	/** 供蓝图读取节点当前可见、可编辑、脏和校验状态，避免直接访问句柄内部状态。 */
	UFUNCTION(BlueprintPure, Category="Generic Property")
	FGenericPropertyState GetState() const { return State; }

	/** 替换当前状态快照，供外部同步句柄刷新结果。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	void SetState(const FGenericPropertyState& InState)
	{
		State = InState;
	}

	/** 属性描述符数据，驱动 UI 名称、样式和值类型展示。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FGenericPropertyDescriptor Descriptor;

	/** 当前节点的可见、可编辑、脏、无效等展示状态。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Property")
	FGenericPropertyState State;

	/** 绑定的值句柄，负责从代理会话读取和提交实际属性值。 */
	UPROPERTY(Transient, BlueprintReadOnly, Category="Generic Property")
	TObjectPtr<UGenericPropertyValueHandleBase> ValueHandle=nullptr;
};
