// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Style/DevSlateButtonStyle.h"
#include "Layout/Margin.h"
#include "Sound/SlateSound.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDevSlateButtonStyle() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UDevSlateButtonStyle();
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UDevSlateButtonStyle_NoRegister();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FMargin();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateColor();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateSound();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UDevSlateButtonStyle *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UDevSlateButtonStyle;
UClass* UDevSlateButtonStyle::GetPrivateStaticClass()
{
	using TClass = UDevSlateButtonStyle;
	if (!Z_Registration_Info_UClass_UDevSlateButtonStyle.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("DevSlateButtonStyle"),
			Z_Registration_Info_UClass_UDevSlateButtonStyle.InnerSingleton,
			StaticRegisterNativesUDevSlateButtonStyle,
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
	return Z_Registration_Info_UClass_UDevSlateButtonStyle.InnerSingleton;
}
UClass* Z_Construct_UClass_UDevSlateButtonStyle_NoRegister()
{
	return UDevSlateButtonStyle::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UDevSlateButtonStyle_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb0\x81\xe8\xa3\x85""DevSlate\xe6\x8c\x89\xe9\x92\xae\xe6\xa0\xb7\xe5\xbc\x8f\xe8\xb5\x84\xe6\xba\x90\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\xa0\xb7\xe5\xbc\x8f\xe9\x9b\x86\xe5\x92\x8c UMG \xe6\x8e\xa7\xe4\xbb\xb6\xe5\x85\xb1\xe4\xba\xab\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Style/DevSlateButtonStyle.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb0\x81\xe8\xa3\x85""DevSlate\xe6\x8c\x89\xe9\x92\xae\xe6\xa0\xb7\xe5\xbc\x8f\xe8\xb5\x84\xe6\xba\x90\xef\xbc\x8c\xe4\xbe\x9b Slate \xe6\xa0\xb7\xe5\xbc\x8f\xe9\x9b\x86\xe5\x92\x8c UMG \xe6\x8e\xa7\xe4\xbb\xb6\xe5\x85\xb1\xe4\xba\xab\xe6\x98\xbe\xe7\xa4\xba\xe5\x8f\x82\xe6\x95\xb0\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Normal_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Hovered_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Pressed_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalForeground_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HoveredForeground_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressedForeground_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DisabledForeground_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NormalPadding_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressedPadding_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HoveredSlateSound_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PressedSlateSound_MetaData[] = {
		{ "Category", "Generic Button Style" },
		{ "ModuleRelativePath", "Public/Style/DevSlateButtonStyle.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UDevSlateButtonStyle constinit property declarations *********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Normal;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Hovered;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Pressed;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NormalForeground;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HoveredForeground;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PressedForeground;
	static const UECodeGen_Private::FStructPropertyParams NewProp_DisabledForeground;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NormalPadding;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PressedPadding;
	static const UECodeGen_Private::FStructPropertyParams NewProp_HoveredSlateSound;
	static const UECodeGen_Private::FStructPropertyParams NewProp_PressedSlateSound;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UDevSlateButtonStyle constinit property declarations ***********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UDevSlateButtonStyle>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UDevSlateButtonStyle_Statics

// ********** Begin Class UDevSlateButtonStyle Property Definitions ********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_Normal = { "Normal", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, Normal), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Normal_MetaData), NewProp_Normal_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_Hovered = { "Hovered", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, Hovered), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Hovered_MetaData), NewProp_Hovered_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_Pressed = { "Pressed", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, Pressed), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Pressed_MetaData), NewProp_Pressed_MetaData) }; // 4278521822
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_NormalForeground = { "NormalForeground", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, NormalForeground), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalForeground_MetaData), NewProp_NormalForeground_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_HoveredForeground = { "HoveredForeground", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, HoveredForeground), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HoveredForeground_MetaData), NewProp_HoveredForeground_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_PressedForeground = { "PressedForeground", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, PressedForeground), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressedForeground_MetaData), NewProp_PressedForeground_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_DisabledForeground = { "DisabledForeground", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, DisabledForeground), Z_Construct_UScriptStruct_FSlateColor, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DisabledForeground_MetaData), NewProp_DisabledForeground_MetaData) }; // 1663967387
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_NormalPadding = { "NormalPadding", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, NormalPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NormalPadding_MetaData), NewProp_NormalPadding_MetaData) }; // 4099648758
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_PressedPadding = { "PressedPadding", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, PressedPadding), Z_Construct_UScriptStruct_FMargin, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressedPadding_MetaData), NewProp_PressedPadding_MetaData) }; // 4099648758
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_HoveredSlateSound = { "HoveredSlateSound", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, HoveredSlateSound), Z_Construct_UScriptStruct_FSlateSound, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HoveredSlateSound_MetaData), NewProp_HoveredSlateSound_MetaData) }; // 845387352
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_PressedSlateSound = { "PressedSlateSound", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UDevSlateButtonStyle, PressedSlateSound), Z_Construct_UScriptStruct_FSlateSound, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PressedSlateSound_MetaData), NewProp_PressedSlateSound_MetaData) }; // 845387352
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UDevSlateButtonStyle_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_Normal,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_Hovered,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_Pressed,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_NormalForeground,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_HoveredForeground,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_PressedForeground,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_DisabledForeground,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_NormalPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_PressedPadding,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_HoveredSlateSound,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UDevSlateButtonStyle_Statics::NewProp_PressedSlateSound,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDevSlateButtonStyle_Statics::PropPointers) < 2048);
// ********** End Class UDevSlateButtonStyle Property Definitions **********************************
UObject* (*const Z_Construct_UClass_UDevSlateButtonStyle_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UDevSlateButtonStyle_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UDevSlateButtonStyle_Statics::ClassParams = {
	&UDevSlateButtonStyle::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UDevSlateButtonStyle_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UDevSlateButtonStyle_Statics::PropPointers),
	0,
	0x000800A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UDevSlateButtonStyle_Statics::Class_MetaDataParams), Z_Construct_UClass_UDevSlateButtonStyle_Statics::Class_MetaDataParams)
};
void UDevSlateButtonStyle::StaticRegisterNativesUDevSlateButtonStyle()
{
}
UClass* Z_Construct_UClass_UDevSlateButtonStyle()
{
	if (!Z_Registration_Info_UClass_UDevSlateButtonStyle.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UDevSlateButtonStyle.OuterSingleton, Z_Construct_UClass_UDevSlateButtonStyle_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UDevSlateButtonStyle.OuterSingleton;
}
UDevSlateButtonStyle::UDevSlateButtonStyle(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UDevSlateButtonStyle);
UDevSlateButtonStyle::~UDevSlateButtonStyle() {}
// ********** End Class UDevSlateButtonStyle *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_DevSlateButtonStyle_h__Script_GenericSlateFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UDevSlateButtonStyle, UDevSlateButtonStyle::StaticClass, TEXT("UDevSlateButtonStyle"), &Z_Registration_Info_UClass_UDevSlateButtonStyle, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UDevSlateButtonStyle), 676468660U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_DevSlateButtonStyle_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_DevSlateButtonStyle_h__Script_GenericSlateFramework_888817107{
	TEXT("/Script/GenericSlateFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_DevSlateButtonStyle_h__Script_GenericSlateFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_Style_DevSlateButtonStyle_h__Script_GenericSlateFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
