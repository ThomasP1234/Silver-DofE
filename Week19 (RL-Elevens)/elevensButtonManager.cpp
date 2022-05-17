#include <iostream>
#include "button.h"
#include "elevensButtonManager.h"
//#include "ElevensButton.h"
void ElevensButtonManager::add(Button *btn) {
    buttons.push_back(btn); // Add buttons to a list
}

void ElevensButtonManager::remove(Button *btn) {
    auto it = buttons.begin();
    for (Button *currentBtn : buttons) {
        if (btn == currentBtn) {
            buttons.erase(it);
        }
        std::advance(it, 1);
    }
}

void ElevensButtonManager::update() {
    for (Button *btn : buttons) {
        //reinterpret_cast<ElevensButton*>(btn)->update(); // Update all buttons
        btn->update(); // Update all buttons
    }
}

void ElevensButtonManager::draw() {
    for (Button *btn : buttons) {
        //ElevensButton* b = static_cast<ElevensButton*>(btn); // Draw all buttons           
        //ElevensButton* b = dynamic_cast<ElevensButton*>(btn); // Draw all buttons   
        btn->draw();
    }
}

void ElevensButtonManager::destroy() {
    for (Button *btn : buttons) {
        //delete dynamic_cast<ElevensButton*>(btn); // Delete all buttons
        //delete static_cast<ElevensButton*>(btn); // Delete all buttons
        delete btn;
    }
}

// std::vector<Button *> ElevensButtonManager::get() {
//     return buttons; // Get the list of all buttons
// }