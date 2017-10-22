#ifndef _Drawer_H_
#define _Drawer_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

#include "Aliases.h"

#include "Camera.h"

namespace Tehsis {

const char DEFAULT_SCREEN_NAME[] = "Game";
const uint DEFAULT_SCREEN_WIDTH = 640;
const uint DEFAULT_SCREEN_HEIGHT = 480;

class Drawer {
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        Camera* camera;
        int level_width;
        int level_height;
    public:
        Drawer(std::string, uint screen_width, uint screen_height, uint level_width, uint level_height);
        Drawer(std::string, uint screen_width, uint screen_height);
        ~Drawer();
        Texture* Image(std::string);
        void DrawImage(Texture* texture, const Rectangle *src, const Rectangle *dst, const double angle, const Point *center);
        void DrawImage(Texture* texture, const Rectangle* src, const Rectangle* dst);
        void clearScreen();
        void updateScreen();
        void MoveCamera(int x, int y);
        uint getCameraWidth();
        uint getCameraHeight();
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
