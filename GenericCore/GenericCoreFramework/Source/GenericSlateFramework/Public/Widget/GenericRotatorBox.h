// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GenericRotatorBox.generated.h"

class UTextBlock;
class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnElementRotated, int32, SelectedIndex, const FText&, SelectedText);

/** 作为通用轮播盒，负责把蓝图可编辑属性同步到底层 Slate 实例。 */
UCLASS(MinimalAPI)
class UGenericRotatorBox : public UUserWidget
{
	GENERATED_BODY()

public:
	GENERICSLATEFRAMEWORK_API virtual void NativePreConstruct() override;
	GENERICSLATEFRAMEWORK_API virtual void NativeConstruct() override;
	GENERICSLATEFRAMEWORK_API virtual void NativeDestruct() override;

private:
	/** 响应左侧按钮点击，把用户输入转换为向左轮播操作。 */
	UFUNCTION(Category="Generic Rotator Box")
	GENERICSLATEFRAMEWORK_API void OnButtonLeftClicked();

	/** 响应右侧按钮点击，把用户输入转换为向右轮播操作。 */
	UFUNCTION(Category="Generic Rotator Box")
	GENERICSLATEFRAMEWORK_API void OnButtonRightClicked();

public:
	/** 向左切换轮播项，更新当前索引并广播选择变化。 */
	UFUNCTION(BlueprintCallable, Category="Generic Rotator Box")
	GENERICSLATEFRAMEWORK_API void RotateLeft();

	/** 向右切换轮播项，更新当前索引并广播选择变化。 */
	UFUNCTION(BlueprintCallable, Category="Generic Rotator Box")
	GENERICSLATEFRAMEWORK_API void RotateRight();

	/** 追加可轮播的文本项，并在必要时刷新当前显示。 */
	UFUNCTION(BlueprintCallable, Category="Generic Rotator Box")
	GENERICSLATEFRAMEWORK_API void AddTextLabel(const FText& InTextLabel);

	/** 移除指定文本项，并修正当前选择索引。 */
	UFUNCTION(BlueprintCallable, Category="Generic Rotator Box")
	GENERICSLATEFRAMEWORK_API void RemoveTextLabel(const FText& InTextLabel);

	/** 写入当前选择索引，并同步到当前对象缓存和底层 Slate 控件。 */
	UFUNCTION(BlueprintCallable, Category="Generic Rotator Box")
	GENERICSLATEFRAMEWORK_API void SetSelectedIndex(int32 Index);

	/** 查找上一个可用索引，按配置决定是否允许从首项回绕到末项。 */
	UFUNCTION(BlueprintPure, Category="Generic Rotator Box")
	GENERICSLATEFRAMEWORK_API bool GetPreviousValidIndex(int32& OutIndex) const;

	/** 查找下一个可用索引，按配置决定是否允许从末项回绕到首项。 */
	UFUNCTION(BlueprintPure, Category="Generic Rotator Box")
	GENERICSLATEFRAMEWORK_API bool GetNextValidIndex(int32& OutIndex) const;

protected:
	/** 当前选择索引变化后通知蓝图，便于外部同步显示或业务状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic Rotator Box")
	GENERICSLATEFRAMEWORK_API void OnSelectedIndexChanged(int32 Index);

public:
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnElementRotated OnElementRotated;

	/** 记录循环选择开关，用于在生命周期、同步或输入流程中选择后续路径。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Rotator Box")
	bool bAllowWrap=false;

	/** 保存默认选择索引数值，供布局、渲染或运行时逻辑读取。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Rotator Box")
	int32 DefaultSelectedIndex=INDEX_NONE;

	/** 缓存轮播文本列表集合，供批量同步、查找或编辑器刷新使用。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Generic Rotator Box")
	TArray<FText> TextLabels;

private:
	/** 绑定左侧按钮控件，用于驱动上一项轮播。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Rotator Box", meta=(BindWidget, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UButton> GenericButton_Left;

	/** 绑定右侧按钮控件，用于驱动下一项轮播。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Rotator Box", meta=(BindWidget, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UButton> GenericButton_Right;

	/** 绑定当前文本显示控件，轮播索引变化时更新内容。 */
	UPROPERTY(BlueprintReadOnly, Category="Generic Rotator Box", meta=(BindWidget, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UTextBlock> TextBlock;

	/** 保存当前选择索引数值，供布局、渲染或运行时逻辑读取。 */
	int32 SelectedIndex = INDEX_NONE;
};
