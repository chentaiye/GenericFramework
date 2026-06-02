// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/** 定义StaticFunctions转换类型，作为 Unreal 通用工具 模块内复用的稳定入口。 */
class UNREALMISC_API FStaticFunctions_Convert
{
	/* To Bool */
public:
	/** 转换Bool，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static bool ToBool(unsigned int Var);

	/** 转换Bool，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static bool ToBool(FString Var);

	/* To Int32 */
public:
	/** 转换Int32，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int32 ToInt32(bool Var);

	/** 转换Int32，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int32 ToInt32(uint8 Var);

	/** 转换Int32，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int32 ToInt32(uint32 Var);

	/** 转换Int32，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int32 ToInt32(int64 Var);

	/** 转换Int32，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int32 ToInt32(float Var);

	/** 转换Int32，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int32 ToInt32(double Var);

	/** 转换Int32，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int32 ToInt32(FString Var);

	/** 转换Int32，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int32 ToInt32(FName Var);

	/** 转换Int32，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int32 ToInt32(FText Var);

	template <typename T>
	static FORCEINLINE int32 RoundToInt32(T Var) { return FMath::RoundToInt(Var); }

	template <typename T>
	static FORCEINLINE int32 CeilToInt32(T Var) { return FMath::CeilToInt(Var); }

	template <typename T>
	static FORCEINLINE int32 FloorToInt32(T Var) { return FMath::FloorToInt(Var); }

	/* To Int64 */
public:
	/** 转换Int64，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int64 ToInt64(bool Var);

	/** 转换Int64，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int64 ToInt64(uint8 Var);

	/** 转换Int64，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int64 ToInt64(uint32 Var);

	/** 转换Int64，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int64 ToInt64(int32 Var);

	/** 转换Int64，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int64 ToInt64(float Var);

	/** 转换Int64，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int64 ToInt64(double Var);

	/** 转换Int64，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int64 ToInt64(FString Var);

	/** 转换Int64，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int64 ToInt64(FName Var);

	/** 转换Int64，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static int64 ToInt64(FText Var);

	template <typename T>
	static FORCEINLINE int64 RoundToInt64(T Var) { return FMath::RoundToInt64(Var); }

	template <typename T>
	static FORCEINLINE int64 CeilToInt64(T Var) { return FMath::CeilToInt(Var); }

	template <typename T>
	static FORCEINLINE int64 FloorToInt64(T Var) { return FMath::FloorToInt(Var); }

	/* To Float */
public:
	/** 转换浮点，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static float ToFloat(bool Var);

	/** 转换浮点，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static float ToFloat(int32 Var);

	/** 转换浮点，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static float ToFloat(int64 Var);

	/** 转换浮点，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static float ToFloat(FString Var);

	/** 转换浮点，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static float ToFloat(FName Var);

	/** 转换浮点，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static float ToFloat(FText Var);

	/* To Double */
public:
	/** 转换双精度，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static double ToDouble(bool Var);

	/** 转换双精度，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static double ToDouble(int32 Var);

	/** 转换双精度，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static double ToDouble(int64 Var);

	/** 转换双精度，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static double ToDouble(FString Var);

	/** 转换双精度，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static double ToDouble(FName Var);

	/** 转换双精度，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static double ToDouble(FText Var);

	/* To String */
public:
	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(FString Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(char* Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(unsigned char* Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(bool Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(uint32 Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(int32 Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(int64 Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(float Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(double Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(FName Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(FText Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(FVector Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(FVector2D Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(FRotator Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(FTransform Var);

	/** 转换字符串，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static FString ToString(TArray<uint8> Var);

	/* To Byte Array */
public:
	/** 转换ByteArray，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
	static TArray<uint8> ToByteArray(const FString& InStr);
};
