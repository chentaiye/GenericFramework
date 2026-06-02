// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AsyncFunctions/AcquireAndroidPermissionAsyncAction.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeAcquireAndroidPermissionAsyncAction() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
GENERICANDROIDFRAMEWORK_API UClass* Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction();
GENERICANDROIDFRAMEWORK_API UClass* Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_NoRegister();
GENERICANDROIDFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature();
GENERICANDROIDFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedSuccess__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_GenericAndroidFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnPermissionsGrantedSuccess ******************************************
struct Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedSuccess__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AsyncFunctions/AcquireAndroidPermissionAsyncAction.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnPermissionsGrantedSuccess constinit property declarations **********
// ********** End Delegate FOnPermissionsGrantedSuccess constinit property declarations ************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedSuccess__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework, nullptr, "OnPermissionsGrantedSuccess__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedSuccess__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedSuccess__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedSuccess__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedSuccess__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPermissionsGrantedSuccess_DelegateWrapper(const FMulticastScriptDelegate& OnPermissionsGrantedSuccess)
{
	OnPermissionsGrantedSuccess.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FOnPermissionsGrantedSuccess ********************************************

// ********** Begin Delegate FOnPermissionsGrantedFail *********************************************
struct Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics
{
	struct _Script_GenericAndroidFramework_eventOnPermissionsGrantedFail_Parms
	{
		TArray<FString> FailPermissions;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AsyncFunctions/AcquireAndroidPermissionAsyncAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FailPermissions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnPermissionsGrantedFail constinit property declarations *************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FailPermissions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FailPermissions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnPermissionsGrantedFail constinit property declarations ***************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnPermissionsGrantedFail Property Definitions ************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::NewProp_FailPermissions_Inner = { "FailPermissions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::NewProp_FailPermissions = { "FailPermissions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericAndroidFramework_eventOnPermissionsGrantedFail_Parms, FailPermissions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FailPermissions_MetaData), NewProp_FailPermissions_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::NewProp_FailPermissions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::NewProp_FailPermissions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnPermissionsGrantedFail Property Definitions **************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework, nullptr, "OnPermissionsGrantedFail__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::_Script_GenericAndroidFramework_eventOnPermissionsGrantedFail_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::_Script_GenericAndroidFramework_eventOnPermissionsGrantedFail_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnPermissionsGrantedFail_DelegateWrapper(const FMulticastScriptDelegate& OnPermissionsGrantedFail, TArray<FString> const& FailPermissions)
{
	struct _Script_GenericAndroidFramework_eventOnPermissionsGrantedFail_Parms
	{
		TArray<FString> FailPermissions;
	};
	_Script_GenericAndroidFramework_eventOnPermissionsGrantedFail_Parms Parms;
	Parms.FailPermissions=FailPermissions;
	OnPermissionsGrantedFail.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnPermissionsGrantedFail ***********************************************

// ********** Begin Class UAcquireAndroidPermissionAsyncAction Function AsyncAcquireAndroidPermission 
struct Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics
{
	struct AcquireAndroidPermissionAsyncAction_eventAsyncAcquireAndroidPermission_Parms
	{
		FString InPermission;
		UAcquireAndroidPermissionAsyncAction* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Android|Permission|Async" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\x8e\xb7\xe5\x8f\x96""Android\xe6\x9d\x83\xe9\x99\x90\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/AcquireAndroidPermissionAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\x8e\xb7\xe5\x8f\x96""Android\xe6\x9d\x83\xe9\x99\x90\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPermission_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AsyncAcquireAndroidPermission constinit property declarations *********
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPermission;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AsyncAcquireAndroidPermission constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AsyncAcquireAndroidPermission Property Definitions ********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::NewProp_InPermission = { "InPermission", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AcquireAndroidPermissionAsyncAction_eventAsyncAcquireAndroidPermission_Parms, InPermission), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPermission_MetaData), NewProp_InPermission_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AcquireAndroidPermissionAsyncAction_eventAsyncAcquireAndroidPermission_Parms, ReturnValue), Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::NewProp_InPermission,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::PropPointers) < 2048);
// ********** End Function AsyncAcquireAndroidPermission Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction, nullptr, "AsyncAcquireAndroidPermission", 	Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::AcquireAndroidPermissionAsyncAction_eventAsyncAcquireAndroidPermission_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::AcquireAndroidPermissionAsyncAction_eventAsyncAcquireAndroidPermission_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAcquireAndroidPermissionAsyncAction::execAsyncAcquireAndroidPermission)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPermission);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAcquireAndroidPermissionAsyncAction**)Z_Param__Result=UAcquireAndroidPermissionAsyncAction::AsyncAcquireAndroidPermission(Z_Param_InPermission);
	P_NATIVE_END;
}
// ********** End Class UAcquireAndroidPermissionAsyncAction Function AsyncAcquireAndroidPermission 

// ********** Begin Class UAcquireAndroidPermissionAsyncAction Function AsyncAcquireAndroidPermissions 
struct Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics
{
	struct AcquireAndroidPermissionAsyncAction_eventAsyncAcquireAndroidPermissions_Parms
	{
		TArray<FString> InPermissions;
		UAcquireAndroidPermissionAsyncAction* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Android|Permission|Async" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\x8e\xb7\xe5\x8f\x96""Android Permissions\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/AcquireAndroidPermissionAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\x8e\xb7\xe5\x8f\x96""Android Permissions\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPermissions_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AsyncAcquireAndroidPermissions constinit property declarations ********
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPermissions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InPermissions;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AsyncAcquireAndroidPermissions constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AsyncAcquireAndroidPermissions Property Definitions *******************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::NewProp_InPermissions_Inner = { "InPermissions", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::NewProp_InPermissions = { "InPermissions", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AcquireAndroidPermissionAsyncAction_eventAsyncAcquireAndroidPermissions_Parms, InPermissions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPermissions_MetaData), NewProp_InPermissions_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AcquireAndroidPermissionAsyncAction_eventAsyncAcquireAndroidPermissions_Parms, ReturnValue), Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::NewProp_InPermissions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::NewProp_InPermissions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::PropPointers) < 2048);
// ********** End Function AsyncAcquireAndroidPermissions Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction, nullptr, "AsyncAcquireAndroidPermissions", 	Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::AcquireAndroidPermissionAsyncAction_eventAsyncAcquireAndroidPermissions_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::AcquireAndroidPermissionAsyncAction_eventAsyncAcquireAndroidPermissions_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UAcquireAndroidPermissionAsyncAction::execAsyncAcquireAndroidPermissions)
{
	P_GET_TARRAY_REF(FString,Z_Param_Out_InPermissions);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UAcquireAndroidPermissionAsyncAction**)Z_Param__Result=UAcquireAndroidPermissionAsyncAction::AsyncAcquireAndroidPermissions(Z_Param_Out_InPermissions);
	P_NATIVE_END;
}
// ********** End Class UAcquireAndroidPermissionAsyncAction Function AsyncAcquireAndroidPermissions 

// ********** Begin Class UAcquireAndroidPermissionAsyncAction *************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UAcquireAndroidPermissionAsyncAction;
UClass* UAcquireAndroidPermissionAsyncAction::GetPrivateStaticClass()
{
	using TClass = UAcquireAndroidPermissionAsyncAction;
	if (!Z_Registration_Info_UClass_UAcquireAndroidPermissionAsyncAction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("AcquireAndroidPermissionAsyncAction"),
			Z_Registration_Info_UClass_UAcquireAndroidPermissionAsyncAction.InnerSingleton,
			StaticRegisterNativesUAcquireAndroidPermissionAsyncAction,
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
	return Z_Registration_Info_UClass_UAcquireAndroidPermissionAsyncAction.InnerSingleton;
}
UClass* Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_NoRegister()
{
	return UAcquireAndroidPermissionAsyncAction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x90\xe4\xbe\x9b\xe8\x8e\xb7\xe5\x8f\x96""Android\xe6\x9d\x83\xe9\x99\x90\xe5\xbc\x82\xe6\xad\xa5\xe5\x8a\xa8\xe4\xbd\x9c\xe8\x83\xbd\xe5\x8a\x9b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "AsyncFunctions/AcquireAndroidPermissionAsyncAction.h" },
		{ "ModuleRelativePath", "Public/AsyncFunctions/AcquireAndroidPermissionAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x90\xe4\xbe\x9b\xe8\x8e\xb7\xe5\x8f\x96""Android\xe6\x9d\x83\xe9\x99\x90\xe5\xbc\x82\xe6\xad\xa5\xe5\x8a\xa8\xe4\xbd\x9c\xe8\x83\xbd\xe5\x8a\x9b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSuccess_MetaData[] = {
		{ "Category", "Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98On\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/AcquireAndroidPermissionAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98On\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFail_MetaData[] = {
		{ "Category", "Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98On\xe5\xa4\xb1\xe8\xb4\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/AcquireAndroidPermissionAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98On\xe5\xa4\xb1\xe8\xb4\xa5\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UAcquireAndroidPermissionAsyncAction constinit property declarations *****
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFail;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UAcquireAndroidPermissionAsyncAction constinit property declarations *******
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AsyncAcquireAndroidPermission"), .Pointer = &UAcquireAndroidPermissionAsyncAction::execAsyncAcquireAndroidPermission },
		{ .NameUTF8 = UTF8TEXT("AsyncAcquireAndroidPermissions"), .Pointer = &UAcquireAndroidPermissionAsyncAction::execAsyncAcquireAndroidPermissions },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermission, "AsyncAcquireAndroidPermission" }, // 170212415
		{ &Z_Construct_UFunction_UAcquireAndroidPermissionAsyncAction_AsyncAcquireAndroidPermissions, "AsyncAcquireAndroidPermissions" }, // 264783606
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAcquireAndroidPermissionAsyncAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics

// ********** Begin Class UAcquireAndroidPermissionAsyncAction Property Definitions ****************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAcquireAndroidPermissionAsyncAction, OnSuccess), Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedSuccess__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSuccess_MetaData), NewProp_OnSuccess_MetaData) }; // 2671071935
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::NewProp_OnFail = { "OnFail", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAcquireAndroidPermissionAsyncAction, OnFail), Z_Construct_UDelegateFunction_GenericAndroidFramework_OnPermissionsGrantedFail__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFail_MetaData), NewProp_OnFail_MetaData) }; // 3299589751
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::NewProp_OnFail,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::PropPointers) < 2048);
// ********** End Class UAcquireAndroidPermissionAsyncAction Property Definitions ******************
UObject* (*const Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::ClassParams = {
	&UAcquireAndroidPermissionAsyncAction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::PropPointers),
	0,
	0x008800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::Class_MetaDataParams), Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::Class_MetaDataParams)
};
void UAcquireAndroidPermissionAsyncAction::StaticRegisterNativesUAcquireAndroidPermissionAsyncAction()
{
	UClass* Class = UAcquireAndroidPermissionAsyncAction::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::Funcs));
}
UClass* Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction()
{
	if (!Z_Registration_Info_UClass_UAcquireAndroidPermissionAsyncAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAcquireAndroidPermissionAsyncAction.OuterSingleton, Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAcquireAndroidPermissionAsyncAction.OuterSingleton;
}
UAcquireAndroidPermissionAsyncAction::UAcquireAndroidPermissionAsyncAction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UAcquireAndroidPermissionAsyncAction);
UAcquireAndroidPermissionAsyncAction::~UAcquireAndroidPermissionAsyncAction() {}
// ********** End Class UAcquireAndroidPermissionAsyncAction ***************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h__Script_GenericAndroidFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction, UAcquireAndroidPermissionAsyncAction::StaticClass, TEXT("UAcquireAndroidPermissionAsyncAction"), &Z_Registration_Info_UClass_UAcquireAndroidPermissionAsyncAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAcquireAndroidPermissionAsyncAction), 262333974U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h__Script_GenericAndroidFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h__Script_GenericAndroidFramework_208533055{
	TEXT("/Script/GenericAndroidFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h__Script_GenericAndroidFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h__Script_GenericAndroidFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
