# GenericIOT UE5 物联控制首版方案文档

## 1. 文档目标

`GenericIOT` 用于承载 Unreal Engine 5 内的物联控制能力，目标是在 UE 工程内形成一套清晰、统一、可扩展、可替换、可调试的智能设备接入与控制框架。

首版需求的核心目标如下：

1. 自动发现局域网内的 `Home Assistant` 实例。
2. 自动同步 `Home Assistant` 中已经接入和暴露的智能设备实体。
3. 在 UE 内以统一方式展示、查询、控制智能设备。
4. 最终可用能力以 `ActorComponent` 形式挂载到 `Actor` / `Pawn` / `Character`。
5. 全局连接、发现、注册、同步、命令路由由 `Subsystem` 统一实现。
6. 尽可能多地覆盖 `Home Assistant` 可控域，并提供原生服务调用兜底入口。

首版范围明确限定为：

- 只接入 `Home Assistant`
- 只通过平台 API 接入
- 不直连品牌私有设备
- 不走设备私有 `UDP`
- 不走设备直连 `MQTT`

这里“自动获取局域网内智能设备”的工程定义不是“扫描出局域网里所有品牌设备”，而是：

- 自动发现本地 `Home Assistant`
- 连接并鉴权
- 从 `Home Assistant` 同步其已识别、已接入、已暴露的实体

因此，`GenericIOT` 的首版定位是：

- `UE5 物联控制前端`
- `Home Assistant 平台控制接入层`
- `统一设备抽象与蓝图暴露层`

而不是：

- 全品牌私有协议适配器合集
- 局域网设备抓包或扫描工具
- 自研智能家居平台

---

## 2. 首版强约束

### 2.1 首版只接入 `Home Assistant`

- 首版唯一平台接入对象是 `Home Assistant`
- 不写任何 `米家` 接入内容
- 不写任何 `智慧生活` 接入内容
- 不为其他生态平台预留首版必须实现的插件或流程

说明：

- 当前目标是先做通用、稳定、可落地的 UE 物联控制闭环
- `Home Assistant` 具备成熟的 `REST API` 与 `WebSocket API`
- 它本身已具备较强的设备接入与聚合能力，适合作为首版统一入口

### 2.2 首版不以设备私有协议直连为主路径

- 不以 `UDP` 广播控制设备
- 不以设备私有 `MQTT` 直连作为默认通路
- 不为每个品牌单独开发设备侧 LAN 协议
- 所有控制动作默认都应经过 `Home Assistant API`

允许的首版链路只有：

- `UE -> Home Assistant REST API`
- `UE -> Home Assistant WebSocket API`

不允许的首版链路包括但不限于：

- `UE -> 某品牌设备 UDP`
- `UE -> 某品牌设备私有 TCP`
- `UE -> 某设备本地 MQTT Broker`
- `UE -> 各品牌私有局域网协议 SDK`

### 2.3 最终业务能力必须以 `ActorComponent` 形式挂载

首版最终对外使用入口必须是 `UIOTComponent`。

要求如下：

- `UIOTComponent` 可挂载到任意 `Actor`
- 场景中的设备代理、可交互对象、控制终端、数字孪生模型都通过组件接入
- 组件只负责单实体绑定、状态缓存、事件分发和便捷控制
- 组件不负责全局网络连接、设备注册表和平台状态机

### 2.4 全局真实实现必须由 `Subsystem` 统一承载

首版运行时主入口为：

- `UIOTSubsystem : UGenericGameInstanceSubsystem`

其职责必须包括：

- 平台连接配置管理
- `Home Assistant` 实例发现
- 鉴权与连接校验
- 全量设备同步
- 增量状态订阅
- 全局设备注册表维护
- 命令路由与执行
- 全局错误与连接状态广播

### 2.5 控制能力尽可能多，但不能牺牲统一抽象

首版必须优先覆盖尽可能多的 `Home Assistant` 可控域。

同时必须满足：

- 蓝图侧不直接拼接 `domain` / `service`
- 常见设备能力走统一强类型命令模型
- 通用命令无法覆盖时，提供平台原生服务调用兜底入口
- 兜底入口也只能走 `Home Assistant service call`

### 2.6 首版最小设备映射单元为 `Home Assistant entity`

首版不做物理设备聚合，最小控制单元定义为：

- 一个 `Home Assistant entity`

原因如下：

- `entity` 是 `Home Assistant` 中最稳定、最直接、最可控的运行时对象
- `entity` 具备统一的状态、属性和服务调用语义
- 以 `entity` 为最小单元可以快速覆盖最多设备域
- 物理设备聚合通常依赖 `device_registry`、`area`、多实体组合策略，复杂度高，不适合作为首版必做项

---

## 3. 总体设计原则

### 3.1 平台聚合优先原则

`GenericIOT` 的首版核心理念不是“适配所有品牌协议”，而是：

- 优先复用成熟平台的设备接入能力
- 在 UE 内建立统一的设备抽象和控制接口
- 把复杂的设备接入问题尽量留给 `Home Assistant`

这意味着：

- `GenericIOT` 负责连接平台、同步设备、统一控制
- `Home Assistant` 负责整合各品牌设备、桥接协议、维护实体语义

### 3.2 统一设备抽象原则

上层蓝图和业务逻辑不应直接感知：

- `Home Assistant REST API` 路径
- `WebSocket` 消息协议细节
- `entity_id`
- `domain/service` 细节
- 设备属性原始 JSON 结构

上层必须通过统一抽象操作：

- 设备列表
- 设备类型
- 能力列表
- 状态快照
- 通用命令
- 原生服务兜底命令

### 3.3 不重复造轮子原则

仓库中已存在 `GenericCommunication` 相关通信能力，因此首版 `GenericIOT` 不应再自建一套底层通信框架。

必须优先复用：

- `HTTP`
- `WebSockets`
- `Json`
- `JsonUtilities`
- 现有 `GenericProtocol`
- 现有 `NativeAPI`

`GenericIOT` 只负责：

- IOT 设备建模
- 平台适配
- UE 暴露层
- 路由和状态管理

### 3.4 组件与全局实现分离原则

首版必须严格区分：

- `Subsystem` 的全局职责
- `ActorComponent` 的局部职责

不允许：

- 每个组件自己维护一个独立 `WebSocket`
- 每个组件自己做全量同步
- 每个组件自己持久化 `Token`
- 每个组件自己持有一套平台状态机

允许的方式是：

- 所有真实连接与同步都由 `Subsystem` 统一完成
- 组件只做绑定和消费

### 3.5 统一失败语义原则

所有失败都必须可被统一处理，不能把底层错误零散暴露给蓝图。

至少需要统一表达以下失败：

- 平台不可达
- 地址无效
- `Token` 无效
- 鉴权失败
- 实体不存在
- 实体离线
- 命令不支持
- 原生服务调用失败
- `WebSocket` 断连
- 自动重连失败

---

## 4. 插件与目录规划

首版目录规划如下：

```text
GenericIOT/
  GenericIOT.md
  GenericIOTFramework/
  Platform/
    GenericIOTWindows/
    GenericIOTAndroid/
  IOTPlatform/
    IOTPlatformHomeAssistant/
```

### 4.1 `GenericIOTFramework`

职责：

- 定义通用 `Type`
- 定义通用 `Enum`
- 定义通用 `Struct`
- 定义 `UIOTSubsystem`
- 定义 `UIOTComponent`
- 定义平台适配接口
- 定义设备注册表
- 定义通用命令模型
- 定义 Blueprint Function Library
- 定义 AsyncAction
- 定义日志分类

这层必须是平台无关、协议无关的核心层。

不应放入：

- `Home Assistant` REST 细节
- `WebSocket` 消息处理实现
- Windows 专属发现逻辑
- Android 专属权限处理

### 4.2 `Platform/GenericIOTWindows`

职责：

- Windows 平台网络环境检测
- Windows 下的 `Home Assistant` 实例发现实现
- Windows 配置存储与凭据存储适配
- Windows 生命周期桥接

这层负责平台差异，不负责 `Home Assistant` 协议语义。

### 4.3 `Platform/GenericIOTAndroid`

职责：

- Android 权限检查与申请策略
- Android 网络状态监听
- Android 下的 `Home Assistant` 实例发现实现
- Android 配置存储与凭据存储适配
- Android 生命周期桥接

这层也只负责平台差异，不负责平台协议语义。

### 4.4 `IOTPlatform/IOTPlatformHomeAssistant`

职责：

- `Home Assistant REST API` 接入
- `Home Assistant WebSocket API` 接入
- `entity` 全量拉取
- `state_changed` 增量订阅
- 通用命令到 `service call` 的映射
- 原生 `service call` 兜底入口
- 原始 JSON 到 UE 通用设备模型的转换

这是首版唯一的平台协议实现层。

### 4.5 插件依赖约束

依赖方向必须为：

- `GenericIOTWindows -> GenericIOTFramework`
- `GenericIOTAndroid -> GenericIOTFramework`
- `IOTPlatformHomeAssistant -> GenericIOTFramework`

`GenericIOTFramework` 不允许反向依赖：

- `GenericIOTWindows`
- `GenericIOTAndroid`
- `IOTPlatformHomeAssistant`

同时，`GenericIOT` 网络底层能力应优先依赖现有：

- `GenericCoreFramework`
- `GenericCommunication`
- `HTTP`
- `WebSockets`
- `Json`

---

## 5. 运行时架构规划

### 5.1 核心运行时链路

推荐运行时链路如下：

```text
UIOTComponent
    ->
UIOTSubsystem
    ->
IOTPlatformHomeAssistant Adapter
    ->
REST / WebSocket
    ->
Home Assistant
```

### 5.2 `UIOTSubsystem` 职责

`UIOTSubsystem` 必须作为全局运行时中心存在，负责所有真实 IOT 实现。

其职责包括：

- 读取和保存平台连接配置
- 管理当前连接状态
- 自动发现或手动连接 `Home Assistant`
- 建立 `REST` 和 `WebSocket` 会话
- 拉取全量实体
- 接收增量状态变更
- 构建设备注册表
- 对组件提供查询与控制入口
- 广播全局连接变化
- 广播设备状态变化
- 统一处理重连与错误

推荐最少公开能力：

- `Connect`
- `Disconnect`
- `RefreshDevices`
- `GetAllDevices`
- `GetDevice`
- `GetDeviceState`
- `ExecuteCommand`
- `ExecuteRawService`
- `SubscribeRealtime`
- `IsConnected`

### 5.3 `UIOTComponent` 职责

`UIOTComponent` 是最终挂载到场景对象上的业务入口。

它的职责必须限制为：

- 绑定一个目标 `EntityId`
- 缓存该实体的最新状态
- 对蓝图暴露简化控制方法
- 监听 `Subsystem` 的全局状态变更并过滤出自身关心的实体
- 将所有控制请求转交给 `Subsystem`

组件不负责：

- 鉴权
- 持久化
- `WebSocket` 建连
- `HTTP` 请求实现
- 全量同步
- 全局注册表维护

### 5.4 一组件一实体原则

首版组件按照“一组件绑定一个逻辑实体”设计。

原因如下：

- 可以直接对应 `Home Assistant entity`
- 状态同步模型最简单
- 控制路径最清晰
- 蓝图使用成本最低

因此首版不做：

- 一组件自动绑定多个实体
- 一组件自动聚合一个物理设备的多个控制实体
- 一组件自动按 `area` 管理多设备

### 5.5 全局设备面板与场景实体分工

推荐使用方式如下：

- 设备列表页、系统面板、配置页直接调用 `UIOTSubsystem`
- 场景设备、控制终端、数字孪生对象挂载 `UIOTComponent`

这样可以兼顾：

- 全局管理
- 局部交互
- 蓝图便利性
- 运行时复用

---

## 6. 核心公开接口与类型设计

## 6.1 核心类

首版必须包含以下核心公开类：

- `UIOTSubsystem`
- `UIOTComponent`
- `UIOTPlatformAdapter` / `IIOTPlatformAdapter`
- `UBPFunctions_IOT`
- `UConnectIOTPlatformAsyncAction`
- `URefreshIOTDevicesAsyncAction`
- `UExecuteIOTCommandAsyncAction`
- `USubscribeIOTRealtimeAsyncAction`

### 6.2 核心枚举

首版必须包含以下核心枚举，并且全部写中文注释：

- `EIOTPlatformKind`
- `EIOTConnectionState`
- `EIOTDeviceKind`
- `EIOTCapabilityKind`
- `EIOTCommandStatus`

推荐语义如下：

- `EIOTPlatformKind`
  - `HomeAssistant`
- `EIOTConnectionState`
  - `Disconnected`
  - `Discovering`
  - `Connecting`
  - `Connected`
  - `Subscribing`
  - `Error`
- `EIOTDeviceKind`
  - `Unknown`
  - `Light`
  - `Switch`
  - `Fan`
  - `Cover`
  - `Climate`
  - `Humidifier`
  - `WaterHeater`
  - `MediaPlayer`
  - `Vacuum`
  - `Lock`
  - `Alarm`
  - `Siren`
  - `Scene`
  - `Script`
  - `Button`
  - `InputBoolean`
  - `InputNumber`
  - `InputSelect`
  - `Number`
  - `Select`
  - `Timer`
  - `Remote`
  - `Sensor`
  - `BinarySensor`
- `EIOTCapabilityKind`
  - `Power`
  - `Toggle`
  - `Brightness`
  - `ColorTemperature`
  - `Color`
  - `Mode`
  - `Preset`
  - `Option`
  - `TargetTemperature`
  - `Position`
  - `Volume`
  - `Mute`
  - `Playback`
  - `Trigger`
  - `LockControl`
  - `ArmControl`
  - `NumericValue`
  - `SensorValue`
- `EIOTCommandStatus`
  - `Success`
  - `Unsupported`
  - `InvalidArgument`
  - `EntityUnavailable`
  - `PlatformUnavailable`
  - `AuthenticationFailed`
  - `TransportError`
  - `PlatformError`

### 6.3 核心配置结构 `FIOTPlatformEndpointConfig`

该结构用于保存平台连接配置。

至少包含：

- `PlatformKind`
- `BaseUrl`
- `AccessToken`
- `InstanceName`
- `bAutoDiscover`
- `bAutoReconnect`
- `RequestTimeoutSeconds`

用途：

- 作为 `Subsystem` 的连接配置输入
- 作为持久化配置的最小模型

### 6.4 核心设备描述 `FIOTDeviceDescriptor`

该结构用于描述一个可被 UE 控制或查询的逻辑设备实体。

至少包含：

- `DeviceId`
- `PlatformKind`
- `EntityId`
- `DisplayName`
- `DeviceKind`
- `CapabilityDescriptors`
- `RawDomain`
- `RawAttributes`

说明：

- `DeviceId` 使用统一格式，例如 `ha:light.living_room_main`
- `EntityId` 保留 `Home Assistant` 原始标识，例如 `light.living_room_main`
- `RawDomain` 例如 `light`、`climate`
- `RawAttributes` 保留原始平台属性，便于调试和兜底显示

### 6.5 核心能力描述 `FIOTCapabilityDescriptor`

该结构用于描述一个设备支持的控制或查询能力。

至少包含：

- `CapabilityKind`
- `CapabilityName`
- `bReadable`
- `bWritable`
- `MinValue`
- `MaxValue`
- `OptionValues`

说明：

- 通用能力由平台 Adapter 根据 `domain + attributes` 推导
- 蓝图层只消费能力结果，不感知推导细节

### 6.6 核心状态结构 `FIOTDeviceState`

该结构用于保存当前实体的状态快照。

至少包含：

- `bAvailable`
- `PrimaryState`
- `CapabilityValues`
- `LastUpdatedUtc`
- `RawState`

说明：

- `PrimaryState` 用于表示如 `on`、`off`、`playing`、`idle`
- `CapabilityValues` 保存亮度、模式、温度、位置等状态值
- `RawState` 保存平台原始状态，方便调试与高级展示

### 6.7 通用命令结构 `FIOTCommandRequest`

该结构用于描述一次统一控制请求。

至少包含：

- `DeviceId`
- `CapabilityKind`
- `CommandName`
- `Parameters`

说明：

- `CommandName` 用于表达通用动作，如 `TurnOn`、`SetBrightness`
- `Parameters` 用于承载亮度值、温度值、颜色值等参数

### 6.8 命令结果结构 `FIOTCommandResult`

该结构用于描述命令执行结果。

至少包含：

- `Status`
- `bSucceeded`
- `ErrorCode`
- `ErrorMessage`
- `UpdatedState`
- `PlatformResponseSummary`

说明：

- `bSucceeded` 用于蓝图快速判断
- `Status` 用于统一细分失败类型
- `UpdatedState` 用于命令成功后的状态回传

---

## 7. Component 与 Subsystem 分工约束

### 7.1 `UIOTComponent` 必须是首版最终入口

首版所有面向业务使用的场景实体，必须通过 `UIOTComponent` 接入。

这意味着：

- 业务不直接 new 平台 Adapter
- 业务不直接连 `WebSocket`
- 蓝图不直接发 `HTTP`
- 蓝图不直接调用 `Home Assistant service`

### 7.2 `UIOTComponent` 最少公开能力

组件至少需要暴露以下能力：

- 绑定目标 `EntityId`
- 切换目标 `EntityId`
- 获取当前设备是否在线
- 获取当前设备类型
- 获取当前能力列表
- 获取当前状态快照
- 执行开关类命令
- 执行数值类命令
- 执行模式类命令
- 执行触发类命令
- 执行原生服务调用

### 7.3 `UIOTComponent` 最少蓝图事件

组件对蓝图至少需要广播：

- `OnStateChanged`
- `OnConnectionChanged`
- `OnCommandSucceeded`
- `OnCommandFailed`

可选增加：

- `OnEntityBound`
- `OnEntityNotFound`
- `OnEntityUnavailable`

### 7.4 `UIOTSubsystem` 是唯一真实实现中心

所有真实实现都集中在：

- `UIOTSubsystem`
- 平台 Adapter

组件只调用：

- `UIOTSubsystem::ExecuteCommand`
- `UIOTSubsystem::ExecuteRawService`
- `UIOTSubsystem::GetDeviceState`

### 7.5 全局注册表为唯一真值来源

首版设备真值来源必须统一为 `Subsystem` 内部注册表。

组件只做局部缓存，不做真值主存。

原因如下：

- 避免多份状态源不一致
- 便于统一增量更新
- 便于设备列表与场景对象共享同一数据

---

## 8. Home Assistant 首版接入方案

## 8.1 实例发现策略

首版 `Home Assistant` 实例发现策略如下：

1. 优先读取已经保存的 `BaseUrl`
2. 如果没有已保存配置，则尝试局域网发现 `_home-assistant._tcp.local.`
3. 如果自动发现失败，则允许手动输入 `BaseUrl`

说明：

- 自动发现仅用于找出可连接的 `Home Assistant` 实例
- 自动发现不等价于直接发现所有设备
- 真正的设备同步发生在连接并鉴权成功之后

### 8.2 鉴权方式

首版只支持：

- `Base URL + Long-Lived Access Token`

不做：

- `OAuth2`
- `IndieAuth`
- 移动端原生登录流程

原因如下：

- `Long-Lived Access Token` 集成成本最低
- 更适合作为首版工程接入方式
- 便于桌面端与 Android 使用统一流程

### 8.3 连接校验

保存连接配置前，必须完成以下校验：

- `BaseUrl` 是否格式有效
- `Home Assistant` 是否可访问
- `Token` 是否有效
- `/api/states` 是否可正常返回

只有全部通过后，才能将配置视为可用。

### 8.4 全量设备同步

首版全量设备同步策略如下：

- 连接建立后调用 `GET /api/states`
- 遍历所有返回实体
- 根据 `domain` 和 `attributes` 转换成 UE 通用设备模型
- 构建设备注册表

首版设备同步只关注：

- 可读实体
- 可控实体
- 与蓝图展示/控制直接相关的实体

### 8.5 实时状态同步

首版实时同步策略如下：

- 通过 `/api/websocket` 建立连接
- 完成鉴权
- 订阅 `state_changed` 事件
- 收到变化后更新注册表
- 通知绑定该实体的组件

首版要求：

- 启动时先全量同步
- 连接后再进入增量同步
- 断线后按策略自动重连

### 8.6 命令执行

首版命令执行统一走：

- `POST /api/services/<domain>/<service>`

由 `Home Assistant Adapter` 负责把通用命令映射成具体平台调用。

例如：

- `TurnOn -> light.turn_on`
- `TurnOff -> switch.turn_off`
- `SetBrightness -> light.turn_on + brightness`
- `SetTargetTemperature -> climate.set_temperature`

### 8.7 原生服务兜底入口

为了覆盖尽可能多的控制能力，首版必须提供原生服务调用入口：

```cpp
ExecuteRawService(FName Domain, FName Service, TMap<FString, FString> Params)
```

该接口的约束如下：

- 只允许调用 `Home Assistant service`
- 不允许扩展为设备私有 LAN 协议调用
- 用于补齐通用命令未覆盖的域与服务
- 用于高级用户和调试场景

### 8.8 错误处理与重连

首版必须统一处理以下场景：

- `BaseUrl` 不可达
- `Token` 失效
- `REST` 请求失败
- `WebSocket` 认证失败
- `WebSocket` 中断
- 自动重连失败
- 实体不存在
- 实体离线
- 目标服务不存在
- 服务参数不合法

首版必须明确：

- 错误需要统一映射为 `FIOTCommandResult`
- 连接状态变化需要广播给组件
- 所有关键错误都必须记录日志

---

## 9. 首版设备模型决策

### 9.1 首版设备定义

首版设备定义为：

- `Home Assistant entity`

而不是：

- 物理设备
- 房间
- 区域
- 品牌设备节点

### 9.2 设备唯一标识

推荐统一格式：

- `ha:<entity_id>`

示例：

- `ha:light.living_room_main`
- `ha:climate.office_ac`
- `ha:switch.projector_power`

### 9.3 设备类型映射

`Home Assistant domain` 需要被映射为 `EIOTDeviceKind`。

例如：

- `light -> Light`
- `switch -> Switch`
- `fan -> Fan`
- `cover -> Cover`
- `climate -> Climate`
- `humidifier -> Humidifier`
- `water_heater -> WaterHeater`
- `media_player -> MediaPlayer`
- `vacuum -> Vacuum`
- `lock -> Lock`
- `alarm_control_panel -> Alarm`
- `scene -> Scene`
- `script -> Script`

### 9.4 首版不做物理设备聚合

首版不做：

- `device_registry` 聚合
- `area` 分组聚合
- 多实体合并成一个业务设备

例如某空调若包含：

- `climate.office_ac`
- `sensor.office_ac_temp`
- `switch.office_ac_power`

首版应按三个逻辑实体处理，而不是自动聚合成一个 “空调设备对象”。

---

## 10. 控制能力覆盖规划

## 10.1 首版必须尽可能多覆盖 `Home Assistant` 可控域

首版通用能力层至少纳入以下域：

- `light`
- `switch`
- `fan`
- `cover`
- `climate`
- `humidifier`
- `water_heater`
- `media_player`
- `vacuum`
- `lock`
- `alarm_control_panel`
- `siren`
- `scene`
- `script`
- `button`
- `input_boolean`
- `input_button`
- `input_number`
- `input_select`
- `number`
- `select`
- `timer`
- `remote`
- `sensor`
- `binary_sensor`

其中：

- `sensor`
- `binary_sensor`

默认只读，不控制。

### 10.2 首版通用命令模型

首版通用命令至少需要支持以下动作：

- 开关类
  - `TurnOn`
  - `TurnOff`
  - `Toggle`
- 数值类
  - `SetValue`
  - `Increase`
  - `Decrease`
- 亮度与颜色类
  - `SetBrightness`
  - `SetColorTemp`
  - `SetRgbColor`
- 模式类
  - `SetMode`
  - `SetPreset`
  - `SetOption`
- 温控类
  - `SetTargetTemperature`
  - `SetHVACMode`
- 位置类
  - `Open`
  - `Close`
  - `Stop`
  - `SetPosition`
- 媒体类
  - `Play`
  - `Pause`
  - `StopMedia`
  - `Next`
  - `Previous`
  - `SetVolume`
  - `Mute`
- 清扫类
  - `Start`
  - `PauseTask`
  - `Resume`
  - `ReturnToBase`
- 安防类
  - `Lock`
  - `Unlock`
  - `Arm`
  - `Disarm`
  - `Trigger`
- 触发类
  - `ActivateScene`
  - `RunScript`
  - `PressButton`

### 10.3 通用命令与原生服务双层方案

为了实现“控制能力尽可能多”，首版必须采用双层方案：

第一层：

- 强类型通用命令层

适用于：

- 常见灯光
- 开关
- 温控
- 媒体
- 门锁
- 窗帘

第二层：

- `ExecuteRawService` 原生服务调用层

适用于：

- 通用命令尚未覆盖的域
- 某些平台特有高级服务
- 调试与高级扩展

### 10.4 映射策略约束

通用命令映射必须满足：

- 映射逻辑集中在 `Home Assistant Adapter`
- 不允许散落到组件中
- 不允许散落到 `BPFunctions_IOT`
- 不允许让蓝图直接知道具体 `service`

---

## 11. Blueprint 暴露与代码规范

## 11.1 所有异步流程必须提供 `AsyncAction`

以下流程都必须提供异步蓝图入口：

- 平台连接
- 设备刷新
- 命令执行
- 实时订阅启动

推荐类名：

- `UConnectIOTPlatformAsyncAction`
- `URefreshIOTDevicesAsyncAction`
- `UExecuteIOTCommandAsyncAction`
- `USubscribeIOTRealtimeAsyncAction`

### 11.2 `BPFunctions_IOT` 只保留轻量入口

`UBPFunctions_IOT` 适合承载：

- 获取 `UIOTSubsystem`
- 获取组件当前状态
- 参数转换
- 枚举转换
- 快捷触发 `AsyncAction`

`UBPFunctions_IOT` 不应承载：

- `HTTP` 请求实现
- `WebSocket` 状态机
- 命令映射逻辑
- 自动重连流程
- 平台配置持久化

### 11.3 组件事件规范

`UIOTComponent` 对外至少广播：

- `OnStateChanged`
- `OnConnectionChanged`
- `OnCommandSucceeded`
- `OnCommandFailed`

建议再补充：

- `OnEntityBound`
- `OnEntityUnavailable`

### 11.4 中文注释规范

所有以下类型都必须写中文注释：

- `Type`
- `Enum`
- `Struct`
- `Settings`
- 蓝图暴露字段
- 蓝图事件

注释要求：

- 解释业务含义
- 解释默认值语义
- 解释字段边界
- 不要只重复字段名

### 11.5 日志规范

日志必须覆盖：

- 实例发现
- 连接开始
- 鉴权成功与失败
- 全量同步
- 增量订阅
- 命令映射
- 命令执行成功与失败
- 断线
- 自动重连
- 平台错误码

---

## 12. 首版实施路径

推荐实施顺序如下：

### 阶段 1：`GenericIOTFramework`

完成：

- 基础类型
- 枚举
- 数据结构
- `UIOTSubsystem`
- `UIOTComponent`
- Blueprint 入口
- AsyncAction 骨架
- 日志分类

### 阶段 2：平台差异层

完成：

- `GenericIOTWindows`
- `GenericIOTAndroid`

重点：

- 自动发现
- 配置持久化
- 网络状态监听
- 生命周期桥接

### 阶段 3：`IOTPlatformHomeAssistant`

完成：

- `REST` 接入
- `/api/states` 全量同步
- `/api/websocket` 增量同步
- 通用命令映射
- `ExecuteRawService`

### 阶段 4：蓝图验证闭环

完成：

- 设备列表同步
- 场景组件绑定
- 灯光/开关/空调/窗帘/媒体等常见控制验证
- 错误场景验证

---

## 13. 首版不做的内容

首版明确不做以下内容：

- 不做米家接入
- 不做智慧生活接入
- 不做品牌私有局域网协议适配
- 不做设备直连 `MQTT`
- 不做设备私有 `UDP` 广播控制
- 不做品牌私有 TCP 协议直连
- 不做物理设备级自动聚合
- 不做多平台统一路由器
- 不做 `OAuth2`
- 不做 `IndieAuth`
- 不做全品牌兼容承诺

---

## 14. 测试与验收标准

首版至少需要满足以下验收场景：

### 14.1 实例发现与连接

- 未配置 `BaseUrl` 时，系统能自动尝试发现本地 `Home Assistant`
- 自动发现失败时，允许手动输入 `BaseUrl + Token`
- 正确配置后能够成功连通并校验鉴权

### 14.2 设备同步

- 系统能够从 `Home Assistant` 拉取实体列表
- 能将实体转换为统一设备描述
- 能建立全局设备注册表

### 14.3 场景组件绑定

- 场景中挂载 `UIOTComponent` 的 `Actor` 能绑定指定 `EntityId`
- 组件能获取当前状态
- 组件能收到后续状态变化

### 14.4 通用控制能力

- 灯光能开关、调亮度、调色温、调颜色
- 开关设备能开关
- 风扇能开关与调整模式或转速
- 窗帘能开关停和设置位置
- 空调能设置模式和目标温度
- 媒体设备能播放、暂停、切换、调音量
- 门锁、警报、脚本、场景等能完成基础控制

### 14.5 原生服务兜底能力

- 对于通用命令尚未覆盖的服务，`ExecuteRawService` 能成功调用
- 调用失败时能够返回统一失败结果

### 14.6 实时同步

- `Home Assistant` 中实体状态变化后，`WebSocket` 能收到事件
- 注册表能更新
- 绑定组件能同步更新

### 14.7 失败场景

- 平台不可达时有明确失败结果
- `Token` 无效时有明确失败结果
- 实体离线时有明确失败结果
- 服务不存在时有明确失败结果
- `WebSocket` 断连时有重连策略与日志

### 14.8 文档验收目标

文档完成后，实施者不需要再自行决定以下问题：

- 首版只接哪个平台
- 挂载入口是什么
- 全局实现放在哪
- 设备最小单元是什么
- 支持哪些控制能力
- 兜底服务怎么设计
- 首版明确不做什么

---

## 15. 官方参考

首版接入方案参考以下官方文档：

- Home Assistant REST API  
  https://developers.home-assistant.io/docs/api/rest/
- Home Assistant WebSocket API  
  https://developers.home-assistant.io/docs/api/websocket/
- Home Assistant Native App Integration Setup  
  https://developers.home-assistant.io/docs/api/native-app-integration/setup/

---

## 16. 结论

`GenericIOT` 首版的正式路线收敛为：

- 只接 `Home Assistant`
- 只走平台 API
- 最终对外入口是 `UIOTComponent`
- 真实实现中心是 `UIOTSubsystem`
- 设备最小单元是 `Home Assistant entity`
- 通用命令尽可能覆盖 `Home Assistant` 可控域
- 无法统一抽象的高级能力通过 `ExecuteRawService` 兜底
- 不做品牌私有协议直连

这样可以在 Unreal 工程内尽快形成一套：

- 稳定
- 清晰
- 可扩展
- 蓝图友好
- 便于后续继续扩展的平台化物联控制框架
