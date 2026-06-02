// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystem/GenericLocalPlayerSubsystem.h"

#ifdef GENERICCOREFRAMEWORK_GenericLocalPlayerSubsystem_generated_h
#error "GenericLocalPlayerSubsystem.generated.h already included, missing '#pragma once' in GenericLocalPlayerSubsystem.h"
#endif
#define GENERICCOREFRAMEWORK_GenericLocalPlayerSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericLocalPlayerSubsystem *********************************************
struct Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics;
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericLocalPlayerSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericLocalPlayerSubsystem(); \
	friend struct ::Z_Construct_UClass_UGenericLocalPlayerSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICCOREFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericLocalPlayerSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericLocalPlayerSubsystem, ULocalPlayerSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericCoreFramework"), Z_Construct_UClass_UGenericLocalPlayerSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGenericLocalPlayerSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICCOREFRAMEWORK_API UGenericLocalPlayerSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericLocalPlayerSubsystem(UGenericLocalPlayerSubsystem&&) = delete; \
	UGenericLocalPlayerSubsystem(const UGenericLocalPlayerSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICCOREFRAMEWORK_API, UGenericLocalPlayerSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericLocalPlayerSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenericLocalPlayerSubsystem) \
	GENERICCOREFRAMEWORK_API virtual ~UGenericLocalPlayerSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericLocalPlayerSubsystem;

// ********** End Class UGenericLocalPlayerSubsystem ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericLocalPlayerSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
