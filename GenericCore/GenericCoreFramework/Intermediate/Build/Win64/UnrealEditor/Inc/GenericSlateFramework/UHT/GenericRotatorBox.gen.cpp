// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Widget/GenericRotatorBox.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericRotatorBox() {}

// ********** Begin Cross Module References ********************************************************
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericRotatorBox();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericRotatorBox_NoRegister();
GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature();
UMG_API UClass* Z_Construct_UClass_UButton_NoRegister();
UMG_API UClass* Z_Construct_UClass_UTextBlock_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnElementRotated *****************************************************
struct Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics
{
	struct _Script_GenericSlateFramework_eventOnElementRotated_Parms
	{
		int32 SelectedIndex;
		FText SelectedText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnElementRotated constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_SelectedIndex;
	static const UECodeGen_Private::FTextPropertyParams NewProp_SelectedText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnElementRotated constinit property declarations ***********************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnElementRotated Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::NewProp_SelectedIndex = { "SelectedIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericSlateFramework_eventOnElementRotated_Parms, SelectedIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::NewProp_SelectedText = { "SelectedText", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericSlateFramework_eventOnElementRotated_Parms, SelectedText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedText_MetaData), NewProp_SelectedText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::NewProp_SelectedIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::NewProp_SelectedText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnElementRotated Property Definitions **********************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework, nullptr, "OnElementRotated__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnElementRotated_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnElementRotated_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnElementRotated_DelegateWrapper(const FMulticastScriptDelegate& OnElementRotated, int32 SelectedIndex, FText const& SelectedText)
{
	struct _Script_GenericSlateFramework_eventOnElementRotated_Parms
	{
		int32 SelectedIndex;
		FText SelectedText;
	};
	_Script_GenericSlateFramework_eventOnElementRotated_Parms Parms;
	Parms.SelectedIndex=SelectedIndex;
	Parms.SelectedText=SelectedText;
	OnElementRotated.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnElementRotated *******************************************************

// ********** Begin Class UGenericRotatorBox Function AddTextLabel *********************************
struct Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics
{
	struct GenericRotatorBox_eventAddTextLabel_Parms
	{
		FText InTextLabel;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\xbd\xe5\x8a\xa0\xe5\x8f\xaf\xe8\xbd\xae\xe6\x92\xad\xe7\x9a\x84\xe6\x96\x87\xe6\x9c\xac\xe9\xa1\xb9\xef\xbc\x8c\xe5\xb9\xb6\xe5\x9c\xa8\xe5\xbf\x85\xe8\xa6\x81\xe6\x97\xb6\xe5\x88\xb7\xe6\x96\xb0\xe5\xbd\x93\xe5\x89\x8d\xe6\x98\xbe\xe7\xa4\xba\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\xbd\xe5\x8a\xa0\xe5\x8f\xaf\xe8\xbd\xae\xe6\x92\xad\xe7\x9a\x84\xe6\x96\x87\xe6\x9c\xac\xe9\xa1\xb9\xef\xbc\x8c\xe5\xb9\xb6\xe5\x9c\xa8\xe5\xbf\x85\xe8\xa6\x81\xe6\x97\xb6\xe5\x88\xb7\xe6\x96\xb0\xe5\xbd\x93\xe5\x89\x8d\xe6\x98\xbe\xe7\xa4\xba\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTextLabel_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddTextLabel constinit property declarations **************************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InTextLabel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddTextLabel constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddTextLabel Property Definitions *************************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::NewProp_InTextLabel = { "InTextLabel", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericRotatorBox_eventAddTextLabel_Parms, InTextLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTextLabel_MetaData), NewProp_InTextLabel_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::NewProp_InTextLabel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::PropPointers) < 2048);
// ********** End Function AddTextLabel Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericRotatorBox, nullptr, "AddTextLabel", 	Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::GenericRotatorBox_eventAddTextLabel_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::GenericRotatorBox_eventAddTextLabel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericRotatorBox::execAddTextLabel)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InTextLabel);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->AddTextLabel(Z_Param_Out_InTextLabel);
	P_NATIVE_END;
}
// ********** End Class UGenericRotatorBox Function AddTextLabel ***********************************

// ********** Begin Class UGenericRotatorBox Function GetNextValidIndex ****************************
struct Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics
{
	struct GenericRotatorBox_eventGetNextValidIndex_Parms
	{
		int32 OutIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9f\xa5\xe6\x89\xbe\xe4\xb8\x8b\xe4\xb8\x80\xe4\xb8\xaa\xe5\x8f\xaf\xe7\x94\xa8\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe6\x8c\x89\xe9\x85\x8d\xe7\xbd\xae\xe5\x86\xb3\xe5\xae\x9a\xe6\x98\xaf\xe5\x90\xa6\xe5\x85\x81\xe8\xae\xb8\xe4\xbb\x8e\xe6\x9c\xab\xe9\xa1\xb9\xe5\x9b\x9e\xe7\xbb\x95\xe5\x88\xb0\xe9\xa6\x96\xe9\xa1\xb9\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9f\xa5\xe6\x89\xbe\xe4\xb8\x8b\xe4\xb8\x80\xe4\xb8\xaa\xe5\x8f\xaf\xe7\x94\xa8\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe6\x8c\x89\xe9\x85\x8d\xe7\xbd\xae\xe5\x86\xb3\xe5\xae\x9a\xe6\x98\xaf\xe5\x90\xa6\xe5\x85\x81\xe8\xae\xb8\xe4\xbb\x8e\xe6\x9c\xab\xe9\xa1\xb9\xe5\x9b\x9e\xe7\xbb\x95\xe5\x88\xb0\xe9\xa6\x96\xe9\xa1\xb9\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetNextValidIndex constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNextValidIndex constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNextValidIndex Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::NewProp_OutIndex = { "OutIndex", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericRotatorBox_eventGetNextValidIndex_Parms, OutIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericRotatorBox_eventGetNextValidIndex_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericRotatorBox_eventGetNextValidIndex_Parms), &Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::NewProp_OutIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::PropPointers) < 2048);
// ********** End Function GetNextValidIndex Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericRotatorBox, nullptr, "GetNextValidIndex", 	Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::GenericRotatorBox_eventGetNextValidIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::GenericRotatorBox_eventGetNextValidIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericRotatorBox::execGetNextValidIndex)
{
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetNextValidIndex(Z_Param_Out_OutIndex);
	P_NATIVE_END;
}
// ********** End Class UGenericRotatorBox Function GetNextValidIndex ******************************

// ********** Begin Class UGenericRotatorBox Function GetPreviousValidIndex ************************
struct Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics
{
	struct GenericRotatorBox_eventGetPreviousValidIndex_Parms
	{
		int32 OutIndex;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9f\xa5\xe6\x89\xbe\xe4\xb8\x8a\xe4\xb8\x80\xe4\xb8\xaa\xe5\x8f\xaf\xe7\x94\xa8\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe6\x8c\x89\xe9\x85\x8d\xe7\xbd\xae\xe5\x86\xb3\xe5\xae\x9a\xe6\x98\xaf\xe5\x90\xa6\xe5\x85\x81\xe8\xae\xb8\xe4\xbb\x8e\xe9\xa6\x96\xe9\xa1\xb9\xe5\x9b\x9e\xe7\xbb\x95\xe5\x88\xb0\xe6\x9c\xab\xe9\xa1\xb9\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9f\xa5\xe6\x89\xbe\xe4\xb8\x8a\xe4\xb8\x80\xe4\xb8\xaa\xe5\x8f\xaf\xe7\x94\xa8\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe6\x8c\x89\xe9\x85\x8d\xe7\xbd\xae\xe5\x86\xb3\xe5\xae\x9a\xe6\x98\xaf\xe5\x90\xa6\xe5\x85\x81\xe8\xae\xb8\xe4\xbb\x8e\xe9\xa6\x96\xe9\xa1\xb9\xe5\x9b\x9e\xe7\xbb\x95\xe5\x88\xb0\xe6\x9c\xab\xe9\xa1\xb9\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetPreviousValidIndex constinit property declarations *****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_OutIndex;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPreviousValidIndex constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPreviousValidIndex Property Definitions ****************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::NewProp_OutIndex = { "OutIndex", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericRotatorBox_eventGetPreviousValidIndex_Parms, OutIndex), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericRotatorBox_eventGetPreviousValidIndex_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericRotatorBox_eventGetPreviousValidIndex_Parms), &Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::NewProp_OutIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::PropPointers) < 2048);
// ********** End Function GetPreviousValidIndex Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericRotatorBox, nullptr, "GetPreviousValidIndex", 	Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::GenericRotatorBox_eventGetPreviousValidIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::GenericRotatorBox_eventGetPreviousValidIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericRotatorBox::execGetPreviousValidIndex)
{
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_OutIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetPreviousValidIndex(Z_Param_Out_OutIndex);
	P_NATIVE_END;
}
// ********** End Class UGenericRotatorBox Function GetPreviousValidIndex **************************

// ********** Begin Class UGenericRotatorBox Function OnButtonLeftClicked **************************
struct Z_Construct_UFunction_UGenericRotatorBox_OnButtonLeftClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x93\x8d\xe5\xba\x94\xe5\xb7\xa6\xe4\xbe\xa7\xe6\x8c\x89\xe9\x92\xae\xe7\x82\xb9\xe5\x87\xbb\xef\xbc\x8c\xe6\x8a\x8a\xe7\x94\xa8\xe6\x88\xb7\xe8\xbe\x93\xe5\x85\xa5\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xba\xe5\x90\x91\xe5\xb7\xa6\xe8\xbd\xae\xe6\x92\xad\xe6\x93\x8d\xe4\xbd\x9c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x93\x8d\xe5\xba\x94\xe5\xb7\xa6\xe4\xbe\xa7\xe6\x8c\x89\xe9\x92\xae\xe7\x82\xb9\xe5\x87\xbb\xef\xbc\x8c\xe6\x8a\x8a\xe7\x94\xa8\xe6\x88\xb7\xe8\xbe\x93\xe5\x85\xa5\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xba\xe5\x90\x91\xe5\xb7\xa6\xe8\xbd\xae\xe6\x92\xad\xe6\x93\x8d\xe4\xbd\x9c\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnButtonLeftClicked constinit property declarations *******************
// ********** End Function OnButtonLeftClicked constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericRotatorBox_OnButtonLeftClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericRotatorBox, nullptr, "OnButtonLeftClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_OnButtonLeftClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericRotatorBox_OnButtonLeftClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UGenericRotatorBox_OnButtonLeftClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericRotatorBox_OnButtonLeftClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericRotatorBox::execOnButtonLeftClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnButtonLeftClicked();
	P_NATIVE_END;
}
// ********** End Class UGenericRotatorBox Function OnButtonLeftClicked ****************************

// ********** Begin Class UGenericRotatorBox Function OnButtonRightClicked *************************
struct Z_Construct_UFunction_UGenericRotatorBox_OnButtonRightClicked_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x93\x8d\xe5\xba\x94\xe5\x8f\xb3\xe4\xbe\xa7\xe6\x8c\x89\xe9\x92\xae\xe7\x82\xb9\xe5\x87\xbb\xef\xbc\x8c\xe6\x8a\x8a\xe7\x94\xa8\xe6\x88\xb7\xe8\xbe\x93\xe5\x85\xa5\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xba\xe5\x90\x91\xe5\x8f\xb3\xe8\xbd\xae\xe6\x92\xad\xe6\x93\x8d\xe4\xbd\x9c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x93\x8d\xe5\xba\x94\xe5\x8f\xb3\xe4\xbe\xa7\xe6\x8c\x89\xe9\x92\xae\xe7\x82\xb9\xe5\x87\xbb\xef\xbc\x8c\xe6\x8a\x8a\xe7\x94\xa8\xe6\x88\xb7\xe8\xbe\x93\xe5\x85\xa5\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xba\xe5\x90\x91\xe5\x8f\xb3\xe8\xbd\xae\xe6\x92\xad\xe6\x93\x8d\xe4\xbd\x9c\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnButtonRightClicked constinit property declarations ******************
// ********** End Function OnButtonRightClicked constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericRotatorBox_OnButtonRightClicked_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericRotatorBox, nullptr, "OnButtonRightClicked", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_OnButtonRightClicked_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericRotatorBox_OnButtonRightClicked_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UGenericRotatorBox_OnButtonRightClicked()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericRotatorBox_OnButtonRightClicked_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericRotatorBox::execOnButtonRightClicked)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnButtonRightClicked();
	P_NATIVE_END;
}
// ********** End Class UGenericRotatorBox Function OnButtonRightClicked ***************************

// ********** Begin Class UGenericRotatorBox Function OnSelectedIndexChanged ***********************
struct GenericRotatorBox_eventOnSelectedIndexChanged_Parms
{
	int32 Index;
};
static FName NAME_UGenericRotatorBox_OnSelectedIndexChanged = FName(TEXT("OnSelectedIndexChanged"));
void UGenericRotatorBox::OnSelectedIndexChanged(int32 Index)
{
	UFunction* Func = FindFunctionChecked(NAME_UGenericRotatorBox_OnSelectedIndexChanged);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GenericRotatorBox_eventOnSelectedIndexChanged_Parms Parms;
		Parms.Index=Index;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnSelectedIndexChanged_Implementation(Index);
	}
}
struct Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xbd\x93\xe5\x89\x8d\xe9\x80\x89\xe6\x8b\xa9\xe7\xb4\xa2\xe5\xbc\x95\xe5\x8f\x98\xe5\x8c\x96\xe5\x90\x8e\xe9\x80\x9a\xe7\x9f\xa5\xe8\x93\x9d\xe5\x9b\xbe\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe5\xa4\x96\xe9\x83\xa8\xe5\x90\x8c\xe6\xad\xa5\xe6\x98\xbe\xe7\xa4\xba\xe6\x88\x96\xe4\xb8\x9a\xe5\x8a\xa1\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe9\x80\x89\xe6\x8b\xa9\xe7\xb4\xa2\xe5\xbc\x95\xe5\x8f\x98\xe5\x8c\x96\xe5\x90\x8e\xe9\x80\x9a\xe7\x9f\xa5\xe8\x93\x9d\xe5\x9b\xbe\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe5\xa4\x96\xe9\x83\xa8\xe5\x90\x8c\xe6\xad\xa5\xe6\x98\xbe\xe7\xa4\xba\xe6\x88\x96\xe4\xb8\x9a\xe5\x8a\xa1\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnSelectedIndexChanged constinit property declarations ****************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnSelectedIndexChanged constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnSelectedIndexChanged Property Definitions ***************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericRotatorBox_eventOnSelectedIndexChanged_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics::NewProp_Index,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics::PropPointers) < 2048);
// ********** End Function OnSelectedIndexChanged Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericRotatorBox, nullptr, "OnSelectedIndexChanged", 	Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics::PropPointers), 
sizeof(GenericRotatorBox_eventOnSelectedIndexChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C02, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericRotatorBox_eventOnSelectedIndexChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericRotatorBox::execOnSelectedIndexChanged)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnSelectedIndexChanged_Implementation(Z_Param_Index);
	P_NATIVE_END;
}
// ********** End Class UGenericRotatorBox Function OnSelectedIndexChanged *************************

// ********** Begin Class UGenericRotatorBox Function RemoveTextLabel ******************************
struct Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics
{
	struct GenericRotatorBox_eventRemoveTextLabel_Parms
	{
		FText InTextLabel;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe6\x96\x87\xe6\x9c\xac\xe9\xa1\xb9\xef\xbc\x8c\xe5\xb9\xb6\xe4\xbf\xae\xe6\xad\xa3\xe5\xbd\x93\xe5\x89\x8d\xe9\x80\x89\xe6\x8b\xa9\xe7\xb4\xa2\xe5\xbc\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe6\x96\x87\xe6\x9c\xac\xe9\xa1\xb9\xef\xbc\x8c\xe5\xb9\xb6\xe4\xbf\xae\xe6\xad\xa3\xe5\xbd\x93\xe5\x89\x8d\xe9\x80\x89\xe6\x8b\xa9\xe7\xb4\xa2\xe5\xbc\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTextLabel_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveTextLabel constinit property declarations ***********************
	static const UECodeGen_Private::FTextPropertyParams NewProp_InTextLabel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveTextLabel constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveTextLabel Property Definitions **********************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::NewProp_InTextLabel = { "InTextLabel", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericRotatorBox_eventRemoveTextLabel_Parms, InTextLabel), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTextLabel_MetaData), NewProp_InTextLabel_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::NewProp_InTextLabel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::PropPointers) < 2048);
// ********** End Function RemoveTextLabel Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericRotatorBox, nullptr, "RemoveTextLabel", 	Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::GenericRotatorBox_eventRemoveTextLabel_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::GenericRotatorBox_eventRemoveTextLabel_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericRotatorBox::execRemoveTextLabel)
{
	P_GET_PROPERTY_REF(FTextProperty,Z_Param_Out_InTextLabel);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RemoveTextLabel(Z_Param_Out_InTextLabel);
	P_NATIVE_END;
}
// ********** End Class UGenericRotatorBox Function RemoveTextLabel ********************************

// ********** Begin Class UGenericRotatorBox Function RotateLeft ***********************************
struct Z_Construct_UFunction_UGenericRotatorBox_RotateLeft_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x90\x91\xe5\xb7\xa6\xe5\x88\x87\xe6\x8d\xa2\xe8\xbd\xae\xe6\x92\xad\xe9\xa1\xb9\xef\xbc\x8c\xe6\x9b\xb4\xe6\x96\xb0\xe5\xbd\x93\xe5\x89\x8d\xe7\xb4\xa2\xe5\xbc\x95\xe5\xb9\xb6\xe5\xb9\xbf\xe6\x92\xad\xe9\x80\x89\xe6\x8b\xa9\xe5\x8f\x98\xe5\x8c\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x90\x91\xe5\xb7\xa6\xe5\x88\x87\xe6\x8d\xa2\xe8\xbd\xae\xe6\x92\xad\xe9\xa1\xb9\xef\xbc\x8c\xe6\x9b\xb4\xe6\x96\xb0\xe5\xbd\x93\xe5\x89\x8d\xe7\xb4\xa2\xe5\xbc\x95\xe5\xb9\xb6\xe5\xb9\xbf\xe6\x92\xad\xe9\x80\x89\xe6\x8b\xa9\xe5\x8f\x98\xe5\x8c\x96\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RotateLeft constinit property declarations ****************************
// ********** End Function RotateLeft constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericRotatorBox_RotateLeft_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericRotatorBox, nullptr, "RotateLeft", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_RotateLeft_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericRotatorBox_RotateLeft_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UGenericRotatorBox_RotateLeft()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericRotatorBox_RotateLeft_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericRotatorBox::execRotateLeft)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RotateLeft();
	P_NATIVE_END;
}
// ********** End Class UGenericRotatorBox Function RotateLeft *************************************

// ********** Begin Class UGenericRotatorBox Function RotateRight **********************************
struct Z_Construct_UFunction_UGenericRotatorBox_RotateRight_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x90\x91\xe5\x8f\xb3\xe5\x88\x87\xe6\x8d\xa2\xe8\xbd\xae\xe6\x92\xad\xe9\xa1\xb9\xef\xbc\x8c\xe6\x9b\xb4\xe6\x96\xb0\xe5\xbd\x93\xe5\x89\x8d\xe7\xb4\xa2\xe5\xbc\x95\xe5\xb9\xb6\xe5\xb9\xbf\xe6\x92\xad\xe9\x80\x89\xe6\x8b\xa9\xe5\x8f\x98\xe5\x8c\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x90\x91\xe5\x8f\xb3\xe5\x88\x87\xe6\x8d\xa2\xe8\xbd\xae\xe6\x92\xad\xe9\xa1\xb9\xef\xbc\x8c\xe6\x9b\xb4\xe6\x96\xb0\xe5\xbd\x93\xe5\x89\x8d\xe7\xb4\xa2\xe5\xbc\x95\xe5\xb9\xb6\xe5\xb9\xbf\xe6\x92\xad\xe9\x80\x89\xe6\x8b\xa9\xe5\x8f\x98\xe5\x8c\x96\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RotateRight constinit property declarations ***************************
// ********** End Function RotateRight constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericRotatorBox_RotateRight_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericRotatorBox, nullptr, "RotateRight", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_RotateRight_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericRotatorBox_RotateRight_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UGenericRotatorBox_RotateRight()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericRotatorBox_RotateRight_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericRotatorBox::execRotateRight)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RotateRight();
	P_NATIVE_END;
}
// ********** End Class UGenericRotatorBox Function RotateRight ************************************

// ********** Begin Class UGenericRotatorBox Function SetSelectedIndex *****************************
struct Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics
{
	struct GenericRotatorBox_eventSetSelectedIndex_Parms
	{
		int32 Index;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe5\xbd\x93\xe5\x89\x8d\xe9\x80\x89\xe6\x8b\xa9\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe5\xbd\x93\xe5\x89\x8d\xe9\x80\x89\xe6\x8b\xa9\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb9\xb6\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe5\x92\x8c\xe5\xba\x95\xe5\xb1\x82 Slate \xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetSelectedIndex constinit property declarations **********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetSelectedIndex constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetSelectedIndex Property Definitions *********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericRotatorBox_eventSetSelectedIndex_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::NewProp_Index,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::PropPointers) < 2048);
// ********** End Function SetSelectedIndex Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericRotatorBox, nullptr, "SetSelectedIndex", 	Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::GenericRotatorBox_eventSetSelectedIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::GenericRotatorBox_eventSetSelectedIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericRotatorBox::execSetSelectedIndex)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetSelectedIndex(Z_Param_Index);
	P_NATIVE_END;
}
// ********** End Class UGenericRotatorBox Function SetSelectedIndex *******************************

// ********** Begin Class UGenericRotatorBox *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericRotatorBox;
UClass* UGenericRotatorBox::GetPrivateStaticClass()
{
	using TClass = UGenericRotatorBox;
	if (!Z_Registration_Info_UClass_UGenericRotatorBox.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericRotatorBox"),
			Z_Registration_Info_UClass_UGenericRotatorBox.InnerSingleton,
			StaticRegisterNativesUGenericRotatorBox,
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
	return Z_Registration_Info_UClass_UGenericRotatorBox.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericRotatorBox_NoRegister()
{
	return UGenericRotatorBox::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericRotatorBox_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe9\x80\x9a\xe7\x94\xa8\xe8\xbd\xae\xe6\x92\xad\xe7\x9b\x92\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Widget/GenericRotatorBox.h" },
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe9\x80\x9a\xe7\x94\xa8\xe8\xbd\xae\xe6\x92\xad\xe7\x9b\x92\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnElementRotated_MetaData[] = {
		{ "Category", "Events" },
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bAllowWrap_MetaData[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xb0\xe5\xbd\x95\xe5\xbe\xaa\xe7\x8e\xaf\xe9\x80\x89\xe6\x8b\xa9\xe5\xbc\x80\xe5\x85\xb3\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x9c\xa8\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe3\x80\x81\xe5\x90\x8c\xe6\xad\xa5\xe6\x88\x96\xe8\xbe\x93\xe5\x85\xa5\xe6\xb5\x81\xe7\xa8\x8b\xe4\xb8\xad\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xb0\xe5\xbd\x95\xe5\xbe\xaa\xe7\x8e\xaf\xe9\x80\x89\xe6\x8b\xa9\xe5\xbc\x80\xe5\x85\xb3\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x9c\xa8\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe3\x80\x81\xe5\x90\x8c\xe6\xad\xa5\xe6\x88\x96\xe8\xbe\x93\xe5\x85\xa5\xe6\xb5\x81\xe7\xa8\x8b\xe4\xb8\xad\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DefaultSelectedIndex_MetaData[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xbb\x98\xe8\xae\xa4\xe9\x80\x89\xe6\x8b\xa9\xe7\xb4\xa2\xe5\xbc\x95\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xbb\x98\xe8\xae\xa4\xe9\x80\x89\xe6\x8b\xa9\xe7\xb4\xa2\xe5\xbc\x95\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextLabels_MetaData[] = {
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbc\x93\xe5\xad\x98\xe8\xbd\xae\xe6\x92\xad\xe6\x96\x87\xe6\x9c\xac\xe5\x88\x97\xe8\xa1\xa8\xe9\x9b\x86\xe5\x90\x88\xef\xbc\x8c\xe4\xbe\x9b\xe6\x89\xb9\xe9\x87\x8f\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x81\xe6\x9f\xa5\xe6\x89\xbe\xe6\x88\x96\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x88\xb7\xe6\x96\xb0\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbc\x93\xe5\xad\x98\xe8\xbd\xae\xe6\x92\xad\xe6\x96\x87\xe6\x9c\xac\xe5\x88\x97\xe8\xa1\xa8\xe9\x9b\x86\xe5\x90\x88\xef\xbc\x8c\xe4\xbe\x9b\xe6\x89\xb9\xe9\x87\x8f\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x81\xe6\x9f\xa5\xe6\x89\xbe\xe6\x88\x96\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x88\xb7\xe6\x96\xb0\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenericButton_Left_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "BindWidget", "" },
		{ "BlueprintProtected", "TRUE" },
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbb\x91\xe5\xae\x9a\xe5\xb7\xa6\xe4\xbe\xa7\xe6\x8c\x89\xe9\x92\xae\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe9\xa9\xb1\xe5\x8a\xa8\xe4\xb8\x8a\xe4\xb8\x80\xe9\xa1\xb9\xe8\xbd\xae\xe6\x92\xad\xe3\x80\x82 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbb\x91\xe5\xae\x9a\xe5\xb7\xa6\xe4\xbe\xa7\xe6\x8c\x89\xe9\x92\xae\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe9\xa9\xb1\xe5\x8a\xa8\xe4\xb8\x8a\xe4\xb8\x80\xe9\xa1\xb9\xe8\xbd\xae\xe6\x92\xad\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GenericButton_Right_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "BindWidget", "" },
		{ "BlueprintProtected", "TRUE" },
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbb\x91\xe5\xae\x9a\xe5\x8f\xb3\xe4\xbe\xa7\xe6\x8c\x89\xe9\x92\xae\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe9\xa9\xb1\xe5\x8a\xa8\xe4\xb8\x8b\xe4\xb8\x80\xe9\xa1\xb9\xe8\xbd\xae\xe6\x92\xad\xe3\x80\x82 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbb\x91\xe5\xae\x9a\xe5\x8f\xb3\xe4\xbe\xa7\xe6\x8c\x89\xe9\x92\xae\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe9\xa9\xb1\xe5\x8a\xa8\xe4\xb8\x8b\xe4\xb8\x80\xe9\xa1\xb9\xe8\xbd\xae\xe6\x92\xad\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TextBlock_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "BindWidget", "" },
		{ "BlueprintProtected", "TRUE" },
		{ "Category", "Generic Rotator Box" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbb\x91\xe5\xae\x9a\xe5\xbd\x93\xe5\x89\x8d\xe6\x96\x87\xe6\x9c\xac\xe6\x98\xbe\xe7\xa4\xba\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xbd\xae\xe6\x92\xad\xe7\xb4\xa2\xe5\xbc\x95\xe5\x8f\x98\xe5\x8c\x96\xe6\x97\xb6\xe6\x9b\xb4\xe6\x96\xb0\xe5\x86\x85\xe5\xae\xb9\xe3\x80\x82 */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widget/GenericRotatorBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbb\x91\xe5\xae\x9a\xe5\xbd\x93\xe5\x89\x8d\xe6\x96\x87\xe6\x9c\xac\xe6\x98\xbe\xe7\xa4\xba\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xbd\xae\xe6\x92\xad\xe7\xb4\xa2\xe5\xbc\x95\xe5\x8f\x98\xe5\x8c\x96\xe6\x97\xb6\xe6\x9b\xb4\xe6\x96\xb0\xe5\x86\x85\xe5\xae\xb9\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericRotatorBox constinit property declarations ***********************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnElementRotated;
	static void NewProp_bAllowWrap_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllowWrap;
	static const UECodeGen_Private::FIntPropertyParams NewProp_DefaultSelectedIndex;
	static const UECodeGen_Private::FTextPropertyParams NewProp_TextLabels_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_TextLabels;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GenericButton_Left;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_GenericButton_Right;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TextBlock;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGenericRotatorBox constinit property declarations *************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddTextLabel"), .Pointer = &UGenericRotatorBox::execAddTextLabel },
		{ .NameUTF8 = UTF8TEXT("GetNextValidIndex"), .Pointer = &UGenericRotatorBox::execGetNextValidIndex },
		{ .NameUTF8 = UTF8TEXT("GetPreviousValidIndex"), .Pointer = &UGenericRotatorBox::execGetPreviousValidIndex },
		{ .NameUTF8 = UTF8TEXT("OnButtonLeftClicked"), .Pointer = &UGenericRotatorBox::execOnButtonLeftClicked },
		{ .NameUTF8 = UTF8TEXT("OnButtonRightClicked"), .Pointer = &UGenericRotatorBox::execOnButtonRightClicked },
		{ .NameUTF8 = UTF8TEXT("OnSelectedIndexChanged"), .Pointer = &UGenericRotatorBox::execOnSelectedIndexChanged },
		{ .NameUTF8 = UTF8TEXT("RemoveTextLabel"), .Pointer = &UGenericRotatorBox::execRemoveTextLabel },
		{ .NameUTF8 = UTF8TEXT("RotateLeft"), .Pointer = &UGenericRotatorBox::execRotateLeft },
		{ .NameUTF8 = UTF8TEXT("RotateRight"), .Pointer = &UGenericRotatorBox::execRotateRight },
		{ .NameUTF8 = UTF8TEXT("SetSelectedIndex"), .Pointer = &UGenericRotatorBox::execSetSelectedIndex },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGenericRotatorBox_AddTextLabel, "AddTextLabel" }, // 704244988
		{ &Z_Construct_UFunction_UGenericRotatorBox_GetNextValidIndex, "GetNextValidIndex" }, // 3942047564
		{ &Z_Construct_UFunction_UGenericRotatorBox_GetPreviousValidIndex, "GetPreviousValidIndex" }, // 14175531
		{ &Z_Construct_UFunction_UGenericRotatorBox_OnButtonLeftClicked, "OnButtonLeftClicked" }, // 2732711891
		{ &Z_Construct_UFunction_UGenericRotatorBox_OnButtonRightClicked, "OnButtonRightClicked" }, // 744416135
		{ &Z_Construct_UFunction_UGenericRotatorBox_OnSelectedIndexChanged, "OnSelectedIndexChanged" }, // 34463998
		{ &Z_Construct_UFunction_UGenericRotatorBox_RemoveTextLabel, "RemoveTextLabel" }, // 3686304790
		{ &Z_Construct_UFunction_UGenericRotatorBox_RotateLeft, "RotateLeft" }, // 2298778904
		{ &Z_Construct_UFunction_UGenericRotatorBox_RotateRight, "RotateRight" }, // 3872690645
		{ &Z_Construct_UFunction_UGenericRotatorBox_SetSelectedIndex, "SetSelectedIndex" }, // 75646290
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericRotatorBox>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericRotatorBox_Statics

// ********** Begin Class UGenericRotatorBox Property Definitions **********************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_OnElementRotated = { "OnElementRotated", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericRotatorBox, OnElementRotated), Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnElementRotated_MetaData), NewProp_OnElementRotated_MetaData) }; // 3497316792
void Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_bAllowWrap_SetBit(void* Obj)
{
	((UGenericRotatorBox*)Obj)->bAllowWrap = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_bAllowWrap = { "bAllowWrap", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGenericRotatorBox), &Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_bAllowWrap_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bAllowWrap_MetaData), NewProp_bAllowWrap_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_DefaultSelectedIndex = { "DefaultSelectedIndex", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericRotatorBox, DefaultSelectedIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DefaultSelectedIndex_MetaData), NewProp_DefaultSelectedIndex_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_TextLabels_Inner = { "TextLabels", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_TextLabels = { "TextLabels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericRotatorBox, TextLabels), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextLabels_MetaData), NewProp_TextLabels_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_GenericButton_Left = { "GenericButton_Left", nullptr, (EPropertyFlags)0x014400000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericRotatorBox, GenericButton_Left), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenericButton_Left_MetaData), NewProp_GenericButton_Left_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_GenericButton_Right = { "GenericButton_Right", nullptr, (EPropertyFlags)0x014400000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericRotatorBox, GenericButton_Right), Z_Construct_UClass_UButton_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GenericButton_Right_MetaData), NewProp_GenericButton_Right_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_TextBlock = { "TextBlock", nullptr, (EPropertyFlags)0x014400000008001c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericRotatorBox, TextBlock), Z_Construct_UClass_UTextBlock_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TextBlock_MetaData), NewProp_TextBlock_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenericRotatorBox_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_OnElementRotated,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_bAllowWrap,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_DefaultSelectedIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_TextLabels_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_TextLabels,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_GenericButton_Left,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_GenericButton_Right,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericRotatorBox_Statics::NewProp_TextBlock,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericRotatorBox_Statics::PropPointers) < 2048);
// ********** End Class UGenericRotatorBox Property Definitions ************************************
UObject* (*const Z_Construct_UClass_UGenericRotatorBox_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericRotatorBox_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericRotatorBox_Statics::ClassParams = {
	&UGenericRotatorBox::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UGenericRotatorBox_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UGenericRotatorBox_Statics::PropPointers),
	0,
	0x00A810A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericRotatorBox_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericRotatorBox_Statics::Class_MetaDataParams)
};
void UGenericRotatorBox::StaticRegisterNativesUGenericRotatorBox()
{
	UClass* Class = UGenericRotatorBox::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGenericRotatorBox_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGenericRotatorBox()
{
	if (!Z_Registration_Info_UClass_UGenericRotatorBox.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericRotatorBox.OuterSingleton, Z_Construct_UClass_UGenericRotatorBox_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericRotatorBox.OuterSingleton;
}
UGenericRotatorBox::UGenericRotatorBox(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericRotatorBox);
UGenericRotatorBox::~UGenericRotatorBox() {}
// ********** End Class UGenericRotatorBox *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h__Script_GenericSlateFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericRotatorBox, UGenericRotatorBox::StaticClass, TEXT("UGenericRotatorBox"), &Z_Registration_Info_UClass_UGenericRotatorBox, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericRotatorBox), 2912735540U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h__Script_GenericSlateFramework_790955957{
	TEXT("/Script/GenericSlateFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h__Script_GenericSlateFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Widget_GenericRotatorBox_h__Script_GenericSlateFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
