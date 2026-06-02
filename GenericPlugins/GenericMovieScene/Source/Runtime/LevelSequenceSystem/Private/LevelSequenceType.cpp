// Copyright ChenTaiye 2025. All Rights Reserved.

#include "LevelSequenceType.h"

// 与 LevelSequenceType.h 中声明的播放事件通道保持一一对应，供 GameplayMessage 监听方按事件类型订阅。
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_LevelSequence, "GameplayMessage.Channel.LevelSequence");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_LevelSequence_OnPlay, "GameplayMessage.Channel.LevelSequence.OnPlay");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_LevelSequence_OnPlayReverse, "GameplayMessage.Channel.LevelSequence.OnPlayReverse");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_LevelSequence_OnPause, "GameplayMessage.Channel.LevelSequence.OnPause");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_LevelSequence_OnStop, "GameplayMessage.Channel.LevelSequence.OnStop");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_LevelSequence_OnSeek, "GameplayMessage.Channel.LevelSequence.OnSeek");
UE_DEFINE_GAMEPLAY_TAG(TAG_GameplayMessage_Channel_LevelSequence_OnFinish, "GameplayMessage.Channel.LevelSequence.OnFinish");
