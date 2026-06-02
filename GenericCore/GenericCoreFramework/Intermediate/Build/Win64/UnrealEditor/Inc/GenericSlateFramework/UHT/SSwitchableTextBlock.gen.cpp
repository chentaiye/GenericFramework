// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SWidget/SSwitchableTextBlock.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSSwitchableTextBlock() {}

// ********** Begin Cross Module References ********************************************************
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ESwitchableTextBlockMode **************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESwitchableTextBlockMode;
static UEnum* ESwitchableTextBlockMode_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESwitchableTextBlockMode.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESwitchableTextBlockMode.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode, (UObject*)Z_Construct_UPackage__Script_GenericSlateFramework(), TEXT("ESwitchableTextBlockMode"));
	}
	return Z_Registration_Info_UEnum_ESwitchableTextBlockMode.OuterSingleton;
}
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<ESwitchableTextBlockMode>()
{
	return ESwitchableTextBlockMode_StaticEnum();
}
struct Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe5\x8f\xaf\xe5\x88\x87\xe6\x8d\xa2\xe6\x96\x87\xe6\x9c\xac\xe6\xa8\xa1\xe5\xbc\x8f\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "Display.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x8f\xaa\xe8\xaf\xbb\xe6\x98\xbe\xe7\xa4\xba\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82 */" },
		{ "Display.Name", "ESwitchableTextBlockMode::Display" },
		{ "Display.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x8f\xaa\xe8\xaf\xbb\xe6\x98\xbe\xe7\xa4\xba\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82" },
		{ "Editable.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe8\xbe\x93\xe5\x85\xa5\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82 */" },
		{ "Editable.Name", "ESwitchableTextBlockMode::Editable" },
		{ "Editable.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe8\xbe\x93\xe5\x85\xa5\xe6\xa8\xa1\xe5\xbc\x8f\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/SWidget/SSwitchableTextBlock.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe5\x8f\xaf\xe5\x88\x87\xe6\x8d\xa2\xe6\x96\x87\xe6\x9c\xac\xe6\xa8\xa1\xe5\xbc\x8f\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESwitchableTextBlockMode::Display", (int64)ESwitchableTextBlockMode::Display },
		{ "ESwitchableTextBlockMode::Editable", (int64)ESwitchableTextBlockMode::Editable },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework,
	nullptr,
	"ESwitchableTextBlockMode",
	"ESwitchableTextBlockMode",
	Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode()
{
	if (!Z_Registration_Info_UEnum_ESwitchableTextBlockMode.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESwitchableTextBlockMode.InnerSingleton, Z_Construct_UEnum_GenericSlateFramework_ESwitchableTextBlockMode_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESwitchableTextBlockMode.InnerSingleton;
}
// ********** End Enum ESwitchableTextBlockMode ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSwitchableTextBlock_h__Script_GenericSlateFramework_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESwitchableTextBlockMode_StaticEnum, TEXT("ESwitchableTextBlockMode"), &Z_Registration_Info_UEnum_ESwitchableTextBlockMode, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2053230862U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSwitchableTextBlock_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSwitchableTextBlock_h__Script_GenericSlateFramework_4036927961{
	TEXT("/Script/GenericSlateFramework"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSwitchableTextBlock_h__Script_GenericSlateFramework_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSwitchableTextBlock_h__Script_GenericSlateFramework_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
