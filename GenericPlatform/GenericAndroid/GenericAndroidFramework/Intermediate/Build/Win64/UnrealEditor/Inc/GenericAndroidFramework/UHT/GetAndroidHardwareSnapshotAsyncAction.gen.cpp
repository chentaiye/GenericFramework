// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AsyncFunctions/GetAndroidHardwareSnapshotAsyncAction.h"
#include "Type/AndroidType.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGetAndroidHardwareSnapshotAsyncAction() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
GENERICANDROIDFRAMEWORK_API UClass* Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction();
GENERICANDROIDFRAMEWORK_API UClass* Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_NoRegister();
GENERICANDROIDFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature();
GENERICANDROIDFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature();
GENERICANDROIDFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FAndroidHardwareSnapshot();
UPackage* Z_Construct_UPackage__Script_GenericAndroidFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnAndroidHardwareSnapshotReady ***************************************
struct Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics
{
	struct _Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotReady_Parms
	{
		FAndroidHardwareSnapshot Snapshot;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AsyncFunctions/GetAndroidHardwareSnapshotAsyncAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Snapshot_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnAndroidHardwareSnapshotReady constinit property declarations *******
	static const UECodeGen_Private::FStructPropertyParams NewProp_Snapshot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnAndroidHardwareSnapshotReady constinit property declarations *********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnAndroidHardwareSnapshotReady Property Definitions ******************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::NewProp_Snapshot = { "Snapshot", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotReady_Parms, Snapshot), Z_Construct_UScriptStruct_FAndroidHardwareSnapshot, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Snapshot_MetaData), NewProp_Snapshot_MetaData) }; // 434754212
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::NewProp_Snapshot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnAndroidHardwareSnapshotReady Property Definitions ********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework, nullptr, "OnAndroidHardwareSnapshotReady__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::_Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotReady_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::_Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAndroidHardwareSnapshotReady_DelegateWrapper(const FMulticastScriptDelegate& OnAndroidHardwareSnapshotReady, FAndroidHardwareSnapshot const& Snapshot)
{
	struct _Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotReady_Parms
	{
		FAndroidHardwareSnapshot Snapshot;
	};
	_Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotReady_Parms Parms;
	Parms.Snapshot=Snapshot;
	OnAndroidHardwareSnapshotReady.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnAndroidHardwareSnapshotReady *****************************************

// ********** Begin Delegate FOnAndroidHardwareSnapshotFailed **************************************
struct Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics
{
	struct _Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotFailed_Parms
	{
		FString ErrorMessage;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AsyncFunctions/GetAndroidHardwareSnapshotAsyncAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnAndroidHardwareSnapshotFailed constinit property declarations ******
	static const UECodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnAndroidHardwareSnapshotFailed constinit property declarations ********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnAndroidHardwareSnapshotFailed Property Definitions *****************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotFailed_Parms, ErrorMessage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorMessage_MetaData), NewProp_ErrorMessage_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::NewProp_ErrorMessage,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnAndroidHardwareSnapshotFailed Property Definitions *******************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericAndroidFramework, nullptr, "OnAndroidHardwareSnapshotFailed__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::_Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotFailed_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::_Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotFailed_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnAndroidHardwareSnapshotFailed_DelegateWrapper(const FMulticastScriptDelegate& OnAndroidHardwareSnapshotFailed, const FString& ErrorMessage)
{
	struct _Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotFailed_Parms
	{
		FString ErrorMessage;
	};
	_Script_GenericAndroidFramework_eventOnAndroidHardwareSnapshotFailed_Parms Parms;
	Parms.ErrorMessage=ErrorMessage;
	OnAndroidHardwareSnapshotFailed.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnAndroidHardwareSnapshotFailed ****************************************

// ********** Begin Class UGetAndroidHardwareSnapshotAsyncAction Function AsyncGetAndroidHardwareSnapshot 
struct Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics
{
	struct GetAndroidHardwareSnapshotAsyncAction_eventAsyncGetAndroidHardwareSnapshot_Parms
	{
		UGetAndroidHardwareSnapshotAsyncAction* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Android|Diagnostics|Async" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\x8e\xb7\xe5\x8f\x96""Android\xe7\xa1\xac\xe4\xbb\xb6Snapshot\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/GetAndroidHardwareSnapshotAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\x8e\xb7\xe5\x8f\x96""Android\xe7\xa1\xac\xe4\xbb\xb6Snapshot\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AsyncGetAndroidHardwareSnapshot constinit property declarations *******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AsyncGetAndroidHardwareSnapshot constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AsyncGetAndroidHardwareSnapshot Property Definitions ******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GetAndroidHardwareSnapshotAsyncAction_eventAsyncGetAndroidHardwareSnapshot_Parms, ReturnValue), Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::PropPointers) < 2048);
// ********** End Function AsyncGetAndroidHardwareSnapshot Property Definitions ********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction, nullptr, "AsyncGetAndroidHardwareSnapshot", 	Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::GetAndroidHardwareSnapshotAsyncAction_eventAsyncGetAndroidHardwareSnapshot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::GetAndroidHardwareSnapshotAsyncAction_eventAsyncGetAndroidHardwareSnapshot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGetAndroidHardwareSnapshotAsyncAction::execAsyncGetAndroidHardwareSnapshot)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UGetAndroidHardwareSnapshotAsyncAction**)Z_Param__Result=UGetAndroidHardwareSnapshotAsyncAction::AsyncGetAndroidHardwareSnapshot();
	P_NATIVE_END;
}
// ********** End Class UGetAndroidHardwareSnapshotAsyncAction Function AsyncGetAndroidHardwareSnapshot 

// ********** Begin Class UGetAndroidHardwareSnapshotAsyncAction ***********************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGetAndroidHardwareSnapshotAsyncAction;
UClass* UGetAndroidHardwareSnapshotAsyncAction::GetPrivateStaticClass()
{
	using TClass = UGetAndroidHardwareSnapshotAsyncAction;
	if (!Z_Registration_Info_UClass_UGetAndroidHardwareSnapshotAsyncAction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GetAndroidHardwareSnapshotAsyncAction"),
			Z_Registration_Info_UClass_UGetAndroidHardwareSnapshotAsyncAction.InnerSingleton,
			StaticRegisterNativesUGetAndroidHardwareSnapshotAsyncAction,
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
	return Z_Registration_Info_UClass_UGetAndroidHardwareSnapshotAsyncAction.InnerSingleton;
}
UClass* Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_NoRegister()
{
	return UGetAndroidHardwareSnapshotAsyncAction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x90\xe4\xbe\x9b\xe8\x8e\xb7\xe5\x8f\x96""Android\xe7\xa1\xac\xe4\xbb\xb6Snapshot\xe5\xbc\x82\xe6\xad\xa5\xe5\x8a\xa8\xe4\xbd\x9c\xe8\x83\xbd\xe5\x8a\x9b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "AsyncFunctions/GetAndroidHardwareSnapshotAsyncAction.h" },
		{ "ModuleRelativePath", "Public/AsyncFunctions/GetAndroidHardwareSnapshotAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x90\xe4\xbe\x9b\xe8\x8e\xb7\xe5\x8f\x96""Android\xe7\xa1\xac\xe4\xbb\xb6Snapshot\xe5\xbc\x82\xe6\xad\xa5\xe5\x8a\xa8\xe4\xbd\x9c\xe8\x83\xbd\xe5\x8a\x9b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnSuccess_MetaData[] = {
		{ "Category", "Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98On\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/GetAndroidHardwareSnapshotAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98On\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnFail_MetaData[] = {
		{ "Category", "Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98On\xe5\xa4\xb1\xe8\xb4\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/GetAndroidHardwareSnapshotAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98On\xe5\xa4\xb1\xe8\xb4\xa5\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGetAndroidHardwareSnapshotAsyncAction constinit property declarations ***
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSuccess;
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFail;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGetAndroidHardwareSnapshotAsyncAction constinit property declarations *****
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AsyncGetAndroidHardwareSnapshot"), .Pointer = &UGetAndroidHardwareSnapshotAsyncAction::execAsyncGetAndroidHardwareSnapshot },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGetAndroidHardwareSnapshotAsyncAction_AsyncGetAndroidHardwareSnapshot, "AsyncGetAndroidHardwareSnapshot" }, // 989577238
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGetAndroidHardwareSnapshotAsyncAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics

// ********** Begin Class UGetAndroidHardwareSnapshotAsyncAction Property Definitions **************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::NewProp_OnSuccess = { "OnSuccess", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGetAndroidHardwareSnapshotAsyncAction, OnSuccess), Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotReady__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnSuccess_MetaData), NewProp_OnSuccess_MetaData) }; // 313052373
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::NewProp_OnFail = { "OnFail", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGetAndroidHardwareSnapshotAsyncAction, OnFail), Z_Construct_UDelegateFunction_GenericAndroidFramework_OnAndroidHardwareSnapshotFailed__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnFail_MetaData), NewProp_OnFail_MetaData) }; // 2698717138
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::NewProp_OnSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::NewProp_OnFail,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::PropPointers) < 2048);
// ********** End Class UGetAndroidHardwareSnapshotAsyncAction Property Definitions ****************
UObject* (*const Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericAndroidFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::ClassParams = {
	&UGetAndroidHardwareSnapshotAsyncAction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::PropPointers),
	0,
	0x008800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::Class_MetaDataParams), Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::Class_MetaDataParams)
};
void UGetAndroidHardwareSnapshotAsyncAction::StaticRegisterNativesUGetAndroidHardwareSnapshotAsyncAction()
{
	UClass* Class = UGetAndroidHardwareSnapshotAsyncAction::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction()
{
	if (!Z_Registration_Info_UClass_UGetAndroidHardwareSnapshotAsyncAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGetAndroidHardwareSnapshotAsyncAction.OuterSingleton, Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGetAndroidHardwareSnapshotAsyncAction.OuterSingleton;
}
UGetAndroidHardwareSnapshotAsyncAction::UGetAndroidHardwareSnapshotAsyncAction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGetAndroidHardwareSnapshotAsyncAction);
UGetAndroidHardwareSnapshotAsyncAction::~UGetAndroidHardwareSnapshotAsyncAction() {}
// ********** End Class UGetAndroidHardwareSnapshotAsyncAction *************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h__Script_GenericAndroidFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction, UGetAndroidHardwareSnapshotAsyncAction::StaticClass, TEXT("UGetAndroidHardwareSnapshotAsyncAction"), &Z_Registration_Info_UClass_UGetAndroidHardwareSnapshotAsyncAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGetAndroidHardwareSnapshotAsyncAction), 1365046936U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h__Script_GenericAndroidFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h__Script_GenericAndroidFramework_2218872929{
	TEXT("/Script/GenericAndroidFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h__Script_GenericAndroidFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h__Script_GenericAndroidFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
