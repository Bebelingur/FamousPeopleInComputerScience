#ifndef FAMOUSPEOPLE_H
#define FAMOUSPEOPLE_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

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

    void sortByNameDesc(vector <InfoType>& FP);

    void sortByNameAsc(vector <InfoType>& FP);

    void sortByYearDesc(vector <InfoType>& FP);

    void sortByYearAsc(vector <InfoType>& FP);





private:
    vector<InfoType>FP;
};

#endif // FAMOUSPEOPLE_H
