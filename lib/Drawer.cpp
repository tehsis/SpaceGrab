#include "Drawer.h"
#include <iostream>

using namespace Tehsis;

Drawer* SDrawer::d;

Drawer::Drawer(std::string title, uint screen_width, uint screen_height, uint lwidth, uint lheight) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    camera = new Camera(0, 0, screen_width, screen_height); 
    level_width = lwidth;
    level_height = lheight;
}

Drawer::Drawer(std::string title, uint screen_width, uint screen_height) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    camera = new Camera(0, 0, screen_width, screen_height); 
    level_width = screen_width;
    level_height = screen_height;
}

Drawer::~Drawer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Drawer::MoveCamera(int x, int y) {
    camera->Move(x, y);
}

Texture* Drawer::Image(std::string path) {
    SDL_Surface* imgSurface = IMG_Load(path.c_str());

    SDL_Texture* imgTexture = SDL_CreateTextureFromSurface(renderer, imgSurface);

    SDL_FreeSurface(imgSurface);
    
    return imgTexture;
}

Font* Drawer::LoadFont(std::string path) {
  return TTF_OpenFont( path.c_str(), 28 );
}

Texture* Drawer::Text(std::string text, Color color, Font* font) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), color);

    SDL_Texture* txtTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_FreeSurface(textSurface);

    return txtTexture;
}

void Drawer::DrawImage(Texture* texture, const Rectangle* src, const Rectangle* dst) {
    DrawImage(texture, src, dst, 0, NULL);
}
void Drawer::DrawImage(Texture* texture, const Rectangle* src, const Rectangle* dst, const double angle, const Point *center) {
    DrawImageAbsolute(texture, src, camera->GetRelativeRect(dst), angle, center);
}

void Drawer::DrawImageAbsolute(Texture* texture, const Rectangle* src, const Rectangle* dst) {
    DrawImageAbsolute(texture, src, dst, 0, NULL);
}

void Drawer::DrawImageAbsolute(Texture* texture, const Rectangle* src, const Rectangle* dst, const double angle, const Point *center) {
    cout <<< "what";
    SDL_RenderCopyEx(renderer, texture, src, dst, angle, center, SDL_FLIP_NONE);
}

unsigned int Drawer::getCameraWidth() {
    return camera->getWidth();
}

unsigned int Drawer::getCameraHeight() {
    return camera->getHeight();
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
