// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Asset/GenericAssetFactory.h"

#ifdef GENERICEDITORFRAMEWORK_GenericAssetFactory_generated_h
#error "GenericAssetFactory.generated.h already included, missing '#pragma once' in GenericAssetFactory.h"
#endif
#define GENERICEDITORFRAMEWORK_GenericAssetFactory_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericAssetFactory *****************************************************
struct Z_Construct_UClass_UGenericAssetFactory_Statics;
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericAssetFactory_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericAssetFactory(); \
	friend struct ::Z_Construct_UClass_UGenericAssetFactory_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICEDITORFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericAssetFactory_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericAssetFactory, UFactory, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GenericEditorFramework"), Z_Construct_UClass_UGenericAssetFactory_NoRegister) \
	DECLARE_SERIALIZER(UGenericAssetFactory)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICEDITORFRAMEWORK_API UGenericAssetFactory(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericAssetFactory(UGenericAssetFactory&&) = delete; \
	UGenericAssetFactory(const UGenericAssetFactory&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICEDITORFRAMEWORK_API, UGenericAssetFactory); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericAssetFactory); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericAssetFactory) \
	GENERICEDITORFRAMEWORK_API virtual ~UGenericAssetFactory();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericAssetFactory;

// ********** End Class UGenericAssetFactory *******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetFactory_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
