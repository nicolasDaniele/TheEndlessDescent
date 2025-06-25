#include "AbilitySystem/TED_BlueprintFunctionLibrary.h"
#include "Game/TED_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "AbilitySystemComponent.h"

void UTED_BlueprintFunctionLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject, EEnemyClass EnemyClass,
	float Level, UAbilitySystemComponent* AbilitySystemComponent)
{
	ATED_GameMode* TedGameMode = Cast<ATED_GameMode>(UGameplayStatics::GetGameMode(WorldContextObject));
	if (TedGameMode == nullptr)
	{
		return;
	}

	AActor* AvatarActor = AbilitySystemComponent->GetAvatarActor();

	FEnemyClassDefaultInfo EnemyClassDefaultInfo = TedGameMode->EnemyClassInfo->GetEnemyClassDefaultInfo(EnemyClass);

	FGameplayEffectContextHandle DefaultAttributesContextHandle = AbilitySystemComponent->MakeEffectContext();
	DefaultAttributesContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle DefaultAttributesSpecHandle =  AbilitySystemComponent->MakeOutgoingSpec(
		EnemyClassDefaultInfo.DefaultAttributes, Level, DefaultAttributesContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*DefaultAttributesSpecHandle.Data.Get());
}

void UTED_BlueprintFunctionLibrary::GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* AbilitySystemComponent)
{
	ATED_GameMode* TedGameMode = Cast<ATED_GameMode>(UGameplayStatics::GetGameMode(WorldContextObject));
	if (TedGameMode == nullptr)
	{
		return;
	}

	UDA_TED_CharacterClassInfo* EnemyClassInfo = TedGameMode->EnemyClassInfo;
	for (TSubclassOf<UGameplayAbility> AbilityClass : EnemyClassInfo->CommonEnemyAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}