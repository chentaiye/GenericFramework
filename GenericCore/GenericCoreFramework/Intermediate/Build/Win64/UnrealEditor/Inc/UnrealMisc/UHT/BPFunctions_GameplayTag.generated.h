// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BPFunctions/BPFunctions_GameplayTag.h"

#ifdef UNREALMISC_BPFunctions_GameplayTag_generated_h
#error "BPFunctions_GameplayTag.generated.h already included, missing '#pragma once' in BPFunctions_GameplayTag.h"
#endif
#define UNREALMISC_BPFunctions_GameplayTag_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTag;
struct FGameplayTagContainer;

// ********** Begin Class UBPFunctions_GameplayTag *************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execConv_NameToGameplayTag); \
	DECLARE_FUNCTION(execConv_GameplayTagToName); \
	DECLARE_FUNCTION(execConv_StringToGameplayTag); \
	DECLARE_FUNCTION(execConv_GameplayTagToString); \
	DECLARE_FUNCTION(execGetDirectGameplayTagParent); \
	DECLARE_FUNCTION(execGetGameplayTagParents); \
	DECLARE_FUNCTION(execGetDirectGameplayTagChildren); \
	DECLARE_FUNCTION(execGetGameplayTagChildren);


struct Z_Construct_UClass_UBPFunctions_GameplayTag_Statics;
UNREALMISC_API UClass* Z_Construct_UClass_UBPFunctions_GameplayTag_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBPFunctions_GameplayTag(); \
	friend struct ::Z_Construct_UClass_UBPFunctions_GameplayTag_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend UNREALMISC_API UClass* ::Z_Construct_UClass_UBPFunctions_GameplayTag_NoRegister(); \
public: \
	DECLARE_CLASS2(UBPFunctions_GameplayTag, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UnrealMisc"), Z_Construct_UClass_UBPFunctions_GameplayTag_NoRegister) \
	DECLARE_SERIALIZER(UBPFunctions_GameplayTag)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	UNREALMISC_API UBPFunctions_GameplayTag(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBPFunctions_GameplayTag(UBPFunctions_GameplayTag&&) = delete; \
	UBPFunctions_GameplayTag(const UBPFunctions_GameplayTag&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(UNREALMISC_API, UBPFunctions_GameplayTag); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBPFunctions_GameplayTag); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBPFunctions_GameplayTag) \
	UNREALMISC_API virtual ~UBPFunctions_GameplayTag();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h_11_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h_14_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBPFunctions_GameplayTag;

// ********** End Class UBPFunctions_GameplayTag ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_BPFunctions_BPFunctions_GameplayTag_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
