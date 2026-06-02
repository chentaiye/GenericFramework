// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystem/GenericEngineSubsystem.h"

#ifdef GENERICCOREFRAMEWORK_GenericEngineSubsystem_generated_h
#error "GenericEngineSubsystem.generated.h already included, missing '#pragma once' in GenericEngineSubsystem.h"
#endif
#define GENERICCOREFRAMEWORK_GenericEngineSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericEngineSubsystem **************************************************
struct Z_Construct_UClass_UGenericEngineSubsystem_Statics;
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericEngineSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericEngineSubsystem_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericEngineSubsystem(); \
	friend struct ::Z_Construct_UClass_UGenericEngineSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICCOREFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericEngineSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericEngineSubsystem, UEngineSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericCoreFramework"), Z_Construct_UClass_UGenericEngineSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGenericEngineSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericEngineSubsystem_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICCOREFRAMEWORK_API UGenericEngineSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericEngineSubsystem(UGenericEngineSubsystem&&) = delete; \
	UGenericEngineSubsystem(const UGenericEngineSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICCOREFRAMEWORK_API, UGenericEngineSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericEngineSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenericEngineSubsystem) \
	GENERICCOREFRAMEWORK_API virtual ~UGenericEngineSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericEngineSubsystem_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericEngineSubsystem_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericEngineSubsystem_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericEngineSubsystem_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericEngineSubsystem;

// ********** End Class UGenericEngineSubsystem ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericEngineSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
