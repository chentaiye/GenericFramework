// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystem/GenericVersionDataSubsystem.h"
#include "Engine/GameInstance.h"
#include "GameplayTagContainer.h"
#include "Types/GenericVersionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericVersionDataSubsystem() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericGameInstanceSubsystem();
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionDataSubsystem();
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionDataSubsystem_NoRegister();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionData();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionDefinition();
UPackage* Z_Construct_UPackage__Script_GenericVersionFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericVersionDataSubsystem Function ClearVersionData *******************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb8\x85\xe7\xa9\xba\xe4\xb8\xad\xe5\xbf\x83\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe7\xbc\x93\xe5\xad\x98\xef\xbc\x8c\xe4\xb8\x8d\xe4\xbc\x9a\xe6\xb8\x85\xe7\xa9\xba\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb8\x85\xe7\xa9\xba\xe4\xb8\xad\xe5\xbf\x83\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe7\xbc\x93\xe5\xad\x98\xef\xbc\x8c\xe4\xb8\x8d\xe4\xbc\x9a\xe6\xb8\x85\xe7\xa9\xba\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ClearVersionData constinit property declarations **********************
// ********** End Function ClearVersionData constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "ClearVersionData", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionData_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execClearVersionData)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearVersionData();
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function ClearVersionData *********************

// ********** Begin Class UGenericVersionDataSubsystem Function ClearVersionDefinitions ************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionDefinitions_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb8\x85\xe7\xa9\xba\xe6\x89\x80\xe6\x9c\x89\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe4\xb8\x8d\xe4\xbc\x9a\xe5\x88\xa0\xe9\x99\xa4\xe5\xb7\xb2\xe7\xbb\x8f\xe7\xbc\x93\xe5\xad\x98\xe7\x9a\x84\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb8\x85\xe7\xa9\xba\xe6\x89\x80\xe6\x9c\x89\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe4\xb8\x8d\xe4\xbc\x9a\xe5\x88\xa0\xe9\x99\xa4\xe5\xb7\xb2\xe7\xbb\x8f\xe7\xbc\x93\xe5\xad\x98\xe7\x9a\x84\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function ClearVersionDefinitions constinit property declarations ***************
// ********** End Function ClearVersionDefinitions constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionDefinitions_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "ClearVersionDefinitions", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionDefinitions_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionDefinitions_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionDefinitions()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionDefinitions_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execClearVersionDefinitions)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ClearVersionDefinitions();
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function ClearVersionDefinitions **************

// ********** Begin Class UGenericVersionDataSubsystem Function GetVersionData *********************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics
{
	struct GenericVersionDataSubsystem_eventGetVersionData_Parms
	{
		UObject* TargetObject;
		FGenericVersionData OutVersionData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x8c\x87\xe5\xae\x9a\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xbd\x93\xe5\x89\x8d\xe7\xbc\x93\xe5\xad\x98\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe5\xbf\xab\xe7\x85\xa7\xef\xbc\x8c\xe4\xb8\x8d\xe4\xbc\x9a\xe4\xb8\xbb\xe5\x8a\xa8\xe8\xb0\x83\xe7\x94\xa8\xe5\xaf\xb9\xe8\xb1\xa1\xe6\x8e\xa5\xe5\x8f\xa3\xe5\x88\xb7\xe6\x96\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x8c\x87\xe5\xae\x9a\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xbd\x93\xe5\x89\x8d\xe7\xbc\x93\xe5\xad\x98\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe5\xbf\xab\xe7\x85\xa7\xef\xbc\x8c\xe4\xb8\x8d\xe4\xbc\x9a\xe4\xb8\xbb\xe5\x8a\xa8\xe8\xb0\x83\xe7\x94\xa8\xe5\xaf\xb9\xe8\xb1\xa1\xe6\x8e\xa5\xe5\x8f\xa3\xe5\x88\xb7\xe6\x96\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetVersionData constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutVersionData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVersionData constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVersionData Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::NewProp_TargetObject = { "TargetObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventGetVersionData_Parms, TargetObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::NewProp_OutVersionData = { "OutVersionData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventGetVersionData_Parms, OutVersionData), Z_Construct_UScriptStruct_FGenericVersionData, METADATA_PARAMS(0, nullptr) }; // 477485717
void Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericVersionDataSubsystem_eventGetVersionData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericVersionDataSubsystem_eventGetVersionData_Parms), &Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::NewProp_TargetObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::NewProp_OutVersionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::PropPointers) < 2048);
// ********** End Function GetVersionData Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "GetVersionData", 	Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::GenericVersionDataSubsystem_eventGetVersionData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::GenericVersionDataSubsystem_eventGetVersionData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execGetVersionData)
{
	P_GET_OBJECT(UObject,Z_Param_TargetObject);
	P_GET_STRUCT_REF(FGenericVersionData,Z_Param_Out_OutVersionData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetVersionData(Z_Param_TargetObject,Z_Param_Out_OutVersionData);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function GetVersionData ***********************

// ********** Begin Class UGenericVersionDataSubsystem Function GetVersionDefinition ***************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics
{
	struct GenericVersionDataSubsystem_eventGetVersionDefinition_Parms
	{
		FGameplayTag VersionKey;
		FGenericVersionDefinition OutVersionDefinition;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe4\xb8\x8d\xe4\xbc\x9a\xe8\xaf\xbb\xe5\x8f\x96\xe6\x88\x96\xe5\x88\xb7\xe6\x96\xb0\xe4\xbb\xbb\xe4\xbd\x95\xe5\x85\xb7\xe4\xbd\x93\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xaf\xb9\xe8\xb1\xa1\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe4\xb8\x8d\xe4\xbc\x9a\xe8\xaf\xbb\xe5\x8f\x96\xe6\x88\x96\xe5\x88\xb7\xe6\x96\xb0\xe4\xbb\xbb\xe4\xbd\x95\xe5\x85\xb7\xe4\xbd\x93\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xaf\xb9\xe8\xb1\xa1\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetVersionDefinition constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutVersionDefinition;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetVersionDefinition constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetVersionDefinition Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::NewProp_VersionKey = { "VersionKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventGetVersionDefinition_Parms, VersionKey), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::NewProp_OutVersionDefinition = { "OutVersionDefinition", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventGetVersionDefinition_Parms, OutVersionDefinition), Z_Construct_UScriptStruct_FGenericVersionDefinition, METADATA_PARAMS(0, nullptr) }; // 144404518
void Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericVersionDataSubsystem_eventGetVersionDefinition_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericVersionDataSubsystem_eventGetVersionDefinition_Parms), &Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::NewProp_VersionKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::NewProp_OutVersionDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::PropPointers) < 2048);
// ********** End Function GetVersionDefinition Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "GetVersionDefinition", 	Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::GenericVersionDataSubsystem_eventGetVersionDefinition_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::GenericVersionDataSubsystem_eventGetVersionDefinition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execGetVersionDefinition)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_VersionKey);
	P_GET_STRUCT_REF(FGenericVersionDefinition,Z_Param_Out_OutVersionDefinition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->GetVersionDefinition(Z_Param_VersionKey,Z_Param_Out_OutVersionDefinition);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function GetVersionDefinition *****************

// ********** Begin Class UGenericVersionDataSubsystem Function RefreshVersionData *****************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics
{
	struct GenericVersionDataSubsystem_eventRefreshVersionData_Parms
	{
		UObject* TargetObject;
		FGenericVersionData VersionData;
		FGenericVersionData OutVersionData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x86\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe4\xbc\xa0\xe5\x85\xa5\xe7\x9a\x84\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xe5\x86\x99\xe5\x85\xa5\xe4\xb8\xad\xe5\xbf\x83\xe7\xbc\x93\xe5\xad\x98\xef\xbc\x9b\xe5\x86\x99\xe5\x85\xa5\xe5\x89\x8d\xe4\xbc\x9a\xe5\x85\x88\xe4\xb8\x8e\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe5\x90\x88\xe5\xb9\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x86\xe8\xb0\x83\xe7\x94\xa8\xe6\x96\xb9\xe4\xbc\xa0\xe5\x85\xa5\xe7\x9a\x84\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xe5\x86\x99\xe5\x85\xa5\xe4\xb8\xad\xe5\xbf\x83\xe7\xbc\x93\xe5\xad\x98\xef\xbc\x9b\xe5\x86\x99\xe5\x85\xa5\xe5\x89\x8d\xe4\xbc\x9a\xe5\x85\x88\xe4\xb8\x8e\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe5\x90\x88\xe5\xb9\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshVersionData constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutVersionData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RefreshVersionData constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RefreshVersionData Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::NewProp_TargetObject = { "TargetObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventRefreshVersionData_Parms, TargetObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::NewProp_VersionData = { "VersionData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventRefreshVersionData_Parms, VersionData), Z_Construct_UScriptStruct_FGenericVersionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionData_MetaData), NewProp_VersionData_MetaData) }; // 477485717
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::NewProp_OutVersionData = { "OutVersionData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventRefreshVersionData_Parms, OutVersionData), Z_Construct_UScriptStruct_FGenericVersionData, METADATA_PARAMS(0, nullptr) }; // 477485717
void Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericVersionDataSubsystem_eventRefreshVersionData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericVersionDataSubsystem_eventRefreshVersionData_Parms), &Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::NewProp_TargetObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::NewProp_VersionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::NewProp_OutVersionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::PropPointers) < 2048);
// ********** End Function RefreshVersionData Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "RefreshVersionData", 	Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::GenericVersionDataSubsystem_eventRefreshVersionData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::GenericVersionDataSubsystem_eventRefreshVersionData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execRefreshVersionData)
{
	P_GET_OBJECT(UObject,Z_Param_TargetObject);
	P_GET_STRUCT_REF(FGenericVersionData,Z_Param_Out_VersionData);
	P_GET_STRUCT_REF(FGenericVersionData,Z_Param_Out_OutVersionData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RefreshVersionData(Z_Param_TargetObject,Z_Param_Out_VersionData,Z_Param_Out_OutVersionData);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function RefreshVersionData *******************

// ********** Begin Class UGenericVersionDataSubsystem Function RegisterVersionDefinitionsFromSettings 
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics
{
	struct GenericVersionDataSubsystem_eventRegisterVersionDefinitionsFromSettings_Parms
	{
		int32 ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbb\x8e\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae\xe8\xaf\xbb\xe5\x8f\x96\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe5\xb9\xb6\xe6\xb3\xa8\xe5\x86\x8c\xe5\x88\xb0\xe4\xb8\xad\xe5\xbf\x83\xe8\xa1\xa8\xef\xbc\x8c\xe5\xb7\xb2\xe5\xad\x98\xe5\x9c\xa8\xe7\x9a\x84 VersionKey \xe4\xbc\x9a\xe8\xa2\xab\xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\xae\x9a\xe4\xb9\x89\xe8\xa6\x86\xe7\x9b\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x8e\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae\xe8\xaf\xbb\xe5\x8f\x96\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe5\xb9\xb6\xe6\xb3\xa8\xe5\x86\x8c\xe5\x88\xb0\xe4\xb8\xad\xe5\xbf\x83\xe8\xa1\xa8\xef\xbc\x8c\xe5\xb7\xb2\xe5\xad\x98\xe5\x9c\xa8\xe7\x9a\x84 VersionKey \xe4\xbc\x9a\xe8\xa2\xab\xe8\xae\xbe\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\xae\x9a\xe4\xb9\x89\xe8\xa6\x86\xe7\x9b\x96\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RegisterVersionDefinitionsFromSettings constinit property declarations 
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RegisterVersionDefinitionsFromSettings constinit property declarations **
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RegisterVersionDefinitionsFromSettings Property Definitions ***********
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventRegisterVersionDefinitionsFromSettings_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::PropPointers) < 2048);
// ********** End Function RegisterVersionDefinitionsFromSettings Property Definitions *************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "RegisterVersionDefinitionsFromSettings", 	Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::GenericVersionDataSubsystem_eventRegisterVersionDefinitionsFromSettings_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::GenericVersionDataSubsystem_eventRegisterVersionDefinitionsFromSettings_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execRegisterVersionDefinitionsFromSettings)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(int32*)Z_Param__Result=P_THIS->RegisterVersionDefinitionsFromSettings();
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function RegisterVersionDefinitionsFromSettings 

// ********** Begin Class UGenericVersionDataSubsystem Function RemoveVersionData ******************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics
{
	struct GenericVersionDataSubsystem_eventRemoveVersionData_Parms
	{
		UObject* TargetObject;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe7\xbc\x93\xe5\xad\x98\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe7\xbc\x93\xe5\xad\x98\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveVersionData constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetObject;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveVersionData constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveVersionData Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::NewProp_TargetObject = { "TargetObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventRemoveVersionData_Parms, TargetObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericVersionDataSubsystem_eventRemoveVersionData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericVersionDataSubsystem_eventRemoveVersionData_Parms), &Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::NewProp_TargetObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::PropPointers) < 2048);
// ********** End Function RemoveVersionData Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "RemoveVersionData", 	Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::GenericVersionDataSubsystem_eventRemoveVersionData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::GenericVersionDataSubsystem_eventRemoveVersionData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execRemoveVersionData)
{
	P_GET_OBJECT(UObject,Z_Param_TargetObject);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RemoveVersionData(Z_Param_TargetObject);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function RemoveVersionData ********************

// ********** Begin Class UGenericVersionDataSubsystem Function RemoveVersionDataByKey *************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics
{
	struct GenericVersionDataSubsystem_eventRemoveVersionDataByKey_Parms
	{
		FGameplayTag VersionKey;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe7\x89\x88\xe6\x9c\xac\xe9\x94\xae\xe5\xaf\xb9\xe5\xba\x94\xe7\x9a\x84\xe6\x89\x80\xe6\x9c\x89\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe7\xbc\x93\xe5\xad\x98\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe7\x89\x88\xe6\x9c\xac\xe9\x94\xae\xe5\xaf\xb9\xe5\xba\x94\xe7\x9a\x84\xe6\x89\x80\xe6\x9c\x89\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe7\xbc\x93\xe5\xad\x98\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveVersionDataByKey constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionKey;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveVersionDataByKey constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveVersionDataByKey Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::NewProp_VersionKey = { "VersionKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventRemoveVersionDataByKey_Parms, VersionKey), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericVersionDataSubsystem_eventRemoveVersionDataByKey_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericVersionDataSubsystem_eventRemoveVersionDataByKey_Parms), &Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::NewProp_VersionKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::PropPointers) < 2048);
// ********** End Function RemoveVersionDataByKey Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "RemoveVersionDataByKey", 	Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::GenericVersionDataSubsystem_eventRemoveVersionDataByKey_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::GenericVersionDataSubsystem_eventRemoveVersionDataByKey_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execRemoveVersionDataByKey)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_VersionKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RemoveVersionDataByKey(Z_Param_VersionKey);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function RemoveVersionDataByKey ***************

// ********** Begin Class UGenericVersionDataSubsystem Function RemoveVersionDefinition ************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics
{
	struct GenericVersionDataSubsystem_eventRemoveVersionDefinition_Parms
	{
		FGameplayTag VersionKey;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe7\x89\x88\xe6\x9c\xac\xe9\x94\xae\xe7\x9a\x84\xe4\xb8\xad\xe5\xa4\xae\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe4\xb8\x8d\xe4\xbc\x9a\xe5\x88\xa0\xe9\x99\xa4\xe5\xb7\xb2\xe7\xbb\x8f\xe7\xbc\x93\xe5\xad\x98\xe7\x9a\x84\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xa7\xbb\xe9\x99\xa4\xe6\x8c\x87\xe5\xae\x9a\xe7\x89\x88\xe6\x9c\xac\xe9\x94\xae\xe7\x9a\x84\xe4\xb8\xad\xe5\xa4\xae\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe4\xb8\x8d\xe4\xbc\x9a\xe5\x88\xa0\xe9\x99\xa4\xe5\xb7\xb2\xe7\xbb\x8f\xe7\xbc\x93\xe5\xad\x98\xe7\x9a\x84\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function RemoveVersionDefinition constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionKey;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function RemoveVersionDefinition constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function RemoveVersionDefinition Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::NewProp_VersionKey = { "VersionKey", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventRemoveVersionDefinition_Parms, VersionKey), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericVersionDataSubsystem_eventRemoveVersionDefinition_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericVersionDataSubsystem_eventRemoveVersionDefinition_Parms), &Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::NewProp_VersionKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::PropPointers) < 2048);
// ********** End Function RemoveVersionDefinition Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "RemoveVersionDefinition", 	Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::GenericVersionDataSubsystem_eventRemoveVersionDefinition_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::GenericVersionDataSubsystem_eventRemoveVersionDefinition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execRemoveVersionDefinition)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_VersionKey);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->RemoveVersionDefinition(Z_Param_VersionKey);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function RemoveVersionDefinition **************

// ********** Begin Class UGenericVersionDataSubsystem Function ResolveVersionData *****************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics
{
	struct GenericVersionDataSubsystem_eventResolveVersionData_Parms
	{
		FGenericVersionData SourceVersionData;
		FGenericVersionData OutVersionData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\xa1\xe9\xaa\x8c\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xe6\x98\xaf\xe5\x90\xa6\xe8\x83\xbd\xe5\x9c\xa8\xe4\xb8\xad\xe5\xa4\xae\xe5\xae\x9a\xe4\xb9\x89\xe8\xa1\xa8\xe4\xb8\xad\xe6\x89\xbe\xe5\x88\xb0\xe5\xaf\xb9\xe5\xba\x94\xe7\x89\x88\xe6\x9c\xac\xe7\xad\x96\xe7\x95\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\xa1\xe9\xaa\x8c\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xe6\x98\xaf\xe5\x90\xa6\xe8\x83\xbd\xe5\x9c\xa8\xe4\xb8\xad\xe5\xa4\xae\xe5\xae\x9a\xe4\xb9\x89\xe8\xa1\xa8\xe4\xb8\xad\xe6\x89\xbe\xe5\x88\xb0\xe5\xaf\xb9\xe5\xba\x94\xe7\x89\x88\xe6\x9c\xac\xe7\xad\x96\xe7\x95\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceVersionData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResolveVersionData constinit property declarations ********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceVersionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutVersionData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ResolveVersionData constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ResolveVersionData Property Definitions *******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::NewProp_SourceVersionData = { "SourceVersionData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventResolveVersionData_Parms, SourceVersionData), Z_Construct_UScriptStruct_FGenericVersionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceVersionData_MetaData), NewProp_SourceVersionData_MetaData) }; // 477485717
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::NewProp_OutVersionData = { "OutVersionData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventResolveVersionData_Parms, OutVersionData), Z_Construct_UScriptStruct_FGenericVersionData, METADATA_PARAMS(0, nullptr) }; // 477485717
void Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericVersionDataSubsystem_eventResolveVersionData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericVersionDataSubsystem_eventResolveVersionData_Parms), &Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::NewProp_SourceVersionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::NewProp_OutVersionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::PropPointers) < 2048);
// ********** End Function ResolveVersionData Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "ResolveVersionData", 	Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::GenericVersionDataSubsystem_eventResolveVersionData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::GenericVersionDataSubsystem_eventResolveVersionData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execResolveVersionData)
{
	P_GET_STRUCT_REF(FGenericVersionData,Z_Param_Out_SourceVersionData);
	P_GET_STRUCT_REF(FGenericVersionData,Z_Param_Out_OutVersionData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->ResolveVersionData(Z_Param_Out_SourceVersionData,Z_Param_Out_OutVersionData);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function ResolveVersionData *******************

// ********** Begin Class UGenericVersionDataSubsystem Function SetVersionData *********************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics
{
	struct GenericVersionDataSubsystem_eventSetVersionData_Parms
	{
		UObject* TargetObject;
		FGenericVersionData VersionData;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\x8b\xe5\x8a\xa8\xe5\x86\x99\xe5\x85\xa5\xe6\x8c\x87\xe5\xae\x9a\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe5\x86\x99\xe5\x85\xa5\xe5\x89\x8d\xe4\xbc\x9a\xe5\x85\x88\xe5\x92\x8c\xe4\xb8\xad\xe5\xa4\xae\xe5\xae\x9a\xe4\xb9\x89\xe5\x90\x88\xe5\xb9\xb6\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\x8b\xe5\x8a\xa8\xe5\x86\x99\xe5\x85\xa5\xe6\x8c\x87\xe5\xae\x9a\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe5\x86\x99\xe5\x85\xa5\xe5\x89\x8d\xe4\xbc\x9a\xe5\x85\x88\xe5\x92\x8c\xe4\xb8\xad\xe5\xa4\xae\xe5\xae\x9a\xe4\xb9\x89\xe5\x90\x88\xe5\xb9\xb6\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetVersionData constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionData;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVersionData constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVersionData Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::NewProp_TargetObject = { "TargetObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventSetVersionData_Parms, TargetObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::NewProp_VersionData = { "VersionData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventSetVersionData_Parms, VersionData), Z_Construct_UScriptStruct_FGenericVersionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionData_MetaData), NewProp_VersionData_MetaData) }; // 477485717
void Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericVersionDataSubsystem_eventSetVersionData_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericVersionDataSubsystem_eventSetVersionData_Parms), &Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::NewProp_TargetObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::NewProp_VersionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::PropPointers) < 2048);
// ********** End Function SetVersionData Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "SetVersionData", 	Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::GenericVersionDataSubsystem_eventSetVersionData_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::GenericVersionDataSubsystem_eventSetVersionData_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execSetVersionData)
{
	P_GET_OBJECT(UObject,Z_Param_TargetObject);
	P_GET_STRUCT_REF(FGenericVersionData,Z_Param_Out_VersionData);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetVersionData(Z_Param_TargetObject,Z_Param_Out_VersionData);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function SetVersionData ***********************

// ********** Begin Class UGenericVersionDataSubsystem Function SetVersionDefinition ***************
struct Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics
{
	struct GenericVersionDataSubsystem_eventSetVersionDefinition_Parms
	{
		FGenericVersionDefinition VersionDefinition;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x86\x99\xe5\x85\xa5\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe5\x90\x8e\xe7\xbb\xad\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xe4\xbc\x9a\xe9\x80\x9a\xe8\xbf\x87 VersionKey \xe5\x90\x88\xe5\xb9\xb6\xe8\xbf\x99\xe9\x87\x8c\xe7\x9a\x84\xe6\x9c\x80\xe6\x96\xb0\xe7\x89\x88\xe6\x9c\xac\xe5\x92\x8c\xe6\x9c\x80\xe4\xbd\x8e\xe6\x94\xaf\xe6\x8c\x81\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x86\x99\xe5\x85\xa5\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe5\x90\x8e\xe7\xbb\xad\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xe4\xbc\x9a\xe9\x80\x9a\xe8\xbf\x87 VersionKey \xe5\x90\x88\xe5\xb9\xb6\xe8\xbf\x99\xe9\x87\x8c\xe7\x9a\x84\xe6\x9c\x80\xe6\x96\xb0\xe7\x89\x88\xe6\x9c\xac\xe5\x92\x8c\xe6\x9c\x80\xe4\xbd\x8e\xe6\x94\xaf\xe6\x8c\x81\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionDefinition_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetVersionDefinition constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionDefinition;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetVersionDefinition constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetVersionDefinition Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::NewProp_VersionDefinition = { "VersionDefinition", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericVersionDataSubsystem_eventSetVersionDefinition_Parms, VersionDefinition), Z_Construct_UScriptStruct_FGenericVersionDefinition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionDefinition_MetaData), NewProp_VersionDefinition_MetaData) }; // 144404518
void Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericVersionDataSubsystem_eventSetVersionDefinition_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericVersionDataSubsystem_eventSetVersionDefinition_Parms), &Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::NewProp_VersionDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::PropPointers) < 2048);
// ********** End Function SetVersionDefinition Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericVersionDataSubsystem, nullptr, "SetVersionDefinition", 	Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::GenericVersionDataSubsystem_eventSetVersionDefinition_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::GenericVersionDataSubsystem_eventSetVersionDefinition_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericVersionDataSubsystem::execSetVersionDefinition)
{
	P_GET_STRUCT_REF(FGenericVersionDefinition,Z_Param_Out_VersionDefinition);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->SetVersionDefinition(Z_Param_Out_VersionDefinition);
	P_NATIVE_END;
}
// ********** End Class UGenericVersionDataSubsystem Function SetVersionDefinition *****************

// ********** Begin Class UGenericVersionDataSubsystem *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericVersionDataSubsystem;
UClass* UGenericVersionDataSubsystem::GetPrivateStaticClass()
{
	using TClass = UGenericVersionDataSubsystem;
	if (!Z_Registration_Info_UClass_UGenericVersionDataSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericVersionDataSubsystem"),
			Z_Registration_Info_UClass_UGenericVersionDataSubsystem.InnerSingleton,
			StaticRegisterNativesUGenericVersionDataSubsystem,
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
	return Z_Registration_Info_UClass_UGenericVersionDataSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericVersionDataSubsystem_NoRegister()
{
	return UGenericVersionDataSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericVersionDataSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xe4\xb8\xad\xe5\xbf\x83\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80\xe4\xbf\x9d\xe5\xad\x98\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe5\xb9\xb6\xe7\xbc\x93\xe5\xad\x98\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xbd\x93\xe5\x89\x8d\xe8\xa7\xa3\xe6\x9e\x90\xe5\x90\x8e\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Subsystem/GenericVersionDataSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystem/GenericVersionDataSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xe4\xb8\xad\xe5\xbf\x83\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80\xe4\xbf\x9d\xe5\xad\x98\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe5\xb9\xb6\xe7\xbc\x93\xe5\xad\x98\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xbd\x93\xe5\x89\x8d\xe8\xa7\xa3\xe6\x9e\x90\xe5\x90\x8e\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericVersionDataSubsystem constinit property declarations *************
// ********** End Class UGenericVersionDataSubsystem constinit property declarations ***************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ClearVersionData"), .Pointer = &UGenericVersionDataSubsystem::execClearVersionData },
		{ .NameUTF8 = UTF8TEXT("ClearVersionDefinitions"), .Pointer = &UGenericVersionDataSubsystem::execClearVersionDefinitions },
		{ .NameUTF8 = UTF8TEXT("GetVersionData"), .Pointer = &UGenericVersionDataSubsystem::execGetVersionData },
		{ .NameUTF8 = UTF8TEXT("GetVersionDefinition"), .Pointer = &UGenericVersionDataSubsystem::execGetVersionDefinition },
		{ .NameUTF8 = UTF8TEXT("RefreshVersionData"), .Pointer = &UGenericVersionDataSubsystem::execRefreshVersionData },
		{ .NameUTF8 = UTF8TEXT("RegisterVersionDefinitionsFromSettings"), .Pointer = &UGenericVersionDataSubsystem::execRegisterVersionDefinitionsFromSettings },
		{ .NameUTF8 = UTF8TEXT("RemoveVersionData"), .Pointer = &UGenericVersionDataSubsystem::execRemoveVersionData },
		{ .NameUTF8 = UTF8TEXT("RemoveVersionDataByKey"), .Pointer = &UGenericVersionDataSubsystem::execRemoveVersionDataByKey },
		{ .NameUTF8 = UTF8TEXT("RemoveVersionDefinition"), .Pointer = &UGenericVersionDataSubsystem::execRemoveVersionDefinition },
		{ .NameUTF8 = UTF8TEXT("ResolveVersionData"), .Pointer = &UGenericVersionDataSubsystem::execResolveVersionData },
		{ .NameUTF8 = UTF8TEXT("SetVersionData"), .Pointer = &UGenericVersionDataSubsystem::execSetVersionData },
		{ .NameUTF8 = UTF8TEXT("SetVersionDefinition"), .Pointer = &UGenericVersionDataSubsystem::execSetVersionDefinition },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionData, "ClearVersionData" }, // 1459208694
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_ClearVersionDefinitions, "ClearVersionDefinitions" }, // 3464111979
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionData, "GetVersionData" }, // 561445039
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_GetVersionDefinition, "GetVersionDefinition" }, // 4213259704
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_RefreshVersionData, "RefreshVersionData" }, // 507637357
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_RegisterVersionDefinitionsFromSettings, "RegisterVersionDefinitionsFromSettings" }, // 2043436435
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionData, "RemoveVersionData" }, // 4012932749
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDataByKey, "RemoveVersionDataByKey" }, // 3678351765
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_RemoveVersionDefinition, "RemoveVersionDefinition" }, // 1453757773
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_ResolveVersionData, "ResolveVersionData" }, // 3912283775
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionData, "SetVersionData" }, // 824015213
		{ &Z_Construct_UFunction_UGenericVersionDataSubsystem_SetVersionDefinition, "SetVersionDefinition" }, // 79224820
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericVersionDataSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericVersionDataSubsystem_Statics
UObject* (*const Z_Construct_UClass_UGenericVersionDataSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGenericGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericVersionFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVersionDataSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericVersionDataSubsystem_Statics::ClassParams = {
	&UGenericVersionDataSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVersionDataSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericVersionDataSubsystem_Statics::Class_MetaDataParams)
};
void UGenericVersionDataSubsystem::StaticRegisterNativesUGenericVersionDataSubsystem()
{
	UClass* Class = UGenericVersionDataSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGenericVersionDataSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGenericVersionDataSubsystem()
{
	if (!Z_Registration_Info_UClass_UGenericVersionDataSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericVersionDataSubsystem.OuterSingleton, Z_Construct_UClass_UGenericVersionDataSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericVersionDataSubsystem.OuterSingleton;
}
UGenericVersionDataSubsystem::UGenericVersionDataSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericVersionDataSubsystem);
UGenericVersionDataSubsystem::~UGenericVersionDataSubsystem() {}
// ********** End Class UGenericVersionDataSubsystem ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h__Script_GenericVersionFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericVersionDataSubsystem, UGenericVersionDataSubsystem::StaticClass, TEXT("UGenericVersionDataSubsystem"), &Z_Registration_Info_UClass_UGenericVersionDataSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericVersionDataSubsystem), 3706929214U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h__Script_GenericVersionFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h__Script_GenericVersionFramework_744846091{
	TEXT("/Script/GenericVersionFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h__Script_GenericVersionFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h__Script_GenericVersionFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
