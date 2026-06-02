#pragma once

#include "CoreMinimal.h"
#include "IAssetTools.h"
#include "Modules/ModuleManager.h"

class UExternalData;

/** 监听编辑器资产注册表事件，把 UExternalData 资产的新增、删除和重命名同步到对应的外部 JSON 文件。 */
class FExternalDataEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** 在资产重命名回调中识别 UExternalData 并复用清理流程，使资产名称变化时外部 JSON 不脱离资产生命周期。 */
	void RenameExternalData(FAssetData InAsset, const FString& OldPath);

	/** 从资产注册表数据解析 UExternalData 后删除外部 JSON，供资产移除事件在尚有 AssetData 信息时调用。 */
	void DeleteExternalData(FAssetData InAsset);

	/** 使用 UExternalData 自身生成的 JSON 路径执行物理删除，是移除和重命名同步流程共用的底层清理入口。 */
	void DeleteExternalData(UExternalData* InExternalData);

	/** 响应资产新增事件，发现 UExternalData 后立即保存一次 RowStruct，确保新资产有对应的 Config/ExternalData JSON。 */
	void OnAssetsAdded(TConstArrayView<FAssetData> Assets);

	/** 响应资产移除事件，删除被移除 UExternalData 的外部 JSON，避免项目配置目录残留孤立文件。 */
	void OnAssetsRemoved(TConstArrayView<FAssetData> Assets);

	/** 响应资产重命名事件，仅对 UExternalData 进入外部文件同步逻辑，其他资产类型保持默认编辑器行为。 */
	void OnAssetRenamed(const FAssetData& Asset, const FString& OldPath);
};
