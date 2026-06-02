// Copyright ChenTaiye 2025. All Rights Reserved.

#include "MediaType.h"

// 与 MediaType.h 中声明的播放事件通道保持一一对应，供 GameplayMessage 监听方按事件类型订阅。
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_Media, "GameplayMessage.Channel.Media");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_Media_OnPlay, "GameplayMessage.Channel.Media.OnPlay");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_Media_OnPlayReverse, "GameplayMessage.Channel.Media.OnPlayReverse");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_Media_OnPause, "GameplayMessage.Channel.Media.OnPause");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_Media_OnStop, "GameplayMessage.Channel.Media.OnStop");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_Media_OnSeek, "GameplayMessage.Channel.Media.OnSeek");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_Media_OnFinish, "GameplayMessage.Channel.Media.OnFinish");
