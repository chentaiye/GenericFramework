// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/SlateWrapperTypes.h"
#include "GameplayTagContainer.h"
#include "Interface/GenericRouteInterface.h"
#include "GenericLayer.generated.h"

class UGenericInputActionDataAsset;

/** 表示可进入本地玩家 UI 路由树的层节点，可在运行时自动注册到 LayerSubsystem。 */
UCLASS(MinimalAPI)
class UGenericLayer : public UUserWidget, public IGenericRouteInterface
{
	GENERATED_BODY()

public:
	/** 初始化层级标识和可作为变量引用的默认值。 */
	GENERICWIDGETFRAMEWORK_API UGenericLayer(const FObjectInitializer& ObjectInitializer);

	/** 显式调整当前层的 Slate 可见性。 */
	UFUNCTION(BlueprintCallable, Category="Layer")
	GENERICWIDGETFRAMEWORK_API void SetLayerVisibility(ESlateVisibility InVisibility);

	GENERICWIDGETFRAMEWORK_API virtual FGameplayTag GetRouteTag_Implementation() const override;
	GENERICWIDGETFRAMEWORK_API virtual ULocalPlayer* GetRouteOwnerPlayer_Implementation() const override;

protected:
#if WITH_EDITOR
	GENERICWIDGETFRAMEWORK_API virtual void ValidateCompiledDefaults(class IWidgetCompilerLog& CompileLog) const override;
#endif
	GENERICWIDGETFRAMEWORK_API virtual TSharedRef<SWidget> RebuildWidget() override;
	GENERICWIDGETFRAMEWORK_API virtual void ReleaseSlateResources(bool bReleaseChildren) override;

private:
	void RegisterToLayerSubsystem();
	void UnregisterFromLayerSubsystem();

public:
	/** 控制运行时是否在 Slate 重建后自动进入当前本地玩家的层级子系统。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Layer")
	bool bAutoRegister = true;

	/** 标识当前层在 GameplayUI.Layer 树中的业务层级。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Layer", meta=(Categories="GameplayUI.Layer"))
	FGameplayTag LayerTag;

	/** 控制同一输入/路由流程中多个层的优先级，数值越大越靠前。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Layer")
	int32 ZOrder = 0;

	/** 提供当前层可响应的输入动作配置。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Input")
	TObjectPtr<UGenericInputActionDataAsset> InputActionDataAsset = nullptr;
};
