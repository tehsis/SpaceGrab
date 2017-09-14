#include <SDL2/SDL.h>

int main() {
    SDL_Window *w;
    w = SDL_CreateWindow("SDL Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);

    SDL_Delay(3000);

    SDL_DestroyWindow(w);

    SDL_Quit();

    return 0;
}
