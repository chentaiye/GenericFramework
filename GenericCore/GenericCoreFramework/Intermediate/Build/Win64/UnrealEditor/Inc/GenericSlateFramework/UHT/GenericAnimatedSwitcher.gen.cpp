// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UWidget/GenericAnimatedSwitcher.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericAnimatedSwitcher() {}

// ********** Begin Cross Module References ********************************************************
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericAnimatedSwitcher();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericAnimatedSwitcher_NoRegister();
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition();
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy();
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve();
GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature();
GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature();
UMG_API UClass* Z_Construct_UClass_UWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UWidgetSwitcher();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnActiveIndexChangedFinish *******************************************
struct Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics
{
	struct _Script_GenericSlateFramework_eventOnActiveIndexChangedFinish_Parms
	{
		UWidget* ActiveWidget;
		int32 ActiveIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnActiveIndexChangedFinish constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveWidget;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ActiveIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnActiveIndexChangedFinish constinit property declarations *************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnActiveIndexChangedFinish Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::NewProp_ActiveWidget = { "ActiveWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericSlateFramework_eventOnActiveIndexChangedFinish_Parms, ActiveWidget), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveWidget_MetaData), NewProp_ActiveWidget_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::NewProp_ActiveIndex = { "ActiveIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericSlateFramework_eventOnActiveIndexChangedFinish_Parms, ActiveIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::NewProp_ActiveWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::NewProp_ActiveIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnActiveIndexChangedFinish Property Definitions ************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework, nullptr, "OnActiveIndexChangedFinish__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnActiveIndexChangedFinish_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnActiveIndexChangedFinish_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnActiveIndexChangedFinish_DelegateWrapper(const FMulticastScriptDelegate& OnActiveIndexChangedFinish, UWidget* ActiveWidget, int32 ActiveIndex)
{
	struct _Script_GenericSlateFramework_eventOnActiveIndexChangedFinish_Parms
	{
		UWidget* ActiveWidget;
		int32 ActiveIndex;
	};
	_Script_GenericSlateFramework_eventOnActiveIndexChangedFinish_Parms Parms;
	Parms.ActiveWidget=ActiveWidget;
	Parms.ActiveIndex=ActiveIndex;
	OnActiveIndexChangedFinish.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnActiveIndexChangedFinish *********************************************

// ********** Begin Delegate FOnGenericAnimatedSwitcherActiveIndexChangedDelegate ******************
struct Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics
{
	struct _Script_GenericSlateFramework_eventOnGenericAnimatedSwitcherActiveIndexChangedDelegate_Parms
	{
		UWidget* ActiveWidget;
		int32 ActiveIndex;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnGenericAnimatedSwitcherActiveIndexChangedDelegate constinit property declarations 
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveWidget;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ActiveIndex;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnGenericAnimatedSwitcherActiveIndexChangedDelegate constinit property declarations 
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnGenericAnimatedSwitcherActiveIndexChangedDelegate Property Definitions 
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::NewProp_ActiveWidget = { "ActiveWidget", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericSlateFramework_eventOnGenericAnimatedSwitcherActiveIndexChangedDelegate_Parms, ActiveWidget), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveWidget_MetaData), NewProp_ActiveWidget_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::NewProp_ActiveIndex = { "ActiveIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericSlateFramework_eventOnGenericAnimatedSwitcherActiveIndexChangedDelegate_Parms, ActiveIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::NewProp_ActiveWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::NewProp_ActiveIndex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnGenericAnimatedSwitcherActiveIndexChangedDelegate Property Definitions 
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework, nullptr, "OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnGenericAnimatedSwitcherActiveIndexChangedDelegate_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::_Script_GenericSlateFramework_eventOnGenericAnimatedSwitcherActiveIndexChangedDelegate_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnGenericAnimatedSwitcherActiveIndexChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnGenericAnimatedSwitcherActiveIndexChangedDelegate, UWidget* ActiveWidget, int32 ActiveIndex)
{
	struct _Script_GenericSlateFramework_eventOnGenericAnimatedSwitcherActiveIndexChangedDelegate_Parms
	{
		UWidget* ActiveWidget;
		int32 ActiveIndex;
	};
	_Script_GenericSlateFramework_eventOnGenericAnimatedSwitcherActiveIndexChangedDelegate_Parms Parms;
	Parms.ActiveWidget=ActiveWidget;
	Parms.ActiveIndex=ActiveIndex;
	OnGenericAnimatedSwitcherActiveIndexChangedDelegate.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnGenericAnimatedSwitcherActiveIndexChangedDelegate ********************

// ********** Begin Class UGenericAnimatedSwitcher Function ActivateNextWidget *********************
struct Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics
{
	struct GenericAnimatedSwitcher_eventActivateNextWidget_Parms
	{
		bool bCanWrap;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Common Widget Switcher" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\x87\xe6\x8d\xa2\xe5\x88\xb0\xe4\xb8\x8b\xe4\xb8\x80\xe4\xb8\xaa\xe5\x8f\xaf\xe7\x94\xa8\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe5\xb9\xb6\xe6\x8c\x89\xe9\x85\x8d\xe7\xbd\xae\xe5\x86\xb3\xe5\xae\x9a\xe6\x98\xaf\xe5\x90\xa6\xe5\xbe\xaa\xe7\x8e\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\x87\xe6\x8d\xa2\xe5\x88\xb0\xe4\xb8\x8b\xe4\xb8\x80\xe4\xb8\xaa\xe5\x8f\xaf\xe7\x94\xa8\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe5\xb9\xb6\xe6\x8c\x89\xe9\x85\x8d\xe7\xbd\xae\xe5\x86\xb3\xe5\xae\x9a\xe6\x98\xaf\xe5\x90\xa6\xe5\xbe\xaa\xe7\x8e\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ActivateNextWidget constinit property declarations ********************
	static void NewProp_bCanWrap_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanWrap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ActivateNextWidget constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ActivateNextWidget Property Definitions *******************************
void Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::NewProp_bCanWrap_SetBit(void* Obj)
{
	((GenericAnimatedSwitcher_eventActivateNextWidget_Parms*)Obj)->bCanWrap = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::NewProp_bCanWrap = { "bCanWrap", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericAnimatedSwitcher_eventActivateNextWidget_Parms), &Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::NewProp_bCanWrap_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::NewProp_bCanWrap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::PropPointers) < 2048);
// ********** End Function ActivateNextWidget Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericAnimatedSwitcher, nullptr, "ActivateNextWidget", 	Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::GenericAnimatedSwitcher_eventActivateNextWidget_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::GenericAnimatedSwitcher_eventActivateNextWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericAnimatedSwitcher::execActivateNextWidget)
{
	P_GET_UBOOL(Z_Param_bCanWrap);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ActivateNextWidget(Z_Param_bCanWrap);
	P_NATIVE_END;
}
// ********** End Class UGenericAnimatedSwitcher Function ActivateNextWidget ***********************

// ********** Begin Class UGenericAnimatedSwitcher Function ActivatePreviousWidget *****************
struct Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics
{
	struct GenericAnimatedSwitcher_eventActivatePreviousWidget_Parms
	{
		bool bCanWrap;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Common Widget Switcher" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\x87\xe6\x8d\xa2\xe5\x88\xb0\xe4\xb8\x8a\xe4\xb8\x80\xe4\xb8\xaa\xe5\x8f\xaf\xe7\x94\xa8\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe5\xb9\xb6\xe6\x8c\x89\xe9\x85\x8d\xe7\xbd\xae\xe5\x86\xb3\xe5\xae\x9a\xe6\x98\xaf\xe5\x90\xa6\xe5\xbe\xaa\xe7\x8e\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\x87\xe6\x8d\xa2\xe5\x88\xb0\xe4\xb8\x8a\xe4\xb8\x80\xe4\xb8\xaa\xe5\x8f\xaf\xe7\x94\xa8\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe5\xb9\xb6\xe6\x8c\x89\xe9\x85\x8d\xe7\xbd\xae\xe5\x86\xb3\xe5\xae\x9a\xe6\x98\xaf\xe5\x90\xa6\xe5\xbe\xaa\xe7\x8e\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ActivatePreviousWidget constinit property declarations ****************
	static void NewProp_bCanWrap_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bCanWrap;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ActivatePreviousWidget constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ActivatePreviousWidget Property Definitions ***************************
void Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::NewProp_bCanWrap_SetBit(void* Obj)
{
	((GenericAnimatedSwitcher_eventActivatePreviousWidget_Parms*)Obj)->bCanWrap = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::NewProp_bCanWrap = { "bCanWrap", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericAnimatedSwitcher_eventActivatePreviousWidget_Parms), &Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::NewProp_bCanWrap_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::NewProp_bCanWrap,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::PropPointers) < 2048);
// ********** End Function ActivatePreviousWidget Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericAnimatedSwitcher, nullptr, "ActivatePreviousWidget", 	Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::GenericAnimatedSwitcher_eventActivatePreviousWidget_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::GenericAnimatedSwitcher_eventActivatePreviousWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericAnimatedSwitcher::execActivatePreviousWidget)
{
	P_GET_UBOOL(Z_Param_bCanWrap);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ActivatePreviousWidget(Z_Param_bCanWrap);
	P_NATIVE_END;
}
// ********** End Class UGenericAnimatedSwitcher Function ActivatePreviousWidget *******************

// ********** Begin Class UGenericAnimatedSwitcher Function GetPendingActiveWidget *****************
struct Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics
{
	struct GenericAnimatedSwitcher_eventGetPendingActiveWidget_Parms
	{
		UWidget* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Common Widget Switcher" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\xbe\x85\xe6\xbf\x80\xe6\xb4\xbb\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\xbe\x85\xe6\xbf\x80\xe6\xb4\xbb\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPendingActiveWidget constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPendingActiveWidget constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPendingActiveWidget Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericAnimatedSwitcher_eventGetPendingActiveWidget_Parms, ReturnValue), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::PropPointers) < 2048);
// ********** End Function GetPendingActiveWidget Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericAnimatedSwitcher, nullptr, "GetPendingActiveWidget", 	Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::GenericAnimatedSwitcher_eventGetPendingActiveWidget_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::GenericAnimatedSwitcher_eventGetPendingActiveWidget_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericAnimatedSwitcher::execGetPendingActiveWidget)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UWidget**)Z_Param__Result=P_THIS->GetPendingActiveWidget();
	P_NATIVE_END;
}
// ********** End Class UGenericAnimatedSwitcher Function GetPendingActiveWidget *******************

// ********** Begin Class UGenericAnimatedSwitcher Function GetPendingActiveWidgetIndex ************
struct Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics
{
	struct GenericAnimatedSwitcher_eventGetPendingActiveWidgetIndex_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Common Widget Switcher" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe5\xbe\x85\xe6\xbf\x80\xe6\xb4\xbb\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe5\xbe\x85\xe6\xbf\x80\xe6\xb4\xbb\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe5\xa4\x8d\xe7\x94\xa8\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe7\xbc\x93\xe5\xad\x98\xe6\x88\x96\xe5\xbc\x95\xe6\x93\x8e\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetPendingActiveWidgetIndex constinit property declarations ***********
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPendingActiveWidgetIndex constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPendingActiveWidgetIndex Property Definitions **********************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericAnimatedSwitcher_eventGetPendingActiveWidgetIndex_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::PropPointers) < 2048);
// ********** End Function GetPendingActiveWidgetIndex Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericAnimatedSwitcher, nullptr, "GetPendingActiveWidgetIndex", 	Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::GenericAnimatedSwitcher_eventGetPendingActiveWidgetIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::GenericAnimatedSwitcher_eventGetPendingActiveWidgetIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericAnimatedSwitcher::execGetPendingActiveWidgetIndex)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->GetPendingActiveWidgetIndex();
	P_NATIVE_END;
}
// ********** End Class UGenericAnimatedSwitcher Function GetPendingActiveWidgetIndex **************

// ********** Begin Class UGenericAnimatedSwitcher Function HasWidgets *****************************
struct Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics
{
	struct GenericAnimatedSwitcher_eventHasWidgets_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Common Widget Switcher" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadWidgets\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe6\x88\x96\xe8\xbf\x87\xe6\xbb\xa4\xe6\x97\xa0\xe6\x95\x88\xe8\xbe\x93\xe5\x85\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadWidgets\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe6\x88\x96\xe8\xbf\x87\xe6\xbb\xa4\xe6\x97\xa0\xe6\x95\x88\xe8\xbe\x93\xe5\x85\xa5\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HasWidgets constinit property declarations ****************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function HasWidgets constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function HasWidgets Property Definitions ***************************************
void Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericAnimatedSwitcher_eventHasWidgets_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericAnimatedSwitcher_eventHasWidgets_Parms), &Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::PropPointers) < 2048);
// ********** End Function HasWidgets Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericAnimatedSwitcher, nullptr, "HasWidgets", 	Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::GenericAnimatedSwitcher_eventHasWidgets_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::GenericAnimatedSwitcher_eventHasWidgets_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericAnimatedSwitcher::execHasWidgets)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->HasWidgets();
	P_NATIVE_END;
}
// ********** End Class UGenericAnimatedSwitcher Function HasWidgets *******************************

// ********** Begin Class UGenericAnimatedSwitcher Function IsCurrentlySwitching *******************
struct Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics
{
	struct GenericAnimatedSwitcher_eventIsCurrentlySwitching_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Common Widget Switcher" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad UMG \xe5\xb0\x81\xe8\xa3\x85\xe6\x98\xaf\xe5\x90\xa6\xe6\xad\xa3\xe5\x9c\xa8\xe7\xad\x89\xe5\xbe\x85\xe5\xba\x95\xe5\xb1\x82\xe5\x88\x87\xe6\x8d\xa2\xe5\xae\x8c\xe6\x88\x90\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad UMG \xe5\xb0\x81\xe8\xa3\x85\xe6\x98\xaf\xe5\x90\xa6\xe6\xad\xa3\xe5\x9c\xa8\xe7\xad\x89\xe5\xbe\x85\xe5\xba\x95\xe5\xb1\x82\xe5\x88\x87\xe6\x8d\xa2\xe5\xae\x8c\xe6\x88\x90\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsCurrentlySwitching constinit property declarations ******************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsCurrentlySwitching constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsCurrentlySwitching Property Definitions *****************************
void Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericAnimatedSwitcher_eventIsCurrentlySwitching_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericAnimatedSwitcher_eventIsCurrentlySwitching_Parms), &Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::PropPointers) < 2048);
// ********** End Function IsCurrentlySwitching Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericAnimatedSwitcher, nullptr, "IsCurrentlySwitching", 	Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::GenericAnimatedSwitcher_eventIsCurrentlySwitching_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::GenericAnimatedSwitcher_eventIsCurrentlySwitching_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericAnimatedSwitcher::execIsCurrentlySwitching)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsCurrentlySwitching();
	P_NATIVE_END;
}
// ********** End Class UGenericAnimatedSwitcher Function IsCurrentlySwitching *********************

// ********** Begin Class UGenericAnimatedSwitcher Function IsTransitionPlaying ********************
struct Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics
{
	struct GenericAnimatedSwitcher_eventIsTransitionPlaying_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Common Widget Switcher" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe5\x88\x87\xe6\x8d\xa2\xe5\x8a\xa8\xe7\x94\xbb\xe6\x98\xaf\xe5\x90\xa6\xe6\xad\xa3\xe5\x9c\xa8\xe6\x92\xad\xe6\x94\xbe\xef\xbc\x8c\xe4\xbe\x9b\xe5\xa4\x96\xe9\x83\xa8\xe9\x80\xbb\xe8\xbe\x91\xe9\x81\xbf\xe5\x85\x8d\xe9\x87\x8d\xe5\xa4\x8d\xe5\x90\xaf\xe5\x8a\xa8\xe8\xbf\x87\xe6\xb8\xa1\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe5\x88\x87\xe6\x8d\xa2\xe5\x8a\xa8\xe7\x94\xbb\xe6\x98\xaf\xe5\x90\xa6\xe6\xad\xa3\xe5\x9c\xa8\xe6\x92\xad\xe6\x94\xbe\xef\xbc\x8c\xe4\xbe\x9b\xe5\xa4\x96\xe9\x83\xa8\xe9\x80\xbb\xe8\xbe\x91\xe9\x81\xbf\xe5\x85\x8d\xe9\x87\x8d\xe5\xa4\x8d\xe5\x90\xaf\xe5\x8a\xa8\xe8\xbf\x87\xe6\xb8\xa1\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsTransitionPlaying constinit property declarations *******************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsTransitionPlaying constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsTransitionPlaying Property Definitions ******************************
void Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericAnimatedSwitcher_eventIsTransitionPlaying_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericAnimatedSwitcher_eventIsTransitionPlaying_Parms), &Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::PropPointers) < 2048);
// ********** End Function IsTransitionPlaying Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericAnimatedSwitcher, nullptr, "IsTransitionPlaying", 	Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::GenericAnimatedSwitcher_eventIsTransitionPlaying_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::GenericAnimatedSwitcher_eventIsTransitionPlaying_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericAnimatedSwitcher::execIsTransitionPlaying)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsTransitionPlaying();
	P_NATIVE_END;
}
// ********** End Class UGenericAnimatedSwitcher Function IsTransitionPlaying **********************

// ********** Begin Class UGenericAnimatedSwitcher Function SetDisableTransitionAnimation **********
struct Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics
{
	struct GenericAnimatedSwitcher_eventSetDisableTransitionAnimation_Parms
	{
		bool bDisableAnimation;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Common Widget Switcher" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xae\xe6\x98\xaf\xe5\x90\xa6\xe7\xa6\x81\xe7\x94\xa8\xe8\xbf\x87\xe6\xb8\xa1\xe5\x8a\xa8\xe7\x94\xbb\xef\xbc\x8c\xe5\xbd\xb1\xe5\x93\x8d\xe5\x90\x8e\xe7\xbb\xad\xe5\x88\x87\xe6\x8d\xa2\xe6\x98\xaf\xe5\x90\xa6\xe5\x8d\xb3\xe6\x97\xb6\xe5\xae\x8c\xe6\x88\x90\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xae\xe6\x98\xaf\xe5\x90\xa6\xe7\xa6\x81\xe7\x94\xa8\xe8\xbf\x87\xe6\xb8\xa1\xe5\x8a\xa8\xe7\x94\xbb\xef\xbc\x8c\xe5\xbd\xb1\xe5\x93\x8d\xe5\x90\x8e\xe7\xbb\xad\xe5\x88\x87\xe6\x8d\xa2\xe6\x98\xaf\xe5\x90\xa6\xe5\x8d\xb3\xe6\x97\xb6\xe5\xae\x8c\xe6\x88\x90\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetDisableTransitionAnimation constinit property declarations *********
	static void NewProp_bDisableAnimation_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisableAnimation;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDisableTransitionAnimation constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDisableTransitionAnimation Property Definitions ********************
void Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::NewProp_bDisableAnimation_SetBit(void* Obj)
{
	((GenericAnimatedSwitcher_eventSetDisableTransitionAnimation_Parms*)Obj)->bDisableAnimation = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::NewProp_bDisableAnimation = { "bDisableAnimation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericAnimatedSwitcher_eventSetDisableTransitionAnimation_Parms), &Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::NewProp_bDisableAnimation_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::NewProp_bDisableAnimation,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::PropPointers) < 2048);
// ********** End Function SetDisableTransitionAnimation Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericAnimatedSwitcher, nullptr, "SetDisableTransitionAnimation", 	Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::GenericAnimatedSwitcher_eventSetDisableTransitionAnimation_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::GenericAnimatedSwitcher_eventSetDisableTransitionAnimation_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericAnimatedSwitcher::execSetDisableTransitionAnimation)
{
	P_GET_UBOOL(Z_Param_bDisableAnimation);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDisableTransitionAnimation(Z_Param_bDisableAnimation);
	P_NATIVE_END;
}
// ********** End Class UGenericAnimatedSwitcher Function SetDisableTransitionAnimation ************

// ********** Begin Class UGenericAnimatedSwitcher *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericAnimatedSwitcher;
UClass* UGenericAnimatedSwitcher::GetPrivateStaticClass()
{
	using TClass = UGenericAnimatedSwitcher;
	if (!Z_Registration_Info_UClass_UGenericAnimatedSwitcher.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericAnimatedSwitcher"),
			Z_Registration_Info_UClass_UGenericAnimatedSwitcher.InnerSingleton,
			StaticRegisterNativesUGenericAnimatedSwitcher,
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
	return Z_Registration_Info_UClass_UGenericAnimatedSwitcher.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericAnimatedSwitcher_NoRegister()
{
	return UGenericAnimatedSwitcher::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericAnimatedSwitcher_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe5\xb8\xa6\xe5\x8a\xa8\xe7\x94\xbb\xe5\x88\x87\xe6\x8d\xa2\xe5\x99\xa8 UMG \xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "UWidget/GenericAnimatedSwitcher.h" },
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe5\xb8\xa6\xe5\x8a\xa8\xe7\x94\xbb\xe5\x88\x87\xe6\x8d\xa2\xe5\x99\xa8 UMG \xe6\x8e\xa7\xe4\xbb\xb6\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnActiveWidgetIndexChangedBP_MetaData[] = {
		{ "Category", "Common Widget Switcher" },
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnActiveIndexChangedFinish_MetaData[] = {
		{ "Category", "Common Widget Switcher" },
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransitionType_MetaData[] = {
		{ "Category", "Transition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x88\x87\xe6\x8d\xa2\xe5\x8a\xa8\xe7\x94\xbb\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x88\x87\xe6\x8d\xa2\xe5\x8a\xa8\xe7\x94\xbb\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransitionCurveType_MetaData[] = {
		{ "Category", "Transition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x88\x87\xe6\x8d\xa2\xe6\x9b\xb2\xe7\xba\xbf\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x88\x87\xe6\x8d\xa2\xe6\x9b\xb2\xe7\xba\xbf\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransitionDuration_MetaData[] = {
		{ "Category", "Transition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x88\x87\xe6\x8d\xa2\xe6\x97\xb6\xe9\x95\xbf\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x88\x87\xe6\x8d\xa2\xe6\x97\xb6\xe9\x95\xbf\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransitionFallbackStrategy_MetaData[] = {
		{ "Category", "Transition" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x88\x87\xe6\x8d\xa2\xe5\x9b\x9e\xe9\x80\x80\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/UWidget/GenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x88\x87\xe6\x8d\xa2\xe5\x9b\x9e\xe9\x80\x80\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericAnimatedSwitcher constinit property declarations *****************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnActiveWidgetIndexChangedBP;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnActiveIndexChangedFinish;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransitionType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransitionType;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransitionCurveType_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransitionCurveType;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_TransitionDuration;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransitionFallbackStrategy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransitionFallbackStrategy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGenericAnimatedSwitcher constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ActivateNextWidget"), .Pointer = &UGenericAnimatedSwitcher::execActivateNextWidget },
		{ .NameUTF8 = UTF8TEXT("ActivatePreviousWidget"), .Pointer = &UGenericAnimatedSwitcher::execActivatePreviousWidget },
		{ .NameUTF8 = UTF8TEXT("GetPendingActiveWidget"), .Pointer = &UGenericAnimatedSwitcher::execGetPendingActiveWidget },
		{ .NameUTF8 = UTF8TEXT("GetPendingActiveWidgetIndex"), .Pointer = &UGenericAnimatedSwitcher::execGetPendingActiveWidgetIndex },
		{ .NameUTF8 = UTF8TEXT("HasWidgets"), .Pointer = &UGenericAnimatedSwitcher::execHasWidgets },
		{ .NameUTF8 = UTF8TEXT("IsCurrentlySwitching"), .Pointer = &UGenericAnimatedSwitcher::execIsCurrentlySwitching },
		{ .NameUTF8 = UTF8TEXT("IsTransitionPlaying"), .Pointer = &UGenericAnimatedSwitcher::execIsTransitionPlaying },
		{ .NameUTF8 = UTF8TEXT("SetDisableTransitionAnimation"), .Pointer = &UGenericAnimatedSwitcher::execSetDisableTransitionAnimation },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivateNextWidget, "ActivateNextWidget" }, // 2806160201
		{ &Z_Construct_UFunction_UGenericAnimatedSwitcher_ActivatePreviousWidget, "ActivatePreviousWidget" }, // 3329483054
		{ &Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidget, "GetPendingActiveWidget" }, // 1317156904
		{ &Z_Construct_UFunction_UGenericAnimatedSwitcher_GetPendingActiveWidgetIndex, "GetPendingActiveWidgetIndex" }, // 4021804781
		{ &Z_Construct_UFunction_UGenericAnimatedSwitcher_HasWidgets, "HasWidgets" }, // 581928679
		{ &Z_Construct_UFunction_UGenericAnimatedSwitcher_IsCurrentlySwitching, "IsCurrentlySwitching" }, // 2636736321
		{ &Z_Construct_UFunction_UGenericAnimatedSwitcher_IsTransitionPlaying, "IsTransitionPlaying" }, // 3869605520
		{ &Z_Construct_UFunction_UGenericAnimatedSwitcher_SetDisableTransitionAnimation, "SetDisableTransitionAnimation" }, // 1834999754
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericAnimatedSwitcher>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericAnimatedSwitcher_Statics

// ********** Begin Class UGenericAnimatedSwitcher Property Definitions ****************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_OnActiveWidgetIndexChangedBP = { "OnActiveWidgetIndexChangedBP", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericAnimatedSwitcher, OnActiveWidgetIndexChangedBP), Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnActiveWidgetIndexChangedBP_MetaData), NewProp_OnActiveWidgetIndexChangedBP_MetaData) }; // 589718504
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_OnActiveIndexChangedFinish = { "OnActiveIndexChangedFinish", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericAnimatedSwitcher, OnActiveIndexChangedFinish), Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnActiveIndexChangedFinish_MetaData), NewProp_OnActiveIndexChangedFinish_MetaData) }; // 336573030
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionType = { "TransitionType", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericAnimatedSwitcher, TransitionType), Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransitionType_MetaData), NewProp_TransitionType_MetaData) }; // 368608009
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionCurveType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionCurveType = { "TransitionCurveType", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericAnimatedSwitcher, TransitionCurveType), Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransitionCurveType_MetaData), NewProp_TransitionCurveType_MetaData) }; // 2581333610
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionDuration = { "TransitionDuration", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericAnimatedSwitcher, TransitionDuration), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransitionDuration_MetaData), NewProp_TransitionDuration_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionFallbackStrategy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionFallbackStrategy = { "TransitionFallbackStrategy", nullptr, (EPropertyFlags)0x0020080000000015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericAnimatedSwitcher, TransitionFallbackStrategy), Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransitionFallbackStrategy_MetaData), NewProp_TransitionFallbackStrategy_MetaData) }; // 2977220325
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_OnActiveWidgetIndexChangedBP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_OnActiveIndexChangedFinish,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionCurveType_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionCurveType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionDuration,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionFallbackStrategy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::NewProp_TransitionFallbackStrategy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::PropPointers) < 2048);
// ********** End Class UGenericAnimatedSwitcher Property Definitions ******************************
UObject* (*const Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UWidgetSwitcher,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::ClassParams = {
	&UGenericAnimatedSwitcher::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::PropPointers),
	0,
	0x00A800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::Class_MetaDataParams)
};
void UGenericAnimatedSwitcher::StaticRegisterNativesUGenericAnimatedSwitcher()
{
	UClass* Class = UGenericAnimatedSwitcher::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGenericAnimatedSwitcher()
{
	if (!Z_Registration_Info_UClass_UGenericAnimatedSwitcher.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericAnimatedSwitcher.OuterSingleton, Z_Construct_UClass_UGenericAnimatedSwitcher_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericAnimatedSwitcher.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericAnimatedSwitcher);
UGenericAnimatedSwitcher::~UGenericAnimatedSwitcher() {}
// ********** End Class UGenericAnimatedSwitcher ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h__Script_GenericSlateFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericAnimatedSwitcher, UGenericAnimatedSwitcher::StaticClass, TEXT("UGenericAnimatedSwitcher"), &Z_Registration_Info_UClass_UGenericAnimatedSwitcher, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericAnimatedSwitcher), 2648563400U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h__Script_GenericSlateFramework_2201432966{
	TEXT("/Script/GenericSlateFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h__Script_GenericSlateFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h__Script_GenericSlateFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
