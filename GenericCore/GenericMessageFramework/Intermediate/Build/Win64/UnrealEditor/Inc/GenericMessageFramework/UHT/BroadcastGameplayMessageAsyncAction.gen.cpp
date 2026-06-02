// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "AsyncAction/BroadcastGameplayMessageAsyncAction.h"
#include "GameplayTagContainer.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeBroadcastGameplayMessageAsyncAction() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UCancellableAsyncAction();
GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
GENERICMESSAGEFRAMEWORK_API UClass* Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction();
GENERICMESSAGEFRAMEWORK_API UClass* Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_NoRegister();
GENERICMESSAGEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericMessageFramework_BroadcastGameplayMessageAsyncDelegate__DelegateSignature();
UPackage* Z_Construct_UPackage__Script_GenericMessageFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Delegate FBroadcastGameplayMessageAsyncDelegate ********************************
struct Z_Construct_UDelegateFunction_GenericMessageFramework_BroadcastGameplayMessageAsyncDelegate__DelegateSignature_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/AsyncAction/BroadcastGameplayMessageAsyncAction.h" },
	};
#endif // WITH_METADATA

// ********** Begin Delegate FBroadcastGameplayMessageAsyncDelegate constinit property declarations 
// ********** End Delegate FBroadcastGameplayMessageAsyncDelegate constinit property declarations **
	static const UECodeGen_Private::FDelegateFunctionParams FuncParams;
};
const UECodeGen_Private::FDelegateFunctionParams Z_Construct_UDelegateFunction_GenericMessageFramework_BroadcastGameplayMessageAsyncDelegate__DelegateSignature_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UPackage__Script_GenericMessageFramework, nullptr, "BroadcastGameplayMessageAsyncDelegate__DelegateSignature", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GenericMessageFramework_BroadcastGameplayMessageAsyncDelegate__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GenericMessageFramework_BroadcastGameplayMessageAsyncDelegate__DelegateSignature_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UDelegateFunction_GenericMessageFramework_BroadcastGameplayMessageAsyncDelegate__DelegateSignature()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUDelegateFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GenericMessageFramework_BroadcastGameplayMessageAsyncDelegate__DelegateSignature_Statics::FuncParams);
	}
	return ReturnFunction;
}
void FBroadcastGameplayMessageAsyncDelegate_DelegateWrapper(const FMulticastScriptDelegate& BroadcastGameplayMessageAsyncDelegate)
{
	BroadcastGameplayMessageAsyncDelegate.ProcessMulticastDelegate<UObject>(NULL);
}
// ********** End Delegate FBroadcastGameplayMessageAsyncDelegate **********************************

// ********** Begin Class UBroadcastGameplayMessageAsyncAction Function BroadcastGameplayMessage ***
struct Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics
{
	struct BroadcastGameplayMessageAsyncAction_eventBroadcastGameplayMessage_Parms
	{
		UObject* WorldContextObject;
		FGameplayTag Channel;
		int32 Message;
		UBroadcastGameplayMessageAsyncAction* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Messaging" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb9\xbf\xe6\x92\xadGameplay\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82 */" },
#endif
		{ "CustomStructureParam", "Message" },
		{ "CustomThunk", "true" },
		{ "ModuleRelativePath", "Public/AsyncAction/BroadcastGameplayMessageAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb9\xbf\xe6\x92\xadGameplay\xe6\xb6\x88\xe6\x81\xaf\xe3\x80\x82" },
#endif
		{ "WorldContext", "WorldContextObject" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Message_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function BroadcastGameplayMessage constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Channel;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Message;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function BroadcastGameplayMessage constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function BroadcastGameplayMessage Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BroadcastGameplayMessageAsyncAction_eventBroadcastGameplayMessage_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::NewProp_Channel = { "Channel", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BroadcastGameplayMessageAsyncAction_eventBroadcastGameplayMessage_Parms, Channel), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 517357616
const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BroadcastGameplayMessageAsyncAction_eventBroadcastGameplayMessage_Parms, Message), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Message_MetaData), NewProp_Message_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BroadcastGameplayMessageAsyncAction_eventBroadcastGameplayMessage_Parms, ReturnValue), Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::NewProp_WorldContextObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::NewProp_Channel,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::NewProp_Message,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::PropPointers) < 2048);
// ********** End Function BroadcastGameplayMessage Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction, nullptr, "BroadcastGameplayMessage", 	Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::BroadcastGameplayMessageAsyncAction_eventBroadcastGameplayMessage_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422403, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::Function_MetaDataParams), Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::BroadcastGameplayMessageAsyncAction_eventBroadcastGameplayMessage_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage_Statics::FuncParams);
	}
	return ReturnFunction;
}
// ********** End Class UBroadcastGameplayMessageAsyncAction Function BroadcastGameplayMessage *****

// ********** Begin Class UBroadcastGameplayMessageAsyncAction *************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UBroadcastGameplayMessageAsyncAction;
UClass* UBroadcastGameplayMessageAsyncAction::GetPrivateStaticClass()
{
	using TClass = UBroadcastGameplayMessageAsyncAction;
	if (!Z_Registration_Info_UClass_UBroadcastGameplayMessageAsyncAction.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("BroadcastGameplayMessageAsyncAction"),
			Z_Registration_Info_UClass_UBroadcastGameplayMessageAsyncAction.InnerSingleton,
			StaticRegisterNativesUBroadcastGameplayMessageAsyncAction,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UBroadcastGameplayMessageAsyncAction.InnerSingleton;
}
UClass* Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_NoRegister()
{
	return UBroadcastGameplayMessageAsyncAction::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xb9\xbf\xe6\x92\xadGameplay\xe6\xb6\x88\xe6\x81\xaf\xe5\xbc\x82\xe6\xad\xa5\xe6\x93\x8d\xe4\xbd\x9c\xe7\xb1\xbb\xe3\x80\x82 */" },
#endif
		{ "HasDedicatedAsyncNode", "" },
		{ "IncludePath", "AsyncAction/BroadcastGameplayMessageAsyncAction.h" },
		{ "ModuleRelativePath", "Public/AsyncAction/BroadcastGameplayMessageAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xb9\xbf\xe6\x92\xadGameplay\xe6\xb6\x88\xe6\x81\xaf\xe5\xbc\x82\xe6\xad\xa5\xe6\x93\x8d\xe4\xbd\x9c\xe7\xb1\xbb\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Completed_MetaData[] = {
		{ "Category", "Events" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xb0\xe5\xbd\x95""Completed\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/AsyncAction/BroadcastGameplayMessageAsyncAction.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xb0\xe5\xbd\x95""Completed\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UBroadcastGameplayMessageAsyncAction constinit property declarations *****
	static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_Completed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UBroadcastGameplayMessageAsyncAction constinit property declarations *******
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("BroadcastGameplayMessage"), .Pointer = &UBroadcastGameplayMessageAsyncAction::execBroadcastGameplayMessage },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UBroadcastGameplayMessageAsyncAction_BroadcastGameplayMessage, "BroadcastGameplayMessage" }, // 1083108068
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBroadcastGameplayMessageAsyncAction>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics

// ********** Begin Class UBroadcastGameplayMessageAsyncAction Property Definitions ****************
const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::NewProp_Completed = { "Completed", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBroadcastGameplayMessageAsyncAction, Completed), Z_Construct_UDelegateFunction_GenericMessageFramework_BroadcastGameplayMessageAsyncDelegate__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Completed_MetaData), NewProp_Completed_MetaData) }; // 3784585965
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::NewProp_Completed,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::PropPointers) < 2048);
// ********** End Class UBroadcastGameplayMessageAsyncAction Property Definitions ******************
UObject* (*const Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UCancellableAsyncAction,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericMessageFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::ClassParams = {
	&UBroadcastGameplayMessageAsyncAction::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::PropPointers),
	0,
	0x008800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::Class_MetaDataParams), Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::Class_MetaDataParams)
};
void UBroadcastGameplayMessageAsyncAction::StaticRegisterNativesUBroadcastGameplayMessageAsyncAction()
{
	UClass* Class = UBroadcastGameplayMessageAsyncAction::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::Funcs));
}
UClass* Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction()
{
	if (!Z_Registration_Info_UClass_UBroadcastGameplayMessageAsyncAction.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBroadcastGameplayMessageAsyncAction.OuterSingleton, Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBroadcastGameplayMessageAsyncAction.OuterSingleton;
}
UBroadcastGameplayMessageAsyncAction::UBroadcastGameplayMessageAsyncAction(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UBroadcastGameplayMessageAsyncAction);
UBroadcastGameplayMessageAsyncAction::~UBroadcastGameplayMessageAsyncAction() {}
// ********** End Class UBroadcastGameplayMessageAsyncAction ***************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h__Script_GenericMessageFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBroadcastGameplayMessageAsyncAction, UBroadcastGameplayMessageAsyncAction::StaticClass, TEXT("UBroadcastGameplayMessageAsyncAction"), &Z_Registration_Info_UClass_UBroadcastGameplayMessageAsyncAction, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBroadcastGameplayMessageAsyncAction), 2866467631U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h__Script_GenericMessageFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h__Script_GenericMessageFramework_2550880865{
	TEXT("/Script/GenericMessageFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h__Script_GenericMessageFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericMessageFramework_Source_GenericMessageFramework_Public_AsyncAction_BroadcastGameplayMessageAsyncAction_h__Script_GenericMessageFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
