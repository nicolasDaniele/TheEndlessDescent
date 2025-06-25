#include "AbilitySystem/GameplayAbilities/TED_ShootProjectile.h"
#include "Actors/TED_Projectile_Base.h"
#include "CombatInterface.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "TED_GameplayTags.h"

void UTED_ShootProjectile::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);	
}

void UTED_ShootProjectile::SpawnProjectile()
{
	if (ProjectileClass == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Red, TEXT("Error: ProjectileClass is null (UTED_ShootProjectile::SpawnProjectile)"));
		return;
	}
	
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
	if (!bIsServer)
	{
		return;
	}

	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if (!CombatInterface)
	{
		return;
	}

	const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
	const FQuat ForwardRotation = GetAvatarActorFromActorInfo()->GetActorForwardVector().Rotation().Quaternion();
	FTransform SpawnTransform;
	SpawnTransform.SetLocation(SocketLocation);
	SpawnTransform.SetRotation(ForwardRotation);

	ATED_Projectile_Base* Projectile = GetWorld()->SpawnActorDeferred<ATED_Projectile_Base>(ProjectileClass, SpawnTransform, GetOwningActorFromActorInfo(),
		Cast<APawn>(GetOwningActorFromActorInfo()), ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	const UAbilitySystemComponent* SourceAbilitySystemComponent = 
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetAvatarActorFromActorInfo());
	const FGameplayEffectSpecHandle SpecHandle = SourceAbilitySystemComponent->MakeOutgoingSpec(DamageEffectClass,
		GetAbilityLevel(), SourceAbilitySystemComponent->MakeEffectContext());

	FTED_GameplayTags GameplayTags = FTED_GameplayTags::Get();
	const float ScaledDamage = Damage.GetValueAtLevel(GetAbilityLevel());
	UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(SpecHandle, GameplayTags.Effect_Damage, ScaledDamage);
	Projectile->DamageSpecHandle = SpecHandle;

	Projectile->FinishSpawning(SpawnTransform);
}