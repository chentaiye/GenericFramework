// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "Containers/Ticker.h"
#include "CoreMinimal.h"
#include "AuthorizationType.h"
#include "Manifest/AuthorizationManifest.h"
#include "License/AuthorizationLicenseToken.h"
#include "Provider/AuthorizationServiceFeature.h"
#include "Subsystem/GenericGameInstanceSubsystem.h"
#include "GenericAuthorizationSubsystem.generated.h"

class IAuthorizationServiceFeatureInterface;
class IInputProcessor;
class SNotificationItem;
class SAuthorizationActivationDialog;
class SWindow;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBPAuthorizationScopeStateChanged, FName, ScopeId, EAuthorizationState, State);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBPAuthorizationManifestChanged);

/** 管理游戏实例级授权运行时状态，负责加载许可证与清单、驱动授权提示/到期处理，并向蓝图同步授权变化。 */
UCLASS(MinimalAPI)
class UGenericAuthorizationSubsystem : public UGenericGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static GENERICAUTHORIZATION_API UGenericAuthorizationSubsystem* Get(const UObject* WorldContextObject);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** 在启动守卫或重新授权失败要求退出前进入授权退出流程，取消待执行提示并恢复暂停/UI 状态，避免退出过程中继续弹授权窗口。 */
	void PrepareForAuthorizationExit();

	/** 按配置的在线/离线优先级加载持久化或随包授权，失败时根据启动阶段决定立即弹窗或延迟提示。 */
	UFUNCTION(BlueprintCallable, Category="Authorization")
	bool LoadAuthorizationState();

	/** 将外部粘贴或异步节点传入的许可证文本作为离线来源解析，验证通过后可写入本地缓存并刷新运行时状态。 */
	UFUNCTION(BlueprintCallable, Category="Authorization")
	bool ImportLicenseTokenText(const FString& LicenseTokenText, FString& OutMessage, bool bPersist = true);

	/** 读取指定许可证文件并复用文本导入流程，用于工具或蓝图从本地离线授权文件恢复授权。 */
	UFUNCTION(BlueprintCallable, Category="Authorization")
	bool ImportLicenseTokenFile(const FString& LicenseTokenFilePath, FString& OutMessage, bool bPersist = true);

	/** 解析并校验授权清单文本，成功后更新内容范围映射，使 Pak 挂载检查能按 Scope 判定权限。 */
	UFUNCTION(BlueprintCallable, Category="Authorization")
	bool ImportManifestText(const FString& ManifestText, FString& OutMessage, bool bPersist = true);

	/** 读取指定清单文件并复用清单文本导入流程，供离线授权包同时更新内容范围定义。 */
	UFUNCTION(BlueprintCallable, Category="Authorization")
	bool ImportManifestFile(const FString& ManifestFilePath, FString& OutMessage, bool bPersist = true);

	/** 通过指定或首选 Provider 提交授权码，使用服务响应的许可证/清单替换当前状态并按 Provider 类型持久化。 */
	UFUNCTION(BlueprintCallable, Category="Authorization")
	bool ActivateWithProvider(FName ProviderName, const FString& AuthorizationCode, const FString& UserId, FName RequestedScopeId, FString& OutMessage);

	/** 向支持刷新的 Provider 请求更新当前许可证/清单，并在本地授权仍有效时写入刷新时间和可信时钟。 */
	UFUNCTION(BlueprintCallable, Category="Authorization")
	bool RefreshAuthorization(FName ProviderName, FString& OutMessage);

	/** 清空内存和持久化授权缓存，广播状态变化，并在配置要求时重新进入授权提示流程。 */
	UFUNCTION(BlueprintCallable, Category="Authorization")
	bool ClearAuthorization(FString& OutMessage);

	/** 检查基础 Scope 当前是否可用，作为游戏继续运行、启动守卫放行和重新授权窗口关闭策略的主判定。 */
	UFUNCTION(BlueprintPure, Category="Authorization")
	bool IsBaseAppAuthorized() const;

	/** 返回配置中 BaseScopeId 对应的授权状态，供异步节点回传和生命周期评估统一读取基础授权结果。 */
	UFUNCTION(BlueprintPure, Category="Authorization")
	EAuthorizationState GetBaseAppState() const;

	/** 检查指定 Scope 的 Grant 是否已通过全局校验且未撤销/过期，用于功能开关或内容访问判断。 */
	UFUNCTION(BlueprintPure, Category="Authorization")
	bool IsScopeAuthorized(FName ScopeId) const;

	/** 先验证全局许可证/清单，再返回指定 Scope 的缺失、撤销、过期或可用状态。 */
	UFUNCTION(BlueprintPure, Category="Authorization")
	EAuthorizationState GetScopeState(FName ScopeId) const;

	/** 将过期、未授权或撤销状态归并为需要重新授权，便于 UI 和上层业务选择补授权路径。 */
	UFUNCTION(BlueprintPure, Category="Authorization")
	bool NeedsReauthorization(FName ScopeId) const;

	/** 返回当前设备指纹生成出的设备 ID，授权申请码和令牌校验都以它作为设备绑定依据。 */
	UFUNCTION(BlueprintPure, Category="Authorization")
	FString GetCurrentDeviceId() const { return CurrentDeviceId; }

	/** 根据当前产品、设备和包指纹生成申请码，供阻塞授权窗口复制给签发方。 */
	UFUNCTION(BlueprintPure, Category="Authorization")
	GENERICAUTHORIZATION_API FString GetCurrentAuthorizationRequestCode() const;

	/** 返回最近一次成功应用授权状态的来源，用于刷新和运行时状态持久化选择在线或离线存储槽。 */
	UFUNCTION(BlueprintPure, Category="Authorization")
	EAuthorizationSourceType GetCurrentAuthorizationSource() const { return CurrentAuthorizationSource; }

	/** 根据当前清单中声明的 Pak 路径匹配 Scope，并用该 Scope 授权状态决定是否允许挂载内容包。 */
	UFUNCTION(BlueprintPure, Category="Authorization")
	bool CanMountPakFile(const FString& PakFilePath, FName& OutScopeId, EAuthorizationState& OutState) const;

	/** 暴露当前通过校验的许可证令牌，供模块内部或外部只读检查 Grant 明细。 */
	const FAuthorizationLicenseToken& GetLicenseToken() const { return CurrentLicenseToken; }

	/** 暴露当前清单，供 Pak 挂载保护或调试工具读取 Scope 与内容路径映射。 */
	const FAuthorizationManifest& GetManifest() const { return CurrentManifest; }

	UPROPERTY(BlueprintAssignable, DisplayName = "OnAuthorizationScopeStateChanged")
	FBPAuthorizationScopeStateChanged BPDelegate_OnAuthorizationScopeStateChanged;

	UPROPERTY(BlueprintAssignable, DisplayName="OnAuthorizationManifestChanged", Category="Events")
	FBPAuthorizationManifestChanged BPDelegate_OnAuthorizationManifestChanged;

protected:
	/** 保存初始化或重置时计算出的设备 ID，后续令牌校验、申请码生成和运行时状态持久化都复用该值。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Authorization")
	FString CurrentDeviceId;

	/** 保存当前包指纹，令牌校验和申请码生成用它绑定具体构建包，降低授权跨包复用风险。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Authorization")
	FString CurrentPackageFingerprint;

	/** 持有当前内存中的许可证令牌，Scope 查询、到期提醒和刷新请求都从这里读取 Grant 数据。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Authorization")
	FAuthorizationLicenseToken CurrentLicenseToken;

	/** 持有当前授权清单，Pak 挂载保护通过其中的 Scope 与 PakFiles 关系定位授权范围。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Authorization")
	FAuthorizationManifest CurrentManifest;

	/** 保存可信时钟、设备和包指纹等运行时状态，防回拨校验和刷新时间会随授权来源持久化。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Authorization")
	FAuthorizationRuntimeState RuntimeState;

	/** 说明当前授权来自在线缓存、离线缓存或无来源，决定后续运行时状态保存到哪个存储槽。 */
	UPROPERTY(BlueprintReadOnly, Transient, Category="Authorization")
	EAuthorizationSourceType CurrentAuthorizationSource=EAuthorizationSourceType::None;

	/** 标记延迟授权提示 Ticker 是否已注册，避免 Slate 未就绪期间重复排队阻塞弹窗。 */
	bool bAuthorizationPromptScheduled=false;

	FTSTicker::FDelegateHandle AuthorizationPromptTickerHandle;

	/** 标记授权生命周期监控 Ticker 是否已启动，防止重复注册周期性到期检查。 */
	bool bAuthorizationMonitorScheduled=false;

	FTSTicker::FDelegateHandle AuthorizationMonitorTickerHandle;

	/** 持有当前到期提醒通知，授权状态变化、用户忽略或子系统销毁时用它主动关闭通知。 */
	TSharedPtr<SNotificationItem> ExpirationWarningNotification;

	/** 注册 Y/N 快捷键的输入预处理器，使到期提醒在通知按钮外也能触发续期或忽略。 */
	TSharedPtr<IInputProcessor> ExpirationWarningInputProcessor;

	/** 弱引用运行中重新授权窗口内容，用于窗口关闭时读取用户是否已成功提交授权。 */
	TWeakPtr<SAuthorizationActivationDialog> ReauthorizationDialogContent;

	/** 弱引用运行中重新授权窗口，授权恢复、退出或子系统销毁时通过它主动关闭窗口。 */
	TWeakPtr<SWindow> ReauthorizationWindow;

	/** 保存重新授权窗口可见性，避免到期监控重复创建多个授权窗口。 */
	bool bReauthorizationWindowVisible=false;

	/** 保存重新授权窗口是否在授权仍有效的预警阶段打开，授权恢复后据此自动关闭预警窗口。 */
	bool bReauthorizationWindowOpenedWhileAuthorized=false;

	/** 标记过期后重新授权窗口关闭且未授权时是否请求退出，避免用户绕过已过期的基础授权。 */
	bool bExitIfReauthorizationWindowClosedWithoutAuthorization=false;

	/** 标记授权系统已进入退出路径，提示、通知和暂停逻辑会据此停止继续干预界面。 */
	bool bAuthorizationExitPending=false;

	/** 保存授权过期逻辑是否已经暂停游戏，恢复授权或退出时只解除本系统施加的暂停。 */
	bool bAuthorizationPauseApplied=false;

	/** 保存当前到期通知自动视为忽略的时间点，生命周期 Tick 到时会关闭通知并记住本次提醒。 */
	double ExpirationWarningDismissAtSeconds=0.0;

	/** 保存上一次已提示的基础 Grant 跟踪键，避免同一许可证和到期时间重复弹出预警。 */
	FString LastExpirationWarningGrantKey;

private:
	/** 将授权窗口提交的文本走离线导入路径，供启动提示和运行中重新授权共用同一校验/持久化逻辑。 */
	bool SubmitLicenseCodeFromPrompt(const FString& LicenseTokenText, FString& OutMessage);

	/** 在当前许可证中查找配置的基础 Scope Grant，生命周期评估和预警窗口都以它作为主授权。 */
	const FAuthorizationGrant* GetBaseGrant() const;

	/** 构建基础 Grant 的许可证、Scope、到期时间和类型组合键，用于判断到期提醒是否已经展示过。 */
	FString BuildBaseGrantTrackingKey() const;

	/** 计算基础 Grant 距离过期的秒数，永久授权返回最大值以跳过到期提醒。 */
	int64 GetBaseGrantRemainingSeconds() const;

	/** 周期性评估授权生命周期，处理到期通知自动关闭、过期暂停和重新授权窗口。 */
	bool TickAuthorizationMonitor(float DeltaTime);

	/** 注册授权生命周期监控 Ticker，使加载、导入或刷新后的授权状态能持续触发预警/过期处理。 */
	void ScheduleAuthorizationMonitor();

	/** 移除授权生命周期监控 Ticker，子系统释放时停止后续 UI 和暂停状态更新。 */
	void CancelAuthorizationMonitor();

	/** 根据基础授权状态推进生命周期：有效时处理到期预警，过期时暂停游戏并打开重新授权窗口。 */
	void EvaluateAuthorizationLifecycle();

	/** 把剩余授权秒数转换为通知可读文本，供到期预警说明还有多久需要续期。 */
	FString FormatRemainingLifetime(int64 RemainingSeconds) const;

	/** 显示基础授权即将到期的通知，并注册按钮与 Y/N 快捷键以进入续期或忽略本次提醒。 */
	void ShowExpirationWarningNotification(int64 RemainingSeconds);

	/** 关闭到期提醒通知和快捷键处理器，并在用户忽略时记住当前 Grant，避免同一授权重复提示。 */
	void DismissExpirationWarningNotification(bool bRememberDismissal);

	/** 处理用户接受到期提醒的路径，关闭通知后打开非强制退出的重新授权窗口。 */
	void HandleExpirationWarningAccepted();

	/** 处理用户忽略到期提醒的路径，关闭通知并把本次基础 Grant 作为已忽略处理。 */
	void HandleExpirationWarningDismissed();

	/** 打开运行中重新授权窗口；授权已过期时可要求窗口关闭未授权则退出进程。 */
	void ShowReauthorizationWindow(bool bExitIfClosedWithoutAuthorization);

	/** 请求关闭当前重新授权窗口，并可把关闭后的未授权状态升级为退出请求。 */
	void CloseReauthorizationWindow(bool bRequestExitIfStillUnauthorized);

	/** 在重新授权窗口关闭后清理弱引用，必要时解除暂停或因过期未授权而请求退出。 */
	void HandleReauthorizationWindowClosed(const TSharedRef<SWindow>& ClosedWindow);

	/** 从子系统外层 GameInstance 解析当前世界，供启动阶段判断和过期暂停游戏使用。 */
	UWorld* GetActiveAuthorizationWorld() const;

	/** 仅在真实游戏世界且已开始运行时允许因基础授权过期暂停游戏。 */
	bool CanPauseGameplayForExpiredAuthorization() const;

	/** 按授权过期状态施加或恢复游戏暂停，并只恢复本子系统曾经施加的暂停。 */
	void SetAuthorizationPauseState(bool bShouldPause);

	/** 原子化应用候选许可证、清单和运行时状态；校验或持久化失败时回滚到先前授权状态。 */
	bool ApplyAuthorizationState(const FAuthorizationLicenseToken& InLicenseToken, const FAuthorizationManifest* InManifest, const FAuthorizationRuntimeState& InRuntimeState, EAuthorizationSourceType InSource, FString& OutMessage, bool bPersistToken, bool bPersistManifest, bool bPersistRuntime);

	/** 解码并解析许可证文本，然后把候选令牌交给统一应用流程处理校验、广播和可选持久化。 */
	bool ImportLicenseTokenTextInternal(const FString& LicenseTokenText, FString& OutMessage, bool bPersist, EAuthorizationSourceType InSource);

	/** 从文件读取许可证文本后进入内部文本导入流程，保留授权来源以写回对应缓存。 */
	bool ImportLicenseTokenFileInternal(const FString& LicenseTokenFilePath, FString& OutMessage, bool bPersist, EAuthorizationSourceType InSource);

	/** 解析并验签清单文本，更新当前清单后广播清单变化并按来源可选保存。 */
	bool ImportManifestTextInternal(const FString& ManifestText, FString& OutMessage, bool bPersist, EAuthorizationSourceType InSource);

	/** 从文件读取清单文本后进入内部清单导入流程，用于离线文件同时更新 Pak Scope 映射。 */
	bool ImportManifestFileInternal(const FString& ManifestFilePath, FString& OutMessage, bool bPersist, EAuthorizationSourceType InSource);

	/** 从指定来源缓存加载许可证、运行时状态和清单，并交给统一应用流程恢复授权。 */
	bool TryLoadPersistedAuthorization(EAuthorizationSourceType InSource, FString& OutMessage);

	/** 从随包离线文件加载许可证和清单，成功后可按配置写入离线持久化缓存。 */
	bool TryLoadBundledOfflineAuthorization(FString& OutMessage);

	/** 检查在线或离线授权来源是否被配置启用，Provider 解析和加载优先级会据此跳过不可用来源。 */
	bool IsAuthorizationSourceEnabled(EAuthorizationSourceType InSource) const;

	/** 判断当前基础授权是否缺失且允许自动提示，编辑器 PIE、启动守卫和退出流程会抑制 UI。 */
	bool ShouldPromptForAuthorization() const;

	/** 在 Slate 初始化后执行先前排队的阻塞授权提示，并在条件不再满足时取消排队。 */
	bool TickDeferredAuthorizationPrompt(float DeltaTime);

	/** 当授权缺失但 Slate 尚未就绪时注册一次 Ticker，稍后再显示阻塞授权窗口。 */
	void ScheduleAuthorizationPromptIfNeeded();

	/** 取消延迟授权提示 Ticker，避免状态恢复、退出或子系统释放后仍然弹窗。 */
	void CancelScheduledAuthorizationPrompt();

	/** 显示模态授权窗口并连接申请码生成与许可证提交回调，取消时可按配置请求退出。 */
	void ShowBlockingAuthorizationPrompt();

	/** 在启动地图尚未开始前把阻塞提示交给启动守卫处理，避免子系统和启动守卫重复弹窗。 */
	bool ShouldDeferAuthorizationPromptToStartupGuard() const;

	/** 汇总退出中、启动守卫弹窗中和引擎退出等状态，决定当前是否禁止授权 UI 干预。 */
	bool ShouldSuppressAuthorizationUi() const;

	/** 重新计算设备/包指纹并清空内存授权，必要时预加载项目清单以保留内容 Scope 定义。 */
	void ResetCurrentAuthorizationState(bool bLoadProjectManifest);

	/** 校验当前许可证、可信时钟和清单签名，返回 Scope 查询之前必须满足的全局授权状态。 */
	EAuthorizationState GetGlobalAuthorizationState(FString* OutMessage = nullptr) const;

	/** 按显式名称、配置首选项和在线/离线偏好选择可用 Provider，并过滤未启用的授权来源。 */
	IAuthorizationServiceFeatureInterface* ResolveProvider(FName ProviderName, bool bPreferOnline) const;

	/** 用当前可信时间推进运行时状态，成功导入、刷新或应用授权后用于防本地时间回拨。 */
	void UpdateTrustedClock();

	/** 广播基础 Scope 和许可证内所有 Grant 的状态，供蓝图监听授权变化后更新功能入口。 */
	void BroadcastLicenseStateChanges();

	/** 广播清单已变化，通知蓝图或上层系统重新读取 Pak Scope 与内容访问规则。 */
	void BroadcastManifestChanged();
};
