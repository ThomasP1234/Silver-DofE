#include "Hangman.h"

int main(void) {
    Hangman *Game = new Hangman;
    Game->gameLoop();
    delete Game;

    return 0;
}