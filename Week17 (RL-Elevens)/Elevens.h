#ifndef ELEVENS_H
#define ELEVENS_H

#include <raylib.h>
#include <string>

#include "ElevensButtonManager.h"
#include "ElevensButton.h"
#include "button.h"
#include "ElevensButtonEventHandler.h"

class Elevens {
    public:
        const int screenWidth = 800; // Window geometry
        const int screenHeight = 450;
        Color backgroundColor = {48, 48, 48, 255}; // Grey Colour
        ElevensButtonManager elevensBtnMgr;
        ButtonEventHandler *btnEventHandler;

        Elevens();

        void gameLogic();
        void window();

        void gameLoop();
        void draw();
        void update();

        ~Elevens();
};

#endif