// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPFunctions/BPFunctions_World.h"

#ifdef UNREALMISC_BPFunctions_World_generated_h
#error "BPFunctions_World.generated.h already included, missing '#pragma once' in BPFunctions_World.h"
#endif
#define UNREALMISC_BPFunctions_World_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
enum class EWorldTypeBP : uint8;

// ********** Begin Class UBPFunctions_World *******************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetWorldType); \
	DECLARE_FUNCTION(execIsPartitionedWorld);


struct Z_Construct_UClass_UBPFunctions_World_Statics;
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_World_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPFunctions_World(); \
	friend struct ::Z_Construct_UClass_UBPFunctions_World_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend UNREALMISC_API UClass* ::Z_Construct_UClass_UBPFunctions_World_NoRegister(); \
public: \
	DECLARE_CLASS2(UBPFunctions_World, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealMisc"), Z_Construct_UClass_UBPFunctions_World_NoRegister) \
	DECLARE_SERIALIZER(UBPFunctions_World)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	UNREALMISC_API UBPFunctions_World(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBPFunctions_World(UBPFunctions_World&&) = delete; \
	UBPFunctions_World(const UBPFunctions_World&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(UNREALMISC_API, UBPFunctions_World); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPFunctions_World); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBPFunctions_World) \
	UNREALMISC_API virtual ~UBPFunctions_World();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h_11_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h_14_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBPFunctions_World;

// ********** End Class UBPFunctions_World *********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_World_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
