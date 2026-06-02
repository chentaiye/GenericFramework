// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "WorldSettings/GenericWorldSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeGenericWorldSettings() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UWorld_NoRegister();
GENERICCOREFRAMEWORK_API UClass* Z_Construct_UClass_UGenericObject();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettings();
GENERICSETTINGSFRAMEWORK_API UClass* Z_Construct_UClass_UGenericWorldSettings_NoRegister();
UPackage* Z_Construct_UPackage__Script_GenericSettingsFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UGenericWorldSettings Function GetSettingsCategory ***********************
#if WITH_EDITOR
struct GenericWorldSettings_eventGetSettingsCategory_Parms
{
	FName ReturnValue;
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_GetSettingsCategory = FName(TEXT("GetSettingsCategory"));
FName UGenericWorldSettings::GetSettingsCategory() const
{
	GenericWorldSettings_eventGetSettingsCategory_Parms Parms;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_GetSettingsCategory);
		const_cast<UGenericWorldSettings*>(this)->ProcessEvent(Func,&Parms);
	return Parms.ReturnValue;
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x94\xe5\x9b\x9e\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\xb7\xa6\xe4\xbe\xa7\xe5\x88\x86\xe7\xbb\x84\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe5\x88\x86\xe7\xb1\xbb\xe5\x90\x8d\xef\xbc\x8c\xe6\x9c\xaa\xe8\xae\xbe\xe7\xbd\xae\xe6\x97\xb6\xe5\x9b\x9e\xe8\x90\xbd\xe5\x88\xb0 Default\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x94\xe5\x9b\x9e\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\xb7\xa6\xe4\xbe\xa7\xe5\x88\x86\xe7\xbb\x84\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe5\x88\x86\xe7\xb1\xbb\xe5\x90\x8d\xef\xbc\x8c\xe6\x9c\xaa\xe8\xae\xbe\xe7\xbd\xae\xe6\x97\xb6\xe5\x9b\x9e\xe8\x90\xbd\xe5\x88\xb0 Default\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSettingsCategory constinit property declarations *******************
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSettingsCategory constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSettingsCategory Property Definitions ******************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventGetSettingsCategory_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics::PropPointers) < 2048);
// ********** End Function GetSettingsCategory Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "GetSettingsCategory", 	Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventGetSettingsCategory_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x7C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventGetSettingsCategory_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execGetSettingsCategory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FName*)Z_Param__Result=P_THIS->GetSettingsCategory_Implementation();
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function GetSettingsCategory *************************

// ********** Begin Class UGenericWorldSettings Function GetSettingsDescription ********************
#if WITH_EDITOR
struct GenericWorldSettings_eventGetSettingsDescription_Parms
{
	FText ReturnValue;
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_GetSettingsDescription = FName(TEXT("GetSettingsDescription"));
FText UGenericWorldSettings::GetSettingsDescription() const
{
	GenericWorldSettings_eventGetSettingsDescription_Parms Parms;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_GetSettingsDescription);
		const_cast<UGenericWorldSettings*>(this)->ProcessEvent(Func,&Parms);
	return Parms.ReturnValue;
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x94\xe5\x9b\x9e\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe7\xae\xa1\xe7\x90\x86\xe7\x95\x8c\xe9\x9d\xa2\xe7\x94\xa8\xe4\xba\x8e\xe8\xa7\xa3\xe9\x87\x8a\xe8\xae\xbe\xe7\xbd\xae\xe7\x94\xa8\xe9\x80\x94\xe7\x9a\x84\xe6\x8f\x8f\xe8\xbf\xb0\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x94\xe5\x9b\x9e\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe7\xae\xa1\xe7\x90\x86\xe7\x95\x8c\xe9\x9d\xa2\xe7\x94\xa8\xe4\xba\x8e\xe8\xa7\xa3\xe9\x87\x8a\xe8\xae\xbe\xe7\xbd\xae\xe7\x94\xa8\xe9\x80\x94\xe7\x9a\x84\xe6\x8f\x8f\xe8\xbf\xb0\xe6\x96\x87\xe6\x9c\xac\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSettingsDescription constinit property declarations ****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSettingsDescription constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSettingsDescription Property Definitions ***************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventGetSettingsDescription_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics::PropPointers) < 2048);
// ********** End Function GetSettingsDescription Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "GetSettingsDescription", 	Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventGetSettingsDescription_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x7C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventGetSettingsDescription_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execGetSettingsDescription)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetSettingsDescription_Implementation();
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function GetSettingsDescription **********************

// ********** Begin Class UGenericWorldSettings Function GetSettingsDisplayName ********************
#if WITH_EDITOR
struct GenericWorldSettings_eventGetSettingsDisplayName_Parms
{
	FText ReturnValue;
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_GetSettingsDisplayName = FName(TEXT("GetSettingsDisplayName"));
FText UGenericWorldSettings::GetSettingsDisplayName() const
{
	GenericWorldSettings_eventGetSettingsDisplayName_Parms Parms;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_GetSettingsDisplayName);
		const_cast<UGenericWorldSettings*>(this)->ProcessEvent(Func,&Parms);
	return Parms.ReturnValue;
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x94\xe5\x9b\x9e\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe7\xae\xa1\xe7\x90\x86\xe7\x95\x8c\xe9\x9d\xa2\xe5\xb7\xa6\xe4\xbe\xa7\xe5\x88\x97\xe8\xa1\xa8\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x8c\xe9\xbb\x98\xe8\xae\xa4\xe4\xbd\xbf\xe7\x94\xa8\xe7\xb1\xbb\xe6\x98\xbe\xe7\xa4\xba\xe5\x90\x8d\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x94\xe5\x9b\x9e\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe7\xae\xa1\xe7\x90\x86\xe7\x95\x8c\xe9\x9d\xa2\xe5\xb7\xa6\xe4\xbe\xa7\xe5\x88\x97\xe8\xa1\xa8\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe5\x90\x8d\xe7\xa7\xb0\xef\xbc\x8c\xe9\xbb\x98\xe8\xae\xa4\xe4\xbd\xbf\xe7\x94\xa8\xe7\xb1\xbb\xe6\x98\xbe\xe7\xa4\xba\xe5\x90\x8d\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetSettingsDisplayName constinit property declarations ****************
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetSettingsDisplayName constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetSettingsDisplayName Property Definitions ***************************
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventGetSettingsDisplayName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics::PropPointers) < 2048);
// ********** End Function GetSettingsDisplayName Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "GetSettingsDisplayName", 	Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventGetSettingsDisplayName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x7C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventGetSettingsDisplayName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execGetSettingsDisplayName)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetSettingsDisplayName_Implementation();
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function GetSettingsDisplayName **********************

// ********** Begin Class UGenericWorldSettings Function GetWorldSettingsDisabledReason ************
#if WITH_EDITOR
struct GenericWorldSettings_eventGetWorldSettingsDisabledReason_Parms
{
	UWorld* World;
	FText ReturnValue;
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_GetWorldSettingsDisabledReason = FName(TEXT("GetWorldSettingsDisabledReason"));
FText UGenericWorldSettings::GetWorldSettingsDisabledReason(UWorld* World) const
{
	GenericWorldSettings_eventGetWorldSettingsDisabledReason_Parms Parms;
	Parms.World=World;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_GetWorldSettingsDisabledReason);
		const_cast<UGenericWorldSettings*>(this)->ProcessEvent(Func,&Parms);
	return Parms.ReturnValue;
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x94\xe5\x9b\x9e\xe8\xae\xbe\xe7\xbd\xae\xe5\x9c\xa8\xe5\xbd\x93\xe5\x89\x8d\xe7\xbc\x96\xe8\xbe\x91\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\x8b\xe5\xa4\xb1\xe6\x95\x88\xe7\x9a\x84\xe8\xaf\xb4\xe6\x98\x8e\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x8f\xb3\xe4\xbe\xa7\xe9\x9d\xa2\xe6\x9d\xbf\xe8\xa7\xa3\xe9\x87\x8a\xe4\xb8\xba\xe4\xbb\x80\xe4\xb9\x88\xe4\xb8\x8d\xe8\x83\xbd\xe7\xbc\x96\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x94\xe5\x9b\x9e\xe8\xae\xbe\xe7\xbd\xae\xe5\x9c\xa8\xe5\xbd\x93\xe5\x89\x8d\xe7\xbc\x96\xe8\xbe\x91\xe4\xb8\x96\xe7\x95\x8c\xe4\xb8\x8b\xe5\xa4\xb1\xe6\x95\x88\xe7\x9a\x84\xe8\xaf\xb4\xe6\x98\x8e\xe6\x96\x87\xe6\x9c\xac\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x8f\xb3\xe4\xbe\xa7\xe9\x9d\xa2\xe6\x9d\xbf\xe8\xa7\xa3\xe9\x87\x8a\xe4\xb8\xba\xe4\xbb\x80\xe4\xb9\x88\xe4\xb8\x8d\xe8\x83\xbd\xe7\xbc\x96\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function GetWorldSettingsDisabledReason constinit property declarations ********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FTextPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetWorldSettingsDisabledReason constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetWorldSettingsDisabledReason Property Definitions *******************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventGetWorldSettingsDisabledReason_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventGetWorldSettingsDisabledReason_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::NewProp_World,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::PropPointers) < 2048);
// ********** End Function GetWorldSettingsDisabledReason Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "GetWorldSettingsDisabledReason", 	Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventGetWorldSettingsDisabledReason_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x7C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventGetWorldSettingsDisabledReason_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execGetWorldSettingsDisabledReason)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(FText*)Z_Param__Result=P_THIS->GetWorldSettingsDisabledReason_Implementation(Z_Param_World);
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function GetWorldSettingsDisabledReason **************

// ********** Begin Class UGenericWorldSettings Function IsWorldSettingsEnabled ********************
#if WITH_EDITOR
struct GenericWorldSettings_eventIsWorldSettingsEnabled_Parms
{
	UWorld* World;
	bool ReturnValue;

	/** Constructor, initializes return property only **/
	GenericWorldSettings_eventIsWorldSettingsEnabled_Parms()
		: ReturnValue(false)
	{
	}
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_IsWorldSettingsEnabled = FName(TEXT("IsWorldSettingsEnabled"));
bool UGenericWorldSettings::IsWorldSettingsEnabled(UWorld* World) const
{
	GenericWorldSettings_eventIsWorldSettingsEnabled_Parms Parms;
	Parms.World=World;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_IsWorldSettingsEnabled);
		const_cast<UGenericWorldSettings*>(this)->ProcessEvent(Func,&Parms);
	return !!Parms.ReturnValue;
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x88\xa4\xe6\x96\xad\xe8\xaf\xa5\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xe6\x98\xaf\xe5\x90\xa6\xe9\x80\x82\xe7\x94\xa8\xe4\xba\x8e\xe5\xbd\x93\xe5\x89\x8d\xe7\xbc\x96\xe8\xbe\x91\xe4\xb8\x96\xe7\x95\x8c\xef\xbc\x9b\xe5\xa4\xb1\xe6\x95\x88\xe6\x97\xb6\xe5\xb7\xa6\xe4\xbe\xa7\xe5\x88\x97\xe8\xa1\xa8\xe4\xbf\x9d\xe7\x95\x99\xe5\x8f\xaf\xe9\x80\x89\xe4\xb8\xad\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbd\x86\xe5\x8f\xb3\xe4\xbe\xa7\xe4\xb8\x8d\xe5\xb1\x95\xe7\xa4\xba Details\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x88\xa4\xe6\x96\xad\xe8\xaf\xa5\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xe6\x98\xaf\xe5\x90\xa6\xe9\x80\x82\xe7\x94\xa8\xe4\xba\x8e\xe5\xbd\x93\xe5\x89\x8d\xe7\xbc\x96\xe8\xbe\x91\xe4\xb8\x96\xe7\x95\x8c\xef\xbc\x9b\xe5\xa4\xb1\xe6\x95\x88\xe6\x97\xb6\xe5\xb7\xa6\xe4\xbe\xa7\xe5\x88\x97\xe8\xa1\xa8\xe4\xbf\x9d\xe7\x95\x99\xe5\x8f\xaf\xe9\x80\x89\xe4\xb8\xad\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe4\xbd\x86\xe5\x8f\xb3\xe4\xbe\xa7\xe4\xb8\x8d\xe5\xb1\x95\xe7\xa4\xba Details\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function IsWorldSettingsEnabled constinit property declarations ****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsWorldSettingsEnabled constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsWorldSettingsEnabled Property Definitions ***************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventIsWorldSettingsEnabled_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((GenericWorldSettings_eventIsWorldSettingsEnabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GenericWorldSettings_eventIsWorldSettingsEnabled_Parms), &Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::NewProp_World,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::PropPointers) < 2048);
// ********** End Function IsWorldSettingsEnabled Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "IsWorldSettingsEnabled", 	Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventIsWorldSettingsEnabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x7C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventIsWorldSettingsEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execIsWorldSettingsEnabled)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsWorldSettingsEnabled_Implementation(Z_Param_World);
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function IsWorldSettingsEnabled **********************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsBeginDestroy ***************
static FName NAME_UGenericWorldSettings_OnWorldSettingsBeginDestroy = FName(TEXT("OnWorldSettingsBeginDestroy"));
void UGenericWorldSettings::OnWorldSettingsBeginDestroy()
{
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsBeginDestroy);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnWorldSettingsBeginDestroy_Implementation();
	}
}
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginDestroy_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UObject \xe8\xbf\x9b\xe5\x85\xa5\xe9\x94\x80\xe6\xaf\x81\xe6\xb5\x81\xe7\xa8\x8b\xe5\x89\x8d\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe9\x87\x8a\xe6\x94\xbe\xe4\xb8\x8d\xe4\xbe\x9d\xe8\xb5\x96\xe4\xb8\x96\xe7\x95\x8c\xe7\x9a\x84\xe4\xb8\xb4\xe6\x97\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UObject \xe8\xbf\x9b\xe5\x85\xa5\xe9\x94\x80\xe6\xaf\x81\xe6\xb5\x81\xe7\xa8\x8b\xe5\x89\x8d\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe9\x87\x8a\xe6\x94\xbe\xe4\xb8\x8d\xe4\xbe\x9d\xe8\xb5\x96\xe4\xb8\x96\xe7\x95\x8c\xe7\x9a\x84\xe4\xb8\xb4\xe6\x97\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsBeginDestroy constinit property declarations ***********
// ********** End Function OnWorldSettingsBeginDestroy constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginDestroy_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsBeginDestroy", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginDestroy_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginDestroy_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginDestroy()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginDestroy_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsBeginDestroy)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsBeginDestroy_Implementation();
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettings Function OnWorldSettingsBeginDestroy *****************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsBeginPlay ******************
struct GenericWorldSettings_eventOnWorldSettingsBeginPlay_Parms
{
	UWorld* World;
};
static FName NAME_UGenericWorldSettings_OnWorldSettingsBeginPlay = FName(TEXT("OnWorldSettingsBeginPlay"));
void UGenericWorldSettings::OnWorldSettingsBeginPlay(UWorld* World)
{
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsBeginPlay);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GenericWorldSettings_eventOnWorldSettingsBeginPlay_Parms Parms;
		Parms.World=World;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnWorldSettingsBeginPlay_Implementation(World);
	}
}
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x90\xe8\xa1\x8c\xe4\xb8\x96\xe7\x95\x8c BeginPlay \xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe6\x8c\x89\xe5\xb7\xb2\xe8\xaf\xbb\xe5\x8f\x96\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe6\x89\xa7\xe8\xa1\x8c\xe4\xb8\x96\xe7\x95\x8c\xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x90\xe8\xa1\x8c\xe4\xb8\x96\xe7\x95\x8c BeginPlay \xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe6\x8c\x89\xe5\xb7\xb2\xe8\xaf\xbb\xe5\x8f\x96\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe6\x89\xa7\xe8\xa1\x8c\xe4\xb8\x96\xe7\x95\x8c\xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsBeginPlay constinit property declarations **************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsBeginPlay constinit property declarations ****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsBeginPlay Property Definitions *************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsBeginPlay_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsBeginPlay Property Definitions ***************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsBeginPlay", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsBeginPlay_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsBeginPlay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsBeginPlay)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsBeginPlay_Implementation(Z_Param_World);
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettings Function OnWorldSettingsBeginPlay ********************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsBeginTearDown **************
struct GenericWorldSettings_eventOnWorldSettingsBeginTearDown_Parms
{
	UWorld* World;
};
static FName NAME_UGenericWorldSettings_OnWorldSettingsBeginTearDown = FName(TEXT("OnWorldSettingsBeginTearDown"));
void UGenericWorldSettings::OnWorldSettingsBeginTearDown(UWorld* World)
{
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsBeginTearDown);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GenericWorldSettings_eventOnWorldSettingsBeginTearDown_Parms Parms;
		Parms.World=World;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnWorldSettingsBeginTearDown_Implementation(World);
	}
}
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x90\xe8\xa1\x8c\xe4\xb8\x96\xe7\x95\x8c\xe5\xbc\x80\xe5\xa7\x8b TearDown \xe6\x97\xb6\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x81\x9c\xe6\xad\xa2\xe4\xbe\x9d\xe8\xb5\x96\xe8\xaf\xa5\xe4\xb8\x96\xe7\x95\x8c\xe7\x9a\x84\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x90\xe8\xa1\x8c\xe4\xb8\x96\xe7\x95\x8c\xe5\xbc\x80\xe5\xa7\x8b TearDown \xe6\x97\xb6\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x81\x9c\xe6\xad\xa2\xe4\xbe\x9d\xe8\xb5\x96\xe8\xaf\xa5\xe4\xb8\x96\xe7\x95\x8c\xe7\x9a\x84\xe9\x80\xbb\xe8\xbe\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsBeginTearDown constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsBeginTearDown constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsBeginTearDown Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsBeginTearDown_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsBeginTearDown Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsBeginTearDown", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsBeginTearDown_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsBeginTearDown_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsBeginTearDown)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsBeginTearDown_Implementation(Z_Param_World);
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettings Function OnWorldSettingsBeginTearDown ****************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsEditorChanged **************
#if WITH_EDITOR
struct GenericWorldSettings_eventOnWorldSettingsEditorChanged_Parms
{
	UWorld* World;
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_OnWorldSettingsEditorChanged = FName(TEXT("OnWorldSettingsEditorChanged"));
void UGenericWorldSettings::OnWorldSettingsEditorChanged(UWorld* World)
{
	GenericWorldSettings_eventOnWorldSettingsEditorChanged_Parms Parms;
	Parms.World=World;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsEditorChanged);
	ProcessEvent(Func,&Parms);
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Details \xe9\x9d\xa2\xe6\x9d\xbf\xe6\x88\x96\xe5\xb1\x9e\xe6\x80\xa7\xe7\xb3\xbb\xe7\xbb\x9f\xe4\xbf\xae\xe6\x94\xb9\xe8\xaf\xa5\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Details \xe9\x9d\xa2\xe6\x9d\xbf\xe6\x88\x96\xe5\xb1\x9e\xe6\x80\xa7\xe7\xb3\xbb\xe7\xbb\x9f\xe4\xbf\xae\xe6\x94\xb9\xe8\xaf\xa5\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsEditorChanged constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsEditorChanged constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsEditorChanged Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsEditorChanged_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsEditorChanged Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsEditorChanged", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsEditorChanged_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x28020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsEditorChanged_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsEditorChanged)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsEditorChanged_Implementation(Z_Param_World);
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function OnWorldSettingsEditorChanged ****************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsEditorCreated **************
#if WITH_EDITOR
struct GenericWorldSettings_eventOnWorldSettingsEditorCreated_Parms
{
	UWorld* World;
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_OnWorldSettingsEditorCreated = FName(TEXT("OnWorldSettingsEditorCreated"));
void UGenericWorldSettings::OnWorldSettingsEditorCreated(UWorld* World)
{
	GenericWorldSettings_eventOnWorldSettingsEditorCreated_Parms Parms;
	Parms.World=World;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsEditorCreated);
	ProcessEvent(Func,&Parms);
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x88\x9b\xe5\xbb\xba\xe8\xaf\xa5\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xe5\xb9\xb6\xe5\x8a\xa0\xe5\x85\xa5\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe6\x80\xbb\xe9\x9b\x86\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x88\x9b\xe5\xbb\xba\xe8\xaf\xa5\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xe5\xb9\xb6\xe5\x8a\xa0\xe5\x85\xa5\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe6\x80\xbb\xe9\x9b\x86\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsEditorCreated constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsEditorCreated constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsEditorCreated Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsEditorCreated_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsEditorCreated Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsEditorCreated", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsEditorCreated_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x28020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsEditorCreated_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsEditorCreated)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsEditorCreated_Implementation(Z_Param_World);
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function OnWorldSettingsEditorCreated ****************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsEditorLoaded ***************
#if WITH_EDITOR
struct GenericWorldSettings_eventOnWorldSettingsEditorLoaded_Parms
{
	UWorld* World;
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_OnWorldSettingsEditorLoaded = FName(TEXT("OnWorldSettingsEditorLoaded"));
void UGenericWorldSettings::OnWorldSettingsEditorLoaded(UWorld* World)
{
	GenericWorldSettings_eventOnWorldSettingsEditorLoaded_Parms Parms;
	Parms.World=World;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsEditorLoaded);
	ProcessEvent(Func,&Parms);
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe4\xb8\x96\xe7\x95\x8c\xe8\xaf\xbb\xe5\x8f\x96\xe5\x88\xb0\xe8\xaf\xa5\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x87\x86\xe5\xa4\x87\xe5\x8f\xaa\xe5\x9c\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\xa2\x84\xe8\xa7\x88\xe4\xb8\xad\xe9\x9c\x80\xe8\xa6\x81\xe7\x9a\x84\xe4\xb8\xb4\xe6\x97\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe4\xb8\x96\xe7\x95\x8c\xe8\xaf\xbb\xe5\x8f\x96\xe5\x88\xb0\xe8\xaf\xa5\xe8\xae\xbe\xe7\xbd\xae\xe5\xae\x9e\xe4\xbe\x8b\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x87\x86\xe5\xa4\x87\xe5\x8f\xaa\xe5\x9c\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\xa2\x84\xe8\xa7\x88\xe4\xb8\xad\xe9\x9c\x80\xe8\xa6\x81\xe7\x9a\x84\xe4\xb8\xb4\xe6\x97\xb6\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsEditorLoaded constinit property declarations ***********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsEditorLoaded constinit property declarations *************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsEditorLoaded Property Definitions **********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsEditorLoaded_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsEditorLoaded Property Definitions ************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsEditorLoaded", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsEditorLoaded_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x28020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsEditorLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsEditorLoaded)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsEditorLoaded_Implementation(Z_Param_World);
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function OnWorldSettingsEditorLoaded *****************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsEditorPreSave **************
#if WITH_EDITOR
struct GenericWorldSettings_eventOnWorldSettingsEditorPreSave_Parms
{
	UWorld* World;
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_OnWorldSettingsEditorPreSave = FName(TEXT("OnWorldSettingsEditorPreSave"));
void UGenericWorldSettings::OnWorldSettingsEditorPreSave(UWorld* World)
{
	GenericWorldSettings_eventOnWorldSettingsEditorPreSave_Parms Parms;
	Parms.World=World;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsEditorPreSave);
	ProcessEvent(Func,&Parms);
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xbf\x9d\xe5\xad\x98\xe5\x89\x8d\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe5\x8f\xaf\xe7\x94\xa8\xe4\xba\x8e\xe6\x8a\x8a\xe6\xb4\xbe\xe7\x94\x9f\xe7\xb1\xbb\xe7\xbc\x93\xe5\xad\x98\xe5\x86\x99\xe5\x9b\x9e\xe5\x8f\xaf\xe5\xba\x8f\xe5\x88\x97\xe5\x8c\x96\xe5\xb1\x9e\xe6\x80\xa7\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xbf\x9d\xe5\xad\x98\xe5\x89\x8d\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe5\x8f\xaf\xe7\x94\xa8\xe4\xba\x8e\xe6\x8a\x8a\xe6\xb4\xbe\xe7\x94\x9f\xe7\xb1\xbb\xe7\xbc\x93\xe5\xad\x98\xe5\x86\x99\xe5\x9b\x9e\xe5\x8f\xaf\xe5\xba\x8f\xe5\x88\x97\xe5\x8c\x96\xe5\xb1\x9e\xe6\x80\xa7\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsEditorPreSave constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsEditorPreSave constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsEditorPreSave Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsEditorPreSave_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsEditorPreSave Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsEditorPreSave", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsEditorPreSave_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x28020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsEditorPreSave_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsEditorPreSave)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsEditorPreSave_Implementation(Z_Param_World);
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function OnWorldSettingsEditorPreSave ****************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsEditorSaved ****************
#if WITH_EDITOR
struct GenericWorldSettings_eventOnWorldSettingsEditorSaved_Parms
{
	UWorld* World;
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_OnWorldSettingsEditorSaved = FName(TEXT("OnWorldSettingsEditorSaved"));
void UGenericWorldSettings::OnWorldSettingsEditorSaved(UWorld* World)
{
	GenericWorldSettings_eventOnWorldSettingsEditorSaved_Parms Parms;
	Parms.World=World;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsEditorSaved);
	ProcessEvent(Func,&Parms);
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xbf\x9d\xe5\xad\x98\xe6\x88\x90\xe5\x8a\x9f\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe4\xbf\x9d\xe5\xad\x98\xe6\x88\x90\xe5\x8a\x9f\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsEditorSaved constinit property declarations ************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsEditorSaved constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsEditorSaved Property Definitions ***********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsEditorSaved_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsEditorSaved Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsEditorSaved", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsEditorSaved_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x28020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsEditorSaved_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsEditorSaved)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsEditorSaved_Implementation(Z_Param_World);
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function OnWorldSettingsEditorSaved ******************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsEditorUnloaded *************
#if WITH_EDITOR
struct GenericWorldSettings_eventOnWorldSettingsEditorUnloaded_Parms
{
	UWorld* World;
};
#if WITH_EDITOR
static FName NAME_UGenericWorldSettings_OnWorldSettingsEditorUnloaded = FName(TEXT("OnWorldSettingsEditorUnloaded"));
void UGenericWorldSettings::OnWorldSettingsEditorUnloaded(UWorld* World)
{
	GenericWorldSettings_eventOnWorldSettingsEditorUnloaded_Parms Parms;
	Parms.World=World;
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsEditorUnloaded);
	ProcessEvent(Func,&Parms);
}
#endif // WITH_EDITOR
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8\xe9\x87\x8a\xe6\x94\xbe\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe8\xae\xbe\xe7\xbd\xae\xe5\xbc\x95\xe7\x94\xa8\xe6\x97\xb6\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe7\xae\xa1\xe7\x90\x86\xe5\x99\xa8\xe9\x87\x8a\xe6\x94\xbe\xe5\xbd\x93\xe5\x89\x8d\xe4\xb8\x96\xe7\x95\x8c\xe8\xae\xbe\xe7\xbd\xae\xe5\xbc\x95\xe7\x94\xa8\xe6\x97\xb6\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsEditorUnloaded constinit property declarations *********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsEditorUnloaded constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsEditorUnloaded Property Definitions ********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsEditorUnloaded_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsEditorUnloaded Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsEditorUnloaded", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsEditorUnloaded_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x28020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsEditorUnloaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsEditorUnloaded)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsEditorUnloaded_Implementation(Z_Param_World);
	P_NATIVE_END;
}
#endif // WITH_EDITOR
// ********** End Class UGenericWorldSettings Function OnWorldSettingsEditorUnloaded ***************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsLoaded *********************
struct GenericWorldSettings_eventOnWorldSettingsLoaded_Parms
{
	UWorld* World;
};
static FName NAME_UGenericWorldSettings_OnWorldSettingsLoaded = FName(TEXT("OnWorldSettingsLoaded"));
void UGenericWorldSettings::OnWorldSettingsLoaded(UWorld* World)
{
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsLoaded);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GenericWorldSettings_eventOnWorldSettingsLoaded_Parms Parms;
		Parms.World=World;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnWorldSettingsLoaded_Implementation(World);
	}
}
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xe5\xae\x8c\xe6\x88\x90\xe8\xaf\xbb\xe5\x8f\x96\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe6\xb4\xbe\xe7\x94\x9f\xe7\xb1\xbb\xe5\x8f\xaf\xe5\x9c\xa8\xe8\xbf\x99\xe9\x87\x8c\xe5\x87\x86\xe5\xa4\x87\xe5\x8f\xaa\xe4\xbe\x9d\xe8\xb5\x96\xe9\x85\x8d\xe7\xbd\xae\xe5\x80\xbc\xe7\x9a\x84\xe8\xbd\xbb\xe9\x87\x8f\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xe5\xae\x8c\xe6\x88\x90\xe8\xaf\xbb\xe5\x8f\x96\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe6\xb4\xbe\xe7\x94\x9f\xe7\xb1\xbb\xe5\x8f\xaf\xe5\x9c\xa8\xe8\xbf\x99\xe9\x87\x8c\xe5\x87\x86\xe5\xa4\x87\xe5\x8f\xaa\xe4\xbe\x9d\xe8\xb5\x96\xe9\x85\x8d\xe7\xbd\xae\xe5\x80\xbc\xe7\x9a\x84\xe8\xbd\xbb\xe9\x87\x8f\xe7\x8a\xb6\xe6\x80\x81\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsLoaded constinit property declarations *****************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsLoaded constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsLoaded Property Definitions ****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsLoaded_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsLoaded Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsLoaded", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsLoaded_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsLoaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsLoaded)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsLoaded_Implementation(Z_Param_World);
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettings Function OnWorldSettingsLoaded ***********************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsMatchStarting **************
struct GenericWorldSettings_eventOnWorldSettingsMatchStarting_Parms
{
	UWorld* World;
};
static FName NAME_UGenericWorldSettings_OnWorldSettingsMatchStarting = FName(TEXT("OnWorldSettingsMatchStarting"));
void UGenericWorldSettings::OnWorldSettingsMatchStarting(UWorld* World)
{
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsMatchStarting);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GenericWorldSettings_eventOnWorldSettingsMatchStarting_Parms Parms;
		Parms.World=World;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnWorldSettingsMatchStarting_Implementation(World);
	}
}
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xb8\x96\xe7\x95\x8c\xe8\xbf\x9b\xe5\x85\xa5 MatchStarting \xe9\x98\xb6\xe6\xae\xb5\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x9b\xe6\xad\xa4\xe6\x97\xb6 Actor BeginPlay \xe5\xb7\xb2\xe5\xae\x8c\xe6\x88\x90\xef\xbc\x8c\xe9\x80\x82\xe5\x90\x88\xe4\xbe\x9d\xe8\xb5\x96\xe5\x9c\xba\xe6\x99\xaf\xe5\xaf\xb9\xe8\xb1\xa1\xe6\xb3\xa8\xe5\x86\x8c\xe7\xbb\x93\xe6\x9e\x9c\xe7\x9a\x84\xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\x96\xe7\x95\x8c\xe8\xbf\x9b\xe5\x85\xa5 MatchStarting \xe9\x98\xb6\xe6\xae\xb5\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x9b\xe6\xad\xa4\xe6\x97\xb6 Actor BeginPlay \xe5\xb7\xb2\xe5\xae\x8c\xe6\x88\x90\xef\xbc\x8c\xe9\x80\x82\xe5\x90\x88\xe4\xbe\x9d\xe8\xb5\x96\xe5\x9c\xba\xe6\x99\xaf\xe5\xaf\xb9\xe8\xb1\xa1\xe6\xb3\xa8\xe5\x86\x8c\xe7\xbb\x93\xe6\x9e\x9c\xe7\x9a\x84\xe5\x88\x9d\xe5\xa7\x8b\xe5\x8c\x96\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsMatchStarting constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsMatchStarting constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsMatchStarting Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsMatchStarting_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsMatchStarting Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsMatchStarting", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsMatchStarting_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsMatchStarting_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsMatchStarting)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsMatchStarting_Implementation(Z_Param_World);
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettings Function OnWorldSettingsMatchStarting ****************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsPostBeginPlay **************
struct GenericWorldSettings_eventOnWorldSettingsPostBeginPlay_Parms
{
	UWorld* World;
};
static FName NAME_UGenericWorldSettings_OnWorldSettingsPostBeginPlay = FName(TEXT("OnWorldSettingsPostBeginPlay"));
void UGenericWorldSettings::OnWorldSettingsPostBeginPlay(UWorld* World)
{
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsPostBeginPlay);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GenericWorldSettings_eventOnWorldSettingsPostBeginPlay_Parms Parms;
		Parms.World=World;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnWorldSettingsPostBeginPlay_Implementation(World);
	}
}
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xb8\x96\xe7\x95\x8c\xe5\xae\x8c\xe6\x88\x90 BeginPlay \xe5\xb9\xbf\xe6\x92\xad\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x9b\xe6\xad\xa4\xe6\x97\xb6 GameMode/Actor \xe7\x9a\x84\xe5\xbc\x80\xe5\xa7\x8b\xe6\xb5\x81\xe7\xa8\x8b\xe5\xb7\xb2\xe6\x94\xb6\xe6\x9d\x9f\xef\xbc\x8c\xe9\x80\x82\xe5\x90\x88\xe6\x89\xa7\xe8\xa1\x8c\xe6\x9c\x80\xe7\xbb\x88\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\x81\x94\xe5\x8a\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xb8\x96\xe7\x95\x8c\xe5\xae\x8c\xe6\x88\x90 BeginPlay \xe5\xb9\xbf\xe6\x92\xad\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x9b\xe6\xad\xa4\xe6\x97\xb6 GameMode/Actor \xe7\x9a\x84\xe5\xbc\x80\xe5\xa7\x8b\xe6\xb5\x81\xe7\xa8\x8b\xe5\xb7\xb2\xe6\x94\xb6\xe6\x9d\x9f\xef\xbc\x8c\xe9\x80\x82\xe5\x90\x88\xe6\x89\xa7\xe8\xa1\x8c\xe6\x9c\x80\xe7\xbb\x88\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\x81\x94\xe5\x8a\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsPostBeginPlay constinit property declarations **********
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsPostBeginPlay constinit property declarations ************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsPostBeginPlay Property Definitions *********************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsPostBeginPlay_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsPostBeginPlay Property Definitions ***********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsPostBeginPlay", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsPostBeginPlay_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsPostBeginPlay_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsPostBeginPlay)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsPostBeginPlay_Implementation(Z_Param_World);
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettings Function OnWorldSettingsPostBeginPlay ****************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsPostLoad *******************
static FName NAME_UGenericWorldSettings_OnWorldSettingsPostLoad = FName(TEXT("OnWorldSettingsPostLoad"));
void UGenericWorldSettings::OnWorldSettingsPostLoad()
{
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsPostLoad);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
	ProcessEvent(Func,NULL);
	}
	else
	{
		OnWorldSettingsPostLoad_Implementation();
	}
}
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostLoad_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** UObject \xe5\xae\x8c\xe6\x88\x90\xe5\x8f\x8d\xe5\xba\x8f\xe5\x88\x97\xe5\x8c\x96\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x92\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x83\xbd\xe4\xbc\x9a\xe8\xa6\x86\xe7\x9b\x96\xe5\x88\xb0\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "UObject \xe5\xae\x8c\xe6\x88\x90\xe5\x8f\x8d\xe5\xba\x8f\xe5\x88\x97\xe5\x8c\x96\xe5\x90\x8e\xe8\xa7\xa6\xe5\x8f\x91\xef\xbc\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe5\x92\x8c\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe9\x83\xbd\xe4\xbc\x9a\xe8\xa6\x86\xe7\x9b\x96\xe5\x88\xb0\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsPostLoad constinit property declarations ***************
// ********** End Function OnWorldSettingsPostLoad constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostLoad_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsPostLoad", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostLoad_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostLoad_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostLoad()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostLoad_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsPostLoad)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsPostLoad_Implementation();
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettings Function OnWorldSettingsPostLoad *********************

// ********** Begin Class UGenericWorldSettings Function OnWorldSettingsUnloaded *******************
struct GenericWorldSettings_eventOnWorldSettingsUnloaded_Parms
{
	UWorld* World;
};
static FName NAME_UGenericWorldSettings_OnWorldSettingsUnloaded = FName(TEXT("OnWorldSettingsUnloaded"));
void UGenericWorldSettings::OnWorldSettingsUnloaded(UWorld* World)
{
	UFunction* Func = FindFunctionChecked(NAME_UGenericWorldSettings_OnWorldSettingsUnloaded);
	if (!Func->GetOwnerClass()->HasAnyClassFlags(CLASS_Native))
	{
		GenericWorldSettings_eventOnWorldSettingsUnloaded_Parms Parms;
		Parms.World=World;
	ProcessEvent(Func,&Parms);
	}
	else
	{
		OnWorldSettingsUnloaded_Implementation(World);
	}
}
struct Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Generic World Settings|Lifecycle" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xe4\xbb\x8e\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe9\x87\x8a\xe6\x94\xbe\xe5\x89\x8d\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xe4\xbb\x8e\xe5\xad\x90\xe7\xb3\xbb\xe7\xbb\x9f\xe9\x87\x8a\xe6\x94\xbe\xe5\x89\x8d\xe8\xa7\xa6\xe5\x8f\x91\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Function OnWorldSettingsUnloaded constinit property declarations ***************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_World;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function OnWorldSettingsUnloaded constinit property declarations *****************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function OnWorldSettingsUnloaded Property Definitions **************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics::NewProp_World = { "World", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GenericWorldSettings_eventOnWorldSettingsUnloaded_Parms, World), Z_Construct_UClass_UWorld_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics::NewProp_World,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics::PropPointers) < 2048);
// ********** End Function OnWorldSettingsUnloaded Property Definitions ****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UGenericWorldSettings, nullptr, "OnWorldSettingsUnloaded", 	Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics::PropPointers), 
sizeof(GenericWorldSettings_eventOnWorldSettingsUnloaded_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(GenericWorldSettings_eventOnWorldSettingsUnloaded_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UGenericWorldSettings::execOnWorldSettingsUnloaded)
{
	P_GET_OBJECT(UWorld,Z_Param_World);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnWorldSettingsUnloaded_Implementation(Z_Param_World);
	P_NATIVE_END;
}
// ********** End Class UGenericWorldSettings Function OnWorldSettingsUnloaded *********************

// ********** Begin Class UGenericWorldSettings ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UGenericWorldSettings;
UClass* UGenericWorldSettings::GetPrivateStaticClass()
{
	using TClass = UGenericWorldSettings;
	if (!Z_Registration_Info_UClass_UGenericWorldSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("GenericWorldSettings"),
			Z_Registration_Info_UClass_UGenericWorldSettings.InnerSingleton,
			StaticRegisterNativesUGenericWorldSettings,
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
	return Z_Registration_Info_UClass_UGenericWorldSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UGenericWorldSettings_NoRegister()
{
	return UGenericWorldSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UGenericWorldSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbd\x9c\xe4\xb8\xba\xe4\xb8\x96\xe7\x95\x8c\xe7\xba\xa7\xe8\xae\xbe\xe7\xbd\xae\xe9\xa1\xb9\xe7\x9a\x84\xe5\x9f\xba\xe7\xb1\xbb\xef\xbc\x8c\xe6\xb4\xbe\xe7\x94\x9f\xe7\xb1\xbb\xe5\xae\x9e\xe4\xbe\x8b\xe4\xbc\x9a\xe5\xb5\x8c\xe5\x85\xa5\xe6\x8c\x87\xe5\xae\x9a\xe5\x9c\xb0\xe5\x9b\xbe\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xe4\xb8\xad\xe9\x9a\x8f\xe5\x9c\xb0\xe5\x9b\xbe\xe6\x8c\x81\xe4\xb9\x85\xe5\x8c\x96\xe3\x80\x82 */" },
#endif
		{ "IncludePath", "WorldSettings/GenericWorldSettings.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/WorldSettings/GenericWorldSettings.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbd\x9c\xe4\xb8\xba\xe4\xb8\x96\xe7\x95\x8c\xe7\xba\xa7\xe8\xae\xbe\xe7\xbd\xae\xe9\xa1\xb9\xe7\x9a\x84\xe5\x9f\xba\xe7\xb1\xbb\xef\xbc\x8c\xe6\xb4\xbe\xe7\x94\x9f\xe7\xb1\xbb\xe5\xae\x9e\xe4\xbe\x8b\xe4\xbc\x9a\xe5\xb5\x8c\xe5\x85\xa5\xe6\x8c\x87\xe5\xae\x9a\xe5\x9c\xb0\xe5\x9b\xbe\xe7\x9a\x84\xe8\xae\xbe\xe7\xbd\xae\xe6\x80\xbb\xe9\x9b\x86\xe4\xb8\xad\xe9\x9a\x8f\xe5\x9c\xb0\xe5\x9b\xbe\xe6\x8c\x81\xe4\xb9\x85\xe5\x8c\x96\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin Class UGenericWorldSettings constinit property declarations ********************
// ********** End Class UGenericWorldSettings constinit property declarations **********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
#if WITH_EDITOR
		{ .NameUTF8 = UTF8TEXT("GetSettingsCategory"), .Pointer = &UGenericWorldSettings::execGetSettingsCategory },
		{ .NameUTF8 = UTF8TEXT("GetSettingsDescription"), .Pointer = &UGenericWorldSettings::execGetSettingsDescription },
		{ .NameUTF8 = UTF8TEXT("GetSettingsDisplayName"), .Pointer = &UGenericWorldSettings::execGetSettingsDisplayName },
		{ .NameUTF8 = UTF8TEXT("GetWorldSettingsDisabledReason"), .Pointer = &UGenericWorldSettings::execGetWorldSettingsDisabledReason },
		{ .NameUTF8 = UTF8TEXT("IsWorldSettingsEnabled"), .Pointer = &UGenericWorldSettings::execIsWorldSettingsEnabled },
#endif // WITH_EDITOR
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsBeginDestroy"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsBeginDestroy },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsBeginPlay"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsBeginPlay },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsBeginTearDown"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsBeginTearDown },
#if WITH_EDITOR
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsEditorChanged"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsEditorChanged },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsEditorCreated"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsEditorCreated },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsEditorLoaded"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsEditorLoaded },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsEditorPreSave"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsEditorPreSave },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsEditorSaved"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsEditorSaved },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsEditorUnloaded"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsEditorUnloaded },
#endif // WITH_EDITOR
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsLoaded"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsLoaded },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsMatchStarting"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsMatchStarting },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsPostBeginPlay"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsPostBeginPlay },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsPostLoad"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsPostLoad },
		{ .NameUTF8 = UTF8TEXT("OnWorldSettingsUnloaded"), .Pointer = &UGenericWorldSettings::execOnWorldSettingsUnloaded },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UGenericWorldSettings_GetSettingsCategory, "GetSettingsCategory" }, // 2361954301
		{ &Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDescription, "GetSettingsDescription" }, // 463059486
		{ &Z_Construct_UFunction_UGenericWorldSettings_GetSettingsDisplayName, "GetSettingsDisplayName" }, // 2825904758
		{ &Z_Construct_UFunction_UGenericWorldSettings_GetWorldSettingsDisabledReason, "GetWorldSettingsDisabledReason" }, // 2435019343
		{ &Z_Construct_UFunction_UGenericWorldSettings_IsWorldSettingsEnabled, "IsWorldSettingsEnabled" }, // 1896066331
#endif // WITH_EDITOR
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginDestroy, "OnWorldSettingsBeginDestroy" }, // 3756206244
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginPlay, "OnWorldSettingsBeginPlay" }, // 490804517
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsBeginTearDown, "OnWorldSettingsBeginTearDown" }, // 1751739882
#if WITH_EDITOR
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorChanged, "OnWorldSettingsEditorChanged" }, // 1580728473
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorCreated, "OnWorldSettingsEditorCreated" }, // 1118304473
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorLoaded, "OnWorldSettingsEditorLoaded" }, // 1707237131
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorPreSave, "OnWorldSettingsEditorPreSave" }, // 480917372
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorSaved, "OnWorldSettingsEditorSaved" }, // 2700585723
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsEditorUnloaded, "OnWorldSettingsEditorUnloaded" }, // 3268381271
#endif // WITH_EDITOR
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsLoaded, "OnWorldSettingsLoaded" }, // 2079848766
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsMatchStarting, "OnWorldSettingsMatchStarting" }, // 1947132966
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostBeginPlay, "OnWorldSettingsPostBeginPlay" }, // 3004752610
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsPostLoad, "OnWorldSettingsPostLoad" }, // 3565475217
		{ &Z_Construct_UFunction_UGenericWorldSettings_OnWorldSettingsUnloaded, "OnWorldSettingsUnloaded" }, // 3389562965
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGenericWorldSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UGenericWorldSettings_Statics
UObject* (*const Z_Construct_UClass_UGenericWorldSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGenericObject,
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSettingsFramework,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UGenericWorldSettings_Statics::ClassParams = {
	&UGenericWorldSettings::StaticClass,
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
	0x003010A1u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGenericWorldSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UGenericWorldSettings_Statics::Class_MetaDataParams)
};
void UGenericWorldSettings::StaticRegisterNativesUGenericWorldSettings()
{
	UClass* Class = UGenericWorldSettings::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UGenericWorldSettings_Statics::Funcs));
}
UClass* Z_Construct_UClass_UGenericWorldSettings()
{
	if (!Z_Registration_Info_UClass_UGenericWorldSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGenericWorldSettings.OuterSingleton, Z_Construct_UClass_UGenericWorldSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UGenericWorldSettings.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UGenericWorldSettings);
UGenericWorldSettings::~UGenericWorldSettings() {}
// ********** End Class UGenericWorldSettings ******************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h__Script_GenericSettingsFramework_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UGenericWorldSettings, UGenericWorldSettings::StaticClass, TEXT("UGenericWorldSettings"), &Z_Registration_Info_UClass_UGenericWorldSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGenericWorldSettings), 726249705U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h__Script_GenericSettingsFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h__Script_GenericSettingsFramework_297131608{
	TEXT("/Script/GenericSettingsFramework"),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h__Script_GenericSettingsFramework_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericSettingsFramework_Source_GenericSettingsFramework_Public_WorldSettings_GenericWorldSettings_h__Script_GenericSettingsFramework_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
