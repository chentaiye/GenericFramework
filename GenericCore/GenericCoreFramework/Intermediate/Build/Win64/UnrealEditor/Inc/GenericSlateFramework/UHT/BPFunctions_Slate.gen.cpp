// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/BPFunctions_Slate.h"
#include "SlateType.h"
#include "Styling/SlateBrush.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBPFunctions_Slate() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_Slate();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_Slate_NoRegister();
GENERICSLATEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FBorderBrush();
GENERICSLATEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FImageBrush();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
UMG_API UClass* Z_Construct_UClass_UBackgroundBlurSlot_NoRegister();
UMG_API UClass* Z_Construct_UClass_UBorder_NoRegister();
UMG_API UClass* Z_Construct_UClass_UButtonSlot_NoRegister();
UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
UMG_API UClass* Z_Construct_UClass_UStackBoxSlot_NoRegister();
UMG_API UClass* Z_Construct_UClass_UWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBPFunctions_Slate Function Border_ConvToSlateBrush **********************
struct Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics
{
	struct BPFunctions_Slate_eventBorder_ConvToSlateBrush_Parms
	{
		FBorderBrush InBorderBrush;
		FSlateBrush ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "BPFunctions_Slate|Border" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2\xe8\xbe\xb9\xe6\xa1\x86""ConvToSlate\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "To Slate Brush(Border)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2\xe8\xbe\xb9\xe6\xa1\x86""ConvToSlate\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBorderBrush_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Border_ConvToSlateBrush constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InBorderBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Border_ConvToSlateBrush constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Border_ConvToSlateBrush Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::NewProp_InBorderBrush = { "InBorderBrush", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventBorder_ConvToSlateBrush_Parms, InBorderBrush), Z_Construct_UScriptStruct_FBorderBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBorderBrush_MetaData), NewProp_InBorderBrush_MetaData) }; // 2746457749
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventBorder_ConvToSlateBrush_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(0, nullptr) }; // 4278521822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::NewProp_InBorderBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::PropPointers) < 2048);
// ********** End Function Border_ConvToSlateBrush Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "Border_ConvToSlateBrush", 	Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::BPFunctions_Slate_eventBorder_ConvToSlateBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::BPFunctions_Slate_eventBorder_ConvToSlateBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execBorder_ConvToSlateBrush)
{
	P_GET_STRUCT_REF(FBorderBrush,Z_Param_Out_InBorderBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateBrush*)Z_Param__Result=UBPFunctions_Slate::Border_ConvToSlateBrush(Z_Param_Out_InBorderBrush);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function Border_ConvToSlateBrush ************************

// ********** Begin Class UBPFunctions_Slate Function ConvToBorderBrush ****************************
struct Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics
{
	struct BPFunctions_Slate_eventConvToBorderBrush_Parms
	{
		FSlateBrush InSlateBrush;
		FBorderBrush ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "BPFunctions_Slate|Border" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2To\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "To Border Brush" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2To\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSlateBrush_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConvToBorderBrush constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSlateBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConvToBorderBrush constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConvToBorderBrush Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::NewProp_InSlateBrush = { "InSlateBrush", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventConvToBorderBrush_Parms, InSlateBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSlateBrush_MetaData), NewProp_InSlateBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventConvToBorderBrush_Parms, ReturnValue), Z_Construct_UScriptStruct_FBorderBrush, METADATA_PARAMS(0, nullptr) }; // 2746457749
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::NewProp_InSlateBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::PropPointers) < 2048);
// ********** End Function ConvToBorderBrush Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "ConvToBorderBrush", 	Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::BPFunctions_Slate_eventConvToBorderBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::BPFunctions_Slate_eventConvToBorderBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execConvToBorderBrush)
{
	P_GET_STRUCT_REF(FSlateBrush,Z_Param_Out_InSlateBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FBorderBrush*)Z_Param__Result=UBPFunctions_Slate::ConvToBorderBrush(Z_Param_Out_InSlateBrush);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function ConvToBorderBrush ******************************

// ********** Begin Class UBPFunctions_Slate Function ConvToImageBrush *****************************
struct Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics
{
	struct BPFunctions_Slate_eventConvToImageBrush_Parms
	{
		FSlateBrush InSlateBrush;
		FImageBrush ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "BPFunctions_Slate|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2To\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "To Image Brush" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2To\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InSlateBrush_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConvToImageBrush constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InSlateBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConvToImageBrush constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConvToImageBrush Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::NewProp_InSlateBrush = { "InSlateBrush", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventConvToImageBrush_Parms, InSlateBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InSlateBrush_MetaData), NewProp_InSlateBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventConvToImageBrush_Parms, ReturnValue), Z_Construct_UScriptStruct_FImageBrush, METADATA_PARAMS(0, nullptr) }; // 799750334
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::NewProp_InSlateBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::PropPointers) < 2048);
// ********** End Function ConvToImageBrush Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "ConvToImageBrush", 	Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::BPFunctions_Slate_eventConvToImageBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::BPFunctions_Slate_eventConvToImageBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execConvToImageBrush)
{
	P_GET_STRUCT_REF(FSlateBrush,Z_Param_Out_InSlateBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FImageBrush*)Z_Param__Result=UBPFunctions_Slate::ConvToImageBrush(Z_Param_Out_InSlateBrush);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function ConvToImageBrush *******************************

// ********** Begin Class UBPFunctions_Slate Function Image_ConvToSlateBrush ***********************
struct Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics
{
	struct BPFunctions_Slate_eventImage_ConvToSlateBrush_Parms
	{
		FImageBrush InImageBrush;
		FSlateBrush ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "BPFunctions_Slate|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2\xe5\x9b\xbe\xe7\x89\x87""ConvToSlate\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "To Slate Brush(Image)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2\xe5\x9b\xbe\xe7\x89\x87""ConvToSlate\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InImageBrush_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Image_ConvToSlateBrush constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InImageBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Image_ConvToSlateBrush constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Image_ConvToSlateBrush Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::NewProp_InImageBrush = { "InImageBrush", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventImage_ConvToSlateBrush_Parms, InImageBrush), Z_Construct_UScriptStruct_FImageBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InImageBrush_MetaData), NewProp_InImageBrush_MetaData) }; // 799750334
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventImage_ConvToSlateBrush_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(0, nullptr) }; // 4278521822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::NewProp_InImageBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::PropPointers) < 2048);
// ********** End Function Image_ConvToSlateBrush Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "Image_ConvToSlateBrush", 	Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::BPFunctions_Slate_eventImage_ConvToSlateBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::BPFunctions_Slate_eventImage_ConvToSlateBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execImage_ConvToSlateBrush)
{
	P_GET_STRUCT_REF(FImageBrush,Z_Param_Out_InImageBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateBrush*)Z_Param__Result=UBPFunctions_Slate::Image_ConvToSlateBrush(Z_Param_Out_InImageBrush);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function Image_ConvToSlateBrush *************************

// ********** Begin Class UBPFunctions_Slate Function IsValid_BorderBrush **************************
struct Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics
{
	struct BPFunctions_Slate_eventIsValid_BorderBrush_Parms
	{
		FBorderBrush InBorderBrush;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "BPFunctions_Slate|Border" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadValidBorder\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe6\x88\x96\xe8\xbf\x87\xe6\xbb\xa4\xe6\x97\xa0\xe6\x95\x88\xe8\xbe\x93\xe5\x85\xa5\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "IsValid" },
		{ "DisplayName", "IsValid(BorderBrush)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadValidBorder\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe6\x88\x96\xe8\xbf\x87\xe6\xbb\xa4\xe6\x97\xa0\xe6\x95\x88\xe8\xbe\x93\xe5\x85\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBorderBrush_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsValid_BorderBrush constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InBorderBrush;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsValid_BorderBrush constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsValid_BorderBrush Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::NewProp_InBorderBrush = { "InBorderBrush", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventIsValid_BorderBrush_Parms, InBorderBrush), Z_Construct_UScriptStruct_FBorderBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBorderBrush_MetaData), NewProp_InBorderBrush_MetaData) }; // 2746457749
void Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Slate_eventIsValid_BorderBrush_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Slate_eventIsValid_BorderBrush_Parms), &Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::NewProp_InBorderBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::PropPointers) < 2048);
// ********** End Function IsValid_BorderBrush Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "IsValid_BorderBrush", 	Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::BPFunctions_Slate_eventIsValid_BorderBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::BPFunctions_Slate_eventIsValid_BorderBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execIsValid_BorderBrush)
{
	P_GET_STRUCT_REF(FBorderBrush,Z_Param_Out_InBorderBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Slate::IsValid_BorderBrush(Z_Param_Out_InBorderBrush);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function IsValid_BorderBrush ****************************

// ********** Begin Class UBPFunctions_Slate Function IsValid_ImageBrush ***************************
struct Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics
{
	struct BPFunctions_Slate_eventIsValid_ImageBrush_Parms
	{
		FImageBrush InImageBrush;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "BPFunctions_Slate|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7\xe5\x8c\x85\xe8\xa3\x85\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe5\x8f\xaf\xe8\xa7\xa3\xe6\x9e\x90\xe8\xb5\x84\xe6\xba\x90\xef\xbc\x8c\xe9\x81\xbf\xe5\x85\x8d Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe7\xa9\xba\xe7\x94\xbb\xe5\x88\xb7\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "IsValid" },
		{ "DisplayName", "IsValid(ImageBrush)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7\xe5\x8c\x85\xe8\xa3\x85\xe6\x98\xaf\xe5\x90\xa6\xe5\x8c\x85\xe5\x90\xab\xe5\x8f\xaf\xe8\xa7\xa3\xe6\x9e\x90\xe8\xb5\x84\xe6\xba\x90\xef\xbc\x8c\xe9\x81\xbf\xe5\x85\x8d Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe7\xa9\xba\xe7\x94\xbb\xe5\x88\xb7\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InImageBrush_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsValid_ImageBrush constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InImageBrush;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsValid_ImageBrush constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsValid_ImageBrush Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::NewProp_InImageBrush = { "InImageBrush", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventIsValid_ImageBrush_Parms, InImageBrush), Z_Construct_UScriptStruct_FImageBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InImageBrush_MetaData), NewProp_InImageBrush_MetaData) }; // 799750334
void Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Slate_eventIsValid_ImageBrush_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Slate_eventIsValid_ImageBrush_Parms), &Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::NewProp_InImageBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::PropPointers) < 2048);
// ********** End Function IsValid_ImageBrush Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "IsValid_ImageBrush", 	Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::BPFunctions_Slate_eventIsValid_ImageBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::BPFunctions_Slate_eventIsValid_ImageBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execIsValid_ImageBrush)
{
	P_GET_STRUCT_REF(FImageBrush,Z_Param_Out_InImageBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Slate::IsValid_ImageBrush(Z_Param_Out_InImageBrush);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function IsValid_ImageBrush *****************************

// ********** Begin Class UBPFunctions_Slate Function SetBorderBrush *******************************
struct Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics
{
	struct BPFunctions_Slate_eventSetBorderBrush_Parms
	{
		UBorder* InBorder;
		FBorderBrush InBorderBrush;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "BPFunctions_Slate|Border" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBorder_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetBorderBrush constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InBorder;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InBorderBrush;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetBorderBrush constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetBorderBrush Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::NewProp_InBorder = { "InBorder", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventSetBorderBrush_Parms, InBorder), Z_Construct_UClass_UBorder_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBorder_MetaData), NewProp_InBorder_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::NewProp_InBorderBrush = { "InBorderBrush", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventSetBorderBrush_Parms, InBorderBrush), Z_Construct_UScriptStruct_FBorderBrush, METADATA_PARAMS(0, nullptr) }; // 2746457749
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::NewProp_InBorder,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::NewProp_InBorderBrush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::PropPointers) < 2048);
// ********** End Function SetBorderBrush Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "SetBorderBrush", 	Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::BPFunctions_Slate_eventSetBorderBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::BPFunctions_Slate_eventSetBorderBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execSetBorderBrush)
{
	P_GET_OBJECT(UBorder,Z_Param_InBorder);
	P_GET_STRUCT(FBorderBrush,Z_Param_InBorderBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Slate::SetBorderBrush(Z_Param_InBorder,Z_Param_InBorderBrush);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function SetBorderBrush *********************************

// ********** Begin Class UBPFunctions_Slate Function SetImageBrush ********************************
struct Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics
{
	struct BPFunctions_Slate_eventSetImageBrush_Parms
	{
		UImage* InImage;
		FImageBrush InImageBrush;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "BPFunctions_Slate|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87""Brush\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87""Brush\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InImage_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetImageBrush constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InImage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InImageBrush;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetImageBrush constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetImageBrush Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::NewProp_InImage = { "InImage", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventSetImageBrush_Parms, InImage), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InImage_MetaData), NewProp_InImage_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::NewProp_InImageBrush = { "InImageBrush", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventSetImageBrush_Parms, InImageBrush), Z_Construct_UScriptStruct_FImageBrush, METADATA_PARAMS(0, nullptr) }; // 799750334
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::NewProp_InImage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::NewProp_InImageBrush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::PropPointers) < 2048);
// ********** End Function SetImageBrush Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "SetImageBrush", 	Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::BPFunctions_Slate_eventSetImageBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::BPFunctions_Slate_eventSetImageBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execSetImageBrush)
{
	P_GET_OBJECT(UImage,Z_Param_InImage);
	P_GET_STRUCT(FImageBrush,Z_Param_InImageBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Slate::SetImageBrush(Z_Param_InImage,Z_Param_InImageBrush);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function SetImageBrush **********************************

// ********** Begin Class UBPFunctions_Slate Function SlotAsBackgroundBlurSlot *********************
struct Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics
{
	struct BPFunctions_Slate_eventSlotAsBackgroundBlurSlot_Parms
	{
		const UWidget* Widget;
		UBackgroundBlurSlot* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "BPFunctions_Slate|Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8a\x8a UWidget \xe7\x9a\x84\xe6\x8f\x92\xe6\xa7\xbd\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xba""BackgroundBlur\xe6\xa7\xbd\xe4\xbd\x8d\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe8\x93\x9d\xe5\x9b\xbe\xe8\xae\xbf\xe9\x97\xae\xe5\x85\xb7\xe4\xbd\x93\xe5\xb8\x83\xe5\xb1\x80\xe5\x8f\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8a\x8a UWidget \xe7\x9a\x84\xe6\x8f\x92\xe6\xa7\xbd\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xba""BackgroundBlur\xe6\xa7\xbd\xe4\xbd\x8d\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe8\x93\x9d\xe5\x9b\xbe\xe8\xae\xbf\xe9\x97\xae\xe5\x85\xb7\xe4\xbd\x93\xe5\xb8\x83\xe5\xb1\x80\xe5\x8f\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Widget_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SlotAsBackgroundBlurSlot constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Widget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SlotAsBackgroundBlurSlot constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SlotAsBackgroundBlurSlot Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::NewProp_Widget = { "Widget", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventSlotAsBackgroundBlurSlot_Parms, Widget), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Widget_MetaData), NewProp_Widget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventSlotAsBackgroundBlurSlot_Parms, ReturnValue), Z_Construct_UClass_UBackgroundBlurSlot_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::NewProp_Widget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::PropPointers) < 2048);
// ********** End Function SlotAsBackgroundBlurSlot Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "SlotAsBackgroundBlurSlot", 	Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::BPFunctions_Slate_eventSlotAsBackgroundBlurSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::BPFunctions_Slate_eventSlotAsBackgroundBlurSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execSlotAsBackgroundBlurSlot)
{
	P_GET_OBJECT(UWidget,Z_Param_Widget);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UBackgroundBlurSlot**)Z_Param__Result=UBPFunctions_Slate::SlotAsBackgroundBlurSlot(Z_Param_Widget);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function SlotAsBackgroundBlurSlot ***********************

// ********** Begin Class UBPFunctions_Slate Function SlotAsButtonSlot *****************************
struct Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics
{
	struct BPFunctions_Slate_eventSlotAsButtonSlot_Parms
	{
		const UWidget* Widget;
		UButtonSlot* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "BPFunctions_Slate|Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8a\x8a UWidget \xe7\x9a\x84\xe6\x8f\x92\xe6\xa7\xbd\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xba""Button\xe6\xa7\xbd\xe4\xbd\x8d\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe8\x93\x9d\xe5\x9b\xbe\xe8\xae\xbf\xe9\x97\xae\xe5\x85\xb7\xe4\xbd\x93\xe5\xb8\x83\xe5\xb1\x80\xe5\x8f\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8a\x8a UWidget \xe7\x9a\x84\xe6\x8f\x92\xe6\xa7\xbd\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xba""Button\xe6\xa7\xbd\xe4\xbd\x8d\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe8\x93\x9d\xe5\x9b\xbe\xe8\xae\xbf\xe9\x97\xae\xe5\x85\xb7\xe4\xbd\x93\xe5\xb8\x83\xe5\xb1\x80\xe5\x8f\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Widget_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SlotAsButtonSlot constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Widget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SlotAsButtonSlot constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SlotAsButtonSlot Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::NewProp_Widget = { "Widget", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventSlotAsButtonSlot_Parms, Widget), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Widget_MetaData), NewProp_Widget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventSlotAsButtonSlot_Parms, ReturnValue), Z_Construct_UClass_UButtonSlot_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::NewProp_Widget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::PropPointers) < 2048);
// ********** End Function SlotAsButtonSlot Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "SlotAsButtonSlot", 	Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::BPFunctions_Slate_eventSlotAsButtonSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::BPFunctions_Slate_eventSlotAsButtonSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execSlotAsButtonSlot)
{
	P_GET_OBJECT(UWidget,Z_Param_Widget);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UButtonSlot**)Z_Param__Result=UBPFunctions_Slate::SlotAsButtonSlot(Z_Param_Widget);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function SlotAsButtonSlot *******************************

// ********** Begin Class UBPFunctions_Slate Function SlotAsStackBoxSlot ***************************
struct Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics
{
	struct BPFunctions_Slate_eventSlotAsStackBoxSlot_Parms
	{
		const UWidget* Widget;
		UStackBoxSlot* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "BPFunctions_Slate|Slot" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8a\x8a UWidget \xe7\x9a\x84\xe6\x8f\x92\xe6\xa7\xbd\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xbaStackBox\xe6\xa7\xbd\xe4\xbd\x8d\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe8\x93\x9d\xe5\x9b\xbe\xe8\xae\xbf\xe9\x97\xae\xe5\x85\xb7\xe4\xbd\x93\xe5\xb8\x83\xe5\xb1\x80\xe5\x8f\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8a\x8a UWidget \xe7\x9a\x84\xe6\x8f\x92\xe6\xa7\xbd\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xbaStackBox\xe6\xa7\xbd\xe4\xbd\x8d\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe8\x93\x9d\xe5\x9b\xbe\xe8\xae\xbf\xe9\x97\xae\xe5\x85\xb7\xe4\xbd\x93\xe5\xb8\x83\xe5\xb1\x80\xe5\x8f\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Widget_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SlotAsStackBoxSlot constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Widget;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SlotAsStackBoxSlot constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SlotAsStackBoxSlot Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::NewProp_Widget = { "Widget", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventSlotAsStackBoxSlot_Parms, Widget), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Widget_MetaData), NewProp_Widget_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Slate_eventSlotAsStackBoxSlot_Parms, ReturnValue), Z_Construct_UClass_UStackBoxSlot_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::NewProp_Widget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::PropPointers) < 2048);
// ********** End Function SlotAsStackBoxSlot Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Slate, nullptr, "SlotAsStackBoxSlot", 	Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::BPFunctions_Slate_eventSlotAsStackBoxSlot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::BPFunctions_Slate_eventSlotAsStackBoxSlot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Slate::execSlotAsStackBoxSlot)
{
	P_GET_OBJECT(UWidget,Z_Param_Widget);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UStackBoxSlot**)Z_Param__Result=UBPFunctions_Slate::SlotAsStackBoxSlot(Z_Param_Widget);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Slate Function SlotAsStackBoxSlot *****************************

// ********** Begin Class UBPFunctions_Slate *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBPFunctions_Slate;
UClass* UBPFunctions_Slate::GetPrivateStaticClass()
{
	using TClass = UBPFunctions_Slate;
	if (!Z_Registration_Info_UClass_UBPFunctions_Slate.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BPFunctions_Slate"),
			Z_Registration_Info_UClass_UBPFunctions_Slate.InnerSingleton,
			StaticRegisterNativesUBPFunctions_Slate,
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
	return Z_Registration_Info_UClass_UBPFunctions_Slate.InnerSingleton;
}
UClass* Z_Construct_UClass_UBPFunctions_Slate_NoRegister()
{
	return UBPFunctions_Slate::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBPFunctions_Slate_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2Slate\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeSlate/UMG\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "BPFunctions/BPFunctions_Slate.h" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Slate.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2Slate\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeSlate/UMG\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBPFunctions_Slate constinit property declarations ***********************
// ********** End Class UBPFunctions_Slate constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Border_ConvToSlateBrush"), .Pointer = &UBPFunctions_Slate::execBorder_ConvToSlateBrush },
		{ .NameUTF8 = UTF8TEXT("ConvToBorderBrush"), .Pointer = &UBPFunctions_Slate::execConvToBorderBrush },
		{ .NameUTF8 = UTF8TEXT("ConvToImageBrush"), .Pointer = &UBPFunctions_Slate::execConvToImageBrush },
		{ .NameUTF8 = UTF8TEXT("Image_ConvToSlateBrush"), .Pointer = &UBPFunctions_Slate::execImage_ConvToSlateBrush },
		{ .NameUTF8 = UTF8TEXT("IsValid_BorderBrush"), .Pointer = &UBPFunctions_Slate::execIsValid_BorderBrush },
		{ .NameUTF8 = UTF8TEXT("IsValid_ImageBrush"), .Pointer = &UBPFunctions_Slate::execIsValid_ImageBrush },
		{ .NameUTF8 = UTF8TEXT("SetBorderBrush"), .Pointer = &UBPFunctions_Slate::execSetBorderBrush },
		{ .NameUTF8 = UTF8TEXT("SetImageBrush"), .Pointer = &UBPFunctions_Slate::execSetImageBrush },
		{ .NameUTF8 = UTF8TEXT("SlotAsBackgroundBlurSlot"), .Pointer = &UBPFunctions_Slate::execSlotAsBackgroundBlurSlot },
		{ .NameUTF8 = UTF8TEXT("SlotAsButtonSlot"), .Pointer = &UBPFunctions_Slate::execSlotAsButtonSlot },
		{ .NameUTF8 = UTF8TEXT("SlotAsStackBoxSlot"), .Pointer = &UBPFunctions_Slate::execSlotAsStackBoxSlot },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBPFunctions_Slate_Border_ConvToSlateBrush, "Border_ConvToSlateBrush" }, // 1005917801
		{ &Z_Construct_UFunction_UBPFunctions_Slate_ConvToBorderBrush, "ConvToBorderBrush" }, // 3715194971
		{ &Z_Construct_UFunction_UBPFunctions_Slate_ConvToImageBrush, "ConvToImageBrush" }, // 161844762
		{ &Z_Construct_UFunction_UBPFunctions_Slate_Image_ConvToSlateBrush, "Image_ConvToSlateBrush" }, // 2906667729
		{ &Z_Construct_UFunction_UBPFunctions_Slate_IsValid_BorderBrush, "IsValid_BorderBrush" }, // 2716909568
		{ &Z_Construct_UFunction_UBPFunctions_Slate_IsValid_ImageBrush, "IsValid_ImageBrush" }, // 2207952676
		{ &Z_Construct_UFunction_UBPFunctions_Slate_SetBorderBrush, "SetBorderBrush" }, // 1570434784
		{ &Z_Construct_UFunction_UBPFunctions_Slate_SetImageBrush, "SetImageBrush" }, // 3027043712
		{ &Z_Construct_UFunction_UBPFunctions_Slate_SlotAsBackgroundBlurSlot, "SlotAsBackgroundBlurSlot" }, // 3975661584
		{ &Z_Construct_UFunction_UBPFunctions_Slate_SlotAsButtonSlot, "SlotAsButtonSlot" }, // 1326776248
		{ &Z_Construct_UFunction_UBPFunctions_Slate_SlotAsStackBoxSlot, "SlotAsStackBoxSlot" }, // 3974341977
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctions_Slate>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBPFunctions_Slate_Statics
UObject* (*const Z_Construct_UClass_UBPFunctions_Slate_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Slate_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctions_Slate_Statics::ClassParams = {
	&UBPFunctions_Slate::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Slate_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPFunctions_Slate_Statics::Class_MetaDataParams)
};
void UBPFunctions_Slate::StaticRegisterNativesUBPFunctions_Slate()
{
	UClass* Class = UBPFunctions_Slate::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UBPFunctions_Slate_Statics::Funcs));
}
UClass* Z_Construct_UClass_UBPFunctions_Slate()
{
	if (!Z_Registration_Info_UClass_UBPFunctions_Slate.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPFunctions_Slate.OuterSingleton, Z_Construct_UClass_UBPFunctions_Slate_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPFunctions_Slate.OuterSingleton;
}
UBPFunctions_Slate::UBPFunctions_Slate(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBPFunctions_Slate);
UBPFunctions_Slate::~UBPFunctions_Slate() {}
// ********** End Class UBPFunctions_Slate *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h__Script_GenericSlateFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPFunctions_Slate, UBPFunctions_Slate::StaticClass, TEXT("UBPFunctions_Slate"), &Z_Registration_Info_UClass_UBPFunctions_Slate, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPFunctions_Slate), 21161012U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h__Script_GenericSlateFramework_3076444903{
	TEXT("/Script/GenericSlateFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h__Script_GenericSlateFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_BPFunctions_BPFunctions_Slate_h__Script_GenericSlateFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
