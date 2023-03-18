#include "Starters.h"
#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

class Menu : public Classic { //create menu, display menu, and update menu
public:
    void create_menu() {


        cout << "New Menu\n" << endl; //print new menu title

        cout << "-------------------------------------------------" << endl;


        cout << "Starters:  \n" << endl; //print starters

        randomize_starter();

        display_starter();



        cout << "\n" << endl; //spacing

        cout << "Soup & Salads:   \n" << endl; //print soup and salads

        cout << "Soup Du Jour $7\n" << endl; //print consistent menu items
        cout << "Clubhouse Chili $8\n" << endl;

        randomize_salad();

        display_salad();


        cout << "\n\n" << endl; //spacing

        cout << "Classics:  \n" << endl; //print classics

        randomize_classic();

        display_classic();


    }

};

#endif
