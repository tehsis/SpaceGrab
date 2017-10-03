#ifndef __Entity_H
#define __Entity_H

#include <SDL2/SDL.h>

#include <iostream>

namespace Tehsis {
class Entity {
    public:
        void onStart() {};
        virtual void onUpdate() {std::cout << "base" << std::endl;};
        void onExit() {};
        void onEvent(SDL_Event*) {};
};
}
#endif
