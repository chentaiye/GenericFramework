// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/BPFunctions_Desktop.h"
#include "Type/DesktopType.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBPFunctions_Desktop() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FDateTime();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_Desktop();
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_Desktop_NoRegister();
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode();
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat();
GENERICDESKTOPFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopApplicationInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopCPUInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopDiskInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopDisplayInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopGPUInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopHardwareSnapshot();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopMainWindowInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopMemoryInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopMonitorInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopNetworkInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopPowerInfo();
GENERICDESKTOPFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FDesktopSystemPathInfo();
UPackage* Z_Construct_UPackage__Script_GenericDesktopFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBPFunctions_Desktop Function AddBytesToFile *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics
{
	struct BPFunctions_Desktop_eventAddBytesToFile_Parms
	{
		FString FileName;
		TArray<uint8> Bytes;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe6\xb7\xbb\xe5\x8a\xa0\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0To\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe6\xb7\xbb\xe5\x8a\xa0\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0To\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function AddBytesToFile constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Bytes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Bytes;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function AddBytesToFile constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function AddBytesToFile Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventAddBytesToFile_Parms, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::NewProp_Bytes_Inner = { "Bytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::NewProp_Bytes = { "Bytes", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventAddBytesToFile_Parms, Bytes), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventAddBytesToFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventAddBytesToFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::NewProp_Bytes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::NewProp_Bytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::PropPointers) < 2048);
// ********** End Function AddBytesToFile Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "AddBytesToFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::BPFunctions_Desktop_eventAddBytesToFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::BPFunctions_Desktop_eventAddBytesToFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execAddBytesToFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_TARRAY(uint8,Z_Param_Bytes);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::AddBytesToFile(Z_Param_FileName,Z_Param_Bytes);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function AddBytesToFile *******************************

// ********** Begin Class UBPFunctions_Desktop Function Base64StringToBytes ************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics
{
	struct BPFunctions_Desktop_eventBase64StringToBytes_Parms
	{
		FString Base64String;
		TArray<uint8> Bytes;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\x9f\xba\xe7\xa1\x80""64\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2To\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\x9f\xba\xe7\xa1\x80""64\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2To\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Base64StringToBytes constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Base64String;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Bytes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Bytes;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Base64StringToBytes constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Base64StringToBytes Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::NewProp_Base64String = { "Base64String", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventBase64StringToBytes_Parms, Base64String), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::NewProp_Bytes_Inner = { "Bytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::NewProp_Bytes = { "Bytes", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventBase64StringToBytes_Parms, Bytes), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventBase64StringToBytes_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventBase64StringToBytes_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::NewProp_Base64String,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::NewProp_Bytes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::NewProp_Bytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::PropPointers) < 2048);
// ********** End Function Base64StringToBytes Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "Base64StringToBytes", 	Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::BPFunctions_Desktop_eventBase64StringToBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::BPFunctions_Desktop_eventBase64StringToBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execBase64StringToBytes)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Base64String);
	P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::Base64StringToBytes(Z_Param_Base64String,Z_Param_Out_Bytes);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function Base64StringToBytes **************************

// ********** Begin Class UBPFunctions_Desktop Function Base64StringToString ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics
{
	struct BPFunctions_Desktop_eventBase64StringToString_Parms
	{
		FString Base64String;
		FString String;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\x9f\xba\xe7\xa1\x80""64\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2To\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\x9f\xba\xe7\xa1\x80""64\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2To\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Base64StringToString constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Base64String;
	static const UECodeGen_Private::FStrPropertyParams NewProp_String;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Base64StringToString constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Base64StringToString Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::NewProp_Base64String = { "Base64String", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventBase64StringToString_Parms, Base64String), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::NewProp_String = { "String", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventBase64StringToString_Parms, String), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventBase64StringToString_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventBase64StringToString_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::NewProp_Base64String,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::NewProp_String,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::PropPointers) < 2048);
// ********** End Function Base64StringToString Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "Base64StringToString", 	Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::BPFunctions_Desktop_eventBase64StringToString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::BPFunctions_Desktop_eventBase64StringToString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execBase64StringToString)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Base64String);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_String);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::Base64StringToString(Z_Param_Base64String,Z_Param_Out_String);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function Base64StringToString *************************

// ********** Begin Class UBPFunctions_Desktop Function BringMainWindowToFront *********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics
{
	struct BPFunctions_Desktop_eventBringMainWindowToFront_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Bring Main\xe7\xaa\x97\xe5\x8f\xa3To Front\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Bring Main\xe7\xaa\x97\xe5\x8f\xa3To Front\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BringMainWindowToFront constinit property declarations ****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BringMainWindowToFront constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BringMainWindowToFront Property Definitions ***************************
void Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventBringMainWindowToFront_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventBringMainWindowToFront_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::PropPointers) < 2048);
// ********** End Function BringMainWindowToFront Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "BringMainWindowToFront", 	Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::BPFunctions_Desktop_eventBringMainWindowToFront_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::BPFunctions_Desktop_eventBringMainWindowToFront_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execBringMainWindowToFront)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::BringMainWindowToFront();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function BringMainWindowToFront ***********************

// ********** Begin Class UBPFunctions_Desktop Function BytesToBase64String ************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics
{
	struct BPFunctions_Desktop_eventBytesToBase64String_Parms
	{
		TArray<uint8> Bytes;
		FString Base64String;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0To\xe5\x9f\xba\xe7\xa1\x80""64\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0To\xe5\x9f\xba\xe7\xa1\x80""64\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function BytesToBase64String constinit property declarations *******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_Bytes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Bytes;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Base64String;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BytesToBase64String constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BytesToBase64String Property Definitions ******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::NewProp_Bytes_Inner = { "Bytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::NewProp_Bytes = { "Bytes", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventBytesToBase64String_Parms, Bytes), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::NewProp_Base64String = { "Base64String", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventBytesToBase64String_Parms, Base64String), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::NewProp_Bytes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::NewProp_Bytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::NewProp_Base64String,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::PropPointers) < 2048);
// ********** End Function BytesToBase64String Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "BytesToBase64String", 	Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::BPFunctions_Desktop_eventBytesToBase64String_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::BPFunctions_Desktop_eventBytesToBase64String_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execBytesToBase64String)
{
	P_GET_TARRAY(uint8,Z_Param_Bytes);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Base64String);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::BytesToBase64String(Z_Param_Bytes,Z_Param_Out_Base64String);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function BytesToBase64String **************************

// ********** Begin Class UBPFunctions_Desktop Function CanLaunchUrl *******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics
{
	struct BPFunctions_Desktop_eventCanLaunchUrl_Parms
	{
		FString InUrl;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Shell" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\xaf\xe4\xbb\xa5\xe5\x90\xaf\xe5\x8a\xa8URL\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x98\xaf\xe5\x90\xa6\xe5\x8f\xaf\xe4\xbb\xa5\xe5\x90\xaf\xe5\x8a\xa8URL\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InUrl_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function CanLaunchUrl constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InUrl;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CanLaunchUrl constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CanLaunchUrl Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::NewProp_InUrl = { "InUrl", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventCanLaunchUrl_Parms, InUrl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InUrl_MetaData), NewProp_InUrl_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventCanLaunchUrl_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventCanLaunchUrl_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::NewProp_InUrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::PropPointers) < 2048);
// ********** End Function CanLaunchUrl Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "CanLaunchUrl", 	Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::BPFunctions_Desktop_eventCanLaunchUrl_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::BPFunctions_Desktop_eventCanLaunchUrl_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execCanLaunchUrl)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InUrl);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::CanLaunchUrl(Z_Param_InUrl);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function CanLaunchUrl *********************************

// ********** Begin Class UBPFunctions_Desktop Function ConvBytesToTexture2D ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics
{
	struct BPFunctions_Desktop_eventConvBytesToTexture2D_Parms
	{
		TArray<uint8> InBytes;
		UTexture2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0To\xe7\xba\xb9\xe7\x90\x86""2 D\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "To Texture2D (Bytes)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0To\xe7\xba\xb9\xe7\x90\x86""2 D\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InBytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConvBytesToTexture2D constinit property declarations ******************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InBytes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_InBytes;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConvBytesToTexture2D constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConvBytesToTexture2D Property Definitions *****************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::NewProp_InBytes_Inner = { "InBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::NewProp_InBytes = { "InBytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventConvBytesToTexture2D_Parms, InBytes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InBytes_MetaData), NewProp_InBytes_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventConvBytesToTexture2D_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::NewProp_InBytes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::NewProp_InBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::PropPointers) < 2048);
// ********** End Function ConvBytesToTexture2D Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "ConvBytesToTexture2D", 	Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::BPFunctions_Desktop_eventConvBytesToTexture2D_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::BPFunctions_Desktop_eventConvBytesToTexture2D_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execConvBytesToTexture2D)
{
	P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture2D**)Z_Param__Result=UBPFunctions_Desktop::ConvBytesToTexture2D(Z_Param_Out_InBytes);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function ConvBytesToTexture2D *************************

// ********** Begin Class UBPFunctions_Desktop Function ConvertToFullPath **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics
{
	struct BPFunctions_Desktop_eventConvertToFullPath_Parms
	{
		FString Filename;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xba\xe6\xbb\xa1\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "To Full" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xba\xe6\xbb\xa1\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConvertToFullPath constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Filename;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConvertToFullPath constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConvertToFullPath Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::NewProp_Filename = { "Filename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventConvertToFullPath_Parms, Filename), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filename_MetaData), NewProp_Filename_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventConvertToFullPath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::NewProp_Filename,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::PropPointers) < 2048);
// ********** End Function ConvertToFullPath Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "ConvertToFullPath", 	Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::BPFunctions_Desktop_eventConvertToFullPath_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::BPFunctions_Desktop_eventConvertToFullPath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execConvertToFullPath)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Filename);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::ConvertToFullPath(Z_Param_Filename);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function ConvertToFullPath ****************************

// ********** Begin Class UBPFunctions_Desktop Function ConvertToRelativePath **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics
{
	struct BPFunctions_Desktop_eventConvertToRelativePath_Parms
	{
		FString Filename;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xbaRelative\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "To Relative" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2\xe4\xb8\xbaRelative\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ConvertToRelativePath constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Filename;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConvertToRelativePath constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConvertToRelativePath Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::NewProp_Filename = { "Filename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventConvertToRelativePath_Parms, Filename), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filename_MetaData), NewProp_Filename_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventConvertToRelativePath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::NewProp_Filename,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::PropPointers) < 2048);
// ********** End Function ConvertToRelativePath Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "ConvertToRelativePath", 	Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::BPFunctions_Desktop_eventConvertToRelativePath_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::BPFunctions_Desktop_eventConvertToRelativePath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execConvertToRelativePath)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Filename);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::ConvertToRelativePath(Z_Param_Filename);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function ConvertToRelativePath ************************

// ********** Begin Class UBPFunctions_Desktop Function ConvTexture2DToBytes ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics
{
	struct BPFunctions_Desktop_eventConvTexture2DToBytes_Parms
	{
		UTexture2D* Texture;
		TArray<uint8> OutBuffer;
		EDesktopImageFormat Format;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2\xe7\xba\xb9\xe7\x90\x86""2 D To\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_Format", "PNG" },
		{ "DisplayName", "To Bytes (Texture2D)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2\xe7\xba\xb9\xe7\x90\x86""2 D To\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ConvTexture2DToBytes constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutBuffer_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutBuffer;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Format_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Format;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ConvTexture2DToBytes constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ConvTexture2DToBytes Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventConvTexture2DToBytes_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_OutBuffer_Inner = { "OutBuffer", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_OutBuffer = { "OutBuffer", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventConvTexture2DToBytes_Parms, OutBuffer), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_Format_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_Format = { "Format", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventConvTexture2DToBytes_Parms, Format), Z_Construct_UEnum_GenericDesktopFramework_EDesktopImageFormat, METADATA_PARAMS(0, nullptr) }; // 2623952161
void Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventConvTexture2DToBytes_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventConvTexture2DToBytes_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_Texture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_OutBuffer_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_OutBuffer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_Format_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_Format,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::PropPointers) < 2048);
// ********** End Function ConvTexture2DToBytes Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "ConvTexture2DToBytes", 	Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::BPFunctions_Desktop_eventConvTexture2DToBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::BPFunctions_Desktop_eventConvTexture2DToBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execConvTexture2DToBytes)
{
	P_GET_OBJECT(UTexture2D,Z_Param_Texture);
	P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBuffer);
	P_GET_ENUM(EDesktopImageFormat,Z_Param_Format);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::ConvTexture2DToBytes(Z_Param_Texture,Z_Param_Out_OutBuffer,EDesktopImageFormat(Z_Param_Format));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function ConvTexture2DToBytes *************************

// ********** Begin Class UBPFunctions_Desktop Function CopyFile ***********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics
{
	struct BPFunctions_Desktop_eventCopyFile_Parms
	{
		FString FileSource;
		FString FileDest;
		bool Replace;
		bool EvenIfReadOnly;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Copy\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_EvenIfReadOnly", "false" },
		{ "CPP_Default_Replace", "true" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Copy\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CopyFile constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileSource;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileDest;
	static void NewProp_Replace_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Replace;
	static void NewProp_EvenIfReadOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_EvenIfReadOnly;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CopyFile constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CopyFile Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_FileSource = { "FileSource", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventCopyFile_Parms, FileSource), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_FileDest = { "FileDest", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventCopyFile_Parms, FileDest), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_Replace_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventCopyFile_Parms*)Obj)->Replace = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_Replace = { "Replace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventCopyFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_Replace_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_EvenIfReadOnly_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventCopyFile_Parms*)Obj)->EvenIfReadOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_EvenIfReadOnly = { "EvenIfReadOnly", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventCopyFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_EvenIfReadOnly_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventCopyFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventCopyFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_FileSource,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_FileDest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_Replace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_EvenIfReadOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::PropPointers) < 2048);
// ********** End Function CopyFile Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "CopyFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::BPFunctions_Desktop_eventCopyFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::BPFunctions_Desktop_eventCopyFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execCopyFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileSource);
	P_GET_PROPERTY(FStrProperty,Z_Param_FileDest);
	P_GET_UBOOL(Z_Param_Replace);
	P_GET_UBOOL(Z_Param_EvenIfReadOnly);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::CopyFile(Z_Param_FileSource,Z_Param_FileDest,Z_Param_Replace,Z_Param_EvenIfReadOnly);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function CopyFile *************************************

// ********** Begin Class UBPFunctions_Desktop Function CreateDirectory ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics
{
	struct BPFunctions_Desktop_eventCreateDirectory_Parms
	{
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Directory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\x9b\xe5\xbb\xba\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\x9b\xe5\xbb\xba\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function CreateDirectory constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function CreateDirectory constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function CreateDirectory Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventCreateDirectory_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventCreateDirectory_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventCreateDirectory_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::PropPointers) < 2048);
// ********** End Function CreateDirectory Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "CreateDirectory", 	Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::BPFunctions_Desktop_eventCreateDirectory_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::BPFunctions_Desktop_eventCreateDirectory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execCreateDirectory)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::CreateDirectory(Z_Param_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function CreateDirectory ******************************

// ********** Begin Class UBPFunctions_Desktop Function DeleteDirectory ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics
{
	struct BPFunctions_Desktop_eventDeleteDirectory_Parms
	{
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Directory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Delete\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Delete\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DeleteDirectory constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DeleteDirectory constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DeleteDirectory Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventDeleteDirectory_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventDeleteDirectory_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventDeleteDirectory_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::PropPointers) < 2048);
// ********** End Function DeleteDirectory Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "DeleteDirectory", 	Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::BPFunctions_Desktop_eventDeleteDirectory_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::BPFunctions_Desktop_eventDeleteDirectory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execDeleteDirectory)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::DeleteDirectory(Z_Param_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function DeleteDirectory ******************************

// ********** Begin Class UBPFunctions_Desktop Function DeleteDirectoryRecursively *****************
struct Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics
{
	struct BPFunctions_Desktop_eventDeleteDirectoryRecursively_Parms
	{
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Directory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Delete\xe7\x9b\xae\xe5\xbd\x95Recursively\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Delete\xe7\x9b\xae\xe5\xbd\x95Recursively\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DeleteDirectoryRecursively constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DeleteDirectoryRecursively constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DeleteDirectoryRecursively Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventDeleteDirectoryRecursively_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventDeleteDirectoryRecursively_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventDeleteDirectoryRecursively_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::PropPointers) < 2048);
// ********** End Function DeleteDirectoryRecursively Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "DeleteDirectoryRecursively", 	Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::BPFunctions_Desktop_eventDeleteDirectoryRecursively_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::BPFunctions_Desktop_eventDeleteDirectoryRecursively_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execDeleteDirectoryRecursively)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::DeleteDirectoryRecursively(Z_Param_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function DeleteDirectoryRecursively *******************

// ********** Begin Class UBPFunctions_Desktop Function DeleteFile *********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics
{
	struct BPFunctions_Desktop_eventDeleteFile_Parms
	{
		FString FileName;
		bool RequireExists;
		bool EvenReadOnly;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Delete\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_EvenReadOnly", "false" },
		{ "CPP_Default_RequireExists", "false" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Delete\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function DeleteFile constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static void NewProp_RequireExists_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_RequireExists;
	static void NewProp_EvenReadOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_EvenReadOnly;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function DeleteFile constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function DeleteFile Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventDeleteFile_Parms, FileName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_RequireExists_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventDeleteFile_Parms*)Obj)->RequireExists = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_RequireExists = { "RequireExists", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventDeleteFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_RequireExists_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_EvenReadOnly_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventDeleteFile_Parms*)Obj)->EvenReadOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_EvenReadOnly = { "EvenReadOnly", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventDeleteFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_EvenReadOnly_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventDeleteFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventDeleteFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_RequireExists,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_EvenReadOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::PropPointers) < 2048);
// ********** End Function DeleteFile Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "DeleteFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::BPFunctions_Desktop_eventDeleteFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::BPFunctions_Desktop_eventDeleteFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execDeleteFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_UBOOL(Z_Param_RequireExists);
	P_GET_UBOOL(Z_Param_EvenReadOnly);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::DeleteFile(Z_Param_FileName,Z_Param_RequireExists,Z_Param_EvenReadOnly);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function DeleteFile ***********************************

// ********** Begin Class UBPFunctions_Desktop Function ExistDirectory *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics
{
	struct BPFunctions_Desktop_eventExistDirectory_Parms
	{
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Directory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Exist\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Exist\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ExistDirectory constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExistDirectory constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExistDirectory Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventExistDirectory_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventExistDirectory_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventExistDirectory_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::PropPointers) < 2048);
// ********** End Function ExistDirectory Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "ExistDirectory", 	Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::BPFunctions_Desktop_eventExistDirectory_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::BPFunctions_Desktop_eventExistDirectory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execExistDirectory)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::ExistDirectory(Z_Param_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function ExistDirectory *******************************

// ********** Begin Class UBPFunctions_Desktop Function ExistFile **********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics
{
	struct BPFunctions_Desktop_eventExistFile_Parms
	{
		FString FileName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Exist\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Exist\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ExistFile constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ExistFile constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ExistFile Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventExistFile_Parms, FileName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventExistFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventExistFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::PropPointers) < 2048);
// ********** End Function ExistFile Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "ExistFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::BPFunctions_Desktop_eventExistFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::BPFunctions_Desktop_eventExistFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execExistFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::ExistFile(Z_Param_FileName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function ExistFile ************************************

// ********** Begin Class UBPFunctions_Desktop Function FileSize ***********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics
{
	struct BPFunctions_Desktop_eventFileSize_Parms
	{
		FString Filename;
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\xa7\xe8\xa1\x8c\xe6\x96\x87\xe4\xbb\xb6\xe5\xb0\xba\xe5\xaf\xb8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\xa7\xe8\xa1\x8c\xe6\x96\x87\xe4\xbb\xb6\xe5\xb0\xba\xe5\xaf\xb8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FileSize constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Filename;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FileSize constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FileSize Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::NewProp_Filename = { "Filename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFileSize_Parms, Filename), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFileSize_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::NewProp_Filename,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::PropPointers) < 2048);
// ********** End Function FileSize Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "FileSize", 	Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::BPFunctions_Desktop_eventFileSize_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::BPFunctions_Desktop_eventFileSize_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_FileSize()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_FileSize_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execFileSize)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Filename);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=UBPFunctions_Desktop::FileSize(Z_Param_Filename);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function FileSize *************************************

// ********** Begin Class UBPFunctions_Desktop Function FindDirectory ******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics
{
	struct BPFunctions_Desktop_eventFindDirectory_Parms
	{
		FString Directory;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Directory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9f\xa5\xe6\x89\xbe\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9f\xa5\xe6\x89\xbe\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FindDirectory constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindDirectory constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindDirectory Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFindDirectory_Parms, Directory), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFindDirectory_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::PropPointers) < 2048);
// ********** End Function FindDirectory Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "FindDirectory", 	Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::BPFunctions_Desktop_eventFindDirectory_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::BPFunctions_Desktop_eventFindDirectory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execFindDirectory)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UBPFunctions_Desktop::FindDirectory(Z_Param_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function FindDirectory ********************************

// ********** Begin Class UBPFunctions_Desktop Function FindDirectoryRecursive *********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics
{
	struct BPFunctions_Desktop_eventFindDirectoryRecursive_Parms
	{
		FString Directory;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Directory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9f\xa5\xe6\x89\xbe\xe7\x9b\xae\xe5\xbd\x95Recursive\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9f\xa5\xe6\x89\xbe\xe7\x9b\xae\xe5\xbd\x95Recursive\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FindDirectoryRecursive constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindDirectoryRecursive constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindDirectoryRecursive Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFindDirectoryRecursive_Parms, Directory), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFindDirectoryRecursive_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::PropPointers) < 2048);
// ********** End Function FindDirectoryRecursive Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "FindDirectoryRecursive", 	Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::BPFunctions_Desktop_eventFindDirectoryRecursive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::BPFunctions_Desktop_eventFindDirectoryRecursive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execFindDirectoryRecursive)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UBPFunctions_Desktop::FindDirectoryRecursive(Z_Param_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function FindDirectoryRecursive ***********************

// ********** Begin Class UBPFunctions_Desktop Function FindFile ***********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics
{
	struct BPFunctions_Desktop_eventFindFile_Parms
	{
		FString Directory;
		FString Extension;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9f\xa5\xe6\x89\xbe\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_Extension", "*.*" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9f\xa5\xe6\x89\xbe\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FindFile constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Extension;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindFile constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindFile Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFindFile_Parms, Directory), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::NewProp_Extension = { "Extension", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFindFile_Parms, Extension), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFindFile_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::NewProp_Extension,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::PropPointers) < 2048);
// ********** End Function FindFile Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "FindFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::BPFunctions_Desktop_eventFindFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::BPFunctions_Desktop_eventFindFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_FindFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_FindFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execFindFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
	P_GET_PROPERTY(FStrProperty,Z_Param_Extension);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UBPFunctions_Desktop::FindFile(Z_Param_Directory,Z_Param_Extension);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function FindFile *************************************

// ********** Begin Class UBPFunctions_Desktop Function FindFileRecursive **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics
{
	struct BPFunctions_Desktop_eventFindFileRecursive_Parms
	{
		FString Directory;
		FString Extension;
		TArray<FString> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9f\xa5\xe6\x89\xbe\xe6\x96\x87\xe4\xbb\xb6Recursive\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_Extension", "*.*" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9f\xa5\xe6\x89\xbe\xe6\x96\x87\xe4\xbb\xb6Recursive\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FindFileRecursive constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Extension;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindFileRecursive constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindFileRecursive Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFindFileRecursive_Parms, Directory), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::NewProp_Extension = { "Extension", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFindFileRecursive_Parms, Extension), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventFindFileRecursive_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::NewProp_Extension,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::PropPointers) < 2048);
// ********** End Function FindFileRecursive Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "FindFileRecursive", 	Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::BPFunctions_Desktop_eventFindFileRecursive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::BPFunctions_Desktop_eventFindFileRecursive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execFindFileRecursive)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
	P_GET_PROPERTY(FStrProperty,Z_Param_Extension);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FString>*)Z_Param__Result=UBPFunctions_Desktop::FindFileRecursive(Z_Param_Directory,Z_Param_Extension);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function FindFileRecursive ****************************

// ********** Begin Class UBPFunctions_Desktop Function FlashMainWindow ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics
{
	struct BPFunctions_Desktop_eventFlashMainWindow_Parms
	{
		bool bStop;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86""Flash Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_bStop", "false" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86""Flash Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function FlashMainWindow constinit property declarations ***********************
	static void NewProp_bStop_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bStop;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FlashMainWindow constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FlashMainWindow Property Definitions **********************************
void Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::NewProp_bStop_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventFlashMainWindow_Parms*)Obj)->bStop = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::NewProp_bStop = { "bStop", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventFlashMainWindow_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::NewProp_bStop_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventFlashMainWindow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventFlashMainWindow_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::NewProp_bStop,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::PropPointers) < 2048);
// ********** End Function FlashMainWindow Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "FlashMainWindow", 	Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::BPFunctions_Desktop_eventFlashMainWindow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::BPFunctions_Desktop_eventFlashMainWindow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execFlashMainWindow)
{
	P_GET_UBOOL(Z_Param_bStop);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::FlashMainWindow(Z_Param_bStop);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function FlashMainWindow ******************************

// ********** Begin Class UBPFunctions_Desktop Function GetAllDiskInfos ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics
{
	struct BPFunctions_Desktop_eventGetAllDiskInfos_Parms
	{
		TArray<FDesktopDiskInfo> OutInfos;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Disk" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xa8\xe9\x83\xa8\xe7\xa3\x81\xe7\x9b\x98Infos\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xa8\xe9\x83\xa8\xe7\xa3\x81\xe7\x9b\x98Infos\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllDiskInfos constinit property declarations ***********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfos_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutInfos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllDiskInfos constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllDiskInfos Property Definitions **********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::NewProp_OutInfos_Inner = { "OutInfos", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDesktopDiskInfo, METADATA_PARAMS(0, nullptr) }; // 1522185633
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::NewProp_OutInfos = { "OutInfos", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetAllDiskInfos_Parms, OutInfos), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1522185633
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::NewProp_OutInfos_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::NewProp_OutInfos,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::PropPointers) < 2048);
// ********** End Function GetAllDiskInfos Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetAllDiskInfos", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::BPFunctions_Desktop_eventGetAllDiskInfos_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::BPFunctions_Desktop_eventGetAllDiskInfos_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetAllDiskInfos)
{
	P_GET_TARRAY_REF(FDesktopDiskInfo,Z_Param_Out_OutInfos);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetAllDiskInfos(Z_Param_Out_OutInfos);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetAllDiskInfos ******************************

// ********** Begin Class UBPFunctions_Desktop Function GetAllMonitorInfos *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics
{
	struct BPFunctions_Desktop_eventGetAllMonitorInfos_Parms
	{
		TArray<FDesktopMonitorInfo> OutInfos;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xa8\xe9\x83\xa8Monitor Infos\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x85\xa8\xe9\x83\xa8Monitor Infos\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllMonitorInfos constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfos_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutInfos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllMonitorInfos constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllMonitorInfos Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::NewProp_OutInfos_Inner = { "OutInfos", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDesktopMonitorInfo, METADATA_PARAMS(0, nullptr) }; // 1496936958
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::NewProp_OutInfos = { "OutInfos", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetAllMonitorInfos_Parms, OutInfos), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 1496936958
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::NewProp_OutInfos_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::NewProp_OutInfos,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::PropPointers) < 2048);
// ********** End Function GetAllMonitorInfos Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetAllMonitorInfos", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::BPFunctions_Desktop_eventGetAllMonitorInfos_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::BPFunctions_Desktop_eventGetAllMonitorInfos_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetAllMonitorInfos)
{
	P_GET_TARRAY_REF(FDesktopMonitorInfo,Z_Param_Out_OutInfos);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetAllMonitorInfos(Z_Param_Out_OutInfos);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetAllMonitorInfos ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetAppDataDir ******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics
{
	struct BPFunctions_Desktop_eventGetAppDataDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\xba\x94\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\xba\x94\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetAppDataDir constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAppDataDir constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAppDataDir Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetAppDataDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::PropPointers) < 2048);
// ********** End Function GetAppDataDir Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetAppDataDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::BPFunctions_Desktop_eventGetAppDataDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::BPFunctions_Desktop_eventGetAppDataDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetAppDataDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetAppDataDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetAppDataDir ********************************

// ********** Begin Class UBPFunctions_Desktop Function GetApplicationInfo *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics
{
	struct BPFunctions_Desktop_eventGetApplicationInfo_Parms
	{
		FDesktopApplicationInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xba\x94\xe7\x94\xa8\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetApplicationInfo constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetApplicationInfo constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetApplicationInfo Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetApplicationInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopApplicationInfo, METADATA_PARAMS(0, nullptr) }; // 3859191725
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::PropPointers) < 2048);
// ********** End Function GetApplicationInfo Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetApplicationInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::BPFunctions_Desktop_eventGetApplicationInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::BPFunctions_Desktop_eventGetApplicationInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetApplicationInfo)
{
	P_GET_STRUCT_REF(FDesktopApplicationInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetApplicationInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetApplicationInfo ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetBaseFilename ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics
{
	struct BPFunctions_Desktop_eventGetBaseFilename_Parms
	{
		FString FileName;
		bool bRemovePath;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x9f\xba\xe7\xa1\x80""Filename\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_bRemovePath", "true" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x9f\xba\xe7\xa1\x80""Filename\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetBaseFilename constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static void NewProp_bRemovePath_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bRemovePath;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBaseFilename constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBaseFilename Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetBaseFilename_Parms, FileName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::NewProp_bRemovePath_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetBaseFilename_Parms*)Obj)->bRemovePath = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::NewProp_bRemovePath = { "bRemovePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetBaseFilename_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::NewProp_bRemovePath_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetBaseFilename_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::NewProp_bRemovePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::PropPointers) < 2048);
// ********** End Function GetBaseFilename Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetBaseFilename", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::BPFunctions_Desktop_eventGetBaseFilename_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::BPFunctions_Desktop_eventGetBaseFilename_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetBaseFilename)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_UBOOL(Z_Param_bRemovePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetBaseFilename(Z_Param_FileName,Z_Param_bRemovePath);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetBaseFilename ******************************

// ********** Begin Class UBPFunctions_Desktop Function GetBatteryPercent **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics
{
	struct BPFunctions_Desktop_eventGetBatteryPercent_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Power" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\x94\xb5\xe6\xb1\xa0\xe7\x94\xb5\xe9\x87\x8f\xe7\x99\xbe\xe5\x88\x86\xe6\xaf\x94\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\x94\xb5\xe6\xb1\xa0\xe7\x94\xb5\xe9\x87\x8f\xe7\x99\xbe\xe5\x88\x86\xe6\xaf\x94\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetBatteryPercent constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetBatteryPercent constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetBatteryPercent Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetBatteryPercent_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::PropPointers) < 2048);
// ********** End Function GetBatteryPercent Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetBatteryPercent", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::BPFunctions_Desktop_eventGetBatteryPercent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::BPFunctions_Desktop_eventGetBatteryPercent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetBatteryPercent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Desktop::GetBatteryPercent();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetBatteryPercent ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetCleanFilename ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics
{
	struct BPFunctions_Desktop_eventGetCleanFilename_Parms
	{
		FString FileName;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Clean Filename\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Clean Filename\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCleanFilename constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCleanFilename constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCleanFilename Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCleanFilename_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCleanFilename_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::PropPointers) < 2048);
// ********** End Function GetCleanFilename Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCleanFilename", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::BPFunctions_Desktop_eventGetCleanFilename_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::BPFunctions_Desktop_eventGetCleanFilename_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCleanFilename)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetCleanFilename(Z_Param_FileName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCleanFilename *****************************

// ********** Begin Class UBPFunctions_Desktop Function GetClipboardText ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics
{
	struct BPFunctions_Desktop_eventGetClipboardText_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Shell" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Clipboard\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Clipboard\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetClipboardText constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetClipboardText constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetClipboardText Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetClipboardText_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::PropPointers) < 2048);
// ********** End Function GetClipboardText Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetClipboardText", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::BPFunctions_Desktop_eventGetClipboardText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::BPFunctions_Desktop_eventGetClipboardText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetClipboardText)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetClipboardText();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetClipboardText *****************************

// ********** Begin Class UBPFunctions_Desktop Function GetCommandLineString ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics
{
	struct BPFunctions_Desktop_eventGetCommandLineString_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x91\xbd\xe4\xbb\xa4\xe8\xa1\x8c\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x91\xbd\xe4\xbb\xa4\xe8\xa1\x8c\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCommandLineString constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCommandLineString constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCommandLineString Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCommandLineString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::PropPointers) < 2048);
// ********** End Function GetCommandLineString Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCommandLineString", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::BPFunctions_Desktop_eventGetCommandLineString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::BPFunctions_Desktop_eventGetCommandLineString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCommandLineString)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetCommandLineString();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCommandLineString *************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPUBrand ********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics
{
	struct BPFunctions_Desktop_eventGetCPUBrand_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUBrand constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUBrand constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUBrand Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPUBrand_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::PropPointers) < 2048);
// ********** End Function GetCPUBrand Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPUBrand", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::BPFunctions_Desktop_eventGetCPUBrand_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::BPFunctions_Desktop_eventGetCPUBrand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPUBrand)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetCPUBrand();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPUBrand **********************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPUChipset ******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics
{
	struct BPFunctions_Desktop_eventGetCPUChipset_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe8\x8a\xaf\xe7\x89\x87\xe7\xbb\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe8\x8a\xaf\xe7\x89\x87\xe7\xbb\x84\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUChipset constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUChipset constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUChipset Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPUChipset_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::PropPointers) < 2048);
// ********** End Function GetCPUChipset Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPUChipset", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::BPFunctions_Desktop_eventGetCPUChipset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::BPFunctions_Desktop_eventGetCPUChipset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPUChipset)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetCPUChipset();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPUChipset ********************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPUCores ********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics
{
	struct BPFunctions_Desktop_eventGetCPUCores_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUCores constinit property declarations ***************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUCores constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUCores Property Definitions **************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPUCores_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::PropPointers) < 2048);
// ********** End Function GetCPUCores Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPUCores", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::BPFunctions_Desktop_eventGetCPUCores_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::BPFunctions_Desktop_eventGetCPUCores_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPUCores)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Desktop::GetCPUCores();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPUCores **********************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPUFrequency ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics
{
	struct BPFunctions_Desktop_eventGetCPUFrequency_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU Frequency\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU Frequency\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUFrequency constinit property declarations ***********************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUFrequency constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUFrequency Property Definitions **********************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPUFrequency_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::PropPointers) < 2048);
// ********** End Function GetCPUFrequency Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPUFrequency", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::BPFunctions_Desktop_eventGetCPUFrequency_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::BPFunctions_Desktop_eventGetCPUFrequency_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPUFrequency)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UBPFunctions_Desktop::GetCPUFrequency();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPUFrequency ******************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPUHardwareInfo *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics
{
	struct BPFunctions_Desktop_eventGetCPUHardwareInfo_Parms
	{
		FDesktopCPUInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUHardwareInfo constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUHardwareInfo constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUHardwareInfo Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPUHardwareInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopCPUInfo, METADATA_PARAMS(0, nullptr) }; // 2400951084
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::PropPointers) < 2048);
// ********** End Function GetCPUHardwareInfo Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPUHardwareInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::BPFunctions_Desktop_eventGetCPUHardwareInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::BPFunctions_Desktop_eventGetCPUHardwareInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPUHardwareInfo)
{
	P_GET_STRUCT_REF(FDesktopCPUInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetCPUHardwareInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPUHardwareInfo ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPULogicalCores *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics
{
	struct BPFunctions_Desktop_eventGetCPULogicalCores_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe9\x80\xbb\xe8\xbe\x91\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe9\x80\xbb\xe8\xbe\x91\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPULogicalCores constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPULogicalCores constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPULogicalCores Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPULogicalCores_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::PropPointers) < 2048);
// ********** End Function GetCPULogicalCores Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPULogicalCores", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::BPFunctions_Desktop_eventGetCPULogicalCores_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::BPFunctions_Desktop_eventGetCPULogicalCores_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPULogicalCores)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Desktop::GetCPULogicalCores();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPULogicalCores ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPUPhysicalCores ************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics
{
	struct BPFunctions_Desktop_eventGetCPUPhysicalCores_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe7\x89\xa9\xe7\x90\x86\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe7\x89\xa9\xe7\x90\x86\xe6\xa0\xb8\xe5\xbf\x83\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUPhysicalCores constinit property declarations *******************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUPhysicalCores constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUPhysicalCores Property Definitions ******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPUPhysicalCores_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::PropPointers) < 2048);
// ********** End Function GetCPUPhysicalCores Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPUPhysicalCores", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::BPFunctions_Desktop_eventGetCPUPhysicalCores_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::BPFunctions_Desktop_eventGetCPUPhysicalCores_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPUPhysicalCores)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Desktop::GetCPUPhysicalCores();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPUPhysicalCores **************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPUProcessCount *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics
{
	struct BPFunctions_Desktop_eventGetCPUProcessCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe8\xbf\x9b\xe7\xa8\x8b\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe8\xbf\x9b\xe7\xa8\x8b\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUProcessCount constinit property declarations ********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUProcessCount constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUProcessCount Property Definitions *******************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPUProcessCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::PropPointers) < 2048);
// ********** End Function GetCPUProcessCount Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPUProcessCount", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::BPFunctions_Desktop_eventGetCPUProcessCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::BPFunctions_Desktop_eventGetCPUProcessCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPUProcessCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Desktop::GetCPUProcessCount();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPUProcessCount ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPUThreadCount **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics
{
	struct BPFunctions_Desktop_eventGetCPUThreadCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe7\xba\xbf\xe7\xa8\x8b\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe7\xba\xbf\xe7\xa8\x8b\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUThreadCount constinit property declarations *********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUThreadCount constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUThreadCount Property Definitions ********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPUThreadCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::PropPointers) < 2048);
// ********** End Function GetCPUThreadCount Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPUThreadCount", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::BPFunctions_Desktop_eventGetCPUThreadCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::BPFunctions_Desktop_eventGetCPUThreadCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPUThreadCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Desktop::GetCPUThreadCount();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPUThreadCount ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPUUsage ********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics
{
	struct BPFunctions_Desktop_eventGetCPUUsage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUUsage constinit property declarations ***************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUUsage constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUUsage Property Definitions **************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPUUsage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::PropPointers) < 2048);
// ********** End Function GetCPUUsage Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPUUsage", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::BPFunctions_Desktop_eventGetCPUUsage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::BPFunctions_Desktop_eventGetCPUUsage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPUUsage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UBPFunctions_Desktop::GetCPUUsage();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPUUsage **********************************

// ********** Begin Class UBPFunctions_Desktop Function GetCPUVendor *******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics
{
	struct BPFunctions_Desktop_eventGetCPUVendor_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""CPU\xe5\x8e\x82\xe5\x95\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""CPU\xe5\x8e\x82\xe5\x95\x86\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCPUVendor constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCPUVendor constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCPUVendor Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCPUVendor_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::PropPointers) < 2048);
// ********** End Function GetCPUVendor Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCPUVendor", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::BPFunctions_Desktop_eventGetCPUVendor_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::BPFunctions_Desktop_eventGetCPUVendor_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCPUVendor)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetCPUVendor();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCPUVendor *********************************

// ********** Begin Class UBPFunctions_Desktop Function GetCurrentMonitorInfo **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics
{
	struct BPFunctions_Desktop_eventGetCurrentMonitorInfo_Parms
	{
		FDesktopMonitorInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8dMonitor\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\xbd\x93\xe5\x89\x8dMonitor\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetCurrentMonitorInfo constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetCurrentMonitorInfo constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetCurrentMonitorInfo Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetCurrentMonitorInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopMonitorInfo, METADATA_PARAMS(0, nullptr) }; // 1496936958
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::PropPointers) < 2048);
// ********** End Function GetCurrentMonitorInfo Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetCurrentMonitorInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::BPFunctions_Desktop_eventGetCurrentMonitorInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::BPFunctions_Desktop_eventGetCurrentMonitorInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetCurrentMonitorInfo)
{
	P_GET_STRUCT_REF(FDesktopMonitorInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetCurrentMonitorInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetCurrentMonitorInfo ************************

// ********** Begin Class UBPFunctions_Desktop Function GetDesktopBaseDir **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics
{
	struct BPFunctions_Desktop_eventGetDesktopBaseDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe5\x9f\xba\xe7\xa1\x80\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe5\x9f\xba\xe7\xa1\x80\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDesktopBaseDir constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDesktopBaseDir constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDesktopBaseDir Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDesktopBaseDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::PropPointers) < 2048);
// ********** End Function GetDesktopBaseDir Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDesktopBaseDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::BPFunctions_Desktop_eventGetDesktopBaseDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::BPFunctions_Desktop_eventGetDesktopBaseDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDesktopBaseDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetDesktopBaseDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDesktopBaseDir ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetDesktopDir ******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics
{
	struct BPFunctions_Desktop_eventGetDesktopDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDesktopDir constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDesktopDir constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDesktopDir Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDesktopDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::PropPointers) < 2048);
// ********** End Function GetDesktopDir Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDesktopDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::BPFunctions_Desktop_eventGetDesktopDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::BPFunctions_Desktop_eventGetDesktopDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDesktopDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetDesktopDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDesktopDir ********************************

// ********** Begin Class UBPFunctions_Desktop Function GetDesktopName *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics
{
	struct BPFunctions_Desktop_eventGetDesktopName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDesktopName constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDesktopName constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDesktopName Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDesktopName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::PropPointers) < 2048);
// ********** End Function GetDesktopName Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDesktopName", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::BPFunctions_Desktop_eventGetDesktopName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::BPFunctions_Desktop_eventGetDesktopName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDesktopName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetDesktopName();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDesktopName *******************************

// ********** Begin Class UBPFunctions_Desktop Function GetDesktopUserDir **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics
{
	struct BPFunctions_Desktop_eventGetDesktopUserDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xa8\xe6\x88\xb7\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xa8\xe6\x88\xb7\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDesktopUserDir constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDesktopUserDir constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDesktopUserDir Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDesktopUserDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::PropPointers) < 2048);
// ********** End Function GetDesktopUserDir Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDesktopUserDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::BPFunctions_Desktop_eventGetDesktopUserDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::BPFunctions_Desktop_eventGetDesktopUserDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDesktopUserDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetDesktopUserDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDesktopUserDir ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetDesktopUserHomeDir **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics
{
	struct BPFunctions_Desktop_eventGetDesktopUserHomeDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xa8\xe6\x88\xb7\xe4\xb8\xbb\xe7\x9b\xae\xe5\xbd\x95\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xa8\xe6\x88\xb7\xe4\xb8\xbb\xe7\x9b\xae\xe5\xbd\x95\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDesktopUserHomeDir constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDesktopUserHomeDir constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDesktopUserHomeDir Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDesktopUserHomeDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::PropPointers) < 2048);
// ********** End Function GetDesktopUserHomeDir Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDesktopUserHomeDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::BPFunctions_Desktop_eventGetDesktopUserHomeDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::BPFunctions_Desktop_eventGetDesktopUserHomeDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDesktopUserHomeDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetDesktopUserHomeDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDesktopUserHomeDir ************************

// ********** Begin Class UBPFunctions_Desktop Function GetDesktopUserName *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics
{
	struct BPFunctions_Desktop_eventGetDesktopUserName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xa8\xe6\x88\xb7\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xa8\xe6\x88\xb7\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDesktopUserName constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDesktopUserName constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDesktopUserName Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDesktopUserName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::PropPointers) < 2048);
// ********** End Function GetDesktopUserName Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDesktopUserName", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::BPFunctions_Desktop_eventGetDesktopUserName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::BPFunctions_Desktop_eventGetDesktopUserName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDesktopUserName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetDesktopUserName();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDesktopUserName ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetDesktopUserTempDir **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics
{
	struct BPFunctions_Desktop_eventGetDesktopUserTempDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xa8\xe6\x88\xb7\xe4\xb8\xb4\xe6\x97\xb6\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\xa1\x8c\xe9\x9d\xa2\xe7\x94\xa8\xe6\x88\xb7\xe4\xb8\xb4\xe6\x97\xb6\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDesktopUserTempDir constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDesktopUserTempDir constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDesktopUserTempDir Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDesktopUserTempDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::PropPointers) < 2048);
// ********** End Function GetDesktopUserTempDir Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDesktopUserTempDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::BPFunctions_Desktop_eventGetDesktopUserTempDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::BPFunctions_Desktop_eventGetDesktopUserTempDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDesktopUserTempDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetDesktopUserTempDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDesktopUserTempDir ************************

// ********** Begin Class UBPFunctions_Desktop Function GetDeviceID ********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics
{
	struct BPFunctions_Desktop_eventGetDeviceID_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe8\xae\xbe\xe5\xa4\x87 ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe8\xae\xbe\xe5\xa4\x87 ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDeviceID constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDeviceID constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDeviceID Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDeviceID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::PropPointers) < 2048);
// ********** End Function GetDeviceID Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDeviceID", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::BPFunctions_Desktop_eventGetDeviceID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::BPFunctions_Desktop_eventGetDeviceID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDeviceID)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetDeviceID();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDeviceID **********************************

// ********** Begin Class UBPFunctions_Desktop Function GetDiskFreeBytes ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics
{
	struct BPFunctions_Desktop_eventGetDiskFreeBytes_Parms
	{
		FString InPath;
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Disk" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xa3\x81\xe7\x9b\x98\xe5\x8f\xaf\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xa3\x81\xe7\x9b\x98\xe5\x8f\xaf\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDiskFreeBytes constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPath;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDiskFreeBytes constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDiskFreeBytes Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::NewProp_InPath = { "InPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDiskFreeBytes_Parms, InPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPath_MetaData), NewProp_InPath_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDiskFreeBytes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::NewProp_InPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::PropPointers) < 2048);
// ********** End Function GetDiskFreeBytes Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDiskFreeBytes", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::BPFunctions_Desktop_eventGetDiskFreeBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::BPFunctions_Desktop_eventGetDiskFreeBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDiskFreeBytes)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=UBPFunctions_Desktop::GetDiskFreeBytes(Z_Param_InPath);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDiskFreeBytes *****************************

// ********** Begin Class UBPFunctions_Desktop Function GetDiskInfo ********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics
{
	struct BPFunctions_Desktop_eventGetDiskInfo_Parms
	{
		FString InPath;
		FDesktopDiskInfo OutInfo;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Disk" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xa3\x81\xe7\x9b\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xa3\x81\xe7\x9b\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDiskInfo constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPath;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDiskInfo constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDiskInfo Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::NewProp_InPath = { "InPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDiskInfo_Parms, InPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPath_MetaData), NewProp_InPath_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDiskInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopDiskInfo, METADATA_PARAMS(0, nullptr) }; // 1522185633
void Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetDiskInfo_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetDiskInfo_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::NewProp_InPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::NewProp_OutInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::PropPointers) < 2048);
// ********** End Function GetDiskInfo Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDiskInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::BPFunctions_Desktop_eventGetDiskInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::BPFunctions_Desktop_eventGetDiskInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDiskInfo)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPath);
	P_GET_STRUCT_REF(FDesktopDiskInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::GetDiskInfo(Z_Param_InPath,Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDiskInfo **********************************

// ********** Begin Class UBPFunctions_Desktop Function GetDiskTotalBytes **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics
{
	struct BPFunctions_Desktop_eventGetDiskTotalBytes_Parms
	{
		FString InPath;
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Disk" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xa3\x81\xe7\x9b\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xa3\x81\xe7\x9b\x98\xe6\x80\xbb\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDiskTotalBytes constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPath;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDiskTotalBytes constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDiskTotalBytes Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::NewProp_InPath = { "InPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDiskTotalBytes_Parms, InPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPath_MetaData), NewProp_InPath_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDiskTotalBytes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::NewProp_InPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::PropPointers) < 2048);
// ********** End Function GetDiskTotalBytes Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDiskTotalBytes", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::BPFunctions_Desktop_eventGetDiskTotalBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::BPFunctions_Desktop_eventGetDiskTotalBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDiskTotalBytes)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=UBPFunctions_Desktop::GetDiskTotalBytes(Z_Param_InPath);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDiskTotalBytes ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetDiskUsedBytes ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics
{
	struct BPFunctions_Desktop_eventGetDiskUsedBytes_Parms
	{
		FString InPath;
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Disk" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xa3\x81\xe7\x9b\x98\xe5\xb7\xb2\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xa3\x81\xe7\x9b\x98\xe5\xb7\xb2\xe7\x94\xa8\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetDiskUsedBytes constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPath;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDiskUsedBytes constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDiskUsedBytes Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::NewProp_InPath = { "InPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDiskUsedBytes_Parms, InPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPath_MetaData), NewProp_InPath_MetaData) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDiskUsedBytes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::NewProp_InPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::PropPointers) < 2048);
// ********** End Function GetDiskUsedBytes Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDiskUsedBytes", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::BPFunctions_Desktop_eventGetDiskUsedBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::BPFunctions_Desktop_eventGetDiskUsedBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDiskUsedBytes)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=UBPFunctions_Desktop::GetDiskUsedBytes(Z_Param_InPath);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDiskUsedBytes *****************************

// ********** Begin Class UBPFunctions_Desktop Function GetDisplayInfo *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics
{
	struct BPFunctions_Desktop_eventGetDisplayInfo_Parms
	{
		FDesktopDisplayInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x98\xbe\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDisplayInfo constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDisplayInfo constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDisplayInfo Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDisplayInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopDisplayInfo, METADATA_PARAMS(0, nullptr) }; // 1657045473
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::PropPointers) < 2048);
// ********** End Function GetDisplayInfo Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDisplayInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::BPFunctions_Desktop_eventGetDisplayInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::BPFunctions_Desktop_eventGetDisplayInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDisplayInfo)
{
	P_GET_STRUCT_REF(FDesktopDisplayInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetDisplayInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDisplayInfo *******************************

// ********** Begin Class UBPFunctions_Desktop Function GetDocumentsDir ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics
{
	struct BPFunctions_Desktop_eventGetDocumentsDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Documents\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Documents\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDocumentsDir constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDocumentsDir constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDocumentsDir Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDocumentsDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::PropPointers) < 2048);
// ********** End Function GetDocumentsDir Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDocumentsDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::BPFunctions_Desktop_eventGetDocumentsDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::BPFunctions_Desktop_eventGetDocumentsDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDocumentsDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetDocumentsDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDocumentsDir ******************************

// ********** Begin Class UBPFunctions_Desktop Function GetDownloadsDir ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics
{
	struct BPFunctions_Desktop_eventGetDownloadsDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Downloads\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Downloads\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDownloadsDir constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDownloadsDir constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDownloadsDir Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetDownloadsDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::PropPointers) < 2048);
// ********** End Function GetDownloadsDir Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetDownloadsDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::BPFunctions_Desktop_eventGetDownloadsDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::BPFunctions_Desktop_eventGetDownloadsDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetDownloadsDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetDownloadsDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetDownloadsDir ******************************

// ********** Begin Class UBPFunctions_Desktop Function GetEnvironmentVariable *********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics
{
	struct BPFunctions_Desktop_eventGetEnvironmentVariable_Parms
	{
		FString VariableName;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Environment Variable\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Environment Variable\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VariableName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetEnvironmentVariable constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_VariableName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetEnvironmentVariable constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetEnvironmentVariable Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::NewProp_VariableName = { "VariableName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetEnvironmentVariable_Parms, VariableName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VariableName_MetaData), NewProp_VariableName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetEnvironmentVariable_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::NewProp_VariableName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::PropPointers) < 2048);
// ********** End Function GetEnvironmentVariable Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetEnvironmentVariable", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::BPFunctions_Desktop_eventGetEnvironmentVariable_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::BPFunctions_Desktop_eventGetEnvironmentVariable_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetEnvironmentVariable)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_VariableName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetEnvironmentVariable(Z_Param_VariableName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetEnvironmentVariable ***********************

// ********** Begin Class UBPFunctions_Desktop Function GetExecutablePath **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics
{
	struct BPFunctions_Desktop_eventGetExecutablePath_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x8f\xaf\xe6\x89\xa7\xe8\xa1\x8c\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x8f\xaf\xe6\x89\xa7\xe8\xa1\x8c\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetExecutablePath constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetExecutablePath constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetExecutablePath Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetExecutablePath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::PropPointers) < 2048);
// ********** End Function GetExecutablePath Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetExecutablePath", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::BPFunctions_Desktop_eventGetExecutablePath_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::BPFunctions_Desktop_eventGetExecutablePath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetExecutablePath)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetExecutablePath();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetExecutablePath ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetExtrasDir *******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics
{
	struct BPFunctions_Desktop_eventGetExtrasDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96""Extras\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96""Extras\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetExtrasDir constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetExtrasDir constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetExtrasDir Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetExtrasDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::PropPointers) < 2048);
// ********** End Function GetExtrasDir Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetExtrasDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::BPFunctions_Desktop_eventGetExtrasDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::BPFunctions_Desktop_eventGetExtrasDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetExtrasDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetExtrasDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetExtrasDir *********************************

// ********** Begin Class UBPFunctions_Desktop Function GetFileExtension ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics
{
	struct BPFunctions_Desktop_eventGetFileExtension_Parms
	{
		FString FileName;
		bool bIncludeDot;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\x87\xe4\xbb\xb6""Extension\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_bIncludeDot", "false" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\x87\xe4\xbb\xb6""Extension\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetFileExtension constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static void NewProp_bIncludeDot_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIncludeDot;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFileExtension constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFileExtension Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetFileExtension_Parms, FileName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::NewProp_bIncludeDot_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetFileExtension_Parms*)Obj)->bIncludeDot = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::NewProp_bIncludeDot = { "bIncludeDot", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetFileExtension_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::NewProp_bIncludeDot_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetFileExtension_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::NewProp_bIncludeDot,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::PropPointers) < 2048);
// ********** End Function GetFileExtension Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetFileExtension", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::BPFunctions_Desktop_eventGetFileExtension_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::BPFunctions_Desktop_eventGetFileExtension_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetFileExtension)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_UBOOL(Z_Param_bIncludeDot);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetFileExtension(Z_Param_FileName,Z_Param_bIncludeDot);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetFileExtension *****************************

// ********** Begin Class UBPFunctions_Desktop Function GetFilePath ********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics
{
	struct BPFunctions_Desktop_eventGetFilePath_Parms
	{
		FString FileName;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetFilePath constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFilePath constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFilePath Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetFilePath_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetFilePath_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::PropPointers) < 2048);
// ********** End Function GetFilePath Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetFilePath", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::BPFunctions_Desktop_eventGetFilePath_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::BPFunctions_Desktop_eventGetFilePath_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetFilePath)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetFilePath(Z_Param_FileName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetFilePath **********************************

// ********** Begin Class UBPFunctions_Desktop Function GetFilePathLeaf ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics
{
	struct BPFunctions_Desktop_eventGetFilePathLeaf_Parms
	{
		FString FileName;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84Leaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x96\x87\xe4\xbb\xb6\xe8\xb7\xaf\xe5\xbe\x84Leaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetFilePathLeaf constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetFilePathLeaf constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetFilePathLeaf Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetFilePathLeaf_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetFilePathLeaf_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::PropPointers) < 2048);
// ********** End Function GetFilePathLeaf Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetFilePathLeaf", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::BPFunctions_Desktop_eventGetFilePathLeaf_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::BPFunctions_Desktop_eventGetFilePathLeaf_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetFilePathLeaf)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetFilePathLeaf(Z_Param_FileName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetFilePathLeaf ******************************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUAdapterDriverDate ********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics
{
	struct BPFunctions_Desktop_eventGetGPUAdapterDriverDate_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU Adapter\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x97\xa5\xe6\x9c\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU Adapter\xe9\xa9\xb1\xe5\x8a\xa8\xe6\x97\xa5\xe6\x9c\x9f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUAdapterDriverDate constinit property declarations ***************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUAdapterDriverDate constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUAdapterDriverDate Property Definitions **************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUAdapterDriverDate_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::PropPointers) < 2048);
// ********** End Function GetGPUAdapterDriverDate Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUAdapterDriverDate", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::BPFunctions_Desktop_eventGetGPUAdapterDriverDate_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::BPFunctions_Desktop_eventGetGPUAdapterDriverDate_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUAdapterDriverDate)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPUAdapterDriverDate();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUAdapterDriverDate **********************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUAdapterInternalDriverVersion *********
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics
{
	struct BPFunctions_Desktop_eventGetGPUAdapterInternalDriverVersion_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU Adapter\xe5\x86\x85\xe9\x83\xa8\xe9\xa9\xb1\xe5\x8a\xa8\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU Adapter\xe5\x86\x85\xe9\x83\xa8\xe9\xa9\xb1\xe5\x8a\xa8\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUAdapterInternalDriverVersion constinit property declarations ****
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUAdapterInternalDriverVersion constinit property declarations ******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUAdapterInternalDriverVersion Property Definitions ***************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUAdapterInternalDriverVersion_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::PropPointers) < 2048);
// ********** End Function GetGPUAdapterInternalDriverVersion Property Definitions *****************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUAdapterInternalDriverVersion", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::BPFunctions_Desktop_eventGetGPUAdapterInternalDriverVersion_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::BPFunctions_Desktop_eventGetGPUAdapterInternalDriverVersion_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUAdapterInternalDriverVersion)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPUAdapterInternalDriverVersion();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUAdapterInternalDriverVersion ***********

// ********** Begin Class UBPFunctions_Desktop Function GetGPUAdapterName **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics
{
	struct BPFunctions_Desktop_eventGetGPUAdapterName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU Adapter\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU Adapter\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUAdapterName constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUAdapterName constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUAdapterName Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUAdapterName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::PropPointers) < 2048);
// ********** End Function GetGPUAdapterName Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUAdapterName", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::BPFunctions_Desktop_eventGetGPUAdapterName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::BPFunctions_Desktop_eventGetGPUAdapterName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUAdapterName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPUAdapterName();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUAdapterName ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUAdapterUserDriverVersion *************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics
{
	struct BPFunctions_Desktop_eventGetGPUAdapterUserDriverVersion_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU Adapter\xe7\x94\xa8\xe6\x88\xb7\xe9\xa9\xb1\xe5\x8a\xa8\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU Adapter\xe7\x94\xa8\xe6\x88\xb7\xe9\xa9\xb1\xe5\x8a\xa8\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUAdapterUserDriverVersion constinit property declarations ********
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUAdapterUserDriverVersion constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUAdapterUserDriverVersion Property Definitions *******************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUAdapterUserDriverVersion_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::PropPointers) < 2048);
// ********** End Function GetGPUAdapterUserDriverVersion Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUAdapterUserDriverVersion", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::BPFunctions_Desktop_eventGetGPUAdapterUserDriverVersion_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::BPFunctions_Desktop_eventGetGPUAdapterUserDriverVersion_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUAdapterUserDriverVersion)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPUAdapterUserDriverVersion();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUAdapterUserDriverVersion ***************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUBrand ********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics
{
	struct BPFunctions_Desktop_eventGetGPUBrand_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe5\x93\x81\xe7\x89\x8c\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUBrand constinit property declarations ***************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUBrand constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUBrand Property Definitions **************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUBrand_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::PropPointers) < 2048);
// ********** End Function GetGPUBrand Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUBrand", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::BPFunctions_Desktop_eventGetGPUBrand_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::BPFunctions_Desktop_eventGetGPUBrand_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUBrand)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPUBrand();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUBrand **********************************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUDeviceId *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics
{
	struct BPFunctions_Desktop_eventGetGPUDeviceId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe8\xae\xbe\xe5\xa4\x87ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe8\xae\xbe\xe5\xa4\x87ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUDeviceId constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUDeviceId constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUDeviceId Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUDeviceId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::PropPointers) < 2048);
// ********** End Function GetGPUDeviceId Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUDeviceId", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::BPFunctions_Desktop_eventGetGPUDeviceId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::BPFunctions_Desktop_eventGetGPUDeviceId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUDeviceId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPUDeviceId();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUDeviceId *******************************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUDeviceRevision ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics
{
	struct BPFunctions_Desktop_eventGetGPUDeviceRevision_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe8\xae\xbe\xe5\xa4\x87Revision\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe8\xae\xbe\xe5\xa4\x87Revision\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUDeviceRevision constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUDeviceRevision constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUDeviceRevision Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUDeviceRevision_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::PropPointers) < 2048);
// ********** End Function GetGPUDeviceRevision Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUDeviceRevision", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::BPFunctions_Desktop_eventGetGPUDeviceRevision_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::BPFunctions_Desktop_eventGetGPUDeviceRevision_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUDeviceRevision)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPUDeviceRevision();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUDeviceRevision *************************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUDriverUnifiedVersion *****************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics
{
	struct BPFunctions_Desktop_eventGetGPUDriverUnifiedVersion_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe9\xa9\xb1\xe5\x8a\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe9\xa9\xb1\xe5\x8a\xa8\xe7\xbb\x9f\xe4\xb8\x80\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUDriverUnifiedVersion constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUDriverUnifiedVersion constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUDriverUnifiedVersion Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUDriverUnifiedVersion_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::PropPointers) < 2048);
// ********** End Function GetGPUDriverUnifiedVersion Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUDriverUnifiedVersion", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::BPFunctions_Desktop_eventGetGPUDriverUnifiedVersion_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::BPFunctions_Desktop_eventGetGPUDriverUnifiedVersion_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUDriverUnifiedVersion)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPUDriverUnifiedVersion();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUDriverUnifiedVersion *******************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUHardwareInfo *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics
{
	struct BPFunctions_Desktop_eventGetGPUHardwareInfo_Parms
	{
		FDesktopGPUInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUHardwareInfo constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUHardwareInfo constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUHardwareInfo Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUHardwareInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopGPUInfo, METADATA_PARAMS(0, nullptr) }; // 2697188576
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::PropPointers) < 2048);
// ********** End Function GetGPUHardwareInfo Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUHardwareInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::BPFunctions_Desktop_eventGetGPUHardwareInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::BPFunctions_Desktop_eventGetGPUHardwareInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUHardwareInfo)
{
	P_GET_STRUCT_REF(FDesktopGPUInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetGPUHardwareInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUHardwareInfo ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUMemoryInfo ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics
{
	struct BPFunctions_Desktop_eventGetGPUMemoryInfo_Parms
	{
		FDesktopGPUMemoryInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe5\x86\x85\xe5\xad\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUMemoryInfo constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUMemoryInfo constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUMemoryInfo Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUMemoryInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopGPUMemoryInfo, METADATA_PARAMS(0, nullptr) }; // 128937207
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::PropPointers) < 2048);
// ********** End Function GetGPUMemoryInfo Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUMemoryInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::BPFunctions_Desktop_eventGetGPUMemoryInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::BPFunctions_Desktop_eventGetGPUMemoryInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUMemoryInfo)
{
	P_GET_STRUCT_REF(FDesktopGPUMemoryInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetGPUMemoryInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUMemoryInfo *****************************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUProviderName *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics
{
	struct BPFunctions_Desktop_eventGetGPUProviderName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe6\x8f\x90\xe4\xbe\x9b\xe5\x99\xa8\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe6\x8f\x90\xe4\xbe\x9b\xe5\x99\xa8\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUProviderName constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUProviderName constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUProviderName Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUProviderName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::PropPointers) < 2048);
// ********** End Function GetGPUProviderName Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUProviderName", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::BPFunctions_Desktop_eventGetGPUProviderName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::BPFunctions_Desktop_eventGetGPUProviderName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUProviderName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPUProviderName();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUProviderName ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetGPURHIName ******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics
{
	struct BPFunctions_Desktop_eventGetGPURHIName_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPURHI\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPURHI\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPURHIName constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPURHIName constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPURHIName Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPURHIName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::PropPointers) < 2048);
// ********** End Function GetGPURHIName Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPURHIName", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::BPFunctions_Desktop_eventGetGPURHIName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::BPFunctions_Desktop_eventGetGPURHIName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPURHIName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPURHIName();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPURHIName ********************************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUUsage ********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics
{
	struct BPFunctions_Desktop_eventGetGPUUsage_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe4\xbd\xbf\xe7\x94\xa8\xe7\x8e\x87\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUUsage constinit property declarations ***************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUUsage constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUUsage Property Definitions **************************************
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUUsage_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::PropPointers) < 2048);
// ********** End Function GetGPUUsage Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUUsage", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::BPFunctions_Desktop_eventGetGPUUsage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::BPFunctions_Desktop_eventGetGPUUsage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUUsage)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=UBPFunctions_Desktop::GetGPUUsage();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUUsage **********************************

// ********** Begin Class UBPFunctions_Desktop Function GetGPUVendorId *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics
{
	struct BPFunctions_Desktop_eventGetGPUVendorId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96GPU\xe5\x8e\x82\xe5\x95\x86ID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96GPU\xe5\x8e\x82\xe5\x95\x86ID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGPUVendorId constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGPUVendorId constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGPUVendorId Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetGPUVendorId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::PropPointers) < 2048);
// ********** End Function GetGPUVendorId Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetGPUVendorId", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::BPFunctions_Desktop_eventGetGPUVendorId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::BPFunctions_Desktop_eventGetGPUVendorId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetGPUVendorId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetGPUVendorId();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetGPUVendorId *******************************

// ********** Begin Class UBPFunctions_Desktop Function GetHardwareSnapshot ************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics
{
	struct BPFunctions_Desktop_eventGetHardwareSnapshot_Parms
	{
		FDesktopHardwareSnapshot OutSnapshot;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Diagnostics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xa1\xac\xe4\xbb\xb6\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xa1\xac\xe4\xbb\xb6\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetHardwareSnapshot constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutSnapshot;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHardwareSnapshot constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHardwareSnapshot Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::NewProp_OutSnapshot = { "OutSnapshot", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetHardwareSnapshot_Parms, OutSnapshot), Z_Construct_UScriptStruct_FDesktopHardwareSnapshot, METADATA_PARAMS(0, nullptr) }; // 369114559
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::NewProp_OutSnapshot,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::PropPointers) < 2048);
// ********** End Function GetHardwareSnapshot Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetHardwareSnapshot", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::BPFunctions_Desktop_eventGetHardwareSnapshot_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::BPFunctions_Desktop_eventGetHardwareSnapshot_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetHardwareSnapshot)
{
	P_GET_STRUCT_REF(FDesktopHardwareSnapshot,Z_Param_Out_OutSnapshot);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetHardwareSnapshot(Z_Param_Out_OutSnapshot);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetHardwareSnapshot **************************

// ********** Begin Class UBPFunctions_Desktop Function GetLocalAppDataDir *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics
{
	struct BPFunctions_Desktop_eventGetLocalAppDataDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x9c\xac\xe5\x9c\xb0\xe5\xba\x94\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x9c\xac\xe5\x9c\xb0\xe5\xba\x94\xe7\x94\xa8\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetLocalAppDataDir constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLocalAppDataDir constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLocalAppDataDir Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetLocalAppDataDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::PropPointers) < 2048);
// ********** End Function GetLocalAppDataDir Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetLocalAppDataDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::BPFunctions_Desktop_eventGetLocalAppDataDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::BPFunctions_Desktop_eventGetLocalAppDataDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetLocalAppDataDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetLocalAppDataDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetLocalAppDataDir ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetMainWindowHandleValue *******************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics
{
	struct BPFunctions_Desktop_eventGetMainWindowHandleValue_Parms
	{
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Main\xe7\xaa\x97\xe5\x8f\xa3\xe5\xa4\x84\xe7\x90\x86\xe5\x80\xbc\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Main\xe7\xaa\x97\xe5\x8f\xa3\xe5\xa4\x84\xe7\x90\x86\xe5\x80\xbc\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMainWindowHandleValue constinit property declarations **************
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMainWindowHandleValue constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMainWindowHandleValue Property Definitions *************************
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetMainWindowHandleValue_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::PropPointers) < 2048);
// ********** End Function GetMainWindowHandleValue Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetMainWindowHandleValue", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::BPFunctions_Desktop_eventGetMainWindowHandleValue_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::BPFunctions_Desktop_eventGetMainWindowHandleValue_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetMainWindowHandleValue)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=UBPFunctions_Desktop::GetMainWindowHandleValue();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetMainWindowHandleValue *********************

// ********** Begin Class UBPFunctions_Desktop Function GetMainWindowInfo **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics
{
	struct BPFunctions_Desktop_eventGetMainWindowInfo_Parms
	{
		FDesktopMainWindowInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Main\xe7\xaa\x97\xe5\x8f\xa3\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Main\xe7\xaa\x97\xe5\x8f\xa3\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMainWindowInfo constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMainWindowInfo constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMainWindowInfo Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetMainWindowInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopMainWindowInfo, METADATA_PARAMS(0, nullptr) }; // 3579282865
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::PropPointers) < 2048);
// ********** End Function GetMainWindowInfo Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetMainWindowInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::BPFunctions_Desktop_eventGetMainWindowInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::BPFunctions_Desktop_eventGetMainWindowInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetMainWindowInfo)
{
	P_GET_STRUCT_REF(FDesktopMainWindowInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetMainWindowInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetMainWindowInfo ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetMainWindowTitle *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics
{
	struct BPFunctions_Desktop_eventGetMainWindowTitle_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Main\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa0\x87\xe9\xa2\x98\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Main\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa0\x87\xe9\xa2\x98\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMainWindowTitle constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMainWindowTitle constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMainWindowTitle Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetMainWindowTitle_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::PropPointers) < 2048);
// ********** End Function GetMainWindowTitle Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetMainWindowTitle", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::BPFunctions_Desktop_eventGetMainWindowTitle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::BPFunctions_Desktop_eventGetMainWindowTitle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetMainWindowTitle)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetMainWindowTitle();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetMainWindowTitle ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetMemoryAvailablePhysicalBytes ************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics
{
	struct BPFunctions_Desktop_eventGetMemoryAvailablePhysicalBytes_Parms
	{
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Memory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe5\x8f\xaf\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMemoryAvailablePhysicalBytes constinit property declarations *******
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMemoryAvailablePhysicalBytes constinit property declarations *********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMemoryAvailablePhysicalBytes Property Definitions ******************
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetMemoryAvailablePhysicalBytes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::PropPointers) < 2048);
// ********** End Function GetMemoryAvailablePhysicalBytes Property Definitions ********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetMemoryAvailablePhysicalBytes", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::BPFunctions_Desktop_eventGetMemoryAvailablePhysicalBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::BPFunctions_Desktop_eventGetMemoryAvailablePhysicalBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetMemoryAvailablePhysicalBytes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=UBPFunctions_Desktop::GetMemoryAvailablePhysicalBytes();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetMemoryAvailablePhysicalBytes **************

// ********** Begin Class UBPFunctions_Desktop Function GetMemoryHardwareInfo **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics
{
	struct BPFunctions_Desktop_eventGetMemoryHardwareInfo_Parms
	{
		FDesktopMemoryInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Memory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe7\xa1\xac\xe4\xbb\xb6\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMemoryHardwareInfo constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMemoryHardwareInfo constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMemoryHardwareInfo Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetMemoryHardwareInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopMemoryInfo, METADATA_PARAMS(0, nullptr) }; // 1857295326
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::PropPointers) < 2048);
// ********** End Function GetMemoryHardwareInfo Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetMemoryHardwareInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::BPFunctions_Desktop_eventGetMemoryHardwareInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::BPFunctions_Desktop_eventGetMemoryHardwareInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetMemoryHardwareInfo)
{
	P_GET_STRUCT_REF(FDesktopMemoryInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetMemoryHardwareInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetMemoryHardwareInfo ************************

// ********** Begin Class UBPFunctions_Desktop Function GetMemoryProcessUsedPhysicalBytes **********
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics
{
	struct BPFunctions_Desktop_eventGetMemoryProcessUsedPhysicalBytes_Parms
	{
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Memory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe8\xbf\x9b\xe7\xa8\x8b\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMemoryProcessUsedPhysicalBytes constinit property declarations *****
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMemoryProcessUsedPhysicalBytes constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMemoryProcessUsedPhysicalBytes Property Definitions ****************
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetMemoryProcessUsedPhysicalBytes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::PropPointers) < 2048);
// ********** End Function GetMemoryProcessUsedPhysicalBytes Property Definitions ******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetMemoryProcessUsedPhysicalBytes", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::BPFunctions_Desktop_eventGetMemoryProcessUsedPhysicalBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::BPFunctions_Desktop_eventGetMemoryProcessUsedPhysicalBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetMemoryProcessUsedPhysicalBytes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=UBPFunctions_Desktop::GetMemoryProcessUsedPhysicalBytes();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetMemoryProcessUsedPhysicalBytes ************

// ********** Begin Class UBPFunctions_Desktop Function GetMemorySystemUsedPhysicalBytes ***********
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics
{
	struct BPFunctions_Desktop_eventGetMemorySystemUsedPhysicalBytes_Parms
	{
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Memory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe7\xb3\xbb\xe7\xbb\x9f\xe5\xb7\xb2\xe7\x94\xa8\xe7\x89\xa9\xe7\x90\x86\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMemorySystemUsedPhysicalBytes constinit property declarations ******
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMemorySystemUsedPhysicalBytes constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMemorySystemUsedPhysicalBytes Property Definitions *****************
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetMemorySystemUsedPhysicalBytes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::PropPointers) < 2048);
// ********** End Function GetMemorySystemUsedPhysicalBytes Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetMemorySystemUsedPhysicalBytes", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::BPFunctions_Desktop_eventGetMemorySystemUsedPhysicalBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::BPFunctions_Desktop_eventGetMemorySystemUsedPhysicalBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetMemorySystemUsedPhysicalBytes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=UBPFunctions_Desktop::GetMemorySystemUsedPhysicalBytes();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetMemorySystemUsedPhysicalBytes *************

// ********** Begin Class UBPFunctions_Desktop Function GetMemoryTotalPhysicalBytes ****************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics
{
	struct BPFunctions_Desktop_eventGetMemoryTotalPhysicalBytes_Parms
	{
		int64 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Memory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe7\x89\xa9\xe7\x90\x86\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe5\x86\x85\xe5\xad\x98\xe6\x80\xbb\xe7\x89\xa9\xe7\x90\x86\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMemoryTotalPhysicalBytes constinit property declarations ***********
	static const UECodeGen_Private::FInt64PropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMemoryTotalPhysicalBytes constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMemoryTotalPhysicalBytes Property Definitions **********************
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetMemoryTotalPhysicalBytes_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::PropPointers) < 2048);
// ********** End Function GetMemoryTotalPhysicalBytes Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetMemoryTotalPhysicalBytes", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::BPFunctions_Desktop_eventGetMemoryTotalPhysicalBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::BPFunctions_Desktop_eventGetMemoryTotalPhysicalBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetMemoryTotalPhysicalBytes)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int64*)Z_Param__Result=UBPFunctions_Desktop::GetMemoryTotalPhysicalBytes();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetMemoryTotalPhysicalBytes ******************

// ********** Begin Class UBPFunctions_Desktop Function GetMonitorCount ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics
{
	struct BPFunctions_Desktop_eventGetMonitorCount_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Monitor\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Monitor\xe6\x95\xb0\xe9\x87\x8f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetMonitorCount constinit property declarations ***********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetMonitorCount constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetMonitorCount Property Definitions **********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetMonitorCount_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::PropPointers) < 2048);
// ********** End Function GetMonitorCount Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetMonitorCount", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::BPFunctions_Desktop_eventGetMonitorCount_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::BPFunctions_Desktop_eventGetMonitorCount_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetMonitorCount)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Desktop::GetMonitorCount();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetMonitorCount ******************************

// ********** Begin Class UBPFunctions_Desktop Function GetNetworkAdapterInfo **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics
{
	struct BPFunctions_Desktop_eventGetNetworkAdapterInfo_Parms
	{
		TArray<FDesktopNetworkAdapterInfo> OutInfos;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Network" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xbd\x91\xe7\xbb\x9c""Adapter\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xbd\x91\xe7\xbb\x9c""Adapter\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetNetworkAdapterInfo constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfos_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutInfos;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNetworkAdapterInfo constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNetworkAdapterInfo Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::NewProp_OutInfos_Inner = { "OutInfos", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FDesktopNetworkAdapterInfo, METADATA_PARAMS(0, nullptr) }; // 3376853757
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::NewProp_OutInfos = { "OutInfos", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetNetworkAdapterInfo_Parms, OutInfos), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3376853757
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::NewProp_OutInfos_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::NewProp_OutInfos,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::PropPointers) < 2048);
// ********** End Function GetNetworkAdapterInfo Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetNetworkAdapterInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::BPFunctions_Desktop_eventGetNetworkAdapterInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::BPFunctions_Desktop_eventGetNetworkAdapterInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetNetworkAdapterInfo)
{
	P_GET_TARRAY_REF(FDesktopNetworkAdapterInfo,Z_Param_Out_OutInfos);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetNetworkAdapterInfo(Z_Param_Out_OutInfos);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetNetworkAdapterInfo ************************

// ********** Begin Class UBPFunctions_Desktop Function GetNetworkInfo *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics
{
	struct BPFunctions_Desktop_eventGetNetworkInfo_Parms
	{
		FDesktopNetworkInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Network" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xbd\x91\xe7\xbb\x9c\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetNetworkInfo constinit property declarations ************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetNetworkInfo constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetNetworkInfo Property Definitions ***********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetNetworkInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopNetworkInfo, METADATA_PARAMS(0, nullptr) }; // 251845637
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::PropPointers) < 2048);
// ********** End Function GetNetworkInfo Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetNetworkInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::BPFunctions_Desktop_eventGetNetworkInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::BPFunctions_Desktop_eventGetNetworkInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetNetworkInfo)
{
	P_GET_STRUCT_REF(FDesktopNetworkInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetNetworkInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetNetworkInfo *******************************

// ********** Begin Class UBPFunctions_Desktop Function GetOperatingSystemId ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics
{
	struct BPFunctions_Desktop_eventGetOperatingSystemId_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x93\x8d\xe4\xbd\x9c\xe7\xb3\xbb\xe7\xbb\x9fID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x93\x8d\xe4\xbd\x9c\xe7\xb3\xbb\xe7\xbb\x9fID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetOperatingSystemId constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOperatingSystemId constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOperatingSystemId Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetOperatingSystemId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::PropPointers) < 2048);
// ********** End Function GetOperatingSystemId Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetOperatingSystemId", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::BPFunctions_Desktop_eventGetOperatingSystemId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::BPFunctions_Desktop_eventGetOperatingSystemId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetOperatingSystemId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetOperatingSystemId();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetOperatingSystemId *************************

// ********** Begin Class UBPFunctions_Desktop Function GetOSVersion *******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics
{
	struct BPFunctions_Desktop_eventGetOSVersion_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96OS\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96OS\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetOSVersion constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOSVersion constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOSVersion Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetOSVersion_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::PropPointers) < 2048);
// ********** End Function GetOSVersion Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetOSVersion", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::BPFunctions_Desktop_eventGetOSVersion_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::BPFunctions_Desktop_eventGetOSVersion_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetOSVersion)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetOSVersion();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetOSVersion *********************************

// ********** Begin Class UBPFunctions_Desktop Function GetOSVersions ******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics
{
	struct BPFunctions_Desktop_eventGetOSVersions_Parms
	{
		FString OutOSVersionLabel;
		FString OutOSSubVersionLabel;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96OS Versions\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96OS Versions\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetOSVersions constinit property declarations *************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutOSVersionLabel;
	static const UECodeGen_Private::FStrPropertyParams NewProp_OutOSSubVersionLabel;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetOSVersions constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetOSVersions Property Definitions ************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::NewProp_OutOSVersionLabel = { "OutOSVersionLabel", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetOSVersions_Parms, OutOSVersionLabel), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::NewProp_OutOSSubVersionLabel = { "OutOSSubVersionLabel", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetOSVersions_Parms, OutOSSubVersionLabel), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::NewProp_OutOSVersionLabel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::NewProp_OutOSSubVersionLabel,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::PropPointers) < 2048);
// ********** End Function GetOSVersions Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetOSVersions", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::BPFunctions_Desktop_eventGetOSVersions_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::BPFunctions_Desktop_eventGetOSVersions_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetOSVersions)
{
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutOSVersionLabel);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_OutOSSubVersionLabel);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetOSVersions(Z_Param_Out_OutOSVersionLabel,Z_Param_Out_OutOSSubVersionLabel);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetOSVersions ********************************

// ********** Begin Class UBPFunctions_Desktop Function GetPluginBaseDir ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics
{
	struct BPFunctions_Desktop_eventGetPluginBaseDir_Parms
	{
		FString InPluginName;
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Plugin\xe5\x9f\xba\xe7\xa1\x80\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Plugin\xe5\x9f\xba\xe7\xa1\x80\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginBaseDir constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginBaseDir constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginBaseDir Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::NewProp_InPluginName = { "InPluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginBaseDir_Parms, InPluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPluginName_MetaData), NewProp_InPluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginBaseDir_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetPluginBaseDir_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetPluginBaseDir_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::NewProp_InPluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::PropPointers) < 2048);
// ********** End Function GetPluginBaseDir Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetPluginBaseDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::BPFunctions_Desktop_eventGetPluginBaseDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::BPFunctions_Desktop_eventGetPluginBaseDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetPluginBaseDir)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPluginName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::GetPluginBaseDir(Z_Param_InPluginName,Z_Param_Out_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetPluginBaseDir *****************************

// ********** Begin Class UBPFunctions_Desktop Function GetPluginBinariesDir ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics
{
	struct BPFunctions_Desktop_eventGetPluginBinariesDir_Parms
	{
		FString InPluginName;
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Plugin Binaries\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Plugin Binaries\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginBinariesDir constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginBinariesDir constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginBinariesDir Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::NewProp_InPluginName = { "InPluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginBinariesDir_Parms, InPluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPluginName_MetaData), NewProp_InPluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginBinariesDir_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetPluginBinariesDir_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetPluginBinariesDir_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::NewProp_InPluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::PropPointers) < 2048);
// ********** End Function GetPluginBinariesDir Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetPluginBinariesDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::BPFunctions_Desktop_eventGetPluginBinariesDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::BPFunctions_Desktop_eventGetPluginBinariesDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetPluginBinariesDir)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPluginName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::GetPluginBinariesDir(Z_Param_InPluginName,Z_Param_Out_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetPluginBinariesDir *************************

// ********** Begin Class UBPFunctions_Desktop Function GetPluginContentDir ************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics
{
	struct BPFunctions_Desktop_eventGetPluginContentDir_Parms
	{
		FString InPluginName;
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Plugin\xe5\x86\x85\xe5\xae\xb9\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Plugin\xe5\x86\x85\xe5\xae\xb9\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginContentDir constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginContentDir constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginContentDir Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::NewProp_InPluginName = { "InPluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginContentDir_Parms, InPluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPluginName_MetaData), NewProp_InPluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginContentDir_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetPluginContentDir_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetPluginContentDir_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::NewProp_InPluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::PropPointers) < 2048);
// ********** End Function GetPluginContentDir Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetPluginContentDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::BPFunctions_Desktop_eventGetPluginContentDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::BPFunctions_Desktop_eventGetPluginContentDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetPluginContentDir)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPluginName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::GetPluginContentDir(Z_Param_InPluginName,Z_Param_Out_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetPluginContentDir **************************

// ********** Begin Class UBPFunctions_Desktop Function GetPluginExtraDir **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics
{
	struct BPFunctions_Desktop_eventGetPluginExtraDir_Parms
	{
		FString InPluginName;
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Plugin Extra\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Plugin Extra\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginExtraDir constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginExtraDir constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginExtraDir Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::NewProp_InPluginName = { "InPluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginExtraDir_Parms, InPluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPluginName_MetaData), NewProp_InPluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginExtraDir_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetPluginExtraDir_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetPluginExtraDir_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::NewProp_InPluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::PropPointers) < 2048);
// ********** End Function GetPluginExtraDir Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetPluginExtraDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::BPFunctions_Desktop_eventGetPluginExtraDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::BPFunctions_Desktop_eventGetPluginExtraDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetPluginExtraDir)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPluginName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::GetPluginExtraDir(Z_Param_InPluginName,Z_Param_Out_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetPluginExtraDir ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetPluginIntermediateDir *******************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics
{
	struct BPFunctions_Desktop_eventGetPluginIntermediateDir_Parms
	{
		FString InPluginName;
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Plugin Intermediate\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Plugin Intermediate\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginIntermediateDir constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginIntermediateDir constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginIntermediateDir Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::NewProp_InPluginName = { "InPluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginIntermediateDir_Parms, InPluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPluginName_MetaData), NewProp_InPluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginIntermediateDir_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetPluginIntermediateDir_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetPluginIntermediateDir_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::NewProp_InPluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::PropPointers) < 2048);
// ********** End Function GetPluginIntermediateDir Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetPluginIntermediateDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::BPFunctions_Desktop_eventGetPluginIntermediateDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::BPFunctions_Desktop_eventGetPluginIntermediateDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetPluginIntermediateDir)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPluginName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::GetPluginIntermediateDir(Z_Param_InPluginName,Z_Param_Out_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetPluginIntermediateDir *********************

// ********** Begin Class UBPFunctions_Desktop Function GetPluginResourcesDir **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics
{
	struct BPFunctions_Desktop_eventGetPluginResourcesDir_Parms
	{
		FString InPluginName;
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Plugin Resources\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Plugin Resources\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginResourcesDir constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginResourcesDir constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginResourcesDir Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::NewProp_InPluginName = { "InPluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginResourcesDir_Parms, InPluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPluginName_MetaData), NewProp_InPluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginResourcesDir_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetPluginResourcesDir_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetPluginResourcesDir_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::NewProp_InPluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::PropPointers) < 2048);
// ********** End Function GetPluginResourcesDir Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetPluginResourcesDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::BPFunctions_Desktop_eventGetPluginResourcesDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::BPFunctions_Desktop_eventGetPluginResourcesDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetPluginResourcesDir)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPluginName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::GetPluginResourcesDir(Z_Param_InPluginName,Z_Param_Out_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetPluginResourcesDir ************************

// ********** Begin Class UBPFunctions_Desktop Function GetPluginSourceDir *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics
{
	struct BPFunctions_Desktop_eventGetPluginSourceDir_Parms
	{
		FString InPluginName;
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Plugin\xe6\x9d\xa5\xe6\xba\x90\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Plugin\xe6\x9d\xa5\xe6\xba\x90\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPluginName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPluginSourceDir constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InPluginName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPluginSourceDir constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPluginSourceDir Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::NewProp_InPluginName = { "InPluginName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginSourceDir_Parms, InPluginName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPluginName_MetaData), NewProp_InPluginName_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPluginSourceDir_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetPluginSourceDir_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetPluginSourceDir_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::NewProp_InPluginName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::PropPointers) < 2048);
// ********** End Function GetPluginSourceDir Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetPluginSourceDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::BPFunctions_Desktop_eventGetPluginSourceDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::BPFunctions_Desktop_eventGetPluginSourceDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetPluginSourceDir)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InPluginName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::GetPluginSourceDir(Z_Param_InPluginName,Z_Param_Out_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetPluginSourceDir ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetPowerInfo *******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics
{
	struct BPFunctions_Desktop_eventGetPowerInfo_Parms
	{
		FDesktopPowerInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Power" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\x94\xb5\xe6\xba\x90\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\x94\xb5\xe6\xba\x90\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetPowerInfo constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPowerInfo constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPowerInfo Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPowerInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopPowerInfo, METADATA_PARAMS(0, nullptr) }; // 2907703197
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::PropPointers) < 2048);
// ********** End Function GetPowerInfo Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetPowerInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::BPFunctions_Desktop_eventGetPowerInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::BPFunctions_Desktop_eventGetPowerInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetPowerInfo)
{
	P_GET_STRUCT_REF(FDesktopPowerInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetPowerInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetPowerInfo *********************************

// ********** Begin Class UBPFunctions_Desktop Function GetPrimaryMonitorInfo **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics
{
	struct BPFunctions_Desktop_eventGetPrimaryMonitorInfo_Parms
	{
		FDesktopMonitorInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Display" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe4\xb8\xbbMonitor\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe4\xb8\xbbMonitor\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetPrimaryMonitorInfo constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPrimaryMonitorInfo constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPrimaryMonitorInfo Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetPrimaryMonitorInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopMonitorInfo, METADATA_PARAMS(0, nullptr) }; // 1496936958
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::PropPointers) < 2048);
// ********** End Function GetPrimaryMonitorInfo Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetPrimaryMonitorInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::BPFunctions_Desktop_eventGetPrimaryMonitorInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::BPFunctions_Desktop_eventGetPrimaryMonitorInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetPrimaryMonitorInfo)
{
	P_GET_STRUCT_REF(FDesktopMonitorInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetPrimaryMonitorInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetPrimaryMonitorInfo ************************

// ********** Begin Class UBPFunctions_Desktop Function GetProcessId *******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics
{
	struct BPFunctions_Desktop_eventGetProcessId_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe8\xbf\x9b\xe7\xa8\x8bID\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe8\xbf\x9b\xe7\xa8\x8bID\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetProcessId constinit property declarations **************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetProcessId constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetProcessId Property Definitions *************************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetProcessId_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::PropPointers) < 2048);
// ********** End Function GetProcessId Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetProcessId", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::BPFunctions_Desktop_eventGetProcessId_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::BPFunctions_Desktop_eventGetProcessId_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetProcessId)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=UBPFunctions_Desktop::GetProcessId();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetProcessId *********************************

// ********** Begin Class UBPFunctions_Desktop Function GetProgramDataDir **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics
{
	struct BPFunctions_Desktop_eventGetProgramDataDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96Program\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96Program\xe6\x95\xb0\xe6\x8d\xae\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetProgramDataDir constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetProgramDataDir constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetProgramDataDir Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetProgramDataDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::PropPointers) < 2048);
// ********** End Function GetProgramDataDir Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetProgramDataDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::BPFunctions_Desktop_eventGetProgramDataDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::BPFunctions_Desktop_eventGetProgramDataDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetProgramDataDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetProgramDataDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetProgramDataDir ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetProjectDiskInfo *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics
{
	struct BPFunctions_Desktop_eventGetProjectDiskInfo_Parms
	{
		FDesktopDiskInfo OutInfo;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Disk" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe9\xa1\xb9\xe7\x9b\xae\xe7\xa3\x81\xe7\x9b\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe9\xa1\xb9\xe7\x9b\xae\xe7\xa3\x81\xe7\x9b\x98\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetProjectDiskInfo constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetProjectDiskInfo constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetProjectDiskInfo Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetProjectDiskInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopDiskInfo, METADATA_PARAMS(0, nullptr) }; // 1522185633
void Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventGetProjectDiskInfo_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventGetProjectDiskInfo_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::NewProp_OutInfo,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::PropPointers) < 2048);
// ********** End Function GetProjectDiskInfo Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetProjectDiskInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::BPFunctions_Desktop_eventGetProjectDiskInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::BPFunctions_Desktop_eventGetProjectDiskInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetProjectDiskInfo)
{
	P_GET_STRUCT_REF(FDesktopDiskInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::GetProjectDiskInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetProjectDiskInfo ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetSavedGamesDir ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics
{
	struct BPFunctions_Desktop_eventGetSavedGamesDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe4\xbf\x9d\xe5\xad\x98Games\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe4\xbf\x9d\xe5\xad\x98Games\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSavedGamesDir constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSavedGamesDir constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSavedGamesDir Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetSavedGamesDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::PropPointers) < 2048);
// ********** End Function GetSavedGamesDir Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetSavedGamesDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::BPFunctions_Desktop_eventGetSavedGamesDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::BPFunctions_Desktop_eventGetSavedGamesDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetSavedGamesDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetSavedGamesDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetSavedGamesDir *****************************

// ********** Begin Class UBPFunctions_Desktop Function GetSaveGameDir *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics
{
	struct BPFunctions_Desktop_eventGetSaveGameDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe4\xbf\x9d\xe5\xad\x98\xe6\xb8\xb8\xe6\x88\x8f\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe4\xbf\x9d\xe5\xad\x98\xe6\xb8\xb8\xe6\x88\x8f\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSaveGameDir constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSaveGameDir constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSaveGameDir Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetSaveGameDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::PropPointers) < 2048);
// ********** End Function GetSaveGameDir Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetSaveGameDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::BPFunctions_Desktop_eventGetSaveGameDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::BPFunctions_Desktop_eventGetSaveGameDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetSaveGameDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetSaveGameDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetSaveGameDir *******************************

// ********** Begin Class UBPFunctions_Desktop Function GetSystemFontBytes *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics
{
	struct BPFunctions_Desktop_eventGetSystemFontBytes_Parms
	{
		TArray<uint8> OutBytes;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Shell" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xb3\xbb\xe7\xbb\x9f""Font\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xb3\xbb\xe7\xbb\x9f""Font\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSystemFontBytes constinit property declarations ********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutBytes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutBytes;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSystemFontBytes constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSystemFontBytes Property Definitions *******************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::NewProp_OutBytes_Inner = { "OutBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::NewProp_OutBytes = { "OutBytes", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetSystemFontBytes_Parms, OutBytes), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::NewProp_OutBytes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::NewProp_OutBytes,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::PropPointers) < 2048);
// ********** End Function GetSystemFontBytes Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetSystemFontBytes", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::BPFunctions_Desktop_eventGetSystemFontBytes_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::BPFunctions_Desktop_eventGetSystemFontBytes_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetSystemFontBytes)
{
	P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBytes);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetSystemFontBytes(Z_Param_Out_OutBytes);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetSystemFontBytes ***************************

// ********** Begin Class UBPFunctions_Desktop Function GetSystemPathInfo **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics
{
	struct BPFunctions_Desktop_eventGetSystemPathInfo_Parms
	{
		FDesktopSystemPathInfo OutInfo;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xb7\xaf\xe5\xbe\x84\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xb7\xaf\xe5\xbe\x84\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSystemPathInfo constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutInfo;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSystemPathInfo constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSystemPathInfo Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::NewProp_OutInfo = { "OutInfo", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetSystemPathInfo_Parms, OutInfo), Z_Construct_UScriptStruct_FDesktopSystemPathInfo, METADATA_PARAMS(0, nullptr) }; // 2957347215
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::NewProp_OutInfo,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::PropPointers) < 2048);
// ********** End Function GetSystemPathInfo Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetSystemPathInfo", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::BPFunctions_Desktop_eventGetSystemPathInfo_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::BPFunctions_Desktop_eventGetSystemPathInfo_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetSystemPathInfo)
{
	P_GET_STRUCT_REF(FDesktopSystemPathInfo,Z_Param_Out_OutInfo);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::GetSystemPathInfo(Z_Param_Out_OutInfo);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetSystemPathInfo ****************************

// ********** Begin Class UBPFunctions_Desktop Function GetSystemUptimeSecond **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics
{
	struct BPFunctions_Desktop_eventGetSystemUptimeSecond_Parms
	{
		double ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xb3\xbb\xe7\xbb\x9fUptime Second\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xb3\xbb\xe7\xbb\x9fUptime Second\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSystemUptimeSecond constinit property declarations *****************
	static const UECodeGen_Private::FDoublePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSystemUptimeSecond constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSystemUptimeSecond Property Definitions ****************************
const UECodeGen_Private::FDoublePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Double, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetSystemUptimeSecond_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::PropPointers) < 2048);
// ********** End Function GetSystemUptimeSecond Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetSystemUptimeSecond", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::BPFunctions_Desktop_eventGetSystemUptimeSecond_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::BPFunctions_Desktop_eventGetSystemUptimeSecond_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetSystemUptimeSecond)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(double*)Z_Param__Result=UBPFunctions_Desktop::GetSystemUptimeSecond();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetSystemUptimeSecond ************************

// ********** Begin Class UBPFunctions_Desktop Function GetTempDir *********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics
{
	struct BPFunctions_Desktop_eventGetTempDir_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Path" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe4\xb8\xb4\xe6\x97\xb6\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe4\xb8\xb4\xe6\x97\xb6\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTempDir constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTempDir constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTempDir Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetTempDir_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::PropPointers) < 2048);
// ********** End Function GetTempDir Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetTempDir", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::BPFunctions_Desktop_eventGetTempDir_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::BPFunctions_Desktop_eventGetTempDir_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetTempDir)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetTempDir();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetTempDir ***********************************

// ********** Begin Class UBPFunctions_Desktop Function GetTimeStamp *******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics
{
	struct BPFunctions_Desktop_eventGetTimeStamp_Parms
	{
		FString FileName;
		FDateTime ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe6\x97\xb6\xe9\x97\xb4Stamp\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe6\x97\xb6\xe9\x97\xb4Stamp\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetTimeStamp constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetTimeStamp constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetTimeStamp Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetTimeStamp_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetTimeStamp_Parms, ReturnValue), Z_Construct_UScriptStruct_FDateTime, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::PropPointers) < 2048);
// ********** End Function GetTimeStamp Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetTimeStamp", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::BPFunctions_Desktop_eventGetTimeStamp_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14822403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::BPFunctions_Desktop_eventGetTimeStamp_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetTimeStamp)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FDateTime*)Z_Param__Result=UBPFunctions_Desktop::GetTimeStamp(Z_Param_FileName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetTimeStamp *********************************

// ********** Begin Class UBPFunctions_Desktop Function GetWindowDebugReport ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics
{
	struct BPFunctions_Desktop_eventGetWindowDebugReport_Parms
	{
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Diagnostics" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xaa\x97\xe5\x8f\xa3\xe8\xb0\x83\xe8\xaf\x95Report\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xaa\x97\xe5\x8f\xa3\xe8\xb0\x83\xe8\xaf\x95Report\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetWindowDebugReport constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWindowDebugReport constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWindowDebugReport Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetWindowDebugReport_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::PropPointers) < 2048);
// ********** End Function GetWindowDebugReport Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetWindowDebugReport", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::BPFunctions_Desktop_eventGetWindowDebugReport_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::BPFunctions_Desktop_eventGetWindowDebugReport_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetWindowDebugReport)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::GetWindowDebugReport();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetWindowDebugReport *************************

// ********** Begin Class UBPFunctions_Desktop Function GetWindowMode ******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics
{
	struct BPFunctions_Desktop_eventGetWindowMode_Parms
	{
		EDesktopDisplayMode ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\x8e\xb7\xe5\x8f\x96\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\x8e\xb7\xe5\x8f\x96\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetWindowMode constinit property declarations *************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWindowMode constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWindowMode Property Definitions ************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventGetWindowMode_Parms, ReturnValue), Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode, METADATA_PARAMS(0, nullptr) }; // 59183459
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::NewProp_ReturnValue_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::PropPointers) < 2048);
// ********** End Function GetWindowMode Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "GetWindowMode", 	Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::BPFunctions_Desktop_eventGetWindowMode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::BPFunctions_Desktop_eventGetWindowMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execGetWindowMode)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(EDesktopDisplayMode*)Z_Param__Result=UBPFunctions_Desktop::GetWindowMode();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function GetWindowMode ********************************

// ********** Begin Class UBPFunctions_Desktop Function IsDrive ************************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics
{
	struct BPFunctions_Desktop_eventIsDrive_Parms
	{
		FString FileName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad""Drive\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad""Drive\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsDrive constinit property declarations *******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsDrive constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsDrive Property Definitions ******************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventIsDrive_Parms, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsDrive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsDrive_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::PropPointers) < 2048);
// ********** End Function IsDrive Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsDrive", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::BPFunctions_Desktop_eventIsDrive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::BPFunctions_Desktop_eventIsDrive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsDrive)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsDrive(Z_Param_FileName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsDrive **************************************

// ********** Begin Class UBPFunctions_Desktop Function IsFileReadOnly *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics
{
	struct BPFunctions_Desktop_eventIsFileReadOnly_Parms
	{
		FString FileName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe6\x96\x87\xe4\xbb\xb6\xe8\xaf\xbb\xe5\x8f\x96Only\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe6\x96\x87\xe4\xbb\xb6\xe8\xaf\xbb\xe5\x8f\x96Only\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsFileReadOnly constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsFileReadOnly constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsFileReadOnly Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventIsFileReadOnly_Parms, FileName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsFileReadOnly_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsFileReadOnly_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::PropPointers) < 2048);
// ********** End Function IsFileReadOnly Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsFileReadOnly", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::BPFunctions_Desktop_eventIsFileReadOnly_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::BPFunctions_Desktop_eventIsFileReadOnly_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsFileReadOnly)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsFileReadOnly(Z_Param_FileName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsFileReadOnly *******************************

// ********** Begin Class UBPFunctions_Desktop Function IsLaptopDevice *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics
{
	struct BPFunctions_Desktop_eventIsLaptopDevice_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Power" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadLaptop\xe8\xae\xbe\xe5\xa4\x87\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadLaptop\xe8\xae\xbe\xe5\xa4\x87\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsLaptopDevice constinit property declarations ************************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsLaptopDevice constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsLaptopDevice Property Definitions ***********************************
void Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsLaptopDevice_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsLaptopDevice_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::PropPointers) < 2048);
// ********** End Function IsLaptopDevice Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsLaptopDevice", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::BPFunctions_Desktop_eventIsLaptopDevice_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::BPFunctions_Desktop_eventIsLaptopDevice_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsLaptopDevice)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsLaptopDevice();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsLaptopDevice *******************************

// ********** Begin Class UBPFunctions_Desktop Function IsMainWindowActive *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics
{
	struct BPFunctions_Desktop_eventIsMainWindowActive_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadMain\xe7\xaa\x97\xe5\x8f\xa3\xe6\xbf\x80\xe6\xb4\xbb\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadMain\xe7\xaa\x97\xe5\x8f\xa3\xe6\xbf\x80\xe6\xb4\xbb\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsMainWindowActive constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsMainWindowActive constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsMainWindowActive Property Definitions *******************************
void Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsMainWindowActive_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsMainWindowActive_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::PropPointers) < 2048);
// ********** End Function IsMainWindowActive Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsMainWindowActive", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::BPFunctions_Desktop_eventIsMainWindowActive_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::BPFunctions_Desktop_eventIsMainWindowActive_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsMainWindowActive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsMainWindowActive();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsMainWindowActive ***************************

// ********** Begin Class UBPFunctions_Desktop Function IsMainWindowMaximized **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics
{
	struct BPFunctions_Desktop_eventIsMainWindowMaximized_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadMain\xe7\xaa\x97\xe5\x8f\xa3Maximized\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadMain\xe7\xaa\x97\xe5\x8f\xa3Maximized\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsMainWindowMaximized constinit property declarations *****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsMainWindowMaximized constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsMainWindowMaximized Property Definitions ****************************
void Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsMainWindowMaximized_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsMainWindowMaximized_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::PropPointers) < 2048);
// ********** End Function IsMainWindowMaximized Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsMainWindowMaximized", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::BPFunctions_Desktop_eventIsMainWindowMaximized_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::BPFunctions_Desktop_eventIsMainWindowMaximized_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsMainWindowMaximized)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsMainWindowMaximized();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsMainWindowMaximized ************************

// ********** Begin Class UBPFunctions_Desktop Function IsMainWindowMinimized **********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics
{
	struct BPFunctions_Desktop_eventIsMainWindowMinimized_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadMain\xe7\xaa\x97\xe5\x8f\xa3Minimized\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadMain\xe7\xaa\x97\xe5\x8f\xa3Minimized\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsMainWindowMinimized constinit property declarations *****************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsMainWindowMinimized constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsMainWindowMinimized Property Definitions ****************************
void Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsMainWindowMinimized_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsMainWindowMinimized_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::PropPointers) < 2048);
// ********** End Function IsMainWindowMinimized Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsMainWindowMinimized", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::BPFunctions_Desktop_eventIsMainWindowMinimized_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::BPFunctions_Desktop_eventIsMainWindowMinimized_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsMainWindowMinimized)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsMainWindowMinimized();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsMainWindowMinimized ************************

// ********** Begin Class UBPFunctions_Desktop Function IsMainWindowValid **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics
{
	struct BPFunctions_Desktop_eventIsMainWindowValid_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadMain\xe7\xaa\x97\xe5\x8f\xa3\xe6\x9c\x89\xe6\x95\x88\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadMain\xe7\xaa\x97\xe5\x8f\xa3\xe6\x9c\x89\xe6\x95\x88\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsMainWindowValid constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsMainWindowValid constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsMainWindowValid Property Definitions ********************************
void Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsMainWindowValid_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsMainWindowValid_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::PropPointers) < 2048);
// ********** End Function IsMainWindowValid Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsMainWindowValid", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::BPFunctions_Desktop_eventIsMainWindowValid_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::BPFunctions_Desktop_eventIsMainWindowValid_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsMainWindowValid)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsMainWindowValid();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsMainWindowValid ****************************

// ********** Begin Class UBPFunctions_Desktop Function IsRelative *********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics
{
	struct BPFunctions_Desktop_eventIsRelative_Parms
	{
		FString FileName;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadRelative\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadRelative\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsRelative constinit property declarations ****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsRelative constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsRelative Property Definitions ***************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventIsRelative_Parms, FileName), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsRelative_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsRelative_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::PropPointers) < 2048);
// ********** End Function IsRelative Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsRelative", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::BPFunctions_Desktop_eventIsRelative_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::BPFunctions_Desktop_eventIsRelative_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsRelative)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsRelative(Z_Param_FileName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsRelative ***********************************

// ********** Begin Class UBPFunctions_Desktop Function IsRunningAsAdministrator *******************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics
{
	struct BPFunctions_Desktop_eventIsRunningAsAdministrator_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|System" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe7\xae\xa1\xe7\x90\x86\xe5\x91\x98\xe8\xbf\x90\xe8\xa1\x8c\xe7\x8a\xb6\xe6\x80\x81\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe7\xae\xa1\xe7\x90\x86\xe5\x91\x98\xe8\xbf\x90\xe8\xa1\x8c\xe7\x8a\xb6\xe6\x80\x81\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsRunningAsAdministrator constinit property declarations **************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsRunningAsAdministrator constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsRunningAsAdministrator Property Definitions *************************
void Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsRunningAsAdministrator_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsRunningAsAdministrator_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::PropPointers) < 2048);
// ********** End Function IsRunningAsAdministrator Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsRunningAsAdministrator", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::BPFunctions_Desktop_eventIsRunningAsAdministrator_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::BPFunctions_Desktop_eventIsRunningAsAdministrator_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsRunningAsAdministrator)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsRunningAsAdministrator();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsRunningAsAdministrator *********************

// ********** Begin Class UBPFunctions_Desktop Function IsRunningOnBattery *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics
{
	struct BPFunctions_Desktop_eventIsRunningOnBattery_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|Power" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe8\xbf\x90\xe8\xa1\x8cOn\xe7\x94\xb5\xe6\xb1\xa0\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe8\xbf\x90\xe8\xa1\x8cOn\xe7\x94\xb5\xe6\xb1\xa0\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsRunningOnBattery constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsRunningOnBattery constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsRunningOnBattery Property Definitions *******************************
void Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsRunningOnBattery_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsRunningOnBattery_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::PropPointers) < 2048);
// ********** End Function IsRunningOnBattery Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsRunningOnBattery", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::BPFunctions_Desktop_eventIsRunningOnBattery_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::BPFunctions_Desktop_eventIsRunningOnBattery_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsRunningOnBattery)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsRunningOnBattery();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsRunningOnBattery ***************************

// ********** Begin Class UBPFunctions_Desktop Function IsScreenCaptureDisabled ********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics
{
	struct BPFunctions_Desktop_eventIsScreenCaptureDisabled_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadScreen Capture\xe5\xb7\xb2\xe7\xa6\x81\xe7\x94\xa8\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadScreen Capture\xe5\xb7\xb2\xe7\xa6\x81\xe7\x94\xa8\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsScreenCaptureDisabled constinit property declarations ***************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsScreenCaptureDisabled constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsScreenCaptureDisabled Property Definitions **************************
void Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsScreenCaptureDisabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsScreenCaptureDisabled_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::PropPointers) < 2048);
// ********** End Function IsScreenCaptureDisabled Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsScreenCaptureDisabled", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::BPFunctions_Desktop_eventIsScreenCaptureDisabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::BPFunctions_Desktop_eventIsScreenCaptureDisabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsScreenCaptureDisabled)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsScreenCaptureDisabled();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsScreenCaptureDisabled **********************

// ********** Begin Class UBPFunctions_Desktop Function IsUnderDirectory ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics
{
	struct BPFunctions_Desktop_eventIsUnderDirectory_Parms
	{
		FString Filename;
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xadUnder\xe7\x9b\xae\xe5\xbd\x95\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xadUnder\xe7\x9b\xae\xe5\xbd\x95\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe7\xab\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filename_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Directory_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsUnderDirectory constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Filename;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsUnderDirectory constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsUnderDirectory Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::NewProp_Filename = { "Filename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventIsUnderDirectory_Parms, Filename), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filename_MetaData), NewProp_Filename_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventIsUnderDirectory_Parms, Directory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Directory_MetaData), NewProp_Directory_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventIsUnderDirectory_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventIsUnderDirectory_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::NewProp_Filename,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::PropPointers) < 2048);
// ********** End Function IsUnderDirectory Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "IsUnderDirectory", 	Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::BPFunctions_Desktop_eventIsUnderDirectory_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::BPFunctions_Desktop_eventIsUnderDirectory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execIsUnderDirectory)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Filename);
	P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::IsUnderDirectory(Z_Param_Filename,Z_Param_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function IsUnderDirectory *****************************

// ********** Begin Class UBPFunctions_Desktop Function LaunchUrl **********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics
{
	struct BPFunctions_Desktop_eventLaunchUrl_Parms
	{
		FString InUrl;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Shell" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\x90\xaf\xe5\x8a\xa8URL\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\x90\xaf\xe5\x8a\xa8URL\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InUrl_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LaunchUrl constinit property declarations *****************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InUrl;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LaunchUrl constinit property declarations *******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LaunchUrl Property Definitions ****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::NewProp_InUrl = { "InUrl", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventLaunchUrl_Parms, InUrl), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InUrl_MetaData), NewProp_InUrl_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventLaunchUrl_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventLaunchUrl_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::NewProp_InUrl,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::PropPointers) < 2048);
// ********** End Function LaunchUrl Property Definitions ******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "LaunchUrl", 	Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::BPFunctions_Desktop_eventLaunchUrl_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::BPFunctions_Desktop_eventLaunchUrl_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execLaunchUrl)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InUrl);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::LaunchUrl(Z_Param_InUrl);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function LaunchUrl ************************************

// ********** Begin Class UBPFunctions_Desktop Function LoadImageFromDialog ************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics
{
	struct BPFunctions_Desktop_eventLoadImageFromDialog_Parms
	{
		UTexture2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x8a\xa0\xe8\xbd\xbd\xe5\x9b\xbe\xe5\x83\x8f""From\xe5\xaf\xb9\xe8\xaf\x9d\xe6\xa1\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x8a\xa0\xe8\xbd\xbd\xe5\x9b\xbe\xe5\x83\x8f""From\xe5\xaf\xb9\xe8\xaf\x9d\xe6\xa1\x86\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function LoadImageFromDialog constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadImageFromDialog constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadImageFromDialog Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventLoadImageFromDialog_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::PropPointers) < 2048);
// ********** End Function LoadImageFromDialog Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "LoadImageFromDialog", 	Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::BPFunctions_Desktop_eventLoadImageFromDialog_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::BPFunctions_Desktop_eventLoadImageFromDialog_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execLoadImageFromDialog)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture2D**)Z_Param__Result=UBPFunctions_Desktop::LoadImageFromDialog();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function LoadImageFromDialog **************************

// ********** Begin Class UBPFunctions_Desktop Function LoadImageFromFile **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics
{
	struct BPFunctions_Desktop_eventLoadImageFromFile_Parms
	{
		FString ImagePath;
		UTexture2D* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x8a\xa0\xe8\xbd\xbd\xe5\x9b\xbe\xe5\x83\x8f""From\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x8a\xa0\xe8\xbd\xbd\xe5\x9b\xbe\xe5\x83\x8f""From\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function LoadImageFromFile constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_ImagePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadImageFromFile constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadImageFromFile Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::NewProp_ImagePath = { "ImagePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventLoadImageFromFile_Parms, ImagePath), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventLoadImageFromFile_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::NewProp_ImagePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::PropPointers) < 2048);
// ********** End Function LoadImageFromFile Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "LoadImageFromFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::BPFunctions_Desktop_eventLoadImageFromFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::BPFunctions_Desktop_eventLoadImageFromFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execLoadImageFromFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_ImagePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UTexture2D**)Z_Param__Result=UBPFunctions_Desktop::LoadImageFromFile(Z_Param_ImagePath);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function LoadImageFromFile ****************************

// ********** Begin Class UBPFunctions_Desktop Function MakeValidFileName **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics
{
	struct BPFunctions_Desktop_eventMakeValidFileName_Parms
	{
		FString Filename;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\x9b\xe5\xbb\xba\xe6\x9c\x89\xe6\x95\x88\xe6\x96\x87\xe4\xbb\xb6\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\x9b\xe5\xbb\xba\xe6\x9c\x89\xe6\x95\x88\xe6\x96\x87\xe4\xbb\xb6\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Filename_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function MakeValidFileName constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Filename;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MakeValidFileName constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MakeValidFileName Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::NewProp_Filename = { "Filename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventMakeValidFileName_Parms, Filename), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Filename_MetaData), NewProp_Filename_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventMakeValidFileName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::NewProp_Filename,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::PropPointers) < 2048);
// ********** End Function MakeValidFileName Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "MakeValidFileName", 	Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::BPFunctions_Desktop_eventMakeValidFileName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::BPFunctions_Desktop_eventMakeValidFileName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execMakeValidFileName)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Filename);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::MakeValidFileName(Z_Param_Filename);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function MakeValidFileName ****************************

// ********** Begin Class UBPFunctions_Desktop Function MaximizeMainWindow *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics
{
	struct BPFunctions_Desktop_eventMaximizeMainWindow_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Maximize Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Maximize Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function MaximizeMainWindow constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MaximizeMainWindow constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MaximizeMainWindow Property Definitions *******************************
void Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventMaximizeMainWindow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventMaximizeMainWindow_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::PropPointers) < 2048);
// ********** End Function MaximizeMainWindow Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "MaximizeMainWindow", 	Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::BPFunctions_Desktop_eventMaximizeMainWindow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::BPFunctions_Desktop_eventMaximizeMainWindow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execMaximizeMainWindow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::MaximizeMainWindow();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function MaximizeMainWindow ***************************

// ********** Begin Class UBPFunctions_Desktop Function MinimizeMainWindow *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics
{
	struct BPFunctions_Desktop_eventMinimizeMainWindow_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Minimize Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Minimize Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function MinimizeMainWindow constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MinimizeMainWindow constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MinimizeMainWindow Property Definitions *******************************
void Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventMinimizeMainWindow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventMinimizeMainWindow_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::PropPointers) < 2048);
// ********** End Function MinimizeMainWindow Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "MinimizeMainWindow", 	Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::BPFunctions_Desktop_eventMinimizeMainWindow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::BPFunctions_Desktop_eventMinimizeMainWindow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execMinimizeMainWindow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::MinimizeMainWindow();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function MinimizeMainWindow ***************************

// ********** Begin Class UBPFunctions_Desktop Function MoveFile ***********************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics
{
	struct BPFunctions_Desktop_eventMoveFile_Parms
	{
		FString FileSource;
		FString FileDest;
		bool Replace;
		bool EvenIfReadOnly;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Move\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_EvenIfReadOnly", "false" },
		{ "CPP_Default_Replace", "true" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Move\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function MoveFile constinit property declarations ******************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileSource;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileDest;
	static void NewProp_Replace_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Replace;
	static void NewProp_EvenIfReadOnly_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_EvenIfReadOnly;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MoveFile constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MoveFile Property Definitions *****************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_FileSource = { "FileSource", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventMoveFile_Parms, FileSource), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_FileDest = { "FileDest", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventMoveFile_Parms, FileDest), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_Replace_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventMoveFile_Parms*)Obj)->Replace = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_Replace = { "Replace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventMoveFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_Replace_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_EvenIfReadOnly_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventMoveFile_Parms*)Obj)->EvenIfReadOnly = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_EvenIfReadOnly = { "EvenIfReadOnly", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventMoveFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_EvenIfReadOnly_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventMoveFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventMoveFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_FileSource,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_FileDest,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_Replace,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_EvenIfReadOnly,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::PropPointers) < 2048);
// ********** End Function MoveFile Property Definitions *******************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "MoveFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::BPFunctions_Desktop_eventMoveFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::BPFunctions_Desktop_eventMoveFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execMoveFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileSource);
	P_GET_PROPERTY(FStrProperty,Z_Param_FileDest);
	P_GET_UBOOL(Z_Param_Replace);
	P_GET_UBOOL(Z_Param_EvenIfReadOnly);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::MoveFile(Z_Param_FileSource,Z_Param_FileDest,Z_Param_Replace,Z_Param_EvenIfReadOnly);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function MoveFile *************************************

// ********** Begin Class UBPFunctions_Desktop Function MoveMainWindow *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics
{
	struct BPFunctions_Desktop_eventMoveMainWindow_Parms
	{
		int32 NewPositionX;
		int32 NewPositionY;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Move Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Move Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function MoveMainWindow constinit property declarations ************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewPositionX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewPositionY;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function MoveMainWindow constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function MoveMainWindow Property Definitions ***********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::NewProp_NewPositionX = { "NewPositionX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventMoveMainWindow_Parms, NewPositionX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::NewProp_NewPositionY = { "NewPositionY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventMoveMainWindow_Parms, NewPositionY), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventMoveMainWindow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventMoveMainWindow_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::NewProp_NewPositionX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::NewProp_NewPositionY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::PropPointers) < 2048);
// ********** End Function MoveMainWindow Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "MoveMainWindow", 	Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::BPFunctions_Desktop_eventMoveMainWindow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::BPFunctions_Desktop_eventMoveMainWindow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execMoveMainWindow)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NewPositionX);
	P_GET_PROPERTY(FIntProperty,Z_Param_NewPositionY);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::MoveMainWindow(Z_Param_NewPositionX,Z_Param_NewPositionY);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function MoveMainWindow *******************************

// ********** Begin Class UBPFunctions_Desktop Function NormalizeDirectory *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics
{
	struct BPFunctions_Desktop_eventNormalizeDirectory_Parms
	{
		FString Directory;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Directory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Normalize\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Normalize\xe7\x9b\xae\xe5\xbd\x95\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function NormalizeDirectory constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function NormalizeDirectory constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function NormalizeDirectory Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventNormalizeDirectory_Parms, Directory), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventNormalizeDirectory_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::PropPointers) < 2048);
// ********** End Function NormalizeDirectory Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "NormalizeDirectory", 	Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::BPFunctions_Desktop_eventNormalizeDirectory_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::BPFunctions_Desktop_eventNormalizeDirectory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execNormalizeDirectory)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::NormalizeDirectory(Z_Param_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function NormalizeDirectory ***************************

// ********** Begin Class UBPFunctions_Desktop Function NormalizeFileName **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics
{
	struct BPFunctions_Desktop_eventNormalizeFileName_Parms
	{
		FString Filename;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Normalize\xe6\x96\x87\xe4\xbb\xb6\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Normalize\xe6\x96\x87\xe4\xbb\xb6\xe5\x90\x8d\xe7\xa7\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function NormalizeFileName constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Filename;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function NormalizeFileName constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function NormalizeFileName Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::NewProp_Filename = { "Filename", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventNormalizeFileName_Parms, Filename), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventNormalizeFileName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::NewProp_Filename,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::PropPointers) < 2048);
// ********** End Function NormalizeFileName Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "NormalizeFileName", 	Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::BPFunctions_Desktop_eventNormalizeFileName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::BPFunctions_Desktop_eventNormalizeFileName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execNormalizeFileName)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Filename);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::NormalizeFileName(Z_Param_Filename);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function NormalizeFileName ****************************

// ********** Begin Class UBPFunctions_Desktop Function OpenDirectoryDialog ************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics
{
	struct BPFunctions_Desktop_eventOpenDirectoryDialog_Parms
	{
		FString Directory;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Directory" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\x93\xe5\xbc\x80\xe7\x9b\xae\xe5\xbd\x95\xe5\xaf\xb9\xe8\xaf\x9d\xe6\xa1\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\x93\xe5\xbc\x80\xe7\x9b\xae\xe5\xbd\x95\xe5\xaf\xb9\xe8\xaf\x9d\xe6\xa1\x86\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenDirectoryDialog constinit property declarations *******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Directory;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenDirectoryDialog constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenDirectoryDialog Property Definitions ******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventOpenDirectoryDialog_Parms, Directory), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventOpenDirectoryDialog_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventOpenDirectoryDialog_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::NewProp_Directory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::PropPointers) < 2048);
// ********** End Function OpenDirectoryDialog Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "OpenDirectoryDialog", 	Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::BPFunctions_Desktop_eventOpenDirectoryDialog_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::BPFunctions_Desktop_eventOpenDirectoryDialog_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execOpenDirectoryDialog)
{
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Directory);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::OpenDirectoryDialog(Z_Param_Out_Directory);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function OpenDirectoryDialog **************************

// ********** Begin Class UBPFunctions_Desktop Function OpenDirectoryInShell ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics
{
	struct BPFunctions_Desktop_eventOpenDirectoryInShell_Parms
	{
		FString InDirectoryPath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Shell" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\x93\xe5\xbc\x80\xe7\x9b\xae\xe5\xbd\x95In Shell\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\x93\xe5\xbc\x80\xe7\x9b\xae\xe5\xbd\x95In Shell\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InDirectoryPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenDirectoryInShell constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InDirectoryPath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenDirectoryInShell constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenDirectoryInShell Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::NewProp_InDirectoryPath = { "InDirectoryPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventOpenDirectoryInShell_Parms, InDirectoryPath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InDirectoryPath_MetaData), NewProp_InDirectoryPath_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventOpenDirectoryInShell_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventOpenDirectoryInShell_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::NewProp_InDirectoryPath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::PropPointers) < 2048);
// ********** End Function OpenDirectoryInShell Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "OpenDirectoryInShell", 	Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::BPFunctions_Desktop_eventOpenDirectoryInShell_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::BPFunctions_Desktop_eventOpenDirectoryInShell_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execOpenDirectoryInShell)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InDirectoryPath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::OpenDirectoryInShell(Z_Param_InDirectoryPath);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function OpenDirectoryInShell *************************

// ********** Begin Class UBPFunctions_Desktop Function OpenFileDialog *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics
{
	struct BPFunctions_Desktop_eventOpenFileDialog_Parms
	{
		FString FileType;
		TArray<FString> FilePaths;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\x93\xe5\xbc\x80\xe6\x96\x87\xe4\xbb\xb6\xe5\xaf\xb9\xe8\xaf\x9d\xe6\xa1\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\x93\xe5\xbc\x80\xe6\x96\x87\xe4\xbb\xb6\xe5\xaf\xb9\xe8\xaf\x9d\xe6\xa1\x86\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OpenFileDialog constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePaths_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FilePaths;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenFileDialog constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenFileDialog Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::NewProp_FileType = { "FileType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventOpenFileDialog_Parms, FileType), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::NewProp_FilePaths_Inner = { "FilePaths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::NewProp_FilePaths = { "FilePaths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventOpenFileDialog_Parms, FilePaths), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventOpenFileDialog_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventOpenFileDialog_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::NewProp_FileType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::NewProp_FilePaths_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::NewProp_FilePaths,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::PropPointers) < 2048);
// ********** End Function OpenFileDialog Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "OpenFileDialog", 	Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::BPFunctions_Desktop_eventOpenFileDialog_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::BPFunctions_Desktop_eventOpenFileDialog_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execOpenFileDialog)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileType);
	P_GET_TARRAY_REF(FString,Z_Param_Out_FilePaths);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::OpenFileDialog(Z_Param_FileType,Z_Param_Out_FilePaths);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function OpenFileDialog *******************************

// ********** Begin Class UBPFunctions_Desktop Function OpenFileInShell ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics
{
	struct BPFunctions_Desktop_eventOpenFileInShell_Parms
	{
		FString InFilePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Shell" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\x93\xe5\xbc\x80\xe6\x96\x87\xe4\xbb\xb6In Shell\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\x93\xe5\xbc\x80\xe6\x96\x87\xe4\xbb\xb6In Shell\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InFilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function OpenFileInShell constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InFilePath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OpenFileInShell constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OpenFileInShell Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::NewProp_InFilePath = { "InFilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventOpenFileInShell_Parms, InFilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InFilePath_MetaData), NewProp_InFilePath_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventOpenFileInShell_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventOpenFileInShell_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::NewProp_InFilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::PropPointers) < 2048);
// ********** End Function OpenFileInShell Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "OpenFileInShell", 	Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::BPFunctions_Desktop_eventOpenFileInShell_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::BPFunctions_Desktop_eventOpenFileInShell_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execOpenFileInShell)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InFilePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::OpenFileInShell(Z_Param_InFilePath);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function OpenFileInShell ******************************

// ********** Begin Class UBPFunctions_Desktop Function ReadBytesFromFile **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics
{
	struct BPFunctions_Desktop_eventReadBytesFromFile_Parms
	{
		FString FileName;
		TArray<uint8> OutBytes;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0""From\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0""From\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ReadBytesFromFile constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OutBytes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_OutBytes;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ReadBytesFromFile constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ReadBytesFromFile Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventReadBytesFromFile_Parms, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::NewProp_OutBytes_Inner = { "OutBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::NewProp_OutBytes = { "OutBytes", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventReadBytesFromFile_Parms, OutBytes), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventReadBytesFromFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventReadBytesFromFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::NewProp_OutBytes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::NewProp_OutBytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::PropPointers) < 2048);
// ********** End Function ReadBytesFromFile Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "ReadBytesFromFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::BPFunctions_Desktop_eventReadBytesFromFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::BPFunctions_Desktop_eventReadBytesFromFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execReadBytesFromFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBytes);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::ReadBytesFromFile(Z_Param_FileName,Z_Param_Out_OutBytes);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function ReadBytesFromFile ****************************

// ********** Begin Class UBPFunctions_Desktop Function ReadStringFromFile *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics
{
	struct BPFunctions_Desktop_eventReadStringFromFile_Parms
	{
		FString FileName;
		FString Data;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2""From\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe8\xaf\xbb\xe5\x8f\x96\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2""From\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ReadStringFromFile constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Data;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ReadStringFromFile constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ReadStringFromFile Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventReadStringFromFile_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventReadStringFromFile_Parms, Data), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventReadStringFromFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventReadStringFromFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::NewProp_Data,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::PropPointers) < 2048);
// ********** End Function ReadStringFromFile Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "ReadStringFromFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::BPFunctions_Desktop_eventReadStringFromFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::BPFunctions_Desktop_eventReadStringFromFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execReadStringFromFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Data);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::ReadStringFromFile(Z_Param_FileName,Z_Param_Out_Data);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function ReadStringFromFile ***************************

// ********** Begin Class UBPFunctions_Desktop Function RequestMinimizeApplication *****************
struct Z_Construct_UFunction_UBPFunctions_Desktop_RequestMinimizeApplication_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xb7\xe6\xb1\x82Minimize\xe5\xba\x94\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xb7\xe6\xb1\x82Minimize\xe5\xba\x94\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RequestMinimizeApplication constinit property declarations ************
// ********** End Function RequestMinimizeApplication constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_RequestMinimizeApplication_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "RequestMinimizeApplication", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_RequestMinimizeApplication_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_RequestMinimizeApplication_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_RequestMinimizeApplication()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_RequestMinimizeApplication_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execRequestMinimizeApplication)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::RequestMinimizeApplication();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function RequestMinimizeApplication *******************

// ********** Begin Class UBPFunctions_Desktop Function ResizeMainWindow ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics
{
	struct BPFunctions_Desktop_eventResizeMainWindow_Parms
	{
		int32 NewSizeX;
		int32 NewSizeY;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Resize Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Resize Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ResizeMainWindow constinit property declarations **********************
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewSizeX;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NewSizeY;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResizeMainWindow constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResizeMainWindow Property Definitions *********************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::NewProp_NewSizeX = { "NewSizeX", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventResizeMainWindow_Parms, NewSizeX), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::NewProp_NewSizeY = { "NewSizeY", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventResizeMainWindow_Parms, NewSizeY), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventResizeMainWindow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventResizeMainWindow_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::NewProp_NewSizeX,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::NewProp_NewSizeY,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::PropPointers) < 2048);
// ********** End Function ResizeMainWindow Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "ResizeMainWindow", 	Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::BPFunctions_Desktop_eventResizeMainWindow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::BPFunctions_Desktop_eventResizeMainWindow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execResizeMainWindow)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_NewSizeX);
	P_GET_PROPERTY(FIntProperty,Z_Param_NewSizeY);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::ResizeMainWindow(Z_Param_NewSizeX,Z_Param_NewSizeY);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function ResizeMainWindow *****************************

// ********** Begin Class UBPFunctions_Desktop Function RestartApplication *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics
{
	struct BPFunctions_Desktop_eventRestartApplication_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Restart\xe5\xba\x94\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Restart\xe5\xba\x94\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RestartApplication constinit property declarations ********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestartApplication constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestartApplication Property Definitions *******************************
void Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventRestartApplication_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventRestartApplication_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::PropPointers) < 2048);
// ********** End Function RestartApplication Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "RestartApplication", 	Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::BPFunctions_Desktop_eventRestartApplication_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::BPFunctions_Desktop_eventRestartApplication_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execRestartApplication)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::RestartApplication();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function RestartApplication ***************************

// ********** Begin Class UBPFunctions_Desktop Function RestoreMainWindow **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics
{
	struct BPFunctions_Desktop_eventRestoreMainWindow_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Restore Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Restore Main\xe7\xaa\x97\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RestoreMainWindow constinit property declarations *********************
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RestoreMainWindow constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RestoreMainWindow Property Definitions ********************************
void Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventRestoreMainWindow_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventRestoreMainWindow_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::PropPointers) < 2048);
// ********** End Function RestoreMainWindow Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "RestoreMainWindow", 	Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::BPFunctions_Desktop_eventRestoreMainWindow_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::BPFunctions_Desktop_eventRestoreMainWindow_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execRestoreMainWindow)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::RestoreMainWindow();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function RestoreMainWindow ****************************

// ********** Begin Class UBPFunctions_Desktop Function RevealFileInExplorer ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics
{
	struct BPFunctions_Desktop_eventRevealFileInExplorer_Parms
	{
		FString InFilePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Shell" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Reveal\xe6\x96\x87\xe4\xbb\xb6In Explorer\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Reveal\xe6\x96\x87\xe4\xbb\xb6In Explorer\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InFilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RevealFileInExplorer constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InFilePath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RevealFileInExplorer constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RevealFileInExplorer Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::NewProp_InFilePath = { "InFilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventRevealFileInExplorer_Parms, InFilePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InFilePath_MetaData), NewProp_InFilePath_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventRevealFileInExplorer_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventRevealFileInExplorer_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::NewProp_InFilePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::PropPointers) < 2048);
// ********** End Function RevealFileInExplorer Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "RevealFileInExplorer", 	Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::BPFunctions_Desktop_eventRevealFileInExplorer_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::BPFunctions_Desktop_eventRevealFileInExplorer_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execRevealFileInExplorer)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InFilePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::RevealFileInExplorer(Z_Param_InFilePath);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function RevealFileInExplorer *************************

// ********** Begin Class UBPFunctions_Desktop Function SaveBytesToFile ****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics
{
	struct BPFunctions_Desktop_eventSaveBytesToFile_Parms
	{
		FString FileName;
		TArray<uint8> Bytes;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe4\xbf\x9d\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0To\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe4\xbf\x9d\xe5\xad\x98\xe5\xad\x97\xe8\x8a\x82\xe6\x95\xb0To\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SaveBytesToFile constinit property declarations ***********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_Bytes_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Bytes;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SaveBytesToFile constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SaveBytesToFile Property Definitions **********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSaveBytesToFile_Parms, FileName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FileName_MetaData), NewProp_FileName_MetaData) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::NewProp_Bytes_Inner = { "Bytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::NewProp_Bytes = { "Bytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSaveBytesToFile_Parms, Bytes), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bytes_MetaData), NewProp_Bytes_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventSaveBytesToFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventSaveBytesToFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::NewProp_Bytes_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::NewProp_Bytes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::PropPointers) < 2048);
// ********** End Function SaveBytesToFile Property Definitions ************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "SaveBytesToFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::BPFunctions_Desktop_eventSaveBytesToFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::BPFunctions_Desktop_eventSaveBytesToFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execSaveBytesToFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::SaveBytesToFile(Z_Param_FileName,Z_Param_Out_Bytes);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function SaveBytesToFile ******************************

// ********** Begin Class UBPFunctions_Desktop Function SaveFileDialog *****************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics
{
	struct BPFunctions_Desktop_eventSaveFileDialog_Parms
	{
		FString FileName;
		FString FileType;
		TArray<FString> FilePaths;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6\xe5\xaf\xb9\xe8\xaf\x9d\xe6\xa1\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe4\xbb\xb6\xe5\xaf\xb9\xe8\xaf\x9d\xe6\xa1\x86\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SaveFileDialog constinit property declarations ************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileType;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FilePaths_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_FilePaths;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SaveFileDialog constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SaveFileDialog Property Definitions ***********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSaveFileDialog_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_FileType = { "FileType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSaveFileDialog_Parms, FileType), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_FilePaths_Inner = { "FilePaths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_FilePaths = { "FilePaths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSaveFileDialog_Parms, FilePaths), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventSaveFileDialog_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventSaveFileDialog_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_FileType,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_FilePaths_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_FilePaths,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::PropPointers) < 2048);
// ********** End Function SaveFileDialog Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "SaveFileDialog", 	Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::BPFunctions_Desktop_eventSaveFileDialog_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::BPFunctions_Desktop_eventSaveFileDialog_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execSaveFileDialog)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_PROPERTY(FStrProperty,Z_Param_FileType);
	P_GET_TARRAY_REF(FString,Z_Param_Out_FilePaths);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::SaveFileDialog(Z_Param_FileName,Z_Param_FileType,Z_Param_Out_FilePaths);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function SaveFileDialog *******************************

// ********** Begin Class UBPFunctions_Desktop Function SetClipboardText ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics
{
	struct BPFunctions_Desktop_eventSetClipboardText_Parms
	{
		FString InText;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Shell" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xae""Clipboard\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xae""Clipboard\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InText_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetClipboardText constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InText;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetClipboardText constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetClipboardText Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::NewProp_InText = { "InText", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSetClipboardText_Parms, InText), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InText_MetaData), NewProp_InText_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::NewProp_InText,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::PropPointers) < 2048);
// ********** End Function SetClipboardText Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "SetClipboardText", 	Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::BPFunctions_Desktop_eventSetClipboardText_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::BPFunctions_Desktop_eventSetClipboardText_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execSetClipboardText)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InText);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::SetClipboardText(Z_Param_InText);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function SetClipboardText *****************************

// ********** Begin Class UBPFunctions_Desktop Function SetFileExtension ***************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics
{
	struct BPFunctions_Desktop_eventSetFileExtension_Parms
	{
		FString FileName;
		FString NewExtension;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xae\xe6\x96\x87\xe4\xbb\xb6""Extension\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xae\xe6\x96\x87\xe4\xbb\xb6""Extension\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetFileExtension constinit property declarations **********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NewExtension;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetFileExtension constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetFileExtension Property Definitions *********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSetFileExtension_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::NewProp_NewExtension = { "NewExtension", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSetFileExtension_Parms, NewExtension), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSetFileExtension_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::NewProp_NewExtension,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::PropPointers) < 2048);
// ********** End Function SetFileExtension Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "SetFileExtension", 	Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::BPFunctions_Desktop_eventSetFileExtension_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::BPFunctions_Desktop_eventSetFileExtension_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execSetFileExtension)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_PROPERTY(FStrProperty,Z_Param_NewExtension);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_Desktop::SetFileExtension(Z_Param_FileName,Z_Param_NewExtension);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function SetFileExtension *****************************

// ********** Begin Class UBPFunctions_Desktop Function SetMainWindowTitle *************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics
{
	struct BPFunctions_Desktop_eventSetMainWindowTitle_Parms
	{
		FString InTitle;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xaeMain\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa0\x87\xe9\xa2\x98\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xaeMain\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa0\x87\xe9\xa2\x98\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InTitle_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetMainWindowTitle constinit property declarations ********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_InTitle;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMainWindowTitle constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMainWindowTitle Property Definitions *******************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::NewProp_InTitle = { "InTitle", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSetMainWindowTitle_Parms, InTitle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InTitle_MetaData), NewProp_InTitle_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventSetMainWindowTitle_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventSetMainWindowTitle_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::NewProp_InTitle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::PropPointers) < 2048);
// ********** End Function SetMainWindowTitle Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "SetMainWindowTitle", 	Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::BPFunctions_Desktop_eventSetMainWindowTitle_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::BPFunctions_Desktop_eventSetMainWindowTitle_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execSetMainWindowTitle)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_InTitle);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::SetMainWindowTitle(Z_Param_InTitle);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function SetMainWindowTitle ***************************

// ********** Begin Class UBPFunctions_Desktop Function SetMainWindowTopMost ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics
{
	struct BPFunctions_Desktop_eventSetMainWindowTopMost_Parms
	{
		bool bEnable;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xaeMain\xe7\xaa\x97\xe5\x8f\xa3Top Most\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xaeMain\xe7\xaa\x97\xe5\x8f\xa3Top Most\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetMainWindowTopMost constinit property declarations ******************
	static void NewProp_bEnable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnable;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetMainWindowTopMost constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetMainWindowTopMost Property Definitions *****************************
void Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::NewProp_bEnable_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventSetMainWindowTopMost_Parms*)Obj)->bEnable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::NewProp_bEnable = { "bEnable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventSetMainWindowTopMost_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::NewProp_bEnable_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventSetMainWindowTopMost_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventSetMainWindowTopMost_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::NewProp_bEnable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::PropPointers) < 2048);
// ********** End Function SetMainWindowTopMost Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "SetMainWindowTopMost", 	Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::BPFunctions_Desktop_eventSetMainWindowTopMost_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::BPFunctions_Desktop_eventSetMainWindowTopMost_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execSetMainWindowTopMost)
{
	P_GET_UBOOL(Z_Param_bEnable);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::SetMainWindowTopMost(Z_Param_bEnable);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function SetMainWindowTopMost *************************

// ********** Begin Class UBPFunctions_Desktop Function SetScreenCaptureDisabled *******************
struct Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics
{
	struct BPFunctions_Desktop_eventSetScreenCaptureDisabled_Parms
	{
		bool bDisable;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xaeScreen Capture\xe5\xb7\xb2\xe7\xa6\x81\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xaeScreen Capture\xe5\xb7\xb2\xe7\xa6\x81\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetScreenCaptureDisabled constinit property declarations **************
	static void NewProp_bDisable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDisable;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetScreenCaptureDisabled constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetScreenCaptureDisabled Property Definitions *************************
void Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::NewProp_bDisable_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventSetScreenCaptureDisabled_Parms*)Obj)->bDisable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::NewProp_bDisable = { "bDisable", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventSetScreenCaptureDisabled_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::NewProp_bDisable_SetBit, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventSetScreenCaptureDisabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventSetScreenCaptureDisabled_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::NewProp_bDisable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::PropPointers) < 2048);
// ********** End Function SetScreenCaptureDisabled Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "SetScreenCaptureDisabled", 	Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::BPFunctions_Desktop_eventSetScreenCaptureDisabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::BPFunctions_Desktop_eventSetScreenCaptureDisabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execSetScreenCaptureDisabled)
{
	P_GET_UBOOL(Z_Param_bDisable);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::SetScreenCaptureDisabled(Z_Param_bDisable);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function SetScreenCaptureDisabled *********************

// ********** Begin Class UBPFunctions_Desktop Function SetWindowMode ******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics
{
	struct BPFunctions_Desktop_eventSetWindowMode_Parms
	{
		EDesktopDisplayMode InWindowMode;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|MainWindow" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xbe\xe7\xbd\xae\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xbe\xe7\xbd\xae\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function SetWindowMode constinit property declarations *************************
	static const UECodeGen_Private::FBytePropertyParams NewProp_InWindowMode_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_InWindowMode;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetWindowMode constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetWindowMode Property Definitions ************************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::NewProp_InWindowMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::NewProp_InWindowMode = { "InWindowMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventSetWindowMode_Parms, InWindowMode), Z_Construct_UEnum_GenericDesktopFramework_EDesktopDisplayMode, METADATA_PARAMS(0, nullptr) }; // 59183459
void Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventSetWindowMode_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventSetWindowMode_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::NewProp_InWindowMode_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::NewProp_InWindowMode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::PropPointers) < 2048);
// ********** End Function SetWindowMode Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "SetWindowMode", 	Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::BPFunctions_Desktop_eventSetWindowMode_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::BPFunctions_Desktop_eventSetWindowMode_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execSetWindowMode)
{
	P_GET_ENUM(EDesktopDisplayMode,Z_Param_InWindowMode);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::SetWindowMode(EDesktopDisplayMode(Z_Param_InWindowMode));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function SetWindowMode ********************************

// ********** Begin Class UBPFunctions_Desktop Function StringToBase64String ***********************
struct Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics
{
	struct BPFunctions_Desktop_eventStringToBase64String_Parms
	{
		FString String;
		FString Base64String;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2To\xe5\x9f\xba\xe7\xa1\x80""64\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2To\xe5\x9f\xba\xe7\xa1\x80""64\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function StringToBase64String constinit property declarations ******************
	static const UECodeGen_Private::FStrPropertyParams NewProp_String;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Base64String;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function StringToBase64String constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function StringToBase64String Property Definitions *****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::NewProp_String = { "String", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventStringToBase64String_Parms, String), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::NewProp_Base64String = { "Base64String", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventStringToBase64String_Parms, Base64String), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::NewProp_String,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::NewProp_Base64String,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::PropPointers) < 2048);
// ********** End Function StringToBase64String Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "StringToBase64String", 	Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::BPFunctions_Desktop_eventStringToBase64String_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::BPFunctions_Desktop_eventStringToBase64String_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execStringToBase64String)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_String);
	P_GET_PROPERTY_REF(FStrProperty,Z_Param_Out_Base64String);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::StringToBase64String(Z_Param_String,Z_Param_Out_Base64String);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function StringToBase64String *************************

// ********** Begin Class UBPFunctions_Desktop Function Test_CPUInfo *******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_Test_CPUInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|CPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Test CPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Test CPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Test_CPUInfo constinit property declarations **************************
// ********** End Function Test_CPUInfo constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_Test_CPUInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "Test_CPUInfo", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_Test_CPUInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_Test_CPUInfo_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_Test_CPUInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_Test_CPUInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execTest_CPUInfo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::Test_CPUInfo();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function Test_CPUInfo *********************************

// ********** Begin Class UBPFunctions_Desktop Function Test_GPUInfo *******************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_Test_GPUInfo_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|Hardware|GPU" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86Test GPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86Test GPU\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Test_GPUInfo constinit property declarations **************************
// ********** End Function Test_GPUInfo constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_Test_GPUInfo_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "Test_GPUInfo", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_Test_GPUInfo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_Test_GPUInfo_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_Test_GPUInfo()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_Test_GPUInfo_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execTest_GPUInfo)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Desktop::Test_GPUInfo();
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function Test_GPUInfo *********************************

// ********** Begin Class UBPFunctions_Desktop Function WriteStringToFile **************************
struct Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics
{
	struct BPFunctions_Desktop_eventWriteStringToFile_Parms
	{
		FString Data;
		FString FileName;
		EDesktopTextEncodingOptions EncodingOptions;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Window|File" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xa4\x84\xe7\x90\x86\xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2To\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_EncodingOptions", "AutoDetect" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xa4\x84\xe7\x90\x86\xe5\x86\x99\xe5\x85\xa5\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2To\xe6\x96\x87\xe4\xbb\xb6\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function WriteStringToFile constinit property declarations *********************
	static const UECodeGen_Private::FStrPropertyParams NewProp_Data;
	static const UECodeGen_Private::FStrPropertyParams NewProp_FileName;
	static const UECodeGen_Private::FBytePropertyParams NewProp_EncodingOptions_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_EncodingOptions;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function WriteStringToFile constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function WriteStringToFile Property Definitions ********************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_Data = { "Data", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventWriteStringToFile_Parms, Data), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventWriteStringToFile_Parms, FileName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_EncodingOptions_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_EncodingOptions = { "EncodingOptions", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Desktop_eventWriteStringToFile_Parms, EncodingOptions), Z_Construct_UEnum_GenericDesktopFramework_EDesktopTextEncodingOptions, METADATA_PARAMS(0, nullptr) }; // 2503097535
void Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Desktop_eventWriteStringToFile_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Desktop_eventWriteStringToFile_Parms), &Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_Data,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_FileName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_EncodingOptions_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_EncodingOptions,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::PropPointers) < 2048);
// ********** End Function WriteStringToFile Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Desktop, nullptr, "WriteStringToFile", 	Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::BPFunctions_Desktop_eventWriteStringToFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::BPFunctions_Desktop_eventWriteStringToFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Desktop::execWriteStringToFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_Data);
	P_GET_PROPERTY(FStrProperty,Z_Param_FileName);
	P_GET_ENUM(EDesktopTextEncodingOptions,Z_Param_EncodingOptions);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Desktop::WriteStringToFile(Z_Param_Data,Z_Param_FileName,EDesktopTextEncodingOptions(Z_Param_EncodingOptions));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Desktop Function WriteStringToFile ****************************

// ********** Begin Class UBPFunctions_Desktop *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBPFunctions_Desktop;
UClass* UBPFunctions_Desktop::GetPrivateStaticClass()
{
	using TClass = UBPFunctions_Desktop;
	if (!Z_Registration_Info_UClass_UBPFunctions_Desktop.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BPFunctions_Desktop"),
			Z_Registration_Info_UClass_UBPFunctions_Desktop.InnerSingleton,
			StaticRegisterNativesUBPFunctions_Desktop,
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
	return Z_Registration_Info_UClass_UBPFunctions_Desktop.InnerSingleton;
}
UClass* Z_Construct_UClass_UBPFunctions_Desktop_NoRegister()
{
	return UBPFunctions_Desktop::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBPFunctions_Desktop_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x90\xe4\xbe\x9b\xe6\xa1\x8c\xe9\x9d\xa2\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "BPFunctions/BPFunctions_Desktop.h" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Desktop.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x90\xe4\xbe\x9b\xe6\xa1\x8c\xe9\x9d\xa2\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBPFunctions_Desktop constinit property declarations *********************
// ********** End Class UBPFunctions_Desktop constinit property declarations ***********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("AddBytesToFile"), .Pointer = &UBPFunctions_Desktop::execAddBytesToFile },
		{ .NameUTF8 = UTF8TEXT("Base64StringToBytes"), .Pointer = &UBPFunctions_Desktop::execBase64StringToBytes },
		{ .NameUTF8 = UTF8TEXT("Base64StringToString"), .Pointer = &UBPFunctions_Desktop::execBase64StringToString },
		{ .NameUTF8 = UTF8TEXT("BringMainWindowToFront"), .Pointer = &UBPFunctions_Desktop::execBringMainWindowToFront },
		{ .NameUTF8 = UTF8TEXT("BytesToBase64String"), .Pointer = &UBPFunctions_Desktop::execBytesToBase64String },
		{ .NameUTF8 = UTF8TEXT("CanLaunchUrl"), .Pointer = &UBPFunctions_Desktop::execCanLaunchUrl },
		{ .NameUTF8 = UTF8TEXT("ConvBytesToTexture2D"), .Pointer = &UBPFunctions_Desktop::execConvBytesToTexture2D },
		{ .NameUTF8 = UTF8TEXT("ConvertToFullPath"), .Pointer = &UBPFunctions_Desktop::execConvertToFullPath },
		{ .NameUTF8 = UTF8TEXT("ConvertToRelativePath"), .Pointer = &UBPFunctions_Desktop::execConvertToRelativePath },
		{ .NameUTF8 = UTF8TEXT("ConvTexture2DToBytes"), .Pointer = &UBPFunctions_Desktop::execConvTexture2DToBytes },
		{ .NameUTF8 = UTF8TEXT("CopyFile"), .Pointer = &UBPFunctions_Desktop::execCopyFile },
		{ .NameUTF8 = UTF8TEXT("CreateDirectory"), .Pointer = &UBPFunctions_Desktop::execCreateDirectory },
		{ .NameUTF8 = UTF8TEXT("DeleteDirectory"), .Pointer = &UBPFunctions_Desktop::execDeleteDirectory },
		{ .NameUTF8 = UTF8TEXT("DeleteDirectoryRecursively"), .Pointer = &UBPFunctions_Desktop::execDeleteDirectoryRecursively },
		{ .NameUTF8 = UTF8TEXT("DeleteFile"), .Pointer = &UBPFunctions_Desktop::execDeleteFile },
		{ .NameUTF8 = UTF8TEXT("ExistDirectory"), .Pointer = &UBPFunctions_Desktop::execExistDirectory },
		{ .NameUTF8 = UTF8TEXT("ExistFile"), .Pointer = &UBPFunctions_Desktop::execExistFile },
		{ .NameUTF8 = UTF8TEXT("FileSize"), .Pointer = &UBPFunctions_Desktop::execFileSize },
		{ .NameUTF8 = UTF8TEXT("FindDirectory"), .Pointer = &UBPFunctions_Desktop::execFindDirectory },
		{ .NameUTF8 = UTF8TEXT("FindDirectoryRecursive"), .Pointer = &UBPFunctions_Desktop::execFindDirectoryRecursive },
		{ .NameUTF8 = UTF8TEXT("FindFile"), .Pointer = &UBPFunctions_Desktop::execFindFile },
		{ .NameUTF8 = UTF8TEXT("FindFileRecursive"), .Pointer = &UBPFunctions_Desktop::execFindFileRecursive },
		{ .NameUTF8 = UTF8TEXT("FlashMainWindow"), .Pointer = &UBPFunctions_Desktop::execFlashMainWindow },
		{ .NameUTF8 = UTF8TEXT("GetAllDiskInfos"), .Pointer = &UBPFunctions_Desktop::execGetAllDiskInfos },
		{ .NameUTF8 = UTF8TEXT("GetAllMonitorInfos"), .Pointer = &UBPFunctions_Desktop::execGetAllMonitorInfos },
		{ .NameUTF8 = UTF8TEXT("GetAppDataDir"), .Pointer = &UBPFunctions_Desktop::execGetAppDataDir },
		{ .NameUTF8 = UTF8TEXT("GetApplicationInfo"), .Pointer = &UBPFunctions_Desktop::execGetApplicationInfo },
		{ .NameUTF8 = UTF8TEXT("GetBaseFilename"), .Pointer = &UBPFunctions_Desktop::execGetBaseFilename },
		{ .NameUTF8 = UTF8TEXT("GetBatteryPercent"), .Pointer = &UBPFunctions_Desktop::execGetBatteryPercent },
		{ .NameUTF8 = UTF8TEXT("GetCleanFilename"), .Pointer = &UBPFunctions_Desktop::execGetCleanFilename },
		{ .NameUTF8 = UTF8TEXT("GetClipboardText"), .Pointer = &UBPFunctions_Desktop::execGetClipboardText },
		{ .NameUTF8 = UTF8TEXT("GetCommandLineString"), .Pointer = &UBPFunctions_Desktop::execGetCommandLineString },
		{ .NameUTF8 = UTF8TEXT("GetCPUBrand"), .Pointer = &UBPFunctions_Desktop::execGetCPUBrand },
		{ .NameUTF8 = UTF8TEXT("GetCPUChipset"), .Pointer = &UBPFunctions_Desktop::execGetCPUChipset },
		{ .NameUTF8 = UTF8TEXT("GetCPUCores"), .Pointer = &UBPFunctions_Desktop::execGetCPUCores },
		{ .NameUTF8 = UTF8TEXT("GetCPUFrequency"), .Pointer = &UBPFunctions_Desktop::execGetCPUFrequency },
		{ .NameUTF8 = UTF8TEXT("GetCPUHardwareInfo"), .Pointer = &UBPFunctions_Desktop::execGetCPUHardwareInfo },
		{ .NameUTF8 = UTF8TEXT("GetCPULogicalCores"), .Pointer = &UBPFunctions_Desktop::execGetCPULogicalCores },
		{ .NameUTF8 = UTF8TEXT("GetCPUPhysicalCores"), .Pointer = &UBPFunctions_Desktop::execGetCPUPhysicalCores },
		{ .NameUTF8 = UTF8TEXT("GetCPUProcessCount"), .Pointer = &UBPFunctions_Desktop::execGetCPUProcessCount },
		{ .NameUTF8 = UTF8TEXT("GetCPUThreadCount"), .Pointer = &UBPFunctions_Desktop::execGetCPUThreadCount },
		{ .NameUTF8 = UTF8TEXT("GetCPUUsage"), .Pointer = &UBPFunctions_Desktop::execGetCPUUsage },
		{ .NameUTF8 = UTF8TEXT("GetCPUVendor"), .Pointer = &UBPFunctions_Desktop::execGetCPUVendor },
		{ .NameUTF8 = UTF8TEXT("GetCurrentMonitorInfo"), .Pointer = &UBPFunctions_Desktop::execGetCurrentMonitorInfo },
		{ .NameUTF8 = UTF8TEXT("GetDesktopBaseDir"), .Pointer = &UBPFunctions_Desktop::execGetDesktopBaseDir },
		{ .NameUTF8 = UTF8TEXT("GetDesktopDir"), .Pointer = &UBPFunctions_Desktop::execGetDesktopDir },
		{ .NameUTF8 = UTF8TEXT("GetDesktopName"), .Pointer = &UBPFunctions_Desktop::execGetDesktopName },
		{ .NameUTF8 = UTF8TEXT("GetDesktopUserDir"), .Pointer = &UBPFunctions_Desktop::execGetDesktopUserDir },
		{ .NameUTF8 = UTF8TEXT("GetDesktopUserHomeDir"), .Pointer = &UBPFunctions_Desktop::execGetDesktopUserHomeDir },
		{ .NameUTF8 = UTF8TEXT("GetDesktopUserName"), .Pointer = &UBPFunctions_Desktop::execGetDesktopUserName },
		{ .NameUTF8 = UTF8TEXT("GetDesktopUserTempDir"), .Pointer = &UBPFunctions_Desktop::execGetDesktopUserTempDir },
		{ .NameUTF8 = UTF8TEXT("GetDeviceID"), .Pointer = &UBPFunctions_Desktop::execGetDeviceID },
		{ .NameUTF8 = UTF8TEXT("GetDiskFreeBytes"), .Pointer = &UBPFunctions_Desktop::execGetDiskFreeBytes },
		{ .NameUTF8 = UTF8TEXT("GetDiskInfo"), .Pointer = &UBPFunctions_Desktop::execGetDiskInfo },
		{ .NameUTF8 = UTF8TEXT("GetDiskTotalBytes"), .Pointer = &UBPFunctions_Desktop::execGetDiskTotalBytes },
		{ .NameUTF8 = UTF8TEXT("GetDiskUsedBytes"), .Pointer = &UBPFunctions_Desktop::execGetDiskUsedBytes },
		{ .NameUTF8 = UTF8TEXT("GetDisplayInfo"), .Pointer = &UBPFunctions_Desktop::execGetDisplayInfo },
		{ .NameUTF8 = UTF8TEXT("GetDocumentsDir"), .Pointer = &UBPFunctions_Desktop::execGetDocumentsDir },
		{ .NameUTF8 = UTF8TEXT("GetDownloadsDir"), .Pointer = &UBPFunctions_Desktop::execGetDownloadsDir },
		{ .NameUTF8 = UTF8TEXT("GetEnvironmentVariable"), .Pointer = &UBPFunctions_Desktop::execGetEnvironmentVariable },
		{ .NameUTF8 = UTF8TEXT("GetExecutablePath"), .Pointer = &UBPFunctions_Desktop::execGetExecutablePath },
		{ .NameUTF8 = UTF8TEXT("GetExtrasDir"), .Pointer = &UBPFunctions_Desktop::execGetExtrasDir },
		{ .NameUTF8 = UTF8TEXT("GetFileExtension"), .Pointer = &UBPFunctions_Desktop::execGetFileExtension },
		{ .NameUTF8 = UTF8TEXT("GetFilePath"), .Pointer = &UBPFunctions_Desktop::execGetFilePath },
		{ .NameUTF8 = UTF8TEXT("GetFilePathLeaf"), .Pointer = &UBPFunctions_Desktop::execGetFilePathLeaf },
		{ .NameUTF8 = UTF8TEXT("GetGPUAdapterDriverDate"), .Pointer = &UBPFunctions_Desktop::execGetGPUAdapterDriverDate },
		{ .NameUTF8 = UTF8TEXT("GetGPUAdapterInternalDriverVersion"), .Pointer = &UBPFunctions_Desktop::execGetGPUAdapterInternalDriverVersion },
		{ .NameUTF8 = UTF8TEXT("GetGPUAdapterName"), .Pointer = &UBPFunctions_Desktop::execGetGPUAdapterName },
		{ .NameUTF8 = UTF8TEXT("GetGPUAdapterUserDriverVersion"), .Pointer = &UBPFunctions_Desktop::execGetGPUAdapterUserDriverVersion },
		{ .NameUTF8 = UTF8TEXT("GetGPUBrand"), .Pointer = &UBPFunctions_Desktop::execGetGPUBrand },
		{ .NameUTF8 = UTF8TEXT("GetGPUDeviceId"), .Pointer = &UBPFunctions_Desktop::execGetGPUDeviceId },
		{ .NameUTF8 = UTF8TEXT("GetGPUDeviceRevision"), .Pointer = &UBPFunctions_Desktop::execGetGPUDeviceRevision },
		{ .NameUTF8 = UTF8TEXT("GetGPUDriverUnifiedVersion"), .Pointer = &UBPFunctions_Desktop::execGetGPUDriverUnifiedVersion },
		{ .NameUTF8 = UTF8TEXT("GetGPUHardwareInfo"), .Pointer = &UBPFunctions_Desktop::execGetGPUHardwareInfo },
		{ .NameUTF8 = UTF8TEXT("GetGPUMemoryInfo"), .Pointer = &UBPFunctions_Desktop::execGetGPUMemoryInfo },
		{ .NameUTF8 = UTF8TEXT("GetGPUProviderName"), .Pointer = &UBPFunctions_Desktop::execGetGPUProviderName },
		{ .NameUTF8 = UTF8TEXT("GetGPURHIName"), .Pointer = &UBPFunctions_Desktop::execGetGPURHIName },
		{ .NameUTF8 = UTF8TEXT("GetGPUUsage"), .Pointer = &UBPFunctions_Desktop::execGetGPUUsage },
		{ .NameUTF8 = UTF8TEXT("GetGPUVendorId"), .Pointer = &UBPFunctions_Desktop::execGetGPUVendorId },
		{ .NameUTF8 = UTF8TEXT("GetHardwareSnapshot"), .Pointer = &UBPFunctions_Desktop::execGetHardwareSnapshot },
		{ .NameUTF8 = UTF8TEXT("GetLocalAppDataDir"), .Pointer = &UBPFunctions_Desktop::execGetLocalAppDataDir },
		{ .NameUTF8 = UTF8TEXT("GetMainWindowHandleValue"), .Pointer = &UBPFunctions_Desktop::execGetMainWindowHandleValue },
		{ .NameUTF8 = UTF8TEXT("GetMainWindowInfo"), .Pointer = &UBPFunctions_Desktop::execGetMainWindowInfo },
		{ .NameUTF8 = UTF8TEXT("GetMainWindowTitle"), .Pointer = &UBPFunctions_Desktop::execGetMainWindowTitle },
		{ .NameUTF8 = UTF8TEXT("GetMemoryAvailablePhysicalBytes"), .Pointer = &UBPFunctions_Desktop::execGetMemoryAvailablePhysicalBytes },
		{ .NameUTF8 = UTF8TEXT("GetMemoryHardwareInfo"), .Pointer = &UBPFunctions_Desktop::execGetMemoryHardwareInfo },
		{ .NameUTF8 = UTF8TEXT("GetMemoryProcessUsedPhysicalBytes"), .Pointer = &UBPFunctions_Desktop::execGetMemoryProcessUsedPhysicalBytes },
		{ .NameUTF8 = UTF8TEXT("GetMemorySystemUsedPhysicalBytes"), .Pointer = &UBPFunctions_Desktop::execGetMemorySystemUsedPhysicalBytes },
		{ .NameUTF8 = UTF8TEXT("GetMemoryTotalPhysicalBytes"), .Pointer = &UBPFunctions_Desktop::execGetMemoryTotalPhysicalBytes },
		{ .NameUTF8 = UTF8TEXT("GetMonitorCount"), .Pointer = &UBPFunctions_Desktop::execGetMonitorCount },
		{ .NameUTF8 = UTF8TEXT("GetNetworkAdapterInfo"), .Pointer = &UBPFunctions_Desktop::execGetNetworkAdapterInfo },
		{ .NameUTF8 = UTF8TEXT("GetNetworkInfo"), .Pointer = &UBPFunctions_Desktop::execGetNetworkInfo },
		{ .NameUTF8 = UTF8TEXT("GetOperatingSystemId"), .Pointer = &UBPFunctions_Desktop::execGetOperatingSystemId },
		{ .NameUTF8 = UTF8TEXT("GetOSVersion"), .Pointer = &UBPFunctions_Desktop::execGetOSVersion },
		{ .NameUTF8 = UTF8TEXT("GetOSVersions"), .Pointer = &UBPFunctions_Desktop::execGetOSVersions },
		{ .NameUTF8 = UTF8TEXT("GetPluginBaseDir"), .Pointer = &UBPFunctions_Desktop::execGetPluginBaseDir },
		{ .NameUTF8 = UTF8TEXT("GetPluginBinariesDir"), .Pointer = &UBPFunctions_Desktop::execGetPluginBinariesDir },
		{ .NameUTF8 = UTF8TEXT("GetPluginContentDir"), .Pointer = &UBPFunctions_Desktop::execGetPluginContentDir },
		{ .NameUTF8 = UTF8TEXT("GetPluginExtraDir"), .Pointer = &UBPFunctions_Desktop::execGetPluginExtraDir },
		{ .NameUTF8 = UTF8TEXT("GetPluginIntermediateDir"), .Pointer = &UBPFunctions_Desktop::execGetPluginIntermediateDir },
		{ .NameUTF8 = UTF8TEXT("GetPluginResourcesDir"), .Pointer = &UBPFunctions_Desktop::execGetPluginResourcesDir },
		{ .NameUTF8 = UTF8TEXT("GetPluginSourceDir"), .Pointer = &UBPFunctions_Desktop::execGetPluginSourceDir },
		{ .NameUTF8 = UTF8TEXT("GetPowerInfo"), .Pointer = &UBPFunctions_Desktop::execGetPowerInfo },
		{ .NameUTF8 = UTF8TEXT("GetPrimaryMonitorInfo"), .Pointer = &UBPFunctions_Desktop::execGetPrimaryMonitorInfo },
		{ .NameUTF8 = UTF8TEXT("GetProcessId"), .Pointer = &UBPFunctions_Desktop::execGetProcessId },
		{ .NameUTF8 = UTF8TEXT("GetProgramDataDir"), .Pointer = &UBPFunctions_Desktop::execGetProgramDataDir },
		{ .NameUTF8 = UTF8TEXT("GetProjectDiskInfo"), .Pointer = &UBPFunctions_Desktop::execGetProjectDiskInfo },
		{ .NameUTF8 = UTF8TEXT("GetSavedGamesDir"), .Pointer = &UBPFunctions_Desktop::execGetSavedGamesDir },
		{ .NameUTF8 = UTF8TEXT("GetSaveGameDir"), .Pointer = &UBPFunctions_Desktop::execGetSaveGameDir },
		{ .NameUTF8 = UTF8TEXT("GetSystemFontBytes"), .Pointer = &UBPFunctions_Desktop::execGetSystemFontBytes },
		{ .NameUTF8 = UTF8TEXT("GetSystemPathInfo"), .Pointer = &UBPFunctions_Desktop::execGetSystemPathInfo },
		{ .NameUTF8 = UTF8TEXT("GetSystemUptimeSecond"), .Pointer = &UBPFunctions_Desktop::execGetSystemUptimeSecond },
		{ .NameUTF8 = UTF8TEXT("GetTempDir"), .Pointer = &UBPFunctions_Desktop::execGetTempDir },
		{ .NameUTF8 = UTF8TEXT("GetTimeStamp"), .Pointer = &UBPFunctions_Desktop::execGetTimeStamp },
		{ .NameUTF8 = UTF8TEXT("GetWindowDebugReport"), .Pointer = &UBPFunctions_Desktop::execGetWindowDebugReport },
		{ .NameUTF8 = UTF8TEXT("GetWindowMode"), .Pointer = &UBPFunctions_Desktop::execGetWindowMode },
		{ .NameUTF8 = UTF8TEXT("IsDrive"), .Pointer = &UBPFunctions_Desktop::execIsDrive },
		{ .NameUTF8 = UTF8TEXT("IsFileReadOnly"), .Pointer = &UBPFunctions_Desktop::execIsFileReadOnly },
		{ .NameUTF8 = UTF8TEXT("IsLaptopDevice"), .Pointer = &UBPFunctions_Desktop::execIsLaptopDevice },
		{ .NameUTF8 = UTF8TEXT("IsMainWindowActive"), .Pointer = &UBPFunctions_Desktop::execIsMainWindowActive },
		{ .NameUTF8 = UTF8TEXT("IsMainWindowMaximized"), .Pointer = &UBPFunctions_Desktop::execIsMainWindowMaximized },
		{ .NameUTF8 = UTF8TEXT("IsMainWindowMinimized"), .Pointer = &UBPFunctions_Desktop::execIsMainWindowMinimized },
		{ .NameUTF8 = UTF8TEXT("IsMainWindowValid"), .Pointer = &UBPFunctions_Desktop::execIsMainWindowValid },
		{ .NameUTF8 = UTF8TEXT("IsRelative"), .Pointer = &UBPFunctions_Desktop::execIsRelative },
		{ .NameUTF8 = UTF8TEXT("IsRunningAsAdministrator"), .Pointer = &UBPFunctions_Desktop::execIsRunningAsAdministrator },
		{ .NameUTF8 = UTF8TEXT("IsRunningOnBattery"), .Pointer = &UBPFunctions_Desktop::execIsRunningOnBattery },
		{ .NameUTF8 = UTF8TEXT("IsScreenCaptureDisabled"), .Pointer = &UBPFunctions_Desktop::execIsScreenCaptureDisabled },
		{ .NameUTF8 = UTF8TEXT("IsUnderDirectory"), .Pointer = &UBPFunctions_Desktop::execIsUnderDirectory },
		{ .NameUTF8 = UTF8TEXT("LaunchUrl"), .Pointer = &UBPFunctions_Desktop::execLaunchUrl },
		{ .NameUTF8 = UTF8TEXT("LoadImageFromDialog"), .Pointer = &UBPFunctions_Desktop::execLoadImageFromDialog },
		{ .NameUTF8 = UTF8TEXT("LoadImageFromFile"), .Pointer = &UBPFunctions_Desktop::execLoadImageFromFile },
		{ .NameUTF8 = UTF8TEXT("MakeValidFileName"), .Pointer = &UBPFunctions_Desktop::execMakeValidFileName },
		{ .NameUTF8 = UTF8TEXT("MaximizeMainWindow"), .Pointer = &UBPFunctions_Desktop::execMaximizeMainWindow },
		{ .NameUTF8 = UTF8TEXT("MinimizeMainWindow"), .Pointer = &UBPFunctions_Desktop::execMinimizeMainWindow },
		{ .NameUTF8 = UTF8TEXT("MoveFile"), .Pointer = &UBPFunctions_Desktop::execMoveFile },
		{ .NameUTF8 = UTF8TEXT("MoveMainWindow"), .Pointer = &UBPFunctions_Desktop::execMoveMainWindow },
		{ .NameUTF8 = UTF8TEXT("NormalizeDirectory"), .Pointer = &UBPFunctions_Desktop::execNormalizeDirectory },
		{ .NameUTF8 = UTF8TEXT("NormalizeFileName"), .Pointer = &UBPFunctions_Desktop::execNormalizeFileName },
		{ .NameUTF8 = UTF8TEXT("OpenDirectoryDialog"), .Pointer = &UBPFunctions_Desktop::execOpenDirectoryDialog },
		{ .NameUTF8 = UTF8TEXT("OpenDirectoryInShell"), .Pointer = &UBPFunctions_Desktop::execOpenDirectoryInShell },
		{ .NameUTF8 = UTF8TEXT("OpenFileDialog"), .Pointer = &UBPFunctions_Desktop::execOpenFileDialog },
		{ .NameUTF8 = UTF8TEXT("OpenFileInShell"), .Pointer = &UBPFunctions_Desktop::execOpenFileInShell },
		{ .NameUTF8 = UTF8TEXT("ReadBytesFromFile"), .Pointer = &UBPFunctions_Desktop::execReadBytesFromFile },
		{ .NameUTF8 = UTF8TEXT("ReadStringFromFile"), .Pointer = &UBPFunctions_Desktop::execReadStringFromFile },
		{ .NameUTF8 = UTF8TEXT("RequestMinimizeApplication"), .Pointer = &UBPFunctions_Desktop::execRequestMinimizeApplication },
		{ .NameUTF8 = UTF8TEXT("ResizeMainWindow"), .Pointer = &UBPFunctions_Desktop::execResizeMainWindow },
		{ .NameUTF8 = UTF8TEXT("RestartApplication"), .Pointer = &UBPFunctions_Desktop::execRestartApplication },
		{ .NameUTF8 = UTF8TEXT("RestoreMainWindow"), .Pointer = &UBPFunctions_Desktop::execRestoreMainWindow },
		{ .NameUTF8 = UTF8TEXT("RevealFileInExplorer"), .Pointer = &UBPFunctions_Desktop::execRevealFileInExplorer },
		{ .NameUTF8 = UTF8TEXT("SaveBytesToFile"), .Pointer = &UBPFunctions_Desktop::execSaveBytesToFile },
		{ .NameUTF8 = UTF8TEXT("SaveFileDialog"), .Pointer = &UBPFunctions_Desktop::execSaveFileDialog },
		{ .NameUTF8 = UTF8TEXT("SetClipboardText"), .Pointer = &UBPFunctions_Desktop::execSetClipboardText },
		{ .NameUTF8 = UTF8TEXT("SetFileExtension"), .Pointer = &UBPFunctions_Desktop::execSetFileExtension },
		{ .NameUTF8 = UTF8TEXT("SetMainWindowTitle"), .Pointer = &UBPFunctions_Desktop::execSetMainWindowTitle },
		{ .NameUTF8 = UTF8TEXT("SetMainWindowTopMost"), .Pointer = &UBPFunctions_Desktop::execSetMainWindowTopMost },
		{ .NameUTF8 = UTF8TEXT("SetScreenCaptureDisabled"), .Pointer = &UBPFunctions_Desktop::execSetScreenCaptureDisabled },
		{ .NameUTF8 = UTF8TEXT("SetWindowMode"), .Pointer = &UBPFunctions_Desktop::execSetWindowMode },
		{ .NameUTF8 = UTF8TEXT("StringToBase64String"), .Pointer = &UBPFunctions_Desktop::execStringToBase64String },
		{ .NameUTF8 = UTF8TEXT("Test_CPUInfo"), .Pointer = &UBPFunctions_Desktop::execTest_CPUInfo },
		{ .NameUTF8 = UTF8TEXT("Test_GPUInfo"), .Pointer = &UBPFunctions_Desktop::execTest_GPUInfo },
		{ .NameUTF8 = UTF8TEXT("WriteStringToFile"), .Pointer = &UBPFunctions_Desktop::execWriteStringToFile },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_AddBytesToFile, "AddBytesToFile" }, // 3804705393
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToBytes, "Base64StringToBytes" }, // 3718247600
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_Base64StringToString, "Base64StringToString" }, // 1781956456
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_BringMainWindowToFront, "BringMainWindowToFront" }, // 3386464468
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_BytesToBase64String, "BytesToBase64String" }, // 1707584390
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_CanLaunchUrl, "CanLaunchUrl" }, // 339865882
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_ConvBytesToTexture2D, "ConvBytesToTexture2D" }, // 3665885039
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToFullPath, "ConvertToFullPath" }, // 1215662973
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_ConvertToRelativePath, "ConvertToRelativePath" }, // 3439530969
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_ConvTexture2DToBytes, "ConvTexture2DToBytes" }, // 3847118473
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_CopyFile, "CopyFile" }, // 2887618662
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_CreateDirectory, "CreateDirectory" }, // 3172725561
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectory, "DeleteDirectory" }, // 1631953456
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_DeleteDirectoryRecursively, "DeleteDirectoryRecursively" }, // 400197954
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_DeleteFile, "DeleteFile" }, // 1092073110
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_ExistDirectory, "ExistDirectory" }, // 4211916515
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_ExistFile, "ExistFile" }, // 3875854223
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_FileSize, "FileSize" }, // 285307785
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectory, "FindDirectory" }, // 1128823228
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_FindDirectoryRecursive, "FindDirectoryRecursive" }, // 3140782530
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_FindFile, "FindFile" }, // 3199916894
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_FindFileRecursive, "FindFileRecursive" }, // 1793880152
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_FlashMainWindow, "FlashMainWindow" }, // 3840478091
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetAllDiskInfos, "GetAllDiskInfos" }, // 2872108352
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetAllMonitorInfos, "GetAllMonitorInfos" }, // 1499128338
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetAppDataDir, "GetAppDataDir" }, // 563467523
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetApplicationInfo, "GetApplicationInfo" }, // 1257135454
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetBaseFilename, "GetBaseFilename" }, // 2803838816
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetBatteryPercent, "GetBatteryPercent" }, // 739541949
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCleanFilename, "GetCleanFilename" }, // 3001857113
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetClipboardText, "GetClipboardText" }, // 4191543268
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCommandLineString, "GetCommandLineString" }, // 987198790
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUBrand, "GetCPUBrand" }, // 2951577816
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUChipset, "GetCPUChipset" }, // 3046092617
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUCores, "GetCPUCores" }, // 2492652867
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUFrequency, "GetCPUFrequency" }, // 4056779937
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUHardwareInfo, "GetCPUHardwareInfo" }, // 1582687931
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPULogicalCores, "GetCPULogicalCores" }, // 3559015132
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUPhysicalCores, "GetCPUPhysicalCores" }, // 4277398175
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUProcessCount, "GetCPUProcessCount" }, // 1847834910
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUThreadCount, "GetCPUThreadCount" }, // 3252479076
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUUsage, "GetCPUUsage" }, // 1052503049
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCPUVendor, "GetCPUVendor" }, // 978999154
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetCurrentMonitorInfo, "GetCurrentMonitorInfo" }, // 3953030186
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopBaseDir, "GetDesktopBaseDir" }, // 3791842342
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopDir, "GetDesktopDir" }, // 1906631479
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopName, "GetDesktopName" }, // 3650520240
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserDir, "GetDesktopUserDir" }, // 2456779683
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserHomeDir, "GetDesktopUserHomeDir" }, // 3188002346
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserName, "GetDesktopUserName" }, // 1158769576
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDesktopUserTempDir, "GetDesktopUserTempDir" }, // 864918291
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDeviceID, "GetDeviceID" }, // 2235251728
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskFreeBytes, "GetDiskFreeBytes" }, // 1252124857
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskInfo, "GetDiskInfo" }, // 3451390142
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskTotalBytes, "GetDiskTotalBytes" }, // 1760124553
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDiskUsedBytes, "GetDiskUsedBytes" }, // 2411454883
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDisplayInfo, "GetDisplayInfo" }, // 1780069976
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDocumentsDir, "GetDocumentsDir" }, // 1301715237
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetDownloadsDir, "GetDownloadsDir" }, // 164531584
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetEnvironmentVariable, "GetEnvironmentVariable" }, // 1564953194
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetExecutablePath, "GetExecutablePath" }, // 2631255382
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetExtrasDir, "GetExtrasDir" }, // 4283799591
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetFileExtension, "GetFileExtension" }, // 139678286
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePath, "GetFilePath" }, // 3826619729
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetFilePathLeaf, "GetFilePathLeaf" }, // 1978543111
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterDriverDate, "GetGPUAdapterDriverDate" }, // 3272931547
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterInternalDriverVersion, "GetGPUAdapterInternalDriverVersion" }, // 3844048068
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterName, "GetGPUAdapterName" }, // 135402455
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUAdapterUserDriverVersion, "GetGPUAdapterUserDriverVersion" }, // 2759822419
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUBrand, "GetGPUBrand" }, // 133139801
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceId, "GetGPUDeviceId" }, // 1474255835
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDeviceRevision, "GetGPUDeviceRevision" }, // 3100129318
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUDriverUnifiedVersion, "GetGPUDriverUnifiedVersion" }, // 3964849506
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUHardwareInfo, "GetGPUHardwareInfo" }, // 2520405666
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUMemoryInfo, "GetGPUMemoryInfo" }, // 1151006747
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUProviderName, "GetGPUProviderName" }, // 3774060899
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPURHIName, "GetGPURHIName" }, // 499765572
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUUsage, "GetGPUUsage" }, // 726345956
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetGPUVendorId, "GetGPUVendorId" }, // 3068983272
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetHardwareSnapshot, "GetHardwareSnapshot" }, // 3914460097
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetLocalAppDataDir, "GetLocalAppDataDir" }, // 670144820
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowHandleValue, "GetMainWindowHandleValue" }, // 235558420
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowInfo, "GetMainWindowInfo" }, // 166078067
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetMainWindowTitle, "GetMainWindowTitle" }, // 2049075715
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryAvailablePhysicalBytes, "GetMemoryAvailablePhysicalBytes" }, // 3691134133
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryHardwareInfo, "GetMemoryHardwareInfo" }, // 3952798917
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryProcessUsedPhysicalBytes, "GetMemoryProcessUsedPhysicalBytes" }, // 2636020013
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetMemorySystemUsedPhysicalBytes, "GetMemorySystemUsedPhysicalBytes" }, // 394414236
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetMemoryTotalPhysicalBytes, "GetMemoryTotalPhysicalBytes" }, // 179069610
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetMonitorCount, "GetMonitorCount" }, // 917478080
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkAdapterInfo, "GetNetworkAdapterInfo" }, // 1934459616
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetNetworkInfo, "GetNetworkInfo" }, // 764884610
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetOperatingSystemId, "GetOperatingSystemId" }, // 161762955
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersion, "GetOSVersion" }, // 3804084805
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetOSVersions, "GetOSVersions" }, // 1929852878
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBaseDir, "GetPluginBaseDir" }, // 2076636472
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginBinariesDir, "GetPluginBinariesDir" }, // 3640277109
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginContentDir, "GetPluginContentDir" }, // 1601148394
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginExtraDir, "GetPluginExtraDir" }, // 579618959
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginIntermediateDir, "GetPluginIntermediateDir" }, // 1057883098
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginResourcesDir, "GetPluginResourcesDir" }, // 528047475
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetPluginSourceDir, "GetPluginSourceDir" }, // 2751375302
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetPowerInfo, "GetPowerInfo" }, // 1271747322
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetPrimaryMonitorInfo, "GetPrimaryMonitorInfo" }, // 3320769692
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetProcessId, "GetProcessId" }, // 1453138623
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetProgramDataDir, "GetProgramDataDir" }, // 3052471004
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetProjectDiskInfo, "GetProjectDiskInfo" }, // 503132823
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetSavedGamesDir, "GetSavedGamesDir" }, // 2933825867
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetSaveGameDir, "GetSaveGameDir" }, // 599896774
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemFontBytes, "GetSystemFontBytes" }, // 471205258
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemPathInfo, "GetSystemPathInfo" }, // 1407021684
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetSystemUptimeSecond, "GetSystemUptimeSecond" }, // 1861356705
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetTempDir, "GetTempDir" }, // 4151751944
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetTimeStamp, "GetTimeStamp" }, // 119976231
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowDebugReport, "GetWindowDebugReport" }, // 2685055478
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_GetWindowMode, "GetWindowMode" }, // 2233122568
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsDrive, "IsDrive" }, // 488848003
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsFileReadOnly, "IsFileReadOnly" }, // 367105750
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsLaptopDevice, "IsLaptopDevice" }, // 1042049592
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowActive, "IsMainWindowActive" }, // 2882278864
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMaximized, "IsMainWindowMaximized" }, // 3948652085
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowMinimized, "IsMainWindowMinimized" }, // 651828273
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsMainWindowValid, "IsMainWindowValid" }, // 3779392773
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsRelative, "IsRelative" }, // 309025552
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningAsAdministrator, "IsRunningAsAdministrator" }, // 2054137225
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsRunningOnBattery, "IsRunningOnBattery" }, // 3386250099
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsScreenCaptureDisabled, "IsScreenCaptureDisabled" }, // 1063823185
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_IsUnderDirectory, "IsUnderDirectory" }, // 2511193773
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_LaunchUrl, "LaunchUrl" }, // 76947841
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromDialog, "LoadImageFromDialog" }, // 1091398726
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_LoadImageFromFile, "LoadImageFromFile" }, // 1699878953
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_MakeValidFileName, "MakeValidFileName" }, // 1837469880
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_MaximizeMainWindow, "MaximizeMainWindow" }, // 1962384875
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_MinimizeMainWindow, "MinimizeMainWindow" }, // 2666669575
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_MoveFile, "MoveFile" }, // 2863168685
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_MoveMainWindow, "MoveMainWindow" }, // 1472695906
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeDirectory, "NormalizeDirectory" }, // 2102241246
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_NormalizeFileName, "NormalizeFileName" }, // 4131076012
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryDialog, "OpenDirectoryDialog" }, // 1717220807
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_OpenDirectoryInShell, "OpenDirectoryInShell" }, // 983393263
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileDialog, "OpenFileDialog" }, // 2329202987
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_OpenFileInShell, "OpenFileInShell" }, // 2320296326
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_ReadBytesFromFile, "ReadBytesFromFile" }, // 862455322
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_ReadStringFromFile, "ReadStringFromFile" }, // 4213161606
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_RequestMinimizeApplication, "RequestMinimizeApplication" }, // 3531497390
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_ResizeMainWindow, "ResizeMainWindow" }, // 1213360212
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_RestartApplication, "RestartApplication" }, // 3693769152
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_RestoreMainWindow, "RestoreMainWindow" }, // 1409502713
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_RevealFileInExplorer, "RevealFileInExplorer" }, // 413897329
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_SaveBytesToFile, "SaveBytesToFile" }, // 2571169867
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_SaveFileDialog, "SaveFileDialog" }, // 2270945908
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_SetClipboardText, "SetClipboardText" }, // 1194784448
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_SetFileExtension, "SetFileExtension" }, // 4231259058
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTitle, "SetMainWindowTitle" }, // 4098750172
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_SetMainWindowTopMost, "SetMainWindowTopMost" }, // 3196263428
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_SetScreenCaptureDisabled, "SetScreenCaptureDisabled" }, // 3040229259
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_SetWindowMode, "SetWindowMode" }, // 3676597046
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_StringToBase64String, "StringToBase64String" }, // 3541997662
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_Test_CPUInfo, "Test_CPUInfo" }, // 2735122692
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_Test_GPUInfo, "Test_GPUInfo" }, // 2743737173
		{ &Z_Construct_UFunction_UBPFunctions_Desktop_WriteStringToFile, "WriteStringToFile" }, // 130750159
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctions_Desktop>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBPFunctions_Desktop_Statics
UObject* (*const Z_Construct_UClass_UBPFunctions_Desktop_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericDesktopFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Desktop_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctions_Desktop_Statics::ClassParams = {
	&UBPFunctions_Desktop::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Desktop_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPFunctions_Desktop_Statics::Class_MetaDataParams)
};
void UBPFunctions_Desktop::StaticRegisterNativesUBPFunctions_Desktop()
{
	UClass* Class = UBPFunctions_Desktop::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UBPFunctions_Desktop_Statics::Funcs));
}
UClass* Z_Construct_UClass_UBPFunctions_Desktop()
{
	if (!Z_Registration_Info_UClass_UBPFunctions_Desktop.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPFunctions_Desktop.OuterSingleton, Z_Construct_UClass_UBPFunctions_Desktop_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPFunctions_Desktop.OuterSingleton;
}
UBPFunctions_Desktop::UBPFunctions_Desktop(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBPFunctions_Desktop);
UBPFunctions_Desktop::~UBPFunctions_Desktop() {}
// ********** End Class UBPFunctions_Desktop *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h__Script_GenericDesktopFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPFunctions_Desktop, UBPFunctions_Desktop::StaticClass, TEXT("UBPFunctions_Desktop"), &Z_Registration_Info_UClass_UBPFunctions_Desktop, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPFunctions_Desktop), 660872221U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h__Script_GenericDesktopFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h__Script_GenericDesktopFramework_4022617299{
	TEXT("/Script/GenericDesktopFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h__Script_GenericDesktopFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_BPFunctions_BPFunctions_Desktop_h__Script_GenericDesktopFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
