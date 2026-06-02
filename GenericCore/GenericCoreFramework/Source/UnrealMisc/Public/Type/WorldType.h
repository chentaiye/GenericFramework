#pragma once

#include "CoreMinimal.h"

/** 定义E世界类型BP枚举，统一 C++、蓝图和编辑器配置中的分支语义。 */
UENUM(BlueprintType)
enum class EWorldTypeBP : uint8
{
	/** 表示不启用额外策略或没有有效类型。 */
	None,

	/** 表示游戏世界。 */
	Game,

	/** 表示编辑器世界。 */
	Editor,

	/** 表示编辑器内播放世界。 */
	PIE,

	/** 表示编辑器预览世界。 */
	EditorPreview,

	/** 表示游戏预览世界。 */
	GamePreview,

	/** 表示游戏 RPC 世界。 */
	GameRPC,

	/** 表示非活跃世界。 */
	Inactive
};

/** 转换To世界类型，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
static EWorldType::Type ConvertToWorldType(EWorldTypeBP SceneWorldType)
{
	switch (SceneWorldType)
	{
	case EWorldTypeBP::None:
		return EWorldType::None;

	case EWorldTypeBP::Game:
		return EWorldType::Game;

	case EWorldTypeBP::Editor:
		return EWorldType::Editor;

	case EWorldTypeBP::PIE:
		return EWorldType::PIE;

	case EWorldTypeBP::EditorPreview:
		return EWorldType::EditorPreview;

	case EWorldTypeBP::GamePreview:
		return EWorldType::GamePreview;

	case EWorldTypeBP::GameRPC:
		return EWorldType::GameRPC;

	case EWorldTypeBP::Inactive:
		return EWorldType::Inactive;
	}

	return EWorldType::None;
}

/** 转换世界类型蓝图，保持 C++、蓝图和 Unreal 原生类型之间的语义一致。 */
static EWorldTypeBP ConvertWorldTypeBP(EWorldType::Type WorldType)
{
	switch (WorldType)
	{
	case EWorldType::None:
		return EWorldTypeBP::None;

	case EWorldType::Game:
		return EWorldTypeBP::Game;

	case EWorldType::Editor:
		return EWorldTypeBP::Editor;

	case EWorldType::PIE:
		return EWorldTypeBP::PIE;

	case EWorldType::EditorPreview:
		return EWorldTypeBP::EditorPreview;

	case EWorldType::GamePreview:
		return EWorldTypeBP::GamePreview;

	case EWorldType::GameRPC:
		return EWorldTypeBP::GameRPC;

	case EWorldType::Inactive:
		return EWorldTypeBP::Inactive;
	}

	return EWorldTypeBP::None;
}
