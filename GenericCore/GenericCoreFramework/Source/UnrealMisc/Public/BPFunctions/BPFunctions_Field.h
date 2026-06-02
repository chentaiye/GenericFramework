// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Type/DebugType.h"
#include "Type/FieldType.h"
#include "UObject/PropertyAccessUtil.h"
#include "BPFunctions_Field.generated.h"

/** 集中暴露字段蓝图函数库接口，让蓝图通过稳定入口访问Unreal 通用工具功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_Field : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 读取布尔属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Field")
	static UNREALMISC_API bool GetBooleanValue(const UObject* Target, const FName& PropertyName, bool& Value);

	/** 写入布尔属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, Category="Field")
	static UNREALMISC_API bool SetBooleanValue(UObject* Target, const FName& PropertyName, bool Value);

	/** 读取整数属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Field")
	static UNREALMISC_API bool GetIntegerValue(const UObject* Target, const FName& PropertyName, int32& Value);

	/** 写入整数属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, Category="Field")
	static UNREALMISC_API bool SetIntegerValue(UObject* Target, const FName& PropertyName, int32 Value);

	/** 读取64 位整数属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Field")
	static UNREALMISC_API bool GetInteger64Value(const UObject* Target, const FName& PropertyName, int64& Value);

	/** 写入64 位整数属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, Category="Field")
	static UNREALMISC_API bool SetInteger64Value(UObject* Target, const FName& PropertyName, int64 Value);

	/** 读取浮点属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Field")
	static UNREALMISC_API bool GetFloatValue(const UObject* Target, const FName& PropertyName, float& Value);

	/** 写入浮点属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, Category="Field")
	static UNREALMISC_API bool SetFloatValue(UObject* Target, const FName& PropertyName, float Value);

	/** 读取双精度属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Field")
	static UNREALMISC_API bool GetDoubleValue(const UObject* Target, const FName& PropertyName, double& Value);

	/** 写入双精度属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, Category="Field")
	static UNREALMISC_API bool SetDoubleValue(UObject* Target, const FName& PropertyName, double Value);

	/** 读取名称属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Field")
	static UNREALMISC_API bool GetNameValue(const UObject* Target, const FName& PropertyName, FName& Value);

	/** 写入名称属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, Category="Field")
	static UNREALMISC_API bool SetNameValue(UObject* Target, const FName& PropertyName, FName Value);

	/** 读取字符串属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Field")
	static UNREALMISC_API bool GetStringValue(const UObject* Target, const FName& PropertyName, FString& Value);

	/** 写入字符串属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, Category="Field")
	static UNREALMISC_API bool SetStringValue(UObject* Target, const FName& PropertyName, FString Value);

	/** 读取文本属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Field")
	static UNREALMISC_API bool GetTextValue(const UObject* Target, const FName& PropertyName, FText& Value);

	/** 写入文本属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, Category="Field")
	static UNREALMISC_API bool SetTextValue(UObject* Target, const FName& PropertyName, FText Value);

	/** 读取向量属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Field")
	static UNREALMISC_API bool GetVectorValue(const UObject* Target, const FName& PropertyName, FVector& Value);

	/** 写入向量属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, Category="Field")
	static UNREALMISC_API bool SetVectorValue(UObject* Target, const FName& PropertyName, FVector Value);

	/** 读取旋转属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	UFUNCTION(BlueprintPure, Category="Field")
	static UNREALMISC_API bool GetRotatorValue(const UObject* Target, const FName& PropertyName, FRotator& Value);

	/** 写入旋转属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, Category="Field")
	static UNREALMISC_API bool SetRotatorValue(UObject* Target, const FName& PropertyName, FRotator Value);

public:
	/** 读取指定类型属性值，封装底层查询细节并减少蓝图侧样板逻辑。 */
	template <typename T>
	static bool GetValueOfType(const UObject* Target, const FName& PropertyName, T& OutValue)
	{
		const FProperty* NamedProperty = PropertyAccessUtil::FindPropertyByName(PropertyName, Target->GetClass());
		if (nullptr == NamedProperty)
		{
			GenericLOG(GenericLogField, Error, TEXT("Find Null Property Named: %s"), *(PropertyName.ToString()));
			return false;
		}

		const T* TempValue = NamedProperty->ContainerPtrToValuePtr<T>(Target);
		if (TempValue)
		{
			OutValue = *TempValue;
			return true;
		}

		return false;
	}

	/** 写入指定类型属性值，通过反射保持 UObject 属性存储同步。 */
	template <typename T>
	static bool SetValueOfType(UObject* Target, const FName& PropertyName, T InValue)
	{
		const FProperty* NamedProperty = PropertyAccessUtil::FindPropertyByName(PropertyName, Target->GetClass());
		if (nullptr == NamedProperty)
		{
			GenericLOG(GenericLogField, Error, TEXT("Find Null Property Named: %s"), *(PropertyName.ToString()));
			return false;
		}

		T* TargetPropertyAddress = NamedProperty->ContainerPtrToValuePtr<T>(Target);
		if (TargetPropertyAddress)
		{
			*TargetPropertyAddress = InValue;
			return true;
		}

		return false;
	}

public:
	/** 写入属性值，通过反射保持 UObject 属性存储同步。 */
	UFUNCTION(BlueprintCallable, CustomThunk, DisplayName="Set Property Value", meta=(DefaultToSelf="TargetObject", CustomStructureParam = "Value", BlueprintInternalUseOnly))
	static void SetPropertyValue(const UObject* TargetObject, FName PropertyName, const int32& Value);

	/** 执行 CustomThunk 属性写入，把蓝图传入的任意类型数据复制到目标属性。 */
	static UNREALMISC_API void Generic_SetPropertyValue(UObject* TargetObject, const FProperty* TargetProperty, void* SourceValuePtr);
	DECLARE_FUNCTION(execSetPropertyValue);
};
