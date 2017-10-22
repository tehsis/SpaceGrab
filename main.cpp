#include "lib/GameRuntime.h"

#include "entities/Ship.h"
#include "entities/Background.h"
#include "entities/Asteroid.h"

#include <vector>
using namespace std;

#include "globals.h"

int random (int, int);


#include <iostream>
using namespace std;

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif


GameRuntime r;
void one_iter() {
  r.onLoop(); 
}

int main() {


    Background b;
    r.AddEntity(&b);


      Ship s;
    r.AddEntity(&s);

   for (int i=0; i< SpaceGrab::ASTEROIDS_AMOUNT;i++) {
      int x = random(0, SpaceGrab::LEVEL_WIDTH);
      int y = random(0, SpaceGrab::LEVEL_HEIGHT);
      Asteroid* a = new Asteroid(x, y);
      r.AddEntity(a);
      s.addAsteroid(a);
    }

    
    r.Start();
    return 0;
}

int random (int min, int max){
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do{
        x = rand();
    }while (x >= RAND_MAX - remainder);
    return min + x % n;
}
