#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Type/DesktopType.h"
#include "DesktopStringFileAsyncAction.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDesktopStringFileCompleted, const FDesktopStringResult&, Result);

/** 提供桌面字符串文件异步动作能力。 */
UCLASS(MinimalAPI)
class UDesktopStringFileAsyncAction : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	GENERICDESKTOPFRAMEWORK_API virtual void Activate() override;

	/** 处理异步读取字符串From文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICDESKTOPFRAMEWORK_API UDesktopStringFileAsyncAction* AsyncReadStringFromFile(const FString& FileName);

	/** 处理异步写入字符串To文件。 */
	UFUNCTION(BlueprintCallable, Category="Window|File|Async", meta=(BlueprintInternalUseOnly="true"))
	static GENERICDESKTOPFRAMEWORK_API UDesktopStringFileAsyncAction* AsyncWriteStringToFile(const FString& Data, const FString& FileName, EDesktopTextEncodingOptions EncodingOptions = EDesktopTextEncodingOptions::AutoDetect);

	/** 保存On已完成。 */
	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnDesktopStringFileCompleted OnCompleted;

private:
	/** 定义字符串文件模式取值。 */
	enum class EStringFileMode : uint8
	{
		/** 表示读取选项。 */
		Read,
		/** 表示写入选项。 */
		Write
	};

	/** 保存文件模式。 */
	EStringFileMode FileMode = EStringFileMode::Read;
	/** 保存缓存文件名称。 */
	FString CachedFileName;
	/** 保存缓存数据。 */
	FString CachedData;
	/** 保存缓存编码选项。 */
	EDesktopTextEncodingOptions CachedEncodingOptions = EDesktopTextEncodingOptions::AutoDetect;
};
