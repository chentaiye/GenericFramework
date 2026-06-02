// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SWidget/SGenericAnimatedSwitcher.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSGenericAnimatedSwitcher() {}

// ********** Begin Cross Module References ********************************************************
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition();
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy();
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EGenericSwitcherTransition ************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGenericSwitcherTransition;
static UEnum* EGenericSwitcherTransition_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGenericSwitcherTransition.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGenericSwitcherTransition.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition, (UObject*)Z_Construct_UPackage__Script_GenericSlateFramework(), TEXT("EGenericSwitcherTransition"));
	}
	return Z_Registration_Info_UEnum_EGenericSwitcherTransition.OuterSingleton;
}
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EGenericSwitcherTransition>()
{
	return EGenericSwitcherTransition_StaticEnum();
}
struct Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe5\x88\x87\xe6\x8d\xa2\xe5\x8a\xa8\xe7\x94\xbb\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "FadeOnly.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xbb\x85\xe6\xb7\xa1\xe5\x85\xa5\xe6\xb7\xa1\xe5\x87\xba\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82 */" },
		{ "FadeOnly.Name", "EGenericSwitcherTransition::FadeOnly" },
		{ "FadeOnly.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xbb\x85\xe6\xb7\xa1\xe5\x85\xa5\xe6\xb7\xa1\xe5\x87\xba\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82" },
		{ "Horizontal.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\xb0\xb4\xe5\xb9\xb3\xe4\xbd\x8d\xe7\xa7\xbb\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82 */" },
		{ "Horizontal.Name", "EGenericSwitcherTransition::Horizontal" },
		{ "Horizontal.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\xb0\xb4\xe5\xb9\xb3\xe4\xbd\x8d\xe7\xa7\xbb\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/SWidget/SGenericAnimatedSwitcher.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe5\x88\x87\xe6\x8d\xa2\xe5\x8a\xa8\xe7\x94\xbb\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82" },
#endif
		{ "Vertical.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe5\x9e\x82\xe7\x9b\xb4\xe4\xbd\x8d\xe7\xa7\xbb\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82 */" },
		{ "Vertical.Name", "EGenericSwitcherTransition::Vertical" },
		{ "Vertical.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe5\x9e\x82\xe7\x9b\xb4\xe4\xbd\x8d\xe7\xa7\xbb\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82" },
		{ "Zoom.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xbc\xa9\xe6\x94\xbe\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82 */" },
		{ "Zoom.Name", "EGenericSwitcherTransition::Zoom" },
		{ "Zoom.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xbc\xa9\xe6\x94\xbe\xe5\x88\x87\xe6\x8d\xa2\xe3\x80\x82" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGenericSwitcherTransition::FadeOnly", (int64)EGenericSwitcherTransition::FadeOnly },
		{ "EGenericSwitcherTransition::Horizontal", (int64)EGenericSwitcherTransition::Horizontal },
		{ "EGenericSwitcherTransition::Vertical", (int64)EGenericSwitcherTransition::Vertical },
		{ "EGenericSwitcherTransition::Zoom", (int64)EGenericSwitcherTransition::Zoom },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework,
	nullptr,
	"EGenericSwitcherTransition",
	"EGenericSwitcherTransition",
	Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition()
{
	if (!Z_Registration_Info_UEnum_EGenericSwitcherTransition.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGenericSwitcherTransition.InnerSingleton, Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransition_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGenericSwitcherTransition.InnerSingleton;
}
// ********** End Enum EGenericSwitcherTransition **************************************************

// ********** Begin Enum EGenericTransitionCurve ***************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGenericTransitionCurve;
static UEnum* EGenericTransitionCurve_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGenericTransitionCurve.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGenericTransitionCurve.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve, (UObject*)Z_Construct_UPackage__Script_GenericSlateFramework(), TEXT("EGenericTransitionCurve"));
	}
	return Z_Registration_Info_UEnum_EGenericTransitionCurve.OuterSingleton;
}
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EGenericTransitionCurve>()
{
	return EGenericTransitionCurve_StaticEnum();
}
struct Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe5\x88\x87\xe6\x8d\xa2\xe6\x9b\xb2\xe7\xba\xbf\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "CubicIn.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x89\xe6\xac\xa1\xe7\xbc\x93\xe5\x85\xa5\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82 */" },
		{ "CubicIn.Name", "EGenericTransitionCurve::CubicIn" },
		{ "CubicIn.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x89\xe6\xac\xa1\xe7\xbc\x93\xe5\x85\xa5\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82" },
		{ "CubicInOut.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x89\xe6\xac\xa1\xe7\xbc\x93\xe5\x85\xa5\xe7\xbc\x93\xe5\x87\xba\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82 */" },
		{ "CubicInOut.Name", "EGenericTransitionCurve::CubicInOut" },
		{ "CubicInOut.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x89\xe6\xac\xa1\xe7\xbc\x93\xe5\x85\xa5\xe7\xbc\x93\xe5\x87\xba\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82" },
		{ "CubicOut.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x89\xe6\xac\xa1\xe7\xbc\x93\xe5\x87\xba\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82 */" },
		{ "CubicOut.Name", "EGenericTransitionCurve::CubicOut" },
		{ "CubicOut.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x89\xe6\xac\xa1\xe7\xbc\x93\xe5\x87\xba\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82" },
		{ "Linear.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xbf\xe6\x80\xa7\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82 */" },
		{ "Linear.Name", "EGenericTransitionCurve::Linear" },
		{ "Linear.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xba\xbf\xe6\x80\xa7\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/SWidget/SGenericAnimatedSwitcher.h" },
		{ "QuadIn.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xba\x8c\xe6\xac\xa1\xe7\xbc\x93\xe5\x85\xa5\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82 */" },
		{ "QuadIn.Name", "EGenericTransitionCurve::QuadIn" },
		{ "QuadIn.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xba\x8c\xe6\xac\xa1\xe7\xbc\x93\xe5\x85\xa5\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82" },
		{ "QuadInOut.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xba\x8c\xe6\xac\xa1\xe7\xbc\x93\xe5\x85\xa5\xe7\xbc\x93\xe5\x87\xba\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82 */" },
		{ "QuadInOut.Name", "EGenericTransitionCurve::QuadInOut" },
		{ "QuadInOut.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xba\x8c\xe6\xac\xa1\xe7\xbc\x93\xe5\x85\xa5\xe7\xbc\x93\xe5\x87\xba\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82" },
		{ "QuadOut.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xba\x8c\xe6\xac\xa1\xe7\xbc\x93\xe5\x87\xba\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82 */" },
		{ "QuadOut.Name", "EGenericTransitionCurve::QuadOut" },
		{ "QuadOut.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xba\x8c\xe6\xac\xa1\xe7\xbc\x93\xe5\x87\xba\xe6\x9b\xb2\xe7\xba\xbf\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe5\x88\x87\xe6\x8d\xa2\xe6\x9b\xb2\xe7\xba\xbf\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGenericTransitionCurve::Linear", (int64)EGenericTransitionCurve::Linear },
		{ "EGenericTransitionCurve::QuadIn", (int64)EGenericTransitionCurve::QuadIn },
		{ "EGenericTransitionCurve::QuadOut", (int64)EGenericTransitionCurve::QuadOut },
		{ "EGenericTransitionCurve::QuadInOut", (int64)EGenericTransitionCurve::QuadInOut },
		{ "EGenericTransitionCurve::CubicIn", (int64)EGenericTransitionCurve::CubicIn },
		{ "EGenericTransitionCurve::CubicOut", (int64)EGenericTransitionCurve::CubicOut },
		{ "EGenericTransitionCurve::CubicInOut", (int64)EGenericTransitionCurve::CubicInOut },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework,
	nullptr,
	"EGenericTransitionCurve",
	"EGenericTransitionCurve",
	Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve()
{
	if (!Z_Registration_Info_UEnum_EGenericTransitionCurve.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGenericTransitionCurve.InnerSingleton, Z_Construct_UEnum_GenericSlateFramework_EGenericTransitionCurve_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGenericTransitionCurve.InnerSingleton;
}
// ********** End Enum EGenericTransitionCurve *****************************************************

// ********** Begin Enum EGenericSwitcherTransitionFallbackStrategy ********************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EGenericSwitcherTransitionFallbackStrategy;
static UEnum* EGenericSwitcherTransitionFallbackStrategy_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EGenericSwitcherTransitionFallbackStrategy.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EGenericSwitcherTransitionFallbackStrategy.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy, (UObject*)Z_Construct_UPackage__Script_GenericSlateFramework(), TEXT("EGenericSwitcherTransitionFallbackStrategy"));
	}
	return Z_Registration_Info_UEnum_EGenericSwitcherTransitionFallbackStrategy.OuterSingleton;
}
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EGenericSwitcherTransitionFallbackStrategy>()
{
	return EGenericSwitcherTransitionFallbackStrategy_StaticEnum();
}
struct Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe5\x88\x87\xe6\x8d\xa2\xe5\x9b\x9e\xe9\x80\x80\xe7\xad\x96\xe7\x95\xa5\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "First.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe7\xac\xac\xe4\xb8\x80\xe4\xb8\xaa\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
		{ "First.Name", "EGenericSwitcherTransitionFallbackStrategy::First" },
		{ "First.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe7\xac\xac\xe4\xb8\x80\xe4\xb8\xaa\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
		{ "Last.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\x80\xe5\x90\x8e\xe4\xb8\x80\xe4\xb8\xaa\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
		{ "Last.Name", "EGenericSwitcherTransitionFallbackStrategy::Last" },
		{ "Last.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9c\x80\xe5\x90\x8e\xe4\xb8\x80\xe4\xb8\xaa\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/SWidget/SGenericAnimatedSwitcher.h" },
		{ "Next.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x8b\xe4\xb8\x80\xe4\xb8\xaa\xe6\x9c\x89\xe6\x95\x88\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
		{ "Next.Name", "EGenericSwitcherTransitionFallbackStrategy::Next" },
		{ "Next.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x8b\xe4\xb8\x80\xe4\xb8\xaa\xe6\x9c\x89\xe6\x95\x88\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
		{ "None.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x8d\xe5\x90\xaf\xe7\x94\xa8\xe9\xa2\x9d\xe5\xa4\x96\xe7\xad\x96\xe7\x95\xa5\xe6\x88\x96\xe6\xb2\xa1\xe6\x9c\x89\xe6\x9c\x89\xe6\x95\x88\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82 */" },
		{ "None.Name", "EGenericSwitcherTransitionFallbackStrategy::None" },
		{ "None.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x8d\xe5\x90\xaf\xe7\x94\xa8\xe9\xa2\x9d\xe5\xa4\x96\xe7\xad\x96\xe7\x95\xa5\xe6\x88\x96\xe6\xb2\xa1\xe6\x9c\x89\xe6\x9c\x89\xe6\x95\x88\xe7\xb1\xbb\xe5\x9e\x8b\xe3\x80\x82" },
		{ "Previous.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x8a\xe4\xb8\x80\xe4\xb8\xaa\xe6\x9c\x89\xe6\x95\x88\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82 */" },
		{ "Previous.Name", "EGenericSwitcherTransitionFallbackStrategy::Previous" },
		{ "Previous.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe4\xb8\x8a\xe4\xb8\x80\xe4\xb8\xaa\xe6\x9c\x89\xe6\x95\x88\xe5\xad\x90\xe6\x8e\xa7\xe4\xbb\xb6\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe5\x88\x87\xe6\x8d\xa2\xe5\x9b\x9e\xe9\x80\x80\xe7\xad\x96\xe7\x95\xa5\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EGenericSwitcherTransitionFallbackStrategy::None", (int64)EGenericSwitcherTransitionFallbackStrategy::None },
		{ "EGenericSwitcherTransitionFallbackStrategy::Previous", (int64)EGenericSwitcherTransitionFallbackStrategy::Previous },
		{ "EGenericSwitcherTransitionFallbackStrategy::Next", (int64)EGenericSwitcherTransitionFallbackStrategy::Next },
		{ "EGenericSwitcherTransitionFallbackStrategy::First", (int64)EGenericSwitcherTransitionFallbackStrategy::First },
		{ "EGenericSwitcherTransitionFallbackStrategy::Last", (int64)EGenericSwitcherTransitionFallbackStrategy::Last },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework,
	nullptr,
	"EGenericSwitcherTransitionFallbackStrategy",
	"EGenericSwitcherTransitionFallbackStrategy",
	Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy()
{
	if (!Z_Registration_Info_UEnum_EGenericSwitcherTransitionFallbackStrategy.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EGenericSwitcherTransitionFallbackStrategy.InnerSingleton, Z_Construct_UEnum_GenericSlateFramework_EGenericSwitcherTransitionFallbackStrategy_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EGenericSwitcherTransitionFallbackStrategy.InnerSingleton;
}
// ********** End Enum EGenericSwitcherTransitionFallbackStrategy **********************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SGenericAnimatedSwitcher_h__Script_GenericSlateFramework_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EGenericSwitcherTransition_StaticEnum, TEXT("EGenericSwitcherTransition"), &Z_Registration_Info_UEnum_EGenericSwitcherTransition, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 368608009U) },
		{ EGenericTransitionCurve_StaticEnum, TEXT("EGenericTransitionCurve"), &Z_Registration_Info_UEnum_EGenericTransitionCurve, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2581333610U) },
		{ EGenericSwitcherTransitionFallbackStrategy_StaticEnum, TEXT("EGenericSwitcherTransitionFallbackStrategy"), &Z_Registration_Info_UEnum_EGenericSwitcherTransitionFallbackStrategy, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2977220325U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SGenericAnimatedSwitcher_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SGenericAnimatedSwitcher_h__Script_GenericSlateFramework_1889869310{
	TEXT("/Script/GenericSlateFramework"),
	nullptr, 0,
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SGenericAnimatedSwitcher_h__Script_GenericSlateFramework_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SGenericAnimatedSwitcher_h__Script_GenericSlateFramework_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
