#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "TED_AttributeSet_Base.generated.h"

UCLASS()
class THEENDLESSDESCENT_API UTED_AttributeSet_Base : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UTED_AttributeSet_Base();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
};
