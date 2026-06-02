// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystem/GenericBlueprintEditorSubsystem.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericBlueprintEditorSubsystem() {}

// ********** Begin Cross Module References ********************************************************
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericBlueprintEditorSubsystem();
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericBlueprintEditorSubsystem_NoRegister();
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericEditorSubsystem();
UPackage* Z_Construct_UPackage__Script_GenericEditorFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericBlueprintEditorSubsystem *****************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericBlueprintEditorSubsystem;
UClass* UGenericBlueprintEditorSubsystem::GetPrivateStaticClass()
{
	using TClass = UGenericBlueprintEditorSubsystem;
	if (!Z_Registration_Info_UClass_UGenericBlueprintEditorSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericBlueprintEditorSubsystem"),
			Z_Registration_Info_UClass_UGenericBlueprintEditorSubsystem.InnerSingleton,
			StaticRegisterNativesUGenericBlueprintEditorSubsystem,
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
	return Z_Registration_Info_UClass_UGenericBlueprintEditorSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericBlueprintEditorSubsystem_NoRegister()
{
	return UGenericBlueprintEditorSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericBlueprintEditorSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe9\x80\x9a\xe7\x94\xa8\xe8\x93\x9d\xe5\x9b\xbe\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x9f\xba\xe7\xb1\xbb\xef\xbc\x8c\xe6\x89\xbf\xe6\x8e\xa5 Unreal \xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\xb9\xb6\xe4\xb8\xba\xe4\xb8\x8a\xe5\xb1\x82\xe6\xa8\xa1\xe5\x9d\x97\xe4\xbf\x9d\xe7\x95\x99\xe6\x89\xa9\xe5\xb1\x95\xe9\x92\xa9\xe5\xad\x90\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Subsystem/GenericBlueprintEditorSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystem/GenericBlueprintEditorSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe9\x80\x9a\xe7\x94\xa8\xe8\x93\x9d\xe5\x9b\xbe\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x9f\xba\xe7\xb1\xbb\xef\xbc\x8c\xe6\x89\xbf\xe6\x8e\xa5 Unreal \xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\xb9\xb6\xe4\xb8\xba\xe4\xb8\x8a\xe5\xb1\x82\xe6\xa8\xa1\xe5\x9d\x97\xe4\xbf\x9d\xe7\x95\x99\xe6\x89\xa9\xe5\xb1\x95\xe9\x92\xa9\xe5\xad\x90\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericBlueprintEditorSubsystem constinit property declarations *********
// ********** End Class UGenericBlueprintEditorSubsystem constinit property declarations ***********
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericBlueprintEditorSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericBlueprintEditorSubsystem_Statics
UObject* (*const Z_Construct_UClass_UGenericBlueprintEditorSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGenericEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericEditorFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericBlueprintEditorSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericBlueprintEditorSubsystem_Statics::ClassParams = {
	&UGenericBlueprintEditorSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericBlueprintEditorSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericBlueprintEditorSubsystem_Statics::Class_MetaDataParams)
};
void UGenericBlueprintEditorSubsystem::StaticRegisterNativesUGenericBlueprintEditorSubsystem()
{
}
UClass* Z_Construct_UClass_UGenericBlueprintEditorSubsystem()
{
	if (!Z_Registration_Info_UClass_UGenericBlueprintEditorSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericBlueprintEditorSubsystem.OuterSingleton, Z_Construct_UClass_UGenericBlueprintEditorSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericBlueprintEditorSubsystem.OuterSingleton;
}
UGenericBlueprintEditorSubsystem::UGenericBlueprintEditorSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericBlueprintEditorSubsystem);
UGenericBlueprintEditorSubsystem::~UGenericBlueprintEditorSubsystem() {}
// ********** End Class UGenericBlueprintEditorSubsystem *******************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericBlueprintEditorSubsystem_h__Script_GenericEditorFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericBlueprintEditorSubsystem, UGenericBlueprintEditorSubsystem::StaticClass, TEXT("UGenericBlueprintEditorSubsystem"), &Z_Registration_Info_UClass_UGenericBlueprintEditorSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericBlueprintEditorSubsystem), 1227548739U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericBlueprintEditorSubsystem_h__Script_GenericEditorFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericBlueprintEditorSubsystem_h__Script_GenericEditorFramework_1650920900{
	TEXT("/Script/GenericEditorFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericBlueprintEditorSubsystem_h__Script_GenericEditorFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericBlueprintEditorSubsystem_h__Script_GenericEditorFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
