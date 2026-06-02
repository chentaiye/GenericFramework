// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "DeveloperSettings/GenericDeveloperEdSettings.h"

#ifdef GENERICSETTINGSEDFRAMEWORK_GenericDeveloperEdSettings_generated_h
#error "GenericDeveloperEdSettings.generated.h already included, missing '#pragma once' in GenericDeveloperEdSettings.h"
#endif
#define GENERICSETTINGSEDFRAMEWORK_GenericDeveloperEdSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericDeveloperEdSettings **********************************************
struct Z_Construct_UClass_UGenericDeveloperEdSettings_Statics;
GENERICSETTINGSEDFRAMEWORK_API UClass* Z_Construct_UClass_UGenericDeveloperEdSettings_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericDeveloperEdSettings(); \
	friend struct ::Z_Construct_UClass_UGenericDeveloperEdSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSETTINGSEDFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericDeveloperEdSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericDeveloperEdSettings, UGenericDeveloperSettings, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_DefaultConfig), CASTCLASS_None, TEXT("/Script/GenericSettingsEdFramework"), Z_Construct_UClass_UGenericDeveloperEdSettings_NoRegister) \
	DECLARE_SERIALIZER(UGenericDeveloperEdSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("GenericEdSettings");} \



#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICSETTINGSEDFRAMEWORK_API UGenericDeveloperEdSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericDeveloperEdSettings(UGenericDeveloperEdSettings&&) = delete; \
	UGenericDeveloperEdSettings(const UGenericDeveloperEdSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSETTINGSEDFRAMEWORK_API, UGenericDeveloperEdSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericDeveloperEdSettings); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericDeveloperEdSettings) \
	GENERICSETTINGSEDFRAMEWORK_API virtual ~UGenericDeveloperEdSettings();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericDeveloperEdSettings;

// ********** End Class UGenericDeveloperEdSettings ************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsEdFramework_Public_DeveloperSettings_GenericDeveloperEdSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
