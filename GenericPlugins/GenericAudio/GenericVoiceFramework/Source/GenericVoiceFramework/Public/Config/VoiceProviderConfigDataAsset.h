// Copyright ChenTaiye 2026. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VoiceTypes.h"
#include "VoiceProviderConfigDataAsset.generated.h"

/** 配置语音提供器配置。 */
UCLASS(MinimalAPI, Abstract, BlueprintType)
class UVoiceProviderConfigDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	/** 是否启用提供器配置。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Provider")
	bool bEnableProviderConfig=true;

	/** 提供器名称。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Provider")
	FName ProviderName=NAME_None;

	/** 配置路由来源。 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Voice|Provider")
	EVoiceRouteSource RouteSource=EVoiceRouteSource::None;

	/** 校验 Block 映射配置。 */
	GENERICVOICEFRAMEWORK_API virtual bool ValidateConfig(FString& OutMessage) const;

	/** 判断匹配Provider，让调用方按结果选择后续路径。 */
	GENERICVOICEFRAMEWORK_API bool MatchesProvider(FName InProviderName, EVoiceRouteSource InRouteSource) const;

	/** 查找First有效配置。 */
	static GENERICVOICEFRAMEWORK_API const UVoiceProviderConfigDataAsset* FindFirstValidConfig(
		const TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>>& InConfigs,
		FName InProviderName,
		EVoiceRouteSource InRouteSource,
		FString& OutMessage);

	/** 查找First有效Typed配置。 */
	template <typename ConfigType>
	static const ConfigType* FindFirstValidTypedConfig(
		const TArray<TSoftObjectPtr<UVoiceProviderConfigDataAsset>>& InConfigs,
		FName InProviderName,
		EVoiceRouteSource InRouteSource,
		FString& OutMessage)
	{
		/** 记录Last消息。 */
		FString LastMessage = FString::Printf(TEXT("No valid provider config found. Provider=%s Route=%d"),
			*InProviderName.ToString(),
			static_cast<int32>(InRouteSource));

		for (const TSoftObjectPtr<UVoiceProviderConfigDataAsset>& ConfigPtr : InConfigs)
		{
			/** 加载Synchronous。 */
			const UVoiceProviderConfigDataAsset* BaseConfig = ConfigPtr.LoadSynchronous();

			/** 配置Typed配置。 */
			const ConfigType* TypedConfig = Cast<ConfigType>(BaseConfig);
			if (TypedConfig == nullptr || !TypedConfig->MatchesProvider(InProviderName, InRouteSource))
			{
				/** 配置continue。 */
				continue;
			}

			/** 配置Validation消息。 */
			FString ValidationMessage;
			if (TypedConfig->ValidateConfig(ValidationMessage))
			{
				/** 配置Out消息。 */
				OutMessage = ValidationMessage;
				return TypedConfig;
			}

			/** 配置上次消息。 */
			LastMessage = ValidationMessage;
		}

		/** 配置Out消息。 */
		OutMessage = LastMessage;
		return nullptr;
	}
};
