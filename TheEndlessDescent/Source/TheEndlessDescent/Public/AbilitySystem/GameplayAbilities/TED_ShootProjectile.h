#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GameplayAbilities/TED_GameplayAbility_Base.h"
#include "TED_ShootProjectile.generated.h"

class ATED_Projectile_Base;

UCLASS()
class THEENDLESSDESCENT_API UTED_ShootProjectile : public UTED_GameplayAbility_Base
{
	GENERATED_BODY()

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SpawnProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ATED_Projectile_Base> ProjectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;
};