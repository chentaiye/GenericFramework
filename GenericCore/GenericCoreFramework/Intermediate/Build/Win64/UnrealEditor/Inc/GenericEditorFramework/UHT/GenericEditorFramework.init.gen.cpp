// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGenericEditorFramework_init() {}
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GenericEditorFramework;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GenericEditorFramework()
	{
		if (!Z_Registration_Info_UPackage__Script_GenericEditorFramework.OuterSingleton)
		{
		static const UECodeGen_Private::FPackageParams PackageParams = {
			"/Script/GenericEditorFramework",
			nullptr,
			0,
			PKG_CompiledIn | 0x00000040,
			0x653E51B4,
			0xC833390C,
			METADATA_PARAMS(0, nullptr)
		};
		UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GenericEditorFramework.OuterSingleton, PackageParams);
	}
	return Z_Registration_Info_UPackage__Script_GenericEditorFramework.OuterSingleton;
}
static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GenericEditorFramework(Z_Construct_UPackage__Script_GenericEditorFramework, TEXT("/Script/GenericEditorFramework"), Z_Registration_Info_UPackage__Script_GenericEditorFramework, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x653E51B4, 0xC833390C));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
