#include "raylib.h"
#include <string>

class Button {
    private:
        float width = 10.0;
        float height = 10.0;
        float x = 10.0; // Top Left Point
        float y = 10.0; // Top Right Point

        int state = 0; // 0 = Normal, 1 = Mouse Hovered, 2 = Pressed
        bool btnAction = false; // false = Unpressed, true = Pressed
        bool btnActive = true; // false = button cannot be pressed, true = button can be pressed
        
        Color buttonColor; // Current color
        Color buttonColorN = GREEN; // Color when normal
        Color buttonColorMH = BLUE; // Color when mouse is hovered
        Color buttonColorP = RED; // Color when pressed
        Color buttonColorD = GRAY; // Color when disabled

        Rectangle sourceRec;
        Rectangle btnBounds;
        Vector2 mousePoint;

        std::string buttonText = "";
        float textFontSize = 10.0;
        float textFontSpacing = 2.0;
        Font textFont = GetFontDefault();
        Color textColor = BLACK;
        Vector2 textMeasure1;

    public:
        void geometry(float setWidth, float setHeight, float setX, float setY) {
            width = setWidth;
            height = setHeight;
            x = setX;
            y = setY;
        }

        void color(Color setColorNormal, Color setColorMouseHover, Color setColorPressed, Color setColorDisabled) {
            buttonColorN = setColorNormal;
            buttonColorMH = setColorMouseHover;
            buttonColorP = setColorPressed;
            buttonColorD = setColorDisabled;
        }

        void text(std::string setText, float setFontSize, float setFontSpacing, Font setFont, Color setTextColor) {
            buttonText = setText;
            textFontSize = setFontSize;
            textFontSpacing = setFontSpacing;
            textFont = setFont;
            textColor = setTextColor;
            textMeasure1 = MeasureTextEx(textFont, buttonText.c_str(), textFontSize, textFontSpacing);
        }

        void active(bool setActive) {
            btnActive = setActive;
        }

        bool getActive() {
            return btnActive;
        }

        Color getColor() {
            return buttonColor;
        }

        Vector2 getPosition() {
            return (Vector2){x, y};
        }

        Vector2 getSize() {
            return (Vector2){width, height};
        }

        bool update() {
            btnBounds = { x, y, width, height };
            mousePoint = GetMousePosition();
            btnAction = false;

            if (btnActive == true) {
                // Check button state
                if (CheckCollisionPointRec(mousePoint, btnBounds)) {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) state = 2;
                    else state = 1;

                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAction = true;
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

            return btnAction;
        }

        void draw() {
            DrawRectangleRec(btnBounds, buttonColor);

            DrawTextEx(textFont, buttonText.c_str(), (Vector2){(width/2.0f) - textMeasure1.x/2 + x, (height/2.0f) - textMeasure1.y/2 + y }, textFontSize, textFontSpacing, textColor);            
        }
};

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Rectangle Button");
    SetTargetFPS(60);

    const Color backgroundColor = {48, 48, 48, 255};

    Button btn1;
    btn1.geometry(90.0, 30.0, 50.0, 20.0);
    btn1.color(GREEN, BLUE, RED, GRAY);
    btn1.text((std::string)"Hello", 20.0, 2.0, GetFontDefault(), BLACK);

    Button btn2;
    btn2.geometry(60.0, 40.0, 80.0, 200.0);
    btn2.color(BLUE, RED, GREEN, GRAY);
    btn2.text((std::string)"World", 20.0, 2.0, GetFontDefault(), BLACK);
    btn2.active(false);

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        bool action1 = btn1.update();
        bool action2 = btn2.update();

        if (action1 == true) {
            Vector2 pos1 = btn1.getPosition();
            Vector2 size1 = btn1.getSize();

            btn1.geometry(size1.x, size1.y, pos1.x+10, pos1.y+10);
        }
        
        if (action2 == true) {
            Vector2 pos2 = btn2.getPosition();
            Vector2 size2 = btn2.getSize();

            btn2.geometry(size2.x, size2.y, pos2.x+10, pos2.y+10);
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(backgroundColor);

            btn1.draw();
            btn2.draw();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();

    return 0;
}