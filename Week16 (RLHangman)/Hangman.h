#ifndef HANGMAN_H
#define HANGMAN_H
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
// #include "button.cpp"
#include "buttonManager.h"
// #include "buttonManager.cpp"
#include "ButtonEventHandler.cpp"
#include "HangmanButtonEventHandler.h"

class Hangman {
    public:
        std::list<std::string> mylst;
        std::string mytxt;
        int random;
        std::list<std::string>::iterator it;
        std::string answer;
        std::string answerUpper;
        int lives = 10;
        std::list<char> validLetters;
        std::string validLettersStr;
        std::list<char> invalidLetters;
        std::string invalidLettersStr;
        std::string puzzle;
        ButtonManager btnMgr;
        ButtonEventHandler *btnEventHandler;
        std::string guess;
        int solutionLetterCount;
        bool end = false;

        const int screenWidth = 800; // Window geometry
        const int screenHeight = 450;
        const Color backgroundColor = {48, 48, 48, 255}; // Grey Colour
        int row = 1;
        int column = 1;

        Hangman();
        ~Hangman();
        void gameLogic();
        void window();
        //void btn_cb(Button *btn);

        void gameLoop();
        void draw();
        void update();

        void setGuess(std::string btnText);
};

#endif