// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SlateType.h"
#include "Styling/SlateBrush.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSlateType() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USlateBrushAsset_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USlateTextureAtlasInterface_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2DDynamic_NoRegister();
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource();
GENERICSLATEFRAMEWORK_API UEnum* Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource();
GENERICSLATEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FBorderBrush();
GENERICSLATEFRAMEWORK_API UScriptStruct* Z_Construct_UScriptStruct_FImageBrush();
SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
UPackage* Z_Construct_UPackage__Script_GenericSlateFramework();
// ********** End Cross Module References **********************************************************

// ********** Begin Enum EImageBrushResource *******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EImageBrushResource;
static UEnum* EImageBrushResource_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EImageBrushResource.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EImageBrushResource.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource, (UObject*)Z_Construct_UPackage__Script_GenericSlateFramework(), TEXT("EImageBrushResource"));
	}
	return Z_Registration_Info_UEnum_EImageBrushResource.OuterSingleton;
}
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EImageBrushResource>()
{
	return EImageBrushResource_StaticEnum();
}
struct Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""E\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7Resource\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "MaterialInterface.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
		{ "MaterialInterface.Name", "EImageBrushResource::MaterialInterface" },
		{ "MaterialInterface.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
		{ "ResourceObject.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xb5\x84\xe6\xba\x90\xe5\xaf\xb9\xe8\xb1\xa1\xe3\x80\x82 */" },
		{ "ResourceObject.Name", "EImageBrushResource::ResourceObject" },
		{ "ResourceObject.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xb5\x84\xe6\xba\x90\xe5\xaf\xb9\xe8\xb1\xa1\xe3\x80\x82" },
		{ "SlateBrush.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaSlate\xe7\x94\xbb\xe5\x88\xb7\xe3\x80\x82 */" },
		{ "SlateBrush.Name", "EImageBrushResource::SlateBrush" },
		{ "SlateBrush.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaSlate\xe7\x94\xbb\xe5\x88\xb7\xe3\x80\x82" },
		{ "SlateBrushAsset.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaSlate\xe7\x94\xbb\xe5\x88\xb7\xe8\xb5\x84\xe4\xba\xa7\xe3\x80\x82 */" },
		{ "SlateBrushAsset.Name", "EImageBrushResource::SlateBrushAsset" },
		{ "SlateBrushAsset.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaSlate\xe7\x94\xbb\xe5\x88\xb7\xe8\xb5\x84\xe4\xba\xa7\xe3\x80\x82" },
		{ "SlateTextureAtlasInterface.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaSlate\xe7\xba\xb9\xe7\x90\x86\xe5\x9b\xbe\xe9\x9b\x86\xe6\x8e\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
		{ "SlateTextureAtlasInterface.Name", "EImageBrushResource::SlateTextureAtlasInterface" },
		{ "SlateTextureAtlasInterface.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaSlate\xe7\xba\xb9\xe7\x90\x86\xe5\x9b\xbe\xe9\x9b\x86\xe6\x8e\xa5\xe5\x8f\xa3\xe3\x80\x82" },
		{ "SoftMaterialInterface.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xbd\xaf\xe5\xbc\x95\xe7\x94\xa8\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
		{ "SoftMaterialInterface.Name", "EImageBrushResource::SoftMaterialInterface" },
		{ "SoftMaterialInterface.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xbd\xaf\xe5\xbc\x95\xe7\x94\xa8\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe3\x80\x82" },
		{ "SoftTexture2D.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe8\xbd\xaf\xe5\xbc\x95\xe7\x94\xa8Texture2D\xe3\x80\x82 */" },
		{ "SoftTexture2D.Name", "EImageBrushResource::SoftTexture2D" },
		{ "SoftTexture2D.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe8\xbd\xaf\xe5\xbc\x95\xe7\x94\xa8Texture2D\xe3\x80\x82" },
		{ "Texture2D.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaTexture2D\xe3\x80\x82 */" },
		{ "Texture2D.Name", "EImageBrushResource::Texture2D" },
		{ "Texture2D.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaTexture2D\xe3\x80\x82" },
		{ "Texture2DDynamic.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaTexture2DDynamic\xe3\x80\x82 */" },
		{ "Texture2DDynamic.Name", "EImageBrushResource::Texture2DDynamic" },
		{ "Texture2DDynamic.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaTexture2DDynamic\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""E\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7Resource\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EImageBrushResource::SlateBrush", (int64)EImageBrushResource::SlateBrush },
		{ "EImageBrushResource::SlateBrushAsset", (int64)EImageBrushResource::SlateBrushAsset },
		{ "EImageBrushResource::SlateTextureAtlasInterface", (int64)EImageBrushResource::SlateTextureAtlasInterface },
		{ "EImageBrushResource::MaterialInterface", (int64)EImageBrushResource::MaterialInterface },
		{ "EImageBrushResource::SoftMaterialInterface", (int64)EImageBrushResource::SoftMaterialInterface },
		{ "EImageBrushResource::Texture2D", (int64)EImageBrushResource::Texture2D },
		{ "EImageBrushResource::SoftTexture2D", (int64)EImageBrushResource::SoftTexture2D },
		{ "EImageBrushResource::Texture2DDynamic", (int64)EImageBrushResource::Texture2DDynamic },
		{ "EImageBrushResource::ResourceObject", (int64)EImageBrushResource::ResourceObject },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework,
	nullptr,
	"EImageBrushResource",
	"EImageBrushResource",
	Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource()
{
	if (!Z_Registration_Info_UEnum_EImageBrushResource.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EImageBrushResource.InnerSingleton, Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EImageBrushResource.InnerSingleton;
}
// ********** End Enum EImageBrushResource *********************************************************

// ********** Begin ScriptStruct FImageBrush *******************************************************
struct Z_Construct_UScriptStruct_FImageBrush_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FImageBrush); }
	static inline consteval int16 GetStructAlignment() { return alignof(FImageBrush); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb1\x87\xe6\x80\xbb\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7\xe5\x8c\x85\xe8\xa3\x85\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e Slate\xe3\x80\x81UMG \xe6\x88\x96\xe8\x93\x9d\xe5\x9b\xbe\xe5\x9c\xa8\xe5\x90\x8c\xe4\xb8\x80\xe7\xbb\x93\xe6\x9e\x84\xe4\xb8\xad\xe4\xbc\xa0\xe9\x80\x92\xe9\x85\x8d\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb1\x87\xe6\x80\xbb\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7\xe5\x8c\x85\xe8\xa3\x85\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e Slate\xe3\x80\x81UMG \xe6\x88\x96\xe8\x93\x9d\xe5\x9b\xbe\xe5\x9c\xa8\xe5\x90\x8c\xe4\xb8\x80\xe7\xbb\x93\xe6\x9e\x84\xe4\xb8\xad\xe4\xbc\xa0\xe9\x80\x92\xe9\x85\x8d\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ImageBrushResource_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xb0\xe5\xbd\x95\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7\xe5\xbd\x93\xe5\x89\x8d\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe8\xb5\x84\xe6\xba\x90\xe6\x9d\xa5\xe6\xba\x90\xef\xbc\x8c\xe9\xa9\xb1\xe5\x8a\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe6\x9d\xa1\xe4\xbb\xb6\xe6\x98\xbe\xe7\xa4\xba\xe5\x92\x8c\xe8\xa7\xa3\xe6\x9e\x90\xe5\x88\x86\xe6\x94\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xb0\xe5\xbd\x95\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7\xe5\xbd\x93\xe5\x89\x8d\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe8\xb5\x84\xe6\xba\x90\xe6\x9d\xa5\xe6\xba\x90\xef\xbc\x8c\xe9\xa9\xb1\xe5\x8a\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe6\x9d\xa1\xe4\xbb\xb6\xe6\x98\xbe\xe7\xa4\xba\xe5\x92\x8c\xe8\xa7\xa3\xe6\x9e\x90\xe5\x88\x86\xe6\x94\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlateBrush_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x9f\xe7\x94\x9f Slate \xe7\x94\xbb\xe5\x88\xb7\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\x9b\xe6\x97\xa0\xe9\x9c\x80\xe8\xb5\x84\xe6\xba\x90\xe8\xbd\xac\xe6\x8d\xa2\xe7\x9a\x84\xe8\xb7\xaf\xe5\xbe\x84\xe7\x9b\xb4\xe6\x8e\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "ImageBrushResource == EImageBrushResource::SlateBrush" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x9f\xe7\x94\x9f Slate \xe7\x94\xbb\xe5\x88\xb7\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\x9b\xe6\x97\xa0\xe9\x9c\x80\xe8\xb5\x84\xe6\xba\x90\xe8\xbd\xac\xe6\x8d\xa2\xe7\x9a\x84\xe8\xb7\xaf\xe5\xbe\x84\xe7\x9b\xb4\xe6\x8e\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlateBrushAsset_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98 Slate \xe7\x94\xbb\xe5\x88\xb7\xe8\xb5\x84\xe4\xba\xa7\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe8\xa7\xa3\xe6\x9e\x90\xe6\x97\xb6\xe8\xaf\xbb\xe5\x8f\x96\xe5\x85\xb6\xe5\x86\x85\xe9\x83\xa8\xe7\x94\xbb\xe5\x88\xb7\xe9\x85\x8d\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "ImageBrushResource == EImageBrushResource::SlateBrushAsset" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98 Slate \xe7\x94\xbb\xe5\x88\xb7\xe8\xb5\x84\xe4\xba\xa7\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe8\xa7\xa3\xe6\x9e\x90\xe6\x97\xb6\xe8\xaf\xbb\xe5\x8f\x96\xe5\x85\xb6\xe5\x86\x85\xe9\x83\xa8\xe7\x94\xbb\xe5\x88\xb7\xe9\x85\x8d\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlateTextureAtlasInterface_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98 Slate \xe7\xba\xb9\xe7\x90\x86\xe5\x9b\xbe\xe9\x9b\x86\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe6\x94\xaf\xe6\x8c\x81\xe4\xbb\x8e\xe5\x9b\xbe\xe9\x9b\x86\xe5\x8c\xba\xe5\x9f\x9f\xe5\x88\x9b\xe5\xbb\xba\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "ImageBrushResource == EImageBrushResource::SlateTextureAtlasInterface" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98 Slate \xe7\xba\xb9\xe7\x90\x86\xe5\x9b\xbe\xe9\x9b\x86\xe6\x8e\xa5\xe5\x8f\xa3\xef\xbc\x8c\xe6\x94\xaf\xe6\x8c\x81\xe4\xbb\x8e\xe5\x9b\xbe\xe9\x9b\x86\xe5\x8c\xba\xe5\x9f\x9f\xe5\x88\x9b\xe5\xbb\xba\xe5\x9b\xbe\xe7\x89\x87\xe7\x94\xbb\xe5\x88\xb7\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialInterface_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "ImageBrushResource == EImageBrushResource::MaterialInterface" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoftMaterialInterface_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbd\xaf\xe5\xbc\x95\xe7\x94\xa8\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "ImageBrushResource == EImageBrushResource::SoftMaterialInterface" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbd\xaf\xe5\xbc\x95\xe7\x94\xa8\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Texture2D_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98 Texture2D \xe8\xb5\x84\xe6\xba\x90\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe7\x94\xbb\xe5\x88\xb7\xe8\xa7\xa3\xe6\x9e\x90\xe6\x97\xb6\xe7\x94\x9f\xe6\x88\x90 Slate \xe8\xb5\x84\xe6\xba\x90\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "ImageBrushResource == EImageBrushResource::Texture2D" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98 Texture2D \xe8\xb5\x84\xe6\xba\x90\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe7\x94\xbb\xe5\x88\xb7\xe8\xa7\xa3\xe6\x9e\x90\xe6\x97\xb6\xe7\x94\x9f\xe6\x88\x90 Slate \xe8\xb5\x84\xe6\xba\x90\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SoftTexture2D_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xbd\xaf\xe5\xbc\x95\xe7\x94\xa8 Texture2D\xef\xbc\x8c\xe8\xa7\xa3\xe6\x9e\x90\xe7\x94\xbb\xe5\x88\xb7\xe6\x97\xb6\xe6\x8c\x89\xe9\x9c\x80\xe5\x8a\xa0\xe8\xbd\xbd\xe5\xae\x9e\xe9\x99\x85\xe8\xb5\x84\xe6\xba\x90\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "ImageBrushResource == EImageBrushResource::SoftTexture2D" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xbd\xaf\xe5\xbc\x95\xe7\x94\xa8 Texture2D\xef\xbc\x8c\xe8\xa7\xa3\xe6\x9e\x90\xe7\x94\xbb\xe5\x88\xb7\xe6\x97\xb6\xe6\x8c\x89\xe9\x9c\x80\xe5\x8a\xa0\xe8\xbd\xbd\xe5\xae\x9e\xe9\x99\x85\xe8\xb5\x84\xe6\xba\x90\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Texture2DDynamic_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8a\xa8\xe6\x80\x81 Texture2D \xe8\xb5\x84\xe6\xba\x90\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x94\xbb\xe5\x88\xb7\xe8\xa7\xa3\xe6\x9e\x90\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "ImageBrushResource == EImageBrushResource::Texture2DDynamic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8a\xa8\xe6\x80\x81 Texture2D \xe8\xb5\x84\xe6\xba\x90\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe7\x94\xbb\xe5\x88\xb7\xe8\xa7\xa3\xe6\x9e\x90\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ResourceObject_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe8\xb5\x84\xe6\xba\x90\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "ImageBrushResource == EImageBrushResource::ResourceObject" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe8\xb5\x84\xe6\xba\x90\xe5\xaf\xb9\xe8\xb1\xa1\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MatchSize_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xb0\xe5\xbd\x95\xe5\x8c\xb9\xe9\x85\x8d\xe5\xb0\xba\xe5\xaf\xb8\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x9c\xa8\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe3\x80\x81\xe5\x90\x8c\xe6\xad\xa5\xe6\x88\x96\xe8\xbe\x93\xe5\x85\xa5\xe6\xb5\x81\xe7\xa8\x8b\xe4\xb8\xad\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "ImageBrushResource == EImageBrushResource::SlateTextureAtlasInterface || ImageBrushResource == EImageBrushResource::Texture2D || ImageBrushResource == EImageBrushResource::SoftTexture2D || ImageBrushResource == EImageBrushResource::Texture2DDynamic" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xb0\xe5\xbd\x95\xe5\x8c\xb9\xe9\x85\x8d\xe5\xb0\xba\xe5\xaf\xb8\xef\xbc\x8c\xe7\x94\xa8\xe4\xba\x8e\xe5\x9c\xa8\xe7\x94\x9f\xe5\x91\xbd\xe5\x91\xa8\xe6\x9c\x9f\xe3\x80\x81\xe5\x90\x8c\xe6\xad\xa5\xe6\x88\x96\xe8\xbe\x93\xe5\x85\xa5\xe6\xb5\x81\xe7\xa8\x8b\xe4\xb8\xad\xe9\x80\x89\xe6\x8b\xa9\xe5\x90\x8e\xe7\xbb\xad\xe8\xb7\xaf\xe5\xbe\x84\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Size_MetaData[] = {
		{ "Category", "Image Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xbb\xe5\x88\xb7\xe7\x9b\xae\xe6\xa0\x87\xe5\xb0\xba\xe5\xaf\xb8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe6\x97\xa0\xe6\xb3\x95\xe8\x87\xaa\xe5\x8a\xa8\xe5\x8c\xb9\xe9\x85\x8d\xe5\xb0\xba\xe5\xaf\xb8\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe7\x94\xbb\xe5\x88\xb7\xe7\x9b\xae\xe6\xa0\x87\xe5\xb0\xba\xe5\xaf\xb8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe6\x97\xa0\xe6\xb3\x95\xe8\x87\xaa\xe5\x8a\xa8\xe5\x8c\xb9\xe9\x85\x8d\xe5\xb0\xba\xe5\xaf\xb8\xe6\x97\xb6\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FImageBrush constinit property declarations ***********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_ImageBrushResource_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_ImageBrushResource;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SlateBrush;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlateBrushAsset;
	static const UECodeGen_Private::FInterfacePropertyParams NewProp_SlateTextureAtlasInterface;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterialInterface;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SoftMaterialInterface;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture2D;
	static const UECodeGen_Private::FSoftObjectPropertyParams NewProp_SoftTexture2D;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture2DDynamic;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ResourceObject;
	static void NewProp_MatchSize_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_MatchSize;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Size;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FImageBrush constinit property declarations *************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FImageBrush>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FImageBrush_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FImageBrush;
class UScriptStruct* FImageBrush::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FImageBrush.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FImageBrush.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FImageBrush, (UObject*)Z_Construct_UPackage__Script_GenericSlateFramework(), TEXT("ImageBrush"));
	}
	return Z_Registration_Info_UScriptStruct_FImageBrush.OuterSingleton;
	}

// ********** Begin ScriptStruct FImageBrush Property Definitions **********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_ImageBrushResource_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_ImageBrushResource = { "ImageBrushResource", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, ImageBrushResource), Z_Construct_UEnum_GenericSlateFramework_EImageBrushResource, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ImageBrushResource_MetaData), NewProp_ImageBrushResource_MetaData) }; // 599414836
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_SlateBrush = { "SlateBrush", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, SlateBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlateBrush_MetaData), NewProp_SlateBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_SlateBrushAsset = { "SlateBrushAsset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, SlateBrushAsset), Z_Construct_UClass_USlateBrushAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlateBrushAsset_MetaData), NewProp_SlateBrushAsset_MetaData) };
const UECodeGen_Private::FInterfacePropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_SlateTextureAtlasInterface = { "SlateTextureAtlasInterface", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Interface, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, SlateTextureAtlasInterface), Z_Construct_UClass_USlateTextureAtlasInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlateTextureAtlasInterface_MetaData), NewProp_SlateTextureAtlasInterface_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_MaterialInterface = { "MaterialInterface", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, MaterialInterface), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialInterface_MetaData), NewProp_MaterialInterface_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_SoftMaterialInterface = { "SoftMaterialInterface", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, SoftMaterialInterface), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoftMaterialInterface_MetaData), NewProp_SoftMaterialInterface_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_Texture2D = { "Texture2D", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, Texture2D), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Texture2D_MetaData), NewProp_Texture2D_MetaData) };
const UECodeGen_Private::FSoftObjectPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_SoftTexture2D = { "SoftTexture2D", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::SoftObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, SoftTexture2D), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SoftTexture2D_MetaData), NewProp_SoftTexture2D_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_Texture2DDynamic = { "Texture2DDynamic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, Texture2DDynamic), Z_Construct_UClass_UTexture2DDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Texture2DDynamic_MetaData), NewProp_Texture2DDynamic_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_ResourceObject = { "ResourceObject", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, ResourceObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ResourceObject_MetaData), NewProp_ResourceObject_MetaData) };
void Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_MatchSize_SetBit(void* Obj)
{
	((FImageBrush*)Obj)->MatchSize = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_MatchSize = { "MatchSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FImageBrush), &Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_MatchSize_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MatchSize_MetaData), NewProp_MatchSize_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_Size = { "Size", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FImageBrush, Size), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Size_MetaData), NewProp_Size_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FImageBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_ImageBrushResource_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_ImageBrushResource,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_SlateBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_SlateBrushAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_SlateTextureAtlasInterface,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_MaterialInterface,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_SoftMaterialInterface,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_Texture2D,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_SoftTexture2D,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_Texture2DDynamic,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_ResourceObject,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_MatchSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FImageBrush_Statics::NewProp_Size,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FImageBrush_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FImageBrush Property Definitions ************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FImageBrush_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
	nullptr,
	&NewStructOps,
	"ImageBrush",
	Z_Construct_UScriptStruct_FImageBrush_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FImageBrush_Statics::PropPointers),
	sizeof(FImageBrush),
	alignof(FImageBrush),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FImageBrush_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FImageBrush_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FImageBrush()
{
	if (!Z_Registration_Info_UScriptStruct_FImageBrush.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FImageBrush.InnerSingleton, Z_Construct_UScriptStruct_FImageBrush_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FImageBrush.InnerSingleton);
}
// ********** End ScriptStruct FImageBrush *********************************************************

// ********** Begin Enum EBorderBrushResource ******************************************************
static FEnumRegistrationInfo Z_Registration_Info_UEnum_EBorderBrushResource;
static UEnum* EBorderBrushResource_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_EBorderBrushResource.OuterSingleton)
	{
		Z_Registration_Info_UEnum_EBorderBrushResource.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource, (UObject*)Z_Construct_UPackage__Script_GenericSlateFramework(), TEXT("EBorderBrushResource"));
	}
	return Z_Registration_Info_UEnum_EBorderBrushResource.OuterSingleton;
}
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EBorderBrushResource>()
{
	return EBorderBrushResource_StaticEnum();
}
struct Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\xae\x9a\xe4\xb9\x89""E\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7Resource\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82 */" },
#endif
		{ "MaterialInterface.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xba\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe3\x80\x82 */" },
		{ "MaterialInterface.Name", "EBorderBrushResource::MaterialInterface" },
		{ "MaterialInterface.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xba\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe3\x80\x82" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
		{ "SlateBrush.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaSlate\xe7\x94\xbb\xe5\x88\xb7\xe3\x80\x82 */" },
		{ "SlateBrush.Name", "EBorderBrushResource::SlateBrush" },
		{ "SlateBrush.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaSlate\xe7\x94\xbb\xe5\x88\xb7\xe3\x80\x82" },
		{ "SlateBrushAsset.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaSlate\xe7\x94\xbb\xe5\x88\xb7\xe8\xb5\x84\xe4\xba\xa7\xe3\x80\x82 */" },
		{ "SlateBrushAsset.Name", "EBorderBrushResource::SlateBrushAsset" },
		{ "SlateBrushAsset.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaSlate\xe7\x94\xbb\xe5\x88\xb7\xe8\xb5\x84\xe4\xba\xa7\xe3\x80\x82" },
		{ "Texture2D.Comment", "/** \xe8\xa1\xa8\xe7\xa4\xbaTexture2D\xe3\x80\x82 */" },
		{ "Texture2D.Name", "EBorderBrushResource::Texture2D" },
		{ "Texture2D.ToolTip", "\xe8\xa1\xa8\xe7\xa4\xbaTexture2D\xe3\x80\x82" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\xae\x9a\xe4\xb9\x89""E\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7Resource\xe6\x9e\x9a\xe4\xb8\xbe\xef\xbc\x8c\xe7\xbb\x9f\xe4\xb8\x80 C++\xe3\x80\x81\xe8\x93\x9d\xe5\x9b\xbe\xe5\x92\x8c\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe9\x85\x8d\xe7\xbd\xae\xe4\xb8\xad\xe7\x9a\x84\xe5\x88\x86\xe6\x94\xaf\xe8\xaf\xad\xe4\xb9\x89\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "EBorderBrushResource::SlateBrush", (int64)EBorderBrushResource::SlateBrush },
		{ "EBorderBrushResource::SlateBrushAsset", (int64)EBorderBrushResource::SlateBrushAsset },
		{ "EBorderBrushResource::MaterialInterface", (int64)EBorderBrushResource::MaterialInterface },
		{ "EBorderBrushResource::Texture2D", (int64)EBorderBrushResource::Texture2D },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
}; // struct Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource_Statics 
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_GenericSlateFramework,
	nullptr,
	"EBorderBrushResource",
	"EBorderBrushResource",
	Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource()
{
	if (!Z_Registration_Info_UEnum_EBorderBrushResource.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EBorderBrushResource.InnerSingleton, Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_EBorderBrushResource.InnerSingleton;
}
// ********** End Enum EBorderBrushResource ********************************************************

// ********** Begin ScriptStruct FBorderBrush ******************************************************
struct Z_Construct_UScriptStruct_FBorderBrush_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FBorderBrush); }
	static inline consteval int16 GetStructAlignment() { return alignof(FBorderBrush); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\xb1\x87\xe6\x80\xbb\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7\xe5\x8c\x85\xe8\xa3\x85\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e Slate\xe3\x80\x81UMG \xe6\x88\x96\xe8\x93\x9d\xe5\x9b\xbe\xe5\x9c\xa8\xe5\x90\x8c\xe4\xb8\x80\xe7\xbb\x93\xe6\x9e\x84\xe4\xb8\xad\xe4\xbc\xa0\xe9\x80\x92\xe9\x85\x8d\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\xb1\x87\xe6\x80\xbb\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7\xe5\x8c\x85\xe8\xa3\x85\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\xbf\xe4\xba\x8e Slate\xe3\x80\x81UMG \xe6\x88\x96\xe8\x93\x9d\xe5\x9b\xbe\xe5\x9c\xa8\xe5\x90\x8c\xe4\xb8\x80\xe7\xbb\x93\xe6\x9e\x84\xe4\xb8\xad\xe4\xbc\xa0\xe9\x80\x92\xe9\x85\x8d\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BoderBrushResource_MetaData[] = {
		{ "Category", "Border Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe8\xae\xb0\xe5\xbd\x95\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7\xe5\xbd\x93\xe5\x89\x8d\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe8\xb5\x84\xe6\xba\x90\xe6\x9d\xa5\xe6\xba\x90\xef\xbc\x8c\xe9\xa9\xb1\xe5\x8a\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe6\x9d\xa1\xe4\xbb\xb6\xe6\x98\xbe\xe7\xa4\xba\xe5\x92\x8c\xe8\xa7\xa3\xe6\x9e\x90\xe5\x88\x86\xe6\x94\xaf\xe3\x80\x82 */" },
#endif
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe8\xae\xb0\xe5\xbd\x95\xe8\xbe\xb9\xe6\xa1\x86\xe7\x94\xbb\xe5\x88\xb7\xe5\xbd\x93\xe5\x89\x8d\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe8\xb5\x84\xe6\xba\x90\xe6\x9d\xa5\xe6\xba\x90\xef\xbc\x8c\xe9\xa9\xb1\xe5\x8a\xa8\xe7\xbc\x96\xe8\xbe\x91\xe5\x99\xa8\xe6\x9d\xa1\xe4\xbb\xb6\xe6\x98\xbe\xe7\xa4\xba\xe5\x92\x8c\xe8\xa7\xa3\xe6\x9e\x90\xe5\x88\x86\xe6\x94\xaf\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlateBrush_MetaData[] = {
		{ "Category", "Border Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x9f\xe7\x94\x9f Slate \xe7\x94\xbb\xe5\x88\xb7\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\x9b\xe6\x97\xa0\xe9\x9c\x80\xe8\xb5\x84\xe6\xba\x90\xe8\xbd\xac\xe6\x8d\xa2\xe7\x9a\x84\xe8\xb7\xaf\xe5\xbe\x84\xe7\x9b\xb4\xe6\x8e\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "BoderBrushResource == EBorderBrushResource::SlateBrush" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe5\x8e\x9f\xe7\x94\x9f Slate \xe7\x94\xbb\xe5\x88\xb7\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe4\xbe\x9b\xe6\x97\xa0\xe9\x9c\x80\xe8\xb5\x84\xe6\xba\x90\xe8\xbd\xac\xe6\x8d\xa2\xe7\x9a\x84\xe8\xb7\xaf\xe5\xbe\x84\xe7\x9b\xb4\xe6\x8e\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SlateBrushAsset_MetaData[] = {
		{ "Category", "Border Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98 Slate \xe7\x94\xbb\xe5\x88\xb7\xe8\xb5\x84\xe4\xba\xa7\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe8\xa7\xa3\xe6\x9e\x90\xe6\x97\xb6\xe8\xaf\xbb\xe5\x8f\x96\xe5\x85\xb6\xe5\x86\x85\xe9\x83\xa8\xe7\x94\xbb\xe5\x88\xb7\xe9\x85\x8d\xe7\xbd\xae\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "BoderBrushResource == EBorderBrushResource::SlateBrushAsset" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98 Slate \xe7\x94\xbb\xe5\x88\xb7\xe8\xb5\x84\xe4\xba\xa7\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe8\xa7\xa3\xe6\x9e\x90\xe6\x97\xb6\xe8\xaf\xbb\xe5\x8f\x96\xe5\x85\xb6\xe5\x86\x85\xe9\x83\xa8\xe7\x94\xbb\xe5\x88\xb7\xe9\x85\x8d\xe7\xbd\xae\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaterialInterface_MetaData[] = {
		{ "Category", "Border Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "BoderBrushResource == EBorderBrushResource::MaterialInterface" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98\xe6\x9d\x90\xe8\xb4\xa8\xe6\x8e\xa5\xe5\x8f\xa3\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe8\xb5\x84\xe6\xba\x90\xe8\xa7\xa3\xe6\x9e\x90\xe3\x80\x81\xe8\xb5\x84\xe4\xba\xa7\xe5\x88\x9b\xe5\xbb\xba\xe6\x88\x96\xe6\x8e\xa7\xe4\xbb\xb6\xe5\x90\x8c\xe6\xad\xa5\xe4\xbd\xbf\xe7\x94\xa8\xe3\x80\x82" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Texture2D_MetaData[] = {
		{ "Category", "Border Brush" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe4\xbf\x9d\xe5\xad\x98 Texture2D \xe8\xb5\x84\xe6\xba\x90\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe7\x94\xbb\xe5\x88\xb7\xe8\xa7\xa3\xe6\x9e\x90\xe6\x97\xb6\xe7\x94\x9f\xe6\x88\x90 Slate \xe8\xb5\x84\xe6\xba\x90\xe3\x80\x82 */" },
#endif
		{ "EditCondition", "BoderBrushResource == EBorderBrushResource::Texture2D" },
		{ "EditConditionHides", "" },
		{ "ModuleRelativePath", "Public/SlateType.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe4\xbf\x9d\xe5\xad\x98 Texture2D \xe8\xb5\x84\xe6\xba\x90\xe5\xbc\x95\xe7\x94\xa8\xef\xbc\x8c\xe4\xbe\x9b\xe7\x94\xbb\xe5\x88\xb7\xe8\xa7\xa3\xe6\x9e\x90\xe6\x97\xb6\xe7\x94\x9f\xe6\x88\x90 Slate \xe8\xb5\x84\xe6\xba\x90\xe3\x80\x82" },
#endif
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FBorderBrush constinit property declarations **********************
	static const UECodeGen_Private::FBytePropertyParams NewProp_BoderBrushResource_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_BoderBrushResource;
	static const UECodeGen_Private::FStructPropertyParams NewProp_SlateBrush;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SlateBrushAsset;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MaterialInterface;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture2D;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FBorderBrush constinit property declarations ************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBorderBrush>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FBorderBrush_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FBorderBrush;
class UScriptStruct* FBorderBrush::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FBorderBrush.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FBorderBrush.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FBorderBrush, (UObject*)Z_Construct_UPackage__Script_GenericSlateFramework(), TEXT("BorderBrush"));
	}
	return Z_Registration_Info_UScriptStruct_FBorderBrush.OuterSingleton;
	}

// ********** Begin ScriptStruct FBorderBrush Property Definitions *********************************
const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_BoderBrushResource_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_BoderBrushResource = { "BoderBrushResource", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBorderBrush, BoderBrushResource), Z_Construct_UEnum_GenericSlateFramework_EBorderBrushResource, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BoderBrushResource_MetaData), NewProp_BoderBrushResource_MetaData) }; // 1413317999
const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_SlateBrush = { "SlateBrush", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBorderBrush, SlateBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlateBrush_MetaData), NewProp_SlateBrush_MetaData) }; // 4278521822
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_SlateBrushAsset = { "SlateBrushAsset", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBorderBrush, SlateBrushAsset), Z_Construct_UClass_USlateBrushAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SlateBrushAsset_MetaData), NewProp_SlateBrushAsset_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_MaterialInterface = { "MaterialInterface", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBorderBrush, MaterialInterface), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaterialInterface_MetaData), NewProp_MaterialInterface_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_Texture2D = { "Texture2D", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBorderBrush, Texture2D), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Texture2D_MetaData), NewProp_Texture2D_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBorderBrush_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_BoderBrushResource_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_BoderBrushResource,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_SlateBrush,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_SlateBrushAsset,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_MaterialInterface,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBorderBrush_Statics::NewProp_Texture2D,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBorderBrush_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FBorderBrush Property Definitions ***********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBorderBrush_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_GenericSlateFramework,
	nullptr,
	&NewStructOps,
	"BorderBrush",
	Z_Construct_UScriptStruct_FBorderBrush_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBorderBrush_Statics::PropPointers),
	sizeof(FBorderBrush),
	alignof(FBorderBrush),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBorderBrush_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FBorderBrush_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FBorderBrush()
{
	if (!Z_Registration_Info_UScriptStruct_FBorderBrush.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FBorderBrush.InnerSingleton, Z_Construct_UScriptStruct_FBorderBrush_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FBorderBrush.InnerSingleton);
}
// ********** End ScriptStruct FBorderBrush ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SlateType_h__Script_GenericSlateFramework_Statics
{
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ EImageBrushResource_StaticEnum, TEXT("EImageBrushResource"), &Z_Registration_Info_UEnum_EImageBrushResource, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 599414836U) },
		{ EBorderBrushResource_StaticEnum, TEXT("EBorderBrushResource"), &Z_Registration_Info_UEnum_EBorderBrushResource, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1413317999U) },
	};
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FImageBrush::StaticStruct, Z_Construct_UScriptStruct_FImageBrush_Statics::NewStructOps, TEXT("ImageBrush"),&Z_Registration_Info_UScriptStruct_FImageBrush, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FImageBrush), 799750334U) },
		{ FBorderBrush::StaticStruct, Z_Construct_UScriptStruct_FBorderBrush_Statics::NewStructOps, TEXT("BorderBrush"),&Z_Registration_Info_UScriptStruct_FBorderBrush, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FBorderBrush), 2746457749U) },
	};
}; // Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SlateType_h__Script_GenericSlateFramework_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SlateType_h__Script_GenericSlateFramework_2907140328{
	TEXT("/Script/GenericSlateFramework"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SlateType_h__Script_GenericSlateFramework_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SlateType_h__Script_GenericSlateFramework_Statics::ScriptStructInfo),
	Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SlateType_h__Script_GenericSlateFramework_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SlateType_h__Script_GenericSlateFramework_Statics::EnumInfo),
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
