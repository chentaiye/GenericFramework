// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "WorldWidgetComponent.generated.h"

class APlayerController;
class UGenericInputActionDataAsset;
class UGenericWidget;
#if WITH_EDITOR
class UWorldWidgetEdSubsystem;
#endif

DECLARE_MULTICAST_DELEGATE_OneParam(FOnWorldWidgetComponentChanged, class UWorldWidgetComponent*);

/** 决定 WorldWidget 由视口叠层还是三维场景组件承载。 */
UENUM(BlueprintType)
enum class EWorldWidgetPaintMethod : uint8
{
	/** 组件只提供世界锚点，控件按屏幕空间尺寸绘制到玩家视口。 */
	Screen,

	/** 控件由 UWidgetComponent 作为三维平面绘制，并可跟随玩家相机调整朝向和尺寸。 */
	World
};

/** 在场景组件上承载 GenericWidget，并在 Screen/World 两种绘制路径之间同步尺寸、锚点和输入注册状态。 */
UCLASS(ClassGroup="UserInterface", HideCategories=(UserInterface, Physics, Collision, Interaction, Animation, Navigation, Networking, Mobile), meta=(BlueprintSpawnableComponent), MinimalAPI)
class UWorldWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	GENERICWORLDWIDGETFRAMEWORK_API UWorldWidgetComponent(const FObjectInitializer& ObjectInitializer);

	/** 返回当前控件由屏幕叠层还是三维组件负责绘制。 */
	UFUNCTION(BlueprintPure, Category="World Widget")
	GENERICWORLDWIDGETFRAMEWORK_API EWorldWidgetPaintMethod GetPaintMethod() const;

	/** 切换绘制路径，并立即刷新底层 WidgetComponent 与编辑器预览使用的状态。 */
	UFUNCTION(BlueprintCallable, Category="World Widget")
	GENERICWORLDWIDGETFRAMEWORK_API void SetPaintMethod(EWorldWidgetPaintMethod InPaintMethod);

	/** 返回控件在屏幕叠层和三维平面中共用的对齐锚点。 */
	UFUNCTION(BlueprintPure, Category="World Widget")
	GENERICWORLDWIDGETFRAMEWORK_API FVector2D GetAnchor() const;

	/** 修改对齐锚点，并同步到 WidgetComponent 的 Pivot 与编辑器 overlay slot。 */
	UFUNCTION(BlueprintCallable, Category="World Widget")
	GENERICWORLDWIDGETFRAMEWORK_API void SetAnchor(FVector2D InAnchor);

	/** 返回当前由组件持有并负责绘制或预览的 GenericWidget 实例。 */
	UFUNCTION(BlueprintPure, Category="World Widget")
	GENERICWORLDWIDGETFRAMEWORK_API UGenericWidget* GetWorldWidget() const;

	/** 替换组件承载的 GenericWidget，并重新计算 DrawSize 与注册预览状态。 */
	UFUNCTION(BlueprintCallable, Category="World Widget")
	GENERICWORLDWIDGETFRAMEWORK_API void SetWorldWidget(UGenericWidget* InWidget);

	/** 返回路由输入未消费后，此 WorldWidget 参与补充输入派发时的排序优先级。 */
	UFUNCTION(BlueprintPure, Category="World Widget|Input")
	GENERICWORLDWIDGETFRAMEWORK_API int32 GetInputPriority() const;

	/** 修改补充输入派发优先级，并通知运行时子系统重新排序。 */
	UFUNCTION(BlueprintCallable, Category="World Widget|Input")
	GENERICWORLDWIDGETFRAMEWORK_API void SetInputPriority(int32 InInputPriority);

	GENERICWORLDWIDGETFRAMEWORK_API virtual void OnRegister() override;
	GENERICWORLDWIDGETFRAMEWORK_API virtual void OnUnregister() override;
	GENERICWORLDWIDGETFRAMEWORK_API virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

#if WITH_EDITOR
	GENERICWORLDWIDGETFRAMEWORK_API virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

private:
	/** 根据 PaintMethod 切换 WidgetComponent 的底层绘制空间。 */
	void SynchronizePaintMethod();

	/** 把通用 Anchor 写入 WidgetComponent Pivot，供 Screen overlay 和 World 平面共用同一对齐语义。 */
	void SynchronizeAnchor();

	/** 把当前 GenericWidget 实例交给正确的运行时或编辑器预览路径。 */
	void SynchronizeWorldWidget();

	/** 通过 Slate 预布局读取控件期望尺寸，并写入 WorldWidget 的 DrawSize。 */
	void SynchronizeWorldWidgetSize();

	/** 按 World 模式跟随相机选项决定组件 Tick 是否需要运行。 */
	void SynchronizeFollowCameraTick();

	/** 在组件 Tick 中按玩家相机更新选定轴向和可选的屏幕等效缩放。 */
	void UpdateFollowCameraTransform();

	/** 使用给定视图更新 World 模式下的相机跟随旋转和屏幕等效缩放。 */
	GENERICWORLDWIDGETFRAMEWORK_API void UpdateFollowCameraTransformForView(const FVector& InCameraLocation, const FRotator& InCameraRotation, TOptional<float> InTargetScale);

	/** 查询当前世界中用于 WorldWidget 对齐和投影换算的本地玩家相机。 */
	bool TryGetFollowCameraView(FVector& OutCameraLocation, FRotator& OutCameraRotation, APlayerController*& OutPlayerController) const;

	/** 使用玩家视口投影采样计算 World 模式下匹配 Screen 模式像素尺寸所需的缩放。 */
	bool CalculateFollowCameraScale(APlayerController* InPlayerController, const FRotator& InCameraRotation, float& OutScale) const;

	/** 在缩放跟随生效前记录设计者设置的相对缩放，避免 Tick 覆盖原始配置。 */
	void CacheFollowCameraBaseScale();

	/** 关闭缩放跟随或离开 World 模式时恢复设计者设置的相对缩放。 */
	void RestoreFollowCameraBaseScale();

	/** 通知运行时或编辑器子系统把该组件加入当前世界的 WorldWidget 集合。 */
	void BroadcastComponentRegistered();

	/** 通知运行时或编辑器子系统移除该组件关联的输入和预览状态。 */
	void BroadcastComponentUnregistered();

	/** 通知运行时或编辑器子系统刷新尺寸、排序或预览 slot。 */
	void BroadcastComponentChanged();

public:
	GENERICWORLDWIDGETFRAMEWORK_API inline static FOnWorldWidgetComponentChanged OnComponentRegistered;
	GENERICWORLDWIDGETFRAMEWORK_API inline static FOnWorldWidgetComponentChanged OnComponentUnregistered;
	GENERICWORLDWIDGETFRAMEWORK_API inline static FOnWorldWidgetComponentChanged OnComponentChanged;

public:
	/** 决定 GenericWidget 由屏幕空间叠层还是三维 WidgetComponent 绘制。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World Widget")
	EWorldWidgetPaintMethod PaintMethod = EWorldWidgetPaintMethod::Screen;

	/** 控件对齐到组件投影点或三维平面原点时使用的归一化锚点。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World Widget")
	FVector2D Anchor = FVector2D(0.5f, 0.5f);

	/** World 模式下把组件 Pitch 旋转实时对齐到玩家相机方向。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World Widget", meta=(EditCondition="PaintMethod == EWorldWidgetPaintMethod::World"))
	bool bEnableFollowCameraPitch = true;

	/** World 模式下把组件 Yaw 旋转实时对齐到玩家相机方向。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World Widget", meta=(EditCondition="PaintMethod == EWorldWidgetPaintMethod::World"))
	bool bEnableFollowCameraYaw = true;

	/** World 模式下把组件 Roll 旋转实时对齐到玩家相机方向。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World Widget", meta=(EditCondition="PaintMethod == EWorldWidgetPaintMethod::World"))
	bool bEnableFollowCameraRoll = false;

	/** World 模式下按组件到玩家相机的距离实时缩放，使三维控件在视口中保持屏幕等效尺寸。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World Widget", meta=(EditCondition="PaintMethod == EWorldWidgetPaintMethod::World"))
	bool bEnableFollowCameraScale = false;

	/** World 模式缩放跟随的屏幕等效倍率；1 表示与 Screen 模式下的 UI 尺寸一致。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World Widget", meta=(EditCondition="PaintMethod == EWorldWidgetPaintMethod::World && bEnableFollowCameraScale", ClampMin="0.0", UIMin="0.0"))
	float FollowCameraScale = 1.0f;

	/** 由组件创建、持有并绘制的 GenericWidget 实例。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="World Widget")
	TObjectPtr<UGenericWidget> WorldWidget = nullptr;

	/** 路由输入未消费时用于补充派发到该 WorldWidget 的输入动作配置。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World Widget|Input")
	TObjectPtr<UGenericInputActionDataAsset> InputActionDataAsset = nullptr;

	/** 多个 WorldWidget 同时参与补充输入派发时，数值越高越先收到事件。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="World Widget|Input")
	int32 InputPriority = 0;

private:
	/** 缩放跟随开始前的相对缩放，用于关闭功能或切回 Screen 模式时还原设计值。 */
	FVector FollowCameraBaseRelativeScale = FVector::OneVector;

	/** 标记当前是否已经记录过可恢复的相对缩放。 */
	bool bHasFollowCameraBaseRelativeScale = false;

	/** 标记当前相对缩放是否由跟随相机逻辑写入。 */
	bool bAppliedFollowCameraScale = false;

#if WITH_EDITOR
	friend class UWorldWidgetEdSubsystem;
#endif
};
