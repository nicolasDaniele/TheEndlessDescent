#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TED_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class THEENDLESSDESCENT_API ATED_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATED_PlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> TED_Context;
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const FInputActionValue& InputActionValue);
};
