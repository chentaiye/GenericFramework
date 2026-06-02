// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/BPFunctions_Gameplay.h"
#include "Engine/HitResult.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UObject/Class.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBPFunctions_Gameplay() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameSession_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AGameStateBase_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_AHUD_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_APlayerState_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UGameInstance_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ULocalPlayer_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FUniqueNetIdRepl();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_Gameplay();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_Gameplay_NoRegister();
UPackage* Z_Construct_UPackage__Script_UnrealMisc();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBPFunctions_Gameplay Function GetActorDownHitResult *********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics
{
	struct BPFunctions_Gameplay_eventGetActorDownHitResult_Parms
	{
		const AActor* InActor;
		FHitResult HitResult;
		TEnumAsByte<ECollisionChannel> TraceChannel;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Actor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96""Actor\xe4\xb8\x8b\xe6\x96\xb9\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_TraceChannel", "ECC_Camera" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96""Actor\xe4\xb8\x8b\xe6\x96\xb9\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActorDownHitResult constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActorDownHitResult constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActorDownHitResult Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::NewProp_InActor = { "InActor", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetActorDownHitResult_Parms, InActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InActor_MetaData), NewProp_InActor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetActorDownHitResult_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 222120718
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetActorDownHitResult_Parms, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 838391399
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetActorDownHitResult_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetActorDownHitResult_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::NewProp_InActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::NewProp_HitResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::PropPointers) < 2048);
// ********** End Function GetActorDownHitResult Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetActorDownHitResult", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::BPFunctions_Gameplay_eventGetActorDownHitResult_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::BPFunctions_Gameplay_eventGetActorDownHitResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetActorDownHitResult)
{
	P_GET_OBJECT(AActor,Z_Param_InActor);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitResult);
	P_GET_PROPERTY(FByteProperty,Z_Param_TraceChannel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetActorDownHitResult(Z_Param_InActor,Z_Param_Out_HitResult,ECollisionChannel(Z_Param_TraceChannel));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetActorDownHitResult ***********************

// ********** Begin Class UBPFunctions_Gameplay Function GetActorForwardHitResult ******************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics
{
	struct BPFunctions_Gameplay_eventGetActorForwardHitResult_Parms
	{
		const AActor* InActor;
		FHitResult HitResult;
		TEnumAsByte<ECollisionChannel> TraceChannel;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Actor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96""Actor\xe5\x89\x8d\xe5\x90\x91\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_TraceChannel", "ECC_Camera" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96""Actor\xe5\x89\x8d\xe5\x90\x91\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActorForwardHitResult constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActorForwardHitResult constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActorForwardHitResult Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::NewProp_InActor = { "InActor", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetActorForwardHitResult_Parms, InActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InActor_MetaData), NewProp_InActor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetActorForwardHitResult_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 222120718
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetActorForwardHitResult_Parms, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 838391399
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetActorForwardHitResult_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetActorForwardHitResult_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::NewProp_InActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::NewProp_HitResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::PropPointers) < 2048);
// ********** End Function GetActorForwardHitResult Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetActorForwardHitResult", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::BPFunctions_Gameplay_eventGetActorForwardHitResult_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::BPFunctions_Gameplay_eventGetActorForwardHitResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetActorForwardHitResult)
{
	P_GET_OBJECT(AActor,Z_Param_InActor);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitResult);
	P_GET_PROPERTY(FByteProperty,Z_Param_TraceChannel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetActorForwardHitResult(Z_Param_InActor,Z_Param_Out_HitResult,ECollisionChannel(Z_Param_TraceChannel));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetActorForwardHitResult ********************

// ********** Begin Class UBPFunctions_Gameplay Function GetActorRightHitResult ********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics
{
	struct BPFunctions_Gameplay_eventGetActorRightHitResult_Parms
	{
		const AActor* InActor;
		FHitResult HitResult;
		TEnumAsByte<ECollisionChannel> TraceChannel;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Actor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96""Actor\xe5\x8f\xb3\xe5\x90\x91\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_TraceChannel", "ECC_Camera" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96""Actor\xe5\x8f\xb3\xe5\x90\x91\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InActor_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetActorRightHitResult constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InActor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetActorRightHitResult constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetActorRightHitResult Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::NewProp_InActor = { "InActor", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetActorRightHitResult_Parms, InActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InActor_MetaData), NewProp_InActor_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetActorRightHitResult_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 222120718
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetActorRightHitResult_Parms, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 838391399
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetActorRightHitResult_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetActorRightHitResult_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::NewProp_InActor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::NewProp_HitResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::PropPointers) < 2048);
// ********** End Function GetActorRightHitResult Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetActorRightHitResult", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::BPFunctions_Gameplay_eventGetActorRightHitResult_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::BPFunctions_Gameplay_eventGetActorRightHitResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetActorRightHitResult)
{
	P_GET_OBJECT(AActor,Z_Param_InActor);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitResult);
	P_GET_PROPERTY(FByteProperty,Z_Param_TraceChannel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetActorRightHitResult(Z_Param_InActor,Z_Param_Out_HitResult,ECollisionChannel(Z_Param_TraceChannel));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetActorRightHitResult **********************

// ********** Begin Class UBPFunctions_Gameplay Function GetComponentDownHitResult *****************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics
{
	struct BPFunctions_Gameplay_eventGetComponentDownHitResult_Parms
	{
		const USceneComponent* InComponent;
		FHitResult HitResult;
		TEnumAsByte<ECollisionChannel> TraceChannel;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Component" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe7\xbb\x84\xe4\xbb\xb6\xe4\xb8\x8b\xe6\x96\xb9\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_TraceChannel", "ECC_Camera" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe7\xbb\x84\xe4\xbb\xb6\xe4\xb8\x8b\xe6\x96\xb9\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetComponentDownHitResult constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetComponentDownHitResult constinit property declarations ***************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetComponentDownHitResult Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::NewProp_InComponent = { "InComponent", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetComponentDownHitResult_Parms, InComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InComponent_MetaData), NewProp_InComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetComponentDownHitResult_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 222120718
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetComponentDownHitResult_Parms, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 838391399
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetComponentDownHitResult_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetComponentDownHitResult_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::NewProp_InComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::NewProp_HitResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::PropPointers) < 2048);
// ********** End Function GetComponentDownHitResult Property Definitions **************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetComponentDownHitResult", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::BPFunctions_Gameplay_eventGetComponentDownHitResult_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::BPFunctions_Gameplay_eventGetComponentDownHitResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetComponentDownHitResult)
{
	P_GET_OBJECT(USceneComponent,Z_Param_InComponent);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitResult);
	P_GET_PROPERTY(FByteProperty,Z_Param_TraceChannel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetComponentDownHitResult(Z_Param_InComponent,Z_Param_Out_HitResult,ECollisionChannel(Z_Param_TraceChannel));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetComponentDownHitResult *******************

// ********** Begin Class UBPFunctions_Gameplay Function GetComponentForwardHitResult **************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics
{
	struct BPFunctions_Gameplay_eventGetComponentForwardHitResult_Parms
	{
		const USceneComponent* InComponent;
		FHitResult HitResult;
		TEnumAsByte<ECollisionChannel> TraceChannel;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Component" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe7\xbb\x84\xe4\xbb\xb6\xe5\x89\x8d\xe5\x90\x91\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_TraceChannel", "ECC_Camera" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe7\xbb\x84\xe4\xbb\xb6\xe5\x89\x8d\xe5\x90\x91\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetComponentForwardHitResult constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetComponentForwardHitResult constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetComponentForwardHitResult Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::NewProp_InComponent = { "InComponent", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetComponentForwardHitResult_Parms, InComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InComponent_MetaData), NewProp_InComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetComponentForwardHitResult_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 222120718
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetComponentForwardHitResult_Parms, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 838391399
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetComponentForwardHitResult_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetComponentForwardHitResult_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::NewProp_InComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::NewProp_HitResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::PropPointers) < 2048);
// ********** End Function GetComponentForwardHitResult Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetComponentForwardHitResult", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::BPFunctions_Gameplay_eventGetComponentForwardHitResult_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::BPFunctions_Gameplay_eventGetComponentForwardHitResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetComponentForwardHitResult)
{
	P_GET_OBJECT(USceneComponent,Z_Param_InComponent);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitResult);
	P_GET_PROPERTY(FByteProperty,Z_Param_TraceChannel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetComponentForwardHitResult(Z_Param_InComponent,Z_Param_Out_HitResult,ECollisionChannel(Z_Param_TraceChannel));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetComponentForwardHitResult ****************

// ********** Begin Class UBPFunctions_Gameplay Function GetComponentRightHitResult ****************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics
{
	struct BPFunctions_Gameplay_eventGetComponentRightHitResult_Parms
	{
		const USceneComponent* InComponent;
		FHitResult HitResult;
		TEnumAsByte<ECollisionChannel> TraceChannel;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "AdvancedDisplay", "2" },
		{ "Category", "Component" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe7\xbb\x84\xe4\xbb\xb6\xe5\x8f\xb3\xe5\x90\x91\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_TraceChannel", "ECC_Camera" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe7\xbb\x84\xe4\xbb\xb6\xe5\x8f\xb3\xe5\x90\x91\xe5\x91\xbd\xe4\xb8\xad\xe7\xbb\x93\xe6\x9e\x9c\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetComponentRightHitResult constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InComponent;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HitResult;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TraceChannel;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetComponentRightHitResult constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetComponentRightHitResult Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::NewProp_InComponent = { "InComponent", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetComponentRightHitResult_Parms, InComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InComponent_MetaData), NewProp_InComponent_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::NewProp_HitResult = { "HitResult", nullptr, (EPropertyFlags)0x0010008000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetComponentRightHitResult_Parms, HitResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(0, nullptr) }; // 222120718
const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::NewProp_TraceChannel = { "TraceChannel", nullptr, (EPropertyFlags)0x0010040000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetComponentRightHitResult_Parms, TraceChannel), Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 838391399
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetComponentRightHitResult_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetComponentRightHitResult_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::NewProp_InComponent,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::NewProp_HitResult,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::NewProp_TraceChannel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::PropPointers) < 2048);
// ********** End Function GetComponentRightHitResult Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetComponentRightHitResult", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::BPFunctions_Gameplay_eventGetComponentRightHitResult_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::BPFunctions_Gameplay_eventGetComponentRightHitResult_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetComponentRightHitResult)
{
	P_GET_OBJECT(USceneComponent,Z_Param_InComponent);
	P_GET_STRUCT_REF(FHitResult,Z_Param_Out_HitResult);
	P_GET_PROPERTY(FByteProperty,Z_Param_TraceChannel);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetComponentRightHitResult(Z_Param_InComponent,Z_Param_Out_HitResult,ECollisionChannel(Z_Param_TraceChannel));
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetComponentRightHitResult ******************

// ********** Begin Class UBPFunctions_Gameplay Function GetGameInstanceByClass ********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics
{
	struct BPFunctions_Gameplay_eventGetGameInstanceByClass_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<UGameInstance> InClass;
		UGameInstance* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\xb8\xb8\xe6\x88\x8f\xe5\xae\x9e\xe4\xbe\x8b""By\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\xb8\xb8\xe6\x88\x8f\xe5\xae\x9e\xe4\xbe\x8b""By\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGameInstanceByClass constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGameInstanceByClass constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGameInstanceByClass Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameInstanceByClass_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameInstanceByClass_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UGameInstance_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameInstanceByClass_Parms, ReturnValue), Z_Construct_UClass_UGameInstance_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::PropPointers) < 2048);
// ********** End Function GetGameInstanceByClass Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetGameInstanceByClass", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::BPFunctions_Gameplay_eventGetGameInstanceByClass_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::BPFunctions_Gameplay_eventGetGameInstanceByClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetGameInstanceByClass)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UGameInstance**)Z_Param__Result=UBPFunctions_Gameplay::GetGameInstanceByClass(Z_Param_WorldContextObject,Z_Param_InClass);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetGameInstanceByClass **********************

// ********** Begin Class UBPFunctions_Gameplay Function GetGameModeByClass ************************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics
{
	struct BPFunctions_Gameplay_eventGetGameModeByClass_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<AGameModeBase> InClass;
		AGameModeBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\xb8\xb8\xe6\x88\x8f\xe6\xa8\xa1\xe5\xbc\x8f""By\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\xb8\xb8\xe6\x88\x8f\xe6\xa8\xa1\xe5\xbc\x8f""By\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGameModeByClass constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGameModeByClass constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGameModeByClass Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameModeByClass_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameModeByClass_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AGameModeBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameModeByClass_Parms, ReturnValue), Z_Construct_UClass_AGameModeBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::PropPointers) < 2048);
// ********** End Function GetGameModeByClass Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetGameModeByClass", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::BPFunctions_Gameplay_eventGetGameModeByClass_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::BPFunctions_Gameplay_eventGetGameModeByClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetGameModeByClass)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AGameModeBase**)Z_Param__Result=UBPFunctions_Gameplay::GetGameModeByClass(Z_Param_WorldContextObject,Z_Param_InClass);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetGameModeByClass **************************

// ********** Begin Class UBPFunctions_Gameplay Function GetGameSessionByClass *********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics
{
	struct BPFunctions_Gameplay_eventGetGameSessionByClass_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<AGameSession> InClass;
		AGameSession* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\xb8\xb8\xe6\x88\x8f\xe4\xbc\x9a\xe8\xaf\x9d""By\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\xb8\xb8\xe6\x88\x8f\xe4\xbc\x9a\xe8\xaf\x9d""By\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGameSessionByClass constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGameSessionByClass constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGameSessionByClass Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameSessionByClass_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameSessionByClass_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AGameSession_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameSessionByClass_Parms, ReturnValue), Z_Construct_UClass_AGameSession_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::PropPointers) < 2048);
// ********** End Function GetGameSessionByClass Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetGameSessionByClass", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::BPFunctions_Gameplay_eventGetGameSessionByClass_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::BPFunctions_Gameplay_eventGetGameSessionByClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetGameSessionByClass)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AGameSession**)Z_Param__Result=UBPFunctions_Gameplay::GetGameSessionByClass(Z_Param_WorldContextObject,Z_Param_InClass);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetGameSessionByClass ***********************

// ********** Begin Class UBPFunctions_Gameplay Function GetGameStateByClass ***********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics
{
	struct BPFunctions_Gameplay_eventGetGameStateByClass_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<AGameStateBase> InClass;
		AGameStateBase* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\xb8\xb8\xe6\x88\x8f\xe7\x8a\xb6\xe6\x80\x81""By\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\xb8\xb8\xe6\x88\x8f\xe7\x8a\xb6\xe6\x80\x81""By\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetGameStateByClass constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGameStateByClass constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGameStateByClass Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameStateByClass_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameStateByClass_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AGameStateBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetGameStateByClass_Parms, ReturnValue), Z_Construct_UClass_AGameStateBase_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::PropPointers) < 2048);
// ********** End Function GetGameStateByClass Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetGameStateByClass", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::BPFunctions_Gameplay_eventGetGameStateByClass_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::BPFunctions_Gameplay_eventGetGameStateByClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetGameStateByClass)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AGameStateBase**)Z_Param__Result=UBPFunctions_Gameplay::GetGameStateByClass(Z_Param_WorldContextObject,Z_Param_InClass);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetGameStateByClass *************************

// ********** Begin Class UBPFunctions_Gameplay Function GetHUDByIndex *****************************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics
{
	struct BPFunctions_Gameplay_eventGetHUDByIndex_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<AHUD> InClass;
		int32 InIndex;
		AHUD* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96HUDBy\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96HUDBy\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetHUDByIndex constinit property declarations *************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHUDByIndex constinit property declarations ***************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHUDByIndex Property Definitions ************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetHUDByIndex_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetHUDByIndex_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AHUD_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::NewProp_InIndex = { "InIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetHUDByIndex_Parms, InIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetHUDByIndex_Parms, ReturnValue), Z_Construct_UClass_AHUD_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::NewProp_InIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::PropPointers) < 2048);
// ********** End Function GetHUDByIndex Property Definitions **************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetHUDByIndex", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::BPFunctions_Gameplay_eventGetHUDByIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::BPFunctions_Gameplay_eventGetHUDByIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetHUDByIndex)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_PROPERTY(FIntProperty,Z_Param_InIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AHUD**)Z_Param__Result=UBPFunctions_Gameplay::GetHUDByIndex(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_InIndex);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetHUDByIndex *******************************

// ********** Begin Class UBPFunctions_Gameplay Function GetHUDByUniqueNetID ***********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics
{
	struct BPFunctions_Gameplay_eventGetHUDByUniqueNetID_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<AHUD> InClass;
		FUniqueNetIdRepl InNetID;
		AHUD* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8c\x89\xe7\x8e\xa9\xe5\xae\xb6\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID \xe6\x9f\xa5\xe6\x89\xbeHUD\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbd\xac\xe6\x8d\xa2\xe7\xbb\x86\xe8\x8a\x82\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8c\x89\xe7\x8e\xa9\xe5\xae\xb6\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID \xe6\x9f\xa5\xe6\x89\xbeHUD\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbd\xac\xe6\x8d\xa2\xe7\xbb\x86\xe8\x8a\x82\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InNetID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetHUDByUniqueNetID constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InNetID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetHUDByUniqueNetID constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetHUDByUniqueNetID Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetHUDByUniqueNetID_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetHUDByUniqueNetID_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AHUD_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::NewProp_InNetID = { "InNetID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetHUDByUniqueNetID_Parms, InNetID), Z_Construct_UScriptStruct_FUniqueNetIdRepl, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InNetID_MetaData), NewProp_InNetID_MetaData) }; // 2301267994
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetHUDByUniqueNetID_Parms, ReturnValue), Z_Construct_UClass_AHUD_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::NewProp_InNetID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::PropPointers) < 2048);
// ********** End Function GetHUDByUniqueNetID Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetHUDByUniqueNetID", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::BPFunctions_Gameplay_eventGetHUDByUniqueNetID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::BPFunctions_Gameplay_eventGetHUDByUniqueNetID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetHUDByUniqueNetID)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_STRUCT_REF(FUniqueNetIdRepl,Z_Param_Out_InNetID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(AHUD**)Z_Param__Result=UBPFunctions_Gameplay::GetHUDByUniqueNetID(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_Out_InNetID);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetHUDByUniqueNetID *************************

// ********** Begin Class UBPFunctions_Gameplay Function GetIsAIPossessPawn ************************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics
{
	struct BPFunctions_Gameplay_eventGetIsAIPossessPawn_Parms
	{
		const APawn* InPawn;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x98\xaf\xe5\x90\xa6""AI\xe5\x8d\xa0\xe6\x9c\x89Pawn\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x98\xaf\xe5\x90\xa6""AI\xe5\x8d\xa0\xe6\x9c\x89Pawn\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPawn_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetIsAIPossessPawn constinit property declarations ********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPawn;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetIsAIPossessPawn constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetIsAIPossessPawn Property Definitions *******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::NewProp_InPawn = { "InPawn", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetIsAIPossessPawn_Parms, InPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPawn_MetaData), NewProp_InPawn_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetIsAIPossessPawn_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetIsAIPossessPawn_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::NewProp_InPawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::PropPointers) < 2048);
// ********** End Function GetIsAIPossessPawn Property Definitions *********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetIsAIPossessPawn", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::BPFunctions_Gameplay_eventGetIsAIPossessPawn_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::BPFunctions_Gameplay_eventGetIsAIPossessPawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetIsAIPossessPawn)
{
	P_GET_OBJECT(APawn,Z_Param_InPawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetIsAIPossessPawn(Z_Param_InPawn);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetIsAIPossessPawn **************************

// ********** Begin Class UBPFunctions_Gameplay Function GetIsPlayerPossessPawn ********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics
{
	struct BPFunctions_Gameplay_eventGetIsPlayerPossessPawn_Parms
	{
		const APawn* InPawn;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Pawn" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x98\xaf\xe5\x90\xa6\xe7\x8e\xa9\xe5\xae\xb6\xe5\x8d\xa0\xe6\x9c\x89Pawn\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x98\xaf\xe5\x90\xa6\xe7\x8e\xa9\xe5\xae\xb6\xe5\x8d\xa0\xe6\x9c\x89Pawn\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPawn_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetIsPlayerPossessPawn constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPawn;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetIsPlayerPossessPawn constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetIsPlayerPossessPawn Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::NewProp_InPawn = { "InPawn", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetIsPlayerPossessPawn_Parms, InPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPawn_MetaData), NewProp_InPawn_MetaData) };
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetIsPlayerPossessPawn_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetIsPlayerPossessPawn_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::NewProp_InPawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::PropPointers) < 2048);
// ********** End Function GetIsPlayerPossessPawn Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetIsPlayerPossessPawn", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::BPFunctions_Gameplay_eventGetIsPlayerPossessPawn_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::BPFunctions_Gameplay_eventGetIsPlayerPossessPawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetIsPlayerPossessPawn)
{
	P_GET_OBJECT(APawn,Z_Param_InPawn);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetIsPlayerPossessPawn(Z_Param_InPawn);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetIsPlayerPossessPawn **********************

// ********** Begin Class UBPFunctions_Gameplay Function GetLocalPlayerByIndex *********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics
{
	struct BPFunctions_Gameplay_eventGetLocalPlayerByIndex_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<ULocalPlayer> InClass;
		int32 InIndex;
		ULocalPlayer* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe6\x9c\xac\xe5\x9c\xb0\xe7\x8e\xa9\xe5\xae\xb6""By\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe6\x9c\xac\xe5\x9c\xb0\xe7\x8e\xa9\xe5\xae\xb6""By\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetLocalPlayerByIndex constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLocalPlayerByIndex constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLocalPlayerByIndex Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetLocalPlayerByIndex_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetLocalPlayerByIndex_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_ULocalPlayer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::NewProp_InIndex = { "InIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetLocalPlayerByIndex_Parms, InIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetLocalPlayerByIndex_Parms, ReturnValue), Z_Construct_UClass_ULocalPlayer_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::NewProp_InIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::PropPointers) < 2048);
// ********** End Function GetLocalPlayerByIndex Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetLocalPlayerByIndex", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::BPFunctions_Gameplay_eventGetLocalPlayerByIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::BPFunctions_Gameplay_eventGetLocalPlayerByIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetLocalPlayerByIndex)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_PROPERTY(FIntProperty,Z_Param_InIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULocalPlayer**)Z_Param__Result=UBPFunctions_Gameplay::GetLocalPlayerByIndex(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_InIndex);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetLocalPlayerByIndex ***********************

// ********** Begin Class UBPFunctions_Gameplay Function GetLocalPlayerByUniqueNetID ***************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics
{
	struct BPFunctions_Gameplay_eventGetLocalPlayerByUniqueNetID_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<ULocalPlayer> InClass;
		FUniqueNetIdRepl InNetID;
		ULocalPlayer* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8c\x89\xe7\x8e\xa9\xe5\xae\xb6\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID \xe6\x9f\xa5\xe6\x89\xbeLocal\xe7\x8e\xa9\xe5\xae\xb6\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbd\xac\xe6\x8d\xa2\xe7\xbb\x86\xe8\x8a\x82\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8c\x89\xe7\x8e\xa9\xe5\xae\xb6\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID \xe6\x9f\xa5\xe6\x89\xbeLocal\xe7\x8e\xa9\xe5\xae\xb6\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbd\xac\xe6\x8d\xa2\xe7\xbb\x86\xe8\x8a\x82\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InNetID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetLocalPlayerByUniqueNetID constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InNetID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetLocalPlayerByUniqueNetID constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetLocalPlayerByUniqueNetID Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetLocalPlayerByUniqueNetID_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetLocalPlayerByUniqueNetID_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_ULocalPlayer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::NewProp_InNetID = { "InNetID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetLocalPlayerByUniqueNetID_Parms, InNetID), Z_Construct_UScriptStruct_FUniqueNetIdRepl, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InNetID_MetaData), NewProp_InNetID_MetaData) }; // 2301267994
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetLocalPlayerByUniqueNetID_Parms, ReturnValue), Z_Construct_UClass_ULocalPlayer_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::NewProp_InNetID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::PropPointers) < 2048);
// ********** End Function GetLocalPlayerByUniqueNetID Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetLocalPlayerByUniqueNetID", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::BPFunctions_Gameplay_eventGetLocalPlayerByUniqueNetID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::BPFunctions_Gameplay_eventGetLocalPlayerByUniqueNetID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetLocalPlayerByUniqueNetID)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_STRUCT_REF(FUniqueNetIdRepl,Z_Param_Out_InNetID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(ULocalPlayer**)Z_Param__Result=UBPFunctions_Gameplay::GetLocalPlayerByUniqueNetID(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_Out_InNetID);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetLocalPlayerByUniqueNetID *****************

// ********** Begin Class UBPFunctions_Gameplay Function GetPawnByIndex ****************************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics
{
	struct BPFunctions_Gameplay_eventGetPawnByIndex_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<APawn> InClass;
		int32 InIndex;
		APawn* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96PawnBy\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96PawnBy\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPawnByIndex constinit property declarations ************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPawnByIndex constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPawnByIndex Property Definitions ***********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPawnByIndex_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPawnByIndex_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::NewProp_InIndex = { "InIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPawnByIndex_Parms, InIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPawnByIndex_Parms, ReturnValue), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::NewProp_InIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::PropPointers) < 2048);
// ********** End Function GetPawnByIndex Property Definitions *************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPawnByIndex", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::BPFunctions_Gameplay_eventGetPawnByIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::BPFunctions_Gameplay_eventGetPawnByIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPawnByIndex)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_PROPERTY(FIntProperty,Z_Param_InIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(APawn**)Z_Param__Result=UBPFunctions_Gameplay::GetPawnByIndex(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_InIndex);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPawnByIndex ******************************

// ********** Begin Class UBPFunctions_Gameplay Function GetPawnByUniqueNetID **********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics
{
	struct BPFunctions_Gameplay_eventGetPawnByUniqueNetID_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<APawn> InClass;
		FUniqueNetIdRepl InNetID;
		APawn* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8c\x89\xe7\x8e\xa9\xe5\xae\xb6\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID \xe6\x9f\xa5\xe6\x89\xbePawn\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbd\xac\xe6\x8d\xa2\xe7\xbb\x86\xe8\x8a\x82\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8c\x89\xe7\x8e\xa9\xe5\xae\xb6\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID \xe6\x9f\xa5\xe6\x89\xbePawn\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbd\xac\xe6\x8d\xa2\xe7\xbb\x86\xe8\x8a\x82\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InNetID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPawnByUniqueNetID constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InNetID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPawnByUniqueNetID constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPawnByUniqueNetID Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPawnByUniqueNetID_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPawnByUniqueNetID_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::NewProp_InNetID = { "InNetID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPawnByUniqueNetID_Parms, InNetID), Z_Construct_UScriptStruct_FUniqueNetIdRepl, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InNetID_MetaData), NewProp_InNetID_MetaData) }; // 2301267994
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPawnByUniqueNetID_Parms, ReturnValue), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::NewProp_InNetID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::PropPointers) < 2048);
// ********** End Function GetPawnByUniqueNetID Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPawnByUniqueNetID", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::BPFunctions_Gameplay_eventGetPawnByUniqueNetID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::BPFunctions_Gameplay_eventGetPawnByUniqueNetID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPawnByUniqueNetID)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_STRUCT_REF(FUniqueNetIdRepl,Z_Param_Out_InNetID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(APawn**)Z_Param__Result=UBPFunctions_Gameplay::GetPawnByUniqueNetID(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_Out_InNetID);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPawnByUniqueNetID ************************

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerControllerByIndex ****************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerControllerByIndex_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<APlayerController> InClass;
		int32 InIndex;
		APlayerController* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe7\x8e\xa9\xe5\xae\xb6\xe6\x8e\xa7\xe5\x88\xb6\xe5\x99\xa8""By\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe7\x8e\xa9\xe5\xae\xb6\xe6\x8e\xa7\xe5\x88\xb6\xe5\x99\xa8""By\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerControllerByIndex constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerControllerByIndex constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerControllerByIndex Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerControllerByIndex_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerControllerByIndex_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::NewProp_InIndex = { "InIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerControllerByIndex_Parms, InIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerControllerByIndex_Parms, ReturnValue), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::NewProp_InIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerControllerByIndex Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerControllerByIndex", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::BPFunctions_Gameplay_eventGetPlayerControllerByIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::BPFunctions_Gameplay_eventGetPlayerControllerByIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerControllerByIndex)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_PROPERTY(FIntProperty,Z_Param_InIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(APlayerController**)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerControllerByIndex(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_InIndex);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerControllerByIndex ******************

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerControllerByUniqueNetID **********
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerControllerByUniqueNetID_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<APlayerController> InClass;
		FUniqueNetIdRepl InNetID;
		APlayerController* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8c\x89\xe7\x8e\xa9\xe5\xae\xb6\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID \xe6\x9f\xa5\xe6\x89\xbe\xe7\x8e\xa9\xe5\xae\xb6\xe6\x8e\xa7\xe5\x88\xb6\xe5\x99\xa8\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbd\xac\xe6\x8d\xa2\xe7\xbb\x86\xe8\x8a\x82\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8c\x89\xe7\x8e\xa9\xe5\xae\xb6\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID \xe6\x9f\xa5\xe6\x89\xbe\xe7\x8e\xa9\xe5\xae\xb6\xe6\x8e\xa7\xe5\x88\xb6\xe5\x99\xa8\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbd\xac\xe6\x8d\xa2\xe7\xbb\x86\xe8\x8a\x82\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InNetID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerControllerByUniqueNetID constinit property declarations ******
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InNetID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerControllerByUniqueNetID constinit property declarations ********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerControllerByUniqueNetID Property Definitions *****************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerControllerByUniqueNetID_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerControllerByUniqueNetID_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::NewProp_InNetID = { "InNetID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerControllerByUniqueNetID_Parms, InNetID), Z_Construct_UScriptStruct_FUniqueNetIdRepl, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InNetID_MetaData), NewProp_InNetID_MetaData) }; // 2301267994
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerControllerByUniqueNetID_Parms, ReturnValue), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::NewProp_InNetID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerControllerByUniqueNetID Property Definitions *******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerControllerByUniqueNetID", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::BPFunctions_Gameplay_eventGetPlayerControllerByUniqueNetID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::BPFunctions_Gameplay_eventGetPlayerControllerByUniqueNetID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerControllerByUniqueNetID)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_STRUCT_REF(FUniqueNetIdRepl,Z_Param_Out_InNetID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(APlayerController**)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerControllerByUniqueNetID(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_Out_InNetID);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerControllerByUniqueNetID ************

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerID *******************************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerID_Parms
	{
		const APlayerController* InPlayer;
		int32 Result;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe7\x8e\xa9\xe5\xae\xb6ID\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "GetPlayerID (PlayerController)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe7\x8e\xa9\xe5\xae\xb6ID\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPlayer_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerID constinit property declarations ***************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPlayer;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Result;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerID constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerID Property Definitions **************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::NewProp_InPlayer = { "InPlayer", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerID_Parms, InPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPlayer_MetaData), NewProp_InPlayer_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerID_Parms, Result), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetPlayerID_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetPlayerID_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::NewProp_InPlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::NewProp_Result,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerID Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerID", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::BPFunctions_Gameplay_eventGetPlayerID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::BPFunctions_Gameplay_eventGetPlayerID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerID)
{
	P_GET_OBJECT(APlayerController,Z_Param_InPlayer);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerID(Z_Param_InPlayer,Z_Param_Out_Result);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerID *********************************

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerIDByPawn *************************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerIDByPawn_Parms
	{
		const APawn* InPawn;
		int32 Result;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe7\x8e\xa9\xe5\xae\xb6IDByPawn\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "GetPlayerID (Pawn)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe7\x8e\xa9\xe5\xae\xb6IDByPawn\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPawn_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerIDByPawn constinit property declarations *********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPawn;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Result;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerIDByPawn constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerIDByPawn Property Definitions ********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::NewProp_InPawn = { "InPawn", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerIDByPawn_Parms, InPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPawn_MetaData), NewProp_InPawn_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerIDByPawn_Parms, Result), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetPlayerIDByPawn_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetPlayerIDByPawn_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::NewProp_InPawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::NewProp_Result,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerIDByPawn Property Definitions **********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerIDByPawn", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::BPFunctions_Gameplay_eventGetPlayerIDByPawn_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::BPFunctions_Gameplay_eventGetPlayerIDByPawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerIDByPawn)
{
	P_GET_OBJECT(APawn,Z_Param_InPawn);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerIDByPawn(Z_Param_InPawn,Z_Param_Out_Result);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerIDByPawn ***************************

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerIDByPlayerState ******************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerIDByPlayerState_Parms
	{
		const APlayerState* InPlayerState;
		int32 Result;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe7\x8e\xa9\xe5\xae\xb6IDBy\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "GetPlayerID (PlayerState)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe7\x8e\xa9\xe5\xae\xb6IDBy\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPlayerState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerIDByPlayerState constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPlayerState;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Result;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerIDByPlayerState constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerIDByPlayerState Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::NewProp_InPlayerState = { "InPlayerState", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerIDByPlayerState_Parms, InPlayerState), Z_Construct_UClass_APlayerState_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPlayerState_MetaData), NewProp_InPlayerState_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerIDByPlayerState_Parms, Result), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetPlayerIDByPlayerState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetPlayerIDByPlayerState_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::NewProp_InPlayerState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::NewProp_Result,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerIDByPlayerState Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerIDByPlayerState", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::BPFunctions_Gameplay_eventGetPlayerIDByPlayerState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::BPFunctions_Gameplay_eventGetPlayerIDByPlayerState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerIDByPlayerState)
{
	P_GET_OBJECT(APlayerState,Z_Param_InPlayerState);
	P_GET_PROPERTY_REF(FIntProperty,Z_Param_Out_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerIDByPlayerState(Z_Param_InPlayerState,Z_Param_Out_Result);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerIDByPlayerState ********************

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerStateByIndex *********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerStateByIndex_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<APlayerState> InClass;
		int32 InIndex;
		APlayerState* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81""By\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81""By\xe7\xb4\xa2\xe5\xbc\x95\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerStateByIndex constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InIndex;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerStateByIndex constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerStateByIndex Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerStateByIndex_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerStateByIndex_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_APlayerState_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::NewProp_InIndex = { "InIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerStateByIndex_Parms, InIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerStateByIndex_Parms, ReturnValue), Z_Construct_UClass_APlayerState_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::NewProp_InIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerStateByIndex Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerStateByIndex", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::BPFunctions_Gameplay_eventGetPlayerStateByIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::BPFunctions_Gameplay_eventGetPlayerStateByIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerStateByIndex)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_PROPERTY(FIntProperty,Z_Param_InIndex);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(APlayerState**)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerStateByIndex(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_InIndex);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerStateByIndex ***********************

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerStateByUniqueNetID ***************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerStateByUniqueNetID_Parms
	{
		const UObject* WorldContextObject;
		const TSubclassOf<APlayerState> InClass;
		FUniqueNetIdRepl InNetID;
		APlayerState* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8c\x89\xe7\x8e\xa9\xe5\xae\xb6\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID \xe6\x9f\xa5\xe6\x89\xbe\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbd\xac\xe6\x8d\xa2\xe7\xbb\x86\xe8\x8a\x82\xe3\x80\x82 */" },
#endif
		{ "DeterminesOutputType", "InClass" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8c\x89\xe7\x8e\xa9\xe5\xae\xb6\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID \xe6\x9f\xa5\xe6\x89\xbe\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbd\xac\xe6\x8d\xa2\xe7\xbb\x86\xe8\x8a\x82\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InClass_MetaData[] = {
		{ "NativeConst", "" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InNetID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerStateByUniqueNetID constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InNetID;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerStateByUniqueNetID constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerStateByUniqueNetID Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerStateByUniqueNetID_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerStateByUniqueNetID_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_APlayerState_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InClass_MetaData), NewProp_InClass_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::NewProp_InNetID = { "InNetID", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerStateByUniqueNetID_Parms, InNetID), Z_Construct_UScriptStruct_FUniqueNetIdRepl, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InNetID_MetaData), NewProp_InNetID_MetaData) }; // 2301267994
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerStateByUniqueNetID_Parms, ReturnValue), Z_Construct_UClass_APlayerState_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::NewProp_InNetID,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerStateByUniqueNetID Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerStateByUniqueNetID", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::BPFunctions_Gameplay_eventGetPlayerStateByUniqueNetID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::BPFunctions_Gameplay_eventGetPlayerStateByUniqueNetID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerStateByUniqueNetID)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_STRUCT_REF(FUniqueNetIdRepl,Z_Param_Out_InNetID);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(APlayerState**)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerStateByUniqueNetID(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_Out_InNetID);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerStateByUniqueNetID *****************

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerUniqueNetID **********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerUniqueNetID_Parms
	{
		const APlayerController* InPlayer;
		FUniqueNetIdRepl Result;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbb\x8e\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x81Pawn \xe6\x88\x96\xe7\x8e\xa9\xe5\xae\xb6\xe7\xb4\xa2\xe5\xbc\x95\xe8\xa7\xa3\xe6\x9e\x90\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe5\xa4\x9a\xe4\xba\xba\xe4\xbc\x9a\xe8\xaf\x9d\xe6\x9f\xa5\xe8\xaf\xa2\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "GetPlayerUniqueNetID (PlayerController)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x8e\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x81Pawn \xe6\x88\x96\xe7\x8e\xa9\xe5\xae\xb6\xe7\xb4\xa2\xe5\xbc\x95\xe8\xa7\xa3\xe6\x9e\x90\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe5\xa4\x9a\xe4\xba\xba\xe4\xbc\x9a\xe8\xaf\x9d\xe6\x9f\xa5\xe8\xaf\xa2\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPlayer_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerUniqueNetID constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPlayer;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerUniqueNetID constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerUniqueNetID Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::NewProp_InPlayer = { "InPlayer", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerUniqueNetID_Parms, InPlayer), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPlayer_MetaData), NewProp_InPlayer_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerUniqueNetID_Parms, Result), Z_Construct_UScriptStruct_FUniqueNetIdRepl, METADATA_PARAMS(0, nullptr) }; // 2301267994
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetPlayerUniqueNetID_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetPlayerUniqueNetID_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::NewProp_InPlayer,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::NewProp_Result,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerUniqueNetID Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerUniqueNetID", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::BPFunctions_Gameplay_eventGetPlayerUniqueNetID_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::BPFunctions_Gameplay_eventGetPlayerUniqueNetID_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerUniqueNetID)
{
	P_GET_OBJECT(APlayerController,Z_Param_InPlayer);
	P_GET_STRUCT_REF(FUniqueNetIdRepl,Z_Param_Out_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerUniqueNetID(Z_Param_InPlayer,Z_Param_Out_Result);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerUniqueNetID ************************

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerUniqueNetIDByPawn ****************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPawn_Parms
	{
		const APawn* InPawn;
		FUniqueNetIdRepl Result;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbb\x8e\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x81Pawn \xe6\x88\x96\xe7\x8e\xa9\xe5\xae\xb6\xe7\xb4\xa2\xe5\xbc\x95\xe8\xa7\xa3\xe6\x9e\x90\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe5\xa4\x9a\xe4\xba\xba\xe4\xbc\x9a\xe8\xaf\x9d\xe6\x9f\xa5\xe8\xaf\xa2\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "GetPlayerUniqueNetID (Pawn)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x8e\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x81Pawn \xe6\x88\x96\xe7\x8e\xa9\xe5\xae\xb6\xe7\xb4\xa2\xe5\xbc\x95\xe8\xa7\xa3\xe6\x9e\x90\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe5\xa4\x9a\xe4\xba\xba\xe4\xbc\x9a\xe8\xaf\x9d\xe6\x9f\xa5\xe8\xaf\xa2\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPawn_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerUniqueNetIDByPawn constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPawn;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerUniqueNetIDByPawn constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerUniqueNetIDByPawn Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::NewProp_InPawn = { "InPawn", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPawn_Parms, InPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPawn_MetaData), NewProp_InPawn_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPawn_Parms, Result), Z_Construct_UScriptStruct_FUniqueNetIdRepl, METADATA_PARAMS(0, nullptr) }; // 2301267994
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPawn_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPawn_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::NewProp_InPawn,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::NewProp_Result,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerUniqueNetIDByPawn Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerUniqueNetIDByPawn", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPawn_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPawn_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerUniqueNetIDByPawn)
{
	P_GET_OBJECT(APawn,Z_Param_InPawn);
	P_GET_STRUCT_REF(FUniqueNetIdRepl,Z_Param_Out_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerUniqueNetIDByPawn(Z_Param_InPawn,Z_Param_Out_Result);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerUniqueNetIDByPawn ******************

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerUniqueNetIDByPlayerIndex *********
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerIndex_Parms
	{
		const UObject* WorldContextObject;
		int32 InPlayerIndex;
		FUniqueNetIdRepl Result;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbb\x8e\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x81Pawn \xe6\x88\x96\xe7\x8e\xa9\xe5\xae\xb6\xe7\xb4\xa2\xe5\xbc\x95\xe8\xa7\xa3\xe6\x9e\x90\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe5\xa4\x9a\xe4\xba\xba\xe4\xbc\x9a\xe8\xaf\x9d\xe6\x9f\xa5\xe8\xaf\xa2\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "GetPlayerUniqueNetID (PlayerIndex)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x8e\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x81Pawn \xe6\x88\x96\xe7\x8e\xa9\xe5\xae\xb6\xe7\xb4\xa2\xe5\xbc\x95\xe8\xa7\xa3\xe6\x9e\x90\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe5\xa4\x9a\xe4\xba\xba\xe4\xbc\x9a\xe8\xaf\x9d\xe6\x9f\xa5\xe8\xaf\xa2\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerUniqueNetIDByPlayerIndex constinit property declarations *****
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FIntPropertyParams NewProp_InPlayerIndex;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerUniqueNetIDByPlayerIndex constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerUniqueNetIDByPlayerIndex Property Definitions ****************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerIndex_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::NewProp_InPlayerIndex = { "InPlayerIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerIndex_Parms, InPlayerIndex), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerIndex_Parms, Result), Z_Construct_UScriptStruct_FUniqueNetIdRepl, METADATA_PARAMS(0, nullptr) }; // 2301267994
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerIndex_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerIndex_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::NewProp_InPlayerIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::NewProp_Result,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerUniqueNetIDByPlayerIndex Property Definitions ******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerUniqueNetIDByPlayerIndex", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerIndex_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerIndex_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerUniqueNetIDByPlayerIndex)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_PROPERTY(FIntProperty,Z_Param_InPlayerIndex);
	P_GET_STRUCT_REF(FUniqueNetIdRepl,Z_Param_Out_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerUniqueNetIDByPlayerIndex(Z_Param_WorldContextObject,Z_Param_InPlayerIndex,Z_Param_Out_Result);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerUniqueNetIDByPlayerIndex ***********

// ********** Begin Class UBPFunctions_Gameplay Function GetPlayerUniqueNetIDByPlayerState *********
struct Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics
{
	struct BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerState_Parms
	{
		const APlayerState* InPlayerState;
		FUniqueNetIdRepl Result;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Gameplay" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbb\x8e\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x81Pawn \xe6\x88\x96\xe7\x8e\xa9\xe5\xae\xb6\xe7\xb4\xa2\xe5\xbc\x95\xe8\xa7\xa3\xe6\x9e\x90\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe5\xa4\x9a\xe4\xba\xba\xe4\xbc\x9a\xe8\xaf\x9d\xe6\x9f\xa5\xe8\xaf\xa2\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "GetPlayerUniqueNetID (PlayerState)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x8e\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x81Pawn \xe6\x88\x96\xe7\x8e\xa9\xe5\xae\xb6\xe7\xb4\xa2\xe5\xbc\x95\xe8\xa7\xa3\xe6\x9e\x90\xe5\x94\xaf\xe4\xb8\x80\xe7\xbd\x91\xe7\xbb\x9c ID\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe5\xa4\x9a\xe4\xba\xba\xe4\xbc\x9a\xe8\xaf\x9d\xe6\x9f\xa5\xe8\xaf\xa2\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InPlayerState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayerUniqueNetIDByPlayerState constinit property declarations *****
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InPlayerState;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Result;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayerUniqueNetIDByPlayerState constinit property declarations *******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayerUniqueNetIDByPlayerState Property Definitions ****************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::NewProp_InPlayerState = { "InPlayerState", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerState_Parms, InPlayerState), Z_Construct_UClass_APlayerState_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InPlayerState_MetaData), NewProp_InPlayerState_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerState_Parms, Result), Z_Construct_UScriptStruct_FUniqueNetIdRepl, METADATA_PARAMS(0, nullptr) }; // 2301267994
void Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerState_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerState_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::NewProp_InPlayerState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::NewProp_Result,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::PropPointers) < 2048);
// ********** End Function GetPlayerUniqueNetIDByPlayerState Property Definitions ******************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "GetPlayerUniqueNetIDByPlayerState", 	Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerState_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::BPFunctions_Gameplay_eventGetPlayerUniqueNetIDByPlayerState_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execGetPlayerUniqueNetIDByPlayerState)
{
	P_GET_OBJECT(APlayerState,Z_Param_InPlayerState);
	P_GET_STRUCT_REF(FUniqueNetIdRepl,Z_Param_Out_Result);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UBPFunctions_Gameplay::GetPlayerUniqueNetIDByPlayerState(Z_Param_InPlayerState,Z_Param_Out_Result);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function GetPlayerUniqueNetIDByPlayerState ***********

// ********** Begin Class UBPFunctions_Gameplay Function SetAllActorsVisibility ********************
struct Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics
{
	struct BPFunctions_Gameplay_eventSetAllActorsVisibility_Parms
	{
		const UObject* WorldContextObject;
		TSubclassOf<AActor> InClass;
		bool bIsHiddenInGame;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Actor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x89\xb9\xe9\x87\x8f\xe5\x86\x99\xe5\x85\xa5\xe5\x85\xa8\xe9\x83\xa8 Actor \xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe9\x9a\x90\xe8\x97\x8f\xe7\x8a\xb6\xe6\x80\x81\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x89\xb9\xe9\x87\x8f\xe5\x86\x99\xe5\x85\xa5\xe5\x85\xa8\xe9\x83\xa8 Actor \xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe4\xb8\x96\xe7\x95\x8c\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe9\x9a\x90\xe8\x97\x8f\xe7\x8a\xb6\xe6\x80\x81\xe5\x90\x8c\xe6\xad\xa5\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAllActorsVisibility constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static void NewProp_bIsHiddenInGame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHiddenInGame;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAllActorsVisibility constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAllActorsVisibility Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventSetAllActorsVisibility_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventSetAllActorsVisibility_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::NewProp_bIsHiddenInGame_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventSetAllActorsVisibility_Parms*)Obj)->bIsHiddenInGame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::NewProp_bIsHiddenInGame = { "bIsHiddenInGame", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventSetAllActorsVisibility_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::NewProp_bIsHiddenInGame_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::NewProp_bIsHiddenInGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::PropPointers) < 2048);
// ********** End Function SetAllActorsVisibility Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "SetAllActorsVisibility", 	Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::BPFunctions_Gameplay_eventSetAllActorsVisibility_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::BPFunctions_Gameplay_eventSetAllActorsVisibility_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execSetAllActorsVisibility)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_UBOOL(Z_Param_bIsHiddenInGame);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Gameplay::SetAllActorsVisibility(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_bIsHiddenInGame);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function SetAllActorsVisibility **********************

// ********** Begin Class UBPFunctions_Gameplay Function SetAllActorsVisibilityWithInterface *******
struct Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics
{
	struct BPFunctions_Gameplay_eventSetAllActorsVisibilityWithInterface_Parms
	{
		const UObject* WorldContextObject;
		TSubclassOf<UInterface> Interface;
		bool bIsHiddenInGame;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Actor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8c\x89\xe6\x8e\xa5\xe5\x8f\xa3\xe8\xbf\x87\xe6\xbb\xa4 Actor \xe5\x90\x8e\xe6\x89\xb9\xe9\x87\x8f\xe5\x86\x99\xe5\x85\xa5\xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7\xef\xbc\x8c\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x88\xa4\xe6\x96\xad\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8c\x89\xe6\x8e\xa5\xe5\x8f\xa3\xe8\xbf\x87\xe6\xbb\xa4 Actor \xe5\x90\x8e\xe6\x89\xb9\xe9\x87\x8f\xe5\x86\x99\xe5\x85\xa5\xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7\xef\xbc\x8c\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe9\x81\x8d\xe5\x8e\x86\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x88\xa4\xe6\x96\xad\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAllActorsVisibilityWithInterface constinit property declarations ***
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_Interface;
	static void NewProp_bIsHiddenInGame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHiddenInGame;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAllActorsVisibilityWithInterface constinit property declarations *****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAllActorsVisibilityWithInterface Property Definitions **************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithInterface_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::NewProp_Interface = { "Interface", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithInterface_Parms, Interface), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::NewProp_bIsHiddenInGame_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventSetAllActorsVisibilityWithInterface_Parms*)Obj)->bIsHiddenInGame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::NewProp_bIsHiddenInGame = { "bIsHiddenInGame", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithInterface_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::NewProp_bIsHiddenInGame_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::NewProp_Interface,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::NewProp_bIsHiddenInGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::PropPointers) < 2048);
// ********** End Function SetAllActorsVisibilityWithInterface Property Definitions ****************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "SetAllActorsVisibilityWithInterface", 	Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::BPFunctions_Gameplay_eventSetAllActorsVisibilityWithInterface_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::BPFunctions_Gameplay_eventSetAllActorsVisibilityWithInterface_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execSetAllActorsVisibilityWithInterface)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_Interface);
	P_GET_UBOOL(Z_Param_bIsHiddenInGame);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Gameplay::SetAllActorsVisibilityWithInterface(Z_Param_WorldContextObject,Z_Param_Interface,Z_Param_bIsHiddenInGame);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function SetAllActorsVisibilityWithInterface *********

// ********** Begin Class UBPFunctions_Gameplay Function SetAllActorsVisibilityWithTag_Class *******
struct Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics
{
	struct BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Class_Parms
	{
		const UObject* WorldContextObject;
		TSubclassOf<AActor> InClass;
		FName InTag;
		bool bIsHiddenInGame;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Actor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8c\x89\xe6\xa0\x87\xe7\xad\xbe\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbf\x87\xe6\xbb\xa4 Actor \xe5\x90\x8e\xe6\x89\xb9\xe9\x87\x8f\xe5\x86\x99\xe5\x85\xa5\xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "SetAllActorsVisibilityWithTag(Class)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8c\x89\xe6\xa0\x87\xe7\xad\xbe\xe5\x92\x8c\xe7\xb1\xbb\xe5\x9e\x8b\xe8\xbf\x87\xe6\xbb\xa4 Actor \xe5\x90\x8e\xe6\x89\xb9\xe9\x87\x8f\xe5\x86\x99\xe5\x85\xa5\xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAllActorsVisibilityWithTag_Class constinit property declarations ***
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_InClass;
	static const UECodeGen_Private::FNamePropertyParams NewProp_InTag;
	static void NewProp_bIsHiddenInGame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHiddenInGame;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAllActorsVisibilityWithTag_Class constinit property declarations *****
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAllActorsVisibilityWithTag_Class Property Definitions **************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Class_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::NewProp_InClass = { "InClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Class_Parms, InClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::NewProp_InTag = { "InTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Class_Parms, InTag), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::NewProp_bIsHiddenInGame_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Class_Parms*)Obj)->bIsHiddenInGame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::NewProp_bIsHiddenInGame = { "bIsHiddenInGame", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Class_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::NewProp_bIsHiddenInGame_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::NewProp_InClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::NewProp_InTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::NewProp_bIsHiddenInGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::PropPointers) < 2048);
// ********** End Function SetAllActorsVisibilityWithTag_Class Property Definitions ****************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "SetAllActorsVisibilityWithTag_Class", 	Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Class_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Class_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execSetAllActorsVisibilityWithTag_Class)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_InClass);
	P_GET_PROPERTY(FNameProperty,Z_Param_InTag);
	P_GET_UBOOL(Z_Param_bIsHiddenInGame);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Gameplay::SetAllActorsVisibilityWithTag_Class(Z_Param_WorldContextObject,Z_Param_InClass,Z_Param_InTag,Z_Param_bIsHiddenInGame);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function SetAllActorsVisibilityWithTag_Class *********

// ********** Begin Class UBPFunctions_Gameplay Function SetAllActorsVisibilityWithTag_Interface ***
struct Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics
{
	struct BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Interface_Parms
	{
		const UObject* WorldContextObject;
		TSubclassOf<UInterface> Interface;
		FName InTag;
		bool bIsHiddenInGame;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Actor" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8c\x89\xe6\xa0\x87\xe7\xad\xbe\xe5\x92\x8c\xe6\x8e\xa5\xe5\x8f\xa3\xe8\xbf\x87\xe6\xbb\xa4 Actor \xe5\x90\x8e\xe6\x89\xb9\xe9\x87\x8f\xe5\x86\x99\xe5\x85\xa5\xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7\xe3\x80\x82 */" },
#endif
		{ "DisplayName", "SetAllActorsVisibilityWithTag(Interface)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8c\x89\xe6\xa0\x87\xe7\xad\xbe\xe5\x92\x8c\xe6\x8e\xa5\xe5\x8f\xa3\xe8\xbf\x87\xe6\xbb\xa4 Actor \xe5\x90\x8e\xe6\x89\xb9\xe9\x87\x8f\xe5\x86\x99\xe5\x85\xa5\xe5\x8f\xaf\xe8\xa7\x81\xe6\x80\xa7\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetAllActorsVisibilityWithTag_Interface constinit property declarations 
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FClassPropertyParams NewProp_Interface;
	static const UECodeGen_Private::FNamePropertyParams NewProp_InTag;
	static void NewProp_bIsHiddenInGame_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHiddenInGame;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetAllActorsVisibilityWithTag_Interface constinit property declarations *
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetAllActorsVisibilityWithTag_Interface Property Definitions **********
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Interface_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WorldContextObject_MetaData), NewProp_WorldContextObject_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::NewProp_Interface = { "Interface", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Interface_Parms, Interface), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UInterface_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::NewProp_InTag = { "InTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Interface_Parms, InTag), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::NewProp_bIsHiddenInGame_SetBit(void* Obj)
{
	((BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Interface_Parms*)Obj)->bIsHiddenInGame = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::NewProp_bIsHiddenInGame = { "bIsHiddenInGame", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Interface_Parms), &Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::NewProp_bIsHiddenInGame_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::NewProp_Interface,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::NewProp_InTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::NewProp_bIsHiddenInGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::PropPointers) < 2048);
// ********** End Function SetAllActorsVisibilityWithTag_Interface Property Definitions ************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_Gameplay, nullptr, "SetAllActorsVisibilityWithTag_Interface", 	Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Interface_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::BPFunctions_Gameplay_eventSetAllActorsVisibilityWithTag_Interface_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_Gameplay::execSetAllActorsVisibilityWithTag_Interface)
{
	P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
	P_GET_OBJECT(UClass,Z_Param_Interface);
	P_GET_PROPERTY(FNameProperty,Z_Param_InTag);
	P_GET_UBOOL(Z_Param_bIsHiddenInGame);
	P_FINISH;
	P_NATIVE_BEGIN;
	UBPFunctions_Gameplay::SetAllActorsVisibilityWithTag_Interface(Z_Param_WorldContextObject,Z_Param_Interface,Z_Param_InTag,Z_Param_bIsHiddenInGame);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_Gameplay Function SetAllActorsVisibilityWithTag_Interface *****

// ********** Begin Class UBPFunctions_Gameplay ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBPFunctions_Gameplay;
UClass* UBPFunctions_Gameplay::GetPrivateStaticClass()
{
	using TClass = UBPFunctions_Gameplay;
	if (!Z_Registration_Info_UClass_UBPFunctions_Gameplay.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BPFunctions_Gameplay"),
			Z_Registration_Info_UClass_UBPFunctions_Gameplay.InnerSingleton,
			StaticRegisterNativesUBPFunctions_Gameplay,
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
	return Z_Registration_Info_UClass_UBPFunctions_Gameplay.InnerSingleton;
}
UClass* Z_Construct_UClass_UBPFunctions_Gameplay_NoRegister()
{
	return UBPFunctions_Gameplay::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBPFunctions_Gameplay_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2Gameplay\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "BPFunctions/BPFunctions_Gameplay.h" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_Gameplay.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2Gameplay\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBPFunctions_Gameplay constinit property declarations ********************
// ********** End Class UBPFunctions_Gameplay constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetActorDownHitResult"), .Pointer = &UBPFunctions_Gameplay::execGetActorDownHitResult },
		{ .NameUTF8 = UTF8TEXT("GetActorForwardHitResult"), .Pointer = &UBPFunctions_Gameplay::execGetActorForwardHitResult },
		{ .NameUTF8 = UTF8TEXT("GetActorRightHitResult"), .Pointer = &UBPFunctions_Gameplay::execGetActorRightHitResult },
		{ .NameUTF8 = UTF8TEXT("GetComponentDownHitResult"), .Pointer = &UBPFunctions_Gameplay::execGetComponentDownHitResult },
		{ .NameUTF8 = UTF8TEXT("GetComponentForwardHitResult"), .Pointer = &UBPFunctions_Gameplay::execGetComponentForwardHitResult },
		{ .NameUTF8 = UTF8TEXT("GetComponentRightHitResult"), .Pointer = &UBPFunctions_Gameplay::execGetComponentRightHitResult },
		{ .NameUTF8 = UTF8TEXT("GetGameInstanceByClass"), .Pointer = &UBPFunctions_Gameplay::execGetGameInstanceByClass },
		{ .NameUTF8 = UTF8TEXT("GetGameModeByClass"), .Pointer = &UBPFunctions_Gameplay::execGetGameModeByClass },
		{ .NameUTF8 = UTF8TEXT("GetGameSessionByClass"), .Pointer = &UBPFunctions_Gameplay::execGetGameSessionByClass },
		{ .NameUTF8 = UTF8TEXT("GetGameStateByClass"), .Pointer = &UBPFunctions_Gameplay::execGetGameStateByClass },
		{ .NameUTF8 = UTF8TEXT("GetHUDByIndex"), .Pointer = &UBPFunctions_Gameplay::execGetHUDByIndex },
		{ .NameUTF8 = UTF8TEXT("GetHUDByUniqueNetID"), .Pointer = &UBPFunctions_Gameplay::execGetHUDByUniqueNetID },
		{ .NameUTF8 = UTF8TEXT("GetIsAIPossessPawn"), .Pointer = &UBPFunctions_Gameplay::execGetIsAIPossessPawn },
		{ .NameUTF8 = UTF8TEXT("GetIsPlayerPossessPawn"), .Pointer = &UBPFunctions_Gameplay::execGetIsPlayerPossessPawn },
		{ .NameUTF8 = UTF8TEXT("GetLocalPlayerByIndex"), .Pointer = &UBPFunctions_Gameplay::execGetLocalPlayerByIndex },
		{ .NameUTF8 = UTF8TEXT("GetLocalPlayerByUniqueNetID"), .Pointer = &UBPFunctions_Gameplay::execGetLocalPlayerByUniqueNetID },
		{ .NameUTF8 = UTF8TEXT("GetPawnByIndex"), .Pointer = &UBPFunctions_Gameplay::execGetPawnByIndex },
		{ .NameUTF8 = UTF8TEXT("GetPawnByUniqueNetID"), .Pointer = &UBPFunctions_Gameplay::execGetPawnByUniqueNetID },
		{ .NameUTF8 = UTF8TEXT("GetPlayerControllerByIndex"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerControllerByIndex },
		{ .NameUTF8 = UTF8TEXT("GetPlayerControllerByUniqueNetID"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerControllerByUniqueNetID },
		{ .NameUTF8 = UTF8TEXT("GetPlayerID"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerID },
		{ .NameUTF8 = UTF8TEXT("GetPlayerIDByPawn"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerIDByPawn },
		{ .NameUTF8 = UTF8TEXT("GetPlayerIDByPlayerState"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerIDByPlayerState },
		{ .NameUTF8 = UTF8TEXT("GetPlayerStateByIndex"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerStateByIndex },
		{ .NameUTF8 = UTF8TEXT("GetPlayerStateByUniqueNetID"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerStateByUniqueNetID },
		{ .NameUTF8 = UTF8TEXT("GetPlayerUniqueNetID"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerUniqueNetID },
		{ .NameUTF8 = UTF8TEXT("GetPlayerUniqueNetIDByPawn"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerUniqueNetIDByPawn },
		{ .NameUTF8 = UTF8TEXT("GetPlayerUniqueNetIDByPlayerIndex"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerUniqueNetIDByPlayerIndex },
		{ .NameUTF8 = UTF8TEXT("GetPlayerUniqueNetIDByPlayerState"), .Pointer = &UBPFunctions_Gameplay::execGetPlayerUniqueNetIDByPlayerState },
		{ .NameUTF8 = UTF8TEXT("SetAllActorsVisibility"), .Pointer = &UBPFunctions_Gameplay::execSetAllActorsVisibility },
		{ .NameUTF8 = UTF8TEXT("SetAllActorsVisibilityWithInterface"), .Pointer = &UBPFunctions_Gameplay::execSetAllActorsVisibilityWithInterface },
		{ .NameUTF8 = UTF8TEXT("SetAllActorsVisibilityWithTag_Class"), .Pointer = &UBPFunctions_Gameplay::execSetAllActorsVisibilityWithTag_Class },
		{ .NameUTF8 = UTF8TEXT("SetAllActorsVisibilityWithTag_Interface"), .Pointer = &UBPFunctions_Gameplay::execSetAllActorsVisibilityWithTag_Interface },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorDownHitResult, "GetActorDownHitResult" }, // 3646099476
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorForwardHitResult, "GetActorForwardHitResult" }, // 2743132513
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetActorRightHitResult, "GetActorRightHitResult" }, // 1313631969
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentDownHitResult, "GetComponentDownHitResult" }, // 850991469
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentForwardHitResult, "GetComponentForwardHitResult" }, // 3884632492
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetComponentRightHitResult, "GetComponentRightHitResult" }, // 3547503107
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameInstanceByClass, "GetGameInstanceByClass" }, // 2419527269
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameModeByClass, "GetGameModeByClass" }, // 3742441680
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameSessionByClass, "GetGameSessionByClass" }, // 37898870
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetGameStateByClass, "GetGameStateByClass" }, // 4287315541
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByIndex, "GetHUDByIndex" }, // 839809959
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetHUDByUniqueNetID, "GetHUDByUniqueNetID" }, // 960064423
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsAIPossessPawn, "GetIsAIPossessPawn" }, // 3867104119
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetIsPlayerPossessPawn, "GetIsPlayerPossessPawn" }, // 2725806812
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByIndex, "GetLocalPlayerByIndex" }, // 2841945880
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetLocalPlayerByUniqueNetID, "GetLocalPlayerByUniqueNetID" }, // 4172087228
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByIndex, "GetPawnByIndex" }, // 1500575385
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPawnByUniqueNetID, "GetPawnByUniqueNetID" }, // 4129081146
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByIndex, "GetPlayerControllerByIndex" }, // 3090263591
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerControllerByUniqueNetID, "GetPlayerControllerByUniqueNetID" }, // 3269731223
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerID, "GetPlayerID" }, // 3042180179
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPawn, "GetPlayerIDByPawn" }, // 1971967457
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerIDByPlayerState, "GetPlayerIDByPlayerState" }, // 659123773
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByIndex, "GetPlayerStateByIndex" }, // 2653017220
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerStateByUniqueNetID, "GetPlayerStateByUniqueNetID" }, // 1802609749
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetID, "GetPlayerUniqueNetID" }, // 1172168998
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPawn, "GetPlayerUniqueNetIDByPawn" }, // 2395385778
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerIndex, "GetPlayerUniqueNetIDByPlayerIndex" }, // 3311109554
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_GetPlayerUniqueNetIDByPlayerState, "GetPlayerUniqueNetIDByPlayerState" }, // 2986349570
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibility, "SetAllActorsVisibility" }, // 1550496493
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithInterface, "SetAllActorsVisibilityWithInterface" }, // 113887847
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Class, "SetAllActorsVisibilityWithTag_Class" }, // 126752148
		{ &Z_Construct_UFunction_UBPFunctions_Gameplay_SetAllActorsVisibilityWithTag_Interface, "SetAllActorsVisibilityWithTag_Interface" }, // 1218452179
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctions_Gameplay>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBPFunctions_Gameplay_Statics
UObject* (*const Z_Construct_UClass_UBPFunctions_Gameplay_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_UnrealMisc,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Gameplay_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctions_Gameplay_Statics::ClassParams = {
	&UBPFunctions_Gameplay::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_Gameplay_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPFunctions_Gameplay_Statics::Class_MetaDataParams)
};
void UBPFunctions_Gameplay::StaticRegisterNativesUBPFunctions_Gameplay()
{
	UClass* Class = UBPFunctions_Gameplay::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UBPFunctions_Gameplay_Statics::Funcs));
}
UClass* Z_Construct_UClass_UBPFunctions_Gameplay()
{
	if (!Z_Registration_Info_UClass_UBPFunctions_Gameplay.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPFunctions_Gameplay.OuterSingleton, Z_Construct_UClass_UBPFunctions_Gameplay_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPFunctions_Gameplay.OuterSingleton;
}
UBPFunctions_Gameplay::UBPFunctions_Gameplay(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBPFunctions_Gameplay);
UBPFunctions_Gameplay::~UBPFunctions_Gameplay() {}
// ********** End Class UBPFunctions_Gameplay ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h__Script_UnrealMisc_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPFunctions_Gameplay, UBPFunctions_Gameplay::StaticClass, TEXT("UBPFunctions_Gameplay"), &Z_Registration_Info_UClass_UBPFunctions_Gameplay, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPFunctions_Gameplay), 495744992U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h__Script_UnrealMisc_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h__Script_UnrealMisc_3146510339{
	TEXT("/Script/UnrealMisc"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h__Script_UnrealMisc_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_Gameplay_h__Script_UnrealMisc_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
