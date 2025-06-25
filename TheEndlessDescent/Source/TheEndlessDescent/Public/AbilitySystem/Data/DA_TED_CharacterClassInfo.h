#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_TED_CharacterClassInfo.generated.h"

class UGameplayEffect;
class UGameplayAbility;

UENUM(BlueprintType)
enum class ECharacterClass : uint8
{
	None,
	Mage,
	Warrior,
	Paladin,
	Archer
};

UENUM(BlueprintType)
enum class EEnemyClass : uint8
{
	None,
	RangeAttacker,
	MeleeAttacker
};

USTRUCT(BlueprintType)
struct FCharacterClassDefaultInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Class Defaults")
	TSubclassOf<UGameplayEffect> DefaultAttributes;
};

USTRUCT(BlueprintType)
struct FEnemyClassDefaultInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Class Defaults")
	TSubclassOf<UGameplayEffect> DefaultAttributes;
};

UCLASS()
class THEENDLESSDESCENT_API UDA_TED_CharacterClassInfo : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaults")
	TMap<ECharacterClass, FCharacterClassDefaultInfo> CharacterClassInformation;
	UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaults")
	TMap<EEnemyClass, FEnemyClassDefaultInfo> EnemyClassInformation;
	
	/*UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaults")
	TSubclassOf<UGameplayEffect> DefaultAttributes;*/
	
	UPROPERTY(EditDefaultsOnly, Category = "Common Class Defaults")
	TArray<TSubclassOf<UGameplayAbility>>  CommonEnemyAbilities;

	FCharacterClassDefaultInfo GetClassDefaultInfo(ECharacterClass CharacterClass);
	FEnemyClassDefaultInfo GetEnemyClassDefaultInfo(EEnemyClass EnemyClass);
};
