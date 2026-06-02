# GenericAudio 数字人语音能力需求文档

## 1. 文档目标

`GenericAudio` 用于承载数字人语音能力，目标是在 Unreal 工程内形成一套清晰、统一、可扩展、可替换、可调试的语音插件体系。

当前需求的核心目标如下：

1. 语音唤醒
2. 语音识别
3. 文本、语音、录音互转
4. 语音合成
5. 语音播放

默认支持语言：

- 中文
- 英文

其他语种不在首期范围内，但框架必须支持后续按 Provider、模型、音色、配置扩展。

---

## 2. 本次需求的强约束

本次设计必须严格满足以下约束：

### 2.1 不按在线 / 离线拆成两个插件

- 不允许把同一个能力拆成 `OnlinePlugin` 和 `OfflinePlugin` 两个插件
- 一个能力只保留一个插件
- 在线和离线能力在同一个能力插件内部拆模块

例如语音唤醒必须是：

```text
VoiceWakeupSystem/
  GenericVoiceWakeupFramework
  Online/
    VoiceWakeupXfyun
    VoiceWakeupDoubao
    ThirdParty/
      VoiceWakeupSdk
  Offline/
    VoiceWakeupSherpaOnnx
    VoiceWakeupPicovoice
```

而不是：

- `VoiceWakeupOnlineSystem`
- `VoiceWakeupOfflineSystem`

### 2.2 优先在线

- 首期优先实现在线能力
- 当在线和离线同时可用时，默认优先在线
- 在线失败、超时、未配置、鉴权失败时，再按配置回退到离线

默认路由策略定义为：

- `OnlineFirst`

必须保留以下可配置策略：

- `OnlineFirst`
- `OfflineFirst`
- `OnlineOnly`
- `OfflineOnly`
- `Hybrid`

### 2.3 `GenericVoiceFramework` 只放全 Voice 通用内容

- `GenericVoiceFramework` 只负责所有语音能力共享的基础通用内容
- 每个功能插件内部可以再定义自己的功能级基础框架

例如：

- 全局通用框架：`GenericVoiceFramework`
- 唤醒功能框架：`GenericVoiceWakeupFramework`
- 识别功能框架：`GenericVoiceRecognitionFramework`
- 合成功能框架：`GenericVoiceSynthesisFramework`

### 2.4 命名统一以 `GenericXXX` 为准

所有插件名、模块名、类名、接口名、日志名、设置名、组件名、数据结构名，统一使用 `GenericXXX` 风格。

示例：

- `GenericVoiceWakeupFramework`
- `UVoiceWakeupComponent`
- `UVoiceWakeupInterface`
- `IVoiceWakeupInterface`
- `FVoiceWakeupResult`
- `LogVoiceWakeup`

### 2.5 日志必须丰富齐全

- 日志风格参考现有 `GenericLogAuthorization`
- 每个能力插件都要有独立日志分类
- 日志必须覆盖初始化、配置、路由、请求、响应、回退、错误、性能、状态切换
- 目标是方便后续调试在线链路、离线链路、平台差异和业务回调

### 2.6 成品必须以 `Component` 形式挂载

- 所有最终可用能力以 `Component` 形式挂载到 `Actor` / `Pawn` / `Character`
- 功能扩展与业务回调通过 `Interface` 方式完成
- Blueprint 侧通过 `UInterface` 提供回调，例如：如果Owner有指定UInterface，则将广播回调
- C++ 侧通过 `Multicast Delegate` 提供扩展与回调

---

## 3. 总体设计原则

### 3.1 插件拆分原则

- 基础通用内容统一放在 `GenericVoiceFramework`
- 每个业务能力单独拆成一个独立插件
- 每个插件内部按“功能框架 + SDK + 在线模块 + 离线模块 + Provider 实现”分层
- 不在上层业务中直接依赖第三方 SDK

推荐插件清单如下：

```text
GenericAudio/
  GenericAudio.md
  GenericVoiceFramework/
  VoiceWakeupSystem/
  VoiceRecognitionSystem/
  VoiceSynthesisSystem/
  VoicePlaybackSystem/
  VoiceConversationSystem/
```

### 3.2 可替换原则

- 所有第三方能力都通过统一接口封装
- Provider 可替换，不影响上层蓝图和数字人逻辑
- 模型、音色、热词、唤醒词、云平台账号全部通过配置暴露
- 上层组件不直接感知具体厂商 SDK

### 3.3 不重复造轮子原则

- 优先接入成熟稳定的第三方方案
- 不自研底层 Wake Word、ASR、TTS 算法
- 自研范围只包含 Unreal 封装、组件、接口、回调、调度、缓存、日志、播放链路

### 3.4 平台优先级原则

平台优先级如下：

1. Windows 桌面端
2. UOS / 麒麟等国产 Linux
3. 其他国产 Linux / ARM64 平台
4. HarmonyOS / OpenHarmony
5. Android
6. Linux 通用桌面 / 服务器
7. macOS / iOS

说明：

- 国产平台优先级中，当前明确以 `UOS / 麒麟` 为最高优先级
- 所有在线链路和离线链路都应优先验证 Windows 与 `UOS / 麒麟`

---

## 4. 总体架构规划

## 4.1 全局通用基础插件：`GenericVoiceFramework`

`GenericVoiceFramework` 用于承载所有 Voice 能力共享的通用内容，不承载某个具体功能的业务逻辑。

其职责包括：

- 通用语音数据结构
- 通用请求 / 响应模型
- 通用语言定义
- 通用音频格式定义
- 通用 Provider 注册、查找、优先级与回退机制
- 通用配置读取
- 通用麦克风采集封装
- PCM / WAV / 压缩格式处理
- 重采样、声道转换、VAD、音量归一化等基础处理
- 通用异步任务
- 通用 Blueprint Library
- 通用日志工具
- 通用缓存、临时文件、请求 ID、会话 ID 管理
- 数字人会话级上下文

推荐模块结构：

```text
GenericVoiceFramework/
  Resources/
  Source/
    GenericVoiceFramework
    GenericVoiceFrameworkEditor          // 可选
```

说明：

- `GenericVoiceFramework` 只做全局共享通用层
- 任何具体功能的功能级基础框架，不放在这里

## 4.2 功能插件内部的二级框架

每个能力插件内部都可以定义自己的功能级基础框架，负责该能力内部的抽象、数据类型、Provider 基类、组件基类、接口和回调事件。

例如：

- `GenericVoiceWakeupFramework`
- `GenericVoiceRecognitionFramework`
- `GenericVoiceSynthesisFramework`
- `GenericVoicePlaybackFramework`

这层是 `GenericVoiceFramework` 之上的第二层抽象。

---

## 5. 插件与模块设计

## 5.1 语音唤醒插件：`VoiceWakeupSystem`

职责：

- 持续监听音频输入
- 中文 / 英文唤醒词检测
- 唤醒后事件分发
- 与识别链路联动
- 支持在线优先与离线回退

推荐结构：

```text
VoiceWakeupSystem/
  Resources/
  Source/
    GenericVoiceWakeupFramework       // 唤醒能力基础框架、组件、接口、回调
    Online/
      VoiceWakeupXfyun                // 在线 Provider
      VoiceWakeupDoubao               // 在线 Provider
      ThirdParty/
        VoiceWakeupSdk                // 在线 Provider 依赖的第三方 SDK
    Offline/
      VoiceWakeupSherpaOnnx           // 离线 Provider
      VoiceWakeupPicovoice            // 离线 Provider
```

说明：

- 在线 / 离线拆模块，不拆插件
- `GenericVoiceWakeupFramework` 放唤醒通用结构、接口、组件、事件
- 在线模块统一放 `Source/Online`
- 离线模块统一放 `Source/Offline`

## 5.2 语音识别插件：`VoiceRecognitionSystem`

职责：

- 实时流式识别
- 录音文件识别
- 中间结果、最终结果回调
- 中文 / 英文默认支持
- 热词与领域词扩展
- 在线优先，离线回退

推荐结构：

```text
VoiceRecognitionSystem/
  Resources/
  Source/
    GenericVoiceRecognitionFramework
    Online/
      VoiceRecognitionVolcengine
      VoiceRecognitionXfyun
      VoiceRecognitionDoubao
      VoiceRecognitionDify
      ThirdParty/
        VolcEngineRTC
    Offline/
      VoiceRecognitionSherpaOnnx
      VoiceRecognitionWhisperCpp
      VoiceRecognitionVosk
```

## 5.3 语音合成插件：`VoiceSynthesisSystem`

职责：

- 文本转语音
- 中文 / 英文音色输出
- 在线优先，离线回退
- 支持流式输出与音频缓存

推荐结构：

```text
VoiceSynthesisSystem/
  Resources/
  Source/
    GenericVoiceSynthesisFramework
    Online/
      VoiceSynthesisVolcengine
      VoiceSynthesisXfyun
      VoiceSynthesisDoubao
      VoiceSynthesisDify
      VoiceSynthesisWenxin
    Offline/
      VoiceSynthesisSherpaOnnx
      VoiceSynthesisPiper
```

## 5.4 语音播放插件：`VoicePlaybackSystem`

职责：

- 本地文件播放
- 实时流式音频播放
- 合成结果播放
- 播放控制、抢占、排队、恢复
- 为口型同步和字幕同步预留事件

推荐结构：

```text
VoicePlaybackSystem/
  Resources/
  Source/
    GenericVoicePlaybackFramework
```

## 5.5 数字人对话平台插件：`VoiceConversationSystem`

职责：

- 对接文心一言
- 对接 Dify
- 对接 豆包 / 火山方舟
- 作为数字人上层语义 / 工作流 / Agent 编排插件
- 与 ASR / TTS 解耦

推荐结构：

```text
VoiceConversationSystem/
  Resources/
  Source/
    GenericVoiceConversationFramework
    Online/
      VoiceConversationWenxin
      VoiceConversationDify
      VoiceConversationDoubao
    Offline/
      VoiceConversationLocal
```

说明：

- `VoiceConversationSystem` 不替代 ASR / TTS
- 它是数字人的上层对话平台接入层
- 语音闭环应仍然保持 `Wakeup -> Recognition -> Conversation -> Synthesis -> Playback`

---

## 6. 组件化成品设计

## 6.1 必须以 Component 形式挂载

最终交付给业务使用的成品统一为 `Component`。

推荐组件如下：

- `UVoiceWakeupComponent`
- `UVoiceRecognitionComponent`
- `UVoiceSynthesisComponent`
- `UVoicePlaybackComponent`
- `UVoiceConversationComponent`
- `UVoiceAgentComponent`          // 数字人总控组件，可选

推荐挂载对象：

- `AActor`
- `APawn`
- `ACharacter`
- 数字人专用 Actor

组件建议声明风格：

```cpp
UCLASS(MinimalAPI, Blueprintable, ClassGroup=(GenericFramework), meta=(BlueprintSpawnableComponent))
class UVoiceWakeupComponent : public UActorComponent
```

## 6.2 Component 责任定义

### `UVoiceWakeupComponent`

负责：

- 管理唤醒 Provider
- 启停监听
- 接收麦克风输入
- 触发唤醒事件
- 向识别组件转交控制权

### `UVoiceRecognitionComponent`

负责：

- 启停实时识别
- 录音文件转写
- 中间结果与最终结果回调
- 在线优先 / 离线回退

### `UVoiceSynthesisComponent`

负责：

- 文本转语音请求
- 语音缓存
- 音频输出数据分发
- 与播放组件联动

### `UVoicePlaybackComponent`

负责：

- 播放音频流
- 控制音频队列
- 中断 / 停止 / 暂停 / 恢复
- 输出播放状态事件

### `UVoiceAgentComponent`

负责：

- 编排多个 Voice 组件
- 驱动数字人完整会话链路
- 管理会话状态、超时、打断、串联回调

---

## 7. Interface 扩展与回调设计

## 7.1 统一使用 Interface 扩展

所有组件必须支持 Interface 扩展。

推荐接口如下：

- `UVoiceWakeupInterface` / `IVoiceWakeupInterface`
- `UVoiceRecognitionInterface` / `IVoiceRecognitionInterface`
- `UVoiceSynthesisInterface` / `IVoiceSynthesisInterface`
- `UVoicePlaybackInterface` / `IVoicePlaybackInterface`
- `UVoiceAgentInterface` / `IVoiceAgentInterface`

用途分为两类：

- 业务回调接口
- 可替换扩展接口

## 7.2 Blueprint 回调要求

每个组件都必须提供尽可能完整的 `Multicast Delegate` 事件。

回调设计参考现有 `GenericProtocol` 中 `Request`、`WebSocket`、`Udp` 的事件粒度，不允许只给一个 `OnSuccess` 和一个 `OnFailed`。

### 语音唤醒组件回调

至少包括：

- `OnWakeupInitialized`
- `OnWakeupStarted`
- `OnWakeupListening`
- `OnWakeupDetected`
- `OnWakeupRejected`
- `OnWakeupCooldownStarted`
- `OnWakeupCooldownFinished`
- `OnWakeupProviderChanged`
- `OnWakeupRouteChanged`
- `OnWakeupFallbackTriggered`
- `OnWakeupStopped`
- `OnWakeupError`

### 语音识别组件回调

至少包括：

- `OnRecognitionInitialized`
- `OnRecognitionStarted`
- `OnRecognitionSpeechBegin`
- `OnRecognitionPartialResult`
- `OnRecognitionSentenceEnd`
- `OnRecognitionFinalResult`
- `OnRecognitionSpeechEnd`
- `OnRecognitionProviderChanged`
- `OnRecognitionRouteChanged`
- `OnRecognitionFallbackTriggered`
- `OnRecognitionStopped`
- `OnRecognitionCancelled`
- `OnRecognitionError`

### 语音合成组件回调

至少包括：

- `OnSynthesisInitialized`
- `OnSynthesisStarted`
- `OnSynthesisChunkGenerated`
- `OnSynthesisCacheHit`
- `OnSynthesisProgress`
- `OnSynthesisFinished`
- `OnSynthesisProviderChanged`
- `OnSynthesisRouteChanged`
- `OnSynthesisFallbackTriggered`
- `OnSynthesisCancelled`
- `OnSynthesisError`

### 语音播放组件回调

至少包括：

- `OnPlaybackQueued`
- `OnPlaybackStarted`
- `OnPlaybackProgress`
- `OnPlaybackPaused`
- `OnPlaybackResumed`
- `OnPlaybackInterrupted`
- `OnPlaybackStopped`
- `OnPlaybackFinished`
- `OnPlaybackError`

### 数字人总控组件回调

至少包括：

- `OnVoiceSessionStarted`
- `OnVoiceSessionWakeup`
- `OnVoiceSessionRecognizing`
- `OnVoiceSessionThinking`
- `OnVoiceSessionSpeaking`
- `OnVoiceSessionInterrupted`
- `OnVoiceSessionFinished`
- `OnVoiceSessionError`

## 7.3 C++ Interface 回调要求

除了 Delegate，还必须提供 `BlueprintNativeEvent` / `BlueprintCallable` 风格接口，方便 C++ 与 Blueprint 双端扩展。

要求：

- 上层可只依赖 Interface，不直接依赖具体 Provider
- 组件 Owner 可以实现 Interface 接收回调
- 数字人 Actor 可以通过 Interface 控制行为切换、表情切换、口型同步

---

## 8. 路由与优先级设计

## 8.1 默认路由策略

本项目默认策略：

- `OnlineFirst`

即：

1. 先检查在线 Provider 是否启用
2. 再检查在线配置是否完整
3. 再尝试在线初始化和请求
4. 在线失败时再按规则回退到离线

## 8.2 回退策略

在线回退到离线的触发条件至少包括：

- Provider 未注册
- 缺少配置
- 账号鉴权失败
- 网络连接失败
- 请求超时
- 服务返回限流
- 服务返回业务错误
- 当前平台不支持该在线 Provider

回退后必须：

- 输出日志
- 广播 `OnRouteChanged`
- 广播 `OnFallbackTriggered`
- 记录失败原因

## 8.3 语音唤醒的特殊说明

语音唤醒从工程常识上更适合本地前置，但本项目当前需求明确为“在线优先”。因此文档按以下规则执行：

- 默认策略仍为 `OnlineFirst`
- 若在线唤醒 Provider 不适合持续监听场景，可在配置中将唤醒能力单独切到 `OfflineFirst`
- 路由策略必须允许按能力分别配置，不能全局一刀切

---

## 9. 功能需求

## 9.1 语音唤醒

首期必须支持：

- 中文唤醒词
- 英文唤醒词
- 自定义唤醒词配置
- 灵敏度配置
- 冷却时间配置
- 持续监听
- 唤醒状态回调
- 在线优先、离线回退

扩展预留：

- 多唤醒词并行
- 指令词模式
- 唤醒词云端下发
- 用户级唤醒词配置

## 9.2 语音识别

首期必须支持：

- 实时流式识别
- 录音文件转写
- 中文识别
- 英文识别
- 中间结果回调
- 最终结果回调
- 热词表
- 在线优先、离线回退

扩展预留：

- 标点恢复
- 数字归一化
- 多说话人
- 中英混说
- 领域词典

## 9.3 文本、语音、录音互转

首期必须支持：

- 麦克风输入 -> 文本
- 录音文件 -> 文本
- 文本 -> 语音
- 文本 -> 音频文件
- 在线音频流 -> 播放
- 离线合成音频 -> 播放

说明：

- “互转”不是单独做一个底层引擎
- 它是 `Recognition + Synthesis + Playback` 的组合工作流
- 组合编排统一放在组件层和 `GenericVoiceFramework`

## 9.4 语音合成

首期必须支持：

- 中文 TTS
- 英文 TTS
- 音色切换
- 语速
- 音量
- 音调
- 流式输出
- 缓存
- 在线优先、离线回退

扩展预留：

- 情感音色
- 长文本自动分段
- 多说话人
- 音素级时间戳

## 9.5 语音播放

首期必须支持：

- 播放本地文件
- 播放在线流式音频
- 播放离线合成音频
- 停止
- 暂停
- 恢复
- 抢占
- 排队
- 背景音 Ducking

扩展预留：

- 字幕同步
- 口型同步
- 音频焦点管理
- 多通道播放策略

---

## 10. 第三方能力选型建议

## 10.1 在线优先推荐

### 10.1.1 在线语音平台主推荐：`火山引擎`

定位：

- 在线语音底层平台主推荐
- 优先承载实时识别、流式识别、文本转语音、数字人口播
- 适合做 `Recognition` 与 `Synthesis` 的主在线 Provider

原因：

- 中文场景能力强
- 支持实时 / 流式接口
- 适合数字人语音交互
- 平台化能力完整，适合统一接入

需要暴露的配置：

- `AppId`
- `AccessToken`
- `SecretKey`
- `Cluster`
- `ResourceId`

推荐模块命名：

- `VoiceRecognitionVolcengine`
- `VoiceSynthesisVolcengine`

### 10.1.2 在线语音平台重点推荐：`科大讯飞`

定位：

- 在线语音重点推荐平台
- 适合语音识别、语音合成、语音唤醒等能力统一接入
- 适合作为在线主链路的重要并行 Provider

需要暴露的配置：

- `AppId`
- `ApiKey`
- `ApiSecret`
- `Host`
- `BusinessId`
- `EngineType`

推荐模块命名：

- `VoiceWakeupXfyun`
- `VoiceRecognitionXfyun`
- `VoiceSynthesisXfyun`

### 10.1.3 在线工作流 / 应用编排推荐：`Dify`

定位：

- 数字人工作流 / Agent / 上层语义编排平台
- 可接入 STT / TTS 接口，也适合做业务流程编排

需要暴露的配置：

- `BaseUrl`
- `ApiKey`
- `ApplicationId`

推荐模块命名：

- `VoiceRecognitionDify`
- `VoiceSynthesisDify`
- `VoiceConversationDify`

### 10.1.4 在线大模型语音 / 对话生态推荐：`豆包`

定位：

- 数字人对话与内容生成平台推荐
- 适合承载对话、语义理解、语音交互生态接入
- 与火山引擎同属火山生态，但在架构上单独保留 Provider 入口

说明：

- `火山引擎` 更偏平台级语音服务接入
- `豆包` 更偏数字人对话、语义与模型服务接入
- 文档中两者分开保留，避免后续产品线耦合

需要暴露的配置：

- `AppId`
- `AccessToken`
- `SecretKey`
- `Cluster`
- `ModelId`
- `ResourceId`

推荐模块命名：

- `VoiceRecognitionDoubao`
- `VoiceSynthesisDoubao`
- `VoiceConversationDoubao`

### 10.1.5 在线中文对话平台推荐：`文心一言`

定位：

- 数字人对话平台接入
- 适用于中文对话、知识问答、业务编排
- 作为中文场景对话平台重点推荐

需要暴露的配置：

- `AppId`
- `ApiKey`
- `SecretKey`
- `AccessToken`
- `ModelId`
- `Endpoint`

推荐模块命名：

- `VoiceConversationWenxin`

### 10.1.6 在线平台推荐结论

在线平台推荐顺序按能力拆分如下：

- 在线语音底层平台优先推荐：`火山引擎`、`科大讯飞`
- 在线语音 / 模型混合生态推荐：`豆包`
- 在线工作流平台推荐：`Dify`
- 在线中文对话平台推荐：`文心一言`

说明：

- `火山引擎` 与 `豆包` 在架构中分别保留入口
- `文心一言` 更偏对话层，不强制作为底层 ASR / TTS 主 Provider
- `Dify` 更偏编排层，可根据接口能力决定是否直接承载 STT / TTS

## 10.2 离线推荐

### 10.2.1 离线统一主栈：`Sherpa-onnx`

定位：

- 唤醒、识别、VAD、TTS 的统一离线主栈
- 作为在线失败时的第一回退方案

原因：

- 能力覆盖面广
- 适合 Unreal C++ 封装
- 更利于在 Windows 和国产 Linux 平台统一离线方案

落地建议：

- `VoiceWakeupSherpaOnnx`
- `VoiceRecognitionSherpaOnnx`
- `VoiceSynthesisSherpaOnnx`

说明：

- 离线 TTS 的首选候选必须优先从 GitHub 开源项目中筛选
- 当前优先候选仍为 `k2-fsa/sherpa-onnx`
- 原因是其同时覆盖 ASR、KWS、VAD、TTS，且更适合统一 Unreal C++ 封装
- 对 Windows、Linux、HarmonyOS、openKylin / 国产 Linux 方向更友好

### 10.2.2 离线唤醒增强备选：`Picovoice Porcupine`

定位：

- 专注唤醒词检测
- 用于对唤醒效果要求更高的场景

注意：

- 需要 `AccessKey`
- 作为唤醒能力离线增强 Provider，不作为全链路底座

### 10.2.3 离线识别备选：`whisper.cpp`

定位：

- 高质量离线转写备选
- 适合录音文件转写与精度优先场景

### 10.2.4 离线轻量备选：`Vosk`

定位：

- 资源受限场景的轻量 ASR 备选

### 10.2.5 国产平台离线合成补充：`百度离线 TTS`

定位：

- 作为国产平台 / 中文离线合成补充方案

注意：

- 需要离线 License、序列号、首次联网鉴权等配置
- 适合作为平台特化 Provider

### 10.2.6 离线 TTS GitHub 选型规则

离线 TTS 不再优先从私有旧插件方案中选型，必须优先从 GitHub 开源项目中筛选候选。

当前推荐候选池如下：

#### 候选 A：`k2-fsa/sherpa-onnx`

定位：

- 离线 TTS 主推荐
- 适合作为首版默认离线 TTS Provider

原因：

- 同一项目内同时覆盖 TTS、ASR、KWS、VAD
- 支持 C / C++ 接入，更适合 Unreal Runtime 集成
- 支持 Windows、Linux、HarmonyOS、openKylin 等多平台方向

推荐模块命名：

- `VoiceSynthesisSherpaOnnx`

#### 候选 B：`rhasspy/piper`

定位：

- 轻量、本地化、离线 TTS 备选
- 适合作为纯 TTS 轻量方案评估

原因：

- GitHub 官方定位为本地神经网络 TTS
- 更适合独立离线 TTS 引擎封装

风险：

- 需要单独评估中文支持质量与 Unreal 集成成本
- 适合作为备选，不默认定为首版主方案

推荐模块命名：

- `VoiceSynthesisPiper`

#### 候选 C：`myshell-ai/MeloTTS`

定位：

- 中英文、多语种离线 TTS 评估候选

原因：

- GitHub 官方说明支持 English、Chinese 等多语种
- 适合做多语种扩展预研

风险：

- 当前实现更偏 Python 生态
- 首版直接嵌入 Unreal Runtime 的工程化成本较高

推荐结论：

- 作为预研候选，不作为首版默认离线 TTS

#### 候选 D：`RVC-Boss/GPT-SoVITS`

定位：

- 高质量音色、克隆、角色语音方向候选

原因：

- 更适合后续数字人个性化音色与角色克隆扩展

风险：

- 更偏模型服务与 Python 推理链路
- 首版工程复杂度高，不适合作为最先落地的基础离线 TTS

推荐结论：

- 作为后续高质量角色音色扩展方向，不作为首版默认离线 TTS

### 10.2.7 离线 TTS 最终建议

离线 TTS 当前结论如下：

1. 首版默认离线 TTS 推荐：`Sherpa-onnx`
2. 轻量离线 TTS 备选：`Piper`
3. 多语种离线 TTS 预研：`MeloTTS`
4. 高质量角色音色扩展：`GPT-SoVITS`

要求：

- 首版落地时至少完成一个 GitHub 离线 TTS 候选的 Unreal 封装
- 不再将旧项目源码直接搬运作为默认离线 TTS 方案
- GitHub 候选选型时优先考虑 Windows、UOS、麒麟 Linux 的可集成性

---

## 11. 配置要求

首版不保留空 Settings 类。没有实际配置项时，直接删除对应 `Settings` 目录和 `UVoiceXXXSettings`。

运行时配置统一走 Component 实例：

- 每个语音 Component 持有自己的 `ProviderConfigs`
- `ProviderConfigs` 使用 `UVoiceProviderConfigDataAsset` 派生 DataAsset
- 一个 Component 可以配置多个 DataAsset
- 使用时按数组顺序选择首个 `ValidateConfig` 通过的配置
- 使用哪套配置、启用哪些语音能力，只取决于 Actor 上挂载了哪些 Component 以及该 Component 上配置了哪些 DataAsset
- Settings 不提供默认 Provider、默认账号、默认功能开关或 DataAsset 列表

要求：

- 火山引擎、科大讯飞、Dify、豆包、文心一言等账号信息必须放在对应 Provider 的 DataAsset 中
- 不允许硬编码账号信息到模块中
- 支持同类 Provider 多套 DataAsset 并可在不同 Component 实例中独立切换
- 未配置或配置校验失败时必须输出明确错误日志

---

## 12. `C:\UEProject\DevProject\Plugins\JC` 参考约束

`C:\UEProject\DevProject\Plugins\JC` 当前存在一批可参考资源，但只能作为 SDK / ThirdParty 资源来源，不能作为源码设计来源。

## 12.1 当前可确认的可用 SDK 参考

目前已确认的 SDK 参考包括：

- `C:\UEProject\DevProject\Plugins\JC\JCVolcEngineService\Source\ThirdParty\VolcEngineRTC`
- `C:\UEProject\DevProject\Plugins\JC\JCMetaHuman\JCXunFeiService\Source\ThirdParty\VoiceWakeUpSdk`

当前未确认存在独立 `ThirdParty / SDK` 资源的其他 `JC` 子插件，如：

- `JCDifyService`
- `JCFunASRService`
- `JCGPTSoVITSService`

在首版中不作为“可直接迁移 SDK 来源”，最多只用于能力清单和接入方向参考。

已观察到的内容类型包括：

- `Build.cs`
- `include`
- `lib`
- `bin`
- `dll`
- `资源文件`

这些内容可以迁移到新的 `GenericVoice` 对应模块中。

## 12.2 允许直接迁移的内容

允许迁移：

- `ThirdParty` 目录下的头文件
- `ThirdParty` 目录下的静态库、动态库、资源文件
- `ThirdParty` 的 `Build.cs`
- SDK 附带的模型、配置模板、运行时资源
- 二进制依赖和运行时依赖列表

推荐迁移方式：

- 迁移到 `VoiceXXXSystem/Source/Online/ThirdParty/...`
- 或迁移到对应的 `VoiceXXXSdk` 模块中

示例：

- `VolcEngineRTC` 迁移到 `VoiceRecognitionSystem` / `VoiceConversationSystem` 对应的在线 SDK 模块
- `VoiceWakeUpSdk` 迁移到 `VoiceWakeupSystem` 对应的唤醒 SDK 模块

## 12.3 明确禁止直接照抄的内容

禁止直接照抄：

- `Public` / `Private` 下的业务源码
- Blueprint Library 设计
- Subsystem 设计
- Component 设计
- Interface 设计
- 日志体系
- 配置类设计
- 业务状态机
- 演示地图
- Content 中的测试资源

要求：

- 源码部分必须基于新的 `GenericVoiceFramework + GenericVoiceXXXFramework + Component + Interface` 架构重新设计
- 可以参考旧插件所接入的 SDK 类型和接入边界，但不能沿用旧插件源码结构

## 12.4 `JC` 目录的使用边界

`C:\UEProject\DevProject\Plugins\JC` 在首版开发期间只作为“临时 SDK 参考池”。

约束如下：

- 首版开发时可从中提取 SDK 和 ThirdParty 资产
- 首版开发时不得继续依赖该目录中的业务源码运行
- 首版能力完成后，所有需要的 SDK 资产必须已经迁移到 `GenericAudio` 自己的模块内
- 首版完成并验证后，删除 `C:\UEProject\DevProject\Plugins\JC`

## 12.5 首版迁移策略建议

建议顺序：

1. 先识别 `JC` 中哪些是纯 SDK、哪些是业务源码
2. 只迁移 SDK 资产到新的 `GenericVoice` 模块
3. 用新架构重新实现 Runtime、Component、Interface、DataAsset、Log
4. 跑通首版功能
5. 删除 `C:\UEProject\DevProject\Plugins\JC`

---

## 13. 日志规范

## 13.1 日志命名规范

日志风格参考现有工程中的：

```cpp
DECLARE_LOG_CATEGORY_EXTERN(GenericLogAuthorization, Log, All);
DEFINE_LOG_CATEGORY(GenericLogAuthorization);
```

语音系统建议至少定义以下日志分类：

```cpp
DECLARE_LOG_CATEGORY_EXTERN(LogVoiceFramework, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogVoiceWakeup, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogVoiceRecognition, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogVoiceSynthesis, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogVoicePlayback, Log, All);
DECLARE_LOG_CATEGORY_EXTERN(LogVoiceConversation, Log, All);
```

如有需要，可继续细分：

- `LogVoiceWakeupOnline`
- `LogVoiceWakeupOffline`
- `LogVoiceRecognitionOnline`
- `LogVoiceRecognitionOffline`
- `LogVoiceSynthesisOnline`
- `LogVoiceSynthesisOffline`

## 13.2 日志覆盖范围

日志必须覆盖：

- 模块加载
- Provider 注册
- 组件初始化
- 配置读取
- 在线鉴权
- 在线请求
- 在线响应
- 离线模型加载
- 路由选择
- 在线回退离线
- 组件状态切换
- 业务回调触发
- 音频格式转换
- 播放状态切换
- 错误码与错误描述
- 请求耗时
- Provider 选择结果

## 13.3 日志字段要求

推荐关键字段：

- `RequestId`
- `SessionId`
- `ComponentName`
- `OwnerName`
- `ProviderName`
- `RoutePolicy`
- `SelectedRoute`
- `FallbackReason`
- `Language`
- `AudioFormat`
- `SampleRate`
- `LatencyMs`
- `ErrorCode`
- `ErrorMessage`

目标：

- 能在日志里完整定位“谁发起的请求、走了哪条路、用了哪个 Provider、为什么回退、在哪一步失败”

---

## 14. 命名规范

统一规则：

- 插件：`GenericVoiceXXXSystem`
- 功能级框架模块：`GenericVoiceXXXFramework`
- SDK 模块：`VoiceXXXSdk`
- 在线模块目录：`Source/Online`
- 离线模块目录：`Source/Offline`
- 在线 Provider：`VoiceRecognitionVolcengine`、`VoiceWakeupXfyun`、`VoiceRecognitionDify`、`VoiceConversationDoubao`、`VoiceConversationWenxin`
- 离线 Provider：`VoiceXXXSherpaOnnx`、`VoiceXXXWhisperCpp`、`VoiceXXXPicovoice`
- 组件：`UVoiceXXXComponent`
- 接口：`UVoiceXXXInterface` / `IVoiceXXXInterface`
- 日志：`LogVoiceXXX`
- 配置：`UVoiceProviderConfigDataAsset` 派生 DataAsset
- 数据：`FVoiceXXXRequest`、`FVoiceXXXResult`

禁止：

- 普通类、函数、结构体、委托、Provider 模块无必要强制添加 `Generic` 前缀
- 同一能力使用多套命名风格
- 把第三方厂商名放到顶层插件名中

---

## 15. 实施优先级

## 15.1 P0

- 完成 `GenericVoiceFramework`
- 完成 `VoiceWakeupSystem`
- 完成 `VoiceRecognitionSystem`
- 完成 `VoiceSynthesisSystem`
- 完成 `VoicePlaybackSystem`
- 完成 `Component + Interface + 完整回调 + 完整日志` 基础框架

## 15.2 P1

- 在线主链路先跑通
- `火山引擎` 在线识别与合成接入
- `科大讯飞` 在线识别、合成与唤醒接入
- `Dify` 在线工作流与可用语音接口接入
- `豆包` 在线语音 / 对话生态接入
- 默认策略设置为 `OnlineFirst`

## 15.3 P2

- `Sherpa-onnx` 离线主栈接入
- `Picovoice Porcupine` 离线唤醒接入
- `whisper.cpp` 离线识别备选接入
- 国产平台 `UOS / 麒麟` 验证

## 15.4 P3

- `VoiceConversationSystem`
- 文心一言链路
- 国产平台特化优化
- 字幕、口型、表情联动扩展

---

## 16. 验收标准

### 16.1 架构验收

- 不存在按在线 / 离线拆分的重复插件
- `GenericVoiceFramework` 仅承载全局共享能力
- 每个能力插件内部存在自己的 `GenericVoiceXXXFramework`
- 所有命名统一为 `GenericXXX`

### 16.2 路由验收

- 默认在线优先
- 在线成功时不走离线
- 在线失败时可按配置回退到离线
- 回退事件、回退日志、回退原因完整可见

### 16.3 组件验收

- 所有能力可通过 `Component` 挂载使用
- 组件支持 Blueprint 调用
- 组件支持 C++ 扩展
- 组件支持 Interface 回调

### 16.4 回调验收

- 不能只有 `Success / Failed`
- 必须具备初始化、开始、过程、切换、结束、错误等完整事件
- Blueprint 和 C++ 两端都能使用

### 16.5 日志验收

- 每个能力独立日志分类
- 关键路径有完整日志
- 在线 / 离线 / 回退链路可在日志中完整还原

### 16.6 平台验收

- Windows 首期可用
- `UOS / 麒麟` 优先验证
- 中文 / 英文首期可用

---

## 17. 最终结论

本方案最终确定如下：

1. 同一能力不再拆分在线插件和离线插件，统一保持一个能力一个插件。
2. 在线和离线在同一插件内部按模块拆分，至少包含 `Framework`、`Sdk`、`Online`、`Offline`、`Provider` 等层。
3. `GenericVoiceFramework` 只负责全 Voice 通用能力；每个功能插件内部再定义自己的 `GenericVoiceXXXFramework`。
4. 系统默认策略改为 `OnlineFirst`，在线可用时优先在线，失败后再回退离线。
5. 国产平台优先级明确为 `UOS / 麒麟` 优先。
6. 所有成品统一以 `Component` 形式挂载，以 `Interface` 形式扩展和回调，并提供完整事件。
7. 日志体系必须参考 `GenericLogAuthorization` 风格，做到“可定位、可回放、可调试”。
8. 所有命名统一采用 `GenericXXX` 风格，不引入额外命名体系。
9. 离线 TTS 首版优先从 GitHub 开源项目中选型，当前默认优先评估 `Sherpa-onnx`，并保留 `Piper`、`MeloTTS`、`GPT-SoVITS` 的后续扩展空间。
10. `C:\UEProject\DevProject\Plugins\JC` 仅作为首版开发期间的临时 SDK 参考池，只允许迁移 SDK / ThirdParty 资产，不允许照抄业务源码；首版完成并完成迁移后删除该目录。

这份文档可直接作为 `GenericAudio` 后续插件拆分、模块搭建、类命名、日志规范、组件封装和平台接入的执行依据。
