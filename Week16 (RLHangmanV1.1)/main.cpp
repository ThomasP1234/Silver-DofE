#include <iostream>
#include "Hangman.h"

int main(void) {
    std::cout << "Hello" << std::endl;
    Hangman *Game = new Hangman;
    Game->gameLoop();
    delete Game;

    return 0;
}