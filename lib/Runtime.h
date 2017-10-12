#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <SDL2/SDL.h>
#include <algorithm>
#include <vector>
#include "Entity.h"


class Runtime {
    public:
        SDL_Event event;
        std::vector<Tehsis::Entity*> entities;
        virtual void loop();
        virtual void onStart();
        virtual void onExit();
        virtual void onLoop();
        virtual void frame();
        virtual void handleEvents(SDL_Event*);
        Runtime();
        ~Runtime();
        void AddEntity(Tehsis::Entity*);
        void Start();
        void WebStart();
        void NativeStart();
};

#endif
