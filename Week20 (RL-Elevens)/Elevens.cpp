#include "Elevens.h"
#include <iostream>

Elevens::Elevens() {
    btnEventHandler = new ElevensButtonEventHandler(this);
    ((ElevensButtonEventHandler*)btnEventHandler)->registerButtonManager(&elevensBtnMgr);

    btnEventHandlerDraw = new ElevensButtonEventHandlerDrawCard(this);
    ((ElevensButtonEventHandlerDrawCard*)btnEventHandler)->registerButtonManager(&elevensBtnMgr);
    gameLogic();
    window();
}

void Elevens::gameLogic() {
    {
        std::vector<std::string> suits = {"club", "diamond", "heart", "spade"};
        std::vector<std::string> values = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
        for (std::string suit : suits) {
            for (std::string value : values) {
                deck.push_back(suit+value);
            }
        }

        std::shuffle(deck.begin(), deck.end(), std::random_device());

        // std::cout << "deck = { ";
        // for (std::string n : deck) {
        //     std::cout << n << ", ";
        // }
        // std::cout << "}; \n";
    }
}

void Elevens::newButton() {
    if (row < 3 && column < 3) {
        if (!deck.empty()) {
            std::string file = "./resources/deck/" + deck.front() + ".png";

            // deck.push_back(deck[0]);
            deck.erase(deck.begin());

            // std::cout << file << std::endl;

            Image img = LoadImage(file.c_str());

            ElevensButton *btn = new ElevensButton(img, 124, 180, float(row*150+50), float(column*206+60), 1);
            btn->registerCallback(btnEventHandler);

            elevensBtnMgr.add(btn);

            row++;

            if (row > 2) {
                row = 0;
                column++;
            }
        }
    }
}

void Elevens::window() {
    InitWindow(screenWidth, screenHeight, "Elevens");
    SetTargetFPS(60);

    newButton();
    Button *drawCard = new Button(424, 40, 50, 669);
    drawCard->registerCallback(btnEventHandlerDraw);
    drawCard->text("Deal a Card", 40, 2, GetFontDefault(), BLACK);
    elevensBtnMgr.add(drawCard);

    // Button *newbtn = new Button(20, 20, 200, 200);
    // elevensBtnMgr.add(reinterpret_cast<ElevensButton*>(newbtn));
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
    delete static_cast<ElevensButtonEventHandlerDrawCard*>(btnEventHandlerDraw);
    elevensBtnMgr.destroy();
    CloseWindow();
}