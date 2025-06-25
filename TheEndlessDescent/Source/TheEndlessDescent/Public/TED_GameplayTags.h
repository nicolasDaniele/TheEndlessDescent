#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FTED_GameplayTags
{
public:
	static const FTED_GameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag Attribute_Health;
	FGameplayTag Attribute_MaxHealth;
	FGameplayTag Attribute_Speed;
	FGameplayTag Attribute_Attack;
	FGameplayTag Attribute_Defense;

	FGameplayTag Input_LMB;
	FGameplayTag Input_RMB;

	FGameplayTag Message_Item_HealthPotion;

	FGameplayTag Effect_Damage;
	FGameplayTag Effect_HitReact;

private:
	static FTED_GameplayTags GameplayTags;
};