#include "Ship.h"

#include <iostream>
using namespace std;

Ship::Ship() {
  shipRect.h = 80;
  shipRect.w = 80;
  shipRect.x = 640/2 - 40;
  shipRect.y = 480/2 - 40;
}

void Ship::onStart() {}

void Ship::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  Tehsis::Texture* t = drawer->Image("../assets/ship.png");

  drawer->DrawImage(t, NULL, &shipRect);
}

void Ship::onEvent(SDL_Event *e) {
  if (e->type == SDL_KEYDOWN) {
    switch (e->key.keysym.sym) {
      case SDLK_DOWN:
        shipRect.y += velocity;
        break;
      case SDLK_UP:
        shipRect.y -= velocity;
        break;
      case SDLK_RIGHT:
        shipRect.x += velocity;
        break;
      case SDLK_LEFT:
        shipRect.x -= velocity;
        break;
    }
}
}

