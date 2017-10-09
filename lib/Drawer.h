#ifndef _Drawer_H_
#define _Drawer_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

namespace Tehsis {

const char DEFAULT_SCREEN_NAME[] = "Game";
const uint DEFAULT_SCREEN_WIDTH = 640;
const uint DEFAULT_SCREEN_HEIGHT = 480;

using Texture = SDL_Texture;
using Rectangle = SDL_Rect;
using Point = SDL_Point;

class Drawer {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        Drawer(std::string, uint x, uint y);
        ~Drawer();
        Texture* Image(std::string);
        void DrawImage(Texture* texture, const Rectangle *src, const Rectangle *dst, const double angle, const Point *center);
        void DrawImage(Texture* texture, const Rectangle* src, const Rectangle* dst);
        void clearScreen();
        void updateScreen();
};

class SDrawer {
    private:
    static Drawer* d;
    SDrawer(std::string, uint, uint) {
    }

    public:
    static Drawer *Init(std::string, uint, uint);
    static Drawer *Drawer();
};
}

#endif
