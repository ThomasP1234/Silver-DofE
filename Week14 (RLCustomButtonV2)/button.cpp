#include "button.h"

Button::Button() {}

Button::Button(const Button &btn) {
    this->width = btn.width;    
    this->height = btn.height;
    this->x = btn.x;
    this->y = btn.y;

    this->state = btn.state;
    this->btnActive = btn.btnActive;

    this->buttonColorN = btn.buttonColorN;
    this->buttonColorMH = btn.buttonColorMH;
    this->buttonColorP = btn.buttonColorP;
    this->buttonColorD = btn.buttonColorD;

    this->buttonText = btn.buttonText;
    this->textFontSize = btn.textFontSize;
    this->textFontSpacing = btn.textFontSpacing;
    this->textFont = btn.textFont;
    this->textColor = btn.textColor;
    this->textMeasure1 = btn.textMeasure1;
    this->callback = btn.callback;
}
Button::Button(float setWidth, float setHeight, float setX, float setY) {
    width = setWidth;
    height = setHeight;
    x = setX;
    y = setY;
}

void Button::registerCallback(void (*func)(Button *btn)) {
    callback = func;
}

void Button::geometry(float setWidth, float setHeight, float setX, float setY) {
    width = setWidth;
    height = setHeight;
    x = setX;
    y = setY;
}

void Button::update() {
    btnBounds = { x, y, width, height };
    mousePoint = GetMousePosition();

    if (btnActive == true) {
        // Check button state
        if (CheckCollisionPointRec(mousePoint, btnBounds)) {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) state = 2;
            else state = 1;

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) callback(this);
        }
        else state = 0;

        if (state == 0) {
        buttonColor = buttonColorN;
        }
        else if (state == 1) {
            buttonColor = buttonColorMH;
        }
        else if (state == 2) {
            buttonColor = buttonColorP;
        }
    }
    else {
        buttonColor = buttonColorD;
    }           

    sourceRec.y = state*height;
}

void Button::draw() {
    DrawRectangleRec(btnBounds, buttonColor);

    DrawTextEx(textFont, buttonText.c_str(), (Vector2){(width/2.0f) - textMeasure1.x/2 + x, (height/2.0f) - textMeasure1.y/2 + y }, textFontSize, textFontSpacing, textColor);            
}