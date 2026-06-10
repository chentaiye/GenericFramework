// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericWindowType.h"
#include "UObject/Object.h"
#include "GenericWindowRuntimeState.generated.h"

class UGenericWindowDescriptor;

/** 作为窗口运行时状态能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI, BlueprintType)
class UGenericWindowRuntimeState : public UObject
{
	GENERATED_BODY()

public:
	/** 初始化通用窗口运行时状态默认状态。 */
	GENERICWINDOWFRAMEWORK_API UGenericWindowRuntimeState();

	/** 初始化来源Descriptor，使运行时状态与输入配置保持一致。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void InitializeFromDescriptor(const UGenericWindowDescriptor* InDescriptor);

	/** 设置逻辑矩形。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void SetLogicalRect(const FVector2D& InPosition, const FVector2D& InSize);

	/** 设置可见矩形。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void SetVisibleRect(const FVector2D& InPosition, const FVector2D& InSize);

	/** 记录当前LogicalPosition。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	FVector2D CurrentLogicalPosition=FVector2D::ZeroVector;

	/** 记录当前Logical大小。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	FVector2D CurrentLogicalSize=FVector2D(640.0f, 480.0f);

	/** 记录当前VisiblePosition。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	FVector2D CurrentVisiblePosition=FVector2D::ZeroVector;

	/** 记录当前Visible大小。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	FVector2D CurrentVisibleSize=FVector2D(640.0f, 480.0f);

	/** 记录LastNormalPosition。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	FVector2D LastNormalPosition=FVector2D::ZeroVector;

	/** 记录LastNormal大小。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	FVector2D LastNormalSize=FVector2D(640.0f, 480.0f);

	/** 记录CollapseRestorePosition。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	FVector2D CollapseRestorePosition=FVector2D::ZeroVector;

	/** 记录CollapseRestore大小。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	FVector2D CollapseRestoreSize=FVector2D(640.0f, 480.0f);

	/** 记录ZOrder。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	int32 ZOrder=0;

	/** 标记打开。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	bool bIsOpen=false;

	/** 标记激活。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	bool bIsActive=false;

	/** 标记悬停。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	bool bIsHovered=false;

	/** 标记IsDragging状态。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	bool bIsDragging=false;

	/** 标记IsResizing状态。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	bool bIsResizing=false;

	/** 标记IsMaximized状态。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	bool bIsMaximized=false;

	/** 标记是否包含Collapse Restore矩形。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	bool bHasCollapseRestoreRect=false;

	/** 标记WasMaximizedBeforeCollapse状态。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	bool bWasMaximizedBeforeCollapse=false;

	/** 记录Display状态。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Window")
	EGenericInGameWindowDisplayState DisplayState=EGenericInGameWindowDisplayState::Expanded;
};
