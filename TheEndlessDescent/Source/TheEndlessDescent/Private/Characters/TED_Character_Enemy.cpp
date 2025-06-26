#include "Characters/TED_Character_Enemy.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystem/TED_AbilitySystemComponent_Base.h"
#include "AbilitySystem/TED_AttributeSet_Base.h"
#include "Components/WidgetComponent.h"
#include "UI/Widgets/TED_UserWidget.h"
#include "AI/TED_AIController_Base.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TED_GameplayTags.h"
#include "AbilitySystem/TED_BlueprintFunctionLibrary.h"

ATED_Character_Enemy::ATED_Character_Enemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UTED_AbilitySystemComponent_Base>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UTED_AttributeSet_Base>("Attribute Set");

	HealthBar = CreateDefaultSubobject<UWidgetComponent>("Health Bar");
	HealthBar->SetupAttachment(GetRootComponent());

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->MaxWalkSpeed = BaseWalkSpeed;
}

void ATED_Character_Enemy::PossessedBy(AController* NewControler)
{
	Super::PossessedBy(NewControler);

	if (!HasAuthority())
	{
		return;
	}

	AIController = Cast<ATED_AIController_Base>(NewControler);
	AIController->GetBlackboardComponent()->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	AIController->RunBehaviorTree(BehaviorTree);
	AIController->GetBlackboardComponent()->SetValueAsBool(FName("HitReacting"), false);
	AIController->GetBlackboardComponent()->SetValueAsBool(FName("RangeAttacker"), EnemyClass == EEnemyClass::RangeAttacker);
}

int32 ATED_Character_Enemy::GetCharacterLevel()
{
	return CharacterLevel;
}

void ATED_Character_Enemy::Die()
{
	SetLifeSpan(LifeSpan);

	Super::Die();
}

void ATED_Character_Enemy::BeginPlay()
{
	Super::BeginPlay();

	check(AbilitySystemComponent);
	InitAbilityActorInfo();
	UTED_BlueprintFunctionLibrary::GiveStartupAbilities(this, AbilitySystemComponent);

	if (UTED_UserWidget * TedUserWidget = Cast<UTED_UserWidget>(HealthBar->GetUserWidgetObject()))
	{
		TedUserWidget->SetWidgetController(this);
	}

	if (UTED_AttributeSet_Base* TedAttributeSet = Cast<UTED_AttributeSet_Base>(AttributeSet))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TedAttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TedAttributeSet->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);

		AbilitySystemComponent->RegisterGameplayTagEvent(FTED_GameplayTags::Get().Effect_HitReact,
			EGameplayTagEventType::NewOrRemoved).AddUObject(this, &ATED_Character_Enemy::HitReactTagChanged);

		OnHealthChanged.Broadcast(TedAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(TedAttributeSet->GetMaxHealth());
	}
}

void ATED_Character_Enemy::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	
	if (UTED_AbilitySystemComponent_Base* TedAbilitySystemComponent =
		Cast<UTED_AbilitySystemComponent_Base>(AbilitySystemComponent))
	{
		TedAbilitySystemComponent->OnAbilityActorInfoSet();
	}

	InitializeAttributes();
}

void ATED_Character_Enemy::InitializeAttributes()
{
	UTED_BlueprintFunctionLibrary::InitializeDefaultAttributes(this, EnemyClass, CharacterLevel, AbilitySystemComponent);
}

void ATED_Character_Enemy::HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount)
{
	bHitReacting = NewCount > 0;
	GetCharacterMovement()->MaxWalkSpeed = bHitReacting ? 0.0f : BaseWalkSpeed;
	AIController->GetBlackboardComponent()->SetValueAsBool(FName("HitReacting"), bHitReacting);
}