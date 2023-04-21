//Randomized Lunch Menu
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <fstream>
#include <vector>
#include "Starters.h"
#include "Salads.h"
#include "Classics.h"
#include "Menu.h"
#include "Interface.h"


class newUser {
public:

    int hashPassword(std::string const& Combine) {
        unsigned int hash = 0;

        const unsigned int VALUE = Combine.length();
        for (auto Letter : Combine)
        {
            srand(VALUE * Letter);
            hash += 33 + rand() % 92;
        }
        return hash;
    }

    bool getUsers(std::string userEntered) {

        for (auto item : s1) {

            if (userEntered.compare(item) == 0)

                return true;
        }
        return false;
    }

    bool getPass(std::string passEntered) {

        for (auto item : s2) {

            if (passEntered.compare(item) == 0)

                return true;
        }
        return false;
    }

    bool loginCreationAttempt() {
        std::string userCode;
        std::cout << "Enter Company Code: ";
        std::cin >> userCode;

        if (compCode.compare(userCode) == 0) {
            //ask for username and password
            std::cout << "Enter New Username and Password.\n Username: ";
            std::cin >> userAttempt;
            s1.push_back(std::to_string(hashPassword(userAttempt)));
            std::cout << "Enter Passord: ";
            std::cin >> passAttempt;
            s2.push_back(std::to_string(hashPassword(passAttempt)));

            return true;
        }
        else {

            std::cout << "Wrong Code" << "\n";

            return false;

        }

        return true; // tells main that user is logged in.
    }

    
private:
    std::string userAttempt; 
    std::string passAttempt;
    std::pair<std::string, std::string> s3;
    std::vector<std::string> s1;
    std::vector<std::string> s2;
    std::string compCode = "8510";
};
bool login(newUser& Obj1) {
    std::string isNew;
    std::string userName;
    std::string passWord;


    //checks if the user already has an account
    std::cout << "Do you have an account? (y/n)\n";
    getline(std::cin >> std::ws, isNew);
    std::transform(isNew.begin(), isNew.end(), isNew.begin(), ::tolower); // transforms to lower case


    if (isNew == "n" || isNew == "no") {

        Obj1.loginCreationAttempt();

        return false;
    }
    else {

        std::cout << "Enter Your Username\nUsername: ";
        std::cin >> userName;
        userName = std::to_string(Obj1.hashPassword(userName));
        std::cout << "Enter Your Password\nPassword: ";
        std::cin >> passWord;
        passWord = std::to_string(Obj1.hashPassword(passWord));
        if (Obj1.getUsers(userName) && Obj1.getPass(passWord)) { //Compare together fix later

            return true;

        }

        std::cout << "Wrong Username and Password Combination" << "\n";

        return false;

    }

}

    

int main() {

    newUser user;

    while (login(user) != true);

    Interface b;

    srand(time(NULL));

    b.summon_interface();

    return 0;
}
