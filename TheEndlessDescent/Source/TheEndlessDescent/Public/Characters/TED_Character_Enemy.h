#pragma once

#include "CoreMinimal.h"
#include "Characters/TED_Character_Base.h"
#include "Interactable.h"
#include "TED_Character_Enemy.generated.h"

UCLASS()
class THEENDLESSDESCENT_API ATED_Character_Enemy : public ATED_Character_Base, public IInteractable
{
	GENERATED_BODY()
	
public:
	ATED_Character_Enemy();

	virtual void HighlightActor() override { };
	virtual void UnhighlightActor() override { };

protected:
	virtual void BeginPlay() override;
};
