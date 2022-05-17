#include "elevensButtonEventHandler.h"
#include <iostream>

ElevensButtonEventHandler::ElevensButtonEventHandler(){}

ElevensButtonEventHandler::ElevensButtonEventHandler(Elevens *setElevens) {
    elevens = setElevens;
}

void ElevensButtonEventHandler::registerButtonManager(ElevensButtonManager *setbtnMgr) {
    btnMgr = setbtnMgr;
}

void ElevensButtonEventHandler::invoke(Button *btn) {    
    btnMgr->remove(btn);
    delete btn;

    Elevens *Game = Game->getInstance();
    Game->newButton();
}