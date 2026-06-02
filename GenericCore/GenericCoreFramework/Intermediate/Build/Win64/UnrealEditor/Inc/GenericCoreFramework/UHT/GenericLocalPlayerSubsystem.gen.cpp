// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Subsystem/GenericLocalPlayerSubsystem.h"
#include "Engine/LocalPlayer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericLocalPlayerSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_ULocalPlayerSubsystem();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericLocalPlayerSubsystem();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericLocalPlayerSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericCoreFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericLocalPlayerSubsystem *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericLocalPlayerSubsystem;
UClass* UGenericLocalPlayerSubsystem::GetPrivateStaticClass()
{
	using TClass = UGenericLocalPlayerSubsystem;
	if (!Z_Registration_Info_UClass_UGenericLocalPlayerSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericLocalPlayerSubsystem"),
			Z_Registration_Info_UClass_UGenericLocalPlayerSubsystem.InnerSingleton,
			StaticRegisterNativesUGenericLocalPlayerSubsystem,
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
	return Z_Registration_Info_UClass_UGenericLocalPlayerSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericLocalPlayerSubsystem_NoRegister()
{
	return UGenericLocalPlayerSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe9\x80\x9a\xe7\x94\xa8\xe6\x9c\xac\xe5\x9c\xb0\xe7\x8e\xa9\xe5\xae\xb6\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x9f\xba\xe7\xb1\xbb\xef\xbc\x8c\xe6\x89\xbf\xe6\x8e\xa5 Unreal \xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\xb9\xb6\xe4\xb8\xba\xe4\xb8\x8a\xe5\xb1\x82\xe6\xa8\xa1\xe5\x9d\x97\xe4\xbf\x9d\xe7\x95\x99\xe6\x89\xa9\xe5\xb1\x95\xe9\x92\xa9\xe5\xad\x90\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Subsystem/GenericLocalPlayerSubsystem.h" },
		{ "ModuleRelativePath", "Public/Subsystem/GenericLocalPlayerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe9\x80\x9a\xe7\x94\xa8\xe6\x9c\xac\xe5\x9c\xb0\xe7\x8e\xa9\xe5\xae\xb6\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe5\x9f\xba\xe7\xb1\xbb\xef\xbc\x8c\xe6\x89\xbf\xe6\x8e\xa5 Unreal \xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\xb9\xb6\xe4\xb8\xba\xe4\xb8\x8a\xe5\xb1\x82\xe6\xa8\xa1\xe5\x9d\x97\xe4\xbf\x9d\xe7\x95\x99\xe6\x89\xa9\xe5\xb1\x95\xe9\x92\xa9\xe5\xad\x90\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Player_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Subsystem/GenericLocalPlayerSubsystem.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x8e\xa9\xe5\xae\xb6\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbe\x9b\xe5\xbd\x93\xe5\x89\x8d\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x90\x8e\xe7\xbb\xad\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe5\x92\x8c\xe5\x90\x8c\xe6\xad\xa5\xe9\x80\xbb\xe8\xbe\x91\xe8\xaf\xbb\xe5\x8f\x96\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericLocalPlayerSubsystem constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Player;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UGenericLocalPlayerSubsystem constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericLocalPlayerSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics

// ********** Begin Class UGenericLocalPlayerSubsystem Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0144000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGenericLocalPlayerSubsystem, Player), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Player_MetaData), NewProp_Player_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::NewProp_Player,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::PropPointers) < 2048);
// ********** End Class UGenericLocalPlayerSubsystem Property Definitions **************************
UObject* (*const Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ULocalPlayerSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericCoreFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::ClassParams = {
	&UGenericLocalPlayerSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::PropPointers),
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::Class_MetaDataParams)
};
void UGenericLocalPlayerSubsystem::StaticRegisterNativesUGenericLocalPlayerSubsystem()
{
}
UClass* Z_Construct_UClass_UGenericLocalPlayerSubsystem()
{
	if (!Z_Registration_Info_UClass_UGenericLocalPlayerSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericLocalPlayerSubsystem.OuterSingleton, Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericLocalPlayerSubsystem.OuterSingleton;
}
UGenericLocalPlayerSubsystem::UGenericLocalPlayerSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericLocalPlayerSubsystem);
UGenericLocalPlayerSubsystem::~UGenericLocalPlayerSubsystem() {}
// ********** End Class UGenericLocalPlayerSubsystem ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h__Script_GenericCoreFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericLocalPlayerSubsystem, UGenericLocalPlayerSubsystem::StaticClass, TEXT("UGenericLocalPlayerSubsystem"), &Z_Registration_Info_UClass_UGenericLocalPlayerSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericLocalPlayerSubsystem), 3624733552U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h__Script_GenericCoreFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h__Script_GenericCoreFramework_1677751911{
	TEXT("/Script/GenericCoreFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h__Script_GenericCoreFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h__Script_GenericCoreFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
