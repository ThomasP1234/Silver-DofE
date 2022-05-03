#include "ElevensButtonEventHandler.h"

ElevensButtonEventHandler::ElevensButtonEventHandler(){}

ElevensButtonEventHandler::ElevensButtonEventHandler(Elevens *setElevens) {
    elevens = setElevens;
}

void ElevensButtonEventHandler::invoke(Button *btn) {
    SetWindowPosition(400, 400);
}