// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/BPFunctions_GameplayTag.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBPFunctions_GameplayTag() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_GameplayTag();
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_GameplayTag_NoRegister();
UPackage* Z_Construct_UPackage__Script_UnrealMisc();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBPFunctions_GameplayTag Function Conv_GameplayTagToName *****************
struct Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics
{
	struct BPFunctions_GameplayTag_eventConv_GameplayTagToName_Parms
	{
		FGameplayTag InTag;
		FName ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2GameplayTagTo\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "To Name(FGameplayTag)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_GameplayTag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2GameplayTagTo\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Conv_GameplayTagToName constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTag;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Conv_GameplayTagToName constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Conv_GameplayTagToName Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::NewProp_InTag = { "InTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventConv_GameplayTagToName_Parms, InTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventConv_GameplayTagToName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::NewProp_InTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::PropPointers) < 2048);
// ********** End Function Conv_GameplayTagToName Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_GameplayTag, nullptr, "Conv_GameplayTagToName", 	Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::BPFunctions_GameplayTag_eventConv_GameplayTagToName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::BPFunctions_GameplayTag_eventConv_GameplayTagToName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_GameplayTag::execConv_GameplayTagToName)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_InTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FName*)Z_Param__Result=UBPFunctions_GameplayTag::Conv_GameplayTagToName(Z_Param_InTag);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_GameplayTag Function Conv_GameplayTagToName *******************

// ********** Begin Class UBPFunctions_GameplayTag Function Conv_GameplayTagToString ***************
struct Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics
{
	struct BPFunctions_GameplayTag_eventConv_GameplayTagToString_Parms
	{
		FGameplayTag InTag;
		FString ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2GameplayTagTo\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "To String(FGameplayTag)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_GameplayTag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2GameplayTagTo\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Conv_GameplayTagToString constinit property declarations **************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTag;
	static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Conv_GameplayTagToString constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Conv_GameplayTagToString Property Definitions *************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::NewProp_InTag = { "InTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventConv_GameplayTagToString_Parms, InTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventConv_GameplayTagToString_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::NewProp_InTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::PropPointers) < 2048);
// ********** End Function Conv_GameplayTagToString Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_GameplayTag, nullptr, "Conv_GameplayTagToString", 	Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::BPFunctions_GameplayTag_eventConv_GameplayTagToString_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::BPFunctions_GameplayTag_eventConv_GameplayTagToString_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_GameplayTag::execConv_GameplayTagToString)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_InTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FString*)Z_Param__Result=UBPFunctions_GameplayTag::Conv_GameplayTagToString(Z_Param_InTag);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_GameplayTag Function Conv_GameplayTagToString *****************

// ********** Begin Class UBPFunctions_GameplayTag Function Conv_NameToGameplayTag *****************
struct Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics
{
	struct BPFunctions_GameplayTag_eventConv_NameToGameplayTag_Parms
	{
		FName TagName;
		FGameplayTag ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2\xe5\x90\x8d\xe7\xa7\xb0ToGameplayTag\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "To GameplayTag(Name)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_GameplayTag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2\xe5\x90\x8d\xe7\xa7\xb0ToGameplayTag\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function Conv_NameToGameplayTag constinit property declarations ****************
	static const UECodeGen_Private::FNamePropertyParams NewProp_TagName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Conv_NameToGameplayTag constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Conv_NameToGameplayTag Property Definitions ***************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::NewProp_TagName = { "TagName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventConv_NameToGameplayTag_Parms, TagName), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventConv_NameToGameplayTag_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::NewProp_TagName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::PropPointers) < 2048);
// ********** End Function Conv_NameToGameplayTag Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_GameplayTag, nullptr, "Conv_NameToGameplayTag", 	Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::BPFunctions_GameplayTag_eventConv_NameToGameplayTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::BPFunctions_GameplayTag_eventConv_NameToGameplayTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_GameplayTag::execConv_NameToGameplayTag)
{
	P_GET_PROPERTY(FNameProperty,Z_Param_TagName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTag*)Z_Param__Result=UBPFunctions_GameplayTag::Conv_NameToGameplayTag(Z_Param_TagName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_GameplayTag Function Conv_NameToGameplayTag *******************

// ********** Begin Class UBPFunctions_GameplayTag Function Conv_StringToGameplayTag ***************
struct Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics
{
	struct BPFunctions_GameplayTag_eventConv_StringToGameplayTag_Parms
	{
		FString TagName;
		FGameplayTag ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbd\xac\xe6\x8d\xa2\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2ToGameplayTag\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82 */" },
#endif
		{ "CompactNodeTitle", "->" },
		{ "DisplayName", "To GameplayTag(String)" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_GameplayTag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbd\xac\xe6\x8d\xa2\xe5\xad\x97\xe7\xac\xa6\xe4\xb8\xb2ToGameplayTag\xef\xbc\x8c\xe4\xbf\x9d\xe6\x8c\x81\xe8\x93\x9d\xe5\x9b\xbe\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xb1\xbb\xe5\x9e\x8b\xe4\xb8\x8e Unreal \xe5\x8e\x9f\xe7\x94\x9f\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe8\xaf\xad\xe4\xb9\x89\xe4\xb8\x80\xe8\x87\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TagName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function Conv_StringToGameplayTag constinit property declarations **************
	static const UECodeGen_Private::FStrPropertyParams NewProp_TagName;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Conv_StringToGameplayTag constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Conv_StringToGameplayTag Property Definitions *************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::NewProp_TagName = { "TagName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventConv_StringToGameplayTag_Parms, TagName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TagName_MetaData), NewProp_TagName_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventConv_StringToGameplayTag_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::NewProp_TagName,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::PropPointers) < 2048);
// ********** End Function Conv_StringToGameplayTag Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_GameplayTag, nullptr, "Conv_StringToGameplayTag", 	Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::BPFunctions_GameplayTag_eventConv_StringToGameplayTag_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::BPFunctions_GameplayTag_eventConv_StringToGameplayTag_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_GameplayTag::execConv_StringToGameplayTag)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_TagName);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTag*)Z_Param__Result=UBPFunctions_GameplayTag::Conv_StringToGameplayTag(Z_Param_TagName);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_GameplayTag Function Conv_StringToGameplayTag *****************

// ********** Begin Class UBPFunctions_GameplayTag Function GetDirectGameplayTagChildren ***********
struct Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics
{
	struct BPFunctions_GameplayTag_eventGetDirectGameplayTagChildren_Parms
	{
		FGameplayTag InTag;
		bool bIsContainOriginal;
		FGameplayTagContainer ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96""DirectGameplay\xe6\xa0\x87\xe7\xad\xbe""Children\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_bIsContainOriginal", "false" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_GameplayTag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96""DirectGameplay\xe6\xa0\x87\xe7\xad\xbe""Children\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDirectGameplayTagChildren constinit property declarations **********
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTag;
	static void NewProp_bIsContainOriginal_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsContainOriginal;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDirectGameplayTagChildren constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDirectGameplayTagChildren Property Definitions *********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::NewProp_InTag = { "InTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventGetDirectGameplayTagChildren_Parms, InTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::NewProp_bIsContainOriginal_SetBit(void* Obj)
{
	((BPFunctions_GameplayTag_eventGetDirectGameplayTagChildren_Parms*)Obj)->bIsContainOriginal = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::NewProp_bIsContainOriginal = { "bIsContainOriginal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_GameplayTag_eventGetDirectGameplayTagChildren_Parms), &Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::NewProp_bIsContainOriginal_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventGetDirectGameplayTagChildren_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::NewProp_InTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::NewProp_bIsContainOriginal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::PropPointers) < 2048);
// ********** End Function GetDirectGameplayTagChildren Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_GameplayTag, nullptr, "GetDirectGameplayTagChildren", 	Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::BPFunctions_GameplayTag_eventGetDirectGameplayTagChildren_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::BPFunctions_GameplayTag_eventGetDirectGameplayTagChildren_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_GameplayTag::execGetDirectGameplayTagChildren)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_InTag);
	P_GET_UBOOL(Z_Param_bIsContainOriginal);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTagContainer*)Z_Param__Result=UBPFunctions_GameplayTag::GetDirectGameplayTagChildren(Z_Param_InTag,Z_Param_bIsContainOriginal);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_GameplayTag Function GetDirectGameplayTagChildren *************

// ********** Begin Class UBPFunctions_GameplayTag Function GetDirectGameplayTagParent *************
struct Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics
{
	struct BPFunctions_GameplayTag_eventGetDirectGameplayTagParent_Parms
	{
		FGameplayTag InTag;
		FGameplayTag ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96""DirectGameplay\xe6\xa0\x87\xe7\xad\xbeParent\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_GameplayTag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96""DirectGameplay\xe6\xa0\x87\xe7\xad\xbeParent\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetDirectGameplayTagParent constinit property declarations ************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTag;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetDirectGameplayTagParent constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetDirectGameplayTagParent Property Definitions ***********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::NewProp_InTag = { "InTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventGetDirectGameplayTagParent_Parms, InTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventGetDirectGameplayTagParent_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::NewProp_InTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::PropPointers) < 2048);
// ********** End Function GetDirectGameplayTagParent Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_GameplayTag, nullptr, "GetDirectGameplayTagParent", 	Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::BPFunctions_GameplayTag_eventGetDirectGameplayTagParent_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::BPFunctions_GameplayTag_eventGetDirectGameplayTagParent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_GameplayTag::execGetDirectGameplayTagParent)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_InTag);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTag*)Z_Param__Result=UBPFunctions_GameplayTag::GetDirectGameplayTagParent(Z_Param_InTag);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_GameplayTag Function GetDirectGameplayTagParent ***************

// ********** Begin Class UBPFunctions_GameplayTag Function GetGameplayTagChildren *****************
struct Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics
{
	struct BPFunctions_GameplayTag_eventGetGameplayTagChildren_Parms
	{
		FGameplayTag InTag;
		bool bIsContainOriginal;
		FGameplayTagContainer ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96Gameplay\xe6\xa0\x87\xe7\xad\xbe""Children\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_bIsContainOriginal", "false" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_GameplayTag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96Gameplay\xe6\xa0\x87\xe7\xad\xbe""Children\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGameplayTagChildren constinit property declarations ****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTag;
	static void NewProp_bIsContainOriginal_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsContainOriginal;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGameplayTagChildren constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGameplayTagChildren Property Definitions ***************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::NewProp_InTag = { "InTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventGetGameplayTagChildren_Parms, InTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::NewProp_bIsContainOriginal_SetBit(void* Obj)
{
	((BPFunctions_GameplayTag_eventGetGameplayTagChildren_Parms*)Obj)->bIsContainOriginal = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::NewProp_bIsContainOriginal = { "bIsContainOriginal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_GameplayTag_eventGetGameplayTagChildren_Parms), &Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::NewProp_bIsContainOriginal_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventGetGameplayTagChildren_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::NewProp_InTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::NewProp_bIsContainOriginal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::PropPointers) < 2048);
// ********** End Function GetGameplayTagChildren Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_GameplayTag, nullptr, "GetGameplayTagChildren", 	Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::BPFunctions_GameplayTag_eventGetGameplayTagChildren_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::BPFunctions_GameplayTag_eventGetGameplayTagChildren_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_GameplayTag::execGetGameplayTagChildren)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_InTag);
	P_GET_UBOOL(Z_Param_bIsContainOriginal);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTagContainer*)Z_Param__Result=UBPFunctions_GameplayTag::GetGameplayTagChildren(Z_Param_InTag,Z_Param_bIsContainOriginal);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_GameplayTag Function GetGameplayTagChildren *******************

// ********** Begin Class UBPFunctions_GameplayTag Function GetGameplayTagParents ******************
struct Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics
{
	struct BPFunctions_GameplayTag_eventGetGameplayTagParents_Parms
	{
		FGameplayTag InTag;
		bool bIsContainOriginal;
		FGameplayTagContainer ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "GameplayTag" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xaf\xbb\xe5\x8f\x96Gameplay\xe6\xa0\x87\xe7\xad\xbeParents\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "CPP_Default_bIsContainOriginal", "false" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_GameplayTag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xaf\xbb\xe5\x8f\x96Gameplay\xe6\xa0\x87\xe7\xad\xbeParents\xef\xbc\x8c\xe5\xb0\x81\xe8\xa3\x85\xe5\xba\x95\xe5\xb1\x82\xe6\x9f\xa5\xe8\xaf\xa2\xe7\xbb\x86\xe8\x8a\x82\xe5\xb9\xb6\xe5\x87\x8f\xe5\xb0\x91\xe8\x93\x9d\xe5\x9b\xbe\xe4\xbe\xa7\xe6\xa0\xb7\xe6\x9d\xbf\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetGameplayTagParents constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_InTag;
	static void NewProp_bIsContainOriginal_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsContainOriginal;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetGameplayTagParents constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetGameplayTagParents Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::NewProp_InTag = { "InTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventGetGameplayTagParents_Parms, InTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
void Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::NewProp_bIsContainOriginal_SetBit(void* Obj)
{
	((BPFunctions_GameplayTag_eventGetGameplayTagParents_Parms*)Obj)->bIsContainOriginal = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::NewProp_bIsContainOriginal = { "bIsContainOriginal", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BPFunctions_GameplayTag_eventGetGameplayTagParents_Parms), &Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::NewProp_bIsContainOriginal_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BPFunctions_GameplayTag_eventGetGameplayTagParents_Parms, ReturnValue), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(0, nullptr) }; // 3438578166
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::NewProp_InTag,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::NewProp_bIsContainOriginal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::PropPointers) < 2048);
// ********** End Function GetGameplayTagParents Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBPFunctions_GameplayTag, nullptr, "GetGameplayTagParents", 	Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::BPFunctions_GameplayTag_eventGetGameplayTagParents_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::BPFunctions_GameplayTag_eventGetGameplayTagParents_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UBPFunctions_GameplayTag::execGetGameplayTagParents)
{
	P_GET_STRUCT(FGameplayTag,Z_Param_InTag);
	P_GET_UBOOL(Z_Param_bIsContainOriginal);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FGameplayTagContainer*)Z_Param__Result=UBPFunctions_GameplayTag::GetGameplayTagParents(Z_Param_InTag,Z_Param_bIsContainOriginal);
	P_NATIVE_END;
}
// ********** End Class UBPFunctions_GameplayTag Function GetGameplayTagParents ********************

// ********** Begin Class UBPFunctions_GameplayTag *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBPFunctions_GameplayTag;
UClass* UBPFunctions_GameplayTag::GetPrivateStaticClass()
{
	using TClass = UBPFunctions_GameplayTag;
	if (!Z_Registration_Info_UClass_UBPFunctions_GameplayTag.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BPFunctions_GameplayTag"),
			Z_Registration_Info_UClass_UBPFunctions_GameplayTag.InnerSingleton,
			StaticRegisterNativesUBPFunctions_GameplayTag,
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
	return Z_Registration_Info_UClass_UBPFunctions_GameplayTag.InnerSingleton;
}
UClass* Z_Construct_UClass_UBPFunctions_GameplayTag_NoRegister()
{
	return UBPFunctions_GameplayTag::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBPFunctions_GameplayTag_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2Gameplay\xe6\xa0\x87\xe7\xad\xbe\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "BPFunctions/BPFunctions_GameplayTag.h" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_GameplayTag.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2Gameplay\xe6\xa0\x87\xe7\xad\xbe\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xaeUnreal \xe9\x80\x9a\xe7\x94\xa8\xe5\xb7\xa5\xe5\x85\xb7\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBPFunctions_GameplayTag constinit property declarations *****************
// ********** End Class UBPFunctions_GameplayTag constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Conv_GameplayTagToName"), .Pointer = &UBPFunctions_GameplayTag::execConv_GameplayTagToName },
		{ .NameUTF8 = UTF8TEXT("Conv_GameplayTagToString"), .Pointer = &UBPFunctions_GameplayTag::execConv_GameplayTagToString },
		{ .NameUTF8 = UTF8TEXT("Conv_NameToGameplayTag"), .Pointer = &UBPFunctions_GameplayTag::execConv_NameToGameplayTag },
		{ .NameUTF8 = UTF8TEXT("Conv_StringToGameplayTag"), .Pointer = &UBPFunctions_GameplayTag::execConv_StringToGameplayTag },
		{ .NameUTF8 = UTF8TEXT("GetDirectGameplayTagChildren"), .Pointer = &UBPFunctions_GameplayTag::execGetDirectGameplayTagChildren },
		{ .NameUTF8 = UTF8TEXT("GetDirectGameplayTagParent"), .Pointer = &UBPFunctions_GameplayTag::execGetDirectGameplayTagParent },
		{ .NameUTF8 = UTF8TEXT("GetGameplayTagChildren"), .Pointer = &UBPFunctions_GameplayTag::execGetGameplayTagChildren },
		{ .NameUTF8 = UTF8TEXT("GetGameplayTagParents"), .Pointer = &UBPFunctions_GameplayTag::execGetGameplayTagParents },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToName, "Conv_GameplayTagToName" }, // 1688576263
		{ &Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_GameplayTagToString, "Conv_GameplayTagToString" }, // 142310730
		{ &Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_NameToGameplayTag, "Conv_NameToGameplayTag" }, // 1359364729
		{ &Z_Construct_UFunction_UBPFunctions_GameplayTag_Conv_StringToGameplayTag, "Conv_StringToGameplayTag" }, // 759375399
		{ &Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagChildren, "GetDirectGameplayTagChildren" }, // 4206128295
		{ &Z_Construct_UFunction_UBPFunctions_GameplayTag_GetDirectGameplayTagParent, "GetDirectGameplayTagParent" }, // 1459978702
		{ &Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagChildren, "GetGameplayTagChildren" }, // 2749851275
		{ &Z_Construct_UFunction_UBPFunctions_GameplayTag_GetGameplayTagParents, "GetGameplayTagParents" }, // 3581904607
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctions_GameplayTag>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBPFunctions_GameplayTag_Statics
UObject* (*const Z_Construct_UClass_UBPFunctions_GameplayTag_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_UnrealMisc,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_GameplayTag_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctions_GameplayTag_Statics::ClassParams = {
	&UBPFunctions_GameplayTag::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_GameplayTag_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPFunctions_GameplayTag_Statics::Class_MetaDataParams)
};
void UBPFunctions_GameplayTag::StaticRegisterNativesUBPFunctions_GameplayTag()
{
	UClass* Class = UBPFunctions_GameplayTag::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UBPFunctions_GameplayTag_Statics::Funcs));
}
UClass* Z_Construct_UClass_UBPFunctions_GameplayTag()
{
	if (!Z_Registration_Info_UClass_UBPFunctions_GameplayTag.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPFunctions_GameplayTag.OuterSingleton, Z_Construct_UClass_UBPFunctions_GameplayTag_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPFunctions_GameplayTag.OuterSingleton;
}
UBPFunctions_GameplayTag::UBPFunctions_GameplayTag(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBPFunctions_GameplayTag);
UBPFunctions_GameplayTag::~UBPFunctions_GameplayTag() {}
// ********** End Class UBPFunctions_GameplayTag ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h__Script_UnrealMisc_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPFunctions_GameplayTag, UBPFunctions_GameplayTag::StaticClass, TEXT("UBPFunctions_GameplayTag"), &Z_Registration_Info_UClass_UBPFunctions_GameplayTag, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPFunctions_GameplayTag), 2345594096U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h__Script_UnrealMisc_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h__Script_UnrealMisc_3387217183{
	TEXT("/Script/UnrealMisc"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h__Script_UnrealMisc_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h__Script_UnrealMisc_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
