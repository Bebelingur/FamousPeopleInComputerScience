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
#include <comptype.h>

using namespace std;

class Services
{
public:

    Services();


    void addPerson(string name, char gender, int bYear, int dYear);
    // setti upp eins fall og addPerson nema bara fyrir tölvurnar
    // spurning um að bæta við vector (gerði vector<CompType> Comp) til að halda utan um tölvurnar
    void addComputer(string computerName, int computerYearMade, char computerType, char computerBuilt);
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



private:
    vector <InfoType> FP;
    vector <CompType> Comp;

    void backToSearchMenu();

};

#endif // SERVICES_H