#ifndef BUTTON_EVENT_HANDLER_H
#define BUTTON_EVENT_HANDLER_H
#include <string>
#include "button.h"
#include <list>

class Button;

class ButtonEventHandler {
    public:
        ButtonEventHandler();
        virtual void invoke(Button *btn) = 0;
};
#endif