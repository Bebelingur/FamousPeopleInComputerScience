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
    struct InfoType
    {
        string name;
        char gender;
        int birthYear;
        int deathYear;
    };
    void viewInfo();
    void displayPerson(InfoType p);


private:

    vector<InfoType>FP;
};

#endif // FAMOUSPEOPLE_H
