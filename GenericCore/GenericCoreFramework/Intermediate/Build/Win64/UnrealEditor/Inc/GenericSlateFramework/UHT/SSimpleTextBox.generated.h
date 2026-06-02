// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SWidget/SSimpleTextBox.h"

#ifdef GENERICSLATEFRAMEWORK_SSimpleTextBox_generated_h
#error "SSimpleTextBox.generated.h already included, missing '#pragma once' in SSimpleTextBox.h"
#endif
#define GENERICSLATEFRAMEWORK_SSimpleTextBox_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/NoDestroy.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_GenericSlateFramework_Public_SWidget_SSimpleTextBox_h

// ********** Begin Enum ESimpleTextBoxType ********************************************************
#define FOREACH_ENUM_ESIMPLETEXTBOXTYPE(op) \
	op(ESimpleTextBoxType::Horizontal) \
	op(ESimpleTextBoxType::Vertical) \
	op(ESimpleTextBoxType::HorizontalReversal) \
	op(ESimpleTextBoxType::VerticalReversal) 

enum class ESimpleTextBoxType : uint8;
template<> struct TIsUEnumClass<ESimpleTextBoxType> { enum { Value = true }; };
template<> GENERICSLATEFRAMEWORK_NON_ATTRIBUTED_API UEnum* StaticEnum<ESimpleTextBoxType>();
// ********** End Enum ESimpleTextBoxType **********************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
