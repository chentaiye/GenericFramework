// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AsyncFunctions/GetDesktopDebugReportAsyncAction.h"

#ifdef GENERICDESKTOPFRAMEWORK_GetDesktopDebugReportAsyncAction_generated_h
#error "GetDesktopDebugReportAsyncAction.generated.h already included, missing '#pragma once' in GetDesktopDebugReportAsyncAction.h"
#endif
#define GENERICDESKTOPFRAMEWORK_GetDesktopDebugReportAsyncAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UGetDesktopDebugReportAsyncAction;

// ********** Begin Delegate FOnDesktopDebugReportReady ********************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h_7_DELEGATE \
GENERICDESKTOPFRAMEWORK_API void FOnDesktopDebugReportReady_DelegateWrapper(const FMulticastScriptDelegate& OnDesktopDebugReportReady, const FString& DebugReport);


// ********** End Delegate FOnDesktopDebugReportReady **********************************************

// ********** Begin Class UGetDesktopDebugReportAsyncAction ****************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAsyncGetDesktopDebugReport);


struct Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics;
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGetDesktopDebugReportAsyncAction(); \
	friend struct ::Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICDESKTOPFRAMEWORK_API UClass* ::Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UGetDesktopDebugReportAsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericDesktopFramework"), Z_Construct_UClass_UGetDesktopDebugReportAsyncAction_NoRegister) \
	DECLARE_SERIALIZER(UGetDesktopDebugReportAsyncAction)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h_13_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICDESKTOPFRAMEWORK_API UGetDesktopDebugReportAsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGetDesktopDebugReportAsyncAction(UGetDesktopDebugReportAsyncAction&&) = delete; \
	UGetDesktopDebugReportAsyncAction(const UGetDesktopDebugReportAsyncAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICDESKTOPFRAMEWORK_API, UGetDesktopDebugReportAsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGetDesktopDebugReportAsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGetDesktopDebugReportAsyncAction) \
	GENERICDESKTOPFRAMEWORK_API virtual ~UGetDesktopDebugReportAsyncAction();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h_10_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h_13_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGetDesktopDebugReportAsyncAction;

// ********** End Class UGetDesktopDebugReportAsyncAction ******************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopDebugReportAsyncAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
