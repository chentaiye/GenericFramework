// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Input/GenericInputActionDataAsset.h"

#if WITH_EDITOR
#include "WidgetType.h"
#include "Misc/DataValidation.h"

EDataValidationResult UGenericInputActionDataAsset::IsDataValid(FDataValidationContext& Context) const
{
	Super::IsDataValid(Context);

	bool bIsValid = true;

	for (int32 MappingIndex = 0; MappingIndex < ActionMappings.Num(); ++MappingIndex)
	{
		const FGenericInputActionKeyTriggerMapping& Mapping = ActionMappings[MappingIndex];
		if (!Mapping.ActionTag.IsValid() || !Mapping.ActionTag.MatchesTag(TAG_GameplayUI_Action))
		{
			Context.AddError(FText::Format(
				NSLOCTEXT("GenericInputActionDataAsset", "InvalidActionTag", "Action mapping {0} has invalid ActionTag. It must match GameplayUI.Action."),
				FText::AsNumber(MappingIndex)
			));
			bIsValid = false;
		}

		TSet<FKey> UsedKeys;
		for (int32 KeyIndex = 0; KeyIndex < Mapping.KeyTriggers.Num(); ++KeyIndex)
		{
			const FGenericInputKeyTrigger& KeyTrigger = Mapping.KeyTriggers[KeyIndex];
			if (!KeyTrigger.Key.IsValid())
			{
				Context.AddError(FText::Format(
					NSLOCTEXT("GenericInputActionDataAsset", "InvalidKey", "Action mapping {0}, key trigger {1} has invalid Key."),
					FText::AsNumber(MappingIndex),
					FText::AsNumber(KeyIndex)
				));
				bIsValid = false;
			}

			if (!IsValid(KeyTrigger.Trigger))
			{
				Context.AddError(FText::Format(
					NSLOCTEXT("GenericInputActionDataAsset", "MissingTrigger", "Action mapping {0}, key trigger {1} has no Trigger."),
					FText::AsNumber(MappingIndex),
					FText::AsNumber(KeyIndex)
				));
				bIsValid = false;
			}

			if (KeyTrigger.Key.IsValid())
			{
				if (UsedKeys.Contains(KeyTrigger.Key))
				{
					Context.AddError(FText::Format(
						NSLOCTEXT("GenericInputActionDataAsset", "DuplicateKey", "Action mapping {0} contains duplicate Key {1}."),
						FText::AsNumber(MappingIndex),
						FText::FromName(KeyTrigger.Key.GetFName())
					));
					bIsValid = false;
				}
				else
				{
					UsedKeys.Add(KeyTrigger.Key);
				}
			}
		}
	}

	return bIsValid ? EDataValidationResult::Valid : EDataValidationResult::Invalid;
}
#endif
