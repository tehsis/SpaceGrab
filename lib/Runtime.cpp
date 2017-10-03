#include "Runtime.h"

#include <iostream>
using namespace std;

Runtime::Runtime() { }
Runtime::~Runtime() {
    quit = false;
}

void Runtime::Start() {
    loop();
}

void Runtime::loop() {
    onStart();
    SDL_Event *Event;
    onLoop();        
    
    while(!quit) {
        onLoop();
        while(SDL_PollEvent(Event)) {
            if (SDL_QUIT == Event->type) {
                quit = false;
            }

            handleEvents(Event);
        }
    }

    onExit();
}

void Runtime::onLoop() {
    cout << "onLoop" << endl;
    for(std::vector<Tehsis::Entity>::iterator eit = entities.begin(); eit != entities.end(); ++eit) {        
        eit->onUpdate();
    }
    cout << "onLoop end" << endl;
}

void Runtime::handleEvents(SDL_Event* event) {
    for(std::vector<Tehsis::Entity>::iterator eit = entities.begin(); eit != entities.end(); ++eit) {
        eit->onEvent(event);
    }
}

void Runtime::onStart() {
    cout << "On start";
    for(std::vector<Tehsis::Entity>::iterator eit = entities.begin(); eit != entities.end(); ++eit) {
        eit->onStart();
    }
    cout << "On start end";
    
}

void Runtime::onExit() {
    for(std::vector<Tehsis::Entity>::iterator eit = entities.begin(); eit != entities.end(); ++eit) {
        eit->onExit();
    }
}

void Runtime::AddEntity(const Tehsis::Entity &e) {
    entities.push_back(e);
}
