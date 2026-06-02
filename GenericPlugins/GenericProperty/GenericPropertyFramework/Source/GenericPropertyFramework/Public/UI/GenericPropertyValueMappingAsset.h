#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Core/GenericPropertyDescriptor.h"
#include "Core/GenericPropertyTypes.h"
#include "GenericPropertyValueMappingAsset.generated.h"

class UGenericProperty;
class UGenericPropertyValueHandleBase;
class UGenericPropertyValue;

/** 值控件映射规则，用属性节点结构、值类型、原生类型、名称和路径选择控件类。 */
USTRUCT(BlueprintType)
struct GENERICPROPERTYFRAMEWORK_API FGenericPropertyValueClassRule
{
	GENERATED_BODY()

	/** 是否要求节点结构类型匹配 NodeKind。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	bool bMatchNodeKind=true;

	/** 规则匹配的节点结构类型。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property", meta=(EditCondition="bMatchNodeKind"))
	EGenericPropertyNodeKind NodeKind=EGenericPropertyNodeKind::Value;

	/** 规则匹配的值语义类型，Unknown 表示不限制。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	EGenericPropertyValueType TypeName=EGenericPropertyValueType::Unknown;

	/** 原生类型名需要包含的字符串片段。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	FString NativeTypeContains;

	/** 需要精确匹配的属性名。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	FName PropertyName=NAME_None;

	/** 属性路径需要包含的字符串片段。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	FString PathContains;

	/** 多条规则同时命中时的基础权重。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	int32 Priority=0;

	/** 规则命中后创建的值控件类。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	TSoftClassPtr<UGenericPropertyValue> WidgetClass;
};

/** 值控件映射资产，供值生成器按属性或句柄描述符解析最合适的 UMG 控件。 */
UCLASS(MinimalAPI, BlueprintType)
class UGenericPropertyValueMappingAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	/** 根据旧属性节点和映射规则解析值控件类。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API TSubclassOf<UGenericPropertyValue> ResolveValueWidgetClass(const UGenericProperty* InProperty) const;

	/** 根据值句柄描述符解析值控件类。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property")
	GENERICPROPERTYFRAMEWORK_API TSubclassOf<UGenericPropertyValue> ResolveValueWidgetClassForHandle(
		const UGenericPropertyValueHandleBase* InValueHandle) const;

	/** 根据公共描述符解析值控件类，字段键直连 UI 使用该路径。 */
	GENERICPROPERTYFRAMEWORK_API TSubclassOf<UGenericPropertyValue> ResolveValueWidgetClassForDescriptor(
		const FGenericPropertyDescriptor& InDescriptor) const;

	/** 自定义控件映射规则，解析时按得分选择最佳控件类。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	TArray<FGenericPropertyValueClassRule> Rules;

	/** 没有规则命中时优先使用的默认控件类。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Generic Property")
	TSoftClassPtr<UGenericPropertyValue> DefaultWidgetClass;
};
