// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WorldSettings/GenericWorldSettingsSubsystem.h"

#ifdef GENERICSETTINGSFRAMEWORK_GenericWorldSettingsSubsystem_generated_h
#error "GenericWorldSettingsSubsystem.generated.h already included, missing '#pragma once' in GenericWorldSettingsSubsystem.h"
#endif
#define GENERICSETTINGSFRAMEWORK_GenericWorldSettingsSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UClass;
class UGenericWorldSettings;
class UGenericWorldSettingsCollection;
class UGenericWorldSettingsSubsystem;
class UObject;

// ********** Begin Class UGenericWorldSettingsSubsystem *******************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetWorldSetting); \
	DECLARE_FUNCTION(execGetSettingsCollection); \
	DECLARE_FUNCTION(execGetWorldSettingsSubsystem);


struct Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics;
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettingsSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericWorldSettingsSubsystem(); \
	friend struct ::Z_Construct_UClass_UGenericWorldSettingsSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSETTINGSFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericWorldSettingsSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericWorldSettingsSubsystem, UGenericWorldSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSettingsFramework"), Z_Construct_UClass_UGenericWorldSettingsSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGenericWorldSettingsSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICSETTINGSFRAMEWORK_API UGenericWorldSettingsSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericWorldSettingsSubsystem(UGenericWorldSettingsSubsystem&&) = delete; \
	UGenericWorldSettingsSubsystem(const UGenericWorldSettingsSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSETTINGSFRAMEWORK_API, UGenericWorldSettingsSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericWorldSettingsSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenericWorldSettingsSubsystem) \
	GENERICSETTINGSFRAMEWORK_API virtual ~UGenericWorldSettingsSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h_13_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h_16_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericWorldSettingsSubsystem;

// ********** End Class UGenericWorldSettingsSubsystem *********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
