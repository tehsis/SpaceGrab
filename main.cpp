#include <SDL2/SDL.h>
#include <string>

int main() {
    SDL_Window *w;
    SDL_Surface *ws, *img;

    SDL_Init(SDL_INIT_VIDEO);

    w = SDL_CreateWindow("TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);

    ws = SDL_GetWindowSurface(w);

    img = SDL_LoadBMP("assets/background.bmp");

    SDL_BlitSurface(img, NULL, ws, NULL);


    SDL_UpdateWindowSurface(w);

    SDL_Delay(2000);

    SDL_DestroyWindow( w ) ;
    SDL_Quit();

    return 0;
}
