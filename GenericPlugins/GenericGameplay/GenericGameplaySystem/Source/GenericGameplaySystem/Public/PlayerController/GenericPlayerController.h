// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GenericPlayerController.generated.h"

class IPawnInputInterface;

/** 承载玩家控制器职责，衔接上层调用与模块内部实现。 */
UCLASS(MinimalAPI)
class AGenericPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	/** 初始化通用玩家控制器默认状态。 */
	GENERICGAMEPLAYSYSTEM_API AGenericPlayerController();
	GENERICGAMEPLAYSYSTEM_API virtual void BeginPlay() override;
	GENERICGAMEPLAYSYSTEM_API virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	/* AGenericPlayerController */
protected:
	/** 执行原生On玩家游戏HUDCreated，并同步当前模块的状态缓存与回调。 */
	GENERICGAMEPLAYSYSTEM_API virtual void NativeOnPlayerGameHUDCreated();

	/** 响应玩家游戏HUD已创建。 */
	UFUNCTION(BlueprintImplementableEvent, Category="Generic Player Controller")
	void OnPlayerGameHUDCreated();
};
