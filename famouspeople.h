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


    FamousPeople();

    void sortByNameDesc();

    void sortByNameAsc();

    void sortByYearDesc();

    void sortByYearAsc();

    void getInfo();

    InputInformation();

private:

    struct InfoType
    {
        string name;
        char gender;
        int birthYear;
        int deathYear;
    };

    vector<InfoType>FP;
};

#endif // FAMOUSPEOPLE_H
