#ifndef __Entity_H
#define __Entity_H

#include <SDL2/SDL.h>

#include <iostream>

namespace Tehsis {
class Entity {

    public:
        virtual void onStart() {};
        virtual void onUpdate() {};
        virtual void onExit() {};
        virtual void onEvent(SDL_Event*) {};
};
}
#endif
