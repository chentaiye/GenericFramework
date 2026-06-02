// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Type/DateTimeType.h"

#ifdef UNREALMISC_DateTimeType_generated_h
#error "DateTimeType.generated.h already included, missing '#pragma once' in DateTimeType.h"
#endif
#define UNREALMISC_DateTimeType_generated_h

#include "Templates/IsUEnumClass.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "Templates/NoDestroy.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Project_DevProject_Plugins_GenericFramework_GenericCore_GenericCoreFramework_Source_UnrealMisc_Public_Type_DateTimeType_h

// ********** Begin Enum EDayInWeek ****************************************************************
#define FOREACH_ENUM_EDAYINWEEK(op) \
	op(EDayInWeek::Monday) \
	op(EDayInWeek::Tuesday) \
	op(EDayInWeek::Wednesday) \
	op(EDayInWeek::Thursday) \
	op(EDayInWeek::Friday) \
	op(EDayInWeek::Saturday) \
	op(EDayInWeek::Sunday) 

enum class EDayInWeek : uint8;
template<> struct TIsUEnumClass<EDayInWeek> { enum { Value = true }; };
template<> UNREALMISC_NON_ATTRIBUTED_API UEnum* StaticEnum<EDayInWeek>();
// ********** End Enum EDayInWeek ******************************************************************

// ********** Begin Enum EMonthInYear **************************************************************
#define FOREACH_ENUM_EMONTHINYEAR(op) \
	op(EMonthInYear::January) \
	op(EMonthInYear::February) \
	op(EMonthInYear::March) \
	op(EMonthInYear::April) \
	op(EMonthInYear::May) \
	op(EMonthInYear::June) \
	op(EMonthInYear::July) \
	op(EMonthInYear::August) \
	op(EMonthInYear::September) \
	op(EMonthInYear::October) \
	op(EMonthInYear::November) \
	op(EMonthInYear::December) 

enum class EMonthInYear : uint8;
template<> struct TIsUEnumClass<EMonthInYear> { enum { Value = true }; };
template<> UNREALMISC_NON_ATTRIBUTED_API UEnum* StaticEnum<EMonthInYear>();
// ********** End Enum EMonthInYear ****************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
