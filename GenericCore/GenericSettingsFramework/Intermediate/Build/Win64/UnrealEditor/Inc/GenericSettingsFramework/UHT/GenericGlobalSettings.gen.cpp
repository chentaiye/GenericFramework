// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DeveloperSettings/GenericGlobalSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericGlobalSettings() {}

// ********** Begin Cross Module References ********************************************************
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericDeveloperSettings();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericGlobalSettings();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericGlobalSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericSettingsFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericGlobalSettings ***************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericGlobalSettings;
UClass* UGenericGlobalSettings::GetPrivateStaticClass()
{
	using TClass = UGenericGlobalSettings;
	if (!Z_Registration_Info_UClass_UGenericGlobalSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericGlobalSettings"),
			Z_Registration_Info_UClass_UGenericGlobalSettings.InnerSingleton,
			StaticRegisterNativesUGenericGlobalSettings,
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
	return Z_Registration_Info_UClass_UGenericGlobalSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericGlobalSettings_NoRegister()
{
	return UGenericGlobalSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericGlobalSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\xa1\x86\xe6\x9e\xb6\xe7\xba\xa7\xe5\x85\xa8\xe5\xb1\x80\xe8\xae\xbe\xe7\xbd\xae\xef\xbc\x8c\xe4\xbe\x9b Settings \xe9\x9d\xa2\xe6\x9d\xbf\xe6\xb3\xa8\xe5\x86\x8c\xe5\x85\xa5\xe5\x8f\xa3\xe5\x92\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xa1\x86\xe6\x9e\xb6\xe5\x85\xac\xe5\x85\xb1\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "DeveloperSettings/GenericGlobalSettings.h" },
		{ "ModuleRelativePath", "Public/DeveloperSettings/GenericGlobalSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\xa1\x86\xe6\x9e\xb6\xe7\xba\xa7\xe5\x85\xa8\xe5\xb1\x80\xe8\xae\xbe\xe7\xbd\xae\xef\xbc\x8c\xe4\xbe\x9b Settings \xe9\x9d\xa2\xe6\x9d\xbf\xe6\xb3\xa8\xe5\x86\x8c\xe5\x85\xa5\xe5\x8f\xa3\xe5\x92\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xa1\x86\xe6\x9e\xb6\xe5\x85\xac\xe5\x85\xb1\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bTest_MetaData[] = {
		{ "Category", "Generic Global Settings|Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe7\x95\x99\xe6\xa1\x86\xe6\x9e\xb6\xe5\x85\xa8\xe5\xb1\x80\xe9\xaa\x8c\xe8\xaf\x81\xe5\xbc\x80\xe5\x85\xb3\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe8\xae\xbe\xe7\xbd\xae\xe9\x9d\xa2\xe6\x9d\xbf\xe5\x92\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe4\xbb\xa3\xe7\xa0\x81\xe7\xa1\xae\xe8\xae\xa4\xe9\x85\x8d\xe7\xbd\xae\xe9\x80\x9a\xe8\xb7\xaf\xe6\x98\xaf\xe5\x90\xa6\xe7\x94\x9f\xe6\x95\x88\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/DeveloperSettings/GenericGlobalSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe7\x95\x99\xe6\xa1\x86\xe6\x9e\xb6\xe5\x85\xa8\xe5\xb1\x80\xe9\xaa\x8c\xe8\xaf\x81\xe5\xbc\x80\xe5\x85\xb3\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e\xe8\xae\xbe\xe7\xbd\xae\xe9\x9d\xa2\xe6\x9d\xbf\xe5\x92\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe4\xbb\xa3\xe7\xa0\x81\xe7\xa1\xae\xe8\xae\xa4\xe9\x85\x8d\xe7\xbd\xae\xe9\x80\x9a\xe8\xb7\xaf\xe6\x98\xaf\xe5\x90\xa6\xe7\x94\x9f\xe6\x95\x88\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericGlobalSettings constinit property declarations *******************
	static void NewProp_bTest_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bTest;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGenericGlobalSettings constinit property declarations *********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericGlobalSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericGlobalSettings_Statics

// ********** Begin Class UGenericGlobalSettings Property Definitions ******************************
void Z_Construct_UClass_UGenericGlobalSettings_Statics::NewProp_bTest_SetBit(void* Obj)
{
	((UGenericGlobalSettings*)Obj)->bTest = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UGenericGlobalSettings_Statics::NewProp_bTest = { "bTest", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UGenericGlobalSettings), &Z_Construct_UClass_UGenericGlobalSettings_Statics::NewProp_bTest_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bTest_MetaData), NewProp_bTest_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenericGlobalSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericGlobalSettings_Statics::NewProp_bTest,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericGlobalSettings_Statics::PropPointers) < 2048);
// ********** End Class UGenericGlobalSettings Property Definitions ********************************
UObject* (*const Z_Construct_UClass_UGenericGlobalSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGenericDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSettingsFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericGlobalSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericGlobalSettings_Statics::ClassParams = {
	&UGenericGlobalSettings::StaticClass,
	"GenericSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGenericGlobalSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGenericGlobalSettings_Statics::PropPointers),
	0,
	0x000800A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericGlobalSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericGlobalSettings_Statics::Class_MetaDataParams)
};
void UGenericGlobalSettings::StaticRegisterNativesUGenericGlobalSettings()
{
}
UClass* Z_Construct_UClass_UGenericGlobalSettings()
{
	if (!Z_Registration_Info_UClass_UGenericGlobalSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericGlobalSettings.OuterSingleton, Z_Construct_UClass_UGenericGlobalSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericGlobalSettings.OuterSingleton;
}
UGenericGlobalSettings::UGenericGlobalSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericGlobalSettings);
UGenericGlobalSettings::~UGenericGlobalSettings() {}
// ********** End Class UGenericGlobalSettings *****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h__Script_GenericSettingsFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericGlobalSettings, UGenericGlobalSettings::StaticClass, TEXT("UGenericGlobalSettings"), &Z_Registration_Info_UClass_UGenericGlobalSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericGlobalSettings), 3623772429U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h__Script_GenericSettingsFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h__Script_GenericSettingsFramework_782435754{
	TEXT("/Script/GenericSettingsFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h__Script_GenericSettingsFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h__Script_GenericSettingsFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
