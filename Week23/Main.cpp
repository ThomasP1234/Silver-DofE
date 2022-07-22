#include "Game.h"

int main(void) {

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1440;
    const int screenHeight = 810;
    
    Game game(screenWidth, screenHeight, "Game");

    while(! game.GameShouldClose()){
        game.Tick();
    }

    return 0;
}