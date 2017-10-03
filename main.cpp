#include "lib/Runtime.h"

#include "entities/Ship.h"

#include <iostream>
using namespace std;

int main() {
    Runtime r;

    Ship s;

    cout << "adding" << endl;

    r.AddEntity(s);

    r.Start();
    return 0;
}
