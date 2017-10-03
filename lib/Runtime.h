#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <SDL2/SDL.h>
#include <vector>

#include "Entity.h"

class Runtime {
    private:
        std::vector<Tehsis::Entity> entities;
        bool quit;
        void loop();
        void onStart();
        void onExit();
        void onLoop();
        void handleEvents(SDL_Event*);
    public:
        Runtime();
        ~Runtime();
        void AddEntity(const Tehsis::Entity&);
        void Start();
};
#endif
