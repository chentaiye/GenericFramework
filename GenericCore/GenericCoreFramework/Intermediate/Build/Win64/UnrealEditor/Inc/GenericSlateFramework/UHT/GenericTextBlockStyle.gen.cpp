// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Style/GenericTextBlockStyle.h"
#include "Fonts/SlateFontInfo.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "Types/SlateVector2.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericTextBlockStyle() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericTextBlockStyle();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericTextBlockStyle_NoRegister();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextOverflowPolicy();
SLATECORE_API UEnum* Z_Construct_UEnum_SlateCore_ETextTransformPolicy();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FDeprecateSlateVector2D();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateColor();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateFontInfo();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericTextBlockStyle ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericTextBlockStyle;
UClass* UGenericTextBlockStyle::GetPrivateStaticClass()
{
	using TClass = UGenericTextBlockStyle;
	if (!Z_Registration_Info_UClass_UGenericTextBlockStyle.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericTextBlockStyle"),
			Z_Registration_Info_UClass_UGenericTextBlockStyle.InnerSingleton,
			StaticRegisterNativesUGenericTextBlockStyle,
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
	return Z_Registration_Info_UClass_UGenericTextBlockStyle.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericTextBlockStyle_NoRegister()
{
	return UGenericTextBlockStyle::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericTextBlockStyle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe9\x80\x9a\xe7\x94\xa8\xe6\x96\x87\xe6\x9c\xac\xe5\x9d\x97\xe6\xa0\xb7\xe5\xbc\x8f\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Style/GenericTextBlockStyle.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe9\x80\x9a\xe7\x94\xa8\xe6\x96\x87\xe6\x9c\xac\xe5\x9d\x97\xe6\xa0\xb7\xe5\xbc\x8f\xef\xbc\x8c\xe8\xb4\x9f\xe8\xb4\xa3\xe6\x8a\x8a\xe8\x93\x9d\xe5\x9b\xbe\xe5\x8f\xaf\xe7\xbc\x96\xe8\xbe\x91\xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe5\x88\xb0\xe5\xba\x95\xe5\xb1\x82 Slate \xe5\xae\x9e\xe4\xbe\x8b\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Font_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xad\x97\xe4\xbd\x93\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xad\x97\xe4\xbd\x93\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ColorAndOpacity_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShadowOffset_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x98\xb4\xe5\xbd\xb1\xe5\x81\x8f\xe7\xa7\xbb\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ShadowColorAndOpacity_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe9\x98\xb4\xe5\xbd\xb1\xe9\xa2\x9c\xe8\x89\xb2\xe5\x92\x8c\xe9\x80\x8f\xe6\x98\x8e\xe5\xba\xa6\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SelectedBackgroundColor_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xb2\xe9\x80\x89\xe6\x8b\xa9""Background\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\xb7\xb2\xe9\x80\x89\xe6\x8b\xa9""Background\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighlightColor_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Highlight\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Highlight\xe9\xa2\x9c\xe8\x89\xb2\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HighlightShape_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98HighlightShape\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98HighlightShape\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StrikeBrush_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x88\xa0\xe9\x99\xa4\xe7\xba\xbf\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UnderlineBrush_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98Underline\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98Underline\xe7\x94\xbb\xe5\x88\xb7\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\x9e\x84\xe5\xbb\xba\xe6\x88\x96 UMG \xe5\xb1\x9e\xe6\x80\xa7\xe5\x90\x8c\xe6\xad\xa5\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_TransformPolicy_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x96\x87\xe6\x9c\xac\xe5\x8f\x98\xe6\x8d\xa2\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_OverflowPolicy_MetaData[] = {
		{ "Category", "Generic Text Block Style" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Style/GenericTextBlockStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xba\xa2\xe5\x87\xba\xe7\xad\x96\xe7\x95\xa5\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericTextBlockStyle constinit property declarations *******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Font;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ColorAndOpacity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShadowOffset;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ShadowColorAndOpacity;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SelectedBackgroundColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HighlightColor;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HighlightShape;
	static const UECodeGen_Private::FStructPropertyParams NewProp_StrikeBrush;
	static const UECodeGen_Private::FStructPropertyParams NewProp_UnderlineBrush;
	static const UECodeGen_Private::FBytePropertyParams NewProp_TransformPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_TransformPolicy;
	static const UECodeGen_Private::FBytePropertyParams NewProp_OverflowPolicy_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_OverflowPolicy;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGenericTextBlockStyle constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericTextBlockStyle>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericTextBlockStyle_Statics

// ********** Begin Class UGenericTextBlockStyle Property Definitions ******************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_Font = { "Font", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, Font), Z_Construct_UScriptStruct_FSlateFontInfo, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Font_MetaData), NewProp_Font_MetaData) }; // 167205173
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_ColorAndOpacity = { "ColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, ColorAndOpacity), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ColorAndOpacity_MetaData), NewProp_ColorAndOpacity_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_ShadowOffset = { "ShadowOffset", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, ShadowOffset), Z_Construct_UScriptStruct_FDeprecateSlateVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShadowOffset_MetaData), NewProp_ShadowOffset_MetaData) }; // 2744153745
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_ShadowColorAndOpacity = { "ShadowColorAndOpacity", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, ShadowColorAndOpacity), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ShadowColorAndOpacity_MetaData), NewProp_ShadowColorAndOpacity_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_SelectedBackgroundColor = { "SelectedBackgroundColor", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, SelectedBackgroundColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SelectedBackgroundColor_MetaData), NewProp_SelectedBackgroundColor_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_HighlightColor = { "HighlightColor", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, HighlightColor), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighlightColor_MetaData), NewProp_HighlightColor_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_HighlightShape = { "HighlightShape", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, HighlightShape), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HighlightShape_MetaData), NewProp_HighlightShape_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_StrikeBrush = { "StrikeBrush", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, StrikeBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StrikeBrush_MetaData), NewProp_StrikeBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_UnderlineBrush = { "UnderlineBrush", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, UnderlineBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UnderlineBrush_MetaData), NewProp_UnderlineBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_TransformPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_TransformPolicy = { "TransformPolicy", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, TransformPolicy), Z_Construct_UEnum_SlateCore_ETextTransformPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_TransformPolicy_MetaData), NewProp_TransformPolicy_MetaData) }; // 2733367800
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_OverflowPolicy_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_OverflowPolicy = { "OverflowPolicy", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericTextBlockStyle, OverflowPolicy), Z_Construct_UEnum_SlateCore_ETextOverflowPolicy, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_OverflowPolicy_MetaData), NewProp_OverflowPolicy_MetaData) }; // 1738161579
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenericTextBlockStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_Font,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_ColorAndOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_ShadowOffset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_ShadowColorAndOpacity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_SelectedBackgroundColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_HighlightColor,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_HighlightShape,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_StrikeBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_UnderlineBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_TransformPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_TransformPolicy,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_OverflowPolicy_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericTextBlockStyle_Statics::NewProp_OverflowPolicy,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericTextBlockStyle_Statics::PropPointers) < 2048);
// ********** End Class UGenericTextBlockStyle Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UGenericTextBlockStyle_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericTextBlockStyle_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericTextBlockStyle_Statics::ClassParams = {
	&UGenericTextBlockStyle::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGenericTextBlockStyle_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGenericTextBlockStyle_Statics::PropPointers),
	0,
	0x000800A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericTextBlockStyle_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericTextBlockStyle_Statics::Class_MetaDataParams)
};
void UGenericTextBlockStyle::StaticRegisterNativesUGenericTextBlockStyle()
{
}
UClass* Z_Construct_UClass_UGenericTextBlockStyle()
{
	if (!Z_Registration_Info_UClass_UGenericTextBlockStyle.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericTextBlockStyle.OuterSingleton, Z_Construct_UClass_UGenericTextBlockStyle_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericTextBlockStyle.OuterSingleton;
}
UGenericTextBlockStyle::UGenericTextBlockStyle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericTextBlockStyle);
UGenericTextBlockStyle::~UGenericTextBlockStyle() {}
// ********** End Class UGenericTextBlockStyle *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_GenericTextBlockStyle_h__Script_GenericSlateFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericTextBlockStyle, UGenericTextBlockStyle::StaticClass, TEXT("UGenericTextBlockStyle"), &Z_Registration_Info_UClass_UGenericTextBlockStyle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericTextBlockStyle), 3700255331U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_GenericTextBlockStyle_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_GenericTextBlockStyle_h__Script_GenericSlateFramework_2758293203{
	TEXT("/Script/GenericSlateFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_GenericTextBlockStyle_h__Script_GenericSlateFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_GenericTextBlockStyle_h__Script_GenericSlateFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
