#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

int main(int argc, char *argv[]) {
    SDL_Window *w;
    SDL_Surface *background, *ship;

    SDL_Rect* shipRect = new SDL_Rect;

    int shipVel = 10;

    shipRect->h = 80;
    shipRect->w = 80;
    shipRect->x = 640/2 - 40;
    shipRect->y = 480/2 - 40;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    w = SDL_CreateWindow("TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* r = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);

    background = IMG_Load("assets/background.png");
    ship = IMG_Load("assets/ship.png");

    SDL_Texture* shipTex = SDL_CreateTextureFromSurface(r,ship);
    SDL_Texture* backTex = SDL_CreateTextureFromSurface(r, background);

    SDL_FreeSurface(background);
    SDL_FreeSurface(ship);

    bool quit = false;
    SDL_Event event;
    while (!quit) {
       while(SDL_PollEvent(&event)) {
           if (event.type == SDL_QUIT) {
               quit = true;
           }

           if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
              case SDLK_DOWN:
                shipRect->y += shipVel;
                break;
              case SDLK_UP:
                shipRect->y -= shipVel;
                break;
              case SDLK_RIGHT:
                shipRect->x += shipVel;
                break;
              case SDLK_LEFT:
                shipRect->x -= shipVel;
                break;
            }
           }
       }

       SDL_RenderClear(r);

       SDL_RenderCopy(r, backTex, NULL, NULL); 
       SDL_RenderCopy(r, shipTex, NULL, shipRect); 

       SDL_RenderPresent(r);
    }

    SDL_DestroyTexture(backTex);
    SDL_DestroyTexture(shipTex);
    SDL_DestroyRenderer(r);
    SDL_DestroyWindow( w ) ;
    SDL_Quit();

    return 0;
}
