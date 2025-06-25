#include "UI/HUD/TED_HUD.h"
#include "UI/Widgets/TED_UserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* ATED_HUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksDependencies();
	}

	return OverlayWidgetController;
}

void ATED_HUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class is uninitialized, please set it in BP_TedHUD"));
	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class is uninitialized, please set it in BP_TedHUD"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<UTED_UserWidget>(Widget);

	const FWidgetControllerParams Params(PC, PS, ASC, AS);
	UOverlayWidgetController* OWController = GetOverlayWidgetController(Params);

	OverlayWidget->SetWidgetController(OWController);
	OWController->BroadcastInitialValues();

	Widget->AddToViewport();
}