#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TED_AIController_Base.generated.h"

class UBehaviorTreeComponent;

UCLASS()
class THEENDLESSDESCENT_API ATED_AIController_Base : public AAIController
{
	GENERATED_BODY()
	
public:
	ATED_AIController_Base();

protected:
	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;
};
