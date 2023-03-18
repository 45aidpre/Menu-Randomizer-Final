#include "Starters.h"
#ifndef CLASSICS_H
#define CLASSICS_H

#include <iostream>

using namespace std;


class Classic : virtual public Salad {
    int classicPrice[100] = { 10, 13, 14, 14, 19, 13, 13, 14, 16 };
    string classicName[100] = { "Hotdog", "Cucumber Sandwich", "Reuben", "Wells BLT","Grouper Sandwich","Wells Quesadilla","SWCC Grilled Cheese","Black Angus Beef Burger","Fish & Chips:\n Haddock" };

    int randPrice[100];
    string randClassic[100];
    int countClassic = 9;
    int temp;
public:

    void add_classic() {

        string input;
        cin.ignore();
        cout << "What is the new starter? (Please enter its numerical index of the item): ";
        getline(cin, input); // Getline rather than cin to read spaces
        classicName[countClassic] = input;


        cout << "What is its price? ";
        getline(cin, input);
        int temp_price = stoi(input); // "casts" the input string to int
        classicPrice[countClassic] = temp_price; // sets price to that temp value

        // output edited menu item for user
        cout << "Here is the new menu item: " << classicName[countClassic] << ": $" << classicPrice[countClassic] << endl;

        countClassic++;


    }

    void remove_classic() {

        if (countClassic == 0) { // if there's nothing to remove
            cout << "Error: no starters to remove!" << endl;
        }
        else {

            cout << "Enter Existing Starter item (enter its numerical index): ";
            cin >> temp;

            if (temp == countClassic) { // removing last item can just be done by not listing it
                countClassic--;
            }
            else if (temp > countClassic || temp < 1) { // if index is out of bounds
                cout << "Error: index out of bounds." << endl;
            }
            else {

                for (int i = temp; i < countClassic; i++) {
                    // shift every item after the removed item down to fill the gap
                    classicName[i - 1] = classicName[i];
                    classicPrice[i - 1] = classicPrice[i];
                }

                countClassic--;
            }
        }

    }

    void edit_classic() { // Edits an entry in the starter list
        string input;

        if (countClassic == 0) { // if there's nothing to edit
            cout << "Error: no starters to edit!" << endl;
        }
        else {
            cout << "Enter Existing Starter item (enter its numerical index): ";
            cin >> temp;

            cin.ignore(); // prevents the later getline from consuming the \n

            if (temp > countClassic || temp < 1) { // if index is out of bounds
                cout << "Error: index out of bounds." << endl;
            }
            else {
                temp -= 1; // changes 0-based indexing to 1-based

                cout << "Edit name? (Enter name or 'n' for no): ";
                getline(cin, input); // Getline rather than cin to read spaces

                if (input == "n") { // do nothing if user doesn't want to change name

                }
                else {
                    classicName[temp] = input; // otherwise change name
                }

                cout << "Edit price? (Enter price or 'n' for no): ";
                getline(cin, input);

                if (input == "n") {


                }
                else {
                    int temp_price = stoi(input); // "casts" the input string to int
                    classicPrice[temp] = temp_price; // sets price to that temp value
                }

                // output edited menu item for user
                cout << "Here is the updated menu item: " << classicName[temp] << ": $" << classicPrice[temp] << endl;
            }
        }

    }

    void randomize_classic() {

        for (int i = 0; i < countClassic; i++) { // for every starter item,
            randClassic[i] = classicName[i];     // copy each item to a new array
            randPrice[i] = classicPrice[i];
        }

        for (int i = 0; i < countClassic; i++) {
            temp = rand() % countClassic; // generate an index (to swap)

            string tempElement = randClassic[temp]; // generate a temporary place to put the index-th element
            int tempPrice = randPrice[temp];

            randClassic[temp] = randClassic[i]; // swap the ith element with the random index
            randPrice[temp] = randPrice[i];

            randClassic[i] = tempElement;
            randPrice[i] = tempPrice;
        }
    }

    void display_classic() {
        cout << "Random Classics\n" << endl;
        for (int i = 0; i < 7; i++)

            cout << randClassic[i] << " $" << randPrice[i] << endl << endl;
    }

    void show_classic() {   //Displaying all items in starter array
        for (int i = 0; i < countClassic; i++) {

            cout << endl;

            cout << i + 1 << ". " << classicName[i] << " $" << classicPrice[i] << endl;

        }
    }
};

#endif
