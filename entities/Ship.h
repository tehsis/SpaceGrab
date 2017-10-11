#ifndef _SHIP_H
#define _SHIP_H

#include "../lib/Entity.h"
#include "../lib/Drawer.h"

class Ship: public Tehsis::Entity {
    private:
        Tehsis::Rectangle shipRect;
        double angle = 0;
        double angleVel = 10;
        int velocity = 1;

        bool isMovingFoward = true;

        uint lastTime = 0;

    public:
        Ship();
        void onStart() override;
        void onEvent(SDL_Event*) override;
        void onUpdate() override;
};
#endif
