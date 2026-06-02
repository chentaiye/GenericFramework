// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystem/GenericVersionMigrationSubsystem.h"

#ifdef GENERICVERSIONFRAMEWORK_GenericVersionMigrationSubsystem_generated_h
#error "GenericVersionMigrationSubsystem.generated.h already included, missing '#pragma once' in GenericVersionMigrationSubsystem.h"
#endif
#define GENERICVERSIONFRAMEWORK_GenericVersionMigrationSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGenericVersionInfo;
struct FGenericVersionMigrationResult;

// ********** Begin Class UGenericVersionMigrationSubsystem ****************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execMakeMigrationFailed); \
	DECLARE_FUNCTION(execMakeMigrationSuccess);


struct Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics;
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionMigrationSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericVersionMigrationSubsystem(); \
	friend struct ::Z_Construct_UClass_UGenericVersionMigrationSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICVERSIONFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericVersionMigrationSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericVersionMigrationSubsystem, UGenericGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericVersionFramework"), Z_Construct_UClass_UGenericVersionMigrationSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGenericVersionMigrationSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICVERSIONFRAMEWORK_API UGenericVersionMigrationSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericVersionMigrationSubsystem(UGenericVersionMigrationSubsystem&&) = delete; \
	UGenericVersionMigrationSubsystem(const UGenericVersionMigrationSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICVERSIONFRAMEWORK_API, UGenericVersionMigrationSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericVersionMigrationSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenericVersionMigrationSubsystem) \
	GENERICVERSIONFRAMEWORK_API virtual ~UGenericVersionMigrationSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h_14_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h_17_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericVersionMigrationSubsystem;

// ********** End Class UGenericVersionMigrationSubsystem ******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionMigrationSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
