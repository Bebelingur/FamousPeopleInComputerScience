#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "famouspeople.h"
#include <algorithm>

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
                searchVector(FP);
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
/*

//Fall sem sortar nöfn eftir öfugri stafrófsröð
void FamousPeople::sortByNameDesc(vector <InfoType>& FP)
{

}

//Fall sem sortar nöfn eftir stafrófsröð
void FamousPeople::sortByNameAsc(vector <InfoType>& FP)
{

}

//Fall sem sortar eftir ári, yngst fyrst
void FamousPeople::sortByYearDesc(vector <InfoType>& FP)
{


}


//Fall sem sortar eftir ári, elst fyrst
void FamousPeople::sortByYearAsc(vector <InfoType>& FP)
{


}*/


void FamousPeople::getInfo()
{
    ofstream getFile;
    getFile.open("InfoFile.txt");
    if(getFile.is_open())
    {
        char keepOn;
        do{
            cout << "Input name: ";
            getFile << "writing this to file";
            cout << endl;
            cout << "Input gender (F for female, M for male or ? for other): ";
            cout << endl;
            cout << "Input birth year: ";
            cout << endl;
            cout << "Input death year: ";
            cout << endl;
            cout << "Input more information (Y for yes N for no): ";
            cin >> keepOn;
            cout << endl;
        }while(keepOn == 'Y' || keepOn == 'y');
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


void FamousPeople::fillVector(vector <InfoType>& FP)
{
    int counter = 0;
    ifstream getFile;
    getFile.open("InfoFile.txt");
    string word;

    if(getFile.fail())
    {
        cout << "Could not open file." << endl;
    }
    else{

        while(!getFile.eof())
        {
            InfoType p;
            //getline(cin, p.name, '*');
            getFile >> p.name;
            getFile >> p.gender;
            getFile >> p.birthYear;
            getFile >> p.deathYear;

            FP.push_back(p);

            counter++;
        }
}
    getFile.close();


}
void FamousPeople::searchVector(vector<InfoType>& FP)
{
    fillVector(FP);

    int choise;
    string nameSearch;
    char genderSearch;
    int birthYearSearch;
    int deathYearSearch;
    do
        {
        cout<<"do you want to search: "<<endl;
        cout<<"1 name"<<endl;
        cout<<"2 gender"<<endl;
        cout<<"3 birth year"<<endl;
        cout<<"4 death year"<<endl;
        cout<<"5 return " <<endl;
        cin>> choise;
        if(choise == 1)
        {
            cout<<"enter name: ";
            cin>> nameSearch;
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(nameSearch == FP[i].name)
                    printVector(FP[i]);
                else
                 cout<<"name was not in file"<<endl;
            }
        }
        if(choise == 2)
        {
            cout<<"enter 2: ";
            cin>> genderSearch;
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(genderSearch == FP[i].gender)
                    printVector(FP[i]);
                else
                 cout<<"gender was not in file"<<endl;
            }
        }
        if(choise == 3)
        {
            cout<<"enter birthYear: ";
            cin>> birthYearSearch;
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(birthYearSearch == FP[i].birthYear)
                    printVector(FP[i]);
                else
                 cout<<"birthYear was not in file"<<endl;
            }
        }
        if(choise == 4)
        {
            cout<<"enter deathYear: ";
            cin>> deathYearSearch;
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(deathYearSearch == FP[i].deathYear)
                    printVector(FP[i]);
                else
                 cout<<"deathYear was not in file"<<endl;
            }
        }
        if(choise >5)
        {
            cout<<"wrong input"<<endl;
        }
    }while (choise != 5);

    userMenu();

}
void FamousPeople::printVector(InfoType& FP)const
{
    cout << "Name: " << FP.name << endl;
    cout << "Gender: " << FP.gender << endl;
    cout << "Birth Year: " << FP.birthYear << endl;
    cout << "Death year: " << FP.deathYear << endl;
    cout << endl;
}
