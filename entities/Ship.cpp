#include <iostream>
#include <cmath>

#include "Ship.h"
#include "../globals.h"

#include <algorithm>

using namespace std;

const double PI = 3.14159265;

const double degToRadFactor = PI / 180;

int vel(int vel) {
    return log(vel) + 1;
}

Ship::Ship() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();
  texture = drawer->Image("../assets/ship.png");
  explosion = drawer->Image("../assets/explosion.png");
  
  reset();

  collider = new Collider(shipRect.h, shipRect.w, shipRect.x, shipRect.y);
}

void Ship::onStart() {
}

void Ship::addAsteroid(Asteroid* asteroid) {
  asteroids.push_back(asteroid);
}

void Ship::reset() {
  shipRect.h = 80;
  shipRect.w = 80;
  shipRect.x = 600;
  shipRect.y = 440;
  isExploding = false;
  explodePositionX = 0;
  explodePositionY = 0;


  std::for_each(asteroids.begin(), asteroids.end(), [&] (Asteroid* a) {
    a->setActive(true);
  });
}

void Ship::onUpdate() {
  Tehsis::Drawer* drawer = Tehsis::SDrawer::Drawer();  

  currentTime = SDL_GetTicks();

  if (isExploding) {
    shipRect.h = 64;
    shipRect.w = 64;

    explosionRect.x = explodePositionX * 64;
    explosionRect.y = explodePositionY * 64;
    explosionRect.w = 64;
    explosionRect.h = 64;

    drawer->DrawImage(explosion, &explosionRect, &shipRect, angle, NULL);    
    
    int time = currentTime - lastTime;    

    if (time >= 200) {
      if (explodePositionX <= 3) {
        explodePositionX++;        
      } else {
        explodePositionX = 0;
        explodePositionY++;
      }

      if (explodePositionY >=3 && explodePositionX >= 3) {
        reset();
      }

      lastTime = currentTime;      
    }

    return;
  }
 
  int newy = shipRect.y - vel(velocity) * cos(angle * degToRadFactor);
  int newx = shipRect.x + vel(velocity) * sin(angle * degToRadFactor);

  int oldx = shipRect.x;
  int oldy = shipRect.y;

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
  collider->Move(shipRect.x, shipRect.y);  

  std::for_each(asteroids.begin(), asteroids.end(), [&] (Asteroid* a) {
    if (isColliding(a)) {
      explode();
      a->setActive(false);
    }

  });

  drawer->DrawImage(texture, NULL, &shipRect, angle, NULL);
}

void Ship::explode() {
  isExploding = true;
}

void Ship::onEvent(SDL_Event *e) {
   if (isExploding) return;

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

bool Ship::isColliding(Asteroid* other) {
    Collider* col = other->GetCollider();
    return collider->IsColliding(col);
}
