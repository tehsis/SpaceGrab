#include "Runtime.h"
#include <iostream>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif


void startRuntime(void* r) {
    static_cast<Runtime*>(r)->WebStart();
}

Runtime::Runtime() { }
Runtime::~Runtime() {
}

void Runtime::NativeStart() {
  loop();
}

void Runtime::Start() {
  #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(startRuntime, this, 0, 1);
  #else
    NativeStart();
  #endif
}

void Runtime::WebStart() {
  SDL_Event Event;
  while(SDL_PollEvent(&Event)) {
    handleEvents(&Event);
  }

  onLoop();
}

void Runtime::loop() {
    onStart();
    bool quit = false;
    SDL_Event Event;
    while(!quit) {
        while(SDL_PollEvent(&Event)) {
            if (SDL_QUIT == Event.type) {
                quit = true;
            }

            handleEvents(&Event);
        }

        onLoop();
    }

    onExit();
}

void Runtime::onLoop() {
    std::for_each(entities.begin(), entities.end(), [&] (Tehsis::Entity* e) {
      e->onUpdate();  
    });
}

void Runtime::handleEvents(SDL_Event* event) {
    std::for_each(entities.begin(), entities.end(), [&] (Tehsis::Entity* e) {
        e->onEvent(event);  
    });
}

void Runtime::onStart() {
    std::for_each(entities.begin(), entities.end(), [] (Tehsis::Entity* e) {
        e->onStart();  
    });
}

void Runtime::onExit() {
    std::for_each(entities.begin(), entities.end(), [] (Tehsis::Entity* e) {
        e->onExit();  
    });
}

void Runtime::AddEntity(Tehsis::Entity *e) {
    entities.push_back(e);
}


