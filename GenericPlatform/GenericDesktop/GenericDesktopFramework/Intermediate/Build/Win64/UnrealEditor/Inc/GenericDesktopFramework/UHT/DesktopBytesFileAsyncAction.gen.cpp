// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AsyncFunctions/DesktopBytesFileAsyncAction.h"
#include "Type/DesktopType.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDesktopBytesFileAsyncAction() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UDesktopBytesFileAsyncAction();
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UDesktopBytesFileAsyncAction_NoRegister();
GENERICDESKTOPFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopBytesResult();
UPackage* Z_Construct_UPackage__Script_GenericDesktopFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnDesktopBytesFileCompleted ******************************************
struct Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics
{
	struct _Script_GenericDesktopFramework_eventOnDesktopBytesFileCompleted_Parms
	{
		FDesktopBytesResult Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AsyncFunctions/DesktopBytesFileAsyncAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnDesktopBytesFileCompleted constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnDesktopBytesFileCompleted constinit property declarations ************
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnDesktopBytesFileCompleted Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericDesktopFramework_eventOnDesktopBytesFileCompleted_Parms, Result), Z_Construct_UScriptStruct_FDesktopBytesResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 1985964648
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnDesktopBytesFileCompleted Property Definitions ***********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericDesktopFramework, nullptr, "OnDesktopBytesFileCompleted__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::_Script_GenericDesktopFramework_eventOnDesktopBytesFileCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::_Script_GenericDesktopFramework_eventOnDesktopBytesFileCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnDesktopBytesFileCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnDesktopBytesFileCompleted, FDesktopBytesResult const& Result)
{
	struct _Script_GenericDesktopFramework_eventOnDesktopBytesFileCompleted_Parms
	{
		FDesktopBytesResult Result;
	};
	_Script_GenericDesktopFramework_eventOnDesktopBytesFileCompleted_Parms Parms;
	Parms.Result=Result;
	OnDesktopBytesFileCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnDesktopBytesFileCompleted ********************************************

// ********** Begin Class UDesktopBytesFileAsyncAction Function AsyncReadBytesFromFile *************
struct Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics
{
	struct DesktopBytesFileAsyncAction_eventAsyncReadBytesFromFile_Parms
	{
		FString FileName;
		UDesktopBytesFileAsyncAction* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Window|File|Async" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0""From\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/DesktopBytesFileAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0""From\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AsyncReadBytesFromFile constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AsyncReadBytesFromFile constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AsyncReadBytesFromFile Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopBytesFileAsyncAction_eventAsyncReadBytesFromFile_Parms, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopBytesFileAsyncAction_eventAsyncReadBytesFromFile_Parms, ReturnValue), Z_Construct_UClass_UDesktopBytesFileAsyncAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::PropPointers) < 2048);
// ********** End Function AsyncReadBytesFromFile Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDesktopBytesFileAsyncAction, nullptr, "AsyncReadBytesFromFile", 	Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::DesktopBytesFileAsyncAction_eventAsyncReadBytesFromFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::DesktopBytesFileAsyncAction_eventAsyncReadBytesFromFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDesktopBytesFileAsyncAction::execAsyncReadBytesFromFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDesktopBytesFileAsyncAction**)Z_Param__Result=UDesktopBytesFileAsyncAction::AsyncReadBytesFromFile(Z_Param_FileName);
	P_NATIVE_END;
}
// ********** End Class UDesktopBytesFileAsyncAction Function AsyncReadBytesFromFile ***************

// ********** Begin Class UDesktopBytesFileAsyncAction Function AsyncWriteBytesToFile **************
struct Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics
{
	struct DesktopBytesFileAsyncAction_eventAsyncWriteBytesToFile_Parms
	{
		FString FileName;
		TArray<uint8> Data;
		UDesktopBytesFileAsyncAction* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Window|File|Async" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0To\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/DesktopBytesFileAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0To\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AsyncWriteBytesToFile constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Data_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Data;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AsyncWriteBytesToFile constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AsyncWriteBytesToFile Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopBytesFileAsyncAction_eventAsyncWriteBytesToFile_Parms, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::NewProp_Data_Inner = { "Data", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopBytesFileAsyncAction_eventAsyncWriteBytesToFile_Parms, Data), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Data_MetaData), NewProp_Data_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopBytesFileAsyncAction_eventAsyncWriteBytesToFile_Parms, ReturnValue), Z_Construct_UClass_UDesktopBytesFileAsyncAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::NewProp_Data_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::NewProp_Data,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::PropPointers) < 2048);
// ********** End Function AsyncWriteBytesToFile Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDesktopBytesFileAsyncAction, nullptr, "AsyncWriteBytesToFile", 	Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::DesktopBytesFileAsyncAction_eventAsyncWriteBytesToFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::DesktopBytesFileAsyncAction_eventAsyncWriteBytesToFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDesktopBytesFileAsyncAction::execAsyncWriteBytesToFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_TARRAY_REF(uint8,Z_Param_Out_Data);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDesktopBytesFileAsyncAction**)Z_Param__Result=UDesktopBytesFileAsyncAction::AsyncWriteBytesToFile(Z_Param_FileName,Z_Param_Out_Data);
	P_NATIVE_END;
}
// ********** End Class UDesktopBytesFileAsyncAction Function AsyncWriteBytesToFile ****************

// ********** Begin Class UDesktopBytesFileAsyncAction *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDesktopBytesFileAsyncAction;
UClass* UDesktopBytesFileAsyncAction::GetPrivateStaticClass()
{
	using TClass = UDesktopBytesFileAsyncAction;
	if (!Z_Registration_Info_UClass_UDesktopBytesFileAsyncAction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DesktopBytesFileAsyncAction"),
			Z_Registration_Info_UClass_UDesktopBytesFileAsyncAction.InnerSingleton,
			StaticRegisterNativesUDesktopBytesFileAsyncAction,
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
	return Z_Registration_Info_UClass_UDesktopBytesFileAsyncAction.InnerSingleton;
}
UClass* Z_Construct_UClass_UDesktopBytesFileAsyncAction_NoRegister()
{
	return UDesktopBytesFileAsyncAction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x90\xe4\xbe\x9b\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe6\x96\x87\xe4\xbb\xb6\xe5\xbc\x82\xe6\xad\xa5\xe5\x8a\xa8\xe4\xbd\x9c\xe8\x83\xbd\xe5\x8a\x9b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "AsyncFunctions/DesktopBytesFileAsyncAction.h" },
		{ "ModuleRelativePath", "Public/AsyncFunctions/DesktopBytesFileAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x90\xe4\xbe\x9b\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe6\x96\x87\xe4\xbb\xb6\xe5\xbc\x82\xe6\xad\xa5\xe5\x8a\xa8\xe4\xbd\x9c\xe8\x83\xbd\xe5\x8a\x9b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompleted_MetaData[] = {
		{ "Category", "Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98On\xe5\xb7\xb2\xe5\xae\x8c\xe6\x88\x90\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/DesktopBytesFileAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98On\xe5\xb7\xb2\xe5\xae\x8c\xe6\x88\x90\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UDesktopBytesFileAsyncAction constinit property declarations *************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCompleted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDesktopBytesFileAsyncAction constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AsyncReadBytesFromFile"), .Pointer = &UDesktopBytesFileAsyncAction::execAsyncReadBytesFromFile },
		{ .NameUTF8 = UTF8TEXT("AsyncWriteBytesToFile"), .Pointer = &UDesktopBytesFileAsyncAction::execAsyncWriteBytesToFile },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncReadBytesFromFile, "AsyncReadBytesFromFile" }, // 1195546963
		{ &Z_Construct_UFunction_UDesktopBytesFileAsyncAction_AsyncWriteBytesToFile, "AsyncWriteBytesToFile" }, // 876977638
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDesktopBytesFileAsyncAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics

// ********** Begin Class UDesktopBytesFileAsyncAction Property Definitions ************************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::NewProp_OnCompleted = { "OnCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDesktopBytesFileAsyncAction, OnCompleted), Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopBytesFileCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompleted_MetaData), NewProp_OnCompleted_MetaData) }; // 237902097
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::NewProp_OnCompleted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::PropPointers) < 2048);
// ********** End Class UDesktopBytesFileAsyncAction Property Definitions **************************
UObject* (*const Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::ClassParams = {
	&UDesktopBytesFileAsyncAction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::PropPointers),
	0,
	0x008800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::Class_MetaDataParams), Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::Class_MetaDataParams)
};
void UDesktopBytesFileAsyncAction::StaticRegisterNativesUDesktopBytesFileAsyncAction()
{
	UClass* Class = UDesktopBytesFileAsyncAction::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDesktopBytesFileAsyncAction()
{
	if (!Z_Registration_Info_UClass_UDesktopBytesFileAsyncAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDesktopBytesFileAsyncAction.OuterSingleton, Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDesktopBytesFileAsyncAction.OuterSingleton;
}
UDesktopBytesFileAsyncAction::UDesktopBytesFileAsyncAction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDesktopBytesFileAsyncAction);
UDesktopBytesFileAsyncAction::~UDesktopBytesFileAsyncAction() {}
// ********** End Class UDesktopBytesFileAsyncAction ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h__Script_GenericDesktopFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDesktopBytesFileAsyncAction, UDesktopBytesFileAsyncAction::StaticClass, TEXT("UDesktopBytesFileAsyncAction"), &Z_Registration_Info_UClass_UDesktopBytesFileAsyncAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDesktopBytesFileAsyncAction), 107389664U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h__Script_GenericDesktopFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h__Script_GenericDesktopFramework_3102707067{
	TEXT("/Script/GenericDesktopFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h__Script_GenericDesktopFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h__Script_GenericDesktopFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
