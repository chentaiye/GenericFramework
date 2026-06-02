#include "Data/GenericPropertyDataSourceCollection.h"

#include "Core/GenericProperty.h"
#include "Core/GenericPropertyReflection.h"
#include "Data/GenericPropertyValueUtilities.h"

void UGenericPropertyDataSourceCollection::Initialize(UGenericPropertyProxy* InOwnerProxy, const FGenericPropertyPanelOptions& InOptions)
{
	OwnerProxy = InOwnerProxy;
	Options = InOptions;
}

void UGenericPropertyDataSourceCollection::BuildRootNodes(TArray<UGenericProperty*>& OutNodes)
{
	OutNodes.Reset();
}

FGenericPropertyReadResult UGenericPropertyDataSourceCollection::ReadValue(const FGenericPropertyAccessPath& InPath) const
{
	if (OwnerProxy == nullptr)
	{
		FGenericPropertyReadResult Result;
		Result.ErrorMessage = FText::FromString(TEXT("Owner proxy is invalid."));
		return Result;
	}

	UGenericProperty* TemporaryNode = NewObject<UGenericProperty>(GetTransientPackage());
	TemporaryNode->Initialize(OwnerProxy);
	TemporaryNode->SetAccessPath(InPath);
	return GenericPropertyFramework::Private::ReadNodeValue(*OwnerProxy, *TemporaryNode);
}

FGenericPropertyWriteResult UGenericPropertyDataSourceCollection::WriteValue(const FGenericPropertyAccessPath& InPath, const FString& InValue)
{
	if (OwnerProxy == nullptr)
	{
		FGenericPropertyWriteResult Result;
		Result.ErrorMessage = FText::FromString(TEXT("Owner proxy is invalid."));
		return Result;
	}

	UGenericProperty* TemporaryNode = NewObject<UGenericProperty>(GetTransientPackage());
	TemporaryNode->Initialize(OwnerProxy);
	TemporaryNode->SetAccessPath(InPath);
	TemporaryNode->TextState.CurrentValue = InValue;
	return GenericPropertyFramework::Private::WriteNodeValue(*OwnerProxy, *TemporaryNode, InValue);
}

FGenericPropertyValidationResult UGenericPropertyDataSourceCollection::ValidateValue(const FGenericPropertyAccessPath& InPath, const FString& InValue) const
{
	if (OwnerProxy == nullptr)
	{
		FGenericPropertyValidationResult Result;
		Result.bSuccess = false;
		Result.Message = FText::FromString(TEXT("Owner proxy is invalid."));
		return Result;
	}

	UGenericProperty* TemporaryNode = NewObject<UGenericProperty>(GetTransientPackage());
	TemporaryNode->Initialize(OwnerProxy);
	TemporaryNode->SetAccessPath(InPath);
	return GenericPropertyFramework::Private::ValidateNodeValue(*OwnerProxy, *TemporaryNode, InValue);
}

void UGenericPropertyDataSourceCollection::RefreshNode(UGenericProperty& InNode) const
{
	GenericPropertyFramework::Private::RefreshNodeState(InNode);
}

void UGenericPropertyDataSourceCollection::RebuildNodeChildren(UGenericProperty& InNode) const
{
	GenericPropertyFramework::Private::BuildDynamicChildren(InNode);
}

bool UGenericPropertyDataSourceCollection::ResetNode(UGenericProperty& InNode, const EGenericPropertyResetMode InMode)
{
	return OwnerProxy != nullptr && GenericPropertyFramework::Private::ResetNodeValue(*OwnerProxy, InNode, InMode);
}

FGenericPropertyWriteResult UGenericPropertyDataSourceCollection::AddContainerElement(UGenericProperty& InNode)
{
	if (OwnerProxy == nullptr)
	{
		FGenericPropertyWriteResult Result;
		Result.ErrorMessage = FText::FromString(TEXT("Owner proxy is invalid."));
		return Result;
	}

	return GenericPropertyFramework::Private::AddContainerNodeValue(*OwnerProxy, InNode);
}

FGenericPropertyWriteResult UGenericPropertyDataSourceCollection::RemoveNode(UGenericProperty& InNode)
{
	if (OwnerProxy == nullptr)
	{
		FGenericPropertyWriteResult Result;
		Result.ErrorMessage = FText::FromString(TEXT("Owner proxy is invalid."));
		return Result;
	}

	return GenericPropertyFramework::Private::RemoveNodeValue(*OwnerProxy, InNode);
}

FGenericPropertyWriteResult UGenericPropertyDataSourceCollection::DuplicateNode(UGenericProperty& InNode)
{
	if (OwnerProxy == nullptr)
	{
		FGenericPropertyWriteResult Result;
		Result.ErrorMessage = FText::FromString(TEXT("Owner proxy is invalid."));
		return Result;
	}

	return GenericPropertyFramework::Private::DuplicateNodeValue(*OwnerProxy, InNode);
}

FGenericPropertyWriteResult UGenericPropertyDataSourceCollection::MoveNode(UGenericProperty& InNode, const int32 InNewIndex)
{
	if (OwnerProxy == nullptr)
	{
		FGenericPropertyWriteResult Result;
		Result.ErrorMessage = FText::FromString(TEXT("Owner proxy is invalid."));
		return Result;
	}

	return GenericPropertyFramework::Private::MoveNodeValue(*OwnerProxy, InNode, InNewIndex);
}

FGenericPropertyWriteResult UGenericPropertyDataSourceCollection::ClearNode(UGenericProperty& InNode)
{
	if (OwnerProxy == nullptr)
	{
		FGenericPropertyWriteResult Result;
		Result.ErrorMessage = FText::FromString(TEXT("Owner proxy is invalid."));
		return Result;
	}

	return GenericPropertyFramework::Private::ClearNodeValue(*OwnerProxy, InNode);
}
