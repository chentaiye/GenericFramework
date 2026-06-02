// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AsyncFunctions/GetDesktopHardwareSnapshotAsyncAction.h"

#ifdef GENERICDESKTOPFRAMEWORK_GetDesktopHardwareSnapshotAsyncAction_generated_h
#error "GetDesktopHardwareSnapshotAsyncAction.generated.h already included, missing '#pragma once' in GetDesktopHardwareSnapshotAsyncAction.h"
#endif
#define GENERICDESKTOPFRAMEWORK_GetDesktopHardwareSnapshotAsyncAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UGetDesktopHardwareSnapshotAsyncAction;
struct FDesktopHardwareSnapshot;

// ********** Begin Delegate FOnDesktopHardwareSnapshotReady ***************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h_8_DELEGATE \
GENERICDESKTOPFRAMEWORK_API void FOnDesktopHardwareSnapshotReady_DelegateWrapper(const FMulticastScriptDelegate& OnDesktopHardwareSnapshotReady, FDesktopHardwareSnapshot const& Snapshot);


// ********** End Delegate FOnDesktopHardwareSnapshotReady *****************************************

// ********** Begin Delegate FOnDesktopHardwareSnapshotFailed **************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h_9_DELEGATE \
GENERICDESKTOPFRAMEWORK_API void FOnDesktopHardwareSnapshotFailed_DelegateWrapper(const FMulticastScriptDelegate& OnDesktopHardwareSnapshotFailed, const FString& ErrorMessage);


// ********** End Delegate FOnDesktopHardwareSnapshotFailed ****************************************

// ********** Begin Class UGetDesktopHardwareSnapshotAsyncAction ***********************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAsyncGetDesktopHardwareSnapshot);


struct Z_Construct_UClass_UGetDesktopHardwareSnapshotAsyncAction_Statics;
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UGetDesktopHardwareSnapshotAsyncAction_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGetDesktopHardwareSnapshotAsyncAction(); \
	friend struct ::Z_Construct_UClass_UGetDesktopHardwareSnapshotAsyncAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICDESKTOPFRAMEWORK_API UClass* ::Z_Construct_UClass_UGetDesktopHardwareSnapshotAsyncAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UGetDesktopHardwareSnapshotAsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericDesktopFramework"), Z_Construct_UClass_UGetDesktopHardwareSnapshotAsyncAction_NoRegister) \
	DECLARE_SERIALIZER(UGetDesktopHardwareSnapshotAsyncAction)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICDESKTOPFRAMEWORK_API UGetDesktopHardwareSnapshotAsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGetDesktopHardwareSnapshotAsyncAction(UGetDesktopHardwareSnapshotAsyncAction&&) = delete; \
	UGetDesktopHardwareSnapshotAsyncAction(const UGetDesktopHardwareSnapshotAsyncAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICDESKTOPFRAMEWORK_API, UGetDesktopHardwareSnapshotAsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGetDesktopHardwareSnapshotAsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGetDesktopHardwareSnapshotAsyncAction) \
	GENERICDESKTOPFRAMEWORK_API virtual ~UGetDesktopHardwareSnapshotAsyncAction();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h_12_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h_15_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGetDesktopHardwareSnapshotAsyncAction;

// ********** End Class UGetDesktopHardwareSnapshotAsyncAction *************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_GetDesktopHardwareSnapshotAsyncAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
