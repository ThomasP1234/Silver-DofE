#include "raylib.h"
#include <string>
#include <iostream>
#include <list>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "button.h"
#include "buttonManager.h"
#include "HangmanButtonEventHandler.h"
#include "Hangman.h"

Hangman::Hangman() {
    btnEventHandler = new HangmanButtonEventHandler(this);
    gameLogic();
    window();
}

void Hangman::gameLogic() {
    srand((unsigned) std::time(NULL)); // Initilize the pseudo-random number generator with a seed determined by the system clock

    std::fstream HangmanFile("Hangmanlist.txt"); // Read in the possible solutions

    while (std::getline(HangmanFile, mytxt)) {
        mylst.push_back(mytxt); // Add them all to an STL list
    }

    random = 0+(rand()%(mylst.size()-1)); // Generate a random interger between 0 and the last index of the array

    it = mylst.begin();
    std::advance(it, random);
    answer = *it; // Get the answer
    answerUpper = answer;

    std::for_each(answerUpper.begin(), answerUpper.end(), [](char &c) {
        c = toupper(c); // Get the answer in uppercase
    });

    std::list<char> solutionLetters;

    std::for_each(answerUpper.begin(), answerUpper.end(), [&solutionLetters](char &d) {
        int ascii = d;
        if (ascii >=65 && ascii <= 90) {
            if ((std::find(solutionLetters.begin(), solutionLetters.end(), d) != solutionLetters.end()) == false) {
                solutionLetters.push_back(d); // Find all the unique letters and add them to an STL list
            }
        }
    });

    solutionLetterCount = solutionLetters.size();
}

void Hangman::window() {
    InitWindow(screenWidth, screenHeight, "Hangman");
    SetTargetFPS(60);

    for( char i = 'A'; i<='Z'; ++i) { // Create 26 buttons each with a different letter of the alphabet
        Button *btn = new Button(50.0, 20.0, -20+60*(row), 100+40*(column));
        btn->color(WHITE, LIGHTGRAY, GRAY, GRAY);
        std::string s(1, i);
        btn->text(s, 20.0, 2.0, GetFontDefault(), BLACK);
        // btn->registerCallback(&btn_cb);
        btn->registerCallback(btnEventHandler);
        btnMgr.add(btn);
        // buttons[i] = btn;

        if (row == 5) {
            row = 1;
            column += 1;
        }
        else row++;
    };
}

void Hangman::gameLoop() {
    while (!WindowShouldClose()){        
        update();
        draw();
    }
}

void Hangman::update() {
    btnMgr.update();

    puzzle = "";

    std::for_each(answerUpper.begin(), answerUpper.end(), [this](char &d) {
        int ascii = d;
        if (ascii >= 65 && ascii <= 90) {
            if ((std::find(validLetters.begin(), validLetters.end(), d) != validLetters.end()) == true || end == true) {
                puzzle += d;
            }
            else {
                puzzle += "–";
            }
        }
        else {
            puzzle += d;
        }
    });

    if (end == false) {
        std::size_t found = answerUpper.find(guess);
        if (found!=std::string::npos) {
            validLetters.push_back(guess[0]);
            validLettersStr += guess;
            if ((unsigned int)solutionLetterCount == validLettersStr.size()) {
                std::list<Button *> btns = btnMgr.get();
                for (Button *btn : btns) {
                    btn->color(WHITE, LIGHTGRAY, GRAY, GREEN);
                    btn->active(false);
                    end = true;
                }
            }
        }
        else {
            invalidLetters.push_back(guess[0]);
            invalidLettersStr += guess;
        }

        if (invalidLetters.size() >= (unsigned int)lives) {
            std::list<Button *> btns = btnMgr.get();
            for (Button *btn : btns) {
                btn->color(WHITE, LIGHTGRAY, GRAY, RED);
                btn->active(false);
                end = true;
            }
        }
    }
    guess = "";
}

void Hangman::draw() {
    BeginDrawing();

        ClearBackground(backgroundColor);

        Vector2 pos;
        std::string text;

        text = "Hangman";
        pos = MeasureTextEx(GetFontDefault(), text.c_str(), 50.0, 2.0);
        DrawTextEx(GetFontDefault(), text.c_str(), {(screenWidth/2)-(pos.x/2), 10}, 50.0, 2.0, WHITE);

        text = puzzle;
        pos = MeasureTextEx(GetFontDefault(), text.c_str(), 30.0, 2.0);
        DrawTextEx(GetFontDefault(), text.c_str(), {(screenWidth/2)-(pos.x/2), 75}, 30.0, 2.0, WHITE);

        text = "Bad Guesses:\n" + invalidLettersStr;
        pos = MeasureTextEx(GetFontDefault(), text.c_str(), 20.0, 2.0);
        DrawTextEx(GetFontDefault(), text.c_str(), {(screenWidth/4)-(pos.x/2)+(screenWidth/2), 140}, 20.0, 2.0, WHITE);

        text = "Lives: " + std::to_string(lives-invalidLetters.size());
        pos = MeasureTextEx(GetFontDefault(), text.c_str(), 20.0, 2.0);
        DrawTextEx(GetFontDefault(), text.c_str(), {(screenWidth/4)-(pos.x/2)+(screenWidth/2), 200}, 20.0, 2.0, WHITE);

        btnMgr.draw();

    EndDrawing();
}

void Hangman::setGuess(std::string btnText) {
    guess = btnText;
}

Hangman::~Hangman() {
    btnMgr.destroy();
    CloseWindow();
}