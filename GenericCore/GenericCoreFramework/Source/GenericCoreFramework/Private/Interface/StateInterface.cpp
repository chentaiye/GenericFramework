// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Interface/StateInterface.h"

#include "CoreType.h"

void IStateInterface::NativeOnCreate()
{
	if (UObject* Object = Cast<UObject>(this))
	{
		IStateInterface::Execute_HandleOnCreate(Object);
	}
}

void IStateInterface::NativeOnActived()
{
	if (UObject* Object = Cast<UObject>(this))
	{
		IStateInterface::Execute_HandleOnActived(Object);
	}
}

void IStateInterface::NativeOnActivedFinish()
{
	if (UObject* Object = Cast<UObject>(this))
	{
		OnActivedFinishEvent.Broadcast(Object);
		IStateInterface::Execute_HandleOnActivedFinish(Object);
	}
}

void IStateInterface::NativeOnInactived()
{
	if (UObject* Object = Cast<UObject>(this))
	{
		OnInactivedFinishEvent.Broadcast(Object);
		IStateInterface::Execute_HandleOnInactived(Object);
	}
}

void IStateInterface::NativeOnInactivedFinish()
{
	if (UObject* Object = Cast<UObject>(this))
	{
		IStateInterface::Execute_HandleOnInactivedFinish(Object);
	}
}

void IStateInterface::NativeOnDestroy()
{
	if (UObject* Object = Cast<UObject>(this))
	{
		IStateInterface::Execute_HandleOnDestroy(Object);
	}
}

bool IStateInterface::GetIsActived() const
{
	return bIsActived;
}

void IStateInterface::SetIsActived(const bool InActived)
{
	if (bIsActived != InActived)
	{
		bIsActived = InActived;

		if (bIsActived)
		{
			NativeOnActived();
		}
		else
		{
			NativeOnInactived();
		}
	}
}
