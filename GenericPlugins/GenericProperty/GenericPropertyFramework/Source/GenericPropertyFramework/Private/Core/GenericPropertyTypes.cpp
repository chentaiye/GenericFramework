#include "Core/GenericPropertyTypes.h"

FString FGenericPropertyAccessPath::ToString() const
{
	TStringBuilder<256> Builder;

	for (const FGenericPropertyAccessSegment& Segment : Segments)
	{
		if (Builder.Len() > 0)
		{
			Builder.Append(TEXT("."));
		}

		switch (Segment.Type)
		{
		case EGenericPropertyAccessType::Property:
			Builder.Append(Segment.PropertyName.ToString());
			break;

		case EGenericPropertyAccessType::ArrayElement:
			Builder.Appendf(TEXT("[%d]"), Segment.ElementIndex);
			break;

		case EGenericPropertyAccessType::SetElement:
			Builder.Appendf(TEXT("{%d}"), Segment.ElementIndex);
			break;

		case EGenericPropertyAccessType::MapKey:
			Builder.Appendf(TEXT("<%d>.Key"), Segment.ElementIndex);
			break;

		case EGenericPropertyAccessType::MapValue:
			Builder.Appendf(TEXT("<%d>.Value"), Segment.ElementIndex);
			break;
		}
	}

	return Builder.ToString();
}
