#pragma once

#include "CoreMinimal.h"
#include "Core/GenericPropertyTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Property.generated.h"

class UGenericProperty;
class UGenericPropertyDataSourceCollection;
class UGenericPropertyProxy;
class UGenericPropertyRowValueSpawner;
class UGenericPropertyValue;

/** 通用属性蓝图函数库，提供代理创建和旧版通配符提交节点入口。 */
UCLASS(MinimalAPI)
class UBPFunctions_Property : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 创建并初始化属性代理，供蓝图手动管理属性集合或值句柄。 */
	UFUNCTION(BlueprintCallable, Category="Generic Property", meta=(DefaultToSelf="Outer", AdvancedDisplay="Outer,DataSourceClass"))
	static GENERICPROPERTYFRAMEWORK_API UGenericPropertyProxy* CreatePropertyProxy(UObject* Outer, const TArray<UObject*>& Targets, const FGenericPropertyPanelOptions& Options, TSubclassOf<UGenericPropertyDataSourceCollection> DataSourceClass);

	/** 旧版通配符入口：把蓝图任意输入导出为文本并提交到属性节点。 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category="Generic Property", meta=(CustomStructureParam="Value", AutoCreateRefTerm="Value", BlueprintInternalUseOnly="true", DeprecatedFunction, DeprecationMessage="Use typed value handles or typed property widgets instead of wildcard string-bridge commits."))
	static GENERICPROPERTYFRAMEWORK_API bool CommitPropertyValue(UGenericProperty* Property, const int32& Value);
	DECLARE_FUNCTION(execCommitPropertyValue);

	/** 旧版通配符入口：把蓝图任意输入导出为文本并提交到值控件。 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category="Generic Property", meta=(CustomStructureParam="Value", AutoCreateRefTerm="Value", BlueprintInternalUseOnly="true", DeprecatedFunction, DeprecationMessage="Use typed value handles or typed property widgets instead of wildcard string-bridge commits."))
	static GENERICPROPERTYFRAMEWORK_API bool CommitPropertyValueWidget(UGenericPropertyValue* ValueWidget, const int32& Value);
	DECLARE_FUNCTION(execCommitPropertyValueWidget);

	/** 旧版通配符入口：把蓝图任意输入导出为文本并提交到值生成器。 */
	UFUNCTION(BlueprintCallable, CustomThunk, Category="Generic Property", meta=(CustomStructureParam="Value", AutoCreateRefTerm="Value", BlueprintInternalUseOnly="true", DeprecatedFunction, DeprecationMessage="Use typed value handles or typed property widgets instead of wildcard string-bridge commits."))
	static GENERICPROPERTYFRAMEWORK_API bool CommitPropertyValueSpawner(UGenericPropertyRowValueSpawner* ValueSpawner, const int32& Value);
	DECLARE_FUNCTION(execCommitPropertyValueSpawner);
};
