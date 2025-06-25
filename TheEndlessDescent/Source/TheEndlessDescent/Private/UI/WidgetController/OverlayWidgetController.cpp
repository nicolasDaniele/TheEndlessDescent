#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/TED_AttributeSet_Base.h"
#include "AbilitySystem/TED_AbilitySystemComponent_Base.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UTED_AttributeSet_Base* TedAttributeSet = CastChecked<UTED_AttributeSet_Base>(AttributeSet);

	OnHealthChanged.Broadcast(TedAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(TedAttributeSet->GetMaxHealth());
}

void UOverlayWidgetController::BindCallbacksDependencies()
{
	const UTED_AttributeSet_Base* TedAttributeSet = CastChecked<UTED_AttributeSet_Base>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TedAttributeSet->GetHealthAttribute())
		.AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(TedAttributeSet->GetMaxHealthAttribute())
		.AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);

	if (UTED_AbilitySystemComponent_Base* TedAbilitySystemComponent =
		Cast<UTED_AbilitySystemComponent_Base>(AbilitySystemComponent))
	{
		TedAbilitySystemComponent->OnEffectAssetTagsReceived.AddLambda(
			[this](const FGameplayTagContainer& AssetTags)
			{
				for (const FGameplayTag& Tag : AssetTags)
				{
					FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
					if (Tag.MatchesTag(MessageTag))
					{
						if (MessageWidgetDataTable == nullptr)
						{
							GEngine->AddOnScreenDebugMessage(-1, 6.f, FColor::Red, TEXT("ERROR: MessageWidgetDataTable is null"));
							return;
						}

						const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
						OnMessageWidgetRowReceived.Broadcast(*Row);
					}
				}
			});
	}
}