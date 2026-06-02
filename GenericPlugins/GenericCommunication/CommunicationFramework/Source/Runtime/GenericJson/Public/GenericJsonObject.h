// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonType.h"
#include "Obect/GenericObject.h"
#include "GenericJsonObject.generated.h"

/** 封装可蓝图访问的 FJsonObject，统一 JSON 字符串、文件编解码与字段读写逻辑。 */
UCLASS(MinimalAPI)
class UGenericJsonObject : public UGenericObject
{
	GENERATED_UCLASS_BODY()

public:
	/** 创建由指定上下文持有的 JSON 对象，供蓝图后续读写字段或序列化使用。 */
	UFUNCTION(BlueprintCallable, Category="Json|Base", meta=(HidePin="WorldContextObject", DefaultToSelf="WorldContextObject"))
	static GENERICJSON_API UGenericJsonObject* ConstructJsonObject(UObject* WorldContextObject);

	/** 丢弃当前底层 FJsonObject 并创建空对象，保证后续字段操作有有效容器。 */
	UFUNCTION(BlueprintCallable, Category="Json|Base")
	GENERICJSON_API void Reset();

	/** 将当前对象序列化为格式化 JSON 并写入文件，供蓝图持久化配置或数据快照。 */
	UFUNCTION(BlueprintCallable, Category="Json|Base")
	GENERICJSON_API bool EncodeJsonToFile(FString FileName);

	/** 将当前对象序列化为格式化 JSON 字符串，失败时返回空字符串。 */
	UFUNCTION(BlueprintPure, Category="Json|Base")
	GENERICJSON_API FString EncodeJsonToString();

	/** 核心序列化入口，刷新 JsonString 缓存并把文本回传给文件或字符串导出流程。 */
	UFUNCTION(BlueprintCallable, Category="Json|Base")
	GENERICJSON_API bool EncodeJson(FString& OutJsonString);

	/** 从文件读取 JSON 文本并替换当前对象内容，用于恢复持久化的数据快照。 */
	UFUNCTION(BlueprintCallable, Category="Json|Base")
	GENERICJSON_API bool DecodeJsonFromFile(FString FileName);

	/** 从字符串解析 JSON 并替换当前对象内容，同时保留原始文本缓存。 */
	UFUNCTION(BlueprintCallable, Category="Json|Base")
	GENERICJSON_API bool DecodeJsonFromString(FString InJsonString);

	/** 核心反序列化入口，确保容器有效后把外部 JSON 文本转为运行时对象。 */
	UFUNCTION(BlueprintCallable, Category="Json|Base")
	GENERICJSON_API bool DecodeJson(const FString& InJsonString);

public:
	/** 返回当前 JSON 对象包含的字段名称列表。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API TArray<FString> GetFieldNames() const;

	/** 检查字段名是否存在，供蓝图在读取或覆盖字段前做安全分支。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool HasField(FString FieldName) const;

	/** 检查字段是否存在且匹配指定 JSON 类型，TrySet 系列依赖它避免覆盖错误类型字段。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool HasTypedField(FString FieldName, EJsonFieldTypeBP JsonFieldType) const;

	/** 从当前 JSON 对象移除指定字段。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API void RemoveField(FString FieldName);

public:
	/** 从指定字段读取布尔值，字段缺失或对象无效时通过返回值阻断蓝图流程。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetBoolValue(FString FieldName, bool& OutputValue);

	/** 从指定 JSON 字段读取布尔值数组，字段不存在或类型不匹配时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetBoolValues(FString FieldName, TArray<bool>& OutputValues);

	/** 仅当目标字段已存在且为布尔类型时写入值，避免把已有 JSON 结构改成其他类型。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetBoolValue(FString FieldName, bool InputValue);

	/** 仅当目标字段已存在且为数组时写入布尔数组，数组元素会逐项包装为 JSON 值。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetBoolValues(FString FieldName, const TArray<bool>& InputValues);

	/** 从指定字段读取 int32 数值，底层 JSON number 会转换为蓝图整数输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetInt32Value(FString FieldName, int32& OutputValue);

	/** 从指定 JSON 字段读取整数32值数组，字段不存在或类型不匹配时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetInt32Values(FString FieldName, TArray<int32>& OutputValues);

	/** 仅当目标字段已存在且为数值类型时写入 int32，并按 JSON number 保存。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetInt32Value(FString FieldName, int32 InputValue);

	/** 仅当目标字段已存在且为数组时写入 int32 数组，供蓝图维护数值列表字段。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetInt32Values(FString FieldName, const TArray<int32>& InputValues);

	/** 从指定字段读取 int64 数值，底层 JSON number 会转换为蓝图长整数输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetInt64Value(FString FieldName, int64& OutputValue);

	/** 从指定 JSON 字段读取整数64值数组，字段不存在或类型不匹配时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetInt64Values(FString FieldName, TArray<int64>& OutputValues);

	/** 仅当目标字段已存在且为数值类型时写入 int64，并按 JSON number 保存。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetInt64Value(FString FieldName, int64 InputValue);

	/** 仅当目标字段已存在且为数组时写入 int64 数组，供蓝图维护长整数列表字段。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetInt64Values(FString FieldName, const TArray<int64>& InputValues);

	/** 从指定字段读取 double 数值，供蓝图处理需要保留精度的 JSON number。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetDoubleValue(FString FieldName, double& OutputValue);

	/** 从指定 JSON 字段读取双精度值数组，字段不存在或类型不匹配时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetDoubleValues(FString FieldName, TArray<double>& OutputValues);

	/** 仅当目标字段已存在且为数值类型时写入 double，并保持 JSON number 语义。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetDoubleValue(FString FieldName, double InputValue);

	/** 仅当目标字段已存在且为数组时写入 double 数组，供蓝图维护数值序列。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetDoubleValues(FString FieldName, const TArray<double>& InputValues);

	/** 从指定字段读取字符串值，字段不是 JSON string 时返回失败。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetStringValue(FString FieldName, FString& OutputValue);

	/** 从指定 JSON 字段读取字符串值数组，字段不存在或类型不匹配时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetStringValues(FString FieldName, TArray<FString>& OutputValues);

	/** 仅当目标字段已存在且为字符串类型时写入文本，避免破坏原字段类型。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetStringValue(FString FieldName, FString InputValue);

	/** 仅当目标字段已存在且为数组时写入字符串数组，供蓝图维护文本列表字段。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetStringValues(FString FieldName, const TArray<FString>& InputValues);

	/** 从指定字段读取子对象，并把输出对象绑定到对应的底层 FJsonObject。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetObjectValue(FString FieldName, UGenericJsonObject*& OutputValue);

	/** 从指定 JSON 字段读取对象值数组，字段不存在或类型不匹配时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Json|Field")
	GENERICJSON_API bool TryGetObjectValues(FString FieldName, TArray<UGenericJsonObject*>& OutputValues);

	/** 仅当目标字段已存在且为对象类型时写入子对象引用，保持嵌套 JSON 结构稳定。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetObjectValue(FString FieldName, UGenericJsonObject* InputValue);

	/** 仅当目标字段已存在且为数组时写入对象数组，元素会转换为 JSON object value。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field")
	GENERICJSON_API bool TrySetObjectValues(FString FieldName, const TArray<UGenericJsonObject*>& InputValues);

public:
	/** 在当前对象及嵌套子对象中递归查找布尔字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetBoolValueRecursive(FString FieldName, bool& OutputValue);

	/** 在当前对象及嵌套子对象中递归查找布尔数组字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetBoolValuesRecursive(FString FieldName, TArray<bool>& OutputValues);

	/** 在当前对象及嵌套子对象中递归查找可写布尔字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetBoolValueRecursive(FString FieldName, bool InputValue);

	/** 在当前对象及嵌套子对象中递归查找可写布尔数组字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetBoolValuesRecursive(FString FieldName, const TArray<bool>& InputValues);

	/** 在当前对象及嵌套子对象中递归查找 int32 字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetInt32ValueRecursive(FString FieldName, int32& OutputValue);

	/** 在当前对象及嵌套子对象中递归查找 int32 数组字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetInt32ValuesRecursive(FString FieldName, TArray<int32>& OutputValues);

	/** 在当前对象及嵌套子对象中递归查找可写 int32 字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetInt32ValueRecursive(FString FieldName, int32 InputValue);

	/** 在当前对象及嵌套子对象中递归查找可写 int32 数组字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetInt32ValuesRecursive(FString FieldName, const TArray<int32>& InputValues);

	/** 在当前对象及嵌套子对象中递归查找 int64 字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetInt64ValueRecursive(FString FieldName, int64& OutputValue);

	/** 在当前对象及嵌套子对象中递归查找 int64 数组字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetInt64ValuesRecursive(FString FieldName, TArray<int64>& OutputValues);

	/** 在当前对象及嵌套子对象中递归查找可写 int64 字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetInt64ValueRecursive(FString FieldName, int64 InputValue);

	/** 在当前对象及嵌套子对象中递归查找可写 int64 数组字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetInt64ValuesRecursive(FString FieldName, const TArray<int64>& InputValues);

	/** 在当前对象及嵌套子对象中递归查找 double 字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetDoubleValueRecursive(FString FieldName, double& OutputValue);

	/** 在当前对象及嵌套子对象中递归查找 double 数组字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetDoubleValuesRecursive(FString FieldName, TArray<double>& OutputValues);

	/** 在当前对象及嵌套子对象中递归查找可写 double 字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetDoubleValueRecursive(FString FieldName, double InputValue);

	/** 在当前对象及嵌套子对象中递归查找可写 double 数组字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetDoubleValuesRecursive(FString FieldName, const TArray<double>& InputValues);

	/** 在当前对象及嵌套子对象中递归查找字符串字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetStringValueRecursive(FString FieldName, FString& OutputValue);

	/** 在当前对象及嵌套子对象中递归查找字符串数组字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetStringValuesRecursive(FString FieldName, TArray<FString>& OutputValues);

	/** 在当前对象及嵌套子对象中递归查找可写字符串字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetStringValueRecursive(FString FieldName, FString InputValue);

	/** 在当前对象及嵌套子对象中递归查找可写字符串数组字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetStringValuesRecursive(FString FieldName, const TArray<FString>& InputValues);

	/** 在当前对象及嵌套子对象中递归查找对象字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetObjectValueRecursive(FString FieldName, UGenericJsonObject*& OutputValue);

	/** 在当前对象及嵌套子对象中递归查找对象数组字段，找到首个匹配项后输出。 */
	UFUNCTION(BlueprintPure, Category="Json|Field Recursive")
	GENERICJSON_API bool TryGetObjectValuesRecursive(FString FieldName, TArray<UGenericJsonObject*>& OutputValues);

	/** 在当前对象及嵌套子对象中递归查找可写对象字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetObjectValueRecursive(FString FieldName, UGenericJsonObject* InputValue);

	/** 在当前对象及嵌套子对象中递归查找可写对象数组字段，匹配后更新首个目标。 */
	UFUNCTION(BlueprintCallable, Category="Json|Field Recursive")
	GENERICJSON_API bool TrySetObjectValuesRecursive(FString FieldName, const TArray<UGenericJsonObject*>& InputValues);

public:
	/** 暴露底层 FJsonObject 给反射转换和协议封包代码，避免在包装层重复拷贝字段。 */
	GENERICJSON_API TSharedPtr<FJsonObject> GetJsonObject();

	/** 替换底层 FJsonObject 并同步 JsonString 缓存，供反序列化和子对象读取复用。 */
	GENERICJSON_API void SetJsonObject(const TSharedRef<FJsonObject>& InJsonObject);

private:
	/** 当前包装的底层 JSON 对象，所有字段读写都围绕它执行。 */
	TSharedPtr<FJsonObject> JsonObject;

	/** 最近一次序列化或反序列化得到的文本缓存，供 Encode/SetJsonObject 保持外部表示一致。 */
	FString JsonString;
};
