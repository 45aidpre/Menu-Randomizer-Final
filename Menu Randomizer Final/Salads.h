#include "Starters.h"
#ifndef SALADS_H
#define SALADS_H

#include <iostream>


class Salad : virtual public Starter {
    std::vector<int> saladPrice = { 11, 14, 15, 15, 15 };
    std::vector<std::string> saladName = { "Caesar Salad", "California Cobb", "Asian Shrimp Salad",
                        "Wedge Salad", "Spinach Salad" };

    std::vector<int> randPrice = {};
    std::vector<std::string> randSalad = {};
    int countSalad = 5;
    int temp;

public:

    void add_salad() {

        std::string input;
        std::cin.ignore();
        std::cout << "What is the new starter? (enter name): ";
        std::getline(std::cin, input); // Getline rather than cin to read spaces
        saladName[countSalad] = input;


        std::cout << "What is its price? ";
        std::getline(std::cin, input);
        int temp_price = stoi(input); // "casts" the input string to int
        saladPrice[countSalad] = temp_price; // sets price to that temp value

        // output edited menu item for user
        std::cout << "Here is the new menu item: " << saladName[countSalad] << ": $" << saladPrice[countSalad] << std::endl;

        countSalad++;


    }

    void remove_salad() {

        if (countSalad == 0) { // if there's nothing to remove
            std::cout << "Error: no starters to remove!" << std::endl;
        }
        else {

            std::cout << "Enter Existing Starter item (enter its numerical index): ";
            std::cin >> temp;

            if (temp == countSalad) { // removing last item can just be done by not listing it
                countSalad--;
            }
            else if (temp > countSalad || temp < 1) { // if index is out of bounds
                std::cout << "Error: index out of bounds." << std::endl;
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
        std::string input;

        if (countSalad == 0) { // if there's nothing to edit
            std::cout << "Error: no starters to edit!" << std::endl;
        }
        else {
            std::cout << "Enter Existing Starter item (enter its numerical index): ";
            std::cin >> temp;

            std::cin.ignore(); // prevents the later getline from consuming the \n

            if (temp > countSalad || temp < 1) { // if index is out of bounds
                std::cout << "Error: index out of bounds." << std::endl;
            }
            else {
                temp -= 1; // changes 0-based indexing to 1-based

                std::cout << "Edit name? (Enter name or 'n' for no): ";
                std::getline(std::cin, input); // Getline rather than cin to read spaces

                if (input == "n") { // do nothing if user doesn't want to change name

                }
                else {
                    saladName[temp] = input; // otherwise change name
                }

                std::cout << "Edit price? (Enter price or 'n' for no): ";
                std::getline(std::cin, input);

                if (input == "n") {


                }
                else {
                    int temp_price = stoi(input); // "casts" the input string to int
                    saladPrice[temp] = temp_price; // sets price to that temp value
                }

                // output edited menu item for user
                std::cout << "Here is the updated menu item: " << saladName[temp] << ": $" << saladPrice[temp] << std::endl;
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

            std::string tempElement = randSalad[temp]; // generate a temporary place to put the index-th element
            int tempPrice = randPrice[temp];

            randSalad[temp] = randSalad[i]; // swap the ith element with the random index
            randPrice[temp] = randPrice[i];

            randSalad[i] = tempElement;
            randPrice[i] = tempPrice;
        }
    }

    void display_salad() {
        std::cout << "Random Salads:\n" << std::endl;
        for (int i = 0; i < 3; i++)

            std::cout << randSalad[i] << " $" << randPrice[i] << std::endl << std::endl;
    }

    void show_salad() {   //Displaying all items in starter array
        for (int i = 0; i < countSalad; i++) {

            std::cout << std::endl;

            std::cout << i + 1 << ". " << saladName[i] << " $" << saladPrice[i] << std::endl;

        }
    }
};

#endif
