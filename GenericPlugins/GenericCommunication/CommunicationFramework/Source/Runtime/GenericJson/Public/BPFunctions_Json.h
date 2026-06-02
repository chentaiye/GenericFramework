// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Json.generated.h"

class UGenericJsonObject;

/** 提供 JSON 与结构体、蓝图通配引脚之间的反射转换入口。 */
UCLASS(MinimalAPI)
class UBPFunctions_Json : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** CustomThunk 占位入口，execGetJsonField 会按输出引脚的 FProperty 类型读取 JSON 字段。 */
	UFUNCTION(BlueprintCallable, CustomThunk, BlueprintInternalUseOnly, Category="Json", meta=(CustomStructureParam="OutValue", AutoCreateRefTerm="OutValue"))
	static GENERICJSON_API bool GetJsonField(UGenericJsonObject* JsonObject, const FString& FieldName, int32& OutValue);
	DECLARE_FUNCTION(execGetJsonField);

	/** CustomThunk 占位入口，execSetJsonField 会把任意输入引脚反射为 JSON 值并写入对象。 */
	UFUNCTION(BlueprintCallable, CustomThunk, BlueprintInternalUseOnly, Category="Json", meta=(CustomStructureParam="Value", AutoCreateRefTerm="Value"))
	static GENERICJSON_API bool SetJsonField(UGenericJsonObject* JsonObject, const FString& FieldName, const int32& Value);
	DECLARE_FUNCTION(execSetJsonField);

public:
	/** CustomThunk 占位入口，execSaveStructToJsonFile 会解析结构体输入并持久化为 JSON 文件。 */
	UFUNCTION(BlueprintCallable, CustomThunk, BlueprintInternalUseOnly, Category="Json", meta=(CustomStructureParam="Value", AutoCreateRefTerm="Value", ExpandEnumAsExecs="Result"))
	static GENERICJSON_API void SaveStructToJsonFile(bool& Result, const FString& FilePath, const int32& Value);
	DECLARE_FUNCTION(execSaveStructToJsonFile);

	/** CustomThunk 占位入口，execLoadJsonFileToStruct 会按输出结构体类型从 JSON 文件反序列化。 */
	UFUNCTION(BlueprintCallable, CustomThunk, BlueprintInternalUseOnly, Category="Json", meta=(CustomStructureParam="Value", ExpandEnumAsExecs="Result"))
	static GENERICJSON_API void LoadJsonFileToStruct(bool& Result, const FString& FilePath, int32& Value);
	DECLARE_FUNCTION(execLoadJsonFileToStruct);

public:
	/** 创建空 FJsonObject，供包装对象或反射写入流程作为目标容器。 */
	static GENERICJSON_API TSharedPtr<FJsonObject> ConstructJsonObject();

	/** 从 JSON 字符串创建 FJsonObject，并通过 Result 告知调用方反序列化是否成功。 */
	static GENERICJSON_API TSharedPtr<FJsonObject> ConstructJsonObject(const FString& JsonString, bool& Result);

	/** 将 JSON object 压缩序列化为字符串，供网络发送和文件保存前复用。 */
	static GENERICJSON_API FString ToJsonString(const TSharedPtr<FJsonObject>& JsonObject);

	/** 将单个 JSON value 转为调试或字段拼接用的字符串表示。 */
	static GENERICJSON_API FString ToJsonString(const TSharedPtr<FJsonValue>& JsonValue);

	/** 将 JSON value 数组序列化为 JSON 数组字符串，供集合字段导出使用。 */
	static GENERICJSON_API FString ToJsonString(const TArray<TSharedPtr<FJsonValue>>& JsonValueArray);

	/** 按 UStruct 字段遍历 JSON object，把匹配字段写回结构体或对象实例内存。 */
	static GENERICJSON_API void ReadStruct(const TSharedPtr<FJsonObject>& JsonObject, const UStruct* Struct, void* Instance, UObject* Owner);

	/** 按 FProperty 具体类型从 JSON value 写入目标内存，是结构体反序列化的核心分发点。 */
	static GENERICJSON_API void ReadValue(const TSharedPtr<FJsonValue>& JsonValue, const FProperty* Property, void* DataPtr, UObject* Owner);

	/** 遍历 UStruct 属性并生成 JSON object，供结构体保存和自定义节点写字段使用。 */
	static GENERICJSON_API TSharedPtr<FJsonObject> WriteStruct(const UStruct* Struct, const void* Instance, const void* Defaults);

	/** 遍历 UObject 属性并生成 JSON object，保留对象类型名用于后续校验。 */
	static GENERICJSON_API TSharedPtr<FJsonObject> WriteUObject(const UClass* Class, const UObject* Instance);

	/** 将数组属性逐项转换为 JSON value array，供 WriteValue 处理 FArrayProperty。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> WriteArray(const FArrayProperty* ArrayProperty, const void* DataPtr);

	/** 将 Set 属性逐项转换为 JSON value array，保留无序集合中的有效元素。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> WriteSet(const FSetProperty* Property, const void* DataPtr);

	/** 将 Map 属性转换为 JSON object 或 `$key`/`$value` 数组，适配不同键类型的可表示性。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> WriteMap(const FMapProperty* Property, const void* DataPtr);

	/** 按 FProperty 类型把单个属性内存转换为 JSON value，是序列化的核心分发点。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> WriteValue(const FProperty* Property, const void* DataPtr, const void* Defaults);

	/** 将 UFunction 参数默认值写成 JSON object，用于函数签名或参数模板导出。 */
	static GENERICJSON_API TSharedPtr<FJsonObject> WriteFunction(const UFunction* Function, const void* Defaults);

	/** 从 JSON 文件读取并填充指定结构体内存，供通配结构体节点执行加载。 */
	static GENERICJSON_API bool JsonFileToStruct(const FString& FilePath, const UStruct* Struct, void* StructPtr);

	/** 将指定结构体内存序列化并写入 JSON 文件，供通配结构体节点执行保存。 */
	static GENERICJSON_API bool StructToJsonFile(const FString& FilePath, const UStruct* Struct, const void* StructPtr);

	/** 将已有 JSON object 按指定 UStruct 布局写入结构体内存。 */
	static GENERICJSON_API bool JsonObjectToStruct(const TSharedPtr<FJsonObject>& JsonObject, const UStruct* Struct, void* StructPtr);

	/** 将指定结构体内存写入外部传入的 JSON object，供调用方复用已有容器。 */
	static GENERICJSON_API bool StructToJsonObject(const UStruct* Struct, const void* StructPtr, const TSharedRef<FJsonObject>& OutJsonObject);

	/** 按目标属性类型读取指定 JSON 字段，用于 GetJsonField 通配输出引脚。 */
	static GENERICJSON_API bool JsonFieldToProperty(const FString& FieldName, UGenericJsonObject* SourceObject, FProperty* TargetProperty, void* TargetValuePtr);

	/** 按源属性类型生成 JSON 字段，用于 SetJsonField 通配输入引脚。 */
	static GENERICJSON_API bool PropertyToJsonField(const FString& FieldName, FProperty* SourceProperty, const void* SourceValuePtr, UGenericJsonObject*& TargetObject);

	/** 将字节数组包装为自定义二进制 JSON 值，序列化时以 Base64 字符串输出。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> ToJsonValue(const TArray<uint8>& InValue);

	/** 将布尔值包装为 JSON boolean，供字段和数组写入复用。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> ToJsonValue(bool InValue);

	/** 将 int32 包装为 JSON number，供蓝图整数写入 JSON 字段。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> ToJsonValue(int32 InValue);

	/** 将 int64 包装为 JSON number，供长整数写入 JSON 字段。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> ToJsonValue(int64 InValue);

	/** 将 double 包装为 JSON number，保留浮点字段的 JSON 数值语义。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> ToJsonValue(double InValue);

	/** 根据字符串内容推断 null、number、object、array、bool 或 string 并生成对应 JSON 值。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> ToJsonValue(const FString& InValue);

	/** 将 JSON 数组文本解析为 JSON value 集合，供字符串形式的数组字段写入。 */
	static GENERICJSON_API TArray<TSharedPtr<FJsonValue>> ToJsonValues(const FString& InValue);

	/** 将字符串数组逐项推断并转换为 JSON value 集合。 */
	static GENERICJSON_API TArray<TSharedPtr<FJsonValue>> ToJsonValues(const TArray<FString>& InValue);

	/** 将 JSON object 包装为 JSON value，供嵌套对象字段写入。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> ToJsonValue(const TSharedPtr<FJsonObject>& InValue);

	/** 将 JSON object 数组包装为 JSON value 集合，供对象数组字段写入。 */
	static GENERICJSON_API TArray<TSharedPtr<FJsonValue>> ToJsonValues(const TArray<TSharedPtr<FJsonObject>>& InValue);

	/** 将 UGenericJsonObject 的底层对象包装为 JSON value，保持包装层与原对象共享数据。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> ToJsonValue(UGenericJsonObject* InValue);

	/** 将 UGenericJsonObject 数组转换为 JSON value 集合，忽略无效对象时由元素转换返回空值。 */
	static GENERICJSON_API TArray<TSharedPtr<FJsonValue>> ToJsonValues(const TArray<UGenericJsonObject*>& InValue);

	/** 将已有 JSON value 集合包装为 JSON array，避免重复拆装数组字段。 */
	static GENERICJSON_API TSharedPtr<FJsonValue> ToJsonValue(const TArray<TSharedPtr<FJsonValue>>& InValue);
};
