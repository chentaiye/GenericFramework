// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "AsyncFunctions/DesktopStringFileAsyncAction.h"

#ifdef GENERICDESKTOPFRAMEWORK_DesktopStringFileAsyncAction_generated_h
#error "DesktopStringFileAsyncAction.generated.h already included, missing '#pragma once' in DesktopStringFileAsyncAction.h"
#endif
#define GENERICDESKTOPFRAMEWORK_DesktopStringFileAsyncAction_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UDesktopStringFileAsyncAction;
enum class EDesktopTextEncodingOptions : uint8;
struct FDesktopStringResult;

// ********** Begin Delegate FOnDesktopStringFileCompleted *****************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h_8_DELEGATE \
GENERICDESKTOPFRAMEWORK_API void FOnDesktopStringFileCompleted_DelegateWrapper(const FMulticastScriptDelegate& OnDesktopStringFileCompleted, FDesktopStringResult const& Result);


// ********** End Delegate FOnDesktopStringFileCompleted *******************************************

// ********** Begin Class UDesktopStringFileAsyncAction ********************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execAsyncWriteStringToFile); \
	DECLARE_FUNCTION(execAsyncReadStringFromFile);


struct Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics;
GENERICDESKTOPFRAMEWORK_API UClass* Z_Construct_UClass_UDesktopStringFileAsyncAction_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDesktopStringFileAsyncAction(); \
	friend struct ::Z_Construct_UClass_UDesktopStringFileAsyncAction_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICDESKTOPFRAMEWORK_API UClass* ::Z_Construct_UClass_UDesktopStringFileAsyncAction_NoRegister(); \
public: \
	DECLARE_CLASS2(UDesktopStringFileAsyncAction, UBlueprintAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericDesktopFramework"), Z_Construct_UClass_UDesktopStringFileAsyncAction_NoRegister) \
	DECLARE_SERIALIZER(UDesktopStringFileAsyncAction)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICDESKTOPFRAMEWORK_API UDesktopStringFileAsyncAction(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UDesktopStringFileAsyncAction(UDesktopStringFileAsyncAction&&) = delete; \
	UDesktopStringFileAsyncAction(const UDesktopStringFileAsyncAction&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICDESKTOPFRAMEWORK_API, UDesktopStringFileAsyncAction); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDesktopStringFileAsyncAction); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDesktopStringFileAsyncAction) \
	GENERICDESKTOPFRAMEWORK_API virtual ~UDesktopStringFileAsyncAction();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h_11_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h_14_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UDesktopStringFileAsyncAction;

// ********** End Class UDesktopStringFileAsyncAction **********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericPlatform_GenericDesktop_GenericDesktopFramework_Source_GenericDesktopFramework_Public_AsyncFunctions_DesktopStringFileAsyncAction_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
