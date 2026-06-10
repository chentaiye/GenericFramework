// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericWindowType.generated.h"


/** 定义通用窗口Drag策略取值。 */
UENUM(BlueprintType)
enum class EGenericWindowDragPolicy : uint8
{
	/** 表示通用窗口Drag策略中的In视口Only分支。 */
	InViewportOnly UMETA(DisplayName="In Viewport Only"),

	/** 表示通用窗口Drag策略中的AllowOutOf视口分支。 */
	AllowOutOfViewport UMETA(DisplayName="Allow Out Of Viewport")
};

/** 定义通用In游戏窗口显示状态取值。 */
UENUM(BlueprintType)
enum class EGenericInGameWindowDisplayState : uint8
{
	/** 表示通用In游戏窗口Display状态中的Expanded分支。 */
	Expanded UMETA(DisplayName="Expanded"),

	/** 表示通用In游戏窗口Display状态中的CollapsedTo标题栏分支。 */
	CollapsedToTitleBar UMETA(DisplayName="Collapsed To Title Bar")
};

/** 定义通用 UI使用的通用窗口Resize句柄取值范围。 */
enum class EGenericWindowResizeHandle : uint8
{
	/** 表示无选项。 */
	None,

	/** 表示Left选项。 */
	Left,

	/** 表示向右选项。 */
	Right,

	/** 表示Top选项。 */
	Top,

	/** 表示Bottom选项。 */
	Bottom,

	/** 表示Top Left选项。 */
	TopLeft,

	/** 表示Top向右选项。 */
	TopRight,

	/** 表示Bottom Left选项。 */
	BottomLeft,

	/** 表示Bottom向右选项。 */
	BottomRight
};

/** 封装通用窗口矩形。 */
USTRUCT(BlueprintType)
struct GENERICWINDOWFRAMEWORK_API FGenericWindowRect
{
	GENERATED_BODY()

	/** 记录Position。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window")
	FVector2D Position = FVector2D::ZeroVector;

	/** 记录大小。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Window")
	FVector2D Size=FVector2D(640.0f, 480.0f);
};
