// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AsyncAction/BroadcastGameplayMessageAsyncAction.h"

#ifdef GENERICMESSAGEFRAMEWORK_BroadcastGameplayMessageAsyncAction_generated_h
#error "BroadcastGameplayMessageAsyncAction.generated.h already included, missing '#pragma once' in BroadcastGameplayMessageAsyncAction.h"
#endif
#define GENERICMESSAGEFRAMEWORK_BroadcastGameplayMessageAsyncAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UBroadcastGameplayMessageAsyncAction;
class UObject;
struct FGameplayTag;

// ********** Begin Delegate FBroadcastGameplayMessageAsyncDelegate ********************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h_15_DELEGATE \
GENERICMESSAGEFRAMEWORK_API void FBroadcastGameplayMessageAsyncDelegate_DelegateWrapper(const FMulticastScriptDelegate& BroadcastGameplayMessageAsyncDelegate);


// ********** End Delegate FBroadcastGameplayMessageAsyncDelegate **********************************

// ********** Begin Class UBroadcastGameplayMessageAsyncAction *************************************
struct Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics;
	struct Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics; \
GENERICMESSAGEFRAMEWORK_API UClass* Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUBroadcastGameplayMessageAsyncAction(); \
	friend struct ::Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics; \
	friend struct ::Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICMESSAGEFRAMEWORK_API UClass* ::Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UBroadcastGameplayMessageAsyncAction, UCancellableAsyncAction, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericMessageFramework"), Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_NoRegister) \
	DECLARE_SERIALIZER(UBroadcastGameplayMessageAsyncAction)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICMESSAGEFRAMEWORK_API UBroadcastGameplayMessageAsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UBroadcastGameplayMessageAsyncAction(UBroadcastGameplayMessageAsyncAction&&) = delete; \
	UBroadcastGameplayMessageAsyncAction(const UBroadcastGameplayMessageAsyncAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICMESSAGEFRAMEWORK_API, UBroadcastGameplayMessageAsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UBroadcastGameplayMessageAsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UBroadcastGameplayMessageAsyncAction) \
	GENERICMESSAGEFRAMEWORK_API virtual ~UBroadcastGameplayMessageAsyncAction();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h_18_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h_21_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UBroadcastGameplayMessageAsyncAction;

// ********** End Class UBroadcastGameplayMessageAsyncAction ***************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
