// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystem/GenericVersionValidationSubsystem.h"

#ifdef GENERICVERSIONFRAMEWORK_GenericVersionValidationSubsystem_generated_h
#error "GenericVersionValidationSubsystem.generated.h already included, missing '#pragma once' in GenericVersionValidationSubsystem.h"
#endif
#define GENERICVERSIONFRAMEWORK_GenericVersionValidationSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGenericVersionContext;
struct FGenericVersionValidationResult;

// ********** Begin Class UGenericVersionValidationSubsystem ***************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execMakeValidationFailed); \
	DECLARE_FUNCTION(execMakeValidationWarning); \
	DECLARE_FUNCTION(execMakeValidationSuccess); \
	DECLARE_FUNCTION(execValidateVersionContext);


struct Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics;
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionValidationSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericVersionValidationSubsystem(); \
	friend struct ::Z_Construct_UClass_UGenericVersionValidationSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICVERSIONFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericVersionValidationSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericVersionValidationSubsystem, UGenericGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericVersionFramework"), Z_Construct_UClass_UGenericVersionValidationSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGenericVersionValidationSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICVERSIONFRAMEWORK_API UGenericVersionValidationSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericVersionValidationSubsystem(UGenericVersionValidationSubsystem&&) = delete; \
	UGenericVersionValidationSubsystem(const UGenericVersionValidationSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICVERSIONFRAMEWORK_API, UGenericVersionValidationSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericVersionValidationSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenericVersionValidationSubsystem) \
	GENERICVERSIONFRAMEWORK_API virtual ~UGenericVersionValidationSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h_14_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h_17_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericVersionValidationSubsystem;

// ********** End Class UGenericVersionValidationSubsystem *****************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionValidationSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
