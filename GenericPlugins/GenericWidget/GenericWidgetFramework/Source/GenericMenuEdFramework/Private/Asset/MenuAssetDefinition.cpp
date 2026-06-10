// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Asset/MenuAssetDefinition.h"

#include "Asset/MenuAssetEditorToolkit.h"
#include "Base/MenuAsset.h"

#define LOCTEXT_NAMESPACE "MenuAssetDefinition"

FText UMenuAssetDefinition::GetAssetDisplayName() const
{
	return LOCTEXT("MenuAssetDisplayName", "Menu Asset");
}

FText UMenuAssetDefinition::GetAssetDescription(const FAssetData& AssetData) const
{
	return LOCTEXT("MenuAssetDescription", "Stores a menu tree authored as connected nodes.");
}

FLinearColor UMenuAssetDefinition::GetAssetColor() const
{
	return FLinearColor(0.1f, 0.35f, 0.9f);
}

TSoftClassPtr<UObject> UMenuAssetDefinition::GetAssetClass() const
{
	return UMenuAsset::StaticClass();
}

FAssetOpenSupport UMenuAssetDefinition::GetAssetOpenSupport(const FAssetOpenSupportArgs& OpenSupportArgs) const
{
	return FAssetOpenSupport(OpenSupportArgs.OpenMethod, OpenSupportArgs.OpenMethod == EAssetOpenMethod::Edit, EToolkitMode::Standalone);
}

EAssetCommandResult UMenuAssetDefinition::OpenAssets(const FAssetOpenArgs& OpenArgs) const
{
	for (UMenuAsset* MenuAsset : OpenArgs.LoadObjects<UMenuAsset>())
	{
		if (MenuAsset)
		{
			TSharedRef<FMenuAssetEditorToolkit> EditorToolkit = MakeShared<FMenuAssetEditorToolkit>();
			EditorToolkit->InitMenuAssetEditor(OpenArgs.GetToolkitMode(), OpenArgs.ToolkitHost, MenuAsset);
		}
	}

	return EAssetCommandResult::Handled;
}

#undef LOCTEXT_NAMESPACE
