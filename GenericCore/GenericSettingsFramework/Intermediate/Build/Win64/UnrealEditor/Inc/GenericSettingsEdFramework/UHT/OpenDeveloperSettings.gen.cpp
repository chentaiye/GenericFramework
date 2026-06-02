// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DeveloperSettings/OpenDeveloperSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeOpenDeveloperSettings() {}

// ********** Begin Cross Module References ********************************************************
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
GENERICSETTINGSEDFRAMEWORK_API UClass* Z_Construct_UClass_UOpenDeveloperSettings();
GENERICSETTINGSEDFRAMEWORK_API UClass* Z_Construct_UClass_UOpenDeveloperSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericSettingsEdFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UOpenDeveloperSettings ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UOpenDeveloperSettings;
UClass* UOpenDeveloperSettings::GetPrivateStaticClass()
{
	using TClass = UOpenDeveloperSettings;
	if (!Z_Registration_Info_UClass_UOpenDeveloperSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("OpenDeveloperSettings"),
			Z_Registration_Info_UClass_UOpenDeveloperSettings.InnerSingleton,
			StaticRegisterNativesUOpenDeveloperSettings,
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
	return Z_Registration_Info_UClass_UOpenDeveloperSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UOpenDeveloperSettings_NoRegister()
{
	return UOpenDeveloperSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UOpenDeveloperSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x9c\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe4\xb8\xad\xe6\xb3\xa8\xe5\x86\x8c GenericFramework \xe8\xae\xbe\xe7\xbd\xae\xe5\x85\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe5\xb9\xb6\xe6\x8a\x8a\xe5\xb7\xa5\xe5\x85\xb7\xe6\xa0\x8f\xe6\x8c\x89\xe9\x92\xae\xe8\xb7\xb3\xe8\xbd\xac\xe5\x88\xb0\xe7\xbb\x9f\xe4\xb8\x80\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe9\xa1\xb5\xe7\xad\xbe\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "DeveloperSettings/OpenDeveloperSettings.h" },
		{ "ModuleRelativePath", "Public/DeveloperSettings/OpenDeveloperSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x9c\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe4\xb8\xad\xe6\xb3\xa8\xe5\x86\x8c GenericFramework \xe8\xae\xbe\xe7\xbd\xae\xe5\x85\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe5\xb9\xb6\xe6\x8a\x8a\xe5\xb7\xa5\xe5\x85\xb7\xe6\xa0\x8f\xe6\x8c\x89\xe9\x92\xae\xe8\xb7\xb3\xe8\xbd\xac\xe5\x88\xb0\xe7\xbb\x9f\xe4\xb8\x80\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe9\xa1\xb5\xe7\xad\xbe\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UOpenDeveloperSettings constinit property declarations *******************
// ********** End Class UOpenDeveloperSettings constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOpenDeveloperSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UOpenDeveloperSettings_Statics
UObject* (*const Z_Construct_UClass_UOpenDeveloperSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSettingsEdFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOpenDeveloperSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOpenDeveloperSettings_Statics::ClassParams = {
	&UOpenDeveloperSettings::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOpenDeveloperSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UOpenDeveloperSettings_Statics::Class_MetaDataParams)
};
void UOpenDeveloperSettings::StaticRegisterNativesUOpenDeveloperSettings()
{
}
UClass* Z_Construct_UClass_UOpenDeveloperSettings()
{
	if (!Z_Registration_Info_UClass_UOpenDeveloperSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOpenDeveloperSettings.OuterSingleton, Z_Construct_UClass_UOpenDeveloperSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOpenDeveloperSettings.OuterSingleton;
}
UOpenDeveloperSettings::UOpenDeveloperSettings() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UOpenDeveloperSettings);
UOpenDeveloperSettings::~UOpenDeveloperSettings() {}
// ********** End Class UOpenDeveloperSettings *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_OpenDeveloperSettings_h__Script_GenericSettingsEdFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOpenDeveloperSettings, UOpenDeveloperSettings::StaticClass, TEXT("UOpenDeveloperSettings"), &Z_Registration_Info_UClass_UOpenDeveloperSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOpenDeveloperSettings), 3136549745U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_OpenDeveloperSettings_h__Script_GenericSettingsEdFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_OpenDeveloperSettings_h__Script_GenericSettingsEdFramework_2328570994{
	TEXT("/Script/GenericSettingsEdFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_OpenDeveloperSettings_h__Script_GenericSettingsEdFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_OpenDeveloperSettings_h__Script_GenericSettingsEdFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
