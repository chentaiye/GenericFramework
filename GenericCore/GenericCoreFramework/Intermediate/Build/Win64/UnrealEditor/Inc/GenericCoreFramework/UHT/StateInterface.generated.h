// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Interface/StateInterface.h"

#ifdef GENERICCOREFRAMEWORK_StateInterface_generated_h
#error "StateInterface.generated.h already included, missing '#pragma once' in StateInterface.h"
#endif
#define GENERICCOREFRAMEWORK_StateInterface_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Interface UStateInterface ******************************************************
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void HandleOnDestroy_Implementation() {}; \
	virtual void HandleOnInactivedFinish_Implementation() {}; \
	virtual void HandleOnInactived_Implementation() {}; \
	virtual void HandleOnActivedFinish_Implementation() {}; \
	virtual void HandleOnActived_Implementation() {}; \
	virtual void HandleOnCreate_Implementation() {}; \
	DECLARE_FUNCTION(execHandleOnDestroy); \
	DECLARE_FUNCTION(execHandleOnInactivedFinish); \
	DECLARE_FUNCTION(execHandleOnInactived); \
	DECLARE_FUNCTION(execHandleOnActivedFinish); \
	DECLARE_FUNCTION(execHandleOnActived); \
	DECLARE_FUNCTION(execHandleOnCreate);


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_CALLBACK_WRAPPERS
struct Z_Construct_UClass_UStateInterface_Statics;
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UStateInterface_NoRegister();

#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	GENERICCOREFRAMEWORK_API UStateInterface(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UStateInterface(UStateInterface&&) = delete; \
	UStateInterface(const UStateInterface&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(GENERICCOREFRAMEWORK_API, UStateInterface); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UStateInterface); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UStateInterface) \
	virtual ~UStateInterface() = default;


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_GENERATED_UINTERFACE_BODY() \
private: \
	static void StaticRegisterNativesUStateInterface(); \
	friend struct ::Z_Construct_UClass_UStateInterface_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend GENERICCOREFRAMEWORK_API UClass* ::Z_Construct_UClass_UStateInterface_NoRegister(); \
public: \
	DECLARE_CLASS2(UStateInterface, UInterface, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Interface), CASTCLASS_None, TEXT("/Script/GenericCoreFramework"), Z_Construct_UClass_UStateInterface_NoRegister) \
	DECLARE_SERIALIZER(UStateInterface)


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_GENERATED_BODY \
	PRAGMA_DISABLE_DEPRECATION_WARNINGS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_GENERATED_UINTERFACE_BODY() \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_ENHANCED_CONSTRUCTORS \
private: \
	PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
protected: \
	virtual ~IStateInterface() {} \
public: \
	typedef UStateInterface UClassType; \
	typedef IStateInterface ThisClass; \
	static void Execute_HandleOnActived(UObject* O); \
	static void Execute_HandleOnActivedFinish(UObject* O); \
	static void Execute_HandleOnCreate(UObject* O); \
	static void Execute_HandleOnDestroy(UObject* O); \
	static void Execute_HandleOnInactived(UObject* O); \
	static void Execute_HandleOnInactivedFinish(UObject* O); \
	virtual UObject* _getUObject() const { return nullptr; }


#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_13_PROLOG
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_CALLBACK_WRAPPERS \
	FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h_16_INCLASS_IINTERFACE_NO_PURE_DECLS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UStateInterface;

// ********** End Interface UStateInterface ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
