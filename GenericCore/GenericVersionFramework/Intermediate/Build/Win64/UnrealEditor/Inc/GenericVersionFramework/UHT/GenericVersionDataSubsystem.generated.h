// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Subsystem/GenericVersionDataSubsystem.h"

#ifdef GENERICVERSIONFRAMEWORK_GenericVersionDataSubsystem_generated_h
#error "GenericVersionDataSubsystem.generated.h already included, missing '#pragma once' in GenericVersionDataSubsystem.h"
#endif
#define GENERICVERSIONFRAMEWORK_GenericVersionDataSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
struct FGameplayTag;
struct FGenericVersionData;
struct FGenericVersionDefinition;

// ********** Begin Class UGenericVersionDataSubsystem *********************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execClearVersionData); \
	DECLARE_FUNCTION(execRemoveVersionDataByKey); \
	DECLARE_FUNCTION(execRemoveVersionData); \
	DECLARE_FUNCTION(execSetVersionData); \
	DECLARE_FUNCTION(execGetVersionData); \
	DECLARE_FUNCTION(execRefreshVersionData); \
	DECLARE_FUNCTION(execResolveVersionData); \
	DECLARE_FUNCTION(execClearVersionDefinitions); \
	DECLARE_FUNCTION(execRemoveVersionDefinition); \
	DECLARE_FUNCTION(execGetVersionDefinition); \
	DECLARE_FUNCTION(execSetVersionDefinition); \
	DECLARE_FUNCTION(execRegisterVersionDefinitionsFromSettings);


struct Z_Construct_UClass_UGenericVersionDataSubsystem_Statics;
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionDataSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericVersionDataSubsystem(); \
	friend struct ::Z_Construct_UClass_UGenericVersionDataSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICVERSIONFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericVersionDataSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericVersionDataSubsystem, UGenericGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericVersionFramework"), Z_Construct_UClass_UGenericVersionDataSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGenericVersionDataSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICVERSIONFRAMEWORK_API UGenericVersionDataSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericVersionDataSubsystem(UGenericVersionDataSubsystem&&) = delete; \
	UGenericVersionDataSubsystem(const UGenericVersionDataSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICVERSIONFRAMEWORK_API, UGenericVersionDataSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericVersionDataSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGenericVersionDataSubsystem) \
	GENERICVERSIONFRAMEWORK_API virtual ~UGenericVersionDataSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h_14_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h_17_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericVersionDataSubsystem;

// ********** End Class UGenericVersionDataSubsystem ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Subsystem_GenericVersionDataSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
