#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <QtSql>
#include <QtDebug>
#include "services.h"
#include "data.h"
#include "infotype.h"
#include "ui.h"

using namespace std;

const int yearNow = 2015;
const int CstartYear = 1791;
//birth year of Charles Babbage should do for beginning year of computer science - BóE


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
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

        switch(choice)
        {
            case 1:
                getInfo();
                break;
            case 2:
                p.viewInfo();
                break;
            case 3:
                sortMenu();
                break;
            case 4:
                p.searchVector();
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

        choice = chooseNumber();

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
        choice = chooseNumber();

        switch(choice)
        {
            case 1:
            {
                p.sortByNameAsc();
                break;
            }
            case 2:
            {
                p.sortByNameDesc();
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
        choice = chooseNumber();

        switch(choice)
        {
            case 1:
            {
                p.sortByGenderMale();
                break;
            }
            case 2:
            {
                p.sortByGenderFemale();
                break;
             }
            case 3:
            {
                p.sortByGenderUndecided();
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
        choice = chooseNumber();

        switch(choice)
        {
            case 1:
            {
                p.sortByYearAsc();
                break;
            }
            case 2:
            {
                p.sortByYearDesc();
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
        choice = chooseNumber();

        switch(choice)
        {
             case 1:
             {
                p.sortByDeathYearAsc();
                break;
             }
             case 2:
             {
                p.sortByDeathYearDesc();
                break;
             }
            case 3:
            {
               p.sortByDeceased();
               break;
            }
            case 4:
            {
               p.sortByNotDeceased();
               break;
            }
             case 5:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}
void UI::searchMenu()
{
    Services p;

    int choice;

    do{
        cout << "* * * SEARCH INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Search by name"<< endl;
        cout << "2. Search by gender"<< endl;
        cout << "3. Search by year of birth"<< endl;
        cout << "4. Search by year of death"<< endl;
        cout << "5. Return to main menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

        switch(choice)
        {
            case 1:
                p.searchVectorName();
                break;
            case 2:
                p.searchVectorGender();
                break;
            case 3:
                p.searchVectorBirthYear();
                break;
            case 4:
                p.searchVectorBirthYear();
                break;
            case 5:
                //FP.clear();//hreinsum vektorinn eftir notkun
                userMenu();
                break;
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5); //eða while(choice != 5);

}
int UI::chooseNumber()
{
    int choice;
    cout << "Please choose one of these numbers: ";
    cin >> choice;
    cout << "===========================================" << endl;
    cout << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
        {
            displayError();
        }
    return choice;
}

void UI::displayError()
{
    cout << "------------------------------------------" << endl;
    cout << "| | | Wrong input. Please try again. | | |" << endl;
    cout << "------------------------------------------" << endl;
}
void UI::getInfo()
{

    ofstream getFile;
    getFile.open("InfoFile.txt", ios::app);
    //nota ios::app svo það skrifist ekki yfir fyrirliggjandi gögn - BóE
    //fasti sem er skilgreindur í iostream, opnast þannig að við getum bætt við hana - BóE

        if(getFile.fail( ))
        {
            cout << "Could not open file." << endl;
            exit(1);
            //ef skrá opnast ekki þá hoppum við út bætti við cstdlib til að nota exitið - BóE
        }

    char keepGoing = ' ';
    //færibreytur núllstilltar svo rusl fylgi ekki með - BóE

    cout << "* * * INPUT INFORMATION * * *" << endl;
    cout << endl;
    do{
        string name = getName();
        char gender = getGender();
        int bYear = getBirthYear();
        int dYear = getDeathYear(name, bYear);

        Services p;
        p.addPerson(name, gender, bYear, dYear);

        //CONTINUE
        do{
            cout << "Input more information (Y for yes/N for no): ";
            cin >> keepGoing;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
                if(toupper(keepGoing) != 'Y' && toupper(keepGoing) != 'N')
                {
                    displayError();
                }
            cout << endl;
        }while(toupper(keepGoing) != 'Y' && toupper(keepGoing) != 'N');

    }while(toupper(keepGoing) == 'Y');
}
string UI::getName()
{
    bool check = false;
    string name = " ";

    do{
        cout << "Input name (in the order first, middle and last name): ";
        cin.clear();
        getline(cin, name);
        check = false;
        //athuga hvort innslátturinn innihaldi nokkuð tölur
        for(unsigned int i = 0; i < name.size(); i++)
        {
            if(isdigit(name[i]))
            {
                check = true;
            }
        }
        if(check == true)
        {
           displayError();
        }
    }while(check == true);

    return name;
}
char UI::getGender()
{
    char gender = ' ';
    do{
        cout << "Input gender (F for female/M for male /? for undecided): ";
        cin >> gender;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
            if(toupper(gender) != 'F' && toupper(gender) != 'M' && gender != '?')
            {
               displayError();
            }
    }while(toupper(gender) != 'F' && toupper(gender) != 'M' && gender != '?');

    return gender;
}
int UI::getBirthYear()
{
    int bYear = 0;

    do{
        cout << "Input year of birth: ";
        cin >> bYear;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
            if(!((bYear < yearNow) && (bYear >= CstartYear)))
            {
                displayError();
            }
    }while(!((bYear < yearNow) && (bYear >= CstartYear)));

    return bYear;
}
int UI::getDeathYear(string name, int bYear)
{
        int dYear = 0;
        char personDead = ' ';

        do{
            cout << "Is " << name << " deceased? (Y for yes/ N for no): ";
            cin >> personDead;
            cin.clear();
            cin.ignore(INT_MAX, '\n');

                if(toupper(personDead) != 'Y' && toupper(personDead) != 'N')
                {
                    displayError();
                }

                if(toupper(personDead) == 'Y')
                //fallegra að nota toupper frekar en langa uppröðun - BóE
                {
                    do{
                        cout << "Input year of death: ";
                        cin >> dYear;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                            if(!((dYear > bYear) && (dYear <= yearNow)))
                            {
                                displayError();
                            }
                    }while(!((dYear > bYear) && (dYear <= yearNow)));
                    //year of birth has to be less than year of death - BÓE
                    //do not do equal since it is highly unlikely that a famous person would be less than 1 years old - BóE
                    //use a constant for the year, now it is set to 2015, death year should be less or equal

                }
                if(toupper(personDead) == 'N')
                {
                    //all deceased get zero as input for year of death, equals NULL in SQL - BóE
                    dYear = 0;
                }
        }while(toupper(personDead) != 'Y' && toupper(personDead) != 'N');

    return dYear;
}

void Services::getComputerInfo()
{
    data datalayer;
    datalayer.loadData();


    string computerName = " ";
    int computerYearMade = 0;
    char keepGoing = ' ', computerType = ' ', computerBuilt = ' ';
    //færibreytur núllstilltar svo rusl fylgi ekki með - BóE

    cout << "* * * INPUT INFORMATION * * *" << endl;
    cout << endl;
    do{
        bool check = false;
        do{
            //NAME
            cout << "Input computer name: ";
            cin.clear();
            getline(cin, computerName);

        //GENDER
        do{
            cout << "Input computer type (M for mechanical/E for electronic /T for transistor): ";
            cin >> computerType; //breyta öllum integerum sem heita gender í nýjan integer sem heitir type í staðinn?
            cin.clear();
            cin.ignore(INT_MAX, '\n');
                if(toupper(computerType) != 'M' && toupper(computerType) != 'E' && toupper(computerType) != 'T')
                {
                    cout << "------------------------------------------" << endl;
                    cout << "| | | Wrong input. Please try again. | | |" << endl;
                    cout << "------------------------------------------" << endl;
                }
        }while(toupper(computerType) != 'M' && toupper(computerType) != 'E' && toupper(computerType) != 'T');

        //BIRTH YEAR
        do{
            cout << "Input year made: ";
            cin >> yearMade;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
                if(!((yearMade < yearNow)))
                {
                    cout << "------------------------------------------" << endl;
                    cout << "| | | Wrong input. Please try again. | | |" << endl;
                    cout << "------------------------------------------" << endl;
                }
        }while(!(yearMade < yearNow));


        //DEATH YEAR
        do{
            cout << "Has " << computerName << " been built? (Y for yes/ N for no): ";
            cin >> computerBuilt;
            cin.clear();
            cin.ignore(INT_MAX, '\n');

                if(toupper(computerBuilt) != 'Y' && toupper(computerBuilt) != 'N')
                {
                    cout << "------------------------------------------" << endl;
                    cout << "| | | Wrong input. Please try again. | | |" << endl;
                    cout << "------------------------------------------" << endl;
                }

                if(toupper(computerBuilt) == 'Y')
                //fallegra að nota toupper frekar en langa uppröðun - BóE
                {
                    do{
                        cout << "Input year made: ";
                        cin >> computerYearMade;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                            if(!(computerYearMade <= yearNow))
                            {
                                cout << "------------------------------------------" << endl;
                                cout << "| | | Wrong input. Please try again. | | |" << endl;
                                cout << "------------------------------------------" << endl;
                            }
                    }while(!(computerYearMade <= yearNow));
                }
                if(toupper(computerBuilt) == 'N')
                {
                    int zero = 0;
                    //all deceased get zero as input for year of death - BóE
                }
        }while(toupper(computerBuilt) != 'Y' && toupper(computerBuilt) != 'N');

        //CONTINUE
        do{
            cout << "Input more information (Y for yes/N for no): ";
            cin >> keepGoing;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
                if(toupper(keepGoing) != 'Y' && toupper(keepGoing) != 'N')
                {
                    cout << "------------------------------------------" << endl;
                    cout << "| | | Wrong input. Please try again. | | |" << endl;
                    cout << "------------------------------------------" << endl;
                }
            cout << endl;
            addComputer(computerName, computerYearMade, computerType, computerBuilt);

        }while(toupper(keepGoing) != 'Y' && toupper(keepGoing) != 'N');

    }while(toupper(keepGoing) == 'Y');
}
