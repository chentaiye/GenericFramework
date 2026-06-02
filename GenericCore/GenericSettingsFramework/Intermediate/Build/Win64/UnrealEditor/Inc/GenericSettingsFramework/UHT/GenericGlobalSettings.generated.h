// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DeveloperSettings/GenericGlobalSettings.h"

#ifdef GENERICSETTINGSFRAMEWORK_GenericGlobalSettings_generated_h
#error "GenericGlobalSettings.generated.h already included, missing '#pragma once' in GenericGlobalSettings.h"
#endif
#define GENERICSETTINGSFRAMEWORK_GenericGlobalSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericGlobalSettings ***************************************************
struct Z_Construct_UClass_UGenericGlobalSettings_Statics;
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericGlobalSettings_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericGlobalSettings(); \
	friend struct ::Z_Construct_UClass_UGenericGlobalSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSETTINGSFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericGlobalSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericGlobalSettings, UGenericDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/GenericSettingsFramework"), Z_Construct_UClass_UGenericGlobalSettings_NoRegister) \
	DECLARE_SERIALIZER(UGenericGlobalSettings)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICSETTINGSFRAMEWORK_API UGenericGlobalSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericGlobalSettings(UGenericGlobalSettings&&) = delete; \
	UGenericGlobalSettings(const UGenericGlobalSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSETTINGSFRAMEWORK_API, UGenericGlobalSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericGlobalSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericGlobalSettings) \
	GENERICSETTINGSFRAMEWORK_API virtual ~UGenericGlobalSettings();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericGlobalSettings;

// ********** End Class UGenericGlobalSettings *****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericGlobalSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
