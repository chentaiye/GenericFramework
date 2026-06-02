// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UWidget/SwitchableTextBlock.h"
#include "Components/TextWidgetTypes.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSwitchableTextBlock() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USwitchableTextBlock();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_USwitchableTextBlock_NoRegister();
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode();
GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature();
GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature();
SLATE_API UEnum* Z_Construct_UEnum_Slate_ETextJustify();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextCommit();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextOverflowPolicy();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextTransformPolicy();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateColor();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateFontInfo();
UMG_API UClass* Z_Construct_UClass_UWidget();
UMG_API UScriptStruct* Z_Construct_UScriptStruct_FShapedTextOptions();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnSwitchableTextChangedEvent *****************************************
struct Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics
{
	struct _Script_GenericSlateFramework_eventOnSwitchableTextChangedEvent_Parms
	{
		FText Text;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnSwitchableTextChangedEvent constinit property declarations *********
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnSwitchableTextChangedEvent constinit property declarations ***********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnSwitchableTextChangedEvent Property Definitions ********************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericSlateFramework_eventOnSwitchableTextChangedEvent_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::NewProp_Text,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnSwitchableTextChangedEvent Property Definitions **********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework, nullptr, "OnSwitchableTextChangedEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnSwitchableTextChangedEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnSwitchableTextChangedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSwitchableTextChangedEvent_DelegateWrapper(const FMulticastScriptDelegate& OnSwitchableTextChangedEvent, FText const& Text)
{
	struct _Script_GenericSlateFramework_eventOnSwitchableTextChangedEvent_Parms
	{
		FText Text;
	};
	_Script_GenericSlateFramework_eventOnSwitchableTextChangedEvent_Parms Parms;
	Parms.Text=Text;
	OnSwitchableTextChangedEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnSwitchableTextChangedEvent *******************************************

// ********** Begin Delegate FOnSwitchableTextCommittedEvent ***************************************
struct Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics
{
	struct _Script_GenericSlateFramework_eventOnSwitchableTextCommittedEvent_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnSwitchableTextCommittedEvent constinit property declarations *******
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FBytePropertyParams NewProp_CommitMethod;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnSwitchableTextCommittedEvent constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnSwitchableTextCommittedEvent Property Definitions ******************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericSlateFramework_eventOnSwitchableTextCommittedEvent_Parms, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::NewProp_CommitMethod = { "CommitMethod", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericSlateFramework_eventOnSwitchableTextCommittedEvent_Parms, CommitMethod), Z_Construct_UEnum_SlateCore_ETextCommit, METADATA_PARAMS(0, nullptr) }; // 1235926667
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::NewProp_CommitMethod,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnSwitchableTextCommittedEvent Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework, nullptr, "OnSwitchableTextCommittedEvent__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnSwitchableTextCommittedEvent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnSwitchableTextCommittedEvent_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnSwitchableTextCommittedEvent_DelegateWrapper(const FMulticastScriptDelegate& OnSwitchableTextCommittedEvent, FText const& Text, ETextCommit::Type CommitMethod)
{
	struct _Script_GenericSlateFramework_eventOnSwitchableTextCommittedEvent_Parms
	{
		FText Text;
		TEnumAsByte<ETextCommit::Type> CommitMethod;
	};
	_Script_GenericSlateFramework_eventOnSwitchableTextCommittedEvent_Parms Parms;
	Parms.Text=Text;
	Parms.CommitMethod=CommitMethod;
	OnSwitchableTextCommittedEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnSwitchableTextCommittedEvent *****************************************

// ********** Begin Class USwitchableTextBlock Function GetColorAndOpacity *************************
struct Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics
{
	struct SwitchableTextBlock_eventGetColorAndOpacity_Parms
	{
		FSlateColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetColorAndOpacity_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(0, nullptr) }; // 1663967387
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::PropPointers) < 2048);
// ********** End Function GetColorAndOpacity Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetColorAndOpacity", 	Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::SwitchableTextBlock_eventGetColorAndOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::SwitchableTextBlock_eventGetColorAndOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetColorAndOpacity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateColor*)Z_Param__Result=P_THIS->GetColorAndOpacity();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetColorAndOpacity ***************************

// ********** Begin Class USwitchableTextBlock Function GetFont ************************************
struct Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics
{
	struct SwitchableTextBlock_eventGetFont_Parms
	{
		FSlateFontInfo ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetFont_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 167205173
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::PropPointers) < 2048);
// ********** End Function GetFont Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetFont", 	Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::SwitchableTextBlock_eventGetFont_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::SwitchableTextBlock_eventGetFont_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetFont()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetFont_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetFont)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateFontInfo*)Z_Param__Result=P_THIS->GetFont();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetFont **************************************

// ********** Begin Class USwitchableTextBlock Function GetHintText ********************************
struct Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics
{
	struct SwitchableTextBlock_eventGetHintText_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x8f\x90\xe7\xa4\xba\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x8f\x90\xe7\xa4\xba\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetHintText constinit property declarations ***************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHintText constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHintText Property Definitions **************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetHintText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::PropPointers) < 2048);
// ********** End Function GetHintText Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetHintText", 	Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::SwitchableTextBlock_eventGetHintText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::SwitchableTextBlock_eventGetHintText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetHintText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetHintText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetHintText)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetHintText();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetHintText **********************************

// ********** Begin Class USwitchableTextBlock Function GetIsReadOnly ******************************
struct Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics
{
	struct SwitchableTextBlock_eventGetIsReadOnly_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x8f\xaa\xe8\xaf\xbb\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x8f\xaa\xe8\xaf\xbb\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetIsReadOnly constinit property declarations *************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetIsReadOnly constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetIsReadOnly Property Definitions ************************************
void Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((SwitchableTextBlock_eventGetIsReadOnly_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SwitchableTextBlock_eventGetIsReadOnly_Parms), &Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::PropPointers) < 2048);
// ********** End Function GetIsReadOnly Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetIsReadOnly", 	Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::SwitchableTextBlock_eventGetIsReadOnly_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::SwitchableTextBlock_eventGetIsReadOnly_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetIsReadOnly)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetIsReadOnly();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetIsReadOnly ********************************

// ********** Begin Class USwitchableTextBlock Function GetJustification ***************************
struct Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics
{
	struct SwitchableTextBlock_eventGetJustification_Parms
	{
		TEnumAsByte<ETextJustify::Type> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\xaf\xb9\xe9\xbd\x90\xe6\x96\xb9\xe5\xbc\x8f\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetJustification_Parms, ReturnValue), Z_Construct_UEnum_Slate_ETextJustify, METADATA_PARAMS(0, nullptr) }; // 2449547307
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::PropPointers) < 2048);
// ********** End Function GetJustification Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetJustification", 	Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::SwitchableTextBlock_eventGetJustification_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::SwitchableTextBlock_eventGetJustification_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetJustification()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetJustification_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetJustification)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TEnumAsByte<ETextJustify::Type>*)Z_Param__Result=P_THIS->GetJustification();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetJustification *****************************

// ********** Begin Class USwitchableTextBlock Function GetMinDesiredWidth *************************
struct Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics
{
	struct SwitchableTextBlock_eventGetMinDesiredWidth_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetMinDesiredWidth_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::PropPointers) < 2048);
// ********** End Function GetMinDesiredWidth Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetMinDesiredWidth", 	Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::SwitchableTextBlock_eventGetMinDesiredWidth_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::SwitchableTextBlock_eventGetMinDesiredWidth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetMinDesiredWidth)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->GetMinDesiredWidth();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetMinDesiredWidth ***************************

// ********** Begin Class USwitchableTextBlock Function GetMode ************************************
struct Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics
{
	struct SwitchableTextBlock_eventGetMode_Parms
	{
		ESwitchableTextBlockMode ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x98\xbe\xe7\xa4\xba\xe6\xa8\xa1\xe5\xbc\x8f\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x98\xbe\xe7\xa4\xba\xe6\xa8\xa1\xe5\xbc\x8f\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMode constinit property declarations *******************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMode constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMode Property Definitions ******************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetMode_Parms, ReturnValue), Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode, METADATA_PARAMS(0, nullptr) }; // 2053230862
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::PropPointers) < 2048);
// ********** End Function GetMode Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetMode", 	Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::SwitchableTextBlock_eventGetMode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::SwitchableTextBlock_eventGetMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetMode)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ESwitchableTextBlockMode*)Z_Param__Result=P_THIS->GetMode();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetMode **************************************

// ********** Begin Class USwitchableTextBlock Function GetShadowColorAndOpacity *******************
struct Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics
{
	struct SwitchableTextBlock_eventGetShadowColorAndOpacity_Parms
	{
		FLinearColor ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetShadowColorAndOpacity_Parms, ReturnValue), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::PropPointers) < 2048);
// ********** End Function GetShadowColorAndOpacity Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetShadowColorAndOpacity", 	Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::SwitchableTextBlock_eventGetShadowColorAndOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::SwitchableTextBlock_eventGetShadowColorAndOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetShadowColorAndOpacity)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FLinearColor*)Z_Param__Result=P_THIS->GetShadowColorAndOpacity();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetShadowColorAndOpacity *********************

// ********** Begin Class USwitchableTextBlock Function GetShadowOffset ****************************
struct Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics
{
	struct SwitchableTextBlock_eventGetShadowOffset_Parms
	{
		FVector2D ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetShadowOffset_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::PropPointers) < 2048);
// ********** End Function GetShadowOffset Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetShadowOffset", 	Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::SwitchableTextBlock_eventGetShadowOffset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::SwitchableTextBlock_eventGetShadowOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetShadowOffset)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FVector2D*)Z_Param__Result=P_THIS->GetShadowOffset();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetShadowOffset ******************************

// ********** Begin Class USwitchableTextBlock Function GetStrikeBrush *****************************
struct Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics
{
	struct SwitchableTextBlock_eventGetStrikeBrush_Parms
	{
		FSlateBrush ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetStrikeBrush constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetStrikeBrush constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetStrikeBrush Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetStrikeBrush_Parms, ReturnValue), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 4278521822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::PropPointers) < 2048);
// ********** End Function GetStrikeBrush Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetStrikeBrush", 	Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::SwitchableTextBlock_eventGetStrikeBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::SwitchableTextBlock_eventGetStrikeBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetStrikeBrush)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FSlateBrush*)Z_Param__Result=P_THIS->GetStrikeBrush();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetStrikeBrush *******************************

// ********** Begin Class USwitchableTextBlock Function GetText ************************************
struct Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics
{
	struct SwitchableTextBlock_eventGetText_Parms
	{
		FText ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::PropPointers) < 2048);
// ********** End Function GetText Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetText", 	Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::SwitchableTextBlock_eventGetText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::SwitchableTextBlock_eventGetText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetText)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetText();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetText **************************************

// ********** Begin Class USwitchableTextBlock Function GetTextOverflowPolicy **********************
struct Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics
{
	struct SwitchableTextBlock_eventGetTextOverflowPolicy_Parms
	{
		ETextOverflowPolicy ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetTextOverflowPolicy_Parms, ReturnValue), Z_Construct_UEnum_SlateCore_ETextOverflowPolicy, METADATA_PARAMS(0, nullptr) }; // 1738161579
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::PropPointers) < 2048);
// ********** End Function GetTextOverflowPolicy Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetTextOverflowPolicy", 	Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::SwitchableTextBlock_eventGetTextOverflowPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::SwitchableTextBlock_eventGetTextOverflowPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetTextOverflowPolicy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ETextOverflowPolicy*)Z_Param__Result=P_THIS->GetTextOverflowPolicy();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetTextOverflowPolicy ************************

// ********** Begin Class USwitchableTextBlock Function GetTextTransformPolicy *********************
struct Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics
{
	struct SwitchableTextBlock_eventGetTextTransformPolicy_Parms
	{
		ETextTransformPolicy ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventGetTextTransformPolicy_Parms, ReturnValue), Z_Construct_UEnum_SlateCore_ETextTransformPolicy, METADATA_PARAMS(0, nullptr) }; // 2733367800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::PropPointers) < 2048);
// ********** End Function GetTextTransformPolicy Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "GetTextTransformPolicy", 	Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::SwitchableTextBlock_eventGetTextTransformPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::SwitchableTextBlock_eventGetTextTransformPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execGetTextTransformPolicy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ETextTransformPolicy*)Z_Param__Result=P_THIS->GetTextTransformPolicy();
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function GetTextTransformPolicy ***********************

// ********** Begin Class USwitchableTextBlock Function SetColorAndOpacity *************************
struct Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics
{
	struct SwitchableTextBlock_eventSetColorAndOpacity_Parms
	{
		FSlateColor InColorAndOpacity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::NewProp_InColorAndOpacity = { "InColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetColorAndOpacity_Parms, InColorAndOpacity), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(0, nullptr) }; // 1663967387
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::NewProp_InColorAndOpacity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetColorAndOpacity Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetColorAndOpacity", 	Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::SwitchableTextBlock_eventSetColorAndOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::SwitchableTextBlock_eventSetColorAndOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetColorAndOpacity)
{
	P_GET_STRUCT(FSlateColor,Z_Param_InColorAndOpacity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetColorAndOpacity(Z_Param_InColorAndOpacity);
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetColorAndOpacity ***************************

// ********** Begin Class USwitchableTextBlock Function SetFont ************************************
struct Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics
{
	struct SwitchableTextBlock_eventSetFont_Parms
	{
		FSlateFontInfo InFontInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe4\xbd\x93\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetFont constinit property declarations *******************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InFontInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFont constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFont Property Definitions ******************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::NewProp_InFontInfo = { "InFontInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetFont_Parms, InFontInfo), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(0, nullptr) }; // 167205173
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::NewProp_InFontInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::PropPointers) < 2048);
// ********** End Function SetFont Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetFont", 	Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::SwitchableTextBlock_eventSetFont_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::SwitchableTextBlock_eventSetFont_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetFont()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetFont_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetFont)
{
	P_GET_STRUCT(FSlateFontInfo,Z_Param_InFontInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetFont(Z_Param_InFontInfo);
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetFont **************************************

// ********** Begin Class USwitchableTextBlock Function SetHintText ********************************
struct Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics
{
	struct SwitchableTextBlock_eventSetHintText_Parms
	{
		FText InHintText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x8f\x90\xe7\xa4\xba\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x8f\x90\xe7\xa4\xba\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetHintText constinit property declarations ***************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InHintText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetHintText constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetHintText Property Definitions **************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::NewProp_InHintText = { "InHintText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetHintText_Parms, InHintText), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::NewProp_InHintText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::PropPointers) < 2048);
// ********** End Function SetHintText Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetHintText", 	Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::SwitchableTextBlock_eventSetHintText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::SwitchableTextBlock_eventSetHintText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetHintText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetHintText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetHintText)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InHintText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetHintText(Z_Param_InHintText);
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetHintText **********************************

// ********** Begin Class USwitchableTextBlock Function SetIsReadOnly ******************************
struct Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics
{
	struct SwitchableTextBlock_eventSetIsReadOnly_Parms
	{
		bool bInIsReadOnly;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x8f\xaa\xe8\xaf\xbb\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x8f\xaa\xe8\xaf\xbb\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetIsReadOnly constinit property declarations *************************
	static void NewProp_bInIsReadOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bInIsReadOnly;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetIsReadOnly constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetIsReadOnly Property Definitions ************************************
void Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::NewProp_bInIsReadOnly_SetBit(void* Obj)
{
	((SwitchableTextBlock_eventSetIsReadOnly_Parms*)Obj)->bInIsReadOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::NewProp_bInIsReadOnly = { "bInIsReadOnly", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(SwitchableTextBlock_eventSetIsReadOnly_Parms), &Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::NewProp_bInIsReadOnly_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::NewProp_bInIsReadOnly,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::PropPointers) < 2048);
// ********** End Function SetIsReadOnly Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetIsReadOnly", 	Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::SwitchableTextBlock_eventSetIsReadOnly_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::SwitchableTextBlock_eventSetIsReadOnly_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetIsReadOnly)
{
	P_GET_UBOOL(Z_Param_bInIsReadOnly);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetIsReadOnly(Z_Param_bInIsReadOnly);
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetIsReadOnly ********************************

// ********** Begin Class USwitchableTextBlock Function SetJustification ***************************
struct Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics
{
	struct SwitchableTextBlock_eventSetJustification_Parms
	{
		TEnumAsByte<ETextJustify::Type> InJustification;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\xaf\xb9\xe9\xbd\x90\xe6\x96\xb9\xe5\xbc\x8f\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::NewProp_InJustification = { "InJustification", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetJustification_Parms, InJustification), Z_Construct_UEnum_Slate_ETextJustify, METADATA_PARAMS(0, nullptr) }; // 2449547307
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::NewProp_InJustification,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::PropPointers) < 2048);
// ********** End Function SetJustification Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetJustification", 	Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::SwitchableTextBlock_eventSetJustification_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::SwitchableTextBlock_eventSetJustification_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetJustification()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetJustification_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetJustification)
{
	P_GET_PROPERTY(FByteProperty,Z_Param_InJustification);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetJustification(ETextJustify::Type(Z_Param_InJustification));
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetJustification *****************************

// ********** Begin Class USwitchableTextBlock Function SetMinDesiredWidth *************************
struct Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics
{
	struct SwitchableTextBlock_eventSetMinDesiredWidth_Parms
	{
		float InMinDesiredWidth;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::NewProp_InMinDesiredWidth = { "InMinDesiredWidth", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetMinDesiredWidth_Parms, InMinDesiredWidth), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::NewProp_InMinDesiredWidth,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::PropPointers) < 2048);
// ********** End Function SetMinDesiredWidth Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetMinDesiredWidth", 	Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::SwitchableTextBlock_eventSetMinDesiredWidth_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::SwitchableTextBlock_eventSetMinDesiredWidth_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetMinDesiredWidth)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_InMinDesiredWidth);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMinDesiredWidth(Z_Param_InMinDesiredWidth);
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetMinDesiredWidth ***************************

// ********** Begin Class USwitchableTextBlock Function SetMode ************************************
struct Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics
{
	struct SwitchableTextBlock_eventSetMode_Parms
	{
		ESwitchableTextBlockMode InMode;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x98\xbe\xe7\xa4\xba\xe6\xa8\xa1\xe5\xbc\x8f\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe6\x98\xbe\xe7\xa4\xba\xe6\xa8\xa1\xe5\xbc\x8f\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMode constinit property declarations *******************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InMode;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMode constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMode Property Definitions ******************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::NewProp_InMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::NewProp_InMode = { "InMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetMode_Parms, InMode), Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode, METADATA_PARAMS(0, nullptr) }; // 2053230862
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::NewProp_InMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::NewProp_InMode,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::PropPointers) < 2048);
// ********** End Function SetMode Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetMode", 	Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::SwitchableTextBlock_eventSetMode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::SwitchableTextBlock_eventSetMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetMode)
{
	P_GET_ENUM(ESwitchableTextBlockMode,Z_Param_InMode);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetMode(ESwitchableTextBlockMode(Z_Param_InMode));
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetMode **************************************

// ********** Begin Class USwitchableTextBlock Function SetShadowColorAndOpacity *******************
struct Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics
{
	struct SwitchableTextBlock_eventSetShadowColorAndOpacity_Parms
	{
		FLinearColor InShadowColorAndOpacity;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::NewProp_InShadowColorAndOpacity = { "InShadowColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetShadowColorAndOpacity_Parms, InShadowColorAndOpacity), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::NewProp_InShadowColorAndOpacity,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::PropPointers) < 2048);
// ********** End Function SetShadowColorAndOpacity Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetShadowColorAndOpacity", 	Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::SwitchableTextBlock_eventSetShadowColorAndOpacity_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::SwitchableTextBlock_eventSetShadowColorAndOpacity_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetShadowColorAndOpacity)
{
	P_GET_STRUCT(FLinearColor,Z_Param_InShadowColorAndOpacity);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShadowColorAndOpacity(Z_Param_InShadowColorAndOpacity);
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetShadowColorAndOpacity *********************

// ********** Begin Class USwitchableTextBlock Function SetShadowOffset ****************************
struct Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics
{
	struct SwitchableTextBlock_eventSetShadowOffset_Parms
	{
		FVector2D InShadowOffset;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::NewProp_InShadowOffset = { "InShadowOffset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetShadowOffset_Parms, InShadowOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::NewProp_InShadowOffset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::PropPointers) < 2048);
// ********** End Function SetShadowOffset Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetShadowOffset", 	Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::SwitchableTextBlock_eventSetShadowOffset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::SwitchableTextBlock_eventSetShadowOffset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetShadowOffset)
{
	P_GET_STRUCT(FVector2D,Z_Param_InShadowOffset);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetShadowOffset(Z_Param_InShadowOffset);
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetShadowOffset ******************************

// ********** Begin Class USwitchableTextBlock Function SetStrikeBrush *****************************
struct Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics
{
	struct SwitchableTextBlock_eventSetStrikeBrush_Parms
	{
		FSlateBrush InStrikeBrush;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetStrikeBrush constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InStrikeBrush;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetStrikeBrush constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetStrikeBrush Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::NewProp_InStrikeBrush = { "InStrikeBrush", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetStrikeBrush_Parms, InStrikeBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(0, nullptr) }; // 4278521822
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::NewProp_InStrikeBrush,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::PropPointers) < 2048);
// ********** End Function SetStrikeBrush Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetStrikeBrush", 	Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::SwitchableTextBlock_eventSetStrikeBrush_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::SwitchableTextBlock_eventSetStrikeBrush_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetStrikeBrush)
{
	P_GET_STRUCT(FSlateBrush,Z_Param_InStrikeBrush);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetStrikeBrush(Z_Param_InStrikeBrush);
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetStrikeBrush *******************************

// ********** Begin Class USwitchableTextBlock Function SetText ************************************
struct Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics
{
	struct SwitchableTextBlock_eventSetText_Parms
	{
		FText InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetText_Parms, InText), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::PropPointers) < 2048);
// ********** End Function SetText Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetText", 	Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::SwitchableTextBlock_eventSetText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::SwitchableTextBlock_eventSetText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetText)
{
	P_GET_PROPERTY(FTextProperty,Z_Param_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetText(Z_Param_InText);
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetText **************************************

// ********** Begin Class USwitchableTextBlock Function SetTextOverflowPolicy **********************
struct Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics
{
	struct SwitchableTextBlock_eventSetTextOverflowPolicy_Parms
	{
		ETextOverflowPolicy InOverflowPolicy;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::NewProp_InOverflowPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::NewProp_InOverflowPolicy = { "InOverflowPolicy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetTextOverflowPolicy_Parms, InOverflowPolicy), Z_Construct_UEnum_SlateCore_ETextOverflowPolicy, METADATA_PARAMS(0, nullptr) }; // 1738161579
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::NewProp_InOverflowPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::NewProp_InOverflowPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::PropPointers) < 2048);
// ********** End Function SetTextOverflowPolicy Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetTextOverflowPolicy", 	Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::SwitchableTextBlock_eventSetTextOverflowPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::SwitchableTextBlock_eventSetTextOverflowPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetTextOverflowPolicy)
{
	P_GET_ENUM(ETextOverflowPolicy,Z_Param_InOverflowPolicy);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextOverflowPolicy(ETextOverflowPolicy(Z_Param_InOverflowPolicy));
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetTextOverflowPolicy ************************

// ********** Begin Class USwitchableTextBlock Function SetTextTransformPolicy *********************
struct Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics
{
	struct SwitchableTextBlock_eventSetTextTransformPolicy_Parms
	{
		ETextTransformPolicy InTransformPolicy;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Switchable Text|Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
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
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::NewProp_InTransformPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::NewProp_InTransformPolicy = { "InTransformPolicy", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(SwitchableTextBlock_eventSetTextTransformPolicy_Parms, InTransformPolicy), Z_Construct_UEnum_SlateCore_ETextTransformPolicy, METADATA_PARAMS(0, nullptr) }; // 2733367800
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::NewProp_InTransformPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::NewProp_InTransformPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::PropPointers) < 2048);
// ********** End Function SetTextTransformPolicy Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USwitchableTextBlock, nullptr, "SetTextTransformPolicy", 	Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::SwitchableTextBlock_eventSetTextTransformPolicy_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::Function_MetaDataParams), Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::SwitchableTextBlock_eventSetTextTransformPolicy_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USwitchableTextBlock::execSetTextTransformPolicy)
{
	P_GET_ENUM(ETextTransformPolicy,Z_Param_InTransformPolicy);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetTextTransformPolicy(ETextTransformPolicy(Z_Param_InTransformPolicy));
	P_NATIVE_END;
}
// ********** End Class USwitchableTextBlock Function SetTextTransformPolicy ***********************

// ********** Begin Class USwitchableTextBlock *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USwitchableTextBlock;
UClass* USwitchableTextBlock::GetPrivateStaticClass()
{
	using TClass = USwitchableTextBlock;
	if (!Z_Registration_Info_UClass_USwitchableTextBlock.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SwitchableTextBlock"),
			Z_Registration_Info_UClass_USwitchableTextBlock.InnerSingleton,
			StaticRegisterNativesUSwitchableTextBlock,
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
	return Z_Registration_Info_UClass_USwitchableTextBlock.InnerSingleton;
}
UClass* Z_Construct_UClass_USwitchableTextBlock_NoRegister()
{
	return USwitchableTextBlock::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USwitchableTextBlock_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe5\x8f\xaf\xe5\x88\x87\xe6\x8d\xa2\xe6\x96\x87\xe6\x9c\xac UMG \xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "Switchable Text" },
		{ "IncludePath", "UWidget/SwitchableTextBlock.h" },
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe5\x8f\xaf\xe5\x88\x87\xe6\x8d\xa2\xe6\x96\x87\xe6\x9c\xac UMG \xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTextChanged_MetaData[] = {
		{ "Category", "Switchable Text" },
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnTextCommitted_MetaData[] = {
		{ "Category", "Switchable Text" },
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Text_MetaData[] = {
		{ "Category", "Content" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x86\x85\xe5\xae\xb9\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x86\x85\xe5\xae\xb9\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HintText_MetaData[] = {
		{ "Category", "Content" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x8f\x90\xe7\xa4\xba\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x8f\x90\xe7\xa4\xba\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mode_MetaData[] = {
		{ "Category", "Content" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xba\xe6\xa8\xa1\xe5\xbc\x8f\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x98\xbe\xe7\xa4\xba\xe6\xa8\xa1\xe5\xbc\x8f\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Font_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xad\x97\xe4\xbd\x93\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xad\x97\xe4\xbd\x93\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ColorAndOpacity_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShadowOffset_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShadowColorAndOpacity_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "Shadow Color" },
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StrikeBrush_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinDesiredWidth_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9c\x80\xe5\xb0\x8f\xe6\x9c\x9f\xe6\x9c\x9b\xe5\xae\xbd\xe5\xba\xa6\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverflowPolicy_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "Overflow Policy" },
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransformPolicy_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "Transform Policy" },
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Justification_MetaData[] = {
		{ "Category", "Appearance" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\xaf\xb9\xe9\xbd\x90\xe6\x96\xb9\xe5\xbc\x8f\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\xaf\xb9\xe9\xbd\x90\xe6\x96\xb9\xe5\xbc\x8f\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShapedTextOptions_MetaData[] = {
		{ "Category", "Localization" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Shaped\xe6\x96\x87\xe6\x9c\xac\xe9\x80\x89\xe9\xa1\xb9\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
		{ "ShowOnlyInnerProperties", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Shaped\xe6\x96\x87\xe6\x9c\xac\xe9\x80\x89\xe9\xa1\xb9\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsReadOnly_MetaData[] = {
		{ "Category", "Behavior" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xb0\xe5\xbd\x95\xe5\x8f\xaa\xe8\xaf\xbb\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe6\x8e\xa7\xe5\x88\xb6\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe6\x88\x96\xe5\x88\x87\xe6\x8d\xa2\xe6\xb5\x81\xe7\xa8\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/SwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xb0\xe5\xbd\x95\xe5\x8f\xaa\xe8\xaf\xbb\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe6\x8e\xa7\xe5\x88\xb6\xe5\x90\x8e\xe7\xbb\xad\xe5\x90\x8c\xe6\xad\xa5\xe6\x88\x96\xe5\x88\x87\xe6\x8d\xa2\xe6\xb5\x81\xe7\xa8\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class USwitchableTextBlock constinit property declarations *********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTextChanged;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnTextCommitted;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Text;
	static const UECodeGen_Private::FTextPropertyParams NewProp_HintText;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Mode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Mode;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Font;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ColorAndOpacity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShadowOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShadowColorAndOpacity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StrikeBrush;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MinDesiredWidth;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OverflowPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OverflowPolicy;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransformPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransformPolicy;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Justification;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShapedTextOptions;
	static void NewProp_bIsReadOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsReadOnly;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class USwitchableTextBlock constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetColorAndOpacity"), .Pointer = &USwitchableTextBlock::execGetColorAndOpacity },
		{ .NameUTF8 = UTF8TEXT("GetFont"), .Pointer = &USwitchableTextBlock::execGetFont },
		{ .NameUTF8 = UTF8TEXT("GetHintText"), .Pointer = &USwitchableTextBlock::execGetHintText },
		{ .NameUTF8 = UTF8TEXT("GetIsReadOnly"), .Pointer = &USwitchableTextBlock::execGetIsReadOnly },
		{ .NameUTF8 = UTF8TEXT("GetJustification"), .Pointer = &USwitchableTextBlock::execGetJustification },
		{ .NameUTF8 = UTF8TEXT("GetMinDesiredWidth"), .Pointer = &USwitchableTextBlock::execGetMinDesiredWidth },
		{ .NameUTF8 = UTF8TEXT("GetMode"), .Pointer = &USwitchableTextBlock::execGetMode },
		{ .NameUTF8 = UTF8TEXT("GetShadowColorAndOpacity"), .Pointer = &USwitchableTextBlock::execGetShadowColorAndOpacity },
		{ .NameUTF8 = UTF8TEXT("GetShadowOffset"), .Pointer = &USwitchableTextBlock::execGetShadowOffset },
		{ .NameUTF8 = UTF8TEXT("GetStrikeBrush"), .Pointer = &USwitchableTextBlock::execGetStrikeBrush },
		{ .NameUTF8 = UTF8TEXT("GetText"), .Pointer = &USwitchableTextBlock::execGetText },
		{ .NameUTF8 = UTF8TEXT("GetTextOverflowPolicy"), .Pointer = &USwitchableTextBlock::execGetTextOverflowPolicy },
		{ .NameUTF8 = UTF8TEXT("GetTextTransformPolicy"), .Pointer = &USwitchableTextBlock::execGetTextTransformPolicy },
		{ .NameUTF8 = UTF8TEXT("SetColorAndOpacity"), .Pointer = &USwitchableTextBlock::execSetColorAndOpacity },
		{ .NameUTF8 = UTF8TEXT("SetFont"), .Pointer = &USwitchableTextBlock::execSetFont },
		{ .NameUTF8 = UTF8TEXT("SetHintText"), .Pointer = &USwitchableTextBlock::execSetHintText },
		{ .NameUTF8 = UTF8TEXT("SetIsReadOnly"), .Pointer = &USwitchableTextBlock::execSetIsReadOnly },
		{ .NameUTF8 = UTF8TEXT("SetJustification"), .Pointer = &USwitchableTextBlock::execSetJustification },
		{ .NameUTF8 = UTF8TEXT("SetMinDesiredWidth"), .Pointer = &USwitchableTextBlock::execSetMinDesiredWidth },
		{ .NameUTF8 = UTF8TEXT("SetMode"), .Pointer = &USwitchableTextBlock::execSetMode },
		{ .NameUTF8 = UTF8TEXT("SetShadowColorAndOpacity"), .Pointer = &USwitchableTextBlock::execSetShadowColorAndOpacity },
		{ .NameUTF8 = UTF8TEXT("SetShadowOffset"), .Pointer = &USwitchableTextBlock::execSetShadowOffset },
		{ .NameUTF8 = UTF8TEXT("SetStrikeBrush"), .Pointer = &USwitchableTextBlock::execSetStrikeBrush },
		{ .NameUTF8 = UTF8TEXT("SetText"), .Pointer = &USwitchableTextBlock::execSetText },
		{ .NameUTF8 = UTF8TEXT("SetTextOverflowPolicy"), .Pointer = &USwitchableTextBlock::execSetTextOverflowPolicy },
		{ .NameUTF8 = UTF8TEXT("SetTextTransformPolicy"), .Pointer = &USwitchableTextBlock::execSetTextTransformPolicy },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetColorAndOpacity, "GetColorAndOpacity" }, // 2680307013
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetFont, "GetFont" }, // 140503122
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetHintText, "GetHintText" }, // 2621440100
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetIsReadOnly, "GetIsReadOnly" }, // 3714732070
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetJustification, "GetJustification" }, // 4153765903
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetMinDesiredWidth, "GetMinDesiredWidth" }, // 584352967
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetMode, "GetMode" }, // 2492892036
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetShadowColorAndOpacity, "GetShadowColorAndOpacity" }, // 3407072155
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetShadowOffset, "GetShadowOffset" }, // 1196502628
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetStrikeBrush, "GetStrikeBrush" }, // 3106447312
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetText, "GetText" }, // 3827826680
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetTextOverflowPolicy, "GetTextOverflowPolicy" }, // 2855528120
		{ &Z_Construct_UFunction_USwitchableTextBlock_GetTextTransformPolicy, "GetTextTransformPolicy" }, // 1767292584
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetColorAndOpacity, "SetColorAndOpacity" }, // 4177143226
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetFont, "SetFont" }, // 1622450274
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetHintText, "SetHintText" }, // 2574438386
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetIsReadOnly, "SetIsReadOnly" }, // 3077716426
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetJustification, "SetJustification" }, // 1888645081
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetMinDesiredWidth, "SetMinDesiredWidth" }, // 3484819943
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetMode, "SetMode" }, // 432914300
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetShadowColorAndOpacity, "SetShadowColorAndOpacity" }, // 1682386090
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetShadowOffset, "SetShadowOffset" }, // 4124952077
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetStrikeBrush, "SetStrikeBrush" }, // 3638919372
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetText, "SetText" }, // 3922582651
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetTextOverflowPolicy, "SetTextOverflowPolicy" }, // 2980192565
		{ &Z_Construct_UFunction_USwitchableTextBlock_SetTextTransformPolicy, "SetTextTransformPolicy" }, // 2109226569
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USwitchableTextBlock>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USwitchableTextBlock_Statics

// ********** Begin Class USwitchableTextBlock Property Definitions ********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_OnTextChanged = { "OnTextChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, OnTextChanged), Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTextChanged_MetaData), NewProp_OnTextChanged_MetaData) }; // 1231679425
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_OnTextCommitted = { "OnTextCommitted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, OnTextCommitted), Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnTextCommitted_MetaData), NewProp_OnTextCommitted_MetaData) }; // 1106168029
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_Text = { "Text", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, Text), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Text_MetaData), NewProp_Text_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_HintText = { "HintText", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, HintText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HintText_MetaData), NewProp_HintText_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_Mode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_Mode = { "Mode", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, Mode), Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mode_MetaData), NewProp_Mode_MetaData) }; // 2053230862
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_Font = { "Font", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, Font), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Font_MetaData), NewProp_Font_MetaData) }; // 167205173
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_ColorAndOpacity = { "ColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, ColorAndOpacity), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ColorAndOpacity_MetaData), NewProp_ColorAndOpacity_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_ShadowOffset = { "ShadowOffset", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, ShadowOffset), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShadowOffset_MetaData), NewProp_ShadowOffset_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_ShadowColorAndOpacity = { "ShadowColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, ShadowColorAndOpacity), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShadowColorAndOpacity_MetaData), NewProp_ShadowColorAndOpacity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_StrikeBrush = { "StrikeBrush", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, StrikeBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StrikeBrush_MetaData), NewProp_StrikeBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_MinDesiredWidth = { "MinDesiredWidth", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, MinDesiredWidth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinDesiredWidth_MetaData), NewProp_MinDesiredWidth_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_OverflowPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_OverflowPolicy = { "OverflowPolicy", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, OverflowPolicy), Z_Construct_UEnum_SlateCore_ETextOverflowPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverflowPolicy_MetaData), NewProp_OverflowPolicy_MetaData) }; // 1738161579
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_TransformPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_TransformPolicy = { "TransformPolicy", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, TransformPolicy), Z_Construct_UEnum_SlateCore_ETextTransformPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransformPolicy_MetaData), NewProp_TransformPolicy_MetaData) }; // 2733367800
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_Justification = { "Justification", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, Justification), Z_Construct_UEnum_Slate_ETextJustify, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Justification_MetaData), NewProp_Justification_MetaData) }; // 2449547307
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_ShapedTextOptions = { "ShapedTextOptions", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(USwitchableTextBlock, ShapedTextOptions), Z_Construct_UScriptStruct_FShapedTextOptions, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShapedTextOptions_MetaData), NewProp_ShapedTextOptions_MetaData) }; // 3514751388
void Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_bIsReadOnly_SetBit(void* Obj)
{
	((USwitchableTextBlock*)Obj)->bIsReadOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_bIsReadOnly = { "bIsReadOnly", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(USwitchableTextBlock), &Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_bIsReadOnly_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsReadOnly_MetaData), NewProp_bIsReadOnly_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USwitchableTextBlock_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_OnTextChanged,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_OnTextCommitted,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_Text,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_HintText,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_Mode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_Mode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_Font,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_ColorAndOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_ShadowOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_ShadowColorAndOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_StrikeBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_MinDesiredWidth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_OverflowPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_OverflowPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_TransformPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_TransformPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_Justification,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_ShapedTextOptions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USwitchableTextBlock_Statics::NewProp_bIsReadOnly,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USwitchableTextBlock_Statics::PropPointers) < 2048);
// ********** End Class USwitchableTextBlock Property Definitions **********************************
UObject* (*const Z_Construct_UClass_USwitchableTextBlock_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USwitchableTextBlock_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USwitchableTextBlock_Statics::ClassParams = {
	&USwitchableTextBlock::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_USwitchableTextBlock_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_USwitchableTextBlock_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USwitchableTextBlock_Statics::Class_MetaDataParams), Z_Construct_UClass_USwitchableTextBlock_Statics::Class_MetaDataParams)
};
void USwitchableTextBlock::StaticRegisterNativesUSwitchableTextBlock()
{
	UClass* Class = USwitchableTextBlock::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USwitchableTextBlock_Statics::Funcs));
}
UClass* Z_Construct_UClass_USwitchableTextBlock()
{
	if (!Z_Registration_Info_UClass_USwitchableTextBlock.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USwitchableTextBlock.OuterSingleton, Z_Construct_UClass_USwitchableTextBlock_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USwitchableTextBlock.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USwitchableTextBlock);
USwitchableTextBlock::~USwitchableTextBlock() {}
// ********** End Class USwitchableTextBlock *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h__Script_GenericSlateFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USwitchableTextBlock, USwitchableTextBlock::StaticClass, TEXT("USwitchableTextBlock"), &Z_Registration_Info_UClass_USwitchableTextBlock, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USwitchableTextBlock), 390792667U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h__Script_GenericSlateFramework_3293540886{
	TEXT("/Script/GenericSlateFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h__Script_GenericSlateFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_SwitchableTextBlock_h__Script_GenericSlateFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
