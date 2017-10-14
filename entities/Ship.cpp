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

  if (velocity > 0 && newy > 0 && newy < 480*2 - 80) {
    shipRect.y = newy;
  }

  if (velocity > 0 && newx > 0 && newx < 640*2 - 80) {
    shipRect.x = newx;
  }

  int camerax = shipRect.x - 320;
  int cameray = shipRect.y - 240;

  if (camerax < 0) {
    camerax = 0;
  }

  if (cameray < 0) {
    cameray = 0;
  }

  if (camerax > 640*2 - 640) {
    camerax = 640*2 - 640;
  }

  if (cameray > 480*2 - 480) {
    cameray = 480*2 - 480;
  }

  drawer->SetCamera(camerax, cameray, 640, 480);

  std::cout << "x: " << shipRect.x << std::endl;
  std::cout << "y: " << shipRect.y << std::endl;  

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

