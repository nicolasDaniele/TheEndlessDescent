#include "Player/TED_PlayerState.h"
#include "AbilitySystem/TED_AttributeSet_Base.h"
#include "AbilitySystem/TED_AbilitySystemComponent_Base.h"

ATED_PlayerState::ATED_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UTED_AbilitySystemComponent_Base>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UTED_AttributeSet_Base>("Attribute Set");

	NetUpdateFrequency = 100.0f;
}

UAbilitySystemComponent* ATED_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ATED_PlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
