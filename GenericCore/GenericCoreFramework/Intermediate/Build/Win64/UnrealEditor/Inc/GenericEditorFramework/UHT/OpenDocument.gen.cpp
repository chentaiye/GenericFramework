// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tools/OpenDocument.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeOpenDocument() {}

// ********** Begin Cross Module References ********************************************************
EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UOpenDocument();
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UOpenDocument_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericEditorFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UOpenDocument ************************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UOpenDocument;
UClass* UOpenDocument::GetPrivateStaticClass()
{
	using TClass = UOpenDocument;
	if (!Z_Registration_Info_UClass_UOpenDocument.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("OpenDocument"),
			Z_Registration_Info_UClass_UOpenDocument.InnerSingleton,
			StaticRegisterNativesUOpenDocument,
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
	return Z_Registration_Info_UClass_UOpenDocument.InnerSingleton;
}
UClass* Z_Construct_UClass_UOpenDocument_NoRegister()
{
	return UOpenDocument::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UOpenDocument_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89\xe6\x89\x93\xe5\xbc\x80\xe6\x96\x87\xe6\xa1\xa3\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe4\xbd\x9c\xe4\xb8\xba \xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe6\x89\xa9\xe5\xb1\x95 \xe6\xa8\xa1\xe5\x9d\x97\xe5\x86\x85\xe5\xa4\x8d\xe7\x94\xa8\xe7\x9a\x84\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "Tools/OpenDocument.h" },
		{ "ModuleRelativePath", "Public/Tools/OpenDocument.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89\xe6\x89\x93\xe5\xbc\x80\xe6\x96\x87\xe6\xa1\xa3\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe4\xbd\x9c\xe4\xb8\xba \xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe6\x89\xa9\xe5\xb1\x95 \xe6\xa8\xa1\xe5\x9d\x97\xe5\x86\x85\xe5\xa4\x8d\xe7\x94\xa8\xe7\x9a\x84\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UOpenDocument constinit property declarations ****************************
// ********** End Class UOpenDocument constinit property declarations ******************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOpenDocument>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UOpenDocument_Statics
UObject* (*const Z_Construct_UClass_UOpenDocument_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericEditorFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UOpenDocument_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UOpenDocument_Statics::ClassParams = {
	&UOpenDocument::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UOpenDocument_Statics::Class_MetaDataParams), Z_Construct_UClass_UOpenDocument_Statics::Class_MetaDataParams)
};
void UOpenDocument::StaticRegisterNativesUOpenDocument()
{
}
UClass* Z_Construct_UClass_UOpenDocument()
{
	if (!Z_Registration_Info_UClass_UOpenDocument.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UOpenDocument.OuterSingleton, Z_Construct_UClass_UOpenDocument_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UOpenDocument.OuterSingleton;
}
UOpenDocument::UOpenDocument() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UOpenDocument);
UOpenDocument::~UOpenDocument() {}
// ********** End Class UOpenDocument **************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h__Script_GenericEditorFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UOpenDocument, UOpenDocument::StaticClass, TEXT("UOpenDocument"), &Z_Registration_Info_UClass_UOpenDocument, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UOpenDocument), 886483181U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h__Script_GenericEditorFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h__Script_GenericEditorFramework_1620541758{
	TEXT("/Script/GenericEditorFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h__Script_GenericEditorFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h__Script_GenericEditorFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
