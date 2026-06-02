// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SlateType.h"

#ifdef GENERICSLATEFRAMEWORK_SlateType_generated_h
#error "SlateType.generated.h already included, missing '#pragma once' in SlateType.h"
#endif
#define GENERICSLATEFRAMEWORK_SlateType_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin ScriptStruct FImageBrush *******************************************************
struct Z_Construct_UScriptStruct_FImageBrush_Statics;
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SlateType_h_56_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FImageBrush_Statics; \
	static class UScriptStruct* StaticStruct();


struct FImageBrush;
// ********** End ScriptStruct FImageBrush *********************************************************

// ********** Begin ScriptStruct FBorderBrush ******************************************************
struct Z_Construct_UScriptStruct_FBorderBrush_Statics;
#define FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SlateType_h_159_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FBorderBrush_Statics; \
	static class UScriptStruct* StaticStruct();


struct FBorderBrush;
// ********** End ScriptStruct FBorderBrush ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SlateType_h

// ********** Begin Enum EImageBrushResource *******************************************************
#define FOREACH_ENUM_EIMAGEBRUSHRESOURCE(op) \
	op(EImageBrushResource::SlateBrush) \
	op(EImageBrushResource::SlateBrushAsset) \
	op(EImageBrushResource::SlateTextureAtlasInterface) \
	op(EImageBrushResource::MaterialInterface) \
	op(EImageBrushResource::SoftMaterialInterface) \
	op(EImageBrushResource::Texture2D) \
	op(EImageBrushResource::SoftTexture2D) \
	op(EImageBrushResource::Texture2DDynamic) \
	op(EImageBrushResource::ResourceObject) 

enum class EImageBrushResource : uint8;
template<> struct TIsUEnumClass<EImageBrushResource> { enum { Value = true }; };
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EImageBrushResource>();
// ********** End Enum EImageBrushResource *********************************************************

// ********** Begin Enum EBorderBrushResource ******************************************************
#define FOREACH_ENUM_EBORDERBRUSHRESOURCE(op) \
	op(EBorderBrushResource::SlateBrush) \
	op(EBorderBrushResource::SlateBrushAsset) \
	op(EBorderBrushResource::MaterialInterface) \
	op(EBorderBrushResource::Texture2D) 

enum class EBorderBrushResource : uint8;
template<> struct TIsUEnumClass<EBorderBrushResource> { enum { Value = true }; };
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<EBorderBrushResource>();
// ********** End Enum EBorderBrushResource ********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
