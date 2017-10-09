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

Texture* Drawer::Image(std::string path) {
    SDL_Surface* imgSurface = IMG_Load(path.c_str());

    SDL_Texture* imgTexture = SDL_CreateTextureFromSurface(renderer, imgSurface);

    SDL_FreeSurface(imgSurface);
    
    return imgTexture;
}

void Drawer::DrawImage(Texture* texture, const Rectangle* src, const Rectangle* dst) {
    DrawImage(texture, src, dst, 0, NULL);
}

void Drawer::DrawImage(Texture* texture, const Rectangle* src, const Rectangle* dst, const double angle, const Point *center) {
    SDL_RenderCopyEx(renderer, texture, src, dst, angle, center, SDL_FLIP_NONE);
}

void Drawer::clearScreen() {
    SDL_RenderClear(renderer);
}

void Drawer::updateScreen() {
    SDL_RenderPresent(renderer);
}

Drawer* SDrawer::Drawer() {
    return Init(Tehsis::DEFAULT_SCREEN_NAME, Tehsis::DEFAULT_SCREEN_WIDTH, Tehsis::DEFAULT_SCREEN_HEIGHT);
}

Drawer* SDrawer::Init(std::string title, uint width, uint height) {
    if (!d) {
      d = new class Drawer(title, width, height);
    }

    return d;
}
