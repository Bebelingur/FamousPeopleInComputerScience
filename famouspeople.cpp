#include <string>
#include <iostream>
#include <vector>
#include <fstream>
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
{

    ofstream getFile;
    getFile.open("InfoFile.txt");

    if(getFile.is_open())
    {
        string firstName = " ", lastName = " ";
        int bYear = 0, dYear = 0;
        char keepGoing = ' ', gender = ' ';

        do{
            cout << "Input name: ";
            getFile << firstName << lastName << " * ";
            cout << endl;
            cout << "Input gender (F for female, M for male or ? for other): ";
            getFile << gender << " * ";
            cout << endl;
            cout << "Input birthYear: ";
            getFile << bYear << " * ";
            cout << endl;
            cout << "Input deathYear: ";
            getFile << dYear << " * ";
            cout << endl;
            cout << "Input more information (Y for yes N for no): ";
            cin >> keepGoing;
            cout << endl;
        }while(keepGoing == 'Y' || keepGoing == 'y');
    }
    else
    {
        cout << "Could not open file." << endl;
    }
    getFile.close();
}

void FamousPeople::displayPerson(InfoType p)
{
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



