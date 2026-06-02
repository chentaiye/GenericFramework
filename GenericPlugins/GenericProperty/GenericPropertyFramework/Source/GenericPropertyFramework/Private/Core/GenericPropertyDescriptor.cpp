#include "Core/GenericPropertyDescriptor.h"

FGenericPropertyFieldKey FGenericPropertyFieldKey::FromAccessPath(const FGenericPropertyAccessPath& InAccessPath)
{
	FGenericPropertyFieldKey FieldKey;
	FieldKey.AccessPath = InAccessPath;
	FieldKey.PropertyPath = InAccessPath.ToString();
	return FieldKey;
}

FString FGenericPropertyFieldKey::ToStableKey() const
{
	if (!PropertyPath.IsEmpty())
	{
		return PropertyPath;
	}

	return AccessPath.ToString();
}
