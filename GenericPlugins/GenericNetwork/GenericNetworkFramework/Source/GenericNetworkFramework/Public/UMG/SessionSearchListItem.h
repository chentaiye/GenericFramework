// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Obect/GenericObject.h"
#include "Base/GenericWidget.h"
#include "SessionSearchListItem.generated.h"

class UGenericButtonWidget;
class USessionSettingViewModel;
class USessionSearchResultViewModel;

/** ListView 使用的数据对象，用于把搜索结果视图模型传递给实际的条目控件。 */
UCLASS(MinimalAPI)
class USessionSearchListItemObject : public UGenericObject
{
	GENERATED_BODY()

public:
	/** 保存条目要展示和加入的搜索结果视图模型，NativeOnListItemObjectSet 会读取它。 */
	UPROPERTY()
	TObjectPtr<USessionSearchResultViewModel> SessionSearchResultViewModel=nullptr;
};

/** 单个会话搜索结果条目控件，处理视图模型绑定、选中后刷新详情以及加入按钮点击。 */
UCLASS(MinimalAPI)
class USessionSearchListItem : public UGenericWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

	friend class USessionSearchList;

public:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

protected:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	virtual void NativeOnItemSelectionChanged(bool bIsSelected) override;
	virtual void NativeOnItemExpansionChanged(bool bIsExpanded) override;
	virtual void NativeOnEntryReleased() override;

public:
	/** 替换当前条目的搜索结果视图模型，并触发蓝图扩展点刷新显示内容。 */
	UFUNCTION(BlueprintCallable, Category="Session Search List Item")
	GENERICNETWORKFRAMEWORK_API void SetSessionSearchResultViewModel(USessionSearchResultViewModel* InViewModel);

	/** 对当前选中会话执行 FindSessionById 刷新，以持续更新房间人数和设置。 */
	UFUNCTION(BlueprintCallable, Category="Session Search List Item")
	GENERICNETWORKFRAMEWORK_API void RefreshSelectedSession();

	/** 单会话刷新完成后回填视图模型；如果条目仍被选中，会继续发起下一次刷新。 */
	GENERICNETWORKFRAMEWORK_API virtual void OnRefreshSelectedSessionComplete(int32 InPlayerIndex, bool bWasSuccessful, const FOnlineSessionSearchResult& InResult);

protected:
	/** Join 按钮点击后使用当前视图模型中的搜索结果请求加入会话。 */
	UFUNCTION(Category="Session Search List Item")
	void OnJoinButtonClicked();

protected:
	/** 视图模型设置完成后的蓝图扩展点，子类可在这里刷新条目文本和状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Session Search List Item")
	GENERICNETWORKFRAMEWORK_API void OnSessionSearchResultViewModelSet(USessionSearchResultViewModel* InViewModel);

	/** 当前条目绑定的搜索结果视图模型，加入和刷新逻辑都会从这里读取原始搜索结果。 */
	UPROPERTY(BlueprintReadOnly, Category="Session Search List Item")
	TObjectPtr<USessionSearchResultViewModel> SessionSearchResultViewModel=nullptr;

private:
	/** 绑定蓝图中的加入按钮，条目未选中时隐藏，选中后允许玩家加入该会话。 */
	UPROPERTY(BlueprintReadOnly, Category="Session Search List Item", meta=(BindWidget, BlueprintProtected=true, AllowPrivateAccess=true))
	TObjectPtr<UGenericButtonWidget> GenericButtonWidget_Join;
};
