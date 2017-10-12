#include "lib/GameRuntime.h"

#include "entities/Ship.h"
#include "entities/Background.h"

#include <iostream>
using namespace std;

int main() {
    GameRuntime r;

    Ship s;
    Background b;

    r.AddEntity(&b);
    r.AddEntity(&s);
    
    b.Follow(&s);

    r.Start();
    return 0;
}
