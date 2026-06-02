// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Obect/GenericObject.h"
#include "GenericWorldSettings.generated.h"

/** 作为世界级设置项的基类，派生类实例会嵌入指定地图的设置总集中随地图持久化。 */
UCLASS(Abstract, Blueprintable, EditInlineNew, DefaultToInstanced)
class GENERICSETTINGSFRAMEWORK_API UGenericWorldSettings : public UGenericObject
{
	GENERATED_BODY()

public:
	UGenericWorldSettings(const FObjectInitializer& ObjectInitializer);

	virtual void PostLoad() override;
	virtual void BeginDestroy() override;

#if WITH_EDITOR
	virtual void PreSave(FObjectPreSaveContext SaveContext) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

#if WITH_EDITOR
	/** 返回编辑器管理界面左侧列表使用的名称，默认使用类显示名。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Generic World Settings")
	FText GetSettingsDisplayName() const;

	/** 返回编辑器管理界面用于解释设置用途的描述文本。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Generic World Settings")
	FText GetSettingsDescription() const;

	/** 返回编辑器左侧分组使用的分类名，未设置时回落到 Default。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Generic World Settings")
	FName GetSettingsCategory() const;

	/** 判断该设置实例是否适用于当前编辑世界；失效时左侧列表保留可选中状态，但右侧不展示 Details。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Generic World Settings")
	bool IsWorldSettingsEnabled(UWorld* World) const;

	/** 返回设置在当前编辑世界下失效的说明文本，用于右侧面板解释为什么不能编辑。 */
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Generic World Settings")
	FText GetWorldSettingsDisabledReason(UWorld* World) const;

	/** 编辑器创建该设置实例并加入当前世界总集后触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsEditorCreated(UWorld* World);

	/** 编辑器世界读取到该设置实例后触发，用于准备只在编辑器预览中需要的临时状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsEditorLoaded(UWorld* World);

	/** Details 面板或属性系统修改该设置实例后触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsEditorChanged(UWorld* World);

	/** 当前世界保存前触发，可用于把派生类缓存写回可序列化属性。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsEditorPreSave(UWorld* World);

	/** 当前世界保存成功后触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsEditorSaved(UWorld* World);

	/** 编辑器管理器释放当前世界设置引用时触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsEditorUnloaded(UWorld* World);
#endif

	/** UObject 完成反序列化后触发，编辑器和运行时都会覆盖到。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsPostLoad();

	/** 运行时设置总集完成读取后触发，派生类可在这里准备只依赖配置值的轻量状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsLoaded(UWorld* World);

	/** 运行世界 BeginPlay 后触发，用于按已读取的设置执行世界初始化。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsBeginPlay(UWorld* World);

	/** 世界进入 MatchStarting 阶段后触发；此时 Actor BeginPlay 已完成，适合依赖场景对象注册结果的初始化。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsMatchStarting(UWorld* World);

	/** 世界完成 BeginPlay 广播后触发；此时 GameMode/Actor 的开始流程已收束，适合执行最终运行时联动。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsPostBeginPlay(UWorld* World);

	/** 运行世界开始 TearDown 时触发，用于停止依赖该世界的逻辑。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsBeginTearDown(UWorld* World);

	/** 运行时设置总集从子系统释放前触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsUnloaded(UWorld* World);

	/** UObject 进入销毁流程前触发，用于释放不依赖世界的临时状态。 */
	UFUNCTION(BlueprintNativeEvent, Category="Generic World Settings|Lifecycle")
	void OnWorldSettingsBeginDestroy();
};
