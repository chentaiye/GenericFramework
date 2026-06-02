// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "K2Node_ListenForGameplayMessages.h"

#ifdef GENERICMESSAGENODE_K2Node_ListenForGameplayMessages_generated_h
#error "K2Node_ListenForGameplayMessages.generated.h already included, missing '#pragma once' in K2Node_ListenForGameplayMessages.h"
#endif
#define GENERICMESSAGENODE_K2Node_ListenForGameplayMessages_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UK2Node_ListenForGameplayMessages ****************************************
struct Z_Construct_UClass_UK2Node_ListenForGameplayMessages_Statics;
GENERICMESSAGENODE_API UClass* Z_Construct_UClass_UK2Node_ListenForGameplayMessages_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_ListenForGameplayMessages_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUK2Node_ListenForGameplayMessages(); \
	friend struct ::Z_Construct_UClass_UK2Node_ListenForGameplayMessages_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICMESSAGENODE_API UClass* ::Z_Construct_UClass_UK2Node_ListenForGameplayMessages_NoRegister(); \
public: \
	DECLARE_CLASS2(UK2Node_ListenForGameplayMessages, UK2Node_AsyncAction, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericMessageNode"), Z_Construct_UClass_UK2Node_ListenForGameplayMessages_NoRegister) \
	DECLARE_SERIALIZER(UK2Node_ListenForGameplayMessages)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_ListenForGameplayMessages_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICMESSAGENODE_API UK2Node_ListenForGameplayMessages(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UK2Node_ListenForGameplayMessages(UK2Node_ListenForGameplayMessages&&) = delete; \
	UK2Node_ListenForGameplayMessages(const UK2Node_ListenForGameplayMessages&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICMESSAGENODE_API, UK2Node_ListenForGameplayMessages); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UK2Node_ListenForGameplayMessages); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UK2Node_ListenForGameplayMessages) \
	GENERICMESSAGENODE_API virtual ~UK2Node_ListenForGameplayMessages();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_ListenForGameplayMessages_h_17_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_ListenForGameplayMessages_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_ListenForGameplayMessages_h_20_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_ListenForGameplayMessages_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UK2Node_ListenForGameplayMessages;

// ********** End Class UK2Node_ListenForGameplayMessages ******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageNode_Public_K2Node_ListenForGameplayMessages_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
