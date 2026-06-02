// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystem/GenericTickableWorldSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericTickableWorldSubsystem() {}

// ********** Begin Cross Module References ********************************************************
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericTickableWorldSubsystem();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericTickableWorldSubsystem_NoRegister();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSubsystem();
UPackage* Z_Construct_UPackage__Script_GenericCoreFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericTickableWorldSubsystem *******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericTickableWorldSubsystem;
UClass* UGenericTickableWorldSubsystem::GetPrivateStaticClass()
{
	using TClass = UGenericTickableWorldSubsystem;
	if (!Z_Registration_Info_UClass_UGenericTickableWorldSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericTickableWorldSubsystem"),
			Z_Registration_Info_UClass_UGenericTickableWorldSubsystem.InnerSingleton,
			StaticRegisterNativesUGenericTickableWorldSubsystem,
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
	return Z_Registration_Info_UClass_UGenericTickableWorldSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericTickableWorldSubsystem_NoRegister()
{
	return UGenericTickableWorldSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericTickableWorldSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe9\x80\x9a\xe7\x94\xa8\xe5\x8f\xaf Tick \xe4\xb8\x96\xe7\x95\x8c\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x9f\xba\xe7\xb1\xbb\xef\xbc\x8c\xe6\x89\xbf\xe6\x8e\xa5 Unreal \xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\xb9\xb6\xe4\xb8\xba\xe4\xb8\x8a\xe5\xb1\x82\xe6\xa8\xa1\xe5\x9d\x97\xe4\xbf\x9d\xe7\x95\x99\xe6\x89\xa9\xe5\xb1\x95\xe9\x92\xa9\xe5\xad\x90\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Subsystem/GenericTickableWorldSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystem/GenericTickableWorldSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe9\x80\x9a\xe7\x94\xa8\xe5\x8f\xaf Tick \xe4\xb8\x96\xe7\x95\x8c\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x9f\xba\xe7\xb1\xbb\xef\xbc\x8c\xe6\x89\xbf\xe6\x8e\xa5 Unreal \xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\xb9\xb6\xe4\xb8\xba\xe4\xb8\x8a\xe5\xb1\x82\xe6\xa8\xa1\xe5\x9d\x97\xe4\xbf\x9d\xe7\x95\x99\xe6\x89\xa9\xe5\xb1\x95\xe9\x92\xa9\xe5\xad\x90\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericTickableWorldSubsystem constinit property declarations ***********
// ********** End Class UGenericTickableWorldSubsystem constinit property declarations *************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericTickableWorldSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericTickableWorldSubsystem_Statics
UObject* (*const Z_Construct_UClass_UGenericTickableWorldSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGenericWorldSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericCoreFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericTickableWorldSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericTickableWorldSubsystem_Statics::ClassParams = {
	&UGenericTickableWorldSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericTickableWorldSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericTickableWorldSubsystem_Statics::Class_MetaDataParams)
};
void UGenericTickableWorldSubsystem::StaticRegisterNativesUGenericTickableWorldSubsystem()
{
}
UClass* Z_Construct_UClass_UGenericTickableWorldSubsystem()
{
	if (!Z_Registration_Info_UClass_UGenericTickableWorldSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericTickableWorldSubsystem.OuterSingleton, Z_Construct_UClass_UGenericTickableWorldSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericTickableWorldSubsystem.OuterSingleton;
}
UGenericTickableWorldSubsystem::UGenericTickableWorldSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericTickableWorldSubsystem);
UGenericTickableWorldSubsystem::~UGenericTickableWorldSubsystem() {}
// ********** End Class UGenericTickableWorldSubsystem *********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericTickableWorldSubsystem_h__Script_GenericCoreFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericTickableWorldSubsystem, UGenericTickableWorldSubsystem::StaticClass, TEXT("UGenericTickableWorldSubsystem"), &Z_Registration_Info_UClass_UGenericTickableWorldSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericTickableWorldSubsystem), 3981493209U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericTickableWorldSubsystem_h__Script_GenericCoreFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericTickableWorldSubsystem_h__Script_GenericCoreFramework_4268319698{
	TEXT("/Script/GenericCoreFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericTickableWorldSubsystem_h__Script_GenericCoreFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericTickableWorldSubsystem_h__Script_GenericCoreFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
