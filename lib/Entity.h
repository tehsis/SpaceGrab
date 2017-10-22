#ifndef __Entity_H
#define __Entity_H

#include <SDL2/SDL.h>

#include <iostream>

namespace Tehsis {
class Entity {
    bool active = true;
    public:
        virtual void onStart() {};
        virtual void onUpdate() {};
        virtual void onExit() {};
        bool isActive() {return active;};
        void setActive(bool a) {active=a;};
        virtual void onEvent(SDL_Event*) {};
};
}
#endif
