// #include "button.h"
#include "ElevensButtonManager.h"

void ElevensButtonManager::add(ElevensButton *btn) {
    buttons.push_back(btn); // Add buttons to a list
}

void ElevensButtonManager::update() {
    for (ElevensButton *btn : buttons) {
        btn->update(); // Update all buttons
    }
}

void ElevensButtonManager::draw() {
    for (ElevensButton *btn : buttons) {
        btn->draw(); // Draw all buttons
    }
}

void ElevensButtonManager::destroy() {
    for (ElevensButton *btn : buttons) {
        delete btn; // Delete all buttons
    }
}

std::list<ElevensButton *> ElevensButtonManager::get() {
    return buttons; // Get the list of all buttons
}