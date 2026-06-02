// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Settings/GenericVersionSettings.h"

#ifdef GENERICVERSIONFRAMEWORK_GenericVersionSettings_generated_h
#error "GenericVersionSettings.generated.h already included, missing '#pragma once' in GenericVersionSettings.h"
#endif
#define GENERICVERSIONFRAMEWORK_GenericVersionSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UGenericVersionSettings **************************************************
struct Z_Construct_UClass_UGenericVersionSettings_Statics;
GENERICVERSIONFRAMEWORK_API UClass* Z_Construct_UClass_UGenericVersionSettings_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericVersionSettings(); \
	friend struct ::Z_Construct_UClass_UGenericVersionSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICVERSIONFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericVersionSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericVersionSettings, UGenericDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/GenericVersionFramework"), Z_Construct_UClass_UGenericVersionSettings_NoRegister) \
	DECLARE_SERIALIZER(UGenericVersionSettings)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICVERSIONFRAMEWORK_API UGenericVersionSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericVersionSettings(UGenericVersionSettings&&) = delete; \
	UGenericVersionSettings(const UGenericVersionSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICVERSIONFRAMEWORK_API, UGenericVersionSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericVersionSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericVersionSettings) \
	GENERICVERSIONFRAMEWORK_API virtual ~UGenericVersionSettings();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h_11_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h_14_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericVersionSettings;

// ********** End Class UGenericVersionSettings ****************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericVersionFramework_Source_GenericVersionFramework_Public_Settings_GenericVersionSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
