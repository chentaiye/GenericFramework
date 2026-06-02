// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystem/GenericGameInstanceSubsystem.h"

#ifdef GENERICCOREFRAMEWORK_GenericGameInstanceSubsystem_generated_h
#error "GenericGameInstanceSubsystem.generated.h already included, missing '#pragma once' in GenericGameInstanceSubsystem.h"
#endif
#define GENERICCOREFRAMEWORK_GenericGameInstanceSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericGameInstanceSubsystem ********************************************
struct Z_Construct_UClass_UGenericGameInstanceSubsystem_Statics;
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericGameInstanceSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericGameInstanceSubsystem_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericGameInstanceSubsystem(); \
	friend struct ::Z_Construct_UClass_UGenericGameInstanceSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICCOREFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericGameInstanceSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericGameInstanceSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericCoreFramework"), Z_Construct_UClass_UGenericGameInstanceSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGenericGameInstanceSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericGameInstanceSubsystem_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICCOREFRAMEWORK_API UGenericGameInstanceSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericGameInstanceSubsystem(UGenericGameInstanceSubsystem&&) = delete; \
	UGenericGameInstanceSubsystem(const UGenericGameInstanceSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICCOREFRAMEWORK_API, UGenericGameInstanceSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericGameInstanceSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenericGameInstanceSubsystem) \
	GENERICCOREFRAMEWORK_API virtual ~UGenericGameInstanceSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericGameInstanceSubsystem_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericGameInstanceSubsystem_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericGameInstanceSubsystem_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericGameInstanceSubsystem_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericGameInstanceSubsystem;

// ********** End Class UGenericGameInstanceSubsystem **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericGameInstanceSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
