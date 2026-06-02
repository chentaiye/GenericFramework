// Copyright ChenTaiye 2025. All Rights Reserved. 

#include "NetworkPlayerState.h"

#include "GenericSessionSubsystem.h"
#include "Net/OnlineEngineInterface.h"

void ANetworkPlayerState::BeginPlay()
{
	Super::BeginPlay();
}

void ANetworkPlayerState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void ANetworkPlayerState::RegisterPlayerWithSession(bool bWasFromInvite)
{
	// Super::RegisterPlayerWithSession(bWasFromInvite);

	/** 从会话子系统缓存的句柄回填 SessionName，使后续注册使用框架创建会话时的自定义名称。 */
	if (UGenericSessionSubsystem* GenericSessionSubsystem = UGenericSessionSubsystem::Get(this))
	{
		FGenericSessionHandle SessionHandle;
		GenericSessionSubsystem->GetSessionHandle(GetUniqueId(), SessionHandle);

		if (SessionHandle.CheckIsValid())
		{
			SessionName = SessionHandle.SessionName;
		}
	}

	/** 使用同步后的自定义会话名注册玩家，避免父类默认 GameSession 名称覆盖框架会话上下文。 */
	if (GetNetMode() != NM_Standalone)
	{
		if (GetUniqueId().IsValid())
		{
			if (UOnlineEngineInterface::Get()->DoesSessionExist(GetWorld(), SessionName))
			{
				UOnlineEngineInterface::Get()->RegisterPlayer(GetWorld(), SessionName, GetUniqueId(), bWasFromInvite);
			}
		}
	}
}

void ANetworkPlayerState::UnregisterPlayerWithSession()
{
	// Super::UnregisterPlayerWithSession();

	if (GetNetMode() == NM_Client && GetUniqueId().IsValid())
	{
		if (SessionName != NAME_None)
		{
			if (UOnlineEngineInterface::Get()->DoesSessionExist(GetWorld(), SessionName))
			{
				UOnlineEngineInterface::Get()->UnregisterPlayer(GetWorld(), SessionName, GetUniqueId());
			}
		}
	}
}
