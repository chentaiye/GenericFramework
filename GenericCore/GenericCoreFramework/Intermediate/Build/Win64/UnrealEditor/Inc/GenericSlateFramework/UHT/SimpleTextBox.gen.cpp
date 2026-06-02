// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UWidget/SimpleTextBox.h"
#include "Fonts/SlateFontInfo.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSimpleTextBox() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USimpleTextBox();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USimpleTextBox_NoRegister();
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType();
SLATE_API UEnum* Z_Construct_UEnum_Slate_ETextJustify();
SLATE_API UEnum* Z_Construct_UEnum_Slate_ETextWrappingPolicy();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EHorizontalAlignment();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextOverflowPolicy();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextTransformPolicy();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_EVerticalAlignment();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateColor();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateFontInfo();
UMG_API UClass* Z_Construct_UClass_UWidget();
UMG_API UEnum* Z_Construct_UEnum_UMG_ESlateVisibility();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USimpleTextBox Function GetAutoWrapText **********************************
struct Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics
{
	struct SimpleTextBox_eventGetAutoWrapText_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe8\x87\xaa\xe5\x8a\xa8\xe6\x8d\xa2\xe8\xa1\x8c\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe8\x87\xaa\xe5\x8a\xa8\xe6\x8d\xa2\xe8\xa1\x8c\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAutoWrapText constinit property declarations ***********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAutoWrapText constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAutoWrapText Property Definitions **********************************
void Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SimpleTextBox_eventGetAutoWrapText_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SimpleTextBox_eventGetAutoWrapText_Parms), &Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::PropPointers) < 2048);
// ********** End Function GetAutoWrapText Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetAutoWrapText", 	Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::SimpleTextBox_eventGetAutoWrapText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::SimpleTextBox_eventGetAutoWrapText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetAutoWrapText)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetAutoWrapText();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetAutoWrapText ************************************

// ********** Begin Class USimpleTextBox Function GetHighlightText *********************************
struct Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics
{
	struct SimpleTextBox_eventGetHighlightText_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96Highlight\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96Highlight\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetHighlightText constinit property declarations **********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHighlightText constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHighlightText Property Definitions *********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetHighlightText_Parms, ReturnValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::PropPointers) < 2048);
// ********** End Function GetHighlightText Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetHighlightText", 	Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::SimpleTextBox_eventGetHighlightText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::SimpleTextBox_eventGetHighlightText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetHighlightText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetHighlightText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetHighlightText)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetHighlightText();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetHighlightText ***********************************

// ********** Begin Class USimpleTextBox Function GetImage *****************************************
struct Z_Construct_UFunction_USimpleTextBox_GetImage_Statics
{
	struct SimpleTextBox_eventGetImage_Parms
	{
		FSlateBrush ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetImage constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetImage constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetImage Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetImage_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 4278521822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::PropPointers) < 2048);
// ********** End Function GetImage Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetImage", 	Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::SimpleTextBox_eventGetImage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::SimpleTextBox_eventGetImage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetImage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetImage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetImage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateBrush*)Z_Param__Result=P_THIS->GetImage();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetImage *******************************************

// ********** Begin Class USimpleTextBox Function GetImageColor ************************************
struct Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics
{
	struct SimpleTextBox_eventGetImageColor_Parms
	{
		FSlateColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87""Color\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87""Color\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetImageColor constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetImageColor constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetImageColor Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetImageColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 1663967387
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::PropPointers) < 2048);
// ********** End Function GetImageColor Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetImageColor", 	Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::SimpleTextBox_eventGetImageColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::SimpleTextBox_eventGetImageColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetImageColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetImageColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetImageColor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateColor*)Z_Param__Result=P_THIS->GetImageColor();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetImageColor **************************************

// ********** Begin Class USimpleTextBox Function GetImageHorizontalAlignment **********************
struct Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics
{
	struct SimpleTextBox_eventGetImageHorizontalAlignment_Parms
	{
		TEnumAsByte<EHorizontalAlignment> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetImageHorizontalAlignment constinit property declarations ***********
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetImageHorizontalAlignment constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetImageHorizontalAlignment Property Definitions **********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetImageHorizontalAlignment_Parms, ReturnValue), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(0, nullptr) }; // 990570535
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::PropPointers) < 2048);
// ********** End Function GetImageHorizontalAlignment Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetImageHorizontalAlignment", 	Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::SimpleTextBox_eventGetImageHorizontalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::SimpleTextBox_eventGetImageHorizontalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetImageHorizontalAlignment)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TEnumAsByte<EHorizontalAlignment>*)Z_Param__Result=P_THIS->GetImageHorizontalAlignment();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetImageHorizontalAlignment ************************

// ********** Begin Class USimpleTextBox Function GetImageMargin ***********************************
struct Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics
{
	struct SimpleTextBox_eventGetImageMargin_Parms
	{
		FMargin ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87Margin\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87Margin\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetImageMargin constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetImageMargin constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetImageMargin Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetImageMargin_Parms, ReturnValue), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(0, nullptr) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::PropPointers) < 2048);
// ********** End Function GetImageMargin Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetImageMargin", 	Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::SimpleTextBox_eventGetImageMargin_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::SimpleTextBox_eventGetImageMargin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetImageMargin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetImageMargin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetImageMargin)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FMargin*)Z_Param__Result=P_THIS->GetImageMargin();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetImageMargin *************************************

// ********** Begin Class USimpleTextBox Function GetImageVerticalAlignment ************************
struct Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics
{
	struct SimpleTextBox_eventGetImageVerticalAlignment_Parms
	{
		TEnumAsByte<EVerticalAlignment> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetImageVerticalAlignment constinit property declarations *************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetImageVerticalAlignment constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetImageVerticalAlignment Property Definitions ************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetImageVerticalAlignment_Parms, ReturnValue), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(0, nullptr) }; // 2496106429
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::PropPointers) < 2048);
// ********** End Function GetImageVerticalAlignment Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetImageVerticalAlignment", 	Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::SimpleTextBox_eventGetImageVerticalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::SimpleTextBox_eventGetImageVerticalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetImageVerticalAlignment)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TEnumAsByte<EVerticalAlignment>*)Z_Param__Result=P_THIS->GetImageVerticalAlignment();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetImageVerticalAlignment **************************

// ********** Begin Class USimpleTextBox Function GetImageVisibility *******************************
struct Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics
{
	struct SimpleTextBox_eventGetImageVisibility_Parms
	{
		ESlateVisibility ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87Visibility\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x9b\xbe\xe7\x89\x87Visibility\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetImageVisibility constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetImageVisibility constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetImageVisibility Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetImageVisibility_Parms, ReturnValue), Z_Construct_UEnum_UMG_ESlateVisibility, METADATA_PARAMS(0, nullptr) }; // 763672810
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::PropPointers) < 2048);
// ********** End Function GetImageVisibility Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetImageVisibility", 	Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::SimpleTextBox_eventGetImageVisibility_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::SimpleTextBox_eventGetImageVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetImageVisibility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetImageVisibility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetImageVisibility)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ESlateVisibility*)Z_Param__Result=P_THIS->GetImageVisibility();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetImageVisibility *********************************

// ********** Begin Class USimpleTextBox Function GetJustification *********************************
struct Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics
{
	struct SimpleTextBox_eventGetJustification_Parms
	{
		TEnumAsByte<ETextJustify::Type> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\xaf\xb9\xe9\xbd\x90\xe6\x96\xb9\xe5\xbc\x8f\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\xaf\xb9\xe9\xbd\x90\xe6\x96\xb9\xe5\xbc\x8f\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetJustification constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetJustification constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetJustification Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetJustification_Parms, ReturnValue), Z_Construct_UEnum_Slate_ETextJustify, METADATA_PARAMS(0, nullptr) }; // 2449547307
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::PropPointers) < 2048);
// ********** End Function GetJustification Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetJustification", 	Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::SimpleTextBox_eventGetJustification_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::SimpleTextBox_eventGetJustification_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetJustification()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetJustification_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetJustification)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TEnumAsByte<ETextJustify::Type>*)Z_Param__Result=P_THIS->GetJustification();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetJustification ***********************************

// ********** Begin Class USimpleTextBox Function GetLineHeightPercentage **************************
struct Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics
{
	struct SimpleTextBox_eventGetLineHeightPercentage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe8\xa1\x8cHeight\xe7\x99\xbe\xe5\x88\x86\xe6\xaf\x94\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe8\xa1\x8cHeight\xe7\x99\xbe\xe5\x88\x86\xe6\xaf\x94\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetLineHeightPercentage constinit property declarations ***************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLineHeightPercentage constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLineHeightPercentage Property Definitions **************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetLineHeightPercentage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::PropPointers) < 2048);
// ********** End Function GetLineHeightPercentage Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetLineHeightPercentage", 	Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::SimpleTextBox_eventGetLineHeightPercentage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::SimpleTextBox_eventGetLineHeightPercentage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetLineHeightPercentage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetLineHeightPercentage();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetLineHeightPercentage ****************************

// ********** Begin Class USimpleTextBox Function GetMinDesiredWidth *******************************
struct Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics
{
	struct SimpleTextBox_eventGetMinDesiredWidth_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetMinDesiredWidth_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::PropPointers) < 2048);
// ********** End Function GetMinDesiredWidth Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetMinDesiredWidth", 	Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::SimpleTextBox_eventGetMinDesiredWidth_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::SimpleTextBox_eventGetMinDesiredWidth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetMinDesiredWidth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetMinDesiredWidth();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetMinDesiredWidth *********************************

// ********** Begin Class USimpleTextBox Function GetOverflowPolicy ********************************
struct Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics
{
	struct SimpleTextBox_eventGetOverflowPolicy_Parms
	{
		ETextOverflowPolicy ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetOverflowPolicy constinit property declarations *********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOverflowPolicy constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOverflowPolicy Property Definitions ********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetOverflowPolicy_Parms, ReturnValue), Z_Construct_UEnum_SlateCore_ETextOverflowPolicy, METADATA_PARAMS(0, nullptr) }; // 1738161579
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::PropPointers) < 2048);
// ********** End Function GetOverflowPolicy Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetOverflowPolicy", 	Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::SimpleTextBox_eventGetOverflowPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::SimpleTextBox_eventGetOverflowPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetOverflowPolicy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ETextOverflowPolicy*)Z_Param__Result=P_THIS->GetOverflowPolicy();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetOverflowPolicy **********************************

// ********** Begin Class USimpleTextBox Function GetPadding ***************************************
struct Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics
{
	struct SimpleTextBox_eventGetPadding_Parms
	{
		FMargin ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x86\x85\xe8\xbe\xb9\xe8\xb7\x9d\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x86\x85\xe8\xbe\xb9\xe8\xb7\x9d\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetPadding constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPadding constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPadding Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetPadding_Parms, ReturnValue), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(0, nullptr) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::PropPointers) < 2048);
// ********** End Function GetPadding Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetPadding", 	Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::SimpleTextBox_eventGetPadding_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::SimpleTextBox_eventGetPadding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetPadding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetPadding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetPadding)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FMargin*)Z_Param__Result=P_THIS->GetPadding();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetPadding *****************************************

// ********** Begin Class USimpleTextBox Function GetSimpleTextBoxType *****************************
struct Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics
{
	struct SimpleTextBox_eventGetSimpleTextBoxType_Parms
	{
		ESimpleTextBoxType ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe7\xae\x80\xe5\x8d\x95\xe6\x96\x87\xe6\x9c\xac\xe7\x9b\x92\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe7\xae\x80\xe5\x8d\x95\xe6\x96\x87\xe6\x9c\xac\xe7\x9b\x92\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSimpleTextBoxType constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSimpleTextBoxType constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSimpleTextBoxType Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetSimpleTextBoxType_Parms, ReturnValue), Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType, METADATA_PARAMS(0, nullptr) }; // 1473637242
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::PropPointers) < 2048);
// ********** End Function GetSimpleTextBoxType Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetSimpleTextBoxType", 	Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::SimpleTextBox_eventGetSimpleTextBoxType_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::SimpleTextBox_eventGetSimpleTextBoxType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetSimpleTextBoxType)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ESimpleTextBoxType*)Z_Param__Result=P_THIS->GetSimpleTextBoxType();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetSimpleTextBoxType *******************************

// ********** Begin Class USimpleTextBox Function GetSpace *****************************************
struct Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics
{
	struct SimpleTextBox_eventGetSpace_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Space" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe9\x97\xb4\xe8\xb7\x9d\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe9\x97\xb4\xe8\xb7\x9d\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSpace constinit property declarations ******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSpace constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSpace Property Definitions *****************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetSpace_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::PropPointers) < 2048);
// ********** End Function GetSpace Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetSpace", 	Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::SimpleTextBox_eventGetSpace_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::SimpleTextBox_eventGetSpace_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetSpace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetSpace_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetSpace)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetSpace();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetSpace *******************************************

// ********** Begin Class USimpleTextBox Function GetText ******************************************
struct Z_Construct_UFunction_USimpleTextBox_GetText_Statics
{
	struct SimpleTextBox_eventGetText_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetText constinit property declarations *******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetText constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetText Property Definitions ******************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USimpleTextBox_GetText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetText_Parms, ReturnValue), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetText_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetText_Statics::PropPointers) < 2048);
// ********** End Function GetText Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetText", 	Z_Construct_UFunction_USimpleTextBox_GetText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetText_Statics::SimpleTextBox_eventGetText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetText_Statics::SimpleTextBox_eventGetText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetText)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetText();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetText ********************************************

// ********** Begin Class USimpleTextBox Function GetTextColor *************************************
struct Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics
{
	struct SimpleTextBox_eventGetTextColor_Parms
	{
		FSlateColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe9\xa2\x9c\xe8\x89\xb2\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe9\xa2\x9c\xe8\x89\xb2\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextColor constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextColor constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextColor Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetTextColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 1663967387
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::PropPointers) < 2048);
// ********** End Function GetTextColor Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetTextColor", 	Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::SimpleTextBox_eventGetTextColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::SimpleTextBox_eventGetTextColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetTextColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetTextColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetTextColor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateColor*)Z_Param__Result=P_THIS->GetTextColor();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetTextColor ***************************************

// ********** Begin Class USimpleTextBox Function GetTextFont **************************************
struct Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics
{
	struct SimpleTextBox_eventGetTextFont_Parms
	{
		FSlateFontInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextFont constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextFont constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextFont Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetTextFont_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 167205173
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::PropPointers) < 2048);
// ********** End Function GetTextFont Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetTextFont", 	Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::SimpleTextBox_eventGetTextFont_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::SimpleTextBox_eventGetTextFont_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetTextFont()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetTextFont_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetTextFont)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateFontInfo*)Z_Param__Result=P_THIS->GetTextFont();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetTextFont ****************************************

// ********** Begin Class USimpleTextBox Function GetTextHighlightShape ****************************
struct Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics
{
	struct SimpleTextBox_eventGetTextHighlightShape_Parms
	{
		FSlateBrush ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xacHighlightShape\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xacHighlightShape\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextHighlightShape constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextHighlightShape constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextHighlightShape Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetTextHighlightShape_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 4278521822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::PropPointers) < 2048);
// ********** End Function GetTextHighlightShape Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetTextHighlightShape", 	Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::SimpleTextBox_eventGetTextHighlightShape_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::SimpleTextBox_eventGetTextHighlightShape_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetTextHighlightShape)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateBrush*)Z_Param__Result=P_THIS->GetTextHighlightShape();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetTextHighlightShape ******************************

// ********** Begin Class USimpleTextBox Function GetTextHorizontalAlignment ***********************
struct Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics
{
	struct SimpleTextBox_eventGetTextHorizontalAlignment_Parms
	{
		TEnumAsByte<EHorizontalAlignment> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextHorizontalAlignment constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextHorizontalAlignment constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextHorizontalAlignment Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetTextHorizontalAlignment_Parms, ReturnValue), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(0, nullptr) }; // 990570535
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::PropPointers) < 2048);
// ********** End Function GetTextHorizontalAlignment Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetTextHorizontalAlignment", 	Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::SimpleTextBox_eventGetTextHorizontalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::SimpleTextBox_eventGetTextHorizontalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetTextHorizontalAlignment)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TEnumAsByte<EHorizontalAlignment>*)Z_Param__Result=P_THIS->GetTextHorizontalAlignment();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetTextHorizontalAlignment *************************

// ********** Begin Class USimpleTextBox Function GetTextMargin ************************************
struct Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics
{
	struct SimpleTextBox_eventGetTextMargin_Parms
	{
		FMargin ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe8\xbe\xb9\xe8\xb7\x9d\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe8\xbe\xb9\xe8\xb7\x9d\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextMargin constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextMargin constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextMargin Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetTextMargin_Parms, ReturnValue), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(0, nullptr) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::PropPointers) < 2048);
// ********** End Function GetTextMargin Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetTextMargin", 	Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::SimpleTextBox_eventGetTextMargin_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::SimpleTextBox_eventGetTextMargin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetTextMargin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetTextMargin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetTextMargin)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FMargin*)Z_Param__Result=P_THIS->GetTextMargin();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetTextMargin **************************************

// ********** Begin Class USimpleTextBox Function GetTextShadowColor *******************************
struct Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics
{
	struct SimpleTextBox_eventGetTextShadowColor_Parms
	{
		FLinearColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextShadowColor constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextShadowColor constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextShadowColor Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetTextShadowColor_Parms, ReturnValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::PropPointers) < 2048);
// ********** End Function GetTextShadowColor Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetTextShadowColor", 	Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::SimpleTextBox_eventGetTextShadowColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::SimpleTextBox_eventGetTextShadowColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetTextShadowColor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLinearColor*)Z_Param__Result=P_THIS->GetTextShadowColor();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetTextShadowColor *********************************

// ********** Begin Class USimpleTextBox Function GetTextShadowOffset ******************************
struct Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics
{
	struct SimpleTextBox_eventGetTextShadowOffset_Parms
	{
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextShadowOffset constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextShadowOffset constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextShadowOffset Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetTextShadowOffset_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::PropPointers) < 2048);
// ********** End Function GetTextShadowOffset Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetTextShadowOffset", 	Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::SimpleTextBox_eventGetTextShadowOffset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::SimpleTextBox_eventGetTextShadowOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetTextShadowOffset)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=P_THIS->GetTextShadowOffset();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetTextShadowOffset ********************************

// ********** Begin Class USimpleTextBox Function GetTextStrikeBrush *******************************
struct Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics
{
	struct SimpleTextBox_eventGetTextStrikeBrush_Parms
	{
		FSlateBrush ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextStrikeBrush constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextStrikeBrush constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextStrikeBrush Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetTextStrikeBrush_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 4278521822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::PropPointers) < 2048);
// ********** End Function GetTextStrikeBrush Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetTextStrikeBrush", 	Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::SimpleTextBox_eventGetTextStrikeBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::SimpleTextBox_eventGetTextStrikeBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetTextStrikeBrush)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateBrush*)Z_Param__Result=P_THIS->GetTextStrikeBrush();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetTextStrikeBrush *********************************

// ********** Begin Class USimpleTextBox Function GetTextVerticalAlignment *************************
struct Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics
{
	struct SimpleTextBox_eventGetTextVerticalAlignment_Parms
	{
		TEnumAsByte<EVerticalAlignment> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTextVerticalAlignment constinit property declarations **************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTextVerticalAlignment constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTextVerticalAlignment Property Definitions *************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetTextVerticalAlignment_Parms, ReturnValue), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(0, nullptr) }; // 2496106429
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::PropPointers) < 2048);
// ********** End Function GetTextVerticalAlignment Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetTextVerticalAlignment", 	Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::SimpleTextBox_eventGetTextVerticalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::SimpleTextBox_eventGetTextVerticalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetTextVerticalAlignment)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TEnumAsByte<EVerticalAlignment>*)Z_Param__Result=P_THIS->GetTextVerticalAlignment();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetTextVerticalAlignment ***************************

// ********** Begin Class USimpleTextBox Function GetTransformPolicy *******************************
struct Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics
{
	struct SimpleTextBox_eventGetTransformPolicy_Parms
	{
		ETextTransformPolicy ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTransformPolicy constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTransformPolicy constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTransformPolicy Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetTransformPolicy_Parms, ReturnValue), Z_Construct_UEnum_SlateCore_ETextTransformPolicy, METADATA_PARAMS(0, nullptr) }; // 2733367800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::PropPointers) < 2048);
// ********** End Function GetTransformPolicy Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetTransformPolicy", 	Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::SimpleTextBox_eventGetTransformPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::SimpleTextBox_eventGetTransformPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetTransformPolicy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ETextTransformPolicy*)Z_Param__Result=P_THIS->GetTransformPolicy();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetTransformPolicy *********************************

// ********** Begin Class USimpleTextBox Function GetWrappingPolicy ********************************
struct Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics
{
	struct SimpleTextBox_eventGetWrappingPolicy_Parms
	{
		ETextWrappingPolicy ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x8d\xa2\xe8\xa1\x8cPolicy\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x8d\xa2\xe8\xa1\x8cPolicy\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetWrappingPolicy constinit property declarations *********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWrappingPolicy constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWrappingPolicy Property Definitions ********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetWrappingPolicy_Parms, ReturnValue), Z_Construct_UEnum_Slate_ETextWrappingPolicy, METADATA_PARAMS(0, nullptr) }; // 3831279660
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::PropPointers) < 2048);
// ********** End Function GetWrappingPolicy Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetWrappingPolicy", 	Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::SimpleTextBox_eventGetWrappingPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::SimpleTextBox_eventGetWrappingPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetWrappingPolicy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ETextWrappingPolicy*)Z_Param__Result=P_THIS->GetWrappingPolicy();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetWrappingPolicy **********************************

// ********** Begin Class USimpleTextBox Function GetWrapTextAt ************************************
struct Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics
{
	struct SimpleTextBox_eventGetWrapTextAt_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x8d\xa2\xe8\xa1\x8c\xe6\x96\x87\xe6\x9c\xac\xe4\xbd\x8d\xe7\xbd\xae\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x8d\xa2\xe8\xa1\x8c\xe6\x96\x87\xe6\x9c\xac\xe4\xbd\x8d\xe7\xbd\xae\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetWrapTextAt constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWrapTextAt constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWrapTextAt Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventGetWrapTextAt_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::PropPointers) < 2048);
// ********** End Function GetWrapTextAt Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "GetWrapTextAt", 	Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::SimpleTextBox_eventGetWrapTextAt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::SimpleTextBox_eventGetWrapTextAt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execGetWrapTextAt)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetWrapTextAt();
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function GetWrapTextAt **************************************

// ********** Begin Class USimpleTextBox Function SetAutoWrapText **********************************
struct Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics
{
	struct SimpleTextBox_eventSetAutoWrapText_Parms
	{
		bool InAutoWrapText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe8\x87\xaa\xe5\x8a\xa8\xe6\x8d\xa2\xe8\xa1\x8c\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe8\x87\xaa\xe5\x8a\xa8\xe6\x8d\xa2\xe8\xa1\x8c\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetAutoWrapText constinit property declarations ***********************
	static void NewProp_InAutoWrapText_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_InAutoWrapText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAutoWrapText constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAutoWrapText Property Definitions **********************************
void Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::NewProp_InAutoWrapText_SetBit(void* Obj)
{
	((SimpleTextBox_eventSetAutoWrapText_Parms*)Obj)->InAutoWrapText = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::NewProp_InAutoWrapText = { "InAutoWrapText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SimpleTextBox_eventSetAutoWrapText_Parms), &Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::NewProp_InAutoWrapText_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::NewProp_InAutoWrapText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::PropPointers) < 2048);
// ********** End Function SetAutoWrapText Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetAutoWrapText", 	Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::SimpleTextBox_eventSetAutoWrapText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::SimpleTextBox_eventSetAutoWrapText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetAutoWrapText)
{
	P_GET_UBOOL(Z_Param_InAutoWrapText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetAutoWrapText(Z_Param_InAutoWrapText);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetAutoWrapText ************************************

// ********** Begin Class USimpleTextBox Function SetHighlightText *********************************
struct Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics
{
	struct SimpleTextBox_eventSetHighlightText_Parms
	{
		FText InHighlightText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5Highlight\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5Highlight\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InHighlightText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetHighlightText constinit property declarations **********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InHighlightText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetHighlightText constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetHighlightText Property Definitions *********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::NewProp_InHighlightText = { "InHighlightText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetHighlightText_Parms, InHighlightText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InHighlightText_MetaData), NewProp_InHighlightText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::NewProp_InHighlightText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::PropPointers) < 2048);
// ********** End Function SetHighlightText Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetHighlightText", 	Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::SimpleTextBox_eventSetHighlightText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::SimpleTextBox_eventSetHighlightText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetHighlightText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetHighlightText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetHighlightText)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InHighlightText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHighlightText(Z_Param_Out_InHighlightText);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetHighlightText ***********************************

// ********** Begin Class USimpleTextBox Function SetImage *****************************************
struct Z_Construct_UFunction_USimpleTextBox_SetImage_Statics
{
	struct SimpleTextBox_eventSetImage_Parms
	{
		FSlateBrush InImage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InImage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetImage constinit property declarations ******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InImage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetImage constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetImage Property Definitions *****************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::NewProp_InImage = { "InImage", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetImage_Parms, InImage), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InImage_MetaData), NewProp_InImage_MetaData) }; // 4278521822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::NewProp_InImage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::PropPointers) < 2048);
// ********** End Function SetImage Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetImage", 	Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::SimpleTextBox_eventSetImage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::SimpleTextBox_eventSetImage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetImage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetImage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetImage)
{
	P_GET_STRUCT_REF(FSlateBrush,Z_Param_Out_InImage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetImage(Z_Param_Out_InImage);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetImage *******************************************

// ********** Begin Class USimpleTextBox Function SetImageColor ************************************
struct Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics
{
	struct SimpleTextBox_eventSetImageColor_Parms
	{
		FSlateColor InImageColor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87""Color\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87""Color\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InImageColor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetImageColor constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InImageColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetImageColor constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetImageColor Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::NewProp_InImageColor = { "InImageColor", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetImageColor_Parms, InImageColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InImageColor_MetaData), NewProp_InImageColor_MetaData) }; // 1663967387
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::NewProp_InImageColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::PropPointers) < 2048);
// ********** End Function SetImageColor Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetImageColor", 	Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::SimpleTextBox_eventSetImageColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::SimpleTextBox_eventSetImageColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetImageColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetImageColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetImageColor)
{
	P_GET_STRUCT_REF(FSlateColor,Z_Param_Out_InImageColor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetImageColor(Z_Param_Out_InImageColor);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetImageColor **************************************

// ********** Begin Class USimpleTextBox Function SetImageHorizontalAlignment **********************
struct Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics
{
	struct SimpleTextBox_eventSetImageHorizontalAlignment_Parms
	{
		TEnumAsByte<EHorizontalAlignment> InImageHorizontalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetImageHorizontalAlignment constinit property declarations ***********
	static const UECodeGen_Private::FBytePropertyParams NewProp_InImageHorizontalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetImageHorizontalAlignment constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetImageHorizontalAlignment Property Definitions **********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::NewProp_InImageHorizontalAlignment = { "InImageHorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetImageHorizontalAlignment_Parms, InImageHorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(0, nullptr) }; // 990570535
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::NewProp_InImageHorizontalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::PropPointers) < 2048);
// ********** End Function SetImageHorizontalAlignment Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetImageHorizontalAlignment", 	Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::SimpleTextBox_eventSetImageHorizontalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::SimpleTextBox_eventSetImageHorizontalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetImageHorizontalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InImageHorizontalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetImageHorizontalAlignment(EHorizontalAlignment(Z_Param_InImageHorizontalAlignment));
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetImageHorizontalAlignment ************************

// ********** Begin Class USimpleTextBox Function SetImageMargin ***********************************
struct Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics
{
	struct SimpleTextBox_eventSetImageMargin_Parms
	{
		FMargin InImageMargin;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87Margin\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87Margin\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InImageMargin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetImageMargin constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InImageMargin;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetImageMargin constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetImageMargin Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::NewProp_InImageMargin = { "InImageMargin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetImageMargin_Parms, InImageMargin), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InImageMargin_MetaData), NewProp_InImageMargin_MetaData) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::NewProp_InImageMargin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::PropPointers) < 2048);
// ********** End Function SetImageMargin Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetImageMargin", 	Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::SimpleTextBox_eventSetImageMargin_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::SimpleTextBox_eventSetImageMargin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetImageMargin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetImageMargin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetImageMargin)
{
	P_GET_STRUCT_REF(FMargin,Z_Param_Out_InImageMargin);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetImageMargin(Z_Param_Out_InImageMargin);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetImageMargin *************************************

// ********** Begin Class USimpleTextBox Function SetImageVerticalAlignment ************************
struct Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics
{
	struct SimpleTextBox_eventSetImageVerticalAlignment_Parms
	{
		TEnumAsByte<EVerticalAlignment> InImageVerticalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetImageVerticalAlignment constinit property declarations *************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InImageVerticalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetImageVerticalAlignment constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetImageVerticalAlignment Property Definitions ************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::NewProp_InImageVerticalAlignment = { "InImageVerticalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetImageVerticalAlignment_Parms, InImageVerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(0, nullptr) }; // 2496106429
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::NewProp_InImageVerticalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::PropPointers) < 2048);
// ********** End Function SetImageVerticalAlignment Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetImageVerticalAlignment", 	Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::SimpleTextBox_eventSetImageVerticalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::SimpleTextBox_eventSetImageVerticalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetImageVerticalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InImageVerticalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetImageVerticalAlignment(EVerticalAlignment(Z_Param_InImageVerticalAlignment));
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetImageVerticalAlignment **************************

// ********** Begin Class USimpleTextBox Function SetImageVisibility *******************************
struct Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics
{
	struct SimpleTextBox_eventSetImageVisibility_Parms
	{
		ESlateVisibility InImageVisibility;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87Visibility\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x9b\xbe\xe7\x89\x87Visibility\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetImageVisibility constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InImageVisibility_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InImageVisibility;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetImageVisibility constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetImageVisibility Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::NewProp_InImageVisibility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::NewProp_InImageVisibility = { "InImageVisibility", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetImageVisibility_Parms, InImageVisibility), Z_Construct_UEnum_UMG_ESlateVisibility, METADATA_PARAMS(0, nullptr) }; // 763672810
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::NewProp_InImageVisibility_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::NewProp_InImageVisibility,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::PropPointers) < 2048);
// ********** End Function SetImageVisibility Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetImageVisibility", 	Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::SimpleTextBox_eventSetImageVisibility_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::SimpleTextBox_eventSetImageVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetImageVisibility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetImageVisibility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetImageVisibility)
{
	P_GET_ENUM(ESlateVisibility,Z_Param_InImageVisibility);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetImageVisibility(ESlateVisibility(Z_Param_InImageVisibility));
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetImageVisibility *********************************

// ********** Begin Class USimpleTextBox Function SetJustification *********************************
struct Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics
{
	struct SimpleTextBox_eventSetJustification_Parms
	{
		TEnumAsByte<ETextJustify::Type> InJustification;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\xaf\xb9\xe9\xbd\x90\xe6\x96\xb9\xe5\xbc\x8f\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\xaf\xb9\xe9\xbd\x90\xe6\x96\xb9\xe5\xbc\x8f\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetJustification constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InJustification;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetJustification constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetJustification Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::NewProp_InJustification = { "InJustification", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetJustification_Parms, InJustification), Z_Construct_UEnum_Slate_ETextJustify, METADATA_PARAMS(0, nullptr) }; // 2449547307
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::NewProp_InJustification,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::PropPointers) < 2048);
// ********** End Function SetJustification Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetJustification", 	Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::SimpleTextBox_eventSetJustification_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::SimpleTextBox_eventSetJustification_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetJustification()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetJustification_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetJustification)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InJustification);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetJustification(ETextJustify::Type(Z_Param_InJustification));
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetJustification ***********************************

// ********** Begin Class USimpleTextBox Function SetLineHeightPercentage **************************
struct Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics
{
	struct SimpleTextBox_eventSetLineHeightPercentage_Parms
	{
		float InLineHeightPercentage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe8\xa1\x8cHeight\xe7\x99\xbe\xe5\x88\x86\xe6\xaf\x94\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe8\xa1\x8cHeight\xe7\x99\xbe\xe5\x88\x86\xe6\xaf\x94\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetLineHeightPercentage constinit property declarations ***************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InLineHeightPercentage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetLineHeightPercentage constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetLineHeightPercentage Property Definitions **************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::NewProp_InLineHeightPercentage = { "InLineHeightPercentage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetLineHeightPercentage_Parms, InLineHeightPercentage), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::NewProp_InLineHeightPercentage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::PropPointers) < 2048);
// ********** End Function SetLineHeightPercentage Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetLineHeightPercentage", 	Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::SimpleTextBox_eventSetLineHeightPercentage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::SimpleTextBox_eventSetLineHeightPercentage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetLineHeightPercentage)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InLineHeightPercentage);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetLineHeightPercentage(Z_Param_InLineHeightPercentage);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetLineHeightPercentage ****************************

// ********** Begin Class USimpleTextBox Function SetMinDesiredWidth *******************************
struct Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics
{
	struct SimpleTextBox_eventSetMinDesiredWidth_Parms
	{
		float InMinDesiredWidth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::NewProp_InMinDesiredWidth = { "InMinDesiredWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetMinDesiredWidth_Parms, InMinDesiredWidth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::NewProp_InMinDesiredWidth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::PropPointers) < 2048);
// ********** End Function SetMinDesiredWidth Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetMinDesiredWidth", 	Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::SimpleTextBox_eventSetMinDesiredWidth_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::SimpleTextBox_eventSetMinDesiredWidth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetMinDesiredWidth)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InMinDesiredWidth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMinDesiredWidth(Z_Param_InMinDesiredWidth);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetMinDesiredWidth *********************************

// ********** Begin Class USimpleTextBox Function SetOverflowPolicy ********************************
struct Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics
{
	struct SimpleTextBox_eventSetOverflowPolicy_Parms
	{
		ETextOverflowPolicy InOverflowPolicy;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetOverflowPolicy constinit property declarations *********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InOverflowPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InOverflowPolicy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetOverflowPolicy constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetOverflowPolicy Property Definitions ********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::NewProp_InOverflowPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::NewProp_InOverflowPolicy = { "InOverflowPolicy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetOverflowPolicy_Parms, InOverflowPolicy), Z_Construct_UEnum_SlateCore_ETextOverflowPolicy, METADATA_PARAMS(0, nullptr) }; // 1738161579
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::NewProp_InOverflowPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::NewProp_InOverflowPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::PropPointers) < 2048);
// ********** End Function SetOverflowPolicy Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetOverflowPolicy", 	Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::SimpleTextBox_eventSetOverflowPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::SimpleTextBox_eventSetOverflowPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetOverflowPolicy)
{
	P_GET_ENUM(ETextOverflowPolicy,Z_Param_InOverflowPolicy);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetOverflowPolicy(ETextOverflowPolicy(Z_Param_InOverflowPolicy));
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetOverflowPolicy **********************************

// ********** Begin Class USimpleTextBox Function SetPadding ***************************************
struct Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics
{
	struct SimpleTextBox_eventSetPadding_Parms
	{
		FMargin InPadding;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x86\x85\xe8\xbe\xb9\xe8\xb7\x9d\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x86\x85\xe8\xbe\xb9\xe8\xb7\x9d\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPadding_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetPadding constinit property declarations ****************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InPadding;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetPadding constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetPadding Property Definitions ***************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::NewProp_InPadding = { "InPadding", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetPadding_Parms, InPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPadding_MetaData), NewProp_InPadding_MetaData) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::NewProp_InPadding,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::PropPointers) < 2048);
// ********** End Function SetPadding Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetPadding", 	Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::SimpleTextBox_eventSetPadding_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::SimpleTextBox_eventSetPadding_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetPadding()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetPadding_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetPadding)
{
	P_GET_STRUCT_REF(FMargin,Z_Param_Out_InPadding);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetPadding(Z_Param_Out_InPadding);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetPadding *****************************************

// ********** Begin Class USimpleTextBox Function SetSimpleTextBoxType *****************************
struct Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics
{
	struct SimpleTextBox_eventSetSimpleTextBoxType_Parms
	{
		ESimpleTextBoxType InSimpleTextBoxType;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe7\xae\x80\xe5\x8d\x95\xe6\x96\x87\xe6\x9c\xac\xe7\x9b\x92\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe7\xae\x80\xe5\x8d\x95\xe6\x96\x87\xe6\x9c\xac\xe7\x9b\x92\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSimpleTextBoxType constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InSimpleTextBoxType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InSimpleTextBoxType;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSimpleTextBoxType constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSimpleTextBoxType Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::NewProp_InSimpleTextBoxType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::NewProp_InSimpleTextBoxType = { "InSimpleTextBoxType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetSimpleTextBoxType_Parms, InSimpleTextBoxType), Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType, METADATA_PARAMS(0, nullptr) }; // 1473637242
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::NewProp_InSimpleTextBoxType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::NewProp_InSimpleTextBoxType,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::PropPointers) < 2048);
// ********** End Function SetSimpleTextBoxType Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetSimpleTextBoxType", 	Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::SimpleTextBox_eventSetSimpleTextBoxType_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::SimpleTextBox_eventSetSimpleTextBoxType_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetSimpleTextBoxType)
{
	P_GET_ENUM(ESimpleTextBoxType,Z_Param_InSimpleTextBoxType);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSimpleTextBoxType(ESimpleTextBoxType(Z_Param_InSimpleTextBoxType));
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetSimpleTextBoxType *******************************

// ********** Begin Class USimpleTextBox Function SetSpace *****************************************
struct Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics
{
	struct SimpleTextBox_eventSetSpace_Parms
	{
		float InSpace;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Space" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe9\x97\xb4\xe8\xb7\x9d\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe9\x97\xb4\xe8\xb7\x9d\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSpace constinit property declarations ******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InSpace;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSpace constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSpace Property Definitions *****************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::NewProp_InSpace = { "InSpace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetSpace_Parms, InSpace), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::NewProp_InSpace,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::PropPointers) < 2048);
// ********** End Function SetSpace Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetSpace", 	Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::SimpleTextBox_eventSetSpace_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::SimpleTextBox_eventSetSpace_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetSpace()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetSpace_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetSpace)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InSpace);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSpace(Z_Param_InSpace);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetSpace *******************************************

// ********** Begin Class USimpleTextBox Function SetText ******************************************
struct Z_Construct_UFunction_USimpleTextBox_SetText_Statics
{
	struct SimpleTextBox_eventSetText_Parms
	{
		FText InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetText constinit property declarations *******************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetText constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetText Property Definitions ******************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USimpleTextBox_SetText_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetText_Parms, InText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InText_MetaData), NewProp_InText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetText_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetText_Statics::PropPointers) < 2048);
// ********** End Function SetText Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetText", 	Z_Construct_UFunction_USimpleTextBox_SetText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetText_Statics::SimpleTextBox_eventSetText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetText_Statics::SimpleTextBox_eventSetText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetText)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetText(Z_Param_Out_InText);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetText ********************************************

// ********** Begin Class USimpleTextBox Function SetTextColor *************************************
struct Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics
{
	struct SimpleTextBox_eventSetTextColor_Parms
	{
		FSlateColor InTextColor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe9\xa2\x9c\xe8\x89\xb2\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe9\xa2\x9c\xe8\x89\xb2\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTextColor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextColor constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTextColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextColor constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextColor Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::NewProp_InTextColor = { "InTextColor", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetTextColor_Parms, InTextColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTextColor_MetaData), NewProp_InTextColor_MetaData) }; // 1663967387
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::NewProp_InTextColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::PropPointers) < 2048);
// ********** End Function SetTextColor Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetTextColor", 	Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::SimpleTextBox_eventSetTextColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::SimpleTextBox_eventSetTextColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetTextColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetTextColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetTextColor)
{
	P_GET_STRUCT_REF(FSlateColor,Z_Param_Out_InTextColor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextColor(Z_Param_Out_InTextColor);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetTextColor ***************************************

// ********** Begin Class USimpleTextBox Function SetTextFont **************************************
struct Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics
{
	struct SimpleTextBox_eventSetTextFont_Parms
	{
		FSlateFontInfo InTextFont;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTextFont_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextFont constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTextFont;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextFont constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextFont Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::NewProp_InTextFont = { "InTextFont", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetTextFont_Parms, InTextFont), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTextFont_MetaData), NewProp_InTextFont_MetaData) }; // 167205173
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::NewProp_InTextFont,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::PropPointers) < 2048);
// ********** End Function SetTextFont Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetTextFont", 	Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::SimpleTextBox_eventSetTextFont_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::SimpleTextBox_eventSetTextFont_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetTextFont()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetTextFont_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetTextFont)
{
	P_GET_STRUCT_REF(FSlateFontInfo,Z_Param_Out_InTextFont);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextFont(Z_Param_Out_InTextFont);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetTextFont ****************************************

// ********** Begin Class USimpleTextBox Function SetTextHighlightShape ****************************
struct Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics
{
	struct SimpleTextBox_eventSetTextHighlightShape_Parms
	{
		FSlateBrush InTextHighlightShape;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xacHighlightShape\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xacHighlightShape\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTextHighlightShape_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextHighlightShape constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTextHighlightShape;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextHighlightShape constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextHighlightShape Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::NewProp_InTextHighlightShape = { "InTextHighlightShape", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetTextHighlightShape_Parms, InTextHighlightShape), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTextHighlightShape_MetaData), NewProp_InTextHighlightShape_MetaData) }; // 4278521822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::NewProp_InTextHighlightShape,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::PropPointers) < 2048);
// ********** End Function SetTextHighlightShape Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetTextHighlightShape", 	Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::SimpleTextBox_eventSetTextHighlightShape_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::SimpleTextBox_eventSetTextHighlightShape_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetTextHighlightShape)
{
	P_GET_STRUCT_REF(FSlateBrush,Z_Param_Out_InTextHighlightShape);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextHighlightShape(Z_Param_Out_InTextHighlightShape);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetTextHighlightShape ******************************

// ********** Begin Class USimpleTextBox Function SetTextHorizontalAlignment ***********************
struct Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics
{
	struct SimpleTextBox_eventSetTextHorizontalAlignment_Parms
	{
		TEnumAsByte<EHorizontalAlignment> InTextHorizontalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextHorizontalAlignment constinit property declarations ************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InTextHorizontalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextHorizontalAlignment constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextHorizontalAlignment Property Definitions ***********************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::NewProp_InTextHorizontalAlignment = { "InTextHorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetTextHorizontalAlignment_Parms, InTextHorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(0, nullptr) }; // 990570535
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::NewProp_InTextHorizontalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::PropPointers) < 2048);
// ********** End Function SetTextHorizontalAlignment Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetTextHorizontalAlignment", 	Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::SimpleTextBox_eventSetTextHorizontalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::SimpleTextBox_eventSetTextHorizontalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetTextHorizontalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InTextHorizontalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextHorizontalAlignment(EHorizontalAlignment(Z_Param_InTextHorizontalAlignment));
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetTextHorizontalAlignment *************************

// ********** Begin Class USimpleTextBox Function SetTextMargin ************************************
struct Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics
{
	struct SimpleTextBox_eventSetTextMargin_Parms
	{
		FMargin InTextMargin;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe8\xbe\xb9\xe8\xb7\x9d\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe8\xbe\xb9\xe8\xb7\x9d\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTextMargin_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextMargin constinit property declarations *************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTextMargin;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextMargin constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextMargin Property Definitions ************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::NewProp_InTextMargin = { "InTextMargin", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetTextMargin_Parms, InTextMargin), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTextMargin_MetaData), NewProp_InTextMargin_MetaData) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::NewProp_InTextMargin,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::PropPointers) < 2048);
// ********** End Function SetTextMargin Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetTextMargin", 	Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::SimpleTextBox_eventSetTextMargin_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::SimpleTextBox_eventSetTextMargin_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetTextMargin()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetTextMargin_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetTextMargin)
{
	P_GET_STRUCT_REF(FMargin,Z_Param_Out_InTextMargin);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextMargin(Z_Param_Out_InTextMargin);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetTextMargin **************************************

// ********** Begin Class USimpleTextBox Function SetTextShadowColor *******************************
struct Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics
{
	struct SimpleTextBox_eventSetTextShadowColor_Parms
	{
		FLinearColor InTextShadowColor;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextShadowColor constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTextShadowColor;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextShadowColor constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextShadowColor Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::NewProp_InTextShadowColor = { "InTextShadowColor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetTextShadowColor_Parms, InTextShadowColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::NewProp_InTextShadowColor,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::PropPointers) < 2048);
// ********** End Function SetTextShadowColor Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetTextShadowColor", 	Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::SimpleTextBox_eventSetTextShadowColor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::SimpleTextBox_eventSetTextShadowColor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetTextShadowColor)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InTextShadowColor);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextShadowColor(Z_Param_InTextShadowColor);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetTextShadowColor *********************************

// ********** Begin Class USimpleTextBox Function SetTextShadowOffset ******************************
struct Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics
{
	struct SimpleTextBox_eventSetTextShadowOffset_Parms
	{
		FVector2D InTextShadowOffset;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextShadowOffset constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTextShadowOffset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextShadowOffset constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextShadowOffset Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::NewProp_InTextShadowOffset = { "InTextShadowOffset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetTextShadowOffset_Parms, InTextShadowOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::NewProp_InTextShadowOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::PropPointers) < 2048);
// ********** End Function SetTextShadowOffset Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetTextShadowOffset", 	Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::SimpleTextBox_eventSetTextShadowOffset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::SimpleTextBox_eventSetTextShadowOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetTextShadowOffset)
{
	P_GET_STRUCT(FVector2D,Z_Param_InTextShadowOffset);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextShadowOffset(Z_Param_InTextShadowOffset);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetTextShadowOffset ********************************

// ********** Begin Class USimpleTextBox Function SetTextStrikeBrush *******************************
struct Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics
{
	struct SimpleTextBox_eventSetTextStrikeBrush_Parms
	{
		FSlateBrush InTextStrikeBrush;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTextStrikeBrush_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextStrikeBrush constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTextStrikeBrush;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextStrikeBrush constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextStrikeBrush Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::NewProp_InTextStrikeBrush = { "InTextStrikeBrush", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetTextStrikeBrush_Parms, InTextStrikeBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTextStrikeBrush_MetaData), NewProp_InTextStrikeBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::NewProp_InTextStrikeBrush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::PropPointers) < 2048);
// ********** End Function SetTextStrikeBrush Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetTextStrikeBrush", 	Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::SimpleTextBox_eventSetTextStrikeBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::SimpleTextBox_eventSetTextStrikeBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetTextStrikeBrush)
{
	P_GET_STRUCT_REF(FSlateBrush,Z_Param_Out_InTextStrikeBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextStrikeBrush(Z_Param_Out_InTextStrikeBrush);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetTextStrikeBrush *********************************

// ********** Begin Class USimpleTextBox Function SetTextVerticalAlignment *************************
struct Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics
{
	struct SimpleTextBox_eventSetTextVerticalAlignment_Parms
	{
		TEnumAsByte<EVerticalAlignment> InTextVerticalAlignment;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTextVerticalAlignment constinit property declarations **************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InTextVerticalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTextVerticalAlignment constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTextVerticalAlignment Property Definitions *************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::NewProp_InTextVerticalAlignment = { "InTextVerticalAlignment", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetTextVerticalAlignment_Parms, InTextVerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(0, nullptr) }; // 2496106429
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::NewProp_InTextVerticalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::PropPointers) < 2048);
// ********** End Function SetTextVerticalAlignment Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetTextVerticalAlignment", 	Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::SimpleTextBox_eventSetTextVerticalAlignment_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::SimpleTextBox_eventSetTextVerticalAlignment_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetTextVerticalAlignment)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InTextVerticalAlignment);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextVerticalAlignment(EVerticalAlignment(Z_Param_InTextVerticalAlignment));
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetTextVerticalAlignment ***************************

// ********** Begin Class USimpleTextBox Function SetTransformPolicy *******************************
struct Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics
{
	struct SimpleTextBox_eventSetTransformPolicy_Parms
	{
		ETextTransformPolicy InTransformPolicy;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetTransformPolicy constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InTransformPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InTransformPolicy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetTransformPolicy constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetTransformPolicy Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::NewProp_InTransformPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::NewProp_InTransformPolicy = { "InTransformPolicy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetTransformPolicy_Parms, InTransformPolicy), Z_Construct_UEnum_SlateCore_ETextTransformPolicy, METADATA_PARAMS(0, nullptr) }; // 2733367800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::NewProp_InTransformPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::NewProp_InTransformPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::PropPointers) < 2048);
// ********** End Function SetTransformPolicy Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetTransformPolicy", 	Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::SimpleTextBox_eventSetTransformPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::SimpleTextBox_eventSetTransformPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetTransformPolicy)
{
	P_GET_ENUM(ETextTransformPolicy,Z_Param_InTransformPolicy);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTransformPolicy(ETextTransformPolicy(Z_Param_InTransformPolicy));
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetTransformPolicy *********************************

// ********** Begin Class USimpleTextBox Function SetWrappingPolicy ********************************
struct Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics
{
	struct SimpleTextBox_eventSetWrappingPolicy_Parms
	{
		ETextWrappingPolicy InWrappingPolicy;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x8d\xa2\xe8\xa1\x8cPolicy\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x8d\xa2\xe8\xa1\x8cPolicy\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetWrappingPolicy constinit property declarations *********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InWrappingPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InWrappingPolicy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetWrappingPolicy constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetWrappingPolicy Property Definitions ********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::NewProp_InWrappingPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::NewProp_InWrappingPolicy = { "InWrappingPolicy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetWrappingPolicy_Parms, InWrappingPolicy), Z_Construct_UEnum_Slate_ETextWrappingPolicy, METADATA_PARAMS(0, nullptr) }; // 3831279660
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::NewProp_InWrappingPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::NewProp_InWrappingPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::PropPointers) < 2048);
// ********** End Function SetWrappingPolicy Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetWrappingPolicy", 	Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::SimpleTextBox_eventSetWrappingPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::SimpleTextBox_eventSetWrappingPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetWrappingPolicy)
{
	P_GET_ENUM(ETextWrappingPolicy,Z_Param_InWrappingPolicy);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetWrappingPolicy(ETextWrappingPolicy(Z_Param_InWrappingPolicy));
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetWrappingPolicy **********************************

// ********** Begin Class USimpleTextBox Function SetWrapTextAt ************************************
struct Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics
{
	struct SimpleTextBox_eventSetWrapTextAt_Parms
	{
		float InWrapTextAt;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x8d\xa2\xe8\xa1\x8c\xe6\x96\x87\xe6\x9c\xac\xe4\xbd\x8d\xe7\xbd\xae\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x8d\xa2\xe8\xa1\x8c\xe6\x96\x87\xe6\x9c\xac\xe4\xbd\x8d\xe7\xbd\xae\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetWrapTextAt constinit property declarations *************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InWrapTextAt;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetWrapTextAt constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetWrapTextAt Property Definitions ************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::NewProp_InWrapTextAt = { "InWrapTextAt", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SimpleTextBox_eventSetWrapTextAt_Parms, InWrapTextAt), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::NewProp_InWrapTextAt,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::PropPointers) < 2048);
// ********** End Function SetWrapTextAt Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USimpleTextBox, nullptr, "SetWrapTextAt", 	Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::SimpleTextBox_eventSetWrapTextAt_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::Function_MetaDataParams), Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::SimpleTextBox_eventSetWrapTextAt_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USimpleTextBox::execSetWrapTextAt)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InWrapTextAt);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetWrapTextAt(Z_Param_InWrapTextAt);
	P_NATIVE_END;
}
// ********** End Class USimpleTextBox Function SetWrapTextAt **************************************

// ********** Begin Class USimpleTextBox ***********************************************************
void USimpleTextBox::GetText_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FText& Result = *(FText*)OutValue;
	Result = (FText)Obj->GetText();
}
void USimpleTextBox::SetText_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FText& Value = *(FText*)InValue;
	Obj->SetText(Value);
}
void USimpleTextBox::GetTextColor_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FSlateColor& Result = *(FSlateColor*)OutValue;
	Result = (FSlateColor)Obj->GetTextColor();
}
void USimpleTextBox::SetTextColor_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FSlateColor& Value = *(FSlateColor*)InValue;
	Obj->SetTextColor(Value);
}
void USimpleTextBox::GetTextFont_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FSlateFontInfo& Result = *(FSlateFontInfo*)OutValue;
	Result = (FSlateFontInfo)Obj->GetTextFont();
}
void USimpleTextBox::SetTextFont_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FSlateFontInfo& Value = *(FSlateFontInfo*)InValue;
	Obj->SetTextFont(Value);
}
void USimpleTextBox::GetTextStrikeBrush_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FSlateBrush& Result = *(FSlateBrush*)OutValue;
	Result = (FSlateBrush)Obj->GetTextStrikeBrush();
}
void USimpleTextBox::SetTextStrikeBrush_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FSlateBrush& Value = *(FSlateBrush*)InValue;
	Obj->SetTextStrikeBrush(Value);
}
void USimpleTextBox::GetTextShadowOffset_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FVector2D& Result = *(FVector2D*)OutValue;
	Result = (FVector2D)Obj->GetTextShadowOffset();
}
void USimpleTextBox::SetTextShadowOffset_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FVector2D& Value = *(FVector2D*)InValue;
	Obj->SetTextShadowOffset(Value);
}
void USimpleTextBox::GetTextShadowColor_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FLinearColor& Result = *(FLinearColor*)OutValue;
	Result = (FLinearColor)Obj->GetTextShadowColor();
}
void USimpleTextBox::SetTextShadowColor_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FLinearColor& Value = *(FLinearColor*)InValue;
	Obj->SetTextShadowColor(Value);
}
void USimpleTextBox::GetHighlightText_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FText& Result = *(FText*)OutValue;
	Result = (FText)Obj->GetHighlightText();
}
void USimpleTextBox::SetHighlightText_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FText& Value = *(FText*)InValue;
	Obj->SetHighlightText(Value);
}
void USimpleTextBox::GetTextHighlightShape_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FSlateBrush& Result = *(FSlateBrush*)OutValue;
	Result = (FSlateBrush)Obj->GetTextHighlightShape();
}
void USimpleTextBox::SetTextHighlightShape_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FSlateBrush& Value = *(FSlateBrush*)InValue;
	Obj->SetTextHighlightShape(Value);
}
void USimpleTextBox::GetAutoWrapText_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	bool& Result = *(bool*)OutValue;
	Result = (bool)Obj->GetAutoWrapText();
}
void USimpleTextBox::SetAutoWrapText_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	bool& Value = *(bool*)InValue;
	Obj->SetAutoWrapText(Value);
}
void USimpleTextBox::GetWrapTextAt_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetWrapTextAt();
}
void USimpleTextBox::SetWrapTextAt_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	float& Value = *(float*)InValue;
	Obj->SetWrapTextAt(Value);
}
void USimpleTextBox::GetWrappingPolicy_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	ETextWrappingPolicy& Result = *(ETextWrappingPolicy*)OutValue;
	Result = (ETextWrappingPolicy)Obj->GetWrappingPolicy();
}
void USimpleTextBox::SetWrappingPolicy_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	ETextWrappingPolicy& Value = *(ETextWrappingPolicy*)InValue;
	Obj->SetWrappingPolicy(Value);
}
void USimpleTextBox::GetTransformPolicy_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	ETextTransformPolicy& Result = *(ETextTransformPolicy*)OutValue;
	Result = (ETextTransformPolicy)Obj->GetTransformPolicy();
}
void USimpleTextBox::SetTransformPolicy_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	ETextTransformPolicy& Value = *(ETextTransformPolicy*)InValue;
	Obj->SetTransformPolicy(Value);
}
void USimpleTextBox::GetJustification_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	uint8& Result = *(uint8*)OutValue;
	Result = (uint8)Obj->GetJustification();
}
void USimpleTextBox::SetJustification_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	ETextJustify::Type Value = (ETextJustify::Type)*(uint8*)InValue;
	Obj->SetJustification(Value);
}
void USimpleTextBox::GetMinDesiredWidth_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetMinDesiredWidth();
}
void USimpleTextBox::SetMinDesiredWidth_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	float& Value = *(float*)InValue;
	Obj->SetMinDesiredWidth(Value);
}
void USimpleTextBox::GetLineHeightPercentage_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetLineHeightPercentage();
}
void USimpleTextBox::SetLineHeightPercentage_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	float& Value = *(float*)InValue;
	Obj->SetLineHeightPercentage(Value);
}
void USimpleTextBox::GetTextMargin_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FMargin& Result = *(FMargin*)OutValue;
	Result = (FMargin)Obj->GetTextMargin();
}
void USimpleTextBox::SetTextMargin_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FMargin& Value = *(FMargin*)InValue;
	Obj->SetTextMargin(Value);
}
void USimpleTextBox::GetOverflowPolicy_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	ETextOverflowPolicy& Result = *(ETextOverflowPolicy*)OutValue;
	Result = (ETextOverflowPolicy)Obj->GetOverflowPolicy();
}
void USimpleTextBox::SetOverflowPolicy_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	ETextOverflowPolicy& Value = *(ETextOverflowPolicy*)InValue;
	Obj->SetOverflowPolicy(Value);
}
void USimpleTextBox::GetSpace_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	float& Result = *(float*)OutValue;
	Result = (float)Obj->GetSpace();
}
void USimpleTextBox::SetSpace_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	float& Value = *(float*)InValue;
	Obj->SetSpace(Value);
}
void USimpleTextBox::GetImage_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FSlateBrush& Result = *(FSlateBrush*)OutValue;
	Result = (FSlateBrush)Obj->GetImage();
}
void USimpleTextBox::SetImage_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FSlateBrush& Value = *(FSlateBrush*)InValue;
	Obj->SetImage(Value);
}
void USimpleTextBox::GetImageColor_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FSlateColor& Result = *(FSlateColor*)OutValue;
	Result = (FSlateColor)Obj->GetImageColor();
}
void USimpleTextBox::SetImageColor_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FSlateColor& Value = *(FSlateColor*)InValue;
	Obj->SetImageColor(Value);
}
void USimpleTextBox::GetImageMargin_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FMargin& Result = *(FMargin*)OutValue;
	Result = (FMargin)Obj->GetImageMargin();
}
void USimpleTextBox::SetImageMargin_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FMargin& Value = *(FMargin*)InValue;
	Obj->SetImageMargin(Value);
}
void USimpleTextBox::GetImageVisibility_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	ESlateVisibility& Result = *(ESlateVisibility*)OutValue;
	Result = (ESlateVisibility)Obj->GetImageVisibility();
}
void USimpleTextBox::SetImageVisibility_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	ESlateVisibility& Value = *(ESlateVisibility*)InValue;
	Obj->SetImageVisibility(Value);
}
void USimpleTextBox::GetSimpleTextBoxType_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	ESimpleTextBoxType& Result = *(ESimpleTextBoxType*)OutValue;
	Result = (ESimpleTextBoxType)Obj->GetSimpleTextBoxType();
}
void USimpleTextBox::SetSimpleTextBoxType_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	ESimpleTextBoxType& Value = *(ESimpleTextBoxType*)InValue;
	Obj->SetSimpleTextBoxType(Value);
}
void USimpleTextBox::GetPadding_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	FMargin& Result = *(FMargin*)OutValue;
	Result = (FMargin)Obj->GetPadding();
}
void USimpleTextBox::SetPadding_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	FMargin& Value = *(FMargin*)InValue;
	Obj->SetPadding(Value);
}
void USimpleTextBox::GetTextHorizontalAlignment_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	uint8& Result = *(uint8*)OutValue;
	Result = (uint8)Obj->GetTextHorizontalAlignment();
}
void USimpleTextBox::SetTextHorizontalAlignment_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	EHorizontalAlignment Value = (EHorizontalAlignment)*(uint8*)InValue;
	Obj->SetTextHorizontalAlignment(Value);
}
void USimpleTextBox::GetTextVerticalAlignment_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	uint8& Result = *(uint8*)OutValue;
	Result = (uint8)Obj->GetTextVerticalAlignment();
}
void USimpleTextBox::SetTextVerticalAlignment_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	EVerticalAlignment Value = (EVerticalAlignment)*(uint8*)InValue;
	Obj->SetTextVerticalAlignment(Value);
}
void USimpleTextBox::GetImageHorizontalAlignment_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	uint8& Result = *(uint8*)OutValue;
	Result = (uint8)Obj->GetImageHorizontalAlignment();
}
void USimpleTextBox::SetImageHorizontalAlignment_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	EHorizontalAlignment Value = (EHorizontalAlignment)*(uint8*)InValue;
	Obj->SetImageHorizontalAlignment(Value);
}
void USimpleTextBox::GetImageVerticalAlignment_WrapperImpl(const void* Object, void* OutValue)
{
	const USimpleTextBox* Obj = (const USimpleTextBox*)Object;
	uint8& Result = *(uint8*)OutValue;
	Result = (uint8)Obj->GetImageVerticalAlignment();
}
void USimpleTextBox::SetImageVerticalAlignment_WrapperImpl(void* Object, const void* InValue)
{
	USimpleTextBox* Obj = (USimpleTextBox*)Object;
	EVerticalAlignment Value = (EVerticalAlignment)*(uint8*)InValue;
	Obj->SetImageVerticalAlignment(Value);
}
FClassRegistrationInfo Z_Registration_Info_UClass_USimpleTextBox;
UClass* USimpleTextBox::GetPrivateStaticClass()
{
	using TClass = USimpleTextBox;
	if (!Z_Registration_Info_UClass_USimpleTextBox.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SimpleTextBox"),
			Z_Registration_Info_UClass_USimpleTextBox.InnerSingleton,
			StaticRegisterNativesUSimpleTextBox,
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
	return Z_Registration_Info_UClass_USimpleTextBox.InnerSingleton;
}
UClass* Z_Construct_UClass_USimpleTextBox_NoRegister()
{
	return USimpleTextBox::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USimpleTextBox_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe7\xae\x80\xe5\x8d\x95\xe6\x96\x87\xe6\x9c\xac\xe6\xa1\x86 UMG \xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "UWidget/SimpleTextBox.h" },
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe7\xae\x80\xe5\x8d\x95\xe6\x96\x87\xe6\x9c\xac\xe6\xa1\x86 UMG \xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "BlueprintGetter", "GetText" },
		{ "BlueprintSetter", "SetText" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x86\x85\xe5\xae\xb9\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
		{ "MultiLine", "true" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x86\x85\xe5\xae\xb9\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextColor_MetaData[] = {
		{ "BlueprintGetter", "GetTextColor" },
		{ "BlueprintSetter", "SetTextColor" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextFont_MetaData[] = {
		{ "BlueprintGetter", "GetTextFont" },
		{ "BlueprintSetter", "SetTextFont" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\xad\x97\xe4\xbd\x93\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\xad\x97\xe4\xbd\x93\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextStrikeBrush_MetaData[] = {
		{ "BlueprintGetter", "GetTextStrikeBrush" },
		{ "BlueprintSetter", "SetTextStrikeBrush" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextShadowOffset_MetaData[] = {
		{ "BlueprintGetter", "GetTextShadowOffset" },
		{ "BlueprintSetter", "SetTextShadowOffset" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextShadowColor_MetaData[] = {
		{ "BlueprintGetter", "GetTextShadowColor" },
		{ "BlueprintSetter", "SetTextShadowColor" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighlightText_MetaData[] = {
		{ "BlueprintGetter", "GetHighlightText" },
		{ "BlueprintSetter", "SetHighlightText" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xab\x98\xe4\xba\xae\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
		{ "MultiLine", "true" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xab\x98\xe4\xba\xae\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextHighlightShape_MetaData[] = {
		{ "BlueprintGetter", "GetTextHighlightShape" },
		{ "BlueprintSetter", "SetTextHighlightShape" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xacHighlightShape\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xacHighlightShape\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AutoWrapText_MetaData[] = {
		{ "BlueprintGetter", "GetAutoWrapText" },
		{ "BlueprintSetter", "SetAutoWrapText" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xb0\xe5\xbd\x95\xe6\x98\xaf\xe5\x90\xa6\xe8\x87\xaa\xe5\x8a\xa8\xe6\x8d\xa2\xe8\xa1\x8c\xef\xbc\x8c\xe5\xbd\xb1\xe5\x93\x8d Slate \xe6\x96\x87\xe6\x9c\xac\xe5\xb8\x83\xe5\xb1\x80\xe5\xae\xbd\xe5\xba\xa6\xe8\xae\xa1\xe7\xae\x97\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xb0\xe5\xbd\x95\xe6\x98\xaf\xe5\x90\xa6\xe8\x87\xaa\xe5\x8a\xa8\xe6\x8d\xa2\xe8\xa1\x8c\xef\xbc\x8c\xe5\xbd\xb1\xe5\x93\x8d Slate \xe6\x96\x87\xe6\x9c\xac\xe5\xb8\x83\xe5\xb1\x80\xe5\xae\xbd\xe5\xba\xa6\xe8\xae\xa1\xe7\xae\x97\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WrapTextAt_MetaData[] = {
		{ "BlueprintGetter", "GetWrapTextAt" },
		{ "BlueprintSetter", "SetWrapTextAt" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x89\x8b\xe5\x8a\xa8\xe6\x8d\xa2\xe8\xa1\x8c\xe5\xae\xbd\xe5\xba\xa6\xef\xbc\x8c\xe8\xa6\x86\xe7\x9b\x96\xe9\xbb\x98\xe8\xae\xa4\xe5\xb8\x83\xe5\xb1\x80\xe5\xae\xbd\xe5\xba\xa6\xe8\xae\xa1\xe7\xae\x97\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x89\x8b\xe5\x8a\xa8\xe6\x8d\xa2\xe8\xa1\x8c\xe5\xae\xbd\xe5\xba\xa6\xef\xbc\x8c\xe8\xa6\x86\xe7\x9b\x96\xe9\xbb\x98\xe8\xae\xa4\xe5\xb8\x83\xe5\xb1\x80\xe5\xae\xbd\xe5\xba\xa6\xe8\xae\xa1\xe7\xae\x97\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WrappingPolicy_MetaData[] = {
		{ "BlueprintGetter", "GetWrappingPolicy" },
		{ "BlueprintSetter", "SetWrappingPolicy" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe6\x8d\xa2\xe8\xa1\x8c\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe6\x8e\xa7\xe5\x88\xb6\xe5\x8d\x95\xe8\xaf\x8d\xe8\xbe\xb9\xe7\x95\x8c\xe5\x92\x8c\xe8\xa3\x81\xe5\x89\xaa\xe8\xa1\x8c\xe4\xb8\xba\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe6\x8d\xa2\xe8\xa1\x8c\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe6\x8e\xa7\xe5\x88\xb6\xe5\x8d\x95\xe8\xaf\x8d\xe8\xbe\xb9\xe7\x95\x8c\xe5\x92\x8c\xe8\xa3\x81\xe5\x89\xaa\xe8\xa1\x8c\xe4\xb8\xba\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransformPolicy_MetaData[] = {
		{ "BlueprintGetter", "GetTransformPolicy" },
		{ "BlueprintSetter", "SetTransformPolicy" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Justification_MetaData[] = {
		{ "BlueprintGetter", "GetJustification" },
		{ "BlueprintSetter", "SetJustification" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\xaf\xb9\xe9\xbd\x90\xe6\x96\xb9\xe5\xbc\x8f\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\xaf\xb9\xe9\xbd\x90\xe6\x96\xb9\xe5\xbc\x8f\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinDesiredWidth_MetaData[] = {
		{ "BlueprintGetter", "GetMinDesiredWidth" },
		{ "BlueprintSetter", "SetMinDesiredWidth" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LineHeightPercentage_MetaData[] = {
		{ "BlueprintGetter", "GetLineHeightPercentage" },
		{ "BlueprintSetter", "SetLineHeightPercentage" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xa1\x8c\xe9\xab\x98\xe6\xaf\x94\xe4\xbe\x8b\xef\xbc\x8c\xe4\xbe\x9b\xe6\x96\x87\xe6\x9c\xac\xe5\xb8\x83\xe5\xb1\x80\xe8\xae\xa1\xe7\xae\x97\xe5\x9e\x82\xe7\x9b\xb4\xe9\x97\xb4\xe8\xb7\x9d\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xa1\x8c\xe9\xab\x98\xe6\xaf\x94\xe4\xbe\x8b\xef\xbc\x8c\xe4\xbe\x9b\xe6\x96\x87\xe6\x9c\xac\xe5\xb8\x83\xe5\xb1\x80\xe8\xae\xa1\xe7\xae\x97\xe5\x9e\x82\xe7\x9b\xb4\xe9\x97\xb4\xe8\xb7\x9d\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextMargin_MetaData[] = {
		{ "BlueprintGetter", "GetTextMargin" },
		{ "BlueprintSetter", "SetTextMargin" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe8\xbe\xb9\xe8\xb7\x9d\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe8\xbe\xb9\xe8\xb7\x9d\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverflowPolicy_MetaData[] = {
		{ "BlueprintGetter", "GetOverflowPolicy" },
		{ "BlueprintSetter", "SetOverflowPolicy" },
		{ "Category", "SimpleTextBox|Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Space_MetaData[] = {
		{ "BlueprintGetter", "GetSpace" },
		{ "BlueprintSetter", "SetSpace" },
		{ "Category", "SimpleTextBox|Space" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe5\xad\x97\xe4\xb8\x8e\xe5\x9b\xbe\xe7\x89\x87\xe4\xb9\x8b\xe9\x97\xb4\xe7\x9a\x84\xe9\x97\xb4\xe8\xb7\x9d\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe5\xad\x97\xe4\xb8\x8e\xe5\x9b\xbe\xe7\x89\x87\xe4\xb9\x8b\xe9\x97\xb4\xe7\x9a\x84\xe9\x97\xb4\xe8\xb7\x9d\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Image_MetaData[] = {
		{ "BlueprintGetter", "GetImage" },
		{ "BlueprintSetter", "SetImage" },
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageColor_MetaData[] = {
		{ "BlueprintGetter", "GetImageColor" },
		{ "BlueprintSetter", "SetImageColor" },
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87""Color\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87""Color\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageMargin_MetaData[] = {
		{ "BlueprintGetter", "GetImageMargin" },
		{ "BlueprintSetter", "SetImageMargin" },
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87Margin\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87Margin\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageVisibility_MetaData[] = {
		{ "BlueprintGetter", "GetImageVisibility" },
		{ "BlueprintSetter", "SetImageVisibility" },
		{ "Category", "SimpleTextBox|Image" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87Visibility\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87Visibility\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SimpleTextBoxType_MetaData[] = {
		{ "BlueprintGetter", "GetSimpleTextBoxType" },
		{ "BlueprintSetter", "SetSimpleTextBoxType" },
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\xae\x80\xe5\x8d\x95\xe6\x96\x87\xe6\x9c\xac\xe7\x9b\x92\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\xae\x80\xe5\x8d\x95\xe6\x96\x87\xe6\x9c\xac\xe7\x9b\x92\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Padding_MetaData[] = {
		{ "BlueprintGetter", "GetPadding" },
		{ "BlueprintSetter", "SetPadding" },
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x86\x85\xe8\xbe\xb9\xe8\xb7\x9d\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x86\x85\xe8\xbe\xb9\xe8\xb7\x9d\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextHorizontalAlignment_MetaData[] = {
		{ "BlueprintGetter", "GetTextHorizontalAlignment" },
		{ "BlueprintSetter", "SetTextHorizontalAlignment" },
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xbb\x84\xe5\x90\x88\xe6\x96\x87\xe6\x9c\xac\xe5\x92\x8c\xe5\x9b\xbe\xe7\x89\x87\xe7\x9a\x84\xe5\xb8\x83\xe5\xb1\x80\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xbb\x84\xe5\x90\x88\xe6\x96\x87\xe6\x9c\xac\xe5\x92\x8c\xe5\x9b\xbe\xe7\x89\x87\xe7\x9a\x84\xe5\xb8\x83\xe5\xb1\x80\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextVerticalAlignment_MetaData[] = {
		{ "BlueprintGetter", "GetTextVerticalAlignment" },
		{ "BlueprintSetter", "SetTextVerticalAlignment" },
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xbb\x84\xe5\x90\x88\xe6\x96\x87\xe6\x9c\xac\xe5\x92\x8c\xe5\x9b\xbe\xe7\x89\x87\xe7\x9a\x84\xe5\xb8\x83\xe5\xb1\x80\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xbb\x84\xe5\x90\x88\xe6\x96\x87\xe6\x9c\xac\xe5\x92\x8c\xe5\x9b\xbe\xe7\x89\x87\xe7\x9a\x84\xe5\xb8\x83\xe5\xb1\x80\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageHorizontalAlignment_MetaData[] = {
		{ "BlueprintGetter", "GetImageHorizontalAlignment" },
		{ "BlueprintSetter", "SetImageHorizontalAlignment" },
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xbb\x84\xe5\x90\x88\xe6\x96\x87\xe6\x9c\xac\xe5\x92\x8c\xe5\x9b\xbe\xe7\x89\x87\xe7\x9a\x84\xe5\xb8\x83\xe5\xb1\x80\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87\xe6\xb0\xb4\xe5\xb9\xb3\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xbb\x84\xe5\x90\x88\xe6\x96\x87\xe6\x9c\xac\xe5\x92\x8c\xe5\x9b\xbe\xe7\x89\x87\xe7\x9a\x84\xe5\xb8\x83\xe5\xb1\x80\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageVerticalAlignment_MetaData[] = {
		{ "BlueprintGetter", "GetImageVerticalAlignment" },
		{ "BlueprintSetter", "SetImageVerticalAlignment" },
		{ "Category", "SimpleTextBox|Layout" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xbb\x84\xe5\x90\x88\xe6\x96\x87\xe6\x9c\xac\xe5\x92\x8c\xe5\x9b\xbe\xe7\x89\x87\xe7\x9a\x84\xe5\xb8\x83\xe5\xb1\x80\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x9b\xbe\xe7\x89\x87\xe5\x9e\x82\xe7\x9b\xb4\xe5\xaf\xb9\xe9\xbd\x90\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe7\xbb\x84\xe5\x90\x88\xe6\x96\x87\xe6\x9c\xac\xe5\x92\x8c\xe5\x9b\xbe\xe7\x89\x87\xe7\x9a\x84\xe5\xb8\x83\xe5\xb1\x80\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USimpleTextBox constinit property declarations ***************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextFont;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextStrikeBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextShadowOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextShadowColor;
	static const UECodeGen_Private::FTextPropertyParams NewProp_HighlightText;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextHighlightShape;
	static void NewProp_AutoWrapText_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_AutoWrapText;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_WrapTextAt;
	static const UECodeGen_Private::FBytePropertyParams NewProp_WrappingPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_WrappingPolicy;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransformPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransformPolicy;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Justification;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinDesiredWidth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_LineHeightPercentage;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TextMargin;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OverflowPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OverflowPolicy;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Space;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Image;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImageColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ImageMargin;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ImageVisibility_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ImageVisibility;
	static const UECodeGen_Private::FBytePropertyParams NewProp_SimpleTextBoxType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_SimpleTextBoxType;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Padding;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TextHorizontalAlignment;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TextVerticalAlignment;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ImageHorizontalAlignment;
	static const UECodeGen_Private::FBytePropertyParams NewProp_ImageVerticalAlignment;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USimpleTextBox constinit property declarations *****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetAutoWrapText"), .Pointer = &USimpleTextBox::execGetAutoWrapText },
		{ .NameUTF8 = UTF8TEXT("GetHighlightText"), .Pointer = &USimpleTextBox::execGetHighlightText },
		{ .NameUTF8 = UTF8TEXT("GetImage"), .Pointer = &USimpleTextBox::execGetImage },
		{ .NameUTF8 = UTF8TEXT("GetImageColor"), .Pointer = &USimpleTextBox::execGetImageColor },
		{ .NameUTF8 = UTF8TEXT("GetImageHorizontalAlignment"), .Pointer = &USimpleTextBox::execGetImageHorizontalAlignment },
		{ .NameUTF8 = UTF8TEXT("GetImageMargin"), .Pointer = &USimpleTextBox::execGetImageMargin },
		{ .NameUTF8 = UTF8TEXT("GetImageVerticalAlignment"), .Pointer = &USimpleTextBox::execGetImageVerticalAlignment },
		{ .NameUTF8 = UTF8TEXT("GetImageVisibility"), .Pointer = &USimpleTextBox::execGetImageVisibility },
		{ .NameUTF8 = UTF8TEXT("GetJustification"), .Pointer = &USimpleTextBox::execGetJustification },
		{ .NameUTF8 = UTF8TEXT("GetLineHeightPercentage"), .Pointer = &USimpleTextBox::execGetLineHeightPercentage },
		{ .NameUTF8 = UTF8TEXT("GetMinDesiredWidth"), .Pointer = &USimpleTextBox::execGetMinDesiredWidth },
		{ .NameUTF8 = UTF8TEXT("GetOverflowPolicy"), .Pointer = &USimpleTextBox::execGetOverflowPolicy },
		{ .NameUTF8 = UTF8TEXT("GetPadding"), .Pointer = &USimpleTextBox::execGetPadding },
		{ .NameUTF8 = UTF8TEXT("GetSimpleTextBoxType"), .Pointer = &USimpleTextBox::execGetSimpleTextBoxType },
		{ .NameUTF8 = UTF8TEXT("GetSpace"), .Pointer = &USimpleTextBox::execGetSpace },
		{ .NameUTF8 = UTF8TEXT("GetText"), .Pointer = &USimpleTextBox::execGetText },
		{ .NameUTF8 = UTF8TEXT("GetTextColor"), .Pointer = &USimpleTextBox::execGetTextColor },
		{ .NameUTF8 = UTF8TEXT("GetTextFont"), .Pointer = &USimpleTextBox::execGetTextFont },
		{ .NameUTF8 = UTF8TEXT("GetTextHighlightShape"), .Pointer = &USimpleTextBox::execGetTextHighlightShape },
		{ .NameUTF8 = UTF8TEXT("GetTextHorizontalAlignment"), .Pointer = &USimpleTextBox::execGetTextHorizontalAlignment },
		{ .NameUTF8 = UTF8TEXT("GetTextMargin"), .Pointer = &USimpleTextBox::execGetTextMargin },
		{ .NameUTF8 = UTF8TEXT("GetTextShadowColor"), .Pointer = &USimpleTextBox::execGetTextShadowColor },
		{ .NameUTF8 = UTF8TEXT("GetTextShadowOffset"), .Pointer = &USimpleTextBox::execGetTextShadowOffset },
		{ .NameUTF8 = UTF8TEXT("GetTextStrikeBrush"), .Pointer = &USimpleTextBox::execGetTextStrikeBrush },
		{ .NameUTF8 = UTF8TEXT("GetTextVerticalAlignment"), .Pointer = &USimpleTextBox::execGetTextVerticalAlignment },
		{ .NameUTF8 = UTF8TEXT("GetTransformPolicy"), .Pointer = &USimpleTextBox::execGetTransformPolicy },
		{ .NameUTF8 = UTF8TEXT("GetWrappingPolicy"), .Pointer = &USimpleTextBox::execGetWrappingPolicy },
		{ .NameUTF8 = UTF8TEXT("GetWrapTextAt"), .Pointer = &USimpleTextBox::execGetWrapTextAt },
		{ .NameUTF8 = UTF8TEXT("SetAutoWrapText"), .Pointer = &USimpleTextBox::execSetAutoWrapText },
		{ .NameUTF8 = UTF8TEXT("SetHighlightText"), .Pointer = &USimpleTextBox::execSetHighlightText },
		{ .NameUTF8 = UTF8TEXT("SetImage"), .Pointer = &USimpleTextBox::execSetImage },
		{ .NameUTF8 = UTF8TEXT("SetImageColor"), .Pointer = &USimpleTextBox::execSetImageColor },
		{ .NameUTF8 = UTF8TEXT("SetImageHorizontalAlignment"), .Pointer = &USimpleTextBox::execSetImageHorizontalAlignment },
		{ .NameUTF8 = UTF8TEXT("SetImageMargin"), .Pointer = &USimpleTextBox::execSetImageMargin },
		{ .NameUTF8 = UTF8TEXT("SetImageVerticalAlignment"), .Pointer = &USimpleTextBox::execSetImageVerticalAlignment },
		{ .NameUTF8 = UTF8TEXT("SetImageVisibility"), .Pointer = &USimpleTextBox::execSetImageVisibility },
		{ .NameUTF8 = UTF8TEXT("SetJustification"), .Pointer = &USimpleTextBox::execSetJustification },
		{ .NameUTF8 = UTF8TEXT("SetLineHeightPercentage"), .Pointer = &USimpleTextBox::execSetLineHeightPercentage },
		{ .NameUTF8 = UTF8TEXT("SetMinDesiredWidth"), .Pointer = &USimpleTextBox::execSetMinDesiredWidth },
		{ .NameUTF8 = UTF8TEXT("SetOverflowPolicy"), .Pointer = &USimpleTextBox::execSetOverflowPolicy },
		{ .NameUTF8 = UTF8TEXT("SetPadding"), .Pointer = &USimpleTextBox::execSetPadding },
		{ .NameUTF8 = UTF8TEXT("SetSimpleTextBoxType"), .Pointer = &USimpleTextBox::execSetSimpleTextBoxType },
		{ .NameUTF8 = UTF8TEXT("SetSpace"), .Pointer = &USimpleTextBox::execSetSpace },
		{ .NameUTF8 = UTF8TEXT("SetText"), .Pointer = &USimpleTextBox::execSetText },
		{ .NameUTF8 = UTF8TEXT("SetTextColor"), .Pointer = &USimpleTextBox::execSetTextColor },
		{ .NameUTF8 = UTF8TEXT("SetTextFont"), .Pointer = &USimpleTextBox::execSetTextFont },
		{ .NameUTF8 = UTF8TEXT("SetTextHighlightShape"), .Pointer = &USimpleTextBox::execSetTextHighlightShape },
		{ .NameUTF8 = UTF8TEXT("SetTextHorizontalAlignment"), .Pointer = &USimpleTextBox::execSetTextHorizontalAlignment },
		{ .NameUTF8 = UTF8TEXT("SetTextMargin"), .Pointer = &USimpleTextBox::execSetTextMargin },
		{ .NameUTF8 = UTF8TEXT("SetTextShadowColor"), .Pointer = &USimpleTextBox::execSetTextShadowColor },
		{ .NameUTF8 = UTF8TEXT("SetTextShadowOffset"), .Pointer = &USimpleTextBox::execSetTextShadowOffset },
		{ .NameUTF8 = UTF8TEXT("SetTextStrikeBrush"), .Pointer = &USimpleTextBox::execSetTextStrikeBrush },
		{ .NameUTF8 = UTF8TEXT("SetTextVerticalAlignment"), .Pointer = &USimpleTextBox::execSetTextVerticalAlignment },
		{ .NameUTF8 = UTF8TEXT("SetTransformPolicy"), .Pointer = &USimpleTextBox::execSetTransformPolicy },
		{ .NameUTF8 = UTF8TEXT("SetWrappingPolicy"), .Pointer = &USimpleTextBox::execSetWrappingPolicy },
		{ .NameUTF8 = UTF8TEXT("SetWrapTextAt"), .Pointer = &USimpleTextBox::execSetWrapTextAt },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USimpleTextBox_GetAutoWrapText, "GetAutoWrapText" }, // 788865360
		{ &Z_Construct_UFunction_USimpleTextBox_GetHighlightText, "GetHighlightText" }, // 1407617089
		{ &Z_Construct_UFunction_USimpleTextBox_GetImage, "GetImage" }, // 4182609531
		{ &Z_Construct_UFunction_USimpleTextBox_GetImageColor, "GetImageColor" }, // 1095535545
		{ &Z_Construct_UFunction_USimpleTextBox_GetImageHorizontalAlignment, "GetImageHorizontalAlignment" }, // 2547463740
		{ &Z_Construct_UFunction_USimpleTextBox_GetImageMargin, "GetImageMargin" }, // 366382931
		{ &Z_Construct_UFunction_USimpleTextBox_GetImageVerticalAlignment, "GetImageVerticalAlignment" }, // 2862776035
		{ &Z_Construct_UFunction_USimpleTextBox_GetImageVisibility, "GetImageVisibility" }, // 3758435187
		{ &Z_Construct_UFunction_USimpleTextBox_GetJustification, "GetJustification" }, // 2177748891
		{ &Z_Construct_UFunction_USimpleTextBox_GetLineHeightPercentage, "GetLineHeightPercentage" }, // 2436412377
		{ &Z_Construct_UFunction_USimpleTextBox_GetMinDesiredWidth, "GetMinDesiredWidth" }, // 381470031
		{ &Z_Construct_UFunction_USimpleTextBox_GetOverflowPolicy, "GetOverflowPolicy" }, // 2900270648
		{ &Z_Construct_UFunction_USimpleTextBox_GetPadding, "GetPadding" }, // 3954312897
		{ &Z_Construct_UFunction_USimpleTextBox_GetSimpleTextBoxType, "GetSimpleTextBoxType" }, // 1891547637
		{ &Z_Construct_UFunction_USimpleTextBox_GetSpace, "GetSpace" }, // 3694033198
		{ &Z_Construct_UFunction_USimpleTextBox_GetText, "GetText" }, // 4198311832
		{ &Z_Construct_UFunction_USimpleTextBox_GetTextColor, "GetTextColor" }, // 1290717507
		{ &Z_Construct_UFunction_USimpleTextBox_GetTextFont, "GetTextFont" }, // 1508317018
		{ &Z_Construct_UFunction_USimpleTextBox_GetTextHighlightShape, "GetTextHighlightShape" }, // 291023307
		{ &Z_Construct_UFunction_USimpleTextBox_GetTextHorizontalAlignment, "GetTextHorizontalAlignment" }, // 3540406067
		{ &Z_Construct_UFunction_USimpleTextBox_GetTextMargin, "GetTextMargin" }, // 13299460
		{ &Z_Construct_UFunction_USimpleTextBox_GetTextShadowColor, "GetTextShadowColor" }, // 2268161251
		{ &Z_Construct_UFunction_USimpleTextBox_GetTextShadowOffset, "GetTextShadowOffset" }, // 2765716602
		{ &Z_Construct_UFunction_USimpleTextBox_GetTextStrikeBrush, "GetTextStrikeBrush" }, // 813111014
		{ &Z_Construct_UFunction_USimpleTextBox_GetTextVerticalAlignment, "GetTextVerticalAlignment" }, // 1377879368
		{ &Z_Construct_UFunction_USimpleTextBox_GetTransformPolicy, "GetTransformPolicy" }, // 2501923154
		{ &Z_Construct_UFunction_USimpleTextBox_GetWrappingPolicy, "GetWrappingPolicy" }, // 1877328653
		{ &Z_Construct_UFunction_USimpleTextBox_GetWrapTextAt, "GetWrapTextAt" }, // 1248708745
		{ &Z_Construct_UFunction_USimpleTextBox_SetAutoWrapText, "SetAutoWrapText" }, // 3122547052
		{ &Z_Construct_UFunction_USimpleTextBox_SetHighlightText, "SetHighlightText" }, // 973630393
		{ &Z_Construct_UFunction_USimpleTextBox_SetImage, "SetImage" }, // 3724328908
		{ &Z_Construct_UFunction_USimpleTextBox_SetImageColor, "SetImageColor" }, // 3241083929
		{ &Z_Construct_UFunction_USimpleTextBox_SetImageHorizontalAlignment, "SetImageHorizontalAlignment" }, // 3890638043
		{ &Z_Construct_UFunction_USimpleTextBox_SetImageMargin, "SetImageMargin" }, // 81349662
		{ &Z_Construct_UFunction_USimpleTextBox_SetImageVerticalAlignment, "SetImageVerticalAlignment" }, // 2523646544
		{ &Z_Construct_UFunction_USimpleTextBox_SetImageVisibility, "SetImageVisibility" }, // 2384013883
		{ &Z_Construct_UFunction_USimpleTextBox_SetJustification, "SetJustification" }, // 419780580
		{ &Z_Construct_UFunction_USimpleTextBox_SetLineHeightPercentage, "SetLineHeightPercentage" }, // 1392714589
		{ &Z_Construct_UFunction_USimpleTextBox_SetMinDesiredWidth, "SetMinDesiredWidth" }, // 3506048709
		{ &Z_Construct_UFunction_USimpleTextBox_SetOverflowPolicy, "SetOverflowPolicy" }, // 2133194967
		{ &Z_Construct_UFunction_USimpleTextBox_SetPadding, "SetPadding" }, // 1381306240
		{ &Z_Construct_UFunction_USimpleTextBox_SetSimpleTextBoxType, "SetSimpleTextBoxType" }, // 4142241146
		{ &Z_Construct_UFunction_USimpleTextBox_SetSpace, "SetSpace" }, // 3369681872
		{ &Z_Construct_UFunction_USimpleTextBox_SetText, "SetText" }, // 1170076897
		{ &Z_Construct_UFunction_USimpleTextBox_SetTextColor, "SetTextColor" }, // 1037754176
		{ &Z_Construct_UFunction_USimpleTextBox_SetTextFont, "SetTextFont" }, // 2532661605
		{ &Z_Construct_UFunction_USimpleTextBox_SetTextHighlightShape, "SetTextHighlightShape" }, // 3255717642
		{ &Z_Construct_UFunction_USimpleTextBox_SetTextHorizontalAlignment, "SetTextHorizontalAlignment" }, // 3500509627
		{ &Z_Construct_UFunction_USimpleTextBox_SetTextMargin, "SetTextMargin" }, // 355057155
		{ &Z_Construct_UFunction_USimpleTextBox_SetTextShadowColor, "SetTextShadowColor" }, // 172763480
		{ &Z_Construct_UFunction_USimpleTextBox_SetTextShadowOffset, "SetTextShadowOffset" }, // 3119149149
		{ &Z_Construct_UFunction_USimpleTextBox_SetTextStrikeBrush, "SetTextStrikeBrush" }, // 1720717625
		{ &Z_Construct_UFunction_USimpleTextBox_SetTextVerticalAlignment, "SetTextVerticalAlignment" }, // 2150073183
		{ &Z_Construct_UFunction_USimpleTextBox_SetTransformPolicy, "SetTransformPolicy" }, // 3715973322
		{ &Z_Construct_UFunction_USimpleTextBox_SetWrappingPolicy, "SetWrappingPolicy" }, // 2218125622
		{ &Z_Construct_UFunction_USimpleTextBox_SetWrapTextAt, "SetWrapTextAt" }, // 4081210507
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USimpleTextBox>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USimpleTextBox_Statics

// ********** Begin Class USimpleTextBox Property Definitions **************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetText_WrapperImpl, &USimpleTextBox::GetText_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextColor = { "TextColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetTextColor_WrapperImpl, &USimpleTextBox::GetTextColor_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, TextColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextColor_MetaData), NewProp_TextColor_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextFont = { "TextFont", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetTextFont_WrapperImpl, &USimpleTextBox::GetTextFont_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, TextFont), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextFont_MetaData), NewProp_TextFont_MetaData) }; // 167205173
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextStrikeBrush = { "TextStrikeBrush", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetTextStrikeBrush_WrapperImpl, &USimpleTextBox::GetTextStrikeBrush_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, TextStrikeBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextStrikeBrush_MetaData), NewProp_TextStrikeBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextShadowOffset = { "TextShadowOffset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetTextShadowOffset_WrapperImpl, &USimpleTextBox::GetTextShadowOffset_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, TextShadowOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextShadowOffset_MetaData), NewProp_TextShadowOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextShadowColor = { "TextShadowColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetTextShadowColor_WrapperImpl, &USimpleTextBox::GetTextShadowColor_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, TextShadowColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextShadowColor_MetaData), NewProp_TextShadowColor_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_HighlightText = { "HighlightText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetHighlightText_WrapperImpl, &USimpleTextBox::GetHighlightText_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, HighlightText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighlightText_MetaData), NewProp_HighlightText_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextHighlightShape = { "TextHighlightShape", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetTextHighlightShape_WrapperImpl, &USimpleTextBox::GetTextHighlightShape_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, TextHighlightShape), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextHighlightShape_MetaData), NewProp_TextHighlightShape_MetaData) }; // 4278521822
void Z_Construct_UClass_USimpleTextBox_Statics::NewProp_AutoWrapText_SetBit(void* Obj)
{
	((USimpleTextBox*)Obj)->AutoWrapText = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_AutoWrapText = { "AutoWrapText", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetAutoWrapText_WrapperImpl, &USimpleTextBox::GetAutoWrapText_WrapperImpl, 1, sizeof(bool), sizeof(USimpleTextBox), &Z_Construct_UClass_USimpleTextBox_Statics::NewProp_AutoWrapText_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AutoWrapText_MetaData), NewProp_AutoWrapText_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_WrapTextAt = { "WrapTextAt", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetWrapTextAt_WrapperImpl, &USimpleTextBox::GetWrapTextAt_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, WrapTextAt), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WrapTextAt_MetaData), NewProp_WrapTextAt_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_WrappingPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_WrappingPolicy = { "WrappingPolicy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetWrappingPolicy_WrapperImpl, &USimpleTextBox::GetWrappingPolicy_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, WrappingPolicy), Z_Construct_UEnum_Slate_ETextWrappingPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WrappingPolicy_MetaData), NewProp_WrappingPolicy_MetaData) }; // 3831279660
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TransformPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TransformPolicy = { "TransformPolicy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetTransformPolicy_WrapperImpl, &USimpleTextBox::GetTransformPolicy_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, TransformPolicy), Z_Construct_UEnum_SlateCore_ETextTransformPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransformPolicy_MetaData), NewProp_TransformPolicy_MetaData) }; // 2733367800
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_Justification = { "Justification", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetJustification_WrapperImpl, &USimpleTextBox::GetJustification_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, Justification), Z_Construct_UEnum_Slate_ETextJustify, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Justification_MetaData), NewProp_Justification_MetaData) }; // 2449547307
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_MinDesiredWidth = { "MinDesiredWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetMinDesiredWidth_WrapperImpl, &USimpleTextBox::GetMinDesiredWidth_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, MinDesiredWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinDesiredWidth_MetaData), NewProp_MinDesiredWidth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_LineHeightPercentage = { "LineHeightPercentage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetLineHeightPercentage_WrapperImpl, &USimpleTextBox::GetLineHeightPercentage_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, LineHeightPercentage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LineHeightPercentage_MetaData), NewProp_LineHeightPercentage_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextMargin = { "TextMargin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetTextMargin_WrapperImpl, &USimpleTextBox::GetTextMargin_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, TextMargin), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextMargin_MetaData), NewProp_TextMargin_MetaData) }; // 4099648758
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_OverflowPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_OverflowPolicy = { "OverflowPolicy", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetOverflowPolicy_WrapperImpl, &USimpleTextBox::GetOverflowPolicy_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, OverflowPolicy), Z_Construct_UEnum_SlateCore_ETextOverflowPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverflowPolicy_MetaData), NewProp_OverflowPolicy_MetaData) }; // 1738161579
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_Space = { "Space", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetSpace_WrapperImpl, &USimpleTextBox::GetSpace_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, Space), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Space_MetaData), NewProp_Space_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_Image = { "Image", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetImage_WrapperImpl, &USimpleTextBox::GetImage_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, Image), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Image_MetaData), NewProp_Image_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageColor = { "ImageColor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetImageColor_WrapperImpl, &USimpleTextBox::GetImageColor_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, ImageColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageColor_MetaData), NewProp_ImageColor_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageMargin = { "ImageMargin", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetImageMargin_WrapperImpl, &USimpleTextBox::GetImageMargin_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, ImageMargin), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageMargin_MetaData), NewProp_ImageMargin_MetaData) }; // 4099648758
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageVisibility_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageVisibility = { "ImageVisibility", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetImageVisibility_WrapperImpl, &USimpleTextBox::GetImageVisibility_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, ImageVisibility), Z_Construct_UEnum_UMG_ESlateVisibility, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageVisibility_MetaData), NewProp_ImageVisibility_MetaData) }; // 763672810
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_SimpleTextBoxType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_SimpleTextBoxType = { "SimpleTextBoxType", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetSimpleTextBoxType_WrapperImpl, &USimpleTextBox::GetSimpleTextBoxType_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, SimpleTextBoxType), Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SimpleTextBoxType_MetaData), NewProp_SimpleTextBoxType_MetaData) }; // 1473637242
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_Padding = { "Padding", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetPadding_WrapperImpl, &USimpleTextBox::GetPadding_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, Padding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Padding_MetaData), NewProp_Padding_MetaData) }; // 4099648758
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextHorizontalAlignment = { "TextHorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetTextHorizontalAlignment_WrapperImpl, &USimpleTextBox::GetTextHorizontalAlignment_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, TextHorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextHorizontalAlignment_MetaData), NewProp_TextHorizontalAlignment_MetaData) }; // 990570535
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextVerticalAlignment = { "TextVerticalAlignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetTextVerticalAlignment_WrapperImpl, &USimpleTextBox::GetTextVerticalAlignment_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, TextVerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextVerticalAlignment_MetaData), NewProp_TextVerticalAlignment_MetaData) }; // 2496106429
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageHorizontalAlignment = { "ImageHorizontalAlignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetImageHorizontalAlignment_WrapperImpl, &USimpleTextBox::GetImageHorizontalAlignment_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, ImageHorizontalAlignment), Z_Construct_UEnum_SlateCore_EHorizontalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageHorizontalAlignment_MetaData), NewProp_ImageHorizontalAlignment_MetaData) }; // 990570535
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageVerticalAlignment = { "ImageVerticalAlignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, &USimpleTextBox::SetImageVerticalAlignment_WrapperImpl, &USimpleTextBox::GetImageVerticalAlignment_WrapperImpl, 1, STRUCT_OFFSET(USimpleTextBox, ImageVerticalAlignment), Z_Construct_UEnum_SlateCore_EVerticalAlignment, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageVerticalAlignment_MetaData), NewProp_ImageVerticalAlignment_MetaData) }; // 2496106429
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USimpleTextBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextFont,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextStrikeBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextShadowOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextShadowColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_HighlightText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextHighlightShape,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_AutoWrapText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_WrapTextAt,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_WrappingPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_WrappingPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TransformPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TransformPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_Justification,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_MinDesiredWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_LineHeightPercentage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextMargin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_OverflowPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_OverflowPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_Space,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_Image,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageMargin,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageVisibility_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageVisibility,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_SimpleTextBoxType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_SimpleTextBoxType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_Padding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextHorizontalAlignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_TextVerticalAlignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageHorizontalAlignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USimpleTextBox_Statics::NewProp_ImageVerticalAlignment,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleTextBox_Statics::PropPointers) < 2048);
// ********** End Class USimpleTextBox Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_USimpleTextBox_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleTextBox_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USimpleTextBox_Statics::ClassParams = {
	&USimpleTextBox::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USimpleTextBox_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USimpleTextBox_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USimpleTextBox_Statics::Class_MetaDataParams), Z_Construct_UClass_USimpleTextBox_Statics::Class_MetaDataParams)
};
void USimpleTextBox::StaticRegisterNativesUSimpleTextBox()
{
	UClass* Class = USimpleTextBox::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USimpleTextBox_Statics::Funcs));
}
UClass* Z_Construct_UClass_USimpleTextBox()
{
	if (!Z_Registration_Info_UClass_USimpleTextBox.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USimpleTextBox.OuterSingleton, Z_Construct_UClass_USimpleTextBox_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USimpleTextBox.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USimpleTextBox);
USimpleTextBox::~USimpleTextBox() {}
// ********** End Class USimpleTextBox *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h__Script_GenericSlateFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USimpleTextBox, USimpleTextBox::StaticClass, TEXT("USimpleTextBox"), &Z_Registration_Info_UClass_USimpleTextBox, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USimpleTextBox), 3137441333U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h__Script_GenericSlateFramework_2563234992{
	TEXT("/Script/GenericSlateFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h__Script_GenericSlateFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SimpleTextBox_h__Script_GenericSlateFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
