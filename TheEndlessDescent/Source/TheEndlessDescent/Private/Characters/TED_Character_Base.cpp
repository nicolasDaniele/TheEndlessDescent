#include "Characters/TED_Character_Base.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/TED_AbilitySystemComponent_Base.h"
#include "Components/CapsuleComponent.h"
#include "TED.h"

ATED_Character_Base::ATED_Character_Base()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetGenerateOverlapEvents(false);
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_Projectile, ECR_Overlap);
	GetMesh()->SetGenerateOverlapEvents(true);
}

UAbilitySystemComponent* ATED_Character_Base::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* ATED_Character_Base::GetAttributeSet() const
{
	return AttributeSet;
}

void ATED_Character_Base::InitializeAttributes()
{
	check(IsValid(GetAbilitySystemComponent()));	
	if (DefaultAttributes == nullptr)
	{
		return;
	}

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultAttributes, 1.0f, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ATED_Character_Base::AddCharacterStartupAbilities()
{
	if (!HasAuthority())
	{
		return;
	}

	UTED_AbilitySystemComponent_Base* TedAbilitySystemComponent = CastChecked<UTED_AbilitySystemComponent_Base>(AbilitySystemComponent);
	TedAbilitySystemComponent->AddCharacterAbilities(StartupAbilities);
}

FVector ATED_Character_Base::GetCombatSocketLocation()
{
	return GetMesh()->GetSocketLocation(CombatSocketName);
}

UAnimMontage* ATED_Character_Base::GetHitReactMontage_Implementation()
{
	return HitReactMontage;
}

void ATED_Character_Base::Die()
{
	MulticastHandleDeath();
}

void ATED_Character_Base::MulticastHandleDeath_Implementation()
{
	GetMesh()->SetSimulatePhysics(true);
	GetMesh()->SetEnableGravity(true);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	GetMesh()->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}