#pragma once
#include <raylib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

#include "elevensButtonManager.h"
#include "elevensButton.h"
#include "button.h"
#include "elevensButtonEventHandler.h"

class Elevens {
    private:
        static Elevens *instance;
        Elevens();

    public:
        static Elevens *getInstance() {
            if (!instance) {
                instance = new Elevens;
            }
            return instance;
        }

    public:
        const int screenWidth = 800; // Window geometry
        const int screenHeight = 450;
        Color backgroundColor = {48, 48, 48, 255}; // Grey Colour
        ElevensButtonManager elevensBtnMgr;
        ButtonEventHandler *btnEventHandler;
        std::vector<std::string> deck;

    public:
        void gameLogic();
        void window();

        void newButton();

        void gameLoop();
        void draw();
        void update();

        ~Elevens();
};