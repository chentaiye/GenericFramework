// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "InputKeyEventArgs.h"
#include "GenericGameViewportClient.generated.h"

/** 提供通用UI行为系统接入Viewport输入链路的入口。 */
UCLASS(MinimalAPI)
class UGenericGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

public:
	GENERICWIDGETFRAMEWORK_API virtual bool InputKey(const FInputKeyEventArgs& EventArgs) override;
	GENERICWIDGETFRAMEWORK_API virtual bool InputTouch(FViewport* InViewport, const FInputDeviceId DeviceId, uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, uint32 TouchpadIndex, const uint64 Timestamp) override;
};
