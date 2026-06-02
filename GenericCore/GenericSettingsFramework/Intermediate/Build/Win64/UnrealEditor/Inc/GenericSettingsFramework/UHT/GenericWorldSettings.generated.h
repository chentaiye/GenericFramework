// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WorldSettings/GenericWorldSettings.h"

#ifdef GENERICSETTINGSFRAMEWORK_GenericWorldSettings_generated_h
#error "GenericWorldSettings.generated.h already included, missing '#pragma once' in GenericWorldSettings.h"
#endif
#define GENERICSETTINGSFRAMEWORK_GenericWorldSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UWorld;

// ********** Begin Class UGenericWorldSettings ****************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void OnWorldSettingsBeginDestroy_Implementation(); \
	virtual void OnWorldSettingsUnloaded_Implementation(UWorld* World); \
	virtual void OnWorldSettingsBeginTearDown_Implementation(UWorld* World); \
	virtual void OnWorldSettingsPostBeginPlay_Implementation(UWorld* World); \
	virtual void OnWorldSettingsMatchStarting_Implementation(UWorld* World); \
	virtual void OnWorldSettingsBeginPlay_Implementation(UWorld* World); \
	virtual void OnWorldSettingsLoaded_Implementation(UWorld* World); \
	virtual void OnWorldSettingsPostLoad_Implementation(); \
	DECLARE_FUNCTION(execOnWorldSettingsBeginDestroy); \
	DECLARE_FUNCTION(execOnWorldSettingsUnloaded); \
	DECLARE_FUNCTION(execOnWorldSettingsBeginTearDown); \
	DECLARE_FUNCTION(execOnWorldSettingsPostBeginPlay); \
	DECLARE_FUNCTION(execOnWorldSettingsMatchStarting); \
	DECLARE_FUNCTION(execOnWorldSettingsBeginPlay); \
	DECLARE_FUNCTION(execOnWorldSettingsLoaded); \
	DECLARE_FUNCTION(execOnWorldSettingsPostLoad);


#if WITH_EDITOR
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_RPC_WRAPPERS_NO_PURE_DECLS_EOD \
	virtual void OnWorldSettingsEditorUnloaded_Implementation(UWorld* World); \
	virtual void OnWorldSettingsEditorSaved_Implementation(UWorld* World); \
	virtual void OnWorldSettingsEditorPreSave_Implementation(UWorld* World); \
	virtual void OnWorldSettingsEditorChanged_Implementation(UWorld* World); \
	virtual void OnWorldSettingsEditorLoaded_Implementation(UWorld* World); \
	virtual void OnWorldSettingsEditorCreated_Implementation(UWorld* World); \
	virtual FText GetWorldSettingsDisabledReason_Implementation(UWorld* World) const; \
	virtual bool IsWorldSettingsEnabled_Implementation(UWorld* World) const; \
	virtual FName GetSettingsCategory_Implementation() const; \
	virtual FText GetSettingsDescription_Implementation() const; \
	virtual FText GetSettingsDisplayName_Implementation() const; \
	DECLARE_FUNCTION(execOnWorldSettingsEditorUnloaded); \
	DECLARE_FUNCTION(execOnWorldSettingsEditorSaved); \
	DECLARE_FUNCTION(execOnWorldSettingsEditorPreSave); \
	DECLARE_FUNCTION(execOnWorldSettingsEditorChanged); \
	DECLARE_FUNCTION(execOnWorldSettingsEditorLoaded); \
	DECLARE_FUNCTION(execOnWorldSettingsEditorCreated); \
	DECLARE_FUNCTION(execGetWorldSettingsDisabledReason); \
	DECLARE_FUNCTION(execIsWorldSettingsEnabled); \
	DECLARE_FUNCTION(execGetSettingsCategory); \
	DECLARE_FUNCTION(execGetSettingsDescription); \
	DECLARE_FUNCTION(execGetSettingsDisplayName);
#else // WITH_EDITOR
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_RPC_WRAPPERS_NO_PURE_DECLS_EOD
#endif // WITH_EDITOR


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UGenericWorldSettings_Statics;
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettings_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericWorldSettings(); \
	friend struct ::Z_Construct_UClass_UGenericWorldSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSETTINGSFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericWorldSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericWorldSettings, UGenericObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GenericSettingsFramework"), Z_Construct_UClass_UGenericWorldSettings_NoRegister) \
	DECLARE_SERIALIZER(UGenericWorldSettings)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericWorldSettings(UGenericWorldSettings&&) = delete; \
	UGenericWorldSettings(const UGenericWorldSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGenericWorldSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericWorldSettings); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericWorldSettings) \
	NO_API virtual ~UGenericWorldSettings();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_RPC_WRAPPERS_NO_PURE_DECLS_EOD \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_CALLBACK_WRAPPERS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericWorldSettings;

// ********** End Class UGenericWorldSettings ******************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
