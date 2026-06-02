// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystem/GenericWorldSubsystem.h"

#ifdef GENERICCOREFRAMEWORK_GenericWorldSubsystem_generated_h
#error "GenericWorldSubsystem.generated.h already included, missing '#pragma once' in GenericWorldSubsystem.h"
#endif
#define GENERICCOREFRAMEWORK_GenericWorldSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericWorldSubsystem ***************************************************
struct Z_Construct_UClass_UGenericWorldSubsystem_Statics;
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericWorldSubsystem_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericWorldSubsystem(); \
	friend struct ::Z_Construct_UClass_UGenericWorldSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICCOREFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericWorldSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericWorldSubsystem, UWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericCoreFramework"), Z_Construct_UClass_UGenericWorldSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGenericWorldSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericWorldSubsystem_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICCOREFRAMEWORK_API UGenericWorldSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericWorldSubsystem(UGenericWorldSubsystem&&) = delete; \
	UGenericWorldSubsystem(const UGenericWorldSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICCOREFRAMEWORK_API, UGenericWorldSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericWorldSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenericWorldSubsystem) \
	GENERICCOREFRAMEWORK_API virtual ~UGenericWorldSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericWorldSubsystem_h_11_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericWorldSubsystem_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericWorldSubsystem_h_14_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericWorldSubsystem_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericWorldSubsystem;

// ********** End Class UGenericWorldSubsystem *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Subsystem_GenericWorldSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
