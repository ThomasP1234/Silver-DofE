#ifndef ELEVENS_BUTTON_EVENT_HANDLER_H
#define ELEVENS_BUTTON_EVENT_HANDLER_H
#include "button.h"
#include "ElevensButton.h"
#include "ButtonEventHandler.h"
#include "Elevens.h"

class Elevens;
class ElevensButton;
class ButtonEventHandler;
class ElevensButtonEventHandler : public ButtonEventHandler {
    private:
        Elevens *elevens;
    public:
        ElevensButtonEventHandler();
        ElevensButtonEventHandler(Elevens* setElevens);
        void invoke(Button *btn);
};
#endif