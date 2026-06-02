// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Interface/StateInterface.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeStateInterface() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UStateInterface();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UStateInterface_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericCoreFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Interface UStateInterface Function HandleOnActived *****************************
void IStateInterface::HandleOnActived()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_HandleOnActived instead.");
}
static FName NAME_UStateInterface_HandleOnActived = FName(TEXT("HandleOnActived"));
void IStateInterface::Execute_HandleOnActived(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UStateInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UStateInterface_HandleOnActived);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IStateInterface*)(O->GetNativeInterfaceAddress(UStateInterface::StaticClass())))
	{
		I->HandleOnActived_Implementation();
	}
}
struct Z_Construct_UFunction_UStateInterface_HandleOnActived_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State Interface" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xa7\xa6\xe5\x8f\x91\xe6\xbf\x80\xe6\xb4\xbb\xe9\x98\xb6\xe6\xae\xb5\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe5\xb9\xb6\xe4\xb8\xb2\xe8\x81\x94\xe6\xbf\x80\xe6\xb4\xbb\xe5\xae\x8c\xe6\x88\x90\xe9\x80\x9a\xe7\x9f\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Interface/StateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xa7\xa6\xe5\x8f\x91\xe6\xbf\x80\xe6\xb4\xbb\xe9\x98\xb6\xe6\xae\xb5\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe5\xb9\xb6\xe4\xb8\xb2\xe8\x81\x94\xe6\xbf\x80\xe6\xb4\xbb\xe5\xae\x8c\xe6\x88\x90\xe9\x80\x9a\xe7\x9f\xa5\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HandleOnActived constinit property declarations ***********************
// ********** End Function HandleOnActived constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateInterface_HandleOnActived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UStateInterface, nullptr, "HandleOnActived", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateInterface_HandleOnActived_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateInterface_HandleOnActived_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UStateInterface_HandleOnActived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateInterface_HandleOnActived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IStateInterface::execHandleOnActived)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOnActived_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UStateInterface Function HandleOnActived *******************************

// ********** Begin Interface UStateInterface Function HandleOnActivedFinish ***********************
void IStateInterface::HandleOnActivedFinish()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_HandleOnActivedFinish instead.");
}
static FName NAME_UStateInterface_HandleOnActivedFinish = FName(TEXT("HandleOnActivedFinish"));
void IStateInterface::Execute_HandleOnActivedFinish(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UStateInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UStateInterface_HandleOnActivedFinish);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IStateInterface*)(O->GetNativeInterfaceAddress(UStateInterface::StaticClass())))
	{
		I->HandleOnActivedFinish_Implementation();
	}
}
struct Z_Construct_UFunction_UStateInterface_HandleOnActivedFinish_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State Interface" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xa7\xa6\xe5\x8f\x91\xe6\xbf\x80\xe6\xb4\xbb\xe5\xae\x8c\xe6\x88\x90\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe9\x80\x9a\xe7\x9f\xa5\xe5\xa4\x96\xe9\x83\xa8\xe7\x8a\xb6\xe6\x80\x81\xe5\x88\x87\xe6\x8d\xa2\xe5\xb7\xb2\xe7\xbb\x8f\xe7\xbb\x93\xe6\x9d\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Interface/StateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xa7\xa6\xe5\x8f\x91\xe6\xbf\x80\xe6\xb4\xbb\xe5\xae\x8c\xe6\x88\x90\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe9\x80\x9a\xe7\x9f\xa5\xe5\xa4\x96\xe9\x83\xa8\xe7\x8a\xb6\xe6\x80\x81\xe5\x88\x87\xe6\x8d\xa2\xe5\xb7\xb2\xe7\xbb\x8f\xe7\xbb\x93\xe6\x9d\x9f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HandleOnActivedFinish constinit property declarations *****************
// ********** End Function HandleOnActivedFinish constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateInterface_HandleOnActivedFinish_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UStateInterface, nullptr, "HandleOnActivedFinish", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateInterface_HandleOnActivedFinish_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateInterface_HandleOnActivedFinish_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UStateInterface_HandleOnActivedFinish()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateInterface_HandleOnActivedFinish_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IStateInterface::execHandleOnActivedFinish)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOnActivedFinish_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UStateInterface Function HandleOnActivedFinish *************************

// ********** Begin Interface UStateInterface Function HandleOnCreate ******************************
void IStateInterface::HandleOnCreate()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_HandleOnCreate instead.");
}
static FName NAME_UStateInterface_HandleOnCreate = FName(TEXT("HandleOnCreate"));
void IStateInterface::Execute_HandleOnCreate(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UStateInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UStateInterface_HandleOnCreate);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IStateInterface*)(O->GetNativeInterfaceAddress(UStateInterface::StaticClass())))
	{
		I->HandleOnCreate_Implementation();
	}
}
struct Z_Construct_UFunction_UStateInterface_HandleOnCreate_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State Interface" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xa7\xa6\xe5\x8f\x91\xe5\x88\x9b\xe5\xbb\xba\xe9\x98\xb6\xe6\xae\xb5\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe4\xbd\x9c\xe4\xb8\xba\xe5\xaf\xb9\xe8\xb1\xa1\xe8\xbf\x9b\xe5\x85\xa5\xe7\x8a\xb6\xe6\x80\x81\xe6\x9c\xba\xe6\x97\xb6\xe7\x9a\x84\xe5\xa4\x96\xe9\x83\xa8\xe9\x80\x9a\xe7\x9f\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Interface/StateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xa7\xa6\xe5\x8f\x91\xe5\x88\x9b\xe5\xbb\xba\xe9\x98\xb6\xe6\xae\xb5\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe4\xbd\x9c\xe4\xb8\xba\xe5\xaf\xb9\xe8\xb1\xa1\xe8\xbf\x9b\xe5\x85\xa5\xe7\x8a\xb6\xe6\x80\x81\xe6\x9c\xba\xe6\x97\xb6\xe7\x9a\x84\xe5\xa4\x96\xe9\x83\xa8\xe9\x80\x9a\xe7\x9f\xa5\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HandleOnCreate constinit property declarations ************************
// ********** End Function HandleOnCreate constinit property declarations **************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateInterface_HandleOnCreate_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UStateInterface, nullptr, "HandleOnCreate", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateInterface_HandleOnCreate_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateInterface_HandleOnCreate_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UStateInterface_HandleOnCreate()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateInterface_HandleOnCreate_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IStateInterface::execHandleOnCreate)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOnCreate_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UStateInterface Function HandleOnCreate ********************************

// ********** Begin Interface UStateInterface Function HandleOnDestroy *****************************
void IStateInterface::HandleOnDestroy()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_HandleOnDestroy instead.");
}
static FName NAME_UStateInterface_HandleOnDestroy = FName(TEXT("HandleOnDestroy"));
void IStateInterface::Execute_HandleOnDestroy(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UStateInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UStateInterface_HandleOnDestroy);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IStateInterface*)(O->GetNativeInterfaceAddress(UStateInterface::StaticClass())))
	{
		I->HandleOnDestroy_Implementation();
	}
}
struct Z_Construct_UFunction_UStateInterface_HandleOnDestroy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State Interface" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xa7\xa6\xe5\x8f\x91\xe9\x94\x80\xe6\xaf\x81\xe9\x98\xb6\xe6\xae\xb5\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe8\xae\xa9\xe7\x8a\xb6\xe6\x80\x81\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x9c\xa8\xe9\x87\x8a\xe6\x94\xbe\xe5\x89\x8d\xe5\xae\x8c\xe6\x88\x90\xe5\xa4\x96\xe9\x83\xa8\xe9\x80\x9a\xe7\x9f\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Interface/StateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xa7\xa6\xe5\x8f\x91\xe9\x94\x80\xe6\xaf\x81\xe9\x98\xb6\xe6\xae\xb5\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe8\xae\xa9\xe7\x8a\xb6\xe6\x80\x81\xe5\xaf\xb9\xe8\xb1\xa1\xe5\x9c\xa8\xe9\x87\x8a\xe6\x94\xbe\xe5\x89\x8d\xe5\xae\x8c\xe6\x88\x90\xe5\xa4\x96\xe9\x83\xa8\xe9\x80\x9a\xe7\x9f\xa5\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HandleOnDestroy constinit property declarations ***********************
// ********** End Function HandleOnDestroy constinit property declarations *************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateInterface_HandleOnDestroy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UStateInterface, nullptr, "HandleOnDestroy", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateInterface_HandleOnDestroy_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateInterface_HandleOnDestroy_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UStateInterface_HandleOnDestroy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateInterface_HandleOnDestroy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IStateInterface::execHandleOnDestroy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOnDestroy_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UStateInterface Function HandleOnDestroy *******************************

// ********** Begin Interface UStateInterface Function HandleOnInactived ***************************
void IStateInterface::HandleOnInactived()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_HandleOnInactived instead.");
}
static FName NAME_UStateInterface_HandleOnInactived = FName(TEXT("HandleOnInactived"));
void IStateInterface::Execute_HandleOnInactived(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UStateInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UStateInterface_HandleOnInactived);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IStateInterface*)(O->GetNativeInterfaceAddress(UStateInterface::StaticClass())))
	{
		I->HandleOnInactived_Implementation();
	}
}
struct Z_Construct_UFunction_UStateInterface_HandleOnInactived_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State Interface" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xa7\xa6\xe5\x8f\x91\xe5\xa4\xb1\xe6\xb4\xbb\xe9\x98\xb6\xe6\xae\xb5\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe5\xb9\xb6\xe4\xb8\xb2\xe8\x81\x94\xe5\xa4\xb1\xe6\xb4\xbb\xe5\xae\x8c\xe6\x88\x90\xe9\x80\x9a\xe7\x9f\xa5\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Interface/StateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xa7\xa6\xe5\x8f\x91\xe5\xa4\xb1\xe6\xb4\xbb\xe9\x98\xb6\xe6\xae\xb5\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe5\xb9\xb6\xe4\xb8\xb2\xe8\x81\x94\xe5\xa4\xb1\xe6\xb4\xbb\xe5\xae\x8c\xe6\x88\x90\xe9\x80\x9a\xe7\x9f\xa5\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HandleOnInactived constinit property declarations *********************
// ********** End Function HandleOnInactived constinit property declarations ***********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateInterface_HandleOnInactived_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UStateInterface, nullptr, "HandleOnInactived", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateInterface_HandleOnInactived_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateInterface_HandleOnInactived_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UStateInterface_HandleOnInactived()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateInterface_HandleOnInactived_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IStateInterface::execHandleOnInactived)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOnInactived_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UStateInterface Function HandleOnInactived *****************************

// ********** Begin Interface UStateInterface Function HandleOnInactivedFinish *********************
void IStateInterface::HandleOnInactivedFinish()
{
	check(0 && "Do not directly call Event functions in Interfaces. Call Execute_HandleOnInactivedFinish instead.");
}
static FName NAME_UStateInterface_HandleOnInactivedFinish = FName(TEXT("HandleOnInactivedFinish"));
void IStateInterface::Execute_HandleOnInactivedFinish(UObject* O)
{
	check(O != NULL);
	check(O->GetClass()->ImplementsInterface(UStateInterface::StaticClass()));
	UFunction* const Func = O->FindFunction(NAME_UStateInterface_HandleOnInactivedFinish);
	if (Func)
	{
		O->ProcessEvent(Func, NULL);
	}
	else if (auto I = (IStateInterface*)(O->GetNativeInterfaceAddress(UStateInterface::StaticClass())))
	{
		I->HandleOnInactivedFinish_Implementation();
	}
}
struct Z_Construct_UFunction_UStateInterface_HandleOnInactivedFinish_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "State Interface" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xa7\xa6\xe5\x8f\x91\xe5\xa4\xb1\xe6\xb4\xbb\xe5\xae\x8c\xe6\x88\x90\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe9\x80\x9a\xe7\x9f\xa5\xe5\xa4\x96\xe9\x83\xa8\xe7\x8a\xb6\xe6\x80\x81\xe5\x88\x87\xe6\x8d\xa2\xe5\xb7\xb2\xe7\xbb\x8f\xe7\xbb\x93\xe6\x9d\x9f\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/Interface/StateInterface.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xa7\xa6\xe5\x8f\x91\xe5\xa4\xb1\xe6\xb4\xbb\xe5\xae\x8c\xe6\x88\x90\xe8\x93\x9d\xe5\x9b\xbe\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe9\x80\x9a\xe7\x9f\xa5\xe5\xa4\x96\xe9\x83\xa8\xe7\x8a\xb6\xe6\x80\x81\xe5\x88\x87\xe6\x8d\xa2\xe5\xb7\xb2\xe7\xbb\x8f\xe7\xbb\x93\xe6\x9d\x9f\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function HandleOnInactivedFinish constinit property declarations ***************
// ********** End Function HandleOnInactivedFinish constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStateInterface_HandleOnInactivedFinish_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UStateInterface, nullptr, "HandleOnInactivedFinish", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStateInterface_HandleOnInactivedFinish_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStateInterface_HandleOnInactivedFinish_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UStateInterface_HandleOnInactivedFinish()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStateInterface_HandleOnInactivedFinish_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(IStateInterface::execHandleOnInactivedFinish)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->HandleOnInactivedFinish_Implementation();
	P_NATIVE_END;
}
// ********** End Interface UStateInterface Function HandleOnInactivedFinish ***********************

// ********** Begin Interface UStateInterface ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UStateInterface;
UClass* UStateInterface::GetPrivateStaticClass()
{
	using TClass = UStateInterface;
	if (!Z_Registration_Info_UClass_UStateInterface.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("StateInterface"),
			Z_Registration_Info_UClass_UStateInterface.InnerSingleton,
			StaticRegisterNativesUStateInterface,
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
	return Z_Registration_Info_UClass_UStateInterface.InnerSingleton;
}
UClass* Z_Construct_UClass_UStateInterface_NoRegister()
{
	return UStateInterface::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UStateInterface_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Interface/StateInterface.h" },
	};
#endif // WITH_METADATA

// ********** Begin Interface UStateInterface constinit property declarations **********************
// ********** End Interface UStateInterface constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("HandleOnActived"), .Pointer = &IStateInterface::execHandleOnActived },
		{ .NameUTF8 = UTF8TEXT("HandleOnActivedFinish"), .Pointer = &IStateInterface::execHandleOnActivedFinish },
		{ .NameUTF8 = UTF8TEXT("HandleOnCreate"), .Pointer = &IStateInterface::execHandleOnCreate },
		{ .NameUTF8 = UTF8TEXT("HandleOnDestroy"), .Pointer = &IStateInterface::execHandleOnDestroy },
		{ .NameUTF8 = UTF8TEXT("HandleOnInactived"), .Pointer = &IStateInterface::execHandleOnInactived },
		{ .NameUTF8 = UTF8TEXT("HandleOnInactivedFinish"), .Pointer = &IStateInterface::execHandleOnInactivedFinish },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UStateInterface_HandleOnActived, "HandleOnActived" }, // 3553492149
		{ &Z_Construct_UFunction_UStateInterface_HandleOnActivedFinish, "HandleOnActivedFinish" }, // 3816627396
		{ &Z_Construct_UFunction_UStateInterface_HandleOnCreate, "HandleOnCreate" }, // 1389335886
		{ &Z_Construct_UFunction_UStateInterface_HandleOnDestroy, "HandleOnDestroy" }, // 2289432831
		{ &Z_Construct_UFunction_UStateInterface_HandleOnInactived, "HandleOnInactived" }, // 3909704960
		{ &Z_Construct_UFunction_UStateInterface_HandleOnInactivedFinish, "HandleOnInactivedFinish" }, // 2219592839
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IStateInterface>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UStateInterface_Statics
UObject* (*const Z_Construct_UClass_UStateInterface_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UInterface,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericCoreFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStateInterface_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStateInterface_Statics::ClassParams = {
	&UStateInterface::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x000840A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStateInterface_Statics::Class_MetaDataParams), Z_Construct_UClass_UStateInterface_Statics::Class_MetaDataParams)
};
void UStateInterface::StaticRegisterNativesUStateInterface()
{
	UClass* Class = UStateInterface::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UStateInterface_Statics::Funcs));
}
UClass* Z_Construct_UClass_UStateInterface()
{
	if (!Z_Registration_Info_UClass_UStateInterface.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStateInterface.OuterSingleton, Z_Construct_UClass_UStateInterface_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStateInterface.OuterSingleton;
}
UStateInterface::UStateInterface(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UStateInterface);
// ********** End Interface UStateInterface ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h__Script_GenericCoreFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UStateInterface, UStateInterface::StaticClass, TEXT("UStateInterface"), &Z_Registration_Info_UClass_UStateInterface, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStateInterface), 3785139515U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h__Script_GenericCoreFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h__Script_GenericCoreFramework_2062120841{
	TEXT("/Script/GenericCoreFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h__Script_GenericCoreFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericCoreFramework_Public_Interface_StateInterface_h__Script_GenericCoreFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
