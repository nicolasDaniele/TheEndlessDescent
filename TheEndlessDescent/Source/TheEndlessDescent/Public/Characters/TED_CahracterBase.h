#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TED_CahracterBase.generated.h"

UCLASS()
class THEENDLESSDESCENT_API ATED_CahracterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ATED_CahracterBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;
};
