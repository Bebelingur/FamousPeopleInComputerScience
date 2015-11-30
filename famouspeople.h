#ifndef FAMOUSPEOPLE_H
#define FAMOUSPEOPLE_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <data.h>

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

    void userMenu();
    void getInfo();
    void viewInfo();
    void displayPerson(InfoType p);

    void fillVector(vector <InfoType>& FP);
    //tekur skjalið og setur inn í vektor

    void searchVector(vector <InfoType>& FP);
    //leitar að skilirðum í vektornum úr skjalinu

    void sortMenu();

    void sortByNameDesc(vector <InfoType>& FP);

    void sortByNameAsc(vector <InfoType>& FP);

    void sortByYearDesc(vector <InfoType>& FP);

    void sortByYearAsc(vector <InfoType>& FP);


private:
    vector <InfoType> FP;
};

#endif // FAMOUSPEOPLE_H
