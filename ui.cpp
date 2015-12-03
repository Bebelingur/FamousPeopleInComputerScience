#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include "services.h"
#include "data.h"
#include "infotype.h"
#include "ui.h"

using namespace std;

UI::UI()
{

}

void UI::userMenu()
{
    Services p;

    int choice;

    do{
        cout << endl;
        cout << "===========================================" << endl;
        cout << "==   Famous People In Computer Science   ==" << endl;
        cout << "===========================================" << endl;
        cout << "1. Input information" << endl;
        cout << "2. View information" << endl;
        cout << "3. Sort information" << endl;
        cout << "4. Search information" << endl;
        cout << "5. Exit" << endl;
        cout << "===========================================" << endl;

        do{
            cout << "Please choose one of these numbers: ";
            cin >> choice;
            cout << "===========================================" << endl;
            cout << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
                if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
                {
                    cout << "------------------------------------------" << endl;
                    cout << "| | | Wrong input. Please try again. | | |" << endl;
                    cout << "------------------------------------------" << endl;
                }
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

        switch(choice)
        {
            case 1:
                p.getInfo();
                break;
            case 2:
                p.viewInfo();
                break;
            case 3:
                sortMenu();
                break;
            case 4:
                p.searchVector(p.FP);
                break;
            case 5:
                exit(1);
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5); //eða while(choice != 5);
    //náði að láta virka aðeins, google to the rescue :)  - BóE
}

void UI::sortMenu()
{
    int choice;

    do{
        cout << "* * * SORT INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by name" << endl;
        cout << "2. Sort by gender" << endl;
        cout << "3. Sort by year of birth" << endl;
        cout << "4. Sort by year of death" << endl;
        cout << "5. Return to main menu" << endl;
        cout << "===========================================" << endl;
        cout << "Please choose one of these numbers: ";
        cin >> choice;
        cout << "===========================================" << endl;
        cout << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
        {
                cout << "------------------------------------------" << endl;
                cout << "| | | Wrong input. Please try again. | | |" << endl;
                cout << "------------------------------------------" << endl;
        }

        switch(choice)
        {
            case 1:
            {
            sortNameMenu();
                break;
            }
            case 2:
            {
            sortGenderMenu();
                break;
            }
            case 3:
            {
            sortYearOfBirthMenu();
                break;
            }
            case 4:
            {
            sortYearOfDeathMenu();
                break;
            }
            case 5:
            {
            userMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
    sortMenu();
}

void UI::sortNameMenu()
{
    Services p;

    int choice;

    do{
        cout << "* * * SORT BY NAME INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by name (Ascending)" << endl;
        cout << "2. Sort by name (Descending)" << endl;
        cout << "3. Return to sort menu" << endl;
        cout << "===========================================" << endl;
        cout << "Please choose one of these numbers: ";
        cin >> choice;
        cout << "===========================================" << endl;
        cout << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if(choice != 1 && choice != 2 && choice != 3)
        {
                cout << "------------------------------------------" << endl;
                cout << "| | | Wrong input. Please try again. | | |" << endl;
                cout << "------------------------------------------" << endl;
        }

        switch(choice)
        {
            case 1:
            {
                p.sortByNameAsc(p.FP);
                break;
            }
            case 2:
            {
                p.sortByNameDesc(p.FP);
                break;
            }
            case 3:
            {
                sortMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}



void UI::sortGenderMenu()
{
    Services p;

    int choice;

    do{
        cout << "* * * SORT BY GENDER INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by male" << endl;
        cout << "2. Sort by female" << endl;
        cout << "3. Sort by undecided" << endl;
        cout << "4. Return to sort menu" << endl;
        cout << "===========================================" << endl;
        cout << "Please choose one of these numbers: ";
        cin >> choice;
        cout << "===========================================" << endl;
        cout << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if(choice != 1 && choice != 2 && choice != 3 && choice != 4)
        {
                cout << "------------------------------------------" << endl;
                cout << "| | | Wrong input. Please try again. | | |" << endl;
                cout << "------------------------------------------" << endl;
        }

        switch(choice)
        {
            case 1:
            {
                p.sortByGenderMale(p.FP);
                break;
            }
            case 2:
            {
                p.sortByGenderFemale(p.FP);
                break;
             }
            case 3:
            {
                p.sortByGenderUndecided(p.FP);
                break;
             }
             case 4:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4);
}


void UI::sortYearOfBirthMenu()
{
    Services p;

    int choice;

    do{
        cout << "* * * SORT BY YEAR OF BIRTH INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by year of birth (Ascending)" << endl;
        cout << "2. Sort by year of birth (Descending)" << endl;
        cout << "3. Return to sort menu" << endl;
        cout << "===========================================" << endl;
        cout << "Please choose one of these numbers: ";
        cin >> choice;
        cout << "===========================================" << endl;
        cout << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if(choice != 1 && choice != 2 && choice != 3)
        {
                cout << "------------------------------------------" << endl;
                cout << "| | | Wrong input. Please try again. | | |" << endl;
                cout << "------------------------------------------" << endl;
        }

        switch(choice)
        {
            case 1:
            {
                p.sortByYearAsc(p.FP);
                break;
            }
            case 2:
            {
                p.sortByYearDesc(p.FP);
                break;
            }
            case 3:
            {
                sortMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3 );
}

void UI::sortYearOfDeathMenu()
{
    Services p;

    int choice;

    do{
        cout << "* * * SORT BY YEAR OF DEATH INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by year of death (Ascending)" << endl;
        cout << "2. Sort by year of death (Descending)" << endl;
        cout << "3. Sort by year of death (deceased only)" << endl;
        cout << "4. Sort by year of death (not deceased)" << endl;
        cout << "5. Return to sort menu" << endl;
        cout << "===========================================" << endl;
        cout << "Please choose one of these numbers: ";
        cin >> choice;
        cout << "===========================================" << endl;
        cout << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
        {
                cout << "------------------------------------------" << endl;
                cout << "| | | Wrong input. Please try again. | | |" << endl;
                cout << "------------------------------------------" << endl;
        }

        switch(choice)
        {
             case 1:
             {
                p.sortByDeathYearAsc(p.FP);
                break;
             }
             case 2:
             {
                p.sortByDeathYearDesc(p.FP);
                break;
             }
            case 3:
            {
               p.sortByDeceased(p.FP);
               break;
            }
            case 4:
            {
               p.sortByNotDeceased(p.FP);
               break;
            }
             case 5:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}
