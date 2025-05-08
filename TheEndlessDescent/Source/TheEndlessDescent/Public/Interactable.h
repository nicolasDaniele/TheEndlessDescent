#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class THEENDLESSDESCENT_API IInteractable
{
	GENERATED_BODY()

public:
	virtual void HighlightActor() = 0;
	virtual void UnhighlightActor() = 0;
};
