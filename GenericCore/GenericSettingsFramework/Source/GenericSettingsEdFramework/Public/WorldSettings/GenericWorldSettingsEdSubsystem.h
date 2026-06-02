// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "Containers/Ticker.h"
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "UObject/ObjectKey.h"
#include "GenericWorldSettingsEdSubsystem.generated.h"

class AWorldSettings;
class FObjectPostSaveContext;
class SDockTab;
class UGenericWorldSettings;
class UGenericWorldSettingsCollection;
class UWorld;
class FSpawnTabArgs;

DECLARE_MULTICAST_DELEGATE(FGenericWorldSettingsClassesChangedDelegate)

namespace GenericWorldSettingsEditor
{
GENERICSETTINGSEDFRAMEWORK_API extern const FName WorldSettingsTabName;
}

/** 在编辑器侧管理世界级设置的类型发现、地图内总集维护和自定义编辑器内容。 */
UCLASS(MinimalAPI)
class UGenericWorldSettingsEdSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	/** 注册外部模块显式声明的世界设置类型，适合尚未被资产扫描覆盖的运行时或插件类。 */
	static GENERICSETTINGSEDFRAMEWORK_API void RegisterWorldSettingsClass(TSubclassOf<UGenericWorldSettings> SettingsClass);

	/** 移除外部模块曾经显式注册的世界设置类型，不会删除地图中已经保存的数据。 */
	static GENERICSETTINGSEDFRAMEWORK_API void UnregisterWorldSettingsClass(TSubclassOf<UGenericWorldSettings> SettingsClass);

	/** 返回当前手动注册的有效设置类型，供模块自检或调试界面展示。 */
	static GENERICSETTINGSEDFRAMEWORK_API TArray<TSubclassOf<UGenericWorldSettings>> GetRegisteredWorldSettingsClasses();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** 轻量刷新已加载的设置类型，不扫描或同步加载蓝图资产。 */
	GENERICSETTINGSEDFRAMEWORK_API void RefreshWorldSettingsClasses();

	/** 请求异步刷新世界设置类型；首次打开页签时只触发加载状态，不阻塞窗口显示。 */
	GENERICSETTINGSEDFRAMEWORK_API void RequestAsyncRefreshWorldSettingsClasses(bool bForce = false);

	/** 返回世界设置类型是否仍在后台发现或分帧解析中。 */
	GENERICSETTINGSEDFRAMEWORK_API bool IsRefreshingWorldSettingsClasses() const;

	/** 返回世界设置类型是否至少完成过一次发现流程。 */
	GENERICSETTINGSEDFRAMEWORK_API bool HasLoadedWorldSettingsClasses() const;

	/** 类型发现状态变化或刷新完成时广播，Slate 面板据此切换 Loading 与真实内容。 */
	GENERICSETTINGSEDFRAMEWORK_API FGenericWorldSettingsClassesChangedDelegate& OnWorldSettingsClassesChanged();

	/** 返回编辑器当前可见的世界设置类型集合，已经合并自动发现和手动注册结果。 */
	GENERICSETTINGSEDFRAMEWORK_API const TArray<TSubclassOf<UGenericWorldSettings>>& GetWorldSettingsClasses() const;

	/** 返回当前关卡编辑器正在编辑的世界，避免把设置写入 PIE 或临时预览世界。 */
	GENERICSETTINGSEDFRAMEWORK_API UWorld* GetEditorWorld() const;

	/** 返回当前编辑世界的 AWorldSettings，所有总集数据都挂在它的 AssetUserData 上。 */
	GENERICSETTINGSEDFRAMEWORK_API AWorldSettings* GetEditorWorldSettings() const;

	/** 查找当前世界已经保存的设置总集；不存在时仅返回空，不自动创建。 */
	GENERICSETTINGSEDFRAMEWORK_API UGenericWorldSettingsCollection* GetSettingsCollection() const;

	/** 在当前世界创建唯一设置总集，并把总集挂到 AWorldSettings::AssetUserData。 */
	GENERICSETTINGSEDFRAMEWORK_API UGenericWorldSettingsCollection* CreateSettingsCollection();

	/** 从当前世界移除已保存的设置总集，删除后地图会被标记为已修改。 */
	GENERICSETTINGSEDFRAMEWORK_API bool DeleteSettingsCollection();

	/** 为当前世界补齐已发现但尚未实例化的设置类型，保留所有既有设置值。 */
	GENERICSETTINGSEDFRAMEWORK_API int32 SyncMissingSettings();

	/** 保存当前世界所在地图包，不保存独立资产或全局配置文件。 */
	GENERICSETTINGSEDFRAMEWORK_API bool SaveCurrentWorld() const;

	/** 判断当前世界的总集中是否缺少任何已发现或已注册的设置实例。 */
	GENERICSETTINGSEDFRAMEWORK_API bool HasMissingSettings() const;

	/** 按精确类型返回当前世界中的设置实例，供编辑器列表和 Details 面板定位对象。 */
	GENERICSETTINGSEDFRAMEWORK_API UGenericWorldSettings* FindSettingsInstance(TSubclassOf<UGenericWorldSettings> SettingsClass) const;

protected:
	/** 构建 Generic World Settings 页签内容，并把 Slate 编辑器交给全局 TabManager 承载。 */
	TSharedRef<SDockTab> HandleSpawnWorldSettingsTab(const FSpawnTabArgs& SpawnTabArgs);

private:
	/** 编辑器地图切换时刷新设置实例的加载边界，避免旧世界实例一直保持编辑器 Loaded 状态。 */
	void HandleEditorMapChanged(uint32 MapChangeFlags);

	/** 编辑器通过任意入口保存当前地图成功后，通知设置实例完成保存。 */
	void HandleEditorPostSaveWorld(UWorld* World, FObjectPostSaveContext ObjectSaveContext);

	/** 合并手动注册类和已加载派生类，不触发蓝图类同步加载。 */
	void AddLoadedWorldSettingsClasses(TArray<TSubclassOf<UGenericWorldSettings>>& OutClasses, TSet<const UClass*>& SeenClasses) const;

	/** 对刷新后的设置类型按显示名排序，保证左侧列表稳定。 */
	void SortWorldSettingsClasses(TArray<TSubclassOf<UGenericWorldSettings>>& InOutClasses) const;

	/** 后台资产扫描完成后，在游戏线程启动蓝图生成类的分帧解析。 */
	void StartResolvingDiscoveredWorldSettingsClasses(TArray<FString>&& ClassObjectPaths, int32 RequestId);

	/** 每帧只解析少量蓝图类，避免首次打开页签时长时间阻塞编辑器线程。 */
	bool TickResolveDiscoveredWorldSettingsClasses(float DeltaTime);

	/** 在编辑器主线程等待 AssetRegistry 完成收集，再提取世界设置蓝图类路径。 */
	bool TickCollectDiscoveredWorldSettingsClassPaths(float DeltaTime, int32 RequestId);

	/** 完成异步刷新并通知所有打开的世界设置编辑器刷新真实内容。 */
	void CompleteWorldSettingsClassRefresh();

	/** 通知当前编辑世界中的设置实例已被编辑器管理器读取。 */
	void NotifyEditorSettingsLoaded();

	/** 通知当前编辑世界中的设置实例即将被编辑器管理器释放。 */
	void NotifyEditorSettingsUnloaded();

	/** 通知当前编辑世界中的设置实例已经保存成功。 */
	void NotifyEditorSettingsSaved() const;

	/** 停止当前分帧解析任务，通常发生在子系统销毁或重新发起刷新时。 */
	void StopWorldSettingsClassRefreshTicker();

	void StopWorldSettingsClassDiscoveryTicker();

	/** 验证设置类型是否可实例化并属于 UGenericWorldSettings 派生层级。 */
	static bool IsValidWorldSettingsClass(const UClass* SettingsClass);

	/** 把单个合法设置类型加入集合，并按精确类型去重。 */
	static void AddUniqueSettingsClass(UClass* SettingsClass, TArray<TSubclassOf<UGenericWorldSettings>>& OutClasses, TSet<const UClass*>& SeenClasses);

	/** 从蓝图资产中异步发现 UGenericWorldSettings 派生类路径。 */
	void DiscoverWorldSettingsClasses(TArray<TSubclassOf<UGenericWorldSettings>>& OutClasses) const;

	/** 标记当前世界包已被修改，确保总集和实例变更能随地图保存。 */
	void MarkCurrentWorldDirty() const;

private:
	/** 编辑器界面使用的设置类型缓存，刷新时会合并手动注册和自动发现的结果。 */
	TArray<TSubclassOf<UGenericWorldSettings>> WorldSettingsClasses;

	/** 后台发现到、等待在游戏线程分帧解析的蓝图生成类路径。 */
	TArray<FString> PendingWorldSettingsClassPaths;

	/** 当前异步刷新期间已经收集到的设置类型，完成后整体替换到 WorldSettingsClasses。 */
	TArray<TSubclassOf<UGenericWorldSettings>> PendingWorldSettingsClasses;

	/** 用于驱动蓝图类分帧解析的编辑器 Ticker 句柄。 */
	FTSTicker::FDelegateHandle WorldSettingsClassRefreshTickerHandle;

	FTSTicker::FDelegateHandle WorldSettingsClassDiscoveryTickerHandle;

	/** 标记当前是否处于异步发现或分帧解析阶段。 */
	bool bIsRefreshingWorldSettingsClasses = false;

	/** 标记类型发现是否至少完成过一次，避免首次打开前展示未准备好的空面板。 */
	bool bHasLoadedWorldSettingsClasses = false;

	/** 用于丢弃过期后台任务回调，防止旧请求覆盖新结果。 */
	int32 WorldSettingsClassRefreshRequestId = 0;

	/** 类型发现状态变化委托。 */
	FGenericWorldSettingsClassesChangedDelegate WorldSettingsClassesChangedDelegate;

	/** 已触发 EditorLoaded 的设置实例，用于避免同一个编辑器世界反复刷新时重复通知。 */
	TSet<TObjectKey<UGenericWorldSettings>> EditorLoadedSettings;

	/** 记录 EditorLoaded 当前对应的编辑器世界，用于地图切换时把卸载通知发给正确世界。 */
	TWeakObjectPtr<UWorld> EditorLoadedWorld;
};
