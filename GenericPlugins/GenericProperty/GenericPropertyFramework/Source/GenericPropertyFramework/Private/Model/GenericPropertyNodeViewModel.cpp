#include "Model/GenericPropertyNodeViewModel.h"

void UGenericPropertyNodeViewModel::Initialize(UGenericPropertyValueHandleBase* InValueHandle, const FGenericPropertyDescriptor& InDescriptor, const FGenericPropertyState& InState)
{
	ValueHandle = InValueHandle;
	Descriptor = InDescriptor;
	State = InState;
}
