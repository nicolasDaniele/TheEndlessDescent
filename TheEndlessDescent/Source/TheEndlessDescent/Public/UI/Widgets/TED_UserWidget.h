#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TED_UserWidget.generated.h"


UCLASS()
class THEENDLESSDESCENT_API UTED_UserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

	UFUNCTION(BlueprintCallable)
	void SetWidgetController(UObject* InWidgetController);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
