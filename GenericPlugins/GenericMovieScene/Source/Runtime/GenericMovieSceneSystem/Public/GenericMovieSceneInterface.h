// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GenericMovieSceneInterface.generated.h"

class UGenericWidget;

/** 将电影场景播放契约接入 UObject 反射体系，使媒体、Bink 与关卡序列句柄能共享同一组控制入口。 */
UINTERFACE(MinimalAPI)
class UGenericMovieSceneInterface : public UInterface
{
	GENERATED_BODY()
};

/** 定义电影场景控制接口，默认实现把播放、关闭、跳转等操作转发到受保护的状态钩子。 */
class GENERICMOVIESCENESYSTEM_API IGenericMovieSceneInterface
{
	GENERATED_BODY()

public:
	/** 进入电影场景打开阶段；基类只触发打开钩子，具体句柄负责先完成底层资源打开。 */
	virtual void OpenMovieScene();

	/** 进入电影场景关闭阶段，供句柄统一触发事件解绑、资源释放和关闭广播。 */
	virtual void CloseMovieScene();

	/** 启动当前播放位置的正向播放，并通过播放钩子通知公共句柄事件。 */
	virtual bool PlayMovieScene();

	/** 从起始位置重新播放，具体实现会先重置底层播放器或序列时间。 */
	virtual bool PlayMovieSceneFromStart();

	/** 以指定循环次数播放，媒体实现维护剩余次数，序列实现同步 PlaybackSettings。 */
	virtual bool PlayLoopingMovieScene(int32 NumLoops = -1);

	/** 请求反向播放，支持的实现会映射到底层负速率或 Sequencer 反向播放。 */
	virtual bool PlayReverseMovieScene();

	/** 暂停当前电影场景，并通过暂停钩子同步上层事件。 */
	virtual bool PauseMovieScene();

	/** 停止当前电影场景，具体实现会清理循环状态并回到安全时间点。 */
	virtual bool StopMovieScene();

	/** 将电影场景跳转到指定时间码，成功后由实现触发跳转钩子。 */
	virtual bool SeekMovieScene(FTimecode SeekTime);

	/** 切换播放方向的扩展点；不支持反向播放的实现可以保持空操作或写入诊断日志。 */
	virtual void ChangeMovieSceneDirection() { return; }

	/** 查询底层播放对象是否正在播放，默认 false 让未绑定资源的句柄安全失败。 */
	virtual bool IsPlaying() { return false; }

	/** 查询当前播放请求是否处于循环语义，默认 false 适配未初始化句柄。 */
	virtual bool IsLooping() { return false; }

	/** 查询底层播放对象是否暂停，默认 false 适配没有播放器的接口实例。 */
	virtual bool IsPaused() { return false; }

	/** 查询当前播放方向是否为反向，默认 false 说明接口层不假定反向能力。 */
	virtual bool IsReversed() { return false; }

	/** 返回统一时间码形式的当前播放位置，供媒体和序列句柄暴露给蓝图侧。 */
	virtual FTimecode GetCurrentTime() { return FTimecode(); }

	/** 返回统一时间码形式的总时长，未绑定播放对象时返回空时间码。 */
	virtual FTimecode GetDuration() { return FTimecode(); }

	/** 返回当前时间码换算使用的帧率，具体实现会从媒体轨道或序列播放器读取。 */
	virtual FFrameRate GetFrameRate() { return FFrameRate(); }

	/** 调整底层播放对象使用的帧率，默认空实现避免接口层持有播放状态。 */
	virtual void SetFrameRate(FFrameRate FrameRate) { return; }

	/** 返回底层播放器当前速率，默认 1.0 保持普通正向播放语义。 */
	virtual float GetPlayRate() { return 1.f; }

	/** 设置底层播放器速率，具体实现负责处理不支持的速率或暂停语义。 */
	virtual void SetPlayRate(float InPlayRate) { return; }

protected:
	/** 打开成功后的内部钩子，公共句柄在这里向蓝图广播打开后的状态变化。 */
	virtual void OnMovieSceneOpened() { return; }

	/** 关闭后的内部钩子，具体句柄在这里解除底层委托并清空缓存对象。 */
	virtual void OnMovieSceneClosed() { return; }

	/** 播放开始后的内部钩子，公共句柄据此广播播放事件。 */
	virtual void OnMovieScenePlay() { return; }

	/** 反向播放开始后的内部钩子，公共句柄据此广播反向播放事件。 */
	virtual void OnMovieScenePlayReverse() { return; }

	/** 暂停后的内部钩子，公共句柄据此广播暂停事件。 */
	virtual void OnMovieScenePause() { return; }

	/** 停止后的内部钩子，公共句柄据此广播停止事件。 */
	virtual void OnMovieSceneStop() { return; }

	/** 跳转完成后的内部钩子，公共句柄据此广播时间跳转事件。 */
	virtual void OnMovieSceneSeek() { return; }

	/** 播放自然结束后的内部钩子，媒体循环耗尽或序列完成时会走到这里。 */
	virtual void OnMovieScenePlayFinish() { return; }
};
