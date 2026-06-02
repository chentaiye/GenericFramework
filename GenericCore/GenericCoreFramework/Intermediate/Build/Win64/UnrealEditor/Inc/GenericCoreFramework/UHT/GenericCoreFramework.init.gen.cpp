// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGenericCoreFramework_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GenericCoreFramework;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GenericCoreFramework()
	{
		if (!Z_Registration_Info_UPackage__Script_GenericCoreFramework.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/GenericCoreFramework",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000000,
			0x7E8318E0,
			0xF30B0C78,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GenericCoreFramework.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_GenericCoreFramework.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GenericCoreFramework(Z_Construct_UPackage__Script_GenericCoreFramework, TEXT("/Script/GenericCoreFramework"), Z_Registration_Info_UPackage__Script_GenericCoreFramework, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x7E8318E0, 0xF30B0C78));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
