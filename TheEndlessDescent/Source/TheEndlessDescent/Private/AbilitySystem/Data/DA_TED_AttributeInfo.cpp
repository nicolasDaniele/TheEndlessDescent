#include "AbilitySystem/Data/DA_TED_AttributeInfo.h"

FTED_AttributeInfo UDA_TED_AttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FTED_AttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag == AttributeTag)
		{
			return Info;
		}
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("DA_TED_AttributeInfo: Cannot find Info for AttributeTag %s on AttributeInfo %s"),
			*AttributeTag.ToString(), *GetNameSafe(this));
	}

	return FTED_AttributeInfo();
}
