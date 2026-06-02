// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericThread.h"
/* #include "StaticFunctions_Thread.generated.h" */
/** 通过目标线程类型的 CreateThread 工厂构造共享实例，让 ExtraProc 等模块复用统一创建入口。 */
template <typename T = FGenericThread, typename... ArgTypes>
static TSharedPtr<T> NewGenericThread(ArgTypes&&... Args)
{
	TSharedPtr<T> Result = T::CreateThread(Forward<ArgTypes>(Args)...);
	return Result;
}
