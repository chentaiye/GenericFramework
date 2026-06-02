// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/** 定义StaticFunctions枚举类型，作为 Unreal 通用工具 模块内复用的稳定入口。 */
class UNREALMISC_API FStaticFunctions_Enum
{
public:
	/** 读取枚举值，供调用方复用当前对象缓存或引擎状态。 */
	template <typename EnumType>
	static int64 GetEnumValue(EnumType InEnum)
	{
		const UEnum* EnumPtr = StaticEnum<EnumType>();
		const int32 Index = static_cast<int32>(InEnum);

		return EnumPtr->GetValueByIndex(Index);
	}

	/** 读取枚举By值，供调用方复用当前对象缓存或引擎状态。 */
	template <typename EnumType>
	static bool GetEnumByValue(int64 InValue, EnumType& OutEnum)
	{
		if (InValue != INDEX_NONE)
		{
			OutEnum = static_cast<EnumType>(InValue);
			return true;
		}
		return false;
	}

	/** 读取枚举名称，供调用方复用当前对象缓存或引擎状态。 */
	template <typename EnumType>
	static FName GetEnumName(EnumType InEnum)
	{
		const UEnum* EnumPtr = StaticEnum<EnumType>();
		const int32 Index = static_cast<int32>(InEnum);

		return EnumPtr->GetNameByIndex(Index);
	}

	/** 读取枚举By名称，供调用方复用当前对象缓存或引擎状态。 */
	template <typename EnumType>
	static bool GetEnumByName(FName InName, EnumType& OutEnum)
	{
		if (InName != NAME_None)
		{
			const UEnum* EnumPtr = StaticEnum<EnumType>();

			int64 Value = EnumPtr->GetValueByName(InName);

			return GetEnumByValue(Value, OutEnum);
		}
		return false;
	}

	/** 读取枚举名称字符串，供调用方复用当前对象缓存或引擎状态。 */
	template <typename EnumType>
	static FString GetEnumNameString(EnumType InEnum)
	{
		const UEnum* EnumPtr = StaticEnum<EnumType>();
		const int32 Index = static_cast<int32>(InEnum);

		return EnumPtr->GetNameStringByIndex(Index);
	}

	/** 读取枚举By名称字符串，供调用方复用当前对象缓存或引擎状态。 */
	template <typename EnumType>
	static bool GetEnumByNameString(FString InNameString, EnumType& OutEnum)
	{
		if (!InNameString.IsEmpty())
		{
			const UEnum* EnumPtr = StaticEnum<EnumType>();

			int64 Value = EnumPtr->GetValueByNameString(InNameString);

			return GetEnumByValue(Value, OutEnum);
		}
		return false;
	}

	/** 读取枚举显示名称文本，供调用方复用当前对象缓存或引擎状态。 */
	template <typename EnumType>
	static FText GetEnumDisplayNameText(EnumType InEnum)
	{
		const UEnum* EnumPtr = StaticEnum<EnumType>();
		const int32 Index = static_cast<int32>(InEnum);

		return EnumPtr->GetDisplayNameTextByIndex(Index);
	}

#if WITH_EDITOR

	/** 读取枚举提示文本，供编辑器和蓝图展示本地化说明。 */
	template <typename EnumType>
	static FText GetEnumTooltipText(EnumType InEnum)
	{
		const UEnum* EnumPtr = StaticEnum<EnumType>();
		const int32 Index = static_cast<int32>(InEnum);

		return EnumPtr->GetToolTipTextByIndex(Index);
	}
#endif
};
