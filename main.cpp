#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include "famouspeople.h"

using namespace std;

int main()
{
    char choice;
    cout << "==== Famous People In Computer Science ====" << endl;
    cout << "===========================================" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Input information" << endl;
    //Berglind, eftir getline þá stjarna
    cout << "2. View information" << endl;
    //Dagur
    cout << "3. Sort information" << endl;
    //Hjálmar og Kristófer
    // Sort by last name(ascending and descending)
    // Sort by birth year/death year
    cout << "4. Search information" << endl;
    //Drífa
    cout << "5. Exit" << endl;

    do{
    cout << "Please choose one of these numbers: ";
    cin >> choice;

        switch(choice)
        {
            case '1':
                cout << "1" << endl;
                break;
            case '2':
                cout << "2" << endl;
                break;
            case '3':
                cout << "3" << endl;
                break;
            case '4':
                cout << "4" << endl;
                break;
            case '5':
                cout << "Thank you for using this program!" << endl;
                return 0;
                break;
            default:
                cout << "Wrong input! Please try again" << endl;
                break;
        }
    }while(choice != '5');

    return 0;
}

