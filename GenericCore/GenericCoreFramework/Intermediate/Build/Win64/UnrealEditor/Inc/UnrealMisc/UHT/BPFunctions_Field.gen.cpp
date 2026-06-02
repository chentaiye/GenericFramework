// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/BPFunctions_Field.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBPFunctions_Field() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_Field();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_Field_NoRegister();
UPackage* Z_Construct_UPackage__Script_UnrealMisc();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBPFunctions_Field Function GetBooleanValue ******************************
struct Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics
{
	struct BPFunctions_Field_eventGetBooleanValue_Parms
	{
		const UObject* Target;
		FName PropertyName;
		bool Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\xb8\x83\xe5\xb0\x94\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\xb8\x83\xe5\xb0\x94\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetBooleanValue constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static void NewProp_Value_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBooleanValue constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBooleanValue Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetBooleanValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetBooleanValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_Value_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetBooleanValue_Parms*)Obj)->Value = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetBooleanValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_Value_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetBooleanValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetBooleanValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::PropPointers) < 2048);
// ********** End Function GetBooleanValue Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "GetBooleanValue", 	Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::BPFunctions_Field_eventGetBooleanValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::BPFunctions_Field_eventGetBooleanValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execGetBooleanValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_UBOOL_REF(Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::GetBooleanValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function GetBooleanValue ********************************

// ********** Begin Class UBPFunctions_Field Function GetDoubleValue *******************************
struct Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics
{
	struct BPFunctions_Field_eventGetDoubleValue_Parms
	{
		const UObject* Target;
		FName PropertyName;
		double Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x8f\x8c\xe7\xb2\xbe\xe5\xba\xa6\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x8f\x8c\xe7\xb2\xbe\xe5\xba\xa6\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDoubleValue constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDoubleValue constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDoubleValue Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetDoubleValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetDoubleValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetDoubleValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetDoubleValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetDoubleValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::PropPointers) < 2048);
// ********** End Function GetDoubleValue Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "GetDoubleValue", 	Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::BPFunctions_Field_eventGetDoubleValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::BPFunctions_Field_eventGetDoubleValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execGetDoubleValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY_REF(FDoubleProperty,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::GetDoubleValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function GetDoubleValue *********************************

// ********** Begin Class UBPFunctions_Field Function GetFloatValue ********************************
struct Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics
{
	struct BPFunctions_Field_eventGetFloatValue_Parms
	{
		const UObject* Target;
		FName PropertyName;
		float Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\xb5\xae\xe7\x82\xb9\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\xb5\xae\xe7\x82\xb9\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetFloatValue constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFloatValue constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFloatValue Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetFloatValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetFloatValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetFloatValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetFloatValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetFloatValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::PropPointers) < 2048);
// ********** End Function GetFloatValue Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "GetFloatValue", 	Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::BPFunctions_Field_eventGetFloatValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::BPFunctions_Field_eventGetFloatValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execGetFloatValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY_REF(FFloatProperty,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::GetFloatValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function GetFloatValue **********************************

// ********** Begin Class UBPFunctions_Field Function GetInteger64Value ****************************
struct Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics
{
	struct BPFunctions_Field_eventGetInteger64Value_Parms
	{
		const UObject* Target;
		FName PropertyName;
		int64 Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96""64 \xe4\xbd\x8d\xe6\x95\xb4\xe6\x95\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96""64 \xe4\xbd\x8d\xe6\x95\xb4\xe6\x95\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetInteger64Value constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetInteger64Value constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetInteger64Value Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetInteger64Value_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetInteger64Value_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetInteger64Value_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetInteger64Value_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetInteger64Value_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::PropPointers) < 2048);
// ********** End Function GetInteger64Value Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "GetInteger64Value", 	Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::BPFunctions_Field_eventGetInteger64Value_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::BPFunctions_Field_eventGetInteger64Value_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execGetInteger64Value)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY_REF(FInt64Property,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::GetInteger64Value(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function GetInteger64Value ******************************

// ********** Begin Class UBPFunctions_Field Function GetIntegerValue ******************************
struct Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics
{
	struct BPFunctions_Field_eventGetIntegerValue_Parms
	{
		const UObject* Target;
		FName PropertyName;
		int32 Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x95\xb4\xe6\x95\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x95\xb4\xe6\x95\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetIntegerValue constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetIntegerValue constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetIntegerValue Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetIntegerValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetIntegerValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetIntegerValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetIntegerValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetIntegerValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::PropPointers) < 2048);
// ********** End Function GetIntegerValue Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "GetIntegerValue", 	Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::BPFunctions_Field_eventGetIntegerValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::BPFunctions_Field_eventGetIntegerValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execGetIntegerValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::GetIntegerValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function GetIntegerValue ********************************

// ********** Begin Class UBPFunctions_Field Function GetNameValue *********************************
struct Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics
{
	struct BPFunctions_Field_eventGetNameValue_Parms
	{
		const UObject* Target;
		FName PropertyName;
		FName Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x90\x8d\xe7\xa7\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x90\x8d\xe7\xa7\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetNameValue constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNameValue constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNameValue Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetNameValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetNameValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetNameValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetNameValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetNameValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::PropPointers) < 2048);
// ********** End Function GetNameValue Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "GetNameValue", 	Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::BPFunctions_Field_eventGetNameValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::BPFunctions_Field_eventGetNameValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_GetNameValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_GetNameValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execGetNameValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::GetNameValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function GetNameValue ***********************************

// ********** Begin Class UBPFunctions_Field Function GetRotatorValue ******************************
struct Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics
{
	struct BPFunctions_Field_eventGetRotatorValue_Parms
	{
		const UObject* Target;
		FName PropertyName;
		FRotator Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x97\x8b\xe8\xbd\xac\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x97\x8b\xe8\xbd\xac\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetRotatorValue constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetRotatorValue constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetRotatorValue Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetRotatorValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetRotatorValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetRotatorValue_Parms, Value), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetRotatorValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetRotatorValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::PropPointers) < 2048);
// ********** End Function GetRotatorValue Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "GetRotatorValue", 	Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::BPFunctions_Field_eventGetRotatorValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::BPFunctions_Field_eventGetRotatorValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execGetRotatorValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_STRUCT_REF(FRotator,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::GetRotatorValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function GetRotatorValue ********************************

// ********** Begin Class UBPFunctions_Field Function GetStringValue *******************************
struct Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics
{
	struct BPFunctions_Field_eventGetStringValue_Parms
	{
		const UObject* Target;
		FName PropertyName;
		FString Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetStringValue constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetStringValue constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetStringValue Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetStringValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetStringValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetStringValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetStringValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetStringValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::PropPointers) < 2048);
// ********** End Function GetStringValue Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "GetStringValue", 	Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::BPFunctions_Field_eventGetStringValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::BPFunctions_Field_eventGetStringValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_GetStringValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_GetStringValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execGetStringValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::GetStringValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function GetStringValue *********************************

// ********** Begin Class UBPFunctions_Field Function GetTextValue *********************************
struct Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics
{
	struct BPFunctions_Field_eventGetTextValue_Parms
	{
		const UObject* Target;
		FName PropertyName;
		FText Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextValue constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextValue constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextValue Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetTextValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetTextValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetTextValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetTextValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetTextValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::PropPointers) < 2048);
// ********** End Function GetTextValue Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "GetTextValue", 	Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::BPFunctions_Field_eventGetTextValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::BPFunctions_Field_eventGetTextValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_GetTextValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_GetTextValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execGetTextValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::GetTextValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function GetTextValue ***********************************

// ********** Begin Class UBPFunctions_Field Function GetVectorValue *******************************
struct Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics
{
	struct BPFunctions_Field_eventGetVectorValue_Parms
	{
		const UObject* Target;
		FName PropertyName;
		FVector Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x90\x91\xe9\x87\x8f\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x90\x91\xe9\x87\x8f\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetVectorValue constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVectorValue constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVectorValue Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetVectorValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Target_MetaData), NewProp_Target_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetVectorValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventGetVectorValue_Parms, Value), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventGetVectorValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventGetVectorValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::PropPointers) < 2048);
// ********** End Function GetVectorValue Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "GetVectorValue", 	Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::BPFunctions_Field_eventGetVectorValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::BPFunctions_Field_eventGetVectorValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execGetVectorValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_STRUCT_REF(FVector,Z_Param_Out_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::GetVectorValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Out_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function GetVectorValue *********************************

// ********** Begin Class UBPFunctions_Field Function SetBooleanValue ******************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics
{
	struct BPFunctions_Field_eventSetBooleanValue_Parms
	{
		UObject* Target;
		FName PropertyName;
		bool Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\xb8\x83\xe5\xb0\x94\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\xb8\x83\xe5\xb0\x94\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBooleanValue constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static void NewProp_Value_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBooleanValue constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBooleanValue Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetBooleanValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetBooleanValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_Value_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetBooleanValue_Parms*)Obj)->Value = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetBooleanValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_Value_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetBooleanValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetBooleanValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::PropPointers) < 2048);
// ********** End Function SetBooleanValue Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetBooleanValue", 	Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::BPFunctions_Field_eventSetBooleanValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::BPFunctions_Field_eventSetBooleanValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execSetBooleanValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_UBOOL(Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::SetBooleanValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function SetBooleanValue ********************************

// ********** Begin Class UBPFunctions_Field Function SetDoubleValue *******************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics
{
	struct BPFunctions_Field_eventSetDoubleValue_Parms
	{
		UObject* Target;
		FName PropertyName;
		double Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x8f\x8c\xe7\xb2\xbe\xe5\xba\xa6\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x8f\x8c\xe7\xb2\xbe\xe5\xba\xa6\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDoubleValue constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FDoublePropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDoubleValue constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDoubleValue Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetDoubleValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetDoubleValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetDoubleValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetDoubleValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetDoubleValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::PropPointers) < 2048);
// ********** End Function SetDoubleValue Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetDoubleValue", 	Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::BPFunctions_Field_eventSetDoubleValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::BPFunctions_Field_eventSetDoubleValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execSetDoubleValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY(FDoubleProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::SetDoubleValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function SetDoubleValue *********************************

// ********** Begin Class UBPFunctions_Field Function SetFloatValue ********************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics
{
	struct BPFunctions_Field_eventSetFloatValue_Parms
	{
		UObject* Target;
		FName PropertyName;
		float Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\xb5\xae\xe7\x82\xb9\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\xb5\xae\xe7\x82\xb9\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetFloatValue constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFloatValue constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFloatValue Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetFloatValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetFloatValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetFloatValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetFloatValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetFloatValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::PropPointers) < 2048);
// ********** End Function SetFloatValue Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetFloatValue", 	Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::BPFunctions_Field_eventSetFloatValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::BPFunctions_Field_eventSetFloatValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execSetFloatValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY(FFloatProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::SetFloatValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function SetFloatValue **********************************

// ********** Begin Class UBPFunctions_Field Function SetInteger64Value ****************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics
{
	struct BPFunctions_Field_eventSetInteger64Value_Parms
	{
		UObject* Target;
		FName PropertyName;
		int64 Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5""64 \xe4\xbd\x8d\xe6\x95\xb4\xe6\x95\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5""64 \xe4\xbd\x8d\xe6\x95\xb4\xe6\x95\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetInteger64Value constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetInteger64Value constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetInteger64Value Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetInteger64Value_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetInteger64Value_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetInteger64Value_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetInteger64Value_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetInteger64Value_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::PropPointers) < 2048);
// ********** End Function SetInteger64Value Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetInteger64Value", 	Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::BPFunctions_Field_eventSetInteger64Value_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::BPFunctions_Field_eventSetInteger64Value_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execSetInteger64Value)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY(FInt64Property,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::SetInteger64Value(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function SetInteger64Value ******************************

// ********** Begin Class UBPFunctions_Field Function SetIntegerValue ******************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics
{
	struct BPFunctions_Field_eventSetIntegerValue_Parms
	{
		UObject* Target;
		FName PropertyName;
		int32 Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x95\xb4\xe6\x95\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x95\xb4\xe6\x95\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetIntegerValue constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetIntegerValue constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetIntegerValue Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetIntegerValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetIntegerValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetIntegerValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetIntegerValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetIntegerValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::PropPointers) < 2048);
// ********** End Function SetIntegerValue Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetIntegerValue", 	Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::BPFunctions_Field_eventSetIntegerValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::BPFunctions_Field_eventSetIntegerValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execSetIntegerValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY(FIntProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::SetIntegerValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function SetIntegerValue ********************************

// ********** Begin Class UBPFunctions_Field Function SetNameValue *********************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics
{
	struct BPFunctions_Field_eventSetNameValue_Parms
	{
		UObject* Target;
		FName PropertyName;
		FName Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x90\x8d\xe7\xa7\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x90\x8d\xe7\xa7\xb0\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetNameValue constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetNameValue constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetNameValue Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetNameValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetNameValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetNameValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetNameValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetNameValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::PropPointers) < 2048);
// ********** End Function SetNameValue Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetNameValue", 	Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::BPFunctions_Field_eventSetNameValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::BPFunctions_Field_eventSetNameValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetNameValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetNameValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execSetNameValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY(FNameProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::SetNameValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function SetNameValue ***********************************

// ********** Begin Class UBPFunctions_Field Function SetPropertyValue *****************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics
{
	struct BPFunctions_Field_eventSetPropertyValue_Parms
	{
		const UObject* TargetObject;
		FName PropertyName;
		int32 Value;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "CustomStructureParam", "Value" },
		{ "CustomThunk", "true" },
		{ "DefaultToSelf", "TargetObject" },
		{ "DisplayName", "Set Property Value" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Value_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPropertyValue constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetObject;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Value;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPropertyValue constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPropertyValue Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::NewProp_TargetObject = { "TargetObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetPropertyValue_Parms, TargetObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetObject_MetaData), NewProp_TargetObject_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetPropertyValue_Parms, PropertyName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetPropertyValue_Parms, Value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Value_MetaData), NewProp_Value_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::NewProp_TargetObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::NewProp_Value,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::PropPointers) < 2048);
// ********** End Function SetPropertyValue Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetPropertyValue", 	Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::BPFunctions_Field_eventSetPropertyValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::BPFunctions_Field_eventSetPropertyValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UBPFunctions_Field Function SetPropertyValue *******************************

// ********** Begin Class UBPFunctions_Field Function SetRotatorValue ******************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics
{
	struct BPFunctions_Field_eventSetRotatorValue_Parms
	{
		UObject* Target;
		FName PropertyName;
		FRotator Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x97\x8b\xe8\xbd\xac\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x97\x8b\xe8\xbd\xac\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetRotatorValue constinit property declarations ***********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetRotatorValue constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetRotatorValue Property Definitions **********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetRotatorValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetRotatorValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetRotatorValue_Parms, Value), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetRotatorValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetRotatorValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::PropPointers) < 2048);
// ********** End Function SetRotatorValue Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetRotatorValue", 	Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::BPFunctions_Field_eventSetRotatorValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::BPFunctions_Field_eventSetRotatorValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execSetRotatorValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_STRUCT(FRotator,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::SetRotatorValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function SetRotatorValue ********************************

// ********** Begin Class UBPFunctions_Field Function SetStringValue *******************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics
{
	struct BPFunctions_Field_eventSetStringValue_Parms
	{
		UObject* Target;
		FName PropertyName;
		FString Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetStringValue constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStringValue constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStringValue Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetStringValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetStringValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetStringValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetStringValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetStringValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::PropPointers) < 2048);
// ********** End Function SetStringValue Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetStringValue", 	Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::BPFunctions_Field_eventSetStringValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::BPFunctions_Field_eventSetStringValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetStringValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetStringValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execSetStringValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY(FStrProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::SetStringValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function SetStringValue *********************************

// ********** Begin Class UBPFunctions_Field Function SetTextValue *********************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics
{
	struct BPFunctions_Field_eventSetTextValue_Parms
	{
		UObject* Target;
		FName PropertyName;
		FText Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextValue constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextValue constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextValue Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetTextValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetTextValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetTextValue_Parms, Value), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetTextValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetTextValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::PropPointers) < 2048);
// ********** End Function SetTextValue Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetTextValue", 	Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::BPFunctions_Field_eventSetTextValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::BPFunctions_Field_eventSetTextValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetTextValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetTextValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execSetTextValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_PROPERTY(FTextProperty,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::SetTextValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function SetTextValue ***********************************

// ********** Begin Class UBPFunctions_Field Function SetVectorValue *******************************
struct Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics
{
	struct BPFunctions_Field_eventSetVectorValue_Parms
	{
		UObject* Target;
		FName PropertyName;
		FVector Value;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Field" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x90\x91\xe9\x87\x8f\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x90\x91\xe9\x87\x8f\xe5\xb1\x9e\xe6\x80\xa7\xe5\x80\xbc\xef\xbc\x8c\xe9\x80\x9a\xe8\xbf\x87\xe5\x8f\x8d\xe5\xb0\x84\xe4\xbf\x9d\xe6\x8c\x81 UObject \xe5\xb1\x9e\xe6\x80\xa7\xe5\xad\x98\xe5\x82\xa8\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PropertyName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetVectorValue constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
	static const UECodeGen_Private::FNamePropertyParams NewProp_PropertyName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Value;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVectorValue constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVectorValue Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetVectorValue_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::NewProp_PropertyName = { "PropertyName", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetVectorValue_Parms, PropertyName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PropertyName_MetaData), NewProp_PropertyName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::NewProp_Value = { "Value", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Field_eventSetVectorValue_Parms, Value), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Field_eventSetVectorValue_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Field_eventSetVectorValue_Parms), &Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::NewProp_PropertyName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::NewProp_Value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::PropPointers) < 2048);
// ********** End Function SetVectorValue Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Field, nullptr, "SetVectorValue", 	Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::BPFunctions_Field_eventSetVectorValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C22403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::BPFunctions_Field_eventSetVectorValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Field::execSetVectorValue)
{
	P_GET_OBJECT(UObject,Z_Param_Target);
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_PropertyName);
	P_GET_STRUCT(FVector,Z_Param_Value);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Field::SetVectorValue(Z_Param_Target,Z_Param_Out_PropertyName,Z_Param_Value);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Field Function SetVectorValue *********************************

// ********** Begin Class UBPFunctions_Field *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBPFunctions_Field;
UClass* UBPFunctions_Field::GetPrivateStaticClass()
{
	using TClass = UBPFunctions_Field;
	if (!Z_Registration_Info_UClass_UBPFunctions_Field.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BPFunctions_Field"),
			Z_Registration_Info_UClass_UBPFunctions_Field.InnerSingleton,
			StaticRegisterNativesUBPFunctions_Field,
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
	return Z_Registration_Info_UClass_UBPFunctions_Field.InnerSingleton;
}
UClass* Z_Construct_UClass_UBPFunctions_Field_NoRegister()
{
	return UBPFunctions_Field::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBPFunctions_Field_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2\xe5\xad\x97\xe6\xae\xb5\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "BPFunctions/BPFunctions_Field.h" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Field.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2\xe5\xad\x97\xe6\xae\xb5\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBPFunctions_Field constinit property declarations ***********************
// ********** End Class UBPFunctions_Field constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetBooleanValue"), .Pointer = &UBPFunctions_Field::execGetBooleanValue },
		{ .NameUTF8 = UTF8TEXT("GetDoubleValue"), .Pointer = &UBPFunctions_Field::execGetDoubleValue },
		{ .NameUTF8 = UTF8TEXT("GetFloatValue"), .Pointer = &UBPFunctions_Field::execGetFloatValue },
		{ .NameUTF8 = UTF8TEXT("GetInteger64Value"), .Pointer = &UBPFunctions_Field::execGetInteger64Value },
		{ .NameUTF8 = UTF8TEXT("GetIntegerValue"), .Pointer = &UBPFunctions_Field::execGetIntegerValue },
		{ .NameUTF8 = UTF8TEXT("GetNameValue"), .Pointer = &UBPFunctions_Field::execGetNameValue },
		{ .NameUTF8 = UTF8TEXT("GetRotatorValue"), .Pointer = &UBPFunctions_Field::execGetRotatorValue },
		{ .NameUTF8 = UTF8TEXT("GetStringValue"), .Pointer = &UBPFunctions_Field::execGetStringValue },
		{ .NameUTF8 = UTF8TEXT("GetTextValue"), .Pointer = &UBPFunctions_Field::execGetTextValue },
		{ .NameUTF8 = UTF8TEXT("GetVectorValue"), .Pointer = &UBPFunctions_Field::execGetVectorValue },
		{ .NameUTF8 = UTF8TEXT("SetBooleanValue"), .Pointer = &UBPFunctions_Field::execSetBooleanValue },
		{ .NameUTF8 = UTF8TEXT("SetDoubleValue"), .Pointer = &UBPFunctions_Field::execSetDoubleValue },
		{ .NameUTF8 = UTF8TEXT("SetFloatValue"), .Pointer = &UBPFunctions_Field::execSetFloatValue },
		{ .NameUTF8 = UTF8TEXT("SetInteger64Value"), .Pointer = &UBPFunctions_Field::execSetInteger64Value },
		{ .NameUTF8 = UTF8TEXT("SetIntegerValue"), .Pointer = &UBPFunctions_Field::execSetIntegerValue },
		{ .NameUTF8 = UTF8TEXT("SetNameValue"), .Pointer = &UBPFunctions_Field::execSetNameValue },
		{ .NameUTF8 = UTF8TEXT("SetPropertyValue"), .Pointer = &UBPFunctions_Field::execSetPropertyValue },
		{ .NameUTF8 = UTF8TEXT("SetRotatorValue"), .Pointer = &UBPFunctions_Field::execSetRotatorValue },
		{ .NameUTF8 = UTF8TEXT("SetStringValue"), .Pointer = &UBPFunctions_Field::execSetStringValue },
		{ .NameUTF8 = UTF8TEXT("SetTextValue"), .Pointer = &UBPFunctions_Field::execSetTextValue },
		{ .NameUTF8 = UTF8TEXT("SetVectorValue"), .Pointer = &UBPFunctions_Field::execSetVectorValue },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBPFunctions_Field_GetBooleanValue, "GetBooleanValue" }, // 2026826736
		{ &Z_Construct_UFunction_UBPFunctions_Field_GetDoubleValue, "GetDoubleValue" }, // 2932426897
		{ &Z_Construct_UFunction_UBPFunctions_Field_GetFloatValue, "GetFloatValue" }, // 3143558193
		{ &Z_Construct_UFunction_UBPFunctions_Field_GetInteger64Value, "GetInteger64Value" }, // 1611292053
		{ &Z_Construct_UFunction_UBPFunctions_Field_GetIntegerValue, "GetIntegerValue" }, // 2822852722
		{ &Z_Construct_UFunction_UBPFunctions_Field_GetNameValue, "GetNameValue" }, // 1429533381
		{ &Z_Construct_UFunction_UBPFunctions_Field_GetRotatorValue, "GetRotatorValue" }, // 3226285698
		{ &Z_Construct_UFunction_UBPFunctions_Field_GetStringValue, "GetStringValue" }, // 1241117095
		{ &Z_Construct_UFunction_UBPFunctions_Field_GetTextValue, "GetTextValue" }, // 2871749475
		{ &Z_Construct_UFunction_UBPFunctions_Field_GetVectorValue, "GetVectorValue" }, // 2745712589
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetBooleanValue, "SetBooleanValue" }, // 3063563770
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetDoubleValue, "SetDoubleValue" }, // 1054371800
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetFloatValue, "SetFloatValue" }, // 794345808
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetInteger64Value, "SetInteger64Value" }, // 3544761295
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetIntegerValue, "SetIntegerValue" }, // 1677004351
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetNameValue, "SetNameValue" }, // 1001073883
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetPropertyValue, "SetPropertyValue" }, // 2209114256
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetRotatorValue, "SetRotatorValue" }, // 3266940818
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetStringValue, "SetStringValue" }, // 2619300040
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetTextValue, "SetTextValue" }, // 1814200292
		{ &Z_Construct_UFunction_UBPFunctions_Field_SetVectorValue, "SetVectorValue" }, // 3649741107
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctions_Field>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBPFunctions_Field_Statics
UObject* (*const Z_Construct_UClass_UBPFunctions_Field_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_UnrealMisc,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Field_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctions_Field_Statics::ClassParams = {
	&UBPFunctions_Field::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Field_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPFunctions_Field_Statics::Class_MetaDataParams)
};
void UBPFunctions_Field::StaticRegisterNativesUBPFunctions_Field()
{
	UClass* Class = UBPFunctions_Field::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UBPFunctions_Field_Statics::Funcs));
}
UClass* Z_Construct_UClass_UBPFunctions_Field()
{
	if (!Z_Registration_Info_UClass_UBPFunctions_Field.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPFunctions_Field.OuterSingleton, Z_Construct_UClass_UBPFunctions_Field_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPFunctions_Field.OuterSingleton;
}
UBPFunctions_Field::UBPFunctions_Field(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBPFunctions_Field);
UBPFunctions_Field::~UBPFunctions_Field() {}
// ********** End Class UBPFunctions_Field *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Field_h__Script_UnrealMisc_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPFunctions_Field, UBPFunctions_Field::StaticClass, TEXT("UBPFunctions_Field"), &Z_Registration_Info_UClass_UBPFunctions_Field, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPFunctions_Field), 1410439147U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Field_h__Script_UnrealMisc_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Field_h__Script_UnrealMisc_3956674592{
	TEXT("/Script/UnrealMisc"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Field_h__Script_UnrealMisc_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Field_h__Script_UnrealMisc_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
