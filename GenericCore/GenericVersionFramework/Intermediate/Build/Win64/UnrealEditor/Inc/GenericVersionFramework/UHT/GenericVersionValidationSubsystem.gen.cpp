// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystem/GenericVersionValidationSubsystem.h"
#include "Engine/GameInstance.h"
#include "Types/GenericVersionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericVersionValidationSubsystem() {}

// ********** Begin Cross Module References ********************************************************
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericGameInstanceSubsystem();
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionValidationSubsystem();
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionValidationSubsystem_NoRegister();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionContext();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionValidationResult();
UPackage* Z_Construct_UPackage__Script_GenericVersionFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericVersionValidationSubsystem Function MakeValidationFailed *********
struct Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics
{
	struct GenericVersionValidationSubsystem_eventMakeValidationFailed_Parms
	{
		FName ErrorCode;
		FText Message;
		FGenericVersionValidationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9e\x84\xe9\x80\xa0\xe6\xa0\xa1\xe9\xaa\x8c\xe5\xa4\xb1\xe8\xb4\xa5\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xa4\xb1\xe8\xb4\xa5\xe6\x98\xaf\xe5\x90\xa6\xe9\x98\xbb\xe6\x96\xad\xe7\x94\xb1\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe6\xa0\xb9\xe6\x8d\xae\xe8\xbf\x94\xe5\x9b\x9e\xe5\x80\xbc\xe5\x86\xb3\xe5\xae\x9a\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionValidationSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9e\x84\xe9\x80\xa0\xe6\xa0\xa1\xe9\xaa\x8c\xe5\xa4\xb1\xe8\xb4\xa5\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xa4\xb1\xe8\xb4\xa5\xe6\x98\xaf\xe5\x90\xa6\xe9\x98\xbb\xe6\x96\xad\xe7\x94\xb1\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe6\xa0\xb9\xe6\x8d\xae\xe8\xbf\x94\xe5\x9b\x9e\xe5\x80\xbc\xe5\x86\xb3\xe5\xae\x9a\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MakeValidationFailed constinit property declarations ******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ErrorCode;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MakeValidationFailed constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MakeValidationFailed Property Definitions *****************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionValidationSubsystem_eventMakeValidationFailed_Parms, ErrorCode), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionValidationSubsystem_eventMakeValidationFailed_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionValidationSubsystem_eventMakeValidationFailed_Parms, ReturnValue), Z_Construct_UScriptStruct_FGenericVersionValidationResult, METADATA_PARAMS(0, nullptr) }; // 2233177156
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::NewProp_ErrorCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::PropPointers) < 2048);
// ********** End Function MakeValidationFailed Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionValidationSubsystem, nullptr, "MakeValidationFailed", 	Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::GenericVersionValidationSubsystem_eventMakeValidationFailed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::GenericVersionValidationSubsystem_eventMakeValidationFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionValidationSubsystem::execMakeValidationFailed)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_ErrorCode);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGenericVersionValidationResult*)Z_Param__Result=P_THIS->MakeValidationFailed(Z_Param_ErrorCode,Z_Param_Out_Message);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionValidationSubsystem Function MakeValidationFailed ***********

// ********** Begin Class UGenericVersionValidationSubsystem Function MakeValidationSuccess ********
struct Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics
{
	struct GenericVersionValidationSubsystem_eventMakeValidationSuccess_Parms
	{
		FText Message;
		FGenericVersionValidationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9e\x84\xe9\x80\xa0\xe6\xa0\xa1\xe9\xaa\x8c\xe6\x88\x90\xe5\x8a\x9f\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe4\xbe\x9b\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\xa4\x8d\xe7\x94\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe7\xbb\x93\xe6\x9e\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionValidationSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9e\x84\xe9\x80\xa0\xe6\xa0\xa1\xe9\xaa\x8c\xe6\x88\x90\xe5\x8a\x9f\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe4\xbe\x9b\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\xa4\x8d\xe7\x94\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe7\xbb\x93\xe6\x9e\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MakeValidationSuccess constinit property declarations *****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MakeValidationSuccess constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MakeValidationSuccess Property Definitions ****************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionValidationSubsystem_eventMakeValidationSuccess_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionValidationSubsystem_eventMakeValidationSuccess_Parms, ReturnValue), Z_Construct_UScriptStruct_FGenericVersionValidationResult, METADATA_PARAMS(0, nullptr) }; // 2233177156
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::PropPointers) < 2048);
// ********** End Function MakeValidationSuccess Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionValidationSubsystem, nullptr, "MakeValidationSuccess", 	Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::GenericVersionValidationSubsystem_eventMakeValidationSuccess_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::GenericVersionValidationSubsystem_eventMakeValidationSuccess_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionValidationSubsystem::execMakeValidationSuccess)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGenericVersionValidationResult*)Z_Param__Result=P_THIS->MakeValidationSuccess(Z_Param_Out_Message);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionValidationSubsystem Function MakeValidationSuccess **********

// ********** Begin Class UGenericVersionValidationSubsystem Function MakeValidationWarning ********
struct Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics
{
	struct GenericVersionValidationSubsystem_eventMakeValidationWarning_Parms
	{
		FName ErrorCode;
		FText Message;
		FGenericVersionValidationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9e\x84\xe9\x80\xa0\xe6\xa0\xa1\xe9\xaa\x8c\xe8\xad\xa6\xe5\x91\x8a\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe8\xad\xa6\xe5\x91\x8a\xe4\xb8\x8d\xe9\x98\xbb\xe6\x96\xad\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionValidationSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9e\x84\xe9\x80\xa0\xe6\xa0\xa1\xe9\xaa\x8c\xe8\xad\xa6\xe5\x91\x8a\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe8\xad\xa6\xe5\x91\x8a\xe4\xb8\x8d\xe9\x98\xbb\xe6\x96\xad\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MakeValidationWarning constinit property declarations *****************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ErrorCode;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MakeValidationWarning constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MakeValidationWarning Property Definitions ****************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionValidationSubsystem_eventMakeValidationWarning_Parms, ErrorCode), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionValidationSubsystem_eventMakeValidationWarning_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionValidationSubsystem_eventMakeValidationWarning_Parms, ReturnValue), Z_Construct_UScriptStruct_FGenericVersionValidationResult, METADATA_PARAMS(0, nullptr) }; // 2233177156
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::NewProp_ErrorCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::PropPointers) < 2048);
// ********** End Function MakeValidationWarning Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionValidationSubsystem, nullptr, "MakeValidationWarning", 	Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::GenericVersionValidationSubsystem_eventMakeValidationWarning_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::GenericVersionValidationSubsystem_eventMakeValidationWarning_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionValidationSubsystem::execMakeValidationWarning)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_ErrorCode);
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_Message);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGenericVersionValidationResult*)Z_Param__Result=P_THIS->MakeValidationWarning(Z_Param_ErrorCode,Z_Param_Out_Message);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionValidationSubsystem Function MakeValidationWarning **********

// ********** Begin Class UGenericVersionValidationSubsystem Function ValidateVersionContext *******
struct Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics
{
	struct GenericVersionValidationSubsystem_eventValidateVersionContext_Parms
	{
		FGenericVersionContext Context;
		FGenericVersionValidationResult ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xaf\x94\xe8\xbe\x83\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe5\x92\x8c\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe4\xb8\x8d\xe8\xb0\x83\xe7\x94\xa8\xe4\xb8\x9a\xe5\x8a\xa1\xe6\x8e\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionValidationSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xaf\x94\xe8\xbe\x83\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe5\x92\x8c\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe4\xb8\x8d\xe8\xb0\x83\xe7\x94\xa8\xe4\xb8\x9a\xe5\x8a\xa1\xe6\x8e\xa5\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Context_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ValidateVersionContext constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Context;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ValidateVersionContext constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ValidateVersionContext Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::NewProp_Context = { "Context", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionValidationSubsystem_eventValidateVersionContext_Parms, Context), Z_Construct_UScriptStruct_FGenericVersionContext, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Context_MetaData), NewProp_Context_MetaData) }; // 2979299899
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionValidationSubsystem_eventValidateVersionContext_Parms, ReturnValue), Z_Construct_UScriptStruct_FGenericVersionValidationResult, METADATA_PARAMS(0, nullptr) }; // 2233177156
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::NewProp_Context,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::PropPointers) < 2048);
// ********** End Function ValidateVersionContext Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionValidationSubsystem, nullptr, "ValidateVersionContext", 	Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::GenericVersionValidationSubsystem_eventValidateVersionContext_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::GenericVersionValidationSubsystem_eventValidateVersionContext_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionValidationSubsystem::execValidateVersionContext)
{
	P_GET_STRUCT_REF(FGenericVersionContext,Z_Param_Out_Context);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGenericVersionValidationResult*)Z_Param__Result=P_THIS->ValidateVersionContext(Z_Param_Out_Context);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionValidationSubsystem Function ValidateVersionContext *********

// ********** Begin Class UGenericVersionValidationSubsystem ***************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericVersionValidationSubsystem;
UClass* UGenericVersionValidationSubsystem::GetPrivateStaticClass()
{
	using TClass = UGenericVersionValidationSubsystem;
	if (!Z_Registration_Info_UClass_UGenericVersionValidationSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericVersionValidationSubsystem"),
			Z_Registration_Info_UClass_UGenericVersionValidationSubsystem.InnerSingleton,
			StaticRegisterNativesUGenericVersionValidationSubsystem,
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
	return Z_Registration_Info_UClass_UGenericVersionValidationSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericVersionValidationSubsystem_NoRegister()
{
	return UGenericVersionValidationSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\xa7\xe8\xa1\x8c\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe6\xa0\xa1\xe9\xaa\x8c\xe7\x9a\x84\xe8\xbd\xbb\xe9\x87\x8f\xe5\x85\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe5\x85\x88\xe5\x81\x9a\xe4\xb8\xad\xe5\xbf\x83\xe7\x89\x88\xe6\x9c\xac\xe6\xaf\x94\xe8\xbe\x83\xef\xbc\x8c\xe5\x86\x8d\xe4\xba\xa4\xe7\xbb\x99\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xaf\xb9\xe8\xb1\xa1\xe8\xa1\xa5\xe5\x85\x85\xe8\xa7\x84\xe5\x88\x99\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Subsystem/GenericVersionValidationSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionValidationSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\xa7\xe8\xa1\x8c\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe6\xa0\xa1\xe9\xaa\x8c\xe7\x9a\x84\xe8\xbd\xbb\xe9\x87\x8f\xe5\x85\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe5\x85\x88\xe5\x81\x9a\xe4\xb8\xad\xe5\xbf\x83\xe7\x89\x88\xe6\x9c\xac\xe6\xaf\x94\xe8\xbe\x83\xef\xbc\x8c\xe5\x86\x8d\xe4\xba\xa4\xe7\xbb\x99\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xaf\xb9\xe8\xb1\xa1\xe8\xa1\xa5\xe5\x85\x85\xe8\xa7\x84\xe5\x88\x99\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericVersionValidationSubsystem constinit property declarations *******
// ********** End Class UGenericVersionValidationSubsystem constinit property declarations *********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("MakeValidationFailed"), .Pointer = &UGenericVersionValidationSubsystem::execMakeValidationFailed },
		{ .NameUTF8 = UTF8TEXT("MakeValidationSuccess"), .Pointer = &UGenericVersionValidationSubsystem::execMakeValidationSuccess },
		{ .NameUTF8 = UTF8TEXT("MakeValidationWarning"), .Pointer = &UGenericVersionValidationSubsystem::execMakeValidationWarning },
		{ .NameUTF8 = UTF8TEXT("ValidateVersionContext"), .Pointer = &UGenericVersionValidationSubsystem::execValidateVersionContext },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationFailed, "MakeValidationFailed" }, // 1019263166
		{ &Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationSuccess, "MakeValidationSuccess" }, // 2437300361
		{ &Z_Construct_UFunction_UGenericVersionValidationSubsystem_MakeValidationWarning, "MakeValidationWarning" }, // 589644795
		{ &Z_Construct_UFunction_UGenericVersionValidationSubsystem_ValidateVersionContext, "ValidateVersionContext" }, // 23758943
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericVersionValidationSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics
UObject* (*const Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGenericGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericVersionFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics::ClassParams = {
	&UGenericVersionValidationSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics::Class_MetaDataParams)
};
void UGenericVersionValidationSubsystem::StaticRegisterNativesUGenericVersionValidationSubsystem()
{
	UClass* Class = UGenericVersionValidationSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGenericVersionValidationSubsystem()
{
	if (!Z_Registration_Info_UClass_UGenericVersionValidationSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericVersionValidationSubsystem.OuterSingleton, Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericVersionValidationSubsystem.OuterSingleton;
}
UGenericVersionValidationSubsystem::UGenericVersionValidationSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericVersionValidationSubsystem);
UGenericVersionValidationSubsystem::~UGenericVersionValidationSubsystem() {}
// ********** End Class UGenericVersionValidationSubsystem *****************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h__Script_GenericVersionFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericVersionValidationSubsystem, UGenericVersionValidationSubsystem::StaticClass, TEXT("UGenericVersionValidationSubsystem"), &Z_Registration_Info_UClass_UGenericVersionValidationSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericVersionValidationSubsystem), 2732837622U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h__Script_GenericVersionFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h__Script_GenericVersionFramework_3969538762{
	TEXT("/Script/GenericVersionFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h__Script_GenericVersionFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h__Script_GenericVersionFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
