#include "Elevens.h"

int main(void) {
    Elevens *Game = new Elevens;
    Game->gameLoop();
    delete Game;

    return 0;
}