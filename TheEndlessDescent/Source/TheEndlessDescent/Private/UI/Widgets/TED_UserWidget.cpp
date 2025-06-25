#include "UI/Widgets/TED_UserWidget.h"

void UTED_UserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;

	WidgetControllerSet();
}