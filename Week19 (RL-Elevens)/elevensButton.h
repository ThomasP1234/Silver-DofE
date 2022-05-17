#pragma once

#include <raylib.h>
#include "button.h"

class Button;
class ElevensButton : public Button {
    private:
        // using Button::color; // "hides" these functions as they are not needed
        // using Button::text;
        // using Button::getColor;
        // using Button::getText;

        Image card;
        Texture2D cardTexture;

        float scale = 1;
    public:
        ElevensButton(Image setCard, float setWidth, float setHeight, float setX, float setY, float setScale);

        void draw();

        ~ElevensButton();
};
