#ifndef FAMOUSPEOPLE_H
#define FAMOUSPEOPLE_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class FamousPeople
{
public:

    struct InfoType
    {
        string name;
        char gender;
        int birthYear;
        int deathYear;
    };


    FamousPeople();


    void sortByNameDesc();

    void sortByNameAsc();

    void sortByYearDesc();

    void sortByYearAsc();

    void getInfo();

    void fillVector(vector <InfoType>& FP);


    void userMenu();

    void viewInfo();
    void displayPerson(InfoType p);


private:
    vector<InfoType>FP;
};

#endif // FAMOUSPEOPLE_H
