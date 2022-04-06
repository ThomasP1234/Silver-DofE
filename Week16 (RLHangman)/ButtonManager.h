#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H
#include <string>
#include "button.h"
#include <list>

class ButtonManager {
    private:
        std::list<Button *> buttons;
    public:
        void add(Button *btn);

        void update();

        void draw();

        void destroy();

        std::list<Button *> get();
};
#endif