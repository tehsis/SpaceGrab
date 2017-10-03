#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#ifndef _Drawer_H_
#define _Drawer_H_

#define SDL_Texture Texture

namespace Tehsis {

const char DEFAULT_SCREEN_NAME[] = "Drawer";
const uint DEFAULT_SCREEN_WIDTH = 640;
const uint DEFAULT_SCREEN_HEIGHT = 480;

class Drawer {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
    public:
        Drawer(std::string, uint x, uint y);
        ~Drawer();
        void clearScreen();
        void update();
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
