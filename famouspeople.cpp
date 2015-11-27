#include <string>
#include <iostream>
#include <vector>
#include "famouspeople.h"

using namespace std;


FamousPeople::FamousPeople()
{}

void FamousPeople::userMenu()
{
    char choice;
    do{
    cout << "===========================================" << endl;
    cout << "==== Famous People In Computer Science ====" << endl;
    cout << "===========================================" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Input information" << endl;
    //Berglind, eftir getline þá stjarna
    cout << "2. View information" << endl;
    //Dagur
    cout << "3. Sort information" << endl;
    //Hjálmar og Kristófer
    cout << "4. Search information" << endl;
    //Drífa
    cout << "5. Exit" << endl;
    cout << "===========================================" << endl;
    cout << "Please choose one of these numbers: ";
    cin >> choice;
    cout << "===========================================" << endl;

        switch(choice)
        {
            case '1':
                getInfo();
                break;
            case '2':
                viewInfo();
                break;
            case '3':
                cout << "3" << endl;
                break;
            case '4':
                cout << "4" << endl;
                break;
            case '5':
                cout << "5" << endl;
                break;
            default:
                cout << "Wrong input! Please try again" << endl;
                break;
        }
    }while(choice != '5');
}

<<<<<<< HEAD
<<<<<<< HEAD


void FamousPeople::sortByNameDesc()
{


}


void FamousPeople::sortByNameAsc()
{


}

void FamousPeople::sortByYearDesc()
{


}

void FamousPeople::sortByYearAsc()
{


}

void FamousPeople::getInfo()
=======
=======


void FamousPeople::getInfo()
{
    ifstream getFile;
    getFile.open("InfoFile.txt");
    if(!getFile)
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        char keepOn;
        do{
            cout << "Input name: ";
            cout << endl;
            cout << "Input gender (F for female, M for male or ? for other): ";
            cout << endl;
            cout << "Input birthYear: ";
            cout << endl;
            cout << "Input deathYear: ";
            cout << endl;
            cout << "Input more information (Y for yes N for no): ";
            cin >> keepOn;
            cout << endl;
        }while(keepOn == 'Y' || keepOn == 'y');
    }
    getFile.close();
}
>>>>>>> e0d49ae766e69b7fd0fb2efd09bbcbbb10f7193a
void FamousPeople::displayPerson(InfoType p){
    cout << "Name: " << p.name << endl;

    cout << "Gender: ";
    if(p.gender == 'f' || p.gender == 'F')
        cout << "Female" << endl;
    else if (p.gender == 'm' || p.gender == 'M')
        cout << "Male" << endl;
    else
        cout << "Other" << endl;

    cout << "Year of birth: " << p.birthYear << endl;

    if(p.deathYear != 0)
        cout << "Year of death: " << p.deathYear << endl;
}

void FamousPeople::viewInfo()
>>>>>>> 616f4ca6e3b4a9e2add4d29c619034bb9eedb70c
{
    ofstream getFile;
    getFile.open("InfoFile.txt");
    if(getFile.fail())
    {
        cout << "Could not open file." << endl;
    }
    else
        while(!getFile.eof())
        {
            InfoType p;
            getline(cin, p.name, '*');
            cin >> p.gender;
            cin >> p.birthYear;
            cin >> p.deathYear;
            displayPerson(p);
        }
    getFile.close();
}



