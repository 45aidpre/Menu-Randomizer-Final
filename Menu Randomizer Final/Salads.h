#include "Starters.h"
#ifndef SALADS_H
#define SALADS_H

#include <iostream>

using namespace std;



class Salad : virtual public Starter {
    int saladPrice[100] = { 11, 14, 15, 15, 15 };
    string saladName[100] = { "Caesar Salad", "California Cobb", "Asian Shrimp Salad",
                        "Wedge Salad", "Spinach Salad" };

    int randPrice[100];
    string randSalad[100];
    int countSalad = 5;
    int temp;

public:

    void add_salad() {

        string input;
        cin.ignore();
        cout << "What is the new starter? (enter name): ";
        getline(cin, input); // Getline rather than cin to read spaces
        saladName[countSalad] = input;


        cout << "What is its price? ";
        getline(cin, input);
        int temp_price = stoi(input); // "casts" the input string to int
        saladPrice[countSalad] = temp_price; // sets price to that temp value

        // output edited menu item for user
        cout << "Here is the new menu item: " << saladName[countSalad] << ": $" << saladPrice[countSalad] << endl;

        countSalad++;


    }

    void remove_salad() {

        if (countSalad == 0) { // if there's nothing to remove
            cout << "Error: no starters to remove!" << endl;
        }
        else {

            cout << "Enter Existing Starter item (enter its numerical index): ";
            cin >> temp;

            if (temp == countSalad) { // removing last item can just be done by not listing it
                countSalad--;
            }
            else if (temp > countSalad || temp < 1) { // if index is out of bounds
                cout << "Error: index out of bounds." << endl;
            }
            else {

                for (int i = temp; i < countSalad; i++) {
                    // shift every item after the removed item down to fill the gap
                    saladName[i - 1] = saladName[i];
                    saladPrice[i - 1] = saladPrice[i];
                }

                countSalad--;
            }
        }

    }

    void edit_salad() { // Edits an entry in the starter list
        string input;

        if (countSalad == 0) { // if there's nothing to edit
            cout << "Error: no starters to edit!" << endl;
        }
        else {
            cout << "Enter Existing Starter item (enter its numerical index): ";
            cin >> temp;

            cin.ignore(); // prevents the later getline from consuming the \n

            if (temp > countSalad || temp < 1) { // if index is out of bounds
                cout << "Error: index out of bounds." << endl;
            }
            else {
                temp -= 1; // changes 0-based indexing to 1-based

                cout << "Edit name? (Enter name or 'n' for no): ";
                getline(cin, input); // Getline rather than cin to read spaces

                if (input == "n") { // do nothing if user doesn't want to change name

                }
                else {
                    saladName[temp] = input; // otherwise change name
                }

                cout << "Edit price? (Enter price or 'n' for no): ";
                getline(cin, input);

                if (input == "n") {


                }
                else {
                    int temp_price = stoi(input); // "casts" the input string to int
                    saladPrice[temp] = temp_price; // sets price to that temp value
                }

                // output edited menu item for user
                cout << "Here is the updated menu item: " << saladName[temp] << ": $" << saladPrice[temp] << endl;
            }
        }

    }

    void randomize_salad() {

        for (int i = 0; i < countSalad; i++) { // for every starter item,
            randSalad[i] = saladName[i];     // copy each item to a new array
            randPrice[i] = saladPrice[i];
        }

        for (int i = 0; i < countSalad; i++) {
            temp = rand() % countSalad; // generate an index (to swap)

            string tempElement = randSalad[temp]; // generate a temporary place to put the index-th element
            int tempPrice = randPrice[temp];

            randSalad[temp] = randSalad[i]; // swap the ith element with the random index
            randPrice[temp] = randPrice[i];

            randSalad[i] = tempElement;
            randPrice[i] = tempPrice;
        }
    }

    void display_salad() {
        cout << "Random Salads:\n" << endl;
        for (int i = 0; i < 3; i++)

            cout << randSalad[i] << " $" << randPrice[i] << endl << endl;
    }

    void show_salad() {   //Displaying all items in starter array
        for (int i = 0; i < countSalad; i++) {

            cout << endl;

            cout << i + 1 << ". " << saladName[i] << " $" << saladPrice[i] << endl;

        }
    }
};

#endif