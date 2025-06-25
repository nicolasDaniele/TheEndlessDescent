#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "TED_AttributeSet_Base.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties() { }

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY() 
	UAbilitySystemComponent* SourceAbilitySystemComponent = nullptr;
	UPROPERTY() 
	AActor* SourceAvatarActor = nullptr;
	UPROPERTY() 
	AController* SourceController = nullptr;
	UPROPERTY() 
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY() 
	UAbilitySystemComponent* TargetAbilitySystemComponent = nullptr;
	UPROPERTY() 
	AActor* TargetAvatarActor = nullptr;
	UPROPERTY() 
	AController* TargetController = nullptr;
	UPROPERTY() 
	ACharacter* TargetCharacter = nullptr;
};

UCLASS()
class THEENDLESSDESCENT_API UTED_AttributeSet_Base : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UTED_AttributeSet_Base() { }

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Speed(const FGameplayAttributeData& OldSpeed) const;
	UFUNCTION()
	void OnRep_Attack(const FGameplayAttributeData& OldAttack) const;
	UFUNCTION()
	void OnRep_Defense(const FGameplayAttributeData& OldAttack) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UTED_AttributeSet_Base, Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UTED_AttributeSet_Base, MaxHealth);


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Speed)
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UTED_AttributeSet_Base, Speed);
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Attack)
	FGameplayAttributeData Attack;
	ATTRIBUTE_ACCESSORS(UTED_AttributeSet_Base, Attack);
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Defense)
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS(UTED_AttributeSet_Base, Defense);

	UPROPERTY(BlueprintReadOnly, Category = "Meta Attributes")
	FGameplayAttributeData IncomingDamage;
	ATTRIBUTE_ACCESSORS(UTED_AttributeSet_Base, IncomingDamage);

private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
