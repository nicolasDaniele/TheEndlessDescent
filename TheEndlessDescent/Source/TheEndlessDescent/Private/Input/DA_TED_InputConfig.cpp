#include "Input/DA_TED_InputConfig.h"

const UInputAction* UDA_TED_InputConfig::FindAbilityInputActionFirTag(const FGameplayTag& InputTag, bool bLogNotfound) const
{
	for (FTED_InputAction Action : InputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	if (bLogNotfound)
	{
		UE_LOG(LogTemp, Error, TEXT("Cannot find AbilityInputAction for Tag %s, or InputCongif %s"),
			*InputTag.ToString(), *GetNameSafe(this));
	}

	return nullptr;
}