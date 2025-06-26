#include "Characters/TED_Character_Player.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Player/TED_PlayerState.h"
#include "AbilitySystemComponent.h"

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
}

void ATED_Character_Player::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// On the Client
	InitAbilityActorInfo();
}

void ATED_Character_Player::InitAbilityActorInfo()
{
	ATED_PlayerState* TedPlayerState = GetPlayerState<ATED_PlayerState>();
	check(TedPlayerState);
	TedPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(TedPlayerState, this);

	}
	AbilitySystemComponent = TedPlayerState->GetAbilitySystemComponent();
	AttributeSet = TedPlayerState->GetAttributeSet();
}
