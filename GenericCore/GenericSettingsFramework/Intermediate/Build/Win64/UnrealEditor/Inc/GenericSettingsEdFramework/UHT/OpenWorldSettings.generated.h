// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WorldSettings/OpenWorldSettings.h"

#ifdef GENERICSETTINGSEDFRAMEWORK_OpenWorldSettings_generated_h
#error "OpenWorldSettings.generated.h already included, missing '#pragma once' in OpenWorldSettings.h"
#endif
#define GENERICSETTINGSEDFRAMEWORK_OpenWorldSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UOpenWorldSettings *******************************************************
struct Z_Construct_UClass_UOpenWorldSettings_Statics;
GENERICSETTINGSEDFRAMEWORK_API UClass* Z_Construct_UClass_UOpenWorldSettings_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOpenWorldSettings(); \
	friend struct ::Z_Construct_UClass_UOpenWorldSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSETTINGSEDFRAMEWORK_API UClass* ::Z_Construct_UClass_UOpenWorldSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UOpenWorldSettings, UEditorSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSettingsEdFramework"), Z_Construct_UClass_UOpenWorldSettings_NoRegister) \
	DECLARE_SERIALIZER(UOpenWorldSettings)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICSETTINGSEDFRAMEWORK_API UOpenWorldSettings(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UOpenWorldSettings(UOpenWorldSettings&&) = delete; \
	UOpenWorldSettings(const UOpenWorldSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSETTINGSEDFRAMEWORK_API, UOpenWorldSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOpenWorldSettings); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOpenWorldSettings) \
	GENERICSETTINGSEDFRAMEWORK_API virtual ~UOpenWorldSettings();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h_12_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h_15_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UOpenWorldSettings;

// ********** End Class UOpenWorldSettings *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_WorldSettings_OpenWorldSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
