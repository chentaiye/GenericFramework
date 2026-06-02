// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FileHelpers.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctions_Asset.generated.h"

/** 集中暴露资产蓝图函数库接口，让蓝图通过稳定入口访问编辑器扩展功能。 */
UCLASS(MinimalAPI)
class UBPFunctions_Asset : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/** 读取资产数据，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API FAssetData GetAssetData(const UObject* InAsset);

	/** 读取资产数据By路径，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API TArray<FAssetData> GetAssetsDataByPath(const FString& InAssetPackagePath);

	/** 读取资产包路径，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API FName GetAssetPackagePath(const UObject* InAsset);

	/** 读取资产包名，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API FPackagePath GetAssetPackageName(const UObject* InAsset);

	/** 读取资产本地完整路径，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API FString GetAssetLocalFullPath(const UObject* InAsset);

	/** 读取资产完整路径，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API FString GetAssetFullPath(const UObject* InAsset);

	/** 读取资产完整目录路径，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API FString GetAssetFullDirectoryPath(const UObject* InAsset);

	/** 读取资产扩展名，封装底层查询细节并减少蓝图侧样板逻辑。 */
	static GENERICEDITORFRAMEWORK_API FString GetAssetExtension(const UObject* InAsset);

	/** 生成唯一资产名称，避免新资产写入时与现有包路径冲突。 */
	static GENERICEDITORFRAMEWORK_API FString CreateUniqueAssetName(FString InPackageName, FString InSuffix = "");

	/** 重命名重命名资产，同步资产注册表和编辑器可见路径。 */
	static GENERICEDITORFRAMEWORK_API void RenameAsset(UObject* InAsset, FString NewName);

	/** 保存资产，把编辑器中的脏包或资产数据写回磁盘。 */
	static GENERICEDITORFRAMEWORK_API bool SaveAsset(const UObject* InAsset);

	/** 保存资产，把编辑器中的脏包或资产数据写回磁盘。 */
	static GENERICEDITORFRAMEWORK_API FEditorFileUtils::EPromptReturnCode SaveAssets(TArray<UObject*> InAssets);

	/** 保存资产And修复引用，把编辑器中的脏包或资产数据写回磁盘。 */
	static GENERICEDITORFRAMEWORK_API FEditorFileUtils::EPromptReturnCode SaveAssetsAndFixupReferencer(TArray<UObject*> InAssets);

	/** 删除资产，并让编辑器资产系统同步清理引用状态。 */
	static GENERICEDITORFRAMEWORK_API void DeleteAsset(UObject* InAsset);

	/** 删除资产，并让编辑器资产系统同步清理引用状态。 */
	static GENERICEDITORFRAMEWORK_API void DeleteAssets(TArray<UObject*> InAssets);

	/** 修复资产引用，整理重定向并保持资产引用一致。 */
	static GENERICEDITORFRAMEWORK_API void FixupAssetReferencer(UObject* InAsset);

	/** 修复资产引用，整理重定向并保持资产引用一致。 */
	static GENERICEDITORFRAMEWORK_API void FixupAssetsReferencer(TArray<UObject*> InAssets);
};
