// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/** 定义EDayInWeek枚举，统一 C++、蓝图和编辑器配置中的分支语义。 */
UENUM(BlueprintType)
enum class EDayInWeek : uint8
{
	/** 表示星期一。 */
	Monday,

	/** 表示星期二。 */
	Tuesday,

	/** 表示星期三。 */
	Wednesday,

	/** 表示星期四。 */
	Thursday,

	/** 表示星期五。 */
	Friday,

	/** 表示星期六。 */
	Saturday,

	/** 表示星期日。 */
	Sunday
};

/** 转换ToDayOfWeek，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
static EDayOfWeek ConvToDayOfWeek(EDayInWeek DayInWeek)
{
	switch (DayInWeek)
	{
	case EDayInWeek::Monday:
		return EDayOfWeek::Monday;
	case EDayInWeek::Tuesday:
		return EDayOfWeek::Tuesday;
	case EDayInWeek::Wednesday:
		return EDayOfWeek::Wednesday;
	case EDayInWeek::Thursday:
		return EDayOfWeek::Thursday;
	case EDayInWeek::Friday:
		return EDayOfWeek::Friday;
	case EDayInWeek::Saturday:
		return EDayOfWeek::Saturday;
	case EDayInWeek::Sunday:
		return EDayOfWeek::Sunday;
	}

	return EDayOfWeek::Monday;
}

/** 转换ToDayInWeek，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
static EDayInWeek ConvToDayInWeek(EDayOfWeek DayOfWeek)
{
	switch (DayOfWeek)
	{
	case EDayOfWeek::Monday:
		return EDayInWeek::Monday;
	case EDayOfWeek::Tuesday:
		return EDayInWeek::Tuesday;
	case EDayOfWeek::Wednesday:
		return EDayInWeek::Wednesday;
	case EDayOfWeek::Thursday:
		return EDayInWeek::Thursday;
	case EDayOfWeek::Friday:
		return EDayInWeek::Friday;
	case EDayOfWeek::Saturday:
		return EDayInWeek::Saturday;
	case EDayOfWeek::Sunday:
		return EDayInWeek::Sunday;
	}

	return EDayInWeek::Monday;
}

/** 定义EMonthInYear枚举，统一 C++、蓝图和编辑器配置中的分支语义。 */
UENUM(BlueprintType)
enum class EMonthInYear : uint8
{
	/** 表示一月。 */
	January,

	/** 表示二月。 */
	February,

	/** 表示三月。 */
	March,

	/** 表示四月。 */
	April,

	/** 表示五月。 */
	May,

	/** 表示六月。 */
	June,

	/** 表示七月。 */
	July,

	/** 表示八月。 */
	August,

	/** 表示九月。 */
	September,

	/** 表示十月。 */
	October,

	/** 表示十一月。 */
	November,

	/** 表示十二月。 */
	December
};

/** 转换ToMonthOfYear，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
static EMonthOfYear ConvToMonthOfYear(EMonthInYear MonthInYear)
{
	switch (MonthInYear)
	{
	case EMonthInYear::January:
		return EMonthOfYear::January;
	case EMonthInYear::February:
		return EMonthOfYear::February;
	case EMonthInYear::March:
		return EMonthOfYear::March;
	case EMonthInYear::April:
		return EMonthOfYear::April;
	case EMonthInYear::May:
		return EMonthOfYear::May;
	case EMonthInYear::June:
		return EMonthOfYear::June;
	case EMonthInYear::July:
		return EMonthOfYear::July;
	case EMonthInYear::August:
		return EMonthOfYear::August;
	case EMonthInYear::September:
		return EMonthOfYear::September;
	case EMonthInYear::October:
		return EMonthOfYear::October;
	case EMonthInYear::November:
		return EMonthOfYear::November;
	case EMonthInYear::December:
		return EMonthOfYear::December;
	}

	return EMonthOfYear::January;
}

/** 转换ToMonthInYear，保持蓝图暴露类型与 Unreal 原生类型的语义一致。 */
static EMonthInYear ConvToMonthInYear(EMonthOfYear MonthOfYear)
{
	switch (MonthOfYear)
	{
	case EMonthOfYear::January:
		return EMonthInYear::January;
	case EMonthOfYear::February:
		return EMonthInYear::February;
	case EMonthOfYear::March:
		return EMonthInYear::March;
	case EMonthOfYear::April:
		return EMonthInYear::April;
	case EMonthOfYear::May:
		return EMonthInYear::May;
	case EMonthOfYear::June:
		return EMonthInYear::June;
	case EMonthOfYear::July:
		return EMonthInYear::July;
	case EMonthOfYear::August:
		return EMonthInYear::August;
	case EMonthOfYear::September:
		return EMonthInYear::September;
	case EMonthOfYear::October:
		return EMonthInYear::October;
	case EMonthOfYear::November:
		return EMonthInYear::November;
	case EMonthOfYear::December:
		return EMonthInYear::December;
	}

	return EMonthInYear::January;
}
