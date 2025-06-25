#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AbilitySystem/Data/DA_TED_CharacterClassInfo.h"
#include "TED_BlueprintFunctionLibrary.generated.h"

class UAbilitySystemComponent;

UCLASS()
class THEENDLESSDESCENT_API UTED_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Class Defaults")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject, EEnemyClass EnemyClass,
		float Level, UAbilitySystemComponent* AbilitySystemComponent);

	UFUNCTION(BlueprintCallable, Category = "Class Defaults")
	static void GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* AbilitySystemComponent);
};
