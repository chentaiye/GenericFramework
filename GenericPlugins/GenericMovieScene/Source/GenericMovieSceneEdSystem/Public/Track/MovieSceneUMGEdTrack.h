// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MovieSceneTrackEditor.h"

class UUserWidgetBlueprint;
class UMovieSceneUMGTrack;

/** Sequencer 的 UMG 轨道编辑器，提供添加 UMG 轨道、选择 Widget Blueprint 并创建 Spawnable 绑定的入口。 */
class FMovieSceneUMGEdTrack : public FMovieSceneTrackEditor
{
public:
	/** 绑定当前 Sequencer 实例，后续菜单、资产选择和绑定查询都通过该实例操作焦点 MovieScene。 */
	FMovieSceneUMGEdTrack(TSharedRef<ISequencer> InSequencer);

	/** 创建轨道编辑器实例，供 Sequencer 模块注册的工厂回调调用。 */
	static TSharedRef<ISequencerTrackEditor> CreateTrackEditor(TSharedRef<ISequencer> InSequencer);

	virtual bool SupportsType(TSubclassOf<UMovieSceneTrack> TrackClass) const override;
	virtual TSharedRef<ISequencerSection> MakeSectionInterface(UMovieSceneSection& SectionObject, UMovieSceneTrack& Track, FGuid ObjectBinding) override;
	virtual void BuildAddTrackMenu(FMenuBuilder& MenuBuilder) override;
	virtual TSharedPtr<SWidget> BuildOutlinerEditWidget(const FGuid& ObjectBinding, UMovieSceneTrack* Track, const FBuildEditWidgetParams& Params) override;

private:
	/** 在当前 LevelSequence 中添加唯一的 UMG 主轨道，并通知 Sequencer 结构变化。 */
	void HandleAddUMGTrack();

	/** 创建只筛选 UserWidgetBlueprint 的资产选择器，用于从轨道外层按钮添加 UMG 绑定。 */
	TSharedRef<SWidget> CreateUMGAssetPicker();

	/** 资产选中后定位已有同类 Widget 绑定，找不到时创建新的 Spawnable。 */
	void OnUMGAssetSelected(const FAssetData& InAssetData);

	/** 资产选择器回车确认时复用单选逻辑，创建或定位 UMG 绑定。 */
	void OnUMGAssetEnterPressed(const TArray<FAssetData>& InAssetData);

	/** 在当前 MovieScene 绑定中查找同一 Widget Blueprint 生成类，避免重复生成相同 UMG。 */
	FGuid FindExistingUMGBinding(UUserWidgetBlueprint* InUserWidgetBP) const;

	/** 基于绑定查询返回是否已经存在该 Widget Blueprint 对应的 UMG Spawnable。 */
	bool IsUMGBindingExist(UUserWidgetBlueprint* InUserWidgetBP);

	/** 通过 Sequencer 创建新的 Widget Spawnable，并通知时间轴结构刷新。 */
	void AddUMGBinding(UUserWidgetBlueprint* InUserWidgetBP);
};
