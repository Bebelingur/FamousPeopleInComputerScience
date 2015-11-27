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
<<<<<<< HEAD

    void sortByNameDesc();

    void sortByNameAsc();

    void sortByYearDesc();

    void sortByYearAsc();

    void getInfo();

    InputInformation();

private:

=======

>>>>>>> 616f4ca6e3b4a9e2add4d29c619034bb9eedb70c
    struct InfoType
    {
        string name;
        char gender;
        int birthYear;
        int deathYear;
    };

    void userMenu();
    void getInfo();
    void viewInfo();
    void displayPerson(InfoType p);


private:
    vector<InfoType>FP;
};

#endif // FAMOUSPEOPLE_H
