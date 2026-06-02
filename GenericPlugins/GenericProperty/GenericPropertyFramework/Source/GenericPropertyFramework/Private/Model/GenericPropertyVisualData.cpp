#include "Model/GenericPropertyVisualData.h"

#include "Core/GenericProperty.h"

void UGenericPropertyVisualData::RegisterRule(const FGenericPropertyVisualRule& InRule)
{
	Rules.Add(InRule);
}

void UGenericPropertyVisualData::ClearRules()
{
	Rules.Reset();
}

TSoftClassPtr<UUserWidget> UGenericPropertyVisualData::ResolveWidgetClass(const UGenericProperty* InViewModel) const
{
	if (InViewModel == nullptr)
	{
		return nullptr;
	}

	int32 BestScore = TNumericLimits<int32>::Lowest();
	TSoftClassPtr<UUserWidget> BestWidgetClass;

	for (const FGenericPropertyVisualRule& Rule : Rules)
	{
		if (Rule.WidgetClass.IsNull())
		{
			continue;
		}

		int32 RuleScore = Rule.Priority * 1000;

		if (Rule.TypeName != EGenericPropertyValueType::Unknown && Rule.TypeName != InViewModel->TypeName)
		{
			continue;
		}
		else if (Rule.TypeName != EGenericPropertyValueType::Unknown)
		{
			RuleScore += 100;
		}

		if (Rule.PropertyName != NAME_None && Rule.PropertyName != InViewModel->PropertyName)
		{
			continue;
		}
		else if (Rule.PropertyName != NAME_None)
		{
			RuleScore += 150;
		}

		if (!Rule.PathContains.IsEmpty() && !InViewModel->PropertyPath.Contains(Rule.PathContains))
		{
			continue;
		}
		else if (!Rule.PathContains.IsEmpty())
		{
			RuleScore += 200 + Rule.PathContains.Len();
		}

		if (Rule.RequiredMetadata != NAME_None && !InViewModel->Metadata.Contains(Rule.RequiredMetadata))
		{
			continue;
		}
		else if (Rule.RequiredMetadata != NAME_None)
		{
			RuleScore += 75;
		}

		if (Rule.RequiredTag.IsValid() && !InViewModel->HasVisualTag(Rule.RequiredTag))
		{
			continue;
		}
		else if (Rule.RequiredTag.IsValid())
		{
			RuleScore += 125;
		}

		if (RuleScore > BestScore)
		{
			BestScore = RuleScore;
			BestWidgetClass = Rule.WidgetClass;
		}
	}

	return BestWidgetClass;
}
