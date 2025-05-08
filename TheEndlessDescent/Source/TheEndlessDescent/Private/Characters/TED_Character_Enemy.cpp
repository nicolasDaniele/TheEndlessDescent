#include "Characters/TED_Character_Enemy.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/TED_AttributeSet_Base.h"

ATED_Character_Enemy::ATED_Character_Enemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UTED_AttributeSet_Base>("Attribute Set");
}

void ATED_Character_Enemy::BeginPlay()
{
	Super::BeginPlay();

	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
