// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelStreamingHandle.h"
#include "LevelStreamingType.h"
#include "SetLevelStreamingVisibilityHandle.generated.h"

/** 可见性句柄按队列切换流关卡显示状态；显示未加载关卡时会先发起加载，再等待 OnLevelShown/Hidden 推进。 */
UCLASS(MinimalAPI)
class USetLevelStreamingVisibilityHandle : public ULevelStreamingHandle
{
	GENERATED_BODY()

public:
	/** 使用单个设置项初始化可见性队列，适配单关卡入口提交到统一调度流程。 */
	void Initialize(const FSetLevelStreamingVisibilitySetting& InSetting, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish);

	/** 过滤无效和重复设置后缓存整批可见性请求，并保存调用方完成回调。 */
	void Initialize(TArray<FSetLevelStreamingVisibilitySetting> InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish);

public:
	virtual void RemoveLevel(const TSoftObjectPtr<UWorld>& InLevel) override;
	virtual TArray<TSoftObjectPtr<UWorld>> GetLevels() override;
	virtual void ExecuteHandle(int32 Index) override;
	virtual void HandleOnOnceFinish() override;
	virtual void HandleOnFinish() override;

public:
	/** 返回可见性设置队列副本，蓝图可用它查看每个关卡的目标显示状态。 */
	UFUNCTION(BlueprintPure, DisplayName="Get Set Level Streaming Visibility Settings", Category="Set Level Streaming Visibility Handle|Setting")
	TArray<FSetLevelStreamingVisibilitySetting> GetSetLevelStreamingVisibilitySettingsCopy() const;

	/** 读取当前索引对应的可见性设置；索引已完成或队列被裁剪时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Set Level Streaming Visibility Handle|Setting")
	bool GetCurrentSetLevelStreamingVisibilitySetting(FSetLevelStreamingVisibilitySetting& OutSetting) const;

	/** 返回可见性设置队列，供 C++ 测试或调度层检查实际保留的请求项。 */
	TArray<FSetLevelStreamingVisibilitySetting>& GetSetLevelStreamingVisibilitySettings() { return SetLevelStreamingVisibilitySettings; }

private:
	/** 当前句柄需要顺序切换的关卡可见性设置。 */
	TArray<FSetLevelStreamingVisibilitySetting> SetLevelStreamingVisibilitySettings;

	FOnHandleLevelStreamingOnceFinish OnSetLevelStreamingVisibilityOnceFinish;

	FOnHandleLevelStreamingFinish OnSetLevelStreamingVisibilityFinish;

	/** 对当前队列项应用可见性；由加载完成回调或直接执行路径共同复用。 */
	void ApplyCurrentLevelVisibility();

	/** 绑定 UE 可见性变化事件并设置 ShouldBeVisible，确保完成回调等到真实状态变化。 */
	void SetLevelVisibility(const TSoftObjectPtr<UWorld>& Level, const bool bVisible);

	/** 收到 OnLevelShown/OnLevelHidden 后解绑事件，并通知基类推进队列。 */
	UFUNCTION(Category="Set Level Streaming Visibility Handle|Handle")
	void OnLevelVisibilityChanged();
};
