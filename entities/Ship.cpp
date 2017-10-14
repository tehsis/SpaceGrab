#include "Ship.h"

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265;

const double degToRadFactor = PI / 180;

int vel(int factor, int time) {
    return factor + log(time);
}

Ship::Ship() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  texture = drawer->Image("../assets/ship.png");

  shipRect.h = 80;
  shipRect.w = 80;
  shipRect.x = 640/2 - 40;
  shipRect.y = 480/2 - 40;
}

void Ship::onStart() {
}

void Ship::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();  
   uint currentTime = SDL_GetTicks() - lastTime;

  if (currentTime > 5) {
      lastTime = SDL_GetTicks();
  }
 

  shipRect.y -= vel(velocity, currentTime) * cos(angle * degToRadFactor);
  shipRect.x += vel(velocity, currentTime) * sin(angle * degToRadFactor);


  drawer->SetCamera(shipRect.x - 320, shipRect.y - 240, 640, 480);

  cout << "velocity: " << velocity << endl;
  drawer->DrawImage(texture, NULL, &shipRect, angle, NULL);
}

void Ship::onEvent(SDL_Event *e) {
   if (e->type == SDL_KEYDOWN) {
    switch (e->key.keysym.sym) {
      case SDLK_DOWN:
        velocity = velocity <= 0 ? velocity : velocity - 1;

        break;
      case SDLK_UP:
        velocity = velocity >= 500 ? velocity : velocity + 1;

        break;
      case SDLK_RIGHT:
        angle = angle > 360 ? (angle - 360) + angleVel : angle + angleVel ;
        break;
      case SDLK_LEFT:
        angle = angle < 0 ? (360 - angle) - angleVel : angle - angleVel;
        break;
    }
  }
}

Tehsis::Rectangle* Ship::getRect() {
    return &shipRect;
}

