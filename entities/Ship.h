#ifndef _SHIP_H
#define _SHIP_H

#include "../lib/Entity.h"
#include "../lib/Drawer.h"
#include "../lib/Collider.h"  

#include "Asteroid.h"


#include <vector>

class Ship: public Tehsis::Entity {
    private:

        std::vector<Asteroid *> asteroids;
        bool isColliding(Asteroid* other);
        bool isExploding = false;
        Tehsis::Texture* texture;
        Tehsis::Texture* explosion;
        Tehsis::Rectangle explosionRect = {0, 0, 64, 64};
        int lastTime = 0;
        int currentTime = 0;
        int explodePositionX = 0;
        int explodePositionY = 0;
        Tehsis::Rectangle shipRect;
        Collider* collider;
        double angle = 0;
        double angleVel = 10;
        int velocity = 1;

        bool isMovingFoward = true;

        void explode();
        void reset();
    public:
        Ship();
        void onStart() override;
        void onEvent(SDL_Event*) override;
        void onUpdate() override;
        void addAsteroid(Asteroid* asteroid);

        Tehsis::Rectangle* getRect();
};
#endif
