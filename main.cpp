#include "lib/GameRuntime.h"

#include "entities/Ship.h"
#include "entities/Background.h"


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

    Ship s;
    Background b;

    r.AddEntity(&b);
    r.AddEntity(&s);
    
    b.Follow(&s);

    r.onStart();    
    emscripten_set_main_loop(one_iter, 60, 1);

    return 0;
}

