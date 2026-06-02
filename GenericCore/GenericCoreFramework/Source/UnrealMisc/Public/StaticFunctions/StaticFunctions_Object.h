// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/** 定义StaticFunctions对象类型，作为 Unreal 通用工具 模块内复用的稳定入口。 */
class UNREALMISC_API FStaticFunctions_Object
{
public:
	/** 加载类型，把软引用解析为运行时可直接使用的对象或类型。 */
	template <typename T>
	static TSubclassOf<T> LoadClass(TSoftClassPtr<T> InSoftClass)
	{
		if (InSoftClass.IsNull()) { return nullptr; }

		if (InSoftClass.IsPending()) { return InSoftClass.LoadSynchronous(); }
		else
		{
			return InSoftClass.Get();
		}
	}

	/** 加载类型，把软引用解析为运行时可直接使用的对象或类型。 */
	template <typename T>
	static TArray<TSubclassOf<T>> LoadClass(const TArray<TSoftClassPtr<T>>& InSoftClasses)
	{
		TArray<TSubclassOf<T>> Result;
		for (auto& InSoftClass : InSoftClasses)
		{
			if (TSubclassOf<T> Class = LoadClass(InSoftClass))
			{
				Result.Add(Class);
			}
		}
		return Result;
	}

public:
	/** 加载对象，把软引用解析为运行时可直接使用的对象或类型。 */
	template <typename T>
	static T* LoadObject(TSoftObjectPtr<T> InSoftObject)
	{
		if (InSoftObject.IsNull()) { return nullptr; }

		if (InSoftObject.IsPending()) { return InSoftObject.LoadSynchronous(); }
		else
		{
			return InSoftObject.Get();
		}
	}

	/** 加载对象，把软引用解析为运行时可直接使用的对象或类型。 */
	template <typename T>
	static TArray<T*> LoadObject(TArray<TSoftObjectPtr<T>> InSoftObjects)
	{
		TArray<T*> Result;
		for (auto& InSoftObject : InSoftObjects)
		{
			if (T* Object = LoadObject(InSoftObjects))
			{
				Result.Add(Object);
			}
		}
		return Result;
	}
};
