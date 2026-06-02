// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GenericWindowPartInterface.generated.h"

class UGenericWindowWidget;

/** 定义窗口Part接口契约，供模块在不同实现之间解耦调用。 */
UINTERFACE(BlueprintType)
class GENERICWINDOWFRAMEWORK_API UGenericWindowPartInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义窗口Part接口契约，供模块在不同实现之间解耦调用。 */
class GENERICWINDOWFRAMEWORK_API IGenericWindowPartInterface
{
	GENERATED_BODY()

public:
	/** 设置Owning通用窗口。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Window")
	void SetOwningGenericWindow(UGenericWindowWidget* InWindowWidget);
};
