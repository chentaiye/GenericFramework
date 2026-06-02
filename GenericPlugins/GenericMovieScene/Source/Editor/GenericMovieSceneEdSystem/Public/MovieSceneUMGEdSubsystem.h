// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interface/StateInterface.h"
#include "Obect/GenericObject.h"
#include "Track/MovieSceneUMGEdTrack.h"
#include "Subsystem/GenericEditorSubsystem.h"
#include "MovieSceneUMGEdSubsystem.generated.h"

class SConstraintCanvas;
class ILevelEditor;
class ISequencer;

/** 编辑器视口中的 UMG 预览面板，持有 Slate 画布并把 Sequencer 中已生成的 Widget 挂到视口。 */
UCLASS(MinimalAPI)
class UMovieSceneUMGPanel : public UGenericObject, public IStateInterface
{
	GENERATED_BODY()

	/* IProcedureBaseInterface */
public:
	virtual void NativeOnCreate() override;
	virtual void NativeOnDestroy() override;

	/* UGamePanel */
protected:
	/** 将内部 SConstraintCanvas 加入目标关卡编辑器视口，供后续刷新填充 Widget。 */
	virtual void HandleAddToViewport();

	/** 从目标关卡编辑器视口移除内部画布，销毁面板时避免残留 Slate 内容。 */
	virtual void HandleRemoveFromViewport();

public:
	/** 当前面板挂载的关卡编辑器视口，生成面板时由子系统从编辑器视口列表中写入。 */
	FLevelEditorViewportClient* LevelEditorViewportClient=nullptr;

	/** 用 Sequencer 当前应生成的 UserWidget 列表重建画布内容，保持编辑器预览与时间轴一致。 */
	virtual void RefreshMovieSceneUMG(const TArray<UUserWidget*>& InUserWidgets);

protected:
	/** 承载预览 Widget 的 Slate 画布，创建时加入视口，销毁时清空并移除。 */
	TSharedPtr<SConstraintCanvas> ConstraintCanvas=nullptr;
};

/** 编辑器子系统，监听 LevelEditor 与 Sequencer 生命周期并刷新 UMG 轨道在编辑器视口中的预览。 */
UCLASS(MinimalAPI)
class UMovieSceneUMGEdSubsystem : public UGenericEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	/** PIE 开始时销毁编辑器视口预览，避免播放态和编辑器态同时持有同一 Widget。 */
	virtual void OnPIEStarted(UGameInstance* InGameInstance);

	/** PIE 结束后重建编辑器视口预览，让 Sequencer 编辑状态恢复可见。 */
	virtual void OnPIEEnded(UGameInstance* InGameInstance);

protected:
#if WITH_EDITORONLY_DATA
	/** 当前创建的编辑器 UMG 预览面板集合，销毁和刷新流程会批量遍历它们。 */
	UPROPERTY(Transient)
	TArray<UMovieSceneUMGPanel*> MovieSceneUMGPanels;
#endif

	FDelegateHandle LevelEditorCreatedHandle;

	/** 关卡编辑器创建后重建预览面板，确保新视口能显示 Sequencer UMG 预览。 */
	void OnLevelEditorCreated(TSharedPtr<ILevelEditor> LevelEditor);

	FDelegateHandle LevelViewportClientListChangedHandle;

	/** 视口列表变化时重建预览面板，让面板挂载到仍然有效的编辑器视口。 */
	void OnLevelViewportClientListChanged();

public:
	/** 为可用关卡编辑器视口创建预览面板，并立即按当前 Sequencer 时间刷新显示内容。 */
	void GenerateMovieSceneUMGPanels();

	/** 销毁所有预览面板并清空缓存，防止视口变化或 PIE 切换时残留 Widget。 */
	void DestroyMovieSceneUMGPanels();

	/** 扫描已打开 Sequencer 中当前应生成的 Widget，并刷新到所有编辑器预览面板。 */
	void RefreshMovieSceneUMGPanels();

protected:
	/** 创建单个预览面板对象并加入面板缓存，子类可重写以提供定制面板。 */
	virtual UMovieSceneUMGPanel* CreateMovieSceneUMGPanel();

private:
	/** 当前被子系统跟踪的 Sequencer 弱引用，关闭或失效后会在回调中清理。 */
	TArray<TWeakPtr<ISequencer>> Sequencers;

	FDelegateHandle OnSequencerCreatedHandle;

	/** Sequencer 创建后登记关闭和时间变化回调，并将其加入预览刷新来源。 */
	void OnSequencerCreated(TSharedRef<ISequencer> InSequencer);

	/** Sequencer 关闭时解除其回调并移出跟踪列表，随后刷新面板去掉失效 Widget。 */
	void OnSequencerClosed(TSharedRef<ISequencer> InSequencer);

	/** Sequencer 全局时间变化时重新评估 Spawn Track，使编辑器视口预览跟随时间轴。 */
	void OnGlobalTimeChanged();
};
