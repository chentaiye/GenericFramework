// Copyright ChenTaiye 2026. All Rights Reserved.

#include "Route/VoiceRouteResolver.h"

TArray<FVoiceProviderRouteCandidate> FVoiceRouteResolver::BuildCandidates(const EVoiceRoutePolicy InPolicy, const FName InOnlineProvider, const FName InOfflineProvider)
{
	TArray<FVoiceProviderRouteCandidate> Output;

	auto AddCandidate = [&Output](const EVoiceRouteSource InRouteSource, const FName InProviderName)
	{
		if (InProviderName.IsNone())
		{
			return;
		}

		FVoiceProviderRouteCandidate Candidate;
		Candidate.RouteSource = InRouteSource;
		Candidate.ProviderName = InProviderName;
		Output.Add(Candidate);
	};

	switch (InPolicy)
	{
	case EVoiceRoutePolicy::OnlineFirst:
		AddCandidate(EVoiceRouteSource::Online, InOnlineProvider);
		AddCandidate(EVoiceRouteSource::Offline, InOfflineProvider);
		break;

	case EVoiceRoutePolicy::OfflineFirst:
		AddCandidate(EVoiceRouteSource::Offline, InOfflineProvider);
		AddCandidate(EVoiceRouteSource::Online, InOnlineProvider);
		break;

	case EVoiceRoutePolicy::OnlineOnly:
		AddCandidate(EVoiceRouteSource::Online, InOnlineProvider);
		break;

	case EVoiceRoutePolicy::OfflineOnly:
		AddCandidate(EVoiceRouteSource::Offline, InOfflineProvider);
		break;

	case EVoiceRoutePolicy::Hybrid:
	default:
		AddCandidate(EVoiceRouteSource::Online, InOnlineProvider);
		AddCandidate(EVoiceRouteSource::Offline, InOfflineProvider);
		break;
	}

	return Output;
}

bool FVoiceRouteResolver::AllowsFallback(const EVoiceRoutePolicy InPolicy)
{
	return InPolicy == EVoiceRoutePolicy::OnlineFirst
		|| InPolicy == EVoiceRoutePolicy::OfflineFirst
		|| InPolicy == EVoiceRoutePolicy::Hybrid;
}
