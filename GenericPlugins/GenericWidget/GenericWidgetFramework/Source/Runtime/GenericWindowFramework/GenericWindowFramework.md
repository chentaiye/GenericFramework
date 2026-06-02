# GenericWindowFramework 重构说明

## 目标

`GenericWindowFramework` 模块采用完全重构方案，不兼容旧的 `Wrapper / Content / ViewModel` 设计。

核心目标如下：
1. 窗口外壳使用 `UWidget` 体系，而不是把窗口主体做成 `UUserWidget`。
2. 窗口创建时固定拖拽策略，运行时不允许再切换。
3. `InViewportOnly` 使用游戏视口宿主，`AllowOutOfViewport` 使用原生 `SWindow` 宿主。
4. `AllowOutOfViewport` 在创建时直接决定为原生窗口模式，不做拖拽过程中的宿主切换。
5. 两种宿主链路共用同一套窗口 UI，本体内容实例不替换。
6. 支持拖拽、边缘缩放、标题栏双击最大化/还原。
7. 游戏内窗口最小化后只保留标题栏；原生窗口最小化/最大化/还原走系统窗口行为。
8. 样式类入口只保留两个：
   - `WindowTitleBarClass`
   - `WindowContentClass`
9. `WindowTitleBar` 内部通过 `BindWidgetOptional` 组织图标、标题位、按钮等内容。

## 当前实现

### 1. 外壳

- `UGenericWindowWidget : UWidget`

职责：
- 窗口主入口。
- 持有 `Descriptor` 和 `RuntimeState`。
- 对外暴露 Blueprint API。
- 在 `RebuildWidget` 中生成 `SGenericWindowFrame`。
- 不接收任何子项，内容区完全由 `WindowContentClass` 决定。
- 只能通过 `CreateWindow` 创建，或作为 `GenericWindowAnchor` 的唯一子项使用。

### 2. Slate 核心

- `SGenericWindowFrame`

职责：
- 承载窗口标题栏和内容区。
- 处理窗口框架刷新和内容区折叠显示。
- 复用同一套 Slate 布局给视口宿主和原生宿主。

### 3. 宿主

- `FGenericInGameWindowHost`
- `FGenericNativeWindowHost`
- `IGenericWindowHost`

职责：
- `FGenericInGameWindowHost` 将窗口挂到游戏视口层，负责视口内位置、尺寸和 ZOrder。
- `FGenericNativeWindowHost` 以原生 `SWindow` 承载同一套窗口内容，负责桌面级位置、尺寸和系统窗口状态。
- `IGenericWindowHost` 统一抽象打开、关闭、置顶、布局失效、最小化、最大化、还原和状态同步接口。

### 4. 数据对象

- `UGenericWindowDescriptor`
- `UGenericWindowRuntimeState`

其中：
- `Descriptor` 保存静态创建参数。
- `RuntimeState` 保存运行时位置、尺寸、可见区域和窗口状态。

## 两个样式类入口

### 1. WindowTitleBar

- 类型：`TSubclassOf<UGenericWindowTitleBar>`
- 配置字段：`WindowTitleBarClass`

`UGenericWindowTitleBar` 继承自 `UGenericWidget`，用于承载整个顶部栏。

内部约定使用 `BindWidgetOptional` 管理这些可选控件：
- `WindowIcon`
- `WindowTitle`
- `WindowMinimizeButton`
- `WindowMaximizeButton`
- `WindowCloseButton`

类型约束：
- `WindowIcon` 必须是 `UGenericWidget`
- `WindowTitle` 必须是 `UGenericWidget`
- `WindowMinimizeButton` 必须是 `UGenericButtonWidget`
- `WindowMaximizeButton` 必须是 `UGenericButtonWidget`
- `WindowCloseButton` 必须是 `UGenericButtonWidget`

其中：
- 非按钮内容由蓝图自行设计。
- 按钮显隐由窗口参数驱动。
- 按钮点击事件由 `UGenericWindowWidget` 自动绑定。

### 2. WindowContent

- 类型：`TSubclassOf<UGenericWindowContent>`
- 配置字段：`WindowContentClass`

`UGenericWindowContent` 继承自 `UGenericWidget`，用于承载整个内容区外观层。

职责：
- 负责内容区背景、边框、留白和业务布局。
- 作为唯一内容区入口，不再叠加额外子内容。
- 支持内容区边缘缩放命中。

## 拖拽策略

枚举：

```cpp
UENUM(BlueprintType)
enum class EGenericWindowDragPolicy : uint8
{
    InViewportOnly,
    AllowOutOfViewport
};
```

规则：
- `InViewportOnly`：窗口创建后挂在游戏视口宿主，位置限制在游戏视口内。
- `AllowOutOfViewport`：窗口创建后直接使用原生 `SWindow` 宿主，可拖拽到游戏窗口外继续显示。
- 两种模式共用同一套 `UGenericWindowWidget + SGenericWindowFrame + WindowTitleBar + WindowContent` UI。
- 创建后策略锁定，运行时不能切换宿主。

## 标题栏与窗口行为

标题栏规则：
- 标题栏高度由 `WindowTitleBar` 蓝图自身布局决定。
- 双击标题栏时，如 `bDoubleClickTitleBarToToggleMaximize = true`，则切换最大化/还原。

按钮规则：
- `bShowMinimizeButton`
- `bShowMaximizeButton`
- `bShowCloseButton`

窗口行为规则：
- `InViewportOnly`：最小化只折叠内容区，保留顶部栏；最大化铺满当前可用视口区域。
- `AllowOutOfViewport`：最小化 / 最大化 / 还原直接对接原生 `SWindow` 系统行为。
- 关闭：关闭窗口并从当前宿主移除。

## Blueprint 可调参数

当前保留的关键蓝图参数：
- `DragPolicy`
- `bCanDragWindow`
- `bDragAnywhere`
- `bCanResizeWindow`
- `bCanCloseWindow`
- `bCanMinimizeWindow`
- `bCanMaximizeWindow`
- `bShowCloseButton`
- `bShowMinimizeButton`
- `bShowMaximizeButton`
- `bDoubleClickTitleBarToToggleMaximize`
- `TitleBarPadding`
- `ClientAreaPadding`
- `ResizeBorderThickness`
- `MinWindowWidth`
- `MinWindowHeight`
- `MaxWindowWidth`
- `MaxWindowHeight`
- `InitialRect`
- `InitialZOrder`
- `InitialDisplayState`
- `WindowTitleBarClass`
- `WindowContentClass`

## Anchor 模式

- `UGenericWindowAnchor : UContentWidget`
- `UGenericWindowSlot`

规则：
- `GenericWindowAnchor` 只能放一个子项。
- 子项只能是 `UGenericWindowWidget`。
- `WindowAnchor` 用于标识窗口逻辑矩形相对 Anchor 的对齐点。
- Anchor 负责在 UMG 设计器和运行时中刷新窗口预览位置和尺寸。

## 当前类关系

```text
UGenericWindowWidget
        |
        v
SGenericWindowFrame
        |
        +--------------------+
        |                    |
        v                    v
WindowTitleBar         WindowContent
        |
        v
UGenericButtonWidget / UGenericWidget / 蓝图自定义内容
```

## 验收标准

1. 窗口主体入口是 `UGenericWindowWidget`，不是 `UUserWidget`。
2. `Descriptor` 的样式类入口只有 `WindowTitleBarClass` 和 `WindowContentClass`。
3. `WindowTitleBar` 内部通过 `BindWidgetOptional` 管理图标、标题位、最小化、最大化、关闭按钮。
4. `InViewportOnly` 和 `AllowOutOfViewport` 在创建时决定宿主类型，运行时不切换。
5. `AllowOutOfViewport` 使用原生 `SWindow` 宿主，但不替换窗口内容实例。
6. 两种模式的窗口 UI 结构一致。
7. 标题栏双击可切换最大化/还原。
8. 游戏内窗口最小化后只保留标题栏。
9. 原生窗口最小化 / 最大化 / 还原走系统窗口行为。
10. 整个模块已按该结构在 `GenericWindowFramework` 中实现。
