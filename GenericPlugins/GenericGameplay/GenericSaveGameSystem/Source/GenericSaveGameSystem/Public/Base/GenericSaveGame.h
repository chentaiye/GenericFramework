// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SaveGameType.h"
#include "Base/GenericVersionObject.h"
#include "GameFramework/SaveGame.h"
#include "Types/GenericVersionTypes.h"
#include "GenericSaveGame.generated.h"

class UGenericSaveGame;

USTRUCT(BlueprintType)
struct GENERICSAVEGAMESYSTEM_API FOnSaveGameDirtyMessage
{
	GENERATED_BODY()

	/** Dirty 变化对应的槽位名，自动保存系统用它提交异步保存。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Dirty Message")
	FString SlotName;

	/** 发生 Dirty 变化的 SaveGame 实例。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Dirty Message")
	TObjectPtr<UGenericSaveGame> SaveGame = nullptr;

	/** 当前 Dirty 状态；true 表示等待保存，false 表示已清理。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Dirty Message")
	bool bIsDirty = false;

	/** Dirty 递增序号，自动保存完成时用它避免清理保存期间再次产生的新变更。 */
	UPROPERTY(BlueprintReadOnly, Category="SaveGame Dirty Message")
	int32 DirtySerial = 0;
};

/** GenericSaveGameSystem 的存档数据基类，保存跨槽位复用的存档元数据和业务派生字段。 */
UCLASS(Blueprintable, BlueprintType, MinimalAPI)
class UGenericSaveGame : public USaveGame, public FGenericVersionObject
{
	GENERATED_BODY()

public:
	/** 创建可被 GenericSaveGameSystem 统一读写的存档对象。 */
	GENERICSAVEGAMESYSTEM_API UGenericSaveGame(const FObjectInitializer& ObjectInitializer);

public:
	/** 存档对象登记到中心运行时表后触发，派生类可在这里准备依赖注册状态的临时数据。 */
	UFUNCTION(BlueprintNativeEvent, Category="SaveGame|Lifecycle")
	GENERICSAVEGAMESYSTEM_API void OnInitialized();

	/** 存档对象的槽位名、路径、类包名和保存时间被系统刷新后触发。 */
	UFUNCTION(BlueprintNativeEvent, Category="SaveGame|Lifecycle")
	GENERICSAVEGAMESYSTEM_API void OnRefresh();

	/** 存档对象从中心运行时表移除后触发，派生类可在这里释放运行时缓存或监听句柄。 */
	UFUNCTION(BlueprintNativeEvent, Category="SaveGame|Lifecycle")
	GENERICSAVEGAMESYSTEM_API void OnDeinitialized();

public:
	/** 返回当前对象对应的逻辑槽位名，蓝图侧只读取，不直接改写中心登记键。 */
	UFUNCTION(BlueprintPure, Category="SaveGame")
	GENERICSAVEGAMESYSTEM_API FString GetSlotName();

	/** 由 C++ 保存加载流程写入当前对象对应的逻辑槽位名。 */
	GENERICSAVEGAMESYSTEM_API void SetSlotName(const FString& InSlotName);

	/** 返回当前对象相对 Saved/SaveGames 的文件路径，用于 UI 展示或调试定位。 */
	UFUNCTION(BlueprintPure, Category="SaveGame")
	GENERICSAVEGAMESYSTEM_API FString GetPathName();

	/** 由 C++ 保存加载流程写入当前对象相对 Saved/SaveGames 的文件路径。 */
	GENERICSAVEGAMESYSTEM_API void SetPathName(const FString& InPathName);

	/** 返回当前对象所属类的包名，用于判断槽位内容和类来源是否一致。 */
	UFUNCTION(BlueprintPure, Category="SaveGame")
	GENERICSAVEGAMESYSTEM_API FString GetClassPackageName();

	/** 由 C++ 保存加载流程写入当前对象所属类的包名。 */
	GENERICSAVEGAMESYSTEM_API void SetClassPackageName(const FString& InClassPackageName);

	/** 返回最近一次刷新存档元数据时记录的本地时间。 */
	UFUNCTION(BlueprintPure, Category="SaveGame")
	GENERICSAVEGAMESYSTEM_API FDateTime GetSaveTime();

	/** 由 C++ 保存加载流程写入最近一次刷新存档元数据的本地时间。 */
	GENERICSAVEGAMESYSTEM_API void SetSaveTime(const FDateTime& InSaveTime);

public:
	/** 返回当前存档对象是否已被业务标记为脏数据。 */
	UFUNCTION(BlueprintPure, Category="SaveGame")
	GENERICSAVEGAMESYSTEM_API bool GetIsDirty() const;

	/** 将当前对象固定标记为脏，并通过 GameplayMessage 通知自动保存系统。 */
	UFUNCTION(BlueprintCallable, Category="SaveGame")
	GENERICSAVEGAMESYSTEM_API void MarkAsDirty();

	/** 立刻按当前 SlotName 异步保存该对象。 */
	UFUNCTION(BlueprintCallable, Category="SaveGame")
	GENERICSAVEGAMESYSTEM_API bool SaveInstant();

	/** 清理 Dirty 状态；ExpectedDirtySerial 有效时仅清理同一次自动保存对应的脏标记。 */
	GENERICSAVEGAMESYSTEM_API bool ClearDirty(int32 ExpectedDirtySerial = INDEX_NONE);

	/** 返回当前 Dirty 序号，保存完成时用于判断期间是否再次产生变更。 */
	GENERICSAVEGAMESYSTEM_API int32 GetDirtySerial() const;

public:
	/** 返回该存档对象持久化的版本数据，业务层可用它和 GenericVersionFramework 的中央定义进行迁移或校验。 */
	GENERICSAVEGAMESYSTEM_API virtual UObject* GetVersionTargetObject() const override;

	UFUNCTION(BlueprintPure, Category="SaveGame|Version")
	GENERICSAVEGAMESYSTEM_API virtual FGenericVersionData GetVersion() const override;

	/** 由 C++ 保存加载流程写入该存档对象的版本数据。 */
	GENERICSAVEGAMESYSTEM_API virtual void SetVersion(const FGenericVersionData& InVersion) override;

	/** 返回当前存档类 SaveGame 字段的结构签名，用于发现新增、删除或类型变化后的旧档。 */
	UFUNCTION(BlueprintPure, Category="SaveGame|Version")
	GENERICSAVEGAMESYSTEM_API virtual FString GetPropertySchemaSignature() const override;

	/** 由 C++ 保存加载流程写入当前存档类 SaveGame 字段的结构签名。 */
	GENERICSAVEGAMESYSTEM_API virtual void SetPropertySchemaSignature(const FString& InPropertySchemaSignature) override;

	/** 计算当前类可持久化业务字段的结构签名，不包含 UGenericSaveGame 自身维护的元数据字段。 */
	GENERICSAVEGAMESYSTEM_API virtual FString BuildCurrentPropertySchemaSignature() const override;

public:
	/** 校验 SaveGame 持久化版本和当前类元数据，派生类可补充字段级兼容规则。 */
	GENERICSAVEGAMESYSTEM_API virtual FGenericVersionValidationResult ValidateGenericVersion(const FGenericVersionContext& Context) override;

	/** 校验成功或仅有警告时触发，供派生类同步提示或调试状态。 */
	GENERICSAVEGAMESYSTEM_API virtual void HandleVersionValidationSuccess(const FGenericVersionValidationResult& Result) override;

	/** 校验失败时触发，RegisterSaveGame 会阻止该对象进入运行时表。 */
	GENERICSAVEGAMESYSTEM_API virtual void HandleVersionValidationFailure(const FGenericVersionValidationResult& Result) override;

public:
	/** 迁移 SaveGame 持久化版本，默认只推进版本元数据，具体字段迁移由派生类重写。 */
	GENERICSAVEGAMESYSTEM_API virtual FGenericVersionMigrationResult MigrateGenericVersion(const FGenericVersionContext& Context) override;

	/** 迁移成功时触发，供派生类记录兼容处理结果。 */
	GENERICSAVEGAMESYSTEM_API virtual void HandleVersionMigrationSuccess(const FGenericVersionMigrationResult& Result) override;

	/** 迁移失败时触发，RegisterSaveGame 会阻止该对象进入运行时表。 */
	GENERICSAVEGAMESYSTEM_API virtual void HandleVersionMigrationFailure(const FGenericVersionMigrationResult& Result) override;

protected:
	/** 当前对象对应的逻辑槽位名，只保留完整槽位路径的最后一段，例如 Global/A 对应 A。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="SaveGame")
	FString SlotName;

	/** 当前对象相对 Saved/SaveGames 的文件路径，例如 Global/A 对应 /Global/A.sav。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="SaveGame")
	FString PathName;

	/** 记录当前存档对象所属类的包名，用于排查槽位内容和类来源是否一致。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="SaveGame")
	FString ClassPackageName;

	/** 记录最近一次保存完成后的本地时间。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="SaveGame")
	FDateTime SaveTime;

protected:
	/** 标记当前存档对象是否已经被业务修改，当前阶段只作为可读写状态。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SaveGame")
	bool bIsDirty = false;

	/** Dirty 状态每次变为脏时递增，避免异步保存完成后误清理新的修改。 */
	UPROPERTY(Transient)
	int32 DirtySerial = 0;

protected:
	/** 随存档文件持久化的版本数据，用于版本框架执行显式迁移和校验。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="SaveGame|Version")
	FGenericVersionData Version;

	/** 随存档文件持久化的字段结构签名，用于在版本号未更新时发现字段集合变化。 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, SaveGame, Category="SaveGame|Version")
	FString PropertySchemaSignature;

private:
	/** 修改 Dirty 状态并按需广播消息。 */
	void SetDirtyState(bool bInIsDirty, bool bBroadcast);
};
