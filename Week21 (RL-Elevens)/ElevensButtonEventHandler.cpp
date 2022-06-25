#include "ElevensButtonEventHandler.h"
#include <iostream>

ElevensButtonEventHandler::ElevensButtonEventHandler(){}

ElevensButtonEventHandler::ElevensButtonEventHandler(Elevens *setElevens) {
    elevens = setElevens;
}

void ElevensButtonEventHandler::registerButtonManager(ElevensButtonManager *setbtnMgr) {
    btnMgr = setbtnMgr;
}

void ElevensButtonEventHandler::invoke(Button *btn) {    
    Elevens *Game = Game->getInstance();
    Game->selected.push_back(reinterpret_cast<ElevensButton*>(btn));
}