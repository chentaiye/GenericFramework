// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
/** 扩展 UE JSON 值以承载二进制数据，序列化时以 Base64 字符串参与普通 JSON 流程。 */
class GENERICJSON_API FJsonValueBinary : public FJsonValue
{
public:
	/** 用原始字节初始化 JSON 值，后续字符串读取会返回 Base64 编码结果。 */
	FJsonValueBinary(const TArray<uint8>& InBinary) : Value(InBinary) { Type = EJson::String; }
	virtual bool TryGetString(FString& OutString) const override
	{
		OutString = FBase64::Encode(Value);
		return true;
	}

	virtual bool TryGetNumber(double& OutDouble) const override
	{
		OutDouble = Value.Num();
		return true;
	}

	virtual bool TryGetBool(bool& OutBool) const override { return false; }

	/** 返回内部字节数组，供 WebSocket、HTTP 或结构体反序列化恢复原始二进制载荷。 */
	TArray<uint8> AsBinary() { return Value; }

	/** 判断给定 JSON 值是否按本类型的二进制约定保存，避免把普通布尔值误当作字节流。 */
	static bool IsBinary(const TSharedPtr<FJsonValue>& InJsonValue);

	/** 把JSON值读取为二进制数组，供协议层传输或反序列化使用。 */
	static TArray<uint8> AsBinary(const TSharedPtr<FJsonValue>& InJsonValue);

protected:
	/** 保存待编码的原始字节，TryGetString 会基于它生成 Base64 文本。 */
	TArray<uint8> Value;

	virtual FString GetType() const override { return TEXT("Binary"); }
};
