// #include "button.h"
#include "ButtonManager.h"

void ButtonManager::add(Button *btn) {
    buttons.push_back(btn); // Add buttons to a list
}

void ButtonManager::update() {
    for (Button *btn : buttons) {
        btn->update(); // Update all buttons
    }
}

void ButtonManager::draw() {
    for (Button *btn : buttons) {
        btn->draw(); // Draw all buttons
    }
}

void ButtonManager::destroy() {
    for (Button *btn : buttons) {
        delete btn; // Delete all buttons
    }
}

std::list<Button *> ButtonManager::get() {
    return buttons; // Get the list of all buttons
}