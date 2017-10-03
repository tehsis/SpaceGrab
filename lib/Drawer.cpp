#include "Drawer.h"
using namespace Tehsis;

Drawer* SDrawer::d;

Drawer::Drawer(std::string title, uint x, uint y) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Drawer::~Drawer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Drawer::clearScreen() {
    SDL_RenderClear(renderer);
}

void Drawer::update() {
    SDL_RenderPresent(renderer);
}

Drawer* SDrawer::Drawer() {
    return Init(DEFAULT_SCREEN_NAME, DEFAULT_SCREEN_WIDTH, DEFAULT_SCREEN_HEIGHT);
}

Drawer* SDrawer::Init(std::string title, uint width, uint height) {
    if (!d) {
      d = new class Drawer(title, width, height);
    }

    return d;
}
