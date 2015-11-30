#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "famouspeople.h"
#include "data.h"

using namespace std;

const int yearNow = 2015;
const int CstartYear = 1791;
//birth year of Charles Babbage should do for beginning year of computer science
//kannski finna fall með nákvæmri dagsetnintu/ári hvers dags fyrir sig

FamousPeople::FamousPeople()
{
     data datalayer;
     datalayer.loadData();
}

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
                fillVector(FP);
                sortMenu();
                break;
            case '4':
                searchVector(FP);
                break;
            case '5':
                break;
            default:
                cout << "Wrong input! Please try again" << endl;
                break;
        }
    }while(choice != '5');
}

void FamousPeople::sortMenu()
{
    char choice;
    do{
    cout << "How would you like to sort?" << endl;
    cout << "1. Sort by name (Ascending)" << endl;
    cout << "2. Sort by name (Descending)" << endl;
    cout << "3. Sort by birth year (Ascending)" << endl;
    cout << "4. Sort by birth year (Descending)" << endl;
    cout << "5. Return" << endl;
    cout << "===========================================" << endl;
    cout << "Please choose one of these numbers: ";
    cin >> choice;
    cout << "===========================================" << endl;

        switch(choice)
        {
            case '1':
                {
                sortByNameAsc(FP);
                break;
                }
            case '2':
                {
                sortByNameDesc(FP);
                break;
                }

            case '3':
                {
                sortByYearAsc(FP);
                break;
                }
            case '4':
                {
                sortByYearDesc(FP);
                break;
                }

            case '5':
                break;
            default:
                cout << "Wrong input! Please try again" << endl;
                break;
        }
    }while(choice != '5');
}

bool compareNameAsc(const InfoType& a, const InfoType& b);

bool compareNameAsc(const InfoType& a, const InfoType& b)
{
    return a.name < b.name;
}


bool compareNameDesc(const InfoType& a, const InfoType& b);

bool compareNameDesc(const InfoType& a, const InfoType& b)
{
    return a.name > b.name;
}


bool compareYearAsc(const InfoType& a, const InfoType& b);

bool compareYearAsc(const InfoType& a, const InfoType& b)
{
    return a.birthYear < b.birthYear;
}


bool compareYearDesc(const InfoType& a, const InfoType& b);

bool compareYearDesc(const InfoType& a, const InfoType& b)
{
    return a.birthYear > b.birthYear;
}


void FamousPeople::sortByNameAsc(vector <InfoType>& FP)
{
    cout << "--- Displaying people by name in asccending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        cout << "Name: " << FP.at(i).name << endl;

        if(FP.at(i).gender == 'F')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(FP.at(i).gender == 'M')
        {
        cout << "Gender: " << "Male" << endl;
        }
        else
        {
         cout << "Unknown" << endl;
        }

        cout << "Birth year: " << FP.at(i).birthYear << endl;

        if(FP.at(i).deathYear == 0)
        {
            cout << endl;
        }
        else
        {
        cout << "Death year: " << FP.at(i).deathYear << endl;
        }

        cout << endl;
    }
}


void FamousPeople::sortByNameDesc(vector <InfoType>& FP)
{
    cout << "--- Displaying people by name in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameDesc);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        cout << "Name: " << FP.at(i).name << endl;

        if(FP.at(i).gender == 'F')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(FP.at(i).gender == 'M')
        {
        cout << "Gender: " << "Male" << endl;
        }
        else
        {
         cout << "Unknown" << endl;
        }

        cout << "Birth year: " << FP.at(i).birthYear << endl;

        if(FP.at(i).deathYear == 0)
        {
            cout << endl;
        }
        else
        {
        cout << "Death year: " << FP.at(i).deathYear << endl;
        }

        cout << endl;
    }
}


void FamousPeople::sortByYearAsc(vector <InfoType>& FP)
{
    cout << "--- Displaying people by birth year in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareYearAsc);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        cout << "Name: " << FP.at(i).name << endl;


        if(FP.at(i).gender == 'F')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(FP.at(i).gender == 'M')
        {
        cout << "Gender: " << "Male" << endl;
        }
        else
        {
         cout << "Unknown" << endl;
        }

        cout << "Birth year: " << FP.at(i).birthYear << endl;

        if(FP.at(i).deathYear == 0)
        {
            cout << endl;
        }
        else
        {
        cout << "Death year: " << FP.at(i).deathYear << endl;
        }

        cout << endl;
    }
}

void FamousPeople::sortByYearDesc(vector <InfoType>& FP)
{
    cout << "--- Displaying people by birth year in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareYearDesc);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        cout << "Name: " << FP.at(i).name << endl;

        if(FP.at(i).gender == 'F')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(FP.at(i).gender == 'M')
        {
        cout << "Gender: " << "Male" << endl;
        }
        else
        {
         cout << "Unknown" << endl;
        }

        cout << "Birth year: " << FP.at(i).birthYear << endl;

        if(FP.at(i).deathYear == 0)
        {
            cout << endl;
        }
        else
        {
        cout << "Death year: " << FP.at(i).deathYear << endl;
        }

        cout << endl;
    }
}

void FamousPeople::getInfo()
{
    ofstream getFile;
    getFile.open("InfoFile.txt", ios::app);
    //nota ios::app svo það skrifist ekki yfir fyrirliggjandi gögn
    //fasti sem er skilgreindur í iostream, opnast þannig að við getum bætt við hana

    if(getFile.fail( ))
    {
        cout << "Could not open file." << endl;
        exit(1);
        //ef skrá opnast ekki þá hoppum við út bætti við cstdlib til að nota exitið
    }
        string name = " ";
        int bYear = 0, dYear = 0;
        char keepGoing = ' ', gender = ' ', personDead = ' ';
        //færibreytur núllstilltar svo rusl fylgi ekki með

        do{
            cin.ignore();
            cout << "Input name (in the order first, middle and last name): ";
            getline(cin, name);
            getFile << name << "*";

            do{
                cout << "Input gender (F for female, M for male or ? for other): ";
                cin >> gender;
                    if(!(gender == 'F' || gender == 'M' || gender == '?'))
                    {
                        cout << "Wrong input. Please try again." << endl;
                    }
            }while(!(gender == 'F' || gender == 'M' || gender == '?'));
            getFile << gender << " ";

            do{
                cout << "Input year of birth: ";
                cin >> bYear;
                if(!((bYear < yearNow) && (bYear >= CstartYear)))
                {
                    cout << "Wrong input. Please try again." << endl;
                }
            }while(!((bYear < yearNow) && (bYear >= CstartYear)));
            getFile << bYear << " ";

                cout << "Is " << name << " deceased? (Y for yes N for no): ";
                cin >> personDead;
                if(personDead == 'Y' || personDead == 'y')
                {
                    do
                    {
                    cout << "Input year of death: ";
                    cin >> dYear;
                    if(dYear < bYear)
                    {
                        cout << "Wrong input. Please try again." << endl;
                    }
                    else
                    {
                        getFile << dYear;
                    }
                    }while(dYear < bYear);
                }
                else
                {
                    int zero = 0;
                    getFile << zero;
                }
            cout << "Input more information (Y for yes N for no): ";
            cin >> keepGoing;
        }while(keepGoing == 'Y' || keepGoing == 'y');

    getFile.close( );
}

void FamousPeople::displayPerson(InfoType p)
{
    cout<<endl;
    cout << "Name: " << p.name << endl;
    cout << "Gender: ";
        if(p.gender == 'f' || p.gender == 'F')
        {
            cout << "Female" << endl;
        }
        else if (p.gender == 'm' || p.gender == 'M')
        {
            cout << "Male" << endl;
        }
        else if (p.gender == '?')
        {
            cout << "Other" << endl;
        }
    cout << "Year of birth: " << p.birthYear << endl;
    if(p.deathYear != 0)
    {
        cout << "Year of death: " << p.deathYear << endl;

    cout<<endl;

    }
    cout << endl;
}

void FamousPeople::viewInfo()
{
    ifstream getFile;
    getFile.open("InfoFile.txt");
    if(getFile.fail())
    {
        cout << "Could not open file." << endl;
        exit(1);
    }
    cout << endl;
    while(!getFile.eof())
    {
        InfoType p;

        getline(getFile, p.name, '*');
        getFile >> p.gender;
        getFile >> p.birthYear;
        getFile >> p.deathYear;
        displayPerson(p);
    }
    getFile.close();
    char input;
    cout << "Press any key to return to menu." << endl;
    cin >> input;
    if(input)
        userMenu();
}

void FamousPeople::fillVector(vector<InfoType>& FP)
{
    ifstream getFile;
    getFile.open("InfoFile.txt");

    if(getFile.fail())
    {
        cout << "Could not open file." << endl;
    }
    else{

        while(!getFile.eof())
        {
            InfoType p;
            getline(getFile, p.name, '*');
            getFile >> p.gender;
            getFile >> p.birthYear;
            getFile >> p.deathYear;

            FP.push_back(p);
        }

        //cout << "Press r to return to user menu. " << endl;
    getFile.close();
    }
}

void FamousPeople::searchVector(vector <InfoType>& FP)
{
<<<<<<< HEAD
    fillVector(FP);//búum til vektorinn
    int choise;
   //gerum breytur fyrir hvert leitarskilyrði
=======
    fillVector(FP);

    int choice;
>>>>>>> 3503e30733caf005fa1dacf950fe0186f3873094
    string nameSearch;
    char genderSearch;
    int birthYearSearch;
    int deathYearSearch;

    bool check = false;//check til að athuga hvort það sé búið að finna í leitinni
    do
        {
<<<<<<< HEAD
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

            int nameSize = nameSearch.size();
            for(int i = 0; i < nameSize; i++)
                 nameSearch[i] = tolower(nameSearch[i]);
            //setjum innsláttinn í lower case
=======
        cout << "What do you want to search?: " << endl;
        cout << "1. Name"<< endl;
        cout << "2. Gender"<< endl;
        cout << "3. Birth year" << endl;
        cout << "4. Death year" << endl;
        cout << "5. Return " << endl;
        cin >> choice;
        if(choice == 1)
        {
            cout << "Enter name: ";
            cin >> nameSearch;
            cout << endl;
>>>>>>> 3503e30733caf005fa1dacf950fe0186f3873094
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                string tempName = FP[i].name;
                nameSize = tempName.size();

                for(int j = 0; j < nameSize; j++)
                    tempName[j] = tolower(tempName[j]);
                //setjum nafnið í skjalinu í lower case og berum svo saman

                int found = tempName.find(nameSearch);//athugum hvort innslátturuinn sé hluti af einhverju nafni
                if(found != std::string::npos)
                {
                    displayPerson(FP[i]);
                    check = true;
                }
            }
            if(check == false)
            {
                cout << "Name was not in file" << endl;
            }
        }
        if(choice == 2)
        {
<<<<<<< HEAD
            cout<<"enter gender: ";
            cin>> genderSearch;
            char tempGender;

            genderSearch = tolower(genderSearch);
=======
            cout << "Enter gender: ";
            cin >> genderSearch;
            cout << endl;
>>>>>>> 3503e30733caf005fa1dacf950fe0186f3873094
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                tempGender = FP[i].gender;
                tempGender = tolower(tempGender);

                if(genderSearch == tempGender)
                {
                    displayPerson(FP[i]);
                    check = true;
                }
            }


            if(check == false)
            {
                cout << "Gender was not in file" << endl;
            }
        }
        if(choice == 3)
        {
            cout << "Enter year of birth: ";
            cin >> birthYearSearch;
            cout << endl;
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(birthYearSearch == FP[i].birthYear)
                {
                    displayPerson(FP[i]);
                    check = true;
                }
            }
            if(check == false)
            {
                cout << "Birth year was not in file" << endl;
            }
        }
        if(choice == 4)
        {
            cout << "Enter year of death: ";
            cin >> deathYearSearch;
            cout << endl;
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(deathYearSearch == FP[i].deathYear)

<<<<<<< HEAD
=======
                    displayPerson(FP[i]);
                else
                 cout << "Name was not in file" << endl;

                 cout << "DeathYear was not in file" << endl;

>>>>>>> 3503e30733caf005fa1dacf950fe0186f3873094
                {
                    displayPerson(FP[i]);
                    check = true;
                }
            }
            if(check == false)
            {
<<<<<<< HEAD
                cout<<"death year was not in file"<<endl;
=======
                cout << "Death year was not in file" << endl;

>>>>>>> 3503e30733caf005fa1dacf950fe0186f3873094
            }
        }
        if(choice > 5)
        {
            cout << "Wrong input" << endl;
        }
    }while (choice != 5);

<<<<<<< HEAD
    FP.clear();//hreinsum vektorinn eftir notkun

=======
    FP.clear();

    userMenu();
>>>>>>> 3503e30733caf005fa1dacf950fe0186f3873094
}
