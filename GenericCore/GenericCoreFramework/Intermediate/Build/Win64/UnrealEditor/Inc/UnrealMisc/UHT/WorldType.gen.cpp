// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Type/WorldType.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeWorldType() {}

// ********** Begin Cross Module References ********************************************************
UNREALMISC_API UEnum* Z_Construct_UEnum_UnrealMisc_EWorldTypeBP();
UPackage* Z_Construct_UPackage__Script_UnrealMisc();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EWorldTypeBP **************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EWorldTypeBP;
static UEnum* EWorldTypeBP_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EWorldTypeBP.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EWorldTypeBP.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_UnrealMisc_EWorldTypeBP, (UObject*)Z_Construct_UPackage__Script_UnrealMisc(), TEXT("EWorldTypeBP"));
	}
	return Z_Registration_Info_UEnum_EWorldTypeBP.OuterSingleton;
}
template<> UNREALMISC_NON_ATTRIBUTED_API UEnum* StaticEnum<EWorldTypeBP>()
{
	return EWorldTypeBP_StaticEnum();
}
struct Z_Construct_UEnum_UnrealMisc_EWorldTypeBP_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""E\xe4\xb8\x96\xe7\x95\x8c\xe7\xb1\xbb\xe5\x9e\x8b""BP\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "Editor.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82 */" },
		{ "Editor.Name", "EWorldTypeBP::Editor" },
		{ "Editor.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82" },
		{ "EditorPreview.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\xa2\x84\xe8\xa7\x88\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82 */" },
		{ "EditorPreview.Name", "EWorldTypeBP::EditorPreview" },
		{ "EditorPreview.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\xa2\x84\xe8\xa7\x88\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82" },
		{ "Game.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xb8\xb8\xe6\x88\x8f\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82 */" },
		{ "Game.Name", "EWorldTypeBP::Game" },
		{ "Game.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xb8\xb8\xe6\x88\x8f\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82" },
		{ "GamePreview.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xb8\xb8\xe6\x88\x8f\xe9\xa2\x84\xe8\xa7\x88\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82 */" },
		{ "GamePreview.Name", "EWorldTypeBP::GamePreview" },
		{ "GamePreview.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xb8\xb8\xe6\x88\x8f\xe9\xa2\x84\xe8\xa7\x88\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82" },
		{ "GameRPC.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xb8\xb8\xe6\x88\x8f RPC \xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82 */" },
		{ "GameRPC.Name", "EWorldTypeBP::GameRPC" },
		{ "GameRPC.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xb8\xb8\xe6\x88\x8f RPC \xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82" },
		{ "Inactive.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe9\x9d\x9e\xe6\xb4\xbb\xe8\xb7\x83\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82 */" },
		{ "Inactive.Name", "EWorldTypeBP::Inactive" },
		{ "Inactive.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe9\x9d\x9e\xe6\xb4\xbb\xe8\xb7\x83\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/WorldType.h" },
		{ "None.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x8d\xe5\x90\xaf\xe7\x94\xa8\xe9\xa2\x9d\xe5\xa4\x96\xe7\xad\x96\xe7\x95\xa5\xe6\x88\x96\xe6\xb2\xa1\xe6\x9c\x89\xe6\x9c\x89\xe6\x95\x88\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82 */" },
		{ "None.Name", "EWorldTypeBP::None" },
		{ "None.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x8d\xe5\x90\xaf\xe7\x94\xa8\xe9\xa2\x9d\xe5\xa4\x96\xe7\xad\x96\xe7\x95\xa5\xe6\x88\x96\xe6\xb2\xa1\xe6\x9c\x89\xe6\x9c\x89\xe6\x95\x88\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82" },
		{ "PIE.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x86\x85\xe6\x92\xad\xe6\x94\xbe\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82 */" },
		{ "PIE.Name", "EWorldTypeBP::PIE" },
		{ "PIE.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x86\x85\xe6\x92\xad\xe6\x94\xbe\xe4\xb8\x96\xe7\x95\x8c\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""E\xe4\xb8\x96\xe7\x95\x8c\xe7\xb1\xbb\xe5\x9e\x8b""BP\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EWorldTypeBP::None", (int64)EWorldTypeBP::None },
		{ "EWorldTypeBP::Game", (int64)EWorldTypeBP::Game },
		{ "EWorldTypeBP::Editor", (int64)EWorldTypeBP::Editor },
		{ "EWorldTypeBP::PIE", (int64)EWorldTypeBP::PIE },
		{ "EWorldTypeBP::EditorPreview", (int64)EWorldTypeBP::EditorPreview },
		{ "EWorldTypeBP::GamePreview", (int64)EWorldTypeBP::GamePreview },
		{ "EWorldTypeBP::GameRPC", (int64)EWorldTypeBP::GameRPC },
		{ "EWorldTypeBP::Inactive", (int64)EWorldTypeBP::Inactive },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_UnrealMisc_EWorldTypeBP_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_UnrealMisc_EWorldTypeBP_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_UnrealMisc,
	nullptr,
	"EWorldTypeBP",
	"EWorldTypeBP",
	Z_Construct_UEnum_UnrealMisc_EWorldTypeBP_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_UnrealMisc_EWorldTypeBP_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_UnrealMisc_EWorldTypeBP_Statics::Enum_MetaDataParams), Z_Construct_UEnum_UnrealMisc_EWorldTypeBP_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_UnrealMisc_EWorldTypeBP()
{
	if (!Z_Registration_Info_UEnum_EWorldTypeBP.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EWorldTypeBP.InnerSingleton, Z_Construct_UEnum_UnrealMisc_EWorldTypeBP_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EWorldTypeBP.InnerSingleton;
}
// ********** End Enum EWorldTypeBP ****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_WorldType_h__Script_UnrealMisc_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EWorldTypeBP_StaticEnum, TEXT("EWorldTypeBP"), &Z_Registration_Info_UEnum_EWorldTypeBP, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2184539054U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_WorldType_h__Script_UnrealMisc_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_WorldType_h__Script_UnrealMisc_145213654{
	TEXT("/Script/UnrealMisc"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_WorldType_h__Script_UnrealMisc_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_WorldType_h__Script_UnrealMisc_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
