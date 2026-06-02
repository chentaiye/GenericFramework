// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SWidget/SSimpleTextBox.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSSimpleTextBox() {}

// ********** Begin Cross Module References ********************************************************
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum ESimpleTextBoxType ********************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESimpleTextBoxType;
static UEnum* ESimpleTextBoxType_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ESimpleTextBoxType.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ESimpleTextBoxType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType, (UObject*)Z_Construct_UPackage__Script_GenericSlateFramework(), TEXT("ESimpleTextBoxType"));
	}
	return Z_Registration_Info_UEnum_ESimpleTextBoxType.OuterSingleton;
}
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<ESimpleTextBoxType>()
{
	return ESimpleTextBoxType_StaticEnum();
}
struct Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe7\xae\x80\xe5\x8d\x95\xe6\x96\x87\xe6\x9c\xac\xe6\xa1\x86\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "Horizontal.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xb0\xb4\xe5\xb9\xb3\xe4\xbd\x8d\xe7\xa7\xbb\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82 */" },
		{ "Horizontal.Name", "ESimpleTextBoxType::Horizontal" },
		{ "Horizontal.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xb0\xb4\xe5\xb9\xb3\xe4\xbd\x8d\xe7\xa7\xbb\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82" },
		{ "HorizontalReversal.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xb0\xb4\xe5\xb9\xb3Reversal\xe3\x80\x82 */" },
		{ "HorizontalReversal.Name", "ESimpleTextBoxType::HorizontalReversal" },
		{ "HorizontalReversal.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xb0\xb4\xe5\xb9\xb3Reversal\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/SWidget/SSimpleTextBox.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe7\xae\x80\xe5\x8d\x95\xe6\x96\x87\xe6\x9c\xac\xe6\xa1\x86\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82" },
#endif
		{ "Vertical.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x9e\x82\xe7\x9b\xb4\xe4\xbd\x8d\xe7\xa7\xbb\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82 */" },
		{ "Vertical.Name", "ESimpleTextBoxType::Vertical" },
		{ "Vertical.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x9e\x82\xe7\x9b\xb4\xe4\xbd\x8d\xe7\xa7\xbb\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82" },
		{ "VerticalReversal.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x9e\x82\xe7\x9b\xb4Reversal\xe3\x80\x82 */" },
		{ "VerticalReversal.Name", "ESimpleTextBoxType::VerticalReversal" },
		{ "VerticalReversal.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x9e\x82\xe7\x9b\xb4Reversal\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ESimpleTextBoxType::Horizontal", (int64)ESimpleTextBoxType::Horizontal },
		{ "ESimpleTextBoxType::Vertical", (int64)ESimpleTextBoxType::Vertical },
		{ "ESimpleTextBoxType::HorizontalReversal", (int64)ESimpleTextBoxType::HorizontalReversal },
		{ "ESimpleTextBoxType::VerticalReversal", (int64)ESimpleTextBoxType::VerticalReversal },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework,
	nullptr,
	"ESimpleTextBoxType",
	"ESimpleTextBoxType",
	Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType()
{
	if (!Z_Registration_Info_UEnum_ESimpleTextBoxType.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESimpleTextBoxType.InnerSingleton, Z_Construct_UEnum_GenericSlateFramework_ESimpleTextBoxType_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ESimpleTextBoxType.InnerSingleton;
}
// ********** End Enum ESimpleTextBoxType **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSimpleTextBox_h__Script_GenericSlateFramework_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ESimpleTextBoxType_StaticEnum, TEXT("ESimpleTextBoxType"), &Z_Registration_Info_UEnum_ESimpleTextBoxType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1473637242U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSimpleTextBox_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSimpleTextBox_h__Script_GenericSlateFramework_1636073427{
	TEXT("/Script/GenericSlateFramework"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSimpleTextBox_h__Script_GenericSlateFramework_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSimpleTextBox_h__Script_GenericSlateFramework_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
