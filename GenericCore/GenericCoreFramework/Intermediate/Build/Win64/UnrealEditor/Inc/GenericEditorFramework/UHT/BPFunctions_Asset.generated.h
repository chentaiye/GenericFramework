// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPFunctions/BPFunctions_Asset.h"

#ifdef GENERICEDITORFRAMEWORK_BPFunctions_Asset_generated_h
#error "BPFunctions_Asset.generated.h already included, missing '#pragma once' in BPFunctions_Asset.h"
#endif
#define GENERICEDITORFRAMEWORK_BPFunctions_Asset_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UBPFunctions_Asset *******************************************************
struct Z_Construct_UClass_UBPFunctions_Asset_Statics;
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UBPFunctions_Asset_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_Asset_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPFunctions_Asset(); \
	friend struct ::Z_Construct_UClass_UBPFunctions_Asset_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICEDITORFRAMEWORK_API UClass* ::Z_Construct_UClass_UBPFunctions_Asset_NoRegister(); \
public: \
	DECLARE_CLASS2(UBPFunctions_Asset, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericEditorFramework"), Z_Construct_UClass_UBPFunctions_Asset_NoRegister) \
	DECLARE_SERIALIZER(UBPFunctions_Asset)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_Asset_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICEDITORFRAMEWORK_API UBPFunctions_Asset(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBPFunctions_Asset(UBPFunctions_Asset&&) = delete; \
	UBPFunctions_Asset(const UBPFunctions_Asset&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICEDITORFRAMEWORK_API, UBPFunctions_Asset); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPFunctions_Asset); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBPFunctions_Asset) \
	GENERICEDITORFRAMEWORK_API virtual ~UBPFunctions_Asset();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_Asset_h_11_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_Asset_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_Asset_h_14_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_Asset_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBPFunctions_Asset;

// ********** End Class UBPFunctions_Asset *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_BPFunctions_BPFunctions_Asset_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
