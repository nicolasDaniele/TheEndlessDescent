#include "TED_GameplayTags.h"
#include "GameplayTagsManager.h"

FTED_GameplayTags FTED_GameplayTags::GameplayTags;

void FTED_GameplayTags::InitializeNativeGameplayTags()
{
	// ATTRIBUTES
	GameplayTags.Attribute_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Health"),
		FString("The amount of damage the player can take before death"));

	GameplayTags.Attribute_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.MaxHealth"),
		FString("The maximum amount of health"));

	GameplayTags.Attribute_Speed = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Speed"),
		FString("The player's speed of movement"));

	GameplayTags.Attribute_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Attack"),
		FString("The amount of damage the player can apply to enemies"));

	GameplayTags.Attribute_Defense = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attribute.Defense"),
		FString("A percentage of reduction in the damage taken by the player"));


	// INPUTS
	GameplayTags.Input_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Input.LMB"),
		FString("Input for Left Mouse Button"));

	GameplayTags.Input_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Input.RMB"),
		FString("Input for Right Mouse Button"));


	// MESSAGES
	GameplayTags.Message_Item_HealthPotion = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Message.Item.HealthPotion"),
		FString("A potion that recovers an amount of health"));

	// EFFECTS
	GameplayTags.Effect_Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Effect.Damage"),
		FString("Amount of damage applied"));

	GameplayTags.Effect_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Effect.HitReact"),
		FString("Effect applied when hit"));
}