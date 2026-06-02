// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WorldSettings/OpenWorldSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeOpenWorldSettings() {}

// ********** Begin Cross Module References ********************************************************
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
GENERICSETTINGSEDFRAMEWORK_API UClass* Z_Construct_UClass_UOpenWorldSettings();
GENERICSETTINGSEDFRAMEWORK_API UClass* Z_Construct_UClass_UOpenWorldSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericSettingsEdFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UOpenWorldSettings *******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UOpenWorldSettings;
UClass* UOpenWorldSettings::GetPrivateStaticClass()
{
	using TClass = UOpenWorldSettings;
	if (!Z_Registration_Info_UClass_UOpenWorldSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("OpenWorldSettings"),
			Z_Registration_Info_UClass_UOpenWorldSettings.InnerSingleton,
			StaticRegisterNativesUOpenWorldSettings,
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
	return Z_Registration_Info_UClass_UOpenWorldSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UOpenWorldSettings_NoRegister()
{
	return UOpenWorldSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UOpenWorldSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb3\xa8\xe5\x86\x8c\xe4\xb8\x96\xe7\x95\x8c\xe8\xae\xbe\xe7\xbd\xae\xe5\xb7\xa5\xe5\x85\xb7\xe6\xa0\x8f\xe5\x85\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe5\xb9\xb6\xe6\x8a\x8a\xe7\x82\xb9\xe5\x87\xbb\xe8\xa1\x8c\xe4\xb8\xba\xe8\xbd\xac\xe5\x8f\x91\xe5\x88\xb0\xe4\xb8\x96\xe7\x95\x8c\xe8\xae\xbe\xe7\xbd\xae\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8 Tab\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "WorldSettings/OpenWorldSettings.h" },
		{ "ModuleRelativePath", "Public/WorldSettings/OpenWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb3\xa8\xe5\x86\x8c\xe4\xb8\x96\xe7\x95\x8c\xe8\xae\xbe\xe7\xbd\xae\xe5\xb7\xa5\xe5\x85\xb7\xe6\xa0\x8f\xe5\x85\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe5\xb9\xb6\xe6\x8a\x8a\xe7\x82\xb9\xe5\x87\xbb\xe8\xa1\x8c\xe4\xb8\xba\xe8\xbd\xac\xe5\x8f\x91\xe5\x88\xb0\xe4\xb8\x96\xe7\x95\x8c\xe8\xae\xbe\xe7\xbd\xae\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8 Tab\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UOpenWorldSettings constinit property declarations ***********************
// ********** End Class UOpenWorldSettings constinit property declarations *************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOpenWorldSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UOpenWorldSettings_Statics
UObject* (*const Z_Construct_UClass_UOpenWorldSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSettingsEdFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOpenWorldSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOpenWorldSettings_Statics::ClassParams = {
	&UOpenWorldSettings::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOpenWorldSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UOpenWorldSettings_Statics::Class_MetaDataParams)
};
void UOpenWorldSettings::StaticRegisterNativesUOpenWorldSettings()
{
}
UClass* Z_Construct_UClass_UOpenWorldSettings()
{
	if (!Z_Registration_Info_UClass_UOpenWorldSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOpenWorldSettings.OuterSingleton, Z_Construct_UClass_UOpenWorldSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOpenWorldSettings.OuterSingleton;
}
UOpenWorldSettings::UOpenWorldSettings() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UOpenWorldSettings);
UOpenWorldSettings::~UOpenWorldSettings() {}
// ********** End Class UOpenWorldSettings *********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h__Script_GenericSettingsEdFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOpenWorldSettings, UOpenWorldSettings::StaticClass, TEXT("UOpenWorldSettings"), &Z_Registration_Info_UClass_UOpenWorldSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOpenWorldSettings), 3357041986U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h__Script_GenericSettingsEdFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h__Script_GenericSettingsEdFramework_4269634240{
	TEXT("/Script/GenericSettingsEdFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h__Script_GenericSettingsEdFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h__Script_GenericSettingsEdFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
