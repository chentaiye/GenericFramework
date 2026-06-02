// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "UWidget/GenericAnimatedSwitcher.h"

#ifdef GENERICSLATEFRAMEWORK_GenericAnimatedSwitcher_generated_h
#error "GenericAnimatedSwitcher.generated.h already included, missing '#pragma once' in GenericAnimatedSwitcher.h"
#endif
#define GENERICSLATEFRAMEWORK_GenericAnimatedSwitcher_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UWidget;

// ********** Begin Delegate FOnActiveIndexChangedFinish *******************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h_13_DELEGATE \
GENERICSLATEFRAMEWORK_API void FOnActiveIndexChangedFinish_DelegateWrapper(const FMulticastScriptDelegate& OnActiveIndexChangedFinish, UWidget* ActiveWidget, int32 ActiveIndex);


// ********** End Delegate FOnActiveIndexChangedFinish *********************************************

// ********** Begin Delegate FOnGenericAnimatedSwitcherActiveIndexChangedDelegate ******************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h_14_DELEGATE \
GENERICSLATEFRAMEWORK_API void FOnGenericAnimatedSwitcherActiveIndexChangedDelegate_DelegateWrapper(const FMulticastScriptDelegate& OnGenericAnimatedSwitcherActiveIndexChangedDelegate, UWidget* ActiveWidget, int32 ActiveIndex);


// ********** End Delegate FOnGenericAnimatedSwitcherActiveIndexChangedDelegate ********************

// ********** Begin Class UGenericAnimatedSwitcher *************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetPendingActiveWidgetIndex); \
	DECLARE_FUNCTION(execGetPendingActiveWidget); \
	DECLARE_FUNCTION(execIsTransitionPlaying); \
	DECLARE_FUNCTION(execIsCurrentlySwitching); \
	DECLARE_FUNCTION(execSetDisableTransitionAnimation); \
	DECLARE_FUNCTION(execHasWidgets); \
	DECLARE_FUNCTION(execActivatePreviousWidget); \
	DECLARE_FUNCTION(execActivateNextWidget);


struct Z_Construct_UClass_UGenericAnimatedSwitcher_Statics;
GENERICSLATEFRAMEWORK_API UClass* Z_Construct_UClass_UGenericAnimatedSwitcher_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGenericAnimatedSwitcher(); \
	friend struct ::Z_Construct_UClass_UGenericAnimatedSwitcher_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICSLATEFRAMEWORK_API UClass* ::Z_Construct_UClass_UGenericAnimatedSwitcher_NoRegister(); \
public: \
	DECLARE_CLASS2(UGenericAnimatedSwitcher, UWidgetSwitcher, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GenericSlateFramework"), Z_Construct_UClass_UGenericAnimatedSwitcher_NoRegister) \
	DECLARE_SERIALIZER(UGenericAnimatedSwitcher)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h_20_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	UGenericAnimatedSwitcher(UGenericAnimatedSwitcher&&) = delete; \
	UGenericAnimatedSwitcher(const UGenericAnimatedSwitcher&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICSLATEFRAMEWORK_API, UGenericAnimatedSwitcher); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGenericAnimatedSwitcher); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGenericAnimatedSwitcher) \
	GENERICSLATEFRAMEWORK_API virtual ~UGenericAnimatedSwitcher();


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h_17_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h_20_INCLASS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UGenericAnimatedSwitcher;

// ********** End Class UGenericAnimatedSwitcher ***************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_UWidget_GenericAnimatedSwitcher_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
