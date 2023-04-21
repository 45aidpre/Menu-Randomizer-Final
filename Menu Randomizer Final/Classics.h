#include "Starters.h"
#ifndef CLASSICS_H
#define CLASSICS_H

#include <iostream>

class Classic : virtual public Salad {
    std::vector<int> classicPrice = { 10, 13, 14, 14, 19, 13, 13, 14, 16 };
    std::vector<std::string> classicName = { "Hotdog", "Cucumber Sandwich", "Reuben", "Wells BLT","Grouper Sandwich","Wells Quesadilla","SWCC Grilled Cheese","Black Angus Beef Burger","Fish & Chips:\n Haddock" };

    std::vector<int> randPrice;
    std::vector<std::string> randClassic;
    int countClassic = 9;
    int temp;
public:

    void add_classic() {

        std::string input;
        std::cin.ignore();
        std::cout << "What is the new starter? (Please enter its numerical index of the item): ";
        std::getline(std::cin, input); // Getline rather than cin to read spaces
        classicName[countClassic] = input;


        std::cout << "What is its price? ";
        std::getline(std::cin, input);
        int temp_price = std::stoi(input); // "casts" the input string to int
        classicPrice[countClassic] = temp_price; // sets price to that temp value

        // output edited menu item for user
        std::cout << "Here is the new menu item: " << classicName[countClassic] << ": $" << classicPrice[countClassic] << std::endl;

        countClassic++;


    }

    void remove_classic() {

        if (countClassic == 0) { // if there's nothing to remove
            std::cout << "Error: no starters to remove!" << std::endl;
        }
        else {

            std::cout << "Enter Existing Starter item (enter its numerical index): ";
            std::cin >> temp;

            if (temp == countClassic) { // removing last item can just be done by not listing it
                countClassic--;
            }
            else if (temp > countClassic || temp < 1) { // if index is out of bounds
                std::cout << "Error: index out of bounds." << std::endl;
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
        std::string input;

        if (countClassic == 0) { // if there's nothing to edit
            std::cout << "Error: no starters to edit!" << std::endl;
        }
        else {
            std::cout << "Enter Existing Starter item (enter its numerical index): ";
            std::cin >> temp;

            std::cin.ignore(); // prevents the later getline from consuming the \n

            if (temp > countClassic || temp < 1) { // if index is out of bounds
                std::cout << "Error: index out of bounds." << std::endl;
            }
            else {
                temp -= 1; // changes 0-based indexing to 1-based

                std::cout << "Edit name? (Enter name or 'n' for no): ";
                std::getline(std::cin, input); // Getline rather than cin to read spaces

                if (input == "n") { // do nothing if user doesn't want to change name

                }
                else {
                    classicName[temp] = input; // otherwise change name
                }

                std::cout << "Edit price? (Enter price or 'n' for no): ";
                std::getline(std::cin, input);

                if (input == "n") {


                }
                else {
                    int temp_price = stoi(input); // "casts" the input string to int
                    classicPrice[temp] = temp_price; // sets price to that temp value
                }

                // output edited menu item for user
                std::cout << "Here is the updated menu item: " << classicName[temp] << ": $" << classicPrice[temp] << std::endl;
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

            std::string tempElement = randClassic[temp]; // generate a temporary place to put the index-th element
            int tempPrice = randPrice[temp];

            randClassic[temp] = randClassic[i]; // swap the ith element with the random index
            randPrice[temp] = randPrice[i];

            randClassic[i] = tempElement;
            randPrice[i] = tempPrice;
        }
    }

    void display_classic() {
        std::cout << "Random Classics\n" << std::endl;
        for (int i = 0; i < 7; i++)

            std::cout << randClassic[i] << " $" << randPrice[i] << "\n" << std::endl;
    }

    void show_classic() {   //Displaying all items in starter array
        for (int i = 0; i < countClassic; i++) {

            std::cout << std::endl;

            std::cout << i + 1 << ". " << classicName[i] << " $" << classicPrice[i] << std::endl;

        }
    }
};

#endif
