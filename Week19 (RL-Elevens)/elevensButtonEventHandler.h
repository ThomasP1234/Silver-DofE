#pragma once

#include "button.h"
#include "elevensButton.h"
#include "buttonEventHandler.h"
#include "elevens.h"
#include "elevensButtonManager.h"
class Elevens;
class ElevensButtonEventHandler : public ButtonEventHandler {
    private:
        Elevens *elevens;
    public:
        ElevensButtonManager *btnMgr;

        ElevensButtonEventHandler();
        ElevensButtonEventHandler(Elevens* setElevens);

        void registerButtonManager(ElevensButtonManager *setbtnMgr);
        void invoke(Button *btn);
};