#ifndef _RUNTIME_H_
#define _RUNTIME_H_

#include <SDL2/SDL.h>
#include <algorithm>
#include <vector>
#include "Entity.h"

class Runtime {
    private:
        SDL_Event event;
    protected:
        std::vector<Tehsis::Entity*> entities;
        virtual void loop();
        virtual void onStart();
        virtual void onExit();
        virtual void onLoop();
        virtual void handleEvents(SDL_Event*);
    public:
        Runtime();
        ~Runtime();
        void AddEntity(Tehsis::Entity*);
        void Start();
};
#endif
