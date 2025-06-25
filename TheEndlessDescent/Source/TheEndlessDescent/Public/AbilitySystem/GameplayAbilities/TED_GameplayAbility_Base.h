#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "TED_GameplayAbility_Base.generated.h"

UCLASS()
class THEENDLESSDESCENT_API UTED_GameplayAbility_Base : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FGameplayTag StartupInputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Damage")
	FScalableFloat Damage;
};
