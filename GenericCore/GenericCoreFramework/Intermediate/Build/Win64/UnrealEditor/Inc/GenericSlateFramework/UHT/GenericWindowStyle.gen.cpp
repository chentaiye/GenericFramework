// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Style/GenericWindowStyle.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericWindowStyle() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UClass_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UDevSlateButtonStyle_NoRegister();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericTextBlockStyle_NoRegister();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWindowStyle();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWindowStyle_NoRegister();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateColor();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericWindowStyle ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericWindowStyle;
UClass* UGenericWindowStyle::GetPrivateStaticClass()
{
	using TClass = UGenericWindowStyle;
	if (!Z_Registration_Info_UClass_UGenericWindowStyle.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericWindowStyle"),
			Z_Registration_Info_UClass_UGenericWindowStyle.InnerSingleton,
			StaticRegisterNativesUGenericWindowStyle,
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
	return Z_Registration_Info_UClass_UGenericWindowStyle.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericWindowStyle_NoRegister()
{
	return UGenericWindowStyle::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericWindowStyle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85\xe9\x80\x9a\xe7\x94\xa8\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa0\xb7\xe5\xbc\x8f\xe8\xb5\x84\xe6\xba\x90\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\xa0\xb7\xe5\xbc\x8f\xe9\x9b\x86\xe5\x92\x8c UMG \xe6\x8e\xa7\xe4\xbb\xb6\xe5\x85\xb1\xe4\xba\xab\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Style/GenericWindowStyle.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85\xe9\x80\x9a\xe7\x94\xa8\xe7\xaa\x97\xe5\x8f\xa3\xe6\xa0\xb7\xe5\xbc\x8f\xe8\xb5\x84\xe6\xba\x90\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\xa0\xb7\xe5\xbc\x8f\xe9\x9b\x86\xe5\x92\x8c UMG \xe6\x8e\xa7\xe4\xbb\xb6\xe5\x85\xb1\xe4\xba\xab\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MinimizeButtonStyleClass_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Minimize\xe6\x8c\x89\xe9\x92\xae\xe6\xa0\xb7\xe5\xbc\x8f\xe7\xb1\xbb\xe5\x9e\x8b\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Minimize\xe6\x8c\x89\xe9\x92\xae\xe6\xa0\xb7\xe5\xbc\x8f\xe7\xb1\xbb\xe5\x9e\x8b\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaximizeButtonStyle_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Maximize\xe6\x8c\x89\xe9\x92\xae\xe6\xa0\xb7\xe5\xbc\x8f\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Maximize\xe6\x8c\x89\xe9\x92\xae\xe6\xa0\xb7\xe5\xbc\x8f\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RestoreButtonStyle_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Restore\xe6\x8c\x89\xe9\x92\xae\xe6\xa0\xb7\xe5\xbc\x8f\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Restore\xe6\x8c\x89\xe9\x92\xae\xe6\xa0\xb7\xe5\xbc\x8f\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CloseButtonStyle_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x85\xb3\xe9\x97\xad\xe6\x8c\x89\xe9\x92\xae\xe6\xa0\xb7\xe5\xbc\x8f\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x85\xb3\xe9\x97\xad\xe6\x8c\x89\xe9\x92\xae\xe6\xa0\xb7\xe5\xbc\x8f\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TitleTextStyle_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xa0\x87\xe9\xa2\x98\xe6\x96\x87\xe6\x9c\xac\xe6\xa0\xb7\xe5\xbc\x8f\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xa0\x87\xe9\xa2\x98\xe6\x96\x87\xe6\x9c\xac\xe6\xa0\xb7\xe5\xbc\x8f\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ActiveTitleBrush_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xbf\x80\xe6\xb4\xbb\xe6\xa0\x87\xe9\xa2\x98\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xbf\x80\xe6\xb4\xbb\xe6\xa0\x87\xe9\xa2\x98\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_InactiveTitleBrush_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x9d\x9e\xe6\xbf\x80\xe6\xb4\xbb\xe6\xa0\x87\xe9\xa2\x98\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x9d\x9e\xe6\xbf\x80\xe6\xb4\xbb\xe6\xa0\x87\xe9\xa2\x98\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_FlashTitleBrush_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x97\xaa\xe7\x83\x81\xe6\xa0\x87\xe9\xa2\x98\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x97\xaa\xe7\x83\x81\xe6\xa0\x87\xe9\xa2\x98\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackgroundColor_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x83\x8c\xe6\x99\xaf\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x83\x8c\xe6\x99\xaf\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutlineBrush_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x8f\x8f\xe8\xbe\xb9\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x8f\x8f\xe8\xbe\xb9\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OutlineColor_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x8f\x8f\xe8\xbe\xb9\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x8f\x8f\xe8\xbe\xb9\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BorderBrush_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BorderColor_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbe\xb9\xe6\xa1\x86\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbe\xb9\xe6\xa1\x86\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackgroundBrush_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\x83\x8c\xe6\x99\xaf\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\x83\x8c\xe6\x99\xaf\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChildBackgroundBrush_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xad\x90\xe5\x8c\xba\xe5\x9f\x9f\xe8\x83\x8c\xe6\x99\xaf\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xad\x90\xe5\x8c\xba\xe5\x9f\x9f\xe8\x83\x8c\xe6\x99\xaf\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CornerRadius_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x9c\x86\xe8\xa7\x92\xe5\x8d\x8a\xe5\xbe\x84\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x9c\x86\xe8\xa7\x92\xe5\x8d\x8a\xe5\xbe\x84\xe6\x95\xb0\xe5\x80\xbc\xef\xbc\x8c\xe4\xbe\x9b\xe5\xb8\x83\xe5\xb1\x80\xe3\x80\x81\xe6\xb8\xb2\xe6\x9f\x93\xe6\x88\x96\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BorderPadding_MetaData[] = {
		{ "Category", "Generic Window Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98""Border\xe5\x86\x85\xe8\xbe\xb9\xe8\xb7\x9d\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericWindowStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98""Border\xe5\x86\x85\xe8\xbe\xb9\xe8\xb7\x9d\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericWindowStyle constinit property declarations **********************
	static const UECodeGen_Private::FClassPropertyParams NewProp_MinimizeButtonStyleClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_MaximizeButtonStyle;
	static const UECodeGen_Private::FClassPropertyParams NewProp_RestoreButtonStyle;
	static const UECodeGen_Private::FClassPropertyParams NewProp_CloseButtonStyle;
	static const UECodeGen_Private::FClassPropertyParams NewProp_TitleTextStyle;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ActiveTitleBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InactiveTitleBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_FlashTitleBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BackgroundColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutlineBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutlineColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BorderBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BorderColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BackgroundBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ChildBackgroundBrush;
	static const UECodeGen_Private::FIntPropertyParams NewProp_CornerRadius;
	static const UECodeGen_Private::FStructPropertyParams NewProp_BorderPadding;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGenericWindowStyle constinit property declarations ************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericWindowStyle>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericWindowStyle_Statics

// ********** Begin Class UGenericWindowStyle Property Definitions *********************************
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_MinimizeButtonStyleClass = { "MinimizeButtonStyleClass", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, MinimizeButtonStyleClass), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UDevSlateButtonStyle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MinimizeButtonStyleClass_MetaData), NewProp_MinimizeButtonStyleClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_MaximizeButtonStyle = { "MaximizeButtonStyle", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, MaximizeButtonStyle), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UDevSlateButtonStyle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaximizeButtonStyle_MetaData), NewProp_MaximizeButtonStyle_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_RestoreButtonStyle = { "RestoreButtonStyle", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, RestoreButtonStyle), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UDevSlateButtonStyle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RestoreButtonStyle_MetaData), NewProp_RestoreButtonStyle_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_CloseButtonStyle = { "CloseButtonStyle", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, CloseButtonStyle), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UDevSlateButtonStyle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CloseButtonStyle_MetaData), NewProp_CloseButtonStyle_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_TitleTextStyle = { "TitleTextStyle", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, TitleTextStyle), Z_Construct_UClass_UClass_NoRegister, Z_Construct_UClass_UGenericTextBlockStyle_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TitleTextStyle_MetaData), NewProp_TitleTextStyle_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_ActiveTitleBrush = { "ActiveTitleBrush", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, ActiveTitleBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ActiveTitleBrush_MetaData), NewProp_ActiveTitleBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_InactiveTitleBrush = { "InactiveTitleBrush", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, InactiveTitleBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_InactiveTitleBrush_MetaData), NewProp_InactiveTitleBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_FlashTitleBrush = { "FlashTitleBrush", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, FlashTitleBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_FlashTitleBrush_MetaData), NewProp_FlashTitleBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_BackgroundColor = { "BackgroundColor", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, BackgroundColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackgroundColor_MetaData), NewProp_BackgroundColor_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_OutlineBrush = { "OutlineBrush", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, OutlineBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutlineBrush_MetaData), NewProp_OutlineBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_OutlineColor = { "OutlineColor", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, OutlineColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OutlineColor_MetaData), NewProp_OutlineColor_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_BorderBrush = { "BorderBrush", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, BorderBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BorderBrush_MetaData), NewProp_BorderBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_BorderColor = { "BorderColor", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, BorderColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BorderColor_MetaData), NewProp_BorderColor_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_BackgroundBrush = { "BackgroundBrush", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, BackgroundBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackgroundBrush_MetaData), NewProp_BackgroundBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_ChildBackgroundBrush = { "ChildBackgroundBrush", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, ChildBackgroundBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChildBackgroundBrush_MetaData), NewProp_ChildBackgroundBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_CornerRadius = { "CornerRadius", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, CornerRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CornerRadius_MetaData), NewProp_CornerRadius_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_BorderPadding = { "BorderPadding", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericWindowStyle, BorderPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BorderPadding_MetaData), NewProp_BorderPadding_MetaData) }; // 4099648758
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenericWindowStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_MinimizeButtonStyleClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_MaximizeButtonStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_RestoreButtonStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_CloseButtonStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_TitleTextStyle,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_ActiveTitleBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_InactiveTitleBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_FlashTitleBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_BackgroundColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_OutlineBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_OutlineColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_BorderBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_BorderColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_BackgroundBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_ChildBackgroundBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_CornerRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericWindowStyle_Statics::NewProp_BorderPadding,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWindowStyle_Statics::PropPointers) < 2048);
// ********** End Class UGenericWindowStyle Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UGenericWindowStyle_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWindowStyle_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericWindowStyle_Statics::ClassParams = {
	&UGenericWindowStyle::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGenericWindowStyle_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWindowStyle_Statics::PropPointers),
	0,
	0x000800A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWindowStyle_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericWindowStyle_Statics::Class_MetaDataParams)
};
void UGenericWindowStyle::StaticRegisterNativesUGenericWindowStyle()
{
}
UClass* Z_Construct_UClass_UGenericWindowStyle()
{
	if (!Z_Registration_Info_UClass_UGenericWindowStyle.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericWindowStyle.OuterSingleton, Z_Construct_UClass_UGenericWindowStyle_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericWindowStyle.OuterSingleton;
}
UGenericWindowStyle::UGenericWindowStyle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericWindowStyle);
UGenericWindowStyle::~UGenericWindowStyle() {}
// ********** End Class UGenericWindowStyle ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_GenericWindowStyle_h__Script_GenericSlateFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericWindowStyle, UGenericWindowStyle::StaticClass, TEXT("UGenericWindowStyle"), &Z_Registration_Info_UClass_UGenericWindowStyle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericWindowStyle), 4129186591U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_GenericWindowStyle_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_GenericWindowStyle_h__Script_GenericSlateFramework_268957924{
	TEXT("/Script/GenericSlateFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_GenericWindowStyle_h__Script_GenericSlateFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_GenericWindowStyle_h__Script_GenericSlateFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
