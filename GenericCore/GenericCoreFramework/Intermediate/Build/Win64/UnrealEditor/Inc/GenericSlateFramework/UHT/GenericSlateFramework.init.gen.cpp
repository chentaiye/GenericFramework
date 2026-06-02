// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGenericSlateFramework_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature();
	GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature();
	GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature();
	GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature();
	GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature();
	GENERICSLATEFRAMEWORK_API UFunction* Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GenericSlateFramework;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GenericSlateFramework()
	{
		if (!Z_Registration_Info_UPackage__Script_GenericSlateFramework.OuterSingleton)
		{
		static UObject* (*const SingletonFuncArray[])() = {
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericSlateFramework_OnActiveIndexChangedFinish__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericSlateFramework_OnElementRotated__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericSlateFramework_OnGenericAnimatedSwitcherActiveIndexChangedDelegate__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericSlateFramework_OnSubtitleLineAdded__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextChangedEvent__DelegateSignature,
			(UObject* (*)())Z_Construct_UDelegateFunction_GenericSlateFramework_OnSwitchableTextCommittedEvent__DelegateSignature,
		};
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/GenericSlateFramework",
			SingletonFuncArray,
			UE_ARRAY_COUNT(SingletonFuncArray),
			PKG_CompiledIn | 0x00000000,
			0xA2AD8A57,
			0x4F22D276,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GenericSlateFramework.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_GenericSlateFramework.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GenericSlateFramework(Z_Construct_UPackage__Script_GenericSlateFramework, TEXT("/Script/GenericSlateFramework"), Z_Registration_Info_UPackage__Script_GenericSlateFramework, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xA2AD8A57, 0x4F22D276));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
