#include "button.h"
#include "ButtonManager.h"

void ButtonManager::add(Button *btn) {
    buttons.push_back(btn);
}

void ButtonManager::update() {
    for (Button *btn : buttons) {
        btn->update();
    }
}

void ButtonManager::draw() {
    for (Button *btn : buttons) {
        btn->draw();
    }
}