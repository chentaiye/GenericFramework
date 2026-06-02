#pragma once

#include "CoreMinimal.h"
#include <type_traits>
#include "UObject/SoftObjectPath.h"

class UGenericProperty;
class UGenericPropertyValue;
class UGenericPropertyRowValueSpawner;
class UObject;

namespace GenericPropertyFramework
{
	namespace Templates
	{
		/** 将 FString 直接作为属性面板提交文本。 */
		inline bool SerializeValue(const FString& InValue, FString& OutSerializedValue)
		{
			OutSerializedValue = InValue;
			return true;
		}

		/** 将 FText 转为显示文本后提交给属性面板。 */
		inline bool SerializeValue(const FText& InValue, FString& OutSerializedValue)
		{
			OutSerializedValue = InValue.ToString();
			return true;
		}

		/** 将 FName 转为名称文本后提交给属性面板。 */
		inline bool SerializeValue(const FName InValue, FString& OutSerializedValue)
		{
			OutSerializedValue = InValue.ToString();
			return true;
		}

		/** 将 bool 转为反射导入可识别的 True/False 文本。 */
		inline bool SerializeValue(const bool bInValue, FString& OutSerializedValue)
		{
			OutSerializedValue = bInValue ? TEXT("True") : TEXT("False");
			return true;
		}

		/** 将对象引用转为路径名文本，供对象属性导入。 */
		inline bool SerializeValue(UObject* InValue, FString& OutSerializedValue)
		{
			OutSerializedValue = GetPathNameSafe(InValue);
			return true;
		}

		/** 将软对象路径转为可提交的路径文本。 */
		inline bool SerializeValue(const FSoftObjectPath& InValue, FString& OutSerializedValue)
		{
			OutSerializedValue = InValue.ToString();
			return true;
		}

		/** 将软类路径转为可提交的路径文本。 */
		inline bool SerializeValue(const FSoftClassPath& InValue, FString& OutSerializedValue)
		{
			OutSerializedValue = InValue.ToString();
			return true;
		}

		/** 将整型值转换为属性面板可提交的文本。 */
		template<typename TValueType, typename TEnableIf<TIsIntegral<TValueType>::Value && !std::is_same<TValueType, bool>::value, int>::Type = 0>
		bool SerializeValue(const TValueType InValue, FString& OutSerializedValue)
		{
			OutSerializedValue = LexToString(InValue);
			return true;
		}

		/** 将浮点值转换为属性面板可提交的文本。 */
		template<typename TValueType, typename TEnableIf<TIsFloatingPoint<TValueType>::Value, int>::Type = 0>
		bool SerializeValue(const TValueType InValue, FString& OutSerializedValue)
		{
			OutSerializedValue = LexToString(InValue);
			return true;
		}

		/** 将枚举值转换为底层整数文本，供枚举句柄提交。 */
		template<typename TValueType, typename TEnableIf<TIsEnum<TValueType>::Value, int>::Type = 0>
		bool SerializeValue(const TValueType InValue, FString& OutSerializedValue)
		{
			OutSerializedValue = LexToString(static_cast<typename std::underlying_type<TValueType>::type>(InValue));
			return true;
		}

		/** 使用 StaticStruct 导出结构体文本，供结构体字段提交。 */
		template<typename TValueType>
		auto SerializeValue(const TValueType& InValue, FString& OutSerializedValue) -> decltype(TValueType::StaticStruct(), bool())
		{
			FString ExportedValue;
			TValueType::StaticStruct()->ExportText(ExportedValue, &InValue, nullptr, nullptr, PPF_None, nullptr);
			OutSerializedValue = MoveTemp(ExportedValue);
			return true;
		}

		/** 把序列化文本提交到属性节点。 */
		GENERICPROPERTYFRAMEWORK_API bool CommitSerializedValue(UGenericProperty& InProperty, const FString& InSerializedValue);

		/** 把序列化文本提交到值控件当前绑定的句柄或属性。 */
		GENERICPROPERTYFRAMEWORK_API bool CommitSerializedValue(UGenericPropertyValue& InValueWidget, const FString& InSerializedValue);

		/** 把序列化文本提交到值生成器当前绑定的句柄或属性。 */
		GENERICPROPERTYFRAMEWORK_API bool CommitSerializedValue(UGenericPropertyRowValueSpawner& InSpawner, const FString& InSerializedValue);

		/** 序列化 typed 值并提交到属性节点。 */
		template<typename TValueType>
		bool CommitValue(UGenericProperty& InProperty, const TValueType& InValue)
		{
			FString SerializedValue;
			if (!SerializeValue(InValue, SerializedValue))
			{
				return false;
			}

			return CommitSerializedValue(InProperty, SerializedValue);
		}

		/** 序列化 typed 值并提交到值控件。 */
		template<typename TValueType>
		bool CommitValue(UGenericPropertyValue& InValueWidget, const TValueType& InValue)
		{
			FString SerializedValue;
			if (!SerializeValue(InValue, SerializedValue))
			{
				return false;
			}

			return CommitSerializedValue(InValueWidget, SerializedValue);
		}

		/** 序列化 typed 值并提交到值生成器。 */
		template<typename TValueType>
		bool CommitValue(UGenericPropertyRowValueSpawner& InSpawner, const TValueType& InValue)
		{
			FString SerializedValue;
			if (!SerializeValue(InValue, SerializedValue))
			{
				return false;
			}

			return CommitSerializedValue(InSpawner, SerializedValue);
		}
	}
}
