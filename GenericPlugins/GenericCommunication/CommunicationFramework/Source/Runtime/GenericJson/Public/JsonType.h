// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
GENERICJSON_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogJson, Log, All);

/** 暴露给蓝图的 JSON 字段类型，供字段检查和类型转换函数映射到底层 EJson。 */
UENUM(BlueprintType)
enum class EJsonFieldTypeBP : uint8
{
	/** 不限定具体 JSON 类型，HasTypedField 中按字段存在性处理。 */
	None,

	/** 对应 JSON null，用于显式检查空字段。 */
	Null,

	/** 对应 JSON boolean，供蓝图读写 bool 字段前做类型校验。 */
	Boolean,

	/** 对应 JSON number，供 int、float、double 等数值字段共用。 */
	Number,

	/** 对应 JSON string，供蓝图字符串读写节点在取值前做类型校验。 */
	String,

	/** 对应 JSON object，供嵌套对象访问和对象字段写入逻辑做类型校验。 */
	Object,

	/** 对应 JSON array，供集合字段和数组写入逻辑做类型校验。 */
	Array
};

/** 将蓝图字段类型转换为 UE JSON 类型，供运行时类型检查直接调用。 */
static EJson ConvertToJsonFieldType(EJsonFieldTypeBP JsonFieldType)
{
	switch (JsonFieldType)
	{
	case EJsonFieldTypeBP::None:
		return EJson::None;
	case EJsonFieldTypeBP::Null:
		return EJson::Null;
	case EJsonFieldTypeBP::Boolean:
		return EJson::Boolean;
	case EJsonFieldTypeBP::Number:
		return EJson::Number;
	case EJsonFieldTypeBP::String:
		return EJson::String;
	case EJsonFieldTypeBP::Object:
		return EJson::Object;
	case EJsonFieldTypeBP::Array:
		return EJson::Array;
	}

	return EJson::None;
}

/** 将 UE JSON 类型转换回蓝图枚举，供节点或调试逻辑向蓝图暴露字段类型。 */
static EJsonFieldTypeBP ConvertToJsonFieldTypeBP(EJson JsonFieldType)
{
	switch (JsonFieldType)
	{
	case EJson::None:
		return EJsonFieldTypeBP::None;
	case EJson::Null:
		return EJsonFieldTypeBP::Null;
	case EJson::Boolean:
		return EJsonFieldTypeBP::Boolean;
	case EJson::Number:
		return EJsonFieldTypeBP::Number;
	case EJson::String:
		return EJsonFieldTypeBP::String;
	case EJson::Object:
		return EJsonFieldTypeBP::Object;
	case EJson::Array:
		return EJsonFieldTypeBP::Array;
	}

	return EJsonFieldTypeBP::None;
}
