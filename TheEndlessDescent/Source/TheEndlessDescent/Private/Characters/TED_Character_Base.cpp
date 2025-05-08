#include "Characters/TED_Character_Base.h"

ATED_Character_Base::ATED_Character_Base()
{
	PrimaryActorTick.bCanEverTick = false;
}

UAbilitySystemComponent* ATED_Character_Base::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ATED_Character_Base::GetAttributeSet() const
{
	return AttributeSet;
}