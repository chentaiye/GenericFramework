// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WorldSettings/GenericWorldSettingsEdSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericWorldSettingsEdSubsystem() {}

// ********** Begin Cross Module References ********************************************************
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
GENERICSETTINGSEDFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettingsEdSubsystem();
GENERICSETTINGSEDFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettingsEdSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericSettingsEdFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericWorldSettingsEdSubsystem *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericWorldSettingsEdSubsystem;
UClass* UGenericWorldSettingsEdSubsystem::GetPrivateStaticClass()
{
	using TClass = UGenericWorldSettingsEdSubsystem;
	if (!Z_Registration_Info_UClass_UGenericWorldSettingsEdSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericWorldSettingsEdSubsystem"),
			Z_Registration_Info_UClass_UGenericWorldSettingsEdSubsystem.InnerSingleton,
			StaticRegisterNativesUGenericWorldSettingsEdSubsystem,
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
	return Z_Registration_Info_UClass_UGenericWorldSettingsEdSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericWorldSettingsEdSubsystem_NoRegister()
{
	return UGenericWorldSettingsEdSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericWorldSettingsEdSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x9c\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe4\xbe\xa7\xe7\xae\xa1\xe7\x90\x86\xe4\xb8\x96\xe7\x95\x8c\xe7\xba\xa7\xe8\xae\xbe\xe7\xbd\xae\xe7\x9a\x84\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x8f\x91\xe7\x8e\xb0\xe3\x80\x81\xe5\x9c\xb0\xe5\x9b\xbe\xe5\x86\x85\xe6\x80\xbb\xe9\x9b\x86\xe7\xbb\xb4\xe6\x8a\xa4\xe5\x92\x8c\xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x86\x85\xe5\xae\xb9\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "WorldSettings/GenericWorldSettingsEdSubsystem.h" },
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettingsEdSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x9c\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe4\xbe\xa7\xe7\xae\xa1\xe7\x90\x86\xe4\xb8\x96\xe7\x95\x8c\xe7\xba\xa7\xe8\xae\xbe\xe7\xbd\xae\xe7\x9a\x84\xe7\xb1\xbb\xe5\x9e\x8b\xe5\x8f\x91\xe7\x8e\xb0\xe3\x80\x81\xe5\x9c\xb0\xe5\x9b\xbe\xe5\x86\x85\xe6\x80\xbb\xe9\x9b\x86\xe7\xbb\xb4\xe6\x8a\xa4\xe5\x92\x8c\xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x86\x85\xe5\xae\xb9\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericWorldSettingsEdSubsystem constinit property declarations *********
// ********** End Class UGenericWorldSettingsEdSubsystem constinit property declarations ***********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericWorldSettingsEdSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericWorldSettingsEdSubsystem_Statics
UObject* (*const Z_Construct_UClass_UGenericWorldSettingsEdSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSettingsEdFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettingsEdSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericWorldSettingsEdSubsystem_Statics::ClassParams = {
	&UGenericWorldSettingsEdSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettingsEdSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericWorldSettingsEdSubsystem_Statics::Class_MetaDataParams)
};
void UGenericWorldSettingsEdSubsystem::StaticRegisterNativesUGenericWorldSettingsEdSubsystem()
{
}
UClass* Z_Construct_UClass_UGenericWorldSettingsEdSubsystem()
{
	if (!Z_Registration_Info_UClass_UGenericWorldSettingsEdSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericWorldSettingsEdSubsystem.OuterSingleton, Z_Construct_UClass_UGenericWorldSettingsEdSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericWorldSettingsEdSubsystem.OuterSingleton;
}
UGenericWorldSettingsEdSubsystem::UGenericWorldSettingsEdSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericWorldSettingsEdSubsystem);
UGenericWorldSettingsEdSubsystem::~UGenericWorldSettingsEdSubsystem() {}
// ********** End Class UGenericWorldSettingsEdSubsystem *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_GenericWorldSettingsEdSubsystem_h__Script_GenericSettingsEdFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericWorldSettingsEdSubsystem, UGenericWorldSettingsEdSubsystem::StaticClass, TEXT("UGenericWorldSettingsEdSubsystem"), &Z_Registration_Info_UClass_UGenericWorldSettingsEdSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericWorldSettingsEdSubsystem), 3844163793U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_GenericWorldSettingsEdSubsystem_h__Script_GenericSettingsEdFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_GenericWorldSettingsEdSubsystem_h__Script_GenericSettingsEdFramework_4009536161{
	TEXT("/Script/GenericSettingsEdFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_GenericWorldSettingsEdSubsystem_h__Script_GenericSettingsEdFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_GenericWorldSettingsEdSubsystem_h__Script_GenericSettingsEdFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
