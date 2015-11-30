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


    void fillVector(vector <InfoType>& FP);
    //tekur skjalið og setur inn í vektor

    void searchVector(vector <InfoType>& FP);
    //leitar að skilirðum í vektornum úr skjalinu

    void sortByNameDesc(vector <InfoType>& FP);

    void sortByNameAsc(vector <InfoType>& FP);

    void sortByYearDesc(vector <InfoType>& FP);

    void sortByYearAsc(vector <InfoType>& FP);

    void userMenu();

    void getInfo();

    void viewInfo(vector<InfoType>& FP);

    void displayPerson(InfoType& p)const;
    //fall sem skrifar bara út upplýsingar, hvort sem er úr skjalinu eða vektor


private:
    vector<InfoType>FP;
};

#endif // FAMOUSPEOPLE_H
