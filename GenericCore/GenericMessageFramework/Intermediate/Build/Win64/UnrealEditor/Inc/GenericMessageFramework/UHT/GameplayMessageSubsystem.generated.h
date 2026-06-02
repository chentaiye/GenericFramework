// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameplayMessageSubsystem.h"

#ifdef GENERICMESSAGEFRAMEWORK_GameplayMessageSubsystem_generated_h
#error "GameplayMessageSubsystem.generated.h already included, missing '#pragma once' in GameplayMessageSubsystem.h"
#endif
#define GENERICMESSAGEFRAMEWORK_GameplayMessageSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FGameplayTag;

// ********** Begin ScriptStruct FGameplayMessageListenerHandle ************************************
struct Z_Construct_UScriptStruct_FGameplayMessageListenerHandle_Statics;
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageSubsystem_h_24_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGameplayMessageListenerHandle_Statics; \
	GENERICMESSAGEFRAMEWORK_API static class UScriptStruct* StaticStruct();


struct FGameplayMessageListenerHandle;
// ********** End ScriptStruct FGameplayMessageListenerHandle **************************************

// ********** Begin ScriptStruct FGameplayMessageListenerData **************************************
struct Z_Construct_UScriptStruct_FGameplayMessageListenerData_Statics;
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageSubsystem_h_64_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FGameplayMessageListenerData_Statics; \
	GENERICMESSAGEFRAMEWORK_API static class UScriptStruct* StaticStruct();


struct FGameplayMessageListenerData;
// ********** End ScriptStruct FGameplayMessageListenerData ****************************************

// ********** Begin Class UGameplayMessageSubsystem ************************************************
struct Z_Construct_UClass_UGameplayMessageSubsystem_Statics;
	struct Z_Construct_UFunction_UGameplayMessageSubsystem_K2_BroadcastMessage_Statics; \
GENERICMESSAGEFRAMEWORK_API UClass* Z_Construct_UClass_UGameplayMessageSubsystem_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageSubsystem_h_86_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameplayMessageSubsystem(); \
	friend struct ::Z_Construct_UClass_UGameplayMessageSubsystem_Statics; \
	friend struct ::Z_Construct_UFunction_UGameplayMessageSubsystem_K2_BroadcastMessage_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICMESSAGEFRAMEWORK_API UClass* ::Z_Construct_UClass_UGameplayMessageSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UGameplayMessageSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericMessageFramework"), Z_Construct_UClass_UGameplayMessageSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UGameplayMessageSubsystem)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageSubsystem_h_86_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICMESSAGEFRAMEWORK_API UGameplayMessageSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGameplayMessageSubsystem(UGameplayMessageSubsystem&&) = delete; \
	UGameplayMessageSubsystem(const UGameplayMessageSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICMESSAGEFRAMEWORK_API, UGameplayMessageSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameplayMessageSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGameplayMessageSubsystem) \
	GENERICMESSAGEFRAMEWORK_API virtual ~UGameplayMessageSubsystem();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageSubsystem_h_83_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageSubsystem_h_86_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageSubsystem_h_86_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageSubsystem_h_86_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGameplayMessageSubsystem;

// ********** End Class UGameplayMessageSubsystem **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_GameplayMessageSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
