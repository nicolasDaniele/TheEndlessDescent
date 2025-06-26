#pragma once

#include "CoreMinimal.h"
#include "Characters/TED_Character_Base.h"
#include "UI/WidgetController/OverlayWidgetController.h"
#include "GameplayTagContainer.h"
#include "AbilitySystem/Data/DA_TED_CharacterClassInfo.h"
#include "TED_Character_Enemy.generated.h"

class UBehaviorTree;
class ATED_AIController_Base;
class UWidgetComponent;

UCLASS()
class THEENDLESSDESCENT_API ATED_Character_Enemy : public ATED_Character_Base
{
	GENERATED_BODY()
	
public:
	ATED_Character_Enemy();
	
	virtual void PossessedBy(AController* NewControler) override;
	virtual int32 GetCharacterLevel() override;
	virtual void Die() override;

	UPROPERTY(BlueprintAssignable)
	FAttributeChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FAttributeChangedSignature OnMaxHealthChanged;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
	virtual void InitializeAttributes() override;

	void HitReactTagChanged(const FGameplayTag CallbackTag, int32 NewCount);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 CharacterLevel = 1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
	UPROPERTY(BlueprintReadOnly, Category = "Combat")
	bool bHitReacting = false;
	UPROPERTY(EditAnywhere, Category = "Combat")
	float LifeSpan = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	EEnemyClass EnemyClass = EEnemyClass::None;

	UPROPERTY(EditAnywhere, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;
	UPROPERTY()
	TObjectPtr<ATED_AIController_Base> AIController;
	UPROPERTY(EditAnywhere, Category = "AI")
	float BaseWalkSpeed = 400.0f;
};
