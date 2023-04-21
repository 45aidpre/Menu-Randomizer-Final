#include "Starters.h"
#ifndef MENU_H
#define MENU_H

#include <iostream>

class Menu : public Classic { //create menu, display menu, and update menu
public:
    void create_menu() {


        std::cout << "New Menu\n" << std::endl; //print new menu title

        std::cout << "-------------------------------------------------" << std::endl;


        std::cout << "Starters:  \n" << std::endl; //print starters


        randomize_starter();

        display_starter();



        std::cout << "\n" << std::endl; //spacing

        std::cout << "Soup & Salads:   \n" << std::endl; //print soup and salads

        std::cout << "Soup Du Jour $7\n" << std::endl; //print consistent menu items
        std::cout << "Clubhouse Chili $8\n" << std::endl;

        randomize_salad();

        display_salad();


        std::cout << "\n\n" << std::endl; //spacing

        std::cout << "Classics:  \n" << std::endl; //print classics

        randomize_classic();

        display_classic();


    }

};

#endif
