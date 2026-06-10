// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericWindowHost.h"

class SWindow;
class UGenericWindowWidget;

/** 定义原生窗口主机地址能力契约，供模块在不同实现之间解耦调用。 */
class FGenericNativeWindowHost : public IGenericWindowHostInterface, public TSharedFromThis<FGenericNativeWindowHost>
{
public:
	/** 初始化通用原生窗口主机地址的默认运行状态。 */
	explicit FGenericNativeWindowHost(UGenericWindowWidget* InOwnerWidget);
	virtual ~FGenericNativeWindowHost() override;
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
	/** 把输入解析为父进程窗口，供后续流程使用。 */
	TSharedPtr<SWindow> ResolveParentWindow() const;

	/** 应用运行时状态To原生窗口。 */
	void ApplyRuntimeStateToNativeWindow() const;

	/** 执行句柄Slate窗口Closed流程，并把结果同步给通用 UI相关状态。 */
	void HandleSlateWindowClosed(const TSharedRef<SWindow>& ClosedWindow);

	/** 执行句柄Slate窗口Moved流程，并把结果同步给通用 UI相关状态。 */
	void HandleSlateWindowMoved(const TSharedRef<SWindow>& MovedWindow);

	/** 缓存拥有者控件。 */
	TWeakObjectPtr<UGenericWindowWidget> OwnerWidget;

	/** 缓存原生窗口。 */
	TSharedPtr<SWindow> NativeWindow;

	/** 标记打开。 */
	bool bIsOpen = false;

	/** 标记关闭Requested按拥有者。 */
	bool bCloseRequestedByOwner = false;

	/** 标记ApplyingRuntime状态状态。 */
	mutable bool bApplyingRuntimeState = false;
};
