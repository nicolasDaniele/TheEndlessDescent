#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "TED_EffectApplierActor.generated.h"

UENUM(BlueprintType)
enum class EEffectApplicationPolicy : uint8
{
	DoNotApply,
	ApplyOnOverlap,
	ApplyOnEndOverlap
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy : uint8
{
	DoNotRemove,
	RemoveOnEndOverlap
};

class UGameplayEffect;

UCLASS(Blueprintable)
class THEENDLESSDESCENT_API ATED_EffectApplierActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATED_EffectApplierActor();

protected:
	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* EffectTarget);
	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* EffectTarget);
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* EffectTarget, TSubclassOf<UGameplayEffect> GameplayEffectClass);


	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Gameplay Effects")
	bool bDestroyOnEffectApplication = false;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Gameplay Effects")
	bool bApplyEffectsToEnemies = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Gameplay Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Gameplay Effects")
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Gameplay Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Gameplay Effects")
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Gameplay Effects")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Gameplay Effects")
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Gameplay Effects")
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::DoNotRemove;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;

	UPROPERTY()
	float ActorLevel = 1.0f;
};
