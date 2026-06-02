// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Types/GenericVersionTypes.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericVersionTypes() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GENERICVERSIONFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionContext();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionData();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionDefinition();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionInfo();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionMigrationResult();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionValidationResult();
UPackage* Z_Construct_UPackage__Script_GenericVersionFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FGenericVersionInfo ***********************************************
struct Z_Construct_UScriptStruct_FGenericVersionInfo_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGenericVersionInfo); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGenericVersionInfo); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x9a\xe5\x8a\xa1\xe6\x95\xb0\xe6\x8d\xae\xe7\xbb\x93\xe6\x9e\x84\xe7\x89\x88\xe6\x9c\xac\xef\xbc\x8c\xe7\x89\x88\xe6\x9c\xac\xe5\x8f\xb7\xe5\x8f\xaa\xe9\x9a\x8f\xe6\x95\xb0\xe6\x8d\xae\xe8\xaf\xad\xe4\xb9\x89\xe5\x8f\x98\xe5\x8c\x96\xe8\x80\x8c\xe5\x8f\x98\xe5\x8c\x96\xef\xbc\x8c\xe4\xb8\x8d\xe5\xaf\xb9\xe5\xba\x94\xe9\xa1\xb9\xe7\x9b\xae\xe6\x89\x93\xe5\x8c\x85\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x9a\xe5\x8a\xa1\xe6\x95\xb0\xe6\x8d\xae\xe7\xbb\x93\xe6\x9e\x84\xe7\x89\x88\xe6\x9c\xac\xef\xbc\x8c\xe7\x89\x88\xe6\x9c\xac\xe5\x8f\xb7\xe5\x8f\xaa\xe9\x9a\x8f\xe6\x95\xb0\xe6\x8d\xae\xe8\xaf\xad\xe4\xb9\x89\xe5\x8f\x98\xe5\x8c\x96\xe8\x80\x8c\xe5\x8f\x98\xe5\x8c\x96\xef\xbc\x8c\xe4\xb8\x8d\xe5\xaf\xb9\xe5\xba\x94\xe9\xa1\xb9\xe7\x9b\xae\xe6\x89\x93\xe5\x8c\x85\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Major_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xb8\xbb\xe7\x89\x88\xe6\x9c\xac\xe5\x8f\xb7\xef\xbc\x8c\xe9\x80\x9a\xe5\xb8\xb8\xe7\x94\xa8\xe4\xba\x8e\xe7\xa0\xb4\xe5\x9d\x8f\xe6\x80\xa7\xe6\x95\xb0\xe6\x8d\xae\xe7\xbb\x93\xe6\x9e\x84\xe5\x8f\x98\xe5\x8c\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\xbb\xe7\x89\x88\xe6\x9c\xac\xe5\x8f\xb7\xef\xbc\x8c\xe9\x80\x9a\xe5\xb8\xb8\xe7\x94\xa8\xe4\xba\x8e\xe7\xa0\xb4\xe5\x9d\x8f\xe6\x80\xa7\xe6\x95\xb0\xe6\x8d\xae\xe7\xbb\x93\xe6\x9e\x84\xe5\x8f\x98\xe5\x8c\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Minor_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xac\xa1\xe7\x89\x88\xe6\x9c\xac\xe5\x8f\xb7\xef\xbc\x8c\xe9\x80\x9a\xe5\xb8\xb8\xe7\x94\xa8\xe4\xba\x8e\xe5\xad\x97\xe6\xae\xb5\xe5\xa2\x9e\xe5\x88\xa0\xe3\x80\x81\xe9\x87\x8d\xe5\x91\xbd\xe5\x90\x8d\xe6\x88\x96\xe6\x9e\x9a\xe4\xb8\xbe\xe5\x85\xbc\xe5\xae\xb9\xe8\xb0\x83\xe6\x95\xb4\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xac\xa1\xe7\x89\x88\xe6\x9c\xac\xe5\x8f\xb7\xef\xbc\x8c\xe9\x80\x9a\xe5\xb8\xb8\xe7\x94\xa8\xe4\xba\x8e\xe5\xad\x97\xe6\xae\xb5\xe5\xa2\x9e\xe5\x88\xa0\xe3\x80\x81\xe9\x87\x8d\xe5\x91\xbd\xe5\x90\x8d\xe6\x88\x96\xe6\x9e\x9a\xe4\xb8\xbe\xe5\x85\xbc\xe5\xae\xb9\xe8\xb0\x83\xe6\x95\xb4\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Patch_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\xae\xe8\xae\xa2\xe7\x89\x88\xe6\x9c\xac\xe5\x8f\xb7\xef\xbc\x8c\xe9\x80\x9a\xe5\xb8\xb8\xe7\x94\xa8\xe4\xba\x8e\xe9\xbb\x98\xe8\xae\xa4\xe5\x80\xbc\xe4\xbf\xae\xe6\xad\xa3\xe6\x88\x96\xe5\xb0\x8f\xe8\x8c\x83\xe5\x9b\xb4\xe6\x95\xb0\xe6\x8d\xae\xe6\xb8\x85\xe7\x90\x86\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\xae\xe8\xae\xa2\xe7\x89\x88\xe6\x9c\xac\xe5\x8f\xb7\xef\xbc\x8c\xe9\x80\x9a\xe5\xb8\xb8\xe7\x94\xa8\xe4\xba\x8e\xe9\xbb\x98\xe8\xae\xa4\xe5\x80\xbc\xe4\xbf\xae\xe6\xad\xa3\xe6\x88\x96\xe5\xb0\x8f\xe8\x8c\x83\xe5\x9b\xb4\xe6\x95\xb0\xe6\x8d\xae\xe6\xb8\x85\xe7\x90\x86\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGenericVersionInfo constinit property declarations ***************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Major;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Minor;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Patch;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGenericVersionInfo constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGenericVersionInfo>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGenericVersionInfo_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGenericVersionInfo;
class UScriptStruct* FGenericVersionInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGenericVersionInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGenericVersionInfo, (UObject*)Z_Construct_UPackage__Script_GenericVersionFramework(), TEXT("GenericVersionInfo"));
	}
	return Z_Registration_Info_UScriptStruct_FGenericVersionInfo.OuterSingleton;
	}

// ********** Begin ScriptStruct FGenericVersionInfo Property Definitions **************************
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::NewProp_Major = { "Major", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionInfo, Major), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Major_MetaData), NewProp_Major_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::NewProp_Minor = { "Minor", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionInfo, Minor), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Minor_MetaData), NewProp_Minor_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::NewProp_Patch = { "Patch", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionInfo, Patch), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Patch_MetaData), NewProp_Patch_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::NewProp_Major,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::NewProp_Minor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::NewProp_Patch,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGenericVersionInfo Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericVersionFramework,
	nullptr,
	&NewStructOps,
	"GenericVersionInfo",
	Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::PropPointers),
	sizeof(FGenericVersionInfo),
	alignof(FGenericVersionInfo),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionInfo()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionInfo.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGenericVersionInfo.InnerSingleton, Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGenericVersionInfo.InnerSingleton);
}
// ********** End ScriptStruct FGenericVersionInfo *************************************************

// ********** Begin ScriptStruct FGenericVersionDefinition *****************************************
struct Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGenericVersionDefinition); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGenericVersionDefinition); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe8\xa1\xa8\xe7\xa4\xba\xe9\xa1\xb9\xe7\x9b\xae\xe5\xbd\x93\xe5\x89\x8d\xe4\xbb\xa3\xe7\xa0\x81\xe5\xaf\xb9\xe6\x9f\x90\xe7\xb1\xbb\xe6\x95\xb0\xe6\x8d\xae\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe7\xad\x96\xe7\x95\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xef\xbc\x8c\xe8\xa1\xa8\xe7\xa4\xba\xe9\xa1\xb9\xe7\x9b\xae\xe5\xbd\x93\xe5\x89\x8d\xe4\xbb\xa3\xe7\xa0\x81\xe5\xaf\xb9\xe6\x9f\x90\xe7\xb1\xbb\xe6\x95\xb0\xe6\x8d\xae\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe7\xad\x96\xe7\x95\xa5\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionKey_MetaData[] = {
		{ "Categories", "GameplayVersion" },
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\x94\xa8\xe4\xba\x8e\xe5\x8c\xb9\xe9\x85\x8d\xe4\xb8\x9a\xe5\x8a\xa1\xe6\x95\xb0\xe6\x8d\xae\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe7\xa8\xb3\xe5\xae\x9a\xe7\x89\x88\xe6\x9c\xac\xe9\x94\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x94\xa8\xe4\xba\x8e\xe5\x8c\xb9\xe9\x85\x8d\xe4\xb8\x9a\xe5\x8a\xa1\xe6\x95\xb0\xe6\x8d\xae\xe7\xb1\xbb\xe5\x9e\x8b\xe7\x9a\x84\xe7\xa8\xb3\xe5\xae\x9a\xe7\x89\x88\xe6\x9c\xac\xe9\x94\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xbd\x93\xe5\x89\x8d\xe4\xbb\xa3\xe7\xa0\x81\xe5\x8f\xaf\xe5\x86\x99\xe5\x87\xba\xe7\x9a\x84\xe6\x95\xb0\xe6\x8d\xae\xe7\x89\x88\xe6\x9c\xac\xef\xbc\x8c\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xaf\xb9\xe8\xb1\xa1\xe8\x87\xaa\xe5\xb7\xb1\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe4\xbc\x9a\xe4\xb8\x8e\xe5\xae\x83\xe8\xbf\x9b\xe8\xa1\x8c\xe6\xaf\x94\xe8\xbe\x83\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe4\xbb\xa3\xe7\xa0\x81\xe5\x8f\xaf\xe5\x86\x99\xe5\x87\xba\xe7\x9a\x84\xe6\x95\xb0\xe6\x8d\xae\xe7\x89\x88\xe6\x9c\xac\xef\xbc\x8c\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xaf\xb9\xe8\xb1\xa1\xe8\x87\xaa\xe5\xb7\xb1\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe4\xbc\x9a\xe4\xb8\x8e\xe5\xae\x83\xe8\xbf\x9b\xe8\xa1\x8c\xe6\xaf\x94\xe8\xbe\x83\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimumSupportedVersion_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xbd\x93\xe5\x89\x8d\xe4\xbb\xa3\xe7\xa0\x81\xe4\xbb\x8d\xe5\x85\x81\xe8\xae\xb8\xe5\xa4\x84\xe7\x90\x86\xe7\x9a\x84\xe6\x9c\x80\xe4\xbd\x8e\xe6\x95\xb0\xe6\x8d\xae\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe4\xbb\xa3\xe7\xa0\x81\xe4\xbb\x8d\xe5\x85\x81\xe8\xae\xb8\xe5\xa4\x84\xe7\x90\x86\xe7\x9a\x84\xe6\x9c\x80\xe4\xbd\x8e\xe6\x95\xb0\xe6\x8d\xae\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceName_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x95\xb0\xe6\x8d\xae\xe6\x9d\xa5\xe6\xba\x90\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x8c\xe4\xbb\x85\xe7\x94\xa8\xe4\xba\x8e\xe6\x97\xa5\xe5\xbf\x97\xe3\x80\x81\xe8\xb0\x83\xe8\xaf\x95\xe6\x88\x96\xe7\x95\x8c\xe9\x9d\xa2\xe5\xb1\x95\xe7\xa4\xba\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x95\xb0\xe6\x8d\xae\xe6\x9d\xa5\xe6\xba\x90\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x8c\xe4\xbb\x85\xe7\x94\xa8\xe4\xba\x8e\xe6\x97\xa5\xe5\xbf\x97\xe3\x80\x81\xe8\xb0\x83\xe8\xaf\x95\xe6\x88\x96\xe7\x95\x8c\xe9\x9d\xa2\xe5\xb1\x95\xe7\xa4\xba\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGenericVersionDefinition constinit property declarations *********
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Version;
	static const UECodeGen_Private::FStructPropertyParams NewProp_MinimumSupportedVersion;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SourceName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGenericVersionDefinition constinit property declarations ***********
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGenericVersionDefinition>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGenericVersionDefinition;
class UScriptStruct* FGenericVersionDefinition::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionDefinition.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGenericVersionDefinition.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGenericVersionDefinition, (UObject*)Z_Construct_UPackage__Script_GenericVersionFramework(), TEXT("GenericVersionDefinition"));
	}
	return Z_Registration_Info_UScriptStruct_FGenericVersionDefinition.OuterSingleton;
	}

// ********** Begin ScriptStruct FGenericVersionDefinition Property Definitions ********************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::NewProp_VersionKey = { "VersionKey", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionDefinition, VersionKey), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionKey_MetaData), NewProp_VersionKey_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionDefinition, Version), Z_Construct_UScriptStruct_FGenericVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Version_MetaData), NewProp_Version_MetaData) }; // 2499025735
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::NewProp_MinimumSupportedVersion = { "MinimumSupportedVersion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionDefinition, MinimumSupportedVersion), Z_Construct_UScriptStruct_FGenericVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimumSupportedVersion_MetaData), NewProp_MinimumSupportedVersion_MetaData) }; // 2499025735
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::NewProp_SourceName = { "SourceName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionDefinition, SourceName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceName_MetaData), NewProp_SourceName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::NewProp_VersionKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::NewProp_Version,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::NewProp_MinimumSupportedVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::NewProp_SourceName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGenericVersionDefinition Property Definitions **********************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericVersionFramework,
	nullptr,
	&NewStructOps,
	"GenericVersionDefinition",
	Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::PropPointers),
	sizeof(FGenericVersionDefinition),
	alignof(FGenericVersionDefinition),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionDefinition()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionDefinition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGenericVersionDefinition.InnerSingleton, Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGenericVersionDefinition.InnerSingleton);
}
// ********** End ScriptStruct FGenericVersionDefinition *******************************************

// ********** Begin ScriptStruct FGenericVersionData ***********************************************
struct Z_Construct_UScriptStruct_FGenericVersionData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGenericVersionData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGenericVersionData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xaf\xb9\xe8\xb1\xa1\xe8\x87\xaa\xe8\xba\xab\xe6\x90\xba\xe5\xb8\xa6\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe5\x8f\xaa\xe6\x8f\x8f\xe8\xbf\xb0\xe7\xa3\x81\xe7\x9b\x98\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xbd\x93\xe5\x89\x8d\xe5\xa4\x84\xe4\xba\x8e\xe5\x93\xaa\xe4\xb8\xaa\xe6\x95\xb0\xe6\x8d\xae\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xaf\xb9\xe8\xb1\xa1\xe8\x87\xaa\xe8\xba\xab\xe6\x90\xba\xe5\xb8\xa6\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe5\x8f\xaa\xe6\x8f\x8f\xe8\xbf\xb0\xe7\xa3\x81\xe7\x9b\x98\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xbd\x93\xe5\x89\x8d\xe5\xa4\x84\xe4\xba\x8e\xe5\x93\xaa\xe4\xb8\xaa\xe6\x95\xb0\xe6\x8d\xae\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionKey_MetaData[] = {
		{ "Categories", "GameplayVersion" },
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe6\x8f\x90\xe4\xbe\x9b\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe9\x94\xae\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x9c\xa8\xe4\xb8\xad\xe5\xbf\x83\xe8\xa1\xa8\xe4\xb8\xad\xe5\xae\x9a\xe4\xbd\x8d\xe5\x90\x8c\xe4\xb8\x80\xe7\xb1\xbb\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe6\x8f\x90\xe4\xbe\x9b\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe9\x94\xae\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x9c\xa8\xe4\xb8\xad\xe5\xbf\x83\xe8\xa1\xa8\xe4\xb8\xad\xe5\xae\x9a\xe4\xbd\x8d\xe5\x90\x8c\xe4\xb8\x80\xe7\xb1\xbb\xe6\x95\xb0\xe6\x8d\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Version_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xaf\xb9\xe8\xb1\xa1\xe5\xbd\x93\xe5\x89\x8d\xe6\x90\xba\xe5\xb8\xa6\xe7\x9a\x84\xe6\x95\xb0\xe6\x8d\xae\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xbd\x93\xe5\x89\x8d\xe6\x90\xba\xe5\xb8\xa6\xe7\x9a\x84\xe6\x95\xb0\xe6\x8d\xae\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceName_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x95\xb0\xe6\x8d\xae\xe6\x9d\xa5\xe6\xba\x90\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x8c\xe4\xbb\x85\xe7\x94\xa8\xe4\xba\x8e\xe6\x97\xa5\xe5\xbf\x97\xe3\x80\x81\xe8\xb0\x83\xe8\xaf\x95\xe6\x88\x96\xe7\x95\x8c\xe9\x9d\xa2\xe5\xb1\x95\xe7\xa4\xba\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x95\xb0\xe6\x8d\xae\xe6\x9d\xa5\xe6\xba\x90\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x8c\xe4\xbb\x85\xe7\x94\xa8\xe4\xba\x8e\xe6\x97\xa5\xe5\xbf\x97\xe3\x80\x81\xe8\xb0\x83\xe8\xaf\x95\xe6\x88\x96\xe7\x95\x8c\xe9\x9d\xa2\xe5\xb1\x95\xe7\xa4\xba\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGenericVersionData constinit property declarations ***************
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Version;
	static const UECodeGen_Private::FStrPropertyParams NewProp_SourceName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGenericVersionData constinit property declarations *****************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGenericVersionData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGenericVersionData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGenericVersionData;
class UScriptStruct* FGenericVersionData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGenericVersionData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGenericVersionData, (UObject*)Z_Construct_UPackage__Script_GenericVersionFramework(), TEXT("GenericVersionData"));
	}
	return Z_Registration_Info_UScriptStruct_FGenericVersionData.OuterSingleton;
	}

// ********** Begin ScriptStruct FGenericVersionData Property Definitions **************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGenericVersionData_Statics::NewProp_VersionKey = { "VersionKey", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionData, VersionKey), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionKey_MetaData), NewProp_VersionKey_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGenericVersionData_Statics::NewProp_Version = { "Version", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionData, Version), Z_Construct_UScriptStruct_FGenericVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Version_MetaData), NewProp_Version_MetaData) }; // 2499025735
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FGenericVersionData_Statics::NewProp_SourceName = { "SourceName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionData, SourceName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceName_MetaData), NewProp_SourceName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGenericVersionData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionData_Statics::NewProp_VersionKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionData_Statics::NewProp_Version,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionData_Statics::NewProp_SourceName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGenericVersionData Property Definitions ****************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGenericVersionData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericVersionFramework,
	nullptr,
	&NewStructOps,
	"GenericVersionData",
	Z_Construct_UScriptStruct_FGenericVersionData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionData_Statics::PropPointers),
	sizeof(FGenericVersionData),
	alignof(FGenericVersionData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGenericVersionData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionData()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGenericVersionData.InnerSingleton, Z_Construct_UScriptStruct_FGenericVersionData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGenericVersionData.InnerSingleton);
}
// ********** End ScriptStruct FGenericVersionData *************************************************

// ********** Begin Enum EGenericVersionValidationStatus *******************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGenericVersionValidationStatus;
static UEnum* EGenericVersionValidationStatus_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGenericVersionValidationStatus.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGenericVersionValidationStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus, (UObject*)Z_Construct_UPackage__Script_GenericVersionFramework(), TEXT("EGenericVersionValidationStatus"));
	}
	return Z_Registration_Info_UEnum_EGenericVersionValidationStatus.OuterSingleton;
}
template<> GENERICVERSIONFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EGenericVersionValidationStatus>()
{
	return EGenericVersionValidationStatus_StaticEnum();
}
struct Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\xa1\xe9\xaa\x8c\xe7\xbb\x93\xe6\x9e\x9c\xe5\xaf\xb9\xe4\xb8\x9a\xe5\x8a\xa1\xe6\xb5\x81\xe7\xa8\x8b\xe7\x9a\x84\xe5\xbd\xb1\xe5\x93\x8d\xe7\xba\xa7\xe5\x88\xab\xe3\x80\x82 */" },
#endif
		{ "Failed.Comment", "/** \xe6\xa0\xa1\xe9\xaa\x8c\xe5\xa4\xb1\xe8\xb4\xa5\xef\xbc\x8c\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\xba\x94\xe5\x81\x9c\xe6\xad\xa2\xe4\xbe\x9d\xe8\xb5\x96\xe8\xaf\xa5\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe3\x80\x82 */" },
		{ "Failed.Name", "EGenericVersionValidationStatus::Failed" },
		{ "Failed.ToolTip", "\xe6\xa0\xa1\xe9\xaa\x8c\xe5\xa4\xb1\xe8\xb4\xa5\xef\xbc\x8c\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\xba\x94\xe5\x81\x9c\xe6\xad\xa2\xe4\xbe\x9d\xe8\xb5\x96\xe8\xaf\xa5\xe5\xaf\xb9\xe8\xb1\xa1\xe7\x9a\x84\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
		{ "Success.Comment", "/** \xe6\xa0\xa1\xe9\xaa\x8c\xe9\x80\x9a\xe8\xbf\x87\xef\xbc\x8c\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\x8f\xaf\xe7\xbb\xa7\xe7\xbb\xad\xe8\x87\xaa\xe5\xb7\xb1\xe7\x9a\x84\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe3\x80\x82 */" },
		{ "Success.Name", "EGenericVersionValidationStatus::Success" },
		{ "Success.ToolTip", "\xe6\xa0\xa1\xe9\xaa\x8c\xe9\x80\x9a\xe8\xbf\x87\xef\xbc\x8c\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\x8f\xaf\xe7\xbb\xa7\xe7\xbb\xad\xe8\x87\xaa\xe5\xb7\xb1\xe7\x9a\x84\xe5\x90\x8e\xe7\xbb\xad\xe6\xb5\x81\xe7\xa8\x8b\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\xa1\xe9\xaa\x8c\xe7\xbb\x93\xe6\x9e\x9c\xe5\xaf\xb9\xe4\xb8\x9a\xe5\x8a\xa1\xe6\xb5\x81\xe7\xa8\x8b\xe7\x9a\x84\xe5\xbd\xb1\xe5\x93\x8d\xe7\xba\xa7\xe5\x88\xab\xe3\x80\x82" },
#endif
		{ "Warning.Comment", "/** \xe6\xa0\xa1\xe9\xaa\x8c\xe5\x8f\x91\xe7\x8e\xb0\xe9\x9d\x9e\xe9\x98\xbb\xe6\x96\xad\xe9\x97\xae\xe9\xa2\x98\xef\xbc\x8c\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\x8f\xaf\xe8\x87\xaa\xe8\xa1\x8c\xe5\x86\xb3\xe5\xae\x9a\xe6\x98\xaf\xe5\x90\xa6\xe6\x8f\x90\xe7\xa4\xba\xe6\x88\x96\xe8\xae\xb0\xe5\xbd\x95\xe3\x80\x82 */" },
		{ "Warning.Name", "EGenericVersionValidationStatus::Warning" },
		{ "Warning.ToolTip", "\xe6\xa0\xa1\xe9\xaa\x8c\xe5\x8f\x91\xe7\x8e\xb0\xe9\x9d\x9e\xe9\x98\xbb\xe6\x96\xad\xe9\x97\xae\xe9\xa2\x98\xef\xbc\x8c\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\x8f\xaf\xe8\x87\xaa\xe8\xa1\x8c\xe5\x86\xb3\xe5\xae\x9a\xe6\x98\xaf\xe5\x90\xa6\xe6\x8f\x90\xe7\xa4\xba\xe6\x88\x96\xe8\xae\xb0\xe5\xbd\x95\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGenericVersionValidationStatus::Success", (int64)EGenericVersionValidationStatus::Success },
		{ "EGenericVersionValidationStatus::Warning", (int64)EGenericVersionValidationStatus::Warning },
		{ "EGenericVersionValidationStatus::Failed", (int64)EGenericVersionValidationStatus::Failed },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericVersionFramework,
	nullptr,
	"EGenericVersionValidationStatus",
	"EGenericVersionValidationStatus",
	Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus()
{
	if (!Z_Registration_Info_UEnum_EGenericVersionValidationStatus.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGenericVersionValidationStatus.InnerSingleton, Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGenericVersionValidationStatus.InnerSingleton;
}
// ********** End Enum EGenericVersionValidationStatus *********************************************

// ********** Begin ScriptStruct FGenericVersionValidationResult ***********************************
struct Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGenericVersionValidationResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGenericVersionValidationResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\x89\x88\xe6\x9c\xac\xe6\xa0\xa1\xe9\xaa\x8c\xe7\x9a\x84\xe5\x8d\x95\xe6\xac\xa1\xe6\x89\xa7\xe8\xa1\x8c\xe7\xbb\x93\xe6\x9e\x9c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x89\x88\xe6\x9c\xac\xe6\xa0\xa1\xe9\xaa\x8c\xe7\x9a\x84\xe5\x8d\x95\xe6\xac\xa1\xe6\x89\xa7\xe8\xa1\x8c\xe7\xbb\x93\xe6\x9e\x9c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Status_MetaData[] = {
		{ "Category", "Version Validation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9c\xac\xe6\xac\xa1\xe6\xa0\xa1\xe9\xaa\x8c\xe7\x9a\x84\xe7\xbb\x93\xe6\x9e\x9c\xe7\xba\xa7\xe5\x88\xab\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9c\xac\xe6\xac\xa1\xe6\xa0\xa1\xe9\xaa\x8c\xe7\x9a\x84\xe7\xbb\x93\xe6\x9e\x9c\xe7\xba\xa7\xe5\x88\xab\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorCode_MetaData[] = {
		{ "Category", "Version Validation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\x8f\xaf\xe7\x94\xa8\xe4\xba\x8e\xe8\xaf\x86\xe5\x88\xab\xe9\x97\xae\xe9\xa2\x98\xe6\x9d\xa5\xe6\xba\x90\xe7\x9a\x84\xe7\xa8\xb3\xe5\xae\x9a\xe9\x94\x99\xe8\xaf\xaf\xe7\xa0\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe5\x8f\xaf\xe7\x94\xa8\xe4\xba\x8e\xe8\xaf\x86\xe5\x88\xab\xe9\x97\xae\xe9\xa2\x98\xe6\x9d\xa5\xe6\xba\x90\xe7\x9a\x84\xe7\xa8\xb3\xe5\xae\x9a\xe9\x94\x99\xe8\xaf\xaf\xe7\xa0\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "Version Validation" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x9d\xa2\xe5\x90\x91\xe6\x97\xa5\xe5\xbf\x97\xe3\x80\x81\xe6\x8f\x90\xe7\xa4\xba\xe6\x88\x96\xe8\xb0\x83\xe8\xaf\x95\xe9\x9d\xa2\xe6\x9d\xbf\xe7\x9a\x84\xe8\xaf\xb4\xe6\x98\x8e\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x9d\xa2\xe5\x90\x91\xe6\x97\xa5\xe5\xbf\x97\xe3\x80\x81\xe6\x8f\x90\xe7\xa4\xba\xe6\x88\x96\xe8\xb0\x83\xe8\xaf\x95\xe9\x9d\xa2\xe6\x9d\xbf\xe7\x9a\x84\xe8\xaf\xb4\xe6\x98\x8e\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGenericVersionValidationResult constinit property declarations ***
	static const UECodeGen_Private::FBytePropertyParams NewProp_Status_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_Status;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ErrorCode;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGenericVersionValidationResult constinit property declarations *****
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGenericVersionValidationResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGenericVersionValidationResult;
class UScriptStruct* FGenericVersionValidationResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionValidationResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGenericVersionValidationResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGenericVersionValidationResult, (UObject*)Z_Construct_UPackage__Script_GenericVersionFramework(), TEXT("GenericVersionValidationResult"));
	}
	return Z_Registration_Info_UScriptStruct_FGenericVersionValidationResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FGenericVersionValidationResult Property Definitions **************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::NewProp_Status_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::NewProp_Status = { "Status", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionValidationResult, Status), Z_Construct_UEnum_GenericVersionFramework_EGenericVersionValidationStatus, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Status_MetaData), NewProp_Status_MetaData) }; // 1185831510
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionValidationResult, ErrorCode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorCode_MetaData), NewProp_ErrorCode_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionValidationResult, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::NewProp_Status_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::NewProp_Status,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::NewProp_ErrorCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGenericVersionValidationResult Property Definitions ****************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericVersionFramework,
	nullptr,
	&NewStructOps,
	"GenericVersionValidationResult",
	Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::PropPointers),
	sizeof(FGenericVersionValidationResult),
	alignof(FGenericVersionValidationResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionValidationResult()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionValidationResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGenericVersionValidationResult.InnerSingleton, Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGenericVersionValidationResult.InnerSingleton);
}
// ********** End ScriptStruct FGenericVersionValidationResult *************************************

// ********** Begin ScriptStruct FGenericVersionMigrationResult ************************************
struct Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGenericVersionMigrationResult); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGenericVersionMigrationResult); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\x89\x88\xe6\x9c\xac\xe8\xbf\x81\xe7\xa7\xbb\xe7\x9a\x84\xe5\x8d\x95\xe6\xac\xa1\xe6\x89\xa7\xe8\xa1\x8c\xe7\xbb\x93\xe6\x9e\x9c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\x89\x88\xe6\x9c\xac\xe8\xbf\x81\xe7\xa7\xbb\xe7\x9a\x84\xe5\x8d\x95\xe6\xac\xa1\xe6\x89\xa7\xe8\xa1\x8c\xe7\xbb\x93\xe6\x9e\x9c\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SourceVersion_MetaData[] = {
		{ "Category", "Version Migration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x81\xe7\xa7\xbb\xe5\xbc\x80\xe5\xa7\x8b\xe6\x97\xb6\xe5\xaf\xb9\xe8\xb1\xa1\xe6\x90\xba\xe5\xb8\xa6\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x81\xe7\xa7\xbb\xe5\xbc\x80\xe5\xa7\x8b\xe6\x97\xb6\xe5\xaf\xb9\xe8\xb1\xa1\xe6\x90\xba\xe5\xb8\xa6\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetVersion_MetaData[] = {
		{ "Category", "Version Migration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x81\xe7\xa7\xbb\xe5\xae\x8c\xe6\x88\x90\xe5\x90\x8e\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xba\x94\xe8\xbe\xbe\xe5\x88\xb0\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x81\xe7\xa7\xbb\xe5\xae\x8c\xe6\x88\x90\xe5\x90\x8e\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xba\x94\xe8\xbe\xbe\xe5\x88\xb0\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bSuccess_MetaData[] = {
		{ "Category", "Version Migration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xa0\x87\xe8\xaf\x86\xe6\x9c\xac\xe6\xac\xa1\xe8\xbf\x81\xe7\xa7\xbb\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xa0\x87\xe8\xaf\x86\xe6\x9c\xac\xe6\xac\xa1\xe8\xbf\x81\xe7\xa7\xbb\xe6\x98\xaf\xe5\x90\xa6\xe6\x88\x90\xe5\x8a\x9f\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ErrorCode_MetaData[] = {
		{ "Category", "Version Migration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x81\xe7\xa7\xbb\xe5\xa4\xb1\xe8\xb4\xa5\xe6\x97\xb6\xe7\x94\xa8\xe4\xba\x8e\xe5\xae\x9a\xe4\xbd\x8d\xe9\x97\xae\xe9\xa2\x98\xe7\x9a\x84\xe7\xa8\xb3\xe5\xae\x9a\xe9\x94\x99\xe8\xaf\xaf\xe7\xa0\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x81\xe7\xa7\xbb\xe5\xa4\xb1\xe8\xb4\xa5\xe6\x97\xb6\xe7\x94\xa8\xe4\xba\x8e\xe5\xae\x9a\xe4\xbd\x8d\xe9\x97\xae\xe9\xa2\x98\xe7\x9a\x84\xe7\xa8\xb3\xe5\xae\x9a\xe9\x94\x99\xe8\xaf\xaf\xe7\xa0\x81\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "Category", "Version Migration" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x81\xe7\xa7\xbb\xe5\xa4\xb1\xe8\xb4\xa5\xe6\x88\x96\xe8\xad\xa6\xe5\x91\x8a\xe6\x97\xb6\xe9\x9d\xa2\xe5\x90\x91\xe6\x97\xa5\xe5\xbf\x97\xe5\x92\x8c\xe7\x95\x8c\xe9\x9d\xa2\xe7\x9a\x84\xe8\xaf\xb4\xe6\x98\x8e\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x81\xe7\xa7\xbb\xe5\xa4\xb1\xe8\xb4\xa5\xe6\x88\x96\xe8\xad\xa6\xe5\x91\x8a\xe6\x97\xb6\xe9\x9d\xa2\xe5\x90\x91\xe6\x97\xa5\xe5\xbf\x97\xe5\x92\x8c\xe7\x95\x8c\xe9\x9d\xa2\xe7\x9a\x84\xe8\xaf\xb4\xe6\x98\x8e\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGenericVersionMigrationResult constinit property declarations ****
	static const UECodeGen_Private::FStructPropertyParams NewProp_SourceVersion;
	static const UECodeGen_Private::FStructPropertyParams NewProp_TargetVersion;
	static void NewProp_bSuccess_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bSuccess;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ErrorCode;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Message;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGenericVersionMigrationResult constinit property declarations ******
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGenericVersionMigrationResult>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGenericVersionMigrationResult;
class UScriptStruct* FGenericVersionMigrationResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionMigrationResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGenericVersionMigrationResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGenericVersionMigrationResult, (UObject*)Z_Construct_UPackage__Script_GenericVersionFramework(), TEXT("GenericVersionMigrationResult"));
	}
	return Z_Registration_Info_UScriptStruct_FGenericVersionMigrationResult.OuterSingleton;
	}

// ********** Begin ScriptStruct FGenericVersionMigrationResult Property Definitions ***************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_SourceVersion = { "SourceVersion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionMigrationResult, SourceVersion), Z_Construct_UScriptStruct_FGenericVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SourceVersion_MetaData), NewProp_SourceVersion_MetaData) }; // 2499025735
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_TargetVersion = { "TargetVersion", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionMigrationResult, TargetVersion), Z_Construct_UScriptStruct_FGenericVersionInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetVersion_MetaData), NewProp_TargetVersion_MetaData) }; // 2499025735
void Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_bSuccess_SetBit(void* Obj)
{
	((FGenericVersionMigrationResult*)Obj)->bSuccess = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_bSuccess = { "bSuccess", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FGenericVersionMigrationResult), &Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_bSuccess_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bSuccess_MetaData), NewProp_bSuccess_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_ErrorCode = { "ErrorCode", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionMigrationResult, ErrorCode), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ErrorCode_MetaData), NewProp_ErrorCode_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionMigrationResult, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_SourceVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_TargetVersion,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_bSuccess,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_ErrorCode,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewProp_Message,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGenericVersionMigrationResult Property Definitions *****************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericVersionFramework,
	nullptr,
	&NewStructOps,
	"GenericVersionMigrationResult",
	Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::PropPointers),
	sizeof(FGenericVersionMigrationResult),
	alignof(FGenericVersionMigrationResult),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionMigrationResult()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionMigrationResult.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGenericVersionMigrationResult.InnerSingleton, Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGenericVersionMigrationResult.InnerSingleton);
}
// ********** End ScriptStruct FGenericVersionMigrationResult **************************************

// ********** Begin ScriptStruct FGenericVersionContext ********************************************
struct Z_Construct_UScriptStruct_FGenericVersionContext_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FGenericVersionContext); }
	static inline consteval int16 GetStructAlignment() { return alignof(FGenericVersionContext); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x8d\x95\xe6\xac\xa1\xe6\xa0\xa1\xe9\xaa\x8c\xe6\x88\x96\xe8\xbf\x81\xe7\xa7\xbb\xe8\xb0\x83\xe7\x94\xa8\xe7\x9a\x84\xe4\xb8\x8a\xe4\xb8\x8b\xe6\x96\x87\xef\xbc\x8c\xe7\x94\xb1\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe6\x8c\x89\xe9\x9c\x80\xe8\xa6\x81\xe5\xa1\xab\xe5\x85\x85\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x8d\x95\xe6\xac\xa1\xe6\xa0\xa1\xe9\xaa\x8c\xe6\x88\x96\xe8\xbf\x81\xe7\xa7\xbb\xe8\xb0\x83\xe7\x94\xa8\xe7\x9a\x84\xe4\xb8\x8a\xe4\xb8\x8b\xe6\x96\x87\xef\xbc\x8c\xe7\x94\xb1\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe6\x8c\x89\xe9\x9c\x80\xe8\xa6\x81\xe5\xa1\xab\xe5\x85\x85\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TargetObject_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xa2\xab\xe6\xa0\xa1\xe9\xaa\x8c\xe6\x88\x96\xe8\xbf\x81\xe7\xa7\xbb\xe7\x9a\x84\xe7\x9b\xae\xe6\xa0\x87\xe5\xaf\xb9\xe8\xb1\xa1\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xa2\xab\xe6\xa0\xa1\xe9\xaa\x8c\xe6\x88\x96\xe8\xbf\x81\xe7\xa7\xbb\xe7\x9a\x84\xe7\x9b\xae\xe6\xa0\x87\xe5\xaf\xb9\xe8\xb1\xa1\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionKey_MetaData[] = {
		{ "Categories", "GameplayVersion" },
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x9c\xac\xe6\xac\xa1\xe8\xb0\x83\xe7\x94\xa8\xe5\xaf\xb9\xe5\xba\x94\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe9\x94\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x9c\xac\xe6\xac\xa1\xe8\xb0\x83\xe7\x94\xa8\xe5\xaf\xb9\xe5\xba\x94\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe9\x94\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionData_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbb\x8e\xe4\xb8\xad\xe5\xbf\x83\xe7\x89\x88\xe6\x9c\xac\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xaf\xbb\xe5\x8f\x96\xe5\x88\xb0\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x8e\xe4\xb8\xad\xe5\xbf\x83\xe7\x89\x88\xe6\x9c\xac\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xaf\xbb\xe5\x8f\x96\xe5\x88\xb0\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xe6\x95\xb0\xe6\x8d\xae\xe5\xbf\xab\xe7\x85\xa7\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionDefinition_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbb\x8e\xe4\xb8\xad\xe5\xbf\x83\xe7\x89\x88\xe6\x9c\xac\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xaf\xbb\xe5\x8f\x96\xe5\x88\xb0\xe7\x9a\x84\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbb\x8e\xe4\xb8\xad\xe5\xbf\x83\xe7\x89\x88\xe6\x9c\xac\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe8\xaf\xbb\xe5\x8f\x96\xe5\x88\xb0\xe7\x9a\x84\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ContextObject_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe4\xbc\xa0\xe5\x85\xa5\xe7\x9a\x84\xe5\x8f\xaf\xe9\x80\x89\xe4\xb8\x8a\xe4\xb8\x8b\xe6\x96\x87\xe5\xaf\xb9\xe8\xb1\xa1\xef\xbc\x8c\xe4\xbe\x8b\xe5\xa6\x82 WorldContext\xe3\x80\x81Subsystem \xe6\x88\x96\xe8\xb0\x83\xe7\x94\xa8\xe6\x9d\xa5\xe6\xba\x90\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Types/GenericVersionTypes.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\x9a\xe5\x8a\xa1\xe5\xb1\x82\xe4\xbc\xa0\xe5\x85\xa5\xe7\x9a\x84\xe5\x8f\xaf\xe9\x80\x89\xe4\xb8\x8a\xe4\xb8\x8b\xe6\x96\x87\xe5\xaf\xb9\xe8\xb1\xa1\xef\xbc\x8c\xe4\xbe\x8b\xe5\xa6\x82 WorldContext\xe3\x80\x81Subsystem \xe6\x88\x96\xe8\xb0\x83\xe7\x94\xa8\xe6\x9d\xa5\xe6\xba\x90\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FGenericVersionContext constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionKey;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionData;
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionDefinition;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ContextObject;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FGenericVersionContext constinit property declarations **************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FGenericVersionContext>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FGenericVersionContext_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FGenericVersionContext;
class UScriptStruct* FGenericVersionContext::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionContext.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FGenericVersionContext.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FGenericVersionContext, (UObject*)Z_Construct_UPackage__Script_GenericVersionFramework(), TEXT("GenericVersionContext"));
	}
	return Z_Registration_Info_UScriptStruct_FGenericVersionContext.OuterSingleton;
	}

// ********** Begin ScriptStruct FGenericVersionContext Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewProp_TargetObject = { "TargetObject", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionContext, TargetObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TargetObject_MetaData), NewProp_TargetObject_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewProp_VersionKey = { "VersionKey", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionContext, VersionKey), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionKey_MetaData), NewProp_VersionKey_MetaData) }; // 517357616
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewProp_VersionData = { "VersionData", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionContext, VersionData), Z_Construct_UScriptStruct_FGenericVersionData, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionData_MetaData), NewProp_VersionData_MetaData) }; // 477485717
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewProp_VersionDefinition = { "VersionDefinition", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionContext, VersionDefinition), Z_Construct_UScriptStruct_FGenericVersionDefinition, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionDefinition_MetaData), NewProp_VersionDefinition_MetaData) }; // 144404518
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewProp_ContextObject = { "ContextObject", nullptr, (EPropertyFlags)0x0114000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FGenericVersionContext, ContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ContextObject_MetaData), NewProp_ContextObject_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FGenericVersionContext_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewProp_TargetObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewProp_VersionKey,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewProp_VersionData,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewProp_VersionDefinition,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewProp_ContextObject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionContext_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FGenericVersionContext Property Definitions *************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FGenericVersionContext_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericVersionFramework,
	nullptr,
	&NewStructOps,
	"GenericVersionContext",
	Z_Construct_UScriptStruct_FGenericVersionContext_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionContext_Statics::PropPointers),
	sizeof(FGenericVersionContext),
	alignof(FGenericVersionContext),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FGenericVersionContext_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FGenericVersionContext_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionContext()
{
	if (!Z_Registration_Info_UScriptStruct_FGenericVersionContext.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FGenericVersionContext.InnerSingleton, Z_Construct_UScriptStruct_FGenericVersionContext_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FGenericVersionContext.InnerSingleton);
}
// ********** End ScriptStruct FGenericVersionContext **********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h__Script_GenericVersionFramework_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EGenericVersionValidationStatus_StaticEnum, TEXT("EGenericVersionValidationStatus"), &Z_Registration_Info_UEnum_EGenericVersionValidationStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1185831510U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FGenericVersionInfo::StaticStruct, Z_Construct_UScriptStruct_FGenericVersionInfo_Statics::NewStructOps, TEXT("GenericVersionInfo"),&Z_Registration_Info_UScriptStruct_FGenericVersionInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGenericVersionInfo), 2499025735U) },
		{ FGenericVersionDefinition::StaticStruct, Z_Construct_UScriptStruct_FGenericVersionDefinition_Statics::NewStructOps, TEXT("GenericVersionDefinition"),&Z_Registration_Info_UScriptStruct_FGenericVersionDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGenericVersionDefinition), 144404518U) },
		{ FGenericVersionData::StaticStruct, Z_Construct_UScriptStruct_FGenericVersionData_Statics::NewStructOps, TEXT("GenericVersionData"),&Z_Registration_Info_UScriptStruct_FGenericVersionData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGenericVersionData), 477485717U) },
		{ FGenericVersionValidationResult::StaticStruct, Z_Construct_UScriptStruct_FGenericVersionValidationResult_Statics::NewStructOps, TEXT("GenericVersionValidationResult"),&Z_Registration_Info_UScriptStruct_FGenericVersionValidationResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGenericVersionValidationResult), 2233177156U) },
		{ FGenericVersionMigrationResult::StaticStruct, Z_Construct_UScriptStruct_FGenericVersionMigrationResult_Statics::NewStructOps, TEXT("GenericVersionMigrationResult"),&Z_Registration_Info_UScriptStruct_FGenericVersionMigrationResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGenericVersionMigrationResult), 3667212279U) },
		{ FGenericVersionContext::StaticStruct, Z_Construct_UScriptStruct_FGenericVersionContext_Statics::NewStructOps, TEXT("GenericVersionContext"),&Z_Registration_Info_UScriptStruct_FGenericVersionContext, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FGenericVersionContext), 2979299899U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h__Script_GenericVersionFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h__Script_GenericVersionFramework_2991120822{
	TEXT("/Script/GenericVersionFramework"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h__Script_GenericVersionFramework_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h__Script_GenericVersionFramework_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h__Script_GenericVersionFramework_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Types_GenericVersionTypes_h__Script_GenericVersionFramework_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
