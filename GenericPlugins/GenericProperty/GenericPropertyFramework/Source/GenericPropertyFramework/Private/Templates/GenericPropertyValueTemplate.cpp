#include "Templates/GenericPropertyValueTemplate.h"

#include "Core/GenericProperty.h"
#include "UI/GenericPropertyRowValueSpawner.h"
#include "UI/GenericPropertyValue.h"

namespace GenericPropertyFramework
{
	namespace Templates
	{
bool CommitSerializedValue(UGenericProperty& InProperty, const FString& InSerializedValue)
{
	InProperty.CommitSerializedValueInternal(InSerializedValue);
	return !InProperty.bIsInvalid;
}

bool CommitSerializedValue(UGenericPropertyValue& InValueWidget, const FString& InSerializedValue)
{
	return InValueWidget.CommitSerializedValueInternal(InSerializedValue);
}

bool CommitSerializedValue(UGenericPropertyRowValueSpawner& InSpawner, const FString& InSerializedValue)
{
	return InSpawner.CommitSerializedValueInternal(InSerializedValue);
}
	}
}
