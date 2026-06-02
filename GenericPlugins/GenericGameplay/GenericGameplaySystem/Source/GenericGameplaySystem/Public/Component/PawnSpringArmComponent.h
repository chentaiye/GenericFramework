// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "PawnSpringArmComponent.generated.h"

/** 作为PawnSpringARM组件能力控件，负责把运行时状态呈现到Slate或UMG层。 */
UCLASS(MinimalAPI, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UPawnSpringArmComponent : public USpringArmComponent
{
	GENERATED_BODY()

public:
	/** 初始化Pawn Spring ARM组件默认状态。 */
	UPawnSpringArmComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	/** 记录弹簧臂Lag。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Spring Arm Component", meta=(ClampMin=0, UIMin=0))
	float SpringArmLag=5.f;

	/** 记录Zoom基础Step。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Spring Arm Component", meta=(ClampMin=0, UIMin=0))
	float ZoomBaseStep=150.f;

	/** 记录Zoom臂LengthRange。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Spring Arm Component", meta=(ClampMin=0, UIMin=0))
	FVector2D ZoomArmLengthRange=FVector2D(300.f, 12000.f);

	/** 记录Zoom臂LengthMultiplierRange。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Spring Arm Component", meta=(ClampMin=0, UIMin=0))
	FVector2D ZoomArmLengthMultiplierRange=FVector2D(0.75f, 2.4f);

	/** 记录ZoomPitchMultiplierRange。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Spring Arm Component", meta=(ClampMin=0, UIMin=0))
	FVector2D ZoomPitchMultiplierRange=FVector2D(0.9f, 1.15f);

	/** 记录Zoom臂LengthExponent。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Spring Arm Component", meta=(ClampMin=0.1, UIMin=0.1))
	float ZoomArmLengthExponent=1.f;

	/** 启用Reassessment焦点。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Spring Arm Component")
	bool bEnableReassessmentFocus=true;

	/** 记录ReassessmentFocus。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Spring Arm Component", meta=(EditCondition="bEnableReassessmentFocus"))
	float ReassessmentFocus=10000.f;

	/** 记录ReassessmentFocusRange。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Pawn Spring Arm Component", meta=(EditCondition="bEnableReassessmentFocus"))
	float ReassessmentFocusRange=2000.f;

public:
	/** 添加目标臂Length，并维护集合缓存与后续查询的一致性。 */
	UFUNCTION(BlueprintCallable, Category="Pawn Spring Arm Component")
	void AddTargetArmLength(float InValue);

	/** 设置目标ARM长度。 */
	UFUNCTION(BlueprintCallable, Category="Pawn Spring Arm Component")
	void SetTargetArmLength(float InValue);

	/** 获取期望ARM长度。 */
	UFUNCTION(BlueprintPure, Category="Pawn Spring Arm Component")
	float GetDesiredArmLength() const;

	/** 执行预览目标臂Length，并同步当前模块的状态缓存与回调。 */
	UFUNCTION(BlueprintPure, Category="Pawn Spring Arm Component")
	float PreviewTargetArmLength(float InValue) const;

protected:
	/** 标记上次Reassessment结果。 */
	bool bLastReassessmentResult=false;

	/** 记录Desired臂Length。 */
	float DesiredArmLength=0.f;

	/** 判断NeedReassessment，让调用方按布尔结果选择后续路径。 */
	bool NeedReassessment() const;

	/** 按当前模块规则计算Calculate臂LengthDelta。 */
	float CalculateArmLengthDelta(float InValue) const;

	/** 更新目标ARM长度。 */
	void UpdateTargetArmLength(float DeltaTime);
};
