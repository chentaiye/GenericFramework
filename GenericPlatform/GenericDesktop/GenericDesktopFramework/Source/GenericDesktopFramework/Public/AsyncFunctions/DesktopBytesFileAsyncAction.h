#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Type/DesktopType.h"
#include "DesktopBytesFileAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDesktopBytesFileCompleted, const FDesktopBytesResult&, Result);

/** 提供桌面字节数文件异步动作能力。 */
UCLASS(MinimalAPI)
class UDesktopBytesFileAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	GENERICDESKTOPFRAMEWORK_API virtual void Activate() override;

	/** 处理异步读取字节数From文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICDESKTOPFRAMEWORK_API UDesktopBytesFileAsyncAction* AsyncReadBytesFromFile(const FString& FileName);

	/** 处理异步写入字节数To文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICDESKTOPFRAMEWORK_API UDesktopBytesFileAsyncAction* AsyncWriteBytesToFile(const FString& FileName, const TArray<uint8>& Data);

	/** 保存On已完成。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnDesktopBytesFileCompleted OnCompleted;

private:
	/** 定义字节数文件模式取值。 */
	enum class EBytesFileMode : uint8
	{
		/** 表示读取选项。 */
		Read,
		/** 表示写入选项。 */
		Write
	};

	/** 保存文件模式。 */
	EBytesFileMode FileMode = EBytesFileMode::Read;
	/** 保存缓存文件名称。 */
	FString CachedFileName;
	/** 保存缓存数据。 */
	TArray<uint8> CachedData;
};
