// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class UGenericWindowRuntimeState;

/** 定义窗口主机地址接口契约，供模块在不同实现之间解耦调用。 */
class IGenericWindowHostInterface
{
public:
	virtual ~IGenericWindowHostInterface() = default;

	/** 打开当前类型。 */
	virtual void Open() = 0;

	/** 关闭当前类型。 */
	virtual void Close() = 0;

	/** 置顶目标Front，同步窗口宿主和运行时状态。 */
	virtual void BringToFront(int32 InZOrder) = 0;

	/** 刷新或清理Layout相关的运行时缓存。 */
	virtual void InvalidateLayout() = 0;

	/** 判断打开是否成立。 */
	virtual bool IsOpen() const = 0;

	/** 获取Viewport大小。 */
	virtual FVector2D GetViewportSize() const = 0;

	/** 把 Slate 屏幕坐标转换到当前宿主的窗口布局坐标系。 */
	virtual bool TryConvertScreenToHostLocal(const FVector2D& InScreenSpacePosition, FVector2D& OutHostLocalPosition) const = 0;

	/** 判断使用s原生窗口，让调用方按结果选择后续路径。 */
	virtual bool UsesNativeWindow() const = 0;

	/** 判断Clips目标HostBounds，让调用方按结果选择后续路径。 */
	virtual bool ClipsToHostBounds() const = 0;

	/** 最小化，同步窗口宿主和运行时状态。 */
	virtual void Minimize() = 0;

	/** 最大化，同步窗口宿主和运行时状态。 */
	virtual void Maximize() = 0;

	/** 恢复，同步窗口宿主和运行时状态。 */
	virtual void Restore() = 0;

	/** 同步运行时状态，使运行时状态与输入配置保持一致。 */
	virtual void SyncRuntimeState(UGenericWindowRuntimeState& InOutRuntimeState) const = 0;
};
