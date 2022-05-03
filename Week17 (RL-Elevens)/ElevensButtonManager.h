#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H
#include <string>
#include "ElevensButton.h"
#include "button.h"
#include <list>

class ElevensButtonManager {
    private:
        std::list<ElevensButton *> buttons;
    public:
        void add(ElevensButton *btn);

        void update();

        void draw();

        void destroy();

        std::list<ElevensButton *> get();
};
#endif