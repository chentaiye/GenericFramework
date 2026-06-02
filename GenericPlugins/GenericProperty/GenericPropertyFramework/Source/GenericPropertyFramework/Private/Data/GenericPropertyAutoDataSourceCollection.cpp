#include "Data/GenericPropertyAutoDataSourceCollection.h"

#include "Core/GenericPropertyReflection.h"
#include "Model/GenericPropertyProxy.h"

void UGenericPropertyAutoDataSourceCollection::BuildRootNodes(TArray<UGenericProperty*>& OutNodes)
{
	if (OwnerProxy == nullptr)
	{
		OutNodes.Reset();
		return;
	}

	GenericPropertyFramework::Private::BuildRootNodes(*OwnerProxy, OutNodes);
}

void UGenericPropertyAutoDataSourceCollection::RefreshNode(UGenericProperty& InNode) const
{
	GenericPropertyFramework::Private::RefreshNodeState(InNode);
}

void UGenericPropertyAutoDataSourceCollection::RebuildNodeChildren(UGenericProperty& InNode) const
{
	GenericPropertyFramework::Private::BuildDynamicChildren(InNode);
}
