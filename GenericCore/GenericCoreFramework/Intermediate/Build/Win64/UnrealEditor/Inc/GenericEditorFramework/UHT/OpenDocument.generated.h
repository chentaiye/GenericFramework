// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Tools/OpenDocument.h"

#ifdef GENERICEDITORFRAMEWORK_OpenDocument_generated_h
#error "OpenDocument.generated.h already included, missing '#pragma once' in OpenDocument.h"
#endif
#define GENERICEDITORFRAMEWORK_OpenDocument_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UOpenDocument ************************************************************
struct Z_Construct_UClass_UOpenDocument_Statics;
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UOpenDocument_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOpenDocument(); \
	friend struct ::Z_Construct_UClass_UOpenDocument_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICEDITORFRAMEWORK_API UClass* ::Z_Construct_UClass_UOpenDocument_NoRegister(); \
public: \
	DECLARE_CLASS2(UOpenDocument, UEditorSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericEditorFramework"), Z_Construct_UClass_UOpenDocument_NoRegister) \
	DECLARE_SERIALIZER(UOpenDocument)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICEDITORFRAMEWORK_API UOpenDocument(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UOpenDocument(UOpenDocument&&) = delete; \
	UOpenDocument(const UOpenDocument&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICEDITORFRAMEWORK_API, UOpenDocument); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOpenDocument); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOpenDocument) \
	GENERICEDITORFRAMEWORK_API virtual ~UOpenDocument();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h_15_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h_18_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UOpenDocument;

// ********** End Class UOpenDocument **************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Tools_OpenDocument_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
