#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "DA_TED_InputConfig.generated.h"

class UInputAction;

USTRUCT(BlueprintType)
struct FTED_InputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	UInputAction* InputAction = nullptr;
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();
};

UCLASS()
class THEENDLESSDESCENT_API UDA_TED_InputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	const UInputAction* FindAbilityInputActionFirTag(const FGameplayTag& InputTag, bool bLogNotfound = false) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FTED_InputAction> InputActions;
};
