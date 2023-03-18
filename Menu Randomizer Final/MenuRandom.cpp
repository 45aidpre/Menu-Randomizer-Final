//Randomized Lunch Menu
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "Starters.h"
#include "Salads.h"
#include "Classics.h"
#include "Menu.h"
#include "Interface.h"


using namespace std;


int main() {

    Interface b;

    srand(time(NULL));

    b.summon_interface();


    return 0;
}