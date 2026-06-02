// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DeveloperSettings/GenericDeveloperSettings.h"

#ifdef GENERICSETTINGSFRAMEWORK_GenericDeveloperSettings_generated_h
#error "GenericDeveloperSettings.generated.h already included, missing '#pragma once' in GenericDeveloperSettings.h"
#endif
#define GENERICSETTINGSFRAMEWORK_GenericDeveloperSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericDeveloperSettings ************************************************
struct Z_Construct_UClass_UGenericDeveloperSettings_Statics;
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericDeveloperSettings_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericDeveloperSettings(); \
	friend struct ::Z_Construct_UClass_UGenericDeveloperSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSETTINGSFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericDeveloperSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericDeveloperSettings, UDeveloperSettings, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_DefaultConfig), CASTCLASS_None, TEXT("/Script/GenericSettingsFramework"), Z_Construct_UClass_UGenericDeveloperSettings_NoRegister) \
	DECLARE_SERIALIZER(UGenericDeveloperSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("GenericSettings");} \



#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICSETTINGSFRAMEWORK_API UGenericDeveloperSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericDeveloperSettings(UGenericDeveloperSettings&&) = delete; \
	UGenericDeveloperSettings(const UGenericDeveloperSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSETTINGSFRAMEWORK_API, UGenericDeveloperSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericDeveloperSettings); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericDeveloperSettings) \
	GENERICSETTINGSFRAMEWORK_API virtual ~UGenericDeveloperSettings();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericDeveloperSettings;

// ********** End Class UGenericDeveloperSettings **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_DeveloperSettings_GenericDeveloperSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
