// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayMessageType.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGameplayMessageType() {}

// ********** Begin Cross Module References ********************************************************
GENERICMESSAGEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch();
UPackage* Z_Construct_UPackage__Script_GenericMessageFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EGameplayMessageMatch *****************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGameplayMessageMatch;
static UEnum* EGameplayMessageMatch_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGameplayMessageMatch.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGameplayMessageMatch.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch, (UObject*)Z_Construct_UPackage__Script_GenericMessageFramework(), TEXT("EGameplayMessageMatch"));
	}
	return Z_Registration_Info_UEnum_EGameplayMessageMatch.OuterSingleton;
}
template<> GENERICMESSAGEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EGameplayMessageMatch>()
{
	return EGameplayMessageMatch_StaticEnum();
}
struct Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe6\xb6\x88\xe6\x81\xaf\xe7\x9b\x91\xe5\x90\xac\xe5\x99\xa8\xe5\x8c\xb9\xe9\x85\x8d\xe9\xa2\x91\xe9\x81\x93\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe8\xa7\x84\xe5\x88\x99\xe3\x80\x82 */" },
#endif
		{ "ExactMatch.Comment", "/** \xe5\x8f\xaa\xe6\x8e\xa5\xe6\x94\xb6\xe4\xb8\x8e\xe6\xb3\xa8\xe5\x86\x8c\xe9\xa2\x91\xe9\x81\x93\xe5\xae\x8c\xe5\x85\xa8\xe4\xb8\x80\xe8\x87\xb4\xe7\x9a\x84\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82 */" },
		{ "ExactMatch.Name", "EGameplayMessageMatch::ExactMatch" },
		{ "ExactMatch.ToolTip", "\xe5\x8f\xaa\xe6\x8e\xa5\xe6\x94\xb6\xe4\xb8\x8e\xe6\xb3\xa8\xe5\x86\x8c\xe9\xa2\x91\xe9\x81\x93\xe5\xae\x8c\xe5\x85\xa8\xe4\xb8\x80\xe8\x87\xb4\xe7\x9a\x84\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/GameplayMessageType.h" },
		{ "PartialMatch.Comment", "/** \xe6\x8e\xa5\xe6\x94\xb6\xe6\xb3\xa8\xe5\x86\x8c\xe9\xa2\x91\xe9\x81\x93\xe5\x8f\x8a\xe5\x85\xb6\xe5\xad\x90\xe9\xa2\x91\xe9\x81\x93\xe4\xb8\x8a\xe7\x9a\x84\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82 */" },
		{ "PartialMatch.Name", "EGameplayMessageMatch::PartialMatch" },
		{ "PartialMatch.ToolTip", "\xe6\x8e\xa5\xe6\x94\xb6\xe6\xb3\xa8\xe5\x86\x8c\xe9\xa2\x91\xe9\x81\x93\xe5\x8f\x8a\xe5\x85\xb6\xe5\xad\x90\xe9\xa2\x91\xe9\x81\x93\xe4\xb8\x8a\xe7\x9a\x84\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe6\xb6\x88\xe6\x81\xaf\xe7\x9b\x91\xe5\x90\xac\xe5\x99\xa8\xe5\x8c\xb9\xe9\x85\x8d\xe9\xa2\x91\xe9\x81\x93\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe8\xa7\x84\xe5\x88\x99\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGameplayMessageMatch::ExactMatch", (int64)EGameplayMessageMatch::ExactMatch },
		{ "EGameplayMessageMatch::PartialMatch", (int64)EGameplayMessageMatch::PartialMatch },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericMessageFramework,
	nullptr,
	"EGameplayMessageMatch",
	"EGameplayMessageMatch",
	Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch()
{
	if (!Z_Registration_Info_UEnum_EGameplayMessageMatch.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGameplayMessageMatch.InnerSingleton, Z_Construct_UEnum_GenericMessageFramework_EGameplayMessageMatch_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGameplayMessageMatch.InnerSingleton;
}
// ********** End Enum EGameplayMessageMatch *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageType_h__Script_GenericMessageFramework_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EGameplayMessageMatch_StaticEnum, TEXT("EGameplayMessageMatch"), &Z_Registration_Info_UEnum_EGameplayMessageMatch, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3165695195U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageType_h__Script_GenericMessageFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageType_h__Script_GenericMessageFramework_2951000180{
	TEXT("/Script/GenericMessageFramework"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageType_h__Script_GenericMessageFramework_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageType_h__Script_GenericMessageFramework_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
