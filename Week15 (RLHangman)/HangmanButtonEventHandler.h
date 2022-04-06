#ifndef HANGMAN_BUTTON_EVENT_HANDLER_H
#define HANGMAN_BUTTON_EVENT_HANDLER_H
#include "button.h"
#include "ButtonEventHandler.h"
#include "Hangman.h"

class Hangman;
class Button;
class ButtonEventHandler;
class HangmanButtonEventHandler : public ButtonEventHandler {
    private:
        Hangman *hangman;
    public:
        HangmanButtonEventHandler();
        HangmanButtonEventHandler(Hangman* hm);
        void invoke(Button *btn);
};
#endif