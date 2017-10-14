#include "Drawer.h"
#include <iostream>
using namespace Tehsis;

Drawer* SDrawer::d;

Drawer::Drawer(std::string title, uint x, uint y) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    camera = new Rectangle; 
    camera->x = 0;
    camera->y = 0;
    camera->w = x;
    camera->h = y;
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

void Drawer::SetCamera(int x, int y, int w, int h) {
  camera->x = x;
  camera->y = y;
  camera->w = w;
  camera->h = h;
}

void Drawer::DrawImage(Texture* texture, const Rectangle* src, const Rectangle* dst) {
    DrawImage(texture, src, dst, 0, NULL);
}

void Drawer::DrawImage(Texture* texture, const Rectangle* src, const Rectangle* dst, const double angle, const Point *center) {
    Rectangle* relative = new Rectangle;

    relative->x = dst->x - camera->x;
    relative->y = dst->y - camera->y;
    relative->w = dst->w;
    relative->h = dst->h;

    SDL_RenderCopyEx(renderer, texture, src, relative, angle, center, SDL_FLIP_NONE);

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
