// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AsyncFunctions/GetAndroidHardwareSnapshotAsyncAction.h"

#ifdef GENERICANDROIDFRAMEWORK_GetAndroidHardwareSnapshotAsyncAction_generated_h
#error "GetAndroidHardwareSnapshotAsyncAction.generated.h already included, missing '#pragma once' in GetAndroidHardwareSnapshotAsyncAction.h"
#endif
#define GENERICANDROIDFRAMEWORK_GetAndroidHardwareSnapshotAsyncAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UGetAndroidHardwareSnapshotAsyncAction;
struct FAndroidHardwareSnapshot;

// ********** Begin Delegate FOnAndroidHardwareSnapshotReady ***************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h_8_DELEGATE \
GENERICANDROIDFRAMEWORK_API void FOnAndroidHardwareSnapshotReady_DelegateWrapper(const FMulticastScriptDelegate& OnAndroidHardwareSnapshotReady, FAndroidHardwareSnapshot const& Snapshot);


// ********** End Delegate FOnAndroidHardwareSnapshotReady *****************************************

// ********** Begin Delegate FOnAndroidHardwareSnapshotFailed **************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h_9_DELEGATE \
GENERICANDROIDFRAMEWORK_API void FOnAndroidHardwareSnapshotFailed_DelegateWrapper(const FMulticastScriptDelegate& OnAndroidHardwareSnapshotFailed, const FString& ErrorMessage);


// ********** End Delegate FOnAndroidHardwareSnapshotFailed ****************************************

// ********** Begin Class UGetAndroidHardwareSnapshotAsyncAction ***********************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAsyncGetAndroidHardwareSnapshot);


struct Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics;
GENERICANDROIDFRAMEWORK_API UClass* Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGetAndroidHardwareSnapshotAsyncAction(); \
	friend struct ::Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICANDROIDFRAMEWORK_API UClass* ::Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UGetAndroidHardwareSnapshotAsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericAndroidFramework"), Z_Construct_UClass_UGetAndroidHardwareSnapshotAsyncAction_NoRegister) \
	DECLARE_SERIALIZER(UGetAndroidHardwareSnapshotAsyncAction)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICANDROIDFRAMEWORK_API UGetAndroidHardwareSnapshotAsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGetAndroidHardwareSnapshotAsyncAction(UGetAndroidHardwareSnapshotAsyncAction&&) = delete; \
	UGetAndroidHardwareSnapshotAsyncAction(const UGetAndroidHardwareSnapshotAsyncAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICANDROIDFRAMEWORK_API, UGetAndroidHardwareSnapshotAsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGetAndroidHardwareSnapshotAsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGetAndroidHardwareSnapshotAsyncAction) \
	GENERICANDROIDFRAMEWORK_API virtual ~UGetAndroidHardwareSnapshotAsyncAction();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h_12_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h_15_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGetAndroidHardwareSnapshotAsyncAction;

// ********** End Class UGetAndroidHardwareSnapshotAsyncAction *************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_GetAndroidHardwareSnapshotAsyncAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
