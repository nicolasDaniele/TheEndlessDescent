#include "AbilitySystem/TED_AttributeSet_Base.h"
#include "AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

UTED_AttributeSet_Base::UTED_AttributeSet_Base()
{

}

void UTED_AttributeSet_Base::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UTED_AttributeSet_Base, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UTED_AttributeSet_Base, MaxHealth, COND_None, REPNOTIFY_Always);
}

void UTED_AttributeSet_Base::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTED_AttributeSet_Base, Health, OldHealth);
}

void UTED_AttributeSet_Base::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTED_AttributeSet_Base, MaxHealth, OldMaxHealth);
}
