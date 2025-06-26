#include "Characters/TED_Character_Player.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Player/TED_PlayerState.h"
#include "AbilitySystemComponent.h"
#include "Player/TED_PlayerController.h"
#include "UI/HUD/TED_HUD.h"
#include "AbilitySystem/TED_AbilitySystemComponent_Base.h"

ATED_Character_Player::ATED_Character_Player()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);
	
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw= false;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ATED_Character_Player::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// On the Server
	InitAbilityActorInfo();
	AddCharacterStartupAbilities();
}

void ATED_Character_Player::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// On the Client
	InitAbilityActorInfo();
	AddCharacterStartupAbilities();
}

void ATED_Character_Player::InitAbilityActorInfo()
{
	ATED_PlayerState* TedPlayerState = GetPlayerState<ATED_PlayerState>();
	check(TedPlayerState);
	TedPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(TedPlayerState, this);

	if (UTED_AbilitySystemComponent_Base* TedAbilitySystemComponent = 
		Cast<UTED_AbilitySystemComponent_Base>(TedPlayerState->GetAbilitySystemComponent()))
	{
		TedAbilitySystemComponent->OnAbilityActorInfoSet();
	}
	
	AbilitySystemComponent = TedPlayerState->GetAbilitySystemComponent();
	AttributeSet = TedPlayerState->GetAttributeSet();

	
	if (ATED_PlayerController* TedPlayerController = Cast<ATED_PlayerController>(GetController()))
	{
		if (ATED_HUD* TedHUD = Cast<ATED_HUD>(TedPlayerController->GetHUD()))
		{
			TedHUD->InitOverlay(TedPlayerController, TedPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}

	InitializeAttributes();
}
