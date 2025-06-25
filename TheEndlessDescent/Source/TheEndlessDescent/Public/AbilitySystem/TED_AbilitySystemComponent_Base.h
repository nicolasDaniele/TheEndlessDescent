#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "TED_AbilitySystemComponent_Base.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTagsReceivedSignature, const FGameplayTagContainer& /*AssetTags*/);

UCLASS()
class THEENDLESSDESCENT_API UTED_AbilitySystemComponent_Base : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void OnAbilityActorInfoSet();
	void AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& Abilities);
	
	void AbilityInputTagHeld(const FGameplayTag& InputTag);
	void AbilityInputTagReleased(const FGameplayTag& InputTag);

	FEffectAssetTagsReceivedSignature OnEffectAssetTagsReceived;

protected:
	UFUNCTION()
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec,
		FActiveGameplayEffectHandle ActiveEffectHandle);
};
