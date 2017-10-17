#include <iostream>
#include <cmath>

#include "Ship.h"
#include "../globals.h"

using namespace std;

const double PI = 3.14159265;

const double degToRadFactor = PI / 180;

int vel(int factor, int time) {
    return log(time*factor);
}

Ship::Ship() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  texture = drawer->Image("../assets/ship.png");

  shipRect.h = 80;
  shipRect.w = 80;
  shipRect.x = 600;
  shipRect.y = 440;
}

void Ship::onStart() {
}

void Ship::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();  
   uint currentTime = SDL_GetTicks() - lastTime;

  if (currentTime > 5) {
      lastTime = SDL_GetTicks();
  }
 
  int newy = shipRect.y - vel(velocity, currentTime) * cos(angle * degToRadFactor);
  int newx = shipRect.x + vel(velocity, currentTime) * sin(angle * degToRadFactor);

  if (newy > 0 && newy < SpaceGrab::LEVEL_HEIGHT - shipRect.h) {
    shipRect.y = newy;
  }

  if (newx > 0 && newx < SpaceGrab::LEVEL_WIDTH - shipRect.w) {
    shipRect.x = newx;
  }

  int camerax = shipRect.x - drawer->getCameraWidth() / 2;
  int cameray = shipRect.y - drawer->getCameraHeight() / 2;

  if (camerax < 0) {
    camerax = 0;
  }

  if (cameray < 0) {
    cameray = 0;
  }

  if (camerax > SpaceGrab::LEVEL_WIDTH - drawer->getCameraWidth() ) {
    camerax = SpaceGrab::LEVEL_WIDTH - drawer->getCameraWidth();
  }

  if (cameray > SpaceGrab::LEVEL_HEIGHT - drawer->getCameraHeight()) {
    cameray = SpaceGrab::LEVEL_HEIGHT - drawer->getCameraHeight();
  }

  drawer->MoveCamera(camerax, cameray);

  drawer->DrawImage(texture, NULL, &shipRect, angle, NULL);
}

void Ship::onEvent(SDL_Event *e) {
   if (e->type == SDL_KEYDOWN) {
    switch (e->key.keysym.sym) {
      case SDLK_DOWN:
        velocity = velocity <= 1 ? velocity : velocity - 1;

        break;
      case SDLK_UP:
        velocity = velocity >= 20 ? velocity : velocity + 1;

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

