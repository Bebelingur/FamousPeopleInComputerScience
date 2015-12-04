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
    void fillVector();
    //tekur skjalið og setur inn í vektor
    void viewInfo();
    void displayPerson(InfoType p);
    string changeName(InfoType p);
    void sortByNameAsc();
    void sortByNameDesc();
    void sortByYearAsc();
    void sortByYearDesc();
    void sortByGenderMale();
    void sortByGenderFemale();
    void sortByGenderUndecided();
    void sortByDeathYearAsc();
    void sortByDeathYearDesc();
    void displaySortedPerson();
    void sortByDeceased();
    void sortByNotDeceased();
    void displaySorted(int i);
    void backToSortMenu();
    void searchVector();
    //leitar í vektornum úr skjalinu
    void searchVectorName();
    void searchVectorGender();
    void searchVectorBirthYear();
    void searchVectorDeathYear();
    void backToSearchMenu();
    void displayComputer(CompType p);

private:
    vector <InfoType> FP;

};

#endif // SERVICES_H
