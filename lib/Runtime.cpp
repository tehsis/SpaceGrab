#include "Runtime.h"

Runtime::Runtime() { }
Runtime::~Runtime() {
}

void Runtime::Start() {
    loop();
}

void Runtime::loop() {
    onStart();
    bool quit = false;
    while(!quit) {
        onLoop();
    }

    onExit();
}

void Runtime::onLoop() {
    std::for_each(entities.begin(), entities.end(), [] (Tehsis::Entity* e) {
      e->onUpdate();  
    });

    SDL_Event Event;
        while(SDL_PollEvent(&Event)) {
    handleEvents(&Event);
        }
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
