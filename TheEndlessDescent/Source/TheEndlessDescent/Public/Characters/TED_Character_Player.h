#pragma once

#include "CoreMinimal.h"
#include "Characters/TED_Character_Base.h"
#include "TED_Character_Player.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class THEENDLESSDESCENT_API ATED_Character_Player : public ATED_Character_Base
{
	GENERATED_BODY()
	
public:
	ATED_Character_Player();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;
	UPROPERTY(EditDefaultsOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> Camera;

private:
	void InitAbilityActorInfo();
};
