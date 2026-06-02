// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DeveloperSettings/GenericDeveloperSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericDeveloperSettings() {}

// ********** Begin Cross Module References ********************************************************
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericDeveloperSettings();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericDeveloperSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericSettingsFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericDeveloperSettings ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericDeveloperSettings;
UClass* UGenericDeveloperSettings::GetPrivateStaticClass()
{
	using TClass = UGenericDeveloperSettings;
	if (!Z_Registration_Info_UClass_UGenericDeveloperSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericDeveloperSettings"),
			Z_Registration_Info_UClass_UGenericDeveloperSettings.InnerSingleton,
			StaticRegisterNativesUGenericDeveloperSettings,
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
	return Z_Registration_Info_UClass_UGenericDeveloperSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericDeveloperSettings_NoRegister()
{
	return UGenericDeveloperSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericDeveloperSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbb\x9f\xe4\xb8\x80 GenericFramework \xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\xae\xbe\xe7\xbd\xae\xe7\x9a\x84\xe5\xae\xb9\xe5\x99\xa8\xe4\xb8\x8e\xe5\x88\x86\xe7\xb1\xbb\xef\xbc\x8c\xe4\xbe\x9b\xe5\x90\x84\xe4\xb8\x9a\xe5\x8a\xa1\xe8\xae\xbe\xe7\xbd\xae\xe7\xb1\xbb\xe7\xbb\xa7\xe6\x89\xbf\xe5\x90\x8e\xe8\xbf\x9b\xe5\x85\xa5\xe5\x90\x8c\xe4\xb8\x80\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae\xe9\x9d\xa2\xe6\x9d\xbf\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "DeveloperSettings/GenericDeveloperSettings.h" },
		{ "ModuleRelativePath", "Public/DeveloperSettings/GenericDeveloperSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbb\x9f\xe4\xb8\x80 GenericFramework \xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\xae\xbe\xe7\xbd\xae\xe7\x9a\x84\xe5\xae\xb9\xe5\x99\xa8\xe4\xb8\x8e\xe5\x88\x86\xe7\xb1\xbb\xef\xbc\x8c\xe4\xbe\x9b\xe5\x90\x84\xe4\xb8\x9a\xe5\x8a\xa1\xe8\xae\xbe\xe7\xbd\xae\xe7\xb1\xbb\xe7\xbb\xa7\xe6\x89\xbf\xe5\x90\x8e\xe8\xbf\x9b\xe5\x85\xa5\xe5\x90\x8c\xe4\xb8\x80\xe9\xa1\xb9\xe7\x9b\xae\xe8\xae\xbe\xe7\xbd\xae\xe9\x9d\xa2\xe6\x9d\xbf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericDeveloperSettings constinit property declarations ****************
// ********** End Class UGenericDeveloperSettings constinit property declarations ******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericDeveloperSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericDeveloperSettings_Statics
UObject* (*const Z_Construct_UClass_UGenericDeveloperSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSettingsFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericDeveloperSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericDeveloperSettings_Statics::ClassParams = {
	&UGenericDeveloperSettings::StaticClass,
	"GenericSettings",
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericDeveloperSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericDeveloperSettings_Statics::Class_MetaDataParams)
};
void UGenericDeveloperSettings::StaticRegisterNativesUGenericDeveloperSettings()
{
}
UClass* Z_Construct_UClass_UGenericDeveloperSettings()
{
	if (!Z_Registration_Info_UClass_UGenericDeveloperSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericDeveloperSettings.OuterSingleton, Z_Construct_UClass_UGenericDeveloperSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericDeveloperSettings.OuterSingleton;
}
UGenericDeveloperSettings::UGenericDeveloperSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericDeveloperSettings);
UGenericDeveloperSettings::~UGenericDeveloperSettings() {}
// ********** End Class UGenericDeveloperSettings **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h__Script_GenericSettingsFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericDeveloperSettings, UGenericDeveloperSettings::StaticClass, TEXT("UGenericDeveloperSettings"), &Z_Registration_Info_UClass_UGenericDeveloperSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericDeveloperSettings), 106835871U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h__Script_GenericSettingsFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h__Script_GenericSettingsFramework_3054795435{
	TEXT("/Script/GenericSettingsFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h__Script_GenericSettingsFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h__Script_GenericSettingsFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
