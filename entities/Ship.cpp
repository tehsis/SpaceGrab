#include "Ship.h"

#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265;

const double degToRadFactor = PI / 180;

int vel(int time) {
    return log(time);
}

Ship::Ship() {
  shipRect.h = 80;
  shipRect.w = 80;
  shipRect.x = 640/2 - 40;
  shipRect.y = 480/2 - 40;
}

void Ship::onStart() {
}

void Ship::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  Tehsis::Texture* t = drawer->Image("../assets/ship.png");

   uint currentTime = SDL_GetTicks() - lastTime;

  if (currentTime > 5) {
      lastTime = SDL_GetTicks();
  }
 
  int currVel = vel(currentTime);

  if (isMovingFoward) {
    shipRect.y -= vel(currentTime) * cos(angle * degToRadFactor);
    shipRect.x += vel(currentTime) * sin(angle * degToRadFactor);
  } else {
    shipRect.y += vel(currentTime) * cos(angle * degToRadFactor);
    shipRect.x -= vel(currentTime) * sin(angle * degToRadFactor); 
  }

  if (shipRect.y < -80) {
    shipRect.y = 560;
  }

  if (shipRect.x < -80) {
      shipRect.x = 740;
  }

  if (shipRect.y > 560) {
      shipRect.y = -80;
  }

  if (shipRect.x > 740) {
      shipRect.x = -80;
  }


  drawer->DrawImage(t, NULL, &shipRect, angle, NULL);
}

void Ship::onEvent(SDL_Event *e) {
   if (e->type == SDL_KEYDOWN) {
    switch (e->key.keysym.sym) {
      case SDLK_DOWN:
        isMovingFoward = false;
        break;
      case SDLK_UP:
        isMovingFoward = true;
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

