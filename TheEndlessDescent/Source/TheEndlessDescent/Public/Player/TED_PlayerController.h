#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TED_PlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
class UDA_TED_InputConfig;
class UTED_AbilitySystemComponent_Base;
struct FInputActionValue;
struct FGameplayTag;

UCLASS()
class THEENDLESSDESCENT_API ATED_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATED_PlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(BlueprintReadOnly)
	bool bShiftKeyDown = false;
private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> TED_Context;
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> RotateAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> ShiftAction;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UDA_TED_InputConfig> InputConfig;

	UPROPERTY()
	TObjectPtr<UTED_AbilitySystemComponent_Base> TedAbilitySystemComponent;

	void Move(const FInputActionValue& InputActionValue);
	void Rotate(const FVector2D& InputVector);
	void ShiftPressed();
	void ShiftReleased();

	void AbilityInputPressed(FGameplayTag InputTag);
	void AbilityInputReleased(FGameplayTag InputTag);
	void AbilityInputHeld(FGameplayTag InputTag);

	UTED_AbilitySystemComponent_Base* GetTedAbilitySystemComponent();
	
};
