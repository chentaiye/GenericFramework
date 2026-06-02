// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Obect/GenericObject.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericObject() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericObject();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericObject_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericCoreFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericObject ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericObject;
UClass* UGenericObject::GetPrivateStaticClass()
{
	using TClass = UGenericObject;
	if (!Z_Registration_Info_UClass_UGenericObject.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericObject"),
			Z_Registration_Info_UClass_UGenericObject.InnerSingleton,
			StaticRegisterNativesUGenericObject,
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
	return Z_Registration_Info_UClass_UGenericObject.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericObject_NoRegister()
{
	return UGenericObject::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericObject_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe9\x80\x9a\xe7\x94\xa8 UObject\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe4\xbd\x9c\xe4\xb8\xba \xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xa0\xb8\xe5\xbf\x83 \xe6\xa8\xa1\xe5\x9d\x97\xe5\x86\x85\xe5\xa4\x8d\xe7\x94\xa8\xe7\x9a\x84\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Obect/GenericObject.h" },
		{ "ModuleRelativePath", "Public/Obect/GenericObject.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe9\x80\x9a\xe7\x94\xa8 UObject\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe4\xbd\x9c\xe4\xb8\xba \xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe6\xa0\xb8\xe5\xbf\x83 \xe6\xa8\xa1\xe5\x9d\x97\xe5\x86\x85\xe5\xa4\x8d\xe7\x94\xa8\xe7\x9a\x84\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericObject constinit property declarations ***************************
// ********** End Class UGenericObject constinit property declarations *****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericObject>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericObject_Statics
UObject* (*const Z_Construct_UClass_UGenericObject_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericCoreFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericObject_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericObject_Statics::ClassParams = {
	&UGenericObject::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericObject_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericObject_Statics::Class_MetaDataParams)
};
void UGenericObject::StaticRegisterNativesUGenericObject()
{
}
UClass* Z_Construct_UClass_UGenericObject()
{
	if (!Z_Registration_Info_UClass_UGenericObject.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericObject.OuterSingleton, Z_Construct_UClass_UGenericObject_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericObject.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericObject);
UGenericObject::~UGenericObject() {}
// ********** End Class UGenericObject *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h__Script_GenericCoreFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericObject, UGenericObject::StaticClass, TEXT("UGenericObject"), &Z_Registration_Info_UClass_UGenericObject, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericObject), 4278701301U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h__Script_GenericCoreFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h__Script_GenericCoreFramework_4294730110{
	TEXT("/Script/GenericCoreFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h__Script_GenericCoreFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Obect_GenericObject_h__Script_GenericCoreFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
