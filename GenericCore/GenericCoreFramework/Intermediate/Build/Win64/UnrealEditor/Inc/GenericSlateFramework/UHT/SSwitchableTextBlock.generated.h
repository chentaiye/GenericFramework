// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SWidget/SSwitchableTextBlock.h"

#ifdef GENERICSLATEFRAMEWORK_SSwitchableTextBlock_generated_h
#error "SSwitchableTextBlock.generated.h already included, missing '#pragma once' in SSwitchableTextBlock.h"
#endif
#define GENERICSLATEFRAMEWORK_SSwitchableTextBlock_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/NoDestroy.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSwitchableTextBlock_h

// ********** Begin Enum ESwitchableTextBlockMode **************************************************
#define FOREACH_ENUM_ESWITCHABLETEXTBLOCKMODE(op) \
	op(ESwitchableTextBlockMode::Display) \
	op(ESwitchableTextBlockMode::Editable) 

enum class ESwitchableTextBlockMode : uint8;
template<> struct TIsUEnumClass<ESwitchableTextBlockMode> { enum { Value = true }; };
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<ESwitchableTextBlockMode>();
// ********** End Enum ESwitchableTextBlockMode ****************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
