// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Asset/GenericAssetFactory.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericAssetFactory() {}

// ********** Begin Cross Module References ********************************************************
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericAssetFactory();
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericAssetFactory_NoRegister();
UNREALED_API UClass* Z_Construct_UClass_UFactory();
UPackage* Z_Construct_UPackage__Script_GenericEditorFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericAssetFactory *****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericAssetFactory;
UClass* UGenericAssetFactory::GetPrivateStaticClass()
{
	using TClass = UGenericAssetFactory;
	if (!Z_Registration_Info_UClass_UGenericAssetFactory.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericAssetFactory"),
			Z_Registration_Info_UClass_UGenericAssetFactory.InnerSingleton,
			StaticRegisterNativesUGenericAssetFactory,
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
	return Z_Registration_Info_UClass_UGenericAssetFactory.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericAssetFactory_NoRegister()
{
	return UGenericAssetFactory::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericAssetFactory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8f\x8f\xe8\xbf\xb0\xe9\x80\x9a\xe7\x94\xa8\xe8\xb5\x84\xe4\xba\xa7\xe5\xb7\xa5\xe5\x8e\x82\xe5\x9c\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe8\xb5\x84\xe4\xba\xa7\xe7\xb3\xbb\xe7\xbb\x9f\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x9b\xe5\xbb\xba\xe3\x80\x81\xe5\x88\x86\xe7\xb1\xbb\xe5\x92\x8c\xe5\xb1\x95\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Asset/GenericAssetFactory.h" },
		{ "ModuleRelativePath", "Public/Asset/GenericAssetFactory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8f\x8f\xe8\xbf\xb0\xe9\x80\x9a\xe7\x94\xa8\xe8\xb5\x84\xe4\xba\xa7\xe5\xb7\xa5\xe5\x8e\x82\xe5\x9c\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe8\xb5\x84\xe4\xba\xa7\xe7\xb3\xbb\xe7\xbb\x9f\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x9b\xe5\xbb\xba\xe3\x80\x81\xe5\x88\x86\xe7\xb1\xbb\xe5\x92\x8c\xe5\xb1\x95\xe7\xa4\xba\xe4\xbf\xa1\xe6\x81\xaf\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericAssetFactory constinit property declarations *********************
// ********** End Class UGenericAssetFactory constinit property declarations ***********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericAssetFactory>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericAssetFactory_Statics
UObject* (*const Z_Construct_UClass_UGenericAssetFactory_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UFactory,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericEditorFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericAssetFactory_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericAssetFactory_Statics::ClassParams = {
	&UGenericAssetFactory::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericAssetFactory_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericAssetFactory_Statics::Class_MetaDataParams)
};
void UGenericAssetFactory::StaticRegisterNativesUGenericAssetFactory()
{
}
UClass* Z_Construct_UClass_UGenericAssetFactory()
{
	if (!Z_Registration_Info_UClass_UGenericAssetFactory.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericAssetFactory.OuterSingleton, Z_Construct_UClass_UGenericAssetFactory_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericAssetFactory.OuterSingleton;
}
UGenericAssetFactory::UGenericAssetFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericAssetFactory);
UGenericAssetFactory::~UGenericAssetFactory() {}
// ********** End Class UGenericAssetFactory *******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h__Script_GenericEditorFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericAssetFactory, UGenericAssetFactory::StaticClass, TEXT("UGenericAssetFactory"), &Z_Registration_Info_UClass_UGenericAssetFactory, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericAssetFactory), 4290244909U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h__Script_GenericEditorFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h__Script_GenericEditorFramework_2649773089{
	TEXT("/Script/GenericEditorFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h__Script_GenericEditorFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h__Script_GenericEditorFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
