// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Type/DateTimeType.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDateTimeType() {}

// ********** Begin Cross Module References ********************************************************
UNREALMISC_API UEnum* Z_Construct_UEnum_UnrealMisc_EDayInWeek();
UNREALMISC_API UEnum* Z_Construct_UEnum_UnrealMisc_EMonthInYear();
UPackage* Z_Construct_UPackage__Script_UnrealMisc();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EDayInWeek ****************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EDayInWeek;
static UEnum* EDayInWeek_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EDayInWeek.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EDayInWeek.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_UnrealMisc_EDayInWeek, (UObject*)Z_Construct_UPackage__Script_UnrealMisc(), TEXT("EDayInWeek"));
	}
	return Z_Registration_Info_UEnum_EDayInWeek.OuterSingleton;
}
template<> UNREALMISC_NON_ATTRIBUTED_API UEnum* StaticEnum<EDayInWeek>()
{
	return EDayInWeek_StaticEnum();
}
struct Z_Construct_UEnum_UnrealMisc_EDayInWeek_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""EDayInWeek\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "Friday.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe4\xba\x94\xe3\x80\x82 */" },
		{ "Friday.Name", "EDayInWeek::Friday" },
		{ "Friday.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe4\xba\x94\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/DateTimeType.h" },
		{ "Monday.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe4\xb8\x80\xe3\x80\x82 */" },
		{ "Monday.Name", "EDayInWeek::Monday" },
		{ "Monday.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe4\xb8\x80\xe3\x80\x82" },
		{ "Saturday.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe5\x85\xad\xe3\x80\x82 */" },
		{ "Saturday.Name", "EDayInWeek::Saturday" },
		{ "Saturday.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe5\x85\xad\xe3\x80\x82" },
		{ "Sunday.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe6\x97\xa5\xe3\x80\x82 */" },
		{ "Sunday.Name", "EDayInWeek::Sunday" },
		{ "Sunday.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe6\x97\xa5\xe3\x80\x82" },
		{ "Thursday.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe5\x9b\x9b\xe3\x80\x82 */" },
		{ "Thursday.Name", "EDayInWeek::Thursday" },
		{ "Thursday.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe5\x9b\x9b\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""EDayInWeek\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82" },
#endif
		{ "Tuesday.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe4\xba\x8c\xe3\x80\x82 */" },
		{ "Tuesday.Name", "EDayInWeek::Tuesday" },
		{ "Tuesday.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe4\xba\x8c\xe3\x80\x82" },
		{ "Wednesday.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe4\xb8\x89\xe3\x80\x82 */" },
		{ "Wednesday.Name", "EDayInWeek::Wednesday" },
		{ "Wednesday.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x98\x9f\xe6\x9c\x9f\xe4\xb8\x89\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EDayInWeek::Monday", (int64)EDayInWeek::Monday },
		{ "EDayInWeek::Tuesday", (int64)EDayInWeek::Tuesday },
		{ "EDayInWeek::Wednesday", (int64)EDayInWeek::Wednesday },
		{ "EDayInWeek::Thursday", (int64)EDayInWeek::Thursday },
		{ "EDayInWeek::Friday", (int64)EDayInWeek::Friday },
		{ "EDayInWeek::Saturday", (int64)EDayInWeek::Saturday },
		{ "EDayInWeek::Sunday", (int64)EDayInWeek::Sunday },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_UnrealMisc_EDayInWeek_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_UnrealMisc_EDayInWeek_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_UnrealMisc,
	nullptr,
	"EDayInWeek",
	"EDayInWeek",
	Z_Construct_UEnum_UnrealMisc_EDayInWeek_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_UnrealMisc_EDayInWeek_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_UnrealMisc_EDayInWeek_Statics::Enum_MetaDataParams), Z_Construct_UEnum_UnrealMisc_EDayInWeek_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_UnrealMisc_EDayInWeek()
{
	if (!Z_Registration_Info_UEnum_EDayInWeek.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EDayInWeek.InnerSingleton, Z_Construct_UEnum_UnrealMisc_EDayInWeek_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EDayInWeek.InnerSingleton;
}
// ********** End Enum EDayInWeek ******************************************************************

// ********** Begin Enum EMonthInYear **************************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EMonthInYear;
static UEnum* EMonthInYear_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EMonthInYear.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EMonthInYear.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_UnrealMisc_EMonthInYear, (UObject*)Z_Construct_UPackage__Script_UnrealMisc(), TEXT("EMonthInYear"));
	}
	return Z_Registration_Info_UEnum_EMonthInYear.OuterSingleton;
}
template<> UNREALMISC_NON_ATTRIBUTED_API UEnum* StaticEnum<EMonthInYear>()
{
	return EMonthInYear_StaticEnum();
}
struct Z_Construct_UEnum_UnrealMisc_EMonthInYear_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "April.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x9b\x9b\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "April.Name", "EMonthInYear::April" },
		{ "April.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x9b\x9b\xe6\x9c\x88\xe3\x80\x82" },
		{ "August.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x85\xab\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "August.Name", "EMonthInYear::August" },
		{ "August.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x85\xab\xe6\x9c\x88\xe3\x80\x82" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""EMonthInYear\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "December.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x8d\x81\xe4\xba\x8c\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "December.Name", "EMonthInYear::December" },
		{ "December.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x8d\x81\xe4\xba\x8c\xe6\x9c\x88\xe3\x80\x82" },
		{ "February.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xba\x8c\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "February.Name", "EMonthInYear::February" },
		{ "February.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xba\x8c\xe6\x9c\x88\xe3\x80\x82" },
		{ "January.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x80\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "January.Name", "EMonthInYear::January" },
		{ "January.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x80\xe6\x9c\x88\xe3\x80\x82" },
		{ "July.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x83\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "July.Name", "EMonthInYear::July" },
		{ "July.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x83\xe6\x9c\x88\xe3\x80\x82" },
		{ "June.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x85\xad\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "June.Name", "EMonthInYear::June" },
		{ "June.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x85\xad\xe6\x9c\x88\xe3\x80\x82" },
		{ "March.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x89\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "March.Name", "EMonthInYear::March" },
		{ "March.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x89\xe6\x9c\x88\xe3\x80\x82" },
		{ "May.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xba\x94\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "May.Name", "EMonthInYear::May" },
		{ "May.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xba\x94\xe6\x9c\x88\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/Type/DateTimeType.h" },
		{ "November.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x8d\x81\xe4\xb8\x80\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "November.Name", "EMonthInYear::November" },
		{ "November.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x8d\x81\xe4\xb8\x80\xe6\x9c\x88\xe3\x80\x82" },
		{ "October.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x8d\x81\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "October.Name", "EMonthInYear::October" },
		{ "October.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x8d\x81\xe6\x9c\x88\xe3\x80\x82" },
		{ "September.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb9\x9d\xe6\x9c\x88\xe3\x80\x82 */" },
		{ "September.Name", "EMonthInYear::September" },
		{ "September.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb9\x9d\xe6\x9c\x88\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""EMonthInYear\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EMonthInYear::January", (int64)EMonthInYear::January },
		{ "EMonthInYear::February", (int64)EMonthInYear::February },
		{ "EMonthInYear::March", (int64)EMonthInYear::March },
		{ "EMonthInYear::April", (int64)EMonthInYear::April },
		{ "EMonthInYear::May", (int64)EMonthInYear::May },
		{ "EMonthInYear::June", (int64)EMonthInYear::June },
		{ "EMonthInYear::July", (int64)EMonthInYear::July },
		{ "EMonthInYear::August", (int64)EMonthInYear::August },
		{ "EMonthInYear::September", (int64)EMonthInYear::September },
		{ "EMonthInYear::October", (int64)EMonthInYear::October },
		{ "EMonthInYear::November", (int64)EMonthInYear::November },
		{ "EMonthInYear::December", (int64)EMonthInYear::December },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_UnrealMisc_EMonthInYear_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_UnrealMisc_EMonthInYear_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_UnrealMisc,
	nullptr,
	"EMonthInYear",
	"EMonthInYear",
	Z_Construct_UEnum_UnrealMisc_EMonthInYear_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_UnrealMisc_EMonthInYear_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_UnrealMisc_EMonthInYear_Statics::Enum_MetaDataParams), Z_Construct_UEnum_UnrealMisc_EMonthInYear_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_UnrealMisc_EMonthInYear()
{
	if (!Z_Registration_Info_UEnum_EMonthInYear.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EMonthInYear.InnerSingleton, Z_Construct_UEnum_UnrealMisc_EMonthInYear_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EMonthInYear.InnerSingleton;
}
// ********** End Enum EMonthInYear ****************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_DateTimeType_h__Script_UnrealMisc_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EDayInWeek_StaticEnum, TEXT("EDayInWeek"), &Z_Registration_Info_UEnum_EDayInWeek, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1650444088U) },
		{ EMonthInYear_StaticEnum, TEXT("EMonthInYear"), &Z_Registration_Info_UEnum_EMonthInYear, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2420210973U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_DateTimeType_h__Script_UnrealMisc_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_DateTimeType_h__Script_UnrealMisc_3769675520{
	TEXT("/Script/UnrealMisc"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_DateTimeType_h__Script_UnrealMisc_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_DateTimeType_h__Script_UnrealMisc_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
