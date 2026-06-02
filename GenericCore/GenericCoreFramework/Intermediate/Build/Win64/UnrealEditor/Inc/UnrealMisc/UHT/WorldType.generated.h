// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Type/WorldType.h"

#ifdef UNREALMISC_WorldType_generated_h
#error "WorldType.generated.h already included, missing '#pragma once' in WorldType.h"
#endif
#define UNREALMISC_WorldType_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/NoDestroy.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_WorldType_h

// ********** Begin Enum EWorldTypeBP **************************************************************
#define FOREACH_ENUM_EWORLDTYPEBP(op) \
	op(EWorldTypeBP::None) \
	op(EWorldTypeBP::Game) \
	op(EWorldTypeBP::Editor) \
	op(EWorldTypeBP::PIE) \
	op(EWorldTypeBP::EditorPreview) \
	op(EWorldTypeBP::GamePreview) \
	op(EWorldTypeBP::GameRPC) \
	op(EWorldTypeBP::Inactive) 

enum class EWorldTypeBP : uint8;
template<> struct TIsUEnumClass<EWorldTypeBP> { enum { Value = true }; };
template<> UNREALMISC_NON_ATTRIBUTED_API UEnum* StaticEnum<EWorldTypeBP>();
// ********** End Enum EWorldTypeBP ****************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
