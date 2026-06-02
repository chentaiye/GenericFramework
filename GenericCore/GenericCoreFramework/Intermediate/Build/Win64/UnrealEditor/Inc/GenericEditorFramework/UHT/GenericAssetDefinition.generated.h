// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Asset/GenericAssetDefinition.h"

#ifdef GENERICEDITORFRAMEWORK_GenericAssetDefinition_generated_h
#error "GenericAssetDefinition.generated.h already included, missing '#pragma once' in GenericAssetDefinition.h"
#endif
#define GENERICEDITORFRAMEWORK_GenericAssetDefinition_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericAssetDefinition **************************************************
struct Z_Construct_UClass_UGenericAssetDefinition_Statics;
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericAssetDefinition_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericAssetDefinition(); \
	friend struct ::Z_Construct_UClass_UGenericAssetDefinition_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICEDITORFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericAssetDefinition_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericAssetDefinition, UAssetDefinitionDefault, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GenericEditorFramework"), Z_Construct_UClass_UGenericAssetDefinition_NoRegister) \
	DECLARE_SERIALIZER(UGenericAssetDefinition)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericAssetDefinition(UGenericAssetDefinition&&) = delete; \
	UGenericAssetDefinition(const UGenericAssetDefinition&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICEDITORFRAMEWORK_API, UGenericAssetDefinition); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericAssetDefinition); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericAssetDefinition) \
	GENERICEDITORFRAMEWORK_API virtual ~UGenericAssetDefinition();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericAssetDefinition;

// ********** End Class UGenericAssetDefinition ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Asset_GenericAssetDefinition_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
