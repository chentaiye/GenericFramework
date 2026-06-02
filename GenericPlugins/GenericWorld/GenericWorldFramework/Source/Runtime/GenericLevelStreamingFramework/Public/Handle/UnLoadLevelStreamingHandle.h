// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelStreamingHandle.h"
#include "LevelStreamingType.h"
#include "UnLoadLevelStreamingHandle.generated.h"

/** 卸载句柄把一组卸载设置按顺序提交给 UE latent 流关卡接口，并在已处于卸载状态的关卡上直接推进队列。 */
UCLASS(MinimalAPI)
class UUnLoadLevelStreamingHandle : public ULevelStreamingHandle
{
	GENERATED_BODY()

public:
	/** 使用单个设置项初始化卸载队列，适配单关卡入口提交到统一调度流程。 */
	void Initialize(const FUnloadLevelStreamingSetting& InSetting, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish);

	/** 过滤无效和重复设置后缓存整批卸载请求，并保存调用方完成回调。 */
	void Initialize(TArray<FUnloadLevelStreamingSetting> InSettings, const FOnHandleLevelStreamingOnceFinish& OnOnceFinish, const FOnHandleLevelStreamingFinish& OnFinish);

public:
	virtual void RemoveLevel(const TSoftObjectPtr<UWorld>& InLevel) override;
	virtual TArray<TSoftObjectPtr<UWorld>> GetLevels() override;
	virtual void ExecuteHandle(int32 Index) override;
	virtual void HandleOnOnceFinish() override;
	virtual void HandleOnFinish() override;

public:
	/** 返回卸载设置队列副本，蓝图可用它查看每个关卡的阻塞策略。 */
	UFUNCTION(BlueprintPure, DisplayName="Get Unload Level Streaming Settings", Category="Unload Level Streaming Handle|Setting")
	TArray<FUnloadLevelStreamingSetting> GetUnLoadLevelStreamingSettingsCopy() const;

	/** 读取当前索引对应的卸载设置；索引已完成或队列被裁剪时返回 false。 */
	UFUNCTION(BlueprintPure, Category="Unload Level Streaming Handle|Setting")
	bool GetCurrentUnLoadLevelStreamingSetting(FUnloadLevelStreamingSetting& OutSetting) const;

	/** 返回卸载设置队列，供 C++ 测试或调度层检查实际保留的请求项。 */
	TArray<FUnloadLevelStreamingSetting>& GetUnLoadLevelStreamingSettings() { return UnLoadLevelStreamingSettings; }

private:
	/** 当前句柄需要顺序卸载的关卡设置。 */
	TArray<FUnloadLevelStreamingSetting> UnLoadLevelStreamingSettings;

	FOnHandleLevelStreamingOnceFinish OnUnLoadLevelStreamingOnceFinish;

	FOnHandleLevelStreamingFinish OnUnLoadLevelStreamingFinish;

	/** 向 UE 提交指定关卡的 latent 卸载请求，完成后回到基类推进下一项。 */
	void UnLoadLevel(const TSoftObjectPtr<UWorld>& Level, const bool bShouldBlockOnUnload);
};
