// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PawnReassessmentInterface.generated.h"

/** 定义PawnReassessment接口契约，供模块在不同实现之间解耦调用。 */
UINTERFACE()
class UPawnReassessmentInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义PawnReassessment接口契约，供模块在不同实现之间解耦调用。 */
class GENERICGAMEPLAYSYSTEM_API IPawnReassessmentInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	/** 将相机聚焦到目标Actor，并创建切换方法承接完成回调。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Pawn Input Movement Interface")
	bool ReassessmentFocus();
};
