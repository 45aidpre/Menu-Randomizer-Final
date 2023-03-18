#ifndef STARTERS_H
#define STARTERS_H

#include <iostream>

using namespace std;


class Starter {
    int starterPrice[100] = { 15, 12, 12, 14, 17, 12 };
    string starterName[100] = { "Chicken Wings", "4 Mini Hot Dogs", "1 lb Onion Rings", "Firecracker Shrimp",
                        "Tempura Grouper Bites", "Chicken Or Pork Potstickers" };

    int randPrice[100];
    string randStarter[100];
    int countStarter = 6;
    int temp;


public:

    void add_starter() {

        cin.ignore();
        string input;

        cout << "What is the new starter? (enter name): ";
        getline(cin, input); // Getline rather than cin to read spaces
        starterName[countStarter] = input;


        cout << "What is its price? ";
        getline(cin, input);
        int temp_price = stoi(input); // "casts" the input string to int
        starterPrice[countStarter] = temp_price; // sets price to that temp value

        // output edited menu item for user
        cout << "Here is the new menu item: " << starterName[countStarter] << ": $" << starterPrice[countStarter] << endl;

        countStarter++;


    }

    void remove_starter() {

        if (countStarter == 0) { // if there's nothing to remove
            cout << "Error: no starters to remove!" << endl;
        }
        else {

            cout << "Enter Existing Starter item (enter its numerical index): ";
            cin >> temp;

            if (temp == countStarter) { // removing last item can just be done by not listing it
                countStarter--;
            }
            else if (temp > countStarter || temp < 1) { // if index is out of bounds
                cout << "Error: index out of bounds." << endl;
            }
            else {

                for (int i = temp; i < countStarter; i++) {
                    // shift every item after the removed item down to fill the gap
                    starterName[i - 1] = starterName[i];
                    starterPrice[i - 1] = starterPrice[i];
                }

                countStarter--;
            }
        }

    }

    void edit_starter() { // Edits an entry in the starter list
        string input;

        if (countStarter == 0) { // if there's nothing to edit
            cout << "Error: no starters to edit!" << endl;
        }
        else {
            cout << "Enter Existing Starter item (enter its numerical index): ";
            cin >> temp;

            cin.ignore(); // prevents the later getline from consuming the \n

            if (temp > countStarter || temp < 1) { // if index is out of bounds
                cout << "Error: index out of bounds." << endl;
            }
            else {
                temp -= 1; // changes 0-based indexing to 1-based

                cout << "Edit name? (Enter name or 'n' for no): ";
                getline(cin, input); // Getline rather than cin to read spaces

                if (input == "n") { // do nothing if user doesn't want to change name

                }
                else {
                    starterName[temp] = input; // otherwise change name
                }

                cout << "Edit price? (Enter price or 'n' for no): ";
                getline(cin, input);

                if (input == "n") {


                }
                else {
                    int temp_price = stoi(input); // "casts" the input string to int
                    starterPrice[temp] = temp_price; // sets price to that temp value
                }

                // output edited menu item for user
                cout << "Here is the updated menu item: " << starterName[temp] << ": $" << starterPrice[temp] << endl;
            }
        }

    }

    void randomize_starter() {

        for (int i = 0; i < countStarter; i++) { // for every starter item,
            randStarter[i] = starterName[i];     // copy each item to a new array
            randPrice[i] = starterPrice[i];
        }

        for (int i = 0; i < countStarter; i++) {
            temp = rand() % countStarter; // generate an index (to swap)

            string tempElement = randStarter[temp]; // generate a temporary place to put the index-th element
            int tempPrice = randPrice[temp];

            randStarter[temp] = randStarter[i]; // swap the ith element with the random index
            randPrice[temp] = randPrice[i];

            randStarter[i] = tempElement;
            randPrice[i] = tempPrice;
        }
    }

    void display_starter() {
        cout << "Random Starters:\n" << endl;
        for (int i = 0; i < 4; i++)

            cout << randStarter[i] << " $" << randPrice[i] << endl << endl;
    }


    void show_starter() {   //Displaying all items in starter array
        for (int i = 0; i < countStarter; i++) {

            cout << i + 1 << ". " << starterName[i] << " $" << starterPrice[i] << endl;

        }
    }

};

#endif
