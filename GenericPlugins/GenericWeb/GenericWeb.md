# GenericWeb 简化说明

## 当前结构

`GenericWeb` 现在只保留两层：

- `GenericWebFramework`
  - 放共享类型、基础 Widget、日志
  - 放第三方依赖 `Source/ThirdParty/CefViewCore`
- `GenericWebBrowser`
  - 放 Web 展示实现
  - 蓝图主要只使用 `GenericWebBrowserWidget`

`GenericWebWindow` 已移除，不再作为独立插件存在。

## 设计原则

- 不再保留多后端切换、工厂、统一调度、子系统封装这类抽象层
- 不再保留地址栏、前进后退、DevTools、Query/Event 桥等与“在 UE 中展示 Web”无关的蓝图入口
- Widget 侧只保留基础加载、刷新、停止、执行脚本、可见性控制
- CEF 相关全局配置统一使用 `GenericWebBrowserCore` 中的 `UCefSettings`

## Framework 职责

`GenericWebFramework` 当前只保留：

- `GenericWebTypes`
- `GenericWebWidgetBase`
- `GenericWebFramework` 模块日志
- `Source/ThirdParty/CefViewCore`

已经移除：

- `GenericWebSettings`
- `GenericWebView`
- `GenericWebViewFactory`
- `GenericWebSubsystem`
- `GenericWebBlueprintLibrary`

## Browser 职责

`GenericWebBrowser` 当前保留：

- `GenericWebBrowserWidget`
- `FGenericWebBrowserViewSettings`
- `GenericWebBrowserCore`

其中运行时真正生效的浏览器全局设置类是：

- `UCefSettings` (`GenericWebBrowserCore`)

旧的 `GenericWebBrowserContext`、`GenericWebBrowserEvent`、`GenericWebBrowserQuery` 已删除，
对应兼容重定向直接落到 `GenericWebBrowserCore` 中的 `UCefContext`、`UCefViewEvent`、`UCefViewQuery`。

## 兼容策略

为兼容旧资源，当前保留这些重定向：

- `CBWebView2Widget` -> `GenericWebBrowserWidget`
- `GenericWebWindowWidget` -> `GenericWebBrowserWidget`
- `GenericWebView` -> `GenericWebBrowserWidget`
- `WebView2Settings` / `GenericWebWindowSettings` / `UCefView.CefSettings` -> `UCefSettings`

## 结果

当前目标很明确：

- `Framework` 只承载共享层
- `Browser` 只承载 Web 展示实现
- 蓝图里主要只使用 `GenericWebBrowserWidget`
