// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystem/GenericEditorSubsystem.h"

#ifdef GENERICEDITORFRAMEWORK_GenericEditorSubsystem_generated_h
#error "GenericEditorSubsystem.generated.h already included, missing '#pragma once' in GenericEditorSubsystem.h"
#endif
#define GENERICEDITORFRAMEWORK_GenericEditorSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericEditorSubsystem **************************************************
struct Z_Construct_UClass_UGenericEditorSubsystem_Statics;
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericEditorSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericEditorSubsystem_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericEditorSubsystem(); \
	friend struct ::Z_Construct_UClass_UGenericEditorSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICEDITORFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericEditorSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericEditorSubsystem, UEditorSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericEditorFramework"), Z_Construct_UClass_UGenericEditorSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGenericEditorSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericEditorSubsystem_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICEDITORFRAMEWORK_API UGenericEditorSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericEditorSubsystem(UGenericEditorSubsystem&&) = delete; \
	UGenericEditorSubsystem(const UGenericEditorSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICEDITORFRAMEWORK_API, UGenericEditorSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericEditorSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenericEditorSubsystem) \
	GENERICEDITORFRAMEWORK_API virtual ~UGenericEditorSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericEditorSubsystem_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericEditorSubsystem_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericEditorSubsystem_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericEditorSubsystem_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericEditorSubsystem;

// ********** End Class UGenericEditorSubsystem ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericEditorSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
