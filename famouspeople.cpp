#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
//#include <ctime>
#include "famouspeople.h"

using namespace std;

const int yearNow = 2015;
const int CstartYear = 1791;
//birth year of Charles Babbage should do for beginning year of computer science - BóE
//kannski finna fall með nákvæmri dagsetnintu/ári hvers dags fyrir sig - BóE

FamousPeople::FamousPeople()
{}

void FamousPeople::userMenu()
{
    int choice;
    do{
        cout << "===========================================" << endl;
        cout << "==== Famous People In Computer Science ====" << endl;
        cout << "===========================================" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Input information" << endl;
        cout << "2. View information" << endl;
        cout << "3. Sort information" << endl;
        cout << "4. Search information" << endl;
        cout << "5. Exit" << endl;
        cout << "===========================================" << endl;
        cout << "Please choose one of these numbers: ";
        cin >> choice;
        cout << "===========================================" << endl;

        switch(choice)
        {
            case 1:
                getInfo();
            break;
            case 2:
                viewInfo();
            break;
            case 3:
                fillVector(FP);
                sortMenu();
            break;
            case 4:
                searchVector(FP);
            break;
            case 5:
                exit(1);
            default:
                cout << " | | | Wrong input! Please try again. | | |" << endl;
                break;
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4);
    //næ ekki að láta virka fyrir default :/ - BóE
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
    //þetta er ekki rétt hérna mun keyra vitlaust með while svona - BóE
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
    //nota ios::app svo það skrifist ekki yfir fyrirliggjandi gögn - BóE
    //fasti sem er skilgreindur í iostream, opnast þannig að við getum bætt við hana - BóE

    if(getFile.fail( ))
    {
        cout << "Could not open file." << endl;
        exit(1);
        //ef skrá opnast ekki þá hoppum við út bætti við cstdlib til að nota exitið - BóE
    }
        string name = " ";
        int bYear = 0, dYear = 0;
        char keepGoing = ' ', gender = ' ', personDead = ' ';
        //færibreytur núllstilltar svo rusl fylgi ekki með - BóE

        do{
            cin.ignore();
            //use ignore before getline(cin) to get rid of before use
            cout << "Input name (in the order first, middle and last name): ";
            getline(cin, name);
            getFile << name << "*";

            do{
                cout << "Input gender (F for female/M for male /? for other): ";
                cin >> gender;
                    if(!(toupper(gender) == 'F' || toupper(gender) == 'M' || gender == '?'))
                    {
                        cout << "Wrong input. Please try again." << endl;
                    }
            }while(!(toupper(gender) == 'F' || toupper(gender) == 'M' || gender == '?'));
            getFile << gender << " ";
            //er að koma vitlaust hérna þar sem kkk t.d. skilar 3 útkomum um wrong input

            do{
                cout << "Input year of birth: ";
                cin >> bYear;
                if(!((bYear < yearNow) && (bYear >= CstartYear)))
                {
                    cout << "Wrong input. Please try again." << endl;
                }
            }while(!((bYear < yearNow) && (bYear >= CstartYear)));
            getFile << bYear << " ";

                cout << "Is " << name << " deceased? (Y for yes/ N for no): ";
                cin >> personDead;
                if(toupper(personDead) == 'Y')
                //fallegra að nota toupper frekar en langa uppröðun
                {
                    do{
                        cout << "Input year of death: ";
                        cin >> dYear;
                            if(!((dYear > bYear) && (dYear <= yearNow)))
                            //year of birth has to be less than year of death - BÓE
                            //do not do equal since it is highly unlikely that a famous person would be less than 1 years old - BóE
                            //use a constant for the year, now it is set to 2015, death year should be less or equal
                            {
                                cout << "Wrong input. Please try again." << endl;
                            }
                    }while(!((dYear > bYear)&& (dYear <= yearNow)));
                    getFile << dYear;
                }
                else
                {
                    int zero = 0;
                    getFile << zero;
                    //all deceased get zero as input for year of death - BóE
                }
            //dYear kemur vitlaust út á þann hátt að ef slegið er inn nnn þá er hoppað í userMenu

            cout << "Input more information (Y for yes/N for no): ";
            cin >> keepGoing;
        }while(toupper(keepGoing) == 'Y');

    getFile.close( );
}

void FamousPeople::displayPerson(InfoType p)
{
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
    fillVector(FP);

    int choise;
    string nameSearch;
    char genderSearch;
    int birthYearSearch;
    int deathYearSearch;
    bool check = false;
    do
        {
        cout << "What do you want to search?: " << endl;
        cout << "1. Name"<< endl;
        cout << "2. Gender"<< endl;
        cout << "3. Birth year" << endl;
        cout << "4. Death year" << endl;
        cout << "5. Return " << endl;
        cin >> choise;
        if(choise == 1)
        {
            cout<<"enter name: ";
            cin>> nameSearch;
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(nameSearch == FP[i].name)
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
        if(choise == 2)
        {
            cout << "Enter gender: ";
            cin >> genderSearch;
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(genderSearch == FP[i].gender)
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
        if(choise == 3)
        {
            cout << "Enter birthYear: ";
            cin >> birthYearSearch;
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
        if(choise == 4)
        {
            cout << "Enter deathYear: ";
            cin >> deathYearSearch;
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(deathYearSearch == FP[i].deathYear)

                    displayPerson(FP[i]);
                else
                 cout << "Name was not in file" << endl;

                 cout << "DeathYear was not in file" << endl;

                {
                    displayPerson(FP[i]);
                    check = true;
                }
            }
            if(check == false)
            {
                cout << "Death year was not in file" << endl;
            }
        }
        if(choise >5)
        {
            cout << "Wrong input" << endl;
        }
    }while (choise != 5);

    FP.clear();

    userMenu();

}
