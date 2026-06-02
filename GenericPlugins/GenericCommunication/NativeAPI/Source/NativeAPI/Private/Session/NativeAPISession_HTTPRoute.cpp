// Copyright ChenTaiye 2025. All Rights Reserved.

#include "NativeAPISession_HTTPRoute.h"
#include "Engine/Engine.h"
#include "HttpServerModule.h"
#include "IHttpRouter.h"
#include "Misc/EngineVersionComparison.h"
#include "NativeAPISubsystem.h"
#include "NativeAPITypes.h"
#include "NativeAPIUtilities.h"
#include "Settings/NativeAPIWorldSettings.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

namespace
{
	const UNativeAPIWorldSettings* GetActiveNativeAPIWorldSettings()
	{
		const UNativeAPISubsystem* NativeAPISubsystem = GEngine ? GEngine->GetEngineSubsystem<UNativeAPISubsystem>() : nullptr;
		return NativeAPISubsystem ? NativeAPISubsystem->GetActiveWorldSettings() : nullptr;
	}
}

FName FNativeAPISession_HTTPRoute::GetSessionName()
{
	static FName SessionName(TEXT("HTTPRoute"));
	return SessionName;
}

bool FNativeAPISession_HTTPRoute::StartSession()
{
	const UNativeAPIWorldSettings* Settings = GetActiveNativeAPIWorldSettings();
	if (Settings == nullptr)
	{
		return false;
	}

	if (!Settings->bSupportHTTPRoute)
	{
		return false;
	}

	if (HttpRouter.IsValid() && RouteHandle.IsValid())
	{
		return true;
	}

	FHttpServerModule& HttpServerModule = FHttpServerModule::Get();
	HttpRouter = FHttpServerModule::Get().GetHttpRouter(Settings->HTTPRoutePort);

	if (!HttpRouter.IsValid())
	{
		return false;
	}

	const FHttpPath HttpPath(TEXT("/NativeAPI"));

	const auto RouteHandlerLambda = [this](const FHttpServerRequest& Request, const FHttpResultCallback& OnComplete) -> bool
		{
			const FString JsonString(Request.Body.Num(), UTF8_TO_TCHAR(Request.Body.GetData()));

			TUniquePtr<FHttpServerResponse> Response = FHttpServerResponse::Create(TEXT("NativeAPIResponse"), TEXT("application/json"));

			TSharedPtr<FJsonObject> JsonObject;
			const TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonString);

			FNativeAPIPayload Payload;
			if (!FJsonSerializer::Deserialize(JsonReader, JsonObject) || !JsonObject.IsValid())
			{
				Response->Code = EHttpServerResponseCodes::BadRequest;
			}
			else if (FNativeAPIUtilities::ConvertNativeAPIJsonToPayload(JsonObject, Payload) && Payload.IsValid())
			{
				NotifyReceiveNativePayload(Payload);
				Response->Code = EHttpServerResponseCodes::Ok;
			}

			OnComplete(MoveTemp(Response));
			return true;
		};

#if UE_VERSION_OLDER_THAN(5, 4, 0)
	const FHttpRequestHandler ThisHandler(RouteHandlerLambda);
#else
	const FHttpRequestHandler ThisHandler = FHttpRequestHandler::CreateLambda(RouteHandlerLambda);
#endif

	// 路由路径
	RouteHandle = HttpRouter->BindRoute(HttpPath, EHttpServerRequestVerbs::VERB_POST, ThisHandler);

	HttpServerModule.StartAllListeners();
	return true;
}

void FNativeAPISession_HTTPRoute::EndSession()
{
	if (HttpRouter.IsValid() && RouteHandle.IsValid())
	{
		HttpRouter->UnbindRoute(RouteHandle);
	}

	RouteHandle.Reset();
	HttpRouter.Reset();
}
