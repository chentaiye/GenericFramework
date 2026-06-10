// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericWindowHost.h"
#include "Widgets/Layout/SConstraintCanvas.h"

class UGameViewportClient;
class UGenericWindowRuntimeState;
class UGenericWindowWidget;

/** 定义In游戏窗口主机地址能力契约，供模块在不同实现之间解耦调用。 */
class FGenericInGameWindowHost : public IGenericWindowHostInterface
{
public:
	/** 初始化通用In游戏窗口主机地址默认状态。 */
	explicit FGenericInGameWindowHost(UGenericWindowWidget* InOwnerWidget);
	virtual ~FGenericInGameWindowHost() override;
	virtual void Open() override;
	virtual void Close() override;
	virtual void BringToFront(int32 InZOrder) override;
	virtual void InvalidateLayout() override;
	virtual bool IsOpen() const override;
	virtual FVector2D GetViewportSize() const override;
	virtual bool TryConvertScreenToHostLocal(const FVector2D& InScreenSpacePosition, FVector2D& OutHostLocalPosition) const override;
	virtual bool UsesNativeWindow() const override;
	virtual bool ClipsToHostBounds() const override;
	virtual void Minimize() override;
	virtual void Maximize() override;
	virtual void Restore() override;
	virtual void SyncRuntimeState(UGenericWindowRuntimeState& InOutRuntimeState) const override;

private:
	/** 把输入解析为视口Client，供后续流程使用。 */
	UGameViewportClient* ResolveViewportClient() const;

	/** 获取窗口Offset。 */
	FMargin GetWindowOffset() const;

	/** 更新窗口槽位。 */
	void UpdateWindowSlot();

	/** 缓存拥有者控件。 */
	TWeakObjectPtr<UGenericWindowWidget> OwnerWidget;

	/** 记录根Canvas。 */
	TSharedPtr<SConstraintCanvas> RootCanvas;

	/** 记录窗口Slot。 */
	SConstraintCanvas::FSlot* WindowSlot = nullptr;

	/** 标记打开。 */
	bool bIsOpen = false;

	/** 记录当前ZOrder。 */
	int32 CurrentZOrder = 0;
};
