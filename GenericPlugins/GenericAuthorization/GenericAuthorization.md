# GenericAuthorization 混合式授权方案与实现路径

## 1. 目标概述

当前希望在程序包及其后续扩展内容上增加一套可控授权机制，核心目标包括：

1. 程序包首次打开时必须经过授权后才能使用。
2. 授权时限可控，支持例如 `1 小时`、`1 周` 等时效型授权，过期后必须再次授权。
3. 支持永久授权。
4. 支持热更新 `pak`，同一授权范围内的更新不应要求每次重新授权。
5. 支持按内容范围授权，例如新增 `DLC` 后，新的 `DLC` 必须单独授权后才能使用。

这 5 点背后真正需要的不是“给某个 pak 文件做一次性校验”，而是建立一套稳定的“授权范围”体系：

- 程序基础包是否被授权。
- 某个 DLC 是否被授权。
- 某个功能模块是否被授权。
- 同一授权范围内更新版本时，不改变授权关系。

因此，推荐将授权对象从“文件”提升为“内容范围（Scope）”。

---

## 2. 需求扩展与澄清

基于现有需求，建议将完整需求扩展为以下几类。

### 2.1 功能性需求

- 首次启动拦截
  - 程序首次进入可用态前，必须完成授权校验。
  - 未授权时只能进入授权页、激活页或受限页，不能进入主业务流程。

- 时效授权
  - 支持按分钟、小时、天、周、月定义有效期。
  - 到期后进入“重新授权”状态。
  - 可配置到期后的处理策略：
    - 启动时阻止进入应用。
    - 运行中弹出提示并阻止继续访问受保护内容。
    - 允许短暂宽限期。

- 永久授权
  - 支持无到期时间的授权。
  - 永久授权仍应支持撤销、禁用、黑名单等后台控制能力。

- 分范围授权
  - 基础程序包单独授权。
  - DLC 单独授权。
  - 后续如有必要，可扩展到：
    - 指定功能模块授权。
    - 指定场景/地图授权。
    - 指定客户项目授权。

- 热更新兼容
  - 同一授权范围下的内容更新不要求重新授权。
  - 更新的是“版本”，不是“授权身份”。
  - 例如：
    - `BaseApp v1` 升级到 `BaseApp v2`，如果仍属于 `BaseApp` 授权范围，则不重新授权。
    - `DLC_CityPack v1` 升级到 `DLC_CityPack v2`，如果仍属于同一 `DLC_CityPack` 授权范围，则不重新授权。

- 新增内容强制授权
  - 新增 DLC 必须具有新的授权范围标识。
  - 未获得该范围授权时，不允许挂载、加载或进入该 DLC 内容。

### 2.2 非功能性需求

- 安全性
  - 本地缓存不能被简单篡改后直接绕过授权。
  - 授权结果应具备签名校验能力。
  - 应能抵抗基础级别的复制安装包、复制授权文件、改系统时间等手段。

- 可运营性
  - 可以生成、发放、续期、撤销授权。
  - 可以查询某个客户、设备、授权码的使用状态。
  - 可以区分测试授权、正式授权、临时演示授权。

- 可扩展性
  - 后续新增 DLC、新模块、新平台时不需要推翻现有授权体系。
  - 授权单位应稳定且可长期演进。

- 可离线性
  - 需要明确是否支持离线使用。
  - 如果支持离线，首次授权后应能在授权期内离线运行。
  - 如果完全依赖在线，则需要接受联网依赖和服务可用性风险。

### 2.3 边界场景需求

- 重装程序后是否仍视为同一设备。
- 更换硬件后是否允许沿用旧授权。
- 多台设备能否共用同一授权码。
- 到期时如果正在运行，是否立即失效。
- 本地系统时间被回拨时如何处理。
- 授权服务器不可用时是否启用宽限期。
- 已授权的 DLC 被撤销后，是否需要下次启动立即失效。

---

## 3. 核心设计原则

### 3.1 授权单位不要绑定到 Pak 文件名

如果授权直接绑定到某个具体 `pak` 文件，会产生两个问题：

1. 每次热更新都会变成一个“新文件”，从而误触发重新授权。
2. 无法稳定表达“这是同一个 DLC 的新版本”。

因此应使用如下抽象：

- `ProductId`
  - 产品标识，例如某个程序主包。

- `ScopeId`
  - 授权范围标识，是最关键的授权单位。
  - 示例：
    - `base_app`
    - `dlc_citypack`
    - `feature_advanced_report`

- `Version`
  - 内容版本号，用于热更新。

- `PakList / ContentList`
  - 当前版本对应的实际内容文件清单。

结论：

- 授权绑定的是 `ScopeId`。
- 更新变化的是 `Version` 和 `PakList`。
- 只要 `ScopeId` 不变，同一范围内的热更新就不需要重新授权。

### 3.2 授权对象应分层

推荐至少拆成两层：

1. 基础程序授权
   - 控制程序能否正常进入主流程。

2. 增量内容授权
   - 控制 DLC、扩展功能、额外资源包能否被挂载和使用。

这样可以自然满足：

- 基础包首次使用必须授权。
- 新 DLC 上线后可独立收费、独立授权。
- 热更新只更新内容，不破坏历史授权。

### 3.3 客户端只负责校验，不负责“信任自己”

如果客户端自己完全决定“我是不是已授权”，安全性会很差。更合理的方式是：

- 服务端或授权生成工具负责签发授权凭证。
- 客户端只负责校验凭证真伪、时效、设备绑定和内容范围。

---

## 4. 可选实现路径

下面给出几条主实现路径，并分析各自适用场景。

## 4.1 路径 A：纯本地离线授权码

### 方案说明

- 首次启动时输入授权码。
- 客户端本地验证授权码是否合法。
- 验证通过后写入本地授权文件。
- 后续启动时读取本地授权文件判断是否已授权。

### 典型实现方式

- 预生成一批授权码。
- 授权码中携带：
  - 产品标识
  - 授权范围
  - 过期时间
  - 是否永久
  - 签名
- 客户端内置公钥，用于验签。

### 优点

- 不依赖在线服务。
- 部署简单。
- 对纯内网、离线交付项目友好。

### 缺点

- 无法方便地做授权回收和动态控制。
- 难以精确掌控一份授权码被多少台设备使用。
- 如果没有设备绑定，授权码容易传播。
- 如果设备绑定做得太强，换设备会带来售后成本。

### 适用场景

- 内网环境。
- 一机一授权的离线交付项目。
- 对“撤销授权”要求不高。

### 对当前需求的匹配度

- 首次授权：支持。
- 时限授权：支持。
- 永久授权：支持。
- 热更新 pak 不重复授权：支持，但前提是授权绑定 `ScopeId` 而不是 pak 文件。
- 新 DLC 单独授权：支持，但需要为每个 DLC 设计独立 `ScopeId`。

## 4.2 路径 B：纯在线授权服务

### 方案说明

- 每次启动时都访问授权服务器。
- 由服务器返回当前设备、当前用户、当前内容范围是否有权限。
- 客户端根据返回结果决定是否放行。

### 优点

- 运营能力最强。
- 可实时撤销授权。
- 可记录设备数、并发数、地区、版本等信息。
- 安全性相对更高。

### 缺点

- 强依赖网络和服务器可用性。
- 首次接入和运维成本更高。
- 对离线交付和弱网环境不友好。

### 适用场景

- SaaS 型产品。
- 长期联网运行的客户端。
- 对授权回收、设备管控要求高的项目。

### 对当前需求的匹配度

- 功能上都能满足。
- 但“热更新 pak 不重复授权”的体验依赖服务稳定性。
- 如果用户环境离线或弱网，体验较差。

## 4.3 路径 C：混合式授权，首次在线激活，后续本地验签缓存

### 方案说明

这是最推荐的路径。

- 首次启动时进行在线授权或由线下工具生成授权文件导入。
- 授权成功后，客户端保存一份带签名的本地授权凭证。
- 后续启动先校验本地凭证。
- 凭证未过期时可直接放行。
- 凭证过期后再触发续期或重新授权。
- 新 DLC 按新的 `ScopeId` 增量签发或下发。

### 优点

- 能兼顾安全性、可运营性、离线可用性。
- 首次授权强控制，后续使用体验好。
- 临时授权和永久授权都容易表达。
- 适合基础包授权 + DLC 授权 + 热更新共存。

### 缺点

- 体系设计比纯本地方案复杂。
- 需要定义本地凭证格式、签名方案、设备绑定策略。
- 如果接入服务端，还需要实现最基础的授权接口。

### 适用场景

- 需要首次激活控制。
- 需要临时授权和永久授权共存。
- 需要 DLC 和热更新并存。
- 可能存在离线运行需求。

### 对当前需求的匹配度

- 与当前需求最匹配。

## 4.4 路径 D：平台账号 / 商店权益驱动

### 方案说明

- 如果程序最终运行于某些带账号体系的平台，可直接基于平台购买权益控制内容使用。
- 客户端通过平台接口查询主包或 DLC 是否已购。

### 优点

- 平台已解决支付、账户、权益同步问题。
- 对 DLC 购买和分发天然友好。

### 缺点

- 强依赖目标平台。
- 对私有交付、离线部署、企业项目不适用。
- 对自定义授权时长支持有限。

### 适用场景

- 最终发布到具备标准商店生态的平台。

### 对当前需求的匹配度

- 可作为补充路径，不建议作为当前 GenericAuthorization 的通用基础设计。

---

## 5. 推荐路线

经过对比，`GenericAuthorization` 的正式实施路线收敛为：

`路径 C：混合式授权`

这里的“混合”不是把多套授权模型并列实现，而是指：

- 首次激活优先走在线激活，或通过线下签发文件导入完成首激活。
- 日常运行优先走本地签名凭证校验，不把每次启动都绑定到网络可用性。
- 凭证过期、授权增量、撤销同步、服务端时间校准时，再回到在线链路。
- 在线与离线两条链路最终都收敛成同一份 `LicenseToken + ContentManifest` 模型。

并将系统设计为：

1. 基础程序按 `base_app` 范围授权。
2. 每个 DLC 按独立 `ScopeId` 授权。
3. 热更新 pak 只更新 `Version` 与内容清单，不改变 `ScopeId`。
4. 客户端保存签名授权凭证，本地校验时效与范围。
5. 需要时再通过服务端或离线签发工具完成续期与新增授权。

这个方案同时满足：

- 首次启动拦截。
- 时限授权。
- 永久授权。
- 热更新不重复授权。
- DLC 独立授权。

额外限定：

- 路径 A 和路径 B 只作为部署形态或降级方案，不再作为主代码结构依据。
- 路径 D 仅保留为未来对接平台权益时的扩展入口，不作为当前 GenericAuthorization 的默认实现。

---

## 6. 推荐系统架构

建议将 GenericAuthorization 拆成以下几个子系统。

## 6.1 授权子系统 `UGenericAuthorizationSubsystem`

职责：

- 作为运行时统一入口，替代裸 `AuthorizationManager` 单例。
- 在 `GameInstance` 生命周期内加载本地授权信息。
- 判断基础程序是否已授权。
- 判断某个 `ScopeId` 是否已授权。
- 对外提供统一查询、激活、刷新和授权事件广播接口。

建议声明示意：

```cpp
UCLASS(MinimalAPI)
class UGenericAuthorizationSubsystem : public UGenericGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    static GENERICAUTHORIZATION_API UGenericAuthorizationSubsystem* Get(const UObject* WorldContextObject);

    bool IsBaseAppAuthorized() const;
    bool IsScopeAuthorized(FName ScopeId) const;
    EAuthorizationState GetScopeState(FName ScopeId) const;
    bool NeedsReauthorization(FName ScopeId) const;
};
```

## 6.2 授权凭证模型 `LicenseToken`

职责：

- 描述某个设备或某个用户当前拥有哪些授权。
- 表达临时授权、永久授权和授权范围。
- 由服务端或签发工具生成，客户端只做验签和读取。

建议字段：

```json
{
  "license_id": "LIC-20260403-0001",
  "product_id": "dev_project",
  "device_id": "DEVICE-ABC",
  "grants": [
    {
      "scope_id": "base_app",
      "grant_type": "timed",
      "issued_at": "2026-04-03T12:00:00Z",
      "expire_at": "2026-04-10T12:00:00Z"
    },
    {
      "scope_id": "dlc_citypack",
      "grant_type": "permanent",
      "issued_at": "2026-04-03T12:00:00Z",
      "expire_at": null
    }
  ],
  "signature": "..."
}
```

重点说明：

- `scope_id` 才是授权单位。
- `expire_at = null` 可表示永久授权。
- 一个凭证里可以同时携带多个范围授权。

## 6.3 本地缓存与安全存储 `LicenseStore`

职责：

- 保存授权凭证。
- 保存上次成功校验时间。
- 保存设备标识。
- 防止本地文件被直接替换或伪造。

建议：

- 本地文件至少做签名校验。
- 最好增加设备绑定。
- 最好记录“最近可信时间”，用于对抗回拨系统时间。

## 6.4 内容清单 `ContentManifest`

职责：

- 维护 `ScopeId` 与实际内容包之间的映射关系。
- 支持热更新和 DLC 的内容声明。

建议字段：

```json
{
  "product_id": "dev_project",
  "scopes": [
    {
      "scope_id": "base_app",
      "version": "1.0.3",
      "pak_files": [
        "Paks/base_1003.pak"
      ]
    },
    {
      "scope_id": "dlc_citypack",
      "version": "2.1.0",
      "pak_files": [
        "Paks/dlc_citypack_210.pak"
      ]
    }
  ],
  "signature": "..."
}
```

重点说明：

- 更新 `base_1002.pak` 到 `base_1003.pak` 不影响 `base_app` 授权。
- 新增 `dlc_citypack` 时，由于它是新的 `ScopeId`，必须单独授权。

## 6.5 内容挂载控制器 `ContentMountGuard`

职责：

- 在挂载 `pak` 或激活 DLC 前，根据 `ScopeId` 做授权检查。
- 未授权则不挂载对应内容。
- 已授权则允许挂载。

这是满足“新 DLC 需要授权才能被使用”的关键模块。

如果只做“启动时校验一次”，而不做内容级挂载控制，那么新增 DLC 仍可能被程序直接加载。

## 6.6 授权交互界面 `AuthorizationUI`

职责：

- 首次启动时引导输入授权码、登录账号或导入授权文件。
- 到期时展示重新授权入口。
- DLC 未授权时展示购买/激活/导入授权入口。

## 6.7 参考 GenericPlugins 的插件组织风格

当前目录里的 `GenericAuthorizationCore` 更像一个最小骨架。若按 `GenericCamera`、`CommunicationFramework`、`GenericWebBrowser` 等插件的现有风格收敛，建议最终插件组织形态为：

```text
GenericAuthorization/
  Config/
  Resources/
  Source/
    Runtime/
      GenericAuthorizationCore/
      GenericAuthorization/
    UncookedOnly/
      GenericAuthorizationNode/          (optional)
  GenericAuthorization.uplugin
```

说明：

- 根插件名建议统一为 `GenericAuthorization`。
- `GenericAuthorizationCore` 只承载凭证、清单、验签、存储、Provider 接口等纯运行时核心能力。
- `GenericAuthorization` 承载 `Subsystem`、`BPFunctions`、`AsyncAction`、UI 和挂载拦截。
- 只有在需要自定义 K2 节点、导入器或编辑器工具时，才增加 `GenericAuthorizationNode`。
- 如果第一阶段暂时不拆双 Runtime 模块，也建议至少先对齐成 `Source/Runtime/GenericAuthorizationCore` 的目录形式，而不是长期停留在当前占位结构。

## 6.8 推荐目录结构

建议目录命名直接参考现有 GenericPlugins 的 `Public / Private + 分类子目录` 风格：

```text
Source/Runtime/GenericAuthorizationCore/Public
  AuthorizationType.h
  License/AuthorizationLicenseToken.h
  License/AuthorizationGrant.h
  Manifest/AuthorizationManifest.h
  Provider/AuthorizationServiceFeature.h
  Provider/Online/OnlineAuthorizationServiceFeature.h
  Provider/Offline/OfflineAuthorizationServiceFeature.h
  Storage/AuthorizationLicenseStore.h
  Verify/AuthorizationVerifier.h
  Verify/AuthorizationClockGuard.h

Source/Runtime/GenericAuthorization/Public
  Subsystem/GenericAuthorizationSubsystem.h
  BPFunctions/BPFunctions_Authorization.h
  AsyncAction/ActivateAuthorizationAsyncAction.h
  AsyncAction/RefreshAuthorizationAsyncAction.h
  AsyncAction/ImportLicenseFileAsyncAction.h
  Settings/GenericAuthorizationSettings.h
  Mount/AuthorizationPakMountGuard.h
  UI/GenericAuthorizationWidget.h

Source/Runtime/GenericAuthorization/Private
  AsyncAction/
  BPFunctions/
  Mount/
  Settings/
  Subsystem/
  Tests/
  UI/
```

其中：

- `AuthorizationType.h` 对齐 `CameraType.h`、`JsonType.h` 的职责，集中放日志类别、枚举和轻量 `USTRUCT`。
- `BPFunctions_Authorization` 对齐 `BPFunctions_HTTP` 的风格，只暴露轻量查询和便捷入口。
- `ActivateAuthorizationAsyncAction`、`RefreshAuthorizationAsyncAction` 对齐现有 `AsyncAction` 组织方式。
- `Private/Tests` 可参考 `GenericProtocol` 的 `Tests` 目录放冒烟测试。

## 6.9 推荐类命名与职责映射

为了和仓库中现有插件保持一致，建议采用如下命名：

- `UGenericAuthorizationSubsystem`
  - 统一运行时入口。
  - 负责启动期校验、Scope 查询、授权状态广播。

- `UBPFunctions_Authorization`
  - 负责 Blueprint 纯函数和轻量工具函数。
  - 不承担完整激活流程。

- `UActivateAuthorizationAsyncAction`
  - 负责首次激活。

- `URefreshAuthorizationAsyncAction`
  - 负责续期、撤销同步、服务端时间校准。

- `UImportLicenseFileAsyncAction`
  - 负责离线导入授权文件。

- `UGenericAuthorizationSettings`
  - 负责项目级配置，例如激活地址、公钥、默认 `ScopeId`、宽限期、缓存路径。

- `FAuthorizationLicenseToken`
  - 负责表达签名授权凭证。

- `FAuthorizationManifest`
  - 负责表达内容范围与 pak 清单的映射。

- `FAuthorizationLicenseStore`
  - 负责本地持久化与缓存读取。

- `FAuthorizationPakMountGuard`
  - 负责 pak / DLC 挂载前授权检查。

不建议：

- 长期保留一个与 UE 生命周期脱钩的裸 `AuthorizationManager` 全局单例。
- 把 HTTP 请求、UI 交互、Scope 校验、pak 挂载全部塞进同一个类。

## 6.10 混合式授权的 Online / Offline 拆法

参考 `GenericVoiceWakeupSystem` 中 `Online / Offline` 的拆法，推荐授权链路也拆成服务特性接口：

- `IAuthorizationServiceFeature`
  - 定义统一授权接口，例如 `Activate`、`Refresh`、`ImportLicense`、`QueryServerTime`。

- `IOnlineAuthorizationServiceFeature`
  - 负责在线激活、续期、撤销同步、服务端校时。

- `IOfflineAuthorizationServiceFeature`
  - 负责线下签发文件导入、本地离线包读取。

- `UGenericAuthorizationSubsystem`
  - 只依赖接口，不直接写死 HTTP 细节。
  - 在线与离线 provider 最终都落到同一套 `LicenseToken` 验签和 `ScopeId` 判断逻辑。

这样的拆法有几个好处：

- 与“混合式授权”的目标天然一致。
- 后续切换服务端地址、激活方式或离线包格式时，不会把 `Subsystem` 和 UI 一起打乱。
- 更接近 GenericPlugins 里现有的模块化风格，而不是单文件堆叠式实现。

## 6.11 推荐模块依赖

如果按双 Runtime 模块落地，建议依赖关系参考如下：

- `GenericAuthorizationCore`
  - Public：`Core`、`GenericCoreFramework`、`GenericJson`
  - Private：`CoreUObject`、`Engine`、`Json`、`JsonUtilities`、`DeveloperSettings`、`Projects`

- `GenericAuthorization`
  - Public：`Core`、`CoreUObject`、`Engine`、`UMG`、`GenericAuthorizationCore`
  - Private：`Slate`、`SlateCore`、`GenericProtocol`

- `GenericAuthorizationNode`（可选）
  - Private：`Core`、`CoreUObject`、`Engine`、`BlueprintGraph`、`KismetCompiler`、`UnrealEd`、`GenericAuthorization`

这里优先复用现有 GenericPlugins 能力：

- JSON 序列化优先复用 `GenericJson`。
- 在线激活与刷新链路优先复用 `GenericProtocol`。
- 子系统生命周期优先复用 `GenericCoreFramework` 中的 `UGenericGameInstanceSubsystem`。

## 6.12 日志、测试与 Blueprint 暴露建议

- 日志统一在 `AuthorizationType.h` 中声明：

```cpp
GENERICAUTHORIZATIONCORE_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogAuthorization, Log, All);
```

- `Private/Tests` 至少覆盖以下冒烟场景：
  - `LicenseToken` 反序列化与验签。
  - 临时授权与永久授权判定。
  - 系统时间回拨检测。
  - `ScopeId -> PakList` 映射检查。
  - 未授权 DLC 挂载拦截。

- Blueprint 层只建议暴露：
  - 授权状态查询。
  - 首次激活。
  - 刷新授权。
  - 导入授权文件。

- 不建议把底层凭证改写、签名拼接、pak 映射维护直接暴露到 Blueprint。

---

## 7. 如何满足你的 5 个核心需求

## 7.1 需求 1：程序包首次打开时需要授权

### 实现方式

- 启动时优先检查 `base_app` 是否有有效授权。
- 没有有效授权时：
  - 不进入主业务流程。
  - 只展示授权界面。

### 落地建议

- 在应用最早期启动流程中执行校验。
- 只有 `base_app` 授权通过后才继续初始化核心业务。

## 7.2 需求 2：授权时限可控，超过时限必须再次授权

### 实现方式

- 每个授权范围带有独立的 `expire_at`。
- 启动时检查是否过期。
- 使用中可按策略进行二次校验。

### 可选策略

- 严格模式
  - 一旦过期，立即阻止继续访问受保护内容。

- 温和模式
  - 启动时阻止进入。
  - 运行中只在切换场景、重新进入模块、重新挂载内容时阻止。

### 推荐

- 基础程序使用“启动拦截”。
- DLC 或功能模块使用“访问前检查”。

这样既满足要求，也能减少运行中强退带来的体验问题。

## 7.3 需求 3：支持永久授权

### 实现方式

- 授权凭证中 `grant_type = permanent`。
- 或 `expire_at = null`。

### 注意事项

- 永久授权不等于不可撤销。
- 建议后台保留黑名单或撤销机制。

## 7.4 需求 4：热更新 pak 不希望每次重新授权

### 实现方式

关键在于：

- 不按 `pak` 文件授权。
- 按 `ScopeId` 授权。

例如：

- `base_app`
  - `v1.0.0 -> base_1000.pak`
  - `v1.0.1 -> base_1001.pak`
  - `v1.0.2 -> base_1002.pak`

只要这几个版本都属于 `base_app` 范围，那么：

- 首次授权后，后续更新到 `v1.0.1`、`v1.0.2` 不需要重新授权。

### 必须避免的错误设计

- 以 pak 文件名作为授权主键。
- 每次更新都生成新的、不可兼容的授权标识。

## 7.5 需求 5：新 DLC 需要被单独授权

### 实现方式

- 每个 DLC 使用独立 `ScopeId`。
- 客户端加载 DLC 前检查该 `ScopeId` 是否已授权。
- 未授权则不挂载该 DLC 的 pak。

例如：

- 主包：`base_app`
- 城市场景 DLC：`dlc_citypack`
- 高级报表 DLC：`dlc_advanced_report`

当新增 `dlc_citypack` 时：

- 即使用户已获得 `base_app` 永久授权，
- 也不能自动使用 `dlc_citypack`，
- 除非凭证中存在 `dlc_citypack` 的有效授权。

---

## 8. 建议的数据模型

## 8.1 授权范围定义

```cpp
enum class EAuthorizationScopeType : uint8
{
    BaseApp,
    DLC,
    Feature
};
```

```cpp
struct FAuthorizationScope
{
    FName ScopeId;
    EAuthorizationScopeType ScopeType;
    FString DisplayName;
    FString Version;
};
```

## 8.2 授权状态定义

```cpp
enum class EAuthorizationState : uint8
{
    Unauthorized,
    Authorized,
    Expired,
    Revoked,
    InvalidSignature,
    DeviceMismatch
};
```

## 8.3 授权 grant 定义

```cpp
struct FAuthorizationGrant
{
    FName ScopeId;
    bool bPermanent = false;
    FDateTime IssuedAt;
    TOptional<FDateTime> ExpireAt;
};
```

---

## 9. UE 内部落地建议

因为当前插件还是骨架状态，建议后续实现按 UE 的职责分层来推进。

## 9.1 启动期校验

可在以下阶段接入：

- 模块启动后尽早初始化 `UGenericAuthorizationSubsystem`。
- GameInstance 初始化前后进行基础包授权校验。
- 进入主地图、主菜单、核心系统前设置拦截。

目标是：

- 未通过 `base_app` 授权时，不进入正式可用态。

## 9.2 Pak / DLC 挂载前校验

如果项目采用热更新 pak 或 DLC 挂载机制，必须在挂载前做检查：

1. 读取内容清单，拿到该 pak 对应的 `ScopeId`。
2. 调用 `UGenericAuthorizationSubsystem` 判断该 `ScopeId` 是否有效。
3. 有效则允许挂载。
4. 无效则拒绝挂载并提示。

这一步是后续实现的重点。

## 9.3 授权结果缓存

建议本地缓存：

- 当前设备标识。
- 已签发的授权凭证。
- 最近一次成功校验时间。
- 最近一次服务端确认时间。

## 9.4 设备标识

建议设备标识不要过于脆弱，也不要过于激进。

可考虑组合：

- 系统安装标识。
- 主板 / CPU / 网卡等硬件信息摘要。
- 项目自定义设备指纹。

建议输出为哈希值，而不是明文保存硬件信息。

---

## 10. 关键安全问题

授权系统无法做到“绝对防破解”，但可以提高绕过成本。建议至少覆盖以下问题。

## 10.1 本地文件篡改

问题：

- 用户直接改本地授权文件，把到期时间改长。

建议：

- 授权凭证必须带签名。
- 客户端只信任签名验证通过的内容。

## 10.2 系统时间回拨

问题：

- 用户把系统时间调回过去，绕过时效限制。

建议：

- 记录最近可信时间。
- 不允许当前时间小于最近可信时间太多。
- 如果可联网，周期性使用服务端时间校准。

## 10.3 复制授权文件到其他设备

问题：

- 用户把一个设备上的授权文件拷贝到另一台设备。

建议：

- 凭证中绑定设备指纹。
- 校验当前设备与签发设备是否一致。

## 10.4 直接替换未授权 DLC Pak

问题：

- 用户手工放入一个 DLC pak，尝试让程序直接识别。

建议：

- 内容清单也需要签名。
- 挂载前必须通过 `ScopeId -> LicenseGrant` 校验。
- 未授权内容不挂载、不注册、不暴露入口。

## 10.5 代码层绕过

问题：

- 高强度攻击者可能会 patch 可执行文件或 hook 关键校验逻辑。

建议：

- 核心校验逻辑做分散化。
- 关键结果不只在一个地方判断。
- 对高价值项目，可考虑再叠加：
  - 混淆
  - 完整性校验
  - 在线复核

---

## 11. 运营与管理后台建议

如果后续需要可持续发放授权，建议配套一个最小后台或签发工具，至少支持：

- 创建授权
  - 指定客户
  - 指定设备
  - 指定 `ScopeId`
  - 指定有效期
  - 指定是否永久

- 续期授权
  - 延长某个 `ScopeId` 的过期时间

- 增量授权
  - 在原基础包授权之外新增 `DLC` 权限

- 撤销授权
  - 拉黑某个授权
  - 拉黑某个设备

- 导出凭证
  - 生成本地导入文件
  - 或生成激活码

---

## 12. 推荐实施阶段

为了降低一次性实现复杂度，建议分阶段推进。

## 12.1 第一阶段：最小可用版

目标：

- 实现基础程序首次授权。
- 支持时效授权和永久授权。
- 支持本地缓存。
- 先完成与 GenericPlugins 对齐的基础骨架：`AuthorizationType`、`UGenericAuthorizationSubsystem`、`UGenericAuthorizationSettings`、`FAuthorizationLicenseStore`。

范围：

- 只处理 `base_app`。
- 不做 DLC。
- 不做复杂后台，先做离线签发或简单在线接口。

## 12.2 第二阶段：范围化授权

目标：

- 引入 `ScopeId` 模型。
- 同时支持 `base_app` 和多个 DLC。
- 完成 `Online / Offline AuthorizationServiceFeature` 拆分。

范围：

- 增加内容清单。
- 增加挂载前校验。
- 增加 DLC 未授权提示逻辑。
- 增加 `AsyncAction` 与 Blueprint 入口。

## 12.3 第三阶段：热更新与运维完善

目标：

- 热更新 pak 与授权范围彻底解耦。
- 增加续期、撤销、设备迁移、黑名单。
- 完成 `GenericProtocol` 在线刷新链路和测试体系。

范围：

- 服务端接口或签发工具完善。
- 加强时间篡改检测和设备绑定策略。

---

## 13. 推荐验收标准

1. 未授权设备首次启动时，不能进入主流程，只能进入授权页。
2. 对 `1 小时`、`1 周`、`永久` 三类授权可正确识别。
3. 授权到期后，基础程序必须重新授权后才能继续使用。
4. 同一 `ScopeId` 下热更新 pak 后，不需要重新授权。
5. 新 DLC 使用新的 `ScopeId` 后，未授权时不能被挂载和使用。
6. 本地修改授权到期时间不能直接生效，签名校验必须失败。
7. 拷贝授权文件到另一设备时，若设备不匹配则授权无效。

---

## 14. 最终结论

针对当前需求，最合理的设计不是“给每个安装包或每个 pak 单独做一次授权”，而是：

- 以 `ScopeId` 作为稳定授权单位。
- 以签名 `LicenseToken` 作为授权凭证。
- 以 `ContentManifest` 维护内容与授权范围的映射。
- 以 `UGenericAuthorizationSubsystem` 作为统一运行时入口。
- 以 `IAuthorizationServiceFeature / IOnlineAuthorizationServiceFeature / IOfflineAuthorizationServiceFeature` 组织混合式授权链路。
- 以启动拦截控制基础包。
- 以挂载前校验控制 DLC 和增量内容。

推荐方案为：

- 首次授权时获取或导入授权凭证。
- 基础包使用 `base_app` 授权范围。
- 每个 DLC 使用独立 `ScopeId`。
- 热更新只更新版本和 pak 文件，不改变 `ScopeId`。
- 临时授权通过 `expire_at` 控制，永久授权通过 `expire_at = null` 或 `bPermanent` 表达。
- 代码组织对齐 GenericPlugins 现有风格，采用 `Source/Runtime/<Module>/Public|Private`、`Subsystem`、`BPFunctions`、`AsyncAction`、`Type`、`Settings` 等固定分层。

这套方案最能稳定满足你当前提出的 5 个目标，并且能为后续的 DLC 扩展、授权后台、离线交付和热更新演进留下足够空间。

---

## 15. 当前已落地的首开授权流程

当前实现已经按“首次启动阻塞式授权”的方式落地：

- 程序启动时，`UGenericAuthorizationSubsystem` 会优先检查在线缓存授权。
- 如果没有有效在线授权，则继续检查离线缓存和包体旁 `Authorization` 目录中的离线授权文件。
- 如果仍然没有有效授权，并且 `bAutoPromptForAuthorization=True`，则会弹出阻塞式授权窗口。
- 窗口中会显示当前机器的 `Machine Key`。
- 用户复制 `Machine Key` 发给签发方。
- 签发方使用独立桌面工具生成 `license.token.json`。
- 用户将 license 文本直接粘贴回授权窗口并点击确认。
- 本地验签通过后自动持久化。
- 如果用户取消、关闭窗口或授权失败后不继续处理，并且 `bExitIfAuthorizationPromptCancelled=True`，则程序退出。

这意味着：

- 首次进入程序时，不再要求用户自己找目录拷文件。
- 同一台电脑换一个目录运行时，会复用公共缓存，不要求重新授权。
- 拷贝到另一台电脑时，由于 `DeviceId` 不一致，会要求重新授权。

## 16. 当前已落地的独立签发工具

签发工具已经改为独立桌面工具，不再保留 Editor 插件版。

工具位置：

- `Tools/GenericAuthorizationSigner`

工具能力：

- 可直接以桌面程序启动。
- 支持输入 `Machine Key` 后签发绑定设备的 license。
- 支持永久授权和定时授权。
- 支持快速模板方式生成基础包授权。
- 支持高级 JSON 方式编辑 `ManifestScopes` 和 `LicenseGrants`。
- 支持生成并保存：
  - `content.manifest.json`
  - `license.token.json`

独立发布方式：

- 执行 `Tools/GenericAuthorizationSigner/publish-win-x64.ps1`
- 发布结果位于 `Tools/GenericAuthorizationSigner/publish/win-x64`
---

## 17. 2026-04-04 最新落地说明

### 17.1 首开授权流程

当前游戏侧已经改成更贴近实际交付的首开授权流程：

- 程序启动时优先检查在线缓存授权。
- 如果没有有效在线授权，则继续检查离线缓存和包体旁 `Authorization` 目录。
- 如果仍然未授权，则直接弹出阻塞式授权窗口。
- 授权窗口不再展示原始 `Machine Key`。
- 窗口里只保留“复制申请码”按钮，用户点击后复制一串加密后的授权申请码。
- 用户将申请码发给签发方。
- 签发方使用独立桌面签发工具生成一串加密后的授权码。
- 用户把授权码粘贴回游戏窗口并确认。
- 验签通过后进入正常启动流程。
- 如果取消或关闭窗口，并且 `bExitIfAuthorizationPromptCancelled=True`，则程序退出。

### 17.2 申请码与授权码

当前已经不再走明文 JSON 直接展示的交互方式。

- 游戏侧发出的不是原始设备信息，而是加密后的“授权申请码”。
- 签发工具回传的也不是 `license.token.json` 明文，而是加密后的“授权码”。
- 游戏侧会先解密授权码，再做签名校验和设备绑定校验。
- 这样用户界面层看到的是单串码，而不是结构化明文内容。

注意：

- 这提升的是交互层和普通使用层的保护性，不等同于绝对安全。
- 真正的有效性仍然依赖签名校验、设备绑定、授权时效和本地缓存策略。

### 17.3 独立签发工具

签发工具已经固定放在：

- `GenericAuthorization/GenericAuthorizationSigner`

并且已经改成中文快签界面。

当前工具界面只保留最必要的内容：

- 授权申请码输入框
- 授权时效选择
- 生成授权码
- 复制授权码

不再要求每次手动输入：

- `ProductId`
- `VerificationKey`
- `MachineKey`
- `ManifestScopes`
- `LicenseGrants`

这些固定配置已经下沉到同目录的：

- `signer.settings.json`

默认发布产物位于：

- `GenericAuthorization/GenericAuthorizationSigner/publish/win-x64/GenericAuthorizationSigner.exe`

### 17.4 当前推荐使用方式

签发方：

1. 打开 `GenericAuthorizationSigner.exe`
2. 粘贴用户发来的授权申请码
3. 选择授权时效，例如 `1 小时 / 1 天 / 1 周 / 30 天 / 永久授权`
4. 点击“生成授权码”
5. 点击“复制授权码”并发回用户

用户：

1. 首次启动程序时看到授权窗口
2. 点击“复制申请码”
3. 将申请码发送给签发方
4. 收到授权码后粘贴回窗口
5. 点击“确认授权”
6. 授权成功后进入程序
