// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Containers/Ticker.h"
#include "CoreMinimal.h"
#include "AuthorizationType.h"
#include "License/AuthorizationLicenseToken.h"
#include "Manifest/AuthorizationManifest.h"

/** 模块级启动守卫，在引擎初始化和地图加载前验证基础授权，必要时显示阻塞授权窗口或请求退出。 */
class FAuthorizationStartupGuard
{
public:
	/** 注册启动阶段引擎委托，让授权检查能在 PostEngineInit 和 PreLoadMap 两个入口触发。 */
	void Startup();

	/** 注销启动阶段委托并取消等待 Slate 的 Ticker，模块卸载时避免遗留回调。 */
	void Shutdown();

private:
	/** 聚合启动阶段加载出的许可证、清单和运行时状态，验证通过后可一次性写回缓存。 */
	struct FResolvedAuthorizationState
	{
		/** 启动检查时计算出的设备 ID，许可证设备绑定校验和运行时状态保存都使用它。 */
		FString DeviceId;

		/** 启动检查时计算出的包指纹，包绑定校验用它确认授权匹配当前构建。 */
		FString PackageFingerprint;

		/** 从持久化缓存、随包文件或用户提交中解析出的候选许可证令牌。 */
		FAuthorizationLicenseToken LicenseToken;

		/** 与候选许可证配套的清单，可能来自缓存、随包文件或项目默认清单。 */
		FAuthorizationManifest Manifest;

		/** 候选运行时状态，启动校验会更新其中的设备、包指纹和可信时钟。 */
		FAuthorizationRuntimeState RuntimeState;

		/** 候选授权来源，决定校验通过后写回在线还是离线缓存。 */
		EAuthorizationSourceType Source = EAuthorizationSourceType::None;

		/** 说明候选状态是否带有有效清单，持久化时用它决定是否保存清单文件。 */
		bool bHasManifest = false;
	};

	/** 把启动守卫挂到引擎初始化和地图加载委托上，使未授权状态能在首张地图前被拦截。 */
	void RegisterDelegates();

	/** 从引擎委托中移除启动守卫回调，防止模块关闭或退出后继续触发授权检查。 */
	void UnregisterDelegates();

	/** 根据授权设置、命令行/编辑器环境和退出状态判断是否需要执行启动前授权检查。 */
	bool ShouldRunStartupGuard() const;

	/** 响应 PostEngineInit，在 Slate 可能尚未就绪时先尝试加载授权或安排等待。 */
	void HandlePostEngineInit();

	/** 响应 PreLoadMap，确保首张地图加载前基础授权已经通过或进入阻塞授权流程。 */
	void HandlePreLoadMap(const FString& MapName);

	/** 等待 Slate 初始化完成后重新执行启动授权检查，用于需要显示模态授权窗口的早期启动阶段。 */
	bool TickWaitForSlate(float DeltaTime);

	/** 串联启动前授权主流程：先加载可用授权，失败则显示阻塞提示，取消时请求进程退出。 */
	bool EnsureAuthorizedBeforeStartup(const TCHAR* TriggerReason);

	/** 按配置的在线/离线优先级尝试加载授权，并把最后失败原因交给阻塞提示或日志。 */
	bool TryLoadAuthorization(FResolvedAuthorizationState& OutState, FString& OutMessage) const;

	/** 从指定来源的持久化缓存加载许可证、运行时状态和清单，并验证是否可在启动前放行。 */
	bool TryLoadPersistedAuthorization(EAuthorizationSourceType Source, const FAuthorizationManifest* ProjectManifest, FResolvedAuthorizationState& OutState, FString& OutMessage) const;

	/** 从随包离线文件加载许可证和清单，验证通过后可按设置持久化到离线缓存。 */
	bool TryLoadBundledOfflineAuthorization(const FAuthorizationManifest* ProjectManifest, FResolvedAuthorizationState& OutState, FString& OutMessage) const;

	/** 加载项目默认清单，作为授权缓存或随包文件缺少清单时的 Scope 定义来源。 */
	bool LoadProjectManifest(FAuthorizationManifest& OutManifest) const;

	/** 校验候选许可证、清单、基础 Grant 和可信时钟，成功后更新候选运行时可信时间。 */
	bool ValidateResolvedAuthorization(FResolvedAuthorizationState& InOutState, FString& OutMessage) const;

	/** 将启动阶段验证通过的许可证、可选清单和运行时状态写回对应来源缓存。 */
	bool PersistResolvedAuthorization(const FResolvedAuthorizationState& State, bool bPersistManifest) const;

	/** 显示启动前模态授权窗口，用户提交成功则继续启动，取消则由调用方请求退出。 */
	bool ShowBlockingAuthorizationPrompt();

	/** 基于当前产品、设备和包指纹生成申请码，启动提示中展示给用户复制给签发方。 */
	FString BuildAuthorizationRequestCode() const;

	/** 解码启动提示提交的许可证文本，验证基础授权并写入离线缓存。 */
	bool SubmitLicenseCode(const FString& LicenseCode, FString& OutMessage);

	/** 在 Slate 尚未初始化时注册等待 Ticker，稍后再显示阻塞授权窗口。 */
	void ScheduleSlateWait();

	/** 取消等待 Slate 的 Ticker，授权通过、退出或模块关闭时停止后续检查。 */
	void CancelSlateWait();

	/** 收敛启动前授权失败的退出路径：标记全局退出、通知现有子系统并请求平台退出。 */
	void RequestProcessExit(const TCHAR* Reason);

	FDelegateHandle PostEngineInitHandle;

	FDelegateHandle PreLoadMapHandle;

	FTSTicker::FDelegateHandle SlateWaitTickerHandle;

	/** 标记等待 Slate 的 Ticker 是否已注册，避免早期启动阶段重复注册等待回调。 */
	bool bSlateWaitScheduled = false;

	/** 保存启动前授权检查是否已完成，避免 PostEngineInit 和 PreLoadMap 重复进入阻塞授权路径。 */
	bool bStartupCheckCompleted = false;

	/** 标记启动授权提示是否正在显示，避免同一启动阶段嵌套打开多个模态窗口。 */
	bool bPromptVisible = false;

	/** 标记启动守卫已经请求退出，后续委托和运行中子系统会停止继续授权提示。 */
	bool bExitRequested = false;
};
