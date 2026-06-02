// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "NetworkType.h"
#include "OnlineSessionSettings.h"
#include "SessionSearchResultViewModel.generated.h"

/** 面向 MVVM 的会话搜索结果视图模型，供列表项绑定展示并保留可加入的原始搜索结果。 */
UCLASS(MinimalAPI)
class USessionSearchResultViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	/** 返回原始 OnlineSession 搜索结果，列表项加入会话时会把它传回会话子系统。 */
	GENERICNETWORKFRAMEWORK_API const FOnlineSessionSearchResult& GetSessionSearchResult() const;

	/** 刷新搜索结果并同步延迟、拥有者、人数和会话设置等 UI 字段。 */
	GENERICNETWORKFRAMEWORK_API void SetSessionSearchResult(const FOnlineSessionSearchResult& InResult);

public:
	/** 保存蓝图和 MVVM 可绑定的搜索结果字段，同时封装底层 FOnlineSessionSearchResult。 */
	UPROPERTY(FieldNotify, VisibleAnywhere, BlueprintReadOnly, Category="Session Search Result View Model")
	FGenericSessionSearchResult SessionSearchResult;
};
