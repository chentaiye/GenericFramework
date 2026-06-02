// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericThread.h"
/** 在单线程运行模式下复用 FGenericThread 状态机，由 FSingleThreadRunnable Tick 推进 RunInternal。 */
class GENERICTHREADSYSTEM_API FGenericSingleThread : public FGenericThread, public FSingleThreadRunnable
{
public:
	/** 初始化单线程适配器的名称、栈大小和优先级，供共享实例进入统一 Launch 流程。 */
	FGenericSingleThread(const FString& InThreadName = TEXT("GenericSingleThread"), uint32 InThreadSize = 0, EThreadPriority InThreadPriority = EThreadPriority::TPri_Normal);

	virtual ~FGenericSingleThread() override;

	/** 构造共享单线程对象，供模板工厂和上层代码用通用线程接口启动。 */
	static TSharedPtr<FGenericSingleThread> CreateThread(const FString& InThreadName, uint32 InThreadSize = 0, EThreadPriority InThreadPriority = EThreadPriority::TPri_Normal)
	{
		return MakeShareable(new FGenericSingleThread(InThreadName, InThreadSize, InThreadPriority));
	}

	/* FRunnable 接口 */
public:
	virtual FSingleThreadRunnable* GetSingleThreadInterface() override { return this; }

	/* FSingleThreadRunnable 接口 */
private:
	virtual void Tick() override;
};
