// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPFunctions/BPFunctions_EditorScene.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBPFunctions_EditorScene() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_EditorScene();
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_EditorScene_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericEditorFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UBPFunctions_EditorScene *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBPFunctions_EditorScene;
UClass* UBPFunctions_EditorScene::GetPrivateStaticClass()
{
	using TClass = UBPFunctions_EditorScene;
	if (!Z_Registration_Info_UClass_UBPFunctions_EditorScene.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BPFunctions_EditorScene"),
			Z_Registration_Info_UClass_UBPFunctions_EditorScene.InnerSingleton,
			StaticRegisterNativesUBPFunctions_EditorScene,
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
	return Z_Registration_Info_UClass_UBPFunctions_EditorScene.InnerSingleton;
}
UClass* Z_Construct_UClass_UBPFunctions_EditorScene_NoRegister()
{
	return UBPFunctions_EditorScene::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBPFunctions_EditorScene_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x9c\xba\xe6\x99\xaf\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xae\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe6\x89\xa9\xe5\xb1\x95\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "BPFunctions/BPFunctions_EditorScene.h" },
		{ "ModuleRelativePath", "Public/BPFunctions/BPFunctions_EditorScene.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe9\x9b\x86\xe4\xb8\xad\xe6\x9a\xb4\xe9\x9c\xb2\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x9c\xba\xe6\x99\xaf\xe8\x93\x9d\xe5\x9b\xbe\xe5\x87\xbd\xe6\x95\xb0\xe5\xba\x93\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe8\xae\xa9\xe8\x93\x9d\xe5\x9b\xbe\xe9\x80\x9a\xe8\xbf\x87\xe7\xa8\xb3\xe5\xae\x9a\xe5\x85\xa5\xe5\x8f\xa3\xe8\xae\xbf\xe9\x97\xae\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe6\x89\xa9\xe5\xb1\x95\xe5\x8a\x9f\xe8\x83\xbd\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBPFunctions_EditorScene constinit property declarations *****************
// ********** End Class UBPFunctions_EditorScene constinit property declarations *******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBPFunctions_EditorScene>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBPFunctions_EditorScene_Statics
UObject* (*const Z_Construct_UClass_UBPFunctions_EditorScene_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericEditorFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_EditorScene_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBPFunctions_EditorScene_Statics::ClassParams = {
	&UBPFunctions_EditorScene::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBPFunctions_EditorScene_Statics::Class_MetaDataParams), Z_Construct_UClass_UBPFunctions_EditorScene_Statics::Class_MetaDataParams)
};
void UBPFunctions_EditorScene::StaticRegisterNativesUBPFunctions_EditorScene()
{
}
UClass* Z_Construct_UClass_UBPFunctions_EditorScene()
{
	if (!Z_Registration_Info_UClass_UBPFunctions_EditorScene.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBPFunctions_EditorScene.OuterSingleton, Z_Construct_UClass_UBPFunctions_EditorScene_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBPFunctions_EditorScene.OuterSingleton;
}
UBPFunctions_EditorScene::UBPFunctions_EditorScene(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBPFunctions_EditorScene);
UBPFunctions_EditorScene::~UBPFunctions_EditorScene() {}
// ********** End Class UBPFunctions_EditorScene ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_EditorScene_h__Script_GenericEditorFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBPFunctions_EditorScene, UBPFunctions_EditorScene::StaticClass, TEXT("UBPFunctions_EditorScene"), &Z_Registration_Info_UClass_UBPFunctions_EditorScene, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBPFunctions_EditorScene), 1302443724U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_EditorScene_h__Script_GenericEditorFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_EditorScene_h__Script_GenericEditorFramework_2911170039{
	TEXT("/Script/GenericEditorFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_EditorScene_h__Script_GenericEditorFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_EditorScene_h__Script_GenericEditorFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
