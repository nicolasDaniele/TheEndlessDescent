#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TED_Character_Base.generated.h"

UCLASS()
class THEENDLESSDESCENT_API ATED_Character_Base : public ACharacter
{
	GENERATED_BODY()

public:
	ATED_Character_Base();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;
};
