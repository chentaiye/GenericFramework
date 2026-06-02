// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AsyncFunctions/GetDesktopDebugReportAsyncAction.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGetDesktopDebugReportAsyncAction() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UGetDesktopDebugReportAsyncAction();
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_NoRegister();
GENERICDESKTOPFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_GenericDesktopFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnDesktopDebugReportReady ********************************************
struct Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics
{
	struct _Script_GenericDesktopFramework_eventOnDesktopDebugReportReady_Parms
	{
		FString DebugReport;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AsyncFunctions/GetDesktopDebugReportAsyncAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DebugReport_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnDesktopDebugReportReady constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_DebugReport;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnDesktopDebugReportReady constinit property declarations **************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnDesktopDebugReportReady Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::NewProp_DebugReport = { "DebugReport", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericDesktopFramework_eventOnDesktopDebugReportReady_Parms, DebugReport), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DebugReport_MetaData), NewProp_DebugReport_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::NewProp_DebugReport,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnDesktopDebugReportReady Property Definitions *************************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericDesktopFramework, nullptr, "OnDesktopDebugReportReady__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::_Script_GenericDesktopFramework_eventOnDesktopDebugReportReady_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::_Script_GenericDesktopFramework_eventOnDesktopDebugReportReady_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnDesktopDebugReportReady_DelegateWrapper(const FMulticastScriptDelegate& OnDesktopDebugReportReady, const FString& DebugReport)
{
	struct _Script_GenericDesktopFramework_eventOnDesktopDebugReportReady_Parms
	{
		FString DebugReport;
	};
	_Script_GenericDesktopFramework_eventOnDesktopDebugReportReady_Parms Parms;
	Parms.DebugReport=DebugReport;
	OnDesktopDebugReportReady.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnDesktopDebugReportReady **********************************************

// ********** Begin Class UGetDesktopDebugReportAsyncAction Function AsyncGetDesktopDebugReport ****
struct Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics
{
	struct GetDesktopDebugReportAsyncAction_eventAsyncGetDesktopDebugReport_Parms
	{
		UGetDesktopDebugReportAsyncAction* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Window|Diagnostics|Async" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe8\xb0\x83\xe8\xaf\x95Report\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/GetDesktopDebugReportAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe8\xb0\x83\xe8\xaf\x95Report\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function AsyncGetDesktopDebugReport constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AsyncGetDesktopDebugReport constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AsyncGetDesktopDebugReport Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GetDesktopDebugReportAsyncAction_eventAsyncGetDesktopDebugReport_Parms, ReturnValue), Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::PropPointers) < 2048);
// ********** End Function AsyncGetDesktopDebugReport Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGetDesktopDebugReportAsyncAction, nullptr, "AsyncGetDesktopDebugReport", 	Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::GetDesktopDebugReportAsyncAction_eventAsyncGetDesktopDebugReport_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::GetDesktopDebugReportAsyncAction_eventAsyncGetDesktopDebugReport_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGetDesktopDebugReportAsyncAction::execAsyncGetDesktopDebugReport)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UGetDesktopDebugReportAsyncAction**)Z_Param__Result=UGetDesktopDebugReportAsyncAction::AsyncGetDesktopDebugReport();
	P_NATIVE_END;
}
// ********** End Class UGetDesktopDebugReportAsyncAction Function AsyncGetDesktopDebugReport ******

// ********** Begin Class UGetDesktopDebugReportAsyncAction ****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGetDesktopDebugReportAsyncAction;
UClass* UGetDesktopDebugReportAsyncAction::GetPrivateStaticClass()
{
	using TClass = UGetDesktopDebugReportAsyncAction;
	if (!Z_Registration_Info_UClass_UGetDesktopDebugReportAsyncAction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GetDesktopDebugReportAsyncAction"),
			Z_Registration_Info_UClass_UGetDesktopDebugReportAsyncAction.InnerSingleton,
			StaticRegisterNativesUGetDesktopDebugReportAsyncAction,
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
	return Z_Registration_Info_UClass_UGetDesktopDebugReportAsyncAction.InnerSingleton;
}
UClass* Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_NoRegister()
{
	return UGetDesktopDebugReportAsyncAction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x90\xe4\xbe\x9b\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe8\xb0\x83\xe8\xaf\x95Report\xe5\xbc\x82\xe6\xad\xa5\xe5\x8a\xa8\xe4\xbd\x9c\xe8\x83\xbd\xe5\x8a\x9b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "AsyncFunctions/GetDesktopDebugReportAsyncAction.h" },
		{ "ModuleRelativePath", "Public/AsyncFunctions/GetDesktopDebugReportAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x90\xe4\xbe\x9b\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe8\xb0\x83\xe8\xaf\x95Report\xe5\xbc\x82\xe6\xad\xa5\xe5\x8a\xa8\xe4\xbd\x9c\xe8\x83\xbd\xe5\x8a\x9b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompleted_MetaData[] = {
		{ "Category", "Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98On\xe5\xb7\xb2\xe5\xae\x8c\xe6\x88\x90\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/GetDesktopDebugReportAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98On\xe5\xb7\xb2\xe5\xae\x8c\xe6\x88\x90\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGetDesktopDebugReportAsyncAction constinit property declarations ********
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCompleted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGetDesktopDebugReportAsyncAction constinit property declarations **********
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AsyncGetDesktopDebugReport"), .Pointer = &UGetDesktopDebugReportAsyncAction::execAsyncGetDesktopDebugReport },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGetDesktopDebugReportAsyncAction_AsyncGetDesktopDebugReport, "AsyncGetDesktopDebugReport" }, // 2086843270
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGetDesktopDebugReportAsyncAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics

// ********** Begin Class UGetDesktopDebugReportAsyncAction Property Definitions *******************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::NewProp_OnCompleted = { "OnCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGetDesktopDebugReportAsyncAction, OnCompleted), Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopDebugReportReady__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompleted_MetaData), NewProp_OnCompleted_MetaData) }; // 2480267546
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::NewProp_OnCompleted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::PropPointers) < 2048);
// ********** End Class UGetDesktopDebugReportAsyncAction Property Definitions *********************
UObject* (*const Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::ClassParams = {
	&UGetDesktopDebugReportAsyncAction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::PropPointers),
	0,
	0x008800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::Class_MetaDataParams), Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::Class_MetaDataParams)
};
void UGetDesktopDebugReportAsyncAction::StaticRegisterNativesUGetDesktopDebugReportAsyncAction()
{
	UClass* Class = UGetDesktopDebugReportAsyncAction::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGetDesktopDebugReportAsyncAction()
{
	if (!Z_Registration_Info_UClass_UGetDesktopDebugReportAsyncAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGetDesktopDebugReportAsyncAction.OuterSingleton, Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGetDesktopDebugReportAsyncAction.OuterSingleton;
}
UGetDesktopDebugReportAsyncAction::UGetDesktopDebugReportAsyncAction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGetDesktopDebugReportAsyncAction);
UGetDesktopDebugReportAsyncAction::~UGetDesktopDebugReportAsyncAction() {}
// ********** End Class UGetDesktopDebugReportAsyncAction ******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h__Script_GenericDesktopFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGetDesktopDebugReportAsyncAction, UGetDesktopDebugReportAsyncAction::StaticClass, TEXT("UGetDesktopDebugReportAsyncAction"), &Z_Registration_Info_UClass_UGetDesktopDebugReportAsyncAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGetDesktopDebugReportAsyncAction), 195487818U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h__Script_GenericDesktopFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h__Script_GenericDesktopFramework_3369384137{
	TEXT("/Script/GenericDesktopFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h__Script_GenericDesktopFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h__Script_GenericDesktopFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
