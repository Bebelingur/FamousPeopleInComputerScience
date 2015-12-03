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
const int alive = (yearNow + 1);
//Fasti sem gefur fólki gildi að það sé ennþá lifandi, nauðsynlegt fyrir sort föll

Services::Services()
{
     data datalayer;
     datalayer.loadData();
}

void Services::getInfo()
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

    cout << "* * * INPUT INFORMATION * * *" << endl;
    cout << endl;
    do{
        bool check = false;
        do{
            //NAME
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
                UI user;
                user.displayError();
            }
        }while(check == true);

        getFile << name << "*";

        //GENDER
        do{
            cout << "Input gender (F for female/M for male /? for undecided): ";
            cin >> gender;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
                if(toupper(gender) != 'F' && toupper(gender) != 'M' && gender != '?')
                {
                    UI user;
                    user.displayError();
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
                    UI user;
                    user.displayError();
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
                    UI user;
                    user.displayError();
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
                                UI user;
                                user.displayError();
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
                    UI user;
                    user.displayError();
                }
            cout << endl;
        }while(toupper(keepGoing) != 'Y' && toupper(keepGoing) != 'N');

    }while(toupper(keepGoing) == 'Y');
    getFile.close( );
}
void Services::fillVector(vector<InfoType>& FP)
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
void Services::viewInfo()
{
    UI p;

    ifstream getFile;
    getFile.open("InfoFile.txt");

        if(getFile.fail())
        {
            cout << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "| | | Could not open file. No data to display. | | |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << endl;
            p.userMenu();
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
            p.userMenu();
        }
}
void Services::displayPerson(InfoType p)
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
            cout << "Undecided" << endl;
        }
    cout << "Year of birth: " << p.birthYear << endl;

        if(p.deathYear != 0)
        {
            cout << "Year of death: " << p.deathYear << endl;
        }

    cout << endl;
}
string Services::changeName(InfoType p)
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

//Fall sem birtir persónur eftir að búið er að sorta lista
void Services::displaySortedPerson(vector <InfoType>& FP)
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
            cout << "Undecided" << endl;
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
void Services::sortByNameAsc(vector <InfoType>& FP)
{
    UI user;

    fillVector(FP);
    cout << endl;
    cout << "--- Displaying persons by name in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);

    displaySortedPerson(FP);

    FP.clear();

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir nöfnum í öfugri stafrófsröð
void Services::sortByNameDesc(vector <InfoType>& FP)
{
    UI user;
    fillVector(FP);
    cout << endl;
    cout << "--- Displaying persons by name in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameDesc);

    displaySortedPerson(FP);

    FP.clear();

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir kyni, Males
void Services::sortByGenderMale(vector <InfoType>& FP)
{
    UI user;

    fillVector(FP);
    cout << endl;
    cout << "--- Displaying male persons ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderMaleFirst);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(toupper(FP.at(i).gender) == 'M')
        {
            cout << "Name: " << FP.at(i).name<< endl;

            if(toupper(FP.at(i).gender) == 'F')
            {
                cout << "Gender: " << "Female" << endl;
            }
            else if(toupper(FP.at(i).gender) == 'M')
            {
                cout << "Gender: " << "Male" << endl;
            }
            else
            {
                cout << "Gender: " << "Undecided" << endl;

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

    FP.clear();
    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir kyni, Females
void Services::sortByGenderFemale(vector <InfoType>& FP)
{
    UI user;

    fillVector(FP);
    cout << endl;
    cout << "--- Displaying female persons ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(toupper(FP.at(i).gender) == 'F')
        {
            cout << "Name: " << FP.at(i).name<< endl;

            if(toupper(FP.at(i).gender) == 'F')
            {
                cout << "Gender: " << "Female" << endl;
            }
            else if(toupper(FP.at(i).gender) == 'M')
            {
                cout << "Gender: " << "Male" << endl;
            }
            else
            {
                cout << "Gender: " << "Undecided" << endl;
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

    FP.clear();

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir kyni, undecided
void Services::sortByGenderUndecided(vector <InfoType>& FP)
{
    UI user;

    fillVector(FP);
    cout << endl;
    cout << "--- Displaying persons of undecided gender ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
    if(FP.at(i).gender != '?')
    {
        cout << "------------------------------------------------------------" << endl;
        cout << "| | | There aren't any persons of undecided gender | | |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << endl;
    }
    else
    {
        for (unsigned int i = 0; i < FP.size(); i++)
        {
            if(FP.at(i).gender == '?')
            {
                cout << "Name: " << FP.at(i).name<< endl;

        if(toupper(FP.at(i).gender) == 'F')
        {
        cout << "Gender: " << "Female" << endl;
        }
        else if(toupper(FP.at(i).gender) == 'M')
        {
        cout << "Gender: " << "Male" << endl;
        }
        else
        {
            cout << "Gender: " << "Undecided" << endl;
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
        FP.clear();
        char input;
        cout << "--- Press any key and then enter to return to sort menu ---" << endl;
        cin >> input;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
            if(input)
            {
                user.sortMenu();
            }
    }
}

//Fall sem birtir lista sem er sortaður eftir fæðingarári elst til yngst
void Services::sortByYearAsc(vector <InfoType>& FP)
{
    UI user;

    fillVector(FP);
    cout << endl;
    cout << "--- Displaying persons by year of birth in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearAsc);

    displaySortedPerson(FP);

    FP.clear();

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir fæðingarár yngst til elst
void Services::sortByYearDesc(vector <InfoType>& FP)
{
    UI user;

    fillVector(FP);
    cout << endl;
    cout << "--- Displaying persons by year of birth in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearDesc);

    displaySortedPerson(FP);

    FP.clear();

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir dánarári elst til yngst
void Services::sortByDeathYearDesc(vector <InfoType>& FP)
{
    UI user;

    fillVector(FP);
    cout << endl;
    cout << "--- Displaying persons by year of death in descending order ---" << endl;
    cout << endl;


    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);

    displaySortedPerson(FP);

    FP.clear();

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}

//Fall sem birtir lista sem er sortaður eftir dánarári yngst til elst
void Services::sortByDeathYearAsc(vector <InfoType>& FP)
{
    UI user;

    fillVector(FP);
    cout << endl;
    cout << "--- Displaying persons by year of death in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearDesc);

    displaySortedPerson(FP);

    FP.clear();

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}


void Services::sortByDeceased(vector <InfoType>& FP)
{
    UI user;

    fillVector(FP);
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

            if(toupper(FP.at(i).gender) == 'F')
            {
                cout << "Gender: " << "Female" << endl;
            }
            else if(toupper(FP.at(i).gender) == 'M')
            {
                cout << "Gender: " << "Male" << endl;
            }
            else
            {
                cout << "Gender: " << "Undecided" << endl;
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

    FP.clear();

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}


void Services::sortByNotDeceased(vector <InfoType>& FP)
{
    UI user;

    fillVector(FP);
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

            if(toupper(FP.at(i).gender) == 'F')
            {
                cout << "Gender: " << "Female" << endl;
            }
            else if(toupper(FP.at(i).gender == 'M'))
            {
                cout << "Gender: " << "Male" << endl;
            }
            else
            {
                cout << "Gender: " << "Undecided" << endl;
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

    FP.clear();

    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}

void Services::searchVectorName(vector <InfoType>& FP)
{
    UI user;
    string nameSearch;
    cout << "Enter name: ";
    cin >> nameSearch;
    int nameSize = nameSearch.size();
    bool check = false; //check til að athuga hvort það sé búið að finna í leitinni


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
        if(found != (int) std::string::npos)
        {
            displayPerson(FP[i]);
            check = true;

            char input;
            cout << "--- Press any key and then enter to return to search menu ---" << endl;
            cin >> input;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
                if(input)
                {
                    user.searchMenu();
                }
        }
    }
    if(check == false)
    {
        cout << "-------------------------------------------" << endl;
        cout << "   "<<nameSearch << " was not in file or input not in the right format" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "--- Please try again. ---" << endl;
        cout << endl;
    }

}
void Services::searchVectorGender(vector <InfoType>& FP)
{
    UI user;
    string genderSearch;
        bool check = false; //check til að athuga hvort það sé búið að finna í leitinni

        cout << "Enter gender (M for male, F for female or ? for undecided): ";
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

                    char input;
                    cout << "--- Press any key and then enter to return to search menu ---" << endl;
                    cin >> input;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                        if(input)
                        {
                            user.searchMenu();
                        }
                }
            }
        }
        if(check == false || genderSearch.size() != 1)
        {
            cout << "-------------------------------------------" << endl;
            cout << "Gender " << genderSearch << " was not in file or input not in the right format" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "--- Please try again. ---" << endl;
            cout << endl;
        }
}

void Services::searchVectorBirthYear(vector <InfoType>& FP)
{
    UI user;
    string birthYearSearch;
    bool check = false; //check til að athuga hvort það sé búið að finna í leitinni

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

                    char input;
                    cout << "--- Press any key and then enter to return to search menu ---" << endl;
                    cin >> input;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                        if(input)
                        {
                            user.searchMenu();
                        }
                }
            }
        }
        if(check == false)
        {
            cout << "-------------------------------------------" << endl;
            cout << "Birth year " << birthYearSearch << " is not in file or input not in the right format" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "--- Please try again. ---" << endl;
            cout << endl;
        }
}
void Services::searchVectorDeathYear(vector <InfoType>& FP)
{
    UI user;
    string deathYearSearch;
    bool check = false; //check til að athuga hvort það sé búið að finna í leitinni


        cout << "Enter death year: ";
        cin >> deathYearSearch;
        //athugum hvort innslátturinn sé af réttri stærð og hvort allir liðir innsláttarins séu tölur
        if(deathYearSearch.size() == 4 && isdigit(deathYearSearch[0]) && isdigit(deathYearSearch[1]) && isdigit(deathYearSearch[2]) && isdigit(deathYearSearch[3]))
        {
            int deathYearSearchI = atoi(deathYearSearch.c_str());//færum string innsláttinn í int til að geta borið saman við skjalið
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(deathYearSearchI == FP[i].deathYear)
                {
                    displayPerson(FP[i]);
                    check = true;

                    char input;
                    cout << "--- Press any key and then enter to return to search menu ---" << endl;
                    cin >> input;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                        if(input)
                        {
                            user.searchMenu();
                        }
                }
            }
        }
        if(check == false)
        {
            cout << "-------------------------------------------"<<endl;
            cout << "Death year "<<  deathYearSearch << " is not in file or input not in the right format" << endl;
            cout << "-------------------------------------------"<<endl;
            cout << "--- Please try again. ---" << endl;
            cout << endl;
        }
}

void Services::searchVector()
{
    UI user;
    fillVector(FP);//búum til vektorinn
    user.searchMenu();
}
