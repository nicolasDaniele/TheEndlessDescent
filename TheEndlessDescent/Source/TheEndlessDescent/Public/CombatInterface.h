#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CombatInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UCombatInterface : public UInterface
{
	GENERATED_BODY()
};

class UAnimMontage;

class THEENDLESSDESCENT_API ICombatInterface
{
	GENERATED_BODY()

public:
	virtual int32 GetCharacterLevel();
	virtual FVector GetCombatSocketLocation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UAnimMontage* GetHitReactMontage();
	virtual void Die() = 0;
};
