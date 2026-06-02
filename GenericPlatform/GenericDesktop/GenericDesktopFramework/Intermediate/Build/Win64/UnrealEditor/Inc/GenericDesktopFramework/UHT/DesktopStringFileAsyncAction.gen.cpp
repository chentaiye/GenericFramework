// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AsyncFunctions/DesktopStringFileAsyncAction.h"
#include "Type/DesktopType.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDesktopStringFileAsyncAction() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UDesktopStringFileAsyncAction();
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UDesktopStringFileAsyncAction_NoRegister();
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions();
GENERICDESKTOPFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopStringResult();
UPackage* Z_Construct_UPackage__Script_GenericDesktopFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FOnDesktopStringFileCompleted *****************************************
struct Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics
{
	struct _Script_GenericDesktopFramework_eventOnDesktopStringFileCompleted_Parms
	{
		FDesktopStringResult Result;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AsyncFunctions/DesktopStringFileAsyncAction.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Result_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FOnDesktopStringFileCompleted constinit property declarations *********
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Delegate FOnDesktopStringFileCompleted constinit property declarations ***********
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};

// ********** Begin Delegate FOnDesktopStringFileCompleted Property Definitions ********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GenericDesktopFramework_eventOnDesktopStringFileCompleted_Parms, Result), Z_Construct_UScriptStruct_FDesktopStringResult, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Result_MetaData), NewProp_Result_MetaData) }; // 3654214038
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::NewProp_Result,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::PropPointers) < 2048);
// ********** End Delegate FOnDesktopStringFileCompleted Property Definitions **********************
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericDesktopFramework, nullptr, "OnDesktopStringFileCompleted__DelegateSignature", 	Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::PropPointers), 
sizeof(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::_Script_GenericDesktopFramework_eventOnDesktopStringFileCompleted_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00530000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::_Script_GenericDesktopFramework_eventOnDesktopStringFileCompleted_Parms) < MAX_uint16);
UFunction* Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FOnDesktopStringFileCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnDesktopStringFileCompleted, FDesktopStringResult const& Result)
{
	struct _Script_GenericDesktopFramework_eventOnDesktopStringFileCompleted_Parms
	{
		FDesktopStringResult Result;
	};
	_Script_GenericDesktopFramework_eventOnDesktopStringFileCompleted_Parms Parms;
	Parms.Result=Result;
	OnDesktopStringFileCompleted.ProcessMulticastDelegate<UObject>(&Parms);
}
// ********** End Delegate FOnDesktopStringFileCompleted *******************************************

// ********** Begin Class UDesktopStringFileAsyncAction Function AsyncReadStringFromFile ***********
struct Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics
{
	struct DesktopStringFileAsyncAction_eventAsyncReadStringFromFile_Parms
	{
		FString FileName;
		UDesktopStringFileAsyncAction* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Window|File|Async" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2""From\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/DesktopStringFileAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2""From\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AsyncReadStringFromFile constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AsyncReadStringFromFile constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AsyncReadStringFromFile Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopStringFileAsyncAction_eventAsyncReadStringFromFile_Parms, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopStringFileAsyncAction_eventAsyncReadStringFromFile_Parms, ReturnValue), Z_Construct_UClass_UDesktopStringFileAsyncAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::PropPointers) < 2048);
// ********** End Function AsyncReadStringFromFile Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDesktopStringFileAsyncAction, nullptr, "AsyncReadStringFromFile", 	Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::DesktopStringFileAsyncAction_eventAsyncReadStringFromFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::DesktopStringFileAsyncAction_eventAsyncReadStringFromFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDesktopStringFileAsyncAction::execAsyncReadStringFromFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDesktopStringFileAsyncAction**)Z_Param__Result=UDesktopStringFileAsyncAction::AsyncReadStringFromFile(Z_Param_FileName);
	P_NATIVE_END;
}
// ********** End Class UDesktopStringFileAsyncAction Function AsyncReadStringFromFile *************

// ********** Begin Class UDesktopStringFileAsyncAction Function AsyncWriteStringToFile ************
struct Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics
{
	struct DesktopStringFileAsyncAction_eventAsyncWriteStringToFile_Parms
	{
		FString Data;
		FString FileName;
		EDesktopTextEncodingOptions EncodingOptions;
		UDesktopStringFileAsyncAction* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Window|File|Async" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2To\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_EncodingOptions", "AutoDetect" },
		{ "ModuleRelativePath", "Public/AsyncFunctions/DesktopStringFileAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\xbc\x82\xe6\xad\xa5\xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2To\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Data_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AsyncWriteStringToFile constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Data;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EncodingOptions_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EncodingOptions;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AsyncWriteStringToFile constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AsyncWriteStringToFile Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopStringFileAsyncAction_eventAsyncWriteStringToFile_Parms, Data), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Data_MetaData), NewProp_Data_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopStringFileAsyncAction_eventAsyncWriteStringToFile_Parms, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::NewProp_EncodingOptions_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::NewProp_EncodingOptions = { "EncodingOptions", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopStringFileAsyncAction_eventAsyncWriteStringToFile_Parms, EncodingOptions), Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions, METADATA_PARAMS(0, nullptr) }; // 2503097535
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(DesktopStringFileAsyncAction_eventAsyncWriteStringToFile_Parms, ReturnValue), Z_Construct_UClass_UDesktopStringFileAsyncAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::NewProp_Data,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::NewProp_EncodingOptions_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::NewProp_EncodingOptions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::PropPointers) < 2048);
// ********** End Function AsyncWriteStringToFile Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UDesktopStringFileAsyncAction, nullptr, "AsyncWriteStringToFile", 	Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::DesktopStringFileAsyncAction_eventAsyncWriteStringToFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::DesktopStringFileAsyncAction_eventAsyncWriteStringToFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UDesktopStringFileAsyncAction::execAsyncWriteStringToFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Data);
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_ENUM(EDesktopTextEncodingOptions,Z_Param_EncodingOptions);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDesktopStringFileAsyncAction**)Z_Param__Result=UDesktopStringFileAsyncAction::AsyncWriteStringToFile(Z_Param_Data,Z_Param_FileName,EDesktopTextEncodingOptions(Z_Param_EncodingOptions));
	P_NATIVE_END;
}
// ********** End Class UDesktopStringFileAsyncAction Function AsyncWriteStringToFile **************

// ********** Begin Class UDesktopStringFileAsyncAction ********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDesktopStringFileAsyncAction;
UClass* UDesktopStringFileAsyncAction::GetPrivateStaticClass()
{
	using TClass = UDesktopStringFileAsyncAction;
	if (!Z_Registration_Info_UClass_UDesktopStringFileAsyncAction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DesktopStringFileAsyncAction"),
			Z_Registration_Info_UClass_UDesktopStringFileAsyncAction.InnerSingleton,
			StaticRegisterNativesUDesktopStringFileAsyncAction,
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
	return Z_Registration_Info_UClass_UDesktopStringFileAsyncAction.InnerSingleton;
}
UClass* Z_Construct_UClass_UDesktopStringFileAsyncAction_NoRegister()
{
	return UDesktopStringFileAsyncAction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x90\xe4\xbe\x9b\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe6\x96\x87\xe4\xbb\xb6\xe5\xbc\x82\xe6\xad\xa5\xe5\x8a\xa8\xe4\xbd\x9c\xe8\x83\xbd\xe5\x8a\x9b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "AsyncFunctions/DesktopStringFileAsyncAction.h" },
		{ "ModuleRelativePath", "Public/AsyncFunctions/DesktopStringFileAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x90\xe4\xbe\x9b\xe6\xa1\x8c\xe9\x9d\xa2\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe6\x96\x87\xe4\xbb\xb6\xe5\xbc\x82\xe6\xad\xa5\xe5\x8a\xa8\xe4\xbd\x9c\xe8\x83\xbd\xe5\x8a\x9b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OnCompleted_MetaData[] = {
		{ "Category", "Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98On\xe5\xb7\xb2\xe5\xae\x8c\xe6\x88\x90\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncFunctions/DesktopStringFileAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98On\xe5\xb7\xb2\xe5\xae\x8c\xe6\x88\x90\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UDesktopStringFileAsyncAction constinit property declarations ************
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnCompleted;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDesktopStringFileAsyncAction constinit property declarations **************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AsyncReadStringFromFile"), .Pointer = &UDesktopStringFileAsyncAction::execAsyncReadStringFromFile },
		{ .NameUTF8 = UTF8TEXT("AsyncWriteStringToFile"), .Pointer = &UDesktopStringFileAsyncAction::execAsyncWriteStringToFile },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncReadStringFromFile, "AsyncReadStringFromFile" }, // 3829793169
		{ &Z_Construct_UFunction_UDesktopStringFileAsyncAction_AsyncWriteStringToFile, "AsyncWriteStringToFile" }, // 2009244297
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDesktopStringFileAsyncAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics

// ********** Begin Class UDesktopStringFileAsyncAction Property Definitions ***********************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::NewProp_OnCompleted = { "OnCompleted", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDesktopStringFileAsyncAction, OnCompleted), Z_Construct_UDelegateFunction_GenericDesktopFramework_OnDesktopStringFileCompleted__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OnCompleted_MetaData), NewProp_OnCompleted_MetaData) }; // 4118111372
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::NewProp_OnCompleted,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::PropPointers) < 2048);
// ********** End Class UDesktopStringFileAsyncAction Property Definitions *************************
UObject* (*const Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::ClassParams = {
	&UDesktopStringFileAsyncAction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::PropPointers),
	0,
	0x008800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::Class_MetaDataParams), Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::Class_MetaDataParams)
};
void UDesktopStringFileAsyncAction::StaticRegisterNativesUDesktopStringFileAsyncAction()
{
	UClass* Class = UDesktopStringFileAsyncAction::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::Funcs));
}
UClass* Z_Construct_UClass_UDesktopStringFileAsyncAction()
{
	if (!Z_Registration_Info_UClass_UDesktopStringFileAsyncAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDesktopStringFileAsyncAction.OuterSingleton, Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDesktopStringFileAsyncAction.OuterSingleton;
}
UDesktopStringFileAsyncAction::UDesktopStringFileAsyncAction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDesktopStringFileAsyncAction);
UDesktopStringFileAsyncAction::~UDesktopStringFileAsyncAction() {}
// ********** End Class UDesktopStringFileAsyncAction **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h__Script_GenericDesktopFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDesktopStringFileAsyncAction, UDesktopStringFileAsyncAction::StaticClass, TEXT("UDesktopStringFileAsyncAction"), &Z_Registration_Info_UClass_UDesktopStringFileAsyncAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDesktopStringFileAsyncAction), 953662751U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h__Script_GenericDesktopFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h__Script_GenericDesktopFramework_3321448758{
	TEXT("/Script/GenericDesktopFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h__Script_GenericDesktopFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h__Script_GenericDesktopFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
