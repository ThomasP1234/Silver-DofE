#include "ElevensButton.h"

ElevensButton::ElevensButton(Image setCard, float setWidth, float setHeight, float setX, float setY, float setScale) {
    trueButton = false;
    scale = setScale;
    card = setCard;
    width = setWidth*scale;
    height = setHeight*scale;
    x = setX;
    y = setY;

    cardTexture = LoadTextureFromImage(card);

    UnloadImage(card);
}

void ElevensButton::draw() {
    if (trueButton == false) {
        DrawTextureEx(cardTexture, {x, y}, 0, scale, WHITE);
    }
    else {
        Button::draw();
    }
}

ElevensButton::~ElevensButton() {
    UnloadTexture(cardTexture);
}