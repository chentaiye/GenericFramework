// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystem/GenericFrameworkEdSubsystem.h"

#ifdef GENERICEDITORFRAMEWORK_GenericFrameworkEdSubsystem_generated_h
#error "GenericFrameworkEdSubsystem.generated.h already included, missing '#pragma once' in GenericFrameworkEdSubsystem.h"
#endif
#define GENERICEDITORFRAMEWORK_GenericFrameworkEdSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericFrameworkEdSubsystem *********************************************
struct Z_Construct_UClass_UGenericFrameworkEdSubsystem_Statics;
GENERICEDITORFRAMEWORK_API UClass* Z_Construct_UClass_UGenericFrameworkEdSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericFrameworkEdSubsystem_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericFrameworkEdSubsystem(); \
	friend struct ::Z_Construct_UClass_UGenericFrameworkEdSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICEDITORFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericFrameworkEdSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericFrameworkEdSubsystem, UEditorSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericEditorFramework"), Z_Construct_UClass_UGenericFrameworkEdSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGenericFrameworkEdSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericFrameworkEdSubsystem_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICEDITORFRAMEWORK_API UGenericFrameworkEdSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericFrameworkEdSubsystem(UGenericFrameworkEdSubsystem&&) = delete; \
	UGenericFrameworkEdSubsystem(const UGenericFrameworkEdSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICEDITORFRAMEWORK_API, UGenericFrameworkEdSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericFrameworkEdSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenericFrameworkEdSubsystem) \
	GENERICEDITORFRAMEWORK_API virtual ~UGenericFrameworkEdSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericFrameworkEdSubsystem_h_17_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericFrameworkEdSubsystem_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericFrameworkEdSubsystem_h_20_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericFrameworkEdSubsystem_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericFrameworkEdSubsystem;

// ********** End Class UGenericFrameworkEdSubsystem ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericEditorFramework_Public_Subsystem_GenericFrameworkEdSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
