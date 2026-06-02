// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGenericVersionFramework_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GenericVersionFramework;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GenericVersionFramework()
	{
		if (!Z_Registration_Info_UPackage__Script_GenericVersionFramework.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/GenericVersionFramework",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000000,
			0xE0DF6DCB,
			0x32BF4764,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GenericVersionFramework.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_GenericVersionFramework.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GenericVersionFramework(Z_Construct_UPackage__Script_GenericVersionFramework, TEXT("/Script/GenericVersionFramework"), Z_Registration_Info_UPackage__Script_GenericVersionFramework, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xE0DF6DCB, 0x32BF4764));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
