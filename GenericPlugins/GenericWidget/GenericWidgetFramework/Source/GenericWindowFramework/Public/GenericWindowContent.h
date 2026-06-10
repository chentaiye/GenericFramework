// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Base/GenericWidget.h"
#include "GenericWindowPartInterface.h"
#include "GenericWindowType.h"
#include "GenericWindowContent.generated.h"

class UGenericWindowWidget;
class UWidget;
struct FGeometry;
struct FPointerEvent;

/** 定义窗口内容能力契约，供模块在不同实现之间解耦调用。 */
UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UGenericWindowContent : public UGenericWidget, public IGenericWindowPartInterface
{
	GENERATED_BODY()

public:
	/** 初始化通用窗口内容默认状态。 */
	GENERICWINDOWFRAMEWORK_API UGenericWindowContent(const FObjectInitializer& ObjectInitializer);

	GENERICWINDOWFRAMEWORK_API virtual void NativeConstruct() override;
	GENERICWINDOWFRAMEWORK_API virtual FReply NativeOnPreviewMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	GENERICWINDOWFRAMEWORK_API virtual FReply NativeOnMouseMove(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	GENERICWINDOWFRAMEWORK_API virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	GENERICWINDOWFRAMEWORK_API virtual void SetOwningGenericWindow_Implementation(UGenericWindowWidget* InWindowWidget) override;

	/** 获取Owning通用窗口。 */
	UFUNCTION(BlueprintPure, Category="Window")
	GENERICWINDOWFRAMEWORK_API UGenericWindowWidget* GetOwningGenericWindow() const;

	/** 同步hronize来源窗口，使运行时状态与输入配置保持一致。 */
	UFUNCTION(BlueprintCallable, Category="Window")
	GENERICWINDOWFRAMEWORK_API void SynchronizeFromWindow();

protected:
	/** 处理所属通用窗口变化并同步相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Window")
	GENERICWINDOWFRAMEWORK_API void HandleOwningGenericWindowChanged(UGenericWindowWidget* InWindowWidget);

	/** 执行句柄窗口状态Synchronized流程，并把结果同步给通用 UI相关状态。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Window")
	GENERICWINDOWFRAMEWORK_API void HandleWindowStateSynchronized();

private:
	/** 检测检测Resize句柄，把屏幕位置转换为窗口缩放句柄。 */
	EGenericWindowResizeHandle DetectResizeHandle(const FGeometry& InGeometry, const FVector2D& InScreenSpacePosition) const;

	/** 持有所属通用窗口实例，供通用 UI运行时复用。 */
	UPROPERTY(Transient)
	TObjectPtr<UGenericWindowWidget> OwningGenericWindow=nullptr;

	/** 标记IsDragging窗口状态。 */
	bool bIsDraggingWindow = false;

	/** 标记IsResizing窗口状态。 */
	bool bIsResizingWindow = false;

	/** 记录激活Resize句柄。 */
	EGenericWindowResizeHandle ActiveResizeHandle = EGenericWindowResizeHandle::None;

	/** 记录Interaction启动ScreenPosition。 */
	FVector2D InteractionStartScreenPosition = FVector2D::ZeroVector;

	/** 记录Interaction启动窗口Position。 */
	FVector2D InteractionStartWindowPosition = FVector2D::ZeroVector;

	/** 记录Interaction启动窗口大小。 */
	FVector2D InteractionStartWindowSize = FVector2D::ZeroVector;
};
