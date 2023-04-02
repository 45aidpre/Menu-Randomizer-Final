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

using namespace std;

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

    bool getUsers(string userEntered) {

        for (auto item : s1) {

            if (userEntered.compare(item) == 0)

                return true;
        }
        return false;
    }

    bool getPass(string passEntered) {

        for (auto item : s2) {

            if (passEntered.compare(item) == 0)

                return true;
        }
        return false;
    }

    bool loginCreationAttempt() {
        string userCode;
        cout << "Enter Company Code: ";
        cin >> userCode;

        if (compCode.compare(userCode) == 0) {
            //ask for username and password
            cout << "Enter New Username and Password.\n Username: ";
            cin >> userAttempt;
            s1.push_back(to_string(hashPassword(userAttempt)));
            cout << "Enter Passord: ";
            cin >> passAttempt;
            s2.push_back(to_string(hashPassword(passAttempt)));

            return true;
        }
        else {

            cout << "Wrong Code" << "\n";

            return false;

        }

        return true; // tells main that user is logged in.
    }

    
private:
    string userAttempt;
    string passAttempt;
    vector<string> s1;
    vector<string> s2;
    string compCode = "8510";
};
bool login(newUser& Obj1) {
    string isNew;
    string userName;
    string passWord;


    //checks if the user already has an account
    cout << "Do you have an account? (y/n)\n";
    getline(cin >> ws, isNew);
    transform(isNew.begin(), isNew.end(), isNew.begin(), ::tolower); // transforms to lower case


    if (isNew == "n" || isNew == "no") {

        Obj1.loginCreationAttempt();

        return false;
    }
    else {

        cout << "Enter Your Username\nUsername: ";
        cin >> userName;
        userName = to_string(Obj1.hashPassword(userName));
        cout << "Enter Your Password\nPassword: ";
        cin >> passWord;
        passWord = to_string(Obj1.hashPassword(passWord));
        if (Obj1.getUsers(userName) && Obj1.getPass(passWord)) { //Compare together fix later

            return true;

        }

        cout << "Wrong Username and Password Combination" << "\n";

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
