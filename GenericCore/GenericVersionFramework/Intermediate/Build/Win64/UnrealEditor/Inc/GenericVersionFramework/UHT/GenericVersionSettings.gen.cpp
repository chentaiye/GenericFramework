// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Settings/GenericVersionSettings.h"
#include "Types/GenericVersionTypes.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericVersionSettings() {}

// ********** Begin Cross Module References ********************************************************
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericDeveloperSettings();
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionSettings();
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionSettings_NoRegister();
GENERICVERSIONFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FGenericVersionDefinition();
UPackage* Z_Construct_UPackage__Script_GenericVersionFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericVersionSettings **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericVersionSettings;
UClass* UGenericVersionSettings::GetPrivateStaticClass()
{
	using TClass = UGenericVersionSettings;
	if (!Z_Registration_Info_UClass_UGenericVersionSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericVersionSettings"),
			Z_Registration_Info_UClass_UGenericVersionSettings.InnerSingleton,
			StaticRegisterNativesUGenericVersionSettings,
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
	return Z_Registration_Info_UClass_UGenericVersionSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericVersionSettings_NoRegister()
{
	return UGenericVersionSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericVersionSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\xa1\xb9\xe7\x9b\xae\xe7\xba\xa7\xe7\x89\x88\xe6\x9c\xac\xe8\xae\xbe\xe7\xbd\xae\xef\xbc\x8c\xe9\x9b\x86\xe4\xb8\xad\xe5\xa3\xb0\xe6\x98\x8e\xe5\xbd\x93\xe5\x89\x8d\xe9\xa1\xb9\xe7\x9b\xae\xe4\xbc\x9a\xe4\xbd\xbf\xe7\x94\xa8\xe5\x88\xb0\xe7\x9a\x84\xe4\xb8\x9a\xe5\x8a\xa1\xe6\x95\xb0\xe6\x8d\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Settings/GenericVersionSettings.h" },
		{ "ModuleRelativePath", "Public/Settings/GenericVersionSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\xa1\xb9\xe7\x9b\xae\xe7\xba\xa7\xe7\x89\x88\xe6\x9c\xac\xe8\xae\xbe\xe7\xbd\xae\xef\xbc\x8c\xe9\x9b\x86\xe4\xb8\xad\xe5\xa3\xb0\xe6\x98\x8e\xe5\xbd\x93\xe5\x89\x8d\xe9\xa1\xb9\xe7\x9b\xae\xe4\xbc\x9a\xe4\xbd\xbf\xe7\x94\xa8\xe5\x88\xb0\xe7\x9a\x84\xe4\xb8\x9a\xe5\x8a\xa1\xe6\x95\xb0\xe6\x8d\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_VersionDefinitions_MetaData[] = {
		{ "Category", "Version" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe8\xa1\xa8\xef\xbc\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x94\xb1 UGenericVersionDataSubsystem \xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe6\x97\xb6\xe8\x87\xaa\xe5\x8a\xa8\xe6\xb3\xa8\xe5\x86\x8c\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Settings/GenericVersionSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\xad\xe5\xa4\xae\xe7\x89\x88\xe6\x9c\xac\xe5\xae\x9a\xe4\xb9\x89\xe8\xa1\xa8\xef\xbc\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x94\xb1 UGenericVersionDataSubsystem \xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe6\x97\xb6\xe8\x87\xaa\xe5\x8a\xa8\xe6\xb3\xa8\xe5\x86\x8c\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericVersionSettings constinit property declarations ******************
	static const UECodeGen_Private::FStructPropertyParams NewProp_VersionDefinitions_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_VersionDefinitions;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGenericVersionSettings constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericVersionSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericVersionSettings_Statics

// ********** Begin Class UGenericVersionSettings Property Definitions *****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGenericVersionSettings_Statics::NewProp_VersionDefinitions_Inner = { "VersionDefinitions", nullptr, (EPropertyFlags)0x0000000000004000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGenericVersionDefinition, METADATA_PARAMS(0, nullptr) }; // 144404518
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGenericVersionSettings_Statics::NewProp_VersionDefinitions = { "VersionDefinitions", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericVersionSettings, VersionDefinitions), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_VersionDefinitions_MetaData), NewProp_VersionDefinitions_MetaData) }; // 144404518
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenericVersionSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericVersionSettings_Statics::NewProp_VersionDefinitions_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericVersionSettings_Statics::NewProp_VersionDefinitions,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVersionSettings_Statics::PropPointers) < 2048);
// ********** End Class UGenericVersionSettings Property Definitions *******************************
UObject* (*const Z_Construct_UClass_UGenericVersionSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGenericDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericVersionFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVersionSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericVersionSettings_Statics::ClassParams = {
	&UGenericVersionSettings::StaticClass,
	"GenericSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGenericVersionSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVersionSettings_Statics::PropPointers),
	0,
	0x000800A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericVersionSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericVersionSettings_Statics::Class_MetaDataParams)
};
void UGenericVersionSettings::StaticRegisterNativesUGenericVersionSettings()
{
}
UClass* Z_Construct_UClass_UGenericVersionSettings()
{
	if (!Z_Registration_Info_UClass_UGenericVersionSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericVersionSettings.OuterSingleton, Z_Construct_UClass_UGenericVersionSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericVersionSettings.OuterSingleton;
}
UGenericVersionSettings::UGenericVersionSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericVersionSettings);
UGenericVersionSettings::~UGenericVersionSettings() {}
// ********** End Class UGenericVersionSettings ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h__Script_GenericVersionFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericVersionSettings, UGenericVersionSettings::StaticClass, TEXT("UGenericVersionSettings"), &Z_Registration_Info_UClass_UGenericVersionSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericVersionSettings), 3957135974U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h__Script_GenericVersionFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h__Script_GenericVersionFramework_1676195892{
	TEXT("/Script/GenericVersionFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h__Script_GenericVersionFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h__Script_GenericVersionFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
