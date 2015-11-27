#ifndef FAMOUSPEOPLE_H
#define FAMOUSPEOPLE_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class FamousPeople
{
public:


    FamousPeople();






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
