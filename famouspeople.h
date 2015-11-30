#ifndef FAMOUSPEOPLE_H
#define FAMOUSPEOPLE_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct InfoType
{
    string name;
    char gender;
    int birthYear;
    int deathYear;
};

class FamousPeople
{
public:

    FamousPeople();


    struct InfoType
    {
        string name;
        char gender;
        int birthYear;
        int deathYear;
    };

    void userMenu();
    void getInfo();
    void viewInfo(vector<InfoType>& FP);
    void displayPerson(InfoType p);


    void fillVector(vector<InfoType>& FP);
    void searchVector(vector <InfoType>& FP);
    void printVector(InfoType& FP) const;

    void fillVector(vector <InfoType>& FP);

    void searchVector(vector <InfoType>& FP);


    void sortByNameDesc(vector <InfoType>& FP);

    void sortByNameAsc(vector <InfoType>& FP);

    void sortByYearDesc(vector <InfoType>& FP);

    void sortByYearAsc(vector <InfoType>& FP);

    void sortMenu();

    void getInfo();

    void viewInfo();
    void displayPerson(InfoType& p)const;

private:
    vector<InfoType>FP;
};

#endif // FAMOUSPEOPLE_H
