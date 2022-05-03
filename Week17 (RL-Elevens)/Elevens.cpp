#include "Elevens.h"

Elevens::Elevens() {
    btnEventHandler = new ElevensButtonEventHandler(this);
    gameLogic();
    window();
}

void Elevens::gameLogic() {

}

void Elevens::window() {
    InitWindow(screenWidth, screenHeight, "Elevens");
    SetTargetFPS(60);

    Image img = LoadImage("./resources/deck/back.png");

    ElevensButton *btn = new ElevensButton(img, 124, 180, 50, 60, 1);
    btn->registerCallback(btnEventHandler);

    elevensBtnMgr.add(btn);

    Button *newbtn = new Button(20, 20, 200, 200);
    elevensBtnMgr.add(reinterpret_cast<ElevensButton*>(newbtn));
}

void Elevens::gameLoop() {
    while (!WindowShouldClose()){        
        update();
        draw();
    }
}

void Elevens::update() {
    elevensBtnMgr.update();
}

void Elevens::draw() {
    BeginDrawing();

        ClearBackground(backgroundColor);

        Vector2 pos;
        std::string text;

        text = "Elevens";
        pos = MeasureTextEx(GetFontDefault(), text.c_str(), 50.0, 2.0);
        DrawTextEx(GetFontDefault(), text.c_str(), {(screenWidth/2)-(pos.x/2), 10}, 50.0, 2.0, WHITE);

        elevensBtnMgr.draw();

        EndDrawing();
}

Elevens::~Elevens() {
    delete static_cast<ElevensButtonEventHandler*>(btnEventHandler);
    elevensBtnMgr.destroy();
    CloseWindow();
}