// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AsyncFunctions/DesktopBytesFileAsyncAction.h"

#ifdef GENERICDESKTOPFRAMEWORK_DesktopBytesFileAsyncAction_generated_h
#error "DesktopBytesFileAsyncAction.generated.h already included, missing '#pragma once' in DesktopBytesFileAsyncAction.h"
#endif
#define GENERICDESKTOPFRAMEWORK_DesktopBytesFileAsyncAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDesktopBytesFileAsyncAction;
struct FDesktopBytesResult;

// ********** Begin Delegate FOnDesktopBytesFileCompleted ******************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h_8_DELEGATE \
GENERICDESKTOPFRAMEWORK_API void FOnDesktopBytesFileCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnDesktopBytesFileCompleted, FDesktopBytesResult const& Result);


// ********** End Delegate FOnDesktopBytesFileCompleted ********************************************

// ********** Begin Class UDesktopBytesFileAsyncAction *********************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAsyncWriteBytesToFile); \
	DECLARE_FUNCTION(execAsyncReadBytesFromFile);


struct Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics;
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UDesktopBytesFileAsyncAction_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDesktopBytesFileAsyncAction(); \
	friend struct ::Z_Construct_UClass_UDesktopBytesFileAsyncAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICDESKTOPFRAMEWORK_API UClass* ::Z_Construct_UClass_UDesktopBytesFileAsyncAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UDesktopBytesFileAsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericDesktopFramework"), Z_Construct_UClass_UDesktopBytesFileAsyncAction_NoRegister) \
	DECLARE_SERIALIZER(UDesktopBytesFileAsyncAction)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICDESKTOPFRAMEWORK_API UDesktopBytesFileAsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDesktopBytesFileAsyncAction(UDesktopBytesFileAsyncAction&&) = delete; \
	UDesktopBytesFileAsyncAction(const UDesktopBytesFileAsyncAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICDESKTOPFRAMEWORK_API, UDesktopBytesFileAsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDesktopBytesFileAsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDesktopBytesFileAsyncAction) \
	GENERICDESKTOPFRAMEWORK_API virtual ~UDesktopBytesFileAsyncAction();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h_11_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h_14_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDesktopBytesFileAsyncAction;

// ********** End Class UDesktopBytesFileAsyncAction ***********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopBytesFileAsyncAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
