// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AsyncFunctions/DesktopDialogAsyncAction.h"

#ifdef GENERICDESKTOPFRAMEWORK_DesktopDialogAsyncAction_generated_h
#error "DesktopDialogAsyncAction.generated.h already included, missing '#pragma once' in DesktopDialogAsyncAction.h"
#endif
#define GENERICDESKTOPFRAMEWORK_DesktopDialogAsyncAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDesktopDialogAsyncAction;
struct FDesktopDialogResult;

// ********** Begin Delegate FOnDesktopDialogCompleted *********************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopDialogAsyncAction_h_8_DELEGATE \
GENERICDESKTOPFRAMEWORK_API void FOnDesktopDialogCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnDesktopDialogCompleted, FDesktopDialogResult const& Result);


// ********** End Delegate FOnDesktopDialogCompleted ***********************************************

// ********** Begin Class UDesktopDialogAsyncAction ************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopDialogAsyncAction_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAsyncSaveFileDialog); \
	DECLARE_FUNCTION(execAsyncOpenFileDialog); \
	DECLARE_FUNCTION(execAsyncOpenDirectoryDialog);


struct Z_Construct_UClass_UDesktopDialogAsyncAction_Statics;
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UDesktopDialogAsyncAction_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopDialogAsyncAction_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDesktopDialogAsyncAction(); \
	friend struct ::Z_Construct_UClass_UDesktopDialogAsyncAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICDESKTOPFRAMEWORK_API UClass* ::Z_Construct_UClass_UDesktopDialogAsyncAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UDesktopDialogAsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericDesktopFramework"), Z_Construct_UClass_UDesktopDialogAsyncAction_NoRegister) \
	DECLARE_SERIALIZER(UDesktopDialogAsyncAction)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopDialogAsyncAction_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICDESKTOPFRAMEWORK_API UDesktopDialogAsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDesktopDialogAsyncAction(UDesktopDialogAsyncAction&&) = delete; \
	UDesktopDialogAsyncAction(const UDesktopDialogAsyncAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICDESKTOPFRAMEWORK_API, UDesktopDialogAsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDesktopDialogAsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDesktopDialogAsyncAction) \
	GENERICDESKTOPFRAMEWORK_API virtual ~UDesktopDialogAsyncAction();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopDialogAsyncAction_h_11_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopDialogAsyncAction_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopDialogAsyncAction_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopDialogAsyncAction_h_14_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopDialogAsyncAction_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDesktopDialogAsyncAction;

// ********** End Class UDesktopDialogAsyncAction **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopDialogAsyncAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
