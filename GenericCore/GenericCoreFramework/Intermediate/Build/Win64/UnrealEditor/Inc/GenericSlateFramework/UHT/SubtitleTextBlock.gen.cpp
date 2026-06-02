// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UWidget/SubtitleTextBlock.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateColor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSubtitleTextBlock() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USubtitleTextBlock();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USubtitleTextBlock_NoRegister();
GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextOverflowPolicy();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextTransformPolicy();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateColor();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateFontInfo();
UMG_API UClass* Z_Construct_UClass_UTextLayoutWidget();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnSubtitleLineAdded **************************************************
struct Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics
{
	struct _Script_GenericSlateFramework_eventOnSubtitleLineAdded_Parms
	{
		FText AddedLine;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AddedLine_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnSubtitleLineAdded constinit property declarations ******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_AddedLine;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnSubtitleLineAdded constinit property declarations ********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnSubtitleLineAdded Property Definitions *****************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::NewProp_AddedLine = { "AddedLine", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericSlateFramework_eventOnSubtitleLineAdded_Parms, AddedLine), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AddedLine_MetaData), NewProp_AddedLine_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::NewProp_AddedLine,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnSubtitleLineAdded Property Definitions *******************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework, nullptr, "OnSubtitleLineAdded__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnSubtitleLineAdded_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnSubtitleLineAdded_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSubtitleLineAdded_DelegateWrapper(const FMulticastScriptDelegate& OnSubtitleLineAdded, FText const& AddedLine)
{
	struct _Script_GenericSlateFramework_eventOnSubtitleLineAdded_Parms
	{
		FText AddedLine;
	};
	_Script_GenericSlateFramework_eventOnSubtitleLineAdded_Parms Parms;
	Parms.AddedLine=AddedLine;
	OnSubtitleLineAdded.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnSubtitleLineAdded ****************************************************

// ********** Begin Class USubtitleTextBlock Function AddText **************************************
struct Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics
{
	struct SubtitleTextBlock_eventAddText_Parms
	{
		FText InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb7\xbb\xe5\x8a\xa0\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x86\x85\xe9\x83\xa8\xe7\xbc\x93\xe5\xad\x98\xe3\x80\x81\xe6\x98\xbe\xe7\xa4\xba\xe7\x8a\xb6\xe6\x80\x81\xe6\x88\x96\xe4\xba\x8b\xe4\xbb\xb6\xe7\xbb\x91\xe5\xae\x9a\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb7\xbb\xe5\x8a\xa0\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x86\x85\xe9\x83\xa8\xe7\xbc\x93\xe5\xad\x98\xe3\x80\x81\xe6\x98\xbe\xe7\xa4\xba\xe7\x8a\xb6\xe6\x80\x81\xe6\x88\x96\xe4\xba\x8b\xe4\xbb\xb6\xe7\xbb\x91\xe5\xae\x9a\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AddText constinit property declarations *******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddText constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddText Property Definitions ******************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventAddText_Parms, InText), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::PropPointers) < 2048);
// ********** End Function AddText Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "AddText", 	Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::SubtitleTextBlock_eventAddText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::SubtitleTextBlock_eventAddText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_AddText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_AddText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execAddText)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddText(Z_Param_InText);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function AddText ****************************************

// ********** Begin Class USubtitleTextBlock Function AddTextWithLifetime **************************
struct Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics
{
	struct SubtitleTextBlock_eventAddTextWithLifetime_Parms
	{
		FText InText;
		float InLifetimeSeconds;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb7\xbb\xe5\x8a\xa0\xe6\x96\x87\xe6\x9c\xacWithLifetime\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x86\x85\xe9\x83\xa8\xe7\xbc\x93\xe5\xad\x98\xe3\x80\x81\xe6\x98\xbe\xe7\xa4\xba\xe7\x8a\xb6\xe6\x80\x81\xe6\x88\x96\xe4\xba\x8b\xe4\xbb\xb6\xe7\xbb\x91\xe5\xae\x9a\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb7\xbb\xe5\x8a\xa0\xe6\x96\x87\xe6\x9c\xacWithLifetime\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x86\x85\xe9\x83\xa8\xe7\xbc\x93\xe5\xad\x98\xe3\x80\x81\xe6\x98\xbe\xe7\xa4\xba\xe7\x8a\xb6\xe6\x80\x81\xe6\x88\x96\xe4\xba\x8b\xe4\xbb\xb6\xe7\xbb\x91\xe5\xae\x9a\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AddTextWithLifetime constinit property declarations *******************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InLifetimeSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddTextWithLifetime constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddTextWithLifetime Property Definitions ******************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventAddTextWithLifetime_Parms, InText), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::NewProp_InLifetimeSeconds = { "InLifetimeSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventAddTextWithLifetime_Parms, InLifetimeSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::NewProp_InText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::NewProp_InLifetimeSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::PropPointers) < 2048);
// ********** End Function AddTextWithLifetime Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "AddTextWithLifetime", 	Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::SubtitleTextBlock_eventAddTextWithLifetime_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::SubtitleTextBlock_eventAddTextWithLifetime_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execAddTextWithLifetime)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InText);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InLifetimeSeconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddTextWithLifetime(Z_Param_InText,Z_Param_InLifetimeSeconds);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function AddTextWithLifetime ****************************

// ********** Begin Class USubtitleTextBlock Function AppendLines **********************************
struct Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics
{
	struct SubtitleTextBlock_eventAppendLines_Parms
	{
		TArray<FText> InLines;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\xb9\xe9\x87\x8f\xe8\xbf\xbd\xe5\x8a\xa0\xe5\xad\x97\xe5\xb9\x95\xe8\xa1\x8c\xef\xbc\x8c\xe5\xb9\xb6\xe6\x8a\x8a\xe7\xbc\x93\xe5\xad\x98\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x98\xbe\xe7\xa4\xba\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\xb9\xe9\x87\x8f\xe8\xbf\xbd\xe5\x8a\xa0\xe5\xad\x97\xe5\xb9\x95\xe8\xa1\x8c\xef\xbc\x8c\xe5\xb9\xb6\xe6\x8a\x8a\xe7\xbc\x93\xe5\xad\x98\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x98\xbe\xe7\xa4\xba\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InLines_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AppendLines constinit property declarations ***************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InLines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InLines;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AppendLines constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AppendLines Property Definitions **************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::NewProp_InLines_Inner = { "InLines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::NewProp_InLines = { "InLines", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventAppendLines_Parms, InLines), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InLines_MetaData), NewProp_InLines_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::NewProp_InLines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::NewProp_InLines,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::PropPointers) < 2048);
// ********** End Function AppendLines Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "AppendLines", 	Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::SubtitleTextBlock_eventAppendLines_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::SubtitleTextBlock_eventAppendLines_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_AppendLines()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_AppendLines_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execAppendLines)
{
	P_GET_TARRAY_REF(FText,Z_Param_Out_InLines);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AppendLines(Z_Param_Out_InLines);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function AppendLines ************************************

// ********** Begin Class USubtitleTextBlock Function ClearLines ***********************************
struct Z_Construct_UFunction_USubtitleTextBlock_ClearLines_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb8\x85\xe7\xa9\xba\xe5\xad\x97\xe5\xb9\x95\xe8\xa1\x8c\xe7\xbc\x93\xe5\xad\x98\xef\xbc\x8c\xe5\xb9\xb6\xe7\xab\x8b\xe5\x8d\xb3\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x98\xbe\xe7\xa4\xba\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb8\x85\xe7\xa9\xba\xe5\xad\x97\xe5\xb9\x95\xe8\xa1\x8c\xe7\xbc\x93\xe5\xad\x98\xef\xbc\x8c\xe5\xb9\xb6\xe7\xab\x8b\xe5\x8d\xb3\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x98\xbe\xe7\xa4\xba\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ClearLines constinit property declarations ****************************
// ********** End Function ClearLines constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_ClearLines_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "ClearLines", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_ClearLines_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_ClearLines_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_USubtitleTextBlock_ClearLines()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_ClearLines_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execClearLines)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearLines();
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function ClearLines *************************************

// ********** Begin Class USubtitleTextBlock Function GetColorAndOpacity ***************************
struct Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics
{
	struct SubtitleTextBlock_eventGetColorAndOpacity_Parms
	{
		FSlateColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetColorAndOpacity constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetColorAndOpacity constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetColorAndOpacity Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventGetColorAndOpacity_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(0, nullptr) }; // 1663967387
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::PropPointers) < 2048);
// ********** End Function GetColorAndOpacity Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "GetColorAndOpacity", 	Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::SubtitleTextBlock_eventGetColorAndOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::SubtitleTextBlock_eventGetColorAndOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execGetColorAndOpacity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateColor*)Z_Param__Result=P_THIS->GetColorAndOpacity();
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function GetColorAndOpacity *****************************

// ********** Begin Class USubtitleTextBlock Function GetFont **************************************
struct Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics
{
	struct SubtitleTextBlock_eventGetFont_Parms
	{
		FSlateFontInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetFont constinit property declarations *******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFont constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFont Property Definitions ******************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventGetFont_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 167205173
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::PropPointers) < 2048);
// ********** End Function GetFont Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "GetFont", 	Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::SubtitleTextBlock_eventGetFont_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::SubtitleTextBlock_eventGetFont_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_GetFont()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_GetFont_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execGetFont)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateFontInfo*)Z_Param__Result=P_THIS->GetFont();
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function GetFont ****************************************

// ********** Begin Class USubtitleTextBlock Function GetLines *************************************
struct Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics
{
	struct SubtitleTextBlock_eventGetLines_Parms
	{
		TArray<FText> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe5\xb9\x95\xe8\xa1\x8c\xe9\x9b\x86\xe5\x90\x88\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe5\xb9\x95\xe8\xa1\x8c\xe9\x9b\x86\xe5\x90\x88\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetLines constinit property declarations ******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLines constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLines Property Definitions *****************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventGetLines_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::PropPointers) < 2048);
// ********** End Function GetLines Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "GetLines", 	Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::SubtitleTextBlock_eventGetLines_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::SubtitleTextBlock_eventGetLines_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_GetLines()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_GetLines_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execGetLines)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FText>*)Z_Param__Result=P_THIS->GetLines();
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function GetLines ***************************************

// ********** Begin Class USubtitleTextBlock Function GetMinDesiredWidth ***************************
struct Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics
{
	struct SubtitleTextBlock_eventGetMinDesiredWidth_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMinDesiredWidth constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMinDesiredWidth constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMinDesiredWidth Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventGetMinDesiredWidth_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::PropPointers) < 2048);
// ********** End Function GetMinDesiredWidth Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "GetMinDesiredWidth", 	Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::SubtitleTextBlock_eventGetMinDesiredWidth_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::SubtitleTextBlock_eventGetMinDesiredWidth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execGetMinDesiredWidth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetMinDesiredWidth();
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function GetMinDesiredWidth *****************************

// ********** Begin Class USubtitleTextBlock Function GetShadowColorAndOpacity *********************
struct Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics
{
	struct SubtitleTextBlock_eventGetShadowColorAndOpacity_Parms
	{
		FLinearColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetShadowColorAndOpacity constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetShadowColorAndOpacity constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetShadowColorAndOpacity Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventGetShadowColorAndOpacity_Parms, ReturnValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::PropPointers) < 2048);
// ********** End Function GetShadowColorAndOpacity Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "GetShadowColorAndOpacity", 	Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::SubtitleTextBlock_eventGetShadowColorAndOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::SubtitleTextBlock_eventGetShadowColorAndOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execGetShadowColorAndOpacity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLinearColor*)Z_Param__Result=P_THIS->GetShadowColorAndOpacity();
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function GetShadowColorAndOpacity ***********************

// ********** Begin Class USubtitleTextBlock Function GetShadowOffset ******************************
struct Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics
{
	struct SubtitleTextBlock_eventGetShadowOffset_Parms
	{
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetShadowOffset constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetShadowOffset constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetShadowOffset Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventGetShadowOffset_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::PropPointers) < 2048);
// ********** End Function GetShadowOffset Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "GetShadowOffset", 	Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::SubtitleTextBlock_eventGetShadowOffset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::SubtitleTextBlock_eventGetShadowOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execGetShadowOffset)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=P_THIS->GetShadowOffset();
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function GetShadowOffset ********************************

// ********** Begin Class USubtitleTextBlock Function GetText **************************************
struct Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics
{
	struct SubtitleTextBlock_eventGetText_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetText constinit property declarations *******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetText constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetText Property Definitions ******************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventGetText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::PropPointers) < 2048);
// ********** End Function GetText Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "GetText", 	Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::SubtitleTextBlock_eventGetText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::SubtitleTextBlock_eventGetText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_GetText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_GetText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execGetText)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetText();
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function GetText ****************************************

// ********** Begin Class USubtitleTextBlock Function GetTextOverflowPolicy ************************
struct Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics
{
	struct SubtitleTextBlock_eventGetTextOverflowPolicy_Parms
	{
		ETextOverflowPolicy ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextOverflowPolicy constinit property declarations *****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextOverflowPolicy constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextOverflowPolicy Property Definitions ****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventGetTextOverflowPolicy_Parms, ReturnValue), Z_Construct_UEnum_SlateCore_ETextOverflowPolicy, METADATA_PARAMS(0, nullptr) }; // 1738161579
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::PropPointers) < 2048);
// ********** End Function GetTextOverflowPolicy Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "GetTextOverflowPolicy", 	Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::SubtitleTextBlock_eventGetTextOverflowPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::SubtitleTextBlock_eventGetTextOverflowPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execGetTextOverflowPolicy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ETextOverflowPolicy*)Z_Param__Result=P_THIS->GetTextOverflowPolicy();
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function GetTextOverflowPolicy **************************

// ********** Begin Class USubtitleTextBlock Function GetTextTransformPolicy ***********************
struct Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics
{
	struct SubtitleTextBlock_eventGetTextTransformPolicy_Parms
	{
		ETextTransformPolicy ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextTransformPolicy constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextTransformPolicy constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextTransformPolicy Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventGetTextTransformPolicy_Parms, ReturnValue), Z_Construct_UEnum_SlateCore_ETextTransformPolicy, METADATA_PARAMS(0, nullptr) }; // 2733367800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::PropPointers) < 2048);
// ********** End Function GetTextTransformPolicy Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "GetTextTransformPolicy", 	Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::SubtitleTextBlock_eventGetTextTransformPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::SubtitleTextBlock_eventGetTextTransformPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execGetTextTransformPolicy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ETextTransformPolicy*)Z_Param__Result=P_THIS->GetTextTransformPolicy();
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function GetTextTransformPolicy *************************

// ********** Begin Class USubtitleTextBlock Function SetColorAndOpacity ***************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics
{
	struct SubtitleTextBlock_eventSetColorAndOpacity_Parms
	{
		FSlateColor InColorAndOpacity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetColorAndOpacity constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InColorAndOpacity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetColorAndOpacity constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetColorAndOpacity Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::NewProp_InColorAndOpacity = { "InColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetColorAndOpacity_Parms, InColorAndOpacity), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(0, nullptr) }; // 1663967387
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::NewProp_InColorAndOpacity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetColorAndOpacity Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetColorAndOpacity", 	Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::SubtitleTextBlock_eventSetColorAndOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::SubtitleTextBlock_eventSetColorAndOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetColorAndOpacity)
{
	P_GET_STRUCT(FSlateColor,Z_Param_InColorAndOpacity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetColorAndOpacity(Z_Param_InColorAndOpacity);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetColorAndOpacity *****************************

// ********** Begin Class USubtitleTextBlock Function SetDefaultLineLifetimeSeconds ****************
struct Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics
{
	struct SubtitleTextBlock_eventSetDefaultLineLifetimeSeconds_Parms
	{
		float InDefaultLineLifetimeSeconds;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe9\xbb\x98\xe8\xae\xa4\xe8\xa1\x8c\xe5\xad\x98\xe6\xb4\xbb\xe6\x97\xb6\xe9\x97\xb4\xe7\xa7\x92\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe9\xbb\x98\xe8\xae\xa4\xe8\xa1\x8c\xe5\xad\x98\xe6\xb4\xbb\xe6\x97\xb6\xe9\x97\xb4\xe7\xa7\x92\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetDefaultLineLifetimeSeconds constinit property declarations *********
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InDefaultLineLifetimeSeconds;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDefaultLineLifetimeSeconds constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDefaultLineLifetimeSeconds Property Definitions ********************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::NewProp_InDefaultLineLifetimeSeconds = { "InDefaultLineLifetimeSeconds", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetDefaultLineLifetimeSeconds_Parms, InDefaultLineLifetimeSeconds), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::NewProp_InDefaultLineLifetimeSeconds,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::PropPointers) < 2048);
// ********** End Function SetDefaultLineLifetimeSeconds Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetDefaultLineLifetimeSeconds", 	Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::SubtitleTextBlock_eventSetDefaultLineLifetimeSeconds_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::SubtitleTextBlock_eventSetDefaultLineLifetimeSeconds_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetDefaultLineLifetimeSeconds)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InDefaultLineLifetimeSeconds);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDefaultLineLifetimeSeconds(Z_Param_InDefaultLineLifetimeSeconds);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetDefaultLineLifetimeSeconds ******************

// ********** Begin Class USubtitleTextBlock Function SetFont **************************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics
{
	struct SubtitleTextBlock_eventSetFont_Parms
	{
		FSlateFontInfo InFont;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetFont constinit property declarations *******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InFont;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFont constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFont Property Definitions ******************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::NewProp_InFont = { "InFont", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetFont_Parms, InFont), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(0, nullptr) }; // 167205173
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::NewProp_InFont,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::PropPointers) < 2048);
// ********** End Function SetFont Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetFont", 	Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::SubtitleTextBlock_eventSetFont_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::SubtitleTextBlock_eventSetFont_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetFont()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetFont_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetFont)
{
	P_GET_STRUCT(FSlateFontInfo,Z_Param_InFont);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFont(Z_Param_InFont);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetFont ****************************************

// ********** Begin Class USubtitleTextBlock Function SetGradientLineCount *************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics
{
	struct SubtitleTextBlock_eventSetGradientLineCount_Parms
	{
		int32 InGradientLineCount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\xb8\x90\xe9\x9a\x90\xe8\xa1\x8c\xe6\x95\xb0\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\xb8\x90\xe9\x9a\x90\xe8\xa1\x8c\xe6\x95\xb0\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetGradientLineCount constinit property declarations ******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InGradientLineCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetGradientLineCount constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetGradientLineCount Property Definitions *****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::NewProp_InGradientLineCount = { "InGradientLineCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetGradientLineCount_Parms, InGradientLineCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::NewProp_InGradientLineCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::PropPointers) < 2048);
// ********** End Function SetGradientLineCount Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetGradientLineCount", 	Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::SubtitleTextBlock_eventSetGradientLineCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::SubtitleTextBlock_eventSetGradientLineCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetGradientLineCount)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InGradientLineCount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetGradientLineCount(Z_Param_InGradientLineCount);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetGradientLineCount ***************************

// ********** Begin Class USubtitleTextBlock Function SetLineOpacityStep ***************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics
{
	struct SubtitleTextBlock_eventSetLineOpacityStep_Parms
	{
		float InLineOpacityStep;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe8\xa1\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\xad\xa5\xe9\x95\xbf\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe8\xa1\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\xad\xa5\xe9\x95\xbf\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetLineOpacityStep constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InLineOpacityStep;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLineOpacityStep constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLineOpacityStep Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::NewProp_InLineOpacityStep = { "InLineOpacityStep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetLineOpacityStep_Parms, InLineOpacityStep), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::NewProp_InLineOpacityStep,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::PropPointers) < 2048);
// ********** End Function SetLineOpacityStep Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetLineOpacityStep", 	Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::SubtitleTextBlock_eventSetLineOpacityStep_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::SubtitleTextBlock_eventSetLineOpacityStep_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetLineOpacityStep)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InLineOpacityStep);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLineOpacityStep(Z_Param_InLineOpacityStep);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetLineOpacityStep *****************************

// ********** Begin Class USubtitleTextBlock Function SetLines *************************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics
{
	struct SubtitleTextBlock_eventSetLines_Parms
	{
		TArray<FText> InLines;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe5\xb9\x95\xe8\xa1\x8c\xe9\x9b\x86\xe5\x90\x88\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe5\xb9\x95\xe8\xa1\x8c\xe9\x9b\x86\xe5\x90\x88\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InLines_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetLines constinit property declarations ******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InLines_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InLines;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLines constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLines Property Definitions *****************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::NewProp_InLines_Inner = { "InLines", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::NewProp_InLines = { "InLines", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetLines_Parms, InLines), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InLines_MetaData), NewProp_InLines_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::NewProp_InLines_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::NewProp_InLines,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::PropPointers) < 2048);
// ********** End Function SetLines Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetLines", 	Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::SubtitleTextBlock_eventSetLines_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::SubtitleTextBlock_eventSetLines_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetLines()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetLines_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetLines)
{
	P_GET_TARRAY_REF(FText,Z_Param_Out_InLines);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLines(Z_Param_Out_InLines);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetLines ***************************************

// ********** Begin Class USubtitleTextBlock Function SetMaxDisplayHeight **************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics
{
	struct SubtitleTextBlock_eventSetMaxDisplayHeight_Parms
	{
		float InMaxDisplayHeight;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x9c\x80\xe5\xa4\xa7\xe6\x98\xbe\xe7\xa4\xba\xe9\xab\x98\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x9c\x80\xe5\xa4\xa7\xe6\x98\xbe\xe7\xa4\xba\xe9\xab\x98\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMaxDisplayHeight constinit property declarations *******************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InMaxDisplayHeight;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMaxDisplayHeight constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMaxDisplayHeight Property Definitions ******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::NewProp_InMaxDisplayHeight = { "InMaxDisplayHeight", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetMaxDisplayHeight_Parms, InMaxDisplayHeight), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::NewProp_InMaxDisplayHeight,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::PropPointers) < 2048);
// ********** End Function SetMaxDisplayHeight Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetMaxDisplayHeight", 	Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::SubtitleTextBlock_eventSetMaxDisplayHeight_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::SubtitleTextBlock_eventSetMaxDisplayHeight_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetMaxDisplayHeight)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InMaxDisplayHeight);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMaxDisplayHeight(Z_Param_InMaxDisplayHeight);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetMaxDisplayHeight ****************************

// ********** Begin Class USubtitleTextBlock Function SetMaxStoredLines ****************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics
{
	struct SubtitleTextBlock_eventSetMaxStoredLines_Parms
	{
		int32 InMaxStoredLines;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x9c\x80\xe5\xa4\xa7\xe7\xbc\x93\xe5\xad\x98\xe8\xa1\x8c\xe6\x95\xb0\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x9c\x80\xe5\xa4\xa7\xe7\xbc\x93\xe5\xad\x98\xe8\xa1\x8c\xe6\x95\xb0\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMaxStoredLines constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InMaxStoredLines;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMaxStoredLines constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMaxStoredLines Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::NewProp_InMaxStoredLines = { "InMaxStoredLines", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetMaxStoredLines_Parms, InMaxStoredLines), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::NewProp_InMaxStoredLines,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::PropPointers) < 2048);
// ********** End Function SetMaxStoredLines Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetMaxStoredLines", 	Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::SubtitleTextBlock_eventSetMaxStoredLines_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::SubtitleTextBlock_eventSetMaxStoredLines_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetMaxStoredLines)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InMaxStoredLines);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMaxStoredLines(Z_Param_InMaxStoredLines);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetMaxStoredLines ******************************

// ********** Begin Class USubtitleTextBlock Function SetMinDesiredWidth ***************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics
{
	struct SubtitleTextBlock_eventSetMinDesiredWidth_Parms
	{
		float InMinDesiredWidth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMinDesiredWidth constinit property declarations ********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InMinDesiredWidth;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMinDesiredWidth constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMinDesiredWidth Property Definitions *******************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::NewProp_InMinDesiredWidth = { "InMinDesiredWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetMinDesiredWidth_Parms, InMinDesiredWidth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::NewProp_InMinDesiredWidth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::PropPointers) < 2048);
// ********** End Function SetMinDesiredWidth Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetMinDesiredWidth", 	Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::SubtitleTextBlock_eventSetMinDesiredWidth_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::SubtitleTextBlock_eventSetMinDesiredWidth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetMinDesiredWidth)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InMinDesiredWidth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMinDesiredWidth(Z_Param_InMinDesiredWidth);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetMinDesiredWidth *****************************

// ********** Begin Class USubtitleTextBlock Function SetPauseExpiration ***************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics
{
	struct SubtitleTextBlock_eventSetPauseExpiration_Parms
	{
		bool bInPauseExpiration;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x9a\x82\xe5\x81\x9c\xe8\xbf\x87\xe6\x9c\x9f\xe6\xb8\x85\xe7\x90\x86\xe5\xbc\x80\xe5\x85\xb3\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x9a\x82\xe5\x81\x9c\xe8\xbf\x87\xe6\x9c\x9f\xe6\xb8\x85\xe7\x90\x86\xe5\xbc\x80\xe5\x85\xb3\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetPauseExpiration constinit property declarations ********************
	static void NewProp_bInPauseExpiration_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInPauseExpiration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPauseExpiration constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPauseExpiration Property Definitions *******************************
void Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::NewProp_bInPauseExpiration_SetBit(void* Obj)
{
	((SubtitleTextBlock_eventSetPauseExpiration_Parms*)Obj)->bInPauseExpiration = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::NewProp_bInPauseExpiration = { "bInPauseExpiration", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SubtitleTextBlock_eventSetPauseExpiration_Parms), &Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::NewProp_bInPauseExpiration_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::NewProp_bInPauseExpiration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::PropPointers) < 2048);
// ********** End Function SetPauseExpiration Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetPauseExpiration", 	Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::SubtitleTextBlock_eventSetPauseExpiration_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::SubtitleTextBlock_eventSetPauseExpiration_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetPauseExpiration)
{
	P_GET_UBOOL(Z_Param_bInPauseExpiration);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPauseExpiration(Z_Param_bInPauseExpiration);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetPauseExpiration *****************************

// ********** Begin Class USubtitleTextBlock Function SetShadowColorAndOpacity *********************
struct Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics
{
	struct SubtitleTextBlock_eventSetShadowColorAndOpacity_Parms
	{
		FLinearColor InShadowColorAndOpacity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShadowColorAndOpacity constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InShadowColorAndOpacity;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShadowColorAndOpacity constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShadowColorAndOpacity Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::NewProp_InShadowColorAndOpacity = { "InShadowColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetShadowColorAndOpacity_Parms, InShadowColorAndOpacity), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::NewProp_InShadowColorAndOpacity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetShadowColorAndOpacity Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetShadowColorAndOpacity", 	Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::SubtitleTextBlock_eventSetShadowColorAndOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::SubtitleTextBlock_eventSetShadowColorAndOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetShadowColorAndOpacity)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InShadowColorAndOpacity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShadowColorAndOpacity(Z_Param_InShadowColorAndOpacity);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetShadowColorAndOpacity ***********************

// ********** Begin Class USubtitleTextBlock Function SetShadowOffset ******************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics
{
	struct SubtitleTextBlock_eventSetShadowOffset_Parms
	{
		FVector2D InShadowOffset;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetShadowOffset constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InShadowOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetShadowOffset constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetShadowOffset Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::NewProp_InShadowOffset = { "InShadowOffset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetShadowOffset_Parms, InShadowOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::NewProp_InShadowOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::PropPointers) < 2048);
// ********** End Function SetShadowOffset Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetShadowOffset", 	Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::SubtitleTextBlock_eventSetShadowOffset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::SubtitleTextBlock_eventSetShadowOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetShadowOffset)
{
	P_GET_STRUCT(FVector2D,Z_Param_InShadowOffset);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShadowOffset(Z_Param_InShadowOffset);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetShadowOffset ********************************

// ********** Begin Class USubtitleTextBlock Function SetTailVisibleLineCount **********************
struct Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics
{
	struct SubtitleTextBlock_eventSetTailVisibleLineCount_Parms
	{
		int32 InTailVisibleLineCount;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\xb0\xbe\xe9\x83\xa8\xe5\x8f\xaf\xe8\xa7\x81\xe8\xa1\x8c\xe6\x95\xb0\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\xb0\xbe\xe9\x83\xa8\xe5\x8f\xaf\xe8\xa7\x81\xe8\xa1\x8c\xe6\x95\xb0\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTailVisibleLineCount constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_InTailVisibleLineCount;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTailVisibleLineCount constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTailVisibleLineCount Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::NewProp_InTailVisibleLineCount = { "InTailVisibleLineCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetTailVisibleLineCount_Parms, InTailVisibleLineCount), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::NewProp_InTailVisibleLineCount,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::PropPointers) < 2048);
// ********** End Function SetTailVisibleLineCount Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetTailVisibleLineCount", 	Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::SubtitleTextBlock_eventSetTailVisibleLineCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::SubtitleTextBlock_eventSetTailVisibleLineCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetTailVisibleLineCount)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_InTailVisibleLineCount);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTailVisibleLineCount(Z_Param_InTailVisibleLineCount);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetTailVisibleLineCount ************************

// ********** Begin Class USubtitleTextBlock Function SetText **************************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics
{
	struct SubtitleTextBlock_eventSetText_Parms
	{
		FText InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetText constinit property declarations *******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetText constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetText Property Definitions ******************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetText_Parms, InText), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::PropPointers) < 2048);
// ********** End Function SetText Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetText", 	Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::SubtitleTextBlock_eventSetText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::SubtitleTextBlock_eventSetText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetText)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetText(Z_Param_InText);
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetText ****************************************

// ********** Begin Class USubtitleTextBlock Function SetTextOverflowPolicy ************************
struct Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics
{
	struct SubtitleTextBlock_eventSetTextOverflowPolicy_Parms
	{
		ETextOverflowPolicy InOverflowPolicy;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextOverflowPolicy constinit property declarations *****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InOverflowPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InOverflowPolicy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextOverflowPolicy constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextOverflowPolicy Property Definitions ****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::NewProp_InOverflowPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::NewProp_InOverflowPolicy = { "InOverflowPolicy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetTextOverflowPolicy_Parms, InOverflowPolicy), Z_Construct_UEnum_SlateCore_ETextOverflowPolicy, METADATA_PARAMS(0, nullptr) }; // 1738161579
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::NewProp_InOverflowPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::NewProp_InOverflowPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::PropPointers) < 2048);
// ********** End Function SetTextOverflowPolicy Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetTextOverflowPolicy", 	Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::SubtitleTextBlock_eventSetTextOverflowPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::SubtitleTextBlock_eventSetTextOverflowPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetTextOverflowPolicy)
{
	P_GET_ENUM(ETextOverflowPolicy,Z_Param_InOverflowPolicy);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextOverflowPolicy(ETextOverflowPolicy(Z_Param_InOverflowPolicy));
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetTextOverflowPolicy **************************

// ********** Begin Class USubtitleTextBlock Function SetTextTransformPolicy ***********************
struct Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics
{
	struct SubtitleTextBlock_eventSetTextTransformPolicy_Parms
	{
		ETextTransformPolicy InTransformPolicy;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Subtitle Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextTransformPolicy constinit property declarations ****************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InTransformPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InTransformPolicy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextTransformPolicy constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextTransformPolicy Property Definitions ***************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::NewProp_InTransformPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::NewProp_InTransformPolicy = { "InTransformPolicy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SubtitleTextBlock_eventSetTextTransformPolicy_Parms, InTransformPolicy), Z_Construct_UEnum_SlateCore_ETextTransformPolicy, METADATA_PARAMS(0, nullptr) }; // 2733367800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::NewProp_InTransformPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::NewProp_InTransformPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::PropPointers) < 2048);
// ********** End Function SetTextTransformPolicy Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USubtitleTextBlock, nullptr, "SetTextTransformPolicy", 	Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::SubtitleTextBlock_eventSetTextTransformPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::SubtitleTextBlock_eventSetTextTransformPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USubtitleTextBlock::execSetTextTransformPolicy)
{
	P_GET_ENUM(ETextTransformPolicy,Z_Param_InTransformPolicy);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextTransformPolicy(ETextTransformPolicy(Z_Param_InTransformPolicy));
	P_NATIVE_END;
}
// ********** End Class USubtitleTextBlock Function SetTextTransformPolicy *************************

// ********** Begin Class USubtitleTextBlock *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USubtitleTextBlock;
UClass* USubtitleTextBlock::GetPrivateStaticClass()
{
	using TClass = USubtitleTextBlock;
	if (!Z_Registration_Info_UClass_USubtitleTextBlock.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SubtitleTextBlock"),
			Z_Registration_Info_UClass_USubtitleTextBlock.InnerSingleton,
			StaticRegisterNativesUSubtitleTextBlock,
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
	return Z_Registration_Info_UClass_USubtitleTextBlock.InnerSingleton;
}
UClass* Z_Construct_UClass_USubtitleTextBlock_NoRegister()
{
	return USubtitleTextBlock::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USubtitleTextBlock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe5\xad\x97\xe5\xb9\x95 UMG \xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "Subtitle Text" },
		{ "IncludePath", "UWidget/SubtitleTextBlock.h" },
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe5\xad\x97\xe5\xb9\x95 UMG \xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnLineAdded_MetaData[] = {
		{ "Category", "Subtitle Text" },
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "Category", "Content" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x86\x85\xe5\xae\xb9\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
		{ "MultiLine", "true" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x86\x85\xe5\xae\xb9\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinDesiredWidth_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ColorAndOpacity_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Font_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xad\x97\xe4\xbd\x93\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xad\x97\xe4\xbd\x93\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShadowOffset_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xbb\xe5\x88\xb7\xe7\x9b\xae\xe6\xa0\x87\xe5\xb0\xba\xe5\xaf\xb8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe6\x97\xa0\xe6\xb3\x95\xe8\x87\xaa\xe5\x8a\xa8\xe5\x8c\xb9\xe9\x85\x8d\xe5\xb0\xba\xe5\xaf\xb8\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xbb\xe5\x88\xb7\xe7\x9b\xae\xe6\xa0\x87\xe5\xb0\xba\xe5\xaf\xb8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe6\x97\xa0\xe6\xb3\x95\xe8\x87\xaa\xe5\x8a\xa8\xe5\x8c\xb9\xe9\x85\x8d\xe5\xb0\xba\xe5\xaf\xb8\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShadowColorAndOpacity_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextTransformPolicy_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextOverflowPolicy_MetaData[] = {
		{ "Category", "Clipping" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TailVisibleLineCount_MetaData[] = {
		{ "Category", "Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xb0\xbe\xe9\x83\xa8\xe5\x8f\xaf\xe8\xa7\x81\xe8\xa1\x8c\xe6\x95\xb0\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xb0\xbe\xe9\x83\xa8\xe5\x8f\xaf\xe8\xa7\x81\xe8\xa1\x8c\xe6\x95\xb0\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxDisplayHeight_MetaData[] = {
		{ "Category", "Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7\xe6\x98\xbe\xe7\xa4\xba\xe9\xab\x98\xe5\xba\xa6\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7\xe6\x98\xbe\xe7\xa4\xba\xe9\xab\x98\xe5\xba\xa6\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GradientLineCount_MetaData[] = {
		{ "Category", "Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xb8\x90\xe9\x9a\x90\xe8\xa1\x8c\xe6\x95\xb0\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xb8\x90\xe9\x9a\x90\xe8\xa1\x8c\xe6\x95\xb0\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineOpacityStep_MetaData[] = {
		{ "Category", "Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xa1\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\xad\xa5\xe9\x95\xbf\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xa1\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\xad\xa5\xe9\x95\xbf\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStoredLines_MetaData[] = {
		{ "Category", "Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7\xe7\xbc\x93\xe5\xad\x98\xe8\xa1\x8c\xe6\x95\xb0\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xa4\xa7\xe7\xbc\x93\xe5\xad\x98\xe8\xa1\x8c\xe6\x95\xb0\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultLineLifetimeSeconds_MetaData[] = {
		{ "Category", "Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xbb\x98\xe8\xae\xa4\xe5\xad\x97\xe5\xb9\x95\xe8\xa1\x8c\xe5\xad\x98\xe6\xb4\xbb\xe6\x97\xb6\xe9\x97\xb4\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xbb\x98\xe8\xae\xa4\xe5\xad\x97\xe5\xb9\x95\xe8\xa1\x8c\xe5\xad\x98\xe6\xb4\xbb\xe6\x97\xb6\xe9\x97\xb4\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPauseExpiration_MetaData[] = {
		{ "Category", "Subtitle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xb0\xe5\xbd\x95\xe6\x9a\x82\xe5\x81\x9c\xe8\xbf\x87\xe6\x9c\x9f\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x9c\xa8\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe3\x80\x81\xe5\x90\x8c\xe6\xad\xa5\xe6\x88\x96\xe8\xbe\x93\xe5\x85\xa5\xe6\xb5\x81\xe7\xa8\x8b\xe4\xb8\xad\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SubtitleTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xb0\xe5\xbd\x95\xe6\x9a\x82\xe5\x81\x9c\xe8\xbf\x87\xe6\x9c\x9f\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x9c\xa8\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe3\x80\x81\xe5\x90\x8c\xe6\xad\xa5\xe6\x88\x96\xe8\xbe\x93\xe5\x85\xa5\xe6\xb5\x81\xe7\xa8\x8b\xe4\xb8\xad\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USubtitleTextBlock constinit property declarations ***********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnLineAdded;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinDesiredWidth;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ColorAndOpacity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Font;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShadowOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShadowColorAndOpacity;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TextTransformPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TextTransformPolicy;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TextOverflowPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TextOverflowPolicy;
	static const UECodeGen_Private::FIntPropertyParams NewProp_TailVisibleLineCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxDisplayHeight;
	static const UECodeGen_Private::FIntPropertyParams NewProp_GradientLineCount;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineOpacityStep;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxStoredLines;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultLineLifetimeSeconds;
	static void NewProp_bPauseExpiration_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPauseExpiration;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USubtitleTextBlock constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddText"), .Pointer = &USubtitleTextBlock::execAddText },
		{ .NameUTF8 = UTF8TEXT("AddTextWithLifetime"), .Pointer = &USubtitleTextBlock::execAddTextWithLifetime },
		{ .NameUTF8 = UTF8TEXT("AppendLines"), .Pointer = &USubtitleTextBlock::execAppendLines },
		{ .NameUTF8 = UTF8TEXT("ClearLines"), .Pointer = &USubtitleTextBlock::execClearLines },
		{ .NameUTF8 = UTF8TEXT("GetColorAndOpacity"), .Pointer = &USubtitleTextBlock::execGetColorAndOpacity },
		{ .NameUTF8 = UTF8TEXT("GetFont"), .Pointer = &USubtitleTextBlock::execGetFont },
		{ .NameUTF8 = UTF8TEXT("GetLines"), .Pointer = &USubtitleTextBlock::execGetLines },
		{ .NameUTF8 = UTF8TEXT("GetMinDesiredWidth"), .Pointer = &USubtitleTextBlock::execGetMinDesiredWidth },
		{ .NameUTF8 = UTF8TEXT("GetShadowColorAndOpacity"), .Pointer = &USubtitleTextBlock::execGetShadowColorAndOpacity },
		{ .NameUTF8 = UTF8TEXT("GetShadowOffset"), .Pointer = &USubtitleTextBlock::execGetShadowOffset },
		{ .NameUTF8 = UTF8TEXT("GetText"), .Pointer = &USubtitleTextBlock::execGetText },
		{ .NameUTF8 = UTF8TEXT("GetTextOverflowPolicy"), .Pointer = &USubtitleTextBlock::execGetTextOverflowPolicy },
		{ .NameUTF8 = UTF8TEXT("GetTextTransformPolicy"), .Pointer = &USubtitleTextBlock::execGetTextTransformPolicy },
		{ .NameUTF8 = UTF8TEXT("SetColorAndOpacity"), .Pointer = &USubtitleTextBlock::execSetColorAndOpacity },
		{ .NameUTF8 = UTF8TEXT("SetDefaultLineLifetimeSeconds"), .Pointer = &USubtitleTextBlock::execSetDefaultLineLifetimeSeconds },
		{ .NameUTF8 = UTF8TEXT("SetFont"), .Pointer = &USubtitleTextBlock::execSetFont },
		{ .NameUTF8 = UTF8TEXT("SetGradientLineCount"), .Pointer = &USubtitleTextBlock::execSetGradientLineCount },
		{ .NameUTF8 = UTF8TEXT("SetLineOpacityStep"), .Pointer = &USubtitleTextBlock::execSetLineOpacityStep },
		{ .NameUTF8 = UTF8TEXT("SetLines"), .Pointer = &USubtitleTextBlock::execSetLines },
		{ .NameUTF8 = UTF8TEXT("SetMaxDisplayHeight"), .Pointer = &USubtitleTextBlock::execSetMaxDisplayHeight },
		{ .NameUTF8 = UTF8TEXT("SetMaxStoredLines"), .Pointer = &USubtitleTextBlock::execSetMaxStoredLines },
		{ .NameUTF8 = UTF8TEXT("SetMinDesiredWidth"), .Pointer = &USubtitleTextBlock::execSetMinDesiredWidth },
		{ .NameUTF8 = UTF8TEXT("SetPauseExpiration"), .Pointer = &USubtitleTextBlock::execSetPauseExpiration },
		{ .NameUTF8 = UTF8TEXT("SetShadowColorAndOpacity"), .Pointer = &USubtitleTextBlock::execSetShadowColorAndOpacity },
		{ .NameUTF8 = UTF8TEXT("SetShadowOffset"), .Pointer = &USubtitleTextBlock::execSetShadowOffset },
		{ .NameUTF8 = UTF8TEXT("SetTailVisibleLineCount"), .Pointer = &USubtitleTextBlock::execSetTailVisibleLineCount },
		{ .NameUTF8 = UTF8TEXT("SetText"), .Pointer = &USubtitleTextBlock::execSetText },
		{ .NameUTF8 = UTF8TEXT("SetTextOverflowPolicy"), .Pointer = &USubtitleTextBlock::execSetTextOverflowPolicy },
		{ .NameUTF8 = UTF8TEXT("SetTextTransformPolicy"), .Pointer = &USubtitleTextBlock::execSetTextTransformPolicy },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USubtitleTextBlock_AddText, "AddText" }, // 3317893851
		{ &Z_Construct_UFunction_USubtitleTextBlock_AddTextWithLifetime, "AddTextWithLifetime" }, // 2095429963
		{ &Z_Construct_UFunction_USubtitleTextBlock_AppendLines, "AppendLines" }, // 235479841
		{ &Z_Construct_UFunction_USubtitleTextBlock_ClearLines, "ClearLines" }, // 81879067
		{ &Z_Construct_UFunction_USubtitleTextBlock_GetColorAndOpacity, "GetColorAndOpacity" }, // 537533862
		{ &Z_Construct_UFunction_USubtitleTextBlock_GetFont, "GetFont" }, // 1623377480
		{ &Z_Construct_UFunction_USubtitleTextBlock_GetLines, "GetLines" }, // 1782125644
		{ &Z_Construct_UFunction_USubtitleTextBlock_GetMinDesiredWidth, "GetMinDesiredWidth" }, // 1220640397
		{ &Z_Construct_UFunction_USubtitleTextBlock_GetShadowColorAndOpacity, "GetShadowColorAndOpacity" }, // 2925252251
		{ &Z_Construct_UFunction_USubtitleTextBlock_GetShadowOffset, "GetShadowOffset" }, // 1910331719
		{ &Z_Construct_UFunction_USubtitleTextBlock_GetText, "GetText" }, // 2794476399
		{ &Z_Construct_UFunction_USubtitleTextBlock_GetTextOverflowPolicy, "GetTextOverflowPolicy" }, // 334082961
		{ &Z_Construct_UFunction_USubtitleTextBlock_GetTextTransformPolicy, "GetTextTransformPolicy" }, // 4031182929
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetColorAndOpacity, "SetColorAndOpacity" }, // 2026768267
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetDefaultLineLifetimeSeconds, "SetDefaultLineLifetimeSeconds" }, // 3650756465
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetFont, "SetFont" }, // 2069537118
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetGradientLineCount, "SetGradientLineCount" }, // 731766057
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetLineOpacityStep, "SetLineOpacityStep" }, // 2151904335
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetLines, "SetLines" }, // 32405055
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetMaxDisplayHeight, "SetMaxDisplayHeight" }, // 3224321496
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetMaxStoredLines, "SetMaxStoredLines" }, // 3574326339
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetMinDesiredWidth, "SetMinDesiredWidth" }, // 364798992
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetPauseExpiration, "SetPauseExpiration" }, // 706217924
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetShadowColorAndOpacity, "SetShadowColorAndOpacity" }, // 3728632012
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetShadowOffset, "SetShadowOffset" }, // 4119450384
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetTailVisibleLineCount, "SetTailVisibleLineCount" }, // 563436929
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetText, "SetText" }, // 1728117809
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetTextOverflowPolicy, "SetTextOverflowPolicy" }, // 2380185250
		{ &Z_Construct_UFunction_USubtitleTextBlock_SetTextTransformPolicy, "SetTextTransformPolicy" }, // 1036740862
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USubtitleTextBlock>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USubtitleTextBlock_Statics

// ********** Begin Class USubtitleTextBlock Property Definitions **********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_OnLineAdded = { "OnLineAdded", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, OnLineAdded), Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnLineAdded_MetaData), NewProp_OnLineAdded_MetaData) }; // 3294307335
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_MinDesiredWidth = { "MinDesiredWidth", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, MinDesiredWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinDesiredWidth_MetaData), NewProp_MinDesiredWidth_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_ColorAndOpacity = { "ColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, ColorAndOpacity), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ColorAndOpacity_MetaData), NewProp_ColorAndOpacity_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_Font = { "Font", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, Font), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Font_MetaData), NewProp_Font_MetaData) }; // 167205173
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_ShadowOffset = { "ShadowOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, ShadowOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShadowOffset_MetaData), NewProp_ShadowOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_ShadowColorAndOpacity = { "ShadowColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, ShadowColorAndOpacity), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShadowColorAndOpacity_MetaData), NewProp_ShadowColorAndOpacity_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_TextTransformPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_TextTransformPolicy = { "TextTransformPolicy", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, TextTransformPolicy), Z_Construct_UEnum_SlateCore_ETextTransformPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextTransformPolicy_MetaData), NewProp_TextTransformPolicy_MetaData) }; // 2733367800
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_TextOverflowPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_TextOverflowPolicy = { "TextOverflowPolicy", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, TextOverflowPolicy), Z_Construct_UEnum_SlateCore_ETextOverflowPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextOverflowPolicy_MetaData), NewProp_TextOverflowPolicy_MetaData) }; // 1738161579
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_TailVisibleLineCount = { "TailVisibleLineCount", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, TailVisibleLineCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TailVisibleLineCount_MetaData), NewProp_TailVisibleLineCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_MaxDisplayHeight = { "MaxDisplayHeight", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, MaxDisplayHeight), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxDisplayHeight_MetaData), NewProp_MaxDisplayHeight_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_GradientLineCount = { "GradientLineCount", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, GradientLineCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GradientLineCount_MetaData), NewProp_GradientLineCount_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_LineOpacityStep = { "LineOpacityStep", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, LineOpacityStep), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineOpacityStep_MetaData), NewProp_LineOpacityStep_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_MaxStoredLines = { "MaxStoredLines", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, MaxStoredLines), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStoredLines_MetaData), NewProp_MaxStoredLines_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_DefaultLineLifetimeSeconds = { "DefaultLineLifetimeSeconds", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USubtitleTextBlock, DefaultLineLifetimeSeconds), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultLineLifetimeSeconds_MetaData), NewProp_DefaultLineLifetimeSeconds_MetaData) };
void Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_bPauseExpiration_SetBit(void* Obj)
{
	((USubtitleTextBlock*)Obj)->bPauseExpiration = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_bPauseExpiration = { "bPauseExpiration", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USubtitleTextBlock), &Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_bPauseExpiration_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPauseExpiration_MetaData), NewProp_bPauseExpiration_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USubtitleTextBlock_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_OnLineAdded,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_MinDesiredWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_ColorAndOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_Font,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_ShadowOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_ShadowColorAndOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_TextTransformPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_TextTransformPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_TextOverflowPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_TextOverflowPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_TailVisibleLineCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_MaxDisplayHeight,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_GradientLineCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_LineOpacityStep,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_MaxStoredLines,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_DefaultLineLifetimeSeconds,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USubtitleTextBlock_Statics::NewProp_bPauseExpiration,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USubtitleTextBlock_Statics::PropPointers) < 2048);
// ********** End Class USubtitleTextBlock Property Definitions ************************************
UObject* (*const Z_Construct_UClass_USubtitleTextBlock_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UTextLayoutWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USubtitleTextBlock_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USubtitleTextBlock_Statics::ClassParams = {
	&USubtitleTextBlock::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USubtitleTextBlock_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USubtitleTextBlock_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USubtitleTextBlock_Statics::Class_MetaDataParams), Z_Construct_UClass_USubtitleTextBlock_Statics::Class_MetaDataParams)
};
void USubtitleTextBlock::StaticRegisterNativesUSubtitleTextBlock()
{
	UClass* Class = USubtitleTextBlock::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USubtitleTextBlock_Statics::Funcs));
}
UClass* Z_Construct_UClass_USubtitleTextBlock()
{
	if (!Z_Registration_Info_UClass_USubtitleTextBlock.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USubtitleTextBlock.OuterSingleton, Z_Construct_UClass_USubtitleTextBlock_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USubtitleTextBlock.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USubtitleTextBlock);
USubtitleTextBlock::~USubtitleTextBlock() {}
// ********** End Class USubtitleTextBlock *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h__Script_GenericSlateFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USubtitleTextBlock, USubtitleTextBlock::StaticClass, TEXT("USubtitleTextBlock"), &Z_Registration_Info_UClass_USubtitleTextBlock, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USubtitleTextBlock), 4267229154U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h__Script_GenericSlateFramework_2472109273{
	TEXT("/Script/GenericSlateFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h__Script_GenericSlateFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SubtitleTextBlock_h__Script_GenericSlateFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
