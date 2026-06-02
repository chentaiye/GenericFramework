// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Asset/GenericAssetDefinition.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericAssetDefinition() {}

// ********** Begin Cross Module References ********************************************************
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericAssetDefinition();
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericAssetDefinition_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UAssetDefinitionDefault();
UPackage* Z_Construct_UPackage__Script_GenericEditorFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericAssetDefinition **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericAssetDefinition;
UClass* UGenericAssetDefinition::GetPrivateStaticClass()
{
	using TClass = UGenericAssetDefinition;
	if (!Z_Registration_Info_UClass_UGenericAssetDefinition.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericAssetDefinition"),
			Z_Registration_Info_UClass_UGenericAssetDefinition.InnerSingleton,
			StaticRegisterNativesUGenericAssetDefinition,
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
	return Z_Registration_Info_UClass_UGenericAssetDefinition.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericAssetDefinition_NoRegister()
{
	return UGenericAssetDefinition::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericAssetDefinition_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x8f\xe8\xbf\xb0\xe9\x80\x9a\xe7\x94\xa8\xe8\xb5\x84\xe4\xba\xa7\xe5\xae\x9a\xe4\xb9\x89\xe5\x9c\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe8\xb5\x84\xe4\xba\xa7\xe7\xb3\xbb\xe7\xbb\x9f\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x9b\xe5\xbb\xba\xe3\x80\x81\xe5\x88\x86\xe7\xb1\xbb\xe5\x92\x8c\xe5\xb1\x95\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Asset/GenericAssetDefinition.h" },
		{ "ModuleRelativePath", "Public/Asset/GenericAssetDefinition.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x8f\xe8\xbf\xb0\xe9\x80\x9a\xe7\x94\xa8\xe8\xb5\x84\xe4\xba\xa7\xe5\xae\x9a\xe4\xb9\x89\xe5\x9c\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe8\xb5\x84\xe4\xba\xa7\xe7\xb3\xbb\xe7\xbb\x9f\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x9b\xe5\xbb\xba\xe3\x80\x81\xe5\x88\x86\xe7\xb1\xbb\xe5\x92\x8c\xe5\xb1\x95\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericAssetDefinition constinit property declarations ******************
// ********** End Class UGenericAssetDefinition constinit property declarations ********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericAssetDefinition>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericAssetDefinition_Statics
UObject* (*const Z_Construct_UClass_UGenericAssetDefinition_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetDefinitionDefault,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericEditorFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericAssetDefinition_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericAssetDefinition_Statics::ClassParams = {
	&UGenericAssetDefinition::StaticClass,
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
	0x000800A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericAssetDefinition_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericAssetDefinition_Statics::Class_MetaDataParams)
};
void UGenericAssetDefinition::StaticRegisterNativesUGenericAssetDefinition()
{
}
UClass* Z_Construct_UClass_UGenericAssetDefinition()
{
	if (!Z_Registration_Info_UClass_UGenericAssetDefinition.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericAssetDefinition.OuterSingleton, Z_Construct_UClass_UGenericAssetDefinition_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericAssetDefinition.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericAssetDefinition);
UGenericAssetDefinition::~UGenericAssetDefinition() {}
// ********** End Class UGenericAssetDefinition ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h__Script_GenericEditorFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericAssetDefinition, UGenericAssetDefinition::StaticClass, TEXT("UGenericAssetDefinition"), &Z_Registration_Info_UClass_UGenericAssetDefinition, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericAssetDefinition), 203330858U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h__Script_GenericEditorFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h__Script_GenericEditorFramework_2025553354{
	TEXT("/Script/GenericEditorFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h__Script_GenericEditorFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h__Script_GenericEditorFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
