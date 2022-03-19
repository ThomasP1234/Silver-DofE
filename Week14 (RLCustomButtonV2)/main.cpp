#include "raylib.h"
#include <string>
#include "button.h"
#include "button.cpp"
#include "buttonManager.h"
#include "buttonManager.cpp"

void btn_cb(Button *btn) {
    Vector2 pos1 = btn->getPosition();
    Vector2 size1 = btn->getSize();

    btn->geometry(size1.x, size1.y, pos1.x+10, pos1.y+10);
}

int main(void)
{    
    // Initialization
    //--------------------------------------------------------------------------------------

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Rectangle Button");
    SetTargetFPS(60);

    const Color backgroundColor = {48, 48, 48, 255};

    ButtonManager btnMgr;

    Button btn1(90.0, 30.0, 50.0, 20.0);
    btn1.color(GREEN, BLUE, RED, GRAY);
    btn1.text((std::string)"Hello", 20.0, 2.0, GetFontDefault(), BLACK);
    btn1.registerCallback(&btn_cb);

    Button btn2;
    btn2.geometry(60.0, 40.0, 80.0, 200.0);
    btn2.color(BLUE, RED, GREEN, GRAY);
    btn2.text((std::string)"World", 20.0, 2.0, GetFontDefault(), BLACK);
    btn2.active(false);
    btn2.registerCallback(&btn_cb);

    Button btn3(btn2);
    btn2.geometry(60, 40.0, 100.0, 50.0);

    btnMgr.add(&btn1);
    btnMgr.add(&btn2);
    btnMgr.add(&btn3);

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------

        btnMgr.update();

        // Draw
        //----------------------------------------------------------------------------------
        
        BeginDrawing();

            ClearBackground(backgroundColor);

            btnMgr.draw();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();

    return 0;
}