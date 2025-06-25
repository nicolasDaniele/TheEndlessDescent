#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TED_GameMode.generated.h"

class UDA_TED_CharacterClassInfo;

UCLASS()
class THEENDLESSDESCENT_API ATED_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaults")
	TObjectPtr<UDA_TED_CharacterClassInfo> EnemyClassInfo;
};
