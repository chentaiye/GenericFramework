// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelStreamingHandle.h"
#include "LevelStreamingType.h"
#include "LoadLevelStreamingHandle.generated.h"

/** 加载句柄把一组加载设置按顺序提交给 UE latent 流关卡接口，并在每个目标完成后回到基类推进队列。 */
UCLASS(MinimalAPI)
class ULoadLevelStreamingHandle : public ULevelStreamingHandle
{
	GENERATED_BODY()

public:
	/** 使用单个设置项初始化加载队列，适配单关卡入口提交到统一调度流程。 */
	void Initialize(const FLoadLevelStreamingSetting& InSetting, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish);

	/** 过滤无效和重复设置后缓存整批加载请求，并保存调用方完成回调。 */
	void Initialize(TArray<FLoadLevelStreamingSetting> InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish);

public:
	virtual void RemoveLevel(const TSoftObjectPtr<UWorld>& InLevel) override;
	virtual TArray<TSoftObjectPtr<UWorld>> GetLevels() override;
	virtual void ExecuteHandle(int32 Index) override;
	virtual void HandleOnOnceFinish() override;
	virtual void HandleOnFinish() override;

public:
	/** 返回加载设置队列副本，蓝图可用它查看每个关卡的显示和阻塞策略。 */
	UFUNCTION(BlueprintPure, DisplayName="Get Load Level Streaming Settings", Category="Load Level Streaming Handle|Setting")
	TArray<FLoadLevelStreamingSetting> GetLoadLevelStreamingSettingsCopy() const;

	/** 读取当前索引对应的加载设置；索引已完成或队列被裁剪时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Load Level Streaming Handle|Setting")
	bool GetCurrentLoadLevelStreamingSetting(FLoadLevelStreamingSetting& OutSetting) const;

	/** 返回加载设置队列，供 C++ 测试或调度层检查实际保留的请求项。 */
	TArray<FLoadLevelStreamingSetting>& GetLoadLevelStreamingSettings() { return LoadLevelStreamingSettings; }

private:
	/** 当前句柄需要顺序加载的关卡设置。 */
	TArray<FLoadLevelStreamingSetting> LoadLevelStreamingSettings;

	FOnHandleLevelStreamingOnceFinish OnLoadLevelStreamingOnceFinish;

	FOnHandleLevelStreamingFinish OnLoadLevelStreamingFinish;

	/** 向 UE 提交指定关卡的 latent 加载请求，完成后回到基类推进下一项。 */
	void LoadLevel(const TSoftObjectPtr<UWorld>& Level, const bool bMakeVisibleAfterLoad, const bool bShouldBlockOnLoad);
};
