#include "Player/TED_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Input/DA_TED_InputConfig.h"
#include "Input/TED_EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "AbilitySystem/TED_AbilitySystemComponent_Base.h"
#include "AbilitySystemBlueprintLibrary.h"

ATED_PlayerController::ATED_PlayerController()
{
	bReplicates = true;
}

void ATED_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(TED_Context);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(TED_Context, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ATED_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UTED_EnhancedInputComponent* TedEnhancedInputComponent = CastChecked<UTED_EnhancedInputComponent>(InputComponent);

	TedEnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ATED_PlayerController::Move);
	TedEnhancedInputComponent->BindAction(ShiftAction, ETriggerEvent::Started, this, &ATED_PlayerController::ShiftPressed);
	TedEnhancedInputComponent->BindAction(ShiftAction, ETriggerEvent::Completed, this, &ATED_PlayerController::ShiftReleased);

	TedEnhancedInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputPressed, &ThisClass::AbilityInputReleased, &ThisClass::AbilityInputHeld);
}

void ATED_PlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator YawRotation(0.0f, GetControlRotation().Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void ATED_PlayerController::Rotate(const FVector2D& InputVector)
{
	GEngine->AddOnScreenDebugMessage(1, 0.1f, FColor::Emerald,
		FString::Printf(TEXT("Mouse X: %f | Mouse Y: %f"), InputVector.X, InputVector.Y));


	//SetControlRotation(InputVector);
}

void ATED_PlayerController::ShiftPressed()
{
	bShiftKeyDown = true;
}

void ATED_PlayerController::ShiftReleased()
{
	bShiftKeyDown = false;
}

void ATED_PlayerController::AbilityInputPressed(FGameplayTag InputTag)
{

}

void ATED_PlayerController::AbilityInputReleased(FGameplayTag InputTag)
{
	if (GetTedAbilitySystemComponent() == nullptr)
	{
		return;
	}

	GetTedAbilitySystemComponent()->AbilityInputTagReleased(InputTag);
}

void ATED_PlayerController::AbilityInputHeld(FGameplayTag InputTag)
{
	if (GetTedAbilitySystemComponent() == nullptr)
	{
		return;
	}

	GetTedAbilitySystemComponent()->AbilityInputTagHeld(InputTag);
}

UTED_AbilitySystemComponent_Base* ATED_PlayerController::GetTedAbilitySystemComponent()
{
	if (TedAbilitySystemComponent == nullptr)
	{
		TedAbilitySystemComponent = Cast<UTED_AbilitySystemComponent_Base>(
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	
	return TedAbilitySystemComponent;
}