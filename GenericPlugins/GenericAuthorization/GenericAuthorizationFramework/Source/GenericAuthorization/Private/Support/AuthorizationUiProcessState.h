#pragma once

namespace AuthorizationUiProcessState
{
	/** 查询启动守卫的阻塞授权提示是否正在显示，运行中子系统用它避免重复弹出授权 UI。 */
	bool IsStartupPromptVisible();

	/** 同步启动守卫授权提示的可见状态，供其他授权 UI 流程判断是否需要抑制自身弹窗。 */
	void SetStartupPromptVisible(bool bVisible);

	/** 查询授权流程是否已经请求进程退出，子系统据此停止提示、通知和暂停干预。 */
	bool IsProcessExitRequested();

	/** 保存授权流程已请求退出这一进程级状态，启动守卫和运行中子系统用它收敛退出路径。 */
	void RequestProcessExit();

	/** 清除授权退出标记，供需要重新进入授权流程的测试或新进程生命周期重新初始化使用。 */
	void ResetProcessExitRequest();
}
