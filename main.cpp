#include "lib/GameRuntime.h"

#include "entities/Ship.h"
#include "entities/Background.h"
#include "entities/Asteroid.h"


#include <iostream>
using namespace std;

int main() {
    GameRuntime r;

    Ship s;
    Background b;
    Asteroid a;

    r.AddEntity(&b);
    r.AddEntity(&a);        
    r.AddEntity(&s);
    
    r.Start();
    return 0;
}
