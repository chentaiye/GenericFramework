// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AsyncFunctions/AcquireAndroidPermissionAsyncAction.h"

#ifdef GENERICANDROIDFRAMEWORK_AcquireAndroidPermissionAsyncAction_generated_h
#error "AcquireAndroidPermissionAsyncAction.generated.h already included, missing '#pragma once' in AcquireAndroidPermissionAsyncAction.h"
#endif
#define GENERICANDROIDFRAMEWORK_AcquireAndroidPermissionAsyncAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UAcquireAndroidPermissionAsyncAction;

// ********** Begin Delegate FOnPermissionsGrantedSuccess ******************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h_7_DELEGATE \
GENERICANDROIDFRAMEWORK_API void FOnPermissionsGrantedSuccess_DelegateWrapper(const FMulticastScriptDelegate& OnPermissionsGrantedSuccess);


// ********** End Delegate FOnPermissionsGrantedSuccess ********************************************

// ********** Begin Delegate FOnPermissionsGrantedFail *********************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h_8_DELEGATE \
GENERICANDROIDFRAMEWORK_API void FOnPermissionsGrantedFail_DelegateWrapper(const FMulticastScriptDelegate& OnPermissionsGrantedFail, TArray<FString> const& FailPermissions);


// ********** End Delegate FOnPermissionsGrantedFail ***********************************************

// ********** Begin Class UAcquireAndroidPermissionAsyncAction *************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAsyncAcquireAndroidPermissions); \
	DECLARE_FUNCTION(execAsyncAcquireAndroidPermission);


struct Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics;
GENERICANDROIDFRAMEWORK_API UClass* Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUAcquireAndroidPermissionAsyncAction(); \
	friend struct ::Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICANDROIDFRAMEWORK_API UClass* ::Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UAcquireAndroidPermissionAsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericAndroidFramework"), Z_Construct_UClass_UAcquireAndroidPermissionAsyncAction_NoRegister) \
	DECLARE_SERIALIZER(UAcquireAndroidPermissionAsyncAction)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICANDROIDFRAMEWORK_API UAcquireAndroidPermissionAsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UAcquireAndroidPermissionAsyncAction(UAcquireAndroidPermissionAsyncAction&&) = delete; \
	UAcquireAndroidPermissionAsyncAction(const UAcquireAndroidPermissionAsyncAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICANDROIDFRAMEWORK_API, UAcquireAndroidPermissionAsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UAcquireAndroidPermissionAsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UAcquireAndroidPermissionAsyncAction) \
	GENERICANDROIDFRAMEWORK_API virtual ~UAcquireAndroidPermissionAsyncAction();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h_11_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h_14_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UAcquireAndroidPermissionAsyncAction;

// ********** End Class UAcquireAndroidPermissionAsyncAction ***************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericAndroid_GenericAndroidFramework_Source_GenericAndroidFramework_Public_AsyncFunctions_AcquireAndroidPermissionAsyncAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
