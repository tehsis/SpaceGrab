#include "Ship.h"

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265;

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

  drawer->DrawImage(t, NULL, &shipRect, angle, NULL);
}

void Ship::onEvent(SDL_Event *e) {
  if (e->type == SDL_KEYDOWN) {
    switch (e->key.keysym.sym) {
      case SDLK_DOWN:
        shipRect.y += velocity * cos(angle * PI / 180);
        shipRect.x -= velocity * sin(angle * PI / 180); 
        break;
      case SDLK_UP:
        shipRect.y -= velocity * cos(angle * PI / 180);
        shipRect.x += velocity * sin(angle * PI / 180); 
        break;
      case SDLK_RIGHT:
        angle += angleVel;
        angle = angle == 360 ? 0 : angle;
        break;
      case SDLK_LEFT:
        angle -= angleVel;
        angle = angle == -10 ? 350 : angle;
        break;
    }
}
}

