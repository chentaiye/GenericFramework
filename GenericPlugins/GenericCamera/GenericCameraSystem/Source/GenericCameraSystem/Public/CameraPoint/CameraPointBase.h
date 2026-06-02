// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"

#include "CameraPointBase.generated.h"

class ACameraPointBase;
class USpringArmComponent;
class USphereComponent;
class UCameraComponent;
class UGenericCameraSwitchMethod;

DECLARE_MULTICAST_DELEGATE_OneParam(FCameraPointDelegate, ACameraPointBase*)

/** 定义可注册到相机子系统的镜头锚点基类，统一处理标签索引、焦点距离和编辑器相机同步。 */
UCLASS(Abstract, MinimalAPI, HideCategories=(Object,Actor,Collision,Physics,Networking,Input,LevelInstance,Cooking,HLOD,Replication))
class ACameraPointBase : public AActor
{
	GENERATED_BODY()

public:
	/** 创建根节点、预览球和弹簧臂，让派生类只负责挂接具体的相机组件。 */
	ACameraPointBase(const FObjectInitializer& ObjectInitializer);

#if WITH_EDITOR
	virtual void PostRegisterAllComponents() override;
#endif

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void Tick(float DeltaTime) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

public:
	/** 作为相机子系统的索引键，只有有效标签的相机点才会参与按标签切换。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Point", meta=(Categories="GameplayCamera"))
	FGameplayTag CameraTag;

	/** 承载相机点 Actor 的根节点，预览球、弹簧臂和实际相机组件都基于它定位。 */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Camera Point (Editor)")
	TObjectPtr<USceneComponent> SceneComponent = nullptr;

	/** 在编辑器视口中提供可选中的可视化体积，不参与运行时碰撞和镜头计算。 */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Camera Point (Editor)")
	TObjectPtr<USphereComponent> SphereComponent = nullptr;

	/** 保存焦点距离并作为相机组件挂点，RefreshFocus 会根据前方命中更新臂长。 */
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="Camera Point (Editor)")
	TObjectPtr<USpringArmComponent> SpringArmComponent = nullptr;

public:
	/** 由派生类返回实际承载画面参数的相机组件，供基类复制外部相机和同步 Pilot 状态。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Camera Point (Editor)")
	GENERICCAMERASYSTEM_API UCameraComponent* GetCameraComponent();

	/** 由派生类把外部相机参数写入自身组件，避免直接替换构造期创建的默认子对象。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Camera Point (Editor)")
	GENERICCAMERASYSTEM_API void SetCameraComponent(UCameraComponent* InCameraComponent);

	/** 沿当前视线重新计算焦点命中和弹簧臂长度，用于编辑器预览、复制视口和相机链接同步。 */
	UFUNCTION(BlueprintCallable, Category="Camera Point (Editor)")
	GENERICCAMERASYSTEM_API void RefreshFocus();

public:
	GENERICCAMERASYSTEM_API inline static FCameraPointDelegate OnCameraPointRegister;

	GENERICCAMERASYSTEM_API inline static FCameraPointDelegate OnCameraPointUnRegister;

#if WITH_EDITOR

public:
#if WITH_EDITORONLY_DATA
	/** 持久化绑定外部 CameraActor，编辑器加载或变更后会同步其姿态和镜头参数。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Camera Point (Editor)")
	TSoftObjectPtr<ACameraActor> CameraActorLink = nullptr;
#endif

public:
	/** 手动重新读取 CameraActorLink 指向的相机，把持久化的外部相机姿态和镜头参数覆盖到当前相机点。 */
	UFUNCTION(CallInEditor, Category="Camera Point (Editor)")
	void RefreshCameraActorLink();

	/** 把当前编辑器视口的姿态写入相机点，并刷新焦点距离，便于把观察位置保存为镜头。 */
	UFUNCTION(CallInEditor, Category="Camera Point (Editor)")
	void CopyFromViewportCamera();

	/** 切换所选 Actor 的移动锁，配合相机点编辑避免误拖动已布好的镜头。 */
	UFUNCTION(CallInEditor, Category="Camera Point (Editor)")
	void ToggleLock();

	/** 进入 LevelEditor Pilot 前归一化弹簧臂，使视口驾驶使用当前相机组件的世界位置。 */
	UFUNCTION(CallInEditor, Category="Camera Point (Editor)")
	void PilotCamera();

	/** 退出 LevelEditor Pilot 后重新计算焦点，把编辑器视口调整后的镜头状态写回相机点。 */
	UFUNCTION(CallInEditor, Category="Camera Point (Editor)")
	void EjectPilotCamera();

	/** 从软引用相机加载并复制配置，适用于关卡重新打开后恢复持久化的 CameraActorLink。 */
	void DuplicateFromCamera(const TSoftObjectPtr<ACameraActor>& InCameraActor);

	/** 从 CameraActor 复制世界姿态和镜头组件参数，并按需要记录编辑器事务。 */
	void DuplicateFromCamera(const ACameraActor* InCameraActor);

	/** 从任意 CameraComponent 复制镜头参数到派生类自己的相机组件，保留相机点对象结构。 */
	void DuplicateFromCamera(const UCameraComponent* InCameraComponent);

private:
	/** 从持久化的 CameraActorLink 读取相机数据；加载、属性变更和手动按钮会在离散时机调用它。 */
	bool RefreshFromCameraActorLink(bool bAllowSynchronousLoad);

	/** 把当前相机世界位置折叠回 Actor 根节点，让 Pilot 和 Eject 后不会叠加 SpringArm 偏移。 */
	void NormalizeForEditorPilot();

	/** 应用 CameraActor 的姿态和相机参数，按调用场景决定是否记录编辑器事务。 */
	void ApplyCameraActor(const ACameraActor* InCameraActor, bool bRecordTransaction);

private:
	/** 记录上一次成功同步的外部相机，避免每帧重复覆盖用户正在编辑的相机点。 */
	TWeakObjectPtr<ACameraActor> LastRefreshedCameraActorLink;

#endif

protected:
	/** 复制普通 CameraComponent 的投影、视野和后处理参数，Cine 参数由派生类继续补齐。 */
	GENERICCAMERASYSTEM_API void CopyCameraComponentProperties(const UCameraComponent* InCameraComponent, UCameraComponent* OutCameraComponent) const;

	/** 归一化写入相机点根节点的位置，派生类可覆写以适配特殊约束。 */
	GENERICCAMERASYSTEM_API virtual FVector NormalizeCameraLocation(const FVector& InLocation);

	/** 归一化写入相机点根节点的旋转，默认把 Roll 合并到 Yaw 并限制 Pitch。 */
	GENERICCAMERASYSTEM_API virtual FRotator NormalizeCameraRotation(const FRotator& InRotation);
};
