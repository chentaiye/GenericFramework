#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Engine/DataTable.h"
#include "FlyLine/FlyLineTypes.h"
#include "FlyLineComponent.generated.h"

struct FPropertyChangedEvent;

/** 把拥有者注册为飞线端点，端点 ID、组名和变换变化会驱动子系统重建飞线实例。 */
UCLASS(MinimalAPI, Blueprintable, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UFlyLineComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	/** 初始化端点组件基础状态，飞线重建由注册和变换通知触发。 */
	FLYLINESYSTEM_API UFlyLineComponent();

	FLYLINESYSTEM_API virtual void OnRegister() override;
	FLYLINESYSTEM_API virtual void OnUnregister() override;
	FLYLINESYSTEM_API virtual void OnUpdateTransform(EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport) override;

#if WITH_EDITOR
	FLYLINESYSTEM_API virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	FLYLINESYSTEM_API virtual void PostEditComponentMove(bool bFinished) override;
#endif

	/** 返回显式端点名或组件路径名，保证未填写 EndpointName 时仍能被连接查找。 */
	UFUNCTION(BlueprintPure, Category="FlyLine")
	FLYLINESYSTEM_API FName GetResolvedEndpointId() const;

	/** 将当前组件的 ID、世界变换、标签和组名打包成端点快照。 */
	UFUNCTION(BlueprintPure, Category="FlyLine")
	FLYLINESYSTEM_API FFlyLineEndpoint BuildEndpoint() const;

	/** 通知子系统端点状态已变化，触发连接解析和实例批次重建。 */
	UFUNCTION(BlueprintCallable, CallInEditor, Category="FlyLine")
	FLYLINESYSTEM_API void RefreshFlyLines();

	/** 从组样式表中按组名查找样式行，成功时填充自动组连接使用的渲染参数。 */
	FLYLINESYSTEM_API bool TryResolveGroupStyle(FName GroupName, FFlyLineStyle& OutStyle) const;

public:
	/** 端点分类标签，供蓝图或上层规则区分不同类型的飞线节点。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine", meta=(Categories="GameplayGeometry.FlyLine"))
	FGameplayTag EndpointTag;

	/** 端点的稳定连接名；为空时 GetResolvedEndpointId 使用组件路径避免空 ID。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
	FString EndpointName;

	/** 自动连线组名列表，同组端点会在 BuildActiveConnections 中两两连接。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
	TArray<FName> GroupNames;

	/** 组自动连线查找样式的 DataTable，为空时自动连接使用默认飞线样式。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FlyLine")
	TObjectPtr<UDataTable> GroupStyleTable=nullptr;
};
