// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AsyncAction/ListenForGameplayMessagesAsyncAction.h"

#ifdef GENERICMESSAGEFRAMEWORK_ListenForGameplayMessagesAsyncAction_generated_h
#error "ListenForGameplayMessagesAsyncAction.generated.h already included, missing '#pragma once' in ListenForGameplayMessagesAsyncAction.h"
#endif
#define GENERICMESSAGEFRAMEWORK_ListenForGameplayMessagesAsyncAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UListenForGameplayMessagesAsyncAction;
class UObject;
class UScriptStruct;
enum class EGameplayMessageMatch : uint8;
struct FGameplayTag;

// ********** Begin Delegate FAsyncGameplayMessageDelegate *****************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_ListenForGameplayMessagesAsyncAction_h_16_DELEGATE \
GENERICMESSAGEFRAMEWORK_API void FAsyncGameplayMessageDelegate_DelegateWrapper(const FMulticastScriptDelegate& AsyncGameplayMessageDelegate, UListenForGameplayMessagesAsyncAction* ProxyObject, FGameplayTag ActualChannel);


// ********** End Delegate FAsyncGameplayMessageDelegate *******************************************

// ********** Begin Class UListenForGameplayMessagesAsyncAction ************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_ListenForGameplayMessagesAsyncAction_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execListenForGameplayMessages);


struct Z_Construct_UClass_UListenForGameplayMessagesAsyncAction_Statics;
	struct Z_Construct_UFunction_UListenForGameplayMessagesAsyncAction_GetPayload_Statics; \
GENERICMESSAGEFRAMEWORK_API UClass* Z_Construct_UClass_UListenForGameplayMessagesAsyncAction_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_ListenForGameplayMessagesAsyncAction_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUListenForGameplayMessagesAsyncAction(); \
	friend struct ::Z_Construct_UClass_UListenForGameplayMessagesAsyncAction_Statics; \
	friend struct ::Z_Construct_UFunction_UListenForGameplayMessagesAsyncAction_GetPayload_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICMESSAGEFRAMEWORK_API UClass* ::Z_Construct_UClass_UListenForGameplayMessagesAsyncAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UListenForGameplayMessagesAsyncAction, UCancellableAsyncAction, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericMessageFramework"), Z_Construct_UClass_UListenForGameplayMessagesAsyncAction_NoRegister) \
	DECLARE_SERIALIZER(UListenForGameplayMessagesAsyncAction)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_ListenForGameplayMessagesAsyncAction_h_22_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICMESSAGEFRAMEWORK_API UListenForGameplayMessagesAsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UListenForGameplayMessagesAsyncAction(UListenForGameplayMessagesAsyncAction&&) = delete; \
	UListenForGameplayMessagesAsyncAction(const UListenForGameplayMessagesAsyncAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICMESSAGEFRAMEWORK_API, UListenForGameplayMessagesAsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UListenForGameplayMessagesAsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UListenForGameplayMessagesAsyncAction) \
	GENERICMESSAGEFRAMEWORK_API virtual ~UListenForGameplayMessagesAsyncAction();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_ListenForGameplayMessagesAsyncAction_h_19_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_ListenForGameplayMessagesAsyncAction_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_ListenForGameplayMessagesAsyncAction_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_ListenForGameplayMessagesAsyncAction_h_22_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_ListenForGameplayMessagesAsyncAction_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UListenForGameplayMessagesAsyncAction;

// ********** End Class UListenForGameplayMessagesAsyncAction **************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_ListenForGameplayMessagesAsyncAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
