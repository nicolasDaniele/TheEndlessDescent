#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TED_EffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class THEENDLESSDESCENT_API ATED_EffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATED_EffectActor();

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

protected:
	virtual void BeginPlay() override;
};
