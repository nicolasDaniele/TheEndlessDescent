#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "TED_Character_Base.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class THEENDLESSDESCENT_API ATED_Character_Base : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATED_Character_Base();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const;

protected:
	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr <UAttributeSet> AttributeSet;
};
