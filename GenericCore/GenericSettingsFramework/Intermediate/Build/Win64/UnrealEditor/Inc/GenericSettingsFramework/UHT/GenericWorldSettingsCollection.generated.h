// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WorldSettings/GenericWorldSettingsCollection.h"

#ifdef GENERICSETTINGSFRAMEWORK_GenericWorldSettingsCollection_generated_h
#error "GenericWorldSettingsCollection.generated.h already included, missing '#pragma once' in GenericWorldSettingsCollection.h"
#endif
#define GENERICSETTINGSFRAMEWORK_GenericWorldSettingsCollection_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UClass;
class UGenericWorldSettings;

// ********** Begin Class UGenericWorldSettingsCollection ******************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFindSettings);


struct Z_Construct_UClass_UGenericWorldSettingsCollection_Statics;
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettingsCollection_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericWorldSettingsCollection(); \
	friend struct ::Z_Construct_UClass_UGenericWorldSettingsCollection_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSETTINGSFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericWorldSettingsCollection_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericWorldSettingsCollection, UAssetUserData, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSettingsFramework"), Z_Construct_UClass_UGenericWorldSettingsCollection_NoRegister) \
	DECLARE_SERIALIZER(UGenericWorldSettingsCollection)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGenericWorldSettingsCollection(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericWorldSettingsCollection(UGenericWorldSettingsCollection&&) = delete; \
	UGenericWorldSettingsCollection(const UGenericWorldSettingsCollection&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGenericWorldSettingsCollection); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericWorldSettingsCollection); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericWorldSettingsCollection) \
	NO_API virtual ~UGenericWorldSettingsCollection();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h_12_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h_15_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericWorldSettingsCollection;

// ********** End Class UGenericWorldSettingsCollection ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettingsCollection_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
