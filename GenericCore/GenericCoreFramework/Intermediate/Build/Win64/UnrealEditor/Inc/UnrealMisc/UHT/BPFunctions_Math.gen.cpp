// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/BPFunctions_Math.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBPFunctions_Math() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_Math();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_Math_NoRegister();
UPackage* Z_Construct_UPackage__Script_UnrealMisc();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBPFunctions_Math Function Rotator_Safe **********************************
struct Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics
{
	struct BPFunctions_Math_eventRotator_Safe_Parms
	{
		FRotator R;
		FRotator ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Math|Rotator" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xa7\x84\xe8\x8c\x83\xe5\x8c\x96\xe6\x97\x8b\xe8\xbd\xac\xe5\x80\xbc\xef\xbc\x8c\xe9\x81\xbf\xe5\x85\x8d\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe5\x9c\xa8\xe8\xa7\x92\xe5\xba\xa6\xe6\x8d\xa2\xe7\xae\x97\xe4\xb8\xad\xe6\x94\xb6\xe5\x88\xb0\xe5\xbc\x82\xe5\xb8\xb8\xe5\xa7\xbf\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "Safe" },
		{ "DisplayName", "Get Safe Rotator" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Math.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xa7\x84\xe8\x8c\x83\xe5\x8c\x96\xe6\x97\x8b\xe8\xbd\xac\xe5\x80\xbc\xef\xbc\x8c\xe9\x81\xbf\xe5\x85\x8d\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe5\x9c\xa8\xe8\xa7\x92\xe5\xba\xa6\xe6\x8d\xa2\xe7\xae\x97\xe4\xb8\xad\xe6\x94\xb6\xe5\x88\xb0\xe5\xbc\x82\xe5\xb8\xb8\xe5\xa7\xbf\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Rotator_Safe constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_R;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Rotator_Safe constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Rotator_Safe Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::NewProp_R = { "R", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventRotator_Safe_Parms, R), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventRotator_Safe_Parms, ReturnValue), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::NewProp_R,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::PropPointers) < 2048);
// ********** End Function Rotator_Safe Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Math, nullptr, "Rotator_Safe", 	Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::BPFunctions_Math_eventRotator_Safe_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::BPFunctions_Math_eventRotator_Safe_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Math::execRotator_Safe)
{
	P_GET_STRUCT(FRotator,Z_Param_R);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FRotator*)Z_Param__Result=UBPFunctions_Math::Rotator_Safe(Z_Param_R);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Math Function Rotator_Safe ************************************

// ********** Begin Class UBPFunctions_Math Function Vector_MiddleDegrees **************************
struct Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics
{
	struct BPFunctions_Math_eventVector_MiddleDegrees_Parms
	{
		FVector V1;
		FVector V2;
		float Alpha;
		float Degrees;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Math|Vector" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xa1\xe7\xae\x97\xe4\xb8\xa4\xe4\xb8\xaa\xe6\x96\xb9\xe5\x90\x91\xe5\x90\x91\xe9\x87\x8f\xe7\x9a\x84\xe8\xa7\x92\xe5\xba\xa6\xe4\xb8\xad\xe5\x80\xbc\xef\xbc\x8c\xe8\xbf\x94\xe5\x9b\x9e\xe4\xbb\xa5\xe8\xa7\x92\xe5\xba\xa6\xe8\xa1\xa8\xe7\xa4\xba\xe7\x9a\x84\xe7\xbb\x93\xe6\x9e\x9c\xe4\xbe\x9b\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xa0\xe4\xbd\x95\xe9\x80\xbb\xe8\xbe\x91\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_Alpha", "0.500000" },
		{ "CPP_Default_Degrees", "0.000000" },
		{ "DisplayName", "Middle (Vector)(Degrees)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Math.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xa1\xe7\xae\x97\xe4\xb8\xa4\xe4\xb8\xaa\xe6\x96\xb9\xe5\x90\x91\xe5\x90\x91\xe9\x87\x8f\xe7\x9a\x84\xe8\xa7\x92\xe5\xba\xa6\xe4\xb8\xad\xe5\x80\xbc\xef\xbc\x8c\xe8\xbf\x94\xe5\x9b\x9e\xe4\xbb\xa5\xe8\xa7\x92\xe5\xba\xa6\xe8\xa1\xa8\xe7\xa4\xba\xe7\x9a\x84\xe7\xbb\x93\xe6\x9e\x9c\xe4\xbe\x9b\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xa0\xe4\xbd\x95\xe9\x80\xbb\xe8\xbe\x91\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_V1_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_V2_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Vector_MiddleDegrees constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_V1;
	static const UECodeGen_Private::FStructPropertyParams NewProp_V2;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Alpha;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Degrees;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Vector_MiddleDegrees constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Vector_MiddleDegrees Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::NewProp_V1 = { "V1", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventVector_MiddleDegrees_Parms, V1), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_V1_MetaData), NewProp_V1_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::NewProp_V2 = { "V2", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventVector_MiddleDegrees_Parms, V2), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_V2_MetaData), NewProp_V2_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::NewProp_Alpha = { "Alpha", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventVector_MiddleDegrees_Parms, Alpha), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::NewProp_Degrees = { "Degrees", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventVector_MiddleDegrees_Parms, Degrees), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventVector_MiddleDegrees_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::NewProp_V1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::NewProp_V2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::NewProp_Alpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::NewProp_Degrees,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::PropPointers) < 2048);
// ********** End Function Vector_MiddleDegrees Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Math, nullptr, "Vector_MiddleDegrees", 	Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::BPFunctions_Math_eventVector_MiddleDegrees_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::BPFunctions_Math_eventVector_MiddleDegrees_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Math::execVector_MiddleDegrees)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_V1);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_V2);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Alpha);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Degrees);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UBPFunctions_Math::Vector_MiddleDegrees(Z_Param_Out_V1,Z_Param_Out_V2,Z_Param_Alpha,Z_Param_Degrees);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Math Function Vector_MiddleDegrees ****************************

// ********** Begin Class UBPFunctions_Math Function Vector_MiddleRadians **************************
struct Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics
{
	struct BPFunctions_Math_eventVector_MiddleRadians_Parms
	{
		FVector V1;
		FVector V2;
		float Alpha;
		float Radians;
		FVector ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Math|Vector" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xa1\xe7\xae\x97\xe4\xb8\xa4\xe4\xb8\xaa\xe6\x96\xb9\xe5\x90\x91\xe5\x90\x91\xe9\x87\x8f\xe7\x9a\x84\xe5\xbc\xa7\xe5\xba\xa6\xe4\xb8\xad\xe5\x80\xbc\xef\xbc\x8c\xe8\xbf\x94\xe5\x9b\x9e\xe4\xbb\xa5\xe5\xbc\xa7\xe5\xba\xa6\xe8\xa1\xa8\xe7\xa4\xba\xe7\x9a\x84\xe7\xbb\x93\xe6\x9e\x9c\xe4\xbe\x9b\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xa0\xe4\xbd\x95\xe9\x80\xbb\xe8\xbe\x91\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_Alpha", "0.500000" },
		{ "CPP_Default_Radians", "0.000000" },
		{ "DisplayName", "Middle (Vector)(Radians)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Math.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xa1\xe7\xae\x97\xe4\xb8\xa4\xe4\xb8\xaa\xe6\x96\xb9\xe5\x90\x91\xe5\x90\x91\xe9\x87\x8f\xe7\x9a\x84\xe5\xbc\xa7\xe5\xba\xa6\xe4\xb8\xad\xe5\x80\xbc\xef\xbc\x8c\xe8\xbf\x94\xe5\x9b\x9e\xe4\xbb\xa5\xe5\xbc\xa7\xe5\xba\xa6\xe8\xa1\xa8\xe7\xa4\xba\xe7\x9a\x84\xe7\xbb\x93\xe6\x9e\x9c\xe4\xbe\x9b\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xa0\xe4\xbd\x95\xe9\x80\xbb\xe8\xbe\x91\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_V1_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_V2_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Vector_MiddleRadians constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_V1;
	static const UECodeGen_Private::FStructPropertyParams NewProp_V2;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Alpha;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Radians;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Vector_MiddleRadians constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Vector_MiddleRadians Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::NewProp_V1 = { "V1", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventVector_MiddleRadians_Parms, V1), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_V1_MetaData), NewProp_V1_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::NewProp_V2 = { "V2", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventVector_MiddleRadians_Parms, V2), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_V2_MetaData), NewProp_V2_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::NewProp_Alpha = { "Alpha", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventVector_MiddleRadians_Parms, Alpha), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::NewProp_Radians = { "Radians", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventVector_MiddleRadians_Parms, Radians), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Math_eventVector_MiddleRadians_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::NewProp_V1,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::NewProp_V2,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::NewProp_Alpha,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::NewProp_Radians,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::PropPointers) < 2048);
// ********** End Function Vector_MiddleRadians Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Math, nullptr, "Vector_MiddleRadians", 	Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::BPFunctions_Math_eventVector_MiddleRadians_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::BPFunctions_Math_eventVector_MiddleRadians_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Math::execVector_MiddleRadians)
{
	P_GET_STRUCT_REF(FVector,Z_Param_Out_V1);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_V2);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Alpha);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Radians);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector*)Z_Param__Result=UBPFunctions_Math::Vector_MiddleRadians(Z_Param_Out_V1,Z_Param_Out_V2,Z_Param_Alpha,Z_Param_Radians);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Math Function Vector_MiddleRadians ****************************

// ********** Begin Class UBPFunctions_Math ********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBPFunctions_Math;
UClass* UBPFunctions_Math::GetPrivateStaticClass()
{
	using TClass = UBPFunctions_Math;
	if (!Z_Registration_Info_UClass_UBPFunctions_Math.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BPFunctions_Math"),
			Z_Registration_Info_UClass_UBPFunctions_Math.InnerSingleton,
			StaticRegisterNativesUBPFunctions_Math,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UBPFunctions_Math.InnerSingleton;
}
UClass* Z_Construct_UClass_UBPFunctions_Math_NoRegister()
{
	return UBPFunctions_Math::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBPFunctions_Math_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2Math\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "BPFunctions/BPFunctions_Math.h" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Math.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2Math\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBPFunctions_Math constinit property declarations ************************
// ********** End Class UBPFunctions_Math constinit property declarations **************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Rotator_Safe"), .Pointer = &UBPFunctions_Math::execRotator_Safe },
		{ .NameUTF8 = UTF8TEXT("Vector_MiddleDegrees"), .Pointer = &UBPFunctions_Math::execVector_MiddleDegrees },
		{ .NameUTF8 = UTF8TEXT("Vector_MiddleRadians"), .Pointer = &UBPFunctions_Math::execVector_MiddleRadians },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBPFunctions_Math_Rotator_Safe, "Rotator_Safe" }, // 3740491235
		{ &Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleDegrees, "Vector_MiddleDegrees" }, // 1564229457
		{ &Z_Construct_UFunction_UBPFunctions_Math_Vector_MiddleRadians, "Vector_MiddleRadians" }, // 2495646756
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctions_Math>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBPFunctions_Math_Statics
UObject* (*const Z_Construct_UClass_UBPFunctions_Math_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_UnrealMisc,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Math_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctions_Math_Statics::ClassParams = {
	&UBPFunctions_Math::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Math_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPFunctions_Math_Statics::Class_MetaDataParams)
};
void UBPFunctions_Math::StaticRegisterNativesUBPFunctions_Math()
{
	UClass* Class = UBPFunctions_Math::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UBPFunctions_Math_Statics::Funcs));
}
UClass* Z_Construct_UClass_UBPFunctions_Math()
{
	if (!Z_Registration_Info_UClass_UBPFunctions_Math.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPFunctions_Math.OuterSingleton, Z_Construct_UClass_UBPFunctions_Math_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPFunctions_Math.OuterSingleton;
}
UBPFunctions_Math::UBPFunctions_Math(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBPFunctions_Math);
UBPFunctions_Math::~UBPFunctions_Math() {}
// ********** End Class UBPFunctions_Math **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Math_h__Script_UnrealMisc_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPFunctions_Math, UBPFunctions_Math::StaticClass, TEXT("UBPFunctions_Math"), &Z_Registration_Info_UClass_UBPFunctions_Math, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPFunctions_Math), 3390338115U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Math_h__Script_UnrealMisc_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Math_h__Script_UnrealMisc_4192961692{
	TEXT("/Script/UnrealMisc"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Math_h__Script_UnrealMisc_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Math_h__Script_UnrealMisc_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
