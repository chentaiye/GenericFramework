// Copyright ChenTaiye 2026. All Rights Reserved.

#include "HomeAssistantPlatformAdapter.h"

#include "IOTPlatformHomeAssistant.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonWriter.h"
#include "Subsystem/IOTSubsystem.h"

namespace
{
	FString ToCompactJsonString(const TSharedPtr<FJsonObject>& InObject)
	{
		if (!InObject.IsValid())
		{
			return FString();
		}

		FString Output;
		TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Output);
		FJsonSerializer::Serialize(InObject.ToSharedRef(), Writer);
		return Output;
	}

	FString JsonValueToString(const TSharedPtr<FJsonValue>& InValue)
	{
		if (!InValue.IsValid())
		{
			return FString();
		}

		switch (InValue->Type)
		{
		case EJson::String:
			return InValue->AsString();
		case EJson::Number:
			return FString::SanitizeFloat(InValue->AsNumber());
		case EJson::Boolean:
			return InValue->AsBool() ? TEXT("true") : TEXT("false");
		case EJson::Null:
			return TEXT("null");
		case EJson::Array:
		{
			FString Output;
			TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&Output);
			FJsonSerializer::Serialize(InValue->AsArray(), Writer);
			return Output;
		}
		case EJson::Object:
			return ToCompactJsonString(InValue->AsObject());
		default:
			break;
		}

		return FString();
	}

	FString GetJsonFieldAsString(const TSharedPtr<FJsonObject>& InObject, const FString& InFieldName)
	{
		if (!InObject.IsValid())
		{
			return FString();
		}

		const TSharedPtr<FJsonValue>* Value = InObject->Values.Find(InFieldName);
		if (!Value || !Value->IsValid())
		{
			return FString();
		}

		return JsonValueToString(*Value);
	}

	TSharedPtr<FJsonObject> GetJsonObjectField(const TSharedPtr<FJsonObject>& InObject, const FString& InFieldName)
	{
		if (!InObject.IsValid() || !InObject->HasTypedField<EJson::Object>(InFieldName))
		{
			return nullptr;
		}

		return InObject->GetObjectField(InFieldName);
	}

	bool TryParseJsonObject(const FString& InPayload, TSharedPtr<FJsonObject>& OutObject)
	{
		OutObject.Reset();
		if (InPayload.IsEmpty())
		{
			return false;
		}

		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InPayload);
		return FJsonSerializer::Deserialize(Reader, OutObject) && OutObject.IsValid();
	}

	bool TryParseJsonArray(const FString& InPayload, TArray<TSharedPtr<FJsonValue>>& OutArray)
	{
		OutArray.Reset();
		if (InPayload.IsEmpty())
		{
			return false;
		}

		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(InPayload);
		return FJsonSerializer::Deserialize(Reader, OutArray);
	}

	TArray<FString> GetJsonStringArray(const TSharedPtr<FJsonObject>& InObject, const FString& InFieldName)
	{
		TArray<FString> Result;
		if (!InObject.IsValid())
		{
			return Result;
		}

		const TArray<TSharedPtr<FJsonValue>>* Values = nullptr;
		if (!InObject->TryGetArrayField(InFieldName, Values) || !Values)
		{
			return Result;
		}

		for (const TSharedPtr<FJsonValue>& Value : *Values)
		{
			Result.Add(JsonValueToString(Value));
		}

		return Result;
	}

	double GetJsonNumberOrDefault(const TSharedPtr<FJsonObject>& InObject, const FString& InFieldName, const double InDefaultValue)
	{
		if (!InObject.IsValid())
		{
			return InDefaultValue;
		}

		double Result = InDefaultValue;
		if (InObject->TryGetNumberField(InFieldName, Result))
		{
			return Result;
		}

		const FString StringValue = GetJsonFieldAsString(InObject, InFieldName);
		double ParsedValue = 0.0;
		return LexTryParseString(ParsedValue, *StringValue) ? ParsedValue : InDefaultValue;
	}

	FString ExtractDomainFromEntityId(const FString& InEntityId)
	{
		FString Left;
		FString Right;
		if (InEntityId.Split(TEXT("."), &Left, &Right))
		{
			return Left;
		}

		return FString();
	}

	void AddCapability(
		TArray<FIOTCapabilityDescriptor>& InCapabilities,
		const EIOTCapabilityKind InKind,
		const FString& InName,
		const bool bInReadable,
		const bool bInWritable,
		const float InMinValue = 0.0f,
		const float InMaxValue = 1.0f,
		const TArray<FString>& InOptions = TArray<FString>())
	{
		if (InCapabilities.ContainsByPredicate([InKind](const FIOTCapabilityDescriptor& InDescriptor)
		{
			return InDescriptor.CapabilityKind == InKind;
		}))
		{
			return;
		}

		FIOTCapabilityDescriptor Descriptor;
		Descriptor.CapabilityKind = InKind;
		Descriptor.CapabilityName = InName;
		Descriptor.bReadable = bInReadable;
		Descriptor.bWritable = bInWritable;
		Descriptor.MinValue = InMinValue;
		Descriptor.MaxValue = InMaxValue;
		Descriptor.OptionValues = InOptions;
		InCapabilities.Add(Descriptor);
	}

	EIOTDeviceKind MapDeviceKind(const FString& InDomain)
	{
		if (InDomain == TEXT("light")) return EIOTDeviceKind::Light;
		if (InDomain == TEXT("switch")) return EIOTDeviceKind::Switch;
		if (InDomain == TEXT("fan")) return EIOTDeviceKind::Fan;
		if (InDomain == TEXT("cover")) return EIOTDeviceKind::Cover;
		if (InDomain == TEXT("climate")) return EIOTDeviceKind::Climate;
		if (InDomain == TEXT("humidifier")) return EIOTDeviceKind::Humidifier;
		if (InDomain == TEXT("water_heater")) return EIOTDeviceKind::WaterHeater;
		if (InDomain == TEXT("media_player")) return EIOTDeviceKind::MediaPlayer;
		if (InDomain == TEXT("vacuum")) return EIOTDeviceKind::Vacuum;
		if (InDomain == TEXT("lock")) return EIOTDeviceKind::Lock;
		if (InDomain == TEXT("alarm_control_panel")) return EIOTDeviceKind::Alarm;
		if (InDomain == TEXT("siren")) return EIOTDeviceKind::Siren;
		if (InDomain == TEXT("scene")) return EIOTDeviceKind::Scene;
		if (InDomain == TEXT("script")) return EIOTDeviceKind::Script;
		if (InDomain == TEXT("button")) return EIOTDeviceKind::Button;
		if (InDomain == TEXT("input_boolean")) return EIOTDeviceKind::InputBoolean;
		if (InDomain == TEXT("input_number")) return EIOTDeviceKind::InputNumber;
		if (InDomain == TEXT("input_select")) return EIOTDeviceKind::InputSelect;
		if (InDomain == TEXT("number")) return EIOTDeviceKind::Number;
		if (InDomain == TEXT("select")) return EIOTDeviceKind::Select;
		if (InDomain == TEXT("timer")) return EIOTDeviceKind::Timer;
		if (InDomain == TEXT("remote")) return EIOTDeviceKind::Remote;
		if (InDomain == TEXT("sensor")) return EIOTDeviceKind::Sensor;
		if (InDomain == TEXT("binary_sensor")) return EIOTDeviceKind::BinarySensor;
		return EIOTDeviceKind::Unknown;
	}

	TArray<FIOTCapabilityDescriptor> BuildCapabilities(const FString& InDomain, const TSharedPtr<FJsonObject>& InAttributes)
	{
		TArray<FIOTCapabilityDescriptor> Capabilities;

		if (InDomain == TEXT("light"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Power, TEXT("Power"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Toggle, TEXT("Toggle"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Brightness, TEXT("Brightness"), true, true, 0.0f, 255.0f);
			AddCapability(Capabilities, EIOTCapabilityKind::ColorTemperature, TEXT("ColorTemperature"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Color, TEXT("Color"), true, true);
		}
		else if (InDomain == TEXT("switch") || InDomain == TEXT("input_boolean"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Power, TEXT("Power"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Toggle, TEXT("Toggle"), true, true);
		}
		else if (InDomain == TEXT("fan"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Power, TEXT("Power"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Toggle, TEXT("Toggle"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::NumericValue, TEXT("Percentage"), true, true, 0.0f, 100.0f);
			AddCapability(Capabilities, EIOTCapabilityKind::Preset, TEXT("Preset"), true, true, 0.0f, 1.0f, GetJsonStringArray(InAttributes, TEXT("preset_modes")));
		}
		else if (InDomain == TEXT("cover"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Position, TEXT("Position"), true, true, 0.0f, 100.0f);
		}
		else if (InDomain == TEXT("climate"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Mode, TEXT("HVACMode"), true, true, 0.0f, 1.0f, GetJsonStringArray(InAttributes, TEXT("hvac_modes")));
			AddCapability(Capabilities, EIOTCapabilityKind::TargetTemperature, TEXT("TargetTemperature"), true, true, static_cast<float>(GetJsonNumberOrDefault(InAttributes, TEXT("min_temp"), 0.0)), static_cast<float>(GetJsonNumberOrDefault(InAttributes, TEXT("max_temp"), 40.0)));
			AddCapability(Capabilities, EIOTCapabilityKind::Preset, TEXT("Preset"), true, true, 0.0f, 1.0f, GetJsonStringArray(InAttributes, TEXT("preset_modes")));
		}
		else if (InDomain == TEXT("humidifier"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Power, TEXT("Power"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Mode, TEXT("Mode"), true, true, 0.0f, 1.0f, GetJsonStringArray(InAttributes, TEXT("available_modes")));
			AddCapability(Capabilities, EIOTCapabilityKind::NumericValue, TEXT("Humidity"), true, true, static_cast<float>(GetJsonNumberOrDefault(InAttributes, TEXT("min_humidity"), 0.0)), static_cast<float>(GetJsonNumberOrDefault(InAttributes, TEXT("max_humidity"), 100.0)));
		}
		else if (InDomain == TEXT("water_heater"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Power, TEXT("Power"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Mode, TEXT("Mode"), true, true, 0.0f, 1.0f, GetJsonStringArray(InAttributes, TEXT("operation_list")));
			AddCapability(Capabilities, EIOTCapabilityKind::TargetTemperature, TEXT("TargetTemperature"), true, true, static_cast<float>(GetJsonNumberOrDefault(InAttributes, TEXT("min_temp"), 0.0)), static_cast<float>(GetJsonNumberOrDefault(InAttributes, TEXT("max_temp"), 100.0)));
		}
		else if (InDomain == TEXT("media_player"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Power, TEXT("Power"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Playback, TEXT("Playback"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Volume, TEXT("Volume"), true, true, 0.0f, 1.0f);
			AddCapability(Capabilities, EIOTCapabilityKind::Mute, TEXT("Mute"), true, true);
		}
		else if (InDomain == TEXT("vacuum"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Trigger, TEXT("Task"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Preset, TEXT("FanSpeed"), true, true, 0.0f, 1.0f, GetJsonStringArray(InAttributes, TEXT("fan_speed_list")));
		}
		else if (InDomain == TEXT("lock"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::LockControl, TEXT("LockControl"), true, true);
		}
		else if (InDomain == TEXT("alarm_control_panel"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::ArmControl, TEXT("ArmControl"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Trigger, TEXT("Trigger"), true, true);
		}
		else if (InDomain == TEXT("siren"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Power, TEXT("Power"), true, true);
			AddCapability(Capabilities, EIOTCapabilityKind::Trigger, TEXT("Trigger"), true, true);
		}
		else if (InDomain == TEXT("scene") || InDomain == TEXT("script") || InDomain == TEXT("button") || InDomain == TEXT("input_button") || InDomain == TEXT("timer") || InDomain == TEXT("remote"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Trigger, TEXT("Trigger"), true, true);
			if (InDomain == TEXT("remote"))
			{
				AddCapability(Capabilities, EIOTCapabilityKind::Power, TEXT("Power"), true, true);
			}
		}
		else if (InDomain == TEXT("input_number") || InDomain == TEXT("number"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::NumericValue, TEXT("NumericValue"), true, true, static_cast<float>(GetJsonNumberOrDefault(InAttributes, TEXT("min"), 0.0)), static_cast<float>(GetJsonNumberOrDefault(InAttributes, TEXT("max"), 100.0)));
		}
		else if (InDomain == TEXT("input_select") || InDomain == TEXT("select"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::Option, TEXT("Option"), true, true, 0.0f, 1.0f, GetJsonStringArray(InAttributes, TEXT("options")));
		}
		else if (InDomain == TEXT("sensor") || InDomain == TEXT("binary_sensor"))
		{
			AddCapability(Capabilities, EIOTCapabilityKind::SensorValue, TEXT("SensorValue"), true, false);
		}

		return Capabilities;
	}

	TMap<FString, FString> BuildRawAttributes(const TSharedPtr<FJsonObject>& InAttributes)
	{
		TMap<FString, FString> Result;
		if (!InAttributes.IsValid())
		{
			return Result;
		}

		for (const TPair<FString, TSharedPtr<FJsonValue>>& Pair : InAttributes->Values)
		{
			Result.Add(Pair.Key, JsonValueToString(Pair.Value));
		}

		return Result;
	}

	FIOTDeviceDescriptor BuildDeviceDescriptor(const TSharedPtr<FJsonObject>& InStateObject)
	{
		FIOTDeviceDescriptor Descriptor;
		if (!InStateObject.IsValid())
		{
			return Descriptor;
		}

		const FString EntityId = GetJsonFieldAsString(InStateObject, TEXT("entity_id"));
		const FString Domain = ExtractDomainFromEntityId(EntityId);
		const TSharedPtr<FJsonObject> Attributes = GetJsonObjectField(InStateObject, TEXT("attributes"));

		Descriptor.DeviceId = FString::Printf(TEXT("ha:%s"), *EntityId);
		Descriptor.PlatformKind = EIOTPlatformKind::HomeAssistant;
		Descriptor.EntityId = EntityId;
		Descriptor.DisplayName = GetJsonFieldAsString(Attributes, TEXT("friendly_name"));
		if (Descriptor.DisplayName.IsEmpty())
		{
			Descriptor.DisplayName = EntityId;
		}
		Descriptor.DeviceKind = MapDeviceKind(Domain);
		Descriptor.CapabilityDescriptors = BuildCapabilities(Domain, Attributes);
		Descriptor.RawDomain = Domain;
		Descriptor.RawAttributes = BuildRawAttributes(Attributes);
		return Descriptor;
	}

	FIOTDeviceState BuildDeviceState(const TSharedPtr<FJsonObject>& InStateObject, const FString& InDeviceId)
	{
		FIOTDeviceState State;
		if (!InStateObject.IsValid())
		{
			return State;
		}

		State.PrimaryState = GetJsonFieldAsString(InStateObject, TEXT("state"));
		State.bAvailable = !State.PrimaryState.Equals(TEXT("unavailable"), ESearchCase::IgnoreCase);
		State.LastUpdatedUtc = GetJsonFieldAsString(InStateObject, TEXT("last_updated"));
		State.RawState = ToCompactJsonString(InStateObject);
		State.CapabilityValues.Add(TEXT("__device_id"), InDeviceId);
		State.CapabilityValues.Add(TEXT("state"), State.PrimaryState);
		State.CapabilityValues.Add(TEXT("entity_id"), GetJsonFieldAsString(InStateObject, TEXT("entity_id")));

		const TSharedPtr<FJsonObject> Attributes = GetJsonObjectField(InStateObject, TEXT("attributes"));
		if (Attributes.IsValid())
		{
			for (const TPair<FString, TSharedPtr<FJsonValue>>& Pair : Attributes->Values)
			{
				State.CapabilityValues.Add(Pair.Key, JsonValueToString(Pair.Value));
			}
		}

		return State;
	}

	TSharedPtr<FJsonValue> BuildJsonValueFromString(const FString& InValue)
	{
		const FString Trimmed = InValue.TrimStartAndEnd();
		if (Trimmed.Equals(TEXT("true"), ESearchCase::IgnoreCase))
		{
			return MakeShared<FJsonValueBoolean>(true);
		}
		if (Trimmed.Equals(TEXT("false"), ESearchCase::IgnoreCase))
		{
			return MakeShared<FJsonValueBoolean>(false);
		}
		if (Trimmed.Equals(TEXT("null"), ESearchCase::IgnoreCase))
		{
			return MakeShared<FJsonValueNull>();
		}

		double NumericValue = 0.0;
		if (LexTryParseString(NumericValue, *Trimmed))
		{
			return MakeShared<FJsonValueNumber>(NumericValue);
		}

		if (Trimmed.StartsWith(TEXT("{")))
		{
			TSharedPtr<FJsonObject> ObjectValue;
			if (TryParseJsonObject(Trimmed, ObjectValue))
			{
				return MakeShared<FJsonValueObject>(ObjectValue);
			}
		}

		if (Trimmed.StartsWith(TEXT("[")))
		{
			TArray<TSharedPtr<FJsonValue>> ArrayValue;
			if (TryParseJsonArray(Trimmed, ArrayValue))
			{
				return MakeShared<FJsonValueArray>(ArrayValue);
			}
		}

		return MakeShared<FJsonValueString>(Trimmed);
	}

	FString BuildJsonPayloadFromParams(const TMap<FString, FString>& InParams)
	{
		TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
		for (const TPair<FString, FString>& Pair : InParams)
		{
			JsonObject->SetField(Pair.Key, BuildJsonValueFromString(Pair.Value));
		}

		return ToCompactJsonString(JsonObject);
	}

	EIOTCommandStatus MapCommandStatus(const FHomeAssistantClientResponse& InResponse)
	{
		if (InResponse.bSucceeded)
		{
			return EIOTCommandStatus::Success;
		}
		if (InResponse.ResponseCode == 400)
		{
			return EIOTCommandStatus::InvalidArgument;
		}
		if (InResponse.ResponseCode == 401 || InResponse.ResponseCode == 403)
		{
			return EIOTCommandStatus::AuthenticationFailed;
		}
		if (InResponse.ResponseCode == 404)
		{
			return EIOTCommandStatus::Unsupported;
		}
		if (InResponse.ResponseCode <= 0)
		{
			return EIOTCommandStatus::TransportError;
		}
		return EIOTCommandStatus::PlatformError;
	}

	void AddEntityToParams(TMap<FString, FString>& InOutParams, const FString& InEntityId)
	{
		if (!InOutParams.Contains(TEXT("entity_id")) && !InEntityId.IsEmpty())
		{
			InOutParams.Add(TEXT("entity_id"), InEntityId);
		}
	}

	bool TryGetFloatParam(const TMap<FString, FString>& InParams, const FString& InKey, float& OutValue)
	{
		const FString* Found = InParams.Find(InKey);
		if (!Found)
		{
			return false;
		}

		return LexTryParseString(OutValue, **Found);
	}

	void ApplyServiceResponseStatePayload(UIOTSubsystem* InSubsystem, const FString& InPayload)
	{
		if (!InSubsystem)
		{
			return;
		}

		TArray<TSharedPtr<FJsonValue>> JsonArray;
		if (!TryParseJsonArray(InPayload, JsonArray))
		{
			return;
		}

		for (const TSharedPtr<FJsonValue>& Value : JsonArray)
		{
			if (!Value.IsValid() || Value->Type != EJson::Object)
			{
				continue;
			}

			const TSharedPtr<FJsonObject> StateObject = Value->AsObject();
			const FIOTDeviceDescriptor Descriptor = BuildDeviceDescriptor(StateObject);
			const FIOTDeviceState State = BuildDeviceState(StateObject, Descriptor.DeviceId);
			InSubsystem->UpdateDeviceState(Descriptor, State);
		}
	}

	bool TryMapGenericCommand(
		const FIOTDeviceDescriptor& InDevice,
		const FIOTCommandRequest& InRequest,
		FName& OutDomain,
		FName& OutService,
		TMap<FString, FString>& OutParams,
		FString& OutErrorMessage)
	{
		const FString Domain = InDevice.RawDomain;
		const FString Command = InRequest.CommandName.ToLower();

		OutDomain = *Domain;
		OutParams = InRequest.Parameters;
		AddEntityToParams(OutParams, InDevice.EntityId);

		if (Command == TEXT("turnon"))
		{
			OutService = (Domain == TEXT("button") || Domain == TEXT("input_button")) ? TEXT("press") : TEXT("turn_on");
			return true;
		}

		if (Command == TEXT("turnoff"))
		{
			OutService = Domain == TEXT("timer") ? TEXT("cancel") : TEXT("turn_off");
			return true;
		}

		if (Command == TEXT("toggle"))
		{
			OutService = TEXT("toggle");
			return true;
		}

		if (Command == TEXT("setvalue"))
		{
			if (Domain == TEXT("input_number") || Domain == TEXT("number"))
			{
				OutService = TEXT("set_value");
				return true;
			}
			if (Domain == TEXT("fan"))
			{
				OutService = TEXT("set_percentage");
				if (!OutParams.Contains(TEXT("percentage")) && OutParams.Contains(TEXT("value")))
				{
					OutParams.Add(TEXT("percentage"), OutParams.FindChecked(TEXT("value")));
				}
				return true;
			}
			if (Domain == TEXT("humidifier"))
			{
				OutService = TEXT("set_humidity");
				if (!OutParams.Contains(TEXT("humidity")) && OutParams.Contains(TEXT("value")))
				{
					OutParams.Add(TEXT("humidity"), OutParams.FindChecked(TEXT("value")));
				}
				return true;
			}
			if (Domain == TEXT("climate") || Domain == TEXT("water_heater"))
			{
				OutService = TEXT("set_temperature");
				if (!OutParams.Contains(TEXT("temperature")) && OutParams.Contains(TEXT("value")))
				{
					OutParams.Add(TEXT("temperature"), OutParams.FindChecked(TEXT("value")));
				}
				return true;
			}
		}

		if ((Command == TEXT("increase") || Command == TEXT("decrease")) && Domain == TEXT("input_number"))
		{
			OutService = Command == TEXT("increase") ? TEXT("increment") : TEXT("decrement");
			return true;
		}

		if (Command == TEXT("setbrightness"))
		{
			OutService = TEXT("turn_on");
			if (!OutParams.Contains(TEXT("brightness")) && !OutParams.Contains(TEXT("brightness_pct")))
			{
				float ParsedValue = 0.0f;
				if (TryGetFloatParam(OutParams, TEXT("value"), ParsedValue))
				{
					if (ParsedValue <= 1.0f)
					{
						OutParams.Add(TEXT("brightness_pct"), FString::SanitizeFloat(ParsedValue * 100.0f));
					}
					else if (ParsedValue <= 100.0f)
					{
						OutParams.Add(TEXT("brightness_pct"), FString::SanitizeFloat(ParsedValue));
					}
					else
					{
						OutParams.Add(TEXT("brightness"), FString::SanitizeFloat(ParsedValue));
					}
				}
			}
			return true;
		}

		if (Command == TEXT("setcolortemp"))
		{
			OutService = TEXT("turn_on");
			if (!OutParams.Contains(TEXT("color_temp")) && !OutParams.Contains(TEXT("color_temp_kelvin")) && OutParams.Contains(TEXT("value")))
			{
				OutParams.Add(TEXT("color_temp_kelvin"), OutParams.FindChecked(TEXT("value")));
			}
			return true;
		}

		if (Command == TEXT("setrgbcolor"))
		{
			OutService = TEXT("turn_on");
			if (!OutParams.Contains(TEXT("rgb_color")))
			{
				const FString* R = OutParams.Find(TEXT("r"));
				const FString* G = OutParams.Find(TEXT("g"));
				const FString* B = OutParams.Find(TEXT("b"));
				if (R && G && B)
				{
					OutParams.Add(TEXT("rgb_color"), FString::Printf(TEXT("[%s,%s,%s]"), **R, **G, **B));
				}
			}
			return true;
		}

		if (Command == TEXT("setmode"))
		{
			if (Domain == TEXT("climate"))
			{
				OutService = TEXT("set_hvac_mode");
				if (!OutParams.Contains(TEXT("hvac_mode")) && OutParams.Contains(TEXT("mode")))
				{
					OutParams.Add(TEXT("hvac_mode"), OutParams.FindChecked(TEXT("mode")));
				}
				return true;
			}
			if (Domain == TEXT("humidifier"))
			{
				OutService = TEXT("set_mode");
				return true;
			}
			if (Domain == TEXT("water_heater"))
			{
				OutService = TEXT("set_operation_mode");
				if (!OutParams.Contains(TEXT("operation_mode")) && OutParams.Contains(TEXT("mode")))
				{
					OutParams.Add(TEXT("operation_mode"), OutParams.FindChecked(TEXT("mode")));
				}
				return true;
			}
			if (Domain == TEXT("select") || Domain == TEXT("input_select"))
			{
				OutService = TEXT("select_option");
				if (!OutParams.Contains(TEXT("option")) && OutParams.Contains(TEXT("mode")))
				{
					OutParams.Add(TEXT("option"), OutParams.FindChecked(TEXT("mode")));
				}
				return true;
			}
		}

		if (Command == TEXT("setpreset"))
		{
			if (Domain == TEXT("fan") || Domain == TEXT("climate"))
			{
				OutService = TEXT("set_preset_mode");
				if (!OutParams.Contains(TEXT("preset_mode")) && OutParams.Contains(TEXT("preset")))
				{
					OutParams.Add(TEXT("preset_mode"), OutParams.FindChecked(TEXT("preset")));
				}
				return true;
			}
			if (Domain == TEXT("vacuum"))
			{
				OutService = TEXT("set_fan_speed");
				if (!OutParams.Contains(TEXT("fan_speed")) && OutParams.Contains(TEXT("preset")))
				{
					OutParams.Add(TEXT("fan_speed"), OutParams.FindChecked(TEXT("preset")));
				}
				return true;
			}
		}

		if (Command == TEXT("setoption"))
		{
			if (Domain == TEXT("select") || Domain == TEXT("input_select"))
			{
				OutService = TEXT("select_option");
				return true;
			}
			if (Domain == TEXT("fan") || Domain == TEXT("climate"))
			{
				OutService = TEXT("set_preset_mode");
				if (!OutParams.Contains(TEXT("preset_mode")) && OutParams.Contains(TEXT("option")))
				{
					OutParams.Add(TEXT("preset_mode"), OutParams.FindChecked(TEXT("option")));
				}
				return true;
			}
		}

		if (Command == TEXT("settargettemperature"))
		{
			if (Domain == TEXT("climate") || Domain == TEXT("water_heater"))
			{
				OutService = TEXT("set_temperature");
				if (!OutParams.Contains(TEXT("temperature")) && OutParams.Contains(TEXT("value")))
				{
					OutParams.Add(TEXT("temperature"), OutParams.FindChecked(TEXT("value")));
				}
				return true;
			}
		}

		if (Command == TEXT("sethvacmode") && Domain == TEXT("climate"))
		{
			OutService = TEXT("set_hvac_mode");
			if (!OutParams.Contains(TEXT("hvac_mode")) && OutParams.Contains(TEXT("mode")))
			{
				OutParams.Add(TEXT("hvac_mode"), OutParams.FindChecked(TEXT("mode")));
			}
			return true;
		}

		if (Command == TEXT("open") && Domain == TEXT("cover"))
		{
			OutService = TEXT("open_cover");
			return true;
		}

		if (Command == TEXT("close") && Domain == TEXT("cover"))
		{
			OutService = TEXT("close_cover");
			return true;
		}

		if (Command == TEXT("stop") && Domain == TEXT("cover"))
		{
			OutService = TEXT("stop_cover");
			return true;
		}

		if (Command == TEXT("setposition") && Domain == TEXT("cover"))
		{
			OutService = TEXT("set_cover_position");
			if (!OutParams.Contains(TEXT("position")) && OutParams.Contains(TEXT("value")))
			{
				OutParams.Add(TEXT("position"), OutParams.FindChecked(TEXT("value")));
			}
			return true;
		}

		if (Command == TEXT("play") && Domain == TEXT("media_player"))
		{
			OutService = TEXT("media_play");
			return true;
		}

		if (Command == TEXT("pause") && Domain == TEXT("media_player"))
		{
			OutService = TEXT("media_pause");
			return true;
		}

		if (Command == TEXT("stopmedia") && Domain == TEXT("media_player"))
		{
			OutService = TEXT("media_stop");
			return true;
		}

		if (Command == TEXT("next") && Domain == TEXT("media_player"))
		{
			OutService = TEXT("media_next_track");
			return true;
		}

		if (Command == TEXT("previous") && Domain == TEXT("media_player"))
		{
			OutService = TEXT("media_previous_track");
			return true;
		}

		if (Command == TEXT("setvolume") && Domain == TEXT("media_player"))
		{
			OutService = TEXT("volume_set");
			float VolumeValue = 0.0f;
			if (!OutParams.Contains(TEXT("volume_level")) && TryGetFloatParam(OutParams, TEXT("value"), VolumeValue))
			{
				const float NormalizedVolume = VolumeValue > 1.0f ? VolumeValue / 100.0f : VolumeValue;
				OutParams.Add(TEXT("volume_level"), FString::SanitizeFloat(FMath::Clamp(NormalizedVolume, 0.0f, 1.0f)));
			}
			return true;
		}

		if (Command == TEXT("mute") && Domain == TEXT("media_player"))
		{
			OutService = TEXT("volume_mute");
			if (!OutParams.Contains(TEXT("is_volume_muted")))
			{
				OutParams.Add(TEXT("is_volume_muted"), TEXT("true"));
			}
			return true;
		}

		if ((Command == TEXT("start") || Command == TEXT("resume")) && (Domain == TEXT("vacuum") || Domain == TEXT("timer")))
		{
			OutService = TEXT("start");
			return true;
		}

		if (Command == TEXT("pausetask") && (Domain == TEXT("vacuum") || Domain == TEXT("timer")))
		{
			OutService = TEXT("pause");
			return true;
		}

		if (Command == TEXT("returntobase") && Domain == TEXT("vacuum"))
		{
			OutService = TEXT("return_to_base");
			return true;
		}

		if (Command == TEXT("lock") && Domain == TEXT("lock"))
		{
			OutService = TEXT("lock");
			return true;
		}

		if (Command == TEXT("unlock") && Domain == TEXT("lock"))
		{
			OutService = TEXT("unlock");
			return true;
		}

		if (Command == TEXT("arm") && Domain == TEXT("alarm_control_panel"))
		{
			const FString Mode = OutParams.Contains(TEXT("mode")) ? OutParams.FindChecked(TEXT("mode")).ToLower() : TEXT("away");
			OutService = FName(*FString::Printf(TEXT("alarm_arm_%s"), *Mode));
			return true;
		}

		if (Command == TEXT("disarm") && Domain == TEXT("alarm_control_panel"))
		{
			OutService = TEXT("alarm_disarm");
			return true;
		}

		if (Command == TEXT("activatescene") && Domain == TEXT("scene"))
		{
			OutService = TEXT("turn_on");
			return true;
		}

		if (Command == TEXT("runscript") && Domain == TEXT("script"))
		{
			OutService = TEXT("turn_on");
			return true;
		}

		if (Command == TEXT("pressbutton") && (Domain == TEXT("button") || Domain == TEXT("input_button")))
		{
			OutService = TEXT("press");
			return true;
		}

		if (Command == TEXT("trigger"))
		{
			if (Domain == TEXT("scene") || Domain == TEXT("script"))
			{
				OutService = TEXT("turn_on");
				return true;
			}
			if (Domain == TEXT("button") || Domain == TEXT("input_button"))
			{
				OutService = TEXT("press");
				return true;
			}
			if (Domain == TEXT("alarm_control_panel"))
			{
				OutService = TEXT("alarm_trigger");
				return true;
			}
			if (Domain == TEXT("siren"))
			{
				OutService = TEXT("turn_on");
				return true;
			}
			if (Domain == TEXT("timer"))
			{
				OutService = TEXT("start");
				return true;
			}
			if (Domain == TEXT("remote"))
			{
				OutService = TEXT("turn_on");
				return true;
			}
		}

		OutErrorMessage = FString::Printf(TEXT("Unsupported command %s for domain %s"), *InRequest.CommandName, *Domain);
		return false;
	}
}

void UHomeAssistantPlatformAdapter::InitializeAdapter(UIOTSubsystem* InSubsystem)
{
	Subsystem = InSubsystem;
}

void UHomeAssistantPlatformAdapter::ShutdownAdapter()
{
	PendingRequests.Reset();

	if (Client)
	{
		Client->OnConnectionValidated.RemoveAll(this);
		Client->OnStatesReceived.RemoveAll(this);
		Client->OnServiceCalled.RemoveAll(this);
		Client->OnRealtimeMessage.RemoveAll(this);
		Client->OnTransportError.RemoveAll(this);
		Client->OnRealtimeStateChanged.RemoveAll(this);
		Client->StopRealtime();
		Client = nullptr;
	}
}

EIOTPlatformKind UHomeAssistantPlatformAdapter::GetPlatformKind() const
{
	return EIOTPlatformKind::HomeAssistant;
}

void UHomeAssistantPlatformAdapter::ApplyEndpointConfig(const FIOTPlatformEndpointConfig& InConfig)
{
	EndpointConfig = InConfig;

	if (Client)
	{
		Client->Configure(EndpointConfig.BaseUrl, EndpointConfig.AccessToken, EndpointConfig.RequestTimeoutSeconds, EndpointConfig.bAutoReconnect);
	}
}

FIOTPlatformEndpointConfig UHomeAssistantPlatformAdapter::GetEndpointConfig() const
{
	return EndpointConfig;
}

bool UHomeAssistantPlatformAdapter::CanConnect() const
{
	return EndpointConfig.IsValidForConnection();
}

void UHomeAssistantPlatformAdapter::Connect()
{
	if (!Subsystem.IsValid())
	{
		return;
	}

	if (!CanConnect())
	{
		Subsystem->NotifyConnectionStateChanged(EIOTConnectionState::Error, TEXT("Home Assistant endpoint config is invalid"));
		return;
	}

	if (!Client)
	{
		Client = UHomeAssistantClient::CreateHomeAssistantClient(this);
	}

	Client->OnConnectionValidated.RemoveAll(this);
	Client->OnStatesReceived.RemoveAll(this);
	Client->OnServiceCalled.RemoveAll(this);
	Client->OnRealtimeMessage.RemoveAll(this);
	Client->OnTransportError.RemoveAll(this);
	Client->OnRealtimeStateChanged.RemoveAll(this);

	Client->OnConnectionValidated.AddUObject(this, &UHomeAssistantPlatformAdapter::HandleConnectionValidated);
	Client->OnStatesReceived.AddUObject(this, &UHomeAssistantPlatformAdapter::HandleStatesReceived);
	Client->OnServiceCalled.AddUObject(this, &UHomeAssistantPlatformAdapter::HandleServiceCalled);
	Client->OnRealtimeMessage.AddUObject(this, &UHomeAssistantPlatformAdapter::HandleRealtimeMessage);
	Client->OnTransportError.AddUObject(this, &UHomeAssistantPlatformAdapter::HandleTransportError);
	Client->OnRealtimeStateChanged.AddUObject(this, &UHomeAssistantPlatformAdapter::HandleRealtimeStateChanged);
	Client->Configure(EndpointConfig.BaseUrl, EndpointConfig.AccessToken, EndpointConfig.RequestTimeoutSeconds, EndpointConfig.bAutoReconnect);

	Subsystem->NotifyConnectionStateChanged(EIOTConnectionState::Connecting);
	Client->ValidateConnection();
}

void UHomeAssistantPlatformAdapter::Disconnect()
{
	PendingRequests.Reset();

	if (Client)
	{
		Client->StopRealtime();
	}
}

void UHomeAssistantPlatformAdapter::RefreshDevices()
{
	if (!Client)
	{
		Connect();
		return;
	}

	Client->FetchStates();
}

void UHomeAssistantPlatformAdapter::SubscribeRealtime()
{
	if (!Client)
	{
		Connect();
		return;
	}

	Client->StartRealtime();
}

void UHomeAssistantPlatformAdapter::ExecuteCommand(const FIOTCommandRequest& InRequest)
{
	if (!Subsystem.IsValid())
	{
		return;
	}

	if (!Client)
	{
		FIOTCommandResult Result;
		Result.RequestId = InRequest.RequestId;
		Result.DeviceId = InRequest.DeviceId;
		Result.Status = EIOTCommandStatus::PlatformUnavailable;
		Result.ErrorMessage = TEXT("Home Assistant client is not connected");
		Subsystem->CompleteCommand(InRequest, Result);
		return;
	}

	FIOTDeviceDescriptor DeviceDescriptor;
	if (!Subsystem->TryGetDeviceById(InRequest.DeviceId, DeviceDescriptor))
	{
		FIOTCommandResult Result;
		Result.RequestId = InRequest.RequestId;
		Result.DeviceId = InRequest.DeviceId;
		Result.Status = EIOTCommandStatus::EntityUnavailable;
		Result.ErrorMessage = TEXT("IOT device is not available in registry");
		Subsystem->CompleteCommand(InRequest, Result);
		return;
	}

	FName DomainName = NAME_None;
	FName ServiceName = NAME_None;
	TMap<FString, FString> ServiceParams;
	FString ErrorMessage;
	if (!TryMapGenericCommand(DeviceDescriptor, InRequest, DomainName, ServiceName, ServiceParams, ErrorMessage))
	{
		FIOTCommandResult Result;
		Result.RequestId = InRequest.RequestId;
		Result.DeviceId = InRequest.DeviceId;
		Result.Status = EIOTCommandStatus::Unsupported;
		Result.ErrorMessage = ErrorMessage;
		Subsystem->CompleteCommand(InRequest, Result);
		return;
	}

	PendingRequests.Add(InRequest.RequestId, InRequest);
	Client->CallService(InRequest.RequestId, DomainName, ServiceName, BuildJsonPayloadFromParams(ServiceParams));
}

void UHomeAssistantPlatformAdapter::ExecuteRawService(const FString& InRequestId, const FString& InDeviceId, const FName& InDomain, const FName& InService, const TMap<FString, FString>& InParams)
{
	if (!Subsystem.IsValid())
	{
		return;
	}

	if (!Client)
	{
		FIOTCommandRequest FailedRequest;
		FailedRequest.RequestId = InRequestId;
		FailedRequest.DeviceId = InDeviceId;
		FailedRequest.CommandName = FString::Printf(TEXT("Raw:%s.%s"), *InDomain.ToString(), *InService.ToString());

		FIOTCommandResult Result;
		Result.RequestId = InRequestId;
		Result.DeviceId = InDeviceId;
		Result.Status = EIOTCommandStatus::PlatformUnavailable;
		Result.ErrorMessage = TEXT("Home Assistant client is not connected");
		Subsystem->CompleteCommand(FailedRequest, Result);
		return;
	}

	FIOTCommandRequest Request;
	Request.RequestId = InRequestId;
	Request.DeviceId = InDeviceId;
	Request.CommandName = FString::Printf(TEXT("Raw:%s.%s"), *InDomain.ToString(), *InService.ToString());
	Request.Parameters = InParams;

	if (!InDeviceId.IsEmpty())
	{
		FString EntityId;
		if (Subsystem->TryResolveEntityIdForDevice(InDeviceId, EntityId) && !Request.Parameters.Contains(TEXT("entity_id")))
		{
			Request.Parameters.Add(TEXT("entity_id"), EntityId);
		}
	}

	PendingRequests.Add(InRequestId, Request);
	Client->CallService(InRequestId, InDomain, InService, BuildJsonPayloadFromParams(Request.Parameters));
}

void UHomeAssistantPlatformAdapter::HandleConnectionValidated(const FHomeAssistantClientResponse& InResponse)
{
	if (!Subsystem.IsValid())
	{
		return;
	}

	if (InResponse.bSucceeded)
	{
		Subsystem->NotifyConnectionStateChanged(EIOTConnectionState::Connected);
		return;
	}

	const FString ErrorMessage =
		InResponse.ResponseCode == 401 || InResponse.ResponseCode == 403
		? TEXT("Home Assistant access token is invalid")
		: (InResponse.ErrorMessage.IsEmpty() ? TEXT("Failed to connect to Home Assistant") : InResponse.ErrorMessage);

	Subsystem->NotifyConnectionStateChanged(EIOTConnectionState::Error, ErrorMessage);
}

void UHomeAssistantPlatformAdapter::HandleStatesReceived(const FHomeAssistantClientResponse& InResponse)
{
	if (!Subsystem.IsValid())
	{
		return;
	}

	if (!InResponse.bSucceeded)
	{
		Subsystem->NotifyConnectionStateChanged(EIOTConnectionState::Error, InResponse.ErrorMessage.IsEmpty() ? TEXT("Failed to fetch Home Assistant states") : InResponse.ErrorMessage);
		return;
	}

	TArray<TSharedPtr<FJsonValue>> JsonArray;
	if (!TryParseJsonArray(InResponse.Payload, JsonArray))
	{
		Subsystem->NotifyConnectionStateChanged(EIOTConnectionState::Error, TEXT("Invalid Home Assistant state payload"));
		return;
	}

	TArray<FIOTDeviceDescriptor> Devices;
	TArray<FIOTDeviceState> States;

	for (const TSharedPtr<FJsonValue>& Value : JsonArray)
	{
		if (!Value.IsValid() || Value->Type != EJson::Object)
		{
			continue;
		}

		const TSharedPtr<FJsonObject> StateObject = Value->AsObject();
		const FIOTDeviceDescriptor Descriptor = BuildDeviceDescriptor(StateObject);
		if (Descriptor.EntityId.IsEmpty())
		{
			continue;
		}

		Devices.Add(Descriptor);
		States.Add(BuildDeviceState(StateObject, Descriptor.DeviceId));
	}

	Subsystem->ReplaceDeviceSnapshot(Devices, States);
}

void UHomeAssistantPlatformAdapter::HandleServiceCalled(const FHomeAssistantClientResponse& InResponse)
{
	FIOTCommandRequest Request;
	if (!PendingRequests.RemoveAndCopyValue(InResponse.RequestId, Request))
	{
		return;
	}

	if (!Subsystem.IsValid())
	{
		return;
	}

	FIOTCommandResult Result;
	Result.RequestId = Request.RequestId;
	Result.DeviceId = Request.DeviceId;
	Result.Status = MapCommandStatus(InResponse);
	Result.bSucceeded = InResponse.bSucceeded;
	Result.ErrorCode = InResponse.ResponseCode > 0 ? FString::FromInt(InResponse.ResponseCode) : FString();
	Result.ErrorMessage = InResponse.ErrorMessage;
	Result.PlatformResponseSummary = InResponse.Payload.Left(2048);

	if (InResponse.bSucceeded)
	{
		ApplyServiceResponseStatePayload(Subsystem.Get(), InResponse.Payload);
		Subsystem->TryGetDeviceState(Request.DeviceId, Result.UpdatedState);
	}

	Subsystem->CompleteCommand(Request, Result);
}

void UHomeAssistantPlatformAdapter::HandleRealtimeMessage(const FString& InMessage)
{
	if (!Subsystem.IsValid())
	{
		return;
	}

	TSharedPtr<FJsonObject> JsonObject;
	if (!TryParseJsonObject(InMessage, JsonObject) || !JsonObject.IsValid())
	{
		return;
	}

	if (GetJsonFieldAsString(JsonObject, TEXT("type")) != TEXT("event"))
	{
		return;
	}

	const TSharedPtr<FJsonObject> EventObject = GetJsonObjectField(JsonObject, TEXT("event"));
	const TSharedPtr<FJsonObject> DataObject = GetJsonObjectField(EventObject, TEXT("data"));
	if (!EventObject.IsValid() || !DataObject.IsValid())
	{
		return;
	}

	const TSharedPtr<FJsonObject> NewStateObject = GetJsonObjectField(DataObject, TEXT("new_state"));
	if (NewStateObject.IsValid())
	{
		const FIOTDeviceDescriptor Descriptor = BuildDeviceDescriptor(NewStateObject);
		const FIOTDeviceState State = BuildDeviceState(NewStateObject, Descriptor.DeviceId);
		Subsystem->UpdateDeviceState(Descriptor, State);
		return;
	}

	const TSharedPtr<FJsonObject> OldStateObject = GetJsonObjectField(DataObject, TEXT("old_state"));
	if (OldStateObject.IsValid())
	{
		const FIOTDeviceDescriptor Descriptor = BuildDeviceDescriptor(OldStateObject);
		FIOTDeviceState State = BuildDeviceState(OldStateObject, Descriptor.DeviceId);
		State.bAvailable = false;
		State.PrimaryState = TEXT("unavailable");
		Subsystem->UpdateDeviceState(Descriptor, State);
	}
}

void UHomeAssistantPlatformAdapter::HandleTransportError(const FString& InErrorMessage)
{
	if (!Subsystem.IsValid())
	{
		return;
	}

	const EIOTConnectionState ConnectionState = Subsystem->GetConnectionState();
	if (ConnectionState == EIOTConnectionState::Connecting || ConnectionState == EIOTConnectionState::Discovering || ConnectionState == EIOTConnectionState::Subscribing)
	{
		Subsystem->NotifyConnectionStateChanged(EIOTConnectionState::Error, InErrorMessage);
		return;
	}

	Subsystem->NotifyRealtimeStateChanged(false, InErrorMessage);
}

void UHomeAssistantPlatformAdapter::HandleRealtimeStateChanged(const bool bInRealtimeActive)
{
	if (!Subsystem.IsValid())
	{
		return;
	}

	Subsystem->NotifyRealtimeStateChanged(bInRealtimeActive);
	if (bInRealtimeActive)
	{
		Subsystem->NotifyConnectionStateChanged(EIOTConnectionState::Connected);
	}
}
