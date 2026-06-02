#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"

/** 管理 GenericSlateFramework 的全局样式集，为编辑器工具栏和 Slate 控件提供统一图标资源。 */
class GENERICSLATEFRAMEWORK_API FGenericSlateStyle
{
public:
	/** 在模块启动时注册样式集，使工具栏、页签和控件可以通过样式名读取图标。 */
	static void Initialize();

	/** 在模块卸载时注销样式集，避免 Slate 继续持有插件资源引用。 */
	static void ShoutDown();

	/** 返回已经注册的样式集实例，供需要直接读取画刷的代码复用。 */
	static const ISlateStyle& Get();

	static void Set(const FName& PropertyName, FSlateBrush* Brush);

	/** 返回样式集名称，供 FSlateIcon 等轻量入口按名称绑定图标。 */
	static FName GetStyleSetName() { return StyleSetName; }

public:
	/** 承载插件资源目录和具体画刷映射的 Slate 样式集实现。 */
	class FStyle : public FSlateStyleSet
	{
	public:
		FStyle();
		virtual ~FStyle() override;

		/** 绑定插件 Resources 目录并注册 GenericFramework 编辑器入口使用的图标。 */
		void Initialize();
	};

	/** 创建并初始化样式集实例，供模块启动阶段注册到 SlateStyleRegistry。 */
	static TSharedRef<class FGenericSlateStyle::FStyle> Create();

private:
	/** 缓存当前注册到 Slate 的样式集实例，生命周期跟随 GenericSlateFramework 模块。 */
	static TSharedPtr<class FGenericSlateStyle::FStyle> Instance;

	static bool bIsRegistered;

	/** 保存样式集的稳定名称，所有外部 FSlateIcon 都通过该名称查找图标。 */
	static FName StyleSetName;
};
