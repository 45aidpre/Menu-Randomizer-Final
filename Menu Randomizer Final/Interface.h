#include "Starters.h"
#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>

using namespace std;


class Interface : public Menu { //Display Interface giving the user the options for Menu editing and production

    int option;

public:

    void summon_interface() {


        cout << "Please enter a single option: " << endl;
        cout << "Enter:  \n 1: Add Menu Item \n 2: Remove Menu Item \n 3: Change Menu Item \n 4: Produce Menu \n 5: Display Menu Items \n 6: Quit Program" << endl;
        cin >> option;

        if (option == 1) { //Adding Items to the Menu which do not already exist

            int option2;
            cout << "Please select the type of item: \n";
            cout << "1: Starter \n 2: Salad \n 3: Classic \n";
            cin >> option2;

            if (option2 == 1) {

                add_starter();

                summon_interface();
            }

            else if (option2 == 2) {

                add_salad();

                summon_interface();
            }
            else if (option2 == 3) {

                add_classic();

                summon_interface();
            }
            else {

                cout << "Incorrect Input: Returning to Main Menu!" << endl;

                summon_interface();
            }
        }
        else if (option == 2) { //Placement for Remove Function

            int option5;
            cout << "Please select the type of item: \n";
            cout << "1: Starter \n 2: Salad \n 3: Classic \n";
            cin >> option5;

            if (option5 == 1) {

                remove_starter();

                summon_interface();
            }

            else if (option5 == 2) {

                remove_salad();

                summon_interface();
            }
            else if (option5 == 3) {

                remove_classic();

                summon_interface();
            }
            else {

                cout << "Incorrect Input: Returning to Main Menu!" << endl;

                summon_interface();
            }
        }

        else if (option == 3) { //Editing specific items stored

            int option3;
            cout << "Please select the type of item: \n";
            cout << "1: Starter \n 2: Salad \n 3: Classic \n";
            cin >> option3;

            if (option3 == 1) {

                edit_starter();

                summon_interface();
            }

            else if (option3 == 2) {

                edit_salad();

                summon_interface();
            }
            else if (option3 == 3) {

                Classic::edit_classic();

                summon_interface();
            }
            else {

                cout << "Incorrect Input: Returning to Main Menu!" << endl;

                summon_interface();
            }
        }
        else if (option == 4) { //Create Menu

            create_menu();

            summon_interface();
        }
        else if (option == 5) { //Display List of Items

            int option4;
            cout << "Please select the type of item: \n";
            cout << "1: Starter \n 2: Salad \n 3: Classic \n";
            cin >> option4;

            if (option4 == 1) {

                show_starter();

                cout << endl;
                cout << endl;

                summon_interface();
            }

            else if (option4 == 2) {

                show_salad();

                cout << endl;
                cout << endl;

                summon_interface();
            }
            else if (option4 == 3) {

                show_classic();

                cout << endl;
                cout << endl;

                summon_interface();
            }
            else { //Quit

                cout << "Incorrect Input: Returning to Main Menu!" << endl;

                summon_interface();
            }
        }

    }


};

#endif
