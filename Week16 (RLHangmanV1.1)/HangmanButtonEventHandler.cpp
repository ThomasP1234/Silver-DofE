#include "button.h"
#include "ButtonEventHandler.h"
#include "HangmanButtonEventHandler.h"

HangmanButtonEventHandler::HangmanButtonEventHandler(){}

HangmanButtonEventHandler::HangmanButtonEventHandler(Hangman *hm) {
    hangman = hm;
}

void HangmanButtonEventHandler::invoke(Button *btn) {
    // ButtonEventHandler::invoke(btn);
    btn->active(false);
    hangman->setGuess(btn->getText());
}