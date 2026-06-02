// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DeveloperSettings/GenericDeveloperEdSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericDeveloperEdSettings() {}

// ********** Begin Cross Module References ********************************************************
GENERICSETTINGSEDFRAMEWORK_API UClass* Z_Construct_UClass_UGenericDeveloperEdSettings();
GENERICSETTINGSEDFRAMEWORK_API UClass* Z_Construct_UClass_UGenericDeveloperEdSettings_NoRegister();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericDeveloperSettings();
UPackage* Z_Construct_UPackage__Script_GenericSettingsEdFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericDeveloperEdSettings **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericDeveloperEdSettings;
UClass* UGenericDeveloperEdSettings::GetPrivateStaticClass()
{
	using TClass = UGenericDeveloperEdSettings;
	if (!Z_Registration_Info_UClass_UGenericDeveloperEdSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericDeveloperEdSettings"),
			Z_Registration_Info_UClass_UGenericDeveloperEdSettings.InnerSingleton,
			StaticRegisterNativesUGenericDeveloperEdSettings,
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
	return Z_Registration_Info_UClass_UGenericDeveloperEdSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericDeveloperEdSettings_NoRegister()
{
	return UGenericDeveloperEdSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericDeveloperEdSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbb\x9f\xe4\xb8\x80 GenericFramework \xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe8\xae\xbe\xe7\xbd\xae\xe7\x9a\x84\xe5\x88\x86\xe7\xb1\xbb\xef\xbc\x8c\xe4\xbe\x9b\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe6\x89\xa9\xe5\xb1\x95\xe8\xae\xbe\xe7\xbd\xae\xe7\xb1\xbb\xe8\xbf\x9b\xe5\x85\xa5\xe5\x90\x8c\xe4\xb8\x80\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae\xe9\x9d\xa2\xe6\x9d\xbf\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "DeveloperSettings/GenericDeveloperEdSettings.h" },
		{ "ModuleRelativePath", "Public/DeveloperSettings/GenericDeveloperEdSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbb\x9f\xe4\xb8\x80 GenericFramework \xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe8\xae\xbe\xe7\xbd\xae\xe7\x9a\x84\xe5\x88\x86\xe7\xb1\xbb\xef\xbc\x8c\xe4\xbe\x9b\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe6\x89\xa9\xe5\xb1\x95\xe8\xae\xbe\xe7\xbd\xae\xe7\xb1\xbb\xe8\xbf\x9b\xe5\x85\xa5\xe5\x90\x8c\xe4\xb8\x80\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae\xe9\x9d\xa2\xe6\x9d\xbf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericDeveloperEdSettings constinit property declarations **************
// ********** End Class UGenericDeveloperEdSettings constinit property declarations ****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericDeveloperEdSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericDeveloperEdSettings_Statics
UObject* (*const Z_Construct_UClass_UGenericDeveloperEdSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGenericDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSettingsEdFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericDeveloperEdSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericDeveloperEdSettings_Statics::ClassParams = {
	&UGenericDeveloperEdSettings::StaticClass,
	"GenericEdSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000800A3u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericDeveloperEdSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericDeveloperEdSettings_Statics::Class_MetaDataParams)
};
void UGenericDeveloperEdSettings::StaticRegisterNativesUGenericDeveloperEdSettings()
{
}
UClass* Z_Construct_UClass_UGenericDeveloperEdSettings()
{
	if (!Z_Registration_Info_UClass_UGenericDeveloperEdSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericDeveloperEdSettings.OuterSingleton, Z_Construct_UClass_UGenericDeveloperEdSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericDeveloperEdSettings.OuterSingleton;
}
UGenericDeveloperEdSettings::UGenericDeveloperEdSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericDeveloperEdSettings);
UGenericDeveloperEdSettings::~UGenericDeveloperEdSettings() {}
// ********** End Class UGenericDeveloperEdSettings ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h__Script_GenericSettingsEdFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericDeveloperEdSettings, UGenericDeveloperEdSettings::StaticClass, TEXT("UGenericDeveloperEdSettings"), &Z_Registration_Info_UClass_UGenericDeveloperEdSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericDeveloperEdSettings), 4292119418U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h__Script_GenericSettingsEdFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h__Script_GenericSettingsEdFramework_3461731181{
	TEXT("/Script/GenericSettingsEdFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h__Script_GenericSettingsEdFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h__Script_GenericSettingsEdFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
