#ifndef SERVICES_H
#define SERVICES_H
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <data.h>
#include <infotype.h>
#include <ui.h>
#include <QtSql>
#include <QtDebug>

using namespace std;

class Services
{
public:

    Services();



    void addPerson(string name, char gender, int bYear, int dYear);
    void fillVector(vector <InfoType>& FP);
    //tekur skjalið og setur inn í vektor
    void viewInfo();
    void displayPerson(InfoType p);
    string changeName(InfoType p);
    void sortByNameAsc(vector <InfoType>& FP);
    void sortByNameDesc(vector <InfoType>& FP);
    void sortByYearAsc(vector <InfoType>& FP);
    void sortByYearDesc(vector <InfoType>& FP);
    void sortByGenderMale(vector <InfoType>& FP);
    void sortByGenderFemale(vector <InfoType>& FP);
    void sortByGenderUndecided(vector <InfoType>& FP);
    void sortByDeathYearAsc(vector <InfoType>& FP);
    void sortByDeathYearDesc(vector <InfoType>& FP);
    void displaySortedPerson(vector <InfoType>& FP);
    void sortByDeceased(vector <InfoType>& FP);
    void sortByNotDeceased(vector <InfoType>& FP);
    void searchVector();
    //leitar í vektornum úr skjalinu
    void searchVectorName(vector <InfoType>& FP);
    void searchVectorGender(vector <InfoType>& FP);
    void searchVectorBirthYear(vector <InfoType>& FP);
    void searchVectorDeathYear(vector <InfoType>& FP);

    vector <InfoType> FP;

private:

};

#endif // SERVICES_H
