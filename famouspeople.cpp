#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
//#include <ctime>
#include "famouspeople.h"
#include "data.h"

using namespace std;


const int yearNow = 2015;
const int CstartYear = 1791;
//birth year of Charles Babbage should do for beginning year of computer science
//kannski finna fall með nákvæmri dagsetningu/ári hvers dags fyrir sig
const int alive = (yearNow + 1);
//Fasti sem gefur fólki gildi að það sé ennþá lifandi, nauðsynlegt fyrir sort föll
//fastinn alive er alltaf yearnow + 1

FamousPeople::FamousPeople()
{
     data datalayer;
     datalayer.loadData();
}
void FamousPeople::userMenu()
{

    int choice;

    do{
        cout << endl;
        cout << "===========================================" << endl;
        cout << "===  Famous People In Computer Science  ===" << endl;
        cout << "===========================================" << endl;
        //cout << "What would you like to do?" << endl;
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
                getInfo();
                break;
            case 2:
                viewInfo();
                break;
            case 3:
                sortMenu();
                break;
            case 4:
                searchVector(FP);
                break;
            case 5:
                exit(1);
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5); //eða while(choice != 5);
    //náði að láta virka aðeins, google to the rescue :)  - BóE
}
void FamousPeople::getInfo()
{
    data datalayer;
    datalayer.loadData();

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

    cout << "* * * INPUT INFORMATION * * *" << endl;
    cout << endl;

    do{

        //NAME
        cout << "Input name (in the order first, middle and last name): ";
        cin.clear();
        getline(cin, name);
        getFile << name << "*";

        //GENDER
        do{
            cout << "Input gender (F for female/M for male /? for other): ";
            cin >> gender;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
                if(toupper(gender) != 'F' && toupper(gender) != 'M' && gender != '?')
                {
                    cout << "------------------------------------------" << endl;
                    cout << "| | | Wrong input. Please try again. | | |" << endl;
                    cout << "------------------------------------------" << endl;
                }
        }while(toupper(gender) != 'F' && toupper(gender) != 'M' && gender != '?');
        getFile << gender << " ";

        //BIRTH YEAR
        do{
            cout << "Input year of birth: ";
            cin >> bYear;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
                if(!((bYear < yearNow) && (bYear >= CstartYear)))
                {
                    cout << "------------------------------------------" << endl;
                    cout << "| | | Wrong input. Please try again. | | |" << endl;
                    cout << "------------------------------------------" << endl;
                }
        }while(!((bYear < yearNow) && (bYear >= CstartYear)));
        getFile << bYear << " ";

        //DEATH YEAR
        do{
            cout << "Is " << name << " deceased? (Y for yes/ N for no): ";
            cin >> personDead;
            cin.clear();
            cin.ignore(INT_MAX, '\n');

                if(toupper(personDead) != 'Y' && toupper(personDead) != 'N')
                {
                    cout << "------------------------------------------" << endl;
                    cout << "| | | Wrong input. Please try again. | | |" << endl;
                    cout << "------------------------------------------" << endl;
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
                                cout << "------------------------------------------" << endl;
                                cout << "| | | Wrong input. Please try again. | | |" << endl;
                                cout << "------------------------------------------" << endl;
                            }
                    }while(!((dYear > bYear) && (dYear <= yearNow)));
                    //year of birth has to be less than year of death - BÓE
                    //do not do equal since it is highly unlikely that a famous person would be less than 1 years old - BóE
                    //use a constant for the year, now it is set to 2015, death year should be less or equal
                    getFile << dYear;
                }
                if(toupper(personDead) == 'N')
                {
                    int zero = 0;
                    getFile << zero;
                    //all deceased get zero as input for year of death - BóE
                }
        }while(toupper(personDead) != 'Y' && toupper(personDead) != 'N');

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
        }while(toupper(keepGoing) != 'Y' && toupper(keepGoing) != 'N');

    }while(toupper(keepGoing) == 'Y');
    getFile.close( );
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
            getFile.close();
        }
}
void FamousPeople::viewInfo()
{
    ifstream getFile;
    getFile.open("InfoFile.txt");

        if(getFile.fail())
        {
            cout << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "| | | Could not open file. No data to display. | | |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << endl;
            userMenu();
            //breytti hér, fannst þetta betri möguleiki heldur en exit(1) út úr forritinu - BóE
        }

        cout << "* * * VIEW INFORMATION * * *" << endl;

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
    cout << "--- Press any key and then enter to return to main menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            userMenu();
        }
}
void FamousPeople::displayPerson(InfoType p)
{
    cout << endl;
    string tempName = changeName(p);

    cout << "Name: " << tempName << endl;
    cout << "Gender: ";
        if(toupper(p.gender) == 'F')
        {
            cout << "Female" << endl;
        }
        else if (toupper(p.gender) == 'M')
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
string FamousPeople::changeName(InfoType p)
{
    string tempName = p.name;
    int NameLength = tempName.size();
        for (int i = 0; i < NameLength; i++)
        {
            if(tempName[i] == ' ')
            {
                tempName[i+1] = toupper(tempName[i+1]);
                i++;
            }
            else if(i ==0)
            {
                tempName[i] = toupper(tempName[i]);
            }
            else
            {
                tempName[i] = tolower(tempName[i]);
            }
        }
    return tempName;
}

//Fall sem birtir valmynd fyrir sort
void FamousPeople::sortMenu()
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


void FamousPeople::sortNameMenu()
{
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
                fillVector(FP);
                sortByNameAsc(FP);
                FP.clear();
                break;
            }
            case 2:
            {
                fillVector(FP);
                sortByNameDesc(FP);
                FP.clear();
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


void FamousPeople::sortGenderMenu()
{
    int choice;

    do{
        cout << "* * * SORT BY GENDER INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by male" << endl;
        cout << "2. Sort by female" << endl;
        cout << "3. Sort by other" << endl;
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
            fillVector(FP);
            sortByGenderMale(FP);
            FP.clear();
            break;
        }
        case 2:
        {
            fillVector(FP);
            sortByGenderFemale(FP);
            FP.clear();
            break;
         }
        case 3:
        {
            fillVector(FP);
            sortByGenderOther(FP);
            FP.clear();
            break;
         }
         case 4:
         {
            sortMenu();
         }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4);
}


void FamousPeople::sortYearOfBirthMenu()
{
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
                fillVector(FP);
                sortByYearAsc(FP);
                FP.clear();
                break;
            }
            case 2:
            {
                fillVector(FP);
                sortByYearDesc(FP);
                FP.clear();
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

void FamousPeople::sortYearOfDeathMenu()
{
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
                fillVector(FP);
                sortByDeathYearAsc(FP);
                FP.clear();
                break;
             }
             case 2:
             {
                fillVector(FP);
                sortByDeathYearDesc(FP);
                FP.clear();
                break;
             }
            case 3:
            {
               fillVector(FP);
               sortByDeceased(FP);
               FP.clear();
               break;
            }
            case 4:
            {
               fillVector(FP);
               sortByNotDeceased(FP);
               FP.clear();
               break;
            }
             case 5:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}


//Fall sem birtir persónur eftir að búið er að sorta lista
void FamousPeople::displaySortedPerson(vector <InfoType>& FP)
{
    for (unsigned int i = 0; i < FP.size(); i++)
    {
        cout << "Name: " << FP.at(i).name<< endl;

        if(FP.at(i).gender == 'F'||FP.at(i).gender == 'f')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(FP.at(i).gender == 'M'||FP.at(i).gender == 'm')
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
            cout << "Not deceased!" << endl;
            cout << endl;
        }
        else
        {
        cout << "Year of death: " << FP.at(i).deathYear << endl;
        cout << endl;
        }
    }
}

//Fall sem ber saman fyrsta staf í hverjum streng, notað til að sorta föll í stafrófsröð
bool compareNameAsc(const InfoType& a, const InfoType& b);
bool compareNameAsc(const InfoType& a, const InfoType& b)
{
    string str1 = a.name;
    str1[0] = tolower(str1[0]);

    string str2 = b.name;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}

//Fall sem ber saman fyrsta staf í hverjum streng, notað til að sorta föll í öfugri stafrófsröð
bool compareNameDesc(const InfoType& a, const InfoType& b);
bool compareNameDesc(const InfoType& a, const InfoType& b)
{
    string str1 = a.name;
    str1[0] = tolower(str1[0]);

    string str2 = b.name;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}

//Fall sem ber saman M og F og skilar M til að sorta lista eftir kyni þar sem M kemur fyrst fyrir í lista
bool compareGenderMaleFirst(const InfoType& a, const InfoType& b);
bool compareGenderMaleFirst(const InfoType& a, const InfoType& b)
{
    return a.gender > b.gender;
}

//Fall sem ber saman M og F og skilar F til að sorta lista eftir kyni þar sem F kemur fyrst fyrir í lista
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
    cout << "--- Displaying persons by name in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);

    displaySortedPerson(FP);

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir nöfnum í öfugri stafrófsröð
void FamousPeople::sortByNameDesc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying persons by name in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameDesc);

    displaySortedPerson(FP);

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir kyni, Males
void FamousPeople::sortByGenderMale(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying male persons ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderMaleFirst);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(FP.at(i).gender == 'M'||FP.at(i).gender == 'm')
        {
        cout << "Name: " << FP.at(i).name<< endl;

        if(FP.at(i).gender == 'F'||FP.at(i).gender == 'f')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(FP.at(i).gender == 'M'||FP.at(i).gender == 'm')
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
            cout << "Not deceased!" << endl;
            cout << endl;
        }
        else
        {
        cout << "Year of death: " << FP.at(i).deathYear << endl;
        cout << endl;
        }
        }
    }
    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir kyni, Females
void FamousPeople::sortByGenderFemale(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying female persons ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(FP.at(i).gender == 'F'||FP.at(i).gender == 'f')
        {
        cout << "Name: " << FP.at(i).name<< endl;

        if(FP.at(i).gender == 'F'||FP.at(i).gender == 'f')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(FP.at(i).gender == 'M'||FP.at(i).gender == 'm')
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
            cout << "Not deceased!" << endl;
            cout << endl;
        }
        else
        {
        cout << "Year of death: " << FP.at(i).deathYear << endl;
        cout << endl;
        }
        }
    }
    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir kyni, other
void FamousPeople::sortByGenderOther(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying persons of other/unkown gender ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);


    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(FP.at(i).gender == '?')
        {
        cout << "Name: " << FP.at(i).name<< endl;

        if(FP.at(i).gender == 'F'||FP.at(i).gender == 'f')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(FP.at(i).gender == 'M'||FP.at(i).gender == 'm')
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
            cout << "Not deceased!" << endl;
            cout << endl;
        }
        else
        {
        cout << "Year of death: " << FP.at(i).deathYear << endl;
        cout << endl;
        }
        }
    }
}

//Fall sem birtir lista sem er sortaður eftir fæðingarári elst til yngst
void FamousPeople::sortByYearAsc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying persons by year of birth in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearAsc);

    displaySortedPerson(FP);

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir fæðingarár yngst til elst
void FamousPeople::sortByYearDesc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying persons by year of birth in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearDesc);

    displaySortedPerson(FP);

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir dánarári elst til yngst
void FamousPeople::sortByDeathYearDesc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying persons by year of death in descending order ---" << endl;
    cout << endl;


    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);

    displaySortedPerson(FP);

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir dánarári yngst til elst
void FamousPeople::sortByDeathYearAsc(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying persons by year of death in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearDesc);

    displaySortedPerson(FP);

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}


void FamousPeople::sortByDeceased(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying deceased persons ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(FP.at(i).deathYear > 0)
        {
        cout << "Name: " << FP.at(i).name<< endl;

        if(FP.at(i).gender == 'F'||FP.at(i).gender == 'f')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(FP.at(i).gender == 'M'||FP.at(i).gender == 'm')
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
            cout << "Not deceased!" << endl;
            cout << endl;
        }
        else
        {
        cout << "Year of death: " << FP.at(i).deathYear << endl;
        cout << endl;
        }
        }
    }
    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}


void FamousPeople::sortByNotDeceased(vector <InfoType>& FP)
{
    cout << endl;
    cout << "--- Displaying non deceased persons ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(FP.at(i).deathYear == 0)
        {
        cout << "Name: " << FP.at(i).name<< endl;

        if(FP.at(i).gender == 'F'||FP.at(i).gender == 'f')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(FP.at(i).gender == 'M'||FP.at(i).gender == 'm')
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
            cout << "Not deceased!" << endl;
            cout << endl;
        }
        else
        {
        cout << "Year of death: " << FP.at(i).deathYear << endl;
        cout << endl;
        }
        }
    }
    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}


void FamousPeople::searchVector(vector <InfoType>& FP)
{

    fillVector(FP);//búum til vektorinn
    string choice;
   //gerum breytur fyrir hvert leitarskilyrði. allar breytur eru strengjabreytur svo við getum skoðað hvað var slegið inn nákvæmlega

    string nameSearch;
    string genderSearch;
    string birthYearSearch;
    string deathYearSearch;
    bool check = false; //check til að athuga hvort það sé búið að finna í leitinni
    do{
            cout << "* * * SEARCH INFORMATION * * *" << endl;
            cout << endl;
            cout << "1. Search by name"<< endl;
            cout << "2. Search by gender"<< endl;
            cout << "3. Search by birth year"<< endl;
            cout << "4. Search by death year"<< endl;
            cout << "5. Return to main menu" << endl;
            cout << "===========================================" << endl;
            cout << "Please choose one of these numbers: ";
            cin >> choice;
            cout << "===========================================" << endl;
            cout <<endl;

            if(choice == "1")
            {
                cout << "Enter name: ";
                cin >> nameSearch;

                int nameSize = nameSearch.size();
                for(int i = 0; i < nameSize; i++)
                {
                    nameSearch[i] = tolower(nameSearch[i]);
                    //setjum innsláttinn í lower case
                }

                for(unsigned int i = 0; i < FP.size(); i++)
                {
                    string tempName = FP[i].name;
                    nameSize = tempName.size();

                    for(int j = 0; j < nameSize; j++)
                    {
                        tempName[j] = tolower(tempName[j]);
                        //setjum nafnið í skjalinu í lower case og berum svo saman
                    }

                    int found = tempName.find(nameSearch);//athugum hvort innslátturuinn sé hluti af einhverju nafni
                    if(found != std::string::npos)
                    {
                        displayPerson(FP[i]);
                        check = true;

                        /*char input;
                        cout << "--- Press any key and then enter to return to search menu ---" << endl;
                        cin >> input;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                            if(input)
                            {
                                userMenu(); //vantar search menu til að virki
                            }*/
                    }
                }
                if(check == false)
                {
                    cout << nameSearch << " was not in file. Please try again." << endl;
                    cout << endl;
                }
            }
            if(choice == "2")
            {
                cout << "Enter gender, M for male, F for female and ? for other: ";
                cin >> genderSearch;
                string tempGender;
                if(genderSearch.size() == 1)
                {   for(int i = 0; i <1; i++)//setjum innsláttinn í lágstafi
                    {
                        genderSearch[i] = tolower(genderSearch[i]);
                    }
                    for(unsigned int i = 0; i < FP.size(); i++)
                    {
                        tempGender = FP[i].gender;
                        for(int j = 0; j <1; j++)//færum gender í möppunni yfir í temp breytu og færum í lágstafi
                        tempGender[j] = tolower(tempGender[j]);

                        if(genderSearch == tempGender)
                        {
                            displayPerson(FP[i]);
                            check = true;
                        }
                    }
                }
                if(check == false || genderSearch.size()!=1)
                {
                    cout << "Gender " << genderSearch << " was not in file or input not in the right format" << endl;
                    cout << endl;
                }
            }
            if(choice == "3")
            {
                cout << "Enter year of birth: ";
                cin >> birthYearSearch;
                //athugum hvort innslátturinn sé af réttri stærð og hvort allir liðir innsláttarins séu tölur
                if(birthYearSearch.size()== 4 && isdigit(birthYearSearch[0])&& isdigit(birthYearSearch[1])&& isdigit(birthYearSearch[2])&& isdigit(birthYearSearch[3]))
                {
                    int birthYearSearchI = atoi(birthYearSearch.c_str());//færum string innsláttinn í int til að geta borið saman við skjalið
                    for(unsigned int i = 0; i < FP.size(); i++)
                    {
                        if(birthYearSearchI == FP[i].birthYear)
                        {
                            displayPerson(FP[i]);
                            check = true;
                        }
                    }
                }
                if(check == false)
                {
                    cout << "Birth year " << birthYearSearch << " is not in file or input not in the right format" << endl;
                    cout<<endl;
                }
            }
            if(choice == "4")
            {
                cout << "Enter death year: ";
                cin >> deathYearSearch;
                //athugum hvort innslátturinn sé af réttri stærð og hvort allir liðir innsláttarins séu tölur
                if(deathYearSearch.size()== 4 && isdigit(deathYearSearch[0])&& isdigit(deathYearSearch[1])&& isdigit(deathYearSearch[2])&& isdigit(deathYearSearch[3]))
                {
                    int deathYearSearchI = atoi(deathYearSearch.c_str());//færum string innsláttinn í int til að geta borið saman við skjalið
                    for(unsigned int i = 0; i < FP.size(); i++)
                    {
                        if(deathYearSearchI == FP[i].deathYear)
                        {
                            displayPerson(FP[i]);
                            check = true;
                        }
                    }
                }
                if(check == false)
                {
                    cout << "Death year "<<  deathYearSearch << " is not in file or input not in the right format" << endl;
                    cout << endl;
                }
            }
            if(choice !="1"&&choice !="2"&&choice !="3"&&choice !="4"&&choice !="5")
            {                
                cout << "------------------------------------------" << endl;
                cout << "| | | Wrong input. Please try again. | | |" << endl;
                cout << "------------------------------------------" << endl;
                cout << endl;
            }
        }while (choice != "5");

        FP.clear();//hreinsum vektorinn eftir notkun
}
