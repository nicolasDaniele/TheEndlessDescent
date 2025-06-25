#include "AbilitySystem/TED_AbilitySystemComponent_Base.h"
#include "AbilitySystem/GameplayAbilities/TED_GameplayAbility_Base.h"

void UTED_AbilitySystemComponent_Base::OnAbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UTED_AbilitySystemComponent_Base::EffectApplied);
}

void UTED_AbilitySystemComponent_Base::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& Abilities)
{
	for (const TSubclassOf<UGameplayAbility> AbilityClass : Abilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
		if (const UTED_GameplayAbility_Base* TedAbility = Cast<UTED_GameplayAbility_Base>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(TedAbility->StartupInputTag);
			GiveAbility(AbilitySpec);
		}
	}
}

void UTED_AbilitySystemComponent_Base::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())
	{
		return;
	}

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec);
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UTED_AbilitySystemComponent_Base::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())
	{
		return;
	}

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}

void UTED_AbilitySystemComponent_Base::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec,
	FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	OnEffectAssetTagsReceived.Broadcast(TagContainer);
}