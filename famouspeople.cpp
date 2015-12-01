#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include "famouspeople.h"

using namespace std;


const int yearNow = 2015;
const int CstartYear = 1791;
//birth year of Charles Babbage should do for beginning year of computer science
//kannski finna fall með nákvæmri dagsetningu/ári hvers dags fyrir sig
const int alive = (yearNow + 1);
//Fasti sem gefur fólki gildi að það sé ennþá lifandi, nauðsynlegt fyrir sort föll
//fastinn alive er alltaf yearnow + 1

FamousPeople::FamousPeople()
{}

void FamousPeople::userMenu()
{

    FP.clear();

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

//Fall sem birtir valmynd fyrir sort
void FamousPeople::sortMenu()
{
    fillVector(FP);
    char choice;

    do{
    cout << "How would you like to sort?" << endl;
    cout << "1. Sort by name (Ascending)" << endl;
    cout << "2. Sort by name (Descending)" << endl;
    cout << "3. Sort by gender (Males first)" << endl;
    cout << "4. Sort by gender (Females first)" << endl;
    cout << "5. Sort by year of birth (Ascending)" << endl;
    cout << "6. Sort by year of birth (Descending)" << endl;
    cout << "7. Sort by year of death (Ascending)" << endl;
    cout << "8. Sort by year of death (Descending)" << endl;
    cout << "9. Return" << endl;
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
                sortByGenderMale(FP);
                break;
                }
            case '4':
                {
                sortByGenderFemale(FP);
                break;
                }
            case '5':
                {
                sortByYearAsc(FP);
                break;
                }
            case '6':
                {
                sortByYearDesc(FP);
                break;
                }
            case '7':
                {
                sortByDeathYearAsc(FP);
                break;
                }
            case '8':
                {
                sortByDeathYearDesc(FP);
                break;
                }
            case '9':
                break;
            default:
                cout << "Wrong input! Please try again" << endl;
                break;
        }
    }while(choice != '9');
}

//Fall sem birtir persónur eftir að búið er að sorta lista
void FamousPeople::displaySortedPerson(vector <InfoType>& FP)
{
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
         cout << "Other" << endl;
        }

        cout << "Year of birth: " << FP.at(i).birthYear << endl;

        if(FP.at(i).deathYear == 0)
        {
            cout << endl;
        }
        else
        {
        cout << "Year of death: " << FP.at(i).deathYear << endl;
        cout << endl;
        }
    }
}

//Fall sem ber saman fyrsta staf í hverjum streng, notað
//til að sorta föll í stafrófsröð
bool compareNameAsc(const InfoType& a, const InfoType& b);
bool compareNameAsc(const InfoType& a, const InfoType& b)
{
    string str1 = a.name;
    str1[0] = tolower(str1[0]);

    string str2 = b.name;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}

//Fall sem ber saman fyrsta staf í hverjum streng, notað
//til að sorta föll í öfugri stafrófsröð
bool compareNameDesc(const InfoType& a, const InfoType& b);
bool compareNameDesc(const InfoType& a, const InfoType& b)
{
    string str1 = a.name;
    str1[0] = tolower(str1[0]);

    string str2 = b.name;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}

//Fall sem ber saman M og F og skilar M til að sorta lista eftir kyni
//þar sem Males kemur fyrst fyrir í lista
bool compareGenderMaleFirst(const InfoType& a, const InfoType& b);
bool compareGenderMaleFirst(const InfoType& a, const InfoType& b)
{
    return a.gender > b.gender;
}

//Fall sem ber saman M og F og skilar F til að sorta lista eftir kyni
//þar sem Females kemur fyrst fyrir í lista
bool compareGenderFemaleFirst(const InfoType& a, const InfoType& b);
bool compareGenderFemaleFirst(const InfoType& a, const InfoType& b)
{
    return a.gender < b.gender;
}

//Fall sem ber saman fæðingarár og skilar elst fyrst
bool compareYearAsc(const InfoType& a, const InfoType& b);
bool compareYearAsc(const InfoType& a, const InfoType& b)
{
    return a.birthYear < b.birthYear;
}

//Fall sem ber saman fæðingarár og skilar yngst fyrst
bool compareYearDesc(const InfoType& a, const InfoType& b);
bool compareYearDesc(const InfoType& a, const InfoType& b)
{
    return a.birthYear > b.birthYear;
}

//Fall sem ber saman dánarár og skilar elst fyrst
bool compareDeathYearAsc(const InfoType& a, const InfoType& b);
bool compareDeathYearAsc(const InfoType& a, const InfoType& b)
{
    int year1 = a.deathYear;
    int year2 = b.deathYear;

    if(year1 == 0)
    {
        year1 = alive;
    }
    else if(year2 == 0)
    {
        year2 = alive;
    }
    return year1 > year2;
}

//Fall sem ber saman dánarár og skilar yngst fyrst
bool compareDeathYearDesc(const InfoType& a, const InfoType& b);
bool compareDeathYearDesc(const InfoType& a, const InfoType& b)
{
    int year1 = a.deathYear;
    int year2 = b.deathYear;

    if(year1 == 0)
    {
        year1 = alive;
    }
    else if(year2 == 0)
    {
        year2 = alive;
    }
    return year1 < year2;
}

//Fall sem birtir lista sem er sortaður eftir nöfnum í stafrófsröð
void FamousPeople::sortByNameAsc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying programmers by name in asccending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);

    displaySortedPerson(FP);
}

//Fall sem birtir lista sem er sortaður eftir nöfnum í öfugri stafrófsröð
void FamousPeople::sortByNameDesc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying programmers by name in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameDesc);

    displaySortedPerson(FP);
}

//Fall sem birtir lista sem er sortaður eftir kyni þar sem Males koma fyrst fyrir
void FamousPeople::sortByGenderMale(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying programmers by gender, males first ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderMaleFirst);

    displaySortedPerson(FP);
}

//Fall sem birtir lista sem er sortaður eftir kyni þar sem Females koma fyrst fyrir
void FamousPeople::sortByGenderFemale(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying programmers by gender, females first ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);

    displaySortedPerson(FP);
}

//Fall sem birtir lista sem er sortaður eftir fæðingarári elst til yngst
void FamousPeople::sortByYearAsc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying programmers by year of birth in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearAsc);

    displaySortedPerson(FP);
}

//Fall sem birtir lista sem er sortaður eftir fæðingarár yngst til elst
void FamousPeople::sortByYearDesc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying programmers by year of birth in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearDesc);

    displaySortedPerson(FP);
}

//Fall sem birtir lista sem er sortaður eftir dánarári elst til yngst
void FamousPeople::sortByDeathYearDesc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying programmers by year of death in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearDesc);

    displaySortedPerson(FP);
}

//Fall sem birtir lista sem er sortaður eftir dánarári yngst til elst
void FamousPeople::sortByDeathYearAsc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying programmers by year of death in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);

    displaySortedPerson(FP);
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
        cout << "Could not open file!" << endl;
    }
    else
    {
        while(!getFile.eof())
        {
            InfoType p;
            getline(getFile, p.name, '*');
            getFile >> p.gender;
            getFile >> p.birthYear;
            getFile >> p.deathYear;

            FP.push_back(p);
        }
    getFile.close();
    }
}

void FamousPeople::searchVector(vector <InfoType>& FP)
{
    fillVector(FP);

    int choice;
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
        cout << "3. Year of birth" << endl;
        cout << "4. Year of death" << endl;
        cout << "5. Return " << endl;
        cin >> choice;
        if(choice == 1)
        {
            cout << "Enter name: ";
            cin >> nameSearch;
            cout << endl;
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
        if(choice == 2)
        {
            cout << "Enter gender: ";
            cin >> genderSearch;
            cout << endl;
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

                    displayPerson(FP[i]);
                else
                 cout << "Name was not in file" << endl;

                 cout << "Year of death was not in file" << endl;

                {
                    displayPerson(FP[i]);
                    check = true;
                }
            }
            if(check == false)
            {
                cout << "Year of death was not in file" << endl;

            }
        }
        if(choice > 5)
        {
            cout << "Wrong input" << endl;
        }
    }while (choice != 5);

    FP.clear();

    userMenu();
}
