// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NativeGameplayTags.h"
#include "GenericVersionTypes.generated.h"

GENERICVERSIONFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayVersion);

/** 表示业务数据结构版本，版本号只随数据语义变化而变化，不对应项目打包版本。 */
USTRUCT(BlueprintType)
struct GENERICVERSIONFRAMEWORK_API FGenericVersionInfo
{
	GENERATED_BODY()

	/** 主版本号，通常用于破坏性数据结构变化。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	int32 Major = 1;

	/** 次版本号，通常用于字段增删、重命名或枚举兼容调整。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	int32 Minor = 0;

	/** 修订版本号，通常用于默认值修正或小范围数据清理。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	int32 Patch = 0;

	FGenericVersionInfo()
	{
	}

	FGenericVersionInfo(const int32 InMajor, const int32 InMinor, const int32 InPatch)
		: Major(InMajor),
		  Minor(InMinor),
		  Patch(InPatch)
	{
	}

	bool IsValid() const { return Major > 0 || Minor > 0 || Patch > 0; }
	FString ToString() const { return FString::Printf(TEXT("%d.%d.%d"), Major, Minor, Patch); }

	bool operator==(const FGenericVersionInfo& Other) const { return Major == Other.Major && Minor == Other.Minor && Patch == Other.Patch; }
	bool operator!=(const FGenericVersionInfo& Other) const { return !(*this == Other); }
	bool operator<(const FGenericVersionInfo& Other) const
	{
		if (Major != Other.Major)
		{
			return Major < Other.Major;
		}
		if (Minor != Other.Minor)
		{
			return Minor < Other.Minor;
		}
		return Patch < Other.Patch;
	}
	bool operator<=(const FGenericVersionInfo& Other) const { return *this < Other || *this == Other; }
	bool operator>(const FGenericVersionInfo& Other) const { return !(*this <= Other); }
	bool operator>=(const FGenericVersionInfo& Other) const { return !(*this < Other); }
};

/** 中央版本定义，表示项目当前代码对某类数据的版本策略。 */
USTRUCT(BlueprintType)
struct GENERICVERSIONFRAMEWORK_API FGenericVersionDefinition
{
	GENERATED_BODY()

	/** 用于匹配业务数据类型的稳定版本键。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version", meta=(Categories="GameplayVersion"))
	FGameplayTag VersionKey = TAG_GameplayVersion;

	/** 当前代码可写出的数据版本，业务对象自己的版本会与它进行比较。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	FGenericVersionInfo Version;

	/** 当前代码仍允许处理的最低数据版本。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	FGenericVersionInfo MinimumSupportedVersion;

	/** 数据来源名称，仅用于日志、调试或界面展示。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	FString SourceName;

	bool IsValid() const { return VersionKey.MatchesTag(TAG_GameplayVersion) && Version.IsValid() && MinimumSupportedVersion.IsValid() && MinimumSupportedVersion <= Version; }
};

/** 对象自身携带的版本数据，只描述磁盘或运行时对象当前处于哪个数据版本。 */
USTRUCT(BlueprintType)
struct GENERICVERSIONFRAMEWORK_API FGenericVersionData
{
	GENERATED_BODY()

	/** 业务层提供的版本键，用于在中心表中定位同一类数据。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version", meta=(Categories="GameplayVersion"))
	FGameplayTag VersionKey = TAG_GameplayVersion;

	/** 对象当前携带的数据版本。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	FGenericVersionInfo Version;

	/** 数据来源名称，仅用于日志、调试或界面展示。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	FString SourceName;

	bool IsValid() const { return VersionKey.MatchesTag(TAG_GameplayVersion) && Version.IsValid(); }
};

/** 校验结果对业务流程的影响级别。 */
UENUM(BlueprintType)
enum class EGenericVersionValidationStatus : uint8
{
	/** 校验通过，业务层可继续自己的后续流程。 */
	Success,

	/** 校验发现非阻断问题，业务层可自行决定是否提示或记录。 */
	Warning,

	/** 校验失败，业务层应停止依赖该对象的后续流程。 */
	Failed
};

/** 版本校验的单次执行结果。 */
USTRUCT(BlueprintType)
struct GENERICVERSIONFRAMEWORK_API FGenericVersionValidationResult
{
	GENERATED_BODY()

	/** 本次校验的结果级别。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version Validation")
	EGenericVersionValidationStatus Status = EGenericVersionValidationStatus::Success;

	/** 业务层可用于识别问题来源的稳定错误码。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version Validation")
	FName ErrorCode;

	/** 面向日志、提示或调试面板的说明文本。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version Validation")
	FText Message;

	bool IsSuccess() const { return Status == EGenericVersionValidationStatus::Success; }
	bool IsWarning() const { return Status == EGenericVersionValidationStatus::Warning; }
	bool IsFailed() const { return Status == EGenericVersionValidationStatus::Failed; }
	bool IsBlocking() const { return IsFailed(); }

	static FGenericVersionValidationResult Success(const FText& InMessage = FText());
	static FGenericVersionValidationResult Warning(FName InErrorCode, const FText& InMessage);
	static FGenericVersionValidationResult Failed(FName InErrorCode, const FText& InMessage);
};

/** 版本迁移的单次执行结果。 */
USTRUCT(BlueprintType)
struct GENERICVERSIONFRAMEWORK_API FGenericVersionMigrationResult
{
	GENERATED_BODY()

	/** 迁移开始时对象携带的版本。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version Migration")
	FGenericVersionInfo SourceVersion;

	/** 迁移完成后对象应达到的版本。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version Migration")
	FGenericVersionInfo TargetVersion;

	/** 标识本次迁移是否成功。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version Migration")
	bool bSuccess = false;

	/** 迁移失败时用于定位问题的稳定错误码。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version Migration")
	FName ErrorCode;

	/** 迁移失败或警告时面向日志和界面的说明。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version Migration")
	FText Message;

	static FGenericVersionMigrationResult Success(const FGenericVersionInfo& InSourceVersion, const FGenericVersionInfo& InTargetVersion, const FText& InMessage = FText());
	static FGenericVersionMigrationResult Failed(const FGenericVersionInfo& InSourceVersion, const FGenericVersionInfo& InTargetVersion, FName InErrorCode, const FText& InMessage);
};

/** 单次校验或迁移调用的上下文，由业务层按需要填充。 */
USTRUCT(BlueprintType)
struct GENERICVERSIONFRAMEWORK_API FGenericVersionContext
{
	GENERATED_BODY()

	/** 被校验或迁移的目标对象。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	TObjectPtr<UObject> TargetObject = nullptr;

	/** 本次调用对应的版本键。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version", meta=(Categories="GameplayVersion"))
	FGameplayTag VersionKey = TAG_GameplayVersion;

	/** 从中心版本子系统读取到的版本数据快照。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	FGenericVersionData VersionData;

	/** 从中心版本子系统读取到的中央版本定义。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	FGenericVersionDefinition VersionDefinition;

	/** 业务层传入的可选上下文对象，例如 WorldContext、Subsystem 或调用来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Version")
	TObjectPtr<UObject> ContextObject = nullptr;
};
